#include "list.h"

#include <stdlib.h>
#include <string.h>

#include "array.h"

struct ncsdk_List {
  ncsdk_Array* array;
  size_t size;
};

ncsdk_List* ncsdk_List_NewWithElementSize(size_t element_size) {
  ncsdk_List* list = malloc(sizeof(ncsdk_List));
  list->array = ncsdk_Array_NewWithElementSize(element_size, 1);
  list->size = 0;
  return list;
}

void ncsdk_List_Delete(ncsdk_List** self) {
  if (*self == NULL) {
    return;
  }

  ncsdk_Array_Delete(&(*self)->array);
  free(*self);
  *self = NULL;
}

void* ncsdk_List_AtWithoutType(ncsdk_List* self, size_t index) {
  if (index >= self->size) {
    return NULL;
  }

  return ncsdk_Array_AtWithoutType(self->array, index);
}

void ncsdk_List_Clear(ncsdk_List* self) { self->size = 0; }

void ncsdk_List_Fill(ncsdk_List* self, void* value) {
  ncsdk_Array_Fill(self->array, value);
}

void ncsdk_List_PopBack(ncsdk_List* self) {
  self->size = self->size > 0 ? self->size - 1 : 0;
}

void ncsdk_List_PushBackWithoutType(ncsdk_List* self, const void* element,
                                    size_t element_size) {
  if (self->size >= ncsdk_Array_Size(self->array)) {
    ncsdk_Array* new_array = ncsdk_Array_NewWithElementSize(
        element_size, ncsdk_Array_Size(self->array) * 2);
    memcpy(ncsdk_Array_AtWithoutType(new_array, 0),
           ncsdk_Array_AtWithoutType(self->array, 0),
           ncsdk_Array_Size(self->array) * element_size);
    ncsdk_Array_Delete(&self->array);
    self->array = new_array;
  }

  void* dest = ncsdk_Array_AtWithoutType(self->array, self->size);
  memcpy(dest, element, element_size);
  ++self->size;
}

size_t ncsdk_List_Size(ncsdk_List* self) { return self->size; }