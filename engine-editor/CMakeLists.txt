cmake_minimum_required(VERSION 3.1)
project(engine-editor LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
add_executable(${PROJECT_NAME} host.cpp)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/cr/)

target_link_libraries(${PROJECT_NAME} engine editor dbghelp)
add_subdirectory(editor)
