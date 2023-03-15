/// @file position.h
/// @brief NovelCraft Position interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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