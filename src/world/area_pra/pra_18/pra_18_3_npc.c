#include "pra_18.h"
#include "effects.h"

#include "world/common/enemy/FrostClubba.h"

NpcSettings N(NpcSettings_Clubba) = {
    .height = 70,
    .radius = 60,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcInteract_Clubba_01) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Clubba_02) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Clubba_03) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_01) = {
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_02) = {
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_03) = {
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_01_Aux) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_02_Aux) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Clubba_03_Aux) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Clubba_01) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_NE(LVar0, 2)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0150)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Clubba_02) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_NE(LVar0, 2)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0151)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Clubba_03) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0152)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayClubbaDefeatFX) = {
    EVT_WAIT(20)
    EVT_LOOP(4)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
        EVT_SET(LVar2, LVarC)
        EVT_CALL(RandInt, 50, LVar3)
        EVT_CALL(RandInt, 50, LVar4)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.8), 0)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_BULLET_BILL_EXPLODE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
        EVT_SET(LVar2, LVarC)
        EVT_CALL(RandInt, 50, LVar3)
        EVT_CALL(RandInt, 50, LVar4)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.8), 0)
        EVT_CALL(PlaySoundAt, SOUND_SEQ_BULLET_BILL_EXPLODE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Clubba_01) = {
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g297, MODEL_GROUP_VISIBLE)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(GB_PRA18_ClubbasDefeated, 1)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(LVarA, 270)
        EVT_SET(LVarB, 20)
        EVT_SET(LVarC, -75)
        EVT_EXEC(N(EVS_PlayClubbaDefeatFX))
    EVT_END_THREAD
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Clubba_02) = {
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g296, MODEL_GROUP_VISIBLE)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(GB_PRA18_ClubbasDefeated, 2)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(LVarA, 480)
        EVT_SET(LVarB, 20)
        EVT_SET(LVarC, -75)
        EVT_EXEC(N(EVS_PlayClubbaDefeatFX))
    EVT_END_THREAD
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Clubba_03) = {
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g298, MODEL_GROUP_VISIBLE)
            EVT_WAIT(2)
            EVT_CALL(SetGroupVisibility, MODEL_g298, MODEL_GROUP_HIDDEN)
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1174, COLLIDER_FLAGS_UPPER_MASK)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_33_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
        EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(LVarA, 725)
        EVT_SET(LVarB, 20)
        EVT_SET(LVarC, -75)
        EVT_EXEC(N(EVS_PlayClubbaDefeatFX))
    EVT_END_THREAD
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_01) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_PRA18_ClubbasDefeated, 1)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Clubba_01)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Clubba_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Clubba_01)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_01)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_02) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_PRA18_ClubbasDefeated, 2)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Clubba_02)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Clubba_02)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Clubba_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_03) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Clubba_03)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Clubba_03)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Clubba_03)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_03)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_01_Aux) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_PRA18_ClubbasDefeated, 1)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_01_Aux)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_02_Aux) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_PRA18_ClubbasDefeated, 2)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_02_Aux)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_03_Aux) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_10000000, TRUE)
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Clubba_03_Aux)))
    EVT_RETURN
    EVT_END
};

#if VERSION_PAL
#define CLUBBA_EXTRA_FLAGS (ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_TOUCH)
#else
#define CLUBBA_EXTRA_FLAGS (0)
#endif

NpcData N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { 268.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_01),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_01_Aux,
        .pos = { 268.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_01_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcData N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .pos = { 490.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_02),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_02_Aux,
        .pos = { 490.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_02_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcData N(NpcData_Clubba_03)[] = {
    {
        .id = NPC_Clubba_03,
        .pos = { 717.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_03),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_03_Aux,
        .pos = { 717.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_03_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000 | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_PRA_FORMATION_0B, BTL_PRA_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_PRA_FORMATION_09, BTL_PRA_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_03), BTL_PRA_FORMATION_0C, BTL_PRA_STAGE_03),
    {}
};
