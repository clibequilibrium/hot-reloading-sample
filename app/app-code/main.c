#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <cr.h>
#include <lib.h>

static unsigned int CR_STATE version = 1;
static bool CR_STATE initialized = false;
static ecs_world_t* world;

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation) {
  assert(ctx);
  if (operation != CR_STEP) {
    fprintf(stdout, "OP: %s(%d)\n", operation == CR_LOAD ? "LOAD" : "UNLOAD", ctx->version);
    return 0;
  }

  if (ctx->version < version) {
    fprintf(stdout, "A rollback happened due to failure: %x!\n", ctx->failure);
  }
  version = ctx->version;

  if (operation == CR_UNLOAD) {
    ecs_quit(world);
    initialized = false;
  }

  if (!initialized) {

    world = ecs_init();

    ECS_COMPONENT_DEFINE(world, Position);
    ECS_COMPONENT_DEFINE(world, Velocity);

    ECS_SYSTEM(world, Move, EcsOnUpdate, Position, Velocity);

    ecs_entity_t e = ecs_new_id(world);
    ecs_set(world, e, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 2});

    initialized = true;
  }

  ecs_progress(world, 0);

  return 0;
}