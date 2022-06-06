#include "sdl_window.h"

ECS_COMPONENT_DECLARE(SdlWindow);

void SdlComponentsImport(ecs_world_t *world) {
  ECS_MODULE(world, SdlComponents);
  ECS_COMPONENT_DEFINE(world, SdlWindow);
}