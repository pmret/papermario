EvtScript N(D_8024ACA4_82DF64) = {
    IfEq(LVar0, Float(0.0))
        Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
        SetF(LVar1, Float(24.0))
    Else
        Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
        SetF(LVar1, Float(-24.0))
    EndIf
    Loop(10)
        AddF(LVar0, LVar1)
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Bootler) = {
    Loop(0)
        Wait(1)
        Set(LVar0, 0)
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Switch(LVar3)
            CaseRange(-52, 47)
                Add(LVar0, 1)
        EndSwitch
        IfGt(LVar1, 140)
            Add(LVar0, 1)
        EndIf
        IfEq(LVar0, 2)
            BreakLoop
        EndIf
    EndLoop
    Call(SetMusic, 0, SONG_BOOS_MANSION, 0, VOL_LEVEL_FULL)
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_MAC_Bridge_0022, 400, 100)
    Thread
        Call(SetNpcPos, NPC_SELF, 430, 60, -40)
        Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
        Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOOTLER_HIDE, SOUND_SPACE_DEFAULT)
        Call(NpcMoveTo, NPC_SELF, 580, -40, 0)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 430, 1, 35)
    Call(SetPanTarget, CAM_DEFAULT, 430, 1, 35)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-10.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPlayerSpeed, Float(4.0 / DT))
    Call(PlayerMoveTo, 430, -40, 0)
    Call(InterpPlayerYaw, 315, 0)
    Call(DisablePartnerAI, 0)
    Call(NpcMoveTo, NPC_PARTNER, 455, -40, 20 * DT)
    Call(InterpNpcYaw, NPC_PARTNER, 315, 0)
    Call(EnablePartnerAI)
    Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, MSG_MAC_Bridge_0023)
    Call(ShowChoice, MSG_Choice_0036)
    IfEq(LVar0, 0)
        Set(LVar1, MSG_MAC_Bridge_0024)
    Else
        Set(LVar1, MSG_MAC_Bridge_0025)
    EndIf
    Call(ContinueSpeech, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar1)
    Wait(20 * DT)
    SetF(LVar0, Float(0.0))
    Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(SetNpcPos, NPC_SELF, 500, 50, 30)
    ExecWait(N(D_8024ACA4_82DF64))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0026)
    ExecWait(N(D_8024ACA4_82DF64))
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Wait(25 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetNpcScale, NPC_Bootler, Float(2.0), Float(2.0), Float(2.0))
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(SetNpcPos, NPC_SELF, 360, 20, 30)
    ExecWait(N(D_8024ACA4_82DF64))
    Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0027)
    ExecWait(N(D_8024ACA4_82DF64))
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Wait(25 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
    Call(SetNpcScale, NPC_Bootler, Float(1.0), Float(1.0), Float(1.0))
    Call(SetNpcPos, NPC_SELF, 480, 70, 10)
    ExecWait(N(D_8024ACA4_82DF64))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOOTLER_HIDE, SOUND_SPACE_DEFAULT)
    Call(NpcFlyTo, NPC_SELF, 550, 40, 10, 40 * DT, 10, EASING_LINEAR)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 5, MSG_MAC_Bridge_0028)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Wait(25 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(40 * DT)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, MSG_MAC_Bridge_0029)
    Exec(N(EVS_SetupMusicTriggers))
    Set(GB_StoryProgress, STORY_CH3_SAW_BOO_ENTER_FOREST)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bootler) = {
    IfEq(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        Call(EnableNpcShadow, NPC_SELF, false)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bootler)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
