#include "dgb_18.h"

EvtScript N(EVS_ExitDoors_dgb_01_6) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_18_ENTRY_0)
    Set(LVar1, COLLIDER_deilittw)
    Set(LVar2, MODEL_o140)
    Set(LVar3, MODEL_o141)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_6)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_18_ENTRY_0)
            Set(LVar2, MODEL_o140)
            Set(LVar3, MODEL_o141)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_ExitDoors_dgb_01_6)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
