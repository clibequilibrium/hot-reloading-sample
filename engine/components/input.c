#include "input.h"

ECS_COMPONENT_DECLARE(Input);

void InputComponentsImport(ecs_world_t *world) {
  ECS_MODULE(world, InputComponents);
  ECS_COMPONENT_DEFINE(world, Input);
}