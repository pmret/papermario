#include "kmr_03.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_03/8C7F90", func_80240000_8C7F90);

#include "world/common/CheckPartnerFlags1000.inc.c"

ApiStatus func_802401B0_8C8140(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[1] = (func_800E0088(npc->pos.x, npc->pos.z) / npc->moveSpeed) * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/UnkPositionFunc.inc.c"
