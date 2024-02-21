#include "hos_03.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_HOS03,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_HOS03,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_HOS03,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_HOS03,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_HOS03,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_HOS03,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_HOS03,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_HOS03,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_HOS03,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_HOS03,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_HOS03,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_HOS03,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_HOS03,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_HOS03,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_HOS03,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_HOS03,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_HOS03,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_HOS03,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_HOS03,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_HOS03,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_HOS03,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_HOS03,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_HOS03,
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
    { .posModelID = MODEL_o121, .triggerColliderID = COLLIDER_o203 },
    { .posModelID = MODEL_o122, .triggerColliderID = COLLIDER_o204 },
    { .posModelID = MODEL_o123, .triggerColliderID = COLLIDER_o205 },
    { .posModelID = MODEL_o124, .triggerColliderID = COLLIDER_o206 },
    { .posModelID = MODEL_o125, .triggerColliderID = COLLIDER_o207 },
    { .posModelID = MODEL_o126, .triggerColliderID = COLLIDER_o208 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_StarMan_ShopOwner,
    .idleAnim = ANIM_StarMan_Idle,
    .talkAnim = ANIM_StarMan_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), 0)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
