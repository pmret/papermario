#include "FlyingMagikoopa.h"

#include "world/common/enemy/ai/FlyingMagikoopaAI.inc.c"

MobileAISettings N(AISettings_FlyingMagikoopa) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 20.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 5.0f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 20.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_FlyingMagikoopa) = {
    Call(N(FlyingMagikoopaAI_Main), Ref(N(AISettings_FlyingMagikoopa)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_FlyingMagikoopa) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(OnPlayerFled, 0)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_FlyingMagikoopa) = {
    .height = 33,
    .radius = 32,
    .level = ACTOR_LEVEL_FLYING_MAGIKOOPA,
    .ai = &N(EVS_NpcAI_FlyingMagikoopa),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_FlyingMagikoopa),
};

AnimID N(ExtraAnims_FlyingMagikoopa)[] = {
    ANIM_FlyingMagikoopa_Anim00,
    ANIM_FlyingMagikoopa_Anim01,
    ANIM_FlyingMagikoopa_Anim01,
    ANIM_FlyingMagikoopa_Anim01,
    ANIM_FlyingMagikoopa_Anim02,
    ANIM_FlyingMagikoopa_Anim03,
    ANIM_FlyingMagikoopa_Anim04,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcAuxAI_FlyingMagikoopa_AltHitbox) = {
    Call(SetSelfVar, 1, 10)
    Call(SetSelfVar, 2, 40)
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_FlyingMagikoopa_Hitbox) = {
    Call(SetSelfVar, 1, 0)
    Call(SetSelfVar, 2, 55)
    Return
    End
};

EvtScript N(EVS_NpcAI_FlyingMagikoopa_Hitbox) = {
    Call(N(MagikoopaAI_SpellMain))
    Return
    End
};

EvtScript N(EVS_NpcHit_FlyingMagikoopa_Hitbox) = {
    Call(N(FlyingMagikoopaAI_OnHitInit))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(N(FlyingMagikoopaAI_OnHit))
    Exec(EnemyNpcHit)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_FlyingMagikoopa_Hitbox) = {
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

NpcSettings N(NpcSettings_FlyingMagikoopa_AltHitbox) = {
    .defaultAnim = ANIM_Magikoopa_Anim00,
    .otherAI = &N(EVS_NpcAuxAI_FlyingMagikoopa_AltHitbox),
    .ai = &N(EVS_NpcAI_FlyingMagikoopa_Hitbox),
    .onHit = &N(EVS_NpcHit_FlyingMagikoopa_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_FlyingMagikoopa_Hitbox),
};

NpcSettings N(NpcSettings_FlyingMagikoopa_Hitbox) = {
    .defaultAnim = ANIM_FlyingMagikoopa_Anim00,
    .otherAI = &N(EVS_NpcAuxAI_FlyingMagikoopa_Hitbox),
    .ai = &N(EVS_NpcAI_FlyingMagikoopa_Hitbox),
    .onHit = &N(EVS_NpcHit_FlyingMagikoopa_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_FlyingMagikoopa_Hitbox),
};
