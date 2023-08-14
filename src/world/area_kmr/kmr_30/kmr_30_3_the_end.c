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
    EVT_SET(LVarA, LVar0)
    EVT_CALL(RandInt, 400, LVar0)
    EVT_SET(LVar1, -47)
    EVT_ADD(LVar1, LVar0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SET(LVar2, 220)
    EVT_ADD(LVar2, LVar0)
    EVT_CALL(RandInt, 200, LVar0)
    EVT_SET(LVar3, -450)
    EVT_ADD(LVar3, LVar0)
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SET(LVar4, -1)
    EVT_ADD(LVar4, LVar0)
    EVT_CALL(RandInt, 4, LVar0)
    EVT_SET(LVar5, 2)
    EVT_ADD(LVar5, LVar0)
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SET(LVar6, -1)
    EVT_ADD(LVar6, LVar0)
    EVT_CALL(RandInt, 5, LVar0)
    EVT_SETF(LVar7, EVT_FLOAT(1.0))
    EVT_MULF(LVar0, EVT_FLOAT(0.1))
    EVT_ADDF(LVar7, LVar0)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, LVarA, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
    EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_IF_NE(LVarA, 2)
        EVT_CALL(RandInt, 100, LVar8)
        EVT_IF_LT(LVar8, 50)
            EVT_IF_EQ(LVarA, 0)
                EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 1, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
            EVT_ELSE
                EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 0, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7, 70)
            EVT_END_IF
            EVT_CALL(N(ChooseFireworkColors), LVarF)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetPlayerPos, 520, 0, -180)
    EVT_CALL(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeIdle)
    EVT_CALL(SetNpcYaw, NPC_ParadePeach, 270)
    EVT_CALL(SetNpcPos, NPC_ParadePeach, 560, 0, -180)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -500, 0)
    EVT_CALL(EnableGroup, MODEL_the_end, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(8.0), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_ParadePeach, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcFlagBits, NPC_ParadePeach, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_ParadePeach, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeWalk)
        EVT_CALL(NpcMoveTo, NPC_ParadePeach, 450, -60, 0)
        EVT_CALL(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeWalkBack)
        EVT_CALL(NpcMoveTo, NPC_ParadePeach, 350, -90, 0)
        EVT_CALL(NpcMoveTo, NPC_ParadePeach, 330, -130, 0)
        EVT_CALL(SetNpcAnimation, NPC_ParadePeach, ANIM_ParadePeach_ShadeBack)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
    EVT_CALL(PlayerMoveTo, 450, -60, 0)
    EVT_CALL(PlayerMoveTo, 320, -80, 0)
    EVT_CALL(PlayerMoveTo, 300, -120, 0)
    EVT_WAIT(30)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 0, 153, 370, -350, -1, 4, -1, EVT_FLOAT(1.6), 70)
    EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_WAIT(30)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 1, 333, 420, -270, -1, 4, -1, EVT_FLOAT(1.6), 70)
    EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_WAIT(30)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 0, -27, 320, -430, -1, 4, -1, EVT_FLOAT(1.6), 70)
    EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_WAIT(80)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 2, 153, 370, -350, -1, 4, -1, EVT_FLOAT(1.6), 70)
    EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_WAIT(150)
        EVT_LOOP(0)
            EVT_CALL(RandInt, 60, LVar1)
            EVT_ADD(LVar1, 5)
            EVT_CALL(RandInt, 5, LVar2)
            EVT_ADD(LVar2, 1)
            EVT_LOOP(LVar2)
                EVT_SET(LVar0, 0)
                EVT_EXEC(N(EVS_RandomFireworks))
                EVT_WAIT(LVar1)
            EVT_END_LOOP
            EVT_CALL(RandInt, 60, LVar0)
            EVT_ADD(LVar0, 60)
            EVT_WAIT(LVar0)
            EVT_SET(LVar0, 2)
            EVT_EXEC(N(EVS_RandomFireworks))
            EVT_CALL(RandInt, 60, LVar0)
            EVT_ADD(LVar0, 60)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(240)
        EVT_LOOP(0)
            EVT_CALL(RandInt, 60, LVar1)
            EVT_ADD(LVar1, 5)
            EVT_CALL(RandInt, 5, LVar2)
            EVT_ADD(LVar2, 1)
            EVT_LOOP(LVar2)
                EVT_SET(LVar0, 1)
                EVT_EXEC(N(EVS_RandomFireworks))
                EVT_WAIT(LVar1)
            EVT_END_LOOP
            EVT_CALL(RandInt, 60, LVar0)
            EVT_ADD(LVar0, 60)
            EVT_WAIT(LVar0)
            EVT_SET(LVar0, 2)
            EVT_EXEC(N(EVS_RandomFireworks))
            EVT_CALL(RandInt, 60, LVar0)
            EVT_ADD(LVar0, 60)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(EnableGroup, MODEL_the_end, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_t, CUSTOM_GFX_1, -1)
    EVT_CALL(SetModelCustomGfx, MODEL_h, CUSTOM_GFX_1, -1)
    EVT_CALL(SetModelCustomGfx, MODEL_e, CUSTOM_GFX_1, -1)
    EVT_CALL(SetModelCustomGfx, MODEL_d, CUSTOM_GFX_1, -1)
    EVT_CALL(SetModelCustomGfx, MODEL_n, CUSTOM_GFX_1, -1)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(gfx_build_the_end)), NULL)
    EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(UpdateTheEndAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(600)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_FIREWORK_ROCKET, 0, 310, 280, -250, -1, 6, -1, EVT_FLOAT(1.6), 70)
        EVT_CALL(N(ChooseFireworkColors), LVarF)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 0, 100, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, EVT_FLOAT(3.6))
        EVT_SETF(LVar3, EVT_FLOAT(-6.0))
        EVT_SETF(LVar4, EVT_FLOAT(0.6))
        EVT_SETF(LVar5, EVT_FLOAT(-0.0048828125))
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar0)
        EVT_MULF(LVar4, LVar0)
        EVT_MULF(LVar5, LVar0)
        EVT_ADDF(LVar5, EVT_FLOAT(1.0))
        EVT_CALL(ScaleGroup, MODEL_the_end, LVar5, LVar5, LVar5)
        EVT_CALL(TranslateGroup, MODEL_the_end, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
