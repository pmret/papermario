#include "hos_10.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Descent

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Twink.h"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcInit_Peach) = {
    Call(SetNpcPos, NPC_Peach, -100, 200, 1300)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    Call(SetNpcPos, NPC_Twink, -130, 260, 1300)
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(SetNpcPos, NPC_Eldstar, -121, 200, 1369)
    Return
    End
};

EvtScript N(EVS_NpcInit_Mamar) = {
    Call(SetNpcPos, NPC_Mamar, -175, 200, 1342)
    Return
    End
};

EvtScript N(EVS_NpcInit_Skolar) = {
    Call(SetNpcPos, NPC_Skolar, -188, 200, 1284)
    Return
    End
};

EvtScript N(EVS_NpcInit_Muskular) = {
    Call(SetNpcPos, NPC_Muskular, -150, 200, 1237)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcPos, NPC_Misstar, -100, 200, 1237)
    Return
    End
};

EvtScript N(EVS_NpcInit_Klevar) = {
    Call(SetNpcPos, NPC_Klevar, -52, 200, 1284)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    Call(SetNpcPos, NPC_Kalmar, -65, 200, 1342)
    Return
    End
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach1_Idle,
    ANIM_Peach1_Walk,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_GaspStill,
    ANIM_Peach2_TiedIdle,
    ANIM_Peach2_TalkIdle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_WorldMamar_TalkHappy,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_WorldSkolar_TalkAngry,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_WorldMuskular_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    ANIM_WorldMisstar_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_WorldKlevar_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_WorldKalmar_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Spirits)[] = {
    {
        .id = NPC_Peach,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Peach),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Peach1_Still,
            .walk   = ANIM_Peach1_Still,
            .run    = ANIM_Peach1_Still,
            .chase  = ANIM_Peach1_Still,
            .anim_4 = ANIM_Peach1_Still,
            .anim_5 = ANIM_Peach1_Still,
            .death  = ANIM_Peach1_Still,
            .hit    = ANIM_Peach1_Still,
            .anim_8 = ANIM_Peach1_Still,
            .anim_9 = ANIM_Peach1_Still,
            .anim_A = ANIM_Peach1_Still,
            .anim_B = ANIM_Peach1_Still,
            .anim_C = ANIM_Peach1_Still,
            .anim_D = ANIM_Peach1_Still,
            .anim_E = ANIM_Peach1_Still,
            .anim_F = ANIM_Peach1_Still,
        },
        .extraAnimations = N(ExtraAnims_Peach),
    },
    {
        .id = NPC_Twink,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Twink),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_Eldstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Mamar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mamar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Skolar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Muskular),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Misstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Klevar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kalmar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
};

#define NAME_SUFFIX

NpcGroupList N(NpcGroup_Descent) = {
    NPC_GROUP(N(NpcData_Spirits_Descent)),
    {}
};
