#include "mac_00.h"
#include "effects.h"

#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_ShyGuy_01) = {
    .height = 23,
    .radius = 22,
    .level = 14,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_Toad_03) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_RussT)[] = {
    ITEM_LETTER04,
    ITEM_NONE 
};

EvtScript N(EVS_RussT_LetterPrompt) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_RussT, ANIM_RussT_Talk, ANIM_RussT_Idle,
        ITEM_LETTER04, ITEM_NONE,
        MSG_MAC_Gate_0011, MSG_MAC_Gate_0012, MSG_MAC_Gate_0013, MSG_MAC_Gate_0014,
        EVT_PTR(N(LetterList_RussT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RussT_LetterReward) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_SET(LVar0, ITEM_STAR_PIECE)
        EVT_SET(LVar1, ITEM_TYPE_STAR_PIECE)
        EVT_EXEC_WAIT(N(GiveKeyReward))
        EVT_CALL(AddStarPieces, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248ED0_7F3BE0) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_B0000021, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

typedef struct RussTLoreEntry {
    /* 0x00 */ s32 hintMessage;
    /* 0x04 */ s32 progressRequired;
    /* 0x08 */ s32 isAvailableFlag;
    /* 0x0C */ s32 savedFlag;
    /* 0x10 */ s32 hasBeenGivenFlag;
} RussTLoreEntry; // size = 0x14

RussTLoreEntry N(RussTLore)[] = {
    { MSG_RussTHint_0000, STORY_CH0_WAKE_UP,             AF_MAC_45, GF_MAC00_RussT_HeardLore_00, AF_MAC_77 }, 
    { MSG_RussTHint_0001, STORY_CH0_WAKE_UP,             AF_MAC_46, GF_MAC00_RussT_HeardLore_01, AF_MAC_78 }, 
    { MSG_RussTHint_0002, STORY_CH0_WAKE_UP,             AF_MAC_47, GF_MAC00_RussT_HeardLore_02, AF_MAC_79 }, 
    { MSG_RussTHint_0003, STORY_CH0_WAKE_UP,             AF_MAC_48, GF_MAC00_RussT_HeardLore_03, AF_MAC_7A }, 
    { MSG_RussTHint_0004, STORY_CH0_BEGAN_PEACH_MISSION, AF_MAC_49, GF_MAC00_RussT_HeardLore_04, AF_MAC_7B }, 
    { MSG_RussTHint_0005, STORY_CH0_BEGAN_PEACH_MISSION, AF_MAC_4A, GF_MAC00_RussT_HeardLore_05, AF_MAC_7C }, 
    { MSG_RussTHint_0006, STORY_CH0_BEGAN_PEACH_MISSION, AF_MAC_4B, GF_MAC00_RussT_HeardLore_06, AF_MAC_7D }, 
    { MSG_RussTHint_0007, STORY_CH0_BEGAN_PEACH_MISSION, AF_MAC_4C, GF_MAC00_RussT_HeardLore_07, AF_MAC_7E }, 
    { MSG_RussTHint_0008, STORY_CH1_BEGAN_PEACH_MISSION, AF_MAC_4D, GF_MAC00_RussT_HeardLore_08, AF_MAC_7F }, 
    { MSG_RussTHint_0009, STORY_CH1_BEGAN_PEACH_MISSION, AF_MAC_4E, GF_MAC00_RussT_HeardLore_09, AF_MAC_80 }, 
    { MSG_RussTHint_000A, STORY_CH1_BEGAN_PEACH_MISSION, AF_MAC_4F, GF_MAC00_RussT_HeardLore_0A, AF_MAC_81 }, 
    { MSG_RussTHint_000B, STORY_CH1_BEGAN_PEACH_MISSION, AF_MAC_50, GF_MAC00_RussT_HeardLore_0B, AF_MAC_82 }, 
    { MSG_RussTHint_000C, STORY_CH2_BEGAN_PEACH_MISSION, AF_MAC_51, GF_MAC00_RussT_HeardLore_0C, AF_MAC_83 }, 
    { MSG_RussTHint_000D, STORY_CH2_BEGAN_PEACH_MISSION, AF_MAC_52, GF_MAC00_RussT_HeardLore_0D, AF_MAC_84 }, 
    { MSG_RussTHint_000E, STORY_CH2_BEGAN_PEACH_MISSION, AF_MAC_53, GF_MAC00_RussT_HeardLore_0E, AF_MAC_85 }, 
    { MSG_RussTHint_000F, STORY_CH2_BEGAN_PEACH_MISSION, AF_MAC_54, GF_MAC00_RussT_HeardLore_0F, AF_MAC_86 }, 
    { MSG_RussTHint_0010, STORY_CH3_BEGAN_PEACH_MISSION, AF_MAC_55, GF_MAC00_RussT_HeardLore_10, AF_MAC_87 }, 
    { MSG_RussTHint_0011, STORY_CH3_BEGAN_PEACH_MISSION, AF_MAC_56, GF_MAC00_RussT_HeardLore_11, AF_MAC_88 }, 
    { MSG_RussTHint_0012, STORY_CH3_BEGAN_PEACH_MISSION, AF_MAC_57, GF_MAC00_RussT_HeardLore_12, AF_MAC_89 }, 
    { MSG_RussTHint_0013, STORY_CH3_BEGAN_PEACH_MISSION, AF_MAC_58, GF_MAC00_RussT_HeardLore_13, AF_MAC_8A }, 
    { MSG_RussTHint_0014, STORY_CH4_BEGAN_PEACH_MISSION, AF_MAC_59, GF_MAC00_RussT_HeardLore_14, AF_MAC_8B }, 
    { MSG_RussTHint_0015, STORY_CH4_BEGAN_PEACH_MISSION, AF_MAC_5A, GF_MAC00_RussT_HeardLore_15, AF_MAC_8C }, 
    { MSG_RussTHint_0016, STORY_CH4_BEGAN_PEACH_MISSION, AF_MAC_5B, GF_MAC00_RussT_HeardLore_16, AF_MAC_8D }, 
    { MSG_RussTHint_0017, STORY_CH4_BEGAN_PEACH_MISSION, AF_MAC_5C, GF_MAC00_RussT_HeardLore_17, AF_MAC_8E }, 
    { MSG_RussTHint_0018, STORY_CH5_BEGAN_PEACH_MISSION, AF_MAC_5D, GF_MAC00_RussT_HeardLore_18, AF_MAC_8F }, 
    { MSG_RussTHint_0019, STORY_CH5_BEGAN_PEACH_MISSION, AF_MAC_5E, GF_MAC00_RussT_HeardLore_19, AF_MAC_90 }, 
    { MSG_RussTHint_001A, STORY_CH5_BEGAN_PEACH_MISSION, AF_MAC_5F, GF_MAC00_RussT_HeardLore_1A, AF_MAC_91 }, 
    { MSG_RussTHint_001B, STORY_CH5_BEGAN_PEACH_MISSION, AF_MAC_60, GF_MAC00_RussT_HeardLore_1B, AF_MAC_92 }, 
    { MSG_RussTHint_001C, STORY_CH6_BEGAN_PEACH_MISSION, AF_MAC_61, GF_MAC00_RussT_HeardLore_1C, AF_MAC_93 }, 
    { MSG_RussTHint_001D, STORY_CH6_BEGAN_PEACH_MISSION, AF_MAC_62, GF_MAC00_RussT_HeardLore_1D, AF_MAC_94 }, 
    { MSG_RussTHint_001E, STORY_CH6_BEGAN_PEACH_MISSION, AF_MAC_63, GF_MAC00_RussT_HeardLore_1E, AF_MAC_95 }, 
    { MSG_RussTHint_001F, STORY_CH6_BEGAN_PEACH_MISSION, AF_MAC_64, GF_MAC00_RussT_HeardLore_1F, AF_MAC_96 }, 
    { MSG_RussTHint_0020, STORY_CH7_BEGAN_PEACH_MISSION, AF_MAC_65, GF_MAC00_RussT_HeardLore_20, AF_MAC_97 }, 
    { MSG_RussTHint_0021, STORY_CH7_BEGAN_PEACH_MISSION, AF_MAC_66, GF_MAC00_RussT_HeardLore_21, AF_MAC_98 }, 
    { MSG_RussTHint_0022, STORY_CH7_BEGAN_PEACH_MISSION, AF_MAC_67, GF_MAC00_RussT_HeardLore_22, AF_MAC_99 }, 
    { MSG_RussTHint_0023, STORY_CH7_BEGAN_PEACH_MISSION, AF_MAC_68, GF_MAC00_RussT_HeardLore_23, AF_MAC_9A }, 
};

API_CALLABLE(N(ResetRussHintsGiven)) {
    RussTLoreEntry* entry = N(RussTLore);
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(RussTLore)); i++, entry++) {
        evt_set_variable(script, entry->hasBeenGivenFlag, FALSE);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitRussHintUnlocks)) {
    RussTLoreEntry* entry = N(RussTLore);
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(RussTLore)); i++, entry++) {
        s32 progress = evt_get_variable(script, GB_StoryProgress);

        evt_set_variable(script, entry->isAvailableFlag, progress >= entry->progressRequired);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetRussHintMessage)) {
    RussTLoreEntry* entry = N(RussTLore);
    s32 hasHintMessage = FALSE;
    s32 count = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(RussTLore)); i++, entry++) {
        if (evt_get_variable(script, entry->isAvailableFlag)) {
            if (!evt_get_variable(script, entry->savedFlag)) {
                hasHintMessage = TRUE;
                break;
            } else {
                if (!evt_get_variable(script, entry->hasBeenGivenFlag)) {
                    count++;
                }
            }
        }
    }

    if (!hasHintMessage) {
        entry = N(RussTLore);
        i = 0;
        if (count != 0) {
            s32 chosenHint = rand_int(count - 1);

            count = 0;
            
            for (i = hasHintMessage; i < ARRAY_COUNT(N(RussTLore)); i++, entry++) {
                if (evt_get_variable(script, entry->isAvailableFlag) &&
                    !evt_get_variable(script, entry->hasBeenGivenFlag) &&
                    count++ >= chosenHint)
                {
                    break;
                }
            }
        }
    }
    script->varTable[0] = i;
    script->varTable[1] = entry->hintMessage;
    script->varTable[2] = hasHintMessage;
    evt_set_variable(script, entry->savedFlag, TRUE);
    evt_set_variable(script, entry->hasBeenGivenFlag, TRUE);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetRussHintCount)) {
    RussTLoreEntry* entry = N(RussTLore);
    s32 count = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(RussTLore)); i++, entry++) {
        if (evt_get_variable(script, entry->isAvailableFlag) && !evt_get_variable(script, entry->hasBeenGivenFlag)) {
            count++;
        }
    }
    script->varTable[0] = count;
    return ApiStatus_DONE2;
}

