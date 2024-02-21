#include "jan_02.h"
#include "sprite/player.h"

#include "world/common/npc/Yoshi.inc.c"
#include "world/common/npc/Yoshi_Patrol.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#define QUIZMO_PRE_STATIC_PAD
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_GetRescuedYoshiCount) = {
    Set(LVar0, 0)
    Add(LVar0, GF_JAN05_SavedYoshi)
    Add(LVar0, GF_JAN07_SavedYoshi)
    Add(LVar0, GF_JAN08_SavedYoshi)
    Add(LVar0, GF_JAN10_SavedYoshi)
    Add(LVar0, GF_JAN11_SavedYoshi)
    Return
    End
};

EvtScript N(EVS_Scene_GetJadeRaven) = {
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    IfEq(GF_JAN02_Met_VillageLeader, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0023)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0024)
    EndIf
    Wait(5 * DT)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Walk)
    Call(NpcMoveTo, NPC_SELF, 8, -140, 25)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
    Wait(5 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 25, 15, -150)
    Call(SetPanTarget, CAM_DEFAULT, 25, 15, -150)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(5 * DT)
    Call(PlayerMoveTo, 58, -140, 25)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(func_802D2C14, 1)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Rummage)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Rummage, ANIM_VillageLeader_Rummage, 5, MSG_CH5_0025)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0026)
    EVT_GIVE_KEY_REWARD(ITEM_JADE_RAVEN)
    Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0027)
    Set(GB_StoryProgress, STORY_CH5_GOT_JADE_RAVEN)
    Wait(15 * DT)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Add(LVar3, 25)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(func_802D2C14, 0)
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_SUSHIE)
        Thread
            Wait(15 * DT)
            Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EndThread
        Call(DisablePartnerAI, 0)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 2, MSG_CH5_0028)
    Else
        Call(N(SwitchToPartner), PARTNER_SUSHIE)
        Call(SpeakToPlayer, NPC_PARTNER, -1, -1, 5, MSG_CH5_0029)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Wait(15 * DT)
        Call(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
        Call(MakeLerp, LVar2, 85, 10 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Wait(10 * DT)
        Thread
            Wait(10 * DT)
            Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EndThread
        Call(DisablePartnerAI, 0)
        Call(ContinueSpeech, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002A)
        Wait(10 * DT)
    EndIf
    Call(ContinueSpeech, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002B)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002C)
    Wait(10 * DT)
    Call(EnablePartnerAI)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Return
    End
};

