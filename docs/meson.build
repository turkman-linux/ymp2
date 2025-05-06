# Doxygen configuration
doxygen = find_program('doxygen', required: false)


if doxygen.found()
  configure_file(
    input: 'Doxyfile.in',
    output: 'Doxyfile',
    configuration: {
      'OUTPUT': meson.current_build_dir(),
      'INPUT': meson.current_source_dir(),
    }
  )
    # Custom target to generate documentation
    doxygen_target = custom_target('doxygen',
        command: [doxygen, meson.current_build_dir()+'/Doxyfile'],
        output: 'doxygen.log',
        build_by_default: true
    )
endif
