#include "dgb_12.h"

EvtScript N(EVS_ExitDoor_dgb_09_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_12_ENTRY_0)
    Set(LVar1, COLLIDER_deilits)
    Set(LVar2, MODEL_o158)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_09"), dgb_09_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_12_ENTRY_0)
            Set(LVar2, MODEL_o158)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupSpikes))
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_ExitDoor_dgb_09_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilits, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
