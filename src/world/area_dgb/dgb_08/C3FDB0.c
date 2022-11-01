#include "dgb_08.h"
#include "message_ids.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/Sentinel.h"
#include "sprite/npc/WorldClubba.h"
#include "sprite/npc/WorldTubba.h"

enum {
    NPC_WORLD_CLUBBA7,
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2,
    NPC_WORLD_CLUBBA3,
    NPC_WORLD_CLUBBA4,
    NPC_WORLD_CLUBBA5,
    NPC_SENTINEL0,
    NPC_SENTINEL1,
    NPC_WORLD_TUBBA,
    NPC_WORLD_CLUBBA6 = 11,
};

EntryList N(entryList) = {
    { -575.0f,   0.0f, 180.0f, 90.0f },
    { -575.0f, 210.0f, 180.0f, 90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_08 },
};

EvtScript N(80243CF0) = {
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

static s32 N(pad_3D88)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitDoubleDoor_80243D90) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 14)
    EVT_SET(LVar2, 23)
    EVT_SET(LVar3, 25)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80243E44) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 18)
    EVT_SET(LVar2, 18)
    EVT_SET(LVar3, 20)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

const s32 N(pad_XXXX)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(enterDoubleDoor_80243EF8) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 23)
            EVT_SET(LVar3, 25)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, 18)
            EVT_SET(LVar3, 20)
            EVT_EXEC_WAIT(EnterDoubleDoor)
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
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-28)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246958)))
        EVT_CASE_LT(-16)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802469AC)))
        EVT_CASE_LT(60)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802469C4)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802469E0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243D90), TRIGGER_WALL_PRESS_A, 14, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243E44), TRIGGER_WALL_PRESS_A, 18, 1, 0)
    EVT_EXEC(N(80243CF0))
    EVT_EXEC(N(enterDoubleDoor_80243EF8))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_40FC) = {
    0x00000000,
};

MobileAISettings N(npcAI_80244100) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .alertOffsetDist = 90.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.9f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 170.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(80244130) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAI_80244100)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244150) = {
    .height = 90,
    .radius = 65,
    .ai = &N(80244130),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_8024417C) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_802441A8) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtScript N(802441D4) = {
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

s32 N(extraAnimationList_80244290)[] = {
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

s32 N(extraAnimationList_802442B8)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_LIST_END,
};

MobileAISettings N(npcAISettings_802442C0) = {
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

EvtScript N(npcAI_802442F0) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(npcAISettings_802442C0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244360) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802442F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtScript N(npcAI_8024438C) = {
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

NpcSettings N(npcSettings_80244434) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_8024438C),
    .onDefeat = &N(802441D4),
    .level = 13,
    .actionFlags = 8,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80244478) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000 | ENEMY_FLAGS_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_802444B4) = {
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

EvtScript N(npcAI_802444E4) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_802444B4)))
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

EvtScript N(8024490C) = {
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

EvtScript N(80244998) = {
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

NpcSettings N(npcSettings_802449FC) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244478),
    .ai = &N(npcAI_802444E4),
    .level = 99,
};

NpcSettings N(npcSettings_80244A28) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtScript N(idle_80244A54) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, -350)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GB_ARN_Tubba_MapID, 8)
    EVT_SET(GB_StoryProgress, -27)
    EVT_CALL(PlaySoundAtCollider, 18, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 18, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, 20, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 9, ANIM_WorldTubba_Anim0A)
    EVT_CALL(SetNpcPos, NPC_SELF, -665, 210, 180)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(NpcMoveTo, NPC_SELF, -530, 180, 30)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 18, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, 20, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 18, 456, 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, -500, 80, 10)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80244D08) = {
    EVT_LABEL(10)
    EVT_CALL(GetNpcPos, 9, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(N(func_80243B98_C43948))
    EVT_RETURN
    EVT_END
};

EvtScript N(npcAI_80244D7C) = {
    EVT_CALL(N(func_80243C10_C439C0))
    EVT_EXEC(N(80244D08))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAI_80244100)))
    EVT_RETURN
    EVT_END
};

extern const char N(dgb_01_name_hack)[];

EvtScript N(defeat_80244E58) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_01_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244E94) = {
    EVT_IF_LT(GB_StoryProgress, -28)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, -26)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244E58)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_NE(GB_ARN_Tubba_MapID, 8)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 0, 200)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_NE(GB_ARN_Tubba_MapID, 8)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244A54)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 210, 80)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80244D7C)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802450A0) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_8024417C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = ENEMY_FLAGS_4 | NPC_FLAG_40000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_800000,
    .init = &N(init_80244E94),
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
	.territory = { .temp = { 10, -400, 210, 80, -100, 210, 80, 100, 210, 80, 400, 210, 80, 820, 100, 80, 820, 100, 260, 400, 0, 260, 100, 0, 200, -100, 0, 175, -450, 0, 175, -32767, 150, 0, 175, 1450, 200, 1 }},
    .animations = {
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim0A,
        ANIM_WorldTubba_Anim0D,
        ANIM_WorldTubba_Anim0D,
        ANIM_WorldTubba_Anim19,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
        ANIM_WorldTubba_Anim07,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_80245290)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80244360),
        .pos = { -250.0f, 0.0f, 135.0f },
        .flags = ENEMY_FLAGS_400,
        .yaw = 90,
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
	.territory = { .temp = { -250, 0, 135, 30, 0, -32767, 0, -250, 0, 135, 250, 0, 0, 1 }},
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
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245670)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80244360),
        .pos = { 220.0f, 0.0f, 155.0f },
        .flags = ENEMY_FLAGS_400,
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
	.territory = { .temp = { 220, 0, 155, 30, 0, -32767, 0, 220, 0, 155, 250, 0, 0, 1 }},
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
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245A50)[] = {
    {
        .id = NPC_WORLD_CLUBBA4,
        .settings = &N(npcSettings_80244360),
        .pos = { 825.0f, 100.0f, 200.0f },
        .flags = ENEMY_FLAGS_400,
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
	.territory = { .temp = { 825, 100, 200, 25, 0, -32767, 0, 825, 100, 200, 150, 0, 0, 1 }},
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
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
        .extraAnimations = N(extraAnimationList_80244290),
    },
    {
        .id = NPC_WORLD_CLUBBA5,
        .settings = &N(npcSettings_80244434),
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
        .extraAnimations = N(extraAnimationList_802442B8),
    },
};

