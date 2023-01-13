#include "mac_01.h"

API_CALLABLE(N(HideRowfBadge)) {
    s32 itemIndex = evt_get_variable(script, *script->ptrReadPos);

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, ITEM_ENTITY_FLAG_HIDDEN);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRowfBadgeBought)) {
    s32 itemIndex = evt_get_variable(script, *script->ptrReadPos);
    s32* buyFlags = (s32*) evt_get_variable(NULL, MV_RowfShopBuyFlags);

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, ITEM_ENTITY_FLAG_HIDDEN);
    evt_set_variable(NULL, buyFlags[itemIndex], TRUE);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateShopInventory)) {
    s32 varBaseUnlocked = GF_MAC01_UnlockedRowfBadge_00;
    s32 varBaseHasBought = GF_MAC01_RowfBadge_00;
    s32 options[16];
    s32 itemID;
    s32 shopIdx;
    s32 randIdx;
    s32 available;
    s32 count;
    s32 i;
    
    ShopItemData* inventory = heap_malloc(4 * sizeof(ShopItemData));
    s32* buyFlags = heap_malloc(3 * sizeof(s32));
    buyFlags[0] = 0;
    buyFlags[1] = 0;
    buyFlags[2] = 0;
    inventory[0].itemID = 0;
    inventory[1].itemID = 0;
    inventory[2].itemID = 0;
    inventory[3].itemID = 0;
    
    if (!evt_get_variable(script, GF_MAC01_RowfBadgesChosen)) {
        available = 0;
        for (i = 0; i < (u32) ARRAY_COUNT(options); i++) {
            s32 isUnlocked = evt_get_variable(NULL, varBaseUnlocked + i);
            s32 hasBought = evt_get_variable(NULL, varBaseHasBought + i);
            if ((isUnlocked == 1) && (hasBought == 0)) {
                options[available++] = i;
            }
        }
        
        count = 0;
        while (available != 0) {
            randIdx = rand_int(available - 1);
            shopIdx = options[randIdx];

            itemID = mac_01_RowfBadgeInventory[shopIdx].itemID;
            inventory[count].itemID = itemID;
            inventory[count].price = gItemTable[itemID].sellValue;
            inventory[count].descMsg = mac_01_RowfBadgeInventory[shopIdx].descMsg;
            buyFlags[count] = varBaseHasBought + shopIdx;
            
            evt_set_variable(script, GB_MAC01_Rowf_Badge0 + count, shopIdx);

            count++;
            if (count >= 3)
                break;

            for (i = randIdx; i < available - 1; i++) {
                options[i] = options[i + 1];
            }
            available--;
        }
        evt_set_variable(script, GB_MAC01_Rowf_NumBadges, count);
        evt_set_variable(script, GF_MAC01_RowfBadgesChosen, TRUE);
        script->varTable[3] = FALSE;
    } else {
        count = evt_get_variable(script, GB_MAC01_Rowf_NumBadges);
        for (i = 0; i < count; i++) {
            shopIdx = evt_get_variable(script, GB_MAC01_Rowf_Badge0 + i);
            itemID = mac_01_RowfBadgeInventory[shopIdx].itemID;
            inventory[i].itemID = itemID;
            inventory[i].price = gItemTable[itemID].sellValue;
            inventory[i].descMsg = mac_01_RowfBadgeInventory[shopIdx].descMsg;
            buyFlags[i] = varBaseHasBought + shopIdx;
        }
        script->varTable[3] = TRUE;
    }
    
    script->varTable[0] = count;
    script->varTablePtr[1] = buyFlags;
    script->varTablePtr[2] = inventory;
    return ApiStatus_DONE2;
}

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
            EVT_CALL(N(SetRowfBadgeBought), LVar2)
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
    EVT_CALL(N(CreateShopInventory))
    EVT_SET(MV_RowfShopBuyFlags, LVar1)
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
                EVT_CALL(N(SetRowfBadgeBought), 2)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar0, 2)
            EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, TRUE)
                EVT_CALL(N(SetRowfBadgeBought), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar0, 1)
            EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, TRUE)
                EVT_CALL(N(SetRowfBadgeBought), 0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
