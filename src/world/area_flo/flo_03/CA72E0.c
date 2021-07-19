#include "flo_03.h"
#include "message_ids.h"
#include "sprite/npc/dayzee.h"
#include "sprite/npc/monty_mole.h"
#include "sprite/npc/petunia.h"

enum {
    NPC_PETUNIA,
    NPC_DAYZEE,
    NPC_MONTY_MOLE0,
    NPC_MONTY_MOLE1,
    NPC_MONTY_MOLE2,
    NPC_MONTY_MOLE3,
};

EntryList N(entryList) = {
    { -325.0f, 0.0f, 0.0f,  90.0f },
    {  325.0f, 0.0f, 0.0f, 270.0f },
    { -325.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_03_tattle },
};

Script N(802406A0) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 2) {
        SetMusicTrack(0, SONG_SUNSHINE_RETURNS, 0, 8);
    } else {
        match STORY_PROGRESS {
            <= STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
                if (SI_SAVE_FLAG(1411) == 0) {
                    SetMusicTrack(0, SONG_MONTY_MOLE_ASSAULT, 0, 8);
                } else {
                    SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
                }
            }
            < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
            } else {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
            }
        }
    }
});

Script N(802407C0) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES) {
        if (SI_SAVE_FLAG(1411) == 1) {
            PushSong(137, 0);
        }
    }
});

Script N(80240814) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES) {
        if (SI_SAVE_FLAG(1411) == 1) {
            FadeOutMusic(0, 250);
            sleep 10;
            PopSong();
        }
    }
});

Script N(80240880) = SCRIPT({
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

Script N(exitWalk_80240B2C) = EXIT_WALK_SCRIPT(60,  0, "flo_09",  1);

Script N(exitWalk_80240B88) = EXIT_WALK_SCRIPT(60,  1, "flo_22",  0);

Script N(80240BE4) = SCRIPT({
    bind N(exitWalk_80240B2C) TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80240B88) TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SI_AREA_FLAG(27) = 0;
    SI_AREA_FLAG(28) = 0;
    SI_AREA_VAR(1) = 0;
    MakeNpcs(0, N(npcGroupList_8024442C));
    await N(makeEntities);
    await N(80241EF4);
    spawn N(80244E54);
    spawn N(80244ED0);
    ModifyColliderFlags(3, 9, 0x00000006);
    SI_VAR(0) = -145;
    SI_VAR(1) = -335;
    SI_VAR(2) = 182;
    SI_VAR(3) = -180;
    SI_VAR(4) = 0;
    spawn N(80240880);
    SI_VAR(0) = 200;
    SI_VAR(1) = -170;
    SI_VAR(2) = 310;
    SI_VAR(3) = 150;
    SI_VAR(4) = 0;
    spawn N(80240880);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 2) {
        spawn N(80240FFC);
    } else {
        ModifyColliderFlags(0, 1, 0x7FFFFE00);
        SI_VAR(0) = N(80240BE4);
        spawn EnterWalk;
    }
    await N(802406A0);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CA72A0)();
    }
});

static s32 N(pad_EA4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240EB0) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80240EDC) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

s32** N(D_80240F08_CA81A8) = NULL;

Script N(80240F0C) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

Script N(80240F3C) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

s32 N(intTable_80240F6C)[] = {
    0xFFFFFF9C, 0x00000000, 0x000000D2, 0xFFFFFF60, 0x00000000, 0x0000011D, 0xFFFFFFDD, 0x00000000,
    0x00000131,
};

s32 N(intTable_80240F90)[] = {
    0xFFFFFF42, 0x00000000, 0x00000050, 0xFFFFFF7E, 0x00000000, 0x00000000, 0xFFFFFFBA, 0x00000000,
    0xFFFFFFC4,
};

s32 N(intTable_80240FB4)[] = {
    0x0000004B, 0x00000000, 0xFFFFFFF1, 0x00000023, 0x00000000, 0xFFFFFF9C, 0x00000082, 0x00000000,
    0x00000000,
};

s32 N(intTable_80240FD8)[] = {
    0x00000073, 0x00000000, 0x000000B4, 0x00000055, 0x00000000, 0x00000122, 0x00000091, 0x00000000,
    0x0000008C,
};

