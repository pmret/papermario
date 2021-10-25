#include "dead.h"
#include "common.h"

// Copy of flo_14?

#define NAMESPACE EE65B0

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

ApiStatus func_8024030C_EE68BC(Evt *script, s32 isInitialCall) {
    dead_playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc43.inc.c"

ApiStatus func_802403D4_EE6984(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        script->varTable[14] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = 1;
    evt_set_variable(NULL, EVT_MAP_VAR(0), get_npc_unsafe(-4)->flags);
    return ApiStatus_DONE2;
}

ApiStatus func_8024042C_EE69DC(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(-4);

    npc->flags = evt_get_variable(NULL, EVT_MAP_VAR(0));
    return ApiStatus_DONE2;
}

ApiStatus func_8024046C_EE6A1C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_UNKNOWN_194, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EE65B0", func_80240504_EE6AB4);

INCLUDE_ASM(s32, "EE65B0", func_802407D4_EE6D84);
