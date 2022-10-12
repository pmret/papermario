#include "sam_03.h"

static char* N(exit_str_0) = "sam_11";
static char* N(exit_str_1) = "sam_04";

ApiStatus func_80240000_D110C0(Evt* script, s32 isInitialCall) {
    Npc* temp_v0 = get_npc_unsafe(0);
    
    script->varTable[0] = atan2(temp_v0->pos.x, temp_v0->pos.z, gPlayerStatus.position.x, gPlayerStatus.position.z);
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"
