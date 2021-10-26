#include "nok_04.h"

typedef struct unk_D_80241440_2 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
} unk_D_80241440_2; //sizeof 0x44
typedef struct unk_D_80241440 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ unk_D_80241440_2* unk_40;
    /* 0x44 */ unk_D_80241440_2* unk_44;
} unk_D_80241440; //sizeof 0x48

extern unk_D_80241440 D_802413F8_9EEFE8;
extern s32 D_80241440_9EF030[12];
extern s32 D_80241438_9EF028;
extern s32 D_8024143C_9EF02C;
extern s32 D_80243254_9F0E44;
extern EvtSource D_80241470_9EF060;
extern EvtSource D_8024161C_9EF20C;
extern s32 D_80241768_9EF358;
extern s32 D_80241748_9EF338;

/*
trees in this room are labeled with a 0 through 5 system, meaning there are "6" tree values
(tree indexes from left to right in both rows, each tree has 2 unique numbers besides 0)
0, 1, 2, 3
0, 5, 4, 3
*/

static char* N(exit_str_0) = "nok_03";
static char* N(exit_str_1) = "";

#include "world/common/UnkFunc41.inc.c"

#include "common/UnkFloatFunc.inc.c"

ApiStatus func_80240314_9EDF04(Evt* script, s32 isInitialCall) {
    f32 temp_f6;
    s32 temp_s0_3;
    s32 temp_s2;
    Bytecode* args = script->ptrReadPos;
    
    temp_s2 = evt_get_variable(script, *args++);
    temp_s0_3 = evt_get_variable(script, *args++);
    temp_f6 = evt_get_variable(script, *args++);
    D_802413F8_9EEFE8.unk_00 = temp_s2;
    D_802413F8_9EEFE8.unk_08 = temp_f6;
    D_802413F8_9EEFE8.unk_04 = temp_s0_3 + 4.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_802403C0_9EDFB0(Evt* script) {
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 temp_f10;
    s32 temp_a0;
    s32 temp_s0_3;
    s32 temp_s2;
    Bytecode* args = script->ptrReadPos;
    s32 phi_s0;
    unk_D_80241440* d802413F8;

    temp_s2 = evt_get_variable(script, *args++);
    temp_s0_3 = evt_get_variable(script, *args++);
    temp_a0 = evt_get_variable(script, *args++);
    phi_s0 = temp_s0_3;
    d802413F8 = &D_802413F8_9EEFE8;

    if (temp_s0_3 < 0) {
        phi_s0 = temp_s0_3 + 0xF;
    }

    temp_f8 = phi_s0 >> 4;
    D_802413F8_9EEFE8.unk_34 = 0.0f;
    temp_f6 = temp_s2 * 0.0625f;
    temp_f10 = D_802413F8_9EEFE8.unk_34;
    temp_f4 = temp_a0;
    D_802413F8_9EEFE8.unk_18 = temp_f8;
    D_802413F8_9EEFE8.unk_30 = temp_f4;
    D_802413F8_9EEFE8.unk_0C = temp_f6;

    if (temp_f10 < temp_f4) {
        D_802413F8_9EEFE8.unk_38 = (temp_f6 - D_802413F8_9EEFE8.unk_10) / temp_f4;
        D_802413F8_9EEFE8.unk_3C = (temp_f8 - D_802413F8_9EEFE8.unk_20) / temp_f4;
    }

    if (temp_f4 < temp_f10) {
        D_802413F8_9EEFE8.unk_10 = temp_f6;
        D_802413F8_9EEFE8.unk_20 = temp_f8;
        D_802413F8_9EEFE8.unk_30 = temp_f10;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus func_802404D0_9EE0C0(Evt* script, s32 isInitialCall) {
    D_802413F8_9EEFE8.unk_00 = 0;
    D_802413F8_9EEFE8.unk_04 = 0;
    D_802413F8_9EEFE8.unk_08 = 0;
    D_802413F8_9EEFE8.unk_10 = 0;
    D_802413F8_9EEFE8.unk_0C = 0;
    D_802413F8_9EEFE8.unk_14 = 0;
    D_802413F8_9EEFE8.unk_18 = 0;
    D_802413F8_9EEFE8.unk_20 = 0;
    D_802413F8_9EEFE8.unk_1C = 0;
    D_802413F8_9EEFE8.unk_40 = NULL;
    D_802413F8_9EEFE8.unk_44 = NULL;
    D_802413F8_9EEFE8.unk_34 = 0;
    D_802413F8_9EEFE8.unk_30 = 0;
    D_802413F8_9EEFE8.unk_38 = 0;
    D_802413F8_9EEFE8.unk_3C = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_8024051C_9EE10C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    D_80241438_9EF028 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240548_9EE138(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    D_8024143C_9EF02C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240574_9EE164(Evt* evt, s32 isInitialCall) {
    Bytecode *args = evt->ptrReadPos;
    s32 mapVar1 = evt_get_variable(evt, *args++) * 3;
    s32 var1 = *args++;
    s32 var2 = *args++;
    s32 var3 = *args++;

    evt_set_variable(evt, var1, D_80241440_9EF030[mapVar1]);
    evt_set_variable(evt, var2, D_80241440_9EF030[mapVar1 + 1]);
    evt_set_variable(evt, var3, D_80241440_9EF030[mapVar1 + 2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80240630_9EE220(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 evtVar = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;;
    evtVar %= 6;

    if (evtVar < 4) {
        evt_set_variable(script, outVar, evtVar);
    } else {
        evt_set_variable(script, outVar, 6 - evtVar);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802406C4_9EE2B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Evt* script2;
    s32 temp_s1_2;
    s32 temp_s2;
    EvtSource* phi_a0;
    
    temp_s1_2 = evt_get_variable(script, *args++);
    temp_s2 = evt_get_variable(script, *args++);
    temp_s1_2 %= 6;

    if (temp_s1_2 >= 4) {
        temp_s1_2 = 6 - temp_s1_2;
    }

    if (does_script_exist(script->varTable[temp_s1_2 + 6]) != 0) {
        kill_script_by_ID(script->varTable[temp_s1_2 + 6]);
    }

    phi_a0 = &D_80241470_9EF060;
    
    if (temp_s2 != 0) {
        phi_a0 = &D_80241470_9EF060;
        if (temp_s2 == 1) {
            phi_a0 = &D_8024161C_9EF20C;
        }
    }

    script2 = start_script(phi_a0, 1, 0);
    script->varTable[temp_s1_2 + 6] = script2->id;

    switch(temp_s1_2) {
        case 0:
            script2->varTable[0] = 0x4C;
            break;
        case 1:
            script2->varTable[0] = 0x4D;
            break;
        case 2:
            script2->varTable[0] = 0x4E;
            break;
        case 3:
            script2->varTable[0] = 0x4F;
            break;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_nok/nok_04/9EDBF0", func_80240814_9EE404);

ApiStatus func_80240E4C_9EEA3C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        D_80243254_9F0E44 = 0; // FALSE
    }
    
    if (D_80243254_9F0E44) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80240E70_9EEA60(Evt* script, s32 isInitialCall) {
    D_80243254_9F0E44 = 1;
    return ApiStatus_DONE2;
}
