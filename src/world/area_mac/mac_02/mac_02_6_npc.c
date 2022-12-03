#include "mac_02.h"

MobileAISettings N(D_80245F40_829200) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Toad_01) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80245F40_829200)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Toad_01) = {
    .height = 30,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_Toad_01),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(80245FBC) = {
    .height = 23,
    .radius = 19,
    .level = 99,
    .ai = &N(EVS_NpcAI_Toad_01),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(D_80245FE8_8292A8) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(D_80246018_8292D8) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(D_80245FE8_8292A8)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(80246038) = {
    .height = 30,
    .radius = 24,
    .level = 99,
    .ai = &N(D_80246018_8292D8),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(80246064) = {
    .height = 23,
    .radius = 19,
    .level = 99,
    .ai = &N(D_80246018_8292D8),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_TayceT) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(802460BC) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

NpcSettings N(NpcSettings_Bootler) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtScript N(EVS_NpcAuxAI_Bubulb) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bubulb) = {
    .height = 42,
    .radius = 26,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_Bubulb),
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

s32 D_80248A98_82BD58[] = {
    138, 140, 142, 149, 139, 128, 172, 157, 
    156, 164, 163, 162, 148, 159, 158, 160, 
    165, 166, 167, 168, 169, 170, 171, 173, 
    174, 175, 141, 161, 147, -1 
};

s32 D_80248B10_82BDD0[] = {
    0, 194, 1, 182, 1, 176,  1, 137, 
    1, 214, 1, 195, 1, 199,  4, 154, 
    2, 192, 1, 193, 1, 201,  1, 216, 
    1, 155, 1, 217, 3, 190,  1, 212, 
    1, 213, 1, 185, 2, 189,  1, 202, 
    1, 215, 1, 218, 1, 149,  1, 139, 
    4, 143, 1, 183, 1, 184,  1, 196, 
    1, 197, 1, 198, 2, 187,  1, 178, 
    1, 179, 1, 180, 1, 186,  1, 204, 
    4, 130, 1, 205, 1, 200,  2, 191, 
    1, 207, 3, 188, 1, 206,  1, 208, 
    1, 203, 1, 209, 1, 177,  1, 181, 
    1, 211, 4, 128, 2, 210, -1,  -1
};

s8 D_80248CB0_82BF70[] = {
    0x01, 0x01, 0x1A, 0x11, 0x11, 0x02, 0x03, 0x03, 0x03, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x04, 0x05, 0x06, 0x00, 0x00, 0x09, 0x0A, 0x27, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

s8 D_80248CD0_82BF90[] = {
    0x01, 0x01, 0x1A, 0x11, 0x11, 0x02, 0x03, 0x03, 0x03, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x04, 0x05, 0x06, 0x00, 0x07, 0x09, 0x0A, 0x27, 0x00, 0x10, 0x01, 0x03, 0x1E, 0x00, 0x00, 0x00
};

s8 D_80248CF0_82BFB0[] = {
    0x00, 0x11, 0x1A, 0x1A, 0x11, 0x11, 0x00, 0x00, 0x00, 0x13, 0x14, 0x15, 0x00, 0x00, 0x00, 0x00,
    0x17, 0x17, 0x12, 0x17, 0x17, 0x19, 0x12, 0x00, 0x00, 0x12, 0x01, 0x00, 0x00, 0xFF, 0x00, 0x1A,
    0x1A, 0x11, 0x12, 0x00, 0x00, 0x00, 0x1B, 0x1C, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x16, 0x16, 0x12,
    0x17, 0x16, 0x19, 0x12, 0x00, 0x00, 0x12, 0x11, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x1A, 0x1A, 0x1E,
    0x00, 0x00, 0x00, 0x1F, 0x20, 0x21, 0x00, 0x00, 0x00, 0x00, 0x16, 0x16, 0x1E, 0x17, 0x16, 0x22,
    0x1E, 0x00, 0x00, 0x1E, 0x1A, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
    0x1B, 0x1C, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x16, 0x16, 0x12, 0x17, 0x16, 0x22, 0x12, 0x00, 0x00,
    0x12, 0x1A, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x12, 0x00, 0x00, 0x00, 0x1B, 0x1C, 0x1D,
    0x00, 0x00, 0x00, 0x00, 0x16, 0x16, 0x12, 0x24, 0x07, 0x23, 0x12, 0x00, 0x00, 0x12, 0x11, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x0F, 0x01, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x03, 0x0C, 0x27, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x0C,
    0x12, 0x00, 0x00, 0x28, 0x00, 0x0C, 0x00, 0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x0C, 0x03, 0x0C, 0x27, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x0C, 0x00, 0x00, 0x00,
    0x2A, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x03, 0x0C, 0x27, 0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x27,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0C,
    0x27, 0x03, 0x03, 0x03, 0x03, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x27, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x27, 0x0C, 0x0C,
    0x0C, 0x0C, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x30, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x27, 0x27, 0x27, 0x27, 0x00,
    0x0C, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0C, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x2E, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0C, 0x0C, 0x00, 0x12, 0x12, 0x00, 0x18, 0x08, 0x00,
    0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0C, 0x00, 0x12, 0x12, 0x00, 0x18, 0x08, 0x00, 0x27, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x12, 0x12, 0x00, 0x18, 0x08, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x12, 0x12, 0x00, 0x12, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x2F,
    0x00, 0x00, 0x30, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x1E, 0x12, 0x00,
    0x12, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x32, 0x0B, 0x27, 0x07, 0x1E, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x08, 0x0D, 0x30, 0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0B, 0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
};

s32 D_8024903C_82C2FC[] = {
    191, 141,  41, 191, 169,  41, 191, 174, 
     41, 213, 199,  30, 213, 182,  18, 213, 
    185,  30, 213, 184,  14, 169, 147,  14, 
};

s32 D_8024909C_82C35C[] = {
    128, 137, 155, 143, 149, 154, 139, 182, 
    181, 176, 195, 199, 201, 216, 213, 202, 
    189, 130, 200, 177, 211, 192, 191, 
};

API_CALLABLE(func_80242C44_825F04);
API_CALLABLE(func_80242DBC_82607C);
API_CALLABLE(func_80242F60_826220);
INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242C44_825F04);
INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242DBC_82607C);
INCLUDE_ASM(s32, "world/area_mac/mac_02/823BF0", func_80242F60_826220);
//MAP_DATA_SECTION_START

