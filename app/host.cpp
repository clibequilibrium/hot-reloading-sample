#define CR_HOST // required in the host only and before including cr.h
#define CR_DEBUG
#include <cr.h>

int main(int argc, char *argv[]) {
  // the host application should initalize a plugin with a context, a plugin
  cr_plugin ctx;

  // the full path to the live-reloadable application
  cr_plugin_open(ctx, "libapp-lib.dll");

  // call the update function at any frequency matters to you, this will give
  // the real application a chance to run
  while (!cr_plugin_update(ctx)) {
    // do anything you need to do on host side (ie. windowing and input stuff?)
  }

  // at the end do not forget to cleanup the plugin context
  cr_plugin_close(ctx);
  return 0;
}