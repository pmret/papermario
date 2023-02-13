#include "kkj_14.h"

#define NAME_SUFFIX _Ch7

#include "world/common/npc/Bowser.inc.c"
#include "world/common/enemy/Kammy.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"

s32 N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Still,
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Run,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_TalkEyesClosed,
    ANIM_WorldBowser_AngryTalk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_Swipe,
    -1
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim00,
    ANIM_WorldKammy_Anim01,
    ANIM_WorldKammy_Anim02,
    ANIM_WorldKammy_Anim03,
    ANIM_WorldKammy_Anim04,
    -1
};

s32 N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_WorldKoopatrol_Anim18,
    -1
};

StaticNpc N(NpcData_Characters)[] = {
    {
        .id = NPC_Ch7_Bowser,
        .settings = &N(NpcSettings_Bowser),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Ch7_Koopatrol_01,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Ch7_Koopatrol_02,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Ch7_Kammy,
        .settings = &N(NpcSettings_Kammy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400,
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

NpcGroupList N(Chapter7NPCs) = {
    NPC_GROUP(N(NpcData_Characters_Ch7)),
    {}
};
