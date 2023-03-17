#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_Client {
  struct ncsdk_Logger* logger;
  char* url;
};

struct ncsdk_Client* ncsdk_Client_New(const char* host, int port);

void ncsdk_Client_Delete(struct ncsdk_Client* self);

#ifdef __cplusplus
}
#endif