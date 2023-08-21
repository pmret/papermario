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
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0058)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0059)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005A)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_01_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_01_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_02_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0060)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0061)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0062)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0063)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_02_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_02_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Koopa_03_CircleSprint) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Run)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_03, TRUE)
    EVT_CALL(GetNpcPointer, NPC_Koopa_03, LVarF)
    EVT_CALL(N(DoCircleSprint), LVarF, -150, 15)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_03, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_03_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0064)
            EVT_EXEC_WAIT(N(EVS_Koopa_03_CircleSprint))
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0065)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0066)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0067)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0068)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0069)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_03_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_04_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006A)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006C)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006D)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006E)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_04_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dueling_Bobombs) = {
    EVT_LABEL(10)
        EVT_IF_EQ(AF_NOK_10, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(AF_NOK_11, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Run)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Idle)
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Bobomb_02, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_Bobomb_02, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_LABEL(20)
            EVT_IF_EQ(AF_NOK_10, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_IF_EQ(AF_NOK_11, TRUE)
                EVT_WAIT(1)
                EVT_GOTO(20)
            EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Run)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Idle)
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Bobomb_01, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_Bobomb_01, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
        EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ConfrontBobombs) = {
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH5_2)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_007C)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007D)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bobomb_01, MSG_CH1_007E)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007F)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0080)
            EVT_CALL(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Idle)
            EVT_CALL(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Idle)
            EVT_SET(GF_NOK02_ConfrontedBobombs, TRUE)
            EVT_SET(GF_MAC02_KootFavor_CurrentComplete, TRUE)
        EVT_ELSE
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_007C)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_0081)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0082)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_PARTNER, MSG_CH1_0077)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_PARTNER, MSG_CH1_0078)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bobomb_01, MSG_CH1_0079)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007A)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_ELSE
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0073)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bobomb_02, MSG_CH1_0074)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0075)
            EVT_CALL(SpeakToNpc, NPC_Bobomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bobomb_02, MSG_CH1_0076)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK_0F, FALSE)
                EVT_CALL(GetCurrentPartnerID, LVar0)
                EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
                    EVT_SET(AF_NOK_0F, TRUE)
                    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_006F)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_0070)
                    EVT_CALL(EnablePartnerAI)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0071)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_EXEC_WAIT(N(EVS_Scene_ConfrontBobombs))
            EVT_ELSE
                EVT_SET(AF_NOK_11, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007F)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0083)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_EXEC_WAIT(N(EVS_Scene_ConfrontBobombs))
            EVT_ELSE
                EVT_SET(AF_NOK_11, TRUE)
                EVT_CALL(SpeakToNpc, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bobomb_01, MSG_CH1_0080)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0084)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0085)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0086)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_01)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_02)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_GE(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, TRUE)
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC(N(EVS_Dueling_Bobombs))
            EVT_SET(AF_NOK_11, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_03)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Artifact)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactReward_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009F)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_00A0)
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ArtifactPrompt_Kolorado) = {
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_NOK_15, FALSE)
        EVT_SET(AF_NOK_15, TRUE)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(LVar0, MSG_CH1_009B)
        EVT_ELSE
            EVT_SET(LVar0, MSG_CH1_009C)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH1_009C)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
    EVT_SET(LVar1, 7)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(1)
            EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
            EVT_BREAK_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009D)
            EVT_SET(LVar0, EVT_PTR(N(ItemList_Artifact)))
            EVT_SET(LVar1, 7)
            EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_EXEC_WAIT(N(EVS_ArtifactReward_Kolorado))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009E)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0093)
    EVT_CALL(NpcFaceNpc, NPC_KoloradoWife, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 5, MSG_CH1_0094)
    EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_KoloradoWife, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH1_0095)
    EVT_WAIT(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0096)
    EVT_EXEC_WAIT(N(EVS_ArtifactPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};
