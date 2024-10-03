#include "kpa_10.h"

#include "world/common/npc/Toad_Stationary.inc.c"

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
#if VERSION_JP
        .pos = { 840.0f, 30.0f, -260.0f },
#else
        .pos = { 845.0f, 30.0f, -285.0f },
#endif
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadA,
    },
    {
        .id = NPC_Toad_02,
#if VERSION_JP
        .pos = { 870.0f, 30.0f, -310.0f },
#else
        .pos = { 872.0f, 30.0f, -315.0f },
#endif
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadB,
    },
    {
        .id = NPC_ToadGuard,
#if VERSION_JP
        .pos = { 900.0f, 30.0f, -260.0f },
#else
        .pos = { 900.0f, 30.0f, -285.0f },
#endif
        .yaw = 0,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierA,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_02),
    {}
};
