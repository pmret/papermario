#include "kpa_134.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_133_1) = EVT_EXIT_WALK(40, kpa_134_ENTRY_0, "kpa_133", kpa_133_ENTRY_1);
EvtScript N(EVS_ExitDoors_kpa_130_0) = EVT_EXIT_DOUBLE_DOOR(kpa_134_ENTRY_1, "kpa_130", kpa_130_ENTRY_0, COLLIDER_nno, MODEL_o408, MODEL_o409);
EvtScript N(EVS_ExitWalk_kpa_133_2) = EVT_EXIT_WALK(40, kpa_134_ENTRY_2, "kpa_133", kpa_133_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_133_3) = EVT_EXIT_WALK(40, kpa_134_ENTRY_3, "kpa_133", kpa_133_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_133_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_exitw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_133_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilite, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_133_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_g98, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_134_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_134_ENTRY_1)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar2, MODEL_o408)
            EVT_SET(LVar3, MODEL_o409)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_134_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_134_ENTRY_3)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupChains))
    EVT_IF_EQ(GF_KPA134_BlueSwitch, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_FlipWallPanels)), TRIGGER_AREA_FLAG_SET, AF_KPA134_HitWaterSwitch, 1, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o383, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o384, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sikake, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o384, FALSE)
        EVT_CALL(EnableModel, MODEL_o383, FALSE)
        EVT_CALL(EnableModel, MODEL_o378, FALSE)
        EVT_CALL(EnableModel, MODEL_o379, FALSE)
        EVT_CALL(EnableModel, MODEL_o380, FALSE)
        EVT_CALL(EnableModel, MODEL_o381, FALSE)
        EVT_CALL(EnableModel, MODEL_o382, FALSE)
        EVT_CALL(EnableModel, MODEL_o377, FALSE)
        EVT_CALL(EnableModel, MODEL_o376, FALSE)
        EVT_CALL(EnableModel, MODEL_o375, FALSE)
        EVT_CALL(EnableModel, MODEL_o374, FALSE)
        EVT_CALL(EnableModel, MODEL_o373, FALSE)
        EVT_CALL(EnableModel, MODEL_o372, FALSE)
        EVT_CALL(EnableModel, MODEL_o371, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_KPA133_Item_BombedWall, TRUE)
        EVT_CALL(EnableModel, MODEL_o503, FALSE)
        EVT_CALL(EnableModel, MODEL_o502, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o358, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o400, FALSE)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, MODEL_move, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_s_sui, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o385, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -100,  100,   70,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  200, -100,   20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
