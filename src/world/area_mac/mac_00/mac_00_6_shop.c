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

ShopItemData N(D_8024E26C_7F8F7C)[] = {
    { .itemID = ITEM_FRIGHT_JAR,    .price =  5, .descMsg = 0x0024002A },
    { .itemID = ITEM_SLEEPY_SHEEP,  .price = 10, .descMsg = 0x00240026 },
    { .itemID = ITEM_POW_BLOCK,     .price =  5, .descMsg = 0x00240027 },
    { .itemID = ITEM_FIRE_FLOWER,   .price = 10, .descMsg = 0x00240000 },
    { .itemID = ITEM_HONEY_SYRUP,   .price = 10, .descMsg = 0x00240016 },
    { .itemID = ITEM_MUSHROOM,      .price =  5, .descMsg = 0x00240009 },
    {}
};

ShopSellPriceData N(D_8024E2C0_7F8FD0)[] = {
    { .itemID = ITEM_DRIED_SHROOM,  .sellPrice = 3 },
    { .itemID = ITEM_DRIED_PASTA,   .sellPrice = 5 },
    { .itemID = ITEM_DUSTY_HAMMER,  .sellPrice = 3 },
    { .itemID = ITEM_WHACKAS_BUMP,  .sellPrice = 64 },
    { .itemID = ITEM_DRIED_FRUIT,   .sellPrice = 20 },
    { .itemID = ITEM_LIME,          .sellPrice = 4 },
    { .itemID = ITEM_LEMON,         .sellPrice = 4 },
    {}
};

EvtScript N(D_8024E320_7F9030) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopItemLocation N(D_8024E374_7F9084)[] = {
    { .posModelID = MODEL_syouhin1, .triggerColliderID = COLLIDER_mono1 },
    { .posModelID = MODEL_syouhin2, .triggerColliderID = COLLIDER_mono2 },
    { .posModelID = MODEL_shouhin3, .triggerColliderID = COLLIDER_mono3 },
    { .posModelID = MODEL_shouhin4, .triggerColliderID = COLLIDER_mono4 },
    { .posModelID = MODEL_shouhin5, .triggerColliderID = COLLIDER_mono5 },
    { .posModelID = MODEL_shouhin6, .triggerColliderID = COLLIDER_mono6 },
};

ShopOwner N(D_8024E38C_7F909C) = {
    .npcID = 1,
    .idleAnim = 0x00880001,
    .talkAnim = 0x00880004,
    .onBuyEvt = &N(D_8024E320_7F9030),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(MakeShop, EVT_PTR(N(D_8024E374_7F9084)), EVT_PTR(N(D_8024E26C_7F8F7C)), EVT_PTR(N(D_8024E2C0_7F8FD0)), 0x00010000)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(D_8024E38C_7F909C)))
    EVT_RETURN
    EVT_END
};
