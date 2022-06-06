#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <base.h>

typedef struct SdlWindow {
  int32_t dummy;
} SdlWindow;

ENGINE_API extern ECS_COMPONENT_DECLARE(SdlWindow);

ENGINE_API
void SdlComponentsImport(ecs_world_t *world);

#endif