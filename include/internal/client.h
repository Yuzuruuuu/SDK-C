#ifndef NOVELCRAFT_SDK_INTERNAL_CLIENT_H_
#define NOVELCRAFT_SDK_INTERNAL_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_Client;

struct ncsdk_Client* ncsdk_Client_New(const char* host, int port);

void ncsdk_Client_Delete(struct ncsdk_Client* client);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_INTERNAL_CLIENT_H_