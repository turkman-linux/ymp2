#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <core/ymp.h>
#include <utils/error.h>
#include <core/logger.h>

#include <utils/string.h>
typedef struct {
    const char* name;
    size_t line;
} label;

static label *labels;
size_t label_max = 32;
size_t label_cur = 0;

static char** parse_args(const char* line){
    return split(strip((char*)line), " ");
}

visible int run_script(const char* script){
    char** lines = split(script, "\n");
    int rc = 0;
    int iflevel = 0;
    if(!labels) {
        labels = calloc(label_max, sizeof(label));
    }
    // search for labels
    for(size_t i=0; lines[i]; i++){
        lines[i] = strip(lines[i]);
        if(startswith(lines[i], "label: ")){
            // reallocate if needed
            if(label_cur >= label_max){
                label_max+= 32;
                labels = realloc(labels, sizeof(label)* label_max);
            }
            labels[label_cur].name = strdup(lines[i]+7);
            labels[label_cur].line = i;
            label_cur++;
        }
    }
    for(size_t i=0; lines[i]; i++){
        if(strlen(lines[i]) == 0){
            continue;
        }
        debug("script:%s\n", lines[i]);
        char** args = parse_args(lines[i]);
        // handle if endif
        if (iseq(args[0], "if")){
            if(operation_main(global->manager, args[1], args+2) != 0){
                iflevel++;
                int cur = i;
                // search for endif
                for(i=i+1;lines[i]; i++){
                    debug("search endif:%s %d\n", lines[i], iflevel);
                    if(strlen(lines[i]) == 0){
                        continue;
                    }
                    if(startswith(lines[i],"endif")){
                        iflevel--;
                    }
                    if(startswith(lines[i],"if ")){
                        iflevel++;
                    }
                    if(iflevel == 0){
                        goto found_endif;
                    }
                }
                error_add(build_string("syntax error at line %d : endif missing", cur));
                error(1);
                return 1;
                found_endif:
                debug("endif found at :%s %d\n", lines[i], iflevel);
            }
        }
        rc = operation_main(global->manager, args[0], args+1);
    }
    // cleanup
    for(size_t i=0; lines[i]; i++){
        free(lines[i]);
    }
    free(lines);
    return rc;
}

