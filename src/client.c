#include "internal/client.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "logger.h"

#ifdef _MSC_VER
#include "internal/msvc_wshelper.h"
#else
#include <wshelper.h>
#endif

static void TryConnect();

struct ncsdk_Client* ncsdk_Client_New(const char* host, int port) {
  struct ncsdk_Client* client = malloc(sizeof(struct ncsdk_Client));

  client->bandwidth = 0.0f;

  client->logger = ncsdk_Logger_New("Sdk.Client");

  client->message_handlers = ncsdk_List_New(void*);

  char url[256];
  sprintf(url, "ws://%s:%d", host, port);

  client->url = malloc(strlen(url) + 1);
  strcpy(client->url, url);

  Launch();
  TryConnect(client);

  return client;
}

void ncsdk_Client_Delete(ncsdk_Client* self) {
  Disconnect();
  Terminate();

  ncsdk_Logger_Delete(self->logger);
  ncsdk_List_Delete(self->message_handlers);
  free(self->url);

  free(self);
}

float ncsdk_Client_GetBandwidth(ncsdk_Client* self) { return self->bandwidth; }

void ncsdk_Client_RegisterMessageHandler(
    ncsdk_Client* self, void (*handler)(const ncsdk_Message*)) {
  ncsdk_List_PushBack(self->message_handlers, (void*)handler);
}

static void TryConnect(const ncsdk_Client* self) {
  if ((bool)IsConnected()) {
    ncsdk_Logger_Warn(self->logger, "Already connected");
    return;
  }

  int status = 0;
  do {
    char msg[256];
    sprintf("Trying to connect to server at %s...", self->url);
    ncsdk_Logger_Info(self->logger, msg);

    status = Connect(self->url);
    if (status != 0) {
      ncsdk_Logger_Error(self->logger, "Failed to connect to server");
      ncsdk_Logger_Info(self->logger, "Retrying...");
    }

  } while (status != 0);
}