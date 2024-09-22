#include "kmr_30.h"
#include "effects.h"

API_CALLABLE(N(ChooseFireworkColors)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 colR1, colG1, colB1;
    s32 colR2, colG2, colB2;
    s32 inv;

    colR1 = colR2 = rand_int(255);
    inv = 255 - colR1;
    colG1 = colG2 = rand_int(inv);
    inv = 255 - colG1;
    colB1 = colB2 = rand_int(inv - colR1);

    colR1 += rand_int(128);
    colG1 += rand_int(128);
    colB1 += rand_int(128);
    if (colR1 > 255) {
        colR1 = 255;
    }
    if (colG1 > 255) {
        colG1 = 255;
    }
    if (colB1 > 255) {
        colB1 = 255;
    }

    colR2 += rand_int(128);
    colG2 += rand_int(128);
    colB2 += rand_int(128);
    if (colR2 > 255) {
        colR2 = 255;
    }
    if (colG2 > 255) {
        colG2 = 255;
    }
    if (colB2 > 255) {
        colB2 = 255;
    }

    effect->data.fireworkRocket->r = colR1;
    effect->data.fireworkRocket->g = colG1;
    effect->data.fireworkRocket->b = colB1;
    effect->data.fireworkRocket->unk_34 = colR2;
    effect->data.fireworkRocket->unk_38 = colG2;
    effect->data.fireworkRocket->unk_3C = colB2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_RandomFireworks) = {
    Set(LVarA, LVar0)
    Call(RandInt, 400, LVar0)
    Set(LVar1, -47)
    Add(LVar1, LVar0)
    Call(RandInt, 250, LVar0)
    Set(LVar2, 220)
    Add(LVar2, LVar0)
    Call(RandInt, 200, LVar0)
    Set(LVar3, -450)
    Add(LVar3, LVar0)
    Call(RandInt, 2, LVar0)
    Set(LVar4, -1)
    Add(LVar4, LVar0)
    Call(RandInt, 4, LVar0)
    Set(LVar5, 2)
    Add(LVar5, LVar0)
    Call(RandInt, 2, LVar0)
    Set(LVar6, -1)
    Add(LVar6, LVar0)
    Call(RandInt, 5, LVar0)
    SetF(LVar7, Float(1.0))
    MulF(LVar0, Float(0.1))
    AddF(LVar7, LVar0)
    PlayEffect(EFFECT_FIREWORK_ROCKET, LVarA, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
    Call(N(ChooseFireworkColors), LVarF)
    IfNe(LVarA, 2)
        Call(RandInt, 100, LVar8)
        IfLt(LVar8, 50)
            IfEq(LVarA, 0)
                PlayEffect(EFFECT_FIREWORK_ROCKET, 1, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
            Else
                PlayEffect(EFFECT_FIREWORK_ROCKET, 0, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
            EndIf
            Call(N(ChooseFireworkColors), LVarF)
        EndIf
    EndIf
    Return
    End
};

s32 TheEndModelAlpha = 0;

API_CALLABLE(N(UpdateTheEndAlpha)) {
    Bytecode* args = script->ptrReadPos;
    TheEndModelAlpha = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
void N(gfx_build_the_end)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, TheEndModelAlpha);
}

EvtScript N(EVS_Scene_TheEnd) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetPlayerPos, 520, 0, -180)
    Call(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeIdle)
    Call(SetNpcYaw, NPC_ParadePeach, 270)
    Call(SetNpcPos, NPC_ParadePeach, 560, 0, -180)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_PARTNER, 0, -500, 0)
    Call(EnableGroup, MODEL_the_end, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(8.0), Float(-11.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        Call(SetNpcSpeed, NPC_ParadePeach, Float(2.0))
        Call(SetNpcFlagBits, NPC_ParadePeach, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcFlagBits, NPC_ParadePeach, NPC_FLAG_FLYING, FALSE)
        Call(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeWalk)
        Call(NpcMoveTo, NPC_ParadePeach, 450, -60, 0)
        Call(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeWalkBack)
        Call(NpcMoveTo, NPC_ParadePeach, 350, -90, 0)
        Call(NpcMoveTo, NPC_ParadePeach, 330, -130, 0)
        Call(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeBack)
    EndThread
    Call(SetPlayerSpeed, Float(2.0))
    Call(PlayerMoveTo, 450, -60, 0)
    Call(PlayerMoveTo, 320, -80, 0)
    Call(PlayerMoveTo, 300, -120, 0)
    Wait(30)
    PlayEffect(EFFECT_FIREWORK_ROCKET, 0, 153, 370, -350, -1, 4, -1, Float(1.6), 70)
    Call(N(ChooseFireworkColors), LVarF)
    Wait(30)
    PlayEffect(EFFECT_FIREWORK_ROCKET, 1, 333, 420, -270, -1, 4, -1, Float(1.6), 70)
    Call(N(ChooseFireworkColors), LVarF)
    Wait(30)
    PlayEffect(EFFECT_FIREWORK_ROCKET, 0, -27, 320, -430, -1, 4, -1, Float(1.6), 70)
    Call(N(ChooseFireworkColors), LVarF)
    Wait(80)
    PlayEffect(EFFECT_FIREWORK_ROCKET, 2, 153, 370, -350, -1, 4, -1, Float(1.6), 70)
    Call(N(ChooseFireworkColors), LVarF)
    Wait(30)
    Thread
        Wait(150)
        Loop(0)
            Call(RandInt, 60, LVar1)
            Add(LVar1, 5)
            Call(RandInt, 5, LVar2)
            Add(LVar2, 1)
            Loop(LVar2)
                Set(LVar0, 0)
                Exec(N(EVS_RandomFireworks))
                Wait(LVar1)
            EndLoop
            Call(RandInt, 60, LVar0)
            Add(LVar0, 60)
            Wait(LVar0)
            Set(LVar0, 2)
            Exec(N(EVS_RandomFireworks))
            Call(RandInt, 60, LVar0)
            Add(LVar0, 60)
            Wait(LVar0)
        EndLoop
    EndThread
    Thread
        Wait(240)
        Loop(0)
            Call(RandInt, 60, LVar1)
            Add(LVar1, 5)
            Call(RandInt, 5, LVar2)
            Add(LVar2, 1)
            Loop(LVar2)
                Set(LVar0, 1)
                Exec(N(EVS_RandomFireworks))
                Wait(LVar1)
            EndLoop
            Call(RandInt, 60, LVar0)
            Add(LVar0, 60)
            Wait(LVar0)
            Set(LVar0, 2)
            Exec(N(EVS_RandomFireworks))
            Call(RandInt, 60, LVar0)
            Add(LVar0, 60)
            Wait(LVar0)
        EndLoop
    EndThread
    Wait(30)
    Call(EnableGroup, MODEL_the_end, TRUE)
    Call(SetModelCustomGfx, MODEL_t, CUSTOM_GFX_1, -1)
    Call(SetModelCustomGfx, MODEL_h, CUSTOM_GFX_1, -1)
    Call(SetModelCustomGfx, MODEL_e, CUSTOM_GFX_1, -1)
    Call(SetModelCustomGfx, MODEL_d, CUSTOM_GFX_1, -1)
    Call(SetModelCustomGfx, MODEL_n, CUSTOM_GFX_1, -1)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(gfx_build_the_end)), NULL)
    Call(MakeLerp, 0, 255, 90, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(UpdateTheEndAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(600)
    Thread
        PlayEffect(EFFECT_FIREWORK_ROCKET, 0, 310, 280, -250, -1, 6, -1, Float(1.6), 70)
        Call(N(ChooseFireworkColors), LVarF)
    EndThread
    Wait(20)
    Call(MakeLerp, 0, 100, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, Float(3.6))
        SetF(LVar3, Float(-6.0))
        SetF(LVar4, Float(0.6))
        SetF(LVar5, Float(-0.0048828125))
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar0)
        MulF(LVar4, LVar0)
        MulF(LVar5, LVar0)
        AddF(LVar5, Float(1.0))
        Call(ScaleGroup, MODEL_the_end, LVar5, LVar5, LVar5)
        Call(TranslateGroup, MODEL_the_end, LVar2, LVar3, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};
