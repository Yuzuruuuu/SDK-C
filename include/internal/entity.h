#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "orientation.h"
#include "position.h"

struct ncsdk_Entity {
  ncsdk_Orientation orientation;
  ncsdk_Position(float) position;
  int type_id;
  int unique_id;
};

struct ncsdk_Entity *ncsdk_Entity_new(ncsdk_Orientation orientation,
                                      ncsdk_Position(float) position,
                                      int type_id, int unique_id);

void ncsdk_Entity_delete(struct ncsdk_Entity *entity);

#ifdef __cplusplus
}
#endif