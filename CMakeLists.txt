cmake_minimum_required(VERSION 2.6)
project(multiMult)

set(PROJECT_PATH ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT})
set(CMAKE_INSTALL_PREFIX ${PROJECT_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)

add_subdirectory(src)
