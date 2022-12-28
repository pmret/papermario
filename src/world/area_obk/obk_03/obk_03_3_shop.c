#include "obk_03.h"

s32 N(ShopMessages)[] = {
    MSG_Shop_0060,
    MSG_Shop_0061,
    MSG_Shop_0062,
    MSG_Shop_0063,
    MSG_Shop_0064,
    MSG_Shop_0065,
    MSG_Shop_0066,
    MSG_Shop_0067, 
    MSG_Shop_0068,
    MSG_Shop_0069,
    MSG_Shop_006A,
    MSG_Shop_006B,
    MSG_Shop_006C,
    MSG_Shop_006D,
    MSG_Shop_006E,
    MSG_Shop_006F, 
    MSG_Shop_0070,
    MSG_Shop_0071,
    MSG_Shop_0072,
    MSG_Shop_0073,
    MSG_Shop_0074,
    MSG_Shop_0075,
    MSG_Shop_0076, 
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_MYSTERY,       .price = 1,  .descMsg = MSG_ItemShopDesc_Mystery },
    { .itemID = ITEM_STOP_WATCH,    .price = 25, .descMsg = MSG_ItemShopDesc_StopWatch },
    { .itemID = ITEM_SNOWMAN_DOLL,  .price = 15, .descMsg = MSG_ItemShopDesc_SnowmanDoll },
    { .itemID = ITEM_MAPLE_SYRUP,   .price = 25, .descMsg = MSG_ItemShopDesc_MapleSyrup },
    { .itemID = ITEM_LIFE_SHROOM,   .price = 50, .descMsg = MSG_ItemShopDesc_LifeShroom },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 13, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_DUSTY_HAMMER,  .sellPrice = 4 },
    { .itemID = ITEM_DRIED_SHROOM,  .sellPrice = 3 },
    { .itemID = ITEM_MISTAKE,       .sellPrice = 5 },
    { .itemID = ITEM_JELLY_ULTRA,   .sellPrice = 200 },
    { .itemID = ITEM_STINKY_HERB,   .sellPrice = 5 },
    {}
};

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_o354, .triggerColliderID = COLLIDER_o485 },
    { .posModelID = MODEL_o355, .triggerColliderID = COLLIDER_o486 },
    { .posModelID = MODEL_o356, .triggerColliderID = COLLIDER_o487 },
    { .posModelID = MODEL_o357, .triggerColliderID = COLLIDER_o488 },
    { .posModelID = MODEL_o358, .triggerColliderID = COLLIDER_o489 },
    { .posModelID = MODEL_o359, .triggerColliderID = COLLIDER_o490 },
};

EvtScript N(EVS_OnBuy) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopOwner N(Owner) = {
    .npcID = NPC_Igor,
    .idleAnim = ANIM_Boo_Idle,
    .talkAnim = ANIM_Boo_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o485, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o486, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o487, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o488, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o489, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o490, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};
