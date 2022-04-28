#include "flo_17.h"
#include "message_ids.h"
#include "sprite/npc/lakitu.h"
#include "sprite/npc/spiny.h"

enum {
    NPC_LAKITU0,
    NPC_LAKITU1,
    NPC_SPINY0 = 50,
    NPC_SPINY1,
    NPC_SPINY2,
    NPC_SPINY3,
};

EntryList N(entryList) = {
    { -730.0f, 0.0f, 0.0f,  90.0f },
    {  730.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_17_tattle },
};

EvtScript N(80243280) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802432F0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_8024359C) = EXIT_WALK_SCRIPT(60,  0, "flo_16",  1);

EvtScript N(exitWalk_802435F8) = EXIT_WALK_SCRIPT(60,  1, "flo_18",  0);

EvtScript N(80243654) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024359C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802435F8), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_8024369C)[] = {
    0x0000000F, 0xC4048000, 0x00000000, 0xC2DC0000, 0x00000011, 0xC4070000, 0x00000000, 0xC2480000,
    0x00000010, 0xC4048000, 0x00000000, 0x42A00000, 0x00000014, 0xC3870000, 0x00000000, 0xC2F00000,
    0x00000013, 0xC3870000, 0x00000000, 0xC2F00000, 0x00000012, 0xC3870000, 0x00000000, 0x420C0000,
    0x00000017, 0xC3020000, 0x00000000, 0xC2480000, 0x00000016, 0xC3020000, 0x00000000, 0xC2480000,
    0x00000015, 0xC30C0000, 0x00000000, 0x42960000, 0x0000001B, 0x42F00000, 0x00000000, 0xC2480000,
    0x0000001A, 0x42F00000, 0x00000000, 0xC2480000, 0x00000018, 0x43020000, 0x00000000, 0x42700000,
    0x00000019, 0x42F00000, 0x00000000, 0x42F00000, 0x0000001F, 0x438C0000, 0x00000000, 0xC2DC0000,
    0x0000001E, 0x438C0000, 0x00000000, 0xC2DC0000, 0x0000001D, 0x43870000, 0x00000000, 0xC2480000,
    0x0000001C, 0x438C0000, 0x00000000, 0x42480000, 0x00000021, 0x44034000, 0x00000000, 0xC28C0000,
    0x00000020, 0x44034000, 0x00000000, 0x42480000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80245228)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80244284))
    EVT_CALL(ModifyColliderFlags, 3, 15, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 16, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 20, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 23, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 25, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 27, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 28, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 31, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 32, 0x00000006)
    EVT_SET(EVT_VAR(0), -736)
    EVT_SET(EVT_VAR(1), -137)
    EVT_SET(EVT_VAR(2), -522)
    EVT_SET(EVT_VAR(3), -118)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_SET(EVT_VAR(0), -728)
    EVT_SET(EVT_VAR(1), 76)
    EVT_SET(EVT_VAR(2), -496)
    EVT_SET(EVT_VAR(3), 137)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_SET(EVT_VAR(0), -160)
    EVT_SET(EVT_VAR(1), -117)
    EVT_SET(EVT_VAR(2), -92)
    EVT_SET(EVT_VAR(3), -54)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_SET(EVT_VAR(0), 76)
    EVT_SET(EVT_VAR(1), -124)
    EVT_SET(EVT_VAR(2), 150)
    EVT_SET(EVT_VAR(3), -55)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_SET(EVT_VAR(0), 192)
    EVT_SET(EVT_VAR(1), 60)
    EVT_SET(EVT_VAR(2), 309)
    EVT_SET(EVT_VAR(3), 133)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_SET(EVT_VAR(0), 488)
    EVT_SET(EVT_VAR(1), 46)
    EVT_SET(EVT_VAR(2), 733)
    EVT_SET(EVT_VAR(3), 137)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802432F0))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_8024369C)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 30, 1)
    EVT_CALL(EnableTexPanning, 32, 1)
    EVT_CALL(EnableTexPanning, 33, 1)
    EVT_CALL(EnableTexPanning, 36, 1)
    EVT_CALL(EnableTexPanning, 37, 1)
    EVT_CALL(EnableTexPanning, 40, 1)
    EVT_CALL(EnableTexPanning, 42, 1)
    EVT_CALL(EnableTexPanning, 44, 1)
    EVT_CALL(EnableTexPanning, 45, 1)
    EVT_CALL(EnableTexPanning, 48, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 52, 1)
    EVT_CALL(EnableTexPanning, 54, 1)
    EVT_CALL(EnableTexPanning, 56, 1)
    EVT_CALL(EnableTexPanning, 57, 1)
    EVT_CALL(EnableTexPanning, 60, 1)
    EVT_CALL(EnableTexPanning, 61, 1)
    EVT_CALL(EnableTexPanning, 64, 1)
    EVT_CALL(EnableTexPanning, 31, 1)
    EVT_CALL(EnableTexPanning, 34, 1)
    EVT_CALL(EnableTexPanning, 35, 1)
    EVT_CALL(EnableTexPanning, 38, 1)
    EVT_CALL(EnableTexPanning, 39, 1)
    EVT_CALL(EnableTexPanning, 43, 1)
    EVT_CALL(EnableTexPanning, 46, 1)
    EVT_CALL(EnableTexPanning, 47, 1)
    EVT_CALL(EnableTexPanning, 50, 1)
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_CALL(EnableTexPanning, 55, 1)
    EVT_CALL(EnableTexPanning, 58, 1)
    EVT_CALL(EnableTexPanning, 59, 1)
    EVT_CALL(EnableTexPanning, 62, 1)
    EVT_CALL(EnableTexPanning, 63, 1)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_SET(EVT_VAR(1), 0)
        EVT_LABEL(0)
        EVT_ADD(EVT_VAR(0), 140)
        EVT_IF_GT(EVT_VAR(0), 65536)
            EVT_ADD(EVT_VAR(0), -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, EVT_VAR(0), 0)
        EVT_ADD(EVT_VAR(1), -200)
        EVT_IF_LT(EVT_VAR(1), 0)
            EVT_ADD(EVT_VAR(1), 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, EVT_VAR(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80243654)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80243280))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CD72E0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3FCC) = {
    0x00000000,
};

