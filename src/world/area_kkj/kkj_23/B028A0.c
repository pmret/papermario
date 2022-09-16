#include "kkj_23.h"

ApiStatus func_80240020_B028A0(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~0x1;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}

ApiStatus func_80240048_B028C8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240080_B02900(Evt* script, s32 isInitialCall) {
    Npc *npc = get_npc_safe(1);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_23D, 0, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/GetPeachDisguise.inc.c"

ApiStatus func_80240784_B03004(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= 8;
    return ApiStatus_DONE2;
}

#include "world/common/UnkGooberFunc50.inc.c"

const char* kkj_23_str = "kkj_14";
