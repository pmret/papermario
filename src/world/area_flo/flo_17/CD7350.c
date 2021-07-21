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

Script N(80243280) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

Script N(802432F0) = SCRIPT({
    group 11;
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    SI_VAR(12) = SI_VAR(2);
    SI_VAR(13) = SI_VAR(3);
    SI_VAR(14) = SI_VAR(4);
    SI_VAR(12) -= SI_VAR(0);
    SI_VAR(13) -= SI_VAR(1);
    SI_VAR(0) = (float) SI_VAR(12);
    SI_VAR(0) /= 100.0;
    SI_VAR(15) = 100.0;
    SI_VAR(15) /= (float) SI_VAR(0);
    SI_VAR(15) += 11;
    SI_VAR(5) = 200;
    SI_VAR(5) /= SI_VAR(15);
    SI_VAR(5) += 1;
    loop SI_VAR(5) {
        RandInt(SI_VAR(12), SI_VAR(0));
        RandInt(SI_VAR(13), SI_VAR(1));
        RandInt(199, SI_VAR(2));
        SI_VAR(3) = 210;
        SI_VAR(3) -= SI_VAR(2);
        SI_VAR(0) += SI_VAR(10);
        SI_VAR(1) += SI_VAR(11);
        SI_VAR(2) += SI_VAR(14);
        PlayEffect(0xD, SI_VAR(0), SI_VAR(2), SI_VAR(1), SI_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep SI_VAR(15);
0:
    RandInt(SI_VAR(12), SI_VAR(0));
    RandInt(SI_VAR(13), SI_VAR(1));
    SI_VAR(0) += SI_VAR(10);
    SI_VAR(1) += SI_VAR(11);
    PlayEffect(0xD, SI_VAR(0), SI_VAR(14), SI_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep SI_VAR(15);
    goto 0;
});

Script N(exitWalk_8024359C) = EXIT_WALK_SCRIPT(60,  0, "flo_16",  1);

Script N(exitWalk_802435F8) = EXIT_WALK_SCRIPT(60,  1, "flo_18",  0);

Script N(80243654) = SCRIPT({
    bind N(exitWalk_8024359C) TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_802435F8) TRIGGER_FLOOR_ABOVE 4;
});

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

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80245228));
    await N(makeEntities);
    spawn N(80244284);
    ModifyColliderFlags(3, 15, 0x00000006);
    ModifyColliderFlags(3, 16, 0x00000006);
    ModifyColliderFlags(3, 20, 0x00000006);
    ModifyColliderFlags(3, 23, 0x00000006);
    ModifyColliderFlags(3, 25, 0x00000006);
    ModifyColliderFlags(3, 27, 0x00000006);
    ModifyColliderFlags(3, 28, 0x00000006);
    ModifyColliderFlags(3, 31, 0x00000006);
    ModifyColliderFlags(3, 32, 0x00000006);
    SI_VAR(0) = -736;
    SI_VAR(1) = -137;
    SI_VAR(2) = -522;
    SI_VAR(3) = -118;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    SI_VAR(0) = -728;
    SI_VAR(1) = 76;
    SI_VAR(2) = -496;
    SI_VAR(3) = 137;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    SI_VAR(0) = -160;
    SI_VAR(1) = -117;
    SI_VAR(2) = -92;
    SI_VAR(3) = -54;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    SI_VAR(0) = 76;
    SI_VAR(1) = -124;
    SI_VAR(2) = 150;
    SI_VAR(3) = -55;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    SI_VAR(0) = 192;
    SI_VAR(1) = 60;
    SI_VAR(2) = 309;
    SI_VAR(3) = 133;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    SI_VAR(0) = 488;
    SI_VAR(1) = 46;
    SI_VAR(2) = 733;
    SI_VAR(3) = 137;
    SI_VAR(4) = 0;
    spawn N(802432F0);
    ModifyColliderFlags(3, 9, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_8024369C));
    }
    EnableTexPanning(30, 1);
    EnableTexPanning(32, 1);
    EnableTexPanning(33, 1);
    EnableTexPanning(36, 1);
    EnableTexPanning(37, 1);
    EnableTexPanning(40, 1);
    EnableTexPanning(42, 1);
    EnableTexPanning(44, 1);
    EnableTexPanning(45, 1);
    EnableTexPanning(48, 1);
    EnableTexPanning(49, 1);
    EnableTexPanning(52, 1);
    EnableTexPanning(54, 1);
    EnableTexPanning(56, 1);
    EnableTexPanning(57, 1);
    EnableTexPanning(60, 1);
    EnableTexPanning(61, 1);
    EnableTexPanning(64, 1);
    EnableTexPanning(31, 1);
    EnableTexPanning(34, 1);
    EnableTexPanning(35, 1);
    EnableTexPanning(38, 1);
    EnableTexPanning(39, 1);
    EnableTexPanning(43, 1);
    EnableTexPanning(46, 1);
    EnableTexPanning(47, 1);
    EnableTexPanning(50, 1);
    EnableTexPanning(51, 1);
    EnableTexPanning(55, 1);
    EnableTexPanning(58, 1);
    EnableTexPanning(59, 1);
    EnableTexPanning(62, 1);
    EnableTexPanning(63, 1);
    spawn {
        SI_VAR(0) = 0;
        SI_VAR(1) = 0;
0:
        SI_VAR(0) += 140;
        if (SI_VAR(0) > 65536) {
            SI_VAR(0) += -65536;
        }
        SetTexPanOffset(1, 0, SI_VAR(0), 0);
        SI_VAR(1) += -200;
        if (SI_VAR(1) < 0) {
            SI_VAR(1) += 65536;
        }
        SetTexPanOffset(2, 0, SI_VAR(1), 0);
        sleep 1;
        goto 0;
    }
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80243654);
    spawn EnterWalk;
    await N(80243280);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CD72E0)();
    }
});