Script N(80240FFC) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetNpcYaw(NPC_PETUNIA, 90);
    GetNpcPos(NPC_PETUNIA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300);
    SetCamPitch(0, 17.0, -9.5);
    SetCamPosA(0, -27, 0);
    SetCamPosB(0, 0, -50);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 20;
    SpeakToPlayer(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00C8));
    SetNpcAnimation(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_3));
    sleep 10;
    GotoMap("flo_18", 1);
    sleep 100;
});

Script N(npcAI_8024119C) = SCRIPT({
    N(func_80240158_CA73F8)();
});

Script N(defeat_802411B8) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_SAVE_FLAG(1366) = 1;
            DoNpcDefeat();
        }
        == 1 {}
        == 2 {
        }
    }
});

Script N(8024122C) = SCRIPT({
    GetPlayerPos(SI_VAR(3), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(0) /= 2;
    SetCamProperties(0, SI_VAR(4), SI_VAR(0), SI_VAR(1), SI_VAR(2), 300, 20.0, -9.5);
});

Script N(interact_802412BC) = SCRIPT({
    await N(802407C0);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            SI_MAP_VAR(14) = 1;
            SI_VAR(4) = (int) 3.5;
            await N(8024122C);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0050));
            SetNpcAnimation(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_6));
            SetPlayerAnimation(ANIM_NOD_YES);
            sleep 20;
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0051));
            SetNpcAnimation(NPC_MONTY_MOLE0, NPC_ANIM(monty_mole, Palette_01, Anim_12));
            SetNpcYaw(NPC_MONTY_MOLE0, 270);
            GetNpcPos(NPC_MONTY_MOLE0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamSpeed(0, 90.0);
            SetCamPitch(0, 17.0, -8.0);
            SetCamDistance(0, 200);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            sleep 20;
            PlaySoundAtNpc(NPC_MONTY_MOLE0, SOUND_MOLE_SURFACE, 0);
            SetNpcAnimation(NPC_MONTY_MOLE0, NPC_ANIM(monty_mole, Palette_01, Anim_16));
            sleep 10;
            PlaySoundAtNpc(NPC_MONTY_MOLE0, 0x263, 0);
            ShowEmote(2, EMOTE_QUESTION, -45, 30, 1, 0, 0, 0, 0);
            GetNpcPos(NPC_MONTY_MOLE1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0052));
            SetNpcYaw(NPC_MONTY_MOLE1, 90);
            SetNpcPos(NPC_MONTY_MOLE1, 0, -1000, 0);
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 200);
            SetCamPitch(0, 17.0, -8.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            SetNpcAnimation(NPC_MONTY_MOLE1, NPC_ANIM(monty_mole, Palette_01, Anim_0));
            sleep 20;
            PlaySoundAtNpc(NPC_MONTY_MOLE1, SOUND_MOLE_SURFACE, 0);
            SetNpcPos(NPC_MONTY_MOLE1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcAnimation(NPC_MONTY_MOLE1, NPC_ANIM(monty_mole, Palette_01, Anim_10));
            sleep 20;
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0053));
            SetNpcYaw(NPC_MONTY_MOLE2, 270);
            GetNpcPos(NPC_MONTY_MOLE2, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 200);
            SetCamPitch(0, 17.0, -8.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            sleep 20;
            SetNpcAnimation(NPC_MONTY_MOLE2, NPC_ANIM(monty_mole, Palette_01, Anim_14));
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0054));
            SetNpcYaw(NPC_MONTY_MOLE3, 270);
            GetNpcPos(NPC_MONTY_MOLE3, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 200);
            SetCamPitch(0, 17.0, -9.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_6));
            sleep 20;
            SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_7));
            sleep 20;
            SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_8));
            sleep 20;
            SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_16));
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0055));
            SetNpcPos(NPC_DAYZEE, -233, 0, -217);
            GetNpcPos(NPC_DAYZEE, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 300);
            SetCamPitch(0, 17.0, -9.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            SetNpcAnimation(NPC_DAYZEE, NPC_ANIM(dayzee, Palette_00, Anim_D));
            PlaySoundAtNpc(NPC_DAYZEE, SOUND_UNKNOWN_262, 0);
            ShowEmote(1, EMOTE_EXCLAMATION, 45, 30, 1, 0, 0, 0, 0);
            sleep 15;
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0056));
            SI_VAR(4) = (int) 90.0;
            await N(8024122C);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0, MESSAGE_ID(0x11, 0x0057));
            SetEnemyFlagBits(1, 1, 0);
            SetEnemyFlagBits(2, 1, 0);
            SetEnemyFlagBits(3, 1, 0);
            SetEnemyFlagBits(4, 1, 0);
            SetEnemyFlagBits(5, 1, 0);
            BindNpcAI(NPC_DAYZEE, N(npcAI_8024119C));
            SI_MAP_VAR(14) = 0;
            SI_MAP_VAR(15) = 60;
            STORY_PROGRESS = STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES;
        }
        == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            if (SI_SAVE_FLAG(1411) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0,
                              MESSAGE_ID(0x11, 0x0058));
                SetNpcAnimation(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_6));
            } else {
                SI_VAR(4) = (int) 3.5;
                await N(8024122C);
                SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_8), NPC_ANIM(petunia, Palette_00, Anim_3), 0,
                              MESSAGE_ID(0x11, 0x0059));
                EndSpeech(-1, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0);
                SetNpcAnimation(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_4));
                sleep 20;
                SetNpcAnimation(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_1));
                SI_VAR(0) = 88;
                SI_VAR(1) = 1;
                await N(80240F0C);
                AddKeyItem(ITEM_MAGICAL_BEAN);
                sleep 20;
                SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x11, 0x005A));
                EndSpeech(-1, NPC_ANIM(petunia, Palette_00, Anim_7), NPC_ANIM(petunia, Palette_00, Anim_6), 0);
                STORY_PROGRESS = STORY_CH6_GOT_MAGICAL_BEAN;
            }
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x005B));
        }
        < STORY_CH6_RETURNED_TO_TOAD_TOWN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x005C));
        } else {
            if (SI_AREA_VAR(1) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x11, 0x005D));
                SI_AREA_VAR(1) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(petunia, Palette_00, Anim_2), NPC_ANIM(petunia, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x11, 0x005E));
            }
        }
    }
    ResetCam(0, 8.0);
    await N(80240814);
});

