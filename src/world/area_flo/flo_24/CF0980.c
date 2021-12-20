#include "flo_24.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -455.0f, 0.0f, 0.0f,  90.0f },
    {  455.0f, 0.0f, 0.0f, 270.0f },
    {  455.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_24_tattle },
};

EvtSource N(80240600) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
    } else {
        SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
    }
    if (EVT_STORY_PROGRESS >= STORY_CH6_FILLED_SPRING_WITH_WATER) {
        PlaySound(0x80000022);
    }
});

EvtSource N(80240690) = SCRIPT({
    group 11;
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(1);
    EVT_VAR(12) = EVT_VAR(2);
    EVT_VAR(13) = EVT_VAR(3);
    EVT_VAR(14) = EVT_VAR(4);
    EVT_VAR(12) -= EVT_VAR(0);
    EVT_VAR(13) -= EVT_VAR(1);
    EVT_VAR(0) = (float) EVT_VAR(12);
    EVT_VAR(0) /= 100.0;
    EVT_VAR(15) = 100.0;
    EVT_VAR(15) /= (float) EVT_VAR(0);
    EVT_VAR(15) += 11;
    EVT_VAR(5) = 200;
    EVT_VAR(5) /= EVT_VAR(15);
    EVT_VAR(5) += 1;
    loop EVT_VAR(5) {
        RandInt(EVT_VAR(12), EVT_VAR(0));
        RandInt(EVT_VAR(13), EVT_VAR(1));
        RandInt(199, EVT_VAR(2));
        EVT_VAR(3) = 210;
        EVT_VAR(3) -= EVT_VAR(2);
        EVT_VAR(0) += EVT_VAR(10);
        EVT_VAR(1) += EVT_VAR(11);
        EVT_VAR(2) += EVT_VAR(14);
        PlayEffect(0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep EVT_VAR(15);
0:
    RandInt(EVT_VAR(12), EVT_VAR(0));
    RandInt(EVT_VAR(13), EVT_VAR(1));
    EVT_VAR(0) += EVT_VAR(10);
    EVT_VAR(1) += EVT_VAR(11);
    PlayEffect(0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep EVT_VAR(15);
    goto 0;
});

EvtSource N(exitWalk_8024093C) = EXIT_WALK_SCRIPT(60,  0, "flo_08",  1);

EvtSource N(exitWalk_80240998) = EXIT_WALK_SCRIPT(60,  1, "flo_10",  0);

EvtSource N(802409F4) = SCRIPT({
    bind N(exitWalk_8024093C) TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80240998) TRIGGER_FLOOR_ABOVE 4;
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    MakeTransformGroup(93);
    MakeTransformGroup(100);
    spawn N(80241728);
    spawn N(80241ABC);
    ModifyColliderFlags(3, 29, 0x00000004);
    ModifyColliderFlags(3, 27, 0x00000004);
    ModifyColliderFlags(3, 28, 0x00000004);
    ModifyColliderFlags(0, 29, 0x00080000);
    ModifyColliderFlags(0, 27, 0x00080000);
    ModifyColliderFlags(0, 28, 0x00080000);
    ModifyColliderFlags(3, 23, 0x00000001);
    EVT_VAR(0) = -480;
    EVT_VAR(1) = -350;
    EVT_VAR(2) = -65;
    EVT_VAR(3) = -260;
    EVT_VAR(4) = 0;
    spawn N(80240690);
    EVT_VAR(0) = 100;
    EVT_VAR(1) = -350;
    EVT_VAR(2) = 480;
    EVT_VAR(3) = -260;
    EVT_VAR(4) = 0;
    spawn N(80240690);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 2) {
        spawn N(8024183C);
        spawn N(802409F4);
    } else {
        EVT_VAR(0) = N(802409F4);
        spawn EnterWalk;
    }
    await N(80240600);
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CF0940)();
    }
});

