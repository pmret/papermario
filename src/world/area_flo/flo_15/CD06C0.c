#include "flo_15.h"
#include "message_ids.h"
#include "sprite/npc/sun.h"

enum {
    NPC_SUN0 = 10,
    NPC_SUN1,
};

EntryList N(entryList) = {
    {  320.0f, 0.0f,  0.0f, 270.0f },
    { -170.0f, 0.0f, 55.0f,   0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_15_tattle },
};

Script N(80240060) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        SetMusicTrack(0, SONG_SUNSHINE_RETURNS, 0, 8);
    } else {
        match STORY_PROGRESS {
            < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                SetMusicTrack(0, SONG_SUN_TOWER_CLOUDY, 0, 8);
            } else {
                SetMusicTrack(0, SONG_SUN_TOWER_SUNNY, 0, 8);
            }
        }
    }
});

static s32 N(pad_11C) = {
    0x00000000,
};

Script N(exitWalk_80240120) = EXIT_WALK_SCRIPT(60,  0, "flo_13",  1);

Script N(8024017C) = SCRIPT({
    bind N(exitWalk_80240120) to TRIGGER_FLOOR_ABOVE 0;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_802412C0));
    await N(makeEntities);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        spawn N(802404D8);
    } else {
        ModifyColliderFlags(0, 1, 0x7FFFFE00);
        SI_VAR(0) = N(8024017C);
        spawn EnterWalk;
    }
    ModifyColliderFlags(0, 14, 0x7FFFFE00);
    spawn N(802413B0);
    await N(80240060);
});

static s32 N(pad_2FC) = {
    0x00000000,
};

NpcSettings N(npcSettings_80240300) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

Script N(8024032C) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SI_VAR(3) = 7;
        SI_VAR(4) = 5;
    } else {
        SI_VAR(3) = 15;
        SI_VAR(4) = 1;
    }
    loop {
        SI_VAR(5) = SI_VAR(3);
        loop SI_VAR(5) {
            GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcPos(NPC_SUN1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep SI_VAR(4);
        }
        SI_VAR(5) = SI_VAR(3);
        loop SI_VAR(5) {
            GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += -1;
            SetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcPos(NPC_SUN1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep SI_VAR(4);
        }
    }
});

Script N(802404D8) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetNpcPos(NPC_SUN0, 0, 270, 0);
    SetNpcPos(NPC_SUN1, 0, -1000, 0);
    sleep 1;
    GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 1050);
    SetCamPitch(0, 10.0, 4.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SetCamDistance(0, 300);
    SetCamPitch(0, 15.0, -10.0);
    SetCamSpeed(0, 6.5);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_9), NPC_ANIM(sun, Palette_00, Anim_9), 517, MESSAGE_ID(0x11, 0x00C3));
    SetNpcAnimation(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_9));
    spawn {
        SetCamDistance(0, 1000);
        SetCamSpeed(0, 5.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
    }
    sleep 15;
    SetNpcJumpscale(NPC_SUN0, 0.0);
    GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 400;
    NpcJump0(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 40);
    GotoMap("flo_00", 9);
    sleep 70;
});

Script N(aux_8024079C) = SCRIPT({
    func_802CDE68(11, 48);
    loop {
        MakeLerp(-30, 30, 20, 11);
        loop {
            UpdateLerp();
            SetNpcRotation(NPC_SUN1, 0, 0, SI_VAR(0));
            GetNpcPos(NPC_SUN0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
            SetNpcPos(NPC_SUN1, SI_VAR(2), SI_VAR(3), SI_VAR(4));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        MakeLerp(30, -30, 20, 11);
        loop {
            UpdateLerp();
            SetNpcRotation(NPC_SUN1, 0, 0, SI_VAR(0));
            GetNpcPos(NPC_SUN0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
            SetNpcPos(NPC_SUN1, SI_VAR(2), SI_VAR(3), SI_VAR(4));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
});

Script N(8024094C) = SCRIPT({
    loop {
        sleep 1;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(1) > 220) {
            break loop;
        }
    }
    spawn {
        sleep 15;
        PlayerFaceNpc(10, 0);
    }
    SetNpcJumpscale(NPC_SUN0, 0.0);
    GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) -= 400;
    NpcJump0(NPC_SUN0, SI_VAR(0), 275, SI_VAR(2), 30);
    SI_VAR(9) = spawn N(8024032C);
    loop {
        sleep 1;
        if (SI_AREA_FLAG(38) == 1) {
            break loop;
        }
    }
    DisablePlayerInput(TRUE);
    sleep 10;
    kill SI_VAR(9);
    SetNpcFlagBits(NPC_SUN0, ((NPC_FLAG_100)), TRUE);
    GetNpcPos(NPC_SUN0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    NpcJump0(NPC_SUN0, SI_VAR(0), 450, SI_VAR(2), 30);
    DisablePlayerInput(FALSE);
    unbind;
});

Script N(interact_80240B28) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_SPOKE_WITH_THE_SUN {
            SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11, 0x009A));
            SetPlayerAnimation(ANIM_THINKING);
            sleep 20;
            SetPlayerAnimation(ANIM_80007);
            sleep 20;
            SetPlayerAnimation(ANIM_10002);
            SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11, 0x009B));
            STORY_PROGRESS = STORY_CH6_SPOKE_WITH_THE_SUN;
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11, 0x009C));
        }
        < STORY_CH6_STAR_SPIRIT_RESCUED {
            if (SI_SAVE_FLAG(1410) == 0) {
                SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11,
                              0x009D));
                SI_SAVE_FLAG(1410) = 1;
            } else {
                SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11,
                              0x009E));
            }
        } else {
            SpeakToPlayer(NPC_SUN0, NPC_ANIM(sun, Palette_00, Anim_7), NPC_ANIM(sun, Palette_00, Anim_1), 517, MESSAGE_ID(0x11,
                          0x009F));
        }
    }
    SI_AREA_FLAG(38) = 1;
});

