#include "mac_04.h"

s32 N(ShopMessages)[] = {
    MSG_Shop_001B,
    MSG_Shop_001C,
    MSG_Shop_001D,
    MSG_Shop_001E,
    MSG_Shop_001F,
    MSG_Shop_0020,
    MSG_Shop_0021,
    MSG_Shop_0022, 
    MSG_Shop_0023,
    MSG_Shop_0024,
    MSG_Shop_0025,
    MSG_Shop_0026,
    MSG_Shop_0027,
    MSG_Shop_0028,
    MSG_Shop_0029,
    MSG_Shop_002A, 
    MSG_Shop_002B,
    MSG_Shop_002C,
    MSG_Shop_002D,
    MSG_Shop_002E,
    MSG_Shop_002F,
    MSG_Shop_0030,
    MSG_Shop_0031, 
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_STONE_CAP,     .price = 30, .descMsg = MSG_ItemShopDesc_StoneCap },
    { .itemID = ITEM_DIZZY_DIAL,    .price = 15, .descMsg = MSG_ItemShopDesc_DizzyDial },
    { .itemID = ITEM_THUNDER_RAGE,  .price = 20, .descMsg = MSG_ItemShopDesc_ThunderRage },
    { .itemID = ITEM_TASTY_TONIC,   .price =  5, .descMsg = MSG_ItemShopDesc_TastyTonic },
    { .itemID = ITEM_VOLT_SHROOM,   .price = 10, .descMsg = MSG_ItemShopDesc_VoltShroom },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 20, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_FIRE_FLOWER,   .sellPrice =  7 },
    { .itemID = ITEM_POW_BLOCK,     .sellPrice =  5 },
    { .itemID = ITEM_SHOOTING_STAR, .sellPrice = 20 },
    { .itemID = ITEM_WHACKAS_BUMP,  .sellPrice = 50 },
    { .itemID = ITEM_STOP_WATCH,    .sellPrice = 20 },
    { .itemID = ITEM_REPEL_GEL,     .sellPrice = 30 },
    {}
};

EvtScript N(EVS_OnBuy) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_mono1, .triggerColliderID = COLLIDER_mono1 }, 
    { .posModelID = MODEL_mono2, .triggerColliderID = COLLIDER_mono2 }, 
    { .posModelID = MODEL_mono3, .triggerColliderID = COLLIDER_mono3 }, 
    { .posModelID = MODEL_mono4, .triggerColliderID = COLLIDER_mono4 }, 
    { .posModelID = MODEL_mono5, .triggerColliderID = COLLIDER_mono5 }, 
    { .posModelID = MODEL_mono6, .triggerColliderID = COLLIDER_mono6 }, 
};

ShopOwner N(Owner) = {
    .npcID = NPC_HarryT,
    .idleAnim = ANIM_HarryT_Idle,
    .talkAnim = ANIM_HarryT_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages) ,
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), ITEM_ENTITY_FLAGS_10000)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};
