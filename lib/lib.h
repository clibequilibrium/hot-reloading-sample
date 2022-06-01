#ifndef LIB_H
#define LIB_H

#include <flecs.h>

typedef struct {
  int x, y;
} Position, Velocity;


extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);

__declspec(dllexport) void Move(ecs_iter_t *it);

#endif