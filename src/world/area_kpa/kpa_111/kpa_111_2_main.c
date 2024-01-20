#include "kpa_111.h"

EvtScript N(EVS_ExitDoors_kpa_130_1) = EVT_EXIT_DOUBLE_DOOR(kpa_111_ENTRY_0, "kpa_130", kpa_130_ENTRY_1, COLLIDER_deiliwtt, MODEL_o119, MODEL_o118);
EvtScript N(EVS_ExitDoors_kpa_112_0) = EVT_EXIT_WALK(40, kpa_111_ENTRY_1, "kpa_112", kpa_112_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_130_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwtt, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_112_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_111_ENTRY_0)
            Set(LVar0, kpa_111_ENTRY_0)
            Set(LVar2, MODEL_o119)
            Set(LVar3, MODEL_o118)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_111_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupStatues))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
