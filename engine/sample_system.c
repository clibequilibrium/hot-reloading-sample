#include <sample_system.h>
#include <SDL2/SDL_syswm.h>

ECS_COMPONENT_DECLARE(SampleData);

static void SampleSystemUpdate(ecs_iter_t *it) {
  printf("%s \n", "Test");
}

void SampleSystemImport(ecs_world_t *world) {

  ECS_MODULE(world, SampleSystem);

  ECS_COMPONENT_DEFINE(world, SampleData);

  ecs_set_ptr(world, ecs_id(SampleData), SampleData, NULL);

  ECS_SYSTEM(world, SampleSystemUpdate, EcsOnUpdate, SampleData($));
}