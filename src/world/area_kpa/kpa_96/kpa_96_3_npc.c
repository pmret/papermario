#include "kpa_96.h"

s32 N(ShopMessages)[] = {
    [SHOP_MSG_BUY_CONFIRM      ] MSG_Shop_00_KPA96,
    [SHOP_MSG_NOT_ENOUGH_COINS ] MSG_Shop_01_KPA96,
    [SHOP_MSG_NOT_ENOUGH_ROOM  ] MSG_Shop_02_KPA96,
    [SHOP_MSG_BUY_THANK_YOU    ] MSG_Shop_03_KPA96,
    [SHOP_MSG_GREETING         ] MSG_Shop_04_KPA96,
    [SHOP_MSG_INSTRUCTIONS     ] MSG_Shop_05_KPA96,
    [SHOP_MSG_NOTHING_TO_SELL  ] MSG_Shop_06_KPA96,
    [SHOP_MSG_SELL_WHICH       ] MSG_Shop_07_KPA96,
    [SHOP_MSG_SELL_CONFIRM     ] MSG_Shop_08_KPA96,
    [SHOP_MSG_SELL_CANCEL      ] MSG_Shop_09_KPA96,
    [SHOP_MSG_SELL_MORE        ] MSG_Shop_0A_KPA96,
    [SHOP_MSG_SELL_THANKS      ] MSG_Shop_0B_KPA96,
    [SHOP_MSG_NOTHING_TO_CHECK ] MSG_Shop_0C_KPA96,
    [SHOP_MSG_NO_CHECK_ROOM    ] MSG_Shop_0D_KPA96,
    [SHOP_MSG_CHECK_WHICH      ] MSG_Shop_0E_KPA96,
    [SHOP_MSG_CHECK_ACCEPTED   ] MSG_Shop_0F_KPA96,
    [SHOP_MSG_CHECK_MORE       ] MSG_Shop_10_KPA96,
    [SHOP_MSG_NOTHING_TO_CLAIM ] MSG_Shop_11_KPA96,
    [SHOP_MSG_NO_CLAIM_ROOM    ] MSG_Shop_12_KPA96,
    [SHOP_MSG_CLAIM_WHICH      ] MSG_Shop_13_KPA96,
    [SHOP_MSG_CLAIM_ACCEPTED   ] MSG_Shop_14_KPA96,
    [SHOP_MSG_CLAIM_MORE       ] MSG_Shop_15_KPA96,
    [SHOP_MSG_FAREWELL         ] MSG_Shop_16_KPA96,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_MYSTERY,       .price =  5, .descMsg = MSG_ItemShopDesc_Mystery },
    { .itemID = ITEM_DIZZY_DIAL,    .price = 25, .descMsg = MSG_ItemShopDesc_DizzyDial },
    { .itemID = ITEM_POW_BLOCK,     .price = 15, .descMsg = MSG_ItemShopDesc_POWBlock },
    { .itemID = ITEM_THUNDER_RAGE,  .price = 30, .descMsg = MSG_ItemShopDesc_ThunderRage },
    { .itemID = ITEM_MAPLE_SYRUP,   .price = 30, .descMsg = MSG_ItemShopDesc_MapleSyrup },
    { .itemID = ITEM_SUPER_SHROOM,  .price = 30, .descMsg = MSG_ItemShopDesc_SuperShroom },
    {}
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_FRIGHT_JAR,    .sellPrice = 15 },
    { .itemID = ITEM_EGG_MISSILE,   .sellPrice = 30 },
    { .itemID = ITEM_PEBBLE,        .sellPrice = 20 },
    { .itemID = ITEM_MISTAKE,       .sellPrice = 20 },
    { .itemID = ITEM_LIFE_SHROOM,   .sellPrice = 25 },
    { .itemID = ITEM_SHOOTING_STAR, .sellPrice = 20 },
    { .itemID = ITEM_SUPER_SODA,    .sellPrice = 10 },
    { .itemID = ITEM_STOP_WATCH,    .sellPrice = 20 },
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
    { .posModelID = MODEL_o831, .triggerColliderID = COLLIDER_o865 },
    { .posModelID = MODEL_o832, .triggerColliderID = COLLIDER_o864 },
    { .posModelID = MODEL_o833, .triggerColliderID = COLLIDER_o863 },
    { .posModelID = MODEL_o834, .triggerColliderID = COLLIDER_o862 },
    { .posModelID = MODEL_o835, .triggerColliderID = COLLIDER_o861 },
    { .posModelID = MODEL_o836, .triggerColliderID = COLLIDER_o860 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_SpikedGoomba,
    .idleAnim = ANIM_SpikedGoomba_Idle,
    .talkAnim = ANIM_SpikedGoomba_Walk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

EvtScript N(EVS_SetupShop) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o860, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o861, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o862, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o863, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o864, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o865, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeShop, EVT_PTR(N(ItemPositions)), EVT_PTR(N(Inventory)), EVT_PTR(N(PriceList)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Owner)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpikedGoomba) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

API_CALLABLE(N(CheckPlayerHasCoins)) {
    if (gPlayerData.coins > 0) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_SpikedGoomba) = {
    EVT_IF_EQ(MV_MetShopkeeper, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_SpikedGoomba_Walk, ANIM_SpikedGoomba_Idle, 0, MSG_CH8_004F)
        EVT_CALL(ShowChoice, MSG_Choice_0013)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(N(CheckPlayerHasCoins))
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_SpikedGoomba_Walk, ANIM_SpikedGoomba_Idle, 0, MSG_CH8_0051)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o860, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o861, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o862, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o863, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o864, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o865, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o964, COLLIDER_FLAGS_UPPER_MASK)
                EVT_SET(MV_MetShopkeeper, 1)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_SpikedGoomba_Walk, ANIM_SpikedGoomba_Idle, 0, MSG_CH8_0052)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_SpikedGoomba_Walk, ANIM_SpikedGoomba_Idle, 0, MSG_CH8_0050)
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_SpikedGoomba) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_SpikedGoomba)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { -122.0f, 0.0f, 163.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_SpikedGoomba),
    .settings = &N(NpcSettings_SpikedGoomba),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_SpikedGoomba_Idle,
        .walk   = ANIM_SpikedGoomba_Walk,
        .run    = ANIM_SpikedGoomba_Run,
        .chase  = ANIM_SpikedGoomba_Run,
        .anim_4 = ANIM_SpikedGoomba_Idle,
        .anim_5 = ANIM_SpikedGoomba_Idle,
        .death  = ANIM_SpikedGoomba_HurtStill,
        .hit    = ANIM_SpikedGoomba_HurtStill,
        .anim_8 = ANIM_SpikedGoomba_Run,
        .anim_9 = ANIM_SpikedGoomba_Run,
        .anim_A = ANIM_SpikedGoomba_Run,
        .anim_B = ANIM_SpikedGoomba_Run,
        .anim_C = ANIM_SpikedGoomba_Run,
        .anim_D = ANIM_SpikedGoomba_Run,
        .anim_E = ANIM_SpikedGoomba_Run,
        .anim_F = ANIM_SpikedGoomba_Run,
    },
    .tattle = MSG_NpcTattle_KPA_ShopOwner,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGoomba)),
    {}
};
