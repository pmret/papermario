#include "kkj_14.h"

#define NAME_SUFFIX _Ch2

#include "world/common/npc/Bowser.inc.c"
#include "world/common/enemy/Kammy.inc.c"

s32 N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Still,
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Run,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_TalkEyesClosed,
    ANIM_WorldBowser_ArmsCrossed,
    ANIM_WorldBowser_Shock,
    -1
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim01,
    ANIM_WorldKammy_Anim02,
    ANIM_WorldKammy_Anim03,
    ANIM_WorldKammy_Anim04,
    -1
};

StaticNpc N(NpcData_Characters)[] = {
    {
        .id = NPC_Bowser,
        .settings = &N(NpcSettings_Bowser),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Kammy,
        .settings = &N(NpcSettings_Kammy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = KAMMY_ANIMS,
        .extraAnimations = N(ExtraAnims_Kammy),
    },
};

#define NAME_SUFFIX

NpcGroupList N(Chapter2NPCs) = {
    NPC_GROUP(N(NpcData_Characters_Ch2)),
    {}
};
