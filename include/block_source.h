/// @file block_source.h
/// @brief NovelCraft BlockSource interfaces

#ifndef NOVELCRAFT_SDK_BLOCK_SOURCE_H_
#define NOVELCRAFT_SDK_BLOCK_SOURCE_H_

#ifdef __cplusplus
extern "C" {
#endif



/// @struct ncsdk_BlockSource
/// @brief Represents a collection of blocks.
struct ncsdk_BlockSource;

/// @brief Gets the block at the position.
/// @param block_source The block source.
/// @param position The position.
/// @return The block, or NULL if not found.
const struct ncsdk_Block* ncsdk_BlockSource_Get(
    const struct ncsdk_BlockSource* block_source,
    const struct ncsdk_Position_Int* position);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_BLOCK_SOURCE_H_