static s32 N(pad_3FCC) = {
    0x00000000,
};

Script N(80243FD0) = SCRIPT({
    loop {
        N(func_80240040_CD7320)(SI_VAR(0));
        if (SI_VAR(0) == SI_VAR(4)) {
            GetPlayerActionState(SI_VAR(0));
            if (SI_VAR(0) != 23) {
                if (SI_VAR(8) == 0) {
                    spawn {
                        GetModelCenter(SI_VAR(5));
                        PlaySoundAt(0x1DB, 4194304, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    }
                }
                if (SI_VAR(7) < 90) {
                    if (SI_VAR(7) == 0) {
                        sleep 5;
                        SI_VAR(8) = 6;
                        ModifyColliderFlags(0, SI_VAR(9), 0x7FFFFE00);
                    }
                    SI_VAR(8) += 1;
                    SI_VAR(7) += SI_VAR(8);
                }
                goto 50;
            }
        }
        if (SI_VAR(7) != 0) {
            SI_VAR(8) -= 1;
            SI_VAR(7) += SI_VAR(8);
            if (SI_VAR(7) <= 0) {
                SI_VAR(8) = 0;
                SI_VAR(7) = 0;
                spawn {
                    GetModelCenter(SI_VAR(5));
                    PlaySoundAt(0x1DC, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                }
                ModifyColliderFlags(1, SI_VAR(9), 0x7FFFFE00);
            }
        }
50:
        if (SI_VAR(7) >= 90) {
            SI_VAR(8) = -1;
            SI_VAR(7) = 90;
        }
        RotateModel(SI_VAR(5), SI_VAR(7), -1, 0, 0);
        RotateModel(SI_VAR(6), SI_VAR(7), -1, 0, 0);
        sleep 1;
    }
});

Script N(80244284) = SCRIPT({
    SI_VAR(4) = 35;
    SI_VAR(5) = 14;
    SI_VAR(6) = 15;
    SI_VAR(7) = SI_MAP_VAR(10);
    SI_VAR(8) = SI_MAP_VAR(11);
    SI_VAR(9) = 38;
    spawn N(80243FD0);
    SI_VAR(4) = 36;
    SI_VAR(5) = 19;
    SI_VAR(6) = 20;
    SI_VAR(7) = SI_MAP_VAR(12);
    SI_VAR(8) = SI_MAP_VAR(13);
    SI_VAR(9) = 39;
    spawn N(80243FD0);
    SI_VAR(4) = 37;
    SI_VAR(5) = 24;
    SI_VAR(6) = 25;
    SI_VAR(7) = SI_MAP_VAR(14);
    SI_VAR(8) = SI_MAP_VAR(15);
    SI_VAR(9) = 40;
    spawn N(80243FD0);
});

static s32 N(pad_XXX)[] = { 0, 0};

NpcSettings N(npcSettings_802443D8) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

f32 N(D_8024440C_CDB6EC)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80244424) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 60 },
    .unk_20 = 10,
    .chaseRadius = 80.0f,
    .unk_28 = { .f = 70.0f },
    .unk_2C = 1,
};

