#include "kkj_24.h"

API_CALLABLE(N(func_80240000_B06570)) {
    enable_world_fog();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_kkj_23_1) = EVT_EXIT_DOUBLE_DOOR(kkj_24_ENTRY_0, "kkj_23", kkj_23_ENTRY_1, COLLIDER_tte, MODEL_o58, MODEL_o57);
EvtScript N(EVS_ExitDoors_kkj_25_0) = EVT_EXIT_DOUBLE_DOOR(kkj_24_ENTRY_1, "kkj_25", kkj_25_ENTRY_0, COLLIDER_tte2, MODEL_o78, MODEL_o77);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_23_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_25_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_24_ENTRY_0)
            Set(LVar2, MODEL_o58)
            Set(LVar3, MODEL_o57)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_24_ENTRY_1)
            Set(LVar2, MODEL_o78)
            Set(LVar3, MODEL_o77)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_24)
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Call(N(func_80240000_B06570))
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