EvtScript N(D_802491E8_7F3EF8) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_DICTIONARY, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(300)
        EVT_CALL(GetNpcPos, NPC_ShyGuy_01, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802492DC_7F3FEC) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -60)
            EVT_IF_LT(LVar0, 120)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_ShyGuy_01, -30, 20, -470)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_01, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Gate_0009, 160, 40)
    EVT_EXEC(N(D_802491E8_7F3EF8))
    EVT_THREAD
        EVT_CALL(SetGroupEnabled, MODEL_intel_inn, 1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_OPEN, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 8)
            EVT_CALL(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_ADD(LVar0, -8)
            EVT_CALL(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_CLOSE, 0)
        EVT_CALL(SetGroupEnabled, MODEL_intel_inn, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_01, 10)
    EVT_SET(LVar0, 21)
    EVT_EXEC_GET_TID(N(D_80248ED0_7F3BE0), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, -10, -410, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_ShyGuy_01, -10, 0, -340, 0)
    EVT_SET(LVar0, 21)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_80248ED0_7F3BE0), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 45, -186, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 139, -67, 0)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 300, -20, 0)
        EVT_CALL(NpcMoveTo, NPC_ShyGuy_01, 600, 0, 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetNpcPos, NPC_ShyGuy_01, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_MAC00_DictionaryStolen, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC00_DictionaryStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(D_802492DC_7F3FEC))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249700_7F4410) = {
    EVT_CALL(N(InitRussHintUnlocks))
    EVT_IF_EQ(GF_MAC00_Met_RussT, FALSE)
        EVT_SET(GF_MAC00_Met_RussT, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0004)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetRussHintCount))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_RussT, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0008)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetRussHintMessage))
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0005)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0006)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, LVar1)
    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0007)
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_RussDocuments1)[] = {
    ITEM_DICTIONARY,
    ITEM_MYSTERY_NOTE,
    ITEM_SUSPICIOUS_NOTE,
    ITEM_NONE
};

