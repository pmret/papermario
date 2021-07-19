#include "common.h"

INCLUDE_ASM(void, "evt/fx_api", func_802D7460, f32 x, f32 y, f32 z, s32 arg3);

INCLUDE_ASM(void, "evt/fx_api", func_802D74C0, f32 x, f32 y, f32 z, s32 arg3);

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    func_802D7460(x, y, z, get_variable(script, *args++));
    sfx_play_sound_at_position(0x2055, 0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    func_802D74C0(x, y, z, get_variable(script, *args++));
    sfx_play_sound_at_position(0x378, 0, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/fx_api", func_802D7690);

INCLUDE_ASM(s32, "evt/fx_api", ShowEmote, ScriptInstance* script, s32 isInitialCall);

ApiStatus RemoveEffect(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    remove_effect(get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B10(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = (s32*) get_variable(script, *args++);

    *ptrValue |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B44(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[5] = 10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B74(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[12] = 5;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7BA4(ScriptInstance* script, s32 isInitialCall) {
    s32 var1 = script->varTable[1];
    s32 var2 = script->varTable[2];
    s32 var3 = script->varTable[3];
    s32 var4 = script->varTable[4];
    s32 var5 = script->varTable[5];
    s32 var6 = script->varTable[6];
    s32 temp;
    f32 t0;
    f32 t1;

    if (isInitialCall) {
        script->functionTemp[0] = var6;
        get_screen_overlay_params(1, &t0, &t1);
        script->functionTemp[1] = t1;
        set_screen_overlay_center(1, 0, var1, var2);
        set_screen_overlay_center(1, 1, var3, var4);
    }

    get_screen_overlay_params(1, &t0, &t1);
    temp = (script->functionTemp[1] - var5) * script->functionTemp[0];
    set_screen_overlay_params_back(12, (temp / var6) + var5);

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        set_screen_overlay_params_back(12, var5);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

Script D_802D9D50 = SCRIPT({
    func_802D7BA4();
});

ApiStatus Spawn802D9D50(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    s32 var5 = get_variable(script, *args++);
    s32 var6 = get_variable(script, *args++);

    ScriptInstance* newScript = start_script(D_802D9D50, 1, 0);
    newScript->varTable[0] = var0;
    newScript->varTable[1] = var1;
    newScript->varTable[2] = var2;
    newScript->varTable[3] = var3;
    newScript->varTable[4] = var4;
    newScript->varTable[5] = var5;
    newScript->varTable[6] = var6;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/fx_api", func_802D7E08);

INCLUDE_ASM(ApiStatus, "evt/fx_api", ShowSleepBubble, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "evt/fx_api", func_802D8248, ScriptInstance* script, s32 isInitialCall);

s32 fx_sleep_bubble(s32, f32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_0A(f32, f32, s32, s32, f32, f32); // extern
s32 playFX_0B(s32, f32, f32, f32); // extern
s32 playFX_0D(s32, f32, f32, f32, s32); // extern
s32 playFX_0E(f32, f32, s32, s32, f32, s32); // extern
//s32 playFX_0F(s32, f32, f32, f32, f32, f32, f32, f32); // extern
s32 playFX_12(s32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_13(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_14(s32, f32, f32, f32, s32); // extern
s32 playFX_15(s32, f32, f32, f32, s32); // extern
s32 playFX_16(s32, f32, f32, f32, f32); // extern
s32 playFX_1A(s32, f32, f32, f32, s32); // extern
s32 playFX_1B(s32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_1C(s32, f32, f32, f32, s32); // extern
s32 playFX_1E(s32, f32, f32, f32, f32, f32, s32, s32*); // extern
s32 playFX_1F(s32, f32, f32, f32, f32, f32, f32, f32); // extern
s32 playFX_20(s32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_21(s32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_24(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_25(s32, f32, f32, f32); // extern
s32 playFX_27(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_2B(s32, f32, f32, f32); // extern
s32 playFX_2C(s32, f32, f32, f32); // extern
s32 playFX_34(s32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_35(s32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_37(s32, f32, f32, f32, f32, f32, f32, s32, s32, s32); // extern
s32 playFX_38(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_39(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_3A(s32, f32, f32, f32, f32, f32, s32, s32); // extern
s32 playFX_3C(s32, f32, f32, f32, f32, EffectInstanceData**); // extern
s32 playFX_3E(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_41(s32, f32, f32, f32, s32); // extern
s32 playFX_42(s32, s32, s32, f32, s32, s32); // extern
s32 playFX_43(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_44(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_45(s32, s32); // extern
s32 playFX_46_whirlwind(s32, s32, f32, s32); // extern
s32 playFX_47(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_48(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_49(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_4A(s32, f32, f32, f32, f32, f32); // extern
s32 playFX_4B(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_4C(s32, f32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_4D(s32, f32, f32, f32, f32, s32, f32, s32, f32, s32); // extern
s32 playFX_4F(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_53(s32, f32, f32, f32); // extern
s32 playFX_55(s32, f32, f32, f32); // extern
s32 playFX_57(s32, f32, f32, f32, f32, s32); // extern
//s32 playFX_58(s32, f32, f32, f32, f32, s32); // extern
//s32 playFX_59(s32, f32, f32, f32, f32, f32, f32, f32, s32); // extern
//s32 playFX_5A(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_5B(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_5C(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_5D(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_5E(s32, f32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_5F(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_60(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_61(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_62(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_63(s32, f32, f32, f32, f32, f32, f32, f32, s32, s32); // extern
//s32 playFX_64(s32, f32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_65(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_66(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_67(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_68(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_6C(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_6D(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_6E(s32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_70(s32, f32, f32, f32, f32, f32, f32, s32, s32, f32, f32); // extern
s32 playFX_71(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_73(s32, f32, f32, f32, f32, s32, s32); // extern
s32 playFX_74(s32, f32, f32, f32, f32, f32, f32, f32, f32); // extern
s32 playFX_75(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_77(s32, f32, f32, f32, f32, f32, f32, f32, s32); // extern
s32 playFX_78(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_79(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_7A(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_7C(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_7D(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_7E(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_7F(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_81(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_82(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_84(s32, f32, f32, f32, f32, f32); // extern
s32 playFX_85(s32, f32, f32, f32, f32, s32); // extern
s32 playFX_86(s32, f32, f32, f32, f32, s32); // extern

#ifdef NON_MATCHING
s32 PlayEffect(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode* floatArgs = args;
    Bytecode* intArgs = args;
    s32 effectID;
    s32 fxReturn = 0;

    s32 iArg1;
    s32 iArg2;
    s32 iArg3;
    s32 iArg4;
    s32 iArg5;
    s32 iArg6;
    s32 iArg7;
    s32 iArg8;
    s32 iArg9;
    s32 iArg10;

    s32 a7;
    f32 fArg1;
    f32 fArg2;
    f32 fArg3;
    f32 fArg4;
    f32 fArg5;
    f32 fArg6;
    f32 fArg7;
    f32 fArg8;
    f32 fArg9;
    f32 fArg10;
    f32 fArg11;

    s32 a2;
    s32* a6;
    s32* a8;
    s32 a9;
    s32 sp3C;
    EffectInstanceData* sp34;
    s32 sp30;

    effectID = get_variable(script, *args++);

    get_variable(script, *floatArgs++);
    get_variable(script, *intArgs++);

    iArg1 = get_variable(script, *intArgs++);
    iArg2 = get_variable(script, *intArgs++);
    iArg3 = get_variable(script, *intArgs++);
    iArg4 = get_variable(script, *intArgs++);
    iArg5 = get_variable(script, *intArgs++);
    iArg6 = get_variable(script, *intArgs++);
    iArg7 = get_variable(script, *intArgs++);
    iArg8 = get_variable(script, *intArgs++);
    iArg9 = get_variable(script, *intArgs++);
    iArg10 = get_variable(script, *intArgs++);
    get_variable(script, *intArgs++);
    get_variable(script, *intArgs++);
    get_variable(script, *intArgs++);

    fArg1 = get_float_variable(script, *floatArgs++);
    fArg2 = get_float_variable(script, *floatArgs++);
    fArg3 = get_float_variable(script, *floatArgs++);
    fArg4 = get_float_variable(script, *floatArgs++);
    fArg5 = get_float_variable(script, *floatArgs++);
    fArg6 = get_float_variable(script, *floatArgs++);
    fArg7 = get_float_variable(script, *floatArgs++);
    fArg8 = get_float_variable(script, *floatArgs++);
    fArg9 = get_float_variable(script, *floatArgs++);
    fArg10 = get_float_variable(script, *floatArgs++);
    fArg11 = get_float_variable(script, *floatArgs++);
    get_float_variable(script, *floatArgs++);
    get_float_variable(script, *floatArgs++);

    args++;
    a2 = *args;
    args++;
    args++;
    args++;
    args++;
    a6 = *args++;
    a7 = *args++;
    a8 = *args++;
    a9 = *args++;

    switch (effectID) {
        case 0:
            playFX_3E(0, fArg1, fArg2, fArg3, 3.0f, iArg5);
            break;
        case 1:
            playFX_01(fArg1, fArg2, fArg3);
            break;
        case 6:
            fx_land(iArg1, fArg2, fArg3, fArg4, fArg5);
            break;
        case 7:
            fx_walk(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6);
            break;
        case 8:
            playFX_08(fArg1, fArg2, fArg3, fArg4);
            break;
        case 9:
            playFX_09(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6);
            break;
        case 10:
            playFX_0A(fArg1, fArg2, iArg1, a2, fArg3, fArg4);
            break;
        case 11:
            playFX_0B(iArg1, fArg2, fArg3, fArg4);
            break;
        case 12:
            playFX_0C(fArg1, fArg2, iArg1, a2, fArg3, fArg4, fArg5);
            break;
        case 13:
            playFX_0D(0, fArg1, fArg2, fArg3, iArg4);
            break;
        case 14:
            playFX_0E(fArg1, fArg2, iArg1, a2, fArg3, iArg4);
            break;
        case 15:
            playFX_0F(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8);
            break;
        case 16:
            fx_emote(iArg1, a2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8, &sp30);
            set_variable(script, *a8, sp30);
            break;
        case 17:
            playFX_11(iArg1, fArg2, fArg3, fArg4, fArg5);
            break;
        case 18:
            playFX_12(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8);
            break;
        case 19:
            playFX_13(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 20:
            playFX_14(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 21:
            playFX_15(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 22:
            playFX_16(iArg1, fArg2, fArg3, fArg4, fArg5);
            break;
        case 23:
            playFX_17(iArg1, fArg2, fArg3, fArg4);
            break;
        case 24:
            playFX_18(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8);
            break;
        case 25:
            playFX_19(iArg1, fArg2, fArg3, fArg4);
            break;
        case 26:
            playFX_1A(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 27:
            playFX_1B(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
        case 28:
            playFX_1C(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 29:
            playFX_1D(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6, fArg7, iArg8);
            break;
        case 30:
            playFX_1E(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, iArg7, &sp30);
            set_variable(script, *a8, sp30);
            break;
        case 31:
            playFX_1F(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8);
            break;
        case 33:
            playFX_21(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, iArg7);
            break;
        case 34:
            playFX_22(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, iArg7, iArg8);
            break;
        case 35:
            playFX_23(iArg1, fArg2, fArg3, fArg4, fArg5);
            break;
        case 36:
            playFX_24(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 37:
            playFX_25(iArg1, fArg2, fArg3, fArg4);
            break;
        case 38:
            playFX_26(iArg1, fArg2, fArg3, fArg4);
            break;
        case 39:
            playFX_27(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 40:
            fx_sweat(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, iArg7);
            break;
        case 41:
            fx_sleep_bubble(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, &sp34);
            set_variable(script, a7, sp34);
            break;
        case 43:
            playFX_2B(iArg1, fArg2, fArg3, fArg4);
            break;
        case 32:
            playFX_20(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
        case 44:
            playFX_2C(iArg1, fArg2, fArg3, fArg4);
            break;
        case 45:
            playFX_2D(iArg1, fArg2, fArg3, fArg4, iArg5, iArg6);
            break;
        case 46:
            playFX_2E(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 47:
            playFX_2F(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6, &sp34);
            set_variable(script, a7, sp34);
            break;
        case 48:
            playFX_30(iArg1, fArg2, fArg3, fArg4);
            break;
        case 49:
            playFX_31(iArg1, fArg2, fArg3, fArg4);
            break;
        case 50:
            playFX_32(iArg1, fArg2, fArg3, fArg4, fArg5);
            break;
        case 51:
            playFX_33(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 52:
            playFX_34(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
        case 53:
            playFX_35(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
        case 54:
            fxReturn = playFX_36(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6);
            break;
        case 55:
            fxReturn = playFX_37(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8, iArg9, iArg10);
            break;
        case 56:
            playFX_38(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 57:
            playFX_39(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 58:
            playFX_3A(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, iArg7, iArg8);
            break;
        case 59:
            playFX_3B(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
        case 60:
            playFX_3C(iArg1, fArg2, fArg3, fArg4, fArg5, &sp34);
            set_variable(script, *a6, sp34);
            break;
        case 61:
            playFX_3D(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8, &sp3C);
            set_variable(script, a9, sp3C);
            break;
        case 62:
            playFX_3E(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 63:
            fxReturn = playFX_3F(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 64:
            fxReturn = playFX_40(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 65:
            fxReturn = playFX_41(iArg1, fArg2, fArg3, fArg4, iArg5);
            break;
        case 66:
            fxReturn = playFX_42(iArg1, iArg2, iArg3, fArg4, iArg5, iArg6);
            break;
        case 67:
            fxReturn = playFX_43(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 68:
            fxReturn = playFX_44(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 69:
            fxReturn = playFX_45(iArg1, iArg2);
            break;
        case 70:
            fxReturn = playFX_46_whirlwind(iArg1, a2, fArg3, iArg4);
            break;
        case 71:
            fxReturn = playFX_47(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 72:
            fxReturn = playFX_48(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 73:
            fxReturn = playFX_49(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 74:
            fxReturn = playFX_4A(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6);
            break;
        case 75:
            fxReturn = playFX_4B(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 76:
            fxReturn = playFX_4C(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9);
            break;
        case 77:
            fxReturn = playFX_4D(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, fArg9, iArg10);
            break;
        case 78:
            fxReturn = playFX_4E(iArg1, fArg2, fArg3, fArg4);
            break;
        case 79:
            fxReturn = playFX_4F(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 82:
            fxReturn = playFX_52(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 83:
            fxReturn = playFX_53(iArg1, fArg2, fArg3, fArg4);
            break;
        case 81:
            fxReturn = playFX_51(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 86:
            fxReturn = playFX_56(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 87:
            fxReturn = playFX_57(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 88:
            fxReturn = playFX_58(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 89:
            fxReturn = playFX_59(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9);
            break;
        case 90:
            fxReturn = playFX_5A(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 91:
            fxReturn = playFX_5B(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 92:
            fxReturn = playFX_5C(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 93:
            fxReturn = playFX_5D(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 94:
            fxReturn = playFX_5E(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9);
            break;
        case 95:
            fxReturn = playFX_5F(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 96:
            fxReturn = playFX_60(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 97:
            fxReturn = playFX_61(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 98:
            fxReturn = playFX_62(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 99:
            fxReturn = playFX_63(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9, iArg10);
            break;
        case 100:
            fxReturn = playFX_64(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9);
            break;
        case 101:
            fxReturn = playFX_65(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 102:
            fxReturn = playFX_66(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 103:
            fxReturn = playFX_67(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 104:
            fxReturn = playFX_68(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 105:
            fxReturn = playFX_69(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 107:
            fxReturn = playFX_6B(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 108:
            fxReturn = playFX_6C(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 109:
            fxReturn = playFX_6D(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 110:
            fxReturn = playFX_6E(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8);
            break;
        case 111:
            fxReturn = playFX_6F(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 112:
            fxReturn = playFX_70(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8, iArg9, fArg10, fArg11);
            break;
        case 113:
            fxReturn = playFX_71(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 114:
            fxReturn = playFX_72(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, iArg8, iArg9);
            break;
        case 115:
            fxReturn = playFX_73(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6, iArg7);
            break;
        case 116:
            fxReturn = playFX_74(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, fArg9);
            break;
        case 117:
            fxReturn = playFX_75(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 119:
            fxReturn = playFX_77(iArg1, fArg2, fArg3, fArg4, fArg5, fArg6, fArg7, fArg8, iArg9);
            break;
        case 120:
            fxReturn = playFX_78(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 85:
            fxReturn = playFX_55(iArg1, fArg2, fArg3, fArg4);
            break;
        case 121:
            fxReturn = playFX_79(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 122:
            fxReturn = playFX_7A(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 123:
            fxReturn = playFX_7B(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 124:
            fxReturn = playFX_7C(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 125:
            fxReturn = playFX_7D(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 126:
            fxReturn = playFX_7E(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 127:
            fxReturn = playFX_7F(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 128:
            fxReturn = playFX_80(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 129:
            fxReturn = playFX_81(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 130:
            fxReturn = playFX_82(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 131:
            fxReturn = playFX_83(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 132:
            fxReturn = playFX_84(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 133:
            fxReturn = playFX_85(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        case 134:
            fxReturn = playFX_86(iArg1, fArg2, fArg3, fArg4, fArg5, iArg6);
            break;
        default:
            PANIC();
    }

    if (fxReturn != 0) {
        set_variable(script, SI_VAR(15), fxReturn);
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "evt/fx_api", PlayEffect, ScriptInstance* script, s32 isInitialCall);
#endif
