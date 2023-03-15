/// @file block.h
/// @brief NovelCraft Block interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/// @struct ncsdk_Block
/// @brief Represents a block.
struct ncsdk_Block;

/// @brief Gets the block's position
/// @param block The block.
/// @return The block's position.
const struct ncsdk_Position_Int* ncsdk_Block_GetPosition(
    const struct ncsdk_Block* block);

/// @brief Gets the block's type ID.
/// @param block The block.
/// @return The block's type ID.
int ncsdk_Block_GetTypeId(const struct ncsdk_Block* block);

#ifdef __cplusplus
}
#endif