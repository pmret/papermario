#include "dro_01.h"

void func_8011BEB4(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7, u8 var8, s32 var9, s32 var10);
void func_8011BF98(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7);
void func_8011B950(u16, s32, s32, s32);

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

ApiStatus N(func_80240034_95B234)(ScriptInstance *script, s32 isInitialCall) {
    s32 stickX, stickY;

    if (gCollisionStatus.currentFloor != script->varTable[11]) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    stickX = abs(gGameStatusPtr->stickX);
    stickY = gGameStatusPtr->stickY;

    if ((stickX != 0) || (stickY != 0)) {
        if (atan2(0.0f, 0.0f, stickX, stickY) < 60.0f) {
            script->varTable[0] = 1;
            return ApiStatus_DONE2;
        }
    }
    return ApiStatus_BLOCK;
}

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

ApiStatus N(func_802402E0_95B4E0)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 testS2 = get_variable(script, *args++);
    s32 testS0 = get_variable(script, *args++);
    s32 testS1 = get_variable(script, *args++);
    s32* temp_s0_3 = testS0;
    s32 temp_s1 = testS1;
    s32 temp_s2 = testS2;

    if (temp_s0_3 == -1) {
        func_8011D82C(temp_s1);
        return ApiStatus_DONE2;
    }

    switch (temp_s2) {
        case 0:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                func_8011BC7C(get_model_from_list_index(get_model_list_index_from_tree_index(*temp_s0_3)), -1, temp_s1);
                temp_s0_3++;
            };
            break;

        case 1:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                func_8011B950(*temp_s0_3, -1, temp_s1, 0);
                temp_s0_3++;
            };
            break;

        case 2:
            *D_801512F0 = temp_s1;
            break;
        
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240404_95B604)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args++);
    s32 var6 = get_variable(script, *args++);
    s32 var7 = get_variable(script, *args++);
    s32 var8 = get_variable(script, *args++);
    s32 var9 = get_variable(script, *args++);
    s32 var10 = get_variable(script, *args++);

    switch (var1) {
        case 1:
            set_background_color_blend(var2, var3, var4, var5);
            break;
        case 2:
            func_8011BEB4(var2, var3, var4, var5, var6, var7, var8, var9, var10);
            break;
        case 3:
            func_8011BF98(var2, var3, var4, var5, var6, var7);
            break;
    }

    return ApiStatus_DONE2;
}
