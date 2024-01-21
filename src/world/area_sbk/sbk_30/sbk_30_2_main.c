#include "sbk_30.h"

#include "world/common/atomic/ApplyTint.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_99_1) = EVT_EXIT_WALK(60, sbk_30_ENTRY_0, "sbk_99", sbk_99_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_31_0) = EVT_EXIT_WALK(60, sbk_30_ENTRY_1, "sbk_31", sbk_31_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_20_3) = EVT_EXIT_WALK(60, sbk_30_ENTRY_2, "sbk_20", sbk_20_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_40_2) = EVT_EXIT_WALK(60, sbk_30_ENTRY_3, "sbk_40", sbk_40_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_99_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_31_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_20_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_40_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(sbk_30_ENTRY_0)
            IfEq(GF_SBK30_Visited, FALSE)
                Set(GF_SBK30_Visited, TRUE)
                Set(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT)
            EndIf
        CaseEq(sbk_30_ENTRY_1)
        CaseEq(sbk_30_ENTRY_2)
        CaseEq(sbk_30_ENTRY_3)
        CaseEq(sbk_30_ENTRY_4)
            Return
    EndSwitch
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Scene_RuinsRising) = {
    Call(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    Call(UseSettingsFrom, CAM_DEFAULT, 193, 0, -237)
    Call(SetPanTarget, CAM_DEFAULT, 193, 0, -237)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(0.25))
    EndThread
    Thread
        Wait(60)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, sbk_30_ENTRY_4)
            Call(GotoMap, Ref("dro_01"), dro_01_ENTRY_3)
        Else
            Call(GotoMap, Ref("dro_01"), dro_01_ENTRY_4)
        EndIf
        Wait(100)
    EndThread
    Return
    End
};

MAP_RODATA_PAD(1, exits); // can be fixed with subalign 16 for this map

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    Call(SetSpriteShading, SHADING_NONE)
    IfEq(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        Call(DisablePulseStone, FALSE)
    EndIf
    SetUP_CAMERA_NO_LEAD()
    IfLt(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        Call(EnableGroup, MODEL_g28, FALSE)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Else
        Call(EnableGroup, MODEL_g23, FALSE)
        Call(EnableGroup, MODEL_sakji_tent, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_Default, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetZoneEnabled, ZONE_o25, FALSE)
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupFoliage))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(sbk_30_ENTRY_4)
        CaseOrEq(sbk_30_ENTRY_5)
            ExecWait(N(EVS_Scene_RuinsRising))
        EndCaseGroup
        CaseDefault
            Call(N(SpawnSunEffect))
    EndSwitch
    Return
    End
};