s32 N(ItemList_RussDocuments2)[] = {
    ITEM_MYSTERY_NOTE,
    ITEM_SUSPICIOUS_NOTE,
    ITEM_NONE
};

EvtScript N(D_80249880_7F4590) = {
    EVT_IF_EQ(AF_MAC_0D, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000A)
        EVT_SET(AF_MAC_0D, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000B)
    EVT_END_IF
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_RussDocuments1))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ITEM_DICTIONARY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000D)
            EVT_SET(GF_MAC00_DictionaryReturned, TRUE)
            EVT_WAIT(10)
            EVT_GIVE_STAR_PIECE()
            EVT_WAIT(10)
            EVT_IF_EQ(GF_MAC00_TranslatedMysteryNote, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0010)
            EVT_END_IF
        EVT_CASE_EQ(ITEM_MYSTERY_NOTE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000F)
            EVT_SET(GF_MAC00_TranslatedMysteryNote, TRUE)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000C)
        EVT_CASE_EQ(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249A7C_7F478C) = {
    EVT_SET(LVarA, 0)
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_RussDocuments2))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_LT(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
                EVT_IF_EQ(GF_MAC00_TranslatedMysteryNote, TRUE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0010)
                    EVT_SET(LVarA, 1)
                    EVT_RETURN
                EVT_END_IF
            EVT_ELSE
            EVT_END_IF
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LVar0, ITEM_MYSTERY_NOTE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000E)
                EVT_SET(GF_MAC00_TranslatedMysteryNote, TRUE)
                EVT_SET(LVarA, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Luigi_01) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
            EVT_EXEC_WAIT(N(D_80249880_7F4590))
            EVT_EXEC_WAIT(N(EVS_RussT_LetterPrompt))
            EVT_EXEC_WAIT(N(EVS_RussT_LetterReward))
            EVT_IF_NE(LVarC, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
        EVT_EXEC_WAIT(N(D_80249A7C_7F478C))
        EVT_IF_NE(LVarA, 0)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(D_80249700_7F4410))
    EVT_EXEC_WAIT(N(EVS_RussT_LetterPrompt))
    EVT_EXEC_WAIT(N(EVS_RussT_LetterReward))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Luigi_01) = {
    EVT_CALL(N(ResetRussHintsGiven))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Luigi_01)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Luigi_01) = {
    .defaultAnim = ANIM_RussT_Idle,
    .height = 30,
    .radius = 24,
    .level = 99,
    .flags = ENEMY_FLAGS_1,
};

