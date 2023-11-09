#include "sam_06.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki2);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki2);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -185.0f, 90.0f, -225.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki3);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki3);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -451.0f, 60.0f, 80.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki5b);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_muki5);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -405.0f, 0.0f, 228.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki6b);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki6);

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { 291.0f, 0.0f, 385.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree5_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki10);
FoliageModelList N(Tree5_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki10);

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { 108.0f, 83.0f, 115.0f },
    .radius = 0.0f
};

EvtScript N(EVS_ExitWalk_sam_05_1) = EVT_EXIT_WALK(60, sam_06_ENTRY_0, "sam_05", sam_05_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_TexPan_Fire) = {
    EVT_CALL(EnableTexPanning, MODEL_hi1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_hi2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_hi3, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   50,   50,  -70,  300)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_STARBORN_VALLEY)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_StarbornValley, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_ManageSnowfall))
    EVT_EXEC(N(EVS_TexPan_Fire))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_CALL(SetRenderMode, MODEL_h_yuki2, RENDER_MODE_SURFACE_XLU_ZB_ZUPD)
    EVT_CALL(SetRenderMode, MODEL_khm_y2, RENDER_MODE_SURFACE_XLU_ZB_ZUPD)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_ground, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_kabe, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o262, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o263, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o264, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o265, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o266, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o267, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o268, SURFACE_TYPE_SNOW)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree4)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o225, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree5)), 1, 0)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_WAIT(1)
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_LABEL(0)
            EVT_CALL(MakeLerp, 100, 90, 5, EASING_LINEAR)
            EVT_LABEL(1)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_ADD(LVar2, 8)
                EVT_MOD(LVar2, 360)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_CALL(MakeLerp, 90, 100, 5, EASING_LINEAR)
            EVT_LABEL(2)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_ADD(LVar2, 8)
                EVT_MOD(LVar2, 360)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
