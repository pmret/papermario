#include "dro_01.h"
#define NAMESPACE dro_01_Shop

s32 N(ShopMessages)[] = {
    MSG_Shop_0049,
    MSG_Shop_004A,
    MSG_Shop_004B,
    MSG_Shop_004C,
    MSG_Shop_004D,
    MSG_Shop_004E,
    MSG_Shop_004F,
    MSG_Shop_0050,
    MSG_Shop_0051,
    MSG_Shop_0052,
    MSG_Shop_0053,
    MSG_Shop_0054,
    MSG_Shop_0055,
    MSG_Shop_0056,
    MSG_Shop_0057,
    MSG_Shop_0058,
    MSG_Shop_0059,
    MSG_Shop_005A,
    MSG_Shop_005B,
    MSG_Shop_005C,
    MSG_Shop_005D,
    MSG_Shop_005E,
    MSG_Shop_005F,
};

ShopItemData N(Inventory)[] = {
    { .itemID = ITEM_THUNDER_BOLT, .price = 5, .descMsg = MSG_ItemShopDesc_ThunderBolt },
    { .itemID = ITEM_DUSTY_HAMMER, .price = 2, .descMsg = MSG_ItemShopDesc_DustyHammer },
    { .itemID = ITEM_HONEY_SYRUP,  .price = 5, .descMsg = MSG_ItemShopDesc_HoneySyrup },
    { .itemID = ITEM_DRIED_SHROOM, .price = 2, .descMsg = MSG_ItemShopDesc_DriedShroom },
    { .itemID = ITEM_DRIED_PASTA,  .price = 3, .descMsg = MSG_ItemShopDesc_DriedPasta },
    { .itemID = ITEM_MUSHROOM,     .price = 3, .descMsg = MSG_ItemShopDesc_Mushroom },
    {},
};

ShopSellPriceData N(PriceList)[] = {
    { .itemID = ITEM_SNOWMAN_DOLL,  .sellPrice = 12 },
    { .itemID = ITEM_MELON,         .sellPrice = 10 },
    { .itemID = ITEM_ICED_POTATO,   .sellPrice = 10 },
    { .itemID = ITEM_TASTY_TONIC,   .sellPrice = 5 },
    { .itemID = ITEM_SUPER_SODA,    .sellPrice = 6 },
    { .itemID = ITEM_SPECIAL_SHAKE, .sellPrice = 15 },
    { .itemID = ITEM_DRIED_PASTA,   .sellPrice = 2 },
    {},
};

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(HideCoinCounter)) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_JumpToPlayer) = {
    EVT_CALL(NpcJump0, NPC_Mouser_ShopOwner, -31, 0, -283, 10)
    EVT_CALL(NpcJump0, NPC_Mouser_ShopOwner, -30, 0, -283, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JumpAway) = {
    EVT_CALL(NpcJump0, NPC_Mouser_ShopOwner, 20, 0, -259, 10)
    EVT_CALL(NpcJump0, NPC_Mouser_ShopOwner, 20, 0, -259, 4)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SecretPurcahseOrder_Moustafa) = {
    EVT_CALL(N(HideCoinCounter))
    EVT_CALL(func_802D2C14, 1)
    EVT_EXEC_WAIT(N(EVS_JumpToPlayer))
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
        EVT_CALL(SpeakToPlayer, NPC_Mouser_ShopOwner, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0087)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Mouser_ShopOwner, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
    EVT_SET(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
    EVT_CALL(func_802D2C14, 0)
    EVT_EXEC_WAIT(N(EVS_JumpAway))
    EVT_END_IF // @bug unmatched endif in script
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SecretPurcahseOrder_RedJar) = {
    EVT_IF_EQ(GF_DRO01_Gift_RedJar, FALSE)
        EVT_CALL(N(HideCoinCounter))
        EVT_CALL(func_802D2C14, 1)
        EVT_EXEC_WAIT(N(EVS_JumpToPlayer))
        EVT_CALL(SpeakToPlayer, NPC_Mouser_ShopOwner, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_008D)
        EVT_GIVE_KEY_REWARD(ITEM_KOOT_RED_JAR)
        EVT_SET(GF_DRO01_Gift_RedJar, TRUE)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(EVS_JumpAway))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

enum {
    SEQ_NONE            = 0,
    SEQ_DRIED_SHOOM     = 1,
    SEQ_DUSTY_HAMMER    = 2,
    SEQ_DRIED_PASTA     = 3,
};

EvtScript N(EVS_OnBuy) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, AB_DRO_SHOP_PREV1)
            EVT_SET(LVar3, AB_DRO_SHOP_PREV2)
            EVT_SET(LVar4, AB_DRO_SHOP_PREV3)
            EVT_SET(AB_DRO_SHOP_PREV2, LVar2)
            EVT_SET(AB_DRO_SHOP_PREV3, LVar3)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(ITEM_DRIED_SHROOM)
                    // Dusty Hammer, Dried Pasta, Dusty Hammer, Dried Shroom -> Red jar
                    EVT_SET(AB_DRO_SHOP_PREV1, SEQ_DRIED_SHOOM)
                    EVT_IF_EQ(LVar2, SEQ_DUSTY_HAMMER)
                        EVT_IF_EQ(LVar3, SEQ_DRIED_PASTA)
                            EVT_IF_EQ(LVar4, SEQ_DUSTY_HAMMER)
                                EVT_EXEC_WAIT(N(EVS_SecretPurcahseOrder_RedJar))
                                EVT_SET(AB_DRO_SHOP_PREV1, SEQ_NONE)
                            EVT_END_IF
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(ITEM_DUSTY_HAMMER)
                    // Dried Shroom, Dusty Hammer -> Moustafa information
                    EVT_SET(AB_DRO_SHOP_PREV1, SEQ_DUSTY_HAMMER)
                    EVT_IF_EQ(LVar2, SEQ_DRIED_SHOOM)
                        EVT_IF_LT(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
                            EVT_EXEC_WAIT(N(EVS_SecretPurcahseOrder_Moustafa))
                            EVT_SET(AB_DRO_SHOP_PREV1, SEQ_NONE)
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(ITEM_DRIED_PASTA)
                    EVT_SET(AB_DRO_SHOP_PREV1, SEQ_DRIED_PASTA)
                EVT_CASE_DEFAULT
                    EVT_SET(AB_DRO_SHOP_PREV1, SEQ_NONE)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

ShopItemLocation N(ItemPositions)[] = {
    { .posModelID = MODEL_o741, .triggerColliderID = COLLIDER_mono1 },
    { .posModelID = MODEL_o740, .triggerColliderID = COLLIDER_mono2 },
    { .posModelID = MODEL_o738, .triggerColliderID = COLLIDER_mono3 },
    { .posModelID = MODEL_o739, .triggerColliderID = COLLIDER_mono4 },
    { .posModelID = MODEL_o737, .triggerColliderID = COLLIDER_mono5 },
    { .posModelID = MODEL_o736, .triggerColliderID = COLLIDER_mono6 },
};

ShopOwner N(Owner) = {
    .npcID = NPC_Mouser_ShopOwner,
    .idleAnim = ANIM_Mouser_Purple_Idle,
    .talkAnim = ANIM_Mouser_Purple_Talk,
    .onBuyEvt = &N(EVS_OnBuy),
    .shopMsgIDs = N(ShopMessages),
};

#define NAMESPACE dro_01