Script N(npcAI_80244454) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 400);
    N(func_80241C64_CD8F44)(N(npcAISettings_80244424));
});

NpcSettings N(npcSettings_802444C4) = {
    .height = 28,
    .radius = 24,
    .ai = &N(npcAI_80244454),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 20,
};

NpcAISettings N(npcAISettings_802444F0) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 3,
};

Script N(npcAI_80244520) = SCRIPT({
    SetSelfVar(2, 3);
    SetSelfVar(3, 18);
    SetSelfVar(5, 3);
    SetSelfVar(7, 4);
    N(func_80242918_CD9BF8)(N(npcAISettings_802444F0));
});

Script N(80244590) = SCRIPT({
    SetNpcRotation(NPC_SELF, 0, 0, 0);
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetSelfVar(10, 100);
            DoNpcDefeat();
        }
        == 2 {
            func_80045900(0);
        }
        == 3 {
            SetEnemyFlagBits(-1, 16, 1);
            RemoveNpc(NPC_SELF);
        }
    }
});

NpcSettings N(npcSettings_8024465C) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_80244520),
    .onHit = EnemyNpcHit,
    .onDefeat = &N(80244590),
    .level = 19,
};

StaticNpc N(npcGroup_80244688) = {
    .id = NPC_LAKITU0,
    .settings = &N(npcSettings_802444C4),
    .pos = { -185.0f, 90.0f, 10.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 270,
    .dropFlags = 0x80,
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
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_2),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_4),
        NPC_ANIM(lakitu, Palette_00, Anim_4),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244878) = {
    .id = NPC_LAKITU1,
    .settings = &N(npcSettings_802444C4),
    .pos = { 200.0f, 90.0f, -25.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
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
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_2),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_4),
        NPC_ANIM(lakitu, Palette_00, Anim_4),
        NPC_ANIM(lakitu, Palette_00, Anim_3),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
        NPC_ANIM(lakitu, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244A68) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244C58) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80244E48) = {
    .id = NPC_SPINY2,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80245038) = {
    .id = NPC_SPINY3,
    .settings = &N(npcSettings_8024465C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
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

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA588, 660, 60, -115, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1390));
    MakeItemEntity(ITEM_LETTER09, -245, 0, 105, 17, SI_SAVE_FLAG(1389));
});

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_MATCHING
// second npc_raycast_down_sides call
void N(func_80241040_BE47F0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            test = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            npc->pos.y = test;
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY;
            phi_f4 += temp_f26;
            d = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            test = d;
            npc->pos.y = test;
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }
        //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.point.x, enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1] < 3)) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_17/CD7350", flo_17_func_80240220_CD7500, ScriptInstance* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240CC4_CD7FA4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024440C_CDB6EC)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024137C_CD865C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240220_CD7500)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240CC4_CD7FA4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

s32 N(func_80241568_CD8848)(void) {
    s32 i;

    for (i = 50; i < 54; i++) {
        if (get_enemy(i)->varTable[10] == 0) {
            return i;
        }
    }

    return -1;
}

void N(func_802415B0_CD8890)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0] = 12;
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.point.x,
                               enemy->territory->wander.point.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSizeX,
                               enemy->territory->wander.wanderSizeZ) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0] = 2;
        script->functionTemp[1] = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1] == 0)) {
            script->functionTemp[0] = 0;
        }
    }
}

