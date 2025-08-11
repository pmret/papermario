#include "pra_05.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_38_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_05_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    Set(LVar2, MODEL_o772)
    Set(LVar3, MODEL_o768)
    Set(LVar4, MODEL_o844)
    Set(LVar5, MODEL_o846)
    Exec(ExitSplitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_38"), pra_38_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_38_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, pra_05_ENTRY_0)
    Set(LVar2, MODEL_o772)
    Set(LVar3, MODEL_o768)
    Set(LVar4, MODEL_o844)
    Set(LVar5, MODEL_o846)
    ExecWait(EnterSplitDoubleDoor)
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(SetCamEnabled, CAM_DEFAULT, true)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Set(LVar0, REFLECTION_FLOOR_ONLY)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