EvtScript N(EVS_NpcAI_ShyGuy_03) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim0C)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_02, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_02, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_ShyGuy_02, 400, 20, -300, 20)
    EVT_CALL(NpcFacePlayer, NPC_ShyGuy_02, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11, ANIM_ShyGuy_Red_Anim01, 0, MSG_MAC_Gate_0002)
    EVT_CALL(ShowSweat, 22, 1, 45, 1, 0, 0, 0, 0, 20)
    EVT_WAIT(10)
    EVT_CALL(ShowSweat, 22, 1, 45, 1, 0, 0, 0, 0, 20)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
        EVT_CALL(PlayerMoveTo, 410, -340, 0)
    EVT_END_THREAD
    EVT_SET(LVar0, 22)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_203F, 0)
    EVT_EXEC_GET_TID(N(D_80248ED0_7F3BE0), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuy_02, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_ShyGuy_02, 170, -140, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_ShyGuy_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Toad_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Toad_01, 170, 20, -140)
    EVT_CALL(SetNpcFlagBits, NPC_Toad_01, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_Toad_01, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_HarryT_Run)
    EVT_CALL(NpcMoveTo, NPC_Toad_01, 430, -373, 0)
    EVT_CALL(SetNpcPos, NPC_Toad_01, 430, 20, -373)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_HarryT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Toad_01, NPC_FLAG_100, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_01, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Gate_0003)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono5, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono6, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkPositionFunc.inc.c"

