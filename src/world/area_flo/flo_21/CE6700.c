#include "flo_21.h"

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_80240000_CE6700);
/*
ApiStatus N(func_80240000_CE6700)(ScriptInstance* script, s32 isInitialCall) {
    arn_07_struct* ptr = script->varTable[0];

    sfx_adjust_env_sound_pos(0xA2, 0, ptr->unk_00, ptr->unk_04, ptr->unk_08);
    return ((ptr->unk_44 < 2) == 0) * ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_8024004C_CE674C);
/*
ApiStatus N(func_8024004C_CE674C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
        script->varTable[0] = ptr;
        set_variable(NULL, SI_MAP_VAR(1), ptr);
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_3C = get_variable(script, *args++);
        ptr->unk_0C = get_float_variable(script, *args++);
        ptr->unk_10 = get_float_variable(script, *args++);
        ptr->unk_14 = get_float_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_1C = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_50 = (struct N(temp)*)func_800729B0(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_802401AC_CE68AC);

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_802405BC_CE6CBC);
/*
ApiStatus N(func_802405BC_CE6CBC)(ScriptInstance* script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    arn_07_struct* ptr = script->varTable[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_802405FC_CE6CFC);
/*
ApiStatus N(func_802405FC_CE6CFC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
        script->varTable[0] = ptr;
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_54 = func_800726B0(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        ptr->unk_54->unk_0C->unk_34 = ptr->unk_38;
        ptr->unk_54->unk_0C->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 0x10E;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_80240708_CE6E08);
/*
ApiStatus N(func_80240708_CE6E08)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    arn_07_struct* ptr = script->varTable[0];

    ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
    ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
    if (dist2D(playerStatus->position.x, playerStatus->position.z, 
               ptr->unk_18, ptr->unk_20) <= 30.0f) {
        ptr->unk_4E = 3;
    }
    ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
    ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
    ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;

    return ApiStatus_BLOCK;
}
*/

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_21/CE6700", func_80240B00_CE7200);
