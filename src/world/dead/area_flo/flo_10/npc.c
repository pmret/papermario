#include "flo_10.h"
#include "sprite/player.h"

#include "world/common/npc/Lily.inc.c"

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetNpcPos, NPC_Lily, 60, 0, 55)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(SpeakToPlayer, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_00C6)
    Wait(10)
    Call(GotoMap, Ref("flo_12"), flo_12_ENTRY_1)
    Wait(100)
    Return
    End
};

s32 N(KeyList)[] = {
    ITEM_WATER_STONE,
    ITEM_NONE
};

EvtScript N(EVS_OnInteract_WaterStoneSocket) = {
    IfEq(GF_FLO10_ShowedLilyTheWaterStone, true)
#if !VERSION_JP
        Call(GetPartnerInUse, LVarA)
        IfNe(LVarA, 0)
            Call(AwaitPlayerLeave, 0, 0, 19)
            Return
        EndIf
#endif
        Call(DisablePlayerInput, true)
        SetGroup(EVT_GROUP_NEVER_PAUSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        Call(ShowKeyChoicePopup)
        Set(LVar2, LVar0)
        Switch(LVar2)
            CaseEq(-1)
                Call(CloseChoicePopup)
                Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
                Wait(10)
                Call(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0081)
            CaseDefault
                Call(GetPlayerPos, LVar3, LVar4, LVar5)
                Call(PlayerMoveTo, -17, -17, 20)
                Call(func_802CF56C, 2)
                Call(InterpPlayerYaw, 100, 1)
                Wait(10)
                Call(AdjustCam, CAM_DEFAULT, Float(1.0), 0, 450, Float(25.0), Float(-6.0))
                Wait(10)
                Call(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                Call(RemoveKeyItemAt, LVar1)
                Call(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(LVarA, LVar0)
                Call(CloseChoicePopup)
                Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
                ExecWait(N(EVS_Scene_ReleaseFountain))
        EndSwitch
        Call(DisablePlayerInput, false)
        Call(AwaitPlayerLeave, 0, 0, 19)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupWaterStoneSocket) = {
    BindPadlock(Ref(N(EVS_OnInteract_WaterStoneSocket)), TRIGGER_FLOOR_TOUCH, COLLIDER_o83, Ref(N(KeyList)), 0, 1)
    Return
    End
};

EvtScript N(EVS_MovePlayerToTalk) = {
    Wait(10)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    IfLt(LVar5, LVar2)
        Set(LVar6, 30)
    Else
        Set(LVar6, 20)
    EndIf
    Set(LVar1, LVar0)
    Set(LVar4, LVar0)
    Sub(LVar1, LVar6)
    Add(LVar4, LVar6)
    Switch(LVar3)
        CaseRange(LVar1, LVar4)
            Thread
                IfLt(LVar3, LVar0)
                    Sub(LVar0, 40)
                Else
                    Add(LVar0, 40)
                EndIf
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
                Call(PlayerMoveTo, LVar0, LVar5, 15)
                Call(PlayerFaceNpc, NPC_Lily, true)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
            EndThread
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lily) = {
    ExecWait(N(EVS_PushFlowerSong))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Exec(N(EVS_MovePlayerToTalk))
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 325)
            Call(SetCamPitch, CAM_DEFAULT, Float(23.0), Float(-9.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Wait(10)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0078)
            Call(EndSpeech, NPC_SELF, ANIM_Lily_DreadLoop, ANIM_Lily_Dread, 5)
        CaseLt(STORY_CH6_GOT_WATER_STONE)
            IfEq(GF_FLO10_LilyRequestedWaterStone, false)
                Exec(N(EVS_MovePlayerToTalk))
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, 325)
                Call(SetCamPitch, CAM_DEFAULT, Float(23.0), Float(-9.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
                Call(PanToTarget, CAM_DEFAULT, 0, true)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Wait(10)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0079)
                Call(NpcFacePlayer, NPC_SELF, 1)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Lily_Idle)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                Wait(15)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_Idle, ANIM_Lily_Idle, 0, MSG_CH6_007A)
                Call(EndSpeech, NPC_SELF, ANIM_Lily_Dread, ANIM_Lily_Idle, 0)
                Call(GetPlayerTargetYaw, LVar0)
                Call(InterpNpcYaw, NPC_SELF, LVar0, 1)
                Wait(20)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_007B)
                Call(NpcFacePlayer, NPC_SELF, 1)
                Wait(20)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_007C)
                Call(ShowChoice, MSG_Choice_0011)
                Wait(10)
                Switch(LVar0)
                    CaseEq(0)
                        Call(ContinueSpeech, NPC_SELF, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_007D)
                    CaseEq(1)
                        Call(ContinueSpeech, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_007E)
                EndSwitch
                Wait(10)
                Set(GF_FLO10_LilyRequestedWaterStone, true)
                Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER, false)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_007F)
            EndIf
        CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0080)
            Set(GF_FLO10_ShowedLilyTheWaterStone, true)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0085)
            Call(EndSpeech, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
            Call(EndSpeech, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0)
        CaseLt(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0086)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0087)
    EndSwitch
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    ExecWait(N(EVS_PopSong))
    Return
    End
};

EvtScript N(EVS_NpcInit_Lily) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lily)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_WATER_STONE)
            IfEq(GF_FLO10_LilyRequestedWaterStone, false)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Lily_IdlePlead)
                Call(InterpNpcYaw, NPC_SELF, 90, 1)
                Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER, true)
            EndIf
        CaseEq(STORY_CH6_GOT_WATER_STONE)
            Call(InterpNpcYaw, NPC_SELF, 270, 1)
        CaseGe(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SetNpcPos, NPC_SELF, -67, -20, -105)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Lily) = {
    .id = NPC_Lily,
    .pos = { 80.0f, -60.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Lily),
    .settings = &N(NpcSettings_Lily),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = LILY_ANIMS,
    .tattle = MSG_NpcTattle_Lily,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lily)),
    {}
};
