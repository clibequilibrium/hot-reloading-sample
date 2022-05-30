cmake_minimum_required(VERSION 3.1)
project(hot-reload LANGUAGES C CXX)

if(CMAKE_HOST_UNIX AND NOT APPLE)
  set(LINUX TRUE)
elseif(CMAKE_HOST_WIN32)
  set(WINDOWS TRUE)
endif()

if(MINGW)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()


set(PROJECT_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(lib)
add_subdirectory(lib-host)
add_subdirectory(app)
