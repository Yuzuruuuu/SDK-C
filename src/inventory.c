

#include "internal/inventory.h"

#include <stdlib.h>

#include "array.h"
#include "internal/item_stack.h"

#define SIZE 36
#define HOTBAR_SIZE 9

struct ncsdk_Inventory* ncsdk_Inventory_New() {
  struct ncsdk_Inventory* self = malloc(sizeof(struct ncsdk_Inventory));
  self->item_stack_array = ncsdk_Array_New(struct ncsdk_ItemStack, SIZE);
  self->size = SIZE;
  self->hot_bar_size = HOTBAR_SIZE;
  self->main_hand_slot = 0;
  return self;
}

void ncsdk_Inventory_Delete(struct ncsdk_Inventory* self) {
  ncsdk_Array_Delete(self->item_stack_array);
  free(self);
}

const struct ncsdk_ItemStack* ncsdk_Inventory_Get(
    const struct ncsdk_Inventory* self, int slot) {
  return ncsdk_Array_At(struct ncsdk_ItemStack, self->item_stack_array, slot);
}

size_t ncsdk_Inventory_GetHotBarSize(const struct ncsdk_Inventory* self) {
  return self->hot_bar_size;
}

size_t ncsdk_Inventory_GetMainHandSlot(const struct ncsdk_Inventory* self) {
  return self->main_hand_slot;
}

void ncsdk_Inventory_SetMainHandSlot(struct ncsdk_Inventory* self, int slot) {
  self->main_hand_slot = slot;

  // TODO: Send packet to server.
}

size_t ncsdk_Inventory_GetSize(const struct ncsdk_Inventory* self) {
  return self->size;
}

void ncsdk_Inventory_DropItem(struct ncsdk_Inventory* self, int slot,
                              int count) {
  // TODO: Send packet to server.
}

void ncsdk_Inventory_MergeSlots(struct ncsdk_Inventory* self, int from_slot,
                                int to_slot) {
  // TODO: Send packet to server.
}

void ncsdk_Inventory_SwapSlots(struct ncsdk_Inventory* self, int slot1,
                               int slot2) {
  // TODO: Send packet to server.
}
