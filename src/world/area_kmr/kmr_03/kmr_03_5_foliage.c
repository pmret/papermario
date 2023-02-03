#include "kmr_03.h"

#include "common/foliage.inc.c"

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_km);

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { 143.0f, 16.0f, 462.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ue);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_sita);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -80.0f, 130.0f, 18.0f },
        { 28.0f, 130.0f, 39.0f },
    }
};

EvtScript N(EVS_OnShakeTree1) = {
    EVT_IF_EQ(GF_KMR03_Tree1_Mushroom, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_JAN01_TreeDrop_StarPiece, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -30)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, -23, 100, 35, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_KMR03_Tree1_Mushroom)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, -85, 100, 16, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_KMR03_Tree1_Mushroom)
    EVT_END_IF
    EVT_SET(AF_JAN01_TreeDrop_StarPiece, TRUE)
    EVT_RETURN
    EVT_END
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -42.0f, 0.0f, -13.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_km, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_ki, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
