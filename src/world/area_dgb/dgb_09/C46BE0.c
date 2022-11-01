#include "dgb_09.h"
#include "message_ids.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/Sentinel.h"
#include "sprite/npc/WorldClubba.h"

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2,
    NPC_WORLD_CLUBBA3,
    NPC_SENTINEL,
};

EntryList N(entryList) = {
    { -567.0f, 0.0f, 180.0f,  90.0f },
    {  567.0f, 0.0f, 180.0f, 270.0f },
    { -450.0f, 0.0f,  90.0f, 180.0f },
    {  300.0f, 0.0f,  90.0f, 180.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_09 },
};

EvtScript N(80243880) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3918)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitDoubleDoor_80243920) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 5)
    EVT_SET(LVar2, 10)
    EVT_SET(LVar3, 12)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), 4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802439D4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 17)
    EVT_SET(LVar2, 17)
    EVT_SET(LVar3, 15)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_80243A88) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, 9)
    EVT_SET(LVar2, 20)
    EVT_SET(LVar3, 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_12"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80243B3C) = EVT_EXIT_WALK(40,  3, "dgb_10",  0);

EvtScript N(80243B98) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243B3C), TRIGGER_FLOOR_ABOVE, 11, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_80243BC4) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 10)
            EVT_SET(LVar3, 12)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LVar2, 17)
            EVT_SET(LVar3, 15)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LVar2, 20)
            EVT_SET(LVar3, 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, EVT_PTR(N(80243B98)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(GB_StoryProgress, -15)
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_8024533C)))
    EVT_END_IF
    EVT_EXEC(N(80243F6C))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243920), TRIGGER_WALL_PRESS_A, 5, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802439D4), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_80243A88), TRIGGER_WALL_PRESS_A, 9, 1, 0)
    EVT_EXEC(N(80243880))
    EVT_EXEC(N(enterWalk_80243BC4))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3E4C) = {
    0x00000000,
};

Vec4f N(triggerCoord_80243E50) = { 300.0f, 0.0f, 88.0f, 0.0f };

EvtScript N(80243E60) = {
    EVT_WAIT(2)
    EVT_CALL(PlayEffect, 0x42, 1, 25, 3, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, 29, 0)
        EVT_CALL(EnableModel, 25, 1)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, 29, 1)
        EVT_CALL(EnableModel, 25, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 13, 0x7FFFFE00)
    EVT_SET(GF_DGB09_BombedWall, 1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80243F6C) = {
    EVT_IF_EQ(GF_DGB09_BombedWall, 0)
        EVT_BIND_TRIGGER(N(80243E60), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243E50)), 1, 0)
        EVT_CALL(EnableModel, 29, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, 25, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 13, 0x7FFFFE00)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3FF8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80244000) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, ENEMY_FLAGS_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_802440BC)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim0C,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim11,
    ANIM_WorldClubba_Anim12,
    ANIM_LIST_END,
};

s32 N(extraAnimationList_802440E4)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_LIST_END,
};

MobileAISettings N(npcAISettings_802440EC) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_8024411C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(npcAISettings_802440EC)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024418C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_8024411C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

MobileAISettings N(npcAISettings_802441B8) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .chaseOffsetDist = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802441E8) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_PTR(N(npcAISettings_802441B8)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244258) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802441E8),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtScript N(npcAI_80244284) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 32)
    EVT_CALL(SetSelfVar, 2, 50)
    EVT_CALL(SetSelfVar, 3, 32)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, 8389)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024432C) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80244284),
    .onDefeat = &N(80244000),
    .level = 13,
    .actionFlags = 8,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80244370) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000 | ENEMY_FLAGS_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_802443AC) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 1,
    .chaseRadius = 240.0f,
    .unk_AI_2C = 1,
};

extern const char N(dgb_00_name_hack)[];

EvtScript N(npcAI_802443DC) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_802443AC)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar4, LVar2)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim08)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
    EVT_WAIT(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244804) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80244890) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802448F4) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244370),
    .ai = &N(npcAI_802443DC),
    .level = 99,
};

StaticNpc N(npcGroup_80244920)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_8024418C),
        .pos = { -350.0f, 0.0f, 180.0f },
        .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
	.territory = { .temp = { -350, 0, 180, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 }},
        .animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_800000,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

EvtScript N(init_80244D00) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(SetNpcPos, NPC_SELF, 240, 0, 88)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80244D6C)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80244258),
        .pos = { 310.0f, 0.0f, 88.0f },
        .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .init = &N(init_80244D00),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
	.territory = { .temp = { 310, 0, 88, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 }},
        .animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_800000,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

StaticNpc N(npcGroup_8024514C) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_802448F4),
    .pos = { -20.0f, 100.0f, 180.0f },
    .flags = ENEMY_FLAGS_400,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { -20, 100, 180, 40, 0, -32767, 0, -20, 100, 180, 250, 0, 0, 1 }},
    .animations = {
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim02,
        ANIM_Sentinel_Anim03,
        ANIM_Sentinel_Anim03,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim05,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim08,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
        ANIM_Sentinel_Anim01,
    },
};

NpcGroupList N(npcGroupList_8024533C) = {
    NPC_GROUP(N(npcGroup_80244920), 0x0F03, 0x00),
    NPC_GROUP(N(npcGroup_80244D6C), 0x0F01, 0x00),
    NPC_GROUP(N(npcGroup_8024514C)),
    {},
};

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

#include "world/common/enemy/ai/ClubbaNappingAI.inc.c"

#define AI_SENTINEL_FIRST_NPC 0
#define AI_SENTINEL_LAST_NPC  0
#include "world/common/enemy/ai/SentinelAI.inc.c"

const char N(dgb_00_name_hack)[] = "dgb_00";
