#include "kpa_102.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_41_2) = EVT_EXIT_WALK(40, kpa_102_ENTRY_0, "kpa_41", kpa_41_ENTRY_2);
EvtScript N(EVS_ExitDoors_kpa_53_0) = EVT_EXIT_DOUBLE_DOOR(kpa_102_ENTRY_1, "kpa_53", kpa_53_ENTRY_0, COLLIDER_tte, MODEL_o631, MODEL_o632);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_41_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_53_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_102_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(kpa_102_ENTRY_1)
            EVT_SET(LVar0, kpa_102_ENTRY_1)
            EVT_SET(LVar2, MODEL_o631)
            EVT_SET(LVar3, MODEL_o632)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnableTexPanning, MODEL_o655, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o657, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o663, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o661, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(   20,   20,  -20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ScaleModel, MODEL_o655, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o657, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o663, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o661, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(ScaleModel, MODEL_o655, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o657, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o663, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o661, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_WAIT(10)
            EVT_CALL(ScaleModel, MODEL_o655, EVT_FLOAT(0.961), 1, EVT_FLOAT(0.961))
            EVT_CALL(ScaleModel, MODEL_o657, EVT_FLOAT(0.961), 1, EVT_FLOAT(0.961))
            EVT_CALL(ScaleModel, MODEL_o663, EVT_FLOAT(0.961), 1, EVT_FLOAT(0.961))
            EVT_CALL(ScaleModel, MODEL_o661, EVT_FLOAT(0.961), 1, EVT_FLOAT(0.961))
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
