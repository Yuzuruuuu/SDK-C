/// @file block_source.h
/// @brief NovelCraft BlockSource interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "position.h"

/// @struct ncsdk_BlockSource
/// @brief Represents a collection of blocks.
struct ncsdk_BlockSource;

/// @brief Gets the block at the position.
/// @param block_source The block source.
/// @param position The position.
/// @return The block, or NULL if not found.
const struct ncsdk_Block* ncsdk_BlockSource_Get(
    const struct ncsdk_BlockSource* block_source,
    const ncsdk_Position(int) * position);

#ifdef __cplusplus
}
#endif