Script N(init_80241DA4) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802412BC));
    if (SI_SAVE_FLAG(1411) == 0) {
        SetNpcAnimation(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_6));
    } else {
        SetNpcAnimation(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_1));
    }
});

Script N(init_80241E10) = SCRIPT({
    BindNpcDefeat(NPC_SELF, N(defeat_802411B8));
    EnableNpcShadow(NPC_DAYZEE, FALSE);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            SetNpcPos(NPC_DAYZEE, 0, -1000, 0);
        } else {
            if (SI_SAVE_FLAG(1366) == 0) {
                SetEnemyFlagBits(1, 1, 0);
                BindNpcIdle(NPC_SELF, N(npcAI_8024119C));
            } else {
                SetNpcPos(NPC_DAYZEE, 0, -1000, 0);
            }
        }
    }
});

Script N(80241EF4) = SCRIPT({
    SI_MAP_VAR(14) = 0;
    SI_MAP_VAR(10) = 0;
    SI_MAP_VAR(11) = 0;
    SI_MAP_VAR(12) = 0;
    SI_MAP_VAR(13) = 0;
    SI_MAP_VAR(15) = 100;
});

Script N(defeat_80241F64) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            GetSelfNpcID(SI_VAR(0));
            match SI_VAR(0) {
                == 2 {
                    SI_SAVE_FLAG(1367) = 1;
                }
                == 3 {
                    SI_SAVE_FLAG(1368) = 1;
                }
                == 4 {
                    SI_SAVE_FLAG(1369) = 1;
                }
                == 5 {
                    SI_SAVE_FLAG(1370) = 1;
                }
            }
            SI_VAR(0) = 0;
            SI_VAR(0) += SI_SAVE_FLAG(1367);
            SI_VAR(0) += SI_SAVE_FLAG(1368);
            SI_VAR(0) += SI_SAVE_FLAG(1369);
            SI_VAR(0) += SI_SAVE_FLAG(1370);
            if (SI_VAR(0) != 4) {
                SetNpcAnimation(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_6));
            } else {
                SetNpcAnimation(NPC_PETUNIA, NPC_ANIM(petunia, Palette_00, Anim_1));
                SI_SAVE_FLAG(1411) = 1;
                await N(802406A0);
            }
            DoNpcDefeat();
        }
        == 1 {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(monty_mole, Palette_01, Anim_1));
        }
        == 2 {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(monty_mole, Palette_01, Anim_1));
        }
    }
});

