/// @file orientation.h
/// @brief NovelCraft Orientation interfaces

#ifndef NOVELCRAFT_SDK_ORIENTATION_H_
#define NOVELCRAFT_SDK_ORIENTATION_H_

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

#endif  // NOVELCRAFT_SDK_ORIENTATION_H_