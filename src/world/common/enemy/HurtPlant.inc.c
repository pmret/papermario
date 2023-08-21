#include "HurtPlant.h"
#include "sprite/player.h"

EvtScript N(EVS_NpcAI_HurtPlant) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim01)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim08)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HURT_PLANT_SHRIEK, SOUND_SPACE_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HurtPlant_Anim02)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(StartBattle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_HurtPlant) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_HurtPlant) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_HurtPlant)))
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HurtPlant) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_HURT_PLANT,
    .onInteract = &N(EVS_NpcInteract_HurtPlant),
    .ai = &N(EVS_NpcAI_HurtPlant),
    .onDefeat = &N(EVS_NpcDefeat_HurtPlant),
};

AnimID N(ExtraAnims_HurtPlant)[] = {
    ANIM_HurtPlant_Anim00,
    ANIM_HurtPlant_Anim01,
    ANIM_HurtPlant_Anim02,
    ANIM_HurtPlant_Anim08,
    ANIM_LIST_END
};

#define HURT_PLANT_NPC_DATA \
    .settings = &N(NpcSettings_HurtPlant), \
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000, \
    .drops = HURT_PLANT_DROPS, \
    .animations = HURT_PLANT_ANIMS, \
    .extraAnimations = N(ExtraAnims_HurtPlant), \
    .tattle = MSG_NpcTattle_HeartPlant, \
