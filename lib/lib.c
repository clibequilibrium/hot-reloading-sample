#include "lib.h"
#include <stdio.h>

ECS_COMPONENT_DECLARE(Position);
ECS_COMPONENT_DECLARE(Velocity);

void Move(ecs_iter_t *it) {
  Position *p = ecs_term(it, Position, 1);
  Velocity *v = ecs_term(it, Velocity, 2);

  for (int i = 0; i < it->count; i++) {
    p[i].x += v[i].x;
    p[i].y += v[i].y;

    fprintf(stdout, "xc: %d \n", p[i].x);
  }
}