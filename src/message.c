#include "internal/message.h"

#include <json.h>
#include <stdio.h>

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

enum ncsdk_Message_BoundToKind ncsdk_Message_GetBoundTo(
    const struct ncsdk_Message* self) {
  struct json_object_s* object = json_value_as_object(self->json);
  for (struct json_object_element_s* element = object->start; element != NULL;
       element = element->next) {
    if (strcmp(element->name->string, "bound_to") == 0) {
      const char* number_string = json_value_as_number(element->value)->number;
      return (enum ncsdk_Message_BoundToKind)atoi(number_string);
    }
  }
  return ncsdk_Message_BoundToKind_Unknown;
}

enum ncsdk_Message_MessageKind ncsdk_Message_GetType(
    const struct ncsdk_Message* self) {
  struct json_object_s* object = json_value_as_object(self->json);
  for (struct json_object_element_s* element = object->start; element != NULL;
       element = element->next) {
    if (strcmp(element->name->string, "type") == 0) {
      const char* number_string = json_value_as_number(element->value)->number;
      return (enum ncsdk_Message_MessageKind)atoi(number_string);
    }
  }
  return ncsdk_Message_MessageKind_Unknown;
}