EvtScript N(80243FD0) = {
    EVT_LOOP(0)
        EVT_CALL(N(func_80240040_CD7320), EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), EVT_VAR(4))
            EVT_CALL(GetPlayerActionState, EVT_VAR(0))
            EVT_IF_NE(EVT_VAR(0), 23)
                EVT_IF_EQ(EVT_VAR(8), 0)
                    EVT_THREAD
                        EVT_CALL(GetModelCenter, EVT_VAR(5))
                        EVT_CALL(PlaySoundAt, 0x1DB, 4194304, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                    EVT_END_THREAD
                EVT_END_IF
                EVT_IF_LT(EVT_VAR(7), 90)
                    EVT_IF_EQ(EVT_VAR(7), 0)
                        EVT_WAIT_FRAMES(5)
                        EVT_SET(EVT_VAR(8), 6)
                        EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(9), 0x7FFFFE00)
                    EVT_END_IF
                    EVT_ADD(EVT_VAR(8), 1)
                    EVT_ADD(EVT_VAR(7), EVT_VAR(8))
                EVT_END_IF
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_NE(EVT_VAR(7), 0)
            EVT_SUB(EVT_VAR(8), 1)
            EVT_ADD(EVT_VAR(7), EVT_VAR(8))
            EVT_IF_LE(EVT_VAR(7), 0)
                EVT_SET(EVT_VAR(8), 0)
                EVT_SET(EVT_VAR(7), 0)
                EVT_THREAD
                    EVT_CALL(GetModelCenter, EVT_VAR(5))
                    EVT_CALL(PlaySoundAt, 0x1DC, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_END_THREAD
                EVT_CALL(ModifyColliderFlags, 1, EVT_VAR(9), 0x7FFFFE00)
            EVT_END_IF
        EVT_END_IF
        EVT_LABEL(50)
        EVT_IF_GE(EVT_VAR(7), 90)
            EVT_SET(EVT_VAR(8), -1)
            EVT_SET(EVT_VAR(7), 90)
        EVT_END_IF
        EVT_CALL(RotateModel, EVT_VAR(5), EVT_VAR(7), -1, 0, 0)
        EVT_CALL(RotateModel, EVT_VAR(6), EVT_VAR(7), -1, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80244284) = {
    EVT_SET(EVT_VAR(4), 35)
    EVT_SET(EVT_VAR(5), 14)
    EVT_SET(EVT_VAR(6), 15)
    EVT_SET(EVT_VAR(7), EVT_MAP_VAR(10))
    EVT_SET(EVT_VAR(8), EVT_MAP_VAR(11))
    EVT_SET(EVT_VAR(9), 38)
    EVT_EXEC(N(80243FD0))
    EVT_SET(EVT_VAR(4), 36)
    EVT_SET(EVT_VAR(5), 19)
    EVT_SET(EVT_VAR(6), 20)
    EVT_SET(EVT_VAR(7), EVT_MAP_VAR(12))
    EVT_SET(EVT_VAR(8), EVT_MAP_VAR(13))
    EVT_SET(EVT_VAR(9), 39)
    EVT_EXEC(N(80243FD0))
    EVT_SET(EVT_VAR(4), 37)
    EVT_SET(EVT_VAR(5), 24)
    EVT_SET(EVT_VAR(6), 25)
    EVT_SET(EVT_VAR(7), EVT_MAP_VAR(14))
    EVT_SET(EVT_VAR(8), EVT_MAP_VAR(15))
    EVT_SET(EVT_VAR(9), 40)
    EVT_EXEC(N(80243FD0))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_XXX)[] = { 0, 0};

NpcSettings N(npcSettings_802443D8) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

f32 N(sixFloats)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80244424) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .unk_AI_10 = { .f = 50.0f },
    .playerSearchInterval = 3,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = { .s = 60 },
    .unk_AI_20 = 10,
    .chaseRadius = 80.0f,
    .unkChase = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80244454) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 400)
    EVT_CALL(N(LakituAI_Main), EVT_PTR(N(npcAISettings_80244424)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802444C4) = {
    .height = 28,
    .radius = 24,
    .ai = &N(npcAI_80244454),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 20,
};

NpcAISettings N(npcAISettings_802444F0) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_AI_10 = { .f = 30.0f },
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unkChase = 30.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_80244520) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(SpinyAI_Main), EVT_PTR(N(npcAISettings_802444F0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80244590) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetSelfVar, 10, 100)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(2)
            EVT_CALL(func_80045900, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024465C) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_80244520),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(80244590),
    .level = 19,
};

