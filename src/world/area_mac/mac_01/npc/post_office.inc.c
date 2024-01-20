typedef struct PostOfficeEntry {
    /* 0x00 */ s32 partnerID;
    /* 0x04 */ s32 itemID;
    /* 0x08 */ s32 letterFromMessage;
    /* 0x0C */ s32 letterDescMessage;
    /* 0x10 */ s32 letterBodyMessage;
} PostOfficeEntry; // size = 0x14

#define LETTER_MESSAGES(name) \
    MSG_Document_Letter_##name##_From, \
    MSG_Document_Letter_##name##_Desc, \
    MSG_Document_Letter_##name##_Body

PostOfficeEntry N(PostOfficeLetters)[] = {
    { PARTNER_GOOMBARIO,  ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Goombario2) },
    { PARTNER_GOOMBARIO,  ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Goombario1) },
    { PARTNER_GOOMBARIO,  ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Goombario3) },
    { PARTNER_KOOPER,     ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Kooper3) },
    { PARTNER_KOOPER,     ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Kooper2) },
    { PARTNER_KOOPER,     ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Kooper1) },
    { PARTNER_BOMBETTE,   ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Bombette2) },
    { PARTNER_BOMBETTE,   ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Bombette3) },
    { PARTNER_BOMBETTE,   ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Bombette1) },
    { PARTNER_PARAKARRY,  ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Parakarry1) },
    { PARTNER_PARAKARRY,  ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Parakarry2) },
    { PARTNER_BOW,        ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Bow1) },
    { PARTNER_BOW,        ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Bow2) },
    { PARTNER_WATT,       ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Watt1) },
    { PARTNER_WATT,       ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Watt2) },
    { PARTNER_SUSHIE,     ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Sushie2) },
    { PARTNER_SUSHIE,     ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Sushie1) },
    { PARTNER_LAKILESTER, ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Lakilester2) },
    { PARTNER_LAKILESTER, ITEM_LETTER_TO_KOLORADO, LETTER_MESSAGES(Lakilester1) },
};

API_CALLABLE(N(func_80244E90_805710)) {
    PlayerData* playerData = &gPlayerData;
    s32 var_s2 = -1;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(PostOfficeLetters)); i++) {
        if (playerData->partners[N(PostOfficeLetters)[i].partnerID].enabled &&
            evt_get_variable(NULL, GF_MAC01_UnlockedLetter_00 + i))
        {
            if (!evt_get_variable(NULL, GF_MAC01_ReadLetter_00 + i)) {
                var_s2 = 1;
                break;
            } else {
                var_s2 = 0;
            }
        }
    }
    script->varTable[0] = var_s2;
    return ApiStatus_DONE2;
}

s32 func_80244F5C_8057DC(s32 partner) {
    s32 ret = 0;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(PostOfficeLetters)); i++) {
        if (N(PostOfficeLetters)[i].partnerID == partner &&
            evt_get_variable(NULL, GF_MAC01_UnlockedLetter_00 + i))
        {
            if (ret == 0) {
                ret = 1;
            }
            if (!evt_get_variable(NULL, GF_MAC01_ReadLetter_00 + i)) {
                ret = 2;
                break;
            }
        }
    }
    return ret;
}

