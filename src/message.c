#include "internal/message.h"

#include <jansson.h>
#include <stdio.h>

struct ncsdk_Message* ncsdk_Message_New(const char* json_string) {
  struct json_t* json = json_loads(json_string, 0, NULL);

  struct ncsdk_Message* self = malloc(sizeof(struct ncsdk_Message));
  self->json = json;
  return self;
}

void ncsdk_Message_Delete(struct ncsdk_Message* self) {
  free(self->json);
  free(self);
}

const struct json_t* ncsdk_Message_GetJson(
    const struct ncsdk_Message* self) {
  return self->json;
}

enum ncsdk_Message_BoundToKind ncsdk_Message_GetBoundTo(
    const struct ncsdk_Message* self) {
  return ncsdk_Message_BoundToKind_Unknown;
}

enum ncsdk_Message_MessageKind ncsdk_Message_GetType(
    const struct ncsdk_Message* self) {
  return ncsdk_Message_MessageKind_Unknown;
}