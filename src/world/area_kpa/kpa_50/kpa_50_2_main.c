#include "kpa_50.h"

EvtScript N(EVS_ExitWalk_kpa_70_1) = EVT_EXIT_WALK(60, kpa_50_ENTRY_0, "kpa_70", kpa_70_ENTRY_1);
EvtScript N(EVS_ExitDoors_kpa_81_0) = EVT_EXIT_DOUBLE_DOOR(kpa_50_ENTRY_1, "kpa_81", kpa_81_ENTRY_0, COLLIDER_tte, MODEL_o324, MODEL_o322);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_70_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_81_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_50_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(kpa_50_ENTRY_1)
            EVT_SET(LVar0, kpa_50_ENTRY_1)
            EVT_SET(LVar2, MODEL_o324)
            EVT_SET(LVar3, MODEL_o322)
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
    EVT_CALL(SetGroupVisibility, MODEL_dw1, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_dw2, MODEL_GROUP_HIDDEN)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
