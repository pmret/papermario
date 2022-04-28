#include "dgb_09.h"
#include "message_ids.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_clubba.h"

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

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_09_tattle },
};

EvtScript N(80243880) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
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
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 5)
    EVT_SET(EVT_VAR(2), 10)
    EVT_SET(EVT_VAR(3), 12)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), 4)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802439D4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 17)
    EVT_SET(EVT_VAR(2), 17)
    EVT_SET(EVT_VAR(3), 15)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 3)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_80243A88) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 2)
    EVT_SET(EVT_VAR(1), 9)
    EVT_SET(EVT_VAR(2), 20)
    EVT_SET(EVT_VAR(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_12"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80243B3C) = EXIT_WALK_SCRIPT(40,  3, "dgb_10",  0);

EvtScript N(80243B98) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243B3C), TRIGGER_FLOOR_ABOVE, 11, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_80243BC4) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 10)
            EVT_SET(EVT_VAR(3), 12)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(EVT_VAR(2), 17)
            EVT_SET(EVT_VAR(3), 15)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(EVT_VAR(2), 20)
            EVT_SET(EVT_VAR(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80243B98))
        EVT_CASE_EQ(3)
            EVT_SET(EVT_VAR(0), EVT_PTR(N(80243B98)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(EVT_SAVE_VAR(0), -15)
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
    EVT_WAIT_FRAMES(2)
    EVT_CALL(PlayEffect, 0x42, 1, 25, 3, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, 29, 0)
        EVT_CALL(EnableModel, 25, 1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(EnableModel, 29, 1)
        EVT_CALL(EnableModel, 25, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
    EVT_SET(EVT_SAVE_FLAG(1051), 1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80243F6C) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1051), 0)
        EVT_BIND_TRIGGER(N(80243E60), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243E50)), 1, 0)
        EVT_CALL(EnableModel, 29, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, 25, 0)
        EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3FF8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80244000) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_802440BC)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    NPC_ANIM_world_clubba_Palette_00_Anim_2,
    NPC_ANIM_world_clubba_Palette_00_Anim_3,
    NPC_ANIM_world_clubba_Palette_00_Anim_4,
    NPC_ANIM_world_clubba_Palette_00_Anim_C,
    NPC_ANIM_world_clubba_Palette_00_Anim_7,
    NPC_ANIM_world_clubba_Palette_00_Anim_8,
    NPC_ANIM_world_clubba_Palette_00_Anim_11,
    NPC_ANIM_world_clubba_Palette_00_Anim_12,
    ANIM_END,
};

s32 N(extraAnimationList_802440E4)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

NpcAISettings N(npcAISettings_802440EC) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .unk_10 = { .f = 65.0f },
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 90 },
    .unk_20 = 12,
    .chaseRadius = 110.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 3,
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

NpcAISettings N(npcAISettings_802441B8) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .unk_10 = { .f = 40.0f },
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 90 },
    .unk_20 = 15,
    .chaseRadius = 200.0f,
    .unk_28 = { .f = 160.0f },
    .unk_2C = 1,
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
    .unk_2A = 8,
};

f32 N(sixFloats)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80244370) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_802443AC) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .unk_1C = { .s = 180 },
    .unk_20 = 1,
    .chaseRadius = 240.0f,
    .unk_2C = 1,
};

extern const char N(dgb_00_name_hack)[];

EvtScript N(npcAI_802443DC) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_802443AC)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(4), EVT_VAR(2))
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244804) = {
    EVT_CALL(GetOwnerEncounterTrigger, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, EVT_VAR(0))
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80244890) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
        .movement = { -350, 0, 180, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 },
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

EvtScript N(init_80244D00) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 3)
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_80244D00),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
        .movement = { 310, 0, 88, 40, 0, -32767, 0, 0, 0, 50, 600, 250, 1, 1 },
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
        .extraAnimations = N(extraAnimationList_802440BC),
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_8024432C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_802440E4),
    },
};

StaticNpc N(npcGroup_8024514C) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_802448F4),
    .pos = { -20.0f, 100.0f, 180.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -20, 100, 180, 40, 0, -32767, 0, -20, 100, 180, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_8024533C) = {
    NPC_GROUP(N(npcGroup_80244920), BATTLE_ID(15, 3, 0, 1)),
    NPC_GROUP(N(npcGroup_80244D6C), BATTLE_ID(15, 1, 0, 1)),
    NPC_GROUP(N(npcGroup_8024514C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/enemy/WanderMeleeAI.inc.c"

#include "world/common/enemy/ClubbaNappingAI.inc.c"

#define AI_SENTINEL_FIRST_NPC 0
#define AI_SENTINEL_LAST_NPC  0
#include "world/common/enemy/SentinelAI.inc.c"

const char N(dgb_00_name_hack)[] = "dgb_00";
