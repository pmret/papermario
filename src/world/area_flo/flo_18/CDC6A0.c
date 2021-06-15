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

Script N(80240830) = SCRIPT({
    match STORY_PROGRESS {
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

Script N(updateTexturePan_802408C0) = SCRIPT({
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

Script N(exitWalk_8024095C) = EXIT_WALK_SCRIPT(60,  0, "flo_17",  1);

Script N(802409B8) = SCRIPT({
    bind N(exitWalk_8024095C) to TRIGGER_FLOOR_ABOVE 0;
});

s32 N(lavaResetList_802409E4)[] = {
    0x0000000B, 0xC3480000, 0x00000000, 0x42F00000, 0x0000000C, 0x00000000, 0x00000000, 0x42F00000,
    0x0000000D, 0x432A0000, 0x00000000, 0x42F00000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
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
        SI_VAR(0) = 1;
        SI_VAR(1) = -140;
        SI_VAR(2) = 0;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 0;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802408C0);
    }
    spawn {
        SI_VAR(0) = 2;
        SI_VAR(1) = -200;
        SI_VAR(2) = 0;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 0;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_802408C0);
    }
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 0) {
        ModifyColliderFlags(0, 1, 0x7FFFFE00);
        SI_VAR(0) = N(802409B8);
        spawn EnterWalk;
    } else {
        spawn N(80244058);
        spawn N(802409B8);
    }
    await N(80240830);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_8024030C_CDC9AC)();
    }
});

static s32 N(pad_E88)[] = {
    0x00000000, 0x00000000,
};

