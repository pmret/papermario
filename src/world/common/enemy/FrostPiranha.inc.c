#include "FrostPiranha.h"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

#include "world/common/enemy/ai/GenericHitboxDefeat.inc.c"

MobileAISettings N(AISettings_FrostPiranha) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_FrostPiranha) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(AISettings_FrostPiranha)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_FrostPiranha) = {
    .height = 50,
    .radius = 36,
    .level = ACTOR_LEVEL_FROST_PIRANHA,
    .ai = &N(EVS_NpcAI_FrostPiranha),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_FrostPiranha_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_20DE)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802425A8) = {
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

NpcSettings N(NpcSettings_FrostPiranha_Hitbox) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_FROST_PIRANHA,
    .ai = &N(EVS_NpcAI_FrostPiranha_Hitbox),
    .onDefeat = &N(EVS_GenericHitboxDefeat),
};

AnimID N(ExtraAnims_FrostPiranha_Hitbox)[] = {
    ANIM_LargePiranha_Frost_Anim00,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_FrostPiranha)[] = {
    ANIM_LargePiranha_Frost_Anim00,
    ANIM_LargePiranha_Frost_Anim01,
    ANIM_LargePiranha_Frost_Anim0E,
    ANIM_LargePiranha_Frost_Anim05,
    ANIM_LargePiranha_Frost_Anim06,
    ANIM_LargePiranha_Frost_Anim18,
    ANIM_LargePiranha_Frost_Anim17,
    ANIM_LIST_END
};
