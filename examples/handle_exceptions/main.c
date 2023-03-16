#include <e4c.h>

#include "sdk.h"

#include "array.h"

void HandleException(void (*func)()) {
  try {
    func();
  } catch (RuntimeException) {
    const e4c_exception *e = e4c_get_exception();
    ncsdk_Logger_Error(ncsdk_GetLogger(), "Name: %s, message: %s",
                       e->type->name, e->name, e->message);
  }
}

void TryArrayOutOfBounds() {
  int *array = malloc(sizeof(int) * 10);
  array[100000000] = 0;
}

E4C_DEFINE_EXCEPTION(CustomException, "Custom exception", RuntimeException);

void TryCustomException() {
  throw(CustomException, "Custom exception");
}

void TryNullPointer() {
  int *a = NULL;
  *a = 0;
}

int main(int argc, char *argv[]) {
  ncsdk_Initialize(argc, argv);

  HandleException(TryArrayOutOfBounds);
  HandleException(TryCustomException);
  HandleException(TryNullPointer);

  ncsdk_Finalize();
  return 0;
}