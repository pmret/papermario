#include "kpa_17.h"

EvtScript N(EVS_ExitWalk_kpa_1X_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_17_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kpa_11"), kpa_11_ENTRY_2)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kpa_10"), kpa_10_ENTRY_2)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_1X_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kpa_17_ENTRY_0)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_EXEC(N(EVS_Scene_FallIntoCell))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 1186.0f, 30.0f, -562.0f },
    .radius = 0.0f
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_SET(AB_KPA17_Toad1_Dialogue, 0)
    EVT_SET(AB_KPA17_Toad2_Dialogue, 0)
    EVT_SET(AB_KPA17_Toad3_Dialogue, 0)
    EVT_SET(AB_KPA17_Toad4_Dialogue, 0)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KPA17_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
