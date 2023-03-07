/// @file config.h
/// @brief NovelCraft Config interfaces

#ifndef NOVELCRAFT_SDK_CONFIG_H_
#define NOVELCRAFT_SDK_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Represents a configuration.
struct ncsdk_Config {
  /// @brief The IP address or the host name of the server.
  const char *host;

  /// @brief The name of the agent.
  const char *name;

  /// @brief The port of the server.
  const int port;

  /// @brief The token of the agent.
  const char *token;
};

#ifdef __cplusplus
}
#endif

#endif