#include "sam_01.h"
#include "sprite/player.h"

#include "common/GetItemEntityPosition.inc.c"
#include "world/common/todo/GetLeftRightPoints.inc.c"

EvtScript N(EVS_MayorCarryGift) = {
    EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Penguin_09, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, LVar0)
    EVT_SUB(LVar4, LVar1)
    EVT_SUB(LVar5, LVar2)
    EVT_ADD(LVar3, 3)
    EVT_ADD(LVar5, 5)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_CALL(SetNpcPos, NPC_Penguin_09, LVar0, LVar1, LVar2)
        EVT_SET(LVar6, LVar0)
        EVT_SUB(LVar6, 10)
        EVT_CALL(SetItemPos, MV_PresentItemID, LVar6, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HerringwayCarryPresent) = {
    EVT_CALL(N(GetItemEntityPosition), MV_PresentItemID, LVarA, LVarB, LVarC)
    EVT_LOOP(6)
        EVT_CALL(SetItemPos, MV_PresentItemID, LVarA, LVarB, LVarC)
        EVT_ADD(LVarC, 10)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 20)
        EVT_CALL(SetItemPos, MV_PresentItemID, LVar0, LVarB, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenMayorsOfficeDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttsn, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 20, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o236, LVar0, 0, -1, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseMayorsOfficeDoor) = {
    EVT_CALL(MakeLerp, 80, 0, 20, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o236, LVar0, 0, -1, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttsn, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MysteryBegins) = {
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguinWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-236.1), EVT_FLOAT(0.0), EVT_FLOAT(-45.6))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-300.0), EVT_FLOAT(-53.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_EXEC_WAIT(N(EVS_OpenMayorsOfficeDoor))
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_EXEC_WAIT(N(EVS_CloseMayorsOfficeDoor))
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguinWife, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcPos, NPC_MayorPenguinWife, -255, 0, 28)
    EVT_CALL(SetNpcSpeed, NPC_MayorPenguinWife, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Walk)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -30, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Idle)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0005)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -255, 0, -150)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.4 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, -284, 0, -165)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -320, 0, -190)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 180, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Walk)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -40, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -165, 0)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -185, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguinWife, SOUND_0262, 0)
    EVT_CALL(ShowEmote, NPC_MayorPenguinWife, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Walk)
    EVT_CALL(SetNpcSpeed, NPC_MayorPenguinWife, EVT_FLOAT(0.5 / DT))
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -200, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Inspect)
    EVT_WAIT(35 * DT)
    EVT_THREAD
        EVT_CALL(SetMusicTrack, 0, SONG_PENGUIN_WHODUNIT, 0, 8)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Horror)
        EVT_SET(MF_ContinueScene, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Horror, ANIM_MayorPenguinWife_Horror, 0, MSG_CH7_0006)
        EVT_SET(MF_ContinueScene, TRUE)
    EVT_END_THREAD
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_LOOP(5)
        EVT_CALL(GetNpcPos, NPC_MayorPenguinWife, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(210.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_MayorPenguinWife, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_LOOP
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    EVT_LABEL(2)
        EVT_IF_EQ(MF_ContinueScene, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcSpeed, NPC_MayorPenguinWife, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Panic)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, 0, 0)
    EVT_CALL(SetNpcPos, NPC_MayorPenguinWife, -255, 0, 60)
    EVT_WAIT(30 * DT)
    EVT_SET(MF_ContinueScene, FALSE)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_WAIT(60 * DT)
        EVT_SET(MF_ContinueScene, TRUE)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_0007, 160, 40)
    EVT_LABEL(100)
        EVT_IF_EQ(MF_ContinueScene, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpPlayerYaw, 180, 5)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpPlayerYaw, 0, 5)
    EVT_WAIT(90 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpPlayerYaw, 180, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-236.1), EVT_FLOAT(0.0), EVT_FLOAT(-45.6))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-300.0), EVT_FLOAT(-53.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetNpcPos, NPC_PARTNER, -306, 0, -116)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Horror, ANIM_MayorPenguinWife_Horror, 5, MSG_CH7_0008)
    EVT_WAIT(20 * DT)
    EVT_EXEC_WAIT(N(EVS_OpenMayorsOfficeDoor))
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_EXEC_WAIT(N(EVS_CloseMayorsOfficeDoor))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(MF_ContinueScene, FALSE)
        EVT_CALL(SetNpcPos, NPC_PenguinPatrol, -255, 0, 50)
        EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(2.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
        EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -255, -75, 0)
        EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
        EVT_SET(MF_ContinueScene, TRUE)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_MayorPenguinWife, -255, 0, 80)
    EVT_CALL(SetNpcSpeed, NPC_MayorPenguinWife, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Walk)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -20, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Idle)
    EVT_LABEL(5)
        EVT_IF_EQ(MF_ContinueScene, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Point, 0, MSG_CH7_0009)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, 180, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -255, 0, -150)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.4 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(PlayerMoveTo, -315, -150, 20 * DT)
        EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -255, -180, 0)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_SET(MF_ContinueScene, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Walk)
        EVT_CALL(NpcMoveTo, NPC_MayorPenguinWife, -255, -70, 0)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Idle)
        EVT_SET(MF_ContinueScene, TRUE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Inspect)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_000A)
    EVT_LABEL(6)
        EVT_IF_EQ(MF_ContinueScene, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(6)
        EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Point, 0, MSG_CH7_000B)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-340.5), EVT_FLOAT(0.0), EVT_FLOAT(-180.7))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-463.0), EVT_FLOAT(180.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-215.0), EVT_FLOAT(-175.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetAngleToPlayer, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
    EVT_WAIT(13 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_000C)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    EVT_WAIT(35 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_000D)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Point, 0, MSG_CH7_000E)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_000F)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0010)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0011)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0012)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0013)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0014)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0015)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0016)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, NPC_PenguinPatrol, MSG_CH7_0017)
    EVT_END_SWITCH
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_0018)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_TalkThink, ANIM_PenguinPatrol_StillThink, 0, MSG_CH7_0019)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001A)
    EVT_CALL(SetNpcPos, NPC_Penguin_05, -150, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Penguin_05, 90, 0)
    EVT_CALL(SetNpcPos, NPC_Penguin_06, -90, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Penguin_06, 270, 0)
    EVT_CALL(SetNpcPos, NPC_Penguin_07, -120, 0, -30)
    EVT_CALL(InterpNpcYaw, NPC_Penguin_07, 180, 0)
    EVT_CALL(SetNpcPos, NPC_Penguin_08, -120, 0, 30)
    EVT_CALL(InterpNpcYaw, NPC_Penguin_08, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguinWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_SET(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
    EVT_SET(GB_SAM11_FrozenPondDamage, 0)
    EVT_SET(MV_DialogueState_Penguin1, 0)
    EVT_SET(MV_DialogueState_Penguin2, 0)
    EVT_SET(MV_DialogueState_Penguin3, 0)
    EVT_SET(MV_DialogueState_Penguin4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MysterySolved) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -262, -103, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_CALL(GetAngleToPlayer, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001D)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerPos, -255, 0, -135)
    EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001E)
    EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
    EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Inspect)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 5, MSG_CH7_001F)
    EVT_CALL(GetAngleToPlayer, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 20)
        EVT_CALL(PlayerMoveTo, LVar0, LVar2, 20 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_Herringway, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -306, -116, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Herringway, 0)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
    EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_0020)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_PenguinPatrol, LVar3, LVar4, LVar5)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Herringway, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_0021)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Herringway, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Herringway, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
    EVT_WAIT(1)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_PenguinPatrol, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_TalkThink, ANIM_PenguinPatrol_StillThink, 0, MSG_CH7_0022)
    EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_Herringway, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_PenguinPatrol, NPC_Herringway, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Herringway, FALSE)
    EVT_WAIT(1)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Herringway, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Herringway, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_0023)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Herringway, NPC_MayorPenguinWife, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Herringway, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_PenguinPatrol, NPC_MayorPenguinWife, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_MayorPenguinWife, FALSE)
    EVT_WAIT(1)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_MayorPenguinWife, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Point, 0, MSG_CH7_0024)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), EVT_FLOAT(-6.5))
    EVT_CALL(N(GetLeftRightPoints), LVar0, LVar2, 45)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Herringway, NPC_PenguinPatrol, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Herringway, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
    EVT_WAIT(1)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_PenguinPatrol, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_TalkThink, ANIM_PenguinPatrol_StillThink, 0, MSG_CH7_0025)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch)
    EVT_WAIT(30 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguin, SOUND_ACTOR_TWITCH, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Dead)
    EVT_WAIT(2 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguin, SOUND_ACTOR_TWITCH, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Dead)
    EVT_WAIT(2 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetLeftRightPoints), LVar0, LVar2, -95)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch, ANIM_MayorPenguin_Twitch, 0, MSG_CH7_0026)
    EVT_CALL(GetAngleBetweenNPCs, NPC_PenguinPatrol, NPC_MayorPenguin, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_MayorPenguin, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Herringway, NPC_MayorPenguin, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Herringway, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_MayorPenguin, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_MayorPenguin, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguin, SOUND_ACTOR_TWITCH, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Dead)
    EVT_WAIT(2 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguin, SOUND_ACTOR_TWITCH, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Dead)
    EVT_WAIT(2 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Twitch)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 11)
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_CALL(EnableNpcShadow, NPC_MayorPenguin, FALSE)
    EVT_CALL(SetNpcPos, NPC_MayorDummy, -270, 0, -205)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcPos, NPC_MayorDummy, NPC_DISPOSE_LOCATION)
        EVT_CALL(EnableNpcShadow, NPC_MayorPenguin, TRUE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_WakeUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_MayorPenguin, SOUND_032C, 0)
    EVT_CALL(SetNpcJumpscale, NPC_MayorPenguin, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_MayorPenguin, LVar0, 0, LVar2, 10 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PENGUIN_WAKES_UP, 0, 8)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0027)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, 180, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Surprise)
    EVT_CALL(SetNpcJumpscale, NPC_MayorPenguinWife, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_MayorPenguinWife, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_MayorPenguinWife, LVar0, LVar1, LVar2, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Idle)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguinWife, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0028)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0029)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SpeakToNpc, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, NPC_MayorPenguin, MSG_CH7_002A)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, NPC_PenguinPatrol, MSG_CH7_002B)
    EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(280.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_CarryTalk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_002C)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_LOOP(200)
            EVT_CALL(GetAngleBetweenNPCs, NPC_PenguinPatrol, NPC_MayorPenguin, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_PenguinPatrol, LVar0, 0)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Herringway, NPC_MayorPenguin, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_Herringway, LVar0, 0)
            EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_MayorPenguin, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Penguin_09, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_MayorPenguin, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Walk)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguin, -320, -258, 0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, 180, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_WAIT(25 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 30)
        EVT_CALL(PlayerMoveTo, LVar0, LVar2, 20 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_MayorPenguin, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_MayorPenguin, 0)
        EVT_WAIT(50 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_MayorPenguin, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_MayorPenguin, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_SET(LVar0, 0)
        EVT_LOOP(8)
            EVT_CALL(GetNpcPos, NPC_Penguin_09, LVar0, LVar1, LVar2)
            EVT_ADDF(LVar1, EVT_FLOAT(1.25))
            EVT_CALL(SetNpcPos, NPC_Penguin_09, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_PickUp)
    EVT_WAIT(30 * DT)
    EVT_EXEC_GET_TID(N(EVS_MayorCarryGift), LVarA)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-300.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Carry)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -35)
    EVT_CALL(NpcMoveTo, NPC_MayorPenguin, LVar0, LVar2, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_LOOP(7)
            EVT_CALL(GetNpcPos, NPC_Penguin_09, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, 1)
            EVT_CALL(SetNpcPos, NPC_Penguin_09, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, NPC_Herringway, MSG_CH7_002D)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Give)
    EVT_WAIT(60 * DT)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -5)
    EVT_CALL(NpcMoveTo, NPC_Herringway, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Recieve)
    EVT_CALL(SpeakToNpc, NPC_Herringway, ANIM_Herringway_TalkCarry, ANIM_Herringway_IdleCarry, 0, NPC_MayorPenguin, MSG_CH7_002E)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_Herringway, 0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_PenguinPatrol, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_002F)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcSpeed, NPC_MayorPenguin, EVT_FLOAT(3.0 / DT))
        EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Walk)
        EVT_CALL(NpcMoveTo, NPC_MayorPenguin, -249, -109, 0)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
        EVT_LOOP(100)
            EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguin, NPC_PenguinPatrol, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetAngleBetweenNPCs, NPC_MayorPenguinWife, NPC_PenguinPatrol, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, LVar0, 0)
            EVT_CALL(PlayerFaceNpc, NPC_PenguinPatrol, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_PenguinPatrol, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -210, -80, 0)
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -250, -10, 0)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PenguinPatrol, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_EXEC_WAIT(N(EVS_OpenMayorsOfficeDoor))
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Walk)
    EVT_CALL(NpcMoveTo, NPC_PenguinPatrol, -250, 50, 0)
    EVT_CALL(SetNpcAnimation, NPC_PenguinPatrol, ANIM_PenguinPatrol_Idle)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0030)
    EVT_CALL(SpeakToPlayer, NPC_Herringway, ANIM_Herringway_TalkCarry, ANIM_Herringway_IdleCarry, 0, MSG_CH7_0031)
    EVT_EXEC_GET_TID(N(EVS_HerringwayCarryPresent), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_Herringway, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_WalkCarry)
    EVT_CALL(NpcMoveTo, NPC_Herringway, -250, 50, 0)
    EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_IdleCarry)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(RemoveItemEntity, MV_PresentItemID)
    EVT_EXEC_WAIT(N(EVS_CloseMayorsOfficeDoor))
    EVT_SET(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 5, MSG_CH7_0032)
    EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0033)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(1)
    EVT_CALL(SpeakToPlayer, NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0034)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, NPC_PenguinPatrol, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Herringway, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_INACTIVE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Herringway, FALSE)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(MV_DialogueState_Penguin1, 0)
    EVT_SET(MV_DialogueState_Penguin2, 0)
    EVT_SET(MV_DialogueState_Penguin3, 0)
    EVT_SET(MV_DialogueState_Penguin4, 0)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguin, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_MayorPenguinWife, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, NPC_Penguin_09, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
