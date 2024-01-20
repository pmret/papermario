#include "obk_03.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_OBK03,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_OBK03,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_OBK03,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_OBK03,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_OBK03,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_OBK03,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_OBK03,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_OBK03,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_OBK03,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_OBK03,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_OBK03,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_OBK03,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_OBK03,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_OBK03,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_OBK03,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_OBK03,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_OBK03,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_OBK03,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_OBK03,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_OBK03,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_OBK03,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_OBK03,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_OBK03,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_MYSTERY,       .price = 1,  .descMsg = MSG_ItemShopDesc_Mystery },
    { .itemID = ITEM_STOP_WATCH,    .price = 25, .descMsg = MSG_ItemShopDesc_StopWatch },
    { .itemID = ITEM_SNOWMAN_DOLL,  .price = 15, .descMsg = MSG_ItemShopDesc_SnowmanDoll },
    { .itemID = ITEM_MAPLE_SYRUP,   .price = 25, .descMsg = MSG_ItemShopDesc_MapleSyrup },
    { .itemID = ITEM_LIFE_SHROOM,   .price = 50, .descMsg = MSG_ItemShopDesc_LifeShroom },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 13, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_DUSTY_HAMMER,  .sellPrice = 4 },
    { .itemID = ITEM_DRIED_SHROOM,  .sellPrice = 3 },
    { .itemID = ITEM_MISTAKE,       .sellPrice = 5 },
    { .itemID = ITEM_JELLY_ULTRA,   .sellPrice = 200 },
    { .itemID = ITEM_STINKY_HERB,   .sellPrice = 5 },
    {}
};

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_o354, .triggerColliderID = COLLIDER_o485 },
    { .posModelID = MODEL_o355, .triggerColliderID = COLLIDER_o486 },
    { .posModelID = MODEL_o356, .triggerColliderID = COLLIDER_o487 },
    { .posModelID = MODEL_o357, .triggerColliderID = COLLIDER_o488 },
    { .posModelID = MODEL_o358, .triggerColliderID = COLLIDER_o489 },
    { .posModelID = MODEL_o359, .triggerColliderID = COLLIDER_o490 },
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

ShopOwner N(Owner) = {
    .npcID = NPC_Igor,
    .idleAnim = ANIM_Boo_Idle,
    .talkAnim = ANIM_Boo_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    IfGe(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o485, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o486, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o487, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o488, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o489, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o490, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeShop, Ref(N(ItemPositions)), Ref(N(Inventory)), Ref(N(PriceList)), 0)
    Call(MakeShopOwner, Ref(N(Owner)))
    Return
    End
};
