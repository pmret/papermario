#include "jan_03.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/npc/Yoshi.inc.c"
#include "world/common/npc/Yoshi_Patrol.inc.c"

#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/npc/YoshiKid_Patrol.inc.c"

#define NAME_SUFFIX _Unused
// included again later in this file; this copy is not used
#include "world/common/npc/Raven.inc.c"
#define NAME_SUFFIX

#include "world/common/npc/Sushie.inc.c"
#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(RedYoshiKidLetters)[] = {
    ITEM_LETTER_CHAIN_YOSHI_KID,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_RedYoshiKid) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_YoshiKid_02, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle,
        ITEM_LETTER_CHAIN_YOSHI_KID, ITEM_LETTER_CHAIN_DANE_T_2,
        MSG_CH5_0079, MSG_CH5_007A, MSG_CH5_007B, MSG_CH5_007C,
        EVT_PTR(N(RedYoshiKidLetters)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(KoloradoLetters)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH5_001D, MSG_CH5_001E, MSG_CH5_001F, MSG_CH5_0020,
        EVT_PTR(N(KoloradoLetters)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(FoodItemList)[] = {
    ITEM_FRIED_SHROOM,
    ITEM_SPICY_SOUP,
    ITEM_NUTTY_CAKE,
    ITEM_KOOPA_TEA,
    ITEM_SPAGHETTI,
    ITEM_BIG_COOKIE,
    ITEM_CAKE,
    ITEM_FRIED_EGG,
    ITEM_BOILED_EGG,
    ITEM_FROZEN_FRIES,
    ITEM_POTATO_SALAD,
    ITEM_HOT_SHROOM,
    ITEM_BLAND_MEAL,
    ITEM_HONEY_SHROOM,
    ITEM_MAPLE_SHROOM,
    ITEM_JELLY_SHROOM1,
    ITEM_SHROOM_CAKE,
    ITEM_SHROOM_STEAK,
    ITEM_HONEY_SUPER,
    ITEM_MAPLE_SUPER,
    ITEM_JELLY_SUPER,
    ITEM_YUMMY_MEAL,
    ITEM_HONEY_ULTRA,
    ITEM_MAPLE_ULTRA,
    ITEM_JELLY_ULTRA,
    ITEM_SWEET_SHROOM,
    ITEM_ELECTRO_POP,
    ITEM_FIRE_POP,
    ITEM_SPECIAL_SHAKE,
    ITEM_COCO_POP,
    ITEM_LIME_CANDY,
    ITEM_LEMON_CANDY,
    ITEM_HONEY_CANDY,
    ITEM_JELLY_POP,
    ITEM_APPLE_PIE,
    ITEM_KOOPASTA,
    ITEM_KOOKY_COOKIE,
    ITEM_YOSHI_COOKIE,
    ITEM_NONE
};

API_CALLABLE(N(CountFoodItems)) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 outVar = *args++;
    s32 foodCount = 0;
    s32* it;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        it = N(FoodItemList);
        while (*it != 0) {
            if (playerData->invItems[i] == *it++) {
                foodCount++;
            }
        }
    }
    evt_set_variable(script, outVar, foodCount);
    return ApiStatus_DONE2;
}


