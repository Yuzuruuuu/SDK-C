/// @file client.h
/// @brief NovelCraft Client interfaces

#ifndef NOVELCRAFT_SDK_CLIENT_H_
#define NOVELCRAFT_SDK_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "message.h"


/// @struct ncsdk_Client
/// @brief Represents a client that can connect to a server.
struct ncsdk_Client;

/// @brief Registers a message handler.
/// @param client The client.
/// @param handler The handler.
void ncsdk_Client_RegisterMessageHandler(
    struct ncsdk_Client* client, void (*handler)(const struct ncsdk_Message*));

/// @brief Sends a message to the server.
/// @param client The client.
/// @param message The message.
void ncsdk_Client_Send(struct ncsdk_Client* client,
                                    const struct ncsdk_Message* message);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_CLIENT_H_