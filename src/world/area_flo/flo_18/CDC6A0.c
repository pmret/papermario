#include "flo_18.h"
#include "message_ids.h"
#include "sprite/npc/flying_magikoopa.h"
#include "sprite/npc/lakitu.h"
#include "sprite/npc/magikoopa.h"
#include "sprite/npc/world_lakilester.h"

enum {
    NPC_LAKITU0,
    NPC_LAKITU1,
    NPC_LAKITU2,
    NPC_MAGIKOOPA,
    NPC_FLYING_MAGIKOOPA,
};

EntryList N(entryList) = {
    { -320.0f, 0.0f,  0.0f,  90.0f },
    {   36.0f, 0.0f, 40.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_18_tattle },
};

EvtSource N(80240830) = SCRIPT({
    match EVT_STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_PUFF_PUFF_MACHINE, 0, 8);
            PlaySoundAtCollider(20, 0x80000025, 0);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

static s32 N(pad_8B8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(updateTexturePan_802408C0) = SCRIPT({
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

EvtSource N(exitWalk_8024095C) = EXIT_WALK_SCRIPT(60,  0, "flo_17",  1);

EvtSource N(802409B8) = SCRIPT({
    bind N(exitWalk_8024095C) TRIGGER_FLOOR_ABOVE 0;
});

s32 N(lavaResetList_802409E4)[] = {
    0x0000000B, 0xC3480000, 0x00000000, 0x42F00000, 0x0000000C, 0x00000000, 0x00000000, 0x42F00000,
    0x0000000D, 0x432A0000, 0x00000000, 0x42F00000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_8024669C));
    spawn N(80247024);
    spawn N(802436BC);
    spawn N(802456D4);
    ModifyColliderFlags(3, 8, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_802409E4));
    }
    EnableTexPanning(9, 1);
    EnableTexPanning(11, 1);
    EnableTexPanning(12, 1);
    EnableTexPanning(13, 1);
    EnableTexPanning(14, 1);
    EnableTexPanning(15, 1);
    EnableTexPanning(7, 1);
    EnableTexPanning(8, 1);
    EnableTexPanning(10, 1);
    EnableTexPanning(16, 1);
    EnableTexPanning(17, 1);
    spawn {
        EVT_VAR(0) = 1;
        EVT_VAR(1) = -140;
        EVT_VAR(2) = 0;
        EVT_VAR(3) = 0;
        EVT_VAR(4) = 0;
        EVT_VAR(5) = 1;
        EVT_VAR(6) = 0;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 0;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802408C0);
    }
    spawn {
        EVT_VAR(0) = 2;
        EVT_VAR(1) = -200;
        EVT_VAR(2) = 0;
        EVT_VAR(3) = 0;
        EVT_VAR(4) = 0;
        EVT_VAR(5) = 1;
        EVT_VAR(6) = 0;
        EVT_VAR(7) = 0;
        EVT_VAR(8) = 0;
        EVT_VAR(9) = 0;
        EVT_VAR(10) = 0;
        EVT_VAR(11) = 0;
        EVT_VAR(12) = 0;
        spawn N(updateTexturePan_802408C0);
    }
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) == 0) {
        ModifyColliderFlags(0, 1, 0x7FFFFE00);
        EVT_VAR(0) = N(802409B8);
        spawn EnterWalk;
    } else {
        spawn N(80244058);
        spawn N(802409B8);
    }
    await N(80240830);
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_8024030C_CDC9AC)();
    }
});

