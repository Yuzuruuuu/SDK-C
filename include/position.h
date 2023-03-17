/// @file position.h
/// @brief NovelCraft Position interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define ncsdk_Position(type) ncsdk_Position_##type

#define NCSDK_DEFINE_POSITION(type) \
  typedef struct {                  \
    type x, y, z;                   \
  } ncsdk_Position_##type

NCSDK_DEFINE_POSITION(int);
NCSDK_DEFINE_POSITION(float);

#ifdef __cplusplus
}
#endif