Script N(hit_80242138) = SCRIPT({
    if (STORY_PROGRESS == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES) {
        GetOwnerEncounterTrigger(SI_VAR(0));
        if (SI_VAR(0) != 1) {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(monty_mole, Palette_01, Anim_5));
        }
    }
});

// *INDENT-OFF*
Script N(idle_8024219C) = {
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(10), 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(23), 1),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 1),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_LABEL, 0),
            SI_CMD(ScriptOpcode_CALL, GetNpcPos, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, IsPlayerWithin, SI_VAR(0), SI_VAR(2), SI_MAP_VAR(15), SI_VAR(3)),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, GetCurrentPartner, SI_VAR(9)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(9), 9),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(14), 1),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(3), 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(23), 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 2, 32840, 1),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 2, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(23), 1),
                SI_CMD(ScriptOpcode_IF_NE, SI_MAP_VAR(10), 0),
                    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 44),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 4),
                    SI_CMD(ScriptOpcode_ELSE),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 10),
                    SI_CMD(ScriptOpcode_END_IF),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 2, 610, 0),
                    SI_CMD(ScriptOpcode_CALL, ShowEmote, 2, 0, 0, SI_VAR(1), 1, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(1)),
                    SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 1),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 2, 802, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 2, 3080465),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1367), 0),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 2, 0, -50, 0),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 45),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(23), 1),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1367), 0),
                    SI_CMD(ScriptOpcode_CALL, RandInt, 2, SI_VAR(0)),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
                    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80240F6C)),
                    SI_CMD(ScriptOpcode_LOOP, SI_VAR(0)),
                        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                    SI_CMD(ScriptOpcode_END_LOOP),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 2, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 2, 32840, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(23), 0),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 2, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 2, 801, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 2, 3080464),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
                SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 0),
                SI_CMD(ScriptOpcode_CALL, RandInt, 30, SI_VAR(0)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 60),
                SI_CMD(ScriptOpcode_SET, SI_MAP_VAR(10), SI_VAR(0)),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_IF_GT, SI_MAP_VAR(10), 0),
                    SI_CMD(ScriptOpcode_SUB, SI_MAP_VAR(10), 1),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(idle_80242618) = {
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(11), 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(24), 1),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 1),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_LABEL, 0),
            SI_CMD(ScriptOpcode_CALL, GetNpcPos, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, IsPlayerWithin, SI_VAR(0), SI_VAR(2), SI_MAP_VAR(15), SI_VAR(3)),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, GetCurrentPartner, SI_VAR(9)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(9), 9),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(14), 1),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(3), 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(24), 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 3, 32840, 1),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 3, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(24), 1),
                SI_CMD(ScriptOpcode_IF_NE, SI_MAP_VAR(11), 0),
                    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 44),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 4),
                    SI_CMD(ScriptOpcode_ELSE),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 10),
                    SI_CMD(ScriptOpcode_END_IF),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 3, 610, 0),
                    SI_CMD(ScriptOpcode_CALL, ShowEmote, 3, 0, 0, SI_VAR(1), 1, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(1)),
                    SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 1),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 3, 802, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 3, 3080465),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1368), 0),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 3, 0, -50, 0),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 45),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(24), 1),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1368), 0),
                    SI_CMD(ScriptOpcode_CALL, RandInt, 2, SI_VAR(0)),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
                    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80240F90)),
                    SI_CMD(ScriptOpcode_LOOP, SI_VAR(0)),
                        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                    SI_CMD(ScriptOpcode_END_LOOP),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 3, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 3, 32840, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(24), 0),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 3, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 3, 801, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 3, 3080464),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
                SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 0),
                SI_CMD(ScriptOpcode_CALL, RandInt, 35, SI_VAR(0)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 55),
                SI_CMD(ScriptOpcode_SET, SI_MAP_VAR(11), SI_VAR(0)),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_IF_GT, SI_MAP_VAR(11), 0),
                    SI_CMD(ScriptOpcode_SUB, SI_MAP_VAR(11), 1),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(idle_80242A94) = {
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(12), 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(25), 1),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 1),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_LABEL, 0),
            SI_CMD(ScriptOpcode_CALL, GetNpcPos, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, IsPlayerWithin, SI_VAR(0), SI_VAR(2), SI_MAP_VAR(15), SI_VAR(3)),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, GetCurrentPartner, SI_VAR(9)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(9), 9),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(14), 1),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(3), 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(25), 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 4, 32840, 1),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 4, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(25), 1),
                SI_CMD(ScriptOpcode_IF_NE, SI_MAP_VAR(12), 0),
                    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 44),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 4),
                    SI_CMD(ScriptOpcode_ELSE),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 10),
                    SI_CMD(ScriptOpcode_END_IF),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 4, 610, 0),
                    SI_CMD(ScriptOpcode_CALL, ShowEmote, 4, 0, 0, SI_VAR(1), 1, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(1)),
                    SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 1),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 4, 802, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 3080465),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1369), 0),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 4, 0, -50, 0),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 45),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(25), 1),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1369), 0),
                    SI_CMD(ScriptOpcode_CALL, RandInt, 2, SI_VAR(0)),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
                    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80240FB4)),
                    SI_CMD(ScriptOpcode_LOOP, SI_VAR(0)),
                        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                    SI_CMD(ScriptOpcode_END_LOOP),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 4, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 4, 32840, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(25), 0),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 4, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 4, 801, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 3080464),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
                SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 0),
                SI_CMD(ScriptOpcode_CALL, RandInt, 40, SI_VAR(0)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 50),
                SI_CMD(ScriptOpcode_SET, SI_MAP_VAR(12), SI_VAR(0)),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_IF_GT, SI_MAP_VAR(12), 0),
                    SI_CMD(ScriptOpcode_SUB, SI_MAP_VAR(12), 1),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(idle_80242F10) = {
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(13), 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(26), 1),
                SI_CMD(ScriptOpcode_GOTO, 0),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 1),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_LABEL, 0),
            SI_CMD(ScriptOpcode_CALL, GetNpcPos, 5, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, IsPlayerWithin, SI_VAR(0), SI_VAR(2), SI_MAP_VAR(15), SI_VAR(3)),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, GetCurrentPartner, SI_VAR(9)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(9), 9),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_MAP_VAR(14), 1),
            SI_CMD(ScriptOpcode_SET, SI_VAR(3), 0),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(3), 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(26), 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 5, 32840, 1),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 5, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(26), 1),
                SI_CMD(ScriptOpcode_IF_NE, SI_MAP_VAR(13), 0),
                    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 44),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 4),
                    SI_CMD(ScriptOpcode_ELSE),
                        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 10),
                    SI_CMD(ScriptOpcode_END_IF),
                    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 5, 610, 0),
                    SI_CMD(ScriptOpcode_CALL, ShowEmote, 5, 0, 0, SI_VAR(1), 1, 0, 0, 0, 0),
                    SI_CMD(ScriptOpcode_SLEEP_FRAMES, SI_VAR(1)),
                    SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 1),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 5, 802, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 5, 3080465),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1370), 0),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 5, 0, -50, 0),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 45),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_IF_EQ, SI_AREA_FLAG(26), 1),
                SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1370), 0),
                    SI_CMD(ScriptOpcode_CALL, RandInt, 2, SI_VAR(0)),
                    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
                    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80240FD8)),
                    SI_CMD(ScriptOpcode_LOOP, SI_VAR(0)),
                        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                    SI_CMD(ScriptOpcode_END_LOOP),
                    SI_CMD(ScriptOpcode_CALL, SetNpcPos, 5, SI_VAR(1), SI_VAR(2), SI_VAR(3)),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 5, 32840, 1),
                SI_CMD(ScriptOpcode_SET, SI_AREA_FLAG(26), 0),
                SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, 5, 1),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
                SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 5, 801, 0),
                SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 5, 3080464),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
                SI_CMD(ScriptOpcode_CALL, SetSelfEnemyFlagBits, 386924544, 0),
                SI_CMD(ScriptOpcode_CALL, RandInt, 45, SI_VAR(0)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 45),
                SI_CMD(ScriptOpcode_SET, SI_MAP_VAR(13), SI_VAR(0)),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_IF_GT, SI_MAP_VAR(13), 0),
                    SI_CMD(ScriptOpcode_SUB, SI_MAP_VAR(13), 1),
                SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(init_8024338C) = SCRIPT({
    BindNpcHit(-1, N(hit_80242138));
    BindNpcDefeat(NPC_SELF, N(defeat_80241F64));
    EnableNpcShadow(NPC_MONTY_MOLE0, FALSE);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            BindNpcIdle(NPC_SELF, N(idle_8024219C));
            SetNpcAnimation(NPC_MONTY_MOLE0, NPC_ANIM(monty_mole, Palette_01, Anim_10));
        }
        == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            if (SI_SAVE_FLAG(1367) == 0) {
                BindNpcIdle(NPC_SELF, N(idle_8024219C));
                SetNpcAnimation(NPC_MONTY_MOLE0, NPC_ANIM(monty_mole, Palette_01, Anim_10));
                SetEnemyFlagBits(2, 1, 0);
            } else {
                SetNpcPos(NPC_MONTY_MOLE0, 0, -1000, 0);
            }
        } else {
            SetNpcPos(NPC_MONTY_MOLE0, 0, -1000, 0);
        }
    }
});

