#include "kkj_19.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcInteract_TayceT) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TayceT_Talk, ANIM_TayceT_Idle, 0, MSG_Intro_0031)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Intro_0032)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TayceT) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TayceT_Idle)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TayceT)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TayceT)[] = {
    {
        .id = NPC_TayceT,
        .pos = { 400.0f, 0.0f, -70.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TayceT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_TayceT_Idle,
        },
    },
    {
        .id = NPC_Toad,
        .pos = { 250.0f, 0.0f, -110.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_TayceT)),
    {}
};
