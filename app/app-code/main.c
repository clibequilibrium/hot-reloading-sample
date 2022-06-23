#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <cr.h>
#include <lib.h>
#include <setjmp.h>

static unsigned int CR_STATE version = 1;
static bool CR_STATE initialized = false;
static ecs_world_t CR_STATE *world = NULL;
static try_catch_wrapper_t CR_STATE wrapper;

void Move(ecs_iter_t *it) {
  Position *p = ecs_term(it, Position, 1);
  Velocity *v = ecs_term(it, Velocity, 2);

  for (int i = 0; i < it->count; i++) {
    p[i].x += v[i].x;
    p[i].y += v[i].y;

    fprintf(stdout, "Change this text: %d \n", p[i].x);
  }
}

static int plugin_update(struct cr_plugin *ctx) {
  ecs_progress(world, 0, &wrapper);

  if (wrapper.success == 0 && initialized) {
    ctx->failure = CR_OTHER;
    ctx->version = ctx->last_working_version;
    return -1;
  }

  return 0;
}

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation) {
  assert(ctx);
  ecs_set_os_api_impl();

  if (operation != CR_STEP) {
    fprintf(stdout, "OP: %s(%d)\n", operation == CR_LOAD ? "LOAD" : "UNLOAD", ctx->version);

    if (initialized) {
      if (operation == CR_LOAD) {

        plugin_update(ctx);
        ECS_SYSTEM(world, Move, EcsOnUpdate, Position, Velocity);
      }
    }

    return 0;
  }

  int *addr = NULL;
  (void)addr; // warning
  // to test crash protection, uncomment the following line
  // int i = *addr;

  if (!initialized) {
    world = ecs_init();
    wrapper.env = ctx->userdata;
    wrapper.success = true;

    ECS_COMPONENT_DEFINE(world, Position);
    ECS_COMPONENT_DEFINE(world, Velocity);

    ECS_SYSTEM(world, Move, EcsOnUpdate, Position, Velocity);

    ecs_entity_t e = ecs_new_id(world);
    ecs_set(world, e, Position, {10, 20});
    ecs_set(world, e, Velocity, {1, 2});

    initialized = true;
  }

  return plugin_update(ctx);
}