Script N(init_802434CC) = SCRIPT({
    BindNpcHit(-1, N(hit_80242138));
    BindNpcDefeat(NPC_SELF, N(defeat_80241F64));
    EnableNpcShadow(NPC_MONTY_MOLE1, FALSE);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            BindNpcIdle(NPC_SELF, N(idle_80242618));
            SetNpcAnimation(NPC_MONTY_MOLE1, NPC_ANIM(monty_mole, Palette_01, Anim_10));
        }
        == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            if (SI_SAVE_FLAG(1368) == 0) {
                BindNpcIdle(NPC_SELF, N(idle_80242618));
                SetNpcAnimation(NPC_MONTY_MOLE1, NPC_ANIM(monty_mole, Palette_01, Anim_10));
                SetEnemyFlagBits(3, 1, 0);
            } else {
                SetNpcPos(NPC_MONTY_MOLE1, 0, -1000, 0);
            }
        } else {
            SetNpcPos(NPC_MONTY_MOLE1, 0, -1000, 0);
        }
    }
});

Script N(init_8024360C) = SCRIPT({
    BindNpcHit(-1, N(hit_80242138));
    BindNpcDefeat(NPC_SELF, N(defeat_80241F64));
    EnableNpcShadow(NPC_MONTY_MOLE2, FALSE);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            BindNpcIdle(NPC_SELF, N(idle_80242A94));
            SetNpcAnimation(NPC_MONTY_MOLE2, NPC_ANIM(monty_mole, Palette_01, Anim_10));
        }
        == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            if (SI_SAVE_FLAG(1369) == 0) {
                BindNpcIdle(NPC_SELF, N(idle_80242A94));
                SetNpcAnimation(NPC_MONTY_MOLE2, NPC_ANIM(monty_mole, Palette_01, Anim_10));
                SetEnemyFlagBits(4, 1, 0);
            } else {
                SetNpcPos(NPC_MONTY_MOLE2, 0, -1000, 0);
            }
        } else {
            SetNpcPos(NPC_MONTY_MOLE2, 0, -1000, 0);
        }
    }
});

