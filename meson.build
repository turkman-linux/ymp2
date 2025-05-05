project('ymp', 'c')

add_project_arguments('-I'+meson.current_source_dir()+'/include', language: 'c')
add_project_arguments('-fvisibility=hidden', '-Dvisible=__attribute__((visibility("default")))',  language: 'c')
add_project_arguments('-Wall', '-Wextra', '-Werror',  language: 'c')


# Main library
libymp = library('ymp', 'src/operations.c')

subdir('docs')
