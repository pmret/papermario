#include "osr_03.h"

#include "world/common/enemy/Kammy.inc.c"

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_FlyStill,
    ANIM_WorldKammy_FlyIdle,
    ANIM_WorldKammy_FlySlow,
    ANIM_WorldKammy_FlyFast,
    ANIM_WorldKammy_FlyTalk,
    ANIM_WorldKammy_FlyRodTalk,
    ANIM_WorldKammy_FlyRodCast,
    ANIM_WorldKammy_FlyBrake,
    ANIM_WorldKammy_FlyChuckle,
    ANIM_WorldKammy_FlyLaugh,
    ANIM_WorldKammy_FlyIdleSly,
    ANIM_WorldKammy_FlySlowSly,
    ANIM_WorldKammy_FlyFastSly,
    ANIM_WorldKammy_FlyTalkSly,
    ANIM_WorldKammy_FlyBack,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .settings = &N(NpcSettings_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
