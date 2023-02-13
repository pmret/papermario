#include "kkj_25.h"
#include "effects.h"

#define KNOCK_DOWN_MAP_VAR MapVar(10)
#include "world/common/complete/KnockDownPlayer.inc.c"

API_CALLABLE(N(func_80240B18_B07518)) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240B8C_B0758C)) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240BA0_B075A0)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    effect->data.starsOrbiting->pos.x = var1;
    effect->data.starsOrbiting->pos.y = var2;
    effect->data.starsOrbiting->pos.z = var3;

    return ApiStatus_DONE2;
}

Vec3f N(D_802479A0_B0E3A0)[] = {
    {  445.0,    60.0,    0.0 },
    {  480.0,    40.0,  -20.0 },
    {  510.0,    25.0,    0.0 },
};

EvtScript N(D_802479C4_B0E3C4) = {
    EVT_CALL(GetNpcPos, LVar8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, EVT_FLOAT(54.0))
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), -1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, LVar8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, EVT_FLOAT(54.0))
        EVT_CALL(N(func_80240BA0_B075A0), LVarF, LVar0, LVar1, LVar2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80247AAC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
    EVT_CALL(SetPlayerPos, 100, 0, 0)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EVT_END_IF
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x00000106)
    EVT_CALL(SetNpcPos, NPC_Bowser_01, 200, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    EVT_CALL(SetNpcPos, NPC_BattleKooper_01, 475, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_01, 0x000C001E)
    EVT_CALL(SetNpcPos, NPC_BattleKammy_01, 550, 10, -50)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim04)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_01, 0, NPC_DECORATION_BOWSER_AURA)
    EVT_CALL(SetNpcDecoration, NPC_Bowser_01, 1, NPC_DECORATION_CHARGED)
    EVT_SET(LVar8, 0)
    EVT_EXEC(N(D_802479C4_B0E3C4))
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 30)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30)
    EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_BattleKooper_01, ANIM_BattleBow_FanSmackOnce, 0x000C001E, 0, MSG_CH8_008E)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(NpcMoveTo, NPC_BattleKammy_01, 520, -50, 15)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_BattleKooper_01, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim0B)
    EVT_CALL(SpeakToPlayer, NPC_BattleKammy_01, ANIM_BattleKammy_Anim07, ANIM_BattleKammy_Anim0B, 0, MSG_CH8_008F)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Sad)
    EVT_CALL(SetNpcPos, NPC_Twink_01, 850, 400, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Twink_01, 530, 45, -50, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_BattleKammy_01, SOUND_HIT_NORMAL, 0)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, 3, 530, 45, -50, -1, -1, 0, 3)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim0C)
        EVT_CALL(SetNpcPos, NPC_BattleKammy_02, 530, 15, -50)
        EVT_CALL(SetNpcJumpscale, NPC_BattleKammy_01, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump1, NPC_BattleKammy_01, 540, 10, -50, 30)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_BattleKammy_02, EVT_FLOAT(0.4))
        EVT_CALL(NpcJump0, NPC_BattleKammy_02, 545, 0, -30, 25)
        EVT_CALL(GetNpcPos, NPC_BattleKammy_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 30)
        EVT_SET(LVar3, 20)
        EVT_SET(LVar4, 3)
        EVT_CALL(N(func_80240B18_B07518))
        EVT_SET(MV_Unk_00, LVar0)
        EVT_CALL(PlaySound, SOUND_20E5)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_BattleKammy_02, ANIM_BattleKammy_Anim03)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_Twink_01, 445, 60, 0, 30)
        EVT_CALL(InterpNpcYaw, NPC_Twink_01, 90, 0)
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(D_802479A0_B0E3A0)), 3, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Twink_01, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Twink_01, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Twink_01, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_CH8_0090)
    EVT_WAIT(10)
    EVT_CALL(SetNpcJumpscale, NPC_Twink_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Twink_01, 490, 18, 0, 20)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Back)
    EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 20)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
        EVT_LOOP(2)
            EVT_LOOP(6)
                EVT_ADD(LVar1, -1)
                EVT_CALL(SetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
            EVT_WAIT(3)
            EVT_LOOP(6)
                EVT_ADD(LVar1, 1)
                EVT_CALL(SetNpcPos, NPC_Twink_01, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_BattleKooper_01, ANIM_BattleBow_FanSmackLoop, ANIM_BattleBow_FanSmackBack, 5, MSG_CH8_0091)
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_01, ANIM_BattleBow_FanSmackBack)
    EVT_SET(LVar2, 12)
    EVT_LOOP(4)
        EVT_CALL(MakeLerp, 90, 450, LVar2, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_ADD(LVar0, 90)
            EVT_IF_GT(LVar0, 359)
                EVT_SUB(LVar0, 360)
            EVT_END_IF
            EVT_CALL(InterpNpcYaw, NPC_BattleKooper_01, LVar0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SUB(LVar2, 2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_01, ANIM_BattleKooper_StillHappy)
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    EVT_WAIT(20)
    EVT_SET(LVar0, MV_Unk_00)
    EVT_CALL(N(func_80240B8C_B0758C))
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_02, ANIM_BattleKammy_Anim00)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_Twink_01, 90, 0)
    EVT_CALL(NpcFaceNpc, NPC_BattleKammy_02, NPC_BattleKammy_01, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Sad)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_02, ANIM_BattleKammy_Anim02)
    EVT_CALL(SetNpcJumpscale, NPC_BattleKammy_02, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_BattleKammy_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_SUB(LVar2, 5)
    EVT_CALL(NpcJump0, NPC_BattleKammy_02, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcPos, NPC_BattleKammy_02, 300, -100, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim04)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_BattleKammy_01, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 0, MSG_CH8_0092)
    EVT_WAIT(10)
    EVT_CALL(SetNpcVar, NPC_BattleKammy_01, 0, 1)
    EVT_RETURN
    EVT_END
};
