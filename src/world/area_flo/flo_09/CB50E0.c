#include "flo_09.h"
#include "message_ids.h"
#include "sprite/npc/bzzap.h"
#include "sprite/npc/dayzee.h"

enum {
    NPC_DAYZEE0,
    NPC_DAYZEE1,
    NPC_BZZAP0,
    NPC_BZZAP1,
};

EntryList N(entryList) = {
    { -520.0f, 0.0f, 0.0f,  90.0f },
    {  520.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_09_tattle },
};

Script N(80241880) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

Script N(802418F0) = SCRIPT({
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

Script N(exitWalk_80241B9C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  5);

Script N(exitWalk_80241BF8) = EXIT_WALK_SCRIPT(60,  1, "flo_03",  0);

Script N(80241C54) = SCRIPT({
    bind N(exitWalk_80241B9C) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80241BF8) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_8024414C));
    spawn N(802425DC);
    spawn N(802434A8);
    ModifyColliderFlags(3, 9, 0x00000006);
    SI_VAR(0) = -511;
    SI_VAR(1) = -4;
    SI_VAR(2) = -319;
    SI_VAR(3) = 10;
    SI_VAR(4) = 0;
    spawn N(802418F0);
    SI_VAR(0) = -302;
    SI_VAR(1) = 77;
    SI_VAR(2) = -32;
    SI_VAR(3) = 116;
    SI_VAR(4) = 0;
    spawn N(802418F0);
    SI_VAR(0) = 51;
    SI_VAR(1) = 18;
    SI_VAR(2) = 141;
    SI_VAR(3) = 127;
    SI_VAR(4) = 0;
    spawn N(802418F0);
    SI_VAR(0) = 234;
    SI_VAR(1) = 38;
    SI_VAR(2) = 502;
    SI_VAR(3) = 98;
    SI_VAR(4) = 0;
    spawn N(802418F0);
    SI_VAR(0) = -525;
    SI_VAR(1) = -163;
    SI_VAR(2) = -400;
    SI_VAR(3) = -80;
    SI_VAR(4) = 60;
    spawn N(802418F0);
    SI_VAR(0) = -346;
    SI_VAR(1) = -148;
    SI_VAR(2) = 517;
    SI_VAR(3) = -91;
    SI_VAR(4) = 60;
    spawn N(802418F0);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80241C54);
    spawn EnterWalk;
    await N(80241880);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CB5000)();
    }
});

