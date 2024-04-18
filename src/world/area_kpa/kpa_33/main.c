
#include "kpa_33.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_94_1) = EVT_EXIT_WALK(60, kpa_33_ENTRY_0, "kpa_94", kpa_94_ENTRY_1);
EvtScript N(EVS_ExitDoors_kpa_61_1) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_1, "kpa_61", kpa_61_ENTRY_1, COLLIDER_tt3, MODEL_o1250, MODEL_b3_doa);
EvtScript N(EVS_ExitDoors_kpa_52_0) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_2, "kpa_52", kpa_52_ENTRY_0, COLLIDER_tte, MODEL_o1252, MODEL_o1253);
EvtScript N(EVS_ExitDoors_kpa_09_1) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_3, "kpa_09", kpa_09_ENTRY_1, COLLIDER_tt4, MODEL_o1258, MODEL_o1259);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_94_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_61_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_52_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_33_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_33_ENTRY_1)
            Set(LVar0, kpa_33_ENTRY_1)
            Set(LVar2, MODEL_o1250)
            Set(LVar3, MODEL_b3_doa)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_33_ENTRY_2)
            Set(LVar0, kpa_33_ENTRY_2)
            Set(LVar2, MODEL_o1252)
            Set(LVar3, MODEL_o1253)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_33_ENTRY_3)
            Set(LVar0, kpa_33_ENTRY_3)
            Set(LVar2, MODEL_o1258)
            Set(LVar3, MODEL_o1259)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Call(EnableTexPanning, MODEL_o1286, TRUE)
    Call(EnableTexPanning, MODEL_o1287, TRUE)
    Call(EnableTexPanning, MODEL_o1289, TRUE)
    Call(EnableTexPanning, MODEL_o1290, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        Loop(0)
            Call(ScaleModel, MODEL_o1286, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1287, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1289, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1290, Float(1.02), 1, Float(1.02))
            Wait(10)
            Call(ScaleModel, MODEL_o1286, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1287, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1289, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1290, Float(1.0), 1, Float(1.0))
            Wait(10)
            Call(ScaleModel, MODEL_o1286, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1287, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1289, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1290, Float(0.98), 1, Float(0.98))
            Wait(10)
        EndLoop
    EndThread
    Return
    End
};
