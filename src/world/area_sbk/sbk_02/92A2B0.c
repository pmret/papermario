#include "sbk_02.h"
#include "effects.h"

static char* N(exit_str_0) = "sbk_01";
static char* N(exit_str_1) = "sbk_03";
static char* N(exit_str_2) = "sbk_12";
static char* N(exit_str_3) = "isk_01";
static char* N(exit_str_4) = "sbk_30";
static char* N(exit_str_5) = "";

void get_model_env_color_parameters(u8* arg0, u8* arg1, u8* arg2, u8* arg3, u8* arg4, u8* arg5);

s32 func_80240000_92A2B0(void) {
    s32 phi;

<<<<<<< HEAD
    if (evt_get_variable(NULL, EVT_STORY_PROGRESS) >= -0x3E) {
=======
    if (evt_get_variable(NULL, EVT_STORY_PROGRESS) > STORY_CH2_GOT_PULSE_STONE) {
>>>>>>> b1989c4f0cbcd069415cf11b512fef9d31cb5426
        phi = 0x190063;
    } else {
        phi = 0x190062;
    }
    return phi;
}

#include "world/common/UnkFunc27.inc.c"

#include "world/common/UnkFunc26.inc.c"

<<<<<<< HEAD
ApiStatus func_80240338_92A5E8(Evt* evt, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(evt, EVT_MAP_VAR(0));
=======
ApiStatus func_80240338_92A5E8(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, EVT_MAP_VAR(0));
>>>>>>> b1989c4f0cbcd069415cf11b512fef9d31cb5426
    effect->data->unk_3C = 0;
    return ApiStatus_DONE2;
}

<<<<<<< HEAD
ApiStatus func_80240364_92A614(Evt* evt, s32 isInitialCall) {
    Bytecode* args = evt->ptrReadPos;
    u8 temp_t0;
    u8 temp_t1;
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_v1;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_a3;
    

    if (isInitialCall) {
        get_model_env_color_parameters(&D_80245600_DB78C0, &D_80245601, &D_80245602, &D_80245603, &D_80245604, &D_80245605);
        D_80245608 = evt_get_variable(evt, *args++);
        D_8024560C = evt_get_variable(evt, *args++);
        D_80245610 = evt_get_variable(evt, *args++);
        D_80245614 = evt_get_variable(evt, *args++);
        D_80245618 = evt_get_variable(evt, *args++);
        D_8024561C = evt_get_variable(evt, *args++);
        D_80245620 = evt_get_variable(evt, *args++);
        flo_18_80245624 = 0;
    }

    temp_t7 = D_80245620;
    if (temp_t7 > 0) {
        temp_v1 = flo_18_80245624 + 1;
        temp_a0 = D_80245600_DB78C0;
        temp_t6 = ((D_80245608 - temp_a0) * temp_v1) / temp_t7;
        temp_a1 = D_80245601;
        temp_t5 = ((D_8024560C - temp_a1) * temp_v1) / temp_t7;
        temp_a2 = D_80245602;
        temp_t4 = ((D_80245610 - temp_a2) * temp_v1) / temp_t7;
        temp_a3 = D_80245603;
        temp_t3 = ((D_80245614 - temp_a3) * temp_v1) / temp_t7;
        temp_t1 = D_80245604;
        temp_t2 = ((D_80245618 - temp_t1) * temp_v1) / temp_t7;
        temp_t0 = D_80245605;
        temp_v0 = ((D_8024561C - temp_t0) * temp_v1) / temp_t7;
        flo_18_80245624 = temp_v1;
        set_model_env_color_parameters((temp_a0 + temp_t6), (temp_a1 + temp_t5), (temp_a2 + temp_t4), (temp_a3 + temp_t3), (temp_t1 + temp_t2), (temp_t0 + temp_v0));
        if (flo_18_80245624 >= D_80245620) {
            return ApiStatus_DONE2;
        }

    } else {
        set_model_env_color_parameters(D_80245608, D_8024560C, D_80245610, D_80245614, D_80245618, D_8024561C);
        return ApiStatus_DONE2;
    }
    
=======
ApiStatus func_80240364_92A614(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        get_model_env_color_parameters(&D_80245600, &D_80245601, &D_80245602, &D_80245603, &D_80245604, &D_80245605);
        D_80245608 = evt_get_variable(script, *args++);
        D_8024560C = evt_get_variable(script, *args++);
        D_80245610 = evt_get_variable(script, *args++);
        D_80245614 = evt_get_variable(script, *args++);
        D_80245618 = evt_get_variable(script, *args++);
        D_8024561C = evt_get_variable(script, *args++);
        D_80245620 = evt_get_variable(script, *args++);
        flo_18_80245624 = 0;
    }

    if (D_80245620 > 0) {
        s32 temp_v1 = flo_18_80245624 + 1;
        u8 temp_a0 = D_80245600;
        u8 temp_a1 = D_80245601;
        u8 temp_a2 = D_80245602;
        u8 temp_a3 = D_80245603;
        u8 temp_t1 = D_80245604;
        u8 temp_t0 = D_80245605;
        s32 temp_t6 = ((D_80245608 - temp_a0) * temp_v1) / D_80245620;
        s32 temp_t5 = ((D_8024560C - temp_a1) * temp_v1) / D_80245620;
        s32 temp_t4 = ((D_80245610 - temp_a2) * temp_v1) / D_80245620;
        s32 temp_t3 = ((D_80245614 - temp_a3) * temp_v1) / D_80245620;
        s32 temp_t2 = ((D_80245618 - temp_t1) * temp_v1) / D_80245620;
        s32 temp_v0 = ((D_8024561C - temp_t0) * temp_v1) / D_80245620;

        flo_18_80245624++;

        set_model_env_color_parameters(temp_a0 + temp_t6, temp_a1 + temp_t5, temp_a2 + temp_t4, temp_a3 + temp_t3,
                                       temp_t1 + temp_t2, temp_t0 + temp_v0);
        if (flo_18_80245624 >= D_80245620) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(D_80245608, D_8024560C, D_80245610, D_80245614, D_80245618, D_8024561C);
        return ApiStatus_DONE2;
    }

>>>>>>> b1989c4f0cbcd069415cf11b512fef9d31cb5426
    return ApiStatus_BLOCK;
}
