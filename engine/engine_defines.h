#ifndef ENGINE_DEFINES_H
#define ENGINE_DEFINES_H

/* Convenience macro for exporting symbols */
#ifndef engine_STATIC
#if engine_EXPORTS && (defined(_MSC_VER) || defined(__MINGW32__))
#define ENGINE_API __declspec(dllexport)
#elif equilibrium_EXPORTS
#define ENGINE_API __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define ENGINE_API __declspec(dllimport)
#else
#define ENGINE_API
#endif
#else
#define ENGINE_API
#endif

#endif
