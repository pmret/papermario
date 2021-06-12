#include "trd_06.h"

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240310_9B1AA0);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240724_9B1EB4);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_8024081C_9B1FAC);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240854_9B1FE4);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_8024093C_9B20CC);

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240A5C_9B21EC);

ApiStatus func_80240A70_9B2200(ScriptInstance* script, s32 isInitialCall) {
    f32 partnerCollisionHeight = get_npc_unsafe(NPC_PARTNER)->collisionHeight;

    script->varTable[0].s = ((partnerCollisionHeight * 2) / 3.0f) + 145.0f;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_trd/trd_06/9B1AA0", func_80240AD0_9B2260);
