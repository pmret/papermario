#include "nok_02.h"

#include "common/foliage.inc.c"

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o443, MODEL_o460);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_KOOPA_LEAF,
            .pos = { -407, 16, 90 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_NOK02_Bush1_KoopaLeaf,
            .spawnFlag = MF_Bush1_Drop,
        },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o444, MODEL_o461);

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o445, MODEL_o462);

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o446, MODEL_o454, MODEL_o455, MODEL_o456);

EvtScript N(EVS_Bush4_HideFlowers) = {
    EVT_CALL(EnableModel, MODEL_o454, FALSE)
    EVT_CALL(EnableModel, MODEL_o455, FALSE)
    EVT_CALL(EnableModel, MODEL_o456, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush4) = {
    EVT_CALL(EnableModel, MODEL_o454, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o456, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o455, TRUE)
    EVT_RETURN
    EVT_END
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .callback = &N(EVS_OnSearchBush4),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o447, MODEL_o457, MODEL_o458, MODEL_o459);

EvtScript N(EVS_Bush5_HideFlowers) = {
    EVT_CALL(EnableModel, MODEL_o457, FALSE)
    EVT_CALL(EnableModel, MODEL_o458, FALSE)
    EVT_CALL(EnableModel, MODEL_o459, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush5) = {
    EVT_CALL(EnableModel, MODEL_o457, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o459, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o458, TRUE)
    EVT_RETURN
    EVT_END
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .callback = &N(EVS_OnSearchBush5),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o448, MODEL_o314);

FoliageDropList N(Bush6_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 387, 16, 202 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_NOK01_Bush5_Coin,
        },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .drops = &N(Bush6_Drops),
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o284);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o283);

EvtScript N(EVS_OnShakeTree1) = {
    EVT_WAIT(15)
    EVT_SET(AF_NOK_13, TRUE)
    EVT_RETURN
    EVT_END
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 443.0f, 0.0f, 68.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o332, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o427, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o458, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o459, 1, 0)
    EVT_EXEC(N(EVS_Bush4_HideFlowers))
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o460, 1, 0)
    EVT_EXEC(N(EVS_Bush5_HideFlowers))
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o461, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o346, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