API_CALLABLE(N(func_80243040_826300)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_count());
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243088_826348)) {
    Bytecode args = *script->ptrReadPos;

    evt_set_variable(script, args++, get_item_empty_count());
    return ApiStatus_DONE2;
}

static s32 N(TayceT_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];

API_CALLABLE(N(func_802430D0_826390)) {
    s32 i;

    for (i = 0; i < 91; i++) {
        N(TayceT_ItemChoiceList)[i] = i + 128;
    }
    N(TayceT_ItemChoiceList)[i] = 0;

    return ApiStatus_DONE2;
}

EvtScript N(D_802490F8_82C3B8) = {
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -220, -425, 30)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Cooking)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Cooking, ANIM_TayceT_Cooking, 5, MSG_MAC_Bridge_000E)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_TurnBack)
    EVT_WAIT(30)
    EVT_CALL(SetNpcYaw, NPC_TayceT, 90)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Walk)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -186, -381, 20)
    EVT_CALL(NpcMoveTo, NPC_TayceT, -236, -318, 20)
    EVT_CALL(SetNpcAnimation, NPC_TayceT, ANIM_TayceT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_TayceT, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_FryingPan)[] = {
    ITEM_FRYING_PAN,
    ITEM_NONE
};

EvtScript N(D_8024926C_82C52C) = {
    EVT_IF_EQ(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_CALL(N(func_80243088_826348), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
            EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
            EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
            EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0017)
    EVT_SET(LVar0, EVT_PTR(N(ItemList_FryingPan)))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_IdleSad, 0, MSG_MAC_Bridge_0018)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_TalkHappy, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0019)
            EVT_EXEC_WAIT(N(D_802490F8_82C3B8))
            EVT_CALL(N(func_80243088_826348), LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001A)
                EVT_GIVE_CONSUMABLE_REWARD_ALT(ITEM_CAKE)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001B)
                EVT_SET(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001C)
                EVT_SET(GF_MAC02_TayceT_HoldingCake, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Cookbook)[] = {
    ITEM_COOKBOOK,
    ITEM_NONE 
};

