#include "kkj_16.h"

#include "../common/RestoreFromPeachState.inc.c"
#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_EndPeachChapter2) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("sbk_02"), sbk_02_ENTRY_5, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoor_kkj_11_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kkj_16_ENTRY_0)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o43)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_16_ENTRY_0)
            Set(LVar2, MODEL_o43)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
    EndSwitch
    IfEq(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        Exec(N(EVS_ManageSneakingScenes))
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH2_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH4_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH5_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(EarlyNPCs)))
        EndCaseGroup
        CaseEq(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(N(SetAvailableDisguise), PEACH_DISGUISE_HAMMER_BROS)
            Call(MakeNpcs, FALSE, Ref(N(LaterNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_11_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
