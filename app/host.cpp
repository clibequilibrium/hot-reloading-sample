#define CR_HOST // required in the host only and before including cr.h
#define CR_DEBUG
#include <cr.h>
#include <flecs.h>

int main(int argc, char *argv[]) {
  // the host application should initalize a plugin with a context, a plugin
  cr_plugin ctx, ctx2;

  // the full path to the live-reloadable application
  cr_plugin_open(ctx, "libapp-code.dll");
  cr_plugin_open(ctx2, "libeditor.dll");

  ecs_world_t *world = ecs_init();
  ctx.userdata = world;
  ctx2.userdata = world;

  // call the update function at any frequency matters to you, this will give
  // the real application a chance to run
  while (true) {
    // do anything you need to do on host side (ie. windowing and input stuff?)

    cr_plugin_update(ctx);
    cr_plugin_update(ctx2);
  }

  // at the end do not forget to cleanup the plugin context
  cr_plugin_close(ctx);
  cr_plugin_close(ctx2);
  return 0;
}