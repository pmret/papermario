#include "arn_07.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/HyperParagoomba.inc.c"
#include "world/common/npc/TubbasHeart.inc.c"
#include "world/common/enemy/TubbaBlubba.inc.c"
#include "world/common/npc/Boo.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

API_CALLABLE(N(UpgradeStarPowerCh3)) {
    set_max_star_power(3);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TubbaWalking) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_Tubba, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.8))
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_TubbaRelents) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, 250, 0, -46)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim08)
    Call(SetNpcYaw, NPC_SELF, 90)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CA)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CB)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(5.0), Float(-16.0))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Scene_BossDefeated) = {
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
    Wait(15 * DT)
    Loop(4)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_02, 0, 1)
        Wait(4 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_05, 0, 1)
        Wait(4 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_01, 0, 1)
        Wait(6 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_03, 0, 1)
        Wait(8 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_04, 0, 1)
        Wait(6 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
        Call(SetNpcVar, NPC_Boo_06, 0, 1)
        Wait(6 * DT)
    EndLoop
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim23)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
    Wait(10 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_BOO_APPEAR, SOUND_SPACE_DEFAULT)
    Call(SetNpcVar, NPC_Boo_02, 0, 1)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim21)
    Wait(45 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 50)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim0F)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 0, MSG_CH3_00CC)
    Thread
        Wait(5 * DT)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Loop(40 * DT)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(func_802CF56C, 2)
        Loop(45 * DT)
            Call(PlayerFaceNpc, NPC_SELF, TRUE)
        EndLoop
    EndThread
    ExecGetTID(N(EVS_TubbaWalking), LVarA)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 800)
    Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 80 * DT)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Set(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
    Call(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    Call(GetCurrentPartnerID, LVar6)
    IfEq(LVar6, PARTNER_BOW)
        Set(LVar5, -4)
        Call(func_802CF56C, 0)
        Call(DisablePartnerAI, 0)
        Call(SetNpcPos, NPC_PARTNER, 257, 25, 0)
    EndIf
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(10 * DT)
    IfNe(LVar6, PARTNER_BOW)
        Set(LVar5, 8)
        Call(SetNpcPos, NPC_Bow, 257, 25, 0)
        Call(SetNpcImgFXParams, NPC_Bow, IMGFX_SET_ALPHA, 0, 0, 0, 0)
        Call(NpcFacePlayer, NPC_Bow, 0)
        Call(MakeLerp, 0, 240, 20 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_Bow, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(func_802CF56C, 0)
    EndIf
    Wait(10 * DT)
    Thread
        IfNe(LVar6, PARTNER_BOW)
            Call(DisablePartnerAI, 0)
            Wait(1)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_Bow, 0)
            Wait(5 * DT)
        EndIf
    EndThread
    Call(SpeakToPlayer, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CD)
    Call(InterpPlayerYaw, 270, 0)
    Wait(10 * DT)
    Call(GetNpcPos, LVar5, LVar0, LVar1, LVar2)
    Add(LVar1, -20)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), LVar0, LVar1, LVar2, Float(300.0), Float(15.0), Float(-7.0))
    Call(PlayerFaceNpc, LVar5, FALSE)
    Wait(10 * DT)
    Call(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00CE)
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CF)
    Else
        Call(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00D0)
    EndIf
    Call(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D1)
    Call(UseSettingsFrom, CAM_DEFAULT, 175, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, 175, 0, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcPos, NPC_Bootler, 93, 160, -6)
    Call(InterpNpcYaw, NPC_Bootler, 90, 0)
    Thread
        Wait(10 * DT)
        Call(InterpPlayerYaw, 270, 0)
    EndThread
    Thread
        IfNe(LVar6, PARTNER_BOW)
            Wait(12 * DT)
            Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndIf
    EndThread
    Call(MakeLerp, 160, 31, 70 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_Bootler, 93, LVar0, -6)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        IfNe(LVar6, PARTNER_BOW)
            Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EndIf
    EndThread
    Call(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D2)
    Thread
        IfNe(LVar6, PARTNER_BOW)
            Wait(12 * DT)
            Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndIf
    EndThread
    Wait(10 * DT)
    Call(InterpPlayerYaw, 270, 0)
    Exec(N(EVS_SpawnStarCard))
    Wait(20 * DT)
    Thread
        IfNe(LVar6, 9)
            Call(MakeLerp, 240, 0, 20 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcImgFXParams, NPC_Bow, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetNpcPos, NPC_Bow, NPC_DISPOSE_LOCATION)
            Call(EnablePartnerAI)
        Else
            Wait(20 * DT)
            Call(ClearPartnerMoveHistory, NPC_PARTNER)
            Call(EnablePartnerAI)
        EndIf
        Wait(8 * DT)
        Call(func_802CF56C, 2)
    EndThread
    Wait(20 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Tubba) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(StartBossBattle, SONG_TUBBA_BLUBBA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Boo) = {
    Label(10)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        SetF(LVar0, Float(0.5))
        Call(MakeLerp, 50, 80, 15 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 100)
            Call(SetNpcScale, NPC_SELF, LVar2, LVar2, LVar2)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(RandInt, 80, LVar2)
        Call(RandInt, 10, LVar3)
        Add(LVar3, 5 * DT)
        Call(MakeLerp, LVar2, 240, LVar3, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(SetNpcPos, NPC_SELF, 293, 59, 21)
    Wait(1)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_SELF, Float(-0.3))
    Call(RandInt, 100, LVar3)
    Sub(LVar0, LVar3)
    Add(LVar1, 100)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20 * DT)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SetSelfVar, 0, 0)
    Goto(10)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
            ExecWait(N(EVS_Scene_TubbaRelents))
            Exec(N(EVS_Scene_BossDefeated))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    IfNe(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    Call(SetSelfVar, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba)))
    IfNe(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo) = {
    Call(SetSelfVar, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo)))
    IfNe(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bow) = {
    IfNe(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bootler) = {
    IfNe(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

AnimID N(ExtraAnims_Tubba)[] = {
    ANIM_WorldTubba_Anim00,
    ANIM_WorldTubba_Anim22,
    ANIM_WorldTubba_Anim23,
    ANIM_WorldTubba_Anim06,
    ANIM_WorldTubba_Anim10,
    ANIM_WorldTubba_Anim08,
    ANIM_WorldTubba_Anim0F,
    ANIM_WorldTubba_Anim12,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Boo)[] = {
    ANIM_Boo_Still,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_GustyBoo)[] = {
    ANIM_Boo_Tan_Still,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bootler)[] = {
    ANIM_Bootler_Idle,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcIdle_Skolar) = {
    Loop(0)
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_SkolarRescued) = {
    Call(DisablePartnerAI, 0)
    Call(func_802CF56C, 2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -50)
    Set(LVar4, LVar1)
    Add(LVar4, 26)
    Call(SetNpcPos, NPC_Skolar, LVar3, LVar4, LVar2)
    Call(PlayerFaceNpc, NPC_Skolar, FALSE)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Skolar, 0)
    Add(LVar0, -25)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(475.0))
    Call(SetCamPitch, CAM_DEFAULT, 18, -8)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D3)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, 18, -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableNpcAI, NPC_Skolar, FALSE)
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Add(LVar1, 50)
    Add(LVar2, 10)
    Add(LVar3, 30)
    Loop(5)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        Wait(6 * DT)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        Wait(6 * DT)
    EndLoop
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    Call(EnableNpcAI, NPC_Skolar, TRUE)
    Call(N(UpgradeStarPowerCh3))
    Call(ShowMessageAtScreenPos, MSG_Menus_0193, 160, 40)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D4)
    Wait(10 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -25)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D5)
    Call(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            Wait(4 * DT)
        EndLoop
    EndThread
    Thread
        Set(LVar2, 0)
        Set(LVar3, 1800)
        Call(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_Skolar, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Skolar, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_Skolar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(90 * DT)
    Call(ResetCam, CAM_DEFAULT, 3)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
    Exec(N(EVS_SetupMusic))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Skolar) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, arn_07_ENTRY_3)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Skolar)))
        Exec(N(EVS_Scene_SkolarRescued))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Tubba)[] = {
    {
        .id = NPC_Tubba,
        .pos = { 309.0f, 0.0f, 11.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Tubba),
        .settings = &N(NpcSettings_TubbaBlubba),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = TUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Tubba),
    },
    {
        .id = NPC_TubbasHeart,
        .pos = { -10.0f, 50.0f, -170.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TubbasHeart),
        .settings = &N(NpcSettings_TubbasHeart),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = TUBBAS_HEART_ANIMS,
    },
};

