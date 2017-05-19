cmake_minimum_required(VERSION 2.8)
find_package(PkgConfig REQUIRED)

project(libnolimits)
set(LIBNOLIMITS_VERSION "1.0.0-beta")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory(include)
add_subdirectory(libnolimits)

pkg_check_modules (ZLIB zlib>=1.2.7)
pkg_search_module(ZLIB REQUIRED zlib>=1.2.7)

pkg_check_modules (GLM glm=>0.9.8)
pkg_search_module(GLM REQUIRED glm=>0.9.8)

# build pkg-config file
configure_file(
    "./cmake/libnolimits.pc.in"
    "libnolimits.pc"
    @ONLY
)

# install pkg-config file
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/libnolimits.pc"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

export(PACKAGE glm)

add_custom_target(
    uninstall
    COMMAND
    cat install_manifest.txt | xargs rm
    COMMAND
    xargs cmake/rm-empty-dirs < install_manifest.txt
    WORKING_DIRECTORY
    "${CMAKE_BINARY_DIR}"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/example")
add_subdirectory(example)