Script N(80240E90) = SCRIPT({
    group 11;
    loop {
        PlayEffect(0x5E, 0, -16.0, 102.0, -4.099609375, 80.900390625, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep 4;
        PlayEffect(0x5E, 0, 80.900390625, 102.0, -4.099609375, -16.0, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep 4;
        if (SI_SAVE_VAR(253) >= 3) {
            break loop;
        }
    }
    SI_VAR(0) = 6;
    loop 5 {
        PlayEffect(0x5E, 0, -16.0, 102.0, -4.099609375, 80.900390625, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep SI_VAR(0);
        SI_VAR(0) += 2;
        PlayEffect(0x5E, 0, 80.900390625, 102.0, -4.099609375, -16.0, 102.0, -4.099609375, 0.5, 6, 0, 0, 0, 0);
        N(func_80240340_CDC9E0)();
        sleep SI_VAR(0);
        SI_VAR(0) += 2;
    }
});

Script N(80241094) = SCRIPT({
    EnableModel(SI_VAR(15), 1);
    SI_VAR(14) = 159;
    loop SI_VAR(14) {
        SI_VAR(3) += (float) 0;
        SI_VAR(4) += 0.0;
        SI_VAR(5) = 0.0107421875;
        SI_VAR(0) += (float) SI_VAR(3);
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        SI_VAR(6) *= 1.0107421875;
        SI_VAR(7) += 0.0107421875;
        SI_VAR(8) = (float) SI_VAR(6);
        N(UnkFloatFunc)(SI_VAR(14), SI_VAR(10), 0.0, 0.203125, 15, 0, 0);
        SI_VAR(8) += (float) SI_VAR(10);
        SI_VAR(9) = (float) SI_VAR(7);
        N(UnkFloatFunc)(SI_VAR(14), SI_VAR(10), 0.0, 0.203125, 20, 0, 90);
        SI_VAR(9) += (float) SI_VAR(10);
        SI_VAR(10) = (float) SI_VAR(0);
        SI_VAR(10) *= 10.0;
        TranslateModel(SI_VAR(15), SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(SI_VAR(15), SI_VAR(8), SI_VAR(9), 1);
        RotateModel(SI_VAR(15), SI_VAR(10), 0, 0, 1);
        sleep 1;
    }
    EnableModel(SI_VAR(15), 0);
});

Script N(80241284) = SCRIPT({
    SI_VAR(14) = 0;
0:
    if (SI_SAVE_VAR(253) >= 3) {
        return;
    }
    SI_VAR(0) = 132.0;
    SI_VAR(1) = 90.0;
    SI_VAR(2) = -30.0;
    RandInt(100, SI_VAR(3));
    SI_VAR(3) += (float) -50;
    SI_VAR(3) /= (float) 200.0;
    SI_VAR(4) = 1.0;
    SI_VAR(5) = (float) 0;
    SI_VAR(6) = 0.296875;
    SI_VAR(7) = 0.296875;
    SI_VAR(15) = SI_VAR(14);
    SI_VAR(15) += 10000;
    spawn N(80241094);
    SI_VAR(14) += 1;
    if (SI_VAR(14) >= 16) {
        SI_VAR(14) = 0;
    }
    sleep 10;
    goto 0;
});

Script N(802413F0) = SCRIPT({
    if (SI_MAP_FLAG(2) == 1) {
        return;
    }
    SI_MAP_FLAG(2) = 1;
    SI_VAR(15) = 0;
    loop 12 {
        RandInt(80, SI_VAR(0));
        SI_VAR(0) -= 40;
        RandInt(50, SI_VAR(1));
        RandInt(50, SI_VAR(2));
        SI_VAR(2) -= 25;
        PlayEffect(0x0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 5, 10, 1, 1, 0, 0, 0, 0, 0, 0);
        SI_VAR(15) += 1;
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(14), 1.0, 1.09375, 2, 0, 0);
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(13), 1.09375, 1.0, 2, 0, 0);
        SI_VAR(0) = (float) SI_VAR(14);
        SI_VAR(1) = (float) SI_VAR(13);
        SI_VAR(2) = (float) SI_VAR(14);
        if (SI_SAVE_VAR(252) == 0) {
            ScaleModel(31, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(32, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
        if (SI_SAVE_VAR(253) == 0) {
            ScaleModel(19, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(20, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
        if (SI_SAVE_VAR(252) <= 1) {
            ScaleModel(21, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
        if (SI_SAVE_VAR(252) <= 2) {
            if (SI_SAVE_VAR(253) <= 1) {
                ScaleModel(22, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(23, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(24, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(25, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(26, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            }
        }
        ScaleModel(27, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_SAVE_VAR(252) <= 2) {
            if (SI_SAVE_VAR(253) <= 2) {
                ScaleModel(29, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(41, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                ScaleModel(33, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            }
        }
        ScaleModel(36, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(37, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(38, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(39, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(40, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(34, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) -= 1.046875;
        SI_VAR(0) *= 100.0;
        if (SI_SAVE_VAR(252) == 0) {
            RotateModel(31, SI_VAR(0), 0, 0, 1);
            RotateModel(32, SI_VAR(0), 0, 0, 1);
        }
        if (SI_SAVE_VAR(253) == 0) {
            RotateModel(19, SI_VAR(0), 0, 0, 1);
            RotateModel(20, SI_VAR(0), 0, 0, 1);
        }
        if (SI_SAVE_VAR(252) <= 1) {
            RotateModel(21, SI_VAR(0), 0, 0, 1);
        }
        if (SI_SAVE_VAR(252) <= 2) {
            if (SI_SAVE_VAR(253) <= 1) {
                RotateModel(22, SI_VAR(0), 0, 0, 1);
                RotateModel(23, SI_VAR(0), 0, 0, 1);
                RotateModel(24, SI_VAR(0), 0, 0, 1);
                RotateModel(25, SI_VAR(0), 0, 0, 1);
                RotateModel(26, SI_VAR(0), 0, 0, 1);
            }
        }
        RotateModel(27, SI_VAR(0), 0, 0, 1);
        if (SI_SAVE_VAR(252) <= 2) {
            if (SI_SAVE_VAR(253) <= 2) {
                RotateModel(29, SI_VAR(0), 0, 0, 1);
                RotateModel(41, SI_VAR(0), 0, 0, 1);
                RotateModel(33, SI_VAR(0), 0, 0, 1);
            }
        }
        RotateModel(36, SI_VAR(0), 0, 0, 1);
        RotateModel(37, SI_VAR(0), 0, 0, 1);
        RotateModel(38, SI_VAR(0), 0, 0, 1);
        RotateModel(39, SI_VAR(0), 0, 0, 1);
        RotateModel(40, SI_VAR(0), 0, 0, 1);
        RotateModel(34, SI_VAR(0), 0, 0, 1);
        sleep 1;
    }
    SI_VAR(0) = (float) 1;
    SI_VAR(1) = (float) 1;
    SI_VAR(2) = (float) 1;
    if (SI_SAVE_VAR(252) == 0) {
        ScaleModel(31, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(32, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    }
    if (SI_SAVE_VAR(253) == 0) {
        ScaleModel(19, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        ScaleModel(20, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    }
    if (SI_SAVE_VAR(252) <= 1) {
        ScaleModel(21, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    }
    if (SI_SAVE_VAR(252) <= 2) {
        if (SI_SAVE_VAR(253) <= 1) {
            ScaleModel(22, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(23, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(24, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(25, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(26, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
    }
    ScaleModel(27, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_SAVE_VAR(252) <= 2) {
        if (SI_SAVE_VAR(253) <= 2) {
            ScaleModel(29, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(41, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            ScaleModel(33, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        }
    }
    ScaleModel(36, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ScaleModel(37, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ScaleModel(38, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ScaleModel(39, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ScaleModel(40, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ScaleModel(34, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    SI_MAP_FLAG(2) = 0;
});

/*
Script N(80241ED4) = SCRIPT({
    SI_VAR(0) = 0;
    SI_VAR(1) = 0;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1.0;
    SI_VAR(4) = 0.0;
    SI_VAR(5) = 3.0;
    spawn {
        sleep 10;
        PlaySoundAtCollider(19, 486, 0);
    }
    loop 300 {
        SI_VAR(4) += -0.5;
        SI_VAR(5) += 0.09375;
        SI_VAR(0) += (float) SI_VAR(3);
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(1) < -10) {
            SI_VAR(1) = -10.0;
            SI_VAR(3) = 0.0;
            SI_VAR(4) = 0.0;
            if (SI_VAR(2) >= 80) {
                goto 0;
            }
        }
    }
    TranslateModel(31, -78, 19, 2);
    TranslateModel(32, -78, 19, 2);
    TranslateModel(31, SI_VAR(0), SI_VAR(1), 0);
    TranslateModel(32, SI_VAR(0), SI_VAR(1), 0);
    RotateModel(31, SI_VAR(2), 0, 0, 1);
    RotateModel(32, SI_VAR(2), 0, 0, 1);
    TranslateModel(31, 78, -19, -2);
    TranslateModel(32, 78, -19, -2);
    sleep 1;
}
0:
    sleep 30;
    ModifyColliderFlags(0, 19, 0x7FFFFE00);
});
*/
// *INDENT-OFF*
Script N(80241ED4) = {
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(0), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(2), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(3), SI_FIXED(-1.0)),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(4), SI_FIXED(0.0)),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(5), SI_FIXED(3.0)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtCollider, 19, 486, 0),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_LOOP, 300),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(4), SI_FIXED(-0.5)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(5), SI_FIXED(0.09375)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(0), SI_VAR(3)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(1), SI_VAR(4)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(2), SI_VAR(5)),
        SI_CMD(ScriptOpcode_IF_LT, SI_VAR(1), -10),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(1), SI_FIXED(-10.0)),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(3), SI_FIXED(0.0)),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(4), SI_FIXED(0.0)),
            SI_CMD(ScriptOpcode_IF_GE, SI_VAR(2), 80),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 31, -78, 19, 2),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 32, -78, 19, 2),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 31, SI_VAR(0), SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 32, SI_VAR(0), SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_CALL, RotateModel, 31, SI_VAR(2), 0, 0, 1),
    SI_CMD(ScriptOpcode_CALL, RotateModel, 32, SI_VAR(2), 0, 0, 1),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 31, 78, -19, -2),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 32, 78, -19, -2),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
SI_CMD(ScriptOpcode_END_LOOP),
SI_CMD(ScriptOpcode_LABEL, 0),
SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
SI_CMD(ScriptOpcode_CALL, ModifyColliderFlags, 0, 19, 0x7FFFFE00),
SI_CMD(ScriptOpcode_RETURN),
SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(80242174) = SCRIPT({
    SI_VAR(0) = (float) 0;
    SI_VAR(1) = (float) 0;
    SI_VAR(2) = (float) 0;
    SI_VAR(3) = 0.0;
    SI_VAR(4) = 0.0;
    SI_VAR(5) = -5.0;
    spawn {
        sleep 12;
        PlaySoundAtCollider(21, 487, 0);
    }
    loop 300 {
        SI_VAR(4) += -0.5;
        SI_VAR(0) += (float) SI_VAR(3);
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(2) < -45) {
            SI_VAR(5) = 5;
        }
        if (SI_VAR(2) > 0) {
            SI_VAR(2) = 0;
            SI_VAR(3) = 5;
        }
        if (SI_VAR(1) < -25) {
            SI_VAR(4) = 0;
            SI_VAR(1) = -25;
        }
        if (SI_VAR(0) > 90) {
            goto 0;
        }
        TranslateModel(19, 50, 28, 27);
        TranslateModel(20, 50, 28, 27);
        TranslateModel(19, 0, SI_VAR(1), 1);
        TranslateModel(20, 0, SI_VAR(1), 1);
        RotateModel(19, SI_VAR(0), 1, 0, 0);
        RotateModel(20, SI_VAR(0), 1, 0, 0);
        RotateModel(19, SI_VAR(2), 0, 0, 1);
        RotateModel(20, SI_VAR(2), 0, 0, 1);
        TranslateModel(19, -50, -28, -27);
        TranslateModel(20, -50, -28, -27);
        sleep 1;
    }
0:
    sleep 30;
});

Script N(80242474) = SCRIPT({
    SI_VAR(2) = (float) 0;
    SI_VAR(1) = (float) 0;
    SI_VAR(0) = (float) 0;
    SI_VAR(5) = 0.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(23, 487, 0);
    }
    loop 300 {
        SI_VAR(5) += 0.5;
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(2) >= 80) {
            SI_VAR(2) = (float) 80;
            SI_VAR(5) *= -0.5;
            if (SI_VAR(5) == 0) {
                goto 0;
            }
        }
        TranslateModel(21, -55, 5, 16);
        TranslateModel(21, SI_VAR(0), SI_VAR(1), 0);
        RotateModel(21, SI_VAR(2), 0, 0, 1);
        TranslateModel(21, 55, -5, -16);
        sleep 1;
    }
0:
    sleep 30;
});

Script N(80242620) = SCRIPT({
    SI_VAR(2) = (float) 0;
    SI_VAR(1) = (float) 0;
    SI_VAR(0) = (float) 0;
    SI_VAR(5) = 0.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(22, 487, 0);
    }
    loop 300 {
        SI_VAR(5) += 0.5;
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(2) >= 80) {
            SI_VAR(2) = (float) 80;
            SI_VAR(5) *= -0.5;
            if (SI_VAR(5) == 0) {
                goto 0;
            }
        }
        TranslateModel(24, 60, 0, 16);
        RotateModel(24, SI_VAR(2), 0, 0, -1);
        TranslateModel(24, -60, 0, -16);
        TranslateModel(22, 0, 0, 27);
        TranslateModel(23, 0, 0, 27);
        RotateModel(22, SI_VAR(2), 1, 0, 0);
        RotateModel(23, SI_VAR(2), 1, 0, 0);
        TranslateModel(22, 0, 0, -27);
        TranslateModel(23, 0, 0, -27);
        TranslateModel(25, 0, 0, -41);
        TranslateModel(26, 0, 0, -41);
        RotateModel(25, SI_VAR(2), -1, 0, 0);
        RotateModel(26, SI_VAR(2), -1, 0, 0);
        TranslateModel(25, 0, 0, 41);
        TranslateModel(26, 0, 0, 41);
        sleep 1;
    }
0:
    sleep 30;
});

/*
Script N(80242910) = SCRIPT({
    SI_VAR(0) = 0;
    SI_VAR(1) = 0;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1.0;
    SI_VAR(4) = 0.0;
    SI_VAR(5) = 3.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(18, 486, 0);
    }
    loop 300 {
        SI_VAR(4) += -0.5;
        SI_VAR(5) += 0.09375;
        SI_VAR(0) += (float) SI_VAR(3);
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(1) < -25) {
            SI_VAR(1) = -25.0;
            SI_VAR(3) = 0.0;
            SI_VAR(4) = 0.0;
            if (SI_VAR(2) >= 80) {
                goto 0;
            }
        }
    }
    TranslateModel(29, 124, 17, 3);
    TranslateModel(29, SI_VAR(0), SI_VAR(1), 0);
    RotateModel(29, SI_VAR(2), 0, 0, -1);
    TranslateModel(29, -124, -17, -3);
    sleep 1;
}
0:
});
*/
// *INDENT-OFF*
Script N(80242910) = {
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(0), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(2), 0),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(3), SI_FIXED(-1.0)),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(4), SI_FIXED(0.0)),
    SI_CMD(ScriptOpcode_SET_F, SI_VAR(5), SI_FIXED(3.0)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtCollider, 18, 486, 0),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_LOOP, 300),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(4), SI_FIXED(-0.5)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(5), SI_FIXED(0.09375)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(0), SI_VAR(3)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(1), SI_VAR(4)),
        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(2), SI_VAR(5)),
        SI_CMD(ScriptOpcode_IF_LT, SI_VAR(1), -25),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(1), SI_FIXED(-25.0)),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(3), SI_FIXED(0.0)),
            SI_CMD(ScriptOpcode_SET_F, SI_VAR(4), SI_FIXED(0.0)),
            SI_CMD(ScriptOpcode_IF_GE, SI_VAR(2), 80),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 29, 124, 17, 3),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 29, SI_VAR(0), SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_CALL, RotateModel, 29, SI_VAR(2), 0, 0, -1),
    SI_CMD(ScriptOpcode_CALL, TranslateModel, 29, -124, -17, -3),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
SI_CMD(ScriptOpcode_END_LOOP),
SI_CMD(ScriptOpcode_LABEL, 0),
SI_CMD(ScriptOpcode_RETURN),
SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(80242B18) = SCRIPT({
    ModifyColliderFlags(0, 18, 0x7FFFFE00);
    SI_VAR(0) = (float) 0;
    SI_VAR(1) = (float) 0;
    SI_VAR(2) = (float) 0;
    SI_VAR(3) = 3.0;
    SI_VAR(4) = 1.0;
    SI_VAR(5) = 5.0;
    spawn {
        sleep 15;
        PlaySoundAtCollider(20, 486, 0);
    }
    loop 300 {
        SI_VAR(4) += -0.5;
        SI_VAR(0) += (float) SI_VAR(3);
        SI_VAR(1) += (float) SI_VAR(4);
        SI_VAR(2) += (float) SI_VAR(5);
        if (SI_VAR(1) <= -40) {
            SI_VAR(1) = (float) -40;
            SI_VAR(4) *= -0.5;
            if (SI_VAR(4) <= 1) {
                goto 1;
            }
        }
        if (SI_VAR(2) >= 60) {
            SI_VAR(2) = (float) 60;
            SI_VAR(5) = (float) 0;
        }
        TranslateModel(41, -34, 50, 10);
        TranslateModel(33, -34, 50, 10);
        TranslateModel(41, 0, SI_VAR(1), SI_VAR(0));
        RotateModel(41, SI_VAR(2), 0, 0, 1);
        TranslateModel(33, 0, SI_VAR(1), SI_VAR(0));
        RotateModel(33, SI_VAR(2), 0, 0, 1);
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

// *INDENT-OFF*
Script N(80242E28) = {
    SI_CMD(ScriptOpcode_SET, SI_VAR(10), SI_VAR(0)),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
    SI_CMD(ScriptOpcode_IF_LT, SI_VAR(0), -210),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 485),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802413F0)),
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), SI_VAR(10)),
    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 52),
        SI_CMD(ScriptOpcode_SET, SI_MAP_FLAG(1), 1),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_FLAG(3), 1),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_SET, SI_MAP_FLAG(3), 1),
    SI_CMD(ScriptOpcode_IF_GT, SI_VAR(0), 2),
        SI_CMD(ScriptOpcode_GOTO, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 2),
        SI_CMD(ScriptOpcode_GOTO, 11),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LABEL, 11),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(252), 0),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(252), 1),
            SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80241ED4)),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 1),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(253), 0),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(253), 1),
            SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80242174)),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(252), 1),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(252), 2),
            SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80242474)),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(252), 2),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(253), 1),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(253), 2),
            SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80242620)),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(252), 2),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(253), 2),
            SI_CMD(ScriptOpcode_CALL, DisablePlayerInput, 1),
            SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, 40, 0, 0),
            SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, 40, 0, 0),
            SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(1.5)),
            SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(253), 3),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802413F0)),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802413F0)),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802413F0)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
            SI_CMD(ScriptOpcode_CALL, GetModelCenter, 27),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 29, 0, SI_VAR(0), 50, SI_VAR(2), 100, 20, 0, 30, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 29, 0, SI_VAR(0), 30, SI_VAR(2), 120, 20, 0, 30, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 29, 0, SI_VAR(0), 10, SI_VAR(2), 100, 20, 0, 30, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
            SI_CMD(ScriptOpcode_SPAWN_THREAD),
                SI_CMD(ScriptOpcode_SET, SI_VAR(3), 6),
                SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80242DC8)),
                SI_CMD(ScriptOpcode_LOOP, 8),
                    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAt, 400, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
                    SI_CMD(ScriptOpcode_CALL, PlayEffect, 39, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 6, 0, 0, 0, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(1), 5),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAt, 400, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
                    SI_CMD(ScriptOpcode_CALL, PlayEffect, 39, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 2, 15, 0, 0, 0, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(3)),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(3), 1),
                SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_SET_F, SI_VAR(4), SI_FIXED(2.0)),
                SI_CMD(ScriptOpcode_LOOP, 2),
                    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80242DC8)),
                    SI_CMD(ScriptOpcode_LOOP, 8),
                        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
                        SI_CMD(ScriptOpcode_CALL, PlaySoundAt, 400, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
                        SI_CMD(ScriptOpcode_CALL, PlayEffect, 39, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 25, 0, 0, 0, 0, 0, 0, 0),
                        SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(3)),
                        SI_CMD(ScriptOpcode_ADD, SI_VAR(3), SI_VAR(4)),
                        SI_CMD(ScriptOpcode_ADD_F, SI_VAR(4), SI_FIXED(0.5)),
                    SI_CMD(ScriptOpcode_END_LOOP),
                SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, PlaySoundAt, 416, 0, 70, 40, 10),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 36, 0, 70, 40, 10, SI_FIXED(3.0), 30, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 0, 0, 20, SI_FIXED(1.0)),
            SI_CMD(ScriptOpcode_CALL, PlaySoundAt, 416, 0, 0, 30, 30),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 36, 0, 0, 30, 30, SI_FIXED(4.0), 40, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 0, 0, 20, SI_FIXED(2.0)),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80242910)),
            SI_CMD(ScriptOpcode_CALL, PlaySoundAtCollider, 20, 1169, 0),
            SI_CMD(ScriptOpcode_CALL, FadeOutMusic, 0, 1000),
            SI_CMD(ScriptOpcode_CALL, DisablePlayerPhysics, 1),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80242B18)),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(0), 53),
            SI_CMD(ScriptOpcode_CALL, GotoMap, "flo_15", 1),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 70),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_LABEL, 0),
    SI_CMD(ScriptOpcode_SET, SI_MAP_FLAG(3), 0),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Vec4f N(triggerCoord_8024367C) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_8024368C) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_8024369C) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802436AC) = { 105.0f, 0.0f, -10.0, 0.0f };

