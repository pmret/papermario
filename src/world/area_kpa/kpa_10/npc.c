#include "kpa_10.h"

#include "world/common/npc/Toad_Stationary.inc.c"

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { 845.0f, 30.0f, -285.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadA,
    },
    {
        .id = NPC_Toad_02,
        .pos = { 872.0f, 30.0f, -315.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadB,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { 900.0f, 30.0f, -285.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierA,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_02),
    {}
};
