#include "Sentinel.h"
#include "world/partners.h"
#include "sprite/player.h"

#include "world/common/enemy/ai/SentinelAI.inc.c"

EvtScript N(EVS_NpcAuxAI_Sentinel) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_DONT_UPDATE_SHADOW_Y | NPC_FLAG_JUMPING, TRUE)
    Return
    End
};

MobileAISettings N(AISettings_Sentinel) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 1,
    .chaseRadius = 240.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Sentinel) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, -650)
    Call(SetSelfVar, 6, 30)
    Call(SetSelfVar, 1, 600)
    Call(N(SentinelAI_Main), Ref(N(AISettings_Sentinel)))
    Call(DisablePlayerInput, TRUE)
    Wait(2)
    Label(20)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar4, LVar2)
    Call(GetPlayerActionState, LVar0)
    IfNe(LVar0, ACTION_STATE_IDLE)
        Wait(1)
        Goto(20)
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(InterruptUsePartner)
    Call(DisablePartnerAI, 0)
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Add(LVar2, 2)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(func_80045838, -1, SOUND_SENTINEL_PICKUP, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim08)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
    Wait(10)
    Call(func_80045838, -1, SOUND_LRAW_SENTINEL_ALARM | SOUND_ID_TRIGGER_CHANGE_SOUND, 0)
    Thread
        Loop(100)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_TALK)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    EndThread
    Wait(30)
    Call(GotoMap, Ref("dgb_00"), dgb_00_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_UnusedSentinelOnHit) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_NONE)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            ExecWait(EVS_NpcHitRecoil)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UnusedSentinelDefeat) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Sentinel) = {
    .height = 38,
    .radius = 32,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_Sentinel),
    .ai = &N(EVS_NpcAI_Sentinel),
};
