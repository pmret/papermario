#include "nok_02.h"

#define NAME_SUFFIX _Koot
//MAP_STATIC_PAD(2,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"
#define NAME_SUFFIX

typedef struct UnkNok02 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkNok02; // size = 0x1C

UnkNok02 N(D_80252784_9E97A4)[] = {
    { 0x00150000, 0x00150001, 0x00150002, GF_NOK02_KootFavor00_Unlocked, GF_NOK02_KootFavor00_GaveUp, GF_NOK02_KootFavor00_Complete, 110 },
    { 0x00150003, 0x00150004, 0x00150005, GF_NOK02_KootFavor01_Unlocked, GF_NOK02_KootFavor01_GaveUp, GF_NOK02_KootFavor01_Complete, 143 },
    { 0x00150006, 0x00150007, 0x00150008, GF_NOK02_KootFavor02_Unlocked, GF_NOK02_KootFavor02_GaveUp, GF_NOK02_KootFavor02_Complete,  92 },
    { 0x00150009, 0x0015000A, 0x0015000B, GF_NOK02_KootFavor03_Unlocked, GF_NOK02_KootFavor03_GaveUp, GF_NOK02_KootFavor03_Complete, 195 },
    { 0x0015000C, 0x0015000D, 0x0015000E, GF_NOK02_KootFavor04_Unlocked, GF_NOK02_KootFavor04_GaveUp, GF_NOK02_KootFavor04_Complete, 111 },
    { 0x0015000F, 0x00150010, 0x00150011, GF_NOK02_KootFavor05_Unlocked, GF_NOK02_KootFavor05_GaveUp, GF_NOK02_KootFavor05_Complete, 112 },
    { 0x00150012, 0x00150013, 0x00150014, GF_NOK02_KootFavor06_Unlocked, GF_NOK02_KootFavor06_GaveUp, GF_NOK02_KootFavor06_Complete, 137 },
    { 0x00150015, 0x00150016, 0x00150017, GF_NOK02_KootFavor07_Unlocked, GF_NOK02_KootFavor07_GaveUp, GF_NOK02_KootFavor07_Complete, 113 },
    { 0x00150018, 0x00150019, 0x0015001A, GF_NOK02_KootFavor08_Unlocked, GF_NOK02_KootFavor08_GaveUp, GF_NOK02_KootFavor08_Complete,   0 },
    { 0x0015001B, 0x0015001C, 0x0015001D, GF_NOK02_KootFavor09_Unlocked, GF_NOK02_KootFavor09_GaveUp, GF_NOK02_KootFavor09_Complete, 149 },
    { 0x0015001E, 0x0015001F, 0x00150020, GF_NOK02_KootFavor0A_Unlocked, GF_NOK02_KootFavor0A_GaveUp, GF_NOK02_KootFavor0A_Complete, 214 },
    { 0x00150021, 0x00150022, 0x00150023, GF_NOK02_KootFavor0B_Unlocked, GF_NOK02_KootFavor0B_GaveUp, GF_NOK02_KootFavor0B_Complete,   0 },
    { 0x00150024, 0x00150025, 0x00150026, GF_NOK02_KootFavor0C_Unlocked, GF_NOK02_KootFavor0C_GaveUp, GF_NOK02_KootFavor0C_Complete, 115 },
    { 0x00150027, 0x00150028, 0x00150029, GF_NOK02_KootFavor0D_Unlocked, GF_NOK02_KootFavor0D_GaveUp, GF_NOK02_KootFavor0D_Complete, 181 },
    { 0x0015002A, 0x0015002B, 0x0015002C, GF_NOK02_KootFavor0E_Unlocked, GF_NOK02_KootFavor0E_GaveUp, GF_NOK02_KootFavor0E_Complete, 116 },
    { 0x0015002D, 0x0015002E, 0x0015002F, GF_NOK02_KootFavor0F_Unlocked, GF_NOK02_KootFavor0F_GaveUp, GF_NOK02_KootFavor0F_Complete, 157 },
    { 0x00150030, 0x00150031, 0x00150032, GF_NOK02_KootFavor10_Unlocked, GF_NOK02_KootFavor10_GaveUp, GF_NOK02_KootFavor10_Complete, 211 },
    { 0x00150033, 0x00150034, 0x00150035, GF_NOK02_KootFavor11_Unlocked, GF_NOK02_KootFavor11_GaveUp, GF_NOK02_KootFavor11_Complete, 118 },
    { 0x00150036, 0x00150037, 0x00150038, GF_NOK02_KootFavor12_Unlocked, GF_NOK02_KootFavor12_GaveUp, GF_NOK02_KootFavor12_Complete, 172 },
    { 0x00150039, 0x0015003A, 0x0015003B, GF_NOK02_KootFavor13_Unlocked, GF_NOK02_KootFavor13_GaveUp, GF_NOK02_KootFavor13_Complete, 119 },
};

