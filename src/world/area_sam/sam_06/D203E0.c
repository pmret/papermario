#include "sam_06.h"
#include "model.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_06/D203E0", func_80241D8C_D21C1C);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 D_8024BEA0[114];
BSS s32 D_8024C068[92];

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

ApiStatus func_80242538_D223C8(Evt* script, s32 isInitialCall) {
    s32 alpha;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            func_8011B950(script->varTable[15], -1, FOG_MODE_1, 1);
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 32;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = 255 - script->functionTemp[0];
    }

    set_background_color_blend(0, 0, 0, alpha);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 3) {
            func_8011B950(script->varTable[15], -1, FOG_MODE_0, 1);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
