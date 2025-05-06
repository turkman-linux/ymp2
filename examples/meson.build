# Test files
foreach src : run_command('find', '.', '-type', 'f', '-iname', '*.c',check:true).stdout().strip().split('\n')
    name = src.replace('./','')
    name = name.replace('.c','')
    name = name.replace('/','_')
    executable(name, src, link_with: libymp)
endforeach

