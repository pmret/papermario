#include "kpa_130.h"

EvtScript N(EVS_ExitDoors_kpa_134_1) = EVT_EXIT_DOUBLE_DOOR(kpa_130_ENTRY_0, "kpa_134", kpa_134_ENTRY_1, COLLIDER_ttw, MODEL_o11, MODEL_o9);
EvtScript N(EVS_ExitDoors_kpa_111_0) = EVT_EXIT_DOUBLE_DOOR(kpa_130_ENTRY_1, "kpa_111", kpa_111_ENTRY_0, COLLIDER_tte, MODEL_o455, MODEL_o454);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_134_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_111_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_130_ENTRY_0)
            EVT_SET(LVar0, kpa_130_ENTRY_0)
            EVT_SET(LVar2, MODEL_o11)
            EVT_SET(LVar3, MODEL_o9)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_130_ENTRY_1)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar2, MODEL_o455)
            EVT_SET(LVar3, MODEL_o454)
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
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
