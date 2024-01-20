#include "kpa_130.h"

EvtScript N(EVS_ExitDoors_kpa_134_1) = EVT_EXIT_DOUBLE_DOOR(kpa_130_ENTRY_0, "kpa_134", kpa_134_ENTRY_1, COLLIDER_ttw, MODEL_o11, MODEL_o9);
EvtScript N(EVS_ExitDoors_kpa_111_0) = EVT_EXIT_DOUBLE_DOOR(kpa_130_ENTRY_1, "kpa_111", kpa_111_ENTRY_0, COLLIDER_tte, MODEL_o455, MODEL_o454);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_134_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_111_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_130_ENTRY_0)
            Set(LVar0, kpa_130_ENTRY_0)
            Set(LVar2, MODEL_o11)
            Set(LVar3, MODEL_o9)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_130_ENTRY_1)
            Set(LVar0, 1)
            Set(LVar2, MODEL_o455)
            Set(LVar3, MODEL_o454)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
