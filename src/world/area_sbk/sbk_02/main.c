#include "sbk_02.h"
#include "effects.h"

EvtScript N(EVS_ExitWalk_sbk_01_1) = EVT_EXIT_WALK(60, sbk_02_ENTRY_0, "sbk_01", sbk_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_03_0) = EVT_EXIT_WALK(60, sbk_02_ENTRY_1, "sbk_03", sbk_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_12_2) = EVT_EXIT_WALK(60, sbk_02_ENTRY_3, "sbk_12", sbk_12_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_01_0) = EVT_EXIT_WALK(60, sbk_02_ENTRY_4, "isk_01", isk_01_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(sbk_02_ENTRY_5)
            Exec(N(EVS_BindExitTriggers))
        CaseOrEq(sbk_02_ENTRY_6)
        CaseOrEq(sbk_02_ENTRY_7)
            Exec(N(EVS_BindExitTriggers))
        EndCaseGroup
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    Call(SetSpriteShading, SHADING_NONE)
    IfEq(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        Call(DisablePulseStone, false)
    EndIf
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    IfLt(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
        PlayEffect(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
        Set(MV_Unk_00, LVarF)
    EndIf
    IfEq(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Else
        Exec(N(EVS_SetupMusic))
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(sbk_02_ENTRY_6)
        CaseOrEq(sbk_02_ENTRY_7)
        EndCaseGroup
        CaseDefault
            ExecWait(N(EVS_SetupRuins))
    EndSwitch
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(sbk_02_ENTRY_5)
            Wait(65)
        CaseOrEq(sbk_02_ENTRY_6)
        CaseOrEq(sbk_02_ENTRY_7)
            Exec(N(EVS_Ruins_Arise_Continued))
            Wait(3)
        EndCaseGroup
        CaseDefault
            Wait(1)
    EndSwitch
    Return
    End
};