static s32 N(pad_2004)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80242010) = SCRIPT({
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

Script N(802422BC) = SCRIPT({
    SI_VAR(9) = SI_VAR(6);
    SI_VAR(8) = SI_VAR(5);
    SI_VAR(7) = SI_VAR(4);
    SI_VAR(6) = SI_VAR(3);
    SI_VAR(5) = SI_VAR(2);
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(3) = SI_VAR(0);
    EnableModel(SI_VAR(6), 0);
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(UnkFunc43)();
    if (SI_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(SI_VAR(6), 1);
    }
    if (SI_VAR(10) != 0) {
        spawn {
            sleep 5;
            SI_VAR(0) = SI_VAR(3);
            SI_VAR(1) = SI_VAR(4);
            SI_VAR(2) = SI_VAR(5);
            SI_VAR(1) += 10;
            SI_VAR(2) += 8;
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) -= 10;
            MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(SI_VAR(8), SI_VAR(0), 1, 0, 0);
    RotateModel(SI_VAR(9), SI_VAR(0), 1, 0, 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(SI_VAR(7), 0);
});

Script N(802425DC) = SCRIPT({
    GetModelCenter(69);
    SI_VAR(3) = 69;
    SI_VAR(4) = 70;
    SI_VAR(5) = 71;
    SI_VAR(6) = 72;
    SI_VAR(10) = 0;
    spawn N(802422BC);
    GetModelCenter(75);
    SI_VAR(3) = 75;
    SI_VAR(4) = 76;
    SI_VAR(5) = 77;
    SI_VAR(6) = 78;
    SI_VAR(10) = 174;
    spawn N(802422BC);
    GetModelCenter(83);
    SI_VAR(3) = 83;
    SI_VAR(4) = 84;
    SI_VAR(5) = 85;
    SI_VAR(6) = 86;
    SI_VAR(10) = 0;
    spawn N(802422BC);
    GetModelCenter(89);
    SI_VAR(3) = 89;
    SI_VAR(4) = 90;
    SI_VAR(5) = 91;
    SI_VAR(6) = 92;
    SI_VAR(10) = 0;
    spawn N(802422BC);
    GetModelCenter(97);
    SI_VAR(3) = 97;
    SI_VAR(4) = 98;
    SI_VAR(5) = 99;
    SI_VAR(6) = 100;
    SI_VAR(10) = 0;
    spawn N(802422BC);
    GetModelCenter(103);
    SI_VAR(3) = 103;
    SI_VAR(4) = 104;
    SI_VAR(5) = 105;
    SI_VAR(6) = 106;
    SI_VAR(10) = 0;
    spawn N(802422BC);
});

static s32 N(pad_2874)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/foliage.inc.c"

Script N(802431E4) = SCRIPT({
    GetNpcPos(NPC_BZZAP1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) < 0) {
        GetModelCenter(SI_VAR(9));
        SI_VAR(2) += 35;
        SetNpcPos(NPC_BZZAP1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    }
});

Script N(tree1_Callback) = SCRIPT({
    if (SI_SAVE_FLAG(1382) == 0) {
        if (SI_AREA_VAR(5) == 1) {
            MakeItemEntity(ITEM_HAPPY_FLOWER_B, -250, 100, 0, 13, SI_SAVE_FLAG(1382));
        } else {
            SI_VAR(9) = 14;
            spawn N(802431E4);
        }
        SI_AREA_VAR(4) = 0;
        SI_AREA_VAR(5) = 0;
    }
});

Script N(tree2_Callback) = SCRIPT({
    if (SI_SAVE_FLAG(1382) == 0) {
        SI_AREA_VAR(4) = 1;
        SI_AREA_VAR(5) = 0;
    }
});

Script N(tree3_Callback) = SCRIPT({
    if (SI_SAVE_FLAG(1382) == 0) {
        if (SI_AREA_VAR(4) == 1) {
            if (SI_AREA_VAR(5) == 0) {
                SI_AREA_VAR(5) = 1;
                return;
            }
        }
        SI_VAR(9) = 22;
        spawn N(802431E4);
        SI_AREA_VAR(4) = 0;
        SI_AREA_VAR(5) = 0;
    }
});

FoliageModelList N(tree1_Leaves) = {
    .count = 2,
    .models = { 15, 16 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 14 }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .callback = &N(tree1_Callback),
};

Vec4f N(triggerCoord_80243428) = { -200.0f, 0.0f, 1.0f, 0.0f };

FoliageModelList N(tree2_Leaves) = {
    .count = 2,
    .models = { 19, 20 }
};

FoliageModelList N(tree2_Trunk) = {
    .count = 1,
    .models = { 18 }
};

ShakeTreeConfig N(tree2) = {
    .leaves = &N(tree2_Leaves),
    .trunk = &N(tree2_Trunk),
    .callback = &N(tree2_Callback),
};

Vec4f N(triggerCoord_80243460) = { 0.0f, 0.0f, 1.0f, 0.0f };

FoliageModelList N(tree3_Leaves) = {
    .count = 2,
    .models = { 23, 24 }
};

FoliageModelList N(tree3_Trunk) = {
    .count = 1,
    .models = { 22 }
};

ShakeTreeConfig N(tree3) = {
    .leaves = &N(tree3_Leaves),
    .trunk = &N(tree3_Trunk),
    .callback = &N(tree3_Callback),
};

Vec4f N(triggerCoord_80243498) = { 200.0f, 0.0f, 1.0f, 0.0f };

Script N(802434A8) = SCRIPT({
    SI_AREA_VAR(4) = 0;
    SI_AREA_VAR(5) = 0;
    SI_VAR(0) = N(tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 15;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80243428);
    SI_VAR(0) = N(tree2);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 16;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80243460);
    SI_VAR(0) = N(tree3);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 17;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_80243498);
});

NpcAISettings N(npcAISettings_802435B0) = {
    .moveSpeed = 1.0f,
    .moveTime = 500,
    .waitTime = 10,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 40 },
    .unk_20 = 3,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

Script N(npcAI_802435E0) = SCRIPT({
    DoBasicAI(N(npcAISettings_802435B0));
});

NpcSettings N(npcSettings_80243600) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_802435E0),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

f32 N(D_8024362C_CB862C)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80243644) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 2,
    .chaseSpeed = 4.5f,
    .unk_1C = { .s = 6 },
    .unk_20 = 1,
    .chaseRadius = 90.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

