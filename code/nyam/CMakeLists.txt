cmake_minimum_required(VERSION 3.25)
project(nyam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(FetchContent)
include(make_dependencies_available)

make_zeromq_available()
make_btcpp_available()
make_asio_available()
make_crow_available()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(instantiate_simple_tree)
add_subdirectory(nyam_full_example)
