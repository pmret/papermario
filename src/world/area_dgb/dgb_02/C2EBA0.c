#include "dgb_02.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"

enum {
    NPC_WORLD_CLUBBA0 = 10,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2 = 30,
    NPC_WORLD_CLUBBA3,
};

EntryList N(entryList) = {
    { -567.0f, 0.0f, 180.0f,  90.0f },
    {  567.0f, 0.0f, 180.0f, 270.0f },
    { -450.0f, 0.0f,  88.0f, 180.0f },
    {  450.0f, 0.0f,  88.0f, 180.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { 0x1900C2 },
};

EvtScript N(802414B0) = {
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

static s32 N(pad_1548)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitDoubleDoor_80241550) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 5)
    EVT_SET(LocalVar(2), 11)
    EVT_SET(LocalVar(3), 13)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_ADDR("dgb_03"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80241604) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LocalVar(0), 1)
    EVT_SET(LocalVar(1), 17)
    EVT_SET(LocalVar(2), 18)
    EVT_SET(LocalVar(3), 16)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_ADDR("dgb_01"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_802416B8) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LocalVar(0), 2)
    EVT_SET(LocalVar(1), 9)
    EVT_SET(LocalVar(2), 21)
    EVT_SET(LocalVar(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_ADDR("dgb_07"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_8024176C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LocalVar(0), 3)
    EVT_SET(LocalVar(1), 13)
    EVT_SET(LocalVar(2), 23)
    EVT_SET(LocalVar(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_ADDR("dgb_11"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80241820) = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LocalVar(2), 11)
            EVT_SET(LocalVar(3), 13)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LocalVar(2), 18)
            EVT_SET(LocalVar(3), 16)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(2)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LocalVar(2), 21)
            EVT_SET(LocalVar(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(3)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LocalVar(2), 23)
            EVT_SET(LocalVar(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
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
        EVT_CALL(MakeNpcs, 1, EVT_ADDR(N(npcGroupList_802425C8)))
    EVT_END_IF
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80241550), TRIGGER_WALL_PRESS_A, 5, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80241604), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_802416B8), TRIGGER_WALL_PRESS_A, 9, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_8024176C), TRIGGER_WALL_PRESS_A, 13, 1, 0)
    EVT_EXEC(N(802414B0))
    EVT_EXEC(N(enterSingleDoor_80241820))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1AA8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80241AB0) = {
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
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

s32 N(extraAnimationList_80241B6C)[] = {
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

s32 N(extraAnimationList_80241B94)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

MobileAISettings N(npcAISettings_80241B9C) = {
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

EvtScript N(npcAI_80241BCC) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_ADDR(N(npcAISettings_80241B9C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241C3C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80241BCC),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

MobileAISettings N(npcAISettings_80241C68) = {
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

EvtScript N(npcAI_80241C98) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_ADDR(N(npcAISettings_80241C68)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241D08) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_80241C98),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtScript N(npcAI_80241D34) = {
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

NpcSettings N(npcSettings_80241DDC) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80241D34),
    .onDefeat = &N(80241AB0),
    .level = 13,
    .actionFlags = 8,
};

StaticNpc N(npcGroup_80241E08)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80241C3C),
        .pos = { -200.0f, 0.0f, 180.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
	.territory = { .temp = { -200, 0, 180, 40, 0, -32767, 0, -200, 0, 175, 250, 90, 1, 1 }},
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
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
        .extraAnimations = N(extraAnimationList_80241B6C),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80241DDC),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .extraAnimations = N(extraAnimationList_80241B94),
    },
};

StaticNpc N(npcGroup_802421E8)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80241D08),
        .pos = { 375.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
	.territory = { .temp = { 375, 0, 100, 40, 0, -32767, 0, 320, 0, 175, 250, 90, 0, 1 }},
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
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80241DDC),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .extraAnimations = N(extraAnimationList_80241B94),
    },
};

NpcGroupList N(npcGroupList_802425C8) = {
    NPC_GROUP(N(npcGroup_80241E08), 0x0F02, 0x00),
    NPC_GROUP(N(npcGroup_802421E8), 0x0F01, 0x00),
    {},
};

#include "world/common/enemy/WanderMeleeAI.inc.c"
#include "world/common/enemy/ClubbaNappingAI.inc.c"
