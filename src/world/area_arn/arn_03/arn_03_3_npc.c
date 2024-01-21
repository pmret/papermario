#include "arn_03.h"
#include "sprite/player.h"

#include "world/common/npc/Boo_Patrol.inc.c"
#include "world/common/npc/Boo.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/atomic/MarioSalute.inc.c"

EvtScript N(EVS_NpcInteract_Boo_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_02, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0073)
                Set(AF_ARN_02, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0074)
                Set(AF_ARN_02, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0075)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0076)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0077)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0078)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(10)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(20)
            Call(EndSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Boo_01) = {
    Call(DisablePlayerInput, TRUE)
    Wait(25 * DT)
    Thread
        Wait(50 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 325)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Thread
        Wait(20 * DT)
        Call(GetCurrentPartnerID, LVar6)
        IfNe(LVar6, PARTNER_BOW)
            Call(BringPartnerOut, PARTNER_BOW)
            Call(DisablePartnerAI, 0)
            Wait(1)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            Wait(5 * DT)
            Call(SetNpcJumpscale, NPC_PARTNER, 0)
            IfEq(LVar6, PARTNER_PARAKARRY)
                Call(NpcJump0, NPC_PARTNER, -81, 176, 171, 20 * DT)
            Else
                Call(NpcJump0, NPC_PARTNER, -81, 186, 171, 20 * DT)
            EndIf
            Call(EnablePartnerAI)
        EndIf
    EndThread
    Call(SetNpcJumpscale, NPC_SELF, 0)
    Call(NpcJump0, NPC_SELF, -8, 186, 159, 60 * DT)
    Wait(15 * DT)
    Call(DisablePartnerAI, 0)
    Call(InterpNpcYaw, NPC_SELF, -4, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_006E)
    Call(InterpNpcYaw, NPC_PARTNER, -1, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_006F)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0070)
    Call(InterpNpcYaw, NPC_PARTNER, -1, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_0071)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0072)
    Call(EnablePartnerAI)
    Wait(10 * DT)
    Call(GetCurrentPartnerID, LVar6)
    IfNe(LVar6, PARTNER_BOW)
        Call(PutPartnerAway)
    EndIf
    Thread
        Call(NpcMoveTo, NPC_SELF, 30, 125, 30 * DT)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndThread
    Call(func_802CF56C, 2)
    Wait(15 * DT)
    Set(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
    Call(DisablePlayerInput, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    IfLt(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
        Call(SetNpcPos, NPC_SELF, 175, 240, 145)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_01)))
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_02) = {
    IfNe(MV_Unk_00, 0)
        IfGe(MV_Unk_00, MV_Unk_01)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0081)
            Set(LVar0, 118)
            Set(LVar1, 1)
            ExecWait(N(GiveItemReward))
            Call(AddKeyItem, ITEM_KOOT_PACKAGE)
            Set(MV_Unk_00, 0)
            Set(GF_ARN03_RecievedPackage, TRUE)
            Set(GF_ARN03_WaitingForPackage, FALSE)
            Return
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0080)
            Return
        EndIf
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_03, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0079)
                Set(AF_ARN_03, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007A)
                Set(AF_ARN_03, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007B)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007C)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007D)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007E)
    EndSwitch
    IfEq(GF_ARN03_RecievedPackage, FALSE)
        IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH7_2)
            ExecWait(N(EVS_MarioSalute))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007F)
            Call(EndSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0)
            Set(MV_Unk_00, 0)
            Set(MV_Unk_01, 450 * DT)
            Set(GF_ARN03_WaitingForPackage, TRUE)
            Thread
                Loop(0)
                    Add(MV_Unk_00, 1)
                    Wait(1)
                    IfGe(MV_Unk_00, MV_Unk_01)
                        BreakLoop
                    EndIf
                EndLoop
            EndThread
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_02)))
    Return
    End
};

EvtScript N(802428CC) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfGt(LVar0, LVar3)
        Add(LVar0, 60)
        Call(SetNpcYaw, NPC_Boo_05, 90)
    Else
        Sub(LVar0, 60)
        Call(SetNpcYaw, NPC_Boo_05, 270)
    EndIf
    Add(LVar1, 20)
    Call(SetNpcPos, NPC_Boo_05, LVar0, LVar1, LVar2)
    Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Wait(1)
    Return
    End
};

EvtScript N(802429D4) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfGt(LVar0, LVar3)
        Add(LVar0, 30)
    Else
        Sub(LVar0, 30)
    EndIf
    Thread
        Call(MakeLerp, 0, 255, 40, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Call(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 40)
    Return
    End
};

