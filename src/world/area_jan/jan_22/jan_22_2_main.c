#include "jan_22.h"

EvtScript N(EVS_ExitWalk_jan_03_2) = EVT_EXIT_WALK(60, jan_22_ENTRY_0, "jan_03", jan_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_jan_16_1) = EVT_EXIT_WALK(60, jan_22_ENTRY_1, "jan_16", jan_16_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_01_0) = EVT_EXIT_WALK(60, jan_22_ENTRY_2, "kzn_01", kzn_01_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_03_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_16_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LavaFalls) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o262, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o269, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o261, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        EVT_SUB(LVar0, 300)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LavaSpread) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o275, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o274, TEX_PANNER_2)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        EVT_SUB(LVar0, 300)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LavaFlow) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o263, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o271, TEX_PANNER_3)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar0)
        EVT_SUB(LVar0, 170)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_LavaGather) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o267, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_o272, TEX_PANNER_4)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar0)
        EVT_ADD(LVar0, 300)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o170, .pos = {  750.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o70,  .pos = {  750.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o119, .pos = {  960.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o276, .pos = {  960.0,    0.0,   50.0 }},
    { .colliderID = -1 }
};

EvtScript N(D_8024202C_B861AC) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
        EVT_CALL(SetGroupVisibility, MODEL_g39, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g52, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g58, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g39, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g86, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o149, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC_WAIT(N(EVS_SeparateBushesImmediately))
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_THREAD
                EVT_EXEC(N(EVS_Scene_RaphaelComingThrough))
                EVT_WAIT(200)
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_CASE_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(RavenNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupZiplines))
    EVT_EXEC(N(EVS_SetupBasketElevator))
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o294, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_TexPan_LavaFalls))
    EVT_EXEC(N(EVS_TexPan_LavaSpread))
    EVT_EXEC(N(EVS_TexPan_LavaFlow))
    EVT_EXEC(N(EVS_TexPan_LavaGather))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(D_8024202C_B861AC))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_WAIT(65)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
