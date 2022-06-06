cmake_minimum_required(VERSION 3.1)
project(hot-reload LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(PROJECT_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(engine)
add_subdirectory(engine-editor)
add_subdirectory(app)
add_subdirectory(3rdparty/flecs)
add_subdirectory(3rdparty/bgfx)