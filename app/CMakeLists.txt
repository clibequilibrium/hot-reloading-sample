project(app LANGUAGES C CXX)

file(GLOB_RECURSE SRC *.c *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(PROJ_SRC ${SRC} ${HEADERS})

add_library(${PROJECT_NAME} SHARED ${PROJ_SRC})
target_include_directories(
  ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                         ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/cr/)

target_link_libraries(${PROJECT_NAME} engine editor)