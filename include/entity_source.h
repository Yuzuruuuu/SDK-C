/// @file entity_source.h
/// @brief NovelCraft EntitySource interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "entity.h"

/// @struct ncsdk_EntitySource
/// @brief Represents a collection of entities.
struct ncsdk_EntitySource;
typedef struct ncsdk_EntitySource ncsdk_EntitySource;

/// @brief Gets the entity with the unique ID.
/// @param entity_source The entity source.
/// @param unique_id The unique ID.
/// @return The entity, or NULL if not found.
const ncsdk_Entity* ncsdk_EntitySource_GetEntity(
    const ncsdk_EntitySource* entity_source, int unique_id);

#ifdef __cplusplus
}
#endif