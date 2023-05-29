#include "mac_04.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_MAC04,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_MAC04,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_MAC04,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_MAC04,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_MAC04,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_MAC04,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_MAC04,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_MAC04,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_MAC04,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_MAC04,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_MAC04,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_MAC04,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_MAC04,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_MAC04,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_MAC04,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_MAC04,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_MAC04,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_MAC04,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_MAC04,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_MAC04,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_MAC04,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_MAC04,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_MAC04,
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
        EVT_CASE_EQ(SHOP_BUY_RESULT_CANCEL)
        EVT_CASE_EQ(SHOP_BUY_RESULT_4)
        EVT_CASE_EQ(SHOP_BUY_RESULT_OK)
        EVT_CASE_EQ(SHOP_BUY_RESULT_OK) //@bug duplicate case
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
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), ITEM_ENTITY_FLAG_TOSS_LOWER)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};
