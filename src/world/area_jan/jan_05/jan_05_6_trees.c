#include "jan_05.h"

#define NAME_SUFFIX _Trees
#include "common/foliage.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(func_8024268C_B4D0FC)) {
    if (get_enemy_safe(NPC_JungleFuzzy) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnShakeTree1) = {
    Wait(15)
    Call(N(func_8024268C_B4D0FC))
    IfEq(LVar0, 1)
        Call(SetNpcVar, NPC_JungleFuzzy, 7, 1)
    EndIf
    Return
    End
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o95, MODEL_o96, MODEL_o97, MODEL_o98, MODEL_o99);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o94);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { 87.0f, 114.0f, -390.0f },
        { 172.0f, 114.0f, -400.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 127.0f, 0.0f, -420.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o89, MODEL_o90, MODEL_o91, MODEL_o92, MODEL_o93);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o88);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 400, 100, -145 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_JAN05_Tree2_Coin,
        },
    }
};

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { 402.0f, 114.0f, -135.0f },
        { 487.0f, 114.0f, -145.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 442.0f, 0.0f, -165.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o83, MODEL_o84, MODEL_o85, MODEL_o86, MODEL_o87);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o34);

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { -309.0f, 112.0f, -301.0f },
        { -226.0f, 105.0f, -306.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .vectors = &N(Tree3_Effects),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -270.0f, 0.0f, -310.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupTrees) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o187, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o188, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_WALL_HAMMER, COLLIDER_o87, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_Trees)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Return
    End
};
