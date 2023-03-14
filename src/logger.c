#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include "internal/logger.h"

struct ncsdk_Logger {
  const char* logging_namespace;
};

/// @brief The color to use for console output.
enum ncsdk_Logger_ConsoleColor {
  ncsdk_Logger_ConsoleColor_Cyan,    // Cyan
  ncsdk_Logger_ConsoleColor_Blue,    // Blue
  ncsdk_Logger_ConsoleColor_Gray,    // Gray
  ncsdk_Logger_ConsoleColor_White,   // White
  ncsdk_Logger_ConsoleColor_Yellow,  // Yellow
  ncsdk_Logger_ConsoleColor_Red,     // Red
};

/// @brief Gets the current time string.
/// @param time_string The time string.
static void ncsdk_Logger_GetCurrentTimeString(char time_string[9]);

/// @brief Prints a message with the specified color.
/// @param color The color to use.
/// @param format The format string.
/// @param ... The arguments.
static void ncsdk_Logger_Print(enum ncsdk_Logger_ConsoleColor color,
                               const char* format, ...);

void ncsdk_Logger_Debug(const struct ncsdk_Logger logger, const char* format,
                        ...) {
#ifdef DEBUG
  char time_string[9];
  ncsdk_Logger_GetCurrentTimeString(time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Cyan, "%s ", time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Gray, "DEBUG [%s] ",
                     logger.logging_namespace);

  va_list args;
  va_start(args, format);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Gray, format, args);
  va_end(args);
#endif
}

void ncsdk_Logger_Info(const struct ncsdk_Logger logger, const char* format,
                       ...) {
  char time_string[9];
  ncsdk_Logger_GetCurrentTimeString(time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Cyan, "%s ", time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Blue, "INFO  ",
                     logger.logging_namespace);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_White, "[%s] ",
                     logger.logging_namespace);

  va_list args;
  va_start(args, format);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_White, format, args);
  va_end(args);
}

void ncsdk_Logger_Warn(const struct ncsdk_Logger logger, const char* format,
                       ...) {
  char time_string[9];
  ncsdk_Logger_GetCurrentTimeString(time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Cyan, "%s ", time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Yellow, "WARN  [%s] ",
                     logger.logging_namespace);

  va_list args;
  va_start(args, format);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Yellow, format, args);
  va_end(args);
}

void ncsdk_Logger_Error(const struct ncsdk_Logger logger, const char* format,
                        ...) {
  char time_string[9];
  ncsdk_Logger_GetCurrentTimeString(time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Cyan, "%s ", time_string);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Red, "ERROR [%s] ",
                     logger.logging_namespace);

  va_list args;
  va_start(args, format);
  ncsdk_Logger_Print(ncsdk_Logger_ConsoleColor_Red, format, args);
  va_end(args);
}

struct ncsdk_Logger ncsdk_Logger_New(const char* logging_namespace) {
  struct ncsdk_Logger logger = {.logging_namespace = logging_namespace};

  return logger;
}

static void ncsdk_Logger_GetCurrentTimeString(char time_string[9]) {
  time_t raw_time = time(NULL);
  strftime(time_string, sizeof time_string, "%H:%M:%S", localtime(&raw_time));
}

static void ncsdk_Logger_Print(enum ncsdk_Logger_ConsoleColor color,
                               const char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}