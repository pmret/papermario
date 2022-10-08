#include "common.h"
#include "sprite/npc/LargePiranha.h"

#define PUTRID_PIRANHA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define PUTRID_PIRANHA_ANIMS \
{ \
    .idle   = ANIM_LargePiranha_Putrid_Anim01, \
    .walk   = ANIM_LargePiranha_Putrid_Anim02, \
    .run    = ANIM_LargePiranha_Putrid_Anim03, \
    .chase  = ANIM_LargePiranha_Putrid_Anim03, \
    .anim_4 = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_5 = ANIM_LargePiranha_Putrid_Anim01, \
    .death  = ANIM_LargePiranha_Putrid_Anim0E, \
    .hit    = ANIM_LargePiranha_Putrid_Anim0E, \
    .anim_8 = ANIM_LargePiranha_Putrid_Anim18, \
    .anim_9 = ANIM_LargePiranha_Putrid_Anim17, \
    .anim_A = ANIM_LargePiranha_Putrid_Anim05, \
    .anim_B = ANIM_LargePiranha_Putrid_Anim06, \
    .anim_C = ANIM_LargePiranha_Putrid_Anim07, \
    .anim_D = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_E = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_F = ANIM_LargePiranha_Putrid_Anim01, \
}

// auxiliary NPC used for triggering enemy first strikes during the bite animation
#define PUTRID_PIRANHA_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_PutridPiranha_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS, \
    .drops = { \
        .dropFlags = NPC_DROP_FLAGS_80, \
        .heartDrops  = NO_DROPS, \
        .flowerDrops = NO_DROPS, \
    }, \
    .animations = PUTRID_PIRANHA_ANIMS, \
}

extern EvtScript EVS_NpcHitRecoil;

#include "world/common/enemy/PiranhaPlantAI.inc.c"

EvtScript N(EVS_NpcDefeat_PutridPiranha_Hitbox) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_Piranha) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_Piranha) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(AISettings_Piranha)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PutridPiranha) = {
    .height = 50,
    .radius = 36,
    .level = 17,
    .ai = &N(EVS_NpcAI_Piranha),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_PutridPiranha_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_20DE)
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
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PutridPiranha_Hitbox) = {
    .height = 20,
    .radius = 28,
    .level = 17,
    .ai = &N(EVS_NpcAI_PutridPiranha_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_PutridPiranha_Hitbox),
};
