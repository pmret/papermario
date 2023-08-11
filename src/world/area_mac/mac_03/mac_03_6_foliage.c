#include "mac_03.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_OnShakeTree3) = {
    EVT_IF_EQ(GF_MAC03_UnlockedPlayroom, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_MAC03_UnlockedPlayroom, TRUE)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -128, 20, -555)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -128, 20, -555)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(330.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5)
    EVT_CALL(PlaySoundWithVolume, SOUND_GROW, 0)
    EVT_CALL(EnableModel, MODEL_o241, TRUE)
    EVT_SET(LVar0, -30)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 1)
        EVT_CALL(TranslateModel, MODEL_o241, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(TranslateModel, MODEL_o241, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_dokan, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilim, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o240);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o128);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { 63.0f, 100.0f, -508.0f },
        { 103.0f, 100.0f, -518.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 79.0f, 20.0f, -504.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o238);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o130);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { 538.0f, 100.0f, -293.0f },
        { 578.0f, 100.0f, -303.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 554.0f, 20.0f, -289.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o239);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o126);

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { -285.0f, 100.0f, -565.0f },
        { -245.0f, 80.0f, -555.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .vectors = &N(Tree3_Effects),
    .callback = &N(EVS_OnShakeTree3),
};

//@bug x-position should be -265
BombTrigger N(BombPos_Tree3) = {
    .pos = { 265.0f, 20.0f, -535.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o212, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o211, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_mgm_tree, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