static s32 N(pad_E88)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80240E90) = SCRIPT({
    group 11;
    loop {
        PlayEffect(0x5E, 0, -16.0, 102.0, -4.099609375, 80.900390625, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep 4;
        PlayEffect(0x5E, 0, 80.900390625, 102.0, -4.099609375, -16.0, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep 4;
        if (EVT_SAVE_VAR(253) >= 3) {
            break loop;
        }
    }
    EVT_VAR(0) = 6;
    loop 5 {
        PlayEffect(0x5E, 0, -16.0, 102.0, -4.099609375, 80.900390625, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep EVT_VAR(0);
        EVT_VAR(0) += 2;
        PlayEffect(0x5E, 0, 80.900390625, 102.0, -4.099609375, -16.0, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep EVT_VAR(0);
        EVT_VAR(0) += 2;
    }
});

EvtSource N(80241094) = SCRIPT({
    EnableModel(EVT_VAR(15), 1);
    EVT_VAR(14) = 159;
    loop EVT_VAR(14) {
        EVT_VAR(3) += (float) 0;
        EVT_VAR(4) += 0.0;
        EVT_VAR(5) = 0.0107421875;
        EVT_VAR(0) += (float) EVT_VAR(3);
        EVT_VAR(1) += (float) EVT_VAR(4);
        EVT_VAR(2) += (float) EVT_VAR(5);
        EVT_VAR(6) *= 1.0107421875;
        EVT_VAR(7) += 0.0107421875;
        EVT_VAR(8) = (float) EVT_VAR(6);
        N(UnkFloatFunc)(EVT_VAR(14), EVT_VAR(10), 0.0, 0.203125, 15, 0, 0);
        EVT_VAR(8) += (float) EVT_VAR(10);
        EVT_VAR(9) = (float) EVT_VAR(7);
        N(UnkFloatFunc)(EVT_VAR(14), EVT_VAR(10), 0.0, 0.203125, 20, 0, 90);
        EVT_VAR(9) += (float) EVT_VAR(10);
        EVT_VAR(10) = (float) EVT_VAR(0);
        EVT_VAR(10) *= 10.0;
        TranslateModel(EVT_VAR(15), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(EVT_VAR(15), EVT_VAR(8), EVT_VAR(9), 1);
        RotateModel(EVT_VAR(15), EVT_VAR(10), 0, 0, 1);
        sleep 1;
    }
    EnableModel(EVT_VAR(15), 0);
});

EvtSource N(80241284) = SCRIPT({
    EVT_VAR(14) = 0;
0:
    if (EVT_SAVE_VAR(253) >= 3) {
        return;
    }
    EVT_VAR(0) = 132.0;
    EVT_VAR(1) = 90.0;
    EVT_VAR(2) = -30.0;
    RandInt(100, EVT_VAR(3));
    EVT_VAR(3) += (float) -50;
    EVT_VAR(3) /= (float) 200.0;
    EVT_VAR(4) = 1.0;
    EVT_VAR(5) = (float) 0;
    EVT_VAR(6) = 0.296875;
    EVT_VAR(7) = 0.296875;
    EVT_VAR(15) = EVT_VAR(14);
    EVT_VAR(15) += 10000;
    spawn N(80241094);
    EVT_VAR(14) += 1;
    if (EVT_VAR(14) >= 16) {
        EVT_VAR(14) = 0;
    }
    sleep 10;
    goto 0;
});

EvtSource N(802413F0) = SCRIPT({
    if (EVT_MAP_FLAG(2) == 1) {
        return;
    }
    EVT_MAP_FLAG(2) = 1;
    EVT_VAR(15) = 0;
    loop 12 {
        RandInt(80, EVT_VAR(0));
        EVT_VAR(0) -= 40;
        RandInt(50, EVT_VAR(1));
        RandInt(50, EVT_VAR(2));
        EVT_VAR(2) -= 25;
        PlayEffect(0x0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5, 10, 1, 1, 0, 0, 0, 0, 0, 0);
        EVT_VAR(15) += 1;
        N(UnkFloatFunc)(EVT_VAR(15), EVT_VAR(14), 1.0, 1.09375, 2, 0, 0);
        N(UnkFloatFunc)(EVT_VAR(15), EVT_VAR(13), 1.09375, 1.0, 2, 0, 0);
        EVT_VAR(0) = (float) EVT_VAR(14);
        EVT_VAR(1) = (float) EVT_VAR(13);
        EVT_VAR(2) = (float) EVT_VAR(14);
        if (EVT_SAVE_VAR(252) == 0) {
            ScaleModel(31, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(32, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        }
        if (EVT_SAVE_VAR(253) == 0) {
            ScaleModel(19, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(20, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        }
        if (EVT_SAVE_VAR(252) <= 1) {
            ScaleModel(21, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        }
        if (EVT_SAVE_VAR(252) <= 2) {
            if (EVT_SAVE_VAR(253) <= 1) {
                ScaleModel(22, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(23, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(24, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(25, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(26, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            }
        }
        ScaleModel(27, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        if (EVT_SAVE_VAR(252) <= 2) {
            if (EVT_SAVE_VAR(253) <= 2) {
                ScaleModel(29, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(41, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                ScaleModel(33, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            }
        }
        ScaleModel(36, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(37, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(38, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(39, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(40, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(34, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(0) -= 1.046875;
        EVT_VAR(0) *= 100.0;
        if (EVT_SAVE_VAR(252) == 0) {
            RotateModel(31, EVT_VAR(0), 0, 0, 1);
            RotateModel(32, EVT_VAR(0), 0, 0, 1);
        }
        if (EVT_SAVE_VAR(253) == 0) {
            RotateModel(19, EVT_VAR(0), 0, 0, 1);
            RotateModel(20, EVT_VAR(0), 0, 0, 1);
        }
        if (EVT_SAVE_VAR(252) <= 1) {
            RotateModel(21, EVT_VAR(0), 0, 0, 1);
        }
        if (EVT_SAVE_VAR(252) <= 2) {
            if (EVT_SAVE_VAR(253) <= 1) {
                RotateModel(22, EVT_VAR(0), 0, 0, 1);
                RotateModel(23, EVT_VAR(0), 0, 0, 1);
                RotateModel(24, EVT_VAR(0), 0, 0, 1);
                RotateModel(25, EVT_VAR(0), 0, 0, 1);
                RotateModel(26, EVT_VAR(0), 0, 0, 1);
            }
        }
        RotateModel(27, EVT_VAR(0), 0, 0, 1);
        if (EVT_SAVE_VAR(252) <= 2) {
            if (EVT_SAVE_VAR(253) <= 2) {
                RotateModel(29, EVT_VAR(0), 0, 0, 1);
                RotateModel(41, EVT_VAR(0), 0, 0, 1);
                RotateModel(33, EVT_VAR(0), 0, 0, 1);
            }
        }
        RotateModel(36, EVT_VAR(0), 0, 0, 1);
        RotateModel(37, EVT_VAR(0), 0, 0, 1);
        RotateModel(38, EVT_VAR(0), 0, 0, 1);
        RotateModel(39, EVT_VAR(0), 0, 0, 1);
        RotateModel(40, EVT_VAR(0), 0, 0, 1);
        RotateModel(34, EVT_VAR(0), 0, 0, 1);
        sleep 1;
    }
    EVT_VAR(0) = (float) 1;
    EVT_VAR(1) = (float) 1;
    EVT_VAR(2) = (float) 1;
    if (EVT_SAVE_VAR(252) == 0) {
        ScaleModel(31, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(32, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    }
    if (EVT_SAVE_VAR(253) == 0) {
        ScaleModel(19, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        ScaleModel(20, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    }
    if (EVT_SAVE_VAR(252) <= 1) {
        ScaleModel(21, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    }
    if (EVT_SAVE_VAR(252) <= 2) {
        if (EVT_SAVE_VAR(253) <= 1) {
            ScaleModel(22, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(23, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(24, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(25, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(26, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        }
    }
    ScaleModel(27, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_SAVE_VAR(252) <= 2) {
        if (EVT_SAVE_VAR(253) <= 2) {
            ScaleModel(29, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(41, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            ScaleModel(33, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        }
    }
    ScaleModel(36, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ScaleModel(37, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ScaleModel(38, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ScaleModel(39, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ScaleModel(40, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ScaleModel(34, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    sleep 1;
    EVT_MAP_FLAG(2) = 0;
});

#ifdef NON_MATCHING
EvtSource N(80241ED4) = SCRIPT({
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 0;
    EVT_VAR(2) = 0;
    EVT_VAR(3) = -1.0;
    EVT_VAR(4) = 0.0;
    EVT_VAR(5) = 3.0;
    spawn {
        sleep 10;
        PlaySoundAtCollider(19, 486, 0);
    }
    loop 300 {
        EVT_VAR(4) += -0.5;
        EVT_VAR(5) += 0.09375;
        EVT_VAR(0) += (float) EVT_VAR(3);
        EVT_VAR(1) += (float) EVT_VAR(4);
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(1) < -10) {
            EVT_VAR(1) = -10.0;
            EVT_VAR(3) = 0.0;
            EVT_VAR(4) = 0.0;
            if (EVT_VAR(2) >= 80) {
                goto 0;
            }
        }
    }
    TranslateModel(31, -78, 19, 2);
    TranslateModel(32, -78, 19, 2);
    TranslateModel(31, EVT_VAR(0), EVT_VAR(1), 0);
    TranslateModel(32, EVT_VAR(0), EVT_VAR(1), 0);
    RotateModel(31, EVT_VAR(2), 0, 0, 1);
    RotateModel(32, EVT_VAR(2), 0, 0, 1);
    TranslateModel(31, 78, -19, -2);
    TranslateModel(32, 78, -19, -2);
    sleep 1;
}
0:
    sleep 30;
    ModifyColliderFlags(0, 19, 0x7FFFFE00);
});
#else
EvtSource N(80241ED4) = {
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(0), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(1), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(2), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(3), EVT_FIXED(-1.0)),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(4), EVT_FIXED(0.0)),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(5), EVT_FIXED(3.0)),
    EVT_CMD(EVT_OP_SPAWN_THREAD),
        EVT_CMD(EVT_OP_SLEEP_FRAMES, 10),
        EVT_CMD(EVT_OP_CALL, PlaySoundAtCollider, 19, 486, 0),
    EVT_CMD(EVT_OP_END_SPAWN_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(4), EVT_FIXED(-0.5)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(5), EVT_FIXED(0.09375)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(0), EVT_VAR(3)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(1), EVT_VAR(4)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(2), EVT_VAR(5)),
        EVT_CMD(EVT_OP_IF_LT, EVT_VAR(1), -10),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(1), EVT_FIXED(-10.0)),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(3), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(4), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_IF_GE, EVT_VAR(2), 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, TranslateModel, 31, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 32, -78, 19, 2),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 31, EVT_VAR(0), EVT_VAR(1), 0),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 32, EVT_VAR(0), EVT_VAR(1), 0),
    EVT_CMD(EVT_OP_CALL, RotateModel, 31, EVT_VAR(2), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, RotateModel, 32, EVT_VAR(2), 0, 0, 1),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 31, 78, -19, -2),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 32, 78, -19, -2),
    EVT_CMD(EVT_OP_SLEEP_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_SLEEP_FRAMES, 30),
EVT_CMD(EVT_OP_CALL, ModifyColliderFlags, 0, 19, 0x7FFFFE00),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtSource N(80242174) = SCRIPT({
    EVT_VAR(0) = (float) 0;
    EVT_VAR(1) = (float) 0;
    EVT_VAR(2) = (float) 0;
    EVT_VAR(3) = 0.0;
    EVT_VAR(4) = 0.0;
    EVT_VAR(5) = -5.0;
    spawn {
        sleep 12;
        PlaySoundAtCollider(21, 487, 0);
    }
    loop 300 {
        EVT_VAR(4) += -0.5;
        EVT_VAR(0) += (float) EVT_VAR(3);
        EVT_VAR(1) += (float) EVT_VAR(4);
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(2) < -45) {
            EVT_VAR(5) = 5;
        }
        if (EVT_VAR(2) > 0) {
            EVT_VAR(2) = 0;
            EVT_VAR(3) = 5;
        }
        if (EVT_VAR(1) < -25) {
            EVT_VAR(4) = 0;
            EVT_VAR(1) = -25;
        }
        if (EVT_VAR(0) > 90) {
            goto 0;
        }
        TranslateModel(19, 50, 28, 27);
        TranslateModel(20, 50, 28, 27);
        TranslateModel(19, 0, EVT_VAR(1), 1);
        TranslateModel(20, 0, EVT_VAR(1), 1);
        RotateModel(19, EVT_VAR(0), 1, 0, 0);
        RotateModel(20, EVT_VAR(0), 1, 0, 0);
        RotateModel(19, EVT_VAR(2), 0, 0, 1);
        RotateModel(20, EVT_VAR(2), 0, 0, 1);
        TranslateModel(19, -50, -28, -27);
        TranslateModel(20, -50, -28, -27);
        sleep 1;
    }
0:
    sleep 30;
});

EvtSource N(80242474) = SCRIPT({
    EVT_VAR(2) = (float) 0;
    EVT_VAR(1) = (float) 0;
    EVT_VAR(0) = (float) 0;
    EVT_VAR(5) = 0.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(23, 487, 0);
    }
    loop 300 {
        EVT_VAR(5) += 0.5;
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(2) >= 80) {
            EVT_VAR(2) = (float) 80;
            EVT_VAR(5) *= -0.5;
            if (EVT_VAR(5) == 0) {
                goto 0;
            }
        }
        TranslateModel(21, -55, 5, 16);
        TranslateModel(21, EVT_VAR(0), EVT_VAR(1), 0);
        RotateModel(21, EVT_VAR(2), 0, 0, 1);
        TranslateModel(21, 55, -5, -16);
        sleep 1;
    }
0:
    sleep 30;
});

EvtSource N(80242620) = SCRIPT({
    EVT_VAR(2) = (float) 0;
    EVT_VAR(1) = (float) 0;
    EVT_VAR(0) = (float) 0;
    EVT_VAR(5) = 0.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(22, 487, 0);
    }
    loop 300 {
        EVT_VAR(5) += 0.5;
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(2) >= 80) {
            EVT_VAR(2) = (float) 80;
            EVT_VAR(5) *= -0.5;
            if (EVT_VAR(5) == 0) {
                goto 0;
            }
        }
        TranslateModel(24, 60, 0, 16);
        RotateModel(24, EVT_VAR(2), 0, 0, -1);
        TranslateModel(24, -60, 0, -16);
        TranslateModel(22, 0, 0, 27);
        TranslateModel(23, 0, 0, 27);
        RotateModel(22, EVT_VAR(2), 1, 0, 0);
        RotateModel(23, EVT_VAR(2), 1, 0, 0);
        TranslateModel(22, 0, 0, -27);
        TranslateModel(23, 0, 0, -27);
        TranslateModel(25, 0, 0, -41);
        TranslateModel(26, 0, 0, -41);
        RotateModel(25, EVT_VAR(2), -1, 0, 0);
        RotateModel(26, EVT_VAR(2), -1, 0, 0);
        TranslateModel(25, 0, 0, 41);
        TranslateModel(26, 0, 0, 41);
        sleep 1;
    }
0:
    sleep 30;
});

#ifdef NON_MATCHING
EvtSource N(80242910) = SCRIPT({
    EVT_VAR(0) = 0;
    EVT_VAR(1) = 0;
    EVT_VAR(2) = 0;
    EVT_VAR(3) = -1.0;
    EVT_VAR(4) = 0.0;
    EVT_VAR(5) = 3.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(18, 486, 0);
    }
    loop 300 {
        EVT_VAR(4) += -0.5;
        EVT_VAR(5) += 0.09375;
        EVT_VAR(0) += (float) EVT_VAR(3);
        EVT_VAR(1) += (float) EVT_VAR(4);
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(1) < -25) {
            EVT_VAR(1) = -25.0;
            EVT_VAR(3) = 0.0;
            EVT_VAR(4) = 0.0;
            if (EVT_VAR(2) >= 80) {
                goto 0;
            }
        }
    }
    TranslateModel(29, 124, 17, 3);
    TranslateModel(29, EVT_VAR(0), EVT_VAR(1), 0);
    RotateModel(29, EVT_VAR(2), 0, 0, -1);
    TranslateModel(29, -124, -17, -3);
    sleep 1;
}
0:
    return;
    break;
});
#else
EvtSource N(80242910) = {
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(0), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(1), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(2), 0),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(3), EVT_FIXED(-1.0)),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(4), EVT_FIXED(0.0)),
    EVT_CMD(EVT_OP_SET_F, EVT_VAR(5), EVT_FIXED(3.0)),
    EVT_CMD(EVT_OP_SPAWN_THREAD),
        EVT_CMD(EVT_OP_SLEEP_FRAMES, 15),
        EVT_CMD(EVT_OP_CALL, PlaySoundAtCollider, 18, 486, 0),
    EVT_CMD(EVT_OP_END_SPAWN_THREAD),
    EVT_CMD(EVT_OP_LOOP, 300),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(4), EVT_FIXED(-0.5)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(5), EVT_FIXED(0.09375)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(0), EVT_VAR(3)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(1), EVT_VAR(4)),
        EVT_CMD(EVT_OP_ADD_F, EVT_VAR(2), EVT_VAR(5)),
        EVT_CMD(EVT_OP_IF_LT, EVT_VAR(1), -25),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(1), EVT_FIXED(-25.0)),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(3), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_SET_F, EVT_VAR(4), EVT_FIXED(0.0)),
            EVT_CMD(EVT_OP_IF_GE, EVT_VAR(2), 80),
                EVT_CMD(EVT_OP_GOTO, 0),
            EVT_CMD(EVT_OP_END_IF),
        EVT_CMD(EVT_OP_END_IF),
    EVT_CMD(EVT_OP_END_IF), // BUG: extraneous END_IF
    EVT_CMD(EVT_OP_CALL, TranslateModel, 29, 124, 17, 3),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 29, EVT_VAR(0), EVT_VAR(1), 0),
    EVT_CMD(EVT_OP_CALL, RotateModel, 29, EVT_VAR(2), 0, 0, -1),
    EVT_CMD(EVT_OP_CALL, TranslateModel, 29, -124, -17, -3),
    EVT_CMD(EVT_OP_SLEEP_FRAMES, 1),
EVT_CMD(EVT_OP_END_LOOP),
EVT_CMD(EVT_OP_LABEL, 0),
EVT_CMD(EVT_OP_RETURN),
EVT_CMD(EVT_OP_END)
};
#endif

EvtSource N(80242B18) = SCRIPT({
    ModifyColliderFlags(0, 18, 0x7FFFFE00);
    EVT_VAR(0) = (float) 0;
    EVT_VAR(1) = (float) 0;
    EVT_VAR(2) = (float) 0;
    EVT_VAR(3) = 3.0;
    EVT_VAR(4) = 1.0;
    EVT_VAR(5) = 5.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(20, 486, 0);
    }
    loop 300 {
        EVT_VAR(4) += -0.5;
        EVT_VAR(0) += (float) EVT_VAR(3);
        EVT_VAR(1) += (float) EVT_VAR(4);
        EVT_VAR(2) += (float) EVT_VAR(5);
        if (EVT_VAR(1) <= -40) {
            EVT_VAR(1) = (float) -40;
            EVT_VAR(4) *= -0.5;
            if (EVT_VAR(4) <= 1) {
                goto 1;
            }
        }
        if (EVT_VAR(2) >= 60) {
            EVT_VAR(2) = (float) 60;
            EVT_VAR(5) = (float) 0;
        }
        TranslateModel(41, -34, 50, 10);
        TranslateModel(33, -34, 50, 10);
        TranslateModel(41, 0, EVT_VAR(1), EVT_VAR(0));
        RotateModel(41, EVT_VAR(2), 0, 0, 1);
        TranslateModel(33, 0, EVT_VAR(1), EVT_VAR(0));
        RotateModel(33, EVT_VAR(2), 0, 0, 1);
        TranslateModel(41, 34, -50, -10);
        TranslateModel(33, 34, -50, -10);
        sleep 1;
    }
1:
    sleep 30;
});

s32 N(intTable_80242DC8)[] = {
    0x00000000, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B, 0x0000003C, 0x0000000A,
    0x0000001B, 0x0000001E, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B, 0x0000001E,
    0x00000000, 0x0000001B, 0x00000055, 0x00000000, 0x0000001B, 0x00000050, 0x00000023, 0x0000001B,
};

EvtSource N(80242E28) = SCRIPT({
    EVT_VAR(10) = EVT_VAR(0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_VAR(0) < -210) {
        return;
    }
    PlaySound(0x1E5);
    await N(802413F0);
    EVT_VAR(0) = EVT_VAR(10);
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        EVT_MAP_FLAG(1) = 1;
        return;
    }
    if (EVT_MAP_FLAG(3) == 1) {
        return;
    }
    EVT_MAP_FLAG(3) = 1;
    if (EVT_VAR(0) > 2) {
        goto 0;
    }
    if (EVT_VAR(0) == 2) {
        goto 11;
    }
    if (EVT_VAR(0) == 0) {
    11:
        if (EVT_SAVE_VAR(252) == 0) {
            EVT_SAVE_VAR(252) = 1;
            spawn N(80241ED4);
            goto 0;
        }
    }
    if (EVT_VAR(0) == 1) {
        if (EVT_SAVE_VAR(253) == 0) {
            EVT_SAVE_VAR(253) = 1;
            spawn N(80242174);
            goto 0;
        }
    }
    if (EVT_VAR(0) == 0) {
        if (EVT_SAVE_VAR(252) == 1) {
            EVT_SAVE_VAR(252) = 2;
            spawn N(80242474);
            goto 0;
        }
    }
    if (EVT_SAVE_VAR(252) == 2) {
        if (EVT_SAVE_VAR(253) == 1) {
            EVT_SAVE_VAR(253) = 2;
            spawn N(80242620);
            goto 0;
        }
    }
    if (EVT_SAVE_VAR(252) == 2) {
        if (EVT_SAVE_VAR(253) == 2) {
            DisablePlayerInput(TRUE);
            UseSettingsFrom(0, 40, 0, 0);
            SetPanTarget(0, 40, 0, 0);
            SetCamSpeed(0, 1.5);
            PanToTarget(0, 0, 1);
            EVT_SAVE_VAR(253) = 3;
            await N(802413F0);
            await N(802413F0);
            await N(802413F0);
            sleep 30;
            GetModelCenter(27);
            PlayEffect(0x1D, 0, EVT_VAR(0), 50, EVT_VAR(2), 100, 20, 0, 30, 0, 0, 0, 0, 0);
            PlayEffect(0x1D, 0, EVT_VAR(0), 30, EVT_VAR(2), 120, 20, 0, 30, 0, 0, 0, 0, 0);
            PlayEffect(0x1D, 0, EVT_VAR(0), 10, EVT_VAR(2), 100, 20, 0, 30, 0, 0, 0, 0, 0);
            sleep 15;
            spawn {
                EVT_VAR(3) = 6;
                buf_use N(intTable_80242DC8);
                loop 8 {
                    buf_read EVT_VAR(0) EVT_VAR(1) EVT_VAR(2);
                    PlaySoundAt(0x190, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                    PlayEffect(0x27, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 6, 0, 0, 0, 0, 0, 0, 0);
                    sleep 2;
                    EVT_VAR(1) += 5;
                    PlaySoundAt(0x190, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                    PlayEffect(0x27, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 2, 15, 0, 0, 0, 0, 0, 0, 0);
                    sleep EVT_VAR(3);
                    EVT_VAR(3) += 1;
                }
                EVT_VAR(4) = 2.0;
                loop 2 {
                    buf_use N(intTable_80242DC8);
                    loop 8 {
                        buf_read EVT_VAR(0) EVT_VAR(1) EVT_VAR(2);
                        PlaySoundAt(0x190, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
                        PlayEffect(0x27, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 25, 0, 0, 0, 0, 0, 0, 0);
                        sleep EVT_VAR(3);
                        EVT_VAR(3) += EVT_VAR(4);
                        EVT_VAR(4) += 0.5;
                    }
                }
            }
            PlaySoundAt(0x1A0, 0, 70, 40, 10);
            PlayEffect(0x24, 0, 70, 40, 10, 3.0, 30, 0, 0, 0, 0, 0, 0, 0);
            ShakeCam(0, 0, 20, 1.0);
            PlaySoundAt(0x1A0, 0, 0, 30, 30);
            PlayEffect(0x24, 0, 0, 30, 30, 4.0, 40, 0, 0, 0, 0, 0, 0, 0);
            ShakeCam(0, 0, 20, 2.0);
            await N(80242910);
            PlaySoundAtCollider(20, 1169, 0);
            FadeOutMusic(0, 1000);
            DisablePlayerPhysics(TRUE);
            sleep 30;
            await N(80242B18);
            EVT_STORY_PROGRESS = STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE;
            GotoMap("flo_15", 1);
            sleep 70;
            return;
        }
    }
0:
    EVT_MAP_FLAG(3) = 0;
});

Vec4f N(triggerCoord_8024367C) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_8024368C) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_8024369C) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802436AC) = { 105.0f, 0.0f, -10.0, 0.0f };

EvtSource N(802436BC) = SCRIPT({
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        EnableModel(49, 0);
        ModifyColliderFlags(0, 19, 0x7FFFFE00);
        EnableModel(31, 0);
        EnableModel(32, 0);
        EnableModel(19, 0);
        EnableModel(20, 0);
        EnableModel(21, 0);
        EnableModel(22, 0);
        EnableModel(23, 0);
        EnableModel(24, 0);
        EnableModel(25, 0);
        EnableModel(26, 0);
        EnableModel(29, 0);
        EnableModel(41, 0);
        EnableModel(33, 0);
        ModifyColliderFlags(0, 18, 0x7FFFFE00);
        return;
    }
    spawn N(80240E90);
    EnableModel(49, 0);
    if (EVT_SAVE_VAR(252) >= 1) {
        ModifyColliderFlags(0, 19, 0x7FFFFE00);
        EnableModel(31, 0);
        EnableModel(32, 0);
    }
    if (EVT_SAVE_VAR(253) >= 1) {
        EnableModel(19, 0);
        EnableModel(20, 0);
    }
    if (EVT_SAVE_VAR(252) >= 2) {
        EnableModel(21, 0);
    }
    if (EVT_SAVE_VAR(253) >= 2) {
        EnableModel(22, 0);
        EnableModel(23, 0);
        EnableModel(24, 0);
        EnableModel(25, 0);
        EnableModel(26, 0);
    }
    if (EVT_SAVE_VAR(253) >= 3) {
        EnableModel(29, 0);
        EnableModel(41, 0);
        EnableModel(33, 0);
        ModifyColliderFlags(0, 18, 0x7FFFFE00);
        return;
    }
    EVT_VAR(0) = 0;
    bind N(80242E28) TRIGGER_WALL_HAMMER 23;
    bind N(80242E28) TRIGGER_POINT_BOMB N(triggerCoord_8024367C);
    bind N(80242E28) TRIGGER_POINT_BOMB N(triggerCoord_8024368C);
    EVT_VAR(0) = 1;
    bind N(80242E28) TRIGGER_WALL_HAMMER 22;
    bind N(80242E28) TRIGGER_POINT_BOMB N(triggerCoord_8024369C);
    bind N(80242E28) TRIGGER_POINT_BOMB N(triggerCoord_802436AC);
    EVT_VAR(0) = 3;
    bind N(80242E28) TRIGGER_WALL_HAMMER 19;
    EVT_VAR(0) = 4;
    bind N(80242E28) TRIGGER_WALL_HAMMER 18;
    EVT_VAR(0) = 0;
    loop 16 {
        EVT_VAR(1) = EVT_VAR(0);
        EVT_VAR(1) += 10000;
        EVT_VAR(0) += 1;
        CloneModel(49, EVT_VAR(1));
        EnableModel(EVT_VAR(1), 0);
    }
    spawn N(80241284);
    EnableTexPanning(36, 1);
    EnableTexPanning(37, 1);
    EnableTexPanning(38, 1);
    EnableTexPanning(39, 1);
    EnableTexPanning(40, 1);
    EnableTexPanning(41, 1);
    spawn {
        EVT_VAR(14) = 1.0;
0:
        if (EVT_SAVE_VAR(253) >= 3) {
            EVT_VAR(14) *= 0.953125;
        }
        EVT_VAR(15) += (float) EVT_VAR(14);
        if (EVT_VAR(15) == 1080) {
            EVT_VAR(15) = (float) 0;
        }
        EVT_VAR(0) = EVT_VAR(15);
        EVT_VAR(0) /= 9;
        EVT_VAR(0) %= 4;
        EVT_VAR(0) *= 16384;
        EVT_VAR(1) = EVT_VAR(15);
        EVT_VAR(1) /= 4;
        EVT_VAR(1) %= 2;
        EVT_VAR(1) *= 16384;
        EVT_VAR(2) = EVT_VAR(15);
        EVT_VAR(2) /= 5;
        EVT_VAR(2) %= 2;
        EVT_VAR(2) *= 16384;
        EVT_VAR(3) = EVT_VAR(15);
        EVT_VAR(3) /= 6;
        EVT_VAR(3) %= 2;
        EVT_VAR(3) *= 16384;
        EVT_VAR(4) = EVT_VAR(15);
        EVT_VAR(4) /= 2;
        EVT_VAR(4) %= 2;
        EVT_VAR(4) *= 32768;
        EVT_VAR(5) = EVT_VAR(15);
        EVT_VAR(5) /= 8;
        EVT_VAR(5) %= 2;
        EVT_VAR(5) *= 16384;
        SetTexPanOffset(12, 0, EVT_VAR(0), 0);
        SetTexPanOffset(13, 0, EVT_VAR(1), 0);
        SetTexPanOffset(14, 0, EVT_VAR(2), 0);
        SetTexPanOffset(15, 0, EVT_VAR(3), 0);
        SetTexPanOffset(11, 0, EVT_VAR(4), 0);
        SetTexPanOffset(10, 0, EVT_VAR(5), 0);
        SetTexPanOffset(9, 0, EVT_VAR(5), 0);
        sleep 1;
        goto 0;
    }
});

NpcSettings N(npcSettings_80243F10) = {
    .height = 32,
    .radius = 24,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 20,
};

NpcSettings N(npcSettings_80243F3C) = {
    .height = 34,
    .radius = 24,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 26,
};

Vec3f N(vectorList_80243F68)[] = {
    { -55.0, 15.0, 35.0 }, { -155.0, 35.0, 35.0 },
    { -255.0, 75.0, 35.0 }, { -355.0, 155.0, 35.0 },
    { -455.0, 315.0, 35.0 },
};

Vec3f N(vectorList_80243FA4)[] = {
    { -20.0, 15.0, 30.0 }, { -120.0, 35.0, 30.0 },
    { -220.0, 75.0, 30.0 }, { -320.0, 155.0, 30.0 },
    { -420.0, 315.0, 30.0 },
};

Vec3f N(vectorList_80243FE0)[] = {
    { 65.0, 15.0, 30.0 }, { -35.0, 35.0, 30.0 },
    { -135.0, 75.0, 30.0 }, { -235.0, 155.0, 30.0 },
    { -335.0, 315.0, 30.0 },
};

Vec3f N(vectorList_8024401C)[] = {
    { 120.0, 15.0, 30.0 }, { 20.0, 35.0, 30.0 },
    { -80.0, 75.0, 30.0 }, { -180.0, 155.0, 30.0 },
    { -280.0, 315.0, 30.0 },
};

EvtSource N(80244058) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetPlayerPos(30, 0, 50);
    InterpPlayerYaw(90, 0);
    SetNpcPos(NPC_PARTNER, 65, 0, 50);
    sleep 30;
    AdjustCam(0, 8.0, 0, 300, 19.0, -8.5);
    GetCurrentPartnerID(EVT_VAR(0));
    BringPartnerOut(8);
    if (EVT_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        EVT_VAR(1) += 20;
        EVT_VAR(2) += 20;
        EVT_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 30);
    }
    PlayerFaceNpc(-4, 0);
    NpcFacePlayer(NPC_PARTNER, 0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C9));
    SetPlayerAnimation(ANIM_NOD_YES);
    sleep 10;
    SetPlayerAnimation(ANIM_STAND_STILL);
    sleep 20;
    EnablePartnerAI();
    PutPartnerAway();
    ResetCam(0, 4.0);
    DisablePlayerInput(FALSE);
});

EvtSource N(80244270) = SCRIPT({
    spawn {
        PlaySoundAtNpc(NPC_FLYING_MAGIKOOPA, 0x19E, 0);
        SetNpcFlagBits(NPC_FLYING_MAGIKOOPA, ((NPC_FLAG_100)), TRUE);
        InterpNpcYaw(NPC_FLYING_MAGIKOOPA, 270, 0);
        LoadPath(60, N(vectorList_80243F68), 5, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_FLYING_MAGIKOOPA, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) != 1) {
                break loop;
            }
        }
    }
    sleep 15;
    spawn {
        PlaySoundAtNpc(NPC_LAKITU0, 0x19F, 0);
        SetNpcFlagBits(NPC_LAKITU0, ((NPC_FLAG_100)), TRUE);
        InterpNpcYaw(NPC_LAKITU0, 270, 0);
        LoadPath(60, N(vectorList_80243FA4), 5, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) != 1) {
                break loop;
            }
        }
    }
    spawn {
        SetNpcFlagBits(NPC_LAKITU1, ((NPC_FLAG_100)), TRUE);
        InterpNpcYaw(NPC_LAKITU1, 270, 0);
        LoadPath(70, N(vectorList_80243FE0), 5, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) != 1) {
                break loop;
            }
        }
    }
    PlaySoundAtNpc(NPC_LAKITU2, 0x19F, 0);
    SetNpcFlagBits(NPC_LAKITU2, ((NPC_FLAG_100)), TRUE);
    InterpNpcYaw(NPC_LAKITU2, 270, 0);
    LoadPath(80, N(vectorList_8024401C), 5, 0);
    loop {
        GetNextPathPos();
        SetNpcPos(NPC_LAKITU2, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        sleep 1;
        if (EVT_VAR(0) != 1) {
            break loop;
        }
    }
});

EvtSource N(802445D4) = SCRIPT({
    sleep 5;
    IsPlayerWithin(40, 0, 200, EVT_VAR(0));
    if (EVT_VAR(0) == 0) {
        EVT_VAR(3) = 45;
    } else {
        EVT_VAR(3) = 25;
    }
    EVT_VAR(4) = EVT_VAR(3);
    EVT_VAR(4) += -5;
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    if (EVT_VAR(2) > -61) {
        parallel {
            SetNpcFlagBits(NPC_LAKITU0, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU0, EVT_VAR(0), 55, EVT_VAR(3));
        }
        parallel {
            SetNpcFlagBits(NPC_LAKITU1, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU1, EVT_VAR(0), 55, EVT_VAR(3));
        }
        parallel {
            SetNpcFlagBits(NPC_LAKITU2, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU2, EVT_VAR(0), 55, EVT_VAR(3));
        }
        sleep EVT_VAR(4);
    }
});

EvtSource N(80244774) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    GetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetNpcPos(NPC_PARTNER, 65, EVT_VAR(1), 80);
    SetNpcYaw(NPC_PARTNER, 270);
    AdjustCam(0, 8.0, 0, 450, 17.0, -6.0);
    SpeakToPlayer(NPC_FLYING_MAGIKOOPA, NPC_ANIM_flying_magikoopa_Palette_02_Anim_9, NPC_ANIM_flying_magikoopa_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x00BB));
    sleep 20;
    spawn N(80244270);
    sleep 80;
    AdjustCam(0, 8.0, 0, 300, 19.0, -8.5);
    GetCurrentPartnerID(EVT_VAR(0));
    BringPartnerOut(8);
    if (EVT_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        EVT_VAR(1) += 20;
        EVT_VAR(2) += 20;
        EVT_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 30);
    }
    NpcFacePlayer(NPC_PARTNER, 0);
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C1));
    EnablePartnerAI();
    sleep 20;
    PutPartnerAway();
    ResetCam(0, 4.0);
    EVT_STORY_PROGRESS = STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS;
    DisablePlayerInput(FALSE);
    AwaitPlayerApproach(-250, 0, 50);
    DisablePlayerInput(TRUE);
    GetCurrentPartnerID(EVT_VAR(0));
    BringPartnerOut(8);
    if (EVT_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        EVT_VAR(1) += 20;
        EVT_VAR(2) += 20;
        EVT_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 30);
    }
    PlayerFaceNpc(-4, 0);
    NpcFacePlayer(NPC_PARTNER, 0);
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00C2));
    EnablePartnerAI();
    PutPartnerAway();
    ResetCam(0, 4.0);
    DisablePlayerInput(FALSE);
});

