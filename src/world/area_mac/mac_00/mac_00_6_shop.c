#include "mac_00.h"

s32 N(ShopMessages)[] = {
    MSG_Shop_0000, 
    MSG_Shop_0001,
    MSG_Shop_0002,
    MSG_Shop_0003,
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
    MSG_Shop_0016, 
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_FRIGHT_JAR,    .price =  5, .descMsg = MSG_ItemShopDesc_FrightJar },
    { .itemID = ITEM_SLEEPY_SHEEP,  .price = 10, .descMsg = MSG_ItemShopDesc_SleepySheep },
    { .itemID = ITEM_POW_BLOCK,     .price =  5, .descMsg = MSG_ItemShopDesc_POWBlock },
    { .itemID = ITEM_FIRE_FLOWER,   .price = 10, .descMsg = MSG_ItemShopDesc_FireFlower },
    { .itemID = ITEM_HONEY_SYRUP,   .price = 10, .descMsg = MSG_ItemShopDesc_HoneySyrup },
    { .itemID = ITEM_MUSHROOM,      .price =  5, .descMsg = MSG_ItemShopDesc_Mushroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_DRIED_SHROOM,  .sellPrice = 3 },
    { .itemID = ITEM_DRIED_PASTA,   .sellPrice = 5 },
    { .itemID = ITEM_DUSTY_HAMMER,  .sellPrice = 3 },
    { .itemID = ITEM_WHACKAS_BUMP,  .sellPrice = 64 },
    { .itemID = ITEM_DRIED_FRUIT,   .sellPrice = 20 },
    { .itemID = ITEM_LIME,          .sellPrice = 4 },
    { .itemID = ITEM_LEMON,         .sellPrice = 4 },
    {}
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

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_syouhin1, .triggerColliderID = COLLIDER_mono1 },
    { .posModelID = MODEL_syouhin2, .triggerColliderID = COLLIDER_mono2 },
    { .posModelID = MODEL_shouhin3, .triggerColliderID = COLLIDER_mono3 },
    { .posModelID = MODEL_shouhin4, .triggerColliderID = COLLIDER_mono4 },
    { .posModelID = MODEL_shouhin5, .triggerColliderID = COLLIDER_mono5 },
    { .posModelID = MODEL_shouhin6, .triggerColliderID = COLLIDER_mono6 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_Toad_01,
    .idleAnim = ANIM_HarryT_Idle,
    .talkAnim = ANIM_HarryT_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), ITEM_ENTITY_FLAGS_10000)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};
