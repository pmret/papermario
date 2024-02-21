#include "jan_01.h"
#include "effects.h"

#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/enemy/JungleFuzzy.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_PlayerWatchKolorado) = {
    Loop(0)
        Call(PlayerFaceNpc, NPC_SELF, FALSE)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Kolorado_RunToVillage) = {
    ExecGetTID(N(EVS_PlayerWatchKolorado), LVar9)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(4.5 / DT))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 150)
    Call(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    KillThread(LVar9)
    Call(N(EnableCameraLeadingPlayer))
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Call(SetSelfVar, 0, 3)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, -600)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH5_000D, 320, 60)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25 * DT)
    Call(DisablePlayerInput, FALSE)
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfGt(LVar0, 430)
                    Call(GetPartnerInUse, LVar0)
                    IfNe(LVar0, PARTNER_NONE)
                        Call(InterruptUsePartner)
                    EndIf
                    Call(DisablePlayerInput, TRUE)
                    Call(RemoveNpc, NPC_JungleFuzzy_01)
                    Call(ShowMessageAtScreenPos, MSG_CH5_0010, 0, 60)
                    Call(InterpPlayerYaw, 270, 4)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                    Call(NpcMoveTo, NPC_SELF, 250, 90, 5 * DT)
                    Call(func_802CF56C, 2)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Set(LVar3, LVar0)
                    Add(LVar3, -50)
                    Call(SetNpcSpeed, NPC_SELF, Float(5.0 / DT))
                    Call(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
                    Add(LVar0, LVar3)
                    Div(LVar0, 2)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetCamDistance, CAM_DEFAULT, 300)
                    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(N(DisableCameraLeadingPlayer))
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Wait(10 * DT)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0011)
                    Set(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
                    ExecWait(N(EVS_Kolorado_RunToVillage))
                    Call(DisablePlayerInput, FALSE)
                EndIf
            CaseEq(1)
                SetGroup(EVT_GROUP_00)
                Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
                Call(func_802D2C14, 1)
                Wait(10 * DT)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_000F)
                Set(GF_JAN01_SavedKolorado, TRUE)
                Call(SetSelfVar, 0, 2)
                Set(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
                ExecWait(N(EVS_Kolorado_RunToVillage))
                Call(func_802D2C14, 0)
                Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                SetGroup(EVT_GROUP_0B)
                Call(DisablePlayerInput, FALSE)
        EndSwitch
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 3)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_NpcHit_Kolorado) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            Set(LVar1, 1)
        CaseDefault
            Set(LVar1, 0)
    EndSwitch
    IfNe(LVar1, 0)
        Call(DisablePlayerInput, TRUE)
        Wait(5)
        Set(AF_JAN01_KoloradoShouting, TRUE)
        Wait(10)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_000E)
        Set(AF_JAN01_KoloradoShouting, FALSE)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Kolorado)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_JungleFuzzy_01) = {
    ChildThread
        Call(GetNpcPos, NPC_Kolorado, LVar3, LVar1, LVar2)
        Set(LVar4, LVar3)
        Add(LVar3, -200)
        Add(LVar4, 200)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Switch(LVar0)
                CaseRange(LVar3, LVar4)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 0)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 0)
                CaseDefault
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
            EndSwitch
            Wait(1)
        EndLoop
    EndChildThread
    Set(AF_JAN01_KoloradoShouting, FALSE)
    Call(GetNpcPos, NPC_Kolorado, LVar7, LVar8, LVar9)
    Add(LVar8, 20)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 5)
    Call(SetNpcJumpscale, NPC_SELF, Float(4.0))
    Set(LVar4, 40)
    Set(LVar5, 90)
    Set(LVar6, 45)
    Loop(0)
        Mul(LVar4, -1)
        Mul(LVar5, -1)
        Mul(LVar6, -1)
        Add(LVar0, LVar4)
        Call(NpcJump0, NPC_SELF, LVar0, 18, LVar2, 15)
        Call(PlaySoundAtNpc, NPC_Kolorado, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
        IfNe(AF_JAN01_KoloradoShouting, TRUE)
            ChildThread
                Call(InterpNpcYaw, NPC_Kolorado, LVar5, 2)
                PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar7, LVar8, LVar9, 0, -1, 0, 3)
            EndChildThread
        EndIf
        Add(LVar0, LVar4)
        Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
        Call(NpcJump0, NPC_SELF, LVar0, -12, LVar2, 15)
        Label(1)
            Wait(1)
            IfEq(AF_JAN01_KoloradoShouting, TRUE)
                Goto(1)
            EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JungleFuzzyBoss) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DisablePlayerInput, TRUE)
            Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
            Call(GetPartnerInUse, LVar0)
            IfNe(LVar0, PARTNER_NONE)
                Call(InterruptUsePartner)
            EndIf
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Thread
                Wait(30)
                Call(GetNpcPos, NPC_Kolorado, LVar3, LVar1, LVar2)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Set(LVar4, LVar0)
                IfLt(LVar3, LVar0)
                    Call(InterpPlayerYaw, 270, 0)
                    Add(LVar4, -30)
                Else
                    Call(InterpPlayerYaw, 90, 0)
                    Add(LVar4, 30)
                EndIf
                Add(LVar0, LVar4)
                Div(LVar0, 2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, 300)
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
                Call(N(DisableCameraLeadingPlayer))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
                Call(SetNpcSpeed, NPC_Kolorado, Float(3.0))
                IfLt(LVar2, -45)
                    Set(LVar2, -45)
                EndIf
                Call(NpcMoveTo, NPC_Kolorado, LVar4, LVar2, 0)
                Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
                Call(NpcFacePlayer, NPC_Kolorado, 0)
                Call(SetNpcVar, NPC_Kolorado, 0, 1)
            EndThread
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_JungleFuzzy_01) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        Call(SetSelfVar, 0, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Leech)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JungleFuzzy_01)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JungleFuzzyBoss)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -70.0f, -9.0f, 90.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_JungleFuzzy_01) = {
    .id = NPC_JungleFuzzy_01,
    .pos = { -30.0f, 0.0f, 90.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JungleFuzzy_01),
    .settings = &N(NpcSettings_JungleFuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
};

EvtScript N(EVS_NpcInit_JungleFuzzy_02) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_JungleFuzzy_02) = {
    .id = NPC_JungleFuzzy_02,
    .pos = { -350.0f, 3.0f, 40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -350, 3, 40 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 3, 40 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_JungleFuzzy_03) = {
    .id = NPC_JungleFuzzy_03,
    .pos = { 0.0f, -10.0f, 110.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, -10, 110 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, -10, 110 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_JungleFuzzy_04) = {
    .id = NPC_JungleFuzzy_04,
    .pos = { 350.0f, 3.0f, 40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 350, 3, 40 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 350, 3, 75 },
            .detectSize = { 200, 125 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_JungleFuzzy_01), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_02), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_03), BTL_JAN_FORMATION_0B, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_04), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    {}
};
