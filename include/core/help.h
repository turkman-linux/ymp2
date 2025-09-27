#ifndef _help_h
#define _help_h
typedef struct {
    char** parameters;
    const char* usage;
    void* priv_data;
    size_t cur;
    size_t max;
} Help;

Help* help_new();

void help_add_parameter(Help* h, const char* name, const char* description);
#endif