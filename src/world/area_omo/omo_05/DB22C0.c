#include "omo_05.h"

static char* N(exit_str_0) = "omo_17";
static char* N(exit_str_1) = "";

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/GrooveGuyAI.inc.c"

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242178_DB4438);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 D_80245650[];
extern s32 D_802457C0[];

ApiStatus func_80242204_DB44C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80245650[i] = ptr[i];
        }
        D_80245650[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80245650[i] = i + 128;
            D_80245650[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802422A0_DB4560(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    ItemData* item = &gItemTable[itemID];

    if (itemID == ITEM_CAKE || itemID == ITEM_STRANGE_CAKE || itemID == ITEM_SHROOM_CAKE) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80242328_DB45E8(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAGS_SHAKING;
        script->functionTempF[0] = 0.0f;
    }
    script->functionTempF[0] += 10.0f;
    guRotateF(camera->viewMtxShaking, script->functionTempF[0], 0.0f, 0.0f, -1.0f);

    if (script->functionTempF[0] >= 360.0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802423C8_DB4688(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 91; i++) {
        D_802457C0[i] = i + 128;
    }
    D_802457C0[i] = 0;

    return ApiStatus_DONE2;
}