EvtScript N(EVS_NpcHit_ShyGuy_03) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar1, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkPositionFunc), 266, -350, 366, -253)
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_NONE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203E, 0)
    EVT_SET(GF_MAC00_ShyGuyChasedFromShop, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetEnemyFlagBits, NPC_ShyGuy_02, ENEMY_FLAGS_8000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShyGuy_02) = {
    EVT_CALL(SpeakToPlayer, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11, ANIM_ShyGuy_Red_Anim01, 0, MSG_MAC_Gate_0001)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                EVT_SET(GF_MAC01_ShyGuyTookOverShop, TRUE)
                EVT_CALL(SetNpcPos, NPC_SELF, 430, 20, -373)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShyGuy_02)))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono1, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono2, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono3, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono4, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono5, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono6, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
                EVT_CALL(SetNpcPos, NPC_SELF, 430, 20, -373)
                EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy_03)))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_EXEC_WAIT(ItemShopInteract)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Gate_0000)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                EVT_CALL(SetNpcPos, NPC_Toad_01, NPC_DISPOSE_LOCATION)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, 105, 0, -40)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

#include "npc/dojo_members.inc.c"

EvtScript N(EVS_NpcInteract_Toad_10) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Gate_0044)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Gate_0045)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0046)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_0047)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Gate_0048)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_0049)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_004A)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Gate_004B)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Gate_004C)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Gate_004D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_004E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Gate_004F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_0050)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Gate_0051)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0052)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Gate_0053)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0036)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Gate_0054)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Gate_0055)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0056)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_0057)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Gate_0058)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_0059)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Gate_005A)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_005B)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Gate_005C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_005D)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Gate_005E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_005F)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Gate_0060)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0037)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Gate_0061)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Gate_0062)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0063)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_0064)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Gate_0065)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_0066)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_0067)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Gate_0068)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Gate_0069)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Gate_006A)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_006B)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Gate_006C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_006D)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Gate_006E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_006F)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Gate_0070)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0038)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Gate_0071)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Gate_0072)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0073)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_0074)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Gate_0075)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_0076)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Gate_0077)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_0078)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Gate_0079)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Gate_007A)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Gate_007B)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Gate_007C)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Gate_007D)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0039)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_10)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKid_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WaterfrontHouse_DoorLocked) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Gate_004A)
                EVT_SET(LVar1, MSG_MAC_Gate_0067)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Gate_004B)
                    EVT_SET(LVar1, MSG_MAC_Gate_0068)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Gate_004C)
                    EVT_SET(LVar1, MSG_MAC_Gate_0069)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, LVar0, 160, 40)
    EVT_WAIT(5)
    EVT_CALL(ShowMessageAtScreenPos, LVar1, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "npc/trading_toad.inc.c"

StaticNpc N(NpcData_ShyGuy_01)[] = {
    {
        .id = NPC_ShyGuy_01,
        .settings = &N(NpcSettings_ShyGuy_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
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
    },
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_ShyGuy_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_ShyGuy_02),
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
        .tattle = MSG_NpcTattle_MAC_ShyGuyShopOwner,
    },
    {
        .id = NPC_ShyGuy_03,
        .settings = &N(NpcSettings_ShyGuy_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_IGNORE_TOUCH,
        .init = &N(EVS_NpcInit_ShyGuy_03),
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
        .tattle = MSG_NpcTattle_MAC_ShyGuyShopOwner,
    },
};

StaticNpc N(NpcData_Luigi_01) = {
    .id = NPC_RussT,
    .settings = &N(NpcSettings_Luigi_01),
    .pos = { -66.0f, 20.0f, -532.0f },
    .yaw = 119,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
    .init = &N(EVS_NpcInit_Luigi_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_RussT_Idle,
        .walk   = ANIM_RussT_Idle,
        .run    = ANIM_RussT_Idle,
        .chase  = ANIM_RussT_Idle,
        .anim_4 = ANIM_RussT_Idle,
        .anim_5 = ANIM_RussT_Idle,
        .death  = ANIM_RussT_Idle,
        .hit    = ANIM_RussT_Idle,
        .anim_8 = ANIM_RussT_Idle,
        .anim_9 = ANIM_RussT_Idle,
        .anim_A = ANIM_RussT_Idle,
        .anim_B = ANIM_RussT_Idle,
        .anim_C = ANIM_RussT_Idle,
        .anim_D = ANIM_RussT_Idle,
        .anim_E = ANIM_RussT_Idle,
        .anim_F = ANIM_RussT_Idle,
    },
    .tattle = MSG_NpcTattle_RussT,
};

StaticNpc N(NpcData_Toad_01)[] = {
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 430.0f, 20.0f, -373.0f },
        .yaw = 223,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 223,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_Toad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
};

