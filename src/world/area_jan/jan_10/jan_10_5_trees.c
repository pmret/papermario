#include "jan_10.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(IsJungleFuzzyAlive)) {
    if (get_enemy_safe(NPC_JungleFuzzy) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnShakeTree1) = {
    EVT_WAIT(15)
    EVT_CALL(N(IsJungleFuzzyAlive))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetNpcVar, NPC_JungleFuzzy, 7, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o59, MODEL_o60, MODEL_o61, MODEL_o62, MODEL_o63);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o58);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -597.0f, 114.0f, 59.0f },
        { -512.0f, 114.0f, 49.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -557.0f, 0.0f, 29.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o91, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
