#include "jan_10.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o29);

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { -527.0f, 20.0f, 124.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o30);

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -368.0f, 22.0f, 145.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o37);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -305.0f, 20.0f, -10.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o38);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -261.0f, 20.0f, -14.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o33);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { 35.0f, 22.0f, -70.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o34);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { 75.0f, 20.0f, -47.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o94, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o95, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o96, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o97, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o98, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o99, 1, 0)
    Return
    End
};
