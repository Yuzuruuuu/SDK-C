#include <internal/client.h>

int main() {
  ncsdk_Client* client = ncsdk_Client_New("localhost", 8080);
  ncsdk_Client_Delete(client);
  return 0;
}