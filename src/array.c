#include "array.h"

#include <stdlib.h>

struct ncsdk_Array {
  void* data;
  size_t capacity;
  size_t element_size;
};

ncsdk_Array* ncsdk_Array_NewWithElementSize(size_t element_size, size_t capacity) {
  ncsdk_Array* array = malloc(sizeof(ncsdk_Array));
  array->data = calloc(capacity, element_size);
  array->capacity = capacity;
  array->element_size = element_size;
  return array;
}

void ncsdk_Array_Delete(ncsdk_Array* self) {
  free(self->data);
  free(self);
}

void* ncsdk_Array_At(ncsdk_Array* self, size_t index) {
  if (index >= self->capacity) {
    return NULL;
  }
  return (char*)self->data + index * self->element_size;
}

void ncsdk_Array_Fill(ncsdk_Array* self, void* value) {
  for (size_t i = 0; i < self->capacity; ++i) {
    void* element = ncsdk_Array_At(self, i);
    memcpy(element, value, self->element_size);
  }
}

size_t ncsdk_Array_Size(ncsdk_Array* self) {
  return self->capacity;
}