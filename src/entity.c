#include "entity.h"

#include <stdlib.h>

#include "internal/entity.h"
#include "orientation.h"
#include "position.h"

struct ncsdk_Entity *ncsdk_Entity_new(ncsdk_Orientation orientation,
                                      ncsdk_Position(float) position,
                                      int type_id, int unique_id) {
  struct ncsdk_Entity *entity = malloc(sizeof(struct ncsdk_Entity));
  entity->orientation = orientation;
  entity->position = position;
  entity->type_id = type_id;
  entity->unique_id = unique_id;
  return entity;
}

void ncsdk_Entity_delete(struct ncsdk_Entity *entity) { free(entity); }

const ncsdk_Orientation *ncsdk_Entity_GetOrientation(
    const struct ncsdk_Entity *entity) {
  return &entity->orientation;
}

const ncsdk_Position(float) *
    ncsdk_Entity_GetPosition(const struct ncsdk_Entity *entity) {
  return &entity->position;
}

int ncsdk_Entity_GetTypeId(const struct ncsdk_Entity *entity) {
  return entity->type_id;
}

int ncsdk_Entity_GetUniqueId(const struct ncsdk_Entity *entity) {
  return entity->unique_id;
}