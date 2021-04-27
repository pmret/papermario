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

Script N(80240600) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
    } else {
        SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
    }
    if (STORY_PROGRESS >= STORY_CH6_FILLED_SPRING_WITH_WATER) {
        PlaySound(0x80000022);
    }
});

Script N(80240690) = SCRIPT({
    group 11;
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    SI_VAR(12) = SI_VAR(2);
    SI_VAR(13) = SI_VAR(3);
    SI_VAR(14) = SI_VAR(4);
    SI_VAR(12) -= SI_VAR(0);
    SI_VAR(13) -= SI_VAR(1);
    SI_VAR(0) =f SI_VAR(12);
    SI_VAR(0) /= 100.0;
    SI_VAR(15) = 100.0;
    SI_VAR(15) /=f SI_VAR(0);
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

Script N(exitWalk_8024093C) = EXIT_WALK_SCRIPT(60,  0, "flo_08",  1);

Script N(exitWalk_80240998) = EXIT_WALK_SCRIPT(60,  1, "flo_10",  0);

Script N(802409F4) = SCRIPT({
    bind N(exitWalk_8024093C) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80240998) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    await N(makeEntities);
    func_802C971C(93);
    func_802C971C(100);
    spawn N(80241728);
    spawn N(80241ABC);
    ModifyColliderFlags(3, 29, 0x00000004);
    ModifyColliderFlags(3, 27, 0x00000004);
    ModifyColliderFlags(3, 28, 0x00000004);
    ModifyColliderFlags(0, 29, 0x00080000);
    ModifyColliderFlags(0, 27, 0x00080000);
    ModifyColliderFlags(0, 28, 0x00080000);
    ModifyColliderFlags(3, 23, 0x00000001);
    SI_VAR(0) = -480;
    SI_VAR(1) = -350;
    SI_VAR(2) = -65;
    SI_VAR(3) = -260;
    SI_VAR(4) = 0;
    spawn N(80240690);
    SI_VAR(0) = 100;
    SI_VAR(1) = -350;
    SI_VAR(2) = 480;
    SI_VAR(3) = -260;
    SI_VAR(4) = 0;
    spawn N(80240690);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 2) {
        spawn N(8024183C);
        spawn N(802409F4);
    } else {
        SI_VAR(0) = N(802409F4);
        spawn EnterWalk;
    }
    await N(80240600);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CF0940)();
    }
});

static s32 N(pad_D38)[] = {
    0x00000000, 0x00000000,
};

