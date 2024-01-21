#include "omo_03.h"

EvtScript N(EVS_ExitWalk_omo_13_1) = EVT_EXIT_WALK(60, omo_03_ENTRY_0, "omo_13", omo_13_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_04_0) = EVT_EXIT_WALK(60, omo_03_ENTRY_1, "omo_04", omo_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(AF_OMO_04, FALSE)
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(omo_03_ENTRY_0, omo_03_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(omo_03_ENTRY_4)
            Set(AF_OMO_04, TRUE)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_Scene_EnterSpring))
        CaseEq(omo_03_ENTRY_5)
            Exec(N(EVS_Scene_Epilogue))
        CaseEq(omo_03_ENTRY_6)
            Exec(N(EVS_Scene_TrainDropped))
        CaseDefault
            Exec(N(EVS_BindExitTriggers))
            Wait(3)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    IfLt(GB_StoryProgress, STORY_CH4_ENTERED_THE_TOY_BOX)
        Set(GB_StoryProgress, STORY_CH4_ENTERED_THE_TOY_BOX)
    EndIf
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Switch(LVar0)
        IfGe(LVar0, LANGUAGE_FR) // or LANGUAGE_ES
            Sub(LVar0, LANGUAGE_FR - LANGUAGE_EN)
        EndIf
        Call(SetModelTexVariant, MODEL_s, LVar0)
        Call(SetModelTexVariant, MODEL_a, LVar0)
        Call(SetModelTexVariant, MODEL_t, LVar0)
        Call(SetModelTexVariant, MODEL_i, LVar0)
        Call(SetModelTexVariant, MODEL_o, LVar0)
        Call(SetModelTexVariant, MODEL_n, LVar0)
#endif
    Set(AF_OMO_05, FALSE)
    Set(GF_MAP_ShyGuysToybox, TRUE)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, omo_03_ENTRY_5)
        Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Else
        Call(MakeNpcs, TRUE, Ref(N(EpilogueNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_8024746C))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
