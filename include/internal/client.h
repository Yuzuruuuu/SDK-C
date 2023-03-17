#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "internal/message.h"

struct ncsdk_Client {
  struct ncsdk_Logger* logger;
  char* url;
};
typedef struct ncsdk_Client ncsdk_Client;

ncsdk_Client* ncsdk_Client_New(const char* host, int port);

void ncsdk_Client_Delete(struct ncsdk_Client* self);

void ncsdk_Client_RegisterMessageHandler(ncsdk_Client* self,
                                         void (*handler)(const ncsdk_Message*));

void ncsdk_Client_Send(ncsdk_Client* self, const ncsdk_Message* message);

#ifdef __cplusplus
}
#endif