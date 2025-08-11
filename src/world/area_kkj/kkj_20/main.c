#include "kkj_20.h"

EvtScript N(EVS_ExitDoor_kkj_10_4) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, kkj_20_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o9)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_10"), kkj_10_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, kkj_20_ENTRY_0)
    Set(LVar2, MODEL_o9)
    Set(LVar3, DOOR_SWING_IN)
    ExecWait(EnterSingleDoor)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_20)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_10_4)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