EvtScript N(D_80249550_82C810) = {
    EVT_IF_EQ(AF_MAC_01, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001D)
        EVT_SET(AF_MAC_01, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001E)
        EVT_SET(AF_MAC_01, FALSE)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Cookbook)))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_001F)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0020)
            EVT_SET(GF_MAC02_TayceT_HasCookbook, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249684_82C944) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_MAC02_Met_TayceT, FALSE)
        EVT_SET(GF_MAC02_Met_TayceT, TRUE)
        EVT_SET(AF_MAC_01, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0000)
    EVT_ELSE
        EVT_IF_EQ(AF_MAC_01, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0001)
            EVT_SET(AF_MAC_01, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(func_80243040_826300), LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0003)
        EVT_GOTO(9)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
        EVT_GOTO(9)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0005)
    EVT_LABEL(1)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(func_802430D0_826390))
    EVT_SET(LVar0, N(TayceT_ItemChoiceList))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0006)
            EVT_CALL(ShowChoice, MSG_Choice_0009)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(9)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar8, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC02_TayceT_HasCookbook, FALSE)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_CALL(N(func_80243040_826300), LVar0)
    EVT_IF_LT(LVar0, 2)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0007)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_LABEL(2)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_SET(LVar3, 0)
    EVT_CALL(N(func_802430D0_826390))
    EVT_SET(LVar0, N(TayceT_ItemChoiceList))
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(N(EVS_ChooseItem))
    EVT_CALL(AddItem, LVar8, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0008)
            EVT_CALL(ShowChoice, MSG_Choice_0008)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(CloseMessage)
                EVT_GOTO(5)
            EVT_END_IF
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0004)
                EVT_GOTO(9)
            EVT_END_IF
            EVT_CALL(CloseMessage)
            EVT_SET(LVar3, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar9, LVar0)
            EVT_CALL(AddItem, LVar0, LVar1)
            EVT_IF_EQ(LVar8, LVar9)
                EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0009)
                EVT_SET(LVar3, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LVar3, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageMsg, LVar0, 0)
    EVT_SET(LVar1, LVar9)
    EVT_CALL(N(GetItemName), LVar1)
    EVT_CALL(SetMessageMsg, LVar1, 1)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000B)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(9)
    EVT_END_IF
    EVT_CALL(func_80242DBC_82607C, LVar6, LVar7, LVar8, LVar9)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_CALL(RemoveItem, LVar9, LVar0)
    EVT_GOTO(6)
    EVT_LABEL(5)
    EVT_SET(LVar0, LVar8)
    EVT_CALL(N(GetItemName), LVar0)
    EVT_CALL(SetMessageMsg, LVar0, 0)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000A)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000C)
        EVT_GOTO(9)
    EVT_END_IF
    EVT_CALL(func_80242C44_825F04, LVar6, LVar7, LVar8, GF_MAC02_TayceT_HasCookbook)
    EVT_CALL(RemoveItem, LVar8, LVar0)
    EVT_LABEL(6)
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000D)
    EVT_EXEC_WAIT(N(D_802490F8_82C3B8))
    EVT_SWITCH(LVar7)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0012)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_000F)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0010)
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0013)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0011)
    EVT_END_SWITCH
    EVT_CALL(ContinueSpeech, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0014)
    EVT_CALL(func_80242F60_826220, LVar6)
    EVT_GIVE_CONSUMABLE_REWARD_ALT(LVar6)
    EVT_CALL(SpeakToPlayer, NPC_TayceT, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_MAC_Bridge_0015)
    EVT_LABEL(9)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TayceT) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_EXEC_WAIT(N(D_8024926C_82C52C))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_COOKBOOK, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_EXEC_WAIT(N(D_80249684_82C944))
    EVT_ELSE
        EVT_EXEC_WAIT(N(D_80249550_82C810))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TayceT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TayceT)))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, -236, 20, -318)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_Idle)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_IF_NE(GF_MAC02_TayceT_HoldingCake, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_IdleSad)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_MAC_01, FALSE)
    EVT_RETURN
    EVT_END
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(D_8024A8C0_82DB80)[] = {
    ITEM_LETTER07,
    ITEM_NONE
};