void N(func_80241A14_CD8CF4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);
    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        script->functionTemp[0] = 12;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->functionTemp[0] = 0;
    }
}

// enemy2 is being copied to a0
#ifdef NON_MATCHING
ApiStatus N(func_80241C64_CD8F44)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    f32 temp_f4;
    f32 dist;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
        script->functionTemp[0] = 0;
    }
    npc->unk_AB = -3;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }


    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);

        case 1:
            N(func_802415B0_CD8890)(script, aiSettings, territoryPtr);
            break;

        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);

        case 3:
            N(func_80241A14_CD8CF4)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->functionTemp[0] == 12) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enemy->varTable[4] = N(func_80241568_CD8848)();
        if (enemy->varTable[4] >= 0) {
            Enemy* enemy2 = get_enemy(enemy->varTable[4]);
            enemy2->varTable[10] = 1;
            enemy2->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->currentAnim.w = 0x490014;
            script->functionTemp[0] = 30;
        }
    }

    switch (script->functionTemp[0]) {
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    switch (script->functionTemp[0]) {
        case 30:
            npc->duration--;
            if (npc->duration <= 0) {
                get_enemy(enemy->varTable[4])->varTable[10] = 2;
                npc->duration = 5;
                script->functionTemp[0] = 31;
            }

        case 31:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->currentAnim.w = 0x490015;
                get_enemy(enemy->varTable[4])->varTable[10] = 3;
                npc->duration = 10;
                script->functionTemp[0] = 32;
            }

        case 32:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->duration = 3;
                script->functionTemp[0] = 33;
            }

        case 33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->functionTemp[0] = 0;
            }
            break;
    }

    if (((u32)script->functionTemp[0] - 30) < 2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, npc->pos.x, npc->pos.z);
        if (!is_point_within_region(territoryPtr->shape, territoryPtr->pointX, territoryPtr->pointZ, npc->pos.x, npc->pos.z,
                                    territoryPtr->sizeX, territoryPtr->sizeZ)) {
            if ((dist > 30.0) && (npc->turnAroundYawAdjustment == 0)) {
                temp_f4 = dist - 20.0;
                if (temp_f4 < 0.0) {
                    temp_f4 = 0.0f;
                }
                if (temp_f4 > 200.0) {
                    temp_f4 = 200.0f;
                }
                npc->moveSpeed = update_lerp(0, aiSettings->moveSpeed, aiSettings->chaseSpeed, temp_f4, 200);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
        }
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_17/CD7350", flo_17_func_80241C64_CD8F44, ScriptInstance* script,
            s32 isInitialCall);
#endif

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

