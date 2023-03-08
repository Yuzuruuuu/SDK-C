/// @file inventory.h
/// @brief NovelCraft Inventory interfaces

#ifndef NOVELCRAFT_SDK_INVENTORY_H_
#define NOVELCRAFT_SDK_INVENTORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "item_stack.h"
#include "ncsdk_export.h"

/// @brief Represents an inventory.
NCSDK_EXPORT struct ncsdk_Inventory;

/// @brief Gets the item in a slot.
/// @param inventory The inventory.
/// @param slot The slot.
/// @return The item in the slot. Or NULL if the slot is empty.
NCSDK_EXPORT const struct ncsdk_ItemStack* ncsdk_Inventory_Get(
    const struct ncsdk_Inventory* inventory, int slot);

/// @brief Gets the number of slots in the hot bar.
/// @param inventory The inventory.
/// @return The number of slots in the hot bar.
NCSDK_EXPORT int ncsdk_Inventory_GetHotBarSize(
    const struct ncsdk_Inventory* inventory);

/// @brief Gets the slot that the main hand is currently in.
/// @param inventory The inventory.
/// @return The slot that the main hand is currently in.
NCSDK_EXPORT int ncsdk_Inventory_GetMainHandSlot(
    const struct ncsdk_Inventory* inventory);

/// @brief Sets the slot that the main hand is currently in.
/// @param inventory The inventory.
/// @param slot The slot that the main hand is currently in.
NCSDK_EXPORT void ncsdk_Inventory_SetMainHandSlot(
    struct ncsdk_Inventory* inventory, int slot);

/// @brief Gets the number of slots in the inventory.
/// @param inventory The inventory.
/// @return The number of slots in the inventory.
NCSDK_EXPORT int ncsdk_Inventory_GetSize(
    const struct ncsdk_Inventory* inventory);

/// @brief Drops items from a slot.
/// @param inventory The inventory.
/// @param slot The slot.
/// @param count The number of items to drop.
NCSDK_EXPORT void ncsdk_Inventory_DropItem(struct ncsdk_Inventory* inventory,
                                           int slot, int count);

/// @brief Merges items from two slots into one slot.
/// @param inventory The inventory.
/// @param from_slot The slot to merge from.
/// @param to_slot The slot to merge to.
/// @note If the items in the two slots are not the same type, nothing happens.
/// If the number of items in the two slots is greater than the maximum stack
/// size, toSlot will be filled to the maximum stack size and the remaining
/// items will be left in fromSlot.
NCSDK_EXPORT void ncsdk_Inventory_MergeSlots(struct ncsdk_Inventory* inventory,
                                             int from_slot, int to_slot);

/// @brief Swaps items between two slots.
/// @param inventory The inventory.
/// @param slot1 The first slot.
/// @param slot2 The second slot.
NCSDK_EXPORT void ncsdk_Inventory_SwapSlots(struct ncsdk_Inventory* inventory,
                                            int slot1, int slot2);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_INVENTORY_H_