#include "HeartPlant.h"

#include "world/common/todo/HeartPlant_SpawnHeart.inc.c"

extern EvtScript N(EVS_NpcInteract_HeartPlant);

EvtScript N(EVS_NpcAuxAI_HeartPlant) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HeartPlant_RebindInteractAfterDelay) = {
    EVT_WAIT(45)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HeartPlant)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_HeartPlant) = {
    EVT_CALL(GetSelfVar, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetSelfVar, 1, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEART_PLANT, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim00)
        EVT_WAIT(1)
        EVT_CALL(N(HeartPlant_SpawnHeart))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim01)
        EVT_THREAD
            EVT_CALL(BindNpcInteract, NPC_SELF, NULL)
            EVT_EXEC(N(EVS_HeartPlant_RebindInteractAfterDelay))
            EVT_WAIT(45)
            EVT_CALL(SetSelfVar, 1, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HeartPlant_Anim00)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HeartPlant) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_HeartPlant),
    .onInteract = &N(EVS_NpcInteract_HeartPlant),
};

#define HEART_PLANT_NPC_DATA \
    .settings = &N(NpcSettings_HeartPlant), \
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000, \
    .drops = NO_DROPS, \
    .animations = HEART_PLANT_ANIMS, \
    .tattle = MSG_NpcTattle_HeartPlant, \
