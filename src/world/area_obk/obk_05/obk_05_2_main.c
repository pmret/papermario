#include "obk_05.h"

EvtScript N(EVS_EnterDoor_obk_05_0) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(obk_05_ENTRY_0)
            Set(LVar2, MODEL_door1)
            Set(LVar4, MODEL_door1b)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSplitSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_01_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, obk_05_ENTRY_0)
    Set(LVar1, COLLIDER_tt1)
    Set(LVar2, MODEL_door1)
    Set(LVar4, MODEL_door1b)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSplitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_01"), obk_01_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TexPan_Fog) = {
    Call(SetTexPanner, MODEL_m1, 0)
    Call(SetTexPanner, MODEL_m2, 0)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Add(LVar0, 300)
        Add(LVar1, 100)
        Call(SetTexPanOffset, 0, 0, LVar0, LVar1)
        Wait(1)
    EndLoop
    Return
    End
};

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

API_CALLABLE(N(RetroJar_AwaitPlayerEntry)) {
    if (gCollisionStatus.curFloor == COLLIDER_o420) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_ManageRetroJar) = {
    Loop(0)
        Call(N(RetroJar_AwaitPlayerEntry))
        Call(DisablePlayerInput, TRUE)
        Wait(1)
        IfEq(MF_IsRetroMario, FALSE)
            Call(PlaySoundAtPlayer, SOUND_JUMP_8BIT_MARIO, SOUND_SPACE_DEFAULT)
            Call(Disable8bitMario, FALSE)
            Call(SetMusicTrack, 0, SONG_CHAPTER_START, 1, 8)
            Set(MF_IsRetroMario, TRUE)
        Else
            Call(PlaySoundAtPlayer, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
            Call(Disable8bitMario, TRUE)
            Exec(N(EVS_SetupMusic))
            Set(MF_IsRetroMario, FALSE)
        EndIf
        Call(N(DisableCameraFollowPlayerY))
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump, -105, 30, -55, 30)
        Wait(1)
        Call(N(EnableCameraFollowPlayerY))
        Call(DisablePlayerInput, FALSE)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupRockingChairs))
    Exec(N(EVS_ManageHole))
    Exec(N(EVS_TexPan_Fog))
    BindTrigger(Ref(N(EVS_ExitDoor_obk_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    Exec(N(EVS_EnterDoor_obk_05_0))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hip1, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_ManageRetroJar))
    Return
    End
};
