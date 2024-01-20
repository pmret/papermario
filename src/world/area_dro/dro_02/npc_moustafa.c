#include "dro_02.h"
#include "sprite/player.h"

EvtScript N(EVS_PartyWatchingMoustafa) = {
    Loop(0)
        Call(PlayerFaceNpc, NPC_Moustafa, FALSE)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_Moustafa, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Moustafa_SetCamBetween) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(GetNpcPos, NPC_DisguisedMoustafa, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    Add(LVar2, LVar5)
    Div(LVar0, 2)
    Div(LVar1, 2)
    Div(LVar2, 2)
    Add(LVar1, 15)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(8.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Moustafa_ResetCam) = {
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Moustafa_Unveiling) = {
    Call(SetNpcYaw, NPC_Moustafa, 270)
    Call(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_GrabCloak)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_ThrownCloak)
    Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
    Call(SetNpcPos, NPC_Moustafa, -335, 163, -260)
    Exec(N(EVS_PlayMoustafaMusic))
    Call(MakeLerp, 0, 80, 30 * DT, EASING_CUBIC_OUT)
    Label(10)
    Call(UpdateLerp)
    Set(LVar2, -335)
    Set(LVar3, 163)
    Sub(LVar2, LVar0)
    Add(LVar3, LVar0)
    Call(SetNpcPos, NPC_DisguisedMoustafa, LVar2, LVar3, -260)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcPos, NPC_DisguisedMoustafa, 0, NPC_DISPOSE_POS_Y, -250)
    Call(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
    Call(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Wait(30 * DT)
    Return
    End
};

EvtScript N(EVS_NpcIdle_DisguisedMoustafa) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_BOUGHT_SECRET_ITEMS)
        CaseLt(STORY_CH2_GOT_PULSE_STONE)
            Call(SetNpcPos, NPC_SELF, -335, 163, -260)
        CaseGe(STORY_CH2_GOT_PULSE_STONE)
            Call(SetNpcPos, NPC_SELF, 0, NPC_DISPOSE_POS_Y, -250)
            Call(SetNpcPos, NPC_Moustafa, -335, 163, -260)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Moustafa) = {
    IfEq(GF_DRO02_Moustafa_UnusedDialogOverride, TRUE)
        Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CF)
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_BOUGHT_SECRET_ITEMS)
            Set(LVarB, 0)
            Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B4)
            Label(0)
            Call(ShowChoice, MSG_Choice_0019)
            IfEq(LVar0, 1)
                Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B6)
                Exec(N(EVS_Moustafa_ResetCam))
                Return
            Else
                Call(EndSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0)
            EndIf
            Label(1)
            EVT_CHOOSE_ANY_CONSUMABLE(2)
            Switch(LVar0)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B8)
                    Exec(N(EVS_Moustafa_ResetCam))
                    Return
                CaseEq(-1)
                    Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B7)
                    Exec(N(EVS_Moustafa_ResetCam))
                    Return
            EndSwitch
            Set(LVarA, LVar0)
            IfEq(GB_DRO02_SheekLemonGiftCount, 0)
                IfEq(LVarA, ITEM_LEMON)
                    Set(GB_DRO02_SheekLemonGiftCount, 1)
                    Set(GB_DRO02_SheekGiftCount, 10)
                    Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BB)
                    Call(ShowChoice, MSG_Choice_001C)
                Else
                    Add(GB_DRO02_SheekGiftCount, 1)
                    IfLe(GB_DRO02_SheekGiftCount, 2)
                        Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B5)
                        Goto(0)
                    EndIf
                    IfEq(GB_DRO02_SheekGiftCount, 3)
                        Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B9)
                        Call(ShowChoice, MSG_Choice_001B)
                    Else
                        Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BA)
                        Call(ShowChoice, MSG_Choice_001B)
                        Set(GB_DRO02_SheekGiftCount, 10)
                    EndIf
                EndIf
            Else
                Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BA)
                Call(ShowChoice, MSG_Choice_001C)
            EndIf
            Switch(LVar0)
                CaseEq(0)
                    Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BC)
                CaseEq(1)
                    ExecWait(N(EVS_Moustafa_SetCamBetween))
                    Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BD)
                    Set(GF_DRO02_Sheek_AskedAboutDesert, TRUE)
                CaseEq(2)
                    ExecWait(N(EVS_Moustafa_SetCamBetween))
                    Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BE)
                    Set(GF_DRO02_Sheek_AskedAboutRuins, TRUE)
                CaseEq(3)
                    ExecWait(N(EVS_Moustafa_SetCamBetween))
                    Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BF)
                CaseEq(4)
                    ExecWait(N(EVS_Moustafa_SetCamBetween))
                    Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C1)
                    Set(GF_DRO02_Sheek_AskedAboutMoustafa, TRUE)
                    Set(LVarB, 1)
            EndSwitch
            Set(GF_DRO02_Sheek_SpokeTo, TRUE)
            Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C0)
            Call(ShowChoice, MSG_Choice_001A)
            IfEq(LVar0, 0)
                Call(EndSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0)
                Goto(1)
            Else
                Call(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B6)
            EndIf
            IfEq(LVarB, 1)
                IfEq(MF_Unk_00, FALSE)
                    Set(MF_Unk_00, TRUE)
                    Thread
                        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        Call(AwaitPlayerLeave, LVar0, LVar2, 50)
                        Call(DisablePlayerInput, TRUE)
                        Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C2)
                        Call(DisablePlayerInput, FALSE)
                        Set(MF_Unk_00, FALSE)
                    EndThread
                EndIf
            EndIf
            Exec(N(EVS_Moustafa_ResetCam))
        CaseLt(STORY_CH2_GOT_PULSE_STONE)
            Thread
                Wait(10 * DT)
                Call(func_802D2C14, 1)
            EndThread
            Call(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetPlayerSpeed, Float(3.0 / DT))
            Call(PlayerMoveTo, -391, -260, 0)
            Call(InterpPlayerYaw, 90, 3)
            Call(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            ExecGetTID(N(EVS_PartyWatchingMoustafa), LVarA)
            Call(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(FadeOutMusic, 0, 500)
            IfEq(GF_DRO02_Sheek_AskedAboutMoustafa, TRUE)
                Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C3)
                ExecWait(N(EVS_Moustafa_Unveiling))
                Call(func_802D2C14, 0)
                Call(SetNpcJumpscale, NPC_Moustafa, Float(1.0))
                Call(NpcJump0, NPC_Moustafa, -425, 140, -206, 20 * DT)
                Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C4)
            Else
                Call(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C5)
                ExecWait(N(EVS_Moustafa_Unveiling))
                Call(func_802D2C14, 0)
                Call(SetNpcJumpscale, NPC_Moustafa, Float(1.0))
                Call(NpcJump0, NPC_Moustafa, -425, 140, -206, 20 * DT)
                Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C6)
            EndIf
            Call(SetNpcJumpscale, NPC_Moustafa, Float(1.0))
            Call(NpcJump0, NPC_Moustafa, -337, 140, -200, 20 * DT)
            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C7)
            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C8)
            Call(SetNpcJumpscale, NPC_Moustafa, Float(1.0))
            Call(NpcJump0, NPC_Moustafa, -335, 163, -260, 20 * DT)
            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C9)
            EVT_GIVE_KEY_REWARD(ITEM_PULSE_STONE)
            Set(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CA)
            KillThread(LVarA)
            Exec(N(EVS_SetupMusic))
        CaseGe(STORY_CH2_GOT_PULSE_STONE)
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
                    Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CB)
                CaseGe(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
                    IfGe(GB_StoryProgress, STORY_CH2_DEFEATED_TUTANKOOPA)
                        IfEq(GF_DRO02_Moustafa_HeardAboutDryDryRuins, FALSE)
                            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CD)
                            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                            Wait(15)
                            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
                            Wait(30)
                            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CE)
                            Set(GF_DRO02_Moustafa_HeardAboutDryDryRuins, TRUE)
                        Else
                            Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00D0)
                        EndIf
                    Else
                        Call(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CC)
                    EndIf
            EndSwitch
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_DisguisedMoustafa) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_02_ENTRY_2)
        CaseOrEq(dro_02_ENTRY_3)
            Call(SetNpcPos, NPC_SELF, 200, 0, -15)
            Call(InterpNpcYaw, NPC_SELF, 270, 0)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_200000, TRUE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_DisguisedMoustafa_GrabCloak)
        EndCaseGroup
        CaseDefault
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_DisguisedMoustafa)))
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Moustafa)))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Moustafa) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Moustafa)))
    Return
    End
};
