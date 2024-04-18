#include "arn_09.h"

EvtScript N(EVS_ExitDoor_arn_10_0) = EVT_EXIT_SPLIT_SINGLE_DOOR(arn_09_ENTRY_0, "arn_10", arn_10_ENTRY_0,
    COLLIDER_tte, MODEL_doa, MODEL_o37, DOOR_SWING_OUT);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_arn_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(arn_09_ENTRY_0)
            Set(LVar2, MODEL_doa)
            Set(LVar4, MODEL_o37)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSplitSingleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(arn_09_ENTRY_1)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_WINDY_MILL)
    Call(SetSpriteShading, SHADING_ARN_09)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_LaunchPlayer))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
