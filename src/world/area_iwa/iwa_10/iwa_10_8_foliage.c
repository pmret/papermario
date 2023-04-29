#include "iwa_10.h"

#include "common/foliage.inc.c"

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_k4);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -839, 15, 521 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_IWA10_Bush1_Coin,
            .spawnFlag = MF_DropBush1,
        },
    }
};

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { -839.0f, 15.0f, 521.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_k5);

FoliageDropList N(Bush2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -691, 22, 384 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_IWA10_Bush2_Coin,
            .spawnFlag = MF_DropBush2,
        },
    }
};

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -691.0f, 22.0f, 384.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .drops = &N(Bush2_Drops),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_k6);

FoliageDropList N(Bush3_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -932, 21, 405 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_IWA10_Bush3_Coin,
            .spawnFlag = MF_DropBush3,
        },
    }
};

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -932.0f, 21.0f, 405.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .drops = &N(Bush3_Drops),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_k7);

FoliageDropList N(Bush4_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_EGG,
            .pos = { -800, 23, 280 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .spawnFlag = MF_DropBush4,
        },
    }
};

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -800.0f, 23.0f, 280.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .drops = &N(Bush4_Drops),
    .vectors = &N(Bush4_Effects),
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_k4, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_k5, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_k6, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_k7, 1, 0)
    EVT_RETURN
    EVT_END
};
