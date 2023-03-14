#include "client.h"

#include "internal/client.h"
#include "internal/logger.h"
#include "logger.h"

struct ncsdk_Client {
  struct ncsdk_Logger* logger;
};


// struct ncsdk_Client* ncsdk_Client_New(const char* host, int port) {
//   struct ncsdk_Client* client = malloc(sizeof(struct ncsdk_Client));
//   client->logger = ncsdk_Logger_New("Sdk.Client");

//   // TODO

//   return client;
// }