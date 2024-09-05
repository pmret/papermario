#include "kmr_22.h"

#include "world/common/npc/StarSpirit.h"
#include "world/common/npc/KoopaBros.h"
#include "world/common/enemy/ShyGuy.h"

MAP_RODATA_PAD(1,npc);

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

// Kolorado?
NpcSettings N(NpcSettings_Unused) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "npc/lava_piranha.inc.c"

#include "npc/chapter_1.inc.c"
#include "npc/chapter_2.inc.c"
#include "npc/chapter_3.inc.c"
#include "npc/chapter_4.inc.c"
#include "npc/chapter_5.inc.c"
#include "npc/chapter_6.inc.c"
#include "npc/chapter_7.inc.c"
#include "npc/chapter_8.inc.c"

NpcData N(NpcData_Chapter1)[] = {
    {
        .id = NPC_Eldstar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
    },
    {
        .id = NPC_KoopaBros_01,
        .pos = { 10.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_02,
        .pos = { 90.0f, 10.0f, 91.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_03,
        .pos = { 86.0f, 0.0f, -7.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_04,
        .pos = { 54.0f, -2.0f, -47.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
    },
};

NpcData N(NpcData_Chapter2)[] = {
    {
        .id = NPC_Mamar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mamar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
    {
        .id = NPC_Tutankoopa,
        .pos = { 78.0f, 19.0f, 20.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Tutankoopa),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Tutankoopa_Idle,
            .walk   = ANIM_Tutankoopa_Idle,
            .run    = ANIM_Tutankoopa_Idle,
            .chase  = ANIM_Tutankoopa_Idle,
            .anim_4 = ANIM_Tutankoopa_Idle,
            .anim_5 = ANIM_Tutankoopa_Idle,
            .death  = ANIM_Tutankoopa_Hurt,
            .hit    = ANIM_Tutankoopa_Hurt,
            .anim_8 = ANIM_Tutankoopa_Idle,
            .anim_9 = ANIM_Tutankoopa_Idle,
            .anim_A = ANIM_Tutankoopa_Idle,
            .anim_B = ANIM_Tutankoopa_Idle,
            .anim_C = ANIM_Tutankoopa_Idle,
            .anim_D = ANIM_Tutankoopa_Idle,
            .anim_E = ANIM_Tutankoopa_Idle,
            .anim_F = ANIM_Tutankoopa_Idle,
        },
    },
    {
        .id = NPC_ChainChomp_01,
        .pos = { 23.0f, -4.0f, -180.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ChainChomp),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChainChomp_Still,
            .walk   = ANIM_ChainChomp_Still,
            .run    = ANIM_ChainChomp_Still,
            .chase  = ANIM_ChainChomp_Still,
            .anim_4 = ANIM_ChainChomp_Still,
            .anim_5 = ANIM_ChainChomp_Still,
            .death  = ANIM_ChainChomp_Still,
            .hit    = ANIM_ChainChomp_Still,
            .anim_8 = ANIM_ChainChomp_Still,
            .anim_9 = ANIM_ChainChomp_Still,
            .anim_A = ANIM_ChainChomp_Still,
            .anim_B = ANIM_ChainChomp_Still,
            .anim_C = ANIM_ChainChomp_Still,
            .anim_D = ANIM_ChainChomp_Still,
            .anim_E = ANIM_ChainChomp_Still,
            .anim_F = ANIM_ChainChomp_Still,
        },
    },
    {
        .id = NPC_ChainChomp_02,
        .pos = { 23.0f, -4.0f, -180.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChainChomp_Still,
            .walk   = ANIM_ChainChomp_Still,
            .run    = ANIM_ChainChomp_Still,
            .chase  = ANIM_ChainChomp_Still,
            .anim_4 = ANIM_ChainChomp_Still,
            .anim_5 = ANIM_ChainChomp_Still,
            .death  = ANIM_ChainChomp_Still,
            .hit    = ANIM_ChainChomp_Still,
            .anim_8 = ANIM_ChainChomp_Still,
            .anim_9 = ANIM_ChainChomp_Still,
            .anim_A = ANIM_ChainChomp_Still,
            .anim_B = ANIM_ChainChomp_Still,
            .anim_C = ANIM_ChainChomp_Still,
            .anim_D = ANIM_ChainChomp_Still,
            .anim_E = ANIM_ChainChomp_Still,
            .anim_F = ANIM_ChainChomp_Still,
        },
    },
    {
        .id = NPC_ChainChomp_03,
        .pos = { 23.0f, -4.0f, -180.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChainChomp_Still,
            .walk   = ANIM_ChainChomp_Still,
            .run    = ANIM_ChainChomp_Still,
            .chase  = ANIM_ChainChomp_Still,
            .anim_4 = ANIM_ChainChomp_Still,
            .anim_5 = ANIM_ChainChomp_Still,
            .death  = ANIM_ChainChomp_Still,
            .hit    = ANIM_ChainChomp_Still,
            .anim_8 = ANIM_ChainChomp_Still,
            .anim_9 = ANIM_ChainChomp_Still,
            .anim_A = ANIM_ChainChomp_Still,
            .anim_B = ANIM_ChainChomp_Still,
            .anim_C = ANIM_ChainChomp_Still,
            .anim_D = ANIM_ChainChomp_Still,
            .anim_E = ANIM_ChainChomp_Still,
            .anim_F = ANIM_ChainChomp_Still,
        },
    },
    {
        .id = NPC_ChainChomp_04,
        .pos = { 23.0f, -4.0f, -180.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChainChomp_Still,
            .walk   = ANIM_ChainChomp_Still,
            .run    = ANIM_ChainChomp_Still,
            .chase  = ANIM_ChainChomp_Still,
            .anim_4 = ANIM_ChainChomp_Still,
            .anim_5 = ANIM_ChainChomp_Still,
            .death  = ANIM_ChainChomp_Still,
            .hit    = ANIM_ChainChomp_Still,
            .anim_8 = ANIM_ChainChomp_Still,
            .anim_9 = ANIM_ChainChomp_Still,
            .anim_A = ANIM_ChainChomp_Still,
            .anim_B = ANIM_ChainChomp_Still,
            .anim_C = ANIM_ChainChomp_Still,
            .anim_D = ANIM_ChainChomp_Still,
            .anim_E = ANIM_ChainChomp_Still,
            .anim_F = ANIM_ChainChomp_Still,
        },
    },
    {
        .id = NPC_ChainChomp_05,
        .pos = { 23.0f, -4.0f, -180.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChainChomp_Still,
            .walk   = ANIM_ChainChomp_Still,
            .run    = ANIM_ChainChomp_Still,
            .chase  = ANIM_ChainChomp_Still,
            .anim_4 = ANIM_ChainChomp_Still,
            .anim_5 = ANIM_ChainChomp_Still,
            .death  = ANIM_ChainChomp_Still,
            .hit    = ANIM_ChainChomp_Still,
            .anim_8 = ANIM_ChainChomp_Still,
            .anim_9 = ANIM_ChainChomp_Still,
            .anim_A = ANIM_ChainChomp_Still,
            .anim_B = ANIM_ChainChomp_Still,
            .anim_C = ANIM_ChainChomp_Still,
            .anim_D = ANIM_ChainChomp_Still,
            .anim_E = ANIM_ChainChomp_Still,
            .anim_F = ANIM_ChainChomp_Still,
        },
    },
};

NpcData N(NpcData_Chapter3)[] = {
    {
        .id = NPC_Skolar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Skolar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
    {
        .id = NPC_Tubba,
        .pos = { 54.0f, -1.0f, 1.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Tubba),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldTubba_Anim06,
            .walk   = ANIM_WorldTubba_Anim09,
            .run    = ANIM_WorldTubba_Anim0C,
            .chase  = ANIM_WorldTubba_Anim0C,
            .anim_4 = ANIM_WorldTubba_Anim00,
            .anim_5 = ANIM_WorldTubba_Anim00,
            .death  = ANIM_WorldTubba_Anim00,
            .hit    = ANIM_WorldTubba_Anim00,
            .anim_8 = ANIM_WorldTubba_Anim00,
            .anim_9 = ANIM_WorldTubba_Anim00,
            .anim_A = ANIM_WorldTubba_Anim00,
            .anim_B = ANIM_WorldTubba_Anim00,
            .anim_C = ANIM_WorldTubba_Anim00,
            .anim_D = ANIM_WorldTubba_Anim00,
            .anim_E = ANIM_WorldTubba_Anim00,
            .anim_F = ANIM_WorldTubba_Anim00,
        },
    },
};

NpcData N(NpcData_Chapter4)[] = {
    {
        .id = NPC_Muskular,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Muskular),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_GeneralGuy,
        .pos = { 97.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GeneralGuy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GeneralGuy_Anim02,
            .walk   = ANIM_GeneralGuy_Anim02,
            .run    = ANIM_GeneralGuy_Anim02,
            .chase  = ANIM_GeneralGuy_Anim02,
            .anim_4 = ANIM_GeneralGuy_Anim02,
            .anim_5 = ANIM_GeneralGuy_Anim02,
            .death  = ANIM_GeneralGuy_Anim02,
            .hit    = ANIM_GeneralGuy_Anim02,
            .anim_8 = ANIM_GeneralGuy_Anim02,
            .anim_9 = ANIM_GeneralGuy_Anim02,
            .anim_A = ANIM_GeneralGuy_Anim02,
            .anim_B = ANIM_GeneralGuy_Anim02,
            .anim_C = ANIM_GeneralGuy_Anim02,
            .anim_D = ANIM_GeneralGuy_Anim02,
            .anim_E = ANIM_GeneralGuy_Anim02,
            .anim_F = ANIM_GeneralGuy_Anim02,
        },
    },
    {
        .id = NPC_ShyGuy_01,
        .pos = { 17.0f, 0.0f, -14.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { 47.0f, 0.0f, 25.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcData N(NpcData_Chapter5)[] = {
    {
        .id = NPC_Misstar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Misstar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
    {
        .id = NPC_LavaPiranhaHead,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaPiranhaHead),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = LAVA_PIRANHA_HEAD_ANIMS,
        .extraAnimations = N(D_80243848_902EB8),
    },
    {
        .id = NPC_LavaBud_01,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud_01),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(D_80243854_902EC4),
    },
    {
        .id = NPC_LavaBud_02,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud_01),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4,
        .drops = NO_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(D_80243854_902EC4),
    },
};

NpcData N(NpcData_Chapter6)[] = {
    {
        .id = NPC_Klevar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Klevar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
    {
        .id = NPC_HuffNPuff_Body,
        .pos = { 70.0f, 109.0f, 1.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Body),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HuffNPuff_Anim01,
            .walk   = ANIM_HuffNPuff_Anim01,
            .run    = ANIM_HuffNPuff_Anim01,
            .chase  = ANIM_HuffNPuff_Anim01,
            .anim_4 = ANIM_HuffNPuff_Anim01,
            .anim_5 = ANIM_HuffNPuff_Anim01,
            .death  = ANIM_HuffNPuff_Anim01,
            .hit    = ANIM_HuffNPuff_Anim01,
            .anim_8 = ANIM_HuffNPuff_Anim01,
            .anim_9 = ANIM_HuffNPuff_Anim01,
            .anim_A = ANIM_HuffNPuff_Anim01,
            .anim_B = ANIM_HuffNPuff_Anim01,
            .anim_C = ANIM_HuffNPuff_Anim01,
            .anim_D = ANIM_HuffNPuff_Anim01,
            .anim_E = ANIM_HuffNPuff_Anim01,
            .anim_F = ANIM_HuffNPuff_Anim01,
        },
    },
    {
        .id = NPC_HuffNPuff_Face,
        .pos = { 70.0f, 109.0f, 1.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Face),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HuffNPuff_Anim01,
            .walk   = ANIM_HuffNPuff_Anim01,
            .run    = ANIM_HuffNPuff_Anim01,
            .chase  = ANIM_HuffNPuff_Anim01,
            .anim_4 = ANIM_HuffNPuff_Anim01,
            .anim_5 = ANIM_HuffNPuff_Anim01,
            .death  = ANIM_HuffNPuff_Anim01,
            .hit    = ANIM_HuffNPuff_Anim01,
            .anim_8 = ANIM_HuffNPuff_Anim01,
            .anim_9 = ANIM_HuffNPuff_Anim01,
            .anim_A = ANIM_HuffNPuff_Anim01,
            .anim_B = ANIM_HuffNPuff_Anim01,
            .anim_C = ANIM_HuffNPuff_Anim01,
            .anim_D = ANIM_HuffNPuff_Anim01,
            .anim_E = ANIM_HuffNPuff_Anim01,
            .anim_F = ANIM_HuffNPuff_Anim01,
        },
    },
    {
        .id = NPC_HuffNPuff_Arms,
        .pos = { 70.0f, 109.0f, 1.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Arms),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HuffNPuff_Anim01,
            .walk   = ANIM_HuffNPuff_Anim01,
            .run    = ANIM_HuffNPuff_Anim01,
            .chase  = ANIM_HuffNPuff_Anim01,
            .anim_4 = ANIM_HuffNPuff_Anim01,
            .anim_5 = ANIM_HuffNPuff_Anim01,
            .death  = ANIM_HuffNPuff_Anim01,
            .hit    = ANIM_HuffNPuff_Anim01,
            .anim_8 = ANIM_HuffNPuff_Anim01,
            .anim_9 = ANIM_HuffNPuff_Anim01,
            .anim_A = ANIM_HuffNPuff_Anim01,
            .anim_B = ANIM_HuffNPuff_Anim01,
            .anim_C = ANIM_HuffNPuff_Anim01,
            .anim_D = ANIM_HuffNPuff_Anim01,
            .anim_E = ANIM_HuffNPuff_Anim01,
            .anim_F = ANIM_HuffNPuff_Anim01,
        },
    },
    {
        .id = NPC_RuffPuff_01,
        .pos = { 60.0f, 40.0f, -50.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff_01),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_RuffPuff_Still,
            .walk   = ANIM_RuffPuff_Still,
            .run    = ANIM_RuffPuff_Grin,
            .chase  = ANIM_RuffPuff_Grin,
            .anim_4 = ANIM_RuffPuff_Still,
            .anim_5 = ANIM_RuffPuff_Still,
            .death  = ANIM_RuffPuff_Hurt,
            .hit    = ANIM_RuffPuff_Hurt,
            .anim_8 = ANIM_RuffPuff_Grin,
            .anim_9 = ANIM_RuffPuff_Idle,
            .anim_A = ANIM_RuffPuff_Idle,
            .anim_B = ANIM_RuffPuff_Idle,
            .anim_C = ANIM_RuffPuff_Idle,
            .anim_D = ANIM_RuffPuff_Idle,
            .anim_E = ANIM_RuffPuff_Idle,
            .anim_F = ANIM_RuffPuff_Idle,
        },
    },
    {
        .id = NPC_RuffPuff_02,
        .pos = { 14.0f, 61.0f, 1.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_RuffPuff_Still,
            .walk   = ANIM_RuffPuff_Still,
            .run    = ANIM_RuffPuff_Grin,
            .chase  = ANIM_RuffPuff_Grin,
            .anim_4 = ANIM_RuffPuff_Still,
            .anim_5 = ANIM_RuffPuff_Still,
            .death  = ANIM_RuffPuff_Hurt,
            .hit    = ANIM_RuffPuff_Hurt,
            .anim_8 = ANIM_RuffPuff_Grin,
            .anim_9 = ANIM_RuffPuff_Idle,
            .anim_A = ANIM_RuffPuff_Idle,
            .anim_B = ANIM_RuffPuff_Idle,
            .anim_C = ANIM_RuffPuff_Idle,
            .anim_D = ANIM_RuffPuff_Idle,
            .anim_E = ANIM_RuffPuff_Idle,
            .anim_F = ANIM_RuffPuff_Idle,
        },
    },
};

NpcData N(NpcData_Chapter7)[] = {
    {
        .id = NPC_Kalmar,
#if VERSION_JP
        .pos = { -40.0f, 96.0f, 0.0f },
#else
        .pos = { -62.0f, 96.0f, 0.0f },
#endif
        .yaw = 270,
        .init = &N(EVS_NpcInit_Kalmar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
    {
        .id = NPC_CrystalKing,
        .pos = { 60.0f, -2.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_CrystalKing),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_CrystalKing_Anim09,
            .walk   = ANIM_CrystalKing_Anim09,
            .run    = ANIM_CrystalKing_Anim09,
            .chase  = ANIM_CrystalKing_Anim09,
            .anim_4 = ANIM_CrystalKing_Anim09,
            .anim_5 = ANIM_CrystalKing_Anim09,
            .death  = ANIM_CrystalKing_Anim09,
            .hit    = ANIM_CrystalKing_Anim09,
            .anim_8 = ANIM_CrystalKing_Anim09,
            .anim_9 = ANIM_CrystalKing_Anim09,
            .anim_A = ANIM_CrystalKing_Anim09,
            .anim_B = ANIM_CrystalKing_Anim09,
            .anim_C = ANIM_CrystalKing_Anim09,
            .anim_D = ANIM_CrystalKing_Anim09,
            .anim_E = ANIM_CrystalKing_Anim09,
            .anim_F = ANIM_CrystalKing_Anim09,
        },
    },
    {
        .id = NPC_IceCube,
        .pos = { 10.0f, 31.0f, -12.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_IceCube),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_CrystalKing_Anim09,
            .walk   = ANIM_CrystalKing_Anim09,
            .run    = ANIM_CrystalKing_Anim09,
            .chase  = ANIM_CrystalKing_Anim09,
            .anim_4 = ANIM_CrystalKing_Anim09,
            .anim_5 = ANIM_CrystalKing_Anim09,
            .death  = ANIM_CrystalKing_Anim09,
            .hit    = ANIM_CrystalKing_Anim09,
            .anim_8 = ANIM_CrystalKing_Anim09,
            .anim_9 = ANIM_CrystalKing_Anim09,
            .anim_A = ANIM_CrystalKing_Anim09,
            .anim_B = ANIM_CrystalKing_Anim09,
            .anim_C = ANIM_CrystalKing_Anim09,
            .anim_D = ANIM_CrystalKing_Anim09,
            .anim_E = ANIM_CrystalKing_Anim09,
            .anim_F = ANIM_CrystalKing_Anim09,
        },
    },
    {
        .id = NPC_IceSphere,
        .pos = { 40.0f, 68.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_IceSphere),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_CrystalKing_Anim09,
            .walk   = ANIM_CrystalKing_Anim09,
            .run    = ANIM_CrystalKing_Anim09,
            .chase  = ANIM_CrystalKing_Anim09,
            .anim_4 = ANIM_CrystalKing_Anim09,
            .anim_5 = ANIM_CrystalKing_Anim09,
            .death  = ANIM_CrystalKing_Anim09,
            .hit    = ANIM_CrystalKing_Anim09,
            .anim_8 = ANIM_CrystalKing_Anim09,
            .anim_9 = ANIM_CrystalKing_Anim09,
            .anim_A = ANIM_CrystalKing_Anim09,
            .anim_B = ANIM_CrystalKing_Anim09,
            .anim_C = ANIM_CrystalKing_Anim09,
            .anim_D = ANIM_CrystalKing_Anim09,
            .anim_E = ANIM_CrystalKing_Anim09,
            .anim_F = ANIM_CrystalKing_Anim09,
        },
    },
    {
        .id = NPC_IceSpike,
        .pos = { 96.0f, 53.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_IceSpike),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_CrystalKing_Anim09,
            .walk   = ANIM_CrystalKing_Anim09,
            .run    = ANIM_CrystalKing_Anim09,
            .chase  = ANIM_CrystalKing_Anim09,
            .anim_4 = ANIM_CrystalKing_Anim09,
            .anim_5 = ANIM_CrystalKing_Anim09,
            .death  = ANIM_CrystalKing_Anim09,
            .hit    = ANIM_CrystalKing_Anim09,
            .anim_8 = ANIM_CrystalKing_Anim09,
            .anim_9 = ANIM_CrystalKing_Anim09,
            .anim_A = ANIM_CrystalKing_Anim09,
            .anim_B = ANIM_CrystalKing_Anim09,
            .anim_C = ANIM_CrystalKing_Anim09,
            .anim_D = ANIM_CrystalKing_Anim09,
            .anim_E = ANIM_CrystalKing_Anim09,
            .anim_F = ANIM_CrystalKing_Anim09,
        },
    },
};

NpcData N(NpcData_Chapter8) = {
    .id = NPC_Bowser,
    .pos = { 58.0f, 0.0f, 20.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldBowser_Idle,
        .walk   = ANIM_WorldBowser_Idle,
        .run    = ANIM_WorldBowser_Idle,
        .chase  = ANIM_WorldBowser_Idle,
        .anim_4 = ANIM_WorldBowser_Idle,
        .anim_5 = ANIM_WorldBowser_Idle,
        .death  = ANIM_WorldBowser_Idle,
        .hit    = ANIM_WorldBowser_Idle,
        .anim_8 = ANIM_WorldBowser_Idle,
        .anim_9 = ANIM_WorldBowser_Idle,
        .anim_A = ANIM_WorldBowser_Idle,
        .anim_B = ANIM_WorldBowser_Idle,
        .anim_C = ANIM_WorldBowser_Idle,
        .anim_D = ANIM_WorldBowser_Idle,
        .anim_E = ANIM_WorldBowser_Idle,
        .anim_F = ANIM_WorldBowser_Idle,
    },
};

NpcGroupList N(NpcGroup_Chapter1) = {
    NPC_GROUP(N(NpcData_Chapter1)),
    {}
};

NpcGroupList N(NpcGroup_Chapter2) = {
    NPC_GROUP(N(NpcData_Chapter2)),
    {}
};

NpcGroupList N(NpcGroup_Chapter3) = {
    NPC_GROUP(N(NpcData_Chapter3)),
    {}
};

NpcGroupList N(NpcGroup_Chapter4) = {
    NPC_GROUP(N(NpcData_Chapter4)),
    {}
};

NpcGroupList N(NpcGroup_Chapter5) = {
    NPC_GROUP(N(NpcData_Chapter5)),
    {}
};

NpcGroupList N(NpcGroup_Chapter6) = {
    NPC_GROUP(N(NpcData_Chapter6)),
    {}
};

NpcGroupList N(NpcGroup_Chapter7) = {
    NPC_GROUP(N(NpcData_Chapter7)),
    {}
};

NpcGroupList N(NpcGroup_Chapter8) = {
    NPC_GROUP(N(NpcData_Chapter8)),
    {}
};
