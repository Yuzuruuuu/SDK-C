/// @file agent.h
/// @brief NovelCraft Agent interfaces

#pragma once

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
/// @param self The agent.
/// @return The agent's orientation.
const ncsdk_Orientation* ncsdk_Agent_GetOrientation(
    const struct ncsdk_Agent* self);

/// @brief Gets the agent's position.
/// @param self The agent.
/// @return The agent's position.
const ncsdk_Position(float)* ncsdk_Agent_GetPosition(
    const struct ncsdk_Agent* self);

/// @brief Gets the agent's type ID.
/// @param self The agent.
/// @return The agent's type ID.
int ncsdk_Agent_GetTypeId(const struct ncsdk_Agent* self);

/// @brief Gets the agent's unique ID.
/// @param self The agent.
/// @return The agent's unique ID.
int ncsdk_Agent_GetUniqueId(const struct ncsdk_Agent* self);

/// @brief Gets the agent's inventory.
/// @param self The agent.
/// @return The agent's inventory.
const struct ncsdk_Inventory* ncsdk_Agent_GetInventory(
    const struct ncsdk_Agent* self);

/// @brief Gets the agent's movement.
/// @param self The agent.
/// @return The agent's movement.
enum ncsdk_Agent_MovementKind ncsdk_Agent_GetMovement(
    const struct ncsdk_Agent* self);

/// @brief Sets the agent's movement.
/// @param self The agent.
/// @param movement The movement.
void ncsdk_Agent_SetMovement(struct ncsdk_Agent* self,
                             enum ncsdk_Agent_MovementKind movement);

/// @brief Gets the agent's token.
/// @param self The agent.
/// @return The agent's token.
const struct ncsdk_Token* ncsdk_Agent_GetToken(const struct ncsdk_Agent* self);

/// @brief Performs an attack.
/// @param self The agent.
/// @param kind The kind of attack.
void ncsdk_Agent_Attack(struct ncsdk_Agent* self,
                        enum ncsdk_Agent_InteractionKind kind);

/// @brief Performs a jump.
/// @param self The agent.
void ncsdk_Agent_Jump(struct ncsdk_Agent* self);

/// @brief Makes the agent look at a position.
/// @param self The agent.
/// @param position The position.
void ncsdk_Agent_LookAt(struct ncsdk_Agent* self,
                        const ncsdk_Position(float)* position);

/// @brief Sets the agent's movement.
/// @param self The agent.
/// @param movement The movement.
void ncsdk_Agent_SetMovement(struct ncsdk_Agent* self,
                             enum ncsdk_Agent_MovementKind movement);

/// @brief Performs a use action.
/// @param self The agent.
/// @param kind The kind of use action.
void ncsdk_Agent_Use(struct ncsdk_Agent* self,
                     enum ncsdk_Agent_InteractionKind kind);

#ifdef __cplusplus
}
#endif