

#include "internal/message.h"

#include "json.h"

struct ncsdk_Message* ncsdk_Message_New(const char* json_string) {
  struct json_value_s* json = json_parse(json_string, strlen(json_string));

  struct ncsdk_Message* self = malloc(sizeof(struct ncsdk_Message));
  self->json = json;
  return self;
}

void ncsdk_Message_Delete(struct ncsdk_Message* self) {
  free(self->json);
  free(self);
}

const struct json_value_s* ncsdk_Message_GetJson(
    const struct ncsdk_Message* self) {
  return self->json;
}
