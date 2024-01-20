#include "mac_03.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_OnShakeTree3) = {
    IfEq(GF_MAC03_UnlockedPlayroom, TRUE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Set(GF_MAC03_UnlockedPlayroom, TRUE)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, -128, 20, -555)
    Call(SetPanTarget, CAM_DEFAULT, -128, 20, -555)
    Call(SetCamDistance, CAM_DEFAULT, Float(330.0))
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5)
    Call(PlaySoundWithVolume, SOUND_GROW, 0)
    Call(EnableModel, MODEL_o241, TRUE)
    Set(LVar0, -30)
    Loop(30)
        Add(LVar0, 1)
        Call(TranslateModel, MODEL_o241, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(TranslateModel, MODEL_o241, 0, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_dokan, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilim, COLLIDER_FLAGS_UPPER_MASK)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
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
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o212, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o211, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_mgm_tree, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Return
    End
};
