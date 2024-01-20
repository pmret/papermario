#include "flo_00.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Bubulb_Patrol.inc.c"
#include "world/common/npc/Tolielup.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

API_CALLABLE(N(UpgradeStarPowerCh6)) {
    set_max_star_power(6);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 0, -200)
    Call(SetPanTarget, CAM_DEFAULT, 50, 0, -200)
    Call(SetCamDistance, CAM_DEFAULT, 700)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-11.0))
    Call(SetCamPosA, CAM_DEFAULT, -27, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(ShowMessageAtWorldPos, MSG_CH6_00C4, 0, 50, -200)
    Wait(10)
    Call(GotoMap, Ref("flo_07"), flo_07_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Wisterwood_Introduction) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, -170)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, -170)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(75 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH6_0000, 160, 40)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(1.5))
    Call(PlayerJump1, LVar0, LVar1, LVar2, 12 * DT)
    Wait(10 * DT)
    Call(DisablePartnerAI, 0)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Wait(15 * DT)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Wait(15 * DT)
    Call(SetCamDistance, CAM_DEFAULT, 800)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-5.8))
    Call(SetCamPosA, CAM_DEFAULT, -2, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Dummy_Wisterwood, -1, -1, 5, MSG_CH6_0001)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 350, 0)
    Wait(15 * DT)
    Call(ContinueSpeech, NPC_Dummy_Wisterwood, -1, -1, 5, MSG_CH6_0002)
    Wait(10 * DT)
    Call(SetCamDistance, CAM_DEFAULT, 333)
    Call(SetCamPitch, CAM_DEFAULT, Float(9.0), Float(-22.0))
    Call(SetCamPosA, CAM_DEFAULT, -2, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnablePartnerAI)
    Call(func_802D2C14, 1)
    Wait(10 * DT)
    Call(ShowMessageAtWorldPos, MSG_CH6_0003, 0, 70, -200)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.5), Float(-11.8))
    Call(SetCamDistance, CAM_DEFAULT, 525)
    Call(SetCamPosA, CAM_DEFAULT, -14, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(ShowMessageAtWorldPos, MSG_CH6_0004, 0, 50, -200)
    Call(SetCamPitch, CAM_DEFAULT, Float(9.0), Float(-22.0))
    Call(SetCamDistance, CAM_DEFAULT, 333)
    Call(SetCamPosA, CAM_DEFAULT, -2, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(ShowMessageAtWorldPos, MSG_CH6_0005, 0, 70, -200)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Set(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Interact_Wisterwood) = {
    Call(DisablePlayerInput, TRUE)
    Wait(2)
    Call(GetPlayerActionState, LVar3)
    Set(LVar4, 0)
    IfEq(LVar3, ACTION_STATE_IDLE)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_WALK)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_RUN)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar4, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(ShowMessageAtWorldPos, MSG_CH6_0006, 0, 50, -200)
        Set(GB_StoryProgress, STORY_CH6_WISTERWOOD_GAVE_HINT)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        Call(ShowMessageAtWorldPos, MSG_CH6_000D, 0, 50, -200)
        Call(ShowChoice, MSG_Choice_001F)
        Wait(10)
        Switch(LVar0)
            CaseEq(0)
                Switch(GB_StoryProgress)
                    CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
                        Call(SwitchMessage, MSG_CH6_000E)
                    CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
                        Call(SwitchMessage, MSG_CH6_000F)
                    CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
                        Call(SwitchMessage, MSG_CH6_0010)
                    CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                        Call(SwitchMessage, MSG_CH6_0011)
                    CaseLt(STORY_CH6_GREW_MAGIC_BEANSTALK)
                        Call(SwitchMessage, MSG_CH6_0007)
                    CaseLt(STORY_CH6_BEGAN_PEACH_MISSION)
                        Call(SwitchMessage, MSG_CH6_0012)
                    CaseDefault
                        Call(SwitchMessage, MSG_CH6_0013)
                EndSwitch
            CaseEq(1)
                Call(CloseMessage)
                Exec(N(EVS_Wisterwood_Exit))
                Return
            CaseEq(2)
                Call(CloseMessage)
        EndSwitch
    Else
        Call(ShowMessageAtWorldPos, MSG_CH6_0014, 0, 50, -200)
        Call(ShowChoice, MSG_Choice_001F)
        Wait(10)
        Switch(LVar0)
            CaseEq(0)
                Call(SwitchMessage, MSG_CH6_0015)
            CaseEq(1)
                Call(CloseMessage)
                Exec(N(EVS_Wisterwood_Exit))
                Return
            CaseEq(2)
                Call(CloseMessage)
        EndSwitch
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Wisterwood_Farewell) = {
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, 600, Float(21.0), Float(-12.0))
    Wait(20 * DT)
    Call(ShowMessageAtWorldPos, MSG_CH6_000B, 0, 50, -200)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, -30)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-25.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(ShowMessageAtWorldPos, MSG_CH6_000C, 0, 50, -200)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Return
    End
};

