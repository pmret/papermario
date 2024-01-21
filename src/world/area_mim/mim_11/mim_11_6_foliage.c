#include "mim_11.h"

#include "common/foliage.inc.c"

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o182);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_STRANGE_LEAF,
            .pos = { 357, 16, 315 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_NEVER_VANISH,
            .spawnFlag = AF_JAN01_TreeDrop_StarPiece,
        },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o183);

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o184);

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o185);

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
};

EvtScript N(EVS_SetupFoliage) = {
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o207, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o208, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o209, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o210, 1, 0)
    Return
    End
};