EvtSource N(idle_80244B3C) = SCRIPT({
    loop {
        GetSelfVar(0, EVT_VAR(0));
        if (EVT_VAR(0) != 0) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    sleep 10;
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamDistance(0, 1000);
    SetCamPitch(0, 17.0, -6.0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    DisablePlayerInput(FALSE);
    StartBossBattle(3);
});

EvtSource N(defeat_80244C84) = SCRIPT({
    GetBattleOutcome(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            GetSelfNpcID(EVT_VAR(0));
            if (EVT_VAR(0) == 3) {
                SetNpcPos(NPC_MAGIKOOPA, 0, -1000, 0);
                SetNpcPos(NPC_FLYING_MAGIKOOPA, -55, 15, 35);
                GetNpcYaw(3, EVT_VAR(0));
                SetNpcYaw(NPC_FLYING_MAGIKOOPA, 90);
                InterpPlayerYaw(180, 0);
                SetPlayerPos(30, 0, 80);
                SetNpcYaw(NPC_LAKITU0, 90);
                SetNpcPos(NPC_LAKITU0, -20, 15, 30);
                SetNpcYaw(NPC_LAKITU1, 270);
                SetNpcPos(NPC_LAKITU1, 65, 15, 30);
                SetNpcYaw(NPC_LAKITU2, 270);
                SetNpcPos(NPC_LAKITU2, 120, 15, 30);
                spawn N(80244774);
            }
        }
        == 1 {}
        == 2 {
        }
    }
});

EvtSource N(80244E2C) = SCRIPT({
    match EVT_MAP_VAR(10) {
        == 0 {
            NpcFacePlayer(NPC_MAGIKOOPA, 1);
        }
        == 1 {
            NpcFacePlayer(NPC_LAKITU0, 1);
        }
        == 2 {
            NpcFacePlayer(NPC_LAKITU1, 1);
        }
        == 3 {
            NpcFacePlayer(NPC_LAKITU2, 1);
        }
    }
});

EvtSource N(80244ED0) = SCRIPT({
    match EVT_MAP_VAR(10) {
        == 0 {
            SpeakToPlayer(NPC_MAGIKOOPA, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 16, MESSAGE_ID(0x11, 0x00B9));
            InterpNpcYaw(NPC_MAGIKOOPA, 90, 0);
        }
        == 1 {
            SpeakToPlayer(NPC_LAKITU0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU0, 90, 0);
        }
        == 2 {
            SpeakToPlayer(NPC_LAKITU1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU1, 270, 0);
        }
        == 3 {
            SpeakToPlayer(NPC_LAKITU2, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU2, 270, 0);
        }
    }
});

EvtSource N(80245004) = SCRIPT({
    match EVT_MAP_VAR(10) {
        == 0 {
            SpeakToPlayer(NPC_MAGIKOOPA, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 16, MESSAGE_ID(0x11, 0x00BA));
        }
        == 1 {
            SpeakToPlayer(NPC_LAKITU0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0));
        }
        == 2 {
            SpeakToPlayer(NPC_LAKITU1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0));
        }
        == 3 {
            SpeakToPlayer(NPC_LAKITU2, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 16, MESSAGE_ID(0x11, 0x00C0));
        }
    }
    SetNpcVar(3, 0, 1);
    sleep 5;
    spawn N(802445D4);
});

