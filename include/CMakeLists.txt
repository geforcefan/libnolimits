file(GLOB_RECURSE INCLUDE_HEADER *.h)
source_group("Include Header Files" FILES ${INCLUDE_HEADER})

foreach ( file ${INCLUDE_HEADER} )
    get_filename_component( dir ${file} DIRECTORY BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
    file(RELATIVE_PATH dir2 "${CMAKE_CURRENT_SOURCE_DIR}" "${dir}")
    install( FILES ${file} DESTINATION include/${dir2} )
endforeach()