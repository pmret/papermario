#include "nok_01.h"

#include "common/foliage.inc.c"

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o315);

FoliageDropList N(Bush5_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -113, 16, 430 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_NOK01_Bush1_Coin,
        },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .drops = &N(Bush5_Drops),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o322, MODEL_o320);

FoliageDropList N(Bush3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_KOOT_GLASSES,
            .pos = { -39, 16, 404 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_NEVER_VANISH,
            .pickupFlag = GF_NOK01_Bush6_Glasses,
            .spawnFlag = MF_Bush3_Drop,
        },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush4_BushModels),
    .drops = &N(Bush3_Drops),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o390, MODEL_o396, MODEL_o397, MODEL_o398);

EvtScript N(EVS_Bush6_HideFlowers) = {
    EVT_CALL(EnableModel, MODEL_o396, FALSE)
    EVT_CALL(EnableModel, MODEL_o397, FALSE)
    EVT_CALL(EnableModel, MODEL_o398, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush6) = {
    EVT_CALL(EnableModel, MODEL_o396, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o398, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o397, TRUE)
    EVT_RETURN
    EVT_END
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .callback = &N(EVS_OnSearchBush6),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o391);

FoliageDropList N(Bush7_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_DRIED_SHROOM,
            .pos = { 43, 16, 443 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_NOK01_Bush3_DriedShroom,
        },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .drops = &N(Bush7_Drops),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o392);

FoliageDropList N(Bush8_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_KOOPA_LEAF,
            .pos = { 329, 16, 245 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_NOK01_Bush4_KoopaLeaf,
            .spawnFlag = MF_Bush8_Drop,
        },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .drops = &N(Bush8_Drops),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o393, MODEL_o402);

FoliageDropList N(Bush9_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 364, 16, 102 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_NOK01_Bush5_Coin,
            .spawnFlag = MF_Bush9_Drop,
        },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .drops = &N(Bush9_Drops),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o394, MODEL_o399, MODEL_o400, MODEL_o401);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_KOOT_EMPTY_WALLET,
            .pos = { 441, 16, 57 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_NEVER_VANISH,
            .pickupFlag = GF_NOK01_Bush7_EmptyWallet,
            .spawnFlag = MF_Bush1_Drop,
        },
    }
};

EvtScript N(EVS_Bush2_HideFlowers) = {
    EVT_CALL(EnableModel, MODEL_o399, FALSE)
    EVT_CALL(EnableModel, MODEL_o400, FALSE)
    EVT_CALL(EnableModel, MODEL_o401, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush2) = {
    EVT_CALL(EnableModel, MODEL_o399, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o401, TRUE)
    EVT_WAIT(10)
    EVT_CALL(EnableModel, MODEL_o400, TRUE)
    EVT_RETURN
    EVT_END
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .callback = &N(EVS_OnSearchBush2),
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush2_BushModels),
    .drops = &N(Bush1_Drops),
    .callback = &N(EVS_OnSearchBush2),
};

FoliageModelList N(Tree1_LeafModels) = FOLIAGE_MODEL_LIST(MODEL_o300);

FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o299);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 198.0f, 0.0f, 147.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o312, 1, 0)
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH6_2)
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o313, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o419, 1, 0)
    EVT_EXEC(N(EVS_Bush6_HideFlowers))
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush7)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o420, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush8)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o421, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush9)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o422, 1, 0)
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH3_2)
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o423, 1, 0)
    EVT_EXEC(N(EVS_Bush2_HideFlowers))
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o323, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    // bind the same tree a second time for the koopa shell stuck inside
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_RecoverTreeShell)), TRIGGER_WALL_HAMMER, COLLIDER_o323, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_RecoverTreeShell)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
