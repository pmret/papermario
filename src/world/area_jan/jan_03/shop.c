#include "jan_03.h"
#include "sprite/npc/Yoshi.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_JAN03,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_JAN03,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_JAN03,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_JAN03,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_JAN03,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_JAN03,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_JAN03,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_JAN03,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_JAN03,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_JAN03,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_JAN03,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_JAN03,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_JAN03,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_JAN03,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_JAN03,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_JAN03,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_JAN03,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_JAN03,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_JAN03,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_JAN03,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_JAN03,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_JAN03,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_JAN03,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_SNOWMAN_DOLL,  .price = 15, MSG_ItemShopDesc_SnowmanDoll },
    { .itemID = ITEM_THUNDER_RAGE,  .price = 15, MSG_ItemShopDesc_ThunderRage },
    { .itemID = ITEM_FIRE_FLOWER,   .price =  5, MSG_ItemShopDesc_FireFlower },
    { .itemID = ITEM_TASTY_TONIC,   .price =  2, MSG_ItemShopDesc_TastyTonic },
    { .itemID = ITEM_HONEY_SYRUP,   .price =  6, MSG_ItemShopDesc_HoneySyrup },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 15, MSG_ItemShopDesc_SuperShroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_SNOWMAN_DOLL,  .sellPrice = 10 },
    { .itemID = ITEM_SUPER_SODA,    .sellPrice =  7 },
    { .itemID = ITEM_ICED_POTATO,   .sellPrice = 10 },
    { .itemID = ITEM_YOSHI_COOKIE,  .sellPrice = 30 },
    { .itemID = ITEM_BUBBLE_BERRY,  .sellPrice =  5 },
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
    { .posModelID = MODEL_o363, .triggerColliderID = COLLIDER_o391 },
    { .posModelID = MODEL_o364, .triggerColliderID = COLLIDER_o392 },
    { .posModelID = MODEL_o365, .triggerColliderID = COLLIDER_o393 },
    { .posModelID = MODEL_o366, .triggerColliderID = COLLIDER_o394 },
    { .posModelID = MODEL_o367, .triggerColliderID = COLLIDER_o395 },
    { .posModelID = MODEL_o368, .triggerColliderID = COLLIDER_o396 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_Yoshi_01,
    .idleAnim = ANIM_Yoshi_Blue_Idle,
    .talkAnim = ANIM_Yoshi_Blue_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    Call(EnableGroup, MODEL_g126, FALSE)
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), ITEM_ENTITY_FLAG_TOSS_LOWER)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
