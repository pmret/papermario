#include "mim_10.h"

EvtScript N(EVS_ExitWalk_mac_02_1) = EVT_EXIT_WALK(60, mim_10_ENTRY_0, "mac_02", mac_02_ENTRY_1);

EvtScript N(EVS_ExitWalk_mim_01_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, mim_10_ENTRY_1)
    Exec(ExitWalk)
    IfEq(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
        IfEq(GF_StartedChapter3, false)
            Set(GF_StartedChapter3, true)
            Call(FadeOutMusic, 0, 1500)
            Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_3, TRANSITION_BEGIN_OR_END_CHAPTER)
            Wait(100)
            Return
        EndIf
    EndIf
    Call(GotoMap, Ref("mim_01"), mim_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mim_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupBootlerTrigger))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Set(GF_MAC01_RowfBadgesChosen, false)
    Return
    End
};
