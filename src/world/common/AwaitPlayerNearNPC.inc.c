#include "common.h"

static ApiStatus AwaitPlayerNearNPC(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    Npc* npc = get_npc_safe(script->ownerID);

    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z) < 50.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