EvtScript N(EVS_GetRescuedYoshiCount) = {
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, GF_JAN05_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN07_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN08_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN10_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN11_SavedYoshi)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH5_0094)
    EVT_SET(LVar8, MSG_CH5_0095)
    EVT_SET(LVar1, MSG_CH5_0096)
    EVT_SET(LVar2, MSG_CH5_0097)
    EVT_SET(LVar3, MSG_CH5_0098)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.5))
    EVT_CALL(PlayerMoveTo, 322, -178, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 54, -27)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 135)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 406, -130)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 361, -190)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, -1)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 361, -194, 0)
    EVT_CALL(PlayerMoveTo, 370, -257, 0)
    EVT_CALL(InterpPlayerYaw, 229, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(81)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, 345, 0, -186)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 291, -100, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_01) = {
    EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_VillageLeader) = {
    EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(1)
            EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_0099)
                EVT_SET(GF_JAN03_AgreedToRescueChildren, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009A)
            EVT_END_IF
        EVT_CASE_LT(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009B)
        EVT_CASE_LT(4)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009C)
        EVT_CASE_LT(5)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009D)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_VillageLeader) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -300, -70, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, -350, -70, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_VillageLeader) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Panic)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_VillageLeader)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VillageLeader)))
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005A)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005B)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005C)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_JAN11_SavedYoshi, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005D)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005E)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LE(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005F)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0060)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0061)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0062)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Yoshi_02) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -430, -220, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, -340, -220, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN11_SavedYoshi, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Green_Panic)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Yoshi_02)))
            EVT_ELSE
                EVT_CALL(BindNpcIdle, NPC_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_03) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CALL(N(CountFoodItems), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006C)
            EVT_CHOOSE_CONSUMABLE_FROM(N(FoodItemList), 4)
            EVT_IF_LE(LVar0, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006E)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006D)
                EVT_SET(LVar0, ITEM_MELON)
                EVT_SET(LVar1, ITEM_TYPE_CONSUMABLE)
                EVT_EXEC_WAIT(N(GiveItemReward)) // misuse?
                EVT_CALL(AddItem, ITEM_MELON, LVar0)
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0063)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0064)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0065)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0066)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0067)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LE(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0068)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0069)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006A)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Yoshi_03) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -105, -20, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, -190, -80, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Yellow_Panic)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Yoshi_03)))
            EVT_ELSE
                EVT_CALL(BindNpcIdle, NPC_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_YoshiKid_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_YoshiKid_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_006F)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0070)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0071)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0072)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0073)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0074)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0075)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0076)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0077)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0078)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_RedYoshiKid))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007D)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007E)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007F)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_0080)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_0081)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0082)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0083)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0084)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0085)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0086)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0087)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0088)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0089)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_008A)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_008B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid_01) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_IF_EQ(GF_JAN11_SavedYoshi, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_ELSE
            EVT_IF_EQ(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SetNpcPos, NPC_SELF, -490, 0, -90)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -450, 0, -190)
            EVT_END_IF
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid_01)))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid_02) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_IF_EQ(GF_JAN08_SavedYoshi, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid_03) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_IF_EQ(GF_JAN10_SavedYoshi, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid_04) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetNpcPos, NPC_SELF, -135, 0, -70)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid_04)))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid_05) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_IF_EQ(GF_JAN05_SavedYoshi, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Raven) = {
    EVT_CALL(GetSelfNpcID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(NPC_Raven_01)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008C)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008D)
            EVT_END_IF
        EVT_CASE_EQ(NPC_Raven_03)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008E)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008F)
            EVT_END_IF
        EVT_CASE_EQ(NPC_Raven_04)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0090)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0091)
            EVT_END_IF
        EVT_CASE_EQ(NPC_Raven_05)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0092)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0093)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Raven)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
        EVT_CASE_RANGE(STORY_CH5_ZIP_LINE_READY, STORY_CH5_OPENED_ESCAPE_ROUTE)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 14)
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(VolcanoVaseList)[] = {
    ITEM_VOLCANO_VASE,
    -1
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0012)
            EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
            EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
        EVT_CASE_LT(STORY_CH5_GOT_JADE_RAVEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0013)
            EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
            EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
        EVT_CASE_LT(STORY_CH5_ZIP_LINE_READY)
            EVT_IF_EQ(AF_JAN_06, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0014)
                EVT_SET(AF_JAN_06, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0015)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
            EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
        EVT_CASE_EQ(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(FindKeyItem, ITEM_VOLCANO_VASE, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0016)
                EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
                EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
            EVT_ELSE
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 0, 325, EVT_FLOAT(20.0), EVT_FLOAT(-7.5))
                EVT_SET(LVar0, EVT_PTR(N(VolcanoVaseList)))
                EVT_SET(LVar1, 15)
                EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(-1)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0017)
                        EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
                        EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0018)
                        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
                        EVT_WAIT(20)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0019)
                        EVT_WAIT(10)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_IdleSad)
                        EVT_WAIT(15)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                        EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
                        EVT_WAIT(25)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001A)
                        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED4)
                        EVT_SET(GF_JAN03_Gift_MagicalSeed4, TRUE)
                        EVT_WAIT(20)
                        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001B)
                        EVT_WAIT(10)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001C)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
                        EVT_CALL(NpcMoveTo, NPC_SELF, -465, -185, 0)
                        EVT_CALL(NpcMoveTo, NPC_SELF, -540, -70, 0)
                        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                        EVT_SET(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
                EVT_END_SWITCH
                EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SET(LVar0, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_ZIP_LINE_READY)
            EVT_SET(LVar0, 1)
        EVT_CASE_EQ(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, -433, 0, -205)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 0)
            EVT_SET(LVar0, 1)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Sushie) = {
    EVT_IF_EQ(AF_JAN_07, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_0058)
        EVT_SET(AF_JAN_07, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_0059)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Sushie) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Talk)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Run)
        EVT_WAIT(15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sushie) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Sushie)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Sushie)))
    EVT_RETURN
    EVT_END
};

