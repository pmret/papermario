s32 N(LetterList_RussT)[] = {
    ITEM_LETTER_TO_RUSS_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_RussT) = {
    Call(N(LetterDelivery_Init),
        NPC_RussT, ANIM_RussT_Talk, ANIM_RussT_Idle,
        ITEM_LETTER_TO_RUSS_T, ITEM_NONE,
        MSG_MAC_Gate_0011, MSG_MAC_Gate_0012, MSG_MAC_Gate_0013, MSG_MAC_Gate_0014,
        Ref(N(LetterList_RussT)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_RussT) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_ShyGuy_PlayRunningSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, LVar0, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(2)
    EndLoop
    Return
    End
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
    Call(GetNpcPos, NPC_ShyGuyThief, LVar2, LVar3, LVar4)
    Add(LVar3, 20)
    Call(MakeItemEntity, ITEM_DICTIONARY, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Loop(300)
        Call(GetNpcPos, NPC_ShyGuyThief, LVar2, LVar3, LVar4)
        Add(LVar3, 20)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(RemoveItemEntity, LVar9)
    Return
    End
};

EvtScript N(EVS_ShyGuy_StealDictionary) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, -60)
            IfLt(LVar0, 120)
                BreakLoop
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_ShyGuyThief, -30, 20, -470)
    Call(SetNpcAnimation, NPC_ShyGuyThief, ANIM_ShyGuy_Red_Anim04)
    Wait(1)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_MAC_Gate_0009, 160, 40)
    Exec(N(EVS_ManageCarriedDictionary))
    Thread
        Call(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_VISIBLE)
        Call(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 8)
            Call(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
            Wait(1)
        EndLoop
        Loop(10)
            Add(LVar0, -8)
            Call(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilit3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
        Call(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_HIDDEN)
    EndThread
    Wait(5)
    Call(SetNpcSpeed, NPC_ShyGuyThief, 10)
    Set(LVar0, 21)
    ExecGetTID(N(EVS_ShyGuy_PlayRunningSounds), LVarA)
    Call(NpcMoveTo, NPC_ShyGuyThief, -10, -410, 0)
    KillThread(LVarA)
    Call(PlaySoundAtNpc, NPC_ShyGuyThief, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_ShyGuyThief, -10, 0, -340, 0)
    Set(LVar0, 21)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(EVS_ShyGuy_PlayRunningSounds), LVarA)
    Call(NpcMoveTo, NPC_ShyGuyThief, 45, -186, 0)
    Call(NpcMoveTo, NPC_ShyGuyThief, 139, -67, 0)
    Thread
        Call(NpcMoveTo, NPC_ShyGuyThief, 300, -20, 0)
        Call(NpcMoveTo, NPC_ShyGuyThief, 600, 0, 0)
        KillThread(LVarA)
        Call(SetNpcPos, NPC_ShyGuyThief, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_MAC00_DictionaryStolen, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuyThief) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfGt(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
        Return
    EndIf
    IfNe(GF_MAC00_DictionaryStolen, FALSE)
        Return
    EndIf
    Exec(N(EVS_ShyGuy_StealDictionary))
    Return
    End
};

EvtScript N(EVS_RussT_GetHint) = {
    Call(N(InitRussHintUnlocks))
    IfEq(GF_MAC00_Met_RussT, FALSE)
        Set(GF_MAC00_Met_RussT, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0004)
        Return
    EndIf
    Call(N(GetRussHintCount))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_RussT, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0008)
        Return
    EndIf
    Call(N(GetRussHintMessage))
    IfNe(LVar2, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0005)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0006)
    EndIf
    Call(ContinueSpeech, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, LVar1)
    Call(ContinueSpeech, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0007)
    Return
    End
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
    IfEq(AF_MAC_0D, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000A)
        Set(AF_MAC_0D, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000B)
    EndIf
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_RussDocuments1))
    Switch(LVar0)
        CaseEq(ITEM_DICTIONARY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000D)
            Set(GF_MAC00_DictionaryReturned, TRUE)
            Wait(10)
            EVT_GIVE_STAR_PIECE()
            Wait(10)
            IfEq(GF_MAC00_TranslatedMysteryNote, TRUE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0010)
            EndIf
        CaseEq(ITEM_MYSTERY_NOTE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000F)
            Set(GF_MAC00_TranslatedMysteryNote, TRUE)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000C)
        CaseEq(0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Documents) = {
    Set(LVarA, 0)
    EVT_CHOOSE_KEY_ITEM_FROM(N(ItemList_RussDocuments2))
    Switch(LVar0)
        CaseEq(0)
            IfLt(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
                IfEq(GF_MAC00_TranslatedMysteryNote, TRUE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_0010)
                    Set(LVarA, 1)
                    Return
                EndIf
            Else
            EndIf
        CaseEq(-1)
        CaseDefault
            IfEq(LVar0, ITEM_MYSTERY_NOTE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 0, MSG_MAC_Gate_000E)
                Set(GF_MAC00_TranslatedMysteryNote, TRUE)
                Set(LVarA, 1)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_RussT) = {
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        IfEq(GF_MAC00_DictionaryReturned, FALSE)
            ExecWait(N(EVS_ItemPrompt_Dictionary))
            ExecWait(N(EVS_LetterPrompt_RussT))
            ExecWait(N(EVS_LetterReward_RussT))
            IfNe(LVarC, 0)
                Return
            EndIf
            Return
        EndIf
        ExecWait(N(EVS_ItemPrompt_Documents))
        IfNe(LVarA, 0)
            Return
        EndIf
    EndIf
    ExecWait(N(EVS_RussT_GetHint))
    ExecWait(N(EVS_LetterPrompt_RussT))
    ExecWait(N(EVS_LetterReward_RussT))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_RussT) = {
    Call(N(ResetRussHintsGiven))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RussT)))
    Return
    End
};

NpcSettings N(NpcSettings_RussT) = {
    .defaultAnim = ANIM_RussT_Idle,
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .flags = ENEMY_FLAG_PASSIVE,
};