EvtSource N(80245108) = SCRIPT({
    if (EVT_STORY_PROGRESS >= STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        return;
    }
    DisablePlayerInput(TRUE);
    func_802D2C14(1);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    AdjustCam(0, 8.0, 0, 300, 17.0, -6.0);
    await N(80244E2C);
    match EVT_AREA_VAR(7) {
        == 0 {
            await N(80244ED0);
            EVT_AREA_VAR(7) += 1;
            ResetCam(0, 4.0);
        }
        == 1 {
            await N(80245004);
        }
    }
    func_802D2C14(0);
    DisablePlayerInput(FALSE);
});

EvtSource N(80245228) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 0;
        await N(80245108);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(8024527C) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 1;
        await N(80245108);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(802452D0) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 2;
        await N(80245108);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(80245324) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 3;
        await N(80245108);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(80245378) = SCRIPT({
    if (EVT_STORY_PROGRESS >= STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        return;
    }
    DisablePlayerInput(TRUE);
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamSpeed(0, 8.0);
    SetCamPitch(0, 17.0, -6.0);
    SetCamDistance(0, 300);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    await N(80244E2C);
    if (EVT_AREA_VAR(7) == 0) {
        await N(80244ED0);
        EVT_AREA_VAR(7) += 1;
        ResetCam(0, 4.0);
    } else {
        await N(80245004);
    }
    DisablePlayerInput(FALSE);
});

