#include "internal/client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "logger.h"

struct ncsdk_Client* ncsdk_Client_New(const char* host, int port) {
  struct ncsdk_Client* client = malloc(sizeof(struct ncsdk_Client));

  client->bandwidth = 0.0f;

  client->logger = ncsdk_Logger_New("Sdk.Client");

  client->message_handlers = ncsdk_List_New(void*);

  return client;
}

void ncsdk_Client_Delete(struct ncsdk_Client* self) {
  ncsdk_Logger_Delete(self->logger);
  ncsdk_List_Delete(self->message_handlers);

  free(self);
}

float ncsdk_Client_GetBandwidth(ncsdk_Client* self) {
  return self->bandwidth;
}

void ncsdk_Client_RegisterMessageHandler(
    ncsdk_Client* self, void (*handler)(const ncsdk_Message*)) {
  ncsdk_List_PushBack(self->message_handlers, (void*)handler);
}