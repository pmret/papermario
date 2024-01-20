#include "sam_01.h"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"

#include "world/common/npc/Penguin_Wander.inc.c"
#include "world/common/npc/Penguin.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(MayorLetterList)[] = {
    ITEM_LETTER_TO_MAYOR_PENGUIN,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Mayor) = {
    Call(N(LetterDelivery_Init),
        NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle,
        ITEM_LETTER_TO_MAYOR_PENGUIN, ITEM_NONE,
        MSG_CH7_0041, MSG_CH7_0042, MSG_CH7_0043, MSG_CH7_0044,
        Ref(N(MayorLetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Mayor) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_Mayor_CarryBucket) = {
    Label(0)
        Call(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
        Add(LVar0, -5)
        Add(LVar1, 15)
        Call(GetNpcYaw, NPC_MayorPenguin, LVar3)
        IfGe(LVar3, 90)
            IfLe(LVar3, 270)
                Add(LVar2, 10)
            Else
                Add(LVar2, -10)
            EndIf
        Else
            Add(LVar2, -10)
        EndIf
        Call(SetItemPos, MV_BucketItemID, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Mayor_HandOverBucket) = {
    Call(GetNpcYaw, NPC_MayorPenguin, LVar3)
    IfGe(LVar3, 90)
        IfLe(LVar3, 270)
            Add(LVar2, 10)
            Set(LVar4, 10)
        Else
            Add(LVar2, -10)
            Set(LVar4, -10)
        EndIf
    Else
        Sub(LVar2, 10)
        Set(LVar4, 10)
    EndIf
    Thread
        Loop(10)
            Call(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
            Add(LVar0, -5)
            Add(LVar1, 15)
            Add(LVar2, LVar4)
            Call(SetItemPos, MV_BucketItemID, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Call(SetItemPos, MV_BucketItemID, NPC_DISPOSE_LOCATION)
    EndThread
    Call(NpcMoveTo, NPC_MayorPenguin, LVar0, LVar2, 10 * DT)
    Return
    End
};

EvtScript N(EVS_NpcInteract_MayorPenguin) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(FadeOutMusic, 0, 500)
            Call(ShowMessageAtScreenPos, MSG_CH7_0002, 160, 40)
            ExecWait(N(EVS_Scene_MysteryBegins))
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(ShowMessageAtScreenPos, MSG_CH7_0002, 160, 40)
        CaseLt(STORY_CH7_GOT_SNOWMAN_SCARF)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0039)
        CaseLt(STORY_CH7_GOT_SNOWMAN_BUCKET)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            IfGe(LVar2, LVar5)
                Set(MV_PlayerLeftOfMayor, 0)
            Else
                Set(MV_PlayerLeftOfMayor, 1)
            EndIf
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003A)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Walk)
            Call(NpcMoveTo, NPC_SELF, -338, -247, 20)
            Call(PlaySoundAtCollider, COLLIDER_yana, SOUND_WOODEN_DOOR_OPEN, 0)
            Call(MakeLerp, 0, 70, 30, EASING_LINEAR)
            Label(10)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_o411, LVar0, 0, -1, 0)
                Call(RotateModel, MODEL_o412, LVar0, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(10)
                EndIf
            Wait(20 * DT)
            Call(MakeLerp, 70, 0, 30, EASING_LINEAR)
            Label(20)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_o411, LVar0, 0, -1, 0)
                Call(RotateModel, MODEL_o412, LVar0, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(20)
                EndIf
            Call(PlaySoundAtCollider, COLLIDER_yana, SOUND_WOODEN_DOOR_CLOSE, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Carry)
            Call(InterpNpcYaw, NPC_SELF, 180, 0)
            ExecGetTID(N(EVS_Mayor_CarryBucket), LVarA)
            Wait(10 * DT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfEq(MV_PlayerLeftOfMayor, 0)
                Add(LVar2, -40)
            Else
                Add(LVar2, 40)
            EndIf
            Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 20)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003B)
            KillThread(LVarA)
            ExecWait(N(EVS_Mayor_HandOverBucket))
            Call(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Idle)
            EVT_GIVE_KEY_REWARD(ITEM_SNOWMAN_BUCKET)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003C)
            Call(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.5))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003D)
            Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Set(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_BUCKET)
        CaseLt(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003E)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003F)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0040)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_Mayor))
    ExecWait(N(EVS_LetterReward_Mayor))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_MayorPenguinWife) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            IfEq(GF_SAM01_Met_MayorsWife, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0000)
                Set(GF_SAM01_Met_MayorsWife, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0001)
            EndIf
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_001C)
        CaseLt(STORY_CH7_GOT_SNOWMAN_SCARF)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0035)
        CaseLt(STORY_CH7_GOT_SNOWMAN_BUCKET)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0036)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0037)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0038)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_PenguinPatrol) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001B)
        CaseGe(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001D)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_PenguinPatrol) = {
    Label(0)
        Switch(GB_StoryProgress)
            CaseEq(STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                IfEq(AF_SAM_03, TRUE)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    IfLt(LVar2, -130)
                        ExecWait(N(EVS_Scene_MysterySolved))
                    EndIf
                EndIf
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Herringway) = {
    IfEq(AF_SAM_04, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D3)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D4)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin1)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0045)
                    Set(MV_DialogueState_Penguin1, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0046)
                    Set(MV_DialogueState_Penguin1, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin1)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0047)
                    Set(MV_DialogueState_Penguin1, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0048)
                    Set(MV_DialogueState_Penguin1, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin1)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0049)
                    Set(MV_DialogueState_Penguin1, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004A)
                    Set(MV_DialogueState_Penguin1, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004C)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004D)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004E)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004F)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0050)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0051)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0052)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0053)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0054)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0055)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0056)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0057)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0058)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0059)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005A)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005B)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005C)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005D)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005E)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005F)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0060)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PenguinCrowd_Leave) = {
    Call(SetNpcFlagBits, NPC_Penguin_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Penguin_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Penguin_07, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Penguin_08, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(BindNpcInteract, NPC_Penguin_05, 0)
    Call(BindNpcInteract, NPC_Penguin_06, 0)
    Call(BindNpcInteract, NPC_Penguin_07, 0)
    Call(BindNpcInteract, NPC_Penguin_08, 0)
    Thread
        Call(SetNpcSpeed, NPC_Penguin_05, Float(3.0))
        Call(SetNpcAnimation, NPC_Penguin_05, ANIM_Penguin_Walk)
        Call(NpcMoveTo, NPC_Penguin_05, 600, 0, 0)
        Call(SetNpcAnimation, NPC_Penguin_05, ANIM_Penguin_Idle)
        Call(SetNpcPos, NPC_Penguin_05, NPC_DISPOSE_LOCATION)
    EndThread
    Wait(10)
    Thread
        Call(SetNpcSpeed, NPC_Penguin_06, Float(3.0))
        Call(SetNpcAnimation, NPC_Penguin_06, ANIM_Penguin_Walk)
        Call(NpcMoveTo, NPC_Penguin_06, 600, 0, 0)
        Call(SetNpcAnimation, NPC_Penguin_06, ANIM_Penguin_Idle)
        Call(SetNpcPos, NPC_Penguin_06, NPC_DISPOSE_LOCATION)
    EndThread
    Wait(10)
    Thread
        Call(SetNpcSpeed, NPC_Penguin_07, Float(3.0))
        Call(SetNpcAnimation, NPC_Penguin_07, ANIM_Penguin_Walk)
        Call(NpcMoveTo, NPC_Penguin_07, 600, 0, 0)
        Call(SetNpcAnimation, NPC_Penguin_07, ANIM_Penguin_Idle)
        Call(SetNpcPos, NPC_Penguin_07, NPC_DISPOSE_LOCATION)
    EndThread
    Wait(10)
    Thread
        Call(SetNpcSpeed, NPC_Penguin_08, Float(3.0))
        Call(SetNpcAnimation, NPC_Penguin_08, ANIM_Penguin_Walk)
        Call(NpcMoveTo, NPC_Penguin_08, 600, 0, 0)
        Call(SetNpcAnimation, NPC_Penguin_08, ANIM_Penguin_Idle)
        Call(SetNpcPos, NPC_Penguin_08, NPC_DISPOSE_LOCATION)
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcInteract_PenguinCrowd) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_Penguin_05, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0061)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_06, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0062)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_07, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0063)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_08, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0064)
        CaseEq(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_Penguin_05, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0065)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_06, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0066)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_07, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0067)
            Wait(10)
            Call(SpeakToPlayer, NPC_Penguin_08, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0068)
            Exec(N(EVS_PenguinCrowd_Leave))
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    ExecWait(N(EVS_NpcInteract_PenguinCrowd))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_07) = {
    ExecWait(N(EVS_NpcInteract_PenguinCrowd))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_08) = {
    ExecWait(N(EVS_NpcInteract_PenguinCrowd))
    Return
    End
};

