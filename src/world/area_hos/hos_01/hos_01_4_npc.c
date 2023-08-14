#include "hos_01.h"
#include "effects.h"

#include "world/common/todo/SwitchToPartner.inc.c"

API_CALLABLE(N(DrawAppearSparkles)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_sparkles(type, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_MuteMusicOnPlayerApproach) = {
    EVT_SET(LVarA, 0)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar1, 245)
            EVT_CALL(IsPlayerWithin, -30, -165, 180, LVar3)
            EVT_IF_EQ(LVar3, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
        EVT_LABEL(10)
        EVT_SET(LVarA, 1)
        EVT_CALL(FadeOutMusic, 0, 2000)
        EVT_WAIT(60)
        EVT_LABEL(20)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar1, 245)
                EVT_CALL(IsPlayerWithin, -30, -165, 180, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_GOTO(30)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_LABEL(30)
        EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
        EVT_WAIT(30)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_StarSpiritsPlea) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -35, 250, -145)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -35, 250, -145)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-5.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(func_802D2C14, 2)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 15 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0000)
    EVT_WAIT(10 * DT)
    EVT_WAIT(1)
    EVT_CALL(PlayerFaceNpc, NPC_Eldstar, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_Eldstar, 0)
    EVT_CALL(NpcJump0, NPC_Eldstar, 21, 260, -277, 30 * DT)
    EVT_CALL(EnableModel, MODEL_1, TRUE)
    EVT_CALL(PlaySound, SOUND_MULTIPLE_STAR_SPIRITS_APPEAR)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(N(DrawAppearSparkles), 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(EnableModel, MODEL_2, TRUE)
    EVT_CALL(EnableModel, MODEL_3, TRUE)
    EVT_CALL(EnableModel, MODEL_4, TRUE)
    EVT_CALL(EnableModel, MODEL_5, TRUE)
    EVT_CALL(EnableModel, MODEL_6, TRUE)
    EVT_CALL(EnableModel, MODEL_7, TRUE)
    EVT_SETF(MV_AlphaAmt_Others, EVT_FLOAT(-80.0))
    EVT_LOOP(20 * DT)
#if VERSION_PAL
        EVT_ADDF(MV_AlphaAmt_Others, EVT_FLOAT(7.203))
#else
        EVT_ADDF(MV_AlphaAmt_Others, EVT_FLOAT(6.0))
#endif
        EVT_WAIT(1)
    EVT_END_LOOP
#if VERSION_PAL
    EVT_SETF(MV_AlphaAmt_Others, EVT_FLOAT(40.0))
#endif
    EVT_CALL(EnableNpcShadow, NPC_Mamar, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Skolar, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Muskular, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Misstar, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Klevar, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Kalmar, TRUE)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0001)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 270)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.8 / DT))
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-6.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0002)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-6.9))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldEldstar_Idle, 0, MSG_HOS_0003)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-7.3))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldMamar_Idle, 0, MSG_HOS_0004)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-7.7))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 0, MSG_HOS_0005)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-7.7))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_HOS_0006)
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-7.3))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, 0, MSG_HOS_0007)
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-6.9))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_HOS_0008)
    EVT_SET(AB_HOS_StatcAmt_Kalmar, 200)
    EVT_WAIT(30 * DT)
    EVT_SET(AB_HOS_StatcAmt_Kalmar, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_HOS_0009)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-6.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_000A)
    EVT_SET(AB_HOS_StatcAmt_Eldstar,  200)
    EVT_SET(AB_HOS_StatcAmt_Mamar,    200)
    EVT_SET(AB_HOS_StatcAmt_Skolar,   200)
    EVT_SET(AB_HOS_StatcAmt_Muskular, 200)
    EVT_SET(AB_HOS_StatcAmt_Misstar,  200)
    EVT_SET(AB_HOS_StatcAmt_Klevar,   200)
    EVT_SET(AB_HOS_StatcAmt_Kalmar,   200)
    EVT_WAIT(30 * DT)
    EVT_SET(AB_HOS_StatcAmt_Eldstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Mamar,    0)
    EVT_SET(AB_HOS_StatcAmt_Skolar,   0)
    EVT_SET(AB_HOS_StatcAmt_Muskular, 0)
    EVT_SET(AB_HOS_StatcAmt_Misstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Klevar,   0)
    EVT_SET(AB_HOS_StatcAmt_Kalmar,   0)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_HOS_000B)
    EVT_CALL(EnableNpcShadow, NPC_Eldstar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Mamar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Skolar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Muskular, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Misstar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Klevar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Kalmar, FALSE)
    EVT_CALL(FullyRestoreHPandFP)
    EVT_SET(AB_HOS_StatcAmt_Eldstar,  100)
    EVT_SET(AB_HOS_StatcAmt_Mamar,    100)
    EVT_SET(AB_HOS_StatcAmt_Skolar,   100)
    EVT_SET(AB_HOS_StatcAmt_Muskular, 100)
    EVT_SET(AB_HOS_StatcAmt_Misstar,  100)
    EVT_SET(AB_HOS_StatcAmt_Klevar,   100)
    EVT_SET(AB_HOS_StatcAmt_Kalmar,   100)
    EVT_SETF(MV_AlphaAmt_Eldstar, EVT_FLOAT(40.0))
    EVT_SETF(MV_AlphaAmt_Others, EVT_FLOAT(40.0))
    EVT_LOOP(20 * DT)
        EVT_ADDF(MV_AlphaAmt_Eldstar, EVT_FLOAT(-6.0 / DT))
        EVT_ADDF(MV_AlphaAmt_Others, EVT_FLOAT(-6.0 / DT))
        EVT_WAIT(1)
    EVT_END_LOOP
