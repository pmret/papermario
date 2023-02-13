#include "kkj_25.h"
#include "effects.h"

#include "world/common/todo/GetFloorCollider.inc.c"

#include "common/UnkLightningFXFunc.inc.c"

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(func_80240264_B06C64)) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_lens_flare(0, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

s32 N(missing_80245640_5640)[] = {
    0x00000000, 0x004B0048, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00180018, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 
    0x00220018, 0x00000000, 0x00000000, 0x00000000, 0x80077F70, 0x00000000, 0x8007809C, 0x00000000, 
    0x00000000, 0x001A0000, 0x00000000, 0x00170016, 0x00000000, 0x00000000, 0x00000000, 0x80077F70, 
    0x00000000, 0x8007809C, 0x00000000, 0x00000000, 0x000E0001, 0x00000000, 0x00180018, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 
};

EvtScript N(D_8024571C_B0C11C) = {
    EVT_CALL(PlaySoundAt, SOUND_5A, 0, 300, -70, 280)
    EVT_CALL(N(func_80240264_B06C64), 225, -70, 280, 240)
    EVT_CALL(N(func_80240264_B06C64), 380, -70, 280, 240)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245784_B0C184) = {
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(N(GetEntityPosition), MV_Unk_00, LVar7, LVar8, LVar9)
        EVT_CALL(MakeLerp, 0, -13, 5, EASING_COS_IN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPositionF), MV_Unk_00, LVar7, LVar0, LVar9)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(30)
        EVT_CALL(N(SetEntityPositionF), MV_Unk_00, LVar7, -20, LVar9)
        EVT_CALL(SetNpcFlagBits, NPC_Bowser_01, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(MV_Unk_0A, 0)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Jump)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Land)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh)
        EVT_CALL(PlaySound, SOUND_3BC)
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 1, EVT_FLOAT(2.0))
            EVT_WAIT(1)
            EVT_IF_EQ(MV_Unk_0A, 11)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySound, 0x000007BC)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Bowser_01, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Bowser_01, 300, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_01, SOUND_208B, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_01, SOUND_20A0, 0)
    EVT_SET(AF_KKJ_1A, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802459E4) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
        EVT_CASE_EQ(PARTNER_KOOPER)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
        EVT_CASE_EQ(PARTNER_SUSHIE)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 19)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80245AB0_B0C4B0)[] = {
    87, 84, 81, 78, 75, 72, 69, 66, 
    63, 60, 57, 54, 51, 48, 45, 42, 
};

