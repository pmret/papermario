#include "kkj_29.h"

#include "world/common/npc/Bowser.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/enemy/HammerBros.inc.c"

EvtScript N(EVS_NpcInit_HammerBros) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -25)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 175, 0, -25)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim03)
    EVT_CALL(SetNpcPos, NPC_SELF, -140, 30, -140)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Still,
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_TalkEyesClosed,
    ANIM_WorldBowser_AngryTalk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpMock,
    -1
};

s32 N(ExtraAnims_HammerBros)[] = {
    ANIM_HammerBros_Anim01,
    ANIM_HammerBros_Anim03,
    ANIM_HammerBros_Anim06,
    ANIM_HammerBros_Anim08,
    ANIM_HammerBros_Anim09,
    ANIM_HammerBros_Anim0B,
    ANIM_HammerBros_Anim13,
    -1
};

s32 N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim03,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim17,
    ANIM_WorldKoopatrol_Anim19,
    ANIM_WorldKoopatrol_Anim1A,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    -1
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Bowser,
        .settings = &N(NpcSettings_Bowser),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = NO_DROPS,
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Koopatrol_01,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400,
        .init = &N(EVS_NpcInit_Koopatrol_02),
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_HammerBros,
        .settings = &N(NpcSettings_HammerBros),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400,
        .init = &N(EVS_NpcInit_HammerBros),
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    {}
};
