#include "mac_01.h"

API_CALLABLE(N(func_80240000_800880)) {
    s32 itemIndex = evt_get_variable(script, *script->ptrReadPos);

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, ITEM_ENTITY_FLAGS_40);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240044_8008C4)) {
    s32 itemIndex = evt_get_variable(script, *script->ptrReadPos);
    s32* var1 = (s32*) evt_get_variable(NULL, MV_Unk_02);

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, ITEM_ENTITY_FLAGS_40);
    evt_set_variable(NULL, var1[itemIndex], 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802400C8_800948);
INCLUDE_ASM(s32, "world/area_mac/mac_01/800880", func_802400C8_800948);
MAP_DATA_SECTION_START

s32 N(ShopMessages)[] = {
    MSG_Shop_0017,
    MSG_Shop_0018,
    MSG_Shop_0002,
    MSG_Shop_0019,
    MSG_Shop_0004,
    MSG_Shop_0005,
    MSG_Shop_0006,
    MSG_Shop_0007, 
    MSG_Shop_0008,
    MSG_Shop_0009,
    MSG_Shop_000A,
    MSG_Shop_000B,
    MSG_Shop_000C,
    MSG_Shop_000D,
    MSG_Shop_000E,
    MSG_Shop_000F, 
    MSG_Shop_0010,
    MSG_Shop_0011,
    MSG_Shop_0012,
    MSG_Shop_0013,
    MSG_Shop_0014,
    MSG_Shop_0015,
    MSG_Shop_001A, 
};

ShopSellPriceData N(RowfDummyPriceList)[] = {
    { .itemID = ITEM_SHOOTING_STAR,  .sellPrice = 0 },
    {}
};

EvtScript N(EVS_OnBuy) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(0)
                    EVT_SET(GF_MAC01_RowfBadgeAvailableA, TRUE)
                    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CASE_EQ(1)
                    EVT_SET(GF_MAC01_RowfBadgeAvailableB, TRUE)
                    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CASE_EQ(2)
                    EVT_SET(GF_MAC01_RowfBadgeAvailableC, TRUE)
                    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_SWITCH
            EVT_CALL(N(func_80240044_8008C4), LVar2)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopItemData N(RowfBadgeInventory)[] = {
    { .itemID = ITEM_SPEEDY_SPIN,    .price =  50, .descMsg = MSG_ItemShopDesc_SpeedySpin },
    { .itemID = ITEM_FIRST_ATTACK,   .price = 100, .descMsg = MSG_ItemShopDesc_FirstAttack },
    { .itemID = ITEM_MULTIBOUNCE,    .price =  75, .descMsg = MSG_ItemShopDesc_Multibounce },
    { .itemID = ITEM_D_DOWN_POUND,   .price =  75, .descMsg = MSG_ItemShopDesc_DDownPound },
    { .itemID = ITEM_DODGE_MASTER,   .price = 100, .descMsg = MSG_ItemShopDesc_DodgeMaster },
    { .itemID = ITEM_SLEEP_STOMP,    .price =  75, .descMsg = MSG_ItemShopDesc_SleepStomp },
    { .itemID = ITEM_DOUBLE_DIP,     .price = 100, .descMsg = MSG_ItemShopDesc_DoubleDip },
    { .itemID = ITEM_BOOTS_CHARGE,   .price =  50, .descMsg = MSG_ItemShopDesc_JumpCharge },
    { .itemID = ITEM_SPIN_SMASH,     .price =  75, .descMsg = MSG_ItemShopDesc_SpinSmash },
    { .itemID = ITEM_GROUP_FOCUS,    .price = 100, .descMsg = MSG_ItemShopDesc_GroupFocus },
    { .itemID = ITEM_ALLOR_NOTHING,  .price = 100, .descMsg = MSG_ItemShopDesc_AllorNothing },
    { .itemID = ITEM_HP_PLUS_C,      .price = 150, .descMsg = MSG_ItemShopDesc_HPPlus },
    { .itemID = ITEM_FP_PLUS_C,      .price = 150, .descMsg = MSG_ItemShopDesc_FPPlus },
    { .itemID = ITEM_S_SMASH_CHG,    .price = 100, .descMsg = MSG_ItemShopDesc_SSmashChg },
    { .itemID = ITEM_DAMAGE_DODGE_A, .price = 150, .descMsg = MSG_ItemShopDesc_DamageDodge },
    { .itemID = ITEM_MEGA_QUAKE,     .price = 200, .descMsg = MSG_ItemShopDesc_MegaQuake },
};

ShopItemLocation N(RowfItemPositions)[] = {
    { .posModelID = MODEL_b3, .triggerColliderID = COLLIDER_b3 }, 
    { .posModelID = MODEL_b2, .triggerColliderID = COLLIDER_b2 }, 
    { .posModelID = MODEL_b1, .triggerColliderID = COLLIDER_b1 }, 
};

ShopOwner N(ShopOwnerRowf) = {
    .npcID = NPC_Rowf,
    .idleAnim = ANIM_Rowf_Idle,
    .talkAnim = ANIM_Rowf_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupBadgeShop) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0F, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0E, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0D, TRUE)
    EVT_LABEL(4)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0C, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0B, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_0A, TRUE)
    EVT_LABEL(3)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_09, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_08, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_07, TRUE)
    EVT_LABEL(2)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_06, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_05, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_04, TRUE)
    EVT_LABEL(1)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_03, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_02, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_01, TRUE)
    EVT_SET(GF_MAC01_UnlockedRowfBadge_00, TRUE)
    EVT_CALL(func_802400C8_800948)
    EVT_SET(MV_Unk_02, LVar1)
    EVT_IF_EQ(LVar3, 0)
        EVT_SET(GF_MAC01_RowfBadgeAvailableA, FALSE)
        EVT_SET(GF_MAC01_RowfBadgeAvailableB, FALSE)
        EVT_SET(GF_MAC01_RowfBadgeAvailableC, FALSE)
        EVT_IF_LT(LVar0, 3)
            EVT_SET(GF_MAC01_RowfBadgeAvailableC, TRUE)
        EVT_END_IF
        EVT_IF_LT(LVar0, 2)
            EVT_SET(GF_MAC01_RowfBadgeAvailableB, TRUE)
        EVT_END_IF
        EVT_IF_LT(LVar0, 1)
            EVT_SET(GF_MAC01_RowfBadgeAvailableA, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeShop, EVT_PTR(N(RowfItemPositions)), LVar2, EVT_PTR(N(RowfDummyPriceList)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(ShopOwnerRowf)))
    EVT_IF_EQ(LVar3, 1)
        EVT_IF_GE(LVar0, 3)
            EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, TRUE)
                EVT_CALL(N(func_80240044_8008C4), 2)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar0, 2)
            EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, TRUE)
                EVT_CALL(N(func_80240044_8008C4), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar0, 1)
            EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, TRUE)
                EVT_CALL(N(func_80240044_8008C4), 0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
