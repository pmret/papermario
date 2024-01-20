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
    Wait(15)
    Call(N(func_8024173C_8CF7AC))
    IfEq(LVar0, 1)
        Call(SetNpcVar, NPC_06, 4, 1)
    EndIf
    Return
    End
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
    IfEq(GF_KMR05_Tree1_Coin, TRUE)
        Return
    EndIf
    IfEq(AF_JAN01_TreeDrop_StarPiece, TRUE)
        Return
    EndIf
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 490)
        Call(MakeItemEntity, ITEM_COIN, 540, 290, -180, ITEM_SPAWN_MODE_FALL, GF_KMR05_Tree1_Coin)
    Else
        Call(MakeItemEntity, ITEM_COIN, 436, 300, -180, ITEM_SPAWN_MODE_FALL, GF_KMR05_Tree1_Coin)
    EndIf
    Set(AF_JAN01_TreeDrop_StarPiece, TRUE)
    Return
    End
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
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o1238, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Return
    End
};
