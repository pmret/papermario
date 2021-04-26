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
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_flo_09_tattle,
};

Script N(80241880) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        }
        else {
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
    N(func_80240040_CB5040)();
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

// *INDENT-OFF*
Script N(searchBush_80242880) = {
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
Script N(shakeTree_80242BE0) = {
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

s32 N(treeModelList_Tree1_Leaves)[] = {
    0x00000002, 0x0000000F, 0x00000010,
};

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000001, 0x0000000E,
};

s32 N(shakeTreeEvent_Tree1)[] = {
    N(treeModelList_Tree1_Leaves), N(treeModelList_Tree1_Trunk), 0x00000000, 0x00000000, N(tree1_Callback),
};

s32 N(triggerCoord_80243428)[] = {
    0xC3480000, 0x00000000, 0x3F800000, 0x00000000,
};

s32 N(treeModelList_Tree2_Leaves)[] = {
    0x00000002, 0x00000013, 0x00000014,
};

s32 N(treeModelList_Tree2_Trunk)[] = {
    0x00000001, 0x00000012,
};

s32 N(shakeTreeEvent_Tree2)[] = {
    N(treeModelList_Tree2_Leaves), N(treeModelList_Tree2_Trunk), 0x00000000, 0x00000000, N(tree2_Callback),
};

s32 N(triggerCoord_80243460)[] = {
    0x00000000, 0x00000000, 0x3F800000, 0x00000000,
};

s32 N(treeModelList_Tree3_Leaves)[] = {
    0x00000002, 0x00000017, 0x00000018,
};

s32 N(treeModelList_Tree3_Trunk)[] = {
    0x00000001, 0x00000016,
};

s32 N(shakeTreeEvent_Tree3)[] = {
    N(treeModelList_Tree3_Leaves), N(treeModelList_Tree3_Trunk), 0x00000000, 0x00000000, N(tree3_Callback),
};

s32 N(triggerCoord_80243498)[] = {
    0x43480000, 0x00000000, 0x3F800000, 0x00000000,
};

Script N(802434A8) = SCRIPT({
    SI_AREA_VAR(4) = 0;
    SI_AREA_VAR(5) = 0;
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree_80242BE0) to TRIGGER_WALL_HAMMER 15;
    bind N(shakeTree_80242BE0) to TRIGGER_POINT_BOMB N(triggerCoord_80243428);
    SI_VAR(0) = N(shakeTreeEvent_Tree2);
    bind N(shakeTree_80242BE0) to TRIGGER_WALL_HAMMER 16;
    bind N(shakeTree_80242BE0) to TRIGGER_POINT_BOMB N(triggerCoord_80243460);
    SI_VAR(0) = N(shakeTreeEvent_Tree3);
    bind N(shakeTree_80242BE0) to TRIGGER_WALL_HAMMER 17;
    bind N(shakeTree_80242BE0) to TRIGGER_POINT_BOMB N(triggerCoord_80243498);
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

void N(func_80240320_CB5320)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}

#ifdef NON_MATCHING
void N(func_802404D0_CB54D0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        // original m2c reference:
        //if ((temp_s0->flags & 8) != 0) {
        //    phi_f0 = temp_f20 + ((temp_f24 - temp_f20) * D_802441A8_CB91A8);
        //    phi_f4 = temp_f24;
        //} else {
        //    func_800DCB7C(temp_s0->unk_80, &subroutine_argA, &subroutine_argB, &subroutine_argC, &subroutine_argD, temp_s0->pos.x, temp_f20, temp_s0->pos.z, 1000.0f);
        //    temp_f4 = subroutine_argB + temp_f26;
        //    phi_f0 = temp_f20 + ((temp_f4 - temp_f20) * D_802441B0_CB91B0);
        //    phi_f4 = temp_f4;
        //}
        //temp_s0->pos.y = phi_f0;

        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY + temp_f26;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }

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
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            if (script->functionTemp[1].s <= 0) {
                script->functionTemp[1].s = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    func_800494C0(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0].s = 10;
                    } else {
                        script->functionTemp[0].s = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1].s--;
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
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1].s < 3)) {
                script->functionTemp[0].s = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_09/CB5320", flo_09_func_802404D0_CB54D0, ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240F74_CB5F74)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024362C_CB862C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024162C_CB662C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, npcAISettings);
    }
    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240320_CB5320)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_802404D0_CB54D0)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(func_80240F74_CB5F74)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, npcAISettings, territoryPtr);
    }

    return ApiStatus_BLOCK;
}
