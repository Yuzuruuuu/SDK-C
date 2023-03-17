/// @file client.h
/// @brief NovelCraft Client interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "message.h"

/// @struct ncsdk_Client
/// @brief Represents a client that can connect to a server.
struct ncsdk_Client;
typedef struct ncsdk_Client ncsdk_Client;

/// @brief Gets the bandwidth in Mbps.
/// @param self The client.
/// @return The bandwidth in Mbps.
float ncsdk_Client_GetBandwidth(ncsdk_Client* self);

/// @brief Registers a message handler.
/// @param client The client.
/// @param handler The handler.
void ncsdk_Client_RegisterMessageHandler(
    ncsdk_Client* self, void (*handler)(const ncsdk_Message*));

/// @brief Sends a message to the server.
/// @param client The client.
/// @param message The message.
void ncsdk_Client_Send(ncsdk_Client* self,
                       const ncsdk_Message* message);

#ifdef __cplusplus
}
#endif
