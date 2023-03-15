/// @file orientation.h
/// @brief NovelCraft Orientation interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Represents a direction in 3D space.
struct ncsdk_Orientation {
  float yaw, pitch;
};

#ifdef __cplusplus
}
#endif