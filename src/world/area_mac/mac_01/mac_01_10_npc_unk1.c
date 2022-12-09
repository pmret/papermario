#include "mac_01.h"

#define NAME_SUFFIX _Intro
#include "world/common/npc/Luigi.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#define NAME_SUFFIX

StaticNpc N(NpcData_Luigi)[] = {
    {
        .id = NPC_Luigi,
        .settings = &N(NpcSettings_Luigi_Intro),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Luigi_Still,
            .walk   = ANIM_Luigi_Still,
            .run    = ANIM_Luigi_Still,
            .chase  = ANIM_Luigi_Still,
            .anim_4 = ANIM_Luigi_Still,
            .anim_5 = ANIM_Luigi_Still,
            .death  = ANIM_Luigi_Still,
            .hit    = ANIM_Luigi_Still,
            .anim_8 = ANIM_Luigi_Still,
            .anim_9 = ANIM_Luigi_Still,
            .anim_A = ANIM_Luigi_Still,
            .anim_B = ANIM_Luigi_Still,
            .anim_C = ANIM_Luigi_Still,
            .anim_D = ANIM_Luigi_Still,
            .anim_E = ANIM_Luigi_Still,
            .anim_F = ANIM_Luigi_Still,
        },
    },
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { -94.0f, 0.0f, -117.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_MAC_RunsHisMouth,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { 40.0f, 0.0f, -300.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
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
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .tattle = MSG_NpcTattle_MAC_PrincessFan,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { -380.0f, 20.0f, -100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Green_Idle,
            .walk   = ANIM_Toad_Green_Walk,
            .run    = ANIM_Toad_Green_Run,
            .chase  = ANIM_Toad_Green_Run,
            .anim_4 = ANIM_Toad_Green_Idle,
            .anim_5 = ANIM_Toad_Green_Idle,
            .death  = ANIM_Toad_Green_Disappointed,
            .hit    = ANIM_Toad_Green_Disappointed,
            .anim_8 = ANIM_Toad_Green_Run,
            .anim_9 = ANIM_Toad_Green_Run,
            .anim_A = ANIM_Toad_Green_Run,
            .anim_B = ANIM_Toad_Green_Run,
            .anim_C = ANIM_Toad_Green_Run,
            .anim_D = ANIM_Toad_Green_Run,
            .anim_E = ANIM_Toad_Green_Run,
            .anim_F = ANIM_Toad_Green_Run,
        },
        .tattle = MSG_NpcTattle_MAC_SeeksTheSouth,
    },
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Luigi)),
    {}
};