API_CALLABLE(N(func_80245018_805898)) {
    D_80262F68 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80245028_8058A8)) {
    PopupMenu* menu = &D_80262C38;
    PartnerPopupProperties* temp_s2;
    PlayerData* playerData = &gPlayerData;
    s32 partnerID;
    s32 cond;
    s32 numEntries;
    s32 i;

    if (isInitialCall) {
        numEntries = 0;

        for (i = 1; i < 12; i++) {
            partnerID = PartnerIDFromMenuIndex[i];
            if (playerData->partners[partnerID].enabled && partnerID != PARTNER_GOOMPA) {
                temp_s2 = &gPartnerPopupProperties[partnerID];
                cond = func_80244F5C_8057DC(partnerID);
                if (cond) {
                    menu->ptrIcon[numEntries] = wPartnerHudScripts[partnerID];
                    menu->userIndex[numEntries] = partnerID;
                    menu->enabled[numEntries] = TRUE;
                    menu->nameMsg[numEntries] = temp_s2->nameMsg;
                    menu->descMsg[numEntries] = temp_s2->worldDescMsg;
                    menu->value[numEntries] = playerData->partners[partnerID].level;
                    if (cond == TRUE) {
                        menu->enabled[numEntries] = FALSE;
                        menu->ptrIcon[numEntries] = wDisabledPartnerHudScripts[partnerID];
                    }
                    numEntries++;
                }
            }
        }
        menu->popupType = POPUP_MENU_POST_OFFICE;
        menu->numEntries = numEntries;
        menu->initialPos = D_80262F68;
        create_standard_popup_menu(menu);
        status_bar_respond_to_changes();
        close_status_bar();
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] == 255) {
        script->varTable[1] = -1;
        return ApiStatus_DONE2;
    }
    partnerID = menu->userIndex[script->functionTemp[1] - 1];
    script->varTable[1] = partnerID; // TODO required to match (use of partnerID temp)
    D_80262F68 = script->functionTemp[1] - 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024522C_805AAC)) {
    s32 vt10 = script->varTable[10];
    PopupMenu* menu = &D_80262C38;
    IconHudScriptPair* scriptPair;
    s32 letterIdx;
    s32 hasRead;
    s32 isUnlocked;
    s32 numEntries;
    u32 i;

    if (isInitialCall) {
        numEntries = 0;

        for (i = 0; i < ARRAY_COUNT(N(PostOfficeLetters)); i++) {
            isUnlocked = evt_get_variable(NULL, GF_MAC01_UnlockedLetter_00 + i);
            hasRead = evt_get_variable(NULL, GF_MAC01_ReadLetter_00 + i);
            if (isUnlocked && vt10 == N(PostOfficeLetters)[i].partnerID) {
                scriptPair = &gItemHudScripts[gItemTable[84].hudElemID];
                menu->userIndex[numEntries] = i;
                menu->nameMsg[numEntries] = N(PostOfficeLetters)[i].letterFromMessage;
                menu->descMsg[numEntries] = N(PostOfficeLetters)[i].letterDescMessage;
                menu->value[numEntries] = 0;
                if (hasRead) {
                    menu->ptrIcon[numEntries] = scriptPair->disabled;
                    menu->enabled[numEntries] = FALSE;
                } else {
                    menu->ptrIcon[numEntries] = scriptPair->enabled;
                    menu->enabled[numEntries] = TRUE;
                }
                numEntries++;
            }
        }
        menu->popupType = POPUP_MENU_READ_LETTER;
        menu->numEntries = numEntries;
        menu->initialPos = 0;
        create_standard_popup_menu(menu);
        status_bar_respond_to_changes();
        close_status_bar();
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = menu->result;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 20) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] == 255) {
        script->varTable[1] = -1;
        return ApiStatus_DONE2;
    }
    letterIdx = menu->userIndex[script->functionTemp[1] - 1];
    script->varTable[1] = letterIdx;
    script->varTable[0] = N(PostOfficeLetters)[letterIdx].letterBodyMessage;
    evt_set_variable(NULL, GF_MAC01_ReadLetter_00 + letterIdx, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80245440_805CC0)) {
    if (gPlayerData.curPartner == script->varTable[10]) {
        script->varTable[1] = 0;
        return ApiStatus_DONE2;
    }
    switch_to_partner(script->varTable[10]);
    script->varTable[1] = 1;
    return ApiStatus_DONE2;
}

s32 N(ItemList_Mailbag)[] = {
    ITEM_MAILBAG,
    ITEM_NONE
};

EvtScript N(EVS_ItemPrompt_Mailbag) = {
    Call(FindKeyItem, ITEM_MAILBAG, LVar0)
    IfEq(LVar0, -1)
        Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0060)
    Else
        Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0061)
        Set(LVar0, Ref(N(ItemList_Mailbag)))
        Set(LVar1, 3)
        ExecWait(N(EVS_ChooseKeyItem))
        Switch(LVar0)
            CaseEq(-1)
                Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0063)
            CaseDefault
                Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0062)
                Set(GF_MAC01_MailbagReturned, TRUE)
                Wait(10)
                EVT_GIVE_STAR_PIECE()
                Wait(10)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Postmaster) = {
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        IfEq(GF_MAC01_MailbagReturned, FALSE)
            ExecWait(N(EVS_ItemPrompt_Mailbag))
            Return
        EndIf
    EndIf
    IfEq(GF_MAC01_Met_Postmaster, FALSE)
        Set(GF_MAC01_Met_Postmaster, TRUE)
        Call(N(func_80244E90_805710))
        Switch(LVar0)
            CaseEq(-1)
                Return
            CaseEq(1)
                Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0055)
        EndSwitch
    Else
        Call(N(func_80244E90_805710))
        Switch(LVar0)
            CaseEq(-1)
                Return
            CaseEq(0)
                Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0057)
            CaseEq(1)
                Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0056)
        EndSwitch
    EndIf
    Call(N(func_80245018_805898))
    Label(0)
    Call(N(func_80245028_8058A8))
    Wait(5)
    IfEq(LVar1, -1)
        Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_0059)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Goto(99)
        Else
            Goto(0)
        EndIf
    EndIf
    Set(LVarA, LVar1)
    Call(N(func_8024522C_805AAC))
    Wait(5)
    IfEq(LVar1, -1)
        Goto(0)
    EndIf
    Call(N(func_80245440_805CC0))
    IfEq(LVar1, 1)
        Wait(30)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 1)
    EndIf
    Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005C)
    Call(ShowMessageAtScreenPos, LVar0, 160, 40)
    Wait(5)
    IfLt(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
        Goto(99)
    EndIf
    Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005A)
    Call(ShowChoice, MSG_Choice_000D)
    Call(CloseMessage)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Label(99)
    IfEq(GF_MAC01_CheckedForLetters, FALSE)
        Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005D)
        Set(GF_MAC01_CheckedForLetters, TRUE)
    Else
        Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_MAC_Plaza_005E)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Postmaster_Epilogue) = {
    Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_Idle, 0, MSG_Outro_0043)
    Return
    End
};

