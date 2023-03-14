/// @file position.h
/// @brief NovelCraft Position interfaces

#ifndef NOVELCRAFT_SDK_POSITION_H_
#define NOVELCRAFT_SDK_POSITION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ncsdk_export.h"

/// @brief Represents a position with integer values in the world.
struct ncsdk_Position_Int {
  int x, y, z;
};

/// @brief Represents a position with floating point values in the world.
struct ncsdk_Position_Float {
  float x, y, z;
};

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_POSITION_H_