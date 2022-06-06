cmake_minimum_required(VERSION 3.1)
project(engine LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

file(GLOB_RECURSE SRC *.c *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(SOURCES ${SRC} ${HEADERS})
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/cimgui
         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/flecs/
         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/bgfx/
         ${CMAKE_CURRENT_SOURCE_DIR}/components
         ${CMAKE_CURRENT_SOURCE_DIR}/systems)

target_link_libraries(${PROJECT_NAME} flecs bgfx bx SDL2)
