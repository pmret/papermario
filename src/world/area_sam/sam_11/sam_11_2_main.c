#include "sam_11.h"

EvtScript N(EVS_LoadPondAnimation) = {
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(ShatterPondSkeleton)))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(N(AS_ShatterPond)))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    EVT_RETURN
    EVT_END
};

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o558);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki3);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 447.0f, 0.0f, -144.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o192);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki4);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -440.0f, 0.0f, -178.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels) =  FOLIAGE_MODEL_LIST(MODEL_o190);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki5);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -450.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_ExitWalk_sam_02_1) = {
    EVT_IF_EQ(MV_ThrownOut, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, sam_11_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sam_02"), sam_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_sam_03_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_SAM11_LeftTown, TRUE)
    EVT_CALL(UseExitHeading, 60, sam_11_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sam_03"), sam_03_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHIVER_CITY)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, sam_11_ENTRY_2)
        EVT_GOTO(10)
    EVT_END_IF
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
        EVT_CALL(FadeInMusic, 0, SONG_SHIVER_CITY, 0, 3000, 0, 127)
        EVT_RETURN
    EVT_LABEL(10)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(BeforeNPCs)))
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(MysteryNPCs)))
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(AfterNPCs)))
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o621, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetRenderMode, MODEL_o583, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_ManageSnowfall))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_EXEC_WAIT(N(EVS_SetupPond))
    EVT_EXEC_WAIT(N(EVS_SetupStaircase))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o595, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o653, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o664, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o677, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o678, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_tumori, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_g_yuki2, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki4, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_CALL(InitAnimatedModels)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, sam_11_ENTRY_2)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