EvtSource N(802454D4) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 0;
        GetNpcPos(NPC_MAGIKOOPA, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        await N(80245378);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(80245544) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 1;
        GetNpcPos(NPC_LAKITU0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        await N(80245378);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(802455B4) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 2;
        GetNpcPos(NPC_LAKITU1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        await N(80245378);
        EVT_MAP_VAR(10) = -1;
    }
});

EvtSource N(80245624) = SCRIPT({
    if (EVT_MAP_VAR(10) == -1) {
        EVT_MAP_VAR(10) = 3;
        GetNpcPos(NPC_LAKITU2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        await N(80245378);
        EVT_MAP_VAR(10) = -1;
    }
});

Vec4f N(triggerCoord_80245694) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456A4) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_802456B4) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456C4) = { 105.0f, 0.0f, -10.0, 0.0f };

EvtSource N(802456D4) = SCRIPT({
    EVT_MAP_VAR(10) = -1;
    bind N(80245228) TRIGGER_WALL_HAMMER 23;
    bind N(80245228) TRIGGER_WALL_HAMMER 19;
    bind N(802454D4) TRIGGER_POINT_BOMB N(triggerCoord_802456A4);
    bind N(80245544) TRIGGER_POINT_BOMB N(triggerCoord_80245694);
    bind N(802452D0) TRIGGER_WALL_HAMMER 22;
    bind N(802455B4) TRIGGER_POINT_BOMB N(triggerCoord_802456B4);
    bind N(80245324) TRIGGER_WALL_HAMMER 18;
    bind N(80245624) TRIGGER_POINT_BOMB N(triggerCoord_802456C4);
});

