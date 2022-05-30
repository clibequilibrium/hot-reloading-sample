cmake_minimum_required(VERSION 3.1)
project(lib-host LANGUAGES CXX)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SRC *.c *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(EQUILIBRIUM_SOURCES ${SRC} ${HEADERS})

add_executable(${PROJECT_NAME} ${EQUILIBRIUM_SOURCES})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/cr/)

target_link_libraries(${PROJECT_NAME} dbghelp) 