EvtScript N(EVS_Inspect_Present) = {
    Call(ShowMessageAtScreenPos, MSG_CH7_0004, 160, 40)
    Return
    End
};

EvtScript N(EVS_NpcInit_MayorPenguin) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MayorPenguin)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -270, 0, -205)
            Call(InterpNpcYaw, NPC_SELF, 180, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Dead)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -300, 0, -160)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_MayorDummy) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(InterpNpcYaw, NPC_SELF, 183, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_MayorPenguinWife) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MayorPenguinWife)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(SetNpcPos, NPC_SELF, -310, 0, 94)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -297, 0, -69)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -297, 0, -69)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_PenguinPatrol) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_PenguinPatrol)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PenguinPatrol)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -255, 0, -178)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Herringway) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(InterpNpcYaw, NPC_SELF, 270, 0)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(BindNpcInteract, NPC_Herringway, Ref(N(EVS_NpcInteract_Herringway)))
            Call(SetNpcPos, NPC_SELF, -228, 0, 91)
            Call(InterpNpcYaw, NPC_SELF, 270, 0)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_PenguinCrowd)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -150, 0, 0)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_06)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -90, 0, 0)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_07) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_07)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -120, 0, -30)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_08) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_08)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -120, 0, 30)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_09) = {
    IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        Call(SetNpcFlagBits, NPC_Penguin_09, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
        Call(EnableNpcShadow, NPC_Penguin_09, FALSE)
        Call(SetNpcPos, NPC_Penguin_09, -325, 0, -240)
    EndIf
    Return
    End
};

NpcData N(NpcData_MayorPenguin)[] = {
    {
        .id = NPC_MayorPenguin,
        .pos = { -272.0f, 0.0f, -180.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorPenguin),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguin,
    },
    {
        .id = NPC_MayorDummy,
        .pos = { -272.0f, 0.0f, -180.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorDummy),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguin,
    },
    {
        .id = NPC_MayorPenguinWife,
        .pos = { -316.0f, 0.0f, 113.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorPenguinWife),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguinWife,
    },
    {
        .id = NPC_PenguinPatrol,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_PenguinPatrol),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_PATROL_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Patrol,
    },
    {
        .id = NPC_Herringway,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Herringway),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = HERRINGWAY_ANIMS,
        .tattle = MSG_NpcTattle_Herringway,
    },
    {
        .id = NPC_Penguin_01,
        .pos = { -150.0f, 0.0f, 400.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -150, 0, 400 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_01),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GossipPenguin,
    },
    {
        .id = NPC_Penguin_02,
        .pos = { 100.0f, 0.0f, 250.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, 250 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_02),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_FriendlyPenguin,
    },
    {
        .id = NPC_Penguin_03,
        .pos = { 400.0f, 0.0f, 50.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 400, 0, 50 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_03),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_CheerfulPenguin,
    },
    {
        .id = NPC_Penguin_04,
        .pos = { 350.0f, 0.0f, -190.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_04),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
};

NpcData N(NpcData_Penguin_05)[] = {
    {
        .id = NPC_Penguin_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Penguin_05),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_RumorLovingPenguins,
    },
    {
        .id = NPC_Penguin_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Penguin_06),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_NotAdventurous,
    },
    {
        .id = NPC_Penguin_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Penguin_07),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
    {
        .id = NPC_Penguin_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_08),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
};

NpcData N(NpcData_Penguin_09) = {
    .id = NPC_Penguin_09,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Penguin_09),
    .settings = &N(NpcSettings_Penguin),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = PENGUIN_ANIMS,
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 230.0f, 0.0f, 150.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_SAM, QUIZ_COUNT_SAM, QUIZ_MAP_SAM_01 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_05), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_09), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(MysteryNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_05), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_09), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};
