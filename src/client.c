#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "internal/client.h"
#include "internal/logger.h"
#include "logger.h"

struct ncsdk_Client {
  struct ncsdk_Logger* logger;
  char* url;
};

struct ncsdk_Client* ncsdk_Client_New(const char* host, int port) {
  struct ncsdk_Client* client = malloc(sizeof(struct ncsdk_Client));
  client->logger = ncsdk_Logger_New("Sdk.Client");

  char port_string[6];
  sprintf(port_string, "%d", port);

  client->url = malloc(strlen(host) + strlen(port_string) + 2);

  strcpy(client->url, host);
  strcat(client->url, ":");
  strcat(client->url, port_string);

  return client;
}

void ncsdk_Client_Delete(struct ncsdk_Client* client) {
  ncsdk_Logger_Delete(client->logger);
  free(client->url);

  free(client);
}