NpcData N(NpcData_Boos)[] = {
    {
        .id = NPC_Boo_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boo),
    },
    {
        .id = NPC_Boo_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Boo),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boo),
    },
};

NpcData N(NpcData_Bow) = {
    .id = NPC_Bow,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bow),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldBow_Idle,
        .walk   = ANIM_WorldBow_Walk,
        .run    = ANIM_WorldBow_Run,
        .chase  = ANIM_WorldBow_Run,
        .anim_4 = ANIM_WorldBow_Idle,
        .anim_5 = ANIM_WorldBow_Idle,
        .death  = ANIM_WorldBow_Still,
        .hit    = ANIM_WorldBow_Still,
        .anim_8 = ANIM_WorldBow_Run,
        .anim_9 = ANIM_WorldBow_Run,
        .anim_A = ANIM_WorldBow_Run,
        .anim_B = ANIM_WorldBow_Run,
        .anim_C = ANIM_WorldBow_Run,
        .anim_D = ANIM_WorldBow_Run,
        .anim_E = ANIM_WorldBow_Run,
        .anim_F = ANIM_WorldBow_Run,
    },
};

NpcData N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bootler),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Bootler_Idle,
        .walk   = ANIM_Bootler_Walk,
        .run    = ANIM_Bootler_Run,
        .chase  = ANIM_Bootler_Run,
        .anim_4 = ANIM_Bootler_Idle,
        .anim_5 = ANIM_Bootler_Idle,
        .death  = ANIM_Bootler_Still,
        .hit    = ANIM_Bootler_Still,
        .anim_8 = ANIM_Bootler_Shock,
        .anim_9 = ANIM_Bootler_Panic,
        .anim_A = ANIM_Bootler_Dejected,
        .anim_B = ANIM_Bootler_Quaver,
        .anim_C = ANIM_Bootler_Shock,
        .anim_D = ANIM_Bootler_Panic,
        .anim_E = ANIM_Bootler_Dejected,
        .anim_F = ANIM_Bootler_Quaver,
    },
    .extraAnimations = N(ExtraAnims_Bootler),
};

