#include "internal/agent.h"

#include <stdlib.h>

#include "internal/inventory.h"
#include "orientation.h"
#include "position.h"
#include "string.h"

ncsdk_Agent* ncsdk_Agent_New(const char* token, int unique_id,
                             const ncsdk_Position(float) * position,
                             const ncsdk_Orientation* orientation) {
  ncsdk_Agent* self = malloc(sizeof(ncsdk_Agent));
  self->health = 0.0;
  self->inventory = ncsdk_Inventory_New();
  self->movement = ncsdk_Agent_MovementKind_Stopped;
  self->orientation = *orientation;
  self->position = *position;
  self->token = malloc(strlen(token) + 1);
  strcpy(self->token, token);
  self->type_id = 0;
  self->unique_id = unique_id;
  return self;
}

void ncsdk_Agent_Delete(ncsdk_Agent* self) {
  ncsdk_Inventory_Delete(self->inventory);
  free(self->token);
  free(self);
}

void ncsdk_Agent_Attack(ncsdk_Agent* self,
                        enum ncsdk_Agent_InteractionKind kind) {
  // TODO: Send attack event to server.
}

float ncsdk_Agent_GetHealth(const struct ncsdk_Agent* self) {
  return self->health;
}

const struct ncsdk_Inventory* ncsdk_Agent_GetInventory(
    const ncsdk_Agent* self) {
  return self->inventory;
}

enum ncsdk_Agent_MovementKind ncsdk_Agent_GetMovement(const ncsdk_Agent* self) {
  return self->movement;
}

const ncsdk_Orientation* ncsdk_Agent_GetOrientation(const ncsdk_Agent* self) {
  return &self->orientation;
}

const ncsdk_Position(float) * ncsdk_Agent_GetPosition(const ncsdk_Agent* self) {
  return &self->position;
}

const char* ncsdk_Agent_GetToken(const ncsdk_Agent* self) {
  return self->token;
}

int ncsdk_Agent_GetTypeId(const ncsdk_Agent* self) { return self->type_id; }

int ncsdk_Agent_GetUniqueId(const ncsdk_Agent* self) { return self->unique_id; }

void ncsdk_Agent_Jump(ncsdk_Agent* self) {
  // TODO: Send jump event to server.
}

void ncsdk_Agent_LookAt(ncsdk_Agent* self,
                        const ncsdk_Position(float) * position) {
  // TODO: Send look at event to server.
}

void ncsdk_Agent_SetMovement(ncsdk_Agent* self,
                             enum ncsdk_Agent_MovementKind movement) {
  // TODO: Send movement event to server.
}

void ncsdk_Agent_Use(ncsdk_Agent* self, enum ncsdk_Agent_InteractionKind kind) {
  // TODO: Send use event to server.
}
