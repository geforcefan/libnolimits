file(GLOB_RECURSE ROOT_SOURCE *.cpp)
file(GLOB_RECURSE ROOT_HEADER *.h)

source_group("Source Files" FILES ${ROOT_SOURCE})
source_group("Header Files" FILES ${ROOT_HEADER})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(nolimits STATIC ${ROOT_SOURCE} ${ROOT_HEADER})
set_target_properties(nolimits PROPERTIES DEFINE_SYMBOL NOLIMITS_DLL)
set_property(TARGET nolimits PROPERTY POSITION_INDEPENDENT_CODE 1)

install(TARGETS nolimits
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

foreach ( file ${ROOT_HEADER} )
    get_filename_component( dir ${file} DIRECTORY BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
    file(RELATIVE_PATH dir2 "${CMAKE_CURRENT_SOURCE_DIR}" "${dir}")
    install( FILES ${file} DESTINATION include/libnolimits/${dir2} )
endforeach()