EvtScript N(80242B0C) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfGt(LVar0, LVar3)
        Add(LVar0, 60)
    Else
        Sub(LVar0, 60)
    EndIf
    Thread
        Call(MakeLerp, 255, 0, 40, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Call(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 40)
    Call(SetNpcPos, NPC_Boo_05, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(80242C60) = {
    ExecWait(N(802429D4))
    Set(MV_Unk_02, 0)
    Set(MV_Unk_03, 0)
    Thread
        Wait(25)
        Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Cower)
        Loop(0)
            IfEq(MV_Unk_02, 1)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
    EndThread
    Call(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Spook)
    Call(EndSpeech, NPC_Boo_05, ANIM_Boo_Tan_Spook, ANIM_Boo_Tan_Spook, 5)
    Wait(30)
    Call(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Idle)
    Wait(10)
    ExecWait(N(80242B0C))
    Set(MV_Unk_02, 1)
    Wait(15)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_04, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0082)
                Set(AF_ARN_04, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0083)
                Set(AF_ARN_04, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0084)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0085)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(DisablePartnerAI, 0)
            Call(DisablePlayerPhysics, TRUE)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar2, -20)
                Call(SetNpcSpeed, NPC_PARTNER, Float(2.0))
                Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EndThread
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0086)
            ExecWait(N(802428CC))
            Call(PlayerFaceNpc, NPC_Boo_05, TRUE)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_Boo_05, 1)
            Call(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0087)
            ExecWait(N(80242C60))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0088)
            Call(DisablePlayerPhysics, FALSE)
            Call(EnablePartnerAI)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(DisablePartnerAI, 0)
            Call(DisablePlayerPhysics, TRUE)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Add(LVar2, -20)
                Call(SetNpcSpeed, NPC_PARTNER, Float(2.0))
                Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EndThread
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0089)
            ExecWait(N(802428CC))
            Call(PlayerFaceNpc, NPC_Boo_05, TRUE)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_Boo_05, 1)
            Call(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_008A)
            ExecWait(N(80242C60))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008B)
            Call(DisablePlayerPhysics, FALSE)
            Call(EnablePartnerAI)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_03)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Boo_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            IfEq(AF_ARN_05, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008C)
                Set(AF_ARN_05, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008D)
                Set(AF_ARN_05, FALSE)
            EndIf
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008E)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008F)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0090)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0091)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Boo_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

NpcData N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .pos = { 36.0f, 185.0f, 140.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 36, 10, 185 },
                { 56, 10, 185 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 479, 215, 198 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Boo_01),
    .settings = &N(NpcSettings_Boo_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_LovesBow,
};

NpcData N(NpcData_Boo_02) = {
    .id = NPC_Boo_02,
    .pos = { 209.0f, 185.0f, 217.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_02),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooA,
};

NpcData N(NpcData_Boo_03) = {
    .id = NPC_Boo_03,
    .pos = { 379.0f, 186.0f, 186.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 379, 10, 186 },
                { 399, 10, 186 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 479, 215, 198 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Boo_03),
    .settings = &N(NpcSettings_Boo_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooB,
};

NpcData N(NpcData_Boo_04) = {
    .id = NPC_Boo_04,
    .pos = { 544.0f, 235.0f, 128.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_04),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooC,
};

NpcData N(NpcData_Boo_05) = {
    .id = NPC_Boo_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_05),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

EvtScript N(EVS_NpcIdle_Boo_06) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Set(LVar3, LVar0)
    Add(LVar3, -60)
    Set(LVar4, LVar0)
    Add(LVar4, 60)
    Loop(0)
        Call(RandInt, 5, LVar5)
        SetF(LVar6, LVar5)
        MulF(LVar6, Float(0.1))
        AddF(LVar6, Float(0.8))
        Call(SetNpcSpeed, NPC_SELF, LVar6)
        Call(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
        Call(RandInt, 5, LVar5)
        SetF(LVar6, LVar5)
        MulF(LVar6, Float(0.1))
        AddF(LVar6, Float(0.8))
        Call(SetNpcSpeed, NPC_SELF, LVar6)
        Call(NpcMoveTo, NPC_SELF, LVar4, LVar2, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_07) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_08) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Boo_09) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Boo_06)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Return
    End
};

NpcData N(NpcData_Boo_06)[] = {
    {
        .id = NPC_Boo_06,
        .pos = { 36.0f, 277.0f, 140.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_06),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_07,
        .pos = { 180.0f, 285.0f, 182.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_07),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_08,
        .pos = { 349.0f, 286.0f, 152.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_08),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_09,
        .pos = { 490.0f, 324.0f, 128.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_09),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    NPC_GROUP(N(NpcData_Boo_06)),
    {}
};