EvtScript N(EVS_NpcInit_Wisterwood) = {
    Call(EnableGroup, MODEL_ha, FALSE)
    Call(EnableGroup, MODEL_tuta, FALSE)
    Call(EnableGroup, MODEL_g54, FALSE)
    Call(SetNpcPos, NPC_SELF, 50, 70, -230)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    IfLt(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
        Exec(N(EVS_Wisterwood_Introduction))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bubulb1) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0016)
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0017)
        CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0018)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0019)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Switch(AF_FLO_PinkBubulbDialogueToggle)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001A)
                    Set(AF_FLO_PinkBubulbDialogueToggle, TRUE)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001B)
                    Set(AF_FLO_PinkBubulbDialogueToggle, FALSE)
            EndSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001C)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bubulb2) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001D)
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001E)
        CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001F)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0020)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Switch(AF_FLO_PurpleBubulbDialogueToggle)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0021)
                    Set(AF_FLO_PurpleBubulbDialogueToggle, TRUE)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0022)
                    Set(AF_FLO_PurpleBubulbDialogueToggle, FALSE)
            EndSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0023)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bubulb_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0024)
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0025)
        CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0026)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0027)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Switch(AF_FLO_GreenBubulbDialogueToggle)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_0028)
                    Set(AF_FLO_GreenBubulbDialogueToggle, TRUE)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_0029)
                    Set(AF_FLO_GreenBubulbDialogueToggle, FALSE)
            EndSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_002A)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bubulb_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002B)
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002C)
        CaseLt(STORY_CH6_FILLED_SPRING_WITH_WATER)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002D)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002E)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Switch(AF_FLO_YellowBubulbDialogueToggle)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_002F)
                    Set(AF_FLO_YellowBubulbDialogueToggle, TRUE)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_0030)
                    Set(AF_FLO_YellowBubulbDialogueToggle, FALSE)
            EndSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_0031)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb_01) = {
    Set(AF_FLO_PinkBubulbDialogueToggle, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb1)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb_02) = {
    Set(AF_FLO_PurpleBubulbDialogueToggle, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb2)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb_03) = {
    Set(AF_FLO_GreenBubulbDialogueToggle, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb_04) = {
    Set(AF_FLO_YellowBubulbDialogueToggle, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb_04)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Tolielup) = {
    IfEq(GF_FLO00_Met_Tolielup, FALSE)
        Call(AdjustCam, CAM_DEFAULT, Float(4.0), -30, 300, Float(20.0), Float(-9.5))
        Set(GF_FLO00_Met_Tolielup, TRUE)
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Switch(AB_FLO_TolielupDialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0035)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 2)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 0)
            EndSwitch
        CaseLt(STORY_CH6_GOT_CRYSTAL_BERRY)
            Switch(AB_FLO_TolielupDialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0036)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 2)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 0)
            EndSwitch
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Switch(AB_FLO_TolielupDialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0037)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 2)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 0)
            EndSwitch
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Switch(AB_FLO_TolielupDialogue)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    Set(AB_FLO_TolielupDialogue, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
            EndSwitch
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_003A)
            Call(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
    EndSwitch
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Return
    End
};