EvtSource N(interact_802457D4) = SCRIPT({
    match EVT_AREA_VAR(6) {
        == 0 {
            GetSelfNpcID(EVT_VAR(0));
            if (EVT_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5,
                              MESSAGE_ID(0x11, 0x00B6));
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11,
                              0x00BC));
            }
            EVT_AREA_VAR(6) += 1;
        }
        == 1 {
            GetSelfNpcID(EVT_VAR(0));
            if (EVT_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5,
                              MESSAGE_ID(0x11, 0x00B7));
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11,
                              0x00BD));
            }
            EVT_AREA_VAR(6) += 1;
        }
        == 2 {
            AdjustCam(0, 8.0, 0, 300, 19.0, -9.0);
            GetSelfNpcID(EVT_VAR(0));
            if (EVT_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 5,
                              MESSAGE_ID(0x11, 0x00B8));
                NpcFacePlayer(NPC_SELF, 0);
                sleep 15;
                EndSpeech(-1, NPC_ANIM_magikoopa_Palette_02_Anim_2, NPC_ANIM_magikoopa_Palette_02_Anim_1, 0);
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11,
                              0x00BE));
                NpcFacePlayer(NPC_SELF, 0);
                sleep 15;
                EndSpeech(-1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0);
            }
            SetNpcVar(3, 0, 1);
            sleep 5;
            spawn N(802445D4);
            BindNpcInteract(NPC_LAKITU0, 0);
            BindNpcInteract(NPC_LAKITU1, 0);
            BindNpcInteract(NPC_LAKITU2, 0);
            BindNpcInteract(NPC_MAGIKOOPA, 0);
        }
    }
});

