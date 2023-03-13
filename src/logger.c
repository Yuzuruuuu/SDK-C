#include "internal/logger.h"

#include <stdio.h>

static enum ncsdk_Logger_ConsoleColor {
  ncsdk_Logger_ConsoleColor_Cyan,
  ncsdk_Logger_ConsoleColor_Gray,
  ncsdk_Logger_ConsoleColor_White,
  ncsdk_Logger_ConsoleColor_Yellow,
  ncsdk_Logger_ConsoleColor_Red,
};

struct ncsdk_Logger {
  const char* logging_namespace;
};


void ncsdk_Logger_Debug(const struct ncsdk_Logger logger, const char* message) {
  
}

struct ncsdk_Logger ncsdk_Logger_New(const char* logging_namespace) {
  struct ncsdk_Logger logger = {.logging_namespace = logging_namespace};

  return logger;
}