Script N(init_80240CD0) = SCRIPT({
    SetNpcCollisionSize(10, 64, 40);
    EnableNpcShadow(NPC_SUN0, FALSE);
    if (STORY_PROGRESS < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SetNpcPos(NPC_SUN0, 0, 270, 0);
        BindNpcInteract(NPC_SELF, N(interact_80240B28));
        spawn N(8024032C);
    } else {
        SetNpcPos(NPC_SUN0, 0, 450, 0);
        BindNpcInteract(NPC_SELF, N(interact_80240B28));
        SI_AREA_FLAG(38) = 0;
        spawn N(8024094C);
    }
});

Script N(init_80240DB4) = SCRIPT({
    EnableNpcShadow(NPC_SUN1, FALSE);
    SetNpcAnimation(NPC_SUN1, NPC_ANIM(sun, Palette_00, Anim_2));
    SetNpcPaletteSwapMode(10, 3);
    SetNpcPaletteSwapMode(11, 3);
    SetNpcPaletteSwapping(10, 0, 1, 5, 5, 13, 5, 0, 0);
    SetNpcPaletteSwapping(11, 0, 1, 5, 5, 13, 5, 0, 0);
    if (STORY_PROGRESS < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SetNpcPos(NPC_SUN1, 0, 270, -5);
    } else {
        SetNpcPos(NPC_SUN1, 0, 450, -5);
        BindNpcAux(-1, N(aux_8024079C));
    }
});

StaticNpc N(npcGroup_80240EE0)[] = {
    {
        .id = NPC_SUN0,
        .settings = &N(npcSettings_80240300),
        .pos = { 0.0f, 250.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_400000,
        .init = &N(init_80240CD0),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E1),
    },
    {
        .id = NPC_SUN1,
        .settings = &N(npcSettings_80240300),
        .pos = { 0.0f, 250.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_8000,
        .init = &N(init_80240DB4),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
            NPC_ANIM(sun, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E1),
    },
};

NpcGroupList N(npcGroupList_802412C0) = {
    NPC_GROUP(N(npcGroup_80240EE0), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_12D8)[] = {
    0x00000000, 0x00000000,
};

Script N(802412E0) = SCRIPT({
    SI_SAVE_FLAG(1401) = 1;
});

Script N(makeEntities) = SCRIPT({
    if (SI_SAVE_FLAG(1401) == 0) {
        MakeEntity(0x802BCF00, -180, 0, -18, 0, MAKE_ENTITY_END);
        AssignScript(N(802412E0));
    }
});

static s32 N(pad_135C) = {
    0x00000000,
};

s32 N(intTable_80241360)[] = {
    0x0000000A, 0xF24A7CE7, 0x0000000D, 0xF24A7D80, 0x00000010, 0xF24A7E1A, 0x00000013, 0xF24A7EB4,
    0x00000016, 0xF24A7F4D, 0x00000019, 0xF24A7EB4, 0x00000018, 0xF24A7E1A, 0x00000019, 0xF24A7D80,
    0x00000018, 0xF24A7CE7, 0x0000000A, 0xF24A814D,
};

// *INDENT-OFF*
Script N(802413B0) = {
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1401), 0),
        SI_CMD(ScriptOpcode_LABEL, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1401), 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_GOTO, 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, DisablePlayerInput, 1),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80241360)),
            SI_CMD(ScriptOpcode_LOOP, 10),
                SI_CMD(ScriptOpcode_BUFFER_READ_2, SI_VAR(1), SI_VAR(2)),
                SI_CMD(ScriptOpcode_CALL, ShakeCam, 0, 0, SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, -170, 0, 35),
        SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, -170, 0, 35),
        SI_CMD(ScriptOpcode_CALL, SetCamDistance, 0, 600),
        SI_CMD(ScriptOpcode_CALL, SetCamPitch, 0, SI_FIXED(25.0), SI_FIXED(-9.0)),
        SI_CMD(ScriptOpcode_CALL, SetCamPosA, 0, SI_FIXED(-50.0), SI_FIXED(25.0)),
        SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(1.5)),
        SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
        SI_CMD(ScriptOpcode_CALL, WaitForCam, 0, SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 100),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 6, 4, -180, 0, -15, 0, 0, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 6, 4, -190, 0, -35, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_LOOP, 6),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtCollider, 11, 391, 0),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
            SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, MakeLerp, 0, -50, 120, 2),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_CALL, UpdateLerp),
            SI_CMD(ScriptOpcode_CALL, TranslateGroup, 16, 0, SI_VAR(0), 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(1), 0),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_CALL, ModifyColliderFlags, 0, 12, 2147483136),
        SI_CMD(ScriptOpcode_CALL, ModifyColliderFlags, 1, 14, 2147483136),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
        SI_CMD(ScriptOpcode_CALL, ResetCam, 0, SI_FIXED(90.0)),
        SI_CMD(ScriptOpcode_CALL, DisablePlayerInput, 0),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_CALL, ModifyColliderFlags, 0, 12, 2147483136),
        SI_CMD(ScriptOpcode_CALL, ModifyColliderFlags, 1, 14, 2147483136),
        SI_CMD(ScriptOpcode_CALL, TranslateGroup, 16, 0, -50, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*
