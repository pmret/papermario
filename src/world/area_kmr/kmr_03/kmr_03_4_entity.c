#include "kmr_03.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock1) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH0_LEFT_THE_PLAYGROUND)
    Return
    End
};

EvtScript N(EVS_OnSmashBlock2) = {
    Set(GF_KMR03_Hammer1Block, TRUE)
    Return
    End
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
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_CH0_LEFT_THE_PLAYGROUND)
        Call(MakeEntity, Ref(Entity_Hammer1Block), 45, 0, 70, 15, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock1)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_KMR03_Hammer1Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block), 230, 0, 310, 15, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock2)))
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 230, 60, 310, 15, ITEM_REPEL_GEL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR03_HiddenItem_RepelGel)
    Call(MakeEntity, Ref(Entity_BrickBlock), 230, 50, -160, 15, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 165, 0, 380, 20, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), -170, 0, 370, 43, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR03_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_SimpleSpring), 345, 75, -250, 0, 100, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_COIN, 345, 205, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, 345, 230, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinB)
    Call(MakeItemEntity, ITEM_COIN, 345, 255, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinC)
    Call(MakeItemEntity, ITEM_COIN, 345, 280, -250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR03_Item_CoinD)
    Call(MakeItemEntity, ITEM_FIRE_FLOWER, 229, 250, -156, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR02_Item_FireFlower)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 300, 0, 150, 0, MODEL_jimen_1, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_KMR03_HiddenPanel)
    Call(MakeEntity, Ref(Entity_HeartBlock), 130, 60, 0, 0, MAKE_ENTITY_END)
    Return
    End
};
