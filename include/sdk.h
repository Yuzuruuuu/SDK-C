/// @file sdk.h
/// @brief NovelCraft SDK interfaces

#ifndef NOVELCRAFT_SDK_SDK_H_
#define NOVELCRAFT_SDK_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"

#include "agent.h"
#include "block_source.h"
#include "client.h"
#include "config.h"
#include "entity_source.h"
#include "logger.h"

/// @brief Gets the agent representing the player controlled by the user.
/// @return The agent.
NCSDK_EXPORT struct ncsdk_Agent *ncsdk_GetAgent();

/// @brief Gets the block collection.
/// @return The block collection.
NCSDK_EXPORT const struct ncsdk_BlockSource *ncsdk_GetBlocks();

/// @brief Gets the client for sending and receiving messages directly to or
/// from the server.
/// @return The client.
NCSDK_EXPORT struct ncsdk_Client *ncsdk_GetClient();

/// @brief Gets the entity collection.
/// @return The entity collection.
NCSDK_EXPORT const struct ncsdk_EntitySource *ncsdk_GetEntities();

/// @brief Gets the logger.
/// @return The logger.
NCSDK_EXPORT const struct ncsdk_Logger *ncsdk_GetLogger();

/// @brief Gets the current tick.
/// @return The current tick. -1 if no tick information is received.
NCSDK_EXPORT int ncsdk_GetTick();

/// @brief Gets the number of ticks per second.
/// @return The number of ticks per second. -1 if no tick information is
/// received.
NCSDK_EXPORT int ncsdk_GetTicksPerSecond();

/// @brief Initializes the SDK.
/// @param config The configuration.
NCSDK_EXPORT void ncsdk_Initialize(const struct ncsdk_Config *config);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_SDK_H_