EvtScript N(EVS_80245AF0) = {
    EVT_LABEL(0)
    EVT_CALL(N(GetFloorCollider), LVar0)
    EVT_IF_NE(LVar0, 11)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(PlayerFaceNpc, NPC_Bowser_01, FALSE)
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_EQ(LVar1, PARTNER_BOMBETTE)
            EVT_IF_NE(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(GetCurrentPartnerID, LVar1)
            EVT_IF_NE(LVar1, PARTNER_LAKILESTER)
                EVT_CALL(WaitForPlayerTouchingFloor)
            EVT_END_IF
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(5)
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 20)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_IF_LT(LVar5, 0)
                EVT_ADD(LVar5, 25)
            EVT_ELSE
                EVT_ADD(LVar5, -25)
            EVT_END_IF
            EVT_ADD(LVar3, -10)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.8))
            EVT_CALL(NpcJump0, NPC_PARTNER, LVar3, LVar1, LVar5, 12)
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
        EVT_LABEL(1)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007C)
    EVT_WAIT(20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 350, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 350, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007D)
    EVT_EXEC_WAIT(N(D_80245784_B0C184))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -150, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -150, 0, 100)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(26.0), EVT_FLOAT(-18.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -480, -480)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 480)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F20_B0C920) = {
    EVT_USE_BUF(EVT_PTR(N(D_80245AB0_B0C4B0)))
    EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_SET(LVar2, 1)
    EVT_LOOP(16)
        EVT_BUF_READ1(LVar3)
        EVT_SETF(LVar0, 0)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_SUBF(LVar0, LVar1)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(5)
                EVT_ADDF(LVar0, LVar1)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(5)
                EVT_ADDF(LVar0, LVar1)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(5)
                EVT_SUBF(LVar0, LVar1)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_IF_LT(LVar2, 8)
            EVT_ADDF(LVar1, EVT_FLOAT(0.5))
        EVT_ELSE
            EVT_SUBF(LVar1, EVT_FLOAT(0.5))
        EVT_END_IF
        EVT_ADD(LVar2, 1)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246128_B0CB28) = {
    EVT_LOOP(4)
        EVT_EXEC(N(D_80245F20_B0C920))
        EVT_WAIT(25)
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(15)
        EVT_SET(MV_Unk_0A, 11)
    EVT_END_THREAD
    EVT_USE_BUF(EVT_PTR(N(D_80245AB0_B0C4B0)))
    EVT_SET(LVar2, 35)
    EVT_SET(LVar5, -15)
    EVT_LOOP(16)
        EVT_CALL(PlaySoundAt, SOUND_B000001B, 0, LVar5, 0, 0)
        EVT_ADD(LVar5, -30)
        EVT_BUF_READ1(LVar3)
        EVT_THREAD
            EVT_CALL(MakeLerp, 0, -25, 5, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_SET(LVar4, 0)
            EVT_CALL(MakeLerp, -25, -1000, LVar2, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
                EVT_ADD(LVar4, -20)
                EVT_CALL(RotateGroup, LVar3, LVar4, 0, 0, 1)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(EnableGroup, LVar3, FALSE)
        EVT_END_THREAD
        EVT_ADD(LVar2, 2)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_80246394_B0CD94)[] = {
    230, 160, 0, 350, 160, 90, 420, 160, 
    10, 280, 160, -10, 
};

s32 N(D_802463C4_B0CDC4)[] = {
    330, 160, 50, 360, 160, -50, 370, 160, 
    50, 330, 160, -50, 
};

EvtScript N(EVS_802463F4) = {
    EVT_SET(AF_KKJ_1A, FALSE)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -150, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -150, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-5.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -480, -480)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 480)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(30)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000A)
    EVT_END_THREAD
    EVT_SET(MV_Unk_0A, 10)
    EVT_EXEC_WAIT(N(D_80246128_B0CB28))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetPlayerPos, 100, 0, 0)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EVT_END_IF
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 70, 0, 0)
    EVT_CALL(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 330)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_CH8_007E)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_BattleKooper_01, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_BattleKooper_01, LVar0, LVar1, LVar2, 12)
        EVT_WAIT(8)
        EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_BattleKooper_01, LVar0, LVar1, LVar2, 7)
        EVT_WAIT(10)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_BattleKooper_01, ANIM_BattleBow_FanSmackOnce, 0x000C001E, 0, MSG_CH8_007F)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_BattleKammy_01, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 512, MSG_CH8_0080)
    EVT_WAIT(15)
    EVT_CALL(GetNpcPos, NPC_BattleKammy_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_BattleKooper_01, 90, 0)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_BattleKooper_01, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim07)
    EVT_CALL(SpeakToPlayer, NPC_BattleKammy_01, ANIM_BattleKammy_Anim07, ANIM_BattleKammy_Anim07, 512, MSG_CH8_0081)
    EVT_CALL(FadeOutMusic, 0, 0x000005DC)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim08)
    EVT_CALL(GetNpcPos, NPC_BattleKammy_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_CALL(PlaySoundAt, SOUND_207A, 0, LVar0, 22, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, 22, 0, 1, 80)
    EVT_THREAD
        EVT_WAIT(80)
        EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim04)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), 300, 0, 0, 1100, EVT_FLOAT(7.0), EVT_FLOAT(0.0))
    EVT_WAIT(20)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_BATTLE, 0, 8)
    EVT_EXEC(N(D_8024571C_B0C11C))
    EVT_WAIT(30)
    EVT_SET(MV_Unk_0B, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(MV_Unk_0B, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Shock)
    EVT_CALL(GetNpcPos, NPC_Bowser_01, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_USE_BUF(EVT_PTR(N(D_80246394_B0CD94)))
        EVT_LOOP(4)
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_USE_BUF(EVT_PTR(N(D_802463C4_B0CDC4)))
        EVT_LOOP(4)
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8)
            EVT_WAIT(12)
        EVT_END_LOOP
        EVT_CALL(SetNpcDecoration, NPC_Bowser_01, 0, NPC_DECORATION_BOWSER_AURA)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_01, SOUND_223, 0)
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_LOOP(50)
        EVT_ADDF(LVar0, EVT_FLOAT(0.01))
        EVT_CALL(SetNpcScale, NPC_Bowser_01, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0082)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_LOOP(4)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 4, EVT_FLOAT(2.0))
            EVT_WAIT(3)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bowser_01, 200, 0, 45)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0083)
    EVT_WAIT(10)
    EVT_CALL(SetNpcVar, NPC_Bowser_01, 0, 1)
    EVT_RETURN
    EVT_END
};

Vec3i N(D_80246FFC_B0D9FC)[] = {
    { EVT_FLOAT(625.825), EVT_FLOAT(-9.194), EVT_FLOAT(-91.893)  }, { EVT_FLOAT(609.671), EVT_FLOAT(-9.194), EVT_FLOAT(136.274)  },
    { EVT_FLOAT(609.671), EVT_FLOAT(-9.194), EVT_FLOAT(136.274)  }, { EVT_FLOAT(450.634), EVT_FLOAT(-9.194), EVT_FLOAT(300.677)  },
    { EVT_FLOAT(450.634), EVT_FLOAT(-9.194), EVT_FLOAT(300.677)  }, { EVT_FLOAT(223.128), EVT_FLOAT(-9.194), EVT_FLOAT(324.39)   },
    { EVT_FLOAT(223.128), EVT_FLOAT(-9.194), EVT_FLOAT(324.39)   }, { EVT_FLOAT(33.606),  EVT_FLOAT(-9.194), EVT_FLOAT(196.317)  },
    { EVT_FLOAT(33.606),  EVT_FLOAT(-9.194), EVT_FLOAT(196.317)  }, { EVT_FLOAT(-29.252), EVT_FLOAT(-9.194), EVT_FLOAT(-23.615)  },
    { EVT_FLOAT(-29.252), EVT_FLOAT(-9.194), EVT_FLOAT(-23.615)  }, { EVT_FLOAT(63.964),  EVT_FLOAT(-9.194), EVT_FLOAT(-232.497) },
    { EVT_FLOAT(63.964),  EVT_FLOAT(-9.194), EVT_FLOAT(-232.497) }, { EVT_FLOAT(269.64),  EVT_FLOAT(-9.194), EVT_FLOAT(-332.591) },
    { EVT_FLOAT(269.64),  EVT_FLOAT(-9.194), EVT_FLOAT(-332.591) }, { EVT_FLOAT(491.536), EVT_FLOAT(-9.194), EVT_FLOAT(-277.063) },
    { EVT_FLOAT(491.536), EVT_FLOAT(-9.194), EVT_FLOAT(-277.063) }, { EVT_FLOAT(625.825), EVT_FLOAT(-9.194), EVT_FLOAT(-91.893)  },
};