static s32 N(pad_D38)[] = {
    0x00000000, 0x00000000,
};

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 6,
    .models = { 20, 18, 21, 22, 23, 19 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 17 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { -38, 87, -156 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(31),
        },
        {
            .itemID = ITEM_BUBBLE_BERRY,
            .pos = { 39, 65, -208 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(32),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80241718) = { 1.0f, 0.0f, -192.0f, 0.0f };

EvtSource N(80241728) = SCRIPT({
    EVT_AREA_FLAG(31) = 0;
    EVT_AREA_FLAG(32) = 0;
    EVT_VAR(0) = N(tree1);
    bind N(shakeTree) TRIGGER_WALL_HAMMER 13;
    bind N(shakeTree) TRIGGER_POINT_BOMB N(triggerCoord_80241718);
});

EvtSource N(updateTexturePan_802417A0) = SCRIPT({
    group 0;
    if (EVT_VAR(5) == 1) {
        if (EVT_VAR(6) == 1) {
            if (EVT_VAR(7) == 1) {
                if (EVT_VAR(8) == 1) {
                    N(UnkTexturePanFunc)();
                    return;
                }
            }
        }
    }
    N(UnkTexturePanFunc2)();
});

extern const char N(flo_10_name_hack)[];

// BUG: missing END_SPAWN_THREADs
#ifdef NON_EQUIVALENT
EvtSource N(8024183C) = SCRIPT({
    DisablePlayerInput(TRUE);
    TranslateGroup(100, 0, 45, 0);
    UseSettingsFrom(0, 170, 0, 160);
    SetPanTarget(0, 170, -90, 160);
    SetCamDistance(0, 800);
    SetCamPitch(0, 18.5, -7.5);
    SetCamPosA(0, -300.0, 200.0);
    SetCamPosB(0, 300.0, -150.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    PlaySound(0x80000050);
    spawn {
        MakeLerp(80, 90, 10, 0);
    0:
        UpdateLerp();
        RotateModel(101, EVT_VAR(0), 1, 0, 0);
        RotateModel(103, EVT_VAR(0), 1, 0, 0);
        if (EVT_VAR(1) == 1) {
            sleep 1;
            goto 0;
        }
        spawn {
            MakeLerp(45, 100, 150, 0);
            loop {
                UpdateLerp();
                TranslateGroup(100, 0, EVT_VAR(0), 0);
                sleep 1;
                if (EVT_VAR(1) == 0) {
                    break loop;
                }
            }
            sleep 30;
            EVT_STORY_PROGRESS = STORY_CH6_FILLED_SPRING_WITH_WATER;
            GotoMap("flo_10", 2);
            sleep 100;
        }
    }
});
#else
EvtSource N(8024183C) = {
    EVT_CMD(EVT_OP_CALL, EVT_PTR(DisablePlayerInput), 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateGroup), 100, 0, 45, 0),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(UseSettingsFrom), 0, 170, 0, 160),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetPanTarget), 0, 170, -90, 160),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamDistance), 0, 800),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPitch), 0, EVT_FIXED(18.5), EVT_FIXED(-7.5)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPosA), 0, EVT_FIXED(-300.0), EVT_FIXED(200.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamPosB), 0, EVT_FIXED(300.0), EVT_FIXED(-150.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(SetCamSpeed), 0, EVT_FIXED(90.0)),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(PanToTarget), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, EVT_PTR(PlaySound), 0x80000050),
    EVT_CMD(EVT_OP_THREAD),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(MakeLerp), 80, 90, 10, 0),
        EVT_CMD(EVT_OP_LABEL, 0),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(UpdateLerp)),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 101, EVT_VAR(0), 1, 0, 0),
        EVT_CMD(EVT_OP_CALL, EVT_PTR(RotateModel), 103, EVT_VAR(0), 1, 0, 0),
        EVT_CMD(EVT_OP_IF_EQ, EVT_VAR(1), 1),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
            EVT_CMD(EVT_OP_GOTO, 0),
        EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_THREAD),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(MakeLerp), 45, 100, 150, 0),
            EVT_CMD(EVT_OP_LOOP, 0),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(UpdateLerp)),
                EVT_CMD(EVT_OP_CALL, EVT_PTR(TranslateGroup), 100, 0, EVT_VAR(0), 0),
                EVT_CMD(EVT_OP_WAIT_FRAMES, 1),
                EVT_CMD(EVT_OP_IF_EQ, EVT_VAR(1), 0),
                    EVT_CMD(EVT_OP_BREAK_LOOP),
                EVT_CMD(EVT_OP_END_IF),
            EVT_CMD(EVT_OP_END_LOOP),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 30),
            EVT_CMD(EVT_OP_SET, EVT_STORY_PROGRESS, STORY_CH6_FILLED_SPRING_WITH_WATER),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(GotoMap), EVT_PTR(N(flo_10_name_hack)), 2),
            EVT_CMD(EVT_OP_WAIT_FRAMES, 100),
            EVT_CMD(EVT_OP_RETURN),
            EVT_CMD(EVT_OP_END)
        };
