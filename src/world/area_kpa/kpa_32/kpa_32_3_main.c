#include "kpa_32.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitDoors_kpa_81_2) = EVT_EXIT_DOUBLE_DOOR(kpa_32_ENTRY_0, "kpa_81", kpa_81_ENTRY_2, COLLIDER_ttw, MODEL_b4_doa, MODEL_o1256);
EvtScript N(EVS_ExitWalk_kpa_90_0) = EVT_EXIT_WALK(60, kpa_32_ENTRY_1, "kpa_90", kpa_90_ENTRY_0);
EvtScript N(EVS_ExitDoors_kpa_51_0) = EVT_EXIT_DOUBLE_DOOR(kpa_32_ENTRY_2, "kpa_51", kpa_51_ENTRY_0, COLLIDER_tte, MODEL_o1258, MODEL_o1257);
EvtScript N(EVS_ExitDoors_kpa_96_0) = EVT_EXIT_DOUBLE_DOOR(kpa_32_ENTRY_3, "kpa_96", kpa_96_ENTRY_0, COLLIDER_tt4, MODEL_o1248, MODEL_o1254);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_81_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_90_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_51_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_96_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
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
        CaseEq(kpa_32_ENTRY_0)
            Set(LVar0, kpa_32_ENTRY_0)
            Set(LVar2, MODEL_o1256)
            Set(LVar3, MODEL_b4_doa)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_32_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_32_ENTRY_2)
            Set(LVar0, 2)
            Set(LVar2, MODEL_o1258)
            Set(LVar3, MODEL_o1257)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_32_ENTRY_3)
            Set(LVar0, 3)
            Set(LVar2, MODEL_o1248)
            Set(LVar3, MODEL_o1254)
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
    Call(EnableTexPanning, MODEL_o1287, TRUE)
    Call(EnableTexPanning, MODEL_o1289, TRUE)
    Call(EnableTexPanning, MODEL_o1293, TRUE)
    Call(EnableTexPanning, MODEL_o1295, TRUE)
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
            Call(ScaleModel, MODEL_o1287, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1289, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1293, Float(1.02), 1, Float(1.02))
            Call(ScaleModel, MODEL_o1295, Float(1.02), 1, Float(1.02))
            Wait(10)
            Call(ScaleModel, MODEL_o1287, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1289, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1293, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o1295, Float(1.0), 1, Float(1.0))
            Wait(10)
            Call(ScaleModel, MODEL_o1287, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1289, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1293, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o1295, Float(0.98), 1, Float(0.98))
            Wait(10)
        EndLoop
    EndThread
    Return
    End
};
