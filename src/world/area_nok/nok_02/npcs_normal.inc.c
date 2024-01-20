API_CALLABLE(N(DoCircleSprint)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;
    f32 yaw;

    if (isInitialCall) {
        script->functionTempPtr[1] = npc = (Npc*) evt_get_variable(script, *args++);
        npc->moveToPos.x = (evt_get_variable(script, *args++) + npc->pos.x) * 0.5f;
        npc->moveToPos.z = (evt_get_variable(script, *args++) + npc->pos.z) * 0.5f;
        npc->moveToPos.y = dist2D(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        script->functionTemp[2] = atan2(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        npc->duration = 0;
    }

    npc = script->functionTempPtr[1];
    npc->pos.x = npc->moveToPos.x;
    npc->pos.z = npc->moveToPos.z;

    npc->duration += 9;
    if (npc->duration >= 360) {
        npc->duration = 360;
    }
    yaw = script->functionTemp[2] + npc->duration;
    npc->yaw = clamp_angle(yaw + 90.0f);
    npc_move_heading(npc, npc->moveToPos.y, yaw);

    if (npc->duration == 360) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcInteract_Koopa_01_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0058)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0059)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005A)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_01_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_01_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_02_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0060)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0061)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0062)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0063)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_02_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_02_Normal)))
    Return
    End
};

EvtScript N(EVS_Koopa_03_CircleSprint) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Run)
    Call(EnableNpcBlur, NPC_Koopa_03, TRUE)
    Call(GetNpcPointer, NPC_Koopa_03, LVarF)
    Call(N(DoCircleSprint), LVarF, -150, 15)
    Call(EnableNpcBlur, NPC_Koopa_03, FALSE)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Idle)
    Wait(5)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_03_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0064)
            ExecWait(N(EVS_Koopa_03_CircleSprint))
            Call(ContinueSpeech, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0065)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0066)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0067)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0068)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0069)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_03_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_04_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006A)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006B)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006C)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006D)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006E)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_04_Normal)))
    Return
    End
};

EvtScript N(EVS_Dueling_Bobombs) = {
    Label(10)
        IfEq(AF_NOK_10, FALSE)
            Wait(1)
            Goto(10)
        EndIf
        IfEq(AF_NOK_11, TRUE)
            Wait(1)
            Goto(10)
        EndIf
        Call(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Run)
        Wait(10)
        Call(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Idle)
        Wait(3)
        Call(GetNpcPos, NPC_Bobomb_02, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_Bobomb_02, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
        Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        Wait(30)
        Label(20)
            IfEq(AF_NOK_10, FALSE)
                Wait(1)
                Goto(20)
            EndIf
            IfEq(AF_NOK_11, TRUE)
                Wait(1)
                Goto(20)
            EndIf
        Call(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Run)
        Wait(10)
        Call(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Idle)
        Wait(3)
        Call(GetNpcPos, NPC_Bobomb_01, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_Bobomb_01, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
        Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        Wait(30)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Scene_ConfrontBobombs) = {
    IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH5_2)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_BOMBETTE)
            Set(AF_NOK_11, TRUE)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_007C)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007D)
            Call(DisablePartnerAI, 0)
            Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bobomb_01, MSG_CH1_007E)
            Call(EnablePartnerAI)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007F)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0080)
            Call(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Idle)
            Call(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Idle)
            Set(GF_NOK02_ConfrontedBobombs, TRUE)
            Set(GF_MAC02_KootFavor_CurrentComplete, TRUE)
        Else
            Set(AF_NOK_11, TRUE)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_007C)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_0081)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0082)
            Set(AF_NOK_11, FALSE)
        EndIf
    Else
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_BOMBETTE)
            Set(AF_NOK_11, TRUE)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_PARTNER, MSG_CH1_0077)
            Call(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_PARTNER, MSG_CH1_0078)
            Call(DisablePartnerAI, 0)
            Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bobomb_01, MSG_CH1_0079)
            Call(EnablePartnerAI)
            Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007A)
            Set(AF_NOK_11, FALSE)
        Else
            Set(AF_NOK_11, TRUE)
            Call(SpeakToPlayer, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0073)
            Call(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bobomb_02, MSG_CH1_0074)
            Call(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0075)
            Call(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bobomb_02, MSG_CH1_0076)
            Set(AF_NOK_11, FALSE)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(AF_NOK_0F, FALSE)
                Call(GetCurrentPartnerID, LVar0)
                IfEq(LVar0, PARTNER_BOMBETTE)
                    Set(AF_NOK_0F, TRUE)
                    Call(NpcFacePlayer, NPC_SELF, 0)
                    Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_006F)
                    Call(DisablePartnerAI, 0)
                    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_0070)
                    Call(EnablePartnerAI)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0071)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
                EndIf
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
            EndIf
        CaseGe(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK02_ConfrontedBobombs, FALSE)
                ExecWait(N(EVS_Scene_ConfrontBobombs))
            Else
                Set(AF_NOK_11, TRUE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007F)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0083)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK02_ConfrontedBobombs, FALSE)
                ExecWait(N(EVS_Scene_ConfrontBobombs))
            Else
                Set(AF_NOK_11, TRUE)
                Call(SpeakToNpc, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0080)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0084)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0085)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK02_ConfrontedBobombs, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0086)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_01)))
    IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_02)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseGe(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK02_ConfrontedBobombs, TRUE)
                Return
            EndIf
            Exec(N(EVS_Dueling_Bobombs))
            Set(AF_NOK_11, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_03)))
    IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009F)
    EVT_GIVE_STAR_PIECE()
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_00A0)
    Set(GF_SBK_GaveArtifactToKolorado, TRUE)
    Return
    End
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    IfEq(GF_SBK_GaveArtifactToKolorado, TRUE)
        Return
    EndIf
    Call(FindKeyItem, ITEM_ARTIFACT, LVar0)
    IfEq(LVar0, -1)
        Return
    EndIf
    IfEq(AF_NOK_15, FALSE)
        Set(AF_NOK_15, TRUE)
        IfEq(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(GF_SBK_KeptArtifactFromKolorado, FALSE)
            Set(LVar0, MSG_CH1_009B)
        Else
            Set(LVar0, MSG_CH1_009C)
        EndIf
    Else
        Set(LVar0, MSG_CH1_009C)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    Set(LVar0, Ref(N(ItemList_Artifact)))
    Set(LVar1, 7)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseGe(1)
            ExecWait(N(EVS_ArtifactReward_Kolorado))
            BreakSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009D)
            Set(LVar0, Ref(N(ItemList_Artifact)))
            Set(LVar1, 7)
            ExecWait(N(EVS_ChooseKeyItem))
            Switch(LVar0)
                CaseGe(1)
                    ExecWait(N(EVS_ArtifactReward_Kolorado))
                CaseDefault
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009E)
            EndSwitch
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0093)
    Call(NpcFaceNpc, NPC_KoloradoWife, NPC_SELF, 0)
    Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 5, MSG_CH1_0094)
    Call(NpcFaceNpc, NPC_SELF, NPC_KoloradoWife, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH1_0095)
    Wait(15)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Wait(15)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0096)
    ExecWait(N(EVS_ArtifactPrompt_Kolorado))
    ExecWait(N(EVS_LetterPrompt_Kolorado))
    ExecWait(N(EVS_LetterReward_Kolorado))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfEq(GF_NOK11_Defeated_KentC, TRUE)
        Return
    EndIf
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};
