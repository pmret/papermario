#include "kpa_83.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_80_shape");
    sprintf(wMapHitName, "kpa_80_hit");
    return FALSE;
}

s32 N(RightDoorModels)[] = {
    MODEL_o140,
    MODEL_o142,
    MODEL_o121,
    MODEL_g35,
    MODEL_o116,
    MODEL_o170,
    -1
};

s32 N(LeftDoorModels)[] = {
    MODEL_o161,
    MODEL_o162,
    MODEL_o119,
    MODEL_g33,
    MODEL_o126,
    MODEL_o171,
    -1
};

EvtScript N(EVS_ExitDoors_kpa_53_1) = EVT_EXIT_DOUBLE_DOOR(kpa_83_ENTRY_0, "kpa_53", kpa_53_ENTRY_1, COLLIDER_deilittw, MODEL_o174, MODEL_o173);

EvtScript N(EVS_ExitDoors_kpa_121_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kpa_83_ENTRY_1)
    Set(LVar1, COLLIDER_o166)
    Set(LVar2, Ref(N(RightDoorModels)))
    Set(LVar3, Ref(N(LeftDoorModels)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_121"), kpa_121_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_53_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_121_0)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_83_ENTRY_0)
            Set(LVar0, kpa_83_ENTRY_0)
            Set(LVar2, MODEL_o174)
            Set(LVar3, MODEL_o173)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_83_ENTRY_1)
            Set(LVar0, kpa_83_ENTRY_1)
            Set(LVar2, Ref(N(LeftDoorModels)))
            Set(LVar3, Ref(N(RightDoorModels)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(EnableModel, MODEL_o166, FALSE)
    Call(EnableModel, MODEL_m_, FALSE)
    Call(EnableModel, MODEL_m_kai, FALSE)
    Call(EnableModel, MODEL_m1, FALSE)
    Call(EnableModel, MODEL_m2, FALSE)
    Call(EnableModel, MODEL_m3, FALSE)
    Call(EnableModel, MODEL_m4, FALSE)
    Call(EnableModel, MODEL_m5, FALSE)
    Call(EnableModel, MODEL_m6, FALSE)
    Call(EnableModel, MODEL_m7, FALSE)
    Call(EnableModel, MODEL_b_, FALSE)
    Call(EnableModel, MODEL_b_kai, FALSE)
    Call(EnableModel, MODEL_b1, FALSE)
    Call(EnableModel, MODEL_b2, FALSE)
    Call(EnableModel, MODEL_b3, FALSE)
    Call(EnableModel, MODEL_b4, FALSE)
    Call(EnableModel, MODEL_b5, FALSE)
    Call(EnableModel, MODEL_b6, FALSE)
    Call(EnableModel, MODEL_b7, FALSE)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
