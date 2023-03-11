/// @file logger.h
/// @brief NovelCraft Logger interfaces

#ifndef NOVELCRAFT_SDK_LOGGER_H_
#define NOVELCRAFT_SDK_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"

/// @struct ncsdk_Logger
/// @brief Logger interface provides logging functionality.
NCSDK_EXPORT struct ncsdk_Logger;

/// @brief Logs a debug message.
/// @param logger The logger instance.
/// @param message The message to log.
NCSDK_EXPORT void ncsdk_Logger_Debug(const struct ncsdk_Logger* logger,
                                     const char* message);

/// @brief Logs an info message.
/// @param logger The logger instance.
/// @param message The message to log.
NCSDK_EXPORT void ncsdk_Logger_Info(const struct ncsdk_Logger* logger,
                                    const char* message);

/// @brief Logs a warning message.
/// @param logger The logger instance.
/// @param message The message to log.
NCSDK_EXPORT void ncsdk_Logger_Warning(const struct ncsdk_Logger* logger,
                                       const char* message);

/// @brief Logs an error message.
/// @param logger The logger instance.
/// @param message The message to log.
NCSDK_EXPORT void ncsdk_Logger_Error(const struct ncsdk_Logger* logger,
                                     const char* message);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_LOGGER_H_