EvtScript N(EVS_NpcInit_Postmaster) = {
    Call(SetNpcCollisionSize, NPC_SELF, 36, 42)
    Switch(GB_StoryProgress)
        CaseGe(STORY_EPILOGUE)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Postmaster_Epilogue)))
        CaseDefault
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Postmaster)))
    EndSwitch
    IfGe(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        Set(GF_MAC01_UnlockedLetter_01, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Set(GF_MAC01_UnlockedLetter_00, TRUE)
    EndIf
    Set(GF_MAC01_UnlockedLetter_02, TRUE)
    IfGe(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_05, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_04, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        Set(GF_MAC01_UnlockedLetter_03, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        Set(GF_MAC01_UnlockedLetter_08, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        Set(GF_MAC01_UnlockedLetter_06, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        Set(GF_MAC01_UnlockedLetter_07, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_09, TRUE)
    EndIf
    IfGe(GB_IWA00_Whacka_HitCount, 2)
        Set(GF_MAC01_UnlockedLetter_0A, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        Set(GF_MAC01_UnlockedLetter_0B, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_0C, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_0D, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
        Set(GF_MAC01_UnlockedLetter_0E, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
        Set(GF_MAC01_UnlockedLetter_10, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_STAR_HAVEN)
        Set(GF_MAC01_UnlockedLetter_0F, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        Set(GF_MAC01_UnlockedLetter_12, TRUE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Set(GF_MAC01_UnlockedLetter_11, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Parakarry) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_MAC_Plaza_0064)
    Return
    End
};

AnimID N(ExtraAnims_Parakarry)[] = {
    ANIM_WorldParakarry_Still,
    ANIM_WorldParakarry_Idle,
    ANIM_WorldParakarry_Talk,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcInit_Parakarry) = {
    Call(SetNpcCollisionSize, NPC_SELF, 37, 26)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Parakarry)))
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
    Return
    End
};

EvtScript N(EVS_CarryItem_PostOfficeShyGuy) = {
    Call(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
    Add(LVar3, 20)
    Call(MakeItemEntity, ITEM_MAILBAG, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Loop(140)
        Call(GetNpcPos, NPC_PostOfficeShyGuy, LVar2, LVar3, LVar4)
        Add(LVar3, 20)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(RemoveItemEntity, LVar9)
    Return
    End
};

EvtScript N(EVS_PostOfficeShyGuy_Escape) = {
    Call(SetNpcPos, NPC_PostOfficeShyGuy, 357, 20, -440)
    Call(SetNpcAnimation, NPC_PostOfficeShyGuy, ANIM_ShyGuy_Red_Anim04)
    Exec(N(EVS_CarryItem_PostOfficeShyGuy))
    Call(DisablePlayerInput, TRUE)
    Wait(60)
    Call(PlaySoundAtNpc, NPC_PostOfficeShyGuy, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_PostOfficeShyGuy, 247, 20, -440, 20)
    Set(LVar0, 6)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024E6F8_80EF78), LVarA)
    Call(NpcMoveTo, NPC_PostOfficeShyGuy, 180, -410, 20)
    Call(NpcMoveTo, NPC_PostOfficeShyGuy, 150, -333, 8)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_PostOfficeShyGuy, NPC_DISPOSE_LOCATION)
    Set(GF_MAC01_MailbagStolen, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Scene_MailbagTheft) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfGt(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
        Return
    EndIf
    IfNe(GF_MAC01_MailbagStolen, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_Postmaster, ANIM_Postmaster_Talk, ANIM_Postmaster_IdleAlt, 0, MSG_MAC_Plaza_005F)
    Exec(N(EVS_PostOfficeShyGuy_Escape))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
