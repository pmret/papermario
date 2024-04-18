#include "nok_01.h"
#include "sprite/npc/Koopa.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_NOK01,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_NOK01,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_NOK01,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_NOK01,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_NOK01,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_NOK01,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_NOK01,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_NOK01,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_NOK01,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_NOK01,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_NOK01,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_NOK01,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_NOK01,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_NOK01,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_NOK01,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_NOK01,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_NOK01,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_NOK01,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_NOK01,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_NOK01,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_NOK01,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_NOK01,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_NOK01,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_DIZZY_DIAL,   .price = 10, MSG_ItemShopDesc_DizzyDial },
    { .itemID = ITEM_POW_BLOCK,    .price =  4, MSG_ItemShopDesc_POWBlock },
    { .itemID = ITEM_FIRE_FLOWER,  .price =  8, MSG_ItemShopDesc_FireFlower },
    { .itemID = ITEM_HONEY_SYRUP,  .price =  8, MSG_ItemShopDesc_HoneySyrup },
    { .itemID = ITEM_VOLT_SHROOM,  .price = 15, MSG_ItemShopDesc_VoltShroom },
    { .itemID = ITEM_MUSHROOM,     .price =  4, MSG_ItemShopDesc_Mushroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_KOOPASTA,       .sellPrice = 12 },
    { .itemID = ITEM_KOOPA_TEA,      .sellPrice =  4 },
    { .itemID = ITEM_KOOKY_COOKIE,   .sellPrice = 15 },
    { .itemID = ITEM_SPECIAL_SHAKE,  .sellPrice = 12 },
    { .itemID = ITEM_BLAND_MEAL,     .sellPrice = 12 },
    { .itemID = ITEM_SUPER_SODA,     .sellPrice =  5 },
    { .itemID = ITEM_LIFE_SHROOM,    .sellPrice = 30 },
    {}
};

s32 N(missing_8024FC20_FC20)[] = {
    ITEM_FIRE_FLOWER,    5,
    ITEM_SNOWMAN_DOLL,   5,
    ITEM_THUNDER_RAGE,   5,
    ITEM_SHOOTING_STAR, 10,
    ITEM_DUSTY_HAMMER,   3,
    ITEM_PEBBLE,         3,
    ITEM_STONE_CAP,      5,
    ITEM_VOLT_SHROOM,    5,
    ITEM_VOLT_SHROOM,    5,
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
    { .posModelID = MODEL_o213, .triggerColliderID = COLLIDER_o343 },
    { .posModelID = MODEL_o214, .triggerColliderID = COLLIDER_o344 },
    { .posModelID = MODEL_o215, .triggerColliderID = COLLIDER_o345 },
    { .posModelID = MODEL_o216, .triggerColliderID = COLLIDER_o346 },
    { .posModelID = MODEL_o217, .triggerColliderID = COLLIDER_o347 },
    { .posModelID = MODEL_o218, .triggerColliderID = COLLIDER_o348 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_Koopa_ShopOwner,
    .idleAnim = ANIM_Koopa_Idle,
    .talkAnim = ANIM_Koopa_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), ITEM_ENTITY_FLAG_TOSS_LOWER)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
