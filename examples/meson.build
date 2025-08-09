# Test files
if get_option('library')
    foreach src : run_command('find', '.', '-type', 'f', '-iname', '*.c',check:true).stdout().strip().split('\n')
        name = src.replace('./','')
        name = name.replace('.c','')
        name = name.replace('/','_')
        executable(name, [src]+start, link_with: libymp, link_args: nostdlib)
    endforeach
endif

valac = find_program('valac', required: false)
if get_option('vala') and valac.found()
    glib_dep = dependency('glib-2.0', required: true)
    executable('ymp-vala', ['ymp.vala'], 
        dependencies: [glib_dep],
        link_with: [libymp],
        c_args: ['-Wno-all'],
        vala_args: ['--pkg', 'ymp', '--vapidir=../include/']
    )
endif