EvtScript N(EVS_NpcInit_Tolielup) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Tolielup)))
    Call(SetNpcCollisionSize, NPC_SELF, 65, 50)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Klevar) = {
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

EvtScript N(EVS_Scene_RescuedKlevar) = {
    Call(DisablePartnerAI, 0)
    Call(func_802CF56C, 2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -50)
    Set(LVar4, LVar1)
    Add(LVar4, 26)
    Call(SetNpcPos, NPC_Klevar, LVar3, LVar4, LVar2)
    Call(PlayerFaceNpc, NPC_Klevar, FALSE)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Klevar, 0)
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
    Call(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00D8)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, 18, -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableNpcAI, NPC_Klevar, FALSE)
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
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
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    Call(EnableNpcAI, NPC_Klevar, TRUE)
    Call(N(UpgradeStarPowerCh6))
    Call(ShowMessageAtScreenPos, MSG_Menus_0196, 160, 40)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00D9)
    Wait(10 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -25)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00DA)
    Call(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
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
            Call(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_Klevar, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Klevar, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_Klevar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(110 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
    ExecWait(N(EVS_Wisterwood_Farewell))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Klevar) = {
    Call(GetLoadType, LVar1)
    IfNe(LVar1, 1)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, flo_00_ENTRY_A)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Klevar)))
            Exec(N(EVS_Scene_RescuedKlevar))
        Else
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lakilulu) = {
    IfLe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
    Else
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_LAKILESTER)
            Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
            Wait(10)
            Call(DisablePartnerAI, 0)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 5, MSG_CH6_0033)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldLakilester_Idle)
            Call(EndSpeech, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5)
            Call(EnablePartnerAI)
        Else
            Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0034)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilulu) = {
    IfGe(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakilulu)))
        Call(SetNpcCollisionSize, NPC_SELF, 36, 28)
        Call(SetNpcPos, NPC_SELF, -200, 15, -300)
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_Wisterwood) = {
    .id = NPC_Dummy_Wisterwood,
    .pos = { -72.0f, 60.0f, -100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Wisterwood),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BUBULB_PINK_ANIMS,
};

NpcData N(NpcData_Bubulbs)[] = {
    {
        .id = NPC_Bubulb_01,
        .pos = { -59.0f, 0.0f, -40.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -59, 0, -40 },
                    { -80, 0, -40 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_01),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_PINK_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbA,
    },
    {
        .id = NPC_Bubulb_02,
        .pos = { 67.0f, 0.0f, 85.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 67, 0, 85 },
                    { 97, 0, 85 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_02),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbB,
    },
    {
        .id = NPC_Bubulb_03,
        .pos = { 90.0f, 0.0f, 410.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 90, 0, 410 },
                    { 120, 0, 410 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_03),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbC,
    },
    {
        .id = NPC_Bubulb_04,
        .pos = { 200.0f, 0.0f, 430.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 200, 0, 430 },
                    { 240, 0, 430 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_04),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbD,
    },
};

NpcData N(NpcData_Tolielup) = {
    .id = NPC_Tolielup,
    .pos = { -400.0f, 0.0f, 190.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Tolielup),
    .settings = &N(NpcSettings_Tolielup),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TOLIELUP_ANIMS,
    .tattle = MSG_NpcTattle_Tolielup,
};

NpcData N(NpcData_Klevar) = {
    .id = NPC_Klevar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Klevar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KLEVAR_ANIMS,
};

NpcData N(NpcData_Lakilulu) = {
    .id = NPC_Lakilulu,
    .pos = { 198.0f, 0.0f, 363.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Lakilulu),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
    .tattle = MSG_NpcTattle_Lakilulu,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Wisterwood)),
    NPC_GROUP(N(NpcData_Bubulbs)),
    NPC_GROUP(N(NpcData_Tolielup)),
    NPC_GROUP(N(NpcData_Klevar)),
    NPC_GROUP(N(NpcData_Lakilulu)),
    {}
};
