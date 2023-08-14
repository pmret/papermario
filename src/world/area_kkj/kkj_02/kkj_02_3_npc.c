#include "kkj_02.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Intro_0049)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 0, MSG_Intro_004A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toads)[] = {
    {
        .id = NPC_Toad,
        .pos = { 0.0f, 0.0f, -100.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, -100 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, -100 },
                .detectSize = { 50 },
            }
        },
        .init = &N(EVS_NpcInit_Toad),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { 1175.0f, 110.0f, 60.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toads)),
    {}
};