StaticNpc N(npcGroup_80244688) = {
    .id = NPC_LAKITU0,
    .settings = &N(npcSettings_802444C4),
    .pos = { -185.0f, 90.0f, 10.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 25,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 2, 0 },
        { ITEM_MAPLE_SYRUP, 2, 0 },
        { ITEM_THUNDER_RAGE, 2, 0 },
        { ITEM_STOP_WATCH, 2, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(3),
    .maxCoinBonus = 2,
    .movement = { -185, 90, 10, 30, 0, -32767, 0, -185, 90, 0, 85, 120, 1, 1 },
    .animations = {
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_2,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244878) = {
    .id = NPC_LAKITU1,
    .settings = &N(npcSettings_802444C4),
    .pos = { 200.0f, 90.0f, -25.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 25,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 2, 0 },
        { ITEM_MAPLE_SYRUP, 2, 0 },
        { ITEM_THUNDER_RAGE, 2, 0 },
        { ITEM_STOP_WATCH, 2, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(3),
    .maxCoinBonus = 2,
    .movement = { 200, 90, -25, 30, 0, -32767, 0, 200, 90, 0, 85, 120, 1, 1 },
    .animations = {
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_2,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244A68) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244C58) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244E48) = {
    .id = NPC_SPINY2,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80245038) = {
    .id = NPC_SPINY3,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80245228) = {
    NPC_GROUP(N(npcGroup_80244688), BATTLE_ID(24, 9, 0, 3)),
    NPC_GROUP(N(npcGroup_80244878), BATTLE_ID(24, 10, 0, 3)),
    NPC_GROUP(N(npcGroup_80244A68), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80244C58), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80244E48), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80245038), BATTLE_ID(24, 12, 0, 3)),
    {},
};

static s32 N(pad_527C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA588, 660, 60, -115, 0, 130, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1390))
    EVT_CALL(MakeItemEntity, ITEM_LETTER09, -245, 0, 105, 17, EVT_SAVE_FLAG(1389))
    EVT_RETURN
    EVT_END
};

#define AI_LAKITU_FIRST_SPINY_ID    50
#define AI_LAKITU_LAST_SPINY_ID     53
#include "world/common/enemy/LakituAI.inc.c"
#include "world/common/enemy/SpinyAI.inc.c"
