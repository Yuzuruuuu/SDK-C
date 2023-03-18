#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "list.h"
#include "message.h"

struct ncsdk_Client {
  float bandwidth;
  struct ncsdk_Logger* logger;
  ncsdk_List* message_handlers;
  char* url;
};
typedef struct ncsdk_Client ncsdk_Client;

ncsdk_Client* ncsdk_Client_New(const char* host, int port);

void ncsdk_Client_Delete(struct ncsdk_Client* self);

float ncsdk_Client_GetBandwidth(ncsdk_Client* self);

void ncsdk_Client_RegisterMessageHandler(ncsdk_Client* self,
                                         void (*handler)(const ncsdk_Message*));

void ncsdk_Client_Send(ncsdk_Client* self, const ncsdk_Message* message);

#ifdef __cplusplus
}
#endif
