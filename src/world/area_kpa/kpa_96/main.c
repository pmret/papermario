#include "kpa_96.h"

EvtScript N(EVS_ExitDoors_kpa_32_3) = EVT_EXIT_DOUBLE_DOOR(kpa_96_ENTRY_0, "kpa_32", kpa_32_ENTRY_3, COLLIDER_deilittw, MODEL_o881, MODEL_o882);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_32_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, kpa_96_ENTRY_0)
    Set(LVar2, MODEL_o881)
    Set(LVar3, MODEL_o882)
    Exec(EnterDoubleDoor)
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupShop))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
