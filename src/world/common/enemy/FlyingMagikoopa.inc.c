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
    EVT_CALL(N(FlyingMagikoopaAI_Main), EVT_PTR(N(AISettings_FlyingMagikoopa)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_FlyingMagikoopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_FlyingMagikoopa_Hitbox) = {
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(SetSelfVar, 2, 55)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_FlyingMagikoopa_Hitbox) = {
    EVT_CALL(N(MagikoopaAI_SpellMain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_FlyingMagikoopa_Hitbox) = {
    EVT_CALL(N(FlyingMagikoopaAI_OnHitInit))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(FlyingMagikoopaAI_OnHit))
    EVT_EXEC(EnemyNpcHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_FlyingMagikoopa_Hitbox) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
