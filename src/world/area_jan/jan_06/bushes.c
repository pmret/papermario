#include "jan_06.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o136);

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { -469.0f, 20.0f, -117.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o135);

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -451.0f, 22.0f, -145.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o130);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -256.0f, 22.0f, -422.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o127);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -141.0f, 20.0f, -484.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o128);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -80.0f, 20.0f, -490.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o129);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { 84.0f, 22.0f, -490.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o132);

FoliageVectorList N(Bush7_Effects) = {
    .count = 1,
    .vectors = {
        { 200.0f, 20.0f, -464.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .vectors = &N(Bush7_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o125);

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { 114.0f, 20.0f, -7.0f },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o126);

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { 164.0f, 22.0f, -25.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Bush10_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o123);

FoliageVectorList N(Bush10_Effects) = {
    .count = 1,
    .vectors = {
        { -124.0f, 22.0f, 372.0f },
    }
};

SearchBushConfig N(SearchBush_Bush10) = {
    .bush = &N(Bush10_BushModels),
    .vectors = &N(Bush10_Effects),
};

FoliageModelList N(Bush11_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o124);

FoliageVectorList N(Bush11_Effects) = {
    .count = 1,
    .vectors = {
        { -87.0f, 20.0f, 341.0f },
    }
};

SearchBushConfig N(SearchBush_Bush11) = {
    .bush = &N(Bush11_BushModels),
    .vectors = &N(Bush11_Effects),
};

FoliageModelList N(Bush12_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o137);

FoliageVectorList N(Bush12_Effects) = {
    .count = 1,
    .vectors = {
        { 150.0f, 20.0f, 486.0f },
    }
};

SearchBushConfig N(SearchBush_Bush12) = {
    .bush = &N(Bush12_BushModels),
    .vectors = &N(Bush12_Effects),
};

FoliageModelList N(Bush13_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o131);

FoliageVectorList N(Bush13_Effects) = {
    .count = 1,
    .vectors = {
        { 396.0f, 20.0f, -90.0f },
    }
};

SearchBushConfig N(SearchBush_Bush13) = {
    .bush = &N(Bush13_BushModels),
    .vectors = &N(Bush13_Effects),
};

FoliageModelList N(Bush14_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o139);

FoliageVectorList N(Bush14_Effects) = {
    .count = 1,
    .vectors = {
        { 439.0f, 22.0f, 140.0f },
    }
};

SearchBushConfig N(SearchBush_Bush14) = {
    .bush = &N(Bush14_BushModels),
    .vectors = &N(Bush14_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o232, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o233, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o234, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o235, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o236, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o237, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush7)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o238, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush8)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o239, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush9)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o240, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush10)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o241, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush11)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o242, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush12)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o243, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush13)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o244, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush14)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o245, 1, 0)
    Return
    End
};
