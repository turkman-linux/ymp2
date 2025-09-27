#include <stdlib.h>

#include <core/help.h>
#include <core/logger.h>

#include <utils/string.h>

Help* help_new(){
    Help *h = malloc(sizeof(Help));
    h->cur = 0;
    h->max = 32;
    h->parameters = malloc(h->max*sizeof(char*));
    return h;
}

void help_add_parameter(Help *h, const char* name, const char* description){
    debug("name: %s, desc: %s\n", name, description);
    if(h->cur >= h->max){
        h->max += 32;
        h->parameters = realloc(h->parameters, h->max);
    }
    h->parameters[h->cur] = build_string("%s : %s", colorize(RED, name), description);
    h->cur++;
}