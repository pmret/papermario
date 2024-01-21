#include "kpa_08.h"

EvtScript N(EVS_ExitDoors_kpa_52_2) = EVT_EXIT_DOUBLE_DOOR(kpa_08_ENTRY_0, "kpa_52", kpa_52_ENTRY_2, COLLIDER_ttw, MODEL_o160, MODEL_o159);
EvtScript N(EVS_ExitWalk_kpa_100_0) = EVT_EXIT_WALK(40, kpa_08_ENTRY_1, "kpa_100", kpa_100_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_52_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_100_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_08_ENTRY_0)
            Set(LVar0, kpa_08_ENTRY_0)
            Set(LVar2, MODEL_o160)
            Set(LVar3, MODEL_o159)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_08_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
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
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
