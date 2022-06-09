#ifndef ENGINE_H
#define ENGINE_H

#include <flecs.h>

typedef struct {
  int x, y;
} Position, Velocity;

extern ECS_COMPONENT_DECLARE(Position);
extern ECS_COMPONENT_DECLARE(Velocity);

#endif