EvtScript N(D_8024A8C8_82DB88) = {
    EVT_CALL(N(LetterDelivery_Init), 1,
        0x00AB0004, 0x00AB0001,
        ITEM_LETTER07, ITEM_NONE,
        MSG_MAC_Bridge_0036, MSG_MAC_Bridge_0037, MSG_MAC_Bridge_0038, 0,
        EVT_PTR(N(D_8024A8C0_82DB80)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A918_82DBD8) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, MSG_MAC_Bridge_0039)
        EVT_CALL(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Afraid)
        EVT_CALL(EndSpeech, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0)
        EVT_GIVE_STAR_PIECE()
        EVT_CALL(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Idle)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FiceT) = {
    EVT_SET(LVar3, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0021)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar3, 1)
            EVT_SET(LVar0, MSG_MAC_Bridge_002A)
            EVT_SET(LVar1, MSG_MAC_Bridge_002B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_002C)
            EVT_SET(LVar1, MSG_MAC_Bridge_002D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_002E)
            EVT_SET(LVar1, MSG_MAC_Bridge_002F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0030)
            EVT_SET(LVar1, MSG_MAC_Bridge_0031)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0032)
            EVT_SET(LVar1, MSG_MAC_Bridge_0033)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0034)
            EVT_SET(LVar1, MSG_MAC_Bridge_0035)
    EVT_END_SWITCH
    EVT_CALL(GetCurrentPartnerID, LVar2)
    EVT_IF_EQ(LVar2, PARTNER_BOW)
        EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar1)
    EVT_ELSE
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, LVar0)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar0)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(D_8024A8C8_82DB88))
    EVT_EXEC_WAIT(N(D_8024A918_82DBD8))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FiceT) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_FiceT_Afraid)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 390, 0, -50)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FiceT)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024ACA4_82DF64) = {
    EVT_IF_EQ(LVar0, EVT_FLOAT(0.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH, 0)
        EVT_SETF(LVar1, EVT_FLOAT(24.0))
    EVT_ELSE
        EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR, 0)
        EVT_SETF(LVar1, EVT_FLOAT(-24.0))
    EVT_END_IF
    EVT_LOOP(10)
        EVT_ADDF(LVar0, LVar1)
        EVT_CALL(func_802CFD30, 9, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Bootler) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_SET(LVar0, 0)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_SWITCH(LVar3)
            EVT_CASE_RANGE(-52, 47)
                EVT_ADD(LVar0, 1)
        EVT_END_SWITCH
        EVT_IF_GT(LVar1, 140)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Bridge_0022, 400, 100)
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_SELF, 430, 60, -40)
        EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_293, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 580, -40, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 430, 1, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 430, 1, 35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, 430, -40, 0)
    EVT_CALL(InterpPlayerYaw, 315, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 455, -40, 20)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 315, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, MSG_MAC_Bridge_0023)
    EVT_CALL(ShowChoice, MSG_Choice_0036)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVar1, MSG_MAC_Bridge_0024)
    EVT_ELSE
        EVT_SET(LVar1, MSG_MAC_Bridge_0025)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar1)
    EVT_WAIT(20)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    EVT_CALL(func_802CFD30, -1, 7, 0, 0, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcPos, NPC_SELF, 500, 50, 30)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0026)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtPlayer, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_TayceT, EMOTE_QUESTION, 0, 30, FALSE, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcScale, NPC_Bootler, EVT_FLOAT(2.0), EVT_FLOAT(2.0), EVT_FLOAT(2.0))
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(SetNpcPos, NPC_SELF, 360, 20, 30)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0027)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtPlayer, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_TayceT, EMOTE_QUESTION, 0, 30, FALSE, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
    EVT_CALL(SetNpcScale, NPC_Bootler, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_SELF, 480, 70, 10)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_293, 0)
    EVT_CALL(NpcFlyTo, NPC_SELF, 550, 40, 10, 40, 10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0028)
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtPlayer, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_TayceT, EMOTE_QUESTION, 0, 30, FALSE, 0, 0, 0, 0)
    EVT_WAIT(40)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, MSG_MAC_Bridge_0029)
    EVT_EXEC(N(EVS_SetupMusicTriggers))
    EVT_SET(GB_StoryProgress, STORY_CH3_SAW_BOO_ENTER_FOREST)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bootler)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B5AC_82E86C) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_FRYING_PAN, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(70)
        EVT_CALL(GetNpcPos, NPC_ShyGuy, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B6A0_82E960) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy, SOUND_B0000021, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B6E8_82E9A8) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 40)
            EVT_IF_LT(LVar2, 180)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Bridge_0016, 160, 40)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(3.0), -140, 20, -140, 400, 15, -6)
    EVT_CALL(SetNpcPos, NPC_ShyGuy, -200, 20, -260)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(10)
    EVT_EXEC(N(D_8024B5AC_82E86C))
    EVT_THREAD
        EVT_CALL(EnableGroup, MODEL_cook_in, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit1u, SOUND_BASIC_DOOR_CLOSE, 0)
        EVT_CALL(EnableGroup, MODEL_cook_in, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_8024B6A0_82E960), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy, 8)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -140, -240, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -140, -140, 0)
    EVT_CALL(NpcJump0, NPC_ShyGuy, -140, 0, -100, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -190, -20, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy, -350, -20, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
    EVT_WAIT(10)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_EXEC(N(D_8024B6E8_82E9A8))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Bridge_003A)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Bridge_003B)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_003C)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_003D)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_003E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_003F)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_0040)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Bridge_0041)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Bridge_0042)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0043)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0044)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Bridge_0045)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0046)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Bridge_0047)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0048)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0049)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -550)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, -20, -550, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, 20, -550, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(30)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_01)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_004A)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_004B)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_004C)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Bridge_004D)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_004E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC02_TayceT_HasCookbook, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_004F)
            EVT_ELSE
                EVT_SWITCH(GB_StoryProgress)
                    EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0050)
                    EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0051)
                    EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0052)
                    EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0053)
                    EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0054)
                    EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0055)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0056)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_0057)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_0058)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0059)
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_005A)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Bridge_005B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_005C)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Bridge_005D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_005E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Bridge_005F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0060)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Bridge_0061)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0062)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0063)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0064)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0065)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0066)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0067)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0068)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0069)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_006A)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ToadKid, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_006B)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_006C)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_006D)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_006E)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Bridge_006F)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Bridge_0070)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0071)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0072)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Bridge_0073)
            EVT_SET(GF_MAC02_HeardAboutMinhT, TRUE)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0074)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Bridge_0075)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0076)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0077)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_03, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_0078)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_0079)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_007A)
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_007B)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Bridge_007C)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_007D)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Bridge_007E)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_007F)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Bridge_0080)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0081)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Bridge_0082)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0083)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0084)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GF_MAC02_Gift_MagicalSeed1, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle, ANIM_Bubulb_Pink_BuriedIdle, 0, MSG_MAC_Bridge_0085)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, 0)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_PopUp)
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_Idle)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0086)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0087)
        EVT_SET(GF_MAC02_Gift_MagicalSeed1, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Revealed)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
                EVT_SET(LVar0, MSG_MAC_Bridge_0088)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_MAC_Bridge_0089)
            EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008A)
            EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008B)
            EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008C)
            EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008D)
            EVT_CASE_LT(STORY_EPILOGUE)
                EVT_SET(LVar0, MSG_MAC_Bridge_008E)
            EVT_CASE_DEFAULT
                EVT_SET(LVar0, MSG_MAC_Bridge_008E)
        EVT_END_SWITCH
        EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_EQ(GF_MAC02_Gift_MagicalSeed1, FALSE)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Hidden)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_8024CB04_82FDC4)[] = {
    ANIM_TayceT_Still,
    ANIM_TayceT_Idle,
    ANIM_TayceT_Walk,
    ANIM_TayceT_Idle,
    ANIM_TayceT_Talk,
    ANIM_TayceT_TalkHappy,
    ANIM_TayceT_IdleSad,
    ANIM_TayceT_Cooking,
    ANIM_TayceT_TurnBack,
    -1
};

