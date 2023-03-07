#ifndef NOVELCRAFT_SDK_INTERNAL_LOGGER_H_
#define NOVELCRAFT_SDK_INTERNAL_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_Logger {
  const char* logging_namespace;
};

/// @brief Creates a new logger instance.
/// @param logging_namespace The namespace to use for logging.
/// @return A new logger instance.
struct ncsdk_Logger* ncsdk_Logger_New(const char* logging_namespace);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_INTERNAL_LOGGER_H_