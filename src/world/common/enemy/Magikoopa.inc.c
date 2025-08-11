#include "Magikoopa.h"

#include "world/common/enemy/ai/MagikoopaAI.inc.c"

MagikoopaTeleportAnim N(MagikoopaAI_TeleportAnim)[] = {
    { 0.80f, 1.0f, 200 },
    { 0.60f, 1.0f, 180 },
    { 0.50f, 1.0f, 160 },
    { 0.40f, 1.0f, 140 },
    { 0.30f, 1.1f, 120 },
    { 0.20f, 1.3f, 110 },
    { 0.15f, 1.6f, 100 },
    { 0.12f, 2.0f, 90 },
    { 0.11f, 3.0f, 80 },
    { 0.10f, 4.0f, 70 },
    {}
};

MobileAISettings N(AISettings_Magikoopa) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Magikoopa) = {
    Call(N(MagikoopaAI_Main), Ref(N(AISettings_Magikoopa)))
    Return
    End
};

EvtScript N(EVS_NpcHit_Magikoopa) = {
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

EvtScript N(EVS_NpcDefeat_Magikoopa) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(N(MagikoopaAI_OnPlayerWon))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(N(MagikoopaAI_OnPlayerFled))
            Call(OnPlayerFled, 0)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Magikoopa) = {
    .height = 32,
    .radius = 28,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .ai = &N(EVS_NpcAI_Magikoopa),
    .onHit = &N(EVS_NpcHit_Magikoopa),
    .onDefeat = &N(EVS_NpcDefeat_Magikoopa),
};

AnimID N(ExtraAnims_Magikoopa)[] = {
    ANIM_Magikoopa_Anim00,
    ANIM_Magikoopa_Anim01,
    ANIM_Magikoopa_Anim01,
    ANIM_Magikoopa_Anim01,
    ANIM_Magikoopa_Anim02,
    ANIM_Magikoopa_Anim03,
    ANIM_Magikoopa_Anim04,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcAuxAI_Magikoopa_GroundHitbox) = {
    Call(SetSelfVar, 1, 10)
    Call(SetSelfVar, 2, 40)
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_Magikoopa_FlyingHitbox) = {
    Call(SetSelfVar, 1, 0)
    Call(SetSelfVar, 2, 55)
    Return
    End
};

EvtScript N(EVS_NpcAI_Magikoopa_Hitbox) = {
    Call(N(MagikoopaAI_SpellMain))
    Return
    End
};

EvtScript N(EVS_NpcHit_Magikoopa_Hitbox) = {
    Call(N(MagikoopaAI_OnHitInit))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(N(MagikoopaAI_OnHit))
    Exec(EnemyNpcHit)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Magikoopa_Hitbox) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(OnPlayerFled, 1)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Magikoopa_GroundHitbox) = {
    .defaultAnim = ANIM_Magikoopa_Anim00,
    .otherAI = &N(EVS_NpcAuxAI_Magikoopa_GroundHitbox),
    .ai = &N(EVS_NpcAI_Magikoopa_Hitbox),
    .onHit = &N(EVS_NpcHit_Magikoopa_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_Magikoopa_Hitbox),
};

NpcSettings N(NpcSettings_Magikoopa_FlyingHitbox) = {
    .defaultAnim = ANIM_FlyingMagikoopa_Anim00,
    .otherAI = &N(EVS_NpcAuxAI_Magikoopa_FlyingHitbox),
    .ai = &N(EVS_NpcAI_Magikoopa_Hitbox),
    .onHit = &N(EVS_NpcHit_Magikoopa_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_Magikoopa_Hitbox),
};