#if VERSION_PAL
    EVT_SETF(MapVar(0), EVT_FLOAT(-80.0))
    EVT_SETF(MapVar(1), EVT_FLOAT(-80.0))
#endif
    EVT_SET(MF_SpiritsGone, TRUE)
    EVT_SET(AB_HOS_StatcAmt_Eldstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Mamar,    0)
    EVT_SET(AB_HOS_StatcAmt_Skolar,   0)
    EVT_SET(AB_HOS_StatcAmt_Muskular, 0)
    EVT_SET(AB_HOS_StatcAmt_Misstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Klevar,   0)
    EVT_SET(AB_HOS_StatcAmt_Kalmar,   0)
    EVT_CALL(EnableModel, MODEL_1, FALSE)
    EVT_CALL(EnableModel, MODEL_2, FALSE)
    EVT_CALL(EnableModel, MODEL_3, FALSE)
    EVT_CALL(EnableModel, MODEL_4, FALSE)
    EVT_CALL(EnableModel, MODEL_5, FALSE)
    EVT_CALL(EnableModel, MODEL_6, FALSE)
    EVT_CALL(EnableModel, MODEL_7, FALSE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(N(SwitchToPartner), PARTNER_GOOMBARIO)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_ADD(LVar2, 30)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_000C)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
        EVT_SET(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 3000 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Eldstar) = {
    EVT_EXEC(N(EVS_Scene_StarSpiritsPlea))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_Eldstar) = {
    EVT_SET(AB_HOS_StatcAmt_Eldstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Mamar,    0)
    EVT_SET(AB_HOS_StatcAmt_Skolar,   0)
    EVT_SET(AB_HOS_StatcAmt_Muskular, 0)
    EVT_SET(AB_HOS_StatcAmt_Misstar,  0)
    EVT_SET(AB_HOS_StatcAmt_Klevar,   0)
    EVT_SET(AB_HOS_StatcAmt_Kalmar,   0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Eldstar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Eldstar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Eldstar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Mamar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Mamar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Mamar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Skolar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Skolar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Skolar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Muskular, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Muskular, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Muskular, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Misstar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Misstar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Misstar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Klevar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Klevar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Klevar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(AB_HOS_StatcAmt_Kalmar, 0)
                EVT_CALL(RandInt, 45, LVar1)
                EVT_ADD(LVar1, 105)
                EVT_SET(AB_HOS_StatcAmt_Kalmar, 200)
                EVT_WAIT(10)
                EVT_SET(AB_HOS_StatcAmt_Kalmar, 0)
                EVT_WAIT(LVar1)
            EVT_ELSE
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_SETF(LVar0, 0)
        EVT_SETF(LVar1, 0)
        EVT_LOOP(20)
            EVT_ADDF(LVar0, EVT_FLOAT(4.0))
            EVT_ADDF(LVar1, EVT_FLOAT(4.0))
            EVT_SETF(LVar2, LVar0)
            EVT_ADDF(LVar2, MV_AlphaAmt_Eldstar)
            EVT_SETF(LVar3, LVar1)
            EVT_ADDF(LVar3, MV_AlphaAmt_Others)
            EVT_IF_LT(LVar2, 0)
                EVT_SETF(LVar2, EVT_FLOAT(0.0))
            EVT_END_IF
            EVT_IF_LT(LVar3, 0)
                EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_END_IF
            EVT_CALL(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Eldstar,  1, LVar2)
            EVT_CALL(SetNpcImgFXParams, NPC_Mamar,    IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Mamar,    1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Skolar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Skolar,   1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Muskular, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Muskular, 1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Misstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Misstar,  1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Klevar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Klevar,   1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Kalmar,   1, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_ADDF(LVar0, EVT_FLOAT(-4.0))
            EVT_ADDF(LVar1, EVT_FLOAT(-4.0))
            EVT_SETF(LVar2, LVar0)
            EVT_ADDF(LVar2, MV_AlphaAmt_Eldstar)
            EVT_SETF(LVar3, LVar1)
            EVT_ADDF(LVar3, MV_AlphaAmt_Others)
            EVT_IF_LT(LVar2, 0)
                EVT_SETF(LVar2, EVT_FLOAT(0.0))
            EVT_END_IF
            EVT_IF_LT(LVar3, 0)
                EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_END_IF
            EVT_CALL(SetNpcImgFXParams, NPC_Eldstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Eldstar,  1, LVar2)
            EVT_CALL(SetNpcImgFXParams, NPC_Mamar,    IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Mamar,    1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Skolar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Skolar,   1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Muskular, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Muskular, 1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Misstar,  IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Misstar,  1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Klevar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Klevar,   1, LVar3)
            EVT_CALL(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, AB_HOS_StatcAmt_Kalmar,   1, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Eldstar)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        EVT_EXEC(N(EVS_MuteMusicOnPlayerApproach))
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
        EVT_CALL(SetNpcPos, NPC_Eldstar,  NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Mamar,    NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Skolar,   NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Muskular, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Misstar,  NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Klevar,   NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Kalmar,   NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableNpcShadow, NPC_Mamar,    FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Skolar,   FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Muskular, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Misstar,  FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Klevar,   FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Kalmar,   FALSE)
    EVT_SET(MV_AlphaAmt_Eldstar, 40)
    EVT_SET(MV_AlphaAmt_Others, -80)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_StarSpirits)[] = {
    {
        .id = NPC_Eldstar,
        .pos = { -30.0f, 260.0f, -170.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .tattle = MSG_NpcTattle_Eldstar,
    },
    {
        .id = NPC_Mamar,
        .pos = { 100.0f, 260.0f, -215.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
    {
        .id = NPC_Skolar,
        .pos = { -145.0f, 260.0f, -225.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
    {
        .id = NPC_Muskular,
        .pos = { 20.0f, 260.0f, -45.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Misstar,
        .pos = { -155.0f, 260.0f, -125.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
    {
        .id = NPC_Klevar,
        .pos = { 90.0f, 260.0f, -110.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
    {
        .id = NPC_Kalmar,
        .pos = { -75.0f, 260.0f, -290.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_StarSpirits)),
    {}
};
