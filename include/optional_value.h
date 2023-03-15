/// @file optional_value.h
/// @brief Optional value types.

#ifndef NOVELCRAFT_SDK_OPTIONAL_VALUE_H_
#define NOVELCRAFT_SDK_OPTIONAL_VALUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/// @brief Optional char.
typedef struct {
  char value;
  bool is_set;
} ncsdk_OptionalChar;

/// @brief Optional int.
typedef struct {
  int value;
  bool is_set;
} ncsdk_OptionalInt;

/// @brief Optional float.
typedef struct {
  float value;
  bool is_set;
} ncsdk_OptionalFloat;

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_OPTIONAL_VALUE_H_