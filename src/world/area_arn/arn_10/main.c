#include "arn_10.h"

EvtScript N(EVS_ExitDoor_arn_09_0) = EVT_EXIT_SINGLE_DOOR(arn_10_ENTRY_0, "arn_09", arn_09_ENTRY_0,
    COLLIDER_ttw, MODEL_o44, DOOR_SWING_IN);

EvtScript N(EVS_ExitDoor_arn_12_0) = EVT_EXIT_SINGLE_DOOR(arn_10_ENTRY_1, "arn_12", arn_12_ENTRY_0,
    COLLIDER_tte, MODEL_o37, DOOR_SWING_OUT);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_arn_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_arn_12_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(arn_10_ENTRY_0)
            Set(LVar2, MODEL_o44)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(arn_10_ENTRY_1)
            Set(LVar2, MODEL_o37)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_WINDY_MILL)
    Call(SetSpriteShading, SHADING_ARN_10)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
