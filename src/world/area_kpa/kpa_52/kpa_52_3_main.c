
#include "kpa_52.h"

EvtScript N(EVS_ExitDoors_kpa_33_2) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_0, "kpa_33", kpa_33_ENTRY_2, COLLIDER_ttw, MODEL_o407, MODEL_o408);
EvtScript N(EVS_ExitDoors_kpa_40_0) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_1, "kpa_40", kpa_40_ENTRY_0, COLLIDER_tte1, MODEL_o410, MODEL_o409);
EvtScript N(EVS_ExitDoors_kpa_08_0) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_2, "kpa_08", kpa_08_ENTRY_0, COLLIDER_tte2, MODEL_o412, MODEL_o411);

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_33_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_52_ENTRY_0)
            Set(LVar0, kpa_52_ENTRY_0)
            Set(LVar2, MODEL_o407)
            Set(LVar3, MODEL_o408)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_52_ENTRY_1)
            Set(LVar0, 1)
            Set(LVar2, MODEL_o410)
            Set(LVar3, MODEL_o409)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_52_ENTRY_2)
            Set(LVar0, 2)
            Set(LVar2, MODEL_o412)
            Set(LVar3, MODEL_o411)
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
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
