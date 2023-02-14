
#include "kpa_33.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_94_1) = EVT_EXIT_WALK(60, kpa_33_ENTRY_0, "kpa_94", kpa_94_ENTRY_1);
EvtScript N(EVS_ExitDoors_kpa_61_1) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_1, "kpa_61", kpa_61_ENTRY_1, COLLIDER_tt3, MODEL_o1250, MODEL_b3_doa);
EvtScript N(EVS_ExitDoors_kpa_52_0) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_2, "kpa_52", kpa_52_ENTRY_0, COLLIDER_tte, MODEL_o1252, MODEL_o1253);
EvtScript N(EVS_ExitDoors_kpa_09_1) = EVT_EXIT_DOUBLE_DOOR(kpa_33_ENTRY_3, "kpa_09", kpa_09_ENTRY_1, COLLIDER_tt4, MODEL_o1258, MODEL_o1259);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_94_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_61_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_52_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_33_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_33_ENTRY_1)
            EVT_SET(LVar0, kpa_33_ENTRY_1)
            EVT_SET(LVar2, MODEL_o1250)
            EVT_SET(LVar3, MODEL_b3_doa)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_33_ENTRY_2)
            EVT_SET(LVar0, kpa_33_ENTRY_2)
            EVT_SET(LVar2, MODEL_o1252)
            EVT_SET(LVar3, MODEL_o1253)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_33_ENTRY_3)
            EVT_SET(LVar0, kpa_33_ENTRY_3)
            EVT_SET(LVar2, MODEL_o1258)
            EVT_SET(LVar3, MODEL_o1259)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnableTexPanning, MODEL_o1286, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o1287, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o1289, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o1290, TRUE)
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
            EVT_CALL(ScaleModel, MODEL_o1286, EVT_FLOAT(1.02), 1, EVT_FLOAT(1.02))
            EVT_CALL(ScaleModel, MODEL_o1287, EVT_FLOAT(1.02), 1, EVT_FLOAT(1.02))
            EVT_CALL(ScaleModel, MODEL_o1289, EVT_FLOAT(1.02), 1, EVT_FLOAT(1.02))
            EVT_CALL(ScaleModel, MODEL_o1290, EVT_FLOAT(1.02), 1, EVT_FLOAT(1.02))
            EVT_WAIT(10)
            EVT_CALL(ScaleModel, MODEL_o1286, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o1287, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o1289, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_o1290, EVT_FLOAT(1.0), 1, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(ScaleModel, MODEL_o1286, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o1287, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o1289, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_CALL(ScaleModel, MODEL_o1290, EVT_FLOAT(0.98), 1, EVT_FLOAT(0.98))
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
