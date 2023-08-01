#include "nok_02.h"

#define NAME_SUFFIX _Koot
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"
#define NAME_SUFFIX

typedef struct KootFavor {
    /* 0x00 */ s32 requestMsg;
    /* 0x04 */ s32 minorRewardMsg;
    /* 0x08 */ s32 majorRewardMsg;
    /* 0x0C */ s32 unlockedFlag;
    /* 0x10 */ s32 gaveUpFlag;
    /* 0x14 */ s32 completeFlag;
    /* 0x18 */ s32 requiredItem;
} KootFavor; // size = 0x1C

KootFavor N(KootFavorData)[] = {
    [KOOT_FAVOR_CH1_1] {
        .requestMsg = MSG_KootFavor_0000,
        .minorRewardMsg = MSG_KootFavor_0001,
        .majorRewardMsg = MSG_KootFavor_0002,
        .unlockedFlag = GF_NOK02_KootFavor00_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor00_GaveUp,
        .completeFlag = GF_NOK02_KootFavor00_Complete,
        .requiredItem = ITEM_KOOT_KOOPA_LEGENDS,
    },
    [KOOT_FAVOR_CH1_2] {
        .requestMsg = MSG_KootFavor_0003,
        .minorRewardMsg = MSG_KootFavor_0004,
        .majorRewardMsg = MSG_KootFavor_0005,
        .unlockedFlag = GF_NOK02_KootFavor01_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor01_GaveUp,
        .completeFlag = GF_NOK02_KootFavor01_Complete,
        .requiredItem = ITEM_SLEEPY_SHEEP,
    },
    [KOOT_FAVOR_CH2_1] {
        .requestMsg = MSG_KootFavor_0006,
        .minorRewardMsg = MSG_KootFavor_0007,
        .majorRewardMsg = MSG_KootFavor_0008,
        .unlockedFlag = GF_NOK02_KootFavor02_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor02_GaveUp,
        .completeFlag = GF_NOK02_KootFavor02_Complete,
        .requiredItem = ITEM_KOOT_THE_TAPE,
    },
    [KOOT_FAVOR_CH2_2] {
        .requestMsg = MSG_KootFavor_0009,
        .minorRewardMsg = MSG_KootFavor_000A,
        .majorRewardMsg = MSG_KootFavor_000B,
        .unlockedFlag = GF_NOK02_KootFavor03_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor03_GaveUp,
        .completeFlag = GF_NOK02_KootFavor03_Complete,
        .requiredItem = ITEM_KOOPA_TEA,
    },
    [KOOT_FAVOR_CH2_3] {
        .requestMsg = MSG_KootFavor_000C,
        .minorRewardMsg = MSG_KootFavor_000D,
        .majorRewardMsg = MSG_KootFavor_000E,
        .unlockedFlag = GF_NOK02_KootFavor04_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor04_GaveUp,
        .completeFlag = GF_NOK02_KootFavor04_Complete,
        .requiredItem = ITEM_KOOT_LUIGI_AUTOGRAPH,
    },
    [KOOT_FAVOR_CH3_1] {
        .requestMsg = MSG_KootFavor_000F,
        .minorRewardMsg = MSG_KootFavor_0010,
        .majorRewardMsg = MSG_KootFavor_0011,
        .unlockedFlag = GF_NOK02_KootFavor05_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor05_GaveUp,
        .completeFlag = GF_NOK02_KootFavor05_Complete,
        .requiredItem = ITEM_KOOT_EMPTY_WALLET,
    },
    [KOOT_FAVOR_CH3_2] {
        .requestMsg = MSG_KootFavor_0012,
        .minorRewardMsg = MSG_KootFavor_0013,
        .majorRewardMsg = MSG_KootFavor_0014,
        .unlockedFlag = GF_NOK02_KootFavor06_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor06_GaveUp,
        .completeFlag = GF_NOK02_KootFavor06_Complete,
        .requiredItem = ITEM_TASTY_TONIC,
    },
    [KOOT_FAVOR_CH3_3] {
        .requestMsg = MSG_KootFavor_0015,
        .minorRewardMsg = MSG_KootFavor_0016,
        .majorRewardMsg = MSG_KootFavor_0017,
        .unlockedFlag = GF_NOK02_KootFavor07_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor07_GaveUp,
        .completeFlag = GF_NOK02_KootFavor07_Complete,
        .requiredItem = ITEM_KOOT_MERLUVLEE_AUTOGRAPH,
    },
    [KOOT_FAVOR_CH4_1] {
        .requestMsg = MSG_KootFavor_0018,
        .minorRewardMsg = MSG_KootFavor_0019,
        .majorRewardMsg = MSG_KootFavor_001A,
        .unlockedFlag = GF_NOK02_KootFavor08_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor08_GaveUp,
        .completeFlag = GF_NOK02_KootFavor08_Complete,
        .requiredItem = ITEM_NONE,
    },
    [KOOT_FAVOR_CH4_2] {
        .requestMsg = MSG_KootFavor_001B,
        .minorRewardMsg = MSG_KootFavor_001C,
        .majorRewardMsg = MSG_KootFavor_001D,
        .unlockedFlag = GF_NOK02_KootFavor09_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor09_GaveUp,
        .completeFlag = GF_NOK02_KootFavor09_Complete,
        .requiredItem = ITEM_LIFE_SHROOM,
    },
    [KOOT_FAVOR_CH4_3] {
        .requestMsg = MSG_KootFavor_001E,
        .minorRewardMsg = MSG_KootFavor_001F,
        .majorRewardMsg = MSG_KootFavor_0020,
        .unlockedFlag = GF_NOK02_KootFavor0A_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0A_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0A_Complete,
        .requiredItem = ITEM_NUTTY_CAKE,
    },
    [KOOT_FAVOR_CH5_1] {
        .requestMsg = MSG_KootFavor_0021,
        .minorRewardMsg = MSG_KootFavor_0022,
        .majorRewardMsg = MSG_KootFavor_0023,
        .unlockedFlag = GF_NOK02_KootFavor0B_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0B_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0B_Complete,
        .requiredItem = ITEM_NONE,
    },
    [KOOT_FAVOR_CH5_2] {
        .requestMsg = MSG_KootFavor_0024,
        .minorRewardMsg = MSG_KootFavor_0025,
        .majorRewardMsg = MSG_KootFavor_0026,
        .unlockedFlag = GF_NOK02_KootFavor0C_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0C_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0C_Complete,
        .requiredItem = ITEM_KOOT_OLD_PHOTO,
    },
    [KOOT_FAVOR_CH5_3] {
        .requestMsg = MSG_KootFavor_0027,
        .minorRewardMsg = MSG_KootFavor_0028,
        .majorRewardMsg = MSG_KootFavor_0029,
        .unlockedFlag = GF_NOK02_KootFavor0D_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0D_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0D_Complete,
        .requiredItem = ITEM_KOOPASTA,
    },
    [KOOT_FAVOR_CH6_1] {
        .requestMsg = MSG_KootFavor_002A,
        .minorRewardMsg = MSG_KootFavor_002B,
        .majorRewardMsg = MSG_KootFavor_002C,
        .unlockedFlag = GF_NOK02_KootFavor0E_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0E_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0E_Complete,
        .requiredItem = ITEM_KOOT_GLASSES,
    },
    [KOOT_FAVOR_CH6_2] {
        .requestMsg = MSG_KootFavor_002D,
        .minorRewardMsg = MSG_KootFavor_002E,
        .majorRewardMsg = MSG_KootFavor_002F,
        .unlockedFlag = GF_NOK02_KootFavor0F_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor0F_GaveUp,
        .completeFlag = GF_NOK02_KootFavor0F_Complete,
        .requiredItem = ITEM_LIME,
    },
    [KOOT_FAVOR_CH6_3] {
        .requestMsg = MSG_KootFavor_0030,
        .minorRewardMsg = MSG_KootFavor_0031,
        .majorRewardMsg = MSG_KootFavor_0032,
        .unlockedFlag = GF_NOK02_KootFavor10_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor10_GaveUp,
        .completeFlag = GF_NOK02_KootFavor10_Complete,
        .requiredItem = ITEM_KOOKY_COOKIE,
    },
    [KOOT_FAVOR_CH7_1] {
        .requestMsg = MSG_KootFavor_0033,
        .minorRewardMsg = MSG_KootFavor_0034,
        .majorRewardMsg = MSG_KootFavor_0035,
        .unlockedFlag = GF_NOK02_KootFavor11_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor11_GaveUp,
        .completeFlag = GF_NOK02_KootFavor11_Complete,
        .requiredItem = ITEM_KOOT_PACKAGE,
    },
    [KOOT_FAVOR_CH7_2] {
        .requestMsg = MSG_KootFavor_0036,
        .minorRewardMsg = MSG_KootFavor_0037,
        .majorRewardMsg = MSG_KootFavor_0038,
        .unlockedFlag = GF_NOK02_KootFavor12_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor12_GaveUp,
        .completeFlag = GF_NOK02_KootFavor12_Complete,
        .requiredItem = ITEM_COCONUT,
    },
    [KOOT_FAVOR_CH7_3] {
        .requestMsg = MSG_KootFavor_0039,
        .minorRewardMsg = MSG_KootFavor_003A,
        .majorRewardMsg = MSG_KootFavor_003B,
        .unlockedFlag = GF_NOK02_KootFavor13_Unlocked,
        .gaveUpFlag   = GF_NOK02_KootFavor13_GaveUp,
        .completeFlag = GF_NOK02_KootFavor13_Complete,
        .requiredItem = ITEM_KOOT_RED_JAR,
    }
};

