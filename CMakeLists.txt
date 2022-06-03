cmake_minimum_required(VERSION 3.1)
project(hot-reload LANGUAGES C CXX)

if (MSVC AND WIN32 AND NOT MSVC_VERSION VERSION_LESS 142)

    # option 1: put the following command before the creation of the first
    #           compiled target you want to apply the option to;
    #           this applies to targets created in this dir and subdirectories
    #add_link_option($<$<CONFIG:Debug>:/INCREMENTAL>)
    #add_compile_option($<$<CONFIG:Debug>:/ZI>)

    # option 2: apply the option on a per-target basis
    add_link_options($<$<CONFIG:Debug>:/INCREMENTAL>)
    add_compile_options($<$<CONFIG:Debug>:/ZI>)

endif()

add_subdirectory(lib)
add_subdirectory(app)
#add_subdirectory(3rdparty/cimgui)
add_subdirectory(3rdparty/flecs)


