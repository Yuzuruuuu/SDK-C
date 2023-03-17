#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "array.h"

struct ncsdk_Inventory {
  ncsdk_Array* item_stack_array;
  size_t size;
  size_t hot_bar_size;
  size_t main_hand_slot;
};

struct ncsdk_Inventory* ncsdk_Inventory_New();

void ncsdk_Inventory_Delete(struct ncsdk_Inventory* self);

const struct ncsdk_ItemStack* ncsdk_Inventory_Get(
    const struct ncsdk_Inventory* self, int slot);

size_t ncsdk_Inventory_GetHotBarSize(const struct ncsdk_Inventory* self);

size_t ncsdk_Inventory_GetMainHandSlot(const struct ncsdk_Inventory* self);

void ncsdk_Inventory_SetMainHandSlot(struct ncsdk_Inventory* self, int slot);

size_t ncsdk_Inventory_GetSize(const struct ncsdk_Inventory* self);

void ncsdk_Inventory_DropItem(struct ncsdk_Inventory* self, int slot,
                              int count);

void ncsdk_Inventory_MergeSlots(struct ncsdk_Inventory* self, int from_slot,
                                int to_slot);

void ncsdk_Inventory_SwapSlots(struct ncsdk_Inventory* self, int slot1,
                               int slot2);

#ifdef __cplusplus
}
#endif