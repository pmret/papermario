#include "jan_04.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_kmr_24_0) = {
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_24"), kmr_24_ENTRY_0, TRANSITION_MARIO_WHITE)
    EVT_WAIT(100)
}; //@bug script not terminated

EvtScript N(EVS_ExitWalk_jan_05_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, jan_04_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("jan_05"), jan_05_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_05_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(jan_04_ENTRY_0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_RANGE(jan_04_ENTRY_1, jan_04_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_TreasureChest))
        EVT_CASE_EQ(jan_04_ENTRY_3)
            EVT_EXEC(N(EVS_Scene_Epilogue))
        EVT_CASE_EQ(jan_04_ENTRY_4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(jan_04_ENTRY_0)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_EQ(jan_04_ENTRY_3)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_EXEC(N(EVS_SetupUnused))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o52, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o53, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o54, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o52, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o53, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o54, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1, SURFACE_TYPE_WATER)
    EVT_CALL(MakeTransformGroup, MODEL_g12)
    EVT_CALL(EnableTexPanning, MODEL_o61, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
