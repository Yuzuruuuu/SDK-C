/// @file message.h
/// @brief NovelCraft Message interfaces

#ifdef __cplusplus
extern "C" {
#endif

#include <json.h>

/// @brief Represents the transmission direction of the message.
enum ncsdk_Message_BoundToKind {
  /// @brief The message is sent from the client to the server.
  ncsdk_Message_BoundToKind_ServerBound,

  /// @brief The message is sent from the server to the client.
  ncsdk_Message_BoundToKind_ClientBound,

  /// @brief The message's bound-to kind is unknown.
  ncsdk_Message_BoundToKind_Unknown
};

/// @brief Represents the message's type.
enum ncsdk_Message_MessageKind {
  ncsdk_Message_MessageKind_Ping = 100,

  ncsdk_Message_MessageKind_Error = 200,

  ncsdk_Message_MessageKind_AfterBlockChange = 400,
  ncsdk_Message_MessageKind_AfterEntityAttack,
  ncsdk_Message_MessageKind_AfterEntityCreate,
  ncsdk_Message_MessageKind_AfterEntityDespawn,
  ncsdk_Message_MessageKind_AfterEntityHurt,
  ncsdk_Message_MessageKind_AfterEntityOrientationChange,
  ncsdk_Message_MessageKind_AfterEntityPositionChange,
  ncsdk_Message_MessageKind_AfterEntityRemove,
  ncsdk_Message_MessageKind_AfterEntitySpawn,
  ncsdk_Message_MessageKind_AfterPlayerInventoryChange,

  ncsdk_Message_MessageKind_GetBlocksAndEntities = 300,
  ncsdk_Message_MessageKind_GetPlayerInfo,
  ncsdk_Message_MessageKind_GetTick,

  ncsdk_Message_MessageKind_PerformAttack = 500,
  ncsdk_Message_MessageKind_PerformCraft,
  ncsdk_Message_MessageKind_PerformDropItem,
  ncsdk_Message_MessageKind_PerformJump,
  ncsdk_Message_MessageKind_PerformMergeSlots,
  ncsdk_Message_MessageKind_PerformMove,
  ncsdk_Message_MessageKind_PerformRotate,
  ncsdk_Message_MessageKind_PerformSwapSlots,
  ncsdk_Message_MessageKind_PerformSwitchMainHandSlot,
  ncsdk_Message_MessageKind_PerformUse,

  /// @brief The message's message kind is unknown.
  ncsdk_Message_MessageKind_Unknown
};

/// @struct ncsdk_Message
/// @brief Represents a message.
struct ncsdk_Message;
typedef struct ncsdk_Message ncsdk_Message;

/// @brief Creates a new message.
/// @param json_string The JSON representation of the message.
/// @return The message.
struct ncsdk_Message* ncsdk_Message_New(const char* json_string);

/// @brief Deletes a message.
/// @param self The message.
void ncsdk_Message_Delete(struct ncsdk_Message* self);

/// @brief Gets the JSON representation of the message.
/// @param self The message.
/// @return The JSON representation of the message.
const struct json_value_s* ncsdk_Message_GetJson(
    const struct ncsdk_Message* self);

/// @brief Gets the message's bound-to kind.
/// @param self The message.
/// @return The message's bound-to kind.
enum ncsdk_Message_BoundToKind ncsdk_Message_GetBoundTo(
    const struct ncsdk_Message* self);

/// @brief Gets the message's message kind.
/// @param self The message.
/// @return The message's message kind.
enum ncsdk_Message_MessageKind ncsdk_Message_GetType(
    const struct ncsdk_Message* self);

#ifdef __cplusplus
}
#endif