s32 N(D_8024CB2C_82FDEC)[] = {
    ANIM_Bubulb_Pink_Still,
    ANIM_Bubulb_Pink_BuriedStill,
    ANIM_Bubulb_Pink_Idle,
    ANIM_Bubulb_Pink_Talk,
    ANIM_Bubulb_Pink_PopUp,
    ANIM_Bubulb_Pink_BuriedIdle,
    -1
};

StaticNpc N(NpcData_TayceT)[] = {
    {
        .id = NPC_TayceT,
        .settings = &N(NpcSettings_TayceT),
        .pos = { -217.0f, 20.0f, -434.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_TayceT),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_TayceT_Idle,
        },
        .extraAnimations = N(D_8024CB04_82FDC4),
        .tattle = MSG_NpcTattle_TayceT,
    },
    {
        .id = NPC_FiceT,
        .settings = &N(NpcSettings_TayceT),
        .pos = { 389.0f, 0.0f, -90.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_FiceT),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_FiceT_Idle,
        },
        .tattle = MSG_NpcTattle_FiceT,
    },
    {
        .id = NPC_Bubulb,
        .settings = &N(NpcSettings_Bubulb),
        .pos = { 150.0f, 20.0f, 500.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_800,
        .init = &N(EVS_NpcInit_Bubulb),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Bubulb_Pink_Idle,
            .walk   = ANIM_Bubulb_Pink_Walk,
            .run    = ANIM_Bubulb_Pink_Walk,
            .chase  = ANIM_Bubulb_Pink_Idle,
            .anim_4 = ANIM_Bubulb_Pink_Idle,
            .anim_5 = ANIM_Bubulb_Pink_Idle,
            .death  = ANIM_Bubulb_Pink_Idle,
            .hit    = ANIM_Bubulb_Pink_Idle,
            .anim_8 = ANIM_Bubulb_Pink_Idle,
            .anim_9 = ANIM_Bubulb_Pink_Idle,
            .anim_A = ANIM_Bubulb_Pink_Idle,
            .anim_B = ANIM_Bubulb_Pink_Idle,
            .anim_C = ANIM_Bubulb_Pink_Idle,
            .anim_D = ANIM_Bubulb_Pink_Idle,
            .anim_E = ANIM_Bubulb_Pink_Idle,
            .anim_F = ANIM_Bubulb_Pink_Idle,
        },
        .extraAnimations = N(D_8024CB2C_82FDEC),
        .tattle = MSG_NpcTattle_MAC_Bubulb_Revealed,
    },
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { 40.0f, 0.0f, -60.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -50, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .tattle = MSG_NpcTattle_MAC_HardWorker,
    },
    {
        .id = NPC_ThreeSisters,
        .settings = &N(NpcSettings_TayceT),
        .pos = { -26.0f, 0.0f, -220.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ThreeSisters),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Purple_Idle,
            .walk   = ANIM_Toadette_Purple_Walk,
            .run    = ANIM_Toadette_Purple_Run,
            .chase  = ANIM_Toadette_Purple_Run,
            .anim_4 = ANIM_Toadette_Purple_Idle,
            .anim_5 = ANIM_Toadette_Purple_Idle,
            .death  = ANIM_Toadette_Purple_Disappointed,
            .hit    = ANIM_Toadette_Purple_Disappointed,
            .anim_8 = ANIM_Toadette_Purple_Run,
            .anim_9 = ANIM_Toadette_Purple_Run,
            .anim_A = ANIM_Toadette_Purple_Run,
            .anim_B = ANIM_Toadette_Purple_Run,
            .anim_C = ANIM_Toadette_Purple_Run,
            .anim_D = ANIM_Toadette_Purple_Run,
            .anim_E = ANIM_Toadette_Purple_Run,
            .anim_F = ANIM_Toadette_Purple_Run,
        },
        .tattle = MSG_NpcTattle_MAC_CookingApprentice,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_TayceT),
        .pos = { -350.0f, 20.0f, -140.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Green_Idle,
            .walk   = ANIM_Toad_Green_Walk,
            .run    = ANIM_Toad_Green_Run,
            .chase  = ANIM_Toad_Green_Run,
            .anim_4 = ANIM_Toad_Green_Idle,
            .anim_5 = ANIM_Toad_Green_Idle,
            .death  = ANIM_Toad_Green_Disappointed,
            .hit    = ANIM_Toad_Green_Disappointed,
            .anim_8 = ANIM_Toad_Green_Run,
            .anim_9 = ANIM_Toad_Green_Run,
            .anim_A = ANIM_Toad_Green_Run,
            .anim_B = ANIM_Toad_Green_Run,
            .anim_C = ANIM_Toad_Green_Run,
            .anim_D = ANIM_Toad_Green_Run,
            .anim_E = ANIM_Toad_Green_Run,
            .anim_F = ANIM_Toad_Green_Run,
        },
        .tattle = MSG_NpcTattle_MAC_CantKeepQuiet,
    },
    {
        .id = NPC_ToadKid,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { 180.0f, 20.0f, -435.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_ToadKid),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 180, 20, -435 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 180, 20, -435 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_ToadKid_Yellow_Idle,
            .walk   = ANIM_ToadKid_Yellow_Walk,
            .run    = ANIM_ToadKid_Yellow_Run,
            .chase  = ANIM_ToadKid_Yellow_Run,
            .anim_4 = ANIM_ToadKid_Yellow_Idle,
            .anim_5 = ANIM_ToadKid_Yellow_Idle,
            .death  = ANIM_ToadKid_Yellow_Still,
            .hit    = ANIM_ToadKid_Yellow_Still,
            .anim_8 = ANIM_ToadKid_Yellow_Still,
            .anim_9 = ANIM_ToadKid_Yellow_Still,
            .anim_A = ANIM_ToadKid_Yellow_Still,
            .anim_B = ANIM_ToadKid_Yellow_Still,
            .anim_C = ANIM_ToadKid_Yellow_Still,
            .anim_D = ANIM_ToadKid_Yellow_Still,
            .anim_E = ANIM_ToadKid_Yellow_Still,
            .anim_F = ANIM_ToadKid_Yellow_Still,
        },
        .tattle = MSG_NpcTattle_MAC_FickleDreamer,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { -160.0f, 0.0f, 25.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_03),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -50, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .tattle = MSG_NpcTattle_MAC_PrettySmart,
    },
    {
        .id = NPC_Toad_04,
        .settings = &N(NpcSettings_TayceT),
        .pos = { -80.0f, 0.0f, 300.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Toad_04),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_MAC_PetBoaster,
    },
};

