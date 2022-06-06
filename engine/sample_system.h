#ifndef SAMPLE_SYSTEM_H
#define SAMPLE_SYSTEM_H

#include <base.h>

typedef struct SampleData {
  int data;
} SampleData;

ENGINE_API extern ECS_COMPONENT_DECLARE(SampleData);

ENGINE_API
void SampleSystemImport(ecs_world_t *world);

#endif