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
    EVT_CALL(N(MagikoopaAI_Main), EVT_PTR(N(AISettings_Magikoopa)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Magikoopa) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Magikoopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(N(MagikoopaAI_OnPlayerWon))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(N(MagikoopaAI_OnPlayerFled))
            EVT_CALL(OnPlayerFled, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_Magikoopa_FlyingHitbox) = {
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(SetSelfVar, 2, 55)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Magikoopa_Hitbox) = {
    EVT_CALL(N(MagikoopaAI_SpellMain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Magikoopa_Hitbox) = {
    EVT_CALL(N(MagikoopaAI_OnHitInit))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(MagikoopaAI_OnHit))
    EVT_EXEC(EnemyNpcHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Magikoopa_Hitbox) = {
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
