/// @file sdk.h
/// @brief NovelCraft SDK interfaces

#ifdef __cplusplus
extern "C" {
#endif

#include "agent.h"
#include "block_source.h"
#include "client.h"
#include "entity_source.h"
#include "logger.h"
#include "optional.h"

/// @brief Initializes the SDK.
/// @param argc The number of arguments.
void ncsdk_Initialize(int argc, char *argv[]);

/// @brief Finalizes the SDK.
void ncsdk_Finalize();

/// @brief Gets the agent representing the player controlled by the user.
/// @return The agent.
struct ncsdk_Agent *ncsdk_GetAgent();

/// @brief Gets the block collection.
/// @return The block collection.
const struct ncsdk_BlockSource *ncsdk_GetBlocks();

/// @brief Gets the client for sending and receiving messages directly to or
/// from the server.
/// @return The client.
struct ncsdk_Client *ncsdk_GetClient();

/// @brief Gets the entity collection.
/// @return The entity collection.
const struct ncsdk_EntitySource *ncsdk_GetEntities();

/// @brief Gets the logger.
/// @return The logger.
const struct ncsdk_Logger *ncsdk_GetLogger();

/// @brief Gets the current tick.
/// @return The current tick. -1 if no tick information is received.
ncsdk_Optional(int) ncsdk_GetTick();

/// @brief Gets the number of ticks per second.
/// @return The number of ticks per second. -1.0 if no tick information is
/// received.
ncsdk_Optional(float) ncsdk_GetTicksPerSecond();

#ifdef __cplusplus
}
#endif