EvtScript N(EVS_NpcInit_HyperParagoomba) = {
    IfGe(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(RemoveNpc, NPC_SELF)
        EndIf
    EndIf
    Return
    End
};

NpcData N(NpcData_HyperParagoomba_01) = {
    .id = NPC_HyperParagoomba_01,
    .pos = { -216.0f, 60.0f, -10.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -216, 60, -10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -216, 60, -10 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .settings = &N(NpcSettings_HyperParagoomba),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = HYPER_PARAGOOMBA_DROPS,
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_HyperParagoomba_02) = {
    .id = NPC_HyperParagoomba_02,
    .pos = { 0.0f, 60.0f, 150.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 60, 150 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 60, 150 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .settings = &N(NpcSettings_HyperParagoomba),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = HYPER_PARAGOOMBA_DROPS,
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_HyperParagoomba_03) = {
    .id = NPC_HyperParagoomba_03,
    .pos = { 260.0f, 60.0f, 30.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 260, 60, 30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 260, 60, 30 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .settings = &N(NpcSettings_HyperParagoomba),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = HYPER_PARAGOOMBA_DROPS,
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Skolar) = {
    .id = NPC_Skolar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Skolar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SKOLAR_ANIMS,
};

NpcGroupList N(BossNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_ARN_FORMATION_10, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_Boos)),
    NPC_GROUP(N(NpcData_Bow)),
    NPC_GROUP(N(NpcData_Bootler)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HyperParagoomba_01), BTL_ARN_FORMATION_06, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_HyperParagoomba_02), BTL_ARN_FORMATION_07, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_HyperParagoomba_03), BTL_ARN_FORMATION_08, BTL_ARN_STAGE_01),
    {}
};

NpcGroupList N(SpiritNPCs) = {
    NPC_GROUP(N(NpcData_Skolar)),
    {}
};
