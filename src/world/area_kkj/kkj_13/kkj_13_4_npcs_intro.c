#include "kkj_13.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Intro

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/npc/Peach.inc.c"

EvtScript N(EVS_NpcIdle_BowserAwaitBattle) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)
    EVT_CALL(StartBossBattle, SONG_BOWSER_THEME)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bowser_Body) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_Body) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_BowserAwaitBattle)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bowser_Body)))
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Still,
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_BrandishIdle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Run,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_TalkEyesClosed,
    ANIM_WorldBowser_BrandishTalk,
    ANIM_WorldBowser_RearUpTalk,
    ANIM_WorldBowser_RearUpLaugh,
    ANIM_WorldBowser_Brandish,
    ANIM_WorldBowser_RearUpMock,
    ANIM_WorldBowser_PostJump,
    ANIM_WorldBowser_ClownCarStill,
    ANIM_WorldBowser_ClownCarIdle,
    ANIM_WorldBowser_ClownCarPropeller,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim01,
    ANIM_WorldKammy_Anim02,
    ANIM_WorldKammy_Anim04,
    ANIM_WorldKammy_Anim09,
    ANIM_WorldKammy_Anim0A,
    ANIM_WorldKammy_Anim0B,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_LIST_END
};

NpcData N(NpcData_Bowser) = {
    .id = NPC_Bowser_Body,
    .pos = { 0.0f, -500.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Body),
    .settings = &N(NpcSettings_Bowser),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Bowser_Prop,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOWSER_ANIMS,
        .extraAnimations = N(ExtraAnims_Bowser),
    },
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Kammy,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Kammy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KAMMY_ANIMS,
        .extraAnimations = N(ExtraAnims_Kammy),
    },
    {
        .id = NPC_Peach,
        .pos = { 670.0f, 0.0f, -12.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
    },
};

#define NAME_SUFFIX

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Bowser_Intro), BTL_KPA2_FORMATION_01),
    NPC_GROUP(N(NpcData_Characters_Intro)),
    {}
};
