#include "mac_00.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_MAC00,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_MAC00,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_MAC00,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_MAC00,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_MAC00,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_MAC00,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_MAC00,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_MAC00,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_MAC00,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_MAC00,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_MAC00,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_MAC00,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_MAC00,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_MAC00,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_MAC00,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_MAC00,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_MAC00,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_MAC00,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_MAC00,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_MAC00,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_MAC00,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_MAC00,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_MAC00,
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
    { .itemID = ITEM_DRIED_SHROOM,  .sellPrice =  3 },
    { .itemID = ITEM_DRIED_PASTA,   .sellPrice =  5 },
    { .itemID = ITEM_DUSTY_HAMMER,  .sellPrice =  3 },
    { .itemID = ITEM_WHACKAS_BUMP,  .sellPrice = 64 },
    { .itemID = ITEM_DRIED_FRUIT,   .sellPrice = 20 },
    { .itemID = ITEM_LIME,          .sellPrice =  4 },
    { .itemID = ITEM_LEMON,         .sellPrice =  4 },
    {}
};

EvtScript N(EVS_OnBuy) = {
    Switch(LVar0)
        CaseEq(SHOP_BUY_RESULT_CANCEL)
        CaseEq(SHOP_BUY_RESULT_4)
        CaseEq(SHOP_BUY_RESULT_OK)
        CaseEq(SHOP_BUY_RESULT_2)
    EndSwitch
    Return
    End
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
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), ITEM_ENTITY_FLAG_TOSS_LOWER)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
