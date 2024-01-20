#include "kpa_102.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_41_2) = EVT_EXIT_WALK(40, kpa_102_ENTRY_0, "kpa_41", kpa_41_ENTRY_2);
EvtScript N(EVS_ExitDoors_kpa_53_0) = EVT_EXIT_DOUBLE_DOOR(kpa_102_ENTRY_1, "kpa_53", kpa_53_ENTRY_0, COLLIDER_tte, MODEL_o631, MODEL_o632);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_41_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_53_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_102_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(kpa_102_ENTRY_1)
            Set(LVar0, kpa_102_ENTRY_1)
            Set(LVar2, MODEL_o631)
            Set(LVar3, MODEL_o632)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    Call(EnableTexPanning, MODEL_o655, TRUE)
    Call(EnableTexPanning, MODEL_o657, TRUE)
    Call(EnableTexPanning, MODEL_o663, TRUE)
    Call(EnableTexPanning, MODEL_o661, TRUE)
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
            Call(ScaleModel, MODEL_o655, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o657, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o663, Float(1.0), 1, Float(1.0))
            Call(ScaleModel, MODEL_o661, Float(1.0), 1, Float(1.0))
            Wait(10)
            Call(ScaleModel, MODEL_o655, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o657, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o663, Float(0.98), 1, Float(0.98))
            Call(ScaleModel, MODEL_o661, Float(0.98), 1, Float(0.98))
            Wait(10)
            Call(ScaleModel, MODEL_o655, Float(0.961), 1, Float(0.961))
            Call(ScaleModel, MODEL_o657, Float(0.961), 1, Float(0.961))
            Call(ScaleModel, MODEL_o663, Float(0.961), 1, Float(0.961))
            Call(ScaleModel, MODEL_o661, Float(0.961), 1, Float(0.961))
            Wait(10)
        EndLoop
    EndThread
    Return
    End
};