// *INDENT-OFF*
Script N(searchBush_80240D40) = {
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(0)),
    SI_CMD(ScriptOpcode_BUFFER_READ_4, SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4)),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(5), SI_VAR(15), SI_VAR(7)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(1), 0),
            SI_CMD(ScriptOpcode_LOOP, 5),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(3), SI_FIXED(0.1005859375), 1, SI_VAR(15), 0),
                    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
                        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
                        SI_CMD(ScriptOpcode_CALL, PlaySoundAtModel, SI_VAR(3), 339, 0),
                    SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(3), SI_FIXED(0.1005859375), -1, SI_VAR(15), 0),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                SI_CMD(ScriptOpcode_CALL, TranslateModel, SI_VAR(3), 0, 0, 0),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(2), 0),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
                SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(5), SI_VAR(6), SI_VAR(7)),
                SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(8), SI_VAR(9), SI_VAR(10)),
                SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(10), 0),
                    SI_CMD(ScriptOpcode_CALL, DropItemEntity, SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9)),
                SI_CMD(ScriptOpcode_ELSE),
                    SI_CMD(ScriptOpcode_CALL, GetValueByRef, SI_VAR(10), SI_VAR(11)),
                    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(11), 0),
                        SI_CMD(ScriptOpcode_CALL, SetValueByRef, SI_VAR(10), 1),
                        SI_CMD(ScriptOpcode_CALL, DropItemEntity, SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9)),
                    SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(4), 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, 0xFE363C84),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(shakeTree_802410A0) = {
    SI_CMD(ScriptOpcode_SET_TIMESCALE, SI_FIXED(2.0)),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(0)),
    SI_CMD(ScriptOpcode_BUFFER_READ_4, SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(6), SI_VAR(15), SI_VAR(8)),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 357),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 358),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(1), 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_LOOP, 5),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(3), SI_FIXED(0.1005859375), SI_FIXED(0.2001953125), SI_VAR(15), 0),
                    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
                        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
                        SI_CMD(ScriptOpcode_CALL, PlaySoundAtModel, SI_VAR(3), 358, 0),
                    SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(3), SI_FIXED(0.1005859375), SI_FIXED(-0.19921875), SI_VAR(15), 0),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                SI_CMD(ScriptOpcode_CALL, TranslateModel, SI_VAR(3), 0, 0, 0),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(2), 0),
            SI_CMD(ScriptOpcode_LOOP, 5),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(4), SI_FIXED(0.1005859375), SI_FIXED(0.2001953125), SI_VAR(15), 0),
                    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
                        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
                        SI_CMD(ScriptOpcode_CALL, PlaySoundAtModel, SI_VAR(4), 357, 0),
                    SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
                SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
                    SI_CMD(ScriptOpcode_CALL, N(SomeMatrixOperation2), SI_VAR(4), SI_FIXED(0.1005859375), SI_FIXED(-0.19921875), SI_VAR(15), 0),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
                SI_CMD(ScriptOpcode_CALL, TranslateModel, SI_VAR(4), 0, 0, 0),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(3), 0),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(3)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(4)),
                SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
                SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(6), SI_VAR(7), SI_VAR(8)),
                SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(9), SI_VAR(10), SI_VAR(11)),
                SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(11), 0),
                    SI_CMD(ScriptOpcode_CALL, DropItemEntity, SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10)),
                SI_CMD(ScriptOpcode_ELSE),
                    SI_CMD(ScriptOpcode_CALL, GetValueByRef, SI_VAR(11), SI_VAR(12)),
                    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(12), 0),
                        SI_CMD(ScriptOpcode_CALL, SetValueByRef, SI_VAR(11), 1),
                        SI_CMD(ScriptOpcode_CALL, DropItemEntity, SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10)),
                    SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_IF_NE, SI_VAR(4), 0),
            SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(4)),
            SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
            SI_CMD(ScriptOpcode_LOOP, SI_VAR(5)),
                SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(6), SI_VAR(7), SI_VAR(8)),
                SI_CMD(ScriptOpcode_CALL, PlayEffect, 20, 0, SI_VAR(6), SI_VAR(7), SI_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(5), 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, 0xFE363C85),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

s32 N(treeModelList_Tree1_Leaves)[] = {
    0x00000006, 0x00000014, 0x00000012, 0x00000015, 0x00000016, 0x00000017, 0x00000013,
};

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000001, 0x00000011,
};

s32 N(treeDropList_Tree1)[] = {
    2,
    ITEM_BUBBLE_BERRY, -38, 87, -156, 0xC, 0, SI_AREA_FLAG(31),
    ITEM_BUBBLE_BERRY, 39, 65, -208, 0xC, 0, SI_AREA_FLAG(32),
};

s32 N(shakeTreeEvent_Tree1)[] = {
    N(treeModelList_Tree1_Leaves), N(treeModelList_Tree1_Trunk), N(treeDropList_Tree1), 0x00000000, 0x00000000,
};

s32 N(triggerCoord_80241718)[] = {
    0x3F800000, 0x00000000, 0xC3400000, 0x00000000,
};

Script N(80241728) = SCRIPT({
    SI_AREA_FLAG(31) = 0;
    SI_AREA_FLAG(32) = 0;
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree_802410A0) to TRIGGER_WALL_HAMMER 13;
    bind N(shakeTree_802410A0) to TRIGGER_POINT_BOMB N(triggerCoord_80241718);
});

Script N(updateTexturePan_802417A0) = SCRIPT({
    group 0;
    if (SI_VAR(5) == 1) {
        if (SI_VAR(6) == 1) {
            if (SI_VAR(7) == 1) {
                if (SI_VAR(8) == 1) {
                    N(UnkTexturePanFunc)();
                    return;
                }
            }
        }
    }
    N(UnkTexturePanFunc2)();
});

