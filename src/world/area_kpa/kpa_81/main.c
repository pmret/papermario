#include "kpa_81.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_80_shape");
    sprintf(wMapHitName, "kpa_80_hit");
    return false;
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

EvtScript N(EVS_ExitDoors_kpa_50_1) = EVT_EXIT_DOUBLE_DOOR(kpa_81_ENTRY_0, "kpa_50", kpa_50_ENTRY_1, COLLIDER_deilittw, MODEL_o174, MODEL_o173);

EvtScript N(EVS_ExitDoors_kpa_32_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, kpa_81_ENTRY_2)
    Set(LVar1, COLLIDER_o166)
    Set(LVar2, Ref(N(RightDoorModels)))
    Set(LVar3, Ref(N(LeftDoorModels)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_32"), kpa_32_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_04_1) = EVT_EXIT_WALK(60, kpa_81_ENTRY_3, "kpa_04", kpa_04_ENTRY_1);

// required to match -- needs to be forward-declared here
const char N(KPA_17)[] = "kpa_17";

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_50_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    IfNe(GB_KPA81_BowserDoorState, 0)
        BindTrigger(Ref(N(EVS_ExitDoors_kpa_32_0)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_81_ENTRY_0)
            Set(LVar0, kpa_81_ENTRY_0)
            Set(LVar2, MODEL_o174)
            Set(LVar3, MODEL_o173)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_81_ENTRY_2)
            Set(LVar0, kpa_81_ENTRY_2)
            Set(LVar2, Ref(N(LeftDoorModels)))
            Set(LVar3, Ref(N(RightDoorModels)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_81_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UnusedMoveStatue) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 0)
        Return
    EndIf
    Call(ParentColliderToModel, COLLIDER_o146, MODEL_o145)
    Call(MakeLerp, 0, -40, 40, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o145, LVar0, 0, 0)
        Call(TranslateModel, MODEL_o146, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o146)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    IfNe(GB_KPA81_BowserDoorState, 0)
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(kpa_81_ENTRY_0)
                BindTrigger(Ref(N(EVS_UnusedMoveStatue)), TRIGGER_WALL_PRESS_A, COLLIDER_o146, 1, 0)
            CaseEq(kpa_81_ENTRY_2)
                BindTrigger(Ref(N(EVS_UnusedMoveStatue)), TRIGGER_WALL_PRESS_A, COLLIDER_o146, 1, 0)
            CaseEq(kpa_81_ENTRY_3)
        EndSwitch
    EndIf
    Call(ParentColliderToModel, COLLIDER_o146, MODEL_o145)
    Switch(GB_KPA04_StatuePosition)
        CaseEq(1)
            Call(TranslateModel, MODEL_o145, -50, 0, 0)
            Call(TranslateModel, MODEL_o146, -50, 0, 0)
        CaseEq(2)
            Call(TranslateModel, MODEL_o145, 50, 0, 0)
            Call(TranslateModel, MODEL_o146, 50, 0, 0)
    EndSwitch
    Call(UpdateColliderTransform, COLLIDER_o146)
    Call(EnableModel, MODEL_o166, false)
    Call(EnableModel, MODEL_m_, false)
    Call(EnableModel, MODEL_m_kai, false)
    Call(EnableModel, MODEL_m1, false)
    Call(EnableModel, MODEL_m2, false)
    Call(EnableModel, MODEL_m3, false)
    Call(EnableModel, MODEL_m4, false)
    Call(EnableModel, MODEL_m5, false)
    Call(EnableModel, MODEL_m6, false)
    Call(EnableModel, MODEL_m7, false)
    Call(EnableModel, MODEL_b_, false)
    Call(EnableModel, MODEL_b_kai, false)
    Call(EnableModel, MODEL_b1, false)
    Call(EnableModel, MODEL_b2, false)
    Call(EnableModel, MODEL_b3, false)
    Call(EnableModel, MODEL_b4, false)
    Call(EnableModel, MODEL_b5, false)
    Call(EnableModel, MODEL_b6, false)
    Call(EnableModel, MODEL_b7, false)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
