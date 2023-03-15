/// @file logger.h
/// @brief NovelCraft Logger interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

/// @struct ncsdk_Logger
/// @brief Logger provides logging functionality.
struct ncsdk_Logger;

/// @brief Creates a new logger instance.
/// @param logging_namespace The namespace to use for logging.
/// @return A new logger instance.
struct ncsdk_Logger* ncsdk_Logger_New(const char* logging_namespace);

/// @brief Deletes a logger instance.
/// @param logger The logger instance to delete.
void ncsdk_Logger_Delete(struct ncsdk_Logger* self);

/// @brief Logs a debug message.
/// @param self The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
void ncsdk_Logger_Debug(const struct ncsdk_Logger* self, const char* format,
                        ...);

/// @brief Logs an info message.
/// @param self The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
void ncsdk_Logger_Info(const struct ncsdk_Logger* self, const char* format,
                       ...);

/// @brief Logs a warning message.
/// @param self The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
void ncsdk_Logger_Warn(const struct ncsdk_Logger* self, const char* format,
                       ...);

/// @brief Logs an error message.
/// @param self The logger instance.
/// @param format The message format.
/// @param ... The format arguments.
void ncsdk_Logger_Error(const struct ncsdk_Logger* self, const char* format,
                        ...);

#ifdef __cplusplus
}
#endif