/*
Script N(8024183C) = SCRIPT({
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
        RotateModel(101, SI_VAR(0), 1, 0, 0);
        RotateModel(103, SI_VAR(0), 1, 0, 0);
        if (SI_VAR(1) == 1) {
            sleep 1;
            goto 0;
        }
        spawn {
            MakeLerp(45, 100, 150, 0);
            loop {
                UpdateLerp();
                TranslateGroup(100, 0, SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            sleep 30;
            STORY_PROGRESS = STORY_CH6_FILLED_SPRING_WITH_WATER;
            GotoMap("flo_10", 2);
            sleep 100;
        }
    }
});
*/

const char N(flo_10_name_hack)[];

// *INDENT-OFF*
Script N(8024183C) = {
    SI_CMD(ScriptOpcode_CALL, DisablePlayerInput, 1),
    SI_CMD(ScriptOpcode_CALL, TranslateGroup, 100, 0, 45, 0),
    SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, 170, 0, 160),
    SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, 170, -90, 160),
    SI_CMD(ScriptOpcode_CALL, SetCamDistance, 0, 800),
    SI_CMD(ScriptOpcode_CALL, SetCamPitch, 0, SI_FIXED(18.5), SI_FIXED(-7.5)),
    SI_CMD(ScriptOpcode_CALL, SetCamPosA, 0, SI_FIXED(-300.0), SI_FIXED(200.0)),
    SI_CMD(ScriptOpcode_CALL, SetCamPosB, 0, SI_FIXED(300.0), SI_FIXED(-150.0)),
    SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(90.0)),
    SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 0x80000050),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, MakeLerp, 80, 90, 10, 0),
        SI_CMD(ScriptOpcode_LABEL, 0),
        SI_CMD(ScriptOpcode_CALL, UpdateLerp),
        SI_CMD(ScriptOpcode_CALL, RotateModel, 101, SI_VAR(0), 1, 0, 0),
        SI_CMD(ScriptOpcode_CALL, RotateModel, 103, SI_VAR(0), 1, 0, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(1), 1),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, MakeLerp, 45, 100, 150, 0),
            SI_CMD(ScriptOpcode_LOOP, 0),
                SI_CMD(ScriptOpcode_CALL, UpdateLerp),
                SI_CMD(ScriptOpcode_CALL, TranslateGroup, 100, 0, SI_VAR(0), 0),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(1), 0),
                    SI_CMD(ScriptOpcode_BREAK_LOOP),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(0), 49),
            SI_CMD(ScriptOpcode_CALL, GotoMap, N(flo_10_name_hack), 2),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 100),
            SI_CMD(ScriptOpcode_RETURN),
            SI_CMD(ScriptOpcode_END)
        };
        // *INDENT-ON*

Script N(80241ABC) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_FILLED_SPRING_WITH_WATER) {
        EnableGroup(94, 0);
        ModifyColliderFlags(0, 30, 0x7FFFFE00);
    } else {
        EnableGroup(65, 0);
    }
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 2) {
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
        SI_VAR(0) = 1;
        SI_VAR(1) = 140;
        SI_VAR(2) = -80;
        SI_VAR(3) = -70;
        SI_VAR(4) = 100;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        SI_VAR(0) = 2;
        SI_VAR(1) = -70;
        SI_VAR(2) = 100;
        SI_VAR(3) = 100;
        SI_VAR(4) = -40;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        SI_VAR(0) = 3;
        SI_VAR(1) = 0;
        SI_VAR(2) = -800;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        SI_VAR(0) = 4;
        SI_VAR(1) = 0;
        SI_VAR(2) = -800;
        SI_VAR(3) = -200;
        SI_VAR(4) = 100;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        SI_VAR(0) = 5;
        SI_VAR(1) = 0;
        SI_VAR(2) = -2500;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 0;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
    spawn {
        SI_VAR(0) = 6;
        SI_VAR(1) = 0;
        SI_VAR(2) = -2500;
        SI_VAR(3) = -200;
        SI_VAR(4) = 100;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 1;
        SI_VAR(8) = 1;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802417A0);
    }
});

static s32 N(pad_21A4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, -325, 60, -140, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1393));
    MakeEntity(0x802EA588, 325, 60, -140, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(1394));
    MakeEntity(0x802EAB04, 335, 0, -160, 0, ITEM_MAP, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(1406));
});

void func_80072950();

ApiStatus N(func_80240000_CF0940)(ScriptInstance* script, s32 isInitialCall) {
    func_80072950(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

const char N(flo_10_name_hack)[] = "flo_10";