Vec3i N(D_802470D4_B0DAD4)[] = {
    { 180, 300, -200 }, { 250, 0, -150 },
    { 270, 300, -200 }, { 200, 0, -150 },
    { 350, 300, -240 }, { 500, 0, -160 },
    { 550, 300, -240 }, { 400, 0, -160 },
    { 500, 300,  -50 }, { 550, 0,  -50 },
    { 585, 300,  100 }, { 535, 0,  100 },
    {  95, 300,  -50 }, { 180, 0,  -50 },
    { 215, 300,  -50 }, { 130, 0,  -50 },
};

EvtScript N(EVS_80247194) = {
    EVT_CHILD_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_IF_EQ(GF_KKJ25_Defeated_Kammy, FALSE)
            EVT_THREAD
                EVT_WAIT(50)
                EVT_CALL(PlaySound, SOUND_22C)
            EVT_END_THREAD
            EVT_CALL(MakeLerp, 0, 50, 120, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIV(LVar0, 10)
                EVT_SUB(LVar2, LVar0)
                EVT_CALL(RotateGroup, MODEL_g31, LVar2, 0, 1, 0)
                EVT_ADD(LVar3, LVar0)
                EVT_CALL(RotateGroup, MODEL_g7, LVar3, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_ELSE
            EVT_IF_EQ(GF_KKJ25_Defeated_Bowser, FALSE)
                EVT_CALL(PlaySound, SOUND_22D)
            EVT_END_IF
            EVT_SET(LVar0, 5)
        EVT_END_IF
        EVT_LOOP(0)
            EVT_ADDF(LVar2, LVar0)
            EVT_IF_GT(LVar2, 360)
                EVT_SUBF(LVar2, 360)
            EVT_END_IF
            EVT_CALL(RotateGroup, MODEL_g31, LVar2, 0, 1, 0)
            EVT_SUBF(LVar3, LVar0)
            EVT_IF_LT(LVar3, -360)
                EVT_ADDF(LVar3, 360)
            EVT_END_IF
            EVT_CALL(RotateGroup, MODEL_g7, LVar3, 0, 1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(45)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(D_80246FFC_B0D9FC)))
            EVT_LOOP(9)
                EVT_BUF_READ3(LVar0, LVar1, LVar2)
                EVT_BUF_READ3(LVar3, LVar4, LVar5)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5)
                EVT_CALL(N(UnkLightningFXFunc))
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(D_802470D4_B0DAD4)))
            EVT_CALL(RandInt, 7, LVar6)
            EVT_ADD(LVar6, 1)
            EVT_LOOP(LVar6)
                EVT_BUF_READ3(LVar0, LVar1, LVar2)
                EVT_BUF_READ3(LVar3, LVar4, LVar5)
            EVT_END_LOOP
            EVT_IF_NE(MV_Unk_0B, 10)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 10)
                EVT_CALL(N(UnkLightningFXFunc))
                EVT_WAIT(30)
            EVT_ELSE
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5)
                EVT_CALL(N(UnkLightningFXFunc))
                EVT_WAIT(15)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 20)
            EVT_IF_GE(LVar0, 360)
                EVT_SUB(LVar0, 360)
            EVT_END_IF
            EVT_CALL(RotateGroup, MODEL_g51, LVar0, 0, 1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_IF_EQ(GF_KKJ25_Defeated_Kammy, FALSE)
            EVT_CALL(EnableModel, MODEL_o122, TRUE)
            EVT_CALL(MakeLerp, 0, 250, 100, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_LOOP(0)
            EVT_IF_NE(MV_Unk_0B, 10)
                EVT_SET(LVar2, 250)
            EVT_ELSE
                EVT_SET(LVar2, 90)
            EVT_END_IF
            EVT_CALL(MakeLerp, LVar2, 90, 45, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_LOOP(15)
                EVT_CALL(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 90, LVar2, 30, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(180)
    EVT_SET(MV_Unk_0B, 2)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_Unk_0B, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_22D)
    EVT_RETURN
    EVT_END
};
