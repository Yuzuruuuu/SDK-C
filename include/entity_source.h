/// @file entity_source.h
/// @brief NovelCraft EntitySource interfaces

#ifndef NOVELCRAFT_SDK_ENTITY_SOURCE_H_
#define NOVELCRAFT_SDK_ENTITY_SOURCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"

/// @brief Represents a collection of entities.
NCSDK_EXPORT struct ncsdk_EntitySource;

/// @brief Gets the entity with the unique ID.
/// @param entity_source The entity source.
/// @param unique_id The unique ID.
/// @return The entity, or NULL if not found.
NCSDK_EXPORT const struct ncsdk_Entity* ncsdk_EntitySource_Get(
    const struct ncsdk_EntitySource* entity_source, int unique_id);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_ENTITY_SOURCE_H_