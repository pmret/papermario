EvtScript N(D_8024ACA4_82DF64) = {
    EVT_IF_EQ(LVar0, EVT_FLOAT(0.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
        EVT_SETF(LVar1, EVT_FLOAT(24.0))
    EVT_ELSE
        EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
        EVT_SETF(LVar1, EVT_FLOAT(-24.0))
    EVT_END_IF
    EVT_LOOP(10)
        EVT_ADDF(LVar0, LVar1)
        EVT_CALL(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
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
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOOTLER_HIDE, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcMoveTo, NPC_SELF, 580, -40, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 430, 1, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 430, 1, 35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PlayerMoveTo, 430, -40, 0)
    EVT_CALL(InterpPlayerYaw, 315, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 455, -40, 20 * DT)
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
    EVT_WAIT(20 * DT)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcPos, NPC_SELF, 500, 50, 30)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0026)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcScale, NPC_Bootler, EVT_FLOAT(2.0), EVT_FLOAT(2.0), EVT_FLOAT(2.0))
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(SetNpcPos, NPC_SELF, 360, 20, 30)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0027)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
    EVT_CALL(SetNpcScale, NPC_Bootler, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_SELF, 480, 70, 10)
    EVT_EXEC_WAIT(N(D_8024ACA4_82DF64))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOOTLER_HIDE, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcFlyTo, NPC_SELF, 550, 40, 10, 40 * DT, 10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0028)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(40 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, MSG_MAC_Bridge_0029)
    EVT_EXEC(N(EVS_SetupMusicTriggers))
    EVT_SET(GB_StoryProgress, STORY_CH3_SAW_BOO_ENTER_FOREST)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
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
