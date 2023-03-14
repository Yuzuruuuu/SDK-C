/// @file entity.h
/// @brief NovelCraft Entity interfaces

#ifndef NOVELCRAFT_SDK_ENTITY_H_
#define NOVELCRAFT_SDK_ENTITY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"
#include "orientation.h"
#include "position.h"

/// @struct ncsdk_Entity
/// @brief Represents an entity.
struct ncsdk_Entity;

/// @brief Gets the entity's orientation.
/// @param entity The entity.
/// @return The entity's orientation.
NCSDK_EXPORT const struct ncsdk_Orientation* ncsdk_Entity_GetOrientation(
    const struct ncsdk_Entity* entity);

/// @brief Gets the entity's position.
/// @param entity The entity.
/// @return The entity's position.
NCSDK_EXPORT const struct ncsdk_Position_Float* ncsdk_Entity_GetPosition(
    const struct ncsdk_Entity* entity);

/// @brief Gets the entity's type ID.
/// @param entity The entity.
/// @return The entity's type ID.
NCSDK_EXPORT int ncsdk_Entity_GetTypeId(const struct ncsdk_Entity* entity);

/// @brief Gets the entity's unique ID.
/// @param entity The entity.
/// @return The entity's unique ID.
NCSDK_EXPORT int ncsdk_Entity_GetUniqueId(const struct ncsdk_Entity* entity);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_ENTITY_H_