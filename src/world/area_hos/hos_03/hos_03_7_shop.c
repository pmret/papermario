#include "hos_03.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_00] MSG_Shop_00_HOS03,
    [SHOP_MSG_01] MSG_Shop_01_HOS03,
    [SHOP_MSG_02] MSG_Shop_02_HOS03,
    [SHOP_MSG_03] MSG_Shop_03_HOS03,
    [SHOP_MSG_04] MSG_Shop_04_HOS03,
    [SHOP_MSG_05] MSG_Shop_05_HOS03,
    [SHOP_MSG_06] MSG_Shop_06_HOS03,
    [SHOP_MSG_07] MSG_Shop_07_HOS03,
    [SHOP_MSG_08] MSG_Shop_08_HOS03,
    [SHOP_MSG_09] MSG_Shop_09_HOS03,
    [SHOP_MSG_0A] MSG_Shop_0A_HOS03,
    [SHOP_MSG_0B] MSG_Shop_0B_HOS03,
    [SHOP_MSG_0C] MSG_Shop_0C_HOS03,
    [SHOP_MSG_0D] MSG_Shop_0D_HOS03,
    [SHOP_MSG_0E] MSG_Shop_0E_HOS03,
    [SHOP_MSG_0F] MSG_Shop_0F_HOS03,
    [SHOP_MSG_10] MSG_Shop_10_HOS03,
    [SHOP_MSG_11] MSG_Shop_11_HOS03,
    [SHOP_MSG_12] MSG_Shop_12_HOS03,
    [SHOP_MSG_13] MSG_Shop_13_HOS03,
    [SHOP_MSG_14] MSG_Shop_14_HOS03,
    [SHOP_MSG_15] MSG_Shop_15_HOS03,
    [SHOP_MSG_16] MSG_Shop_16_HOS03,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_STOP_WATCH,    .price = 15, .descMsg = MSG_ItemShopDesc_StopWatch },
    { .itemID = ITEM_SHOOTING_STAR, .price = 15, .descMsg = MSG_ItemShopDesc_ShootingStar },
    { .itemID = ITEM_SUPER_SODA,    .price =  3, .descMsg = MSG_ItemShopDesc_SuperSoda },
    { .itemID = ITEM_MAPLE_SYRUP,   .price = 10, .descMsg = MSG_ItemShopDesc_MapleSyrup },
    { .itemID = ITEM_LIFE_SHROOM,   .price = 25, .descMsg = MSG_ItemShopDesc_LifeShroom },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 10, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {},
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_DRIED_PASTA,   .sellPrice =  7 },
    { .itemID = ITEM_THUNDER_RAGE,  .sellPrice = 15 },
    { .itemID = ITEM_SHOOTING_STAR, .sellPrice = 14 },
    { .itemID = ITEM_HONEY_SHROOM,  .sellPrice = 15 },
    { .itemID = ITEM_SLEEPY_SHEEP,  .sellPrice = 10 },
    { .itemID = ITEM_CAKE,          .sellPrice = 15 },
    { .itemID = ITEM_STOP_WATCH,    .sellPrice = 14 },
    { .itemID = ITEM_KOOPASTA,      .sellPrice = 15 },
    { .itemID = ITEM_SHROOM_CAKE,   .sellPrice = 30 },
    { .itemID = ITEM_SWEET_SHROOM,  .sellPrice = 70 },
    {},
};

EvtScript N(EVS_OnBuy) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(SHOP_BUY_RESULT_CANCEL)
        EVT_CASE_EQ(SHOP_BUY_RESULT_4)
        EVT_CASE_EQ(SHOP_BUY_RESULT_OK)
        EVT_CASE_EQ(SHOP_BUY_RESULT_2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_o121, .triggerColliderID = COLLIDER_o203 },
    { .posModelID = MODEL_o122, .triggerColliderID = COLLIDER_o204 },
    { .posModelID = MODEL_o123, .triggerColliderID = COLLIDER_o205 },
    { .posModelID = MODEL_o124, .triggerColliderID = COLLIDER_o206 },
    { .posModelID = MODEL_o125, .triggerColliderID = COLLIDER_o207 },
    { .posModelID = MODEL_o126, .triggerColliderID = COLLIDER_o208 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_StarKid_ShopOwner,
    .idleAnim = ANIM_StarMan_Idle,
    .talkAnim = ANIM_StarMan_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};
