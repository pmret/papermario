#include "end_00.h"
#include "battle/battle.h"
#include "world/common/PlayFX3D.inc.c"

INCLUDE_ASM(s32, "world/area_end/end_00/DF9300", func_80242A30_DF9430);



// #ifdef NON_MATCHING
typedef struct unk_DF94D4 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
} unk_DF94D4;

ApiStatus func_80242AD4_DF94D4(Evt *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    unk_DF94D4* unk = ((unk_DF94D4*) effect->data)->unk04 = 1;
    return ApiStatus_DONE2;
}
// #else
// INCLUDE_ASM(s32, "world/area_end/end_00/DF9300", func_80242AD4_DF94D4);
// #endif
