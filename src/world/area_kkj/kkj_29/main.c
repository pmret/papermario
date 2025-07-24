#include "kkj_29.h"

#include "../common/RestoreFromPeachState.inc.c"

EvtScript N(EVS_EndPeachChapter5) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("jan_22"), jan_22_ENTRY_3, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoor_kkj_10_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, kkj_29_ENTRY_0)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o57)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_10"), kkj_10_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    IfEq(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        Exec(N(EVS_ManageQuizGame))
    Else
        Set(LVar0, kkj_29_ENTRY_0)
        Set(LVar2, MODEL_o57)
        Set(LVar3, DOOR_SWING_IN)
        ExecWait(EnterSingleDoor)
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    IfEq(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    EndIf
    Exec(N(EVS_ManageStageEffects))
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(FadeOutMusic, 0, 500)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_10_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
