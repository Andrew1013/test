cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/)

project(root)
set(HEADER_FILES ${root_SOURCE_DIR}/include/)

add_library(myutillib src/myutil.c ${HEADER_FILES})

add_subdirectory(multi_echo/c/tcp)
add_subdirectory(multi_echo/c/sctp)
add_subdirectory(multi_echo/go/tcp)
add_subdirectory(multi_echo/go/sctp)

add_subdirectory(simple/c/tcp)
add_subdirectory(simple/c/sctp)
add_subdirectory(simple/go/sctp)