StaticNpc N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .settings = &N(NpcSettings_Bootler),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Bootler),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Bootler_Idle,
        .walk   = ANIM_Bootler_Walk,
        .run    = ANIM_Bootler_Run,
        .chase  = ANIM_Bootler_Run,
        .anim_4 = ANIM_Bootler_Idle,
        .anim_5 = ANIM_Bootler_Idle,
        .death  = ANIM_Bootler_Still,
        .hit    = ANIM_Bootler_Still,
        .anim_8 = ANIM_Bootler_Shock,
        .anim_9 = ANIM_Bootler_Panic,
        .anim_A = ANIM_Bootler_Dejected,
        .anim_B = ANIM_Bootler_Quaver,
        .anim_C = ANIM_Bootler_Shock,
        .anim_D = ANIM_Bootler_Panic,
        .anim_E = ANIM_Bootler_Dejected,
        .anim_F = ANIM_Bootler_Quaver,
    },
};

s32 N(D_8024DEA8_831168)[] = {
    ANIM_ShyGuy_Red_Anim00,
    ANIM_ShyGuy_Red_Anim01,
    ANIM_ShyGuy_Red_Anim02,
    ANIM_ShyGuy_Red_Anim03,
    ANIM_ShyGuy_Red_Anim11,
    ANIM_ShyGuy_Red_Anim02,
    ANIM_ShyGuy_Red_Anim04,
    -1
};

