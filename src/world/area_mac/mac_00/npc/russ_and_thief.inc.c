s32 N(LetterList_RussT)[] = {
    ITEM_LETTER_TO_RUSS_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_RussT) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_RussT, ANIM_RussT_Talk, ANIM_RussT_Idle,
        ITEM_LETTER_TO_RUSS_T, ITEM_NONE,
        MSG_MAC_Gate_0011, MSG_MAC_Gate_0012, MSG_MAC_Gate_0013, MSG_MAC_Gate_0014,
        EVT_PTR(N(LetterList_RussT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_RussT) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_PlayRunningSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
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

EvtScript N(EVS_ManageCarriedDictionary) = {
    EVT_CALL(GetNpcPos, NPC_ShyGuyThief, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 20)
    EVT_CALL(MakeItemEntity, ITEM_DICTIONARY, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LOOP(300)
        EVT_CALL(GetNpcPos, NPC_ShyGuyThief, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 20)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShyGuy_StealDictionary) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -60)
            EVT_IF_LT(LVar0, 120)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_ShyGuyThief, -30, 20, -470)
    EVT_CALL(SetNpcAnimation, NPC_ShyGuyThief, ANIM_ShyGuy_Red_Anim04)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Gate_0009, 160, 40)
    EVT_EXEC(N(EVS_ManageCarriedDictionary))
    EVT_THREAD
        EVT_CALL(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_VISIBLE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
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
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_HIDDEN)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcSpeed, NPC_ShyGuyThief, 10)
    EVT_SET(LVar0, 21)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PlayRunningSounds), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuyThief, -10, -410, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(PlaySoundAtNpc, NPC_ShyGuyThief, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_ShyGuyThief, -10, 0, -340, 0)
    EVT_SET(LVar0, 21)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(EVS_ShyGuy_PlayRunningSounds), LVarA)
    EVT_CALL(NpcMoveTo, NPC_ShyGuyThief, 45, -186, 0)
    EVT_CALL(NpcMoveTo, NPC_ShyGuyThief, 139, -67, 0)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_ShyGuyThief, 300, -20, 0)
        EVT_CALL(NpcMoveTo, NPC_ShyGuyThief, 600, 0, 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetNpcPos, NPC_ShyGuyThief, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_MAC00_DictionaryStolen, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuyThief) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_MAC00_DictionaryStolen, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_ShyGuy_StealDictionary))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RussT_GetHint) = {
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

EvtScript N(EVS_ItemPrompt_Dictionary) = {
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

EvtScript N(EVS_ItemPrompt_Documents) = {
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

EvtScript N(EVS_NpcInteract_RussT) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
            EVT_EXEC_WAIT(N(EVS_ItemPrompt_Dictionary))
            EVT_EXEC_WAIT(N(EVS_LetterPrompt_RussT))
            EVT_EXEC_WAIT(N(EVS_LetterReward_RussT))
            EVT_IF_NE(LVarC, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_ItemPrompt_Documents))
        EVT_IF_NE(LVarA, 0)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_RussT_GetHint))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_RussT))
    EVT_EXEC_WAIT(N(EVS_LetterReward_RussT))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RussT) = {
    EVT_CALL(N(ResetRussHintsGiven))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RussT)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_RussT) = {
    .defaultAnim = ANIM_RussT_Idle,
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .flags = ENEMY_FLAG_PASSIVE,
};
