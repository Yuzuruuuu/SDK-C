#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_Inventory {
  ncsdk_Array* item_stack_array;
  size_t size;
  size_t hot_bar_size;
  size_t main_hand_slot;
};

struct ncsdk_Inventory* ncsdk_Inventory_New();

void ncsdk_Inventory_Delete(struct ncsdk_Inventory* self);

#ifdef __cplusplus
}
#endif