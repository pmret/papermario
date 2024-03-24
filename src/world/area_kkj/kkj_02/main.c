#include "kkj_02.h"

EvtScript N(EVS_ExitDoors_kkj_01_1) = EVT_EXIT_DOUBLE_DOOR(kkj_02_ENTRY_0, "kkj_01", kkj_01_ENTRY_1,
    COLLIDER_deilit1, MODEL_door1, MODEL_door2);
EvtScript N(EVS_ExitDoors_kkj_03_0) = EVT_EXIT_DOUBLE_DOOR(kkj_02_ENTRY_1, "kkj_03", kkj_03_ENTRY_0,
    COLLIDER_deilit2, MODEL_door4, MODEL_door3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_02_ENTRY_0)
            Set(LVar2, MODEL_door1)
            Set(LVar3, MODEL_door2)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_02_ENTRY_1)
            Set(LVar2, MODEL_door4)
            Set(LVar3, MODEL_door3)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
