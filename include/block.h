/// @file block.h
/// @brief NovelCraft Block interfaces

#ifndef NOVELCRAFT_SDK_BLOCK_H_
#define NOVELCRAFT_SDK_BLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"

/// @struct ncsdk_Block
/// @brief Represents a block.
NCSDK_EXPORT struct ncsdk_Block;

/// @brief Gets the block's position
/// @param block The block.
/// @return The block's position.
NCSDK_EXPORT const struct ncsdk_Position_Int* ncsdk_Block_GetPosition(
    const struct ncsdk_Block* block);

/// @brief Gets the block's type ID.
/// @param block The block.
/// @return The block's type ID.
NCSDK_EXPORT int ncsdk_Block_GetTypeId(const struct ncsdk_Block* block);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_BLOCK_H_