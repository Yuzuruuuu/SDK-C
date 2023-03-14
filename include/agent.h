/// @file agent.h
/// @brief NovelCraft Agent interfaces

#ifndef NOVELCRAFT_SDK_AGENT_H_
#define NOVELCRAFT_SDK_AGENT_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "orientation.h"
#include "position.h"

/// @brief Represents the kind of interaction that an agent can perform.
enum ncsdk_Agent_InteractionKind {
  /// @brief Clicks.
  ncsdk_Agent_InteractionKind_Click,

  /// @brief Starts holding.
  ncsdk_Agent_InteractionKind_HoldStart,

  /// @brief Ends holding.
  ncsdk_Agent_InteractionKind_HoldEnd
};

/// @brief Represents the kind of movement that an agent can perform.
enum ncsdk_Agent_MovementKind {
  /// @brief Moves forward.
  ncsdk_Agent_MovementKind_Forward,

  /// @brief Moves backward.
  ncsdk_Agent_MovementKind_Backward,

  /// @brief Moves left.
  ncsdk_Agent_MovementKind_Left,

  /// @brief Moves right.
  ncsdk_Agent_MovementKind_Right,
};

/// @struct ncsdk_Agent
/// @brief Represents a player that can be controlled by an AI.
struct ncsdk_Agent;

/// @brief Gets the agent's orientation.
/// @param agent The agent.
/// @return The agent's orientation.
const struct ncsdk_Orientation* ncsdk_Agent_GetOrientation(
    const struct ncsdk_Agent* agent);

/// @brief Gets the agent's position.
/// @param agent The agent.
/// @return The agent's position.
const struct ncsdk_Position_Float* ncsdk_Agent_GetPosition(
    const struct ncsdk_Agent* agent);

/// @brief Gets the agent's type ID.
/// @param agent The agent.
/// @return The agent's type ID.
int ncsdk_Agent_GetTypeId(const struct ncsdk_Agent* agent);

/// @brief Gets the agent's unique ID.
/// @param agent The agent.
/// @return The agent's unique ID.
int ncsdk_Agent_GetUniqueId(const struct ncsdk_Agent* agent);

/// @brief Gets the agent's inventory.
/// @param agent The agent.
/// @return The agent's inventory.
const struct ncsdk_Inventory* ncsdk_Agent_GetInventory(
    const struct ncsdk_Agent* agent);

/// @brief Gets the agent's movement.
/// @param agent The agent.
/// @return The agent's movement.
enum ncsdk_Agent_MovementKind ncsdk_Agent_GetMovement(
    const struct ncsdk_Agent* agent);

/// @brief Sets the agent's movement.
/// @param agent The agent.
/// @param movement The movement.
void ncsdk_Agent_SetMovement(
    struct ncsdk_Agent* agent, enum ncsdk_Agent_MovementKind movement);

/// @brief Gets the agent's token.
/// @param agent The agent.
/// @return The agent's token.
const struct ncsdk_Token* ncsdk_Agent_GetToken(
    const struct ncsdk_Agent* agent);

/// @brief Performs an attack.
/// @param agent The agent.
/// @param kind The kind of attack.
void ncsdk_Agent_Attack(struct ncsdk_Agent* agent,
                                     enum ncsdk_Agent_InteractionKind kind);

/// @brief Performs a jump.
/// @param agent The agent.
void ncsdk_Agent_Jump(struct ncsdk_Agent* agent);

/// @brief Makes the agent look at a position.
/// @param agent The agent.
/// @param position The position.
void ncsdk_Agent_LookAt(
    struct ncsdk_Agent* agent, const struct ncsdk_Position_Float* position);

/// @brief Sets the agent's movement.
/// @param agent The agent.
/// @param movement The movement.
void ncsdk_Agent_SetMovement(
    struct ncsdk_Agent* agent, enum ncsdk_Agent_MovementKind movement);

/// @brief Performs a use action.
/// @param agent The agent.
/// @param kind The kind of use action.
void ncsdk_Agent_Use(struct ncsdk_Agent* agent,
                                  enum ncsdk_Agent_InteractionKind kind);

#ifdef __cplusplus
}
#endif

#endif  // NOVELCRAFT_SDK_AGENT_H_