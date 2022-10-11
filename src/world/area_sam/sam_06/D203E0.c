#include "sam_06.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_06/D203E0", func_80241D8C_D21C1C);

INCLUDE_ASM(s32, "world/area_sam/sam_06/D203E0", func_80241DE0_D21C70);

extern s32 D_8024BEA0[];

ApiStatus func_80241E18_D21CA8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024BEA0[i] = ptr[i];
        }
        D_8024BEA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_8024BEA0[i] = i + 16;
            D_8024BEA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_8024C068[];

ApiStatus func_80241EB4_D21D44(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024C068[i] = ptr[i];
        }
        D_8024C068[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_8024C068[i] = i + 128;
            D_8024C068[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/atomic/ToadHouse.inc.c"

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_06/D203E0", func_80242538_D223C8);
