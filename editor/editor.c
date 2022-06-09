#include <flecs.h>
#include <stdio.h>
#include <cr.h>
#include "editor.h"

static void Test(ecs_iter_t *it) {
  Position *p = ecs_term(it, Position, 1);
  Velocity *v = ecs_term(it, Velocity, 2);

  for (int i = 0; i < it->count; i++) {
    p[i].x += v[i].x;
    p[i].y += v[i].y;

    fprintf(stdout, "Editor system: %d \n", p[i].x);
  }
}

CR_EXPORT void EditorSystemImport(ecs_world_t *world) {
  ECS_MODULE(world, EditorSystem);

  ECS_SYSTEM(world, Test, EcsOnUpdate, Position, Velocity);
}

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation) {
  assert(ctx);
  if (operation != CR_STEP) {
    fprintf(stdout, "OP: %s(%d)\n", operation == CR_LOAD ? "LOAD" : "UNLOAD", ctx->version);

    ECS_IMPORT(ctx->userdata, EditorSystem);

    return 0;
  }
}