StaticNpc N(npcGroup_80245E30) = {
    .id = NPC_SENTINEL0,
    .settings = &N(npcSettings_802449FC),
    .pos = { 75.0f, 310.0f, 85.0f },
    .flags = ENEMY_FLAGS_400,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 75, 310, 85, 30, 0, -32767, 0, 75, 0, 85, 250, 55, 1, 1 }},
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

StaticNpc N(npcGroup_80246020) = {
    .id = NPC_SENTINEL1,
    .settings = &N(npcSettings_802449FC),
    .pos = { -451.0f, 310.0f, 81.0f },
    .flags = ENEMY_FLAGS_400,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { -451, 310, 81, 30, 0, -32767, 0, -310, 0, 175, 250, 145, 1, 1 }},
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

EvtScript N(idle_80246210) = {
    EVT_LABEL(0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_WAIT(30)
    EVT_LOOP(15)
        EVT_CALL(N(func_80243C50_C43A00))
        EVT_WAIT(60)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_WAIT(30)
    EVT_LOOP(5)
        EVT_CALL(N(func_80243C50_C43A00))
        EVT_WAIT(60)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
    EVT_WAIT(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80246310) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim08)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2F1, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim02)
    EVT_WAIT(20)
    EVT_CALL(GetNpcYaw, -1, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcYaw, -1, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(25)
    EVT_CALL(GetNpcYaw, -1, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Anim05, ANIM_WorldClubba_Anim02, 0, MSG_CH3_00F2)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim06)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802464C4) = {
    EVT_CALL(SetNpcCollisionSize, -1, 36, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80246310)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80246210)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246528) = {
    .id = NPC_WORLD_CLUBBA6,
    .settings = &N(npcSettings_80244A28),
    .pos = { 426.0f, 0.0f, 38.0f },
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_400000,
    .init = &N(init_802464C4),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
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
    .tattle = MSG_NpcTattle_LastClubba,
};

EvtScript N(idle_80246718) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246728) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80246718)))
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246768) = {
    .id = NPC_WORLD_CLUBBA7,
    .settings = &N(npcSettings_80244360),
    .pos = { -250.0f, 0.0f, 135.0f },
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_400,
    .init = &N(init_80246728),
    .yaw = 90,
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
	.territory = { .temp = { -250, 0, 135, 30, 0, -32767, 0, -250, 0, 135, 250, 0, 0, 1 }},
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
    .extraAnimations = N(extraAnimationList_80244290),
};

NpcGroupList N(npcGroupList_80246958) = {
    NPC_GROUP(N(npcGroup_80246768), 0x0F02, 0x02),
    NPC_GROUP(N(npcGroup_80245290), 0x0F02, 0x02),
    NPC_GROUP(N(npcGroup_80245670), 0x0F02, 0x02),
    NPC_GROUP(N(npcGroup_80245A50), 0x0F03, 0x02),
    NPC_GROUP(N(npcGroup_80245E30)),
    NPC_GROUP(N(npcGroup_80246020)),
    {},
};

NpcGroupList N(npcGroupList_802469AC) = {
    NPC_GROUP(N(npcGroup_802450A0), 0x0F04, 0x00),
    {},
};

NpcGroupList N(npcGroupList_802469C4) = {
    NPC_GROUP(N(npcGroup_80246528)),
    {},
};

static s32 N(pad_69DC) = {
    0x00000000,
};

EvtScript N(802469E0) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

#define AI_SENTINEL_FIRST_NPC 7
#define AI_SENTINEL_LAST_NPC  9
#include "world/common/enemy/ai/SentinelAI.inc.c"

#include "world/common/todo/UnkFunc1.inc.c"

ApiStatus N(func_80243B98_C43948)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9) != 0) {
        Enemy* enemy = get_enemy(9);
        enemy->territory->wander.centerPos.x = 2;
        enemy->territory->wander.centerPos.y = -450;
        enemy->territory->wander.centerPos.z = 0;
        enemy->territory->wander.wanderSize.x = 175;
        enemy->territory->wander.wanderSize.z = 300;
        enemy->territory->wander.moveSpeedOverride = 0;
        enemy->territory->wander.wanderShape = 175;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C10_C439C0)(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(9)) {
        Enemy* enemy = get_enemy(9);
        enemy->aiFlags |= ENEMY_AI_FLAGS_80;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243C50_C43A00)(Evt* script, s32 isInitialCall) {
    ai_enemy_play_sound(get_npc_unsafe(script->owner1.enemy->npcID), SOUND_32F, 0);
    return ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[] = "dgb_00";
const char N(dgb_01_name_hack)[] = "dgb_01";
