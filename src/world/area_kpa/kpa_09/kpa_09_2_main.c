#include "kpa_09.h"

EvtScript N(EVS_ExitWalk_kpa_101_0) = EVT_EXIT_WALK(60, kpa_09_ENTRY_0, "kpa_101", kpa_101_ENTRY_0);
EvtScript N(EVS_ExitDoors_kpa_33_3) = EVT_EXIT_DOUBLE_DOOR(kpa_09_ENTRY_1, "kpa_33", kpa_33_ENTRY_3, COLLIDER_tte, MODEL_o159, MODEL_o160);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_101_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_33_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_09_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(kpa_09_ENTRY_1)
            Set(LVar0, 1)
            Set(LVar2, MODEL_o159)
            Set(LVar3, MODEL_o160)
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
    ExecWait(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o180, FALSE)
    Call(EnableModel, MODEL_o181, FALSE)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
