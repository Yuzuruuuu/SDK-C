/// @file logger.h
/// @brief NovelCraft Logger interfaces

#ifndef NOVELCRAFT_SDK_LOGGER_H_
#define NOVELCRAFT_SDK_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#include "ncsdk_export.h"

/// @struct ncsdk_Logger
/// @brief Logger provides logging functionality.
struct ncsdk_Logger;

/// @brief Logs a debug message.
/// @param logger The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
NCSDK_EXPORT void ncsdk_Logger_Debug(const struct ncsdk_Logger logger,
                                     const char* format, ...);

/// @brief Logs an info message.
/// @param logger The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
NCSDK_EXPORT void ncsdk_Logger_Info(const struct ncsdk_Logger logger,
                                    const char* format, ...);

/// @brief Logs a warning message.
/// @param logger The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
NCSDK_EXPORT void ncsdk_Logger_Warn(const struct ncsdk_Logger logger,
                                    const char* format, ...);

/// @brief Logs an error message.
/// @param logger The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
NCSDK_EXPORT void ncsdk_Logger_Error(const struct ncsdk_Logger logger,
                                     const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_LOGGER_H_