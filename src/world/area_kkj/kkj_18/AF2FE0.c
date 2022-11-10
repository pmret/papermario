#include "kkj_18.h"
#include "camera.h"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
extern s32 kkj_18_D_80244E78[];

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// Needs data migration, matching otherwise
#ifdef NON_MATCHING
ApiStatus func_8024056C_AF320C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        kkj_18_ItemChoice_HasSelectedItem = 0;
    }

    if (kkj_18_ItemChoice_HasSelectedItem != 0) {
        kkj_18_ItemChoice_HasSelectedItem = 0;
        evt_set_variable(script, *args++, kkj_18_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_8024056C_AF320C);
#endif

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 kkj_18_D_80244CB0[];

ApiStatus func_802405F8_AF3298(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            kkj_18_D_80244CB0[i] = ptr[i];
        }
        kkj_18_D_80244CB0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            kkj_18_D_80244CB0[i] = i + 16;
            kkj_18_D_80244CB0[112] = 0;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240694_AF3334(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            kkj_18_D_80244E78[i] = ptr[i];
        }
        kkj_18_D_80244E78[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            kkj_18_D_80244E78[i] = i + 128;
            kkj_18_D_80244E78[91] = 0;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240730_AF33D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.peachItemHeld = evt_get_float_variable(script, *args++);
    gGameStatusPtr->peachCookingIngredient = gPlayerStatus.peachItemHeld;

    return ApiStatus_DONE2;
}

ApiStatus func_80240774_AF3414(Evt* script, s32 isInitialCall) {
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