s32 N(D_8024CFFC_7F7D0C)[] = {
    ANIM_TheMaster_Still,
    ANIM_TheMaster_Idle,
    ANIM_TheMaster_Walk,
    ANIM_TheMaster_Talk,
    -1
};

s32 N(D_8024D010_7F7D20)[] = {
    ANIM_Chan_Still,
    ANIM_Chan_Idle,
    ANIM_Chan_Walk,
    ANIM_Chan_Run,
    -1
};

s32 N(D_8024D024_7F7D34)[] = {
    ANIM_Lee_Still,
    ANIM_Lee_Idle,
    ANIM_Lee_Walk,
    ANIM_Lee_Talk,
    -1
};

StaticNpc N(NpcData_Toad_03)[] = {
    {
        .id = NPC_TheMaster,
        .settings = &N(NpcSettings_Toad_03),
        .pos = { 375.0f, 115.0f, -440.0f },
        .yaw = 225,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_800000,
        .init = &N(EVS_NpcInit_TheMaster),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_TheMaster_Idle,
            .walk   = ANIM_TheMaster_Still,
            .run    = ANIM_TheMaster_Still,
            .chase  = ANIM_TheMaster_Still,
            .anim_4 = ANIM_TheMaster_Still,
            .anim_5 = ANIM_TheMaster_Still,
            .death  = ANIM_TheMaster_Still,
            .hit    = ANIM_TheMaster_Still,
            .anim_8 = ANIM_TheMaster_Still,
            .anim_9 = ANIM_TheMaster_Still,
            .anim_A = ANIM_TheMaster_Still,
            .anim_B = ANIM_TheMaster_Still,
            .anim_C = ANIM_TheMaster_Still,
            .anim_D = ANIM_TheMaster_Still,
            .anim_E = ANIM_TheMaster_Still,
            .anim_F = ANIM_TheMaster_Still,
        },
        .extraAnimations = N(D_8024CFFC_7F7D0C),
        .tattle = MSG_NpcTattle_TheMaster,
    },
    {
        .id = NPC_Chan,
        .settings = &N(NpcSettings_Toad_03),
        .pos = { 310.0f, 115.0f, -390.0f },
        .yaw = 45,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_800000,
        .init = &N(EVS_NpcInit_Chan),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Chan_Idle,
        },
        .extraAnimations = N(D_8024D010_7F7D20),
        .tattle = MSG_NpcTattle_Chan,
    },
    {
        .id = NPC_Lee,
        .settings = &N(NpcSettings_Toad_03),
        .pos = { 330.0f, 115.0f, -410.0f },
        .yaw = 45,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_800000,
        .init = &N(EVS_NpcInit_Lee),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Lee_Idle,
        },
        .extraAnimations = N(D_8024D024_7F7D34),
        .tattle = MSG_NpcTattle_Lee,
    },
};

