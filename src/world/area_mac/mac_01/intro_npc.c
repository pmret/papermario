#include "mac_01.h"

#define NAME_SUFFIX _Intro
#include "world/common/npc/Luigi.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#define NAME_SUFFIX

NpcData N(NpcData_IntroNPCs)[] = {
    {
        .id = NPC_Luigi,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_Luigi_Intro),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
    },
    {
        .id = NPC_IntroToad1,
        .pos = { -94.0f, 0.0f, -117.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_RunsHisMouth,
    },
    {
        .id = NPC_IntroToad2,
        .pos = { 40.0f, 0.0f, -300.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 40, 0, -300 },
                    { -40, 0, -300 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_PrincessFan,
    },
    {
        .id = NPC_IntroToad3,
        .pos = { -380.0f, 20.0f, -100.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_SeeksTheSouth,
    },
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_IntroNPCs)),
    {}
};
