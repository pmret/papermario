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
    Wait(15)
    Call(N(IsJungleFuzzyAlive))
    IfEq(LVar0, TRUE)
        Call(SetNpcVar, NPC_JungleFuzzy, 7, 1)
    EndIf
    Return
    End
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
    .diameter = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o91, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Return
    End
};
