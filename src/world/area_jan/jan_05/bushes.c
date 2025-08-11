#include "jan_05.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBushes_Separate) = EVT_MOVE_BUSHES(COLLIDER_o64,
    MODEL_o64, MODEL_o65, MV_BushOffsetL, MV_BushOffsetR);

EvtScript N(EVS_MoveBushes) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o64, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBushes_Separate))
    Call(DisablePlayerInput, true)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Label(0)
    Call(UpdateLerp)
    SetF(MV_BushOffsetR, LVar0)
    SetF(MV_BushOffsetL, MV_BushOffsetR)
    MulF(MV_BushOffsetL, -1)
    IfEq(LVar1, 1)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, false)
    Return
    End
};

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o63);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 168, 20, 375 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_JAN05_Bush1_Coin,
        },
    }
};

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { 168.0f, 20.0f, 375.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o141);

FoliageDropList N(Bush2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -401, 20, 176 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_JAN05_Bush2_Coin,
            .spawnFlag = MF_BushDrop_Coin,
        },
    }
};

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -401.0f, 20.0f, 176.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .drops = &N(Bush2_Drops),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o140);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -242.0f, 22.0f, 205.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o142);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -206.0f, 20.0f, 248.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o134);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -462.0f, 20.0f, -207.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o137);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { -417.0f, 20.0f, -261.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o131);

FoliageVectorList N(Bush7_Effects) = {
    .count = 1,
    .vectors = {
        { -32.0f, 22.0f, -364.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .vectors = &N(Bush7_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o132);

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { -91.0f, 20.0f, -485.0f },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o133);

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { 94.0f, 22.0f, -485.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Bush10_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o139);

FoliageVectorList N(Bush10_Effects) = {
    .count = 1,
    .vectors = {
        { 9.0f, 20.0f, -90.0f },
    }
};

SearchBushConfig N(SearchBush_Bush10) = {
    .bush = &N(Bush10_BushModels),
    .vectors = &N(Bush10_Effects),
};

FoliageModelList N(Bush11_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o138);

FoliageVectorList N(Bush11_Effects) = {
    .count = 1,
    .vectors = {
        { 53.0f, 20.0f, -63.0f },
    }
};

SearchBushConfig N(SearchBush_Bush11) = {
    .bush = &N(Bush11_BushModels),
    .vectors = &N(Bush11_Effects),
};

FoliageModelList N(Bush12_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o102);

FoliageVectorList N(Bush12_Effects) = {
    .count = 1,
    .vectors = {
        { 339.0f, 22.0f, -151.0f },
    }
};

SearchBushConfig N(SearchBush_Bush12) = {
    .bush = &N(Bush12_BushModels),
    .vectors = &N(Bush12_Effects),
};

FoliageModelList N(Bush13_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o126);

FoliageVectorList N(Bush13_Effects) = {
    .count = 1,
    .vectors = {
        { 144.0f, 22.0f, 490.0f },
    }
};

SearchBushConfig N(SearchBush_Bush13) = {
    .bush = &N(Bush13_BushModels),
    .vectors = &N(Bush13_Effects),
};

FoliageModelList N(Bush14_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o106);

FoliageVectorList N(Bush14_Effects) = {
    .count = 1,
    .vectors = {
        { 209.0f, 20.0f, 471.0f },
    }
};

SearchBushConfig N(SearchBush_Bush14) = {
    .bush = &N(Bush14_BushModels),
    .vectors = &N(Bush14_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    BindTrigger(Ref(N(EVS_MoveBushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o64, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o135, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o213, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o214, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o215, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o216, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o217, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush7)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o218, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush8)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o219, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush9)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o220, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush10)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o221, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush11)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o222, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush12)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o223, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush13)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o224, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush14)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o225, 1, 0)
    Return
    End
};
