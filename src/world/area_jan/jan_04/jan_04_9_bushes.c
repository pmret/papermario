#include "jan_04.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o82);

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { -400.0f, 20.0f, -120.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o81);

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -353.0f, 22.0f, -81.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o83);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -264.0f, 20.0f, -402.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o85);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -211.0f, 22.0f, -420.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o89);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -111.0f, 22.0f, -62.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o91);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { 258.0f, 20.0f, -286.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o92);

FoliageVectorList N(Bush7_Effects) = {
    .count = 1,
    .vectors = {
        { 315.0f, 20.0f, -289.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .vectors = &N(Bush7_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o86);

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { 284.0f, 20.0f, 181.0f },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o88);

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { 378.0f, 22.0f, 185.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Bush10_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o87);

FoliageVectorList N(Bush10_Effects) = {
    .count = 1,
    .vectors = {
        { 435.0f, 20.0f, 205.0f },
    }
};

SearchBushConfig N(SearchBush_Bush10) = {
    .bush = &N(Bush10_BushModels),
    .vectors = &N(Bush10_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o118, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o162, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o119, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o163, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o121, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o122, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush7)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush8)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o120, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush9)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o164, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush10)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o165, 1, 0)
    Return
    End
};
