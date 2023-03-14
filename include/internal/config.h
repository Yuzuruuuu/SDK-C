/// @file config.h
/// @brief NovelCraft Config interfaces

#ifndef NOVELCRAFT_SDK_INTERNAL_CONFIG_H_
#define NOVELCRAFT_SDK_INTERNAL_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/// @struct ncsdk_Config
/// @brief Represents a configuration.
struct ncsdk_Config;

/// @brief Creates a new configuration.
/// @return The configuration.
struct ncsdk_Config* ncsdk_Config_New(const char* host, int port,
                                                   const char* token);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_INTERNAL_CONFIG_H_