API_CALLABLE(N(IsFourthMultipleFavor)) {
    Bytecode* args = script->ptrReadPos;
    s32 favorIdx = evt_get_variable(script, *args++);

    if ((favorIdx % 4) != 0) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FindNextFavor)) {
    Bytecode* args = script->ptrReadPos;
    s32 currentFavorVar = *args++;
    u32 count = 0;
    KootFavor* it = N(KootFavorData);
    s32 randomIdx;
    u32 i;

    // count number of available favors
    for (i = 0; i < ARRAY_COUNT(N(KootFavorData)); i++, it++) {
        if (evt_get_variable(script, it->unlockedFlag) && !evt_get_variable(script, it->completeFlag)) {
            count++;
            if (!evt_get_variable(script, it->gaveUpFlag)) {
                // after first non-skipped favor is found, break the loop
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(N(KootFavorData))) {
        if (count == 0) {
            // found no available favors and none were skipped
            script->varTable[0] = 0;
            evt_set_variable(script, currentFavorVar, 0xFF);
            return ApiStatus_DONE2;
        } else {
            // found no new favors, choose one randomly among the skipped ones
            randomIdx = rand_int(count - 1);
            count = 0;

            it = N(KootFavorData);
            for (i = 0; i < ARRAY_COUNT(N(KootFavorData)); i++, it++) {
                if (evt_get_variable(script, it->unlockedFlag) && !evt_get_variable(script, it->completeFlag)) {
                    if (count++ == randomIdx) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->requestMsg;
        evt_set_variable(script, currentFavorVar, i + 1);
        return ApiStatus_DONE2;
    } else {
        // found a new pending favor
        script->varTable[0] = it->requestMsg;
        evt_set_variable(script, currentFavorVar, i + 1);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(GiveUpFavor)) {
    Bytecode* args = script->ptrReadPos;
    s32 currentFavorVar = *args++;
    s32 favorIdx = evt_get_variable(script, currentFavorVar) - 1;
    KootFavor* it = N(KootFavorData);
    s32 count = 0;
    s32 randomIdx;
    u32 i;

    evt_set_variable(script, N(KootFavorData)[favorIdx].gaveUpFlag, TRUE);

    for (i = 0; i < ARRAY_COUNT(N(KootFavorData)); i++, it++) {
        if (evt_get_variable(script, it->unlockedFlag) && !evt_get_variable(script, it->completeFlag)) {
            count++;
            if (!evt_get_variable(script, it->gaveUpFlag)) {
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(N(KootFavorData))) {
        if (count < 2) {
            script->varTable[0] = 0;
            evt_set_variable(script, currentFavorVar, 0xFF);
            return ApiStatus_DONE2;
        } else {
            randomIdx = rand_int(count - 2);
            count = 0;

            it = N(KootFavorData);
            for (i = 0; i < ARRAY_COUNT(N(KootFavorData)); i++, it++) {
                if (i == favorIdx) {
                    continue;
                }
                if (evt_get_variable(script, it->unlockedFlag) && !evt_get_variable(script, it->completeFlag)) {
                    if (count++ == randomIdx) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->requestMsg;
        evt_set_variable(script, currentFavorVar, i + 1);
        return ApiStatus_DONE2;
    } else {
        script->varTable[0] = it->requestMsg;
        evt_set_variable(script, currentFavorVar, i + 1);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(GetFavorMessages)) {
    Bytecode* args = script->ptrReadPos;
    s32 favorIdx = evt_get_variable(script, *args++) - 1;
    KootFavor* favor = &N(KootFavorData)[favorIdx];

    script->varTable[0] = favor->requestMsg;
    script->varTable[1] = favor->minorRewardMsg;
    script->varTable[2] = favor->majorRewardMsg;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetFavorComplete)) {
    Bytecode* args = script->ptrReadPos;
    s32 favorIdx = evt_get_variable(script, *args++) - 1;
    KootFavor* favor = &N(KootFavorData)[favorIdx];

    evt_set_variable(script, favor->completeFlag, TRUE);
    return ApiStatus_DONE2;
}

s32 N(FavorItemList)[] = {
    ITEM_NONE,
    ITEM_NONE,
};

API_CALLABLE(N(MakeFavorItemList)) {
    Bytecode *args = script->ptrReadPos;
    s32 favorIdx = evt_get_variable(script, *args++) - 1;
    s32 itemID = N(KootFavorData)[favorIdx].requiredItem;
    s16* typeFlags = &gItemTable[itemID].typeFlags;

    N(FavorItemList)[0] = itemID;
    script->varTable[0] = (*typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) > 0;
    script->varTable[1] = itemID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_KoopaKoot) = {
    EVT_CALL(func_802CF56C, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A2)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_IF_EQ(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        EVT_IF_EQ(GF_MAC02_KootFavor_CurrentComplete, FALSE)
            EVT_CALL(N(MakeFavorItemList), GB_KootFavor_Current)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, EVT_PTR(N(FavorItemList)))
                EVT_SET(LVar1, 9)
                EVT_EXEC_WAIT(N(EVS_ChooseKeyItem_Koot))
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(-1)
                    EVT_CASE_EQ(0)
                    EVT_CASE_DEFAULT
                        EVT_SET(GF_MAC02_KootFavor_CurrentComplete, TRUE)
                EVT_END_SWITCH
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(FavorItemList)))
                EVT_SET(LVar1, 9)
                EVT_EXEC_WAIT(N(EVS_ChooseItem_Koot))
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(-1)
                    EVT_CASE_EQ(0)
                    EVT_CASE_DEFAULT
                        EVT_SET(GF_MAC02_KootFavor_CurrentComplete, TRUE)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(GF_MAC02_KootFavor_CurrentComplete, TRUE)
            EVT_CALL(N(SetFavorComplete), GB_KootFavor_Current)
            EVT_ADD(GB_KootFavor_Completed, 1)
            EVT_CALL(N(IsFourthMultipleFavor), GB_KootFavor_Completed)
            EVT_IF_FALSE(LVar0)
                EVT_CALL(N(GetFavorMessages), GB_KootFavor_Current)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar1)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B1)
                #define NAME_SUFFIX _Koot
                EVT_GIVE_COIN()
                #define NAME_SUFFIX
            EVT_ELSE
                EVT_CALL(N(GetFavorMessages), GB_KootFavor_Current)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar2)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B1)
                EVT_CALL(ShowGotItem, ITEM_STAR_PIECE, TRUE, ITEM_PICKUP_FLAG_3_STAR_PIECES)
                EVT_CALL(AddStarPieces, 3)
            EVT_END_IF
            EVT_SWITCH(GB_KootFavor_Completed)
                #define NAME_SUFFIX _Koot
                EVT_CASE_EQ(1 + KOOT_FAVOR_CH1_2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B2)
                    EVT_GIVE_KEY_REWARD(ITEM_SILVER_CREDIT)
                EVT_CASE_EQ(1 + KOOT_FAVOR_CH4_2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B3)
                    EVT_GIVE_KEY_REWARD(ITEM_GOLD_CREDIT)
                    EVT_CALL(FindKeyItem, ITEM_SILVER_CREDIT, LVar1)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                #define NAME_SUFFIX
            EVT_END_SWITCH
            EVT_SET(GB_KootFavor_State, KOOT_FAVOR_STATE_0)
            EVT_GOTO(90)
        EVT_END_IF
        // ask about current favor progress
        EVT_IF_EQ(GF_KootFavor_LeftKoopaArea, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AD)
            EVT_CALL(ShowChoice, MSG_Choice_0012)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0) // go on
                    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AE)
                EVT_CASE_EQ(1) // give up
                    EVT_CALL(N(GiveUpFavor), GB_KootFavor_Current)
                    EVT_IF_EQ(LVar0, 0)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B0)
                        EVT_SET(GB_KootFavor_State, KOOT_FAVOR_STATE_1)
                        EVT_GOTO(90)
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AF)
                    EVT_END_IF
                    EVT_GOTO(50)
                EVT_CASE_EQ(2) // forgotten
                    EVT_CALL(N(GetFavorMessages), GB_KootFavor_Current)
                    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar0)
            EVT_END_SWITCH
        EVT_ELSE
            EVT_IF_EQ(GF_KootFavor_LeftKoopaVillage, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AA)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AB)
            EVT_END_IF
            EVT_CALL(ShowChoice, MSG_Choice_0010)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(N(GetFavorMessages), GB_KootFavor_Current)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar0)
                EVT_SET(GF_KootFavor_LeftKoopaVillage, FALSE)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AC)
            EVT_END_IF
        EVT_END_IF
        EVT_GOTO(90)
    EVT_END_IF
    EVT_CALL(N(FindNextFavor), GB_KootFavor_Current)
    EVT_IF_EQ(LVar0, 0)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A5)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A6)
        EVT_END_IF
        EVT_GOTO(90)
    EVT_ELSE
        EVT_IF_EQ(GB_KootFavor_State, KOOT_FAVOR_STATE_0)
            EVT_IF_EQ(GF_NOK02_Met_KoopaKoot, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A3)
                EVT_SET(GF_NOK02_Met_KoopaKoot, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A4)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A7)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(50)
    EVT_CALL(ShowChoice, MSG_Choice_0010)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A9)
        EVT_CALL(N(GetFavorMessages), GB_KootFavor_Current)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar0)
        EVT_SET(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        EVT_SET(GF_KootFavor_LeftKoopaVillage, FALSE)
        EVT_SET(GF_MAC02_KootFavor_CurrentComplete, FALSE)
        EVT_SET(GF_KootFavor_LeftKoopaArea, FALSE)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A8)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaKoot_SwingCane)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaKoot_IdleCane)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_KoopaKoot_TalkCane, ANIM_KoopaKoot_IdleCane, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaKoot_StillCane)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaKoot_Idle)
        EVT_SET(GB_KootFavor_State, KOOT_FAVOR_STATE_1)
        EVT_SET(GB_KootFavor_Current, KOOT_FAVOR_CH1_1)
    EVT_END_IF
    EVT_LABEL(90)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupKootFavors) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_GOTO(80)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_GOTO(75)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_GOTO(70)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_GOTO(60)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_SET(GF_NOK02_KootFavor14_Unlocked, TRUE)
    EVT_LABEL(20)
    EVT_SET(GF_NOK02_KootFavor13_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor12_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor11_Unlocked, TRUE)
    EVT_LABEL(30)
    EVT_SET(GF_NOK02_KootFavor10_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor0F_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor0E_Unlocked, TRUE)
    EVT_LABEL(40)
    EVT_SET(GF_NOK02_KootFavor0D_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor0C_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor0B_Unlocked, TRUE)
    EVT_LABEL(50)
    EVT_SET(GF_NOK02_KootFavor0A_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor09_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor08_Unlocked, TRUE)
    EVT_LABEL(60)
    EVT_SET(GF_NOK02_KootFavor07_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor06_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor05_Unlocked, TRUE)
    EVT_LABEL(70)
    EVT_SET(GF_NOK02_KootFavor04_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor03_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor02_Unlocked, TRUE)
    EVT_LABEL(75)
    EVT_SET(GF_NOK02_KootFavor01_Unlocked, TRUE)
    EVT_SET(GF_NOK02_KootFavor00_Unlocked, TRUE)
    EVT_LABEL(80)
    EVT_RETURN
    EVT_END
};