Script N(init_8024374C) = SCRIPT({
    BindNpcHit(-1, N(hit_80242138));
    BindNpcDefeat(NPC_SELF, N(defeat_80241F64));
    EnableNpcShadow(NPC_MONTY_MOLE3, FALSE);
    match STORY_PROGRESS {
        < STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            BindNpcIdle(NPC_SELF, N(idle_80242F10));
            SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_10));
        }
        == STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES {
            if (SI_SAVE_FLAG(1370) == 0) {
                BindNpcIdle(NPC_SELF, N(idle_80242F10));
                SetNpcAnimation(NPC_MONTY_MOLE3, NPC_ANIM(monty_mole, Palette_01, Anim_10));
                SetEnemyFlagBits(5, 1, 0);
            } else {
                SetNpcPos(NPC_MONTY_MOLE3, 0, -1000, 0);
            }
        } else {
            SetNpcPos(NPC_MONTY_MOLE3, 0, -1000, 0);
        }
    }
});

StaticNpc N(npcGroup_8024388C) = {
    .id = NPC_PETUNIA,
    .settings = &N(npcSettings_80240EDC),
    .pos = { -30.0f, 0.0f, 100.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241DA4),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
        NPC_ANIM(petunia, Palette_00, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DD),
};

StaticNpc N(npcGroup_80243A7C) = {
    .id = NPC_DAYZEE,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -233.0f, 0.0f, -217.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241E10),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
};

StaticNpc N(npcGroup_80243C6C) = {
    .id = NPC_MONTY_MOLE0,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -100.0f, 0.0f, 210.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024338C),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_2),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
    },
};

StaticNpc N(npcGroup_80243E5C) = {
    .id = NPC_MONTY_MOLE1,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -130.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802434CC),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_2),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
    },
};

StaticNpc N(npcGroup_8024404C) = {
    .id = NPC_MONTY_MOLE2,
    .settings = &N(npcSettings_80240EB0),
    .pos = { 75.0f, 0.0f, 20.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024360C),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_2),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
    },
};

StaticNpc N(npcGroup_8024423C) = {
    .id = NPC_MONTY_MOLE3,
    .settings = &N(npcSettings_80240EB0),
    .pos = { 71.0f, 0.0f, 200.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024374C),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_2),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_3),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_1),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_5),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
        NPC_ANIM(monty_mole, Palette_01, Anim_0),
    },
};

NpcGroupList N(npcGroupList_8024442C) = {
    NPC_GROUP(N(npcGroup_8024388C), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243A7C), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_80243C6C), BATTLE_ID(25, 2, 0, 2)),
    NPC_GROUP(N(npcGroup_80243E5C), BATTLE_ID(25, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_8024404C), BATTLE_ID(25, 3, 0, 2)),
    NPC_GROUP(N(npcGroup_8024423C), BATTLE_ID(25, 4, 0, 2)),
    {},
};

ApiStatus N(func_80240040_CA72E0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240F08_CA81A8) == NULL) {
        N(D_80240F08_CA81A8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240F08_CA81A8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240F08_CA81A8)[i];
        }
        heap_free(N(D_80240F08_CA81A8));
        N(D_80240F08_CA81A8) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

ApiStatus N(func_80240158_CA73F8)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 clamp = clamp_angle(atan2(-210.0f, -183.0f, gPlayerStatus.position.x, gPlayerStatus.position.z) + 180.0f);
    f32 sp10 = -210.0f;
    f32 sp14 = -183.0f;

    f32 temp_f20;
    f32 temp_f4_2;
    f64 temp_f4;
    f32 phi_f2;

    add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
    temp_f4 = dist2D(npc->pos.x, npc->pos.z, sp10, sp14);
    if (temp_f4 > 2.0) {
        temp_f20 = clamp_angle(atan2(-210.0f, -183.0f, npc->pos.x, npc->pos.z));
        temp_f4_2 = temp_f20 - clamp_angle(atan2(-210.0f, -183.0f, sp10, sp14));
        if (abs(temp_f4_2) >= 0x15) {
            phi_f2 = temp_f4_2;
            if (temp_f4_2 >= 180.0f) {
                phi_f2 = temp_f4_2 - 360.0f;
            }
            if (phi_f2 <= -180.0f) {
                phi_f2 += 360.0f;
            }
            if (temp_f4_2 == phi_f2) {
                sp10 = -210.0f;
                sp14 = -183.0f;
                if (temp_f4_2 >= 0.0f) {
                    clamp = clamp_angle(temp_f20 - 20.0f);
                } else {
                    clamp = clamp_angle(temp_f20 + 20.0f);
                }
                add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
            }
        }
        npc->currentAnim.w = enemy->animList[2];
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc_move_heading(npc, 2.0f, npc->yaw);
    } else if (temp_f4 > 0.2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[1];
    } else {
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[0];
    }
    return ApiStatus_BLOCK;
}

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 1,
    .models = { 23 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 22 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_RED_BERRY,
            .pos = { -256, 102, -169 },
            .spawnMode = 0xC,
            .spawnFlag = SI_AREA_FLAG(27),
        },
        {
            .itemID = ITEM_RED_BERRY,
            .pos = { -156, 102, -169 },
            .spawnMode = 0xC,
            .spawnFlag = SI_AREA_FLAG(28),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80244E44) = { -208.0f, 0.0f, -182.0f, 0.0f };

Script N(80244E54) = SCRIPT({
    SI_AREA_FLAG(27) = 0;
    SI_AREA_FLAG(28) = 0;
    SI_VAR(0) = N(tree1);
    bind N(shakeTree) TRIGGER_WALL_HAMMER 16;
    bind N(shakeTree) TRIGGER_POINT_BOMB N(triggerCoord_80244E44);
});

static s32 N(pad_4ECC) = {
    0x00000000,
};

Script N(80244ED0) = SCRIPT({

});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAB04, -175, 0, 150, 0, ITEM_MAP, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(1404));
});
