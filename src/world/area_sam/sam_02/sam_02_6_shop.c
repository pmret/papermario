#include "sam_02.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_SAM02,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_SAM02,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_SAM02,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_SAM02,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_SAM02,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_SAM02,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_SAM02,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_SAM02,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_SAM02,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_SAM02,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_SAM02,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_SAM02,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_SAM02,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_SAM02,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_SAM02,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_SAM02,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_SAM02,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_SAM02,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_SAM02,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_SAM02,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_SAM02,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_SAM02,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_SAM02,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_DIZZY_DIAL,    .price = 15, .descMsg = MSG_ItemShopDesc_DizzyDial },
    { .itemID = ITEM_SHOOTING_STAR, .price = 30, .descMsg = MSG_ItemShopDesc_ShootingStar },
    { .itemID = ITEM_SNOWMAN_DOLL,  .price =  8, .descMsg = MSG_ItemShopDesc_SnowmanDoll },
    { .itemID = ITEM_MAPLE_SYRUP,   .price = 20, .descMsg = MSG_ItemShopDesc_MapleSyrup },
    { .itemID = ITEM_LIFE_SHROOM,   .price = 40, .descMsg = MSG_ItemShopDesc_LifeShroom },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 20, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {},
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_FIRE_FLOWER,  .sellPrice =  8 },
    { .itemID = ITEM_BLAND_MEAL,   .sellPrice = 15 },
    { .itemID = ITEM_YUMMY_MEAL,   .sellPrice = 20 },
    { .itemID = ITEM_DELUXE_FEAST, .sellPrice = 70 },
    { .itemID = ITEM_FROZEN_FRIES, .sellPrice = 18 },
    { .itemID = ITEM_POTATO_SALAD, .sellPrice = 10 },
    {},
};

s32 N(UnknownData)[] = {
    ITEM_FIRE_FLOWER,     5,
    ITEM_SNOWMAN_DOLL,    5,
    ITEM_THUNDER_RAGE,    5,
    ITEM_SHOOTING_STAR,  10,
    ITEM_DUSTY_HAMMER,    3,
    ITEM_PEBBLE,          3,
    ITEM_STONE_CAP,       5,
    ITEM_VOLT_SHROOM,    ITEM_VOLT_SHROOM,
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
    { .posModelID = MODEL_1, .triggerColliderID = COLLIDER_o433 },
    { .posModelID = MODEL_2, .triggerColliderID = COLLIDER_o434 },
    { .posModelID = MODEL_3, .triggerColliderID = COLLIDER_o435 },
    { .posModelID = MODEL_4, .triggerColliderID = COLLIDER_o436 },
    { .posModelID = MODEL_5, .triggerColliderID = COLLIDER_o437 },
    { .posModelID = MODEL_6, .triggerColliderID = COLLIDER_o438 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_Penguin_ShopOwner,
    .idleAnim = ANIM_Penguin_Idle,
    .talkAnim = ANIM_Penguin_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o512, COLLIDER_FLAGS_UPPER_MASK)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o433, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o434, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o435, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o436, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o437, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o438, COLLIDER_FLAGS_UPPER_MASK)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o512, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), ITEM_ENTITY_FLAG_TOSS_LOWER)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
