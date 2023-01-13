#include "mac_00.h"

#define NAME_SUFFIX _Intro
#include "world/common/npc/Luigi.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Toad_Wander.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_NpcInit_Chan_Intro) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 570, 20, -150)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lee_Intro) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 600, 20, -145)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Chan_Intro)[] = {
    ANIM_Chan_Still,
    ANIM_Chan_Idle,
    ANIM_Chan_Run,
    -1
};

s32 N(ExtraAnims_Lee_Intro)[] = {
    ANIM_Lee_Still,
    ANIM_Lee_Idle,
    ANIM_Lee_Talk,
    -1
};

StaticNpc N(NpcData_IntroNPCs)[] = {
    {
        .id = NPC_Luigi_Intro,
        .settings = &N(NpcSettings_Luigi_Intro),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = LUIGI_DROPS,
        .animations = LUIGI_ANIMS,
    },
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { -150.0f, 0.0f, -275.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = TOAD_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_GateGuardian,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Wander_Intro),
        .pos = { 219.0f, 0.0f, -45.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_10000,
        .drops = TOAD_DROPS,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 5,
                .points  = {
                    { 219, 0, -45 },
                    { 144, 0, -10 },
                    { 163, 0, -50 },
                    { 240, 0, 50 },
                    { 275, 0, 10 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShopLoiterer,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { 424.0f, 20.0f, -85.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_10000,
        .drops = TOAD_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_DojoSpectator,
    },
    {
        .id = NPC_Chan,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { 310.0f, 115.0f, -390.0f },
        .yaw = 45,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .init = &N(EVS_NpcInit_Chan_Intro),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Chan_Idle,
        },
        .extraAnimations = N(ExtraAnims_Chan_Intro),
        .tattle = MSG_NpcTattle_Chan,
    },
    {
        .id = NPC_Lee,
        .settings = &N(NpcSettings_Toad_Stationary_Intro),
        .pos = { 330.0f, 115.0f, -410.0f },
        .yaw = 45,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .init = &N(EVS_NpcInit_Lee_Intro),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Lee_Idle,
        },
        .extraAnimations = N(ExtraAnims_Lee_Intro),
        .tattle = MSG_NpcTattle_Lee,
    },
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_IntroNPCs)),
    {}
};
