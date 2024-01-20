#include "kkj_22.h"

EvtScript N(EVS_ExitDoor_kkj_13_1) = EVT_EXIT_DOUBLE_DOOR(kkj_22_ENTRY_0, "kkj_13", kkj_13_ENTRY_1, COLLIDER_ttw, MODEL_o51, MODEL_o52);
EvtScript N(EVS_ExitDoor_kkj_23_0) = EVT_EXIT_DOUBLE_DOOR(kkj_22_ENTRY_1, "kkj_23", kkj_23_ENTRY_0, COLLIDER_ttnw, MODEL_o94, MODEL_o95);

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_22_ENTRY_0)
            Set(LVar2, MODEL_o51)
            Set(LVar3, MODEL_o52)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_22_ENTRY_1)
            Set(LVar2, MODEL_o94)
            Set(LVar3, MODEL_o95)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_22)
    SetUP_CAMERA_DEFAULT()
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_13_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_23_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttnw, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
