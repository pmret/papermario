#include "kmr_03.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock1) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH0_LEFT_THE_PLAYGROUND)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSmashBlock2) = {
    EVT_SET(GF_KMR03_Hammer1Block, TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/EnableCameraFollowPlayerY.inc.c"

#include "world/common/DisableCameraFollowPlayerY.inc.c"

API_CALLABLE(func_80240358_8C82E8) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    f32 xDelta = playerStatus->curSpeed * 5.0f * sin_deg(playerStatus->targetYaw);
    f32 zDelta = playerStatus->curSpeed * 5.0f * -cos_deg(playerStatus->targetYaw);

    script->varTable[0] = playerStatus->pos.x + xDelta;
    script->varTable[1] = playerStatus->pos.z + zDelta;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TetherCameraToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_LEFT_THE_PLAYGROUND)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), 45, 0, 70, 15, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock1)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_KMR03_Hammer1Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), 230, 0, 310, 15, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock2)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 230, 60, 310, 15, ITEM_REPEL_GEL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR03_HiddenItem_RepelGel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 230, 50, -160, 15, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 165, 0, 380, 20, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -170, 0, 370, 43, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR03_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 345, 75, -250, 0, 100, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 205, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 230, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 255, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 345, 280, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_FIRE_FLOWER, 229, 250, -156, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR02_Item_FireFlower)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 300, 0, 150, 0, MODEL_jimen_1, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KMR03_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 130, 60, 0, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