#endif

EvtSource N(80241ABC) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_FILLED_SPRING_WITH_WATER) {
        EnableGroup(94, 0);
        ModifyColliderFlags(0, 30, 0x7FFFFE00);
    } else {
        EnableGroup(65, 0);
    }
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) != 2) {
        EnableGroup(105, 0);
    }
    EnableTexPanning(89, 1);
    EnableTexPanning(97, 1);
    EnableTexPanning(90, 1);
    EnableTexPanning(98, 1);
    EnableTexPanning(91, 1);
    EnableTexPanning(92, 1);
    EnableTexPanning(101, 1);
    EnableTexPanning(103, 1);
    EnableTexPanning(99, 1);
    spawn {
        EVT_VAR(0) = 1;
        EVT_VAR(1) = 140;
        EVT_VAR(2) = -80;
        EVT_VAR(3) = -70;
        EVT_VAR(4) = 100;
        EVT_VAR(5) = 1;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 1;
        EVT_VAR(8) = 1;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        EVT_VAR(0) = 2;
        EVT_VAR(1) = -70;
        EVT_VAR(2) = 100;
        EVT_VAR(3) = 100;
        EVT_VAR(4) = -40;
        EVT_VAR(5) = 1;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 1;
        EVT_VAR(8) = 1;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        EVT_VAR(0) = 3;
        EVT_VAR(1) = 0;
        EVT_VAR(2) = -800;
        EVT_VAR(3) = 0;
        EVT_VAR(4) = 0;
        EVT_VAR(5) = 0;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 0;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        EVT_VAR(0) = 4;
        EVT_VAR(1) = 0;
        EVT_VAR(2) = -800;
        EVT_VAR(3) = -200;
        EVT_VAR(4) = 100;
        EVT_VAR(5) = 0;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 1;
        EVT_VAR(8) = 1;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        EVT_VAR(0) = 5;
        EVT_VAR(1) = 0;
        EVT_VAR(2) = -2500;
        EVT_VAR(3) = 0;
        EVT_VAR(4) = 0;
        EVT_VAR(5) = 0;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 0;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        EVT_VAR(0) = 6;
        EVT_VAR(1) = 0;
        EVT_VAR(2) = -2500;
        EVT_VAR(3) = -200;
        EVT_VAR(4) = 100;
        EVT_VAR(5) = 1;
        EVT_VAR(6) = 1;
        EVT_VAR(7) = 1;
        EVT_VAR(8) = 1;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
});

static s32 N(pad_21A4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, -325, 60, -140, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END);
    AssignBlockFlag(EVT_SAVE_FLAG(1393));
    MakeEntity(0x802EA588, 325, 60, -140, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END);
    AssignBlockFlag(EVT_SAVE_FLAG(1394));
    MakeEntity(0x802EAB04, 335, 0, -160, 0, ITEM_MAP, MAKE_ENTITY_END);
    AssignPanelFlag(EVT_SAVE_FLAG(1406));
});

const char N(flo_10_name_hack)[] = "flo_10";
