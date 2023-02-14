#include "kpa_133.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitDoors_kpa_51_1) = EVT_EXIT_DOUBLE_DOOR(kpa_133_ENTRY_0, "kpa_51", kpa_51_ENTRY_1, COLLIDER_ttw, MODEL_o486, MODEL_o485);
EvtScript N(EVS_ExitWalk_kpa_134_0) = EVT_EXIT_WALK(40, kpa_133_ENTRY_1, "kpa_134", kpa_134_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_134_2) = EVT_EXIT_WALK(40, kpa_133_ENTRY_2, "kpa_134", kpa_134_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_134_3) = EVT_EXIT_WALK(40, kpa_133_ENTRY_3, "kpa_134", kpa_134_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_51_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_134_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_134_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_134_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliae, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_133_ENTRY_0)
            EVT_SET(LVar0, kpa_133_ENTRY_0)
            EVT_SET(LVar2, MODEL_o486)
            EVT_SET(LVar3, MODEL_o485)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_133_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_133_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_133_ENTRY_3)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 388.0f, 240.0f, -25.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 56, 56, 1, 10, 30)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(EnableModel, MODEL_o235, TRUE)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_o477, TRUE)
        EVT_CALL(EnableModel, MODEL_o476, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_o477, FALSE)
        EVT_CALL(EnableModel, MODEL_o476, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttae, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_KPA133_Item_BombedWall, TRUE)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KPA133_Item_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_o235, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o477, FALSE)
        EVT_CALL(EnableModel, MODEL_o476, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttae, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetWaterLevel))
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80241A90_AA8F10)), TRIGGER_AREA_FLAG_SET, AF_KPA133_HitWaterSwitch, 1, 0)
    EVT_CALL(EnableTexPanning, MODEL_move, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_s_sui, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_sui, TRUE)
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
