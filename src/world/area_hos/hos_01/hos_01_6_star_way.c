#include "hos_01.h"
#include "effects.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

#define NAME_SUFFIX _StarWay
#include "world/common/todo/GetFloorCollider.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_Scene_StarWayOpened) = {
    EVT_LABEL(0)
        EVT_CALL(N(GetFloorCollider_StarWay), LVar0)
        EVT_IF_NE(LVar0, COLLIDER_o234)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(FacePlayerTowardPoint, -30, -160, 0)
    EVT_WAIT(15)
    EVT_CALL(ShowMessageAtScreenPos, MSG_HOS_005C, 160, 40)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -100)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_HOS_005D, 160, 40)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 0, 8)
#if VERSION_PAL
    EVT_WAIT(30)
#else
    EVT_WAIT(10)
#endif
    EVT_CALL(EnableModel, MODEL_power, TRUE)
    EVT_SET(MV_StarBeamState, 1)
        EVT_LABEL(10)
        EVT_IF_NE(MV_StarBeamState, 2)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 245, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 245, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_PLAY_EFFECT(EFFECT_75, 0, -30, 250, -160, 1, -1)
    EVT_SET(MV_StarBeamFXPtr, LVarF)
    EVT_CALL(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
    EVT_CALL(MakeLerp, 1, 255, 55, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetStarBeamMasterAlpha), MV_StarBeamFXPtr, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(45)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -100)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_HOS_005E, 160, 40)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_SET(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
    EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AscendStarBeam) = {
    EVT_CALL(N(func_80240B10_A11390), MV_StarBeamFXPtr)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -30, 250, -160)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -30, 250, -160)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -30, -160, 0)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 1, 8)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_PARTNER, -30, 250, -170, 15)
    EVT_THREAD
        EVT_SET(LVar2, 90)
        EVT_CALL(MakeLerp, 1, 90, 60, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_ADD(LVar2, LVar0)
            EVT_CALL(InterpPlayerYaw, LVar2, 0)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_ADD(LVar2, LVar0)
            EVT_CALL(InterpPlayerYaw, LVar2, 0)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(N(EnableCameraFollowPlayerY))
    EVT_THREAD
        EVT_LABEL(10)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 430)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_SET(LVar5, LVar4)
    EVT_ADD(LVar5, -10)
    EVT_CALL(MakeLerp, LVar3, 700, 90, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, LVar2, LVar0, LVar4)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar5)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