EvtSource N(init_80245AA8) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcIdle(NPC_SELF, N(idle_80244B3C));
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_80245B30) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_80245B90) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_80245C04) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_80245C78) = SCRIPT({
    if (EVT_STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

StaticNpc N(npcGroup_80245CEC)[] = {
    {
        .id = NPC_LAKITU0,
        .settings = &N(npcSettings_80243F10),
        .pos = { 0.0f, 15.0f, 60.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245B90),
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
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_LAKITU1,
        .settings = &N(npcSettings_80243F10),
        .pos = { 65.0f, 15.0f, 60.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245C04),
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
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_LAKITU2,
        .settings = &N(npcSettings_80243F10),
        .pos = { 135.0f, 15.0f, 35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245C78),
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
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_MAGIKOOPA,
        .settings = &N(npcSettings_80243F3C),
        .pos = { -60.0f, 0.0f, 50.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245AA8),
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
        .animations = {
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_magikoopa_Palette_02_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
    {
        .id = NPC_FLYING_MAGIKOOPA,
        .settings = &N(npcSettings_80243F3C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_400000,
        .init = &N(init_80245B30),
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
        .animations = {
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_4,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
            NPC_ANIM_flying_magikoopa_Palette_02_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E4),
    },
};

NpcGroupList N(npcGroupList_8024669C) = {
    NPC_GROUP(N(npcGroup_80245CEC), BATTLE_ID(24, 11, 0, 7)),
    {},
};

static s32 N(pad_66B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

void playFX_82();

ApiStatus N(func_8024030C_CDC9AC)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

typedef struct N(unk_effect) {
    char unk_00[0x30];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    char unk_3C[0x4];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
} N(unk_effect);

typedef struct N(temp) {
    char unk_00[0xC];
    N(unk_effect)* unk_0C;
} N(temp);

ApiStatus N(func_80240340_CDC9E0)(Evt* script, s32 isInitialCall) {
    N(temp)* ptr = script->varTable[15];

    ptr->unk_0C->unk_30 = 69;
    ptr->unk_0C->unk_34 = 255;
    ptr->unk_0C->unk_38 = 217;
    ptr->unk_0C->unk_40 = 176;
    ptr->unk_0C->unk_44 = 254;
    ptr->unk_0C->unk_48 = 124;
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"
