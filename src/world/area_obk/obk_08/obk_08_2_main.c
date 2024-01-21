#include "obk_08.h"

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Set(LVar2, MODEL_door1)
    Set(LVar4, MODEL_door1b)
    Set(LVar3, DOOR_SWING_OUT)
    ExecWait(EnterSplitSingleDoor)
    Return
    End
};

EvtScript N(EVS_ExitMap_obk_01_4) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, obk_08_ENTRY_0)
    Set(LVar1, COLLIDER_tt1)
    Set(LVar2, MODEL_door1)
    Set(LVar4, MODEL_door1b)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSplitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_01"), obk_01_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TexPan_Fog) = {
    Call(SetTexPanner, MODEL_moku1, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_moku2, TEX_PANNER_0)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Add(LVar0, 300)
        Add(LVar1, 100)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Set(AF_OBK08_KeepAwayStarted, FALSE)
    Exec(N(EVS_SetupCabinets))
    Exec(N(EVS_ManageWindows))
    Exec(N(EVS_TexPan_Fog))
    BindTrigger(Ref(N(EVS_ExitMap_obk_01_4)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