StaticNpc N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .settings = &N(NpcSettings_TayceT),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .init = &N(EVS_NpcInit_ShyGuy),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_ShyGuy_Red_Anim01,
        .walk   = ANIM_ShyGuy_Red_Anim02,
        .run    = ANIM_ShyGuy_Red_Anim03,
        .chase  = ANIM_ShyGuy_Red_Anim03,
        .anim_4 = ANIM_ShyGuy_Red_Anim01,
        .anim_5 = ANIM_ShyGuy_Red_Anim01,
        .death  = ANIM_ShyGuy_Red_Anim0C,
        .hit    = ANIM_ShyGuy_Red_Anim0C,
        .anim_8 = ANIM_ShyGuy_Red_Anim15,
        .anim_9 = ANIM_ShyGuy_Red_Anim12,
        .anim_A = ANIM_ShyGuy_Red_Anim11,
        .anim_B = ANIM_ShyGuy_Red_Anim10,
        .anim_C = ANIM_ShyGuy_Red_Anim05,
        .anim_D = ANIM_ShyGuy_Red_Anim01,
        .anim_E = ANIM_ShyGuy_Red_Anim01,
        .anim_F = ANIM_ShyGuy_Red_Anim01,
    },
    .extraAnimations = N(D_8024DEA8_831168),
};

NpcGroupList N(NpcGroup4) = {
    NPC_GROUP(N(NpcData_TayceT)),
    {}
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_TayceT)),
    NPC_GROUP(N(NpcData_Bootler)),
    {}
};

NpcGroupList N(NpcGroup3) = {
    NPC_GROUP(N(NpcData_ShyGuy)),
    NPC_GROUP(N(NpcData_TayceT)),
    {}
};
