#include "kmr_05.h"

#include "common/foliage.inc.c"

API_CALLABLE(N(func_8024173C_8CF7AC)) {
    if (get_enemy_safe(NPC_06) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_80243234) = {
    EVT_WAIT(15)
    EVT_CALL(N(func_8024173C_8CF7AC))
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcVar, NPC_06, 4, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ha2_1, MODEL_ha2_2, MODEL_ha2_3);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o1065, MODEL_miki2_1, MODEL_miki2_2);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { 439.0f, 314.0f, -181.0f },
        { 524.0f, 314.0f, -210.0f },
    }
};

EvtScript N(EVS_OnShakeTree1) = {
    EVT_IF_EQ(GF_KMR05_Tree1_Coin, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_JAN01_TreeDrop_StarPiece, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 490)
        EVT_CALL(MakeItemEntity, ITEM_COIN, 540, 290, -180, ITEM_SPAWN_MODE_FALL, GF_KMR05_Tree1_Coin)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_COIN, 436, 300, -180, ITEM_SPAWN_MODE_FALL, GF_KMR05_Tree1_Coin)
    EVT_END_IF
    EVT_SET(AF_JAN01_TreeDrop_StarPiece, TRUE)
    EVT_RETURN
    EVT_END
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
    .callback = &N(EVS_OnShakeTree1),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 488.0f, 245.0f, -196.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o1238, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_RETURN
    EVT_END
};
