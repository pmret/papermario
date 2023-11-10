#include "mac_00.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(DummyColliderFunction)) {
    Bytecode* args = script->ptrReadPos;
    f32 x, y, z;

    get_collider_center(evt_get_variable(script, *args++), &x, &y, &z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DummyInitFunction)) {
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_kmr_10_1) = EVT_EXIT_WALK(60, mac_00_ENTRY_0, "kmr_10", kmr_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_mac_01_0) = EVT_EXIT_WALK(60, mac_00_ENTRY_1, "mac_01", mac_01_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_19_9) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_19"), tik_19_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_kmr_20_4) = {
    EVT_CALL(GotoMap, EVT_PTR("kmr_20"), kmr_20_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_19_9) = EVT_EXIT_PIPE_VERTICAL(mac_00_ENTRY_3, COLLIDER_deilit, N(EVS_GotoMap_tik_19_9));
EvtScript N(EVS_ExitPipe_kmr_20_4) = EVT_EXIT_PIPE_VERTICAL(mac_00_ENTRY_4, COLLIDER_deilim, N(EVS_GotoMap_kmr_20_4));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_kmr_20_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilim, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_RETURN
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_10_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_19_9)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilit, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(mac_00_ENTRY_3)
        EVT_CASE_OR_EQ(mac_00_ENTRY_4)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(mac_00_ENTRY_5)
            EVT_EXEC(N(EVS_Scene_Intro))
        EVT_CASE_EQ(mac_00_ENTRY_7)
            EVT_EXEC_WAIT(N(EVS_Scene_BeginEpilogue))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_mushroom_kingdom, LVar0)
#endif
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_SET(GF_MAP_ToadTown, TRUE)
    EVT_END_IF
    EVT_CALL(SetRenderMode, MODEL_minka1_yuka, RENDER_MODE_SURFACE_XLU_ZB_ZUPD)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupShop))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_water, SURFACE_TYPE_WATER)
    EVT_EXEC(N(EVS_SetupWaterCustomGfx))
    EVT_CALL(EnableTexPanning, MODEL_water, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,    0,    0,  120)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_op_1, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_op2, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_op3, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_op_1, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_op2, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_op3, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(N(DummyColliderFunction), COLLIDER_op_1)
    EVT_CALL(N(DummyColliderFunction), COLLIDER_op2)
    EVT_CALL(N(DummyColliderFunction), COLLIDER_op3)
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_EXEC_WAIT(N(EVS_SetupDemo))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_SET(GB_StoryProgress, STORY_CH0_ARRIVED_AT_TOAD_TOWN)
        EVT_EXEC(N(EVS_Scene_ToadTownGreeting))
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_CALL(N(DummyInitFunction))
    EVT_RETURN
    EVT_END
};