StaticNpc N(NpcData_Quizmo_Unused) = {
    .id = NPC_ChuckQuizmo,
    .settings = &N(Quizmo_NpcSettings),
    .pos = { 545.0f, 20.0f, 150.0f },
    .yaw = 30,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_4000,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_00 }},
    .drops = QUIZMO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

StaticNpc N(NpcData_Waterfront_Family)[] = {
    {
        .id = NPC_Waterfront_Dad,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -496.0f, 20.0f, 218.0f },
        .yaw = 133,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_Toad_10),
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_LuckyCastleWorker,
    },
    {
        .id = NPC_Waterfront_Mom,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -566.0f, 20.0f, 267.0f },
        .yaw = 133,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_ThreeSisters_05),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_Homemaker,
    },
    {
        .id = NPC_Waterfront_Kid1,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -508.0f, 20.0f, 324.0f },
        .yaw = 313,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_ToadKid_01),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_FriendlyToadKid,
    },
    {
        .id = NPC_Waterfront_Kid2,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -480.0f, 20.0f, 329.0f },
        .yaw = 313,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_ToadKid_02),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_PowerHungryToadKid,
    },
};

StaticNpc N(NpcData_PrizeToad) = {
    .id = NPC_Toad_11,
    .settings = &N(NpcSettings_Toad_Stationary),
    .pos = { -112.0f, 0.0f, -62.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
    .init = &N(EVS_NpcInit_TradingToad),
    .drops = TOAD_DROPS,
    .animations = {
        .idle   = ANIM_Toad_Pink_Idle,
        .walk   = ANIM_Toad_Pink_Walk,
        .run    = ANIM_Toad_Pink_Run,
        .chase  = ANIM_Toad_Pink_Run,
        .anim_4 = ANIM_Toad_Pink_Idle,
        .anim_5 = ANIM_Toad_Pink_Idle,
        .death  = ANIM_Toad_Pink_Idle,
        .hit    = ANIM_Toad_Pink_Disappointed,
        .anim_8 = ANIM_Toad_Pink_Run,
        .anim_9 = ANIM_Toad_Pink_Run,
        .anim_A = ANIM_Toad_Pink_Run,
        .anim_B = ANIM_Toad_Pink_Run,
        .anim_C = ANIM_Toad_Pink_Run,
        .anim_D = ANIM_Toad_Pink_Run,
        .anim_E = ANIM_Toad_Pink_Run,
        .anim_F = ANIM_Toad_Pink_Run,
    },
    .tattle = MSG_NpcTattle_PrizeToad,
};

extern StaticNpc N(NpcData_Toad_04)[10];

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad_03)),
    NPC_GROUP(N(NpcData_ShyGuy_01)),
    NPC_GROUP(N(NpcData_Luigi_01)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_Toad_04)),
    NPC_GROUP(N(NpcData_Waterfront_Family)),
    NPC_GROUP(N(NpcData_PrizeToad)),
    {}
};
