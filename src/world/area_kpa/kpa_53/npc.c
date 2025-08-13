#include "kpa_53.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(UpdateFollowerPosition)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Npc* npc = resolve_npc(script, npcID);
    u32 animID;

    if (npc == nullptr) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = (s32)(((s32)playerStatus->pos.x - 700) * 0.85) + 765;
    if (playerStatus->curSpeed == 0.0f) {
        animID = ANIM_Peach1_Idle;
    } else if (playerStatus->curSpeed < 2.0f) {
        animID = ANIM_Peach1_Walk;
    } else {
        animID = ANIM_Peach1_Run;
    }
    npc->curAnim = animID;
    evt_set_variable(script, outVar, playerStatus->targetYaw);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Peach.inc.c"

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
};

EvtScript N(EVS_NpcAI_Duplighost_Flee) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -130)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        IfGe(LVar1, LVar0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20)
    Call(InterpNpcYaw, NPC_SELF, 90, 5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 150)
    Call(NpcMoveTo, NPC_SELF, LVar0, -30, 20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim02)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcAI_Duplighost_Caught) = {
    Call(DisablePlayerInput, true)
    Call(GetNpcPos, NPC_Follower, LVar2, LVar3, LVar4)
    Thread
        Add(LVar4, 15)
        Loop(8)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 1, 1, 1, 1)
            Wait(5)
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_Follower, SOUND_GHOST_TRANSFORM, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 1440, 20, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Follower, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtNpc, NPC_Follower, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
    Call(SetNpcPos, NPC_Guardian, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Follower, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_Follower, false)
    Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(MakeLerp, -1440, 0, 20, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0, MSG_CH8_002D)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 700)
        Add(LVar0, 30)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 35)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Duplighost) = {
    Call(RemoveNpc, NPC_Follower)
    Call(RemoveNpc, NPC_Guardian)
    Set(GF_KPA53_Defeated_PeachImposter, true)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_83_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Call(DisablePlayerInput, false)
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost) = {
    IfEq(GF_KPA53_Defeated_PeachImposter, false)
        IfEq(GF_KPA53_Met_PeachImposter, true)
            Call(SetNpcPos, NPC_SELF, -120, 0, -30)
            Call(SetNpcYaw, NPC_SELF, 270)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Duplighost_Flee)))
        EndIf
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Duplighost)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Follower_FirstTime) = {
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0023)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(1)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(35)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0024)
            Set(GF_KPA53_Met_PeachImposter, true)
            Call(SetSelfVar, 0, 1)
            Call(SetSelfVar, 1, 1)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0025)
            Call(SetSelfVar, 0, 2)
        CaseEq(2)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0026)
            Call(SetSelfVar, 0, 1)
    EndSwitch
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Follower) = {
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0027)
        Call(SetSelfVar, 0, 1)
        Call(SetSelfVar, 1, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0028)
    EndIf
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcHit_Guardian_FirstTime) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(DisablePlayerInput, true)
            Call(SetNpcVar, NPC_Follower, 2, 1)
            Call(InterpNpcYaw, NPC_Follower, 270, 0)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
            Wait(10)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
            Call(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0029)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
            Wait(10)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
            Call(SetNpcVar, NPC_Follower, 2, 0)
            Call(DisablePlayerInput, false)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_Guardian) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(DisablePlayerInput, true)
            Call(SetNpcVar, NPC_Follower, 2, 1)
            Call(InterpNpcYaw, NPC_Follower, 270, 0)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
            Wait(10)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
            Call(GetSelfVar, 0, LVar1)
            Switch(LVar1)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002A)
                    Call(SetSelfVar, 0, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002B)
                    Call(SetSelfVar, 0, 2)
                CaseEq(2)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    IfLt(LVar0, 270)
                        Call(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002B)
                    Else
                        Call(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002C)
                        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, true)
                        Call(BindNpcAI, NPC_Duplighost, Ref(N(EVS_NpcAI_Duplighost_Caught)))
                    EndIf
            EndSwitch
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
            Wait(10)
            Call(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
            Call(SetNpcVar, NPC_Follower, 2, 0)
            Call(DisablePlayerInput, false)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Follower) = {
    Loop(0)
        Wait(1)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Set(LVarF, 0)
    Loop(0)
        Wait(1)
        Switch(LVarF)
            CaseEq(0)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLe(LVar0, 700)
                    Set(LVarF, 1)
                EndIf
            CaseEq(1)
                Call(GetSelfVar, 2, LVar0)
                IfEq(LVar0, 1)
                    BreakSwitch
                EndIf
                Call(N(UpdateFollowerPosition), 0, LVar0)
                Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
                Call(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
                Call(InterpNpcYaw, NPC_Guardian, LVar0, 0)
                Call(SetNpcPos, NPC_Guardian, LVar1, LVar2, LVar3)
                IfLe(LVar1, 100)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_Peach1_Idle)
                    Call(SetNpcPos, NPC_SELF, 765, 0, -30)
                    Call(SetNpcPos, NPC_Guardian, 765, 0, -30)
                    Call(SetNpcPos, NPC_Duplighost, 150, 0, -30)
                    Call(SetNpcYaw, NPC_Duplighost, 270)
                    Call(BindNpcAI, NPC_Duplighost, Ref(N(EVS_NpcAI_Duplighost_Flee)))
                    Call(SetSelfVar, 0, 0)
                    Call(BindNpcInteract, NPC_Follower, Ref(N(EVS_NpcInteract_Follower)))
                    Call(SetNpcVar, NPC_Guardian, 0, 0)
                    Call(BindNpcHit, NPC_Guardian, Ref(N(EVS_NpcHit_Guardian)))
                    Set(LVarF, 2)
                EndIf
                IfGe(LVar1, 765)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_Peach1_Idle)
                    Call(InterpNpcYaw, NPC_SELF, 270, 0)
                    Set(LVarF, 0)
                EndIf
            CaseEq(2)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfGt(LVar0, 700)
                    Set(LVarF, 0)
                EndIf
        EndSwitch
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Follower) = {
    IfEq(GF_KPA53_Defeated_PeachImposter, false)
        Call(SetNpcPos, NPC_SELF, 765, 0, -30)
        IfEq(GF_KPA53_Met_PeachImposter, false)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Follower_FirstTime)))
        Else
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Follower)))
        EndIf
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Follower)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Guardian) = {
    IfEq(GF_KPA53_Defeated_PeachImposter, false)
        Call(SetNpcPos, NPC_SELF, 765, 0, -30)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, true)
        Call(EnableNpcShadow, NPC_SELF, false)
        IfEq(GF_KPA53_Met_PeachImposter, false)
            Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Guardian_FirstTime)))
        Else
            Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Guardian)))
        EndIf
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Imposter)[] = {
    {
        .id = NPC_Follower,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Follower),
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
        .tattle = MSG_NpcTattle_KPA_FakePrincessPeach,
    },
    {
        .id = NPC_Guardian,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Guardian),
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
        .tattle = MSG_NpcTattle_KPA_FakePrincessPeach,
    },
    {
        .id = NPC_Duplighost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Duplighost),
        .settings = &N(NpcSettings_Duplighost),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 5, 0 },
                { ITEM_MAPLE_SYRUP, 5, 0 },
                { ITEM_THUNDER_RAGE, 5, 0 },
                { ITEM_STOP_WATCH, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(5),
            .minCoinBonus = 1,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Imposter), BTL_KPA3_FORMATION_02, BTL_KPA3_STAGE_00),
    {}
};
