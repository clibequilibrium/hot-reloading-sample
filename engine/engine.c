#include "engine.h"
#include <stdio.h>

ECS_COMPONENT_DECLARE(Position);
ECS_COMPONENT_DECLARE(Velocity);

void EngineImport(ecs_world_t *world) {
  ECS_MODULE(world, Engine);

  ECS_COMPONENT_DEFINE(world, Position);
  ECS_COMPONENT_DEFINE(world, Velocity);
}