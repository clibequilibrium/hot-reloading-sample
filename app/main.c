#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <cr.h>
#include <engine.h>
#include <editor.h>
#include <components/gui.h>

static unsigned int CR_STATE version = 1;
static bool CR_STATE initialized = false;
static ecs_world_t CR_STATE *world = NULL;

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

  if (!initialized) {

    world = ecs_init();

    ECS_IMPORT(world, SdlSystem);
    ECS_IMPORT(world, BgfxSystem);
    ECS_IMPORT(world, ImguiBgfxSdlSystem);
    ECS_IMPORT(world, ImguiDockspaceSystem);

    ecs_entity_t app = ecs_set_name(world, 0, "App");
    ecs_set(world, app, AppWindow, {maximized : true});
    ecs_set(world, app, Renderer, {type : Direct3D11});

    initialized = true;
  }

  ecs_set_os_api_impl();
  ecs_progress(world, 0);

  return 0;
}