Script N(802436BC) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
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
    if (SI_SAVE_VAR(252) >= 1) {
        ModifyColliderFlags(0, 19, 0x7FFFFE00);
        EnableModel(31, 0);
        EnableModel(32, 0);
    }
    if (SI_SAVE_VAR(253) >= 1) {
        EnableModel(19, 0);
        EnableModel(20, 0);
    }
    if (SI_SAVE_VAR(252) >= 2) {
        EnableModel(21, 0);
    }
    if (SI_SAVE_VAR(253) >= 2) {
        EnableModel(22, 0);
        EnableModel(23, 0);
        EnableModel(24, 0);
        EnableModel(25, 0);
        EnableModel(26, 0);
    }
    if (SI_SAVE_VAR(253) >= 3) {
        EnableModel(29, 0);
        EnableModel(41, 0);
        EnableModel(33, 0);
        ModifyColliderFlags(0, 18, 0x7FFFFE00);
        return;
    }
    SI_VAR(0) = 0;
    bind N(80242E28) to TRIGGER_WALL_HAMMER 23;
    bind N(80242E28) to TRIGGER_POINT_BOMB N(triggerCoord_8024367C);
    bind N(80242E28) to TRIGGER_POINT_BOMB N(triggerCoord_8024368C);
    SI_VAR(0) = 1;
    bind N(80242E28) to TRIGGER_WALL_HAMMER 22;
    bind N(80242E28) to TRIGGER_POINT_BOMB N(triggerCoord_8024369C);
    bind N(80242E28) to TRIGGER_POINT_BOMB N(triggerCoord_802436AC);
    SI_VAR(0) = 3;
    bind N(80242E28) to TRIGGER_WALL_HAMMER 19;
    SI_VAR(0) = 4;
    bind N(80242E28) to TRIGGER_WALL_HAMMER 18;
    SI_VAR(0) = 0;
    loop 16 {
        SI_VAR(1) = SI_VAR(0);
        SI_VAR(1) += 10000;
        SI_VAR(0) += 1;
        CloneModel(49, SI_VAR(1));
        EnableModel(SI_VAR(1), 0);
    }
    spawn N(80241284);
    EnableTexPanning(36, 1);
    EnableTexPanning(37, 1);
    EnableTexPanning(38, 1);
    EnableTexPanning(39, 1);
    EnableTexPanning(40, 1);
    EnableTexPanning(41, 1);
    spawn {
        SI_VAR(14) = 1.0;
0:
        if (SI_SAVE_VAR(253) >= 3) {
            SI_VAR(14) *= 0.953125;
        }
        SI_VAR(15) += (float) SI_VAR(14);
        if (SI_VAR(15) == 1080) {
            SI_VAR(15) = (float) 0;
        }
        SI_VAR(0) = SI_VAR(15);
        SI_VAR(0) /= 9;
        SI_VAR(0) %= 4;
        SI_VAR(0) *= 16384;
        SI_VAR(1) = SI_VAR(15);
        SI_VAR(1) /= 4;
        SI_VAR(1) %= 2;
        SI_VAR(1) *= 16384;
        SI_VAR(2) = SI_VAR(15);
        SI_VAR(2) /= 5;
        SI_VAR(2) %= 2;
        SI_VAR(2) *= 16384;
        SI_VAR(3) = SI_VAR(15);
        SI_VAR(3) /= 6;
        SI_VAR(3) %= 2;
        SI_VAR(3) *= 16384;
        SI_VAR(4) = SI_VAR(15);
        SI_VAR(4) /= 2;
        SI_VAR(4) %= 2;
        SI_VAR(4) *= 32768;
        SI_VAR(5) = SI_VAR(15);
        SI_VAR(5) /= 8;
        SI_VAR(5) %= 2;
        SI_VAR(5) *= 16384;
        SetTexPanOffset(12, 0, SI_VAR(0), 0);
        SetTexPanOffset(13, 0, SI_VAR(1), 0);
        SetTexPanOffset(14, 0, SI_VAR(2), 0);
        SetTexPanOffset(15, 0, SI_VAR(3), 0);
        SetTexPanOffset(11, 0, SI_VAR(4), 0);
        SetTexPanOffset(10, 0, SI_VAR(5), 0);
        SetTexPanOffset(9, 0, SI_VAR(5), 0);
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

Script N(80244058) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetPlayerPos(30, 0, 50);
    InterpPlayerYaw(90, 0);
    SetNpcPos(NPC_PARTNER, 65, 0, 50);
    sleep 30;
    AdjustCam(0, 8.0, 0, 300, 19.0, -8.5);
    GetCurrentPartnerID(SI_VAR(0));
    BringPartnerOut(8);
    if (SI_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SI_VAR(1) += 20;
        SI_VAR(2) += 20;
        SI_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, SI_VAR(1), SI_VAR(2), SI_VAR(3), 30);
    }
    PlayerFaceNpc(-4, 0);
    NpcFacePlayer(NPC_PARTNER, 0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 5, MESSAGE_ID(0x11, 0x00C9));
    SetPlayerAnimation(ANIM_NOD_YES);
    sleep 10;
    SetPlayerAnimation(ANIM_STAND_STILL);
    sleep 20;
    EnablePartnerAI();
    PutPartnerAway();
    ResetCam(0, 4.0);
    DisablePlayerInput(FALSE);
});

Script N(80244270) = SCRIPT({
    spawn {
        PlaySoundAtNpc(NPC_FLYING_MAGIKOOPA, 0x19E, 0);
        SetNpcFlagBits(NPC_FLYING_MAGIKOOPA, ((NPC_FLAG_100)), TRUE);
        InterpNpcYaw(NPC_FLYING_MAGIKOOPA, 270, 0);
        LoadPath(60, N(vectorList_80243F68), 5, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_FLYING_MAGIKOOPA, SI_VAR(1), SI_VAR(2), SI_VAR(3));
            sleep 1;
            if (SI_VAR(0) != 1) {
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
            SetNpcPos(NPC_LAKITU0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
            sleep 1;
            if (SI_VAR(0) != 1) {
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
            SetNpcPos(NPC_LAKITU1, SI_VAR(1), SI_VAR(2), SI_VAR(3));
            sleep 1;
            if (SI_VAR(0) != 1) {
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
        SetNpcPos(NPC_LAKITU2, SI_VAR(1), SI_VAR(2), SI_VAR(3));
        sleep 1;
        if (SI_VAR(0) != 1) {
            break loop;
        }
    }
});

Script N(802445D4) = SCRIPT({
    sleep 5;
    IsPlayerWithin(40, 0, 200, SI_VAR(0));
    if (SI_VAR(0) == 0) {
        SI_VAR(3) = 45;
    } else {
        SI_VAR(3) = 25;
    }
    SI_VAR(4) = SI_VAR(3);
    SI_VAR(4) += -5;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(2) > -61) {
        parallel {
            SetNpcFlagBits(NPC_LAKITU0, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU0, SI_VAR(0), 55, SI_VAR(3));
        }
        parallel {
            SetNpcFlagBits(NPC_LAKITU1, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU1, SI_VAR(0), 55, SI_VAR(3));
        }
        parallel {
            SetNpcFlagBits(NPC_LAKITU2, ((NPC_FLAG_100)), TRUE);
            NpcMoveTo(NPC_LAKITU2, SI_VAR(0), 55, SI_VAR(3));
        }
        sleep SI_VAR(4);
    }
});

Script N(80244774) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetNpcPos(NPC_PARTNER, 65, SI_VAR(1), 80);
    SetNpcYaw(NPC_PARTNER, 270);
    AdjustCam(0, 8.0, 0, 450, 17.0, -6.0);
    SpeakToPlayer(NPC_FLYING_MAGIKOOPA, NPC_ANIM(flying_magikoopa, Palette_02, Anim_9), NPC_ANIM(flying_magikoopa, Palette_02, Anim_1), 0, MESSAGE_ID(0x11, 0x00BB));
    sleep 20;
    spawn N(80244270);
    sleep 80;
    AdjustCam(0, 8.0, 0, 300, 19.0, -8.5);
    GetCurrentPartnerID(SI_VAR(0));
    BringPartnerOut(8);
    if (SI_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SI_VAR(1) += 20;
        SI_VAR(2) += 20;
        SI_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, SI_VAR(1), SI_VAR(2), SI_VAR(3), 30);
    }
    NpcFacePlayer(NPC_PARTNER, 0);
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 5, MESSAGE_ID(0x11, 0x00C1));
    EnablePartnerAI();
    sleep 20;
    PutPartnerAway();
    ResetCam(0, 4.0);
    STORY_PROGRESS = STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS;
    DisablePlayerInput(FALSE);
    AwaitPlayerApproach(-250, 0, 50);
    DisablePlayerInput(TRUE);
    GetCurrentPartnerID(SI_VAR(0));
    BringPartnerOut(8);
    if (SI_VAR(0) != 8) {
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SI_VAR(1) += 20;
        SI_VAR(2) += 20;
        SI_VAR(3) += 20;
        NpcJump0(NPC_PARTNER, SI_VAR(1), SI_VAR(2), SI_VAR(3), 30);
    }
    PlayerFaceNpc(-4, 0);
    NpcFacePlayer(NPC_PARTNER, 0);
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 5, MESSAGE_ID(0x11, 0x00C2));
    EnablePartnerAI();
    PutPartnerAway();
    ResetCam(0, 4.0);
    DisablePlayerInput(FALSE);
});