Script N(npcAI_80243674) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -630);
    SetSelfVar(6, 50);
    SetSelfVar(1, 200);
    N(func_8024162C_CB662C)(N(npcAISettings_80243644));
});

NpcSettings N(npcSettings_802436E4) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80243674),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

NpcSettings N(npcSettings_80243710) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

Script N(npcAI_8024373C) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        match SI_VAR(0) {
            == 0 {
                GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                if (SI_VAR(1) > 0) {
                    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    SetNpcJumpscale(NPC_SELF, 0);
                    NpcJump0(NPC_SELF, SI_VAR(0), 50, SI_VAR(2), 15);
                    SetSelfVar(0, 1);
                    BindNpcAI(NPC_SELF, N(npcAI_80243674));
                }
            }
            == 2 {
                DisablePlayerInput(TRUE);
                sleep 25;
                SetNpcPos(NPC_SELF, 0, -1000, 0);
                SetNpcFlagBits(NPC_SELF, ((0x00000002)), FALSE);
                SetSelfVar(0, 0);
                DisablePlayerInput(FALSE);
            }
        }
        sleep 1;
    }
});

Script N(defeat_802438C8) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetSelfVar(0, 2);
            BindNpcAI(NPC_SELF, N(npcAI_8024373C));
            DoNpcDefeat();
        }
        == 1 {}
        == 2 {
        }
    }
});

Script N(init_80243954) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(npcAI_8024373C));
    BindNpcDefeat(NPC_SELF, N(defeat_802438C8));
});

StaticNpc N(npcGroup_8024398C) = {
    .id = NPC_DAYZEE0,
    .settings = &N(npcSettings_80243600),
    .pos = { -350.0f, 0.0f, 40.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -350, 0, 40, 30, 0, -32767, 0, -350, 0, 40, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243B7C) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_80243600),
    .pos = { 260.0f, 0.0f, 75.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { 260, 0, 75, 30, 0, -32767, 0, 260, 0, 75, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_2),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_3),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_8),
        NPC_ANIM(dayzee, Palette_00, Anim_6),
        NPC_ANIM(dayzee, Palette_00, Anim_7),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
        NPC_ANIM(dayzee, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243D6C) = {
    .id = NPC_BZZAP0,
    .settings = &N(npcSettings_802436E4),
    .pos = { -50.0f, 55.0f, 90.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -50, 55, 90, 30, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_4),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243F5C) = {
    .id = NPC_BZZAP1,
    .settings = &N(npcSettings_80243710),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80243954),
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -50, 55, 90, 100, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_3),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_6),
        NPC_ANIM(bzzap, Palette_00, Anim_4),
        NPC_ANIM(bzzap, Palette_00, Anim_2),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
        NPC_ANIM(bzzap, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_8024414C) = {
    NPC_GROUP(N(npcGroup_8024398C), BATTLE_ID(24, 16, 0, 5)),
    NPC_GROUP(N(npcGroup_80243B7C), BATTLE_ID(24, 21, 0, 5)),
    NPC_GROUP(N(npcGroup_80243D6C), BATTLE_ID(24, 23, 0, 2)),
    NPC_GROUP(N(npcGroup_80243F5C), BATTLE_ID(24, 23, 0, 2)),
    {},
};

