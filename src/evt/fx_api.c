#include "common.h"
#include "effects.h"

INCLUDE_ASM(void, "evt/fx_api", func_802D7460, f32 x, f32 y, f32 z, s32 arg3);

INCLUDE_ASM(void, "evt/fx_api", func_802D74C0, f32 x, f32 y, f32 z, s32 arg3);

ApiStatus func_802D7520(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    func_802D7460(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(0x2055, 0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D75D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    func_802D74C0(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(0x378, 0, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/fx_api", func_802D7690);

INCLUDE_ASM(s32, "evt/fx_api", ShowEmote, Evt* script, s32 isInitialCall);

ApiStatus RemoveEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    remove_effect(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = (s32*) evt_get_variable(script, *args++);

    *ptrValue |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B44(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) evt_get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[5] = 10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B74(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) evt_get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[12] = 5;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7BA4(Evt* script, s32 isInitialCall) {
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

EvtSource D_802D9D50 = {
    EVT_CALL(func_802D7BA4)
    EVT_RETURN
    EVT_END
};

ApiStatus Spawn802D9D50(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args++);
    s32 var6 = evt_get_variable(script, *args++);

    Evt* newScript = start_script(D_802D9D50, 1, 0);
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

INCLUDE_ASM(ApiStatus, "evt/fx_api", ShowSleepBubble, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "evt/fx_api", func_802D8248, Evt* script, s32 isInitialCall);

ApiStatus PlayEffect(Evt* script, s32 isInitialCall) {
    Bytecode* intArgs = script->ptrReadPos;
    Bytecode* floatArgs = script->ptrReadPos;
    Bytecode* args = script->ptrReadPos;

    s32 effectID = evt_get_variable(script, *intArgs++);
    EffectInstance* effectRet = NULL;
    s32 new_var;

    s32 iVar1, iVar2, iVar3, iVar4, iVar5;
    s32 iVar6, iVar7, iVar8, iVar9, iVar10;

    f32 fVar1, fVar2, fVar3, fVar4, fVar5, fVar6;
    f32 fVar7, fVar8, fVar9, fVar10, fVar11;

    s32 sp30, sp34, sp38, sp3C;

    s32 a2, a6, a7, a8, a9;

    evt_get_variable(script, *floatArgs++);
    evt_get_variable(script, *args++);

    new_var = evt_get_variable(script, *intArgs++);
    iVar2 = evt_get_variable(script, *intArgs++);
    iVar3 = evt_get_variable(script, *intArgs++);
    iVar4 = evt_get_variable(script, *intArgs++);
    iVar5 = evt_get_variable(script, *intArgs++);
    iVar6 = evt_get_variable(script, *intArgs++);
    iVar7 = evt_get_variable(script, *intArgs++);
    iVar8 = evt_get_variable(script, *intArgs++);
    iVar9 = evt_get_variable(script, *intArgs++);
    iVar10 = evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);

    fVar1 = evt_get_float_variable(script, *floatArgs++);
    fVar2 = evt_get_float_variable(script, *floatArgs++);
    fVar3 = evt_get_float_variable(script, *floatArgs++);
    fVar4 = evt_get_float_variable(script, *floatArgs++);
    fVar5 = evt_get_float_variable(script, *floatArgs++);
    fVar6 = evt_get_float_variable(script, *floatArgs++);
    fVar7 = evt_get_float_variable(script, *floatArgs++);
    fVar8 = evt_get_float_variable(script, *floatArgs++);
    fVar9 = evt_get_float_variable(script, *floatArgs++);
    fVar10 = evt_get_float_variable(script, *floatArgs++);
    fVar11 = evt_get_float_variable(script, *floatArgs++);
    evt_get_float_variable(script, *floatArgs++);
    evt_get_float_variable(script, *floatArgs++);

    args++;
    a2 = *args++;
    args++;
    args++;
    args++;
    a6 = *args++;
    a7 = *args++;
    a8 = *args++;
    a9 = *args++;

    iVar1 = new_var;

    switch (effectID) {
        case EFFECT_ID_00:
            playFX_3E(0, fVar1, fVar2, fVar3, 3.0f, iVar5);
            break;
        case EFFECT_ID_01:
            playFX_01(fVar1, fVar2, fVar3);
            break;
        case EFFECT_ID_06:
            fx_land(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_07:
            fx_walk(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_ID_08:
            playFX_08(fVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_09:
            playFX_09(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_ID_0A:
            playFX_0A(fVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_0B:
            playFX_0B(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_0C:
            playFX_0C(fVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_0D:
            playFX_0D(0, fVar1, fVar2, fVar3, iVar4);
            break;
        case EFFECT_ID_0E:
            playFX_0E(fVar1, fVar2, fVar3, iVar4);
            break;
        case EFFECT_ID_0F:
            playFX_0F(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8);
            break;
        case EFFECT_ID_10:
            fx_emote(iVar1, (Npc* ) a2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp30);
            evt_set_variable(script, a8, sp30);
            break;
        case EFFECT_ID_11:
            playFX_11(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_12:
            playFX_12(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_ID_13:
            playFX_13(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_14:
            playFX_14(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_15:
            playFX_15(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_16:
            playFX_16(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_17:
            playFX_17(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_18:
            playFX_18(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_ID_19:
            playFX_19(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_1A:
            playFX_1A(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_1B:
            playFX_1B(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_1C:
            playFX_1C(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_1D:
            playFX_1D(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, fVar7, iVar8);
            break;
        case EFFECT_ID_1E:
            playFX_1E(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, &sp30);
            evt_set_variable(script, a8, sp30);
            break;
        case EFFECT_ID_1F:
            playFX_1F(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8);
            break;
        case EFFECT_ID_21:
            playFX_21(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7);
            break;
        case EFFECT_ID_22:
            playFX_22(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, iVar8);
            break;
        case EFFECT_ID_23:
            playFX_23(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_24:
            playFX_24(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_25:
            playFX_25(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_26:
            playFX_26(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_27:
            playFX_27(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_28:
            fx_sweat(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7);
            break;
        case EFFECT_ID_29:
            fx_sleep_bubble(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, &sp38);
            evt_set_variable(script, a7, sp38);
            break;
        case EFFECT_ID_2B:
            playFX_2B(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_20:
            playFX_20(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_2C:
            playFX_2C(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_2D:
            playFX_2D(iVar1, fVar2, fVar3, fVar4, iVar5, iVar6);
            break;
        case EFFECT_ID_2E:
            playFX_2E(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_2F:
            playFX_2F(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, &sp38);
            evt_set_variable(script, a7, sp38);
            break;
        case EFFECT_ID_30:
            playFX_30(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_31:
            playFX_31(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_32:
            playFX_32(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_ID_33:
            playFX_33(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_34:
            playFX_34(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_35:
            playFX_35(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_36:
            effectRet = playFX_36(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_ID_37:
            effectRet = playFX_37(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9, iVar10);
            break;
        case EFFECT_ID_38:
            playFX_38(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_39:
            playFX_39(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_3A:
            playFX_3A(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, iVar8);
            break;
        case EFFECT_ID_3B:
            playFX_3B(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_3C:
            playFX_3C(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_ID_3D:
            playFX_3D(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp3C);
            evt_set_variable(script, a9, sp3C);
            break;
        case EFFECT_ID_3E:
            playFX_3E(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_3F:
            effectRet = playFX_3F(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_40:
            effectRet = playFX_40(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_41:
            effectRet = playFX_41(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_ID_42:
            effectRet = playFX_42(iVar1, iVar2, iVar3, fVar4, iVar5, iVar6);
            break;
        case EFFECT_ID_43:
            effectRet = playFX_43(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_44:
            effectRet = playFX_44(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_45:
            effectRet = playFX_45(iVar1, iVar2);
            break;
        case EFFECT_ID_46:
            effectRet = playFX_46_whirlwind(iVar1, a2, fVar3, iVar4);
            break;
        case EFFECT_ID_47:
            effectRet = playFX_47(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_48:
            effectRet = playFX_48(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_49:
            effectRet = playFX_49(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_4A:
            effectRet = playFX_4A(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_ID_4B:
            effectRet = playFX_4B(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_4C:
            effectRet = playFX_4C(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_ID_4D:
            effectRet = playFX_4D(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, fVar9, iVar10);
            break;
        case EFFECT_ID_4E:
            effectRet = playFX_4E(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_4F:
            effectRet = playFX_4F(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_52:
            effectRet = playFX_52(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_53:
            effectRet = playFX_53(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_51:
            effectRet = playFX_51(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_56:
            effectRet = playFX_56(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_57:
            effectRet = playFX_57(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_58:
            effectRet = playFX_58(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_59:
            effectRet = playFX_59(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_ID_5A:
            effectRet = playFX_5A(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_5B:
            effectRet = playFX_5B(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_5C:
            effectRet = playFX_5C(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_5D:
            effectRet = playFX_5D(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_5E:
            effectRet = playFX_5E(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_ID_5F:
            effectRet = playFX_5F(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_60:
            effectRet = playFX_60(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_61:
            effectRet = playFX_61(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_62:
            effectRet = playFX_62(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_63:
            effectRet = playFX_63(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9, iVar10);
            break;
        case EFFECT_ID_64:
            effectRet = playFX_64(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_ID_65:
            effectRet = playFX_65(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_66:
            effectRet = playFX_66(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_67:
            effectRet = playFX_67(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_68:
            effectRet = playFX_68(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_69:
            effectRet = playFX_69(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_6B:
            effectRet = playFX_6B(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_6C:
            effectRet = playFX_6C(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_6D:
            effectRet = playFX_6D(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_6E:
            effectRet = playFX_6E(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_ID_6F:
            effectRet = playFX_6F(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_70:
            effectRet = playFX_70(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9, fVar10, fVar11);
            break;
        case EFFECT_ID_71:
            effectRet = playFX_71(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_72:
            effectRet = playFX_72(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9);
            break;
        case EFFECT_ID_73:
            effectRet = playFX_73(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, iVar7);
            break;
        case EFFECT_ID_74:
            effectRet = playFX_74(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, fVar9);
            break;
        case EFFECT_ID_75:
            effectRet = playFX_75(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_77:
            effectRet = playFX_77(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_ID_78:
            effectRet = playFX_78(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_55:
            effectRet = playFX_55(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_ID_79:
            effectRet = playFX_79(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7A:
            effectRet = playFX_7A(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7B:
            effectRet = playFX_7B(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7C:
            effectRet = playFX_7C(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7D:
            effectRet = playFX_7D(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7E:
            effectRet = playFX_7E(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_7F:
            effectRet = playFX_7F(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_80:
            effectRet = playFX_80(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_81:
            effectRet = playFX_81(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_82:
            effectRet = playFX_82(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_83:
            effectRet = playFX_83(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_84:
            effectRet = playFX_84(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_85:
            effectRet = playFX_85(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ID_86:
            effectRet = playFX_86(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        default:
            PANIC();
    }

    if (effectRet != NULL) {
        evt_set_variable(script, EVT_VAR(15), effectRet);
    }

    return ApiStatus_DONE2;
}
