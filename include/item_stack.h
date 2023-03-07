/// @file item_stack.h
/// @brief NovelCraft ItemStack interfaces

#ifndef NOVELCRAFT_SDK_ITEM_STACK_H_
#define NOVELCRAFT_SDK_ITEM_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Represents a stack of items.
struct ncsdk_ItemStack;

/// @brief Gets the count of items in the stack.
/// @param item_stack The item stack.
/// @return The count of items in the stack.
int ncsdk_ItemStack_GetCount(const struct ncsdk_ItemStack* item_stack);

/// @brief Gets the type ID of the items.
/// @param item_stack The item stack.
/// @return The type ID.
int ncsdk_ItemStack_GetTypeID(const struct ncsdk_ItemStack* item_stack);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_ITEM_STACK_H_