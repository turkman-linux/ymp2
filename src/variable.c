#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <variable.h>

typedef struct {
    char* name;
    char* value;
    bool read_only;
} Variable;

visible VariableManager* variable_manager_new(){
    VariableManager *variables = (VariableManager*)malloc(sizeof(VariableManager));
    variables->capacity = 0;
    variables->length = 0;
    variables->priv_data = NULL;
    return variables;
}

void visible variable_set_value(VariableManager* variables, const char* name, const char* value){
    Variable* vars = (Variable*)variables->priv_data;
    for(size_t i=0; i< variables->length; i++){
        if(strcmp(name, vars[i].name) == 0){
            strcpy(vars[i].value, value);
            return;
        }
    }
}
