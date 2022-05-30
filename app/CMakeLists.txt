project(app LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

file(GLOB_RECURSE SRC *.c *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(PROJ_SRC ${SRC} ${HEADERS})

add_library(${PROJECT_NAME} SHARED ${PROJ_SRC})
target_include_directories(
  ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/cr/)


# add_executable(${PROJECT_NAME} ${PROJ_SRC})
target_link_libraries(${PROJECT_NAME} lib)
