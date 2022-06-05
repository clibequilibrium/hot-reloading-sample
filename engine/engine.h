#ifndef LIB_H
#define LIB_H

#include <flecs.h>
#include <engine_defines.h>

typedef struct {
  int x, y;
} Position, Velocity;

ENGINE_API extern ECS_COMPONENT_DECLARE(Position);
ENGINE_API extern ECS_COMPONENT_DECLARE(Velocity);

ENGINE_API
void EngineImport(ecs_world_t *world);

#endif