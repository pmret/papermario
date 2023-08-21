#include "arn_11.h"
#include "sprite/player.h"

EvtScript N(EVS_SetupCamera) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 60, 30, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 60, 30, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MeetHeart) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 6, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00BF)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_TubbasHeart, EVT_FLOAT(2.5))
        EVT_CALL(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 10 * DT)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 10 * DT)
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C2)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcVar, NPC_TubbasHeart, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_arn_13_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, arn_11_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_o37)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_13"), arn_13_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_13_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar2, MODEL_o37)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
        EVT_WAIT(10)
        EVT_EXEC(N(EVS_SetupCamera))
        EVT_EXEC(N(EVS_Scene_MeetHeart))
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_WINDY_MILL)
    EVT_CALL(SetSpriteShading, SHADING_ARN_11)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