EvtScript N(EVS_NpcInteract_VillageLeader) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            IfEq(GF_JAN02_Met_VillageLeader, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0021)
                Set(GF_JAN02_Met_VillageLeader, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0022)
            EndIf
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        CaseLt(STORY_CH5_GOT_JADE_RAVEN)
            ExecWait(N(EVS_Scene_GetJadeRaven))
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_002D)
        CaseLt(STORY_CH5_ZIP_LINE_READY)
            IfEq(AF_JAN02_RaphaelComment, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_002E)
                Set(AF_JAN02_RaphaelComment, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_002F)
            EndIf
        CaseLt(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0030)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0031)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0032)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0033)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_VillageLeader) = {
    Call(BindNpcIdle, NPC_SELF, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_IdleSit)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_VillageLeader)))
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH5_GOT_JADE_RAVEN)
            Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
            Call(InterpNpcYaw, NPC_SELF, 90, 1)
            Call(SetNpcPos, NPC_SELF, 0, 15, -50)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_VillageLeader)))
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
            Call(InterpNpcYaw, NPC_SELF, 90, 1)
            Call(SetNpcPos, NPC_SELF, 30, 15, -30)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_VillageLeader)))
        CaseDefault
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_VillageLeader)))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Councillor) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            IfEq(AF_JAN02_MetCouncillor, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0034)
                Call(EndSpeech, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0)
                Set(AF_JAN02_MetCouncillor, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0035)
            EndIf
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSitSad, ANIM_LeadersFriend_BowSit, 0, MSG_CH5_0036)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSitSad, ANIM_LeadersFriend_BowSit, 0, MSG_CH5_0037)
            EndIf
        CaseLt(STORY_CH5_GOT_JADE_RAVEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0038)
        CaseLt(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0039)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003A)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003B)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003C)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Councillor) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_LeadersFriend_IdleSit)
    Call(SetNpcCollisionSize, NPC_SELF, 40, 32)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_LeadersFriend_BowSit)
        EndIf
    EndSwitch
    Call(BindNpcIdle, NPC_SELF, 0)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Councillor)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_003D)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            ExecWait(N(EVS_GetRescuedYoshiCount))
            IfEq(LVar0, 0)
                IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_003E)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_003F)
                EndIf
            Else
                IfEq(GF_JAN08_SavedYoshi, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_0040)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0041)
                EndIf
            EndIf
        CaseLe(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0042)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0043)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0044)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0045)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Yoshi_01) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -520, -270, 50)
        Call(NpcMoveTo, NPC_SELF, -420, -270, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN08_SavedYoshi, FALSE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Red_Panic)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Yoshi_01)))
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_0046)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            ExecWait(N(EVS_GetRescuedYoshiCount))
            IfEq(LVar0, 0)
                IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0047)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0048)
                EndIf
            Else
                IfEq(GF_JAN10_SavedYoshi, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0049)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004A)
                EndIf
            EndIf
        CaseLe(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004B)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004C)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004D)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004E)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Yoshi_02) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, 180, -520, 50)
        Call(NpcMoveTo, NPC_SELF, 80, -520, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN10_SavedYoshi, FALSE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Blue_Panic)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Yoshi_02)))
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_004F)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            ExecWait(N(EVS_GetRescuedYoshiCount))
            IfEq(LVar0, 0)
                IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0050)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0051)
                EndIf
            Else
                IfEq(GF_JAN05_SavedYoshi, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0052)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0053)
                EndIf
            EndIf
        CaseLe(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0054)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0055)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0056)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0057)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Yoshi_03) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, 600, -150, 50)
        Call(NpcMoveTo, NPC_SELF, 500, -150, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN05_SavedYoshi, FALSE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Purple_Panic)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Yoshi_03)))
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_03)))
    Return
    End
};

AnimID N(ExtraAnims_Councillor)[] = {
    ANIM_LeadersFriend_TalkSit,
    ANIM_LeadersFriend_TalkSitSad,
    ANIM_LeadersFriend_IdleSit,
    ANIM_LeadersFriend_BowSit,
    ANIM_LIST_END
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_YoshiLeader,
        .pos = { 323.0f, 30.0f, 412.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_VillageLeader),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = YOSHI_LEADER_ANIMS,
        .tattle = MSG_NpcTattle_VillageLeader,
    },
    {
        .id = NPC_YoshiCouncillor,
        .pos = { 172.0f, 30.0f, 418.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Councillor),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = YOSHI_COUNCILLOR_ANIMS,
        .extraAnimations = N(ExtraAnims_Councillor),
        .tattle = MSG_NpcTattle_LeadersFriend,
    },
    {
        .id = NPC_Yoshi_01,
        .pos = { -520.0f, 0.0f, -270.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -520, 0, -270 },
                    { -420, 0, -270 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -520, 0, -270 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_01),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_RED_ANIMS,
        .tattle = MSG_NpcTattle_EntranceYoshi,
    },
    {
        .id = NPC_Yoshi_02,
        .pos = { 180.0f, 0.0f, -520.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { 180, 0, -520 },
                    { 10, 0, -520 },
                    { 100, 0, -600 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 5, 0, -554 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_02),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshi,
    },
    {
        .id = NPC_Yoshi_03,
        .pos = { 600.0f, 0.0f, -150.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 600, 0, -150 },
                    { 485, 0, -220 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 600, 0, -150 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_03),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_LikeableYoshi,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { -150.0f, 15.0f, 300.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_JAN, QUIZ_COUNT_JAN, QUIZ_MAP_JAN_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};
