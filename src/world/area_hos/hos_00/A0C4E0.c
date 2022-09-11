#include "hos_00.h"

extern f32 D_80242B9C_A0E88C;
extern f32 D_80242BA0_A0E890;

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

ApiStatus N(EnableActionCommands)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->hasActionCommands = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_8024091C_A0C60C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 f1 = evt_get_float_variable(script, *args++);
    f32 f2 = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, *args++, f1 * sin_deg(f2));
    return ApiStatus_DONE2;
}

ApiStatus func_80240994_A0C684(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Npc* npc = get_npc_unsafe(0);

    partner->yaw = atan2(partner->pos.x, partner->pos.z, npc->pos.x, npc->pos.z);
    gPlayerStatus.targetYaw = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, npc->pos.x, npc->pos.z);
    npc->yaw = atan2(D_80242B9C_A0E88C, D_80242BA0_A0E890, npc->pos.x, npc->pos.z);
    D_80242B9C_A0E88C = npc->pos.x;
    D_80242BA0_A0E890 = npc->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus func_80240A54_A0C744(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(1);

    if (npc->yaw < 180.0f) {
        script->varTable[0] = npc->pos.x - 40.0f;
        script->varTable[1] = npc->pos.y + 10.0f;
        script->varTable[2] = npc->pos.z;
    } else {
        script->varTable[0] = npc->pos.x + 40.0f;
        script->varTable[1] = npc->pos.y + 10.0f;
        script->varTable[2] = npc->pos.z;
    }
    npc->yaw = atan2(script->varTable[6], script->varTable[8], npc->pos.x, npc->pos.z);
    return ApiStatus_DONE2;
}

#include "world/common/SetCamera0Flag1000.inc.c"

ApiStatus func_80240B3C_A0C82C(Evt* script, s32 isInitialCall) {
    s32 temp_s1 = script->varTable[0];
    s32 temp_s2 = script->varTable[2];

    script->varTable[0] = temp_s1 + (sin_deg(310.0f) * 100.0f);
    script->varTable[1] = temp_s2 - (cos_deg(310.0f) * 100.0f);
    script->varTable[2] = temp_s1 + (sin_deg(130.0f) * 100.0f);
    script->varTable[3] = temp_s2 - (cos_deg(130.0f) * 100.0f);
    return ApiStatus_DONE2;
}