Script N(idle_80244B3C) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) != 0) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 1000);
    SetCamPitch(0, 17.0, -6.0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    DisablePlayerInput(FALSE);
    StartBossBattle(3);
});

Script N(defeat_80244C84) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            GetSelfNpcID(SI_VAR(0));
            if (SI_VAR(0) == 3) {
                SetNpcPos(NPC_MAGIKOOPA, 0, -1000, 0);
                SetNpcPos(NPC_FLYING_MAGIKOOPA, -55, 15, 35);
                GetNpcYaw(3, SI_VAR(0));
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

Script N(80244E2C) = SCRIPT({
    match SI_MAP_VAR(10) {
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

Script N(80244ED0) = SCRIPT({
    match SI_MAP_VAR(10) {
        == 0 {
            SpeakToPlayer(NPC_MAGIKOOPA, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 16, MESSAGE_ID(0x11, 0x00B9));
            InterpNpcYaw(NPC_MAGIKOOPA, 90, 0);
        }
        == 1 {
            SpeakToPlayer(NPC_LAKITU0, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU0, 90, 0);
        }
        == 2 {
            SpeakToPlayer(NPC_LAKITU1, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU1, 270, 0);
        }
        == 3 {
            SpeakToPlayer(NPC_LAKITU2, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00BF));
            InterpNpcYaw(NPC_LAKITU2, 270, 0);
        }
    }
});

Script N(80245004) = SCRIPT({
    match SI_MAP_VAR(10) {
        == 0 {
            SpeakToPlayer(NPC_MAGIKOOPA, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 16, MESSAGE_ID(0x11, 0x00BA));
        }
        == 1 {
            SpeakToPlayer(NPC_LAKITU0, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00C0));
        }
        == 2 {
            SpeakToPlayer(NPC_LAKITU1, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00C0));
        }
        == 3 {
            SpeakToPlayer(NPC_LAKITU2, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 16, MESSAGE_ID(0x11, 0x00C0));
        }
    }
    SetNpcVar(3, 0, 1);
    sleep 5;
    spawn N(802445D4);
});

Script N(80245108) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        return;
    }
    DisablePlayerInput(TRUE);
    func_802D2C14(1);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    AdjustCam(0, 8.0, 0, 300, 17.0, -6.0);
    await N(80244E2C);
    match SI_AREA_VAR(7) {
        == 0 {
            await N(80244ED0);
            SI_AREA_VAR(7) += 1;
            ResetCam(0, 4.0);
        }
        == 1 {
            await N(80245004);
        }
    }
    func_802D2C14(0);
    DisablePlayerInput(FALSE);
});

Script N(80245228) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 0;
        await N(80245108);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(8024527C) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 1;
        await N(80245108);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(802452D0) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 2;
        await N(80245108);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(80245324) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 3;
        await N(80245108);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(80245378) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        return;
    }
    DisablePlayerInput(TRUE);
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 8.0);
    SetCamPitch(0, 17.0, -6.0);
    SetCamDistance(0, 300);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    await N(80244E2C);
    if (SI_AREA_VAR(7) == 0) {
        await N(80244ED0);
        SI_AREA_VAR(7) += 1;
        ResetCam(0, 4.0);
    } else {
        await N(80245004);
    }
    DisablePlayerInput(FALSE);
});

Script N(802454D4) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 0;
        GetNpcPos(NPC_MAGIKOOPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        await N(80245378);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(80245544) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 1;
        GetNpcPos(NPC_LAKITU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        await N(80245378);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(802455B4) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 2;
        GetNpcPos(NPC_LAKITU1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        await N(80245378);
        SI_MAP_VAR(10) = -1;
    }
});

Script N(80245624) = SCRIPT({
    if (SI_MAP_VAR(10) == -1) {
        SI_MAP_VAR(10) = 3;
        GetNpcPos(NPC_LAKITU2, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        await N(80245378);
        SI_MAP_VAR(10) = -1;
    }
});

Vec4f N(triggerCoord_80245694) = { 5.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456A4) = { -5.0f, 0.0f, -20.0f, 0.0f };

Vec4f N(triggerCoord_802456B4) = { 50.0f, 0.0f, -10.0, 0.0f };

Vec4f N(triggerCoord_802456C4) = { 105.0f, 0.0f, -10.0, 0.0f };

Script N(802456D4) = SCRIPT({
    SI_MAP_VAR(10) = -1;
    bind N(80245228) to TRIGGER_WALL_HAMMER 23;
    bind N(80245228) to TRIGGER_WALL_HAMMER 19;
    bind N(802454D4) to TRIGGER_POINT_BOMB N(triggerCoord_802456A4);
    bind N(80245544) to TRIGGER_POINT_BOMB N(triggerCoord_80245694);
    bind N(802452D0) to TRIGGER_WALL_HAMMER 22;
    bind N(802455B4) to TRIGGER_POINT_BOMB N(triggerCoord_802456B4);
    bind N(80245324) to TRIGGER_WALL_HAMMER 18;
    bind N(80245624) to TRIGGER_POINT_BOMB N(triggerCoord_802456C4);
});

Script N(interact_802457D4) = SCRIPT({
    match SI_AREA_VAR(6) {
        == 0 {
            GetSelfNpcID(SI_VAR(0));
            if (SI_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 5,
                              MESSAGE_ID(0x11, 0x00B6));
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 5, MESSAGE_ID(0x11,
                              0x00BC));
            }
            SI_AREA_VAR(6) += 1;
        }
        == 1 {
            GetSelfNpcID(SI_VAR(0));
            if (SI_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 5,
                              MESSAGE_ID(0x11, 0x00B7));
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 5, MESSAGE_ID(0x11,
                              0x00BD));
            }
            SI_AREA_VAR(6) += 1;
        }
        == 2 {
            AdjustCam(0, 8.0, 0, 300, 19.0, -9.0);
            GetSelfNpcID(SI_VAR(0));
            if (SI_VAR(0) == 3) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 5,
                              MESSAGE_ID(0x11, 0x00B8));
                NpcFacePlayer(NPC_SELF, 0);
                sleep 15;
                EndSpeech(-1, NPC_ANIM(magikoopa, Palette_02, Anim_2), NPC_ANIM(magikoopa, Palette_02, Anim_1), 0);
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 5, MESSAGE_ID(0x11,
                              0x00BE));
                NpcFacePlayer(NPC_SELF, 0);
                sleep 15;
                EndSpeech(-1, NPC_ANIM(lakitu, Palette_00, Anim_16), NPC_ANIM(lakitu, Palette_00, Anim_1), 0);
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

