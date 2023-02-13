#include "hos_10.h"

#define NAME_SUFFIX _FlyAway

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/Twink.h"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(SetNpcPos, NPC_Twink, 0, 0, -400)
    EVT_CALL(SetNpcYaw, NPC_Twink, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(SetNpcPos, NPC_Eldstar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(SetNpcPos, NPC_Mamar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(SetNpcPos, NPC_Skolar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(SetNpcPos, NPC_Muskular, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcPos, NPC_Misstar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(SetNpcPos, NPC_Klevar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(SetNpcPos, NPC_Kalmar, 0, 0, -400)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Back,
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
        .id = NPC_Twink,
        .settings = &N(NpcSettings_Dummy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Twink),
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_Eldstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Eldstar),
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Mamar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Mamar),
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Skolar),
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Muskular),
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Misstar),
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Klevar),
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Kalmar),
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
};

#define NAME_SUFFIX

NpcGroupList N(NpcGroup_FlyAway) = {
    NPC_GROUP(N(NpcData_Spirits_FlyAway)),
    {}
};
