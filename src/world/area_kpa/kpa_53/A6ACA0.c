#include "kpa_53.h"

ApiStatus func_80240000_A6ACA0(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 2;
    sprintf(wMapShapeName, "kpa_50_shape");
    sprintf(wMapHitName, "kpa_50_hit");
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "kpa_102";
const char* N(exit_str_1) = "kpa_83";

ApiStatus func_80240050_A6ACF0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Npc* npc = resolve_npc(script, npcID);
    u32 animID;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = (s32)(((s32)playerStatus->position.x - 700) * 0.85) + 765;
    if (playerStatus->currentSpeed == 0.0f) {
        animID = 0xA0001;
    } else if (playerStatus->currentSpeed < 2.0f) {
        animID = 0xA0002;
    } else {
        animID = 0xA0003;
    }
    npc->currentAnim = animID;
    evt_set_variable(script, outVar, playerStatus->targetYaw);
    return ApiStatus_DONE2;
}
