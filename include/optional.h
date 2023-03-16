/// @file optional_value.h
/// @brief Optional value types.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <time.h>

/// @brief Defines an optional value type.
/// @param type The type of the optional value.
#define ncsdk_Optional(type) struct ncsdk_Optional_##type

struct ncsdk_Optional_bool {
  bool value;
  bool has_value;
};

struct ncsdk_Optional_char {
  char value;
  bool has_value;
};

struct ncsdk_Optional_int {
  int value;
  bool has_value;
};

struct ncsdk_Optional_float {
  float value;
  bool has_value;
};

struct ncsdk_Optional_time_t {
  time_t value;
  bool has_value;
};

#ifdef __cplusplus
}
#endif