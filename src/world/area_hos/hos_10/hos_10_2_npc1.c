#include "hos_10.h"

#define NAME_SUFFIX _Descent

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/Twink.h"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcInit_Peach) = {
    EVT_CALL(SetNpcPos, NPC_Peach, -100, 200, 1300)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(SetNpcPos, NPC_Twink, -130, 260, 1300)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(SetNpcPos, NPC_Eldstar, -121, 200, 1369)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(SetNpcPos, NPC_Mamar, -175, 200, 1342)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(SetNpcPos, NPC_Skolar, -188, 200, 1284)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(SetNpcPos, NPC_Muskular, -150, 200, 1237)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcPos, NPC_Misstar, -100, 200, 1237)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(SetNpcPos, NPC_Klevar, -52, 200, 1284)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(SetNpcPos, NPC_Kalmar, -65, 200, 1342)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Peach)[] = {
    ANIM_Peach_A0001,
    ANIM_Peach_A0002,
    ANIM_Peach_C0000,
    ANIM_Peach_C0006,
    ANIM_Peach_C001E,
    ANIM_Peach_C0026,
    -1
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    -1
};

s32 N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    -1
};

s32 N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_WorldMamar_TalkHappy,
    -1
};

s32 N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_WorldSkolar_TalkAngry,
    -1
};

s32 N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_WorldMuskular_Talk,
    -1
};

s32 N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    ANIM_WorldMisstar_Talk,
    -1
};

s32 N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_WorldKlevar_Talk,
    -1
};

s32 N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_WorldKalmar_Talk,
    -1
};

StaticNpc N(NpcData_Spirits)[] = {
    {
        .id = NPC_Peach,
        .settings = &N(NpcSettings_Dummy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
        .init = &N(EVS_NpcInit_Peach),
        .drops = NPC_NO_DROPS,
        .animations = {
            .idle   = ANIM_Peach_A0000,
            .walk   = ANIM_Peach_A0000,
            .run    = ANIM_Peach_A0000,
            .chase  = ANIM_Peach_A0000,
            .anim_4 = ANIM_Peach_A0000,
            .anim_5 = ANIM_Peach_A0000,
            .death  = ANIM_Peach_A0000,
            .hit    = ANIM_Peach_A0000,
            .anim_8 = ANIM_Peach_A0000,
            .anim_9 = ANIM_Peach_A0000,
            .anim_A = ANIM_Peach_A0000,
            .anim_B = ANIM_Peach_A0000,
            .anim_C = ANIM_Peach_A0000,
            .anim_D = ANIM_Peach_A0000,
            .anim_E = ANIM_Peach_A0000,
            .anim_F = ANIM_Peach_A0000,
        },
        .extraAnimations = N(ExtraAnims_Peach),
    },
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_Dummy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Twink),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_Eldstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Eldstar),
        .drops = NPC_NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Mamar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Mamar),
        .drops = NPC_NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Skolar),
        .drops = NPC_NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Muskular),
        .drops = NPC_NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Misstar),
        .drops = NPC_NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Klevar),
        .drops = NPC_NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Kalmar),
        .drops = NPC_NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
};

#define NAME_SUFFIX

NpcGroupList N(NpcGroup_Descent) = {
    NPC_GROUP(N(NpcData_Spirits_Descent)),
    {}
};
