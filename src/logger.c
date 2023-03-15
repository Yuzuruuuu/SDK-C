#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define TIME_STRING_LENGTH 9

struct ncsdk_Logger {
  char* logging_namespace;
};

/// @brief The color to use for console output.
enum ncsdk_Logger_ConsoleColor {
  ncsdk_Logger_ConsoleColor_kCyan,    // Cyan
  ncsdk_Logger_ConsoleColor_kBlue,    // Blue
  ncsdk_Logger_ConsoleColor_kGray,    // Gray
  ncsdk_Logger_ConsoleColor_kWhite,   // White
  ncsdk_Logger_ConsoleColor_kYellow,  // Yellow
  ncsdk_Logger_ConsoleColor_kRed,     // Red
};

/// @brief Gets the current time string.
/// @param time_string The time string.
static void GetCurrentTimeString(char time_string[9]);

/// @brief Prints a message with the specified color.
/// @param color The color to use.
/// @param format The format string.
/// @param ... The arguments.
static void Print(enum ncsdk_Logger_ConsoleColor color, const char* format,
                  ...);

struct ncsdk_Logger* ncsdk_Logger_New(const char* logging_namespace) {
  struct ncsdk_Logger* self =
      (struct ncsdk_Logger*)malloc(sizeof(struct ncsdk_Logger));

  self->logging_namespace = malloc(strlen(logging_namespace) + 1);
  strcpy(self->logging_namespace, logging_namespace);

  return self;
}

void ncsdk_Logger_Delete(struct ncsdk_Logger* self) {
  free(self->logging_namespace);
  free(self);
}

void ncsdk_Logger_Debug(const struct ncsdk_Logger* self, const char* format,
                        ...) {
#ifndef DEBUG
  return;
#endif

  char time_string[9];
  GetCurrentTimeString(time_string);
  Print(ncsdk_Logger_ConsoleColor_kCyan, "%s ", time_string);
  Print(ncsdk_Logger_ConsoleColor_kGray, "DEBUG [%s] ",
        self->logging_namespace);

  va_list args;
  va_start(args, format);
  Print(ncsdk_Logger_ConsoleColor_kGray, format, args);
  va_end(args);

  Print(ncsdk_Logger_ConsoleColor_kGray, "\n");
}

void ncsdk_Logger_Info(const struct ncsdk_Logger* self, const char* format,
                       ...) {
  char time_string[9];
  GetCurrentTimeString(time_string);
  Print(ncsdk_Logger_ConsoleColor_kCyan, "%s ", time_string);
  Print(ncsdk_Logger_ConsoleColor_kBlue, "INFO  ");
  Print(ncsdk_Logger_ConsoleColor_kWhite, "[%s] ", self->logging_namespace);

  va_list args;
  va_start(args, format);
  Print(ncsdk_Logger_ConsoleColor_kWhite, format, args);
  va_end(args);

  Print(ncsdk_Logger_ConsoleColor_kWhite, "\n");
}

void ncsdk_Logger_Warn(const struct ncsdk_Logger* self, const char* format,
                       ...) {
  char time_string[9];
  GetCurrentTimeString(time_string);
  Print(ncsdk_Logger_ConsoleColor_kCyan, "%s ", time_string);
  Print(ncsdk_Logger_ConsoleColor_kYellow, "WARN  [%s] ",
        self->logging_namespace);

  va_list args;
  va_start(args, format);
  Print(ncsdk_Logger_ConsoleColor_kYellow, format, args);
  va_end(args);

  Print(ncsdk_Logger_ConsoleColor_kYellow, "\n");
}

void ncsdk_Logger_Error(const struct ncsdk_Logger* self, const char* format,
                        ...) {
  char time_string[9];
  GetCurrentTimeString(time_string);
  Print(ncsdk_Logger_ConsoleColor_kCyan, "%s ", time_string);
  Print(ncsdk_Logger_ConsoleColor_kRed, "ERROR [%s] ", self->logging_namespace);

  va_list args;
  va_start(args, format);
  Print(ncsdk_Logger_ConsoleColor_kRed, format, args);
  va_end(args);

  Print(ncsdk_Logger_ConsoleColor_kRed, "\n");
}

static void GetCurrentTimeString(char time_string[TIME_STRING_LENGTH]) {
  time_t raw_time = time(NULL);
  strftime(time_string, TIME_STRING_LENGTH, "%H:%M:%S", localtime(&raw_time));
}

static void Print(enum ncsdk_Logger_ConsoleColor color, const char* format,
                  ...) {
#ifdef _WIN32
  HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  switch (color) {
    case ncsdk_Logger_ConsoleColor_kCyan:
      SetConsoleTextAttribute(console_handle, FOREGROUND_BLUE |
                                                  FOREGROUND_GREEN |
                                                  FOREGROUND_INTENSITY);
      break;
    case ncsdk_Logger_ConsoleColor_kBlue:
      SetConsoleTextAttribute(console_handle,
                              FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      break;
    case ncsdk_Logger_ConsoleColor_kGray:
      SetConsoleTextAttribute(
          console_handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
      break;
    case ncsdk_Logger_ConsoleColor_kWhite:
      SetConsoleTextAttribute(
          console_handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED |
                              FOREGROUND_INTENSITY);
      break;
    case ncsdk_Logger_ConsoleColor_kYellow:
      SetConsoleTextAttribute(console_handle, FOREGROUND_GREEN |
                                                  FOREGROUND_RED |
                                                  FOREGROUND_INTENSITY);
      break;
    case ncsdk_Logger_ConsoleColor_kRed:
      SetConsoleTextAttribute(console_handle,
                              FOREGROUND_RED | FOREGROUND_INTENSITY);
      break;
  }

#else
  // For UNIX systems, we can use ANSI escape codes to color the output.
  switch (color) {
    case ncsdk_Logger_ConsoleColor_kCyan:
      printf("\033[36m");
      break;
    case ncsdk_Logger_ConsoleColor_kBlue:
      printf("\033[34m");
      break;
    case ncsdk_Logger_ConsoleColor_kGray:
      printf("\033[38;5;8m");
      break;
    case ncsdk_Logger_ConsoleColor_kWhite:
      printf("\033[97m");
      break;
    case ncsdk_Logger_ConsoleColor_kYellow:
      printf("\033[33m");
      break;
    case ncsdk_Logger_ConsoleColor_kRed:
      printf("\033[31m");
      break;
  }
#endif

  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

#ifdef _WIN32
  SetConsoleTextAttribute(console_handle,
                          FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

#else
  // For UNIX systems, we can use ANSI escape codes to color the output.
  printf("\033[0m");
#endif
}