cmake_minimum_required(VERSION 2.8)

project(libnolimits_example_basic)

add_executable(libnolimits_example_basic basic.cpp)

target_link_libraries(libnolimits_example_basic nolimits ${GLM_LIBRARIES} ${ZLIB_LIBRARIES})