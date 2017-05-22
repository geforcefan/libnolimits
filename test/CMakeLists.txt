cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE ROOT_SOURCE *.cpp)

foreach ( file ${ROOT_SOURCE} )
    get_filename_component(filename ${file} NAME_WE)

    project(${filename})
    add_executable(${filename} ${file})
    target_link_libraries(${filename} nolimits ${GLM_LIBRARIES} ${ZLIB_LIBRARIES})
endforeach()
