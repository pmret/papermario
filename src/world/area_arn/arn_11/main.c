#include "arn_11.h"
#include "sprite/player.h"

EvtScript N(EVS_SetupCamera) = {
    Call(SetCamType, CAM_DEFAULT, 6, TRUE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(UseSettingsFrom, CAM_DEFAULT, 60, 30, 0)
    Call(SetPanTarget, CAM_DEFAULT, 60, 30, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-13.0))
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Scene_MeetHeart) = {
    Call(DisablePlayerInput, TRUE)
    Wait(30 * DT)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 6, 0, 0)
    Call(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00BF)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    Thread
        Call(SetNpcJumpscale, NPC_TubbasHeart, Float(2.5))
        Call(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 10 * DT)
        Wait(1)
        Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 10 * DT)
    EndThread
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01, 0, MSG_CH3_00C2)
    Call(SetPlayerAnimation, ANIM_MarioW3_ShakeHead)
    Wait(10 * DT)
    Call(SetNpcVar, NPC_TubbasHeart, 0, 1)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ExitDoor_arn_13_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, arn_11_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o37)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("arn_13"), arn_13_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_arn_13_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(DisablePlayerInput, TRUE)
    Set(LVar2, MODEL_o37)
    Set(LVar3, DOOR_SWING_IN)
    ExecWait(EnterSingleDoor)
    Exec(N(EVS_BindExitTriggers))
    IfLt(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
        Wait(10)
        Exec(N(EVS_SetupCamera))
        Exec(N(EVS_Scene_MeetHeart))
        Wait(1)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_WINDY_MILL)
    Call(SetSpriteShading, SHADING_ARN_11)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
