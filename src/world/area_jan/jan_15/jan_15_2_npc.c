#include "jan_15.h"

NpcSettings N(NpcSettings_PutridPiranha_01) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

s32 N(missing_802405EC_5EC)[] = {
    0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 
};

#include "world/common/enemy/complete/HeartPlant.inc.c"

EvtScript N(D_802407CC_B7E0EC) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(RandInt, 5, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
                EVT_WAIT(15)
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim05)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim06)
                EVT_WAIT(5)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(RandInt, 5, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
                EVT_WAIT(15)
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
                EVT_WAIT(5)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
            EVT_WAIT(15)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim05)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim06)
            EVT_WAIT(5)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_PutridPiranha_01) = {
    EVT_IF_EQ(GF_JAN15_EncounteredMiniboss, FALSE)
        EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 34)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00BB, 320, 60)
        EVT_SET(GF_JAN15_EncounteredMiniboss, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(D_802407CC_B7E0EC), LVar9)
    EVT_CALL(AwaitPlayerApproach, 400, -10, 135)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim04)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 24)
            EVT_CALL(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_03, SOUND_3B1, 0)
        EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, 24)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_20B1, 0)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, 24)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_20B1, 0)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_20B2, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_20B2, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_20B2, 0)
    EVT_LOOP(3)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_20B3, 0)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim05)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim05)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim06)
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_3B2, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_PutridPiranha_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GB_StoryProgress, STORY_CH5_DEFEATED_PIRANHAS_MINIBOSS)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PutridPiranha_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_PIRANHAS_MINIBOSS)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PutridPiranha_01)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_PutridPiranha_01)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PutridPiranha_01, 0, -1000, 0)
        EVT_CALL(SetNpcPos, NPC_PutridPiranha_02, 0, -1000, 0)
        EVT_CALL(SetNpcPos, NPC_PutridPiranha_03, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_PutridPiranha_01)[] = {
    {
        .id = NPC_PutridPiranha_01,
        .settings = &N(NpcSettings_PutridPiranha_01),
        .pos = { 365.0f, 0.0f, -45.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_PutridPiranha_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_FIRE_FLOWER, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .minCoinBonus = 0,
            .maxCoinBonus = 2,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
    {
        .id = NPC_PutridPiranha_02,
        .settings = &N(NpcSettings_PutridPiranha_01),
        .pos = { 325.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_FIRE_FLOWER, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .minCoinBonus = 0,
            .maxCoinBonus = 2,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
    {
        .id = NPC_PutridPiranha_03,
        .settings = &N(NpcSettings_PutridPiranha_01),
        .pos = { 375.0f, 0.0f, 45.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_FIRE_FLOWER, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(3),
            .minCoinBonus = 0,
            .maxCoinBonus = 2,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
};

StaticNpc N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .settings = &N(NpcSettings_HeartPlant),
    .pos = { -183.0f, 0.0f, 47.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_HeartPlant_Anim00,
        .walk   = ANIM_HeartPlant_Anim00,
        .run    = ANIM_HeartPlant_Anim00,
        .chase  = ANIM_HeartPlant_Anim00,
        .anim_4 = ANIM_HeartPlant_Anim00,
        .anim_5 = ANIM_HeartPlant_Anim00,
        .death  = ANIM_HeartPlant_Anim00,
        .hit    = ANIM_HeartPlant_Anim00,
        .anim_8 = ANIM_HeartPlant_Anim00,
        .anim_9 = ANIM_HeartPlant_Anim00,
        .anim_A = ANIM_HeartPlant_Anim00,
        .anim_B = ANIM_HeartPlant_Anim00,
        .anim_C = ANIM_HeartPlant_Anim00,
        .anim_D = ANIM_HeartPlant_Anim00,
        .anim_E = ANIM_HeartPlant_Anim00,
        .anim_F = ANIM_HeartPlant_Anim00,
    },
    .tattle = MSG_NpcTattle_HeartPlant,
};

StaticNpc N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .settings = &N(NpcSettings_HeartPlant),
    .pos = { -124.0f, 0.0f, 20.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_HeartPlant_Anim00,
        .walk   = ANIM_HeartPlant_Anim00,
        .run    = ANIM_HeartPlant_Anim00,
        .chase  = ANIM_HeartPlant_Anim00,
        .anim_4 = ANIM_HeartPlant_Anim00,
        .anim_5 = ANIM_HeartPlant_Anim00,
        .death  = ANIM_HeartPlant_Anim00,
        .hit    = ANIM_HeartPlant_Anim00,
        .anim_8 = ANIM_HeartPlant_Anim00,
        .anim_9 = ANIM_HeartPlant_Anim00,
        .anim_A = ANIM_HeartPlant_Anim00,
        .anim_B = ANIM_HeartPlant_Anim00,
        .anim_C = ANIM_HeartPlant_Anim00,
        .anim_D = ANIM_HeartPlant_Anim00,
        .anim_E = ANIM_HeartPlant_Anim00,
        .anim_F = ANIM_HeartPlant_Anim00,
    },
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PutridPiranha_01), BTL_JAN2_FORMATION_03, BTL_JAN2_STAGE_04),
    NPC_GROUP(N(NpcData_HeartPlant_01)),
    NPC_GROUP(N(NpcData_HeartPlant_02)),
    {}
};
