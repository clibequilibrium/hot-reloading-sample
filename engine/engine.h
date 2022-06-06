#ifndef ENGINE_H
#define ENGINE_H

#include <base.h>
#include <systems/bgfx_system.h>
#include <systems/sdl_system.h>

typedef struct {
  int x, y;
} Position, Velocity;

ENGINE_API extern ECS_COMPONENT_DECLARE(Position);
ENGINE_API extern ECS_COMPONENT_DECLARE(Velocity);

ENGINE_API
void EngineImport(ecs_world_t *world);

#endif