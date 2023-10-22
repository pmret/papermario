#include "PutridPiranha.h"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

#include "world/common/enemy/ai/GenericHitboxDefeat.inc.c"

MobileAISettings N(AISettings_PutridPiranha) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_PutridPiranha) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(AISettings_PutridPiranha)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PutridPiranha) = {
    .height = 50,
    .radius = 36,
    .level = ACTOR_LEVEL_PUTRID_PIRANHA,
    .ai = &N(EVS_NpcAI_PutridPiranha),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_PutridPiranha_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_PIRANHA_BITE)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244090) = {
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

NpcSettings N(NpcSettings_PutridPiranha_Hitbox) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_PUTRID_PIRANHA,
    .ai = &N(EVS_NpcAI_PutridPiranha_Hitbox),
    .onDefeat = &N(EVS_GenericHitboxDefeat),
};