API_CALLABLE(N(func_80243EC8_9DAEE8)) {
    Bytecode* args = script->ptrReadPos;

    if ((evt_get_variable(script, *args++) % 4) != 0) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243F10_9DAF30)) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    u32 count = 0;
    UnkNok02* it = N(D_80252784_9E97A4);
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(D_80252784_9E97A4)); i++, it++) {
        if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
            count++;
            if (evt_get_variable(script, it->unk_10) == 0) {
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(N(D_80252784_9E97A4))) {
        if (count == 0) {
            script->varTable[0] = 0;
            evt_set_variable(script, a0, 0xFF);
            return ApiStatus_DONE2;
        } else {
            s32 temp_s6 = rand_int(count - 1);
            count = 0;

            it = N(D_80252784_9E97A4);
            for (i = 0; i < ARRAY_COUNT(N(D_80252784_9E97A4)); i++, it++) {
                if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
                    if (count++ == temp_s6) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    } else {
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(func_80244078_9DB098)) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 count = 0;
    s32 thing = evt_get_variable(script, a0) - 1;
    UnkNok02* it = N(D_80252784_9E97A4);
    u32 i;

    evt_set_variable(script, N(D_80252784_9E97A4)[thing].unk_10, 1);

    for (i = 0; i < ARRAY_COUNT(N(D_80252784_9E97A4)); i++, it++) {
        if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
            count++;
            if (evt_get_variable(script, it->unk_10) == 0) {
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(N(D_80252784_9E97A4))) {
        if (count < 2) {
            script->varTable[0] = 0;
            evt_set_variable(script, a0, 0xFF);
            return ApiStatus_DONE2;
        } else {
            s32 temp_s6 = rand_int(count - 2);

            count = 0;

            it = N(D_80252784_9E97A4);
            for (i = 0; i < ARRAY_COUNT(N(D_80252784_9E97A4)); i++, it++) {
                if (i != thing &&
                    evt_get_variable(script, it->unk_0C) != 0 &&
                    evt_get_variable(script, it->unk_14) == 0)
                {
                    if (count++ == temp_s6) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    } else {
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(func_80244224_9DB244)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++) - 1;
    UnkNok02* temp_v1 = &N(D_80252784_9E97A4)[idx];

    script->varTable[0] = temp_v1->unk_00;
    script->varTable[1] = temp_v1->unk_04;
    script->varTable[2] = temp_v1->unk_08;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80244288_9DB2A8)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, N(D_80252784_9E97A4)[evt_get_variable(script, *args++) - 1].unk_14, 1);
    return ApiStatus_DONE2;
}

s32 N(D_802529B4_9E99D4) = {
    0
};

s32 N(D_802529B4_9E99D8) = {
    0
};

API_CALLABLE(N(func_802442E0_9DB300)) {
    Bytecode *args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *(args++)) - 1;
    s32 val = N(D_80252784_9E97A4)[idx].unk_18;
    s16* typeFlags = &gItemTable[val].typeFlags;

    N(D_802529B4_9E99D4) = val;
    script->varTable[0] = (*typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) > 0;
    script->varTable[1] = val;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_KoopaKoot) = {
    EVT_CALL(func_802CF56C, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A2)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_IF_EQ(GB_KootFavor_State, 2)
        EVT_IF_EQ(GF_MAC02_KootFavor_CurrentComplete, FALSE)
            EVT_CALL(N(func_802442E0_9DB300), GB_KootFavor_Current)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, EVT_PTR(N(D_802529B4_9E99D4)))
                EVT_SET(LVar1, 9)
                EVT_EXEC_WAIT(N(EVS_ChooseKeyItem_Koot))
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(-1)
                    EVT_CASE_EQ(0)
                    EVT_CASE_DEFAULT
                        EVT_SET(GF_MAC02_KootFavor_CurrentComplete, TRUE)
                EVT_END_SWITCH
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(D_802529B4_9E99D4)))
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
            EVT_CALL(N(func_80244288_9DB2A8), GB_KootFavor_Current)
            EVT_ADD(GB_KootFavor_Completed, 1)
            EVT_CALL(N(func_80243EC8_9DAEE8), GB_KootFavor_Completed)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(N(func_80244224_9DB244), GB_KootFavor_Current)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar1)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B1)
                #define NAME_SUFFIX _Koot
                EVT_GIVE_COIN()
                #define NAME_SUFFIX
            EVT_ELSE
                EVT_CALL(N(func_80244224_9DB244), GB_KootFavor_Current)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar2)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B1)
                EVT_CALL(ShowGotItem, ITEM_STAR_PIECE, TRUE, 32)
                EVT_CALL(AddStarPieces, 3)
            EVT_END_IF
            EVT_SWITCH(GB_KootFavor_Completed)
                #define NAME_SUFFIX _Koot
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B2)
                    EVT_GIVE_KEY_REWARD(ITEM_SILVER_CREDIT)
                EVT_CASE_EQ(10)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B3)
                    EVT_GIVE_KEY_REWARD(ITEM_GOLD_CREDIT)
                    EVT_CALL(FindKeyItem, ITEM_SILVER_CREDIT, LVar1)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                #define NAME_SUFFIX
            EVT_END_SWITCH
            EVT_SET(GB_KootFavor_State, 0)
            EVT_GOTO(90)
        EVT_END_IF
        EVT_IF_EQ(GF_KootFavor_LeftKoopaArea, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AD)
            EVT_CALL(ShowChoice, MSG_Choice_0012)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AE)
                EVT_CASE_EQ(1)
                    EVT_CALL(N(func_80244078_9DB098), GB_KootFavor_Current)
                    EVT_IF_EQ(LVar0, 0)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00B0)
                        EVT_SET(GB_KootFavor_State, 1)
                        EVT_GOTO(90)
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AF)
                    EVT_END_IF
                    EVT_GOTO(50)
                EVT_CASE_EQ(2)
                    EVT_CALL(N(func_80244224_9DB244), GB_KootFavor_Current)
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
                EVT_CALL(N(func_80244224_9DB244), GB_KootFavor_Current)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar0)
                EVT_SET(GF_KootFavor_LeftKoopaVillage, FALSE)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00AC)
            EVT_END_IF
        EVT_END_IF
        EVT_GOTO(90)
    EVT_END_IF
    EVT_CALL(N(func_80243F10_9DAF30), GB_KootFavor_Current)
    EVT_IF_EQ(LVar0, 0)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A5)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH1_00A6)
        EVT_END_IF
        EVT_GOTO(90)
    EVT_ELSE
        EVT_IF_EQ(GB_KootFavor_State, 0)
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
        EVT_CALL(N(func_80244224_9DB244), GB_KootFavor_Current)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, LVar0)
        EVT_SET(GB_KootFavor_State, 2)
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
        EVT_SET(GB_KootFavor_State, 1)
        EVT_SET(GB_KootFavor_Current, 0)
    EVT_END_IF
    EVT_LABEL(90)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80253350) = {
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
