#include "sbk_30.h"

#include "common/foliage.inc.c"

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki_ha);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_ki_miki);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_LETTER_TO_GOOMPA,
            .pos = { 204, 92, -220 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_NEVER_VANISH,
            .pickupFlag = GF_SBK30_Tree2_Letter02,
            .spawnFlag = MF_TreeDrop_Letter,
        },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree1_Drops),
};

BombTrigger N(BombPos_Tree) = {
    .pos = { 266.0f, 0.0f, -209.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o84, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree)), 1, 0)
    EVT_RETURN
    EVT_END
};
