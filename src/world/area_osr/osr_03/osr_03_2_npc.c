#include "osr_03.h"

#include "world/common/enemy/Kammy.inc.c"

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim09,
    ANIM_WorldKammy_Anim0A,
    ANIM_WorldKammy_Anim0B,
    ANIM_WorldKammy_Anim0C,
    ANIM_WorldKammy_Anim0D,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim11,
    ANIM_WorldKammy_Anim12,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim14,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    ANIM_WorldKammy_Anim1A,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .settings = &N(NpcSettings_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