Script N(init_80245AA8) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcIdle(NPC_SELF, N(idle_80244B3C));
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

Script N(init_80245B30) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

Script N(init_80245B90) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

Script N(init_80245C04) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
        BindNpcInteract(NPC_SELF, N(interact_802457D4));
        BindNpcDefeat(NPC_SELF, N(defeat_80244C84));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

Script N(init_80245C78) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS) {
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
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_4),
            NPC_ANIM(magikoopa, Palette_02, Anim_4),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
            NPC_ANIM(magikoopa, Palette_02, Anim_1),
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
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_4),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_4),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
            NPC_ANIM(flying_magikoopa, Palette_02, Anim_1),
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

void func_80072950();

ApiStatus N(func_8024030C_CDC9AC)(ScriptInstance* script, s32 isInitialCall) {
    func_80072950(1, 0, 0, 0, 0, 0);
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

ApiStatus N(func_80240340_CDC9E0)(ScriptInstance* script, s32 isInitialCall) {
    N(temp)* ptr = script->varTable[15].s;

    ptr->unk_0C->unk_30 = 69;
    ptr->unk_0C->unk_34 = 255;
    ptr->unk_0C->unk_38 = 217;
    ptr->unk_0C->unk_40 = 176;
    ptr->unk_0C->unk_44 = 254;
    ptr->unk_0C->unk_48 = 124;
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"