#include "world/common/npc/Raven.inc.c"

AnimID N(ExtraAnims_VillageLeader)[] = {
    ANIM_VillageLeader_Idle,
    ANIM_VillageLeader_IdleSad,
    ANIM_VillageLeader_Walk,
    ANIM_VillageLeader_Panic,
    ANIM_VillageLeader_Run,
    ANIM_VillageLeader_Talk,
    ANIM_VillageLeader_Shout,
    ANIM_VillageLeader_Celebrate,
    ANIM_VillageLeader_CrossArms,
    ANIM_LIST_END
};

NpcData N(NpcData_VillageLeader) = {
    .id = NPC_VillageLeader,
    .pos = { -300.0f, 0.0f, -70.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_VillageLeader),
    .settings = &N(NpcSettings_Yoshi),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = YOSHI_LEADER_ANIMS,
    .extraAnimations = N(ExtraAnims_VillageLeader),
    .tattle = MSG_NpcTattle_VillageLeader,
};

AnimID N(ExtraAnims_Sushie)[] = {
    ANIM_WorldSushie_Idle,
    ANIM_WorldSushie_Run,
    ANIM_WorldSushie_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Sushie) = {
    .id = NPC_Sushie,
    .pos = { -425.0f, 0.0f, -350.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Sushie),
    .settings = &N(NpcSettings_Sushie),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = SUSHIE_ANIMS,
    .extraAnimations = N(ExtraAnims_Sushie),
    .tattle = MSG_NpcTattle_Sushie,
};

AnimID N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_IdleSad,
    ANIM_Kolorado_Walk,
    ANIM_Kolorado_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -475.0f, 0.0f, -75.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .extraAnimations = N(ExtraAnims_Kolorado),
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Toad)[] = {
    {
        .id = NPC_Toad,
        .pos = { 275.0f, 0.0f, -70.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_JAN_ToadHouseToad,
    },
    {
        .id = NPC_Yoshi_01,
        .pos = { 125.0f, 30.0f, -425.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Yoshi_01),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_JAN_ShopOwner,
    },
    {
        .id = NPC_Yoshi_02,
        .pos = { -350.0f, 0.0f, -220.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -375, 0, -220 },
                    { -325, 0, -220 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_02),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GenericYoshi,
    },
    {
        .id = NPC_Yoshi_03,
        .pos = { -100.0f, 0.0f, -80.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -100, 0, -20 },
                    { -210, 0, -80 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_03),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_FoodLovingYoshi,
    },
    {
        .id = NPC_YoshiKid_01,
        .pos = { -450.0f, 0.0f, -160.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 5,
                .points  = {
                    { -450, 0, -160 },
                    { -378, 0, -81 },
                    { -590, 0, -100 },
                    { -464, 0, -46 },
                    { -495, 0, -147 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_01),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreenYoshiKid,
    },
    {
        .id = NPC_YoshiKid_02,
        .pos = { -340.0f, 0.0f, -385.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -340, 0, -385 },
                    { -290, 0, -310 },
                    { -360, 0, -310 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_02),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_RedYoshiKid,
    },
    {
        .id = NPC_YoshiKid_03,
        .pos = { -260.0f, 0.0f, -220.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -260, 0, -220 },
                    { -270, 0, -220 },
                    { -260, 0, -230 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_03),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshiKid,
    },
    {
        .id = NPC_YoshiKid_04,
        .pos = { -460.0f, 0.0f, 150.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -460, 0, 150 },
                    { -450, 0, 150 },
                    { -460, 0, 160 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_04),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_YellowYoshiKid,
    },
    {
        .id = NPC_YoshiKid_05,
        .pos = { -320.0f, 0.0f, 80.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -320, 0, 80 },
                    { -330, 0, 80 },
                    { -320, 0, 90 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_05),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_PurpleYoshiKid,
    },
};

AnimID N(ExtraAnims_Raven)[] = {
    ANIM_Raven_Still,
    ANIM_Raven_Idle,
    ANIM_Raven_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Ravens)[] = {
    {
        .id = NPC_Raven_01,
        .pos = { -650.0f, 374.0f, -150.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Raven),
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { -645.0f, 457.0f, -255.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
    },
    {
        .id = NPC_Raven_03,
        .pos = { -570.0f, 374.0f, -300.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { -500.0f, 374.0f, -285.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { -450.0f, 374.0f, -175.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 300.0f, 0.0f, 400.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_JAN, QUIZ_COUNT_JAN, QUIZ_MAP_JAN_03 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Sushie)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(ChapterNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