ApiStatus N(func_802424D8_CD97B8)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~0x40000000;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if ((npc->currentAnim.w + 0xFFAAFFD2) < 2) {
                npc->currentAnim.w = 0x55000C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 0x21) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim.w = 0x55002F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim.w = 0x55002E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 99:
            func_8004A73C(script);
            break;

    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim.w + 0xFFAAFFFC) {
                case 0:
                case 8:
                case 10:
                case 12:
                case 14:
                case 18:
                case 20:
                    npc->currentAnim.w++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242918_CD9BF8)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;
    u32 x, y, z;
    f32 x2, y2, z2, w2;
    Npc* npc2;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->varTable[10] == 100)) {
        script->functionTemp[0] = 100;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        enemy->flags |= 0x200000;
        npc->flags = (npc->flags & ~0x200) | 8;
        enemy->varTable[10] = 0;
        enemy->varTable[11] = -1;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
    }

    if (enemy->unk_B0 & 4) {
        npc->duration = 0;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B0 &= ~4;
        if (npc->flags & 0x800) {
            npc->currentAnim.w = 0x4A0018;
            npc->moveSpeed = 0.0f;
            npc->jumpVelocity = 0.0f;
            npc->jumpScale = 1.0f;
            script->functionTemp[0] = 102;
        } else {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            npc->currentAnim.w = enemy->animList[0];
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 200;
        }
    }
    get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &x, &y, &z);
    if ((script->functionTemp[0] < 100) && ((x + 50) >= 421)) {
        script->functionTemp[0] = 110;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            if (enemy->varTable[13] != 0) {
                if (npc->pos.y <= 0.0) {
                    npc->flags = (npc->flags & ~0x200) | 8;
                } else {
                    npc->flags = (npc->flags | 0x200) & ~8;
                }
            }
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 100:
            if (enemy->varTable[10] != 2) {
                break;
            }
            npc2 = get_npc_unsafe(get_enemy(enemy->varTable[11])->npcID);
            if (npc2->yaw < 180.0) {
                npc->pos.x = npc2->pos.x + 12.0;
            } else {
                npc->pos.x = npc2->pos.x - 12.0;
            }
            npc->pos.y = npc2->pos.y + 25.0;
            npc->pos.z = npc2->pos.z + 1.0;
            npc->rotation.y = 0.0f;
            npc->flags |= 8;
            npc->flags &= ~2;
            npc->flags &= ~0x200;
            npc->renderYaw = 0.0f;
            npc->currentAnim.w = 0x4A0018;
            script->functionTemp[0] = 101;

        case 101:
            if (enemy->varTable[10] != 3) {
                break;
            }
            enemy->varTable[10] = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            npc->moveSpeed = 2.5f;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 0.8f;
            npc->flags |= 0x800;
            script->functionTemp[0] = 102;

        case 102:
            if (npc->moveSpeed > 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y;
                z2 = npc->pos.z;
                if (npc_test_move_simple_with_slipping(npc->unk_80, &x2, &y2, &z2, npc->moveSpeed, npc->yaw, npc->collisionHeight,
                                  npc->collisionRadius) == 0) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                } else {
                    npc->moveSpeed = 0.0f;
                }
            }


            if (npc->jumpVelocity < 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y + 13.0;
                z2 = npc->pos.z;
                w2 = fabsf(npc->jumpVelocity) + 16.0;
                if ((npc_raycast_down_sides(npc->unk_80, &x2, &y2, &z2, &w2) != 0) && (w2 <= (fabsf(npc->jumpVelocity) + 13.0))) {
                    npc->pos.y = y2;
                    enemy->territory->wander.point.x = npc->pos.x;
                    enemy->territory->wander.point.y = npc->pos.y;
                    enemy->territory->wander.point.z = npc->pos.z;
                    enemy->territory->wander.detect.x = npc->pos.x;
                    enemy->territory->wander.detect.y = npc->pos.y;
                    enemy->territory->wander.detect.z = npc->pos.z;
                    enemy->varTable[10] = 5;
                    if (enemy->varTable[13] != 0) {
                        if (npc->pos.y <= 0.0) {
                            npc->flags = (npc->flags & ~0x200) | 8;
                        } else {
                            npc->flags = (npc->flags | 0x200) & ~8;
                        }
                    } else if (!enemy->territory->wander.isFlying) {
                        npc->flags = (npc->flags | 0x200) & ~8;
                    } else {
                        npc->flags = (npc->flags & ~0x200) | 8;
                    }
                    npc->flags = (npc->flags | 0x40000) & ~0x800;
                    npc->jumpVelocity = 0.0f;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                    npc->currentAnim.w = 0x4A001A;
                    npc->duration = 3;
                    script->functionTemp[0] = 103;
                    break;
                }
            }
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            break;

        case 103:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags &= 0xFFFBFFFF;
                npc->currentAnim.w = 0x4A0001;
                script->functionTemp[0] = 0;
            }
            break;

        case 110:
            npc->duration = 30;
            npc->pos.x = 0.0f;
            npc->pos.z = 0.0f;
            npc->pos.y = -1000.0f;
            npc->flags = (npc->flags | 0xA) & ~0x200;
            script->functionTemp[0] = 111;

        case 111:
            npc->duration--;
            if (npc->duration <= 0) {
                enemy->varTable[10] = 0;
                script->functionTemp[0] = 100;
            }
            break;

        case 200:
            func_8004A73C(script);
            break;

    }
    return ApiStatus_BLOCK;
}
