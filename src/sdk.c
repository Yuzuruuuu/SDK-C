#include "sdk.h"

#include <stdlib.h>

#include "argparse.h"
#include "internal/logger.h"
#include "logger.h"
#include "types.h"

#define GET_INFO_INVERNAL 10000
#define PING_INTERVAL 1000

static struct ncsdk_Agent *agent_ = NULL;
static struct ncsdk_BlockSource *block_source_ = NULL;
static struct ncsdk_Client *client_ = NULL;
static struct ncsdk_EntitySource *entity_source_ = NULL;
static ncsdk_OptionalFloat latency_ = {0.0f, false};
static struct ncsdk_Logger *sdk_logger_ = NULL;
static ncsdk_OptionalFloat ticks_per_second_ = {0.0f, false};
static struct ncsdk_Logger *user_logger_ = NULL;
static char *token_ = NULL;

const struct ncsdk_Logger *ncsdk_GetLogger() { return sdk_logger_; }

void ncsdk_Initialize(int argc, char *argv[]) {
  sdk_logger_ = ncsdk_Logger_New("Sdk");
  user_logger_ = ncsdk_Logger_New("User");

  ncsdk_Logger_Info(sdk_logger_, "Initializing SDK...");

  const char *host = "localhost";
  int port = 14514;

  struct argparse_option options[] = {
      OPT_STRING('\0', "token", &token_, "Token to use for authentication",
                 NULL, 0, 0),
      OPT_STRING('\0', "host", &host, "Host to connect to", NULL, 0, 0),
      OPT_INTEGER('\0', "port", &port, "Port to connect to", NULL, 0, 0),
      OPT_END(),
  };

  struct argparse argparse;
  argparse_init(&argparse, options, NULL, 0);
  argparse_parse(&argparse, argc, argv);
}

void ncsdk_Finalize() {
  // If the SDK is not initialized, directly exit.
  if (sdk_logger_ == NULL || user_logger_ == NULL) {
    exit(1);
  }

  ncsdk_Logger_Info(sdk_logger_, "Finalizing SDK...");

  ncsdk_Logger_Delete(user_logger_);
  user_logger_ = NULL;

  ncsdk_Logger_Delete(sdk_logger_);
  sdk_logger_ = NULL;
}