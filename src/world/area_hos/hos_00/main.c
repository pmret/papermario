#include "hos_00.h"

#include "../common/FallingStars.inc.c"

EvtScript N(EVS_ExitWalk_osr) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, hos_00_ENTRY_0)
    Exec(ExitWalk)
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH0_WAKE_UP, STORY_CH8_REACHED_PEACHS_CASTLE)
            Call(GotoMap, Ref("osr_01"), osr_01_ENTRY_1)
        CaseDefault
            Call(GotoMap, Ref("osr_00"), osr_00_ENTRY_1)
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_hos_01_0) = EVT_EXIT_WALK(60, hos_00_ENTRY_1, "hos_01", hos_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_hos_06_0) = EVT_EXIT_WALK(60, hos_00_ENTRY_2, "hos_06", hos_06_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_osr)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_hos_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_hos_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_Unknown) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Set(LVar0, 0)
    Loop(0)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
        Add(LVar0, 0x4000)
        Wait(15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(N(EVS_SetupBackgroundShade))
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_00_ENTRY_3)
        Call(SetGroupVisibility, MODEL_g107, MODEL_GROUP_HIDDEN)
        Exec(N(EVS_Scene_Wishing))
        Return
    Else
        Exec(N(EVS_SetupBackgroundShade))
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Set(GF_MAP_ShootingStarSummit, true)
    Set(GF_MAC01_RowfBadgesChosen, false)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_00_ENTRY_3)
        Call(MakeNpcs, false, Ref(N(WishingNPCs)))
    Else
        Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Call(GetEntryID, LVar0)
    IfNe(LVar0, hos_00_ENTRY_3)
        Exec(N(EVS_Starfall_Directed))
    EndIf
    ExecWait(N(EVS_SetupMusic))
    IfEq(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
        IfEq(AF_HOS_B4, false)
            Wait(50)
            Set(AF_HOS_B4, true)
        EndIf
        Exec(N(EVS_Scene_MeetingTwink))
    EndIf
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_TexPan_Unknown))
    Return
    End
};
