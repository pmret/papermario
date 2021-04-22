#include "dgb_18.h"
#include "message_ids.h"
#include "sprite/npc/world_bombette.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kooper.h"
#include "sprite/npc/world_parakarry.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/yakkey.h"

enum {
    NPC_WORLD_TUBBA,
    NPC_YAKKEY,
};

EntryList N(entryList) = {
    { -120.0f, 0.0f, 180.0f, 90.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = 0x1900D2,
};

Script N(802412C0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_1358)[] = {
    0x00000000, 0x00000000,
};

Script N(exitDoubleDoor_80241360) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 17;
    SI_VAR(2) = 8;
    SI_VAR(3) = 10;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_01", 6);
    sleep 100;
});

Script N(enterDoubleDoor_80241414) = SCRIPT({
    UseDoorSounds(3);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 8;
            SI_VAR(3) = 10;
            await EnterDoubleDoor;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    MakeNpcs(1, N(npcGroupList_802436B4));
    await N(makeEntities);
    spawn N(802412C0);
    bind N(exitDoubleDoor_80241360) to TRIGGER_WALL_PRESS_A 17;
    spawn N(enterDoubleDoor_80241414);
});

static s32 N(pad_1578)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80241580) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .unk_10 = { .f = 90.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.9f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 170.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 1,
};

Script N(802415B0) = SCRIPT({
    N(func_80240B94_C56AD4)(N(npcAISettings_80241580));
});

NpcSettings N(npcSettings_802415D0) = {
    .height = 90,
    .radius = 65,
    .ai = &N(802415B0),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_802415FC) = {
    .height = 90,
    .radius = 65,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80241628) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

Script N(idle_80241654) = SCRIPT({
10:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    if (SI_VAR(0) < 700) {
        goto 10;
    }
    if (SI_VAR(2) > 185) {
        goto 10;
    }
    DisablePlayerInput(TRUE);
    sleep 10;
    spawn {
        sleep 10;
        InterpPlayerYaw(270, 0);
    }
    FadeOutMusic(0, 500);
    loop 3 {
        SetPlayerAnimation(ANIM_8001E);
        PlaySoundAt(SOUND_UNKNOWN_20F6, 0, 382, 0, 218);
        ShakeCam(0, 0, 5, 1.0);
        sleep 20;
        SetPlayerAnimation(ANIM_10002);
        sleep 10;
    }
    loop 2 {
        InterpPlayerYaw(270, 0);
        sleep 10;
        InterpPlayerYaw(90, 0);
        sleep 10;
    }
    UseSettingsFrom(0, -40, 0, 180);
    SetCamSpeed(0, 90.0);
    SetPanTarget(0, -40, 0, 180);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SetPlayerPos(740, 0, 180);
    SetNpcPos(NPC_PARTNER, 765, 0, 180);
    InterpPlayerYaw(270, 0);
    InterpNpcYaw(NPC_PARTNER, 270, 0);
    SetPlayerAnimation(ANIM_8000C);
    PlaySoundAtCollider(17, 455, 0);
    MakeLerp(0, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(8, SI_VAR(0), 0, -1, 0);
        RotateModel(10, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    spawn {
        loop 3 {
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 0);
            ShakeCam(0, 0, 5, 0.30078125);
            sleep 5;
        }
    }
    SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_9));
    SetNpcPos(NPC_SELF, -210, 0, 180);
    NpcMoveTo(NPC_SELF, -60, 180, 30);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    spawn {
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(8, SI_VAR(0), 0, -1, 0);
            RotateModel(10, SI_VAR(0), 0, 1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(17, 456, 0);
    }
    sleep 20;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_10), NPC_ANIM(world_tubba, Palette_00, Anim_6), 5, MESSAGE_ID(0x0E, 0x00F4));
    sleep 20;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_9));
    SetSelfVar(0, 0);
    spawn {
        loop {
            GetSelfVar(0, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 0);
            ShakeCam(0, 0, 5, 0.30078125);
            sleep 9;
            GetSelfVar(0, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 0);
            ShakeCam(0, 0, 2, 0.150390625);
            sleep 12;
        }
    }
    spawn {
        loop {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
            GetSelfVar(0, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
        }
    }
    SetNpcSpeed(NPC_SELF, 4.0);
    NpcMoveTo(NPC_SELF, 45, 215, 0);
    NpcMoveTo(NPC_SELF, 140, 245, 0);
    NpcMoveTo(NPC_SELF, 615, 245, 0);
    SetSelfVar(0, 1);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    sleep 15;
    sleep 20;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_10), NPC_ANIM(world_tubba, Palette_00, Anim_6), 5, MESSAGE_ID(0x0E, 0x00F5));
    sleep 20;
    spawn {
        SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_14));
        sleep 5;
        SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_15));
        sleep 5;
        SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_16));
        sleep 5;
    }
    sleep 5;
    SetNpcJumpscale(NPC_SELF, 0.7001953125);
    NpcJump0(NPC_SELF, 600, 50, 115, 20);
    spawn {
        ShakeCam(0, 0, 5, 0.30078125);
    }
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_5));
    SetNpcScale(NPC_SELF, 1.25, 1.2001953125, 1.25);
    sleep 1;
    SetNpcScale(NPC_SELF, 1.3505859375, 1.150390625, 1.25);
    sleep 1;
    SetNpcScale(NPC_SELF, 1.4501953125, 1.05078125, 1.25);
    sleep 1;
    SetNpcScale(NPC_SELF, 1.3505859375, 1.150390625, 1.25);
    sleep 1;
    SetNpcScale(NPC_SELF, 1.25, 1.2001953125, 1.25);
    sleep 1;
    GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    spawn {
        SetNpcJumpscale(NPC_SELF, 0.5);
        NpcJump0(NPC_SELF, SI_VAR(3), 30, SI_VAR(5), 23);
    }
    sleep 2;
    spawn {
        MakeLerp(0, 50, 18, 1);
        loop {
            UpdateLerp();
            func_802CDE68(-1, SI_VAR(0));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    MakeLerp(0, -90, 18, 1);
    loop {
        UpdateLerp();
        SetNpcRotation(NPC_SELF, 0, 0, SI_VAR(0));
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    spawn {
        ShakeCam(0, 0, 10, 0.400390625);
    }
    sleep 5;
    FadeOutMusic(0, 1000);
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    SetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    func_802CDE68(-1, 0);
    SetNpcRotation(NPC_SELF, 0, 0, 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_2));
    sleep 15;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_24));
    sleep 30;
    PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2038, 0);
    sleep 30;
    spawn {
        SetSelfVar(1, 0);
        loop {
            GetSelfVar(1, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2039, 0);
            RandInt(10, SI_VAR(1));
            SI_VAR(1) += 15;
            ShowSleepBubble(0, 0, 0, 2, 628, 121, 127, SI_VAR(1), SI_VAR(0));
            sleep 48;
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2038, 0);
            RandInt(10, SI_VAR(1));
            SI_VAR(1) += 10;
            func_802D8248(SI_VAR(0), SI_VAR(1));
            sleep 30;
        }
    }
    sleep 30;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 2.0);
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    STORY_PROGRESS = STORY_CH3_TUBBA_BEGAN_NAPPING;
    DisablePlayerInput(FALSE);
});

Script N(idle_80242494) = SCRIPT({
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    SetNpcPos(NPC_SELF, 600, 50, 115);
    func_802CDE68(-1, 0);
    SetNpcRotation(NPC_SELF, 0, 0, 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_2));
    sleep 15;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_24));
    sleep 30;
    PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2038, 0);
    sleep 30;
    spawn {
        SetSelfVar(1, 0);
        loop {
            GetSelfVar(1, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2039, 0);
            RandInt(10, SI_VAR(1));
            SI_VAR(1) += 15;
            ShowSleepBubble(0, 0, 0, 2, 628, 121, 127, SI_VAR(1), SI_VAR(0));
            sleep 48;
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2038, 0);
            RandInt(10, SI_VAR(1));
            SI_VAR(1) += 10;
            func_802D8248(SI_VAR(0), SI_VAR(1));
            sleep 30;
        }
    }
});

Script N(npcAI_802426B0) = SCRIPT({
    group 11;
    PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2039, 0);
    ShowSleepBubble(0, 0, 50, 2, 552, 111, 128, 30, SI_VAR(0));
    sleep 360;
    func_802D8248(SI_VAR(0), 20);
    SetNpcVar(-1, 1, 2);
    sleep 20;
    PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_2F1, 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_19));
    sleep 30;
    spawn {
        NpcJump0(NPC_SELF, 650, 0, 250, 25);
    }
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_1A));
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_1B));
    sleep 12;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(world_tubba, Palette_00, Anim_1C));
    sleep 5;
    BindNpcAI(NPC_WORLD_TUBBA, N(npcAI_80242834));
});

Script N(npcAI_80242834) = SCRIPT({
    group 11;
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_D));
    spawn {
        loop {
            ShakeCam(0, 0, 5, 2.0);
            sleep 5;
            ShakeCam(0, 0, 2, 1.0);
            sleep 8;
        }
    }
    N(func_80240B94_C56AD4)(N(npcAISettings_80241580));
});

const char N(dgb_01_name_hack)[];

Script N(defeat_802428E8) = SCRIPT({
    N(UnkFunc1)();
    GotoMap(N(dgb_01_name_hack), 6);
    sleep 100;
});

const char N(pad_XXX)[] = { 0, 0 };

Script N(init_80242924) = SCRIPT({
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    BindNpcDefeat(NPC_SELF, N(defeat_802428E8));
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_BEGAN_NAPPING {
            BindNpcIdle(NPC_SELF, N(idle_80241654));
        }
        < STORY_CH3_TUBBA_WOKE_UP {
            BindNpcIdle(NPC_SELF, N(idle_80242494));
        }
        < STORY_CH3_TUBBA_SMASHED_THE_BRIDGES {
            SetNpcPos(NPC_SELF, 245, 0, 250);
            SetNpcYaw(NPC_SELF, 270);
            BindNpcIdle(NPC_SELF, N(npcAI_80242834));
        }
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            RemoveNpc(NPC_SELF);
        }
    }
});

Script N(idle_80242A24) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    sleep 40;
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
    SetNpcPos(NPC_SELF, 845, 0, 140);
    SetNpcJumpscale(NPC_SELF, 0.80078125);
    NpcJump1(NPC_SELF, 845, 35, 145, 15);
    PlayerFaceNpc(-1, 0);
    sleep 15;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamDistance(0, 300);
    SetCamPosB(0, 800, 245);
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PanToTarget(0, 0, 1);
    SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 5, MESSAGE_ID(0x0E, 0x00F6));
    sleep 15;
    SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 5, MESSAGE_ID(0x0E, 0x00F7));
    ShowChoice(1966093);
    if (SI_VAR(0) == 0) {
        ContinueSpeech(-1, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00F8));
    } else {
        ContinueSpeech(-1, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00F9));
    }
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 4.0);
    UseSettingsFrom(0, 740, SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 600);
    SetCamPosB(0, 800, 245);
    SetPanTarget(0, 740, SI_VAR(1), SI_VAR(2));
    WaitForCam(0, 1.0);
    spawn {
        SI_MAP_FLAG(0) = 0;
        SpeakToPlayer(NPC_SELF, NPC_ANIM(yakkey, Palette_00, Anim_2), NPC_ANIM(yakkey, Palette_00, Anim_1), 517, MESSAGE_ID(0x0E, 0x00FA));
        SI_MAP_FLAG(0) = 1;
    }
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    loop {
        SetCamDistance(0, 550.0);
        SetCamSpeed(0, 90.0);
        SetPanTarget(0, 740, SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetCamDistance(0, 600.0);
        SetCamSpeed(0, 90.0);
        SetPanTarget(0, 740, SI_VAR(1), SI_VAR(2));
        sleep 1;
        if (SI_MAP_FLAG(0) == 1) {
            break loop;
        }
    }
    SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
    SetNpcVar(0, 1, 1);
    sleep 15;
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_25));
    spawn {
        loop {
            GetNpcVar(0, 1, SI_VAR(0));
            if (SI_VAR(0) == 2) {
                break loop;
            }
            RandInt(40, SI_VAR(0));
            RandInt(40, SI_VAR(1));
            SI_VAR(0) += 537;
            SI_VAR(1) += 110;
            PlayEffect(0x27, 2, SI_VAR(0), SI_VAR(1), 128, 0.30078125, 24, 0, 0, 0, 0, 0, 0, 0);
            sleep 5;
        }
    }
    sleep 15;
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_5));
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_13), NPC_ANIM(world_tubba, Palette_00, Anim_5), 5, MESSAGE_ID(0x0E, 0x00FB));
    sleep 15;
    DisablePartnerAI(0);
    GetCurrentPartnerID(SI_VAR(0));
    match SI_VAR(0) {
        == 1 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0, MESSAGE_ID(0x0E, 0x00FC));
        }
        == 2 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_kooper, normal, talk), NPC_ANIM(world_kooper, normal, idle), 0, MESSAGE_ID(0x0E, 0x00FD));
        }
        == 3 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_bombette, normal, idle_fast), NPC_ANIM(world_bombette, normal, idle), 0, MESSAGE_ID(0x0E, 0x00FE));
        }
        == 4 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_parakarry, Palette_00, Anim_6), NPC_ANIM(world_parakarry, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00FF));
        }
        == 9 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x0100));
        }
    }
    EnablePartnerAI();
    sleep 15;
    BindNpcAI(NPC_WORLD_TUBBA, N(npcAI_802426B0));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 4.0);
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetNpcJumpscale(NPC_SELF, 1.0);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
    SI_VAR(1) -= 10;
    NpcJump0(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    STORY_PROGRESS = STORY_CH3_TUBBA_WOKE_UP;
    DisablePlayerInput(FALSE);
});

Script N(init_8024329C) = SCRIPT({
    SetSelfVar(0, 0);
    BindNpcIdle(NPC_SELF, N(idle_80242A24));
});

StaticNpc N(npcGroup_802432D4) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802415FC),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_80242924),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 5, 0, 0, 240, 175, 0, 240, 350, 0, 240, 525, 0, 240, 700, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 300, 0, 240, 1000, 250, 1, 1 },
    .animations = {
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_A),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_19),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
    },
};

StaticNpc N(npcGroup_802434C4) = {
    .id = NPC_YAKKEY,
    .settings = &N(npcSettings_80241628),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024329C),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
        NPC_ANIM(yakkey, Palette_00, Anim_1),
    },
};

NpcGroupList N(npcGroupList_802436B4) = {
    NPC_GROUP(N(npcGroup_802432D4), BATTLE_ID(15, 4, 0, 0)),
    NPC_GROUP(N(npcGroup_802434C4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_36D8)[] = {
    0x00000000, 0x00000000,
};

s32 N(D_802436E0_C59620) = {
    0x00000000,
};

Script N(802436E4) = SCRIPT({
    group 0;
    func_802D5830(2);
    sleep 40;
    ShowGotItem(SI_VAR(0), 0, 0);
    func_802D5830(0);
    return;
});

Script N(8024374C) = SCRIPT({
    DisablePlayerInput(TRUE);
    SI_VAR(0) = SI_VAR(10);
    if (SI_VAR(10) != 0) {
        await N(802436E4);
    }
    match SI_VAR(11) {
        == 0 {
            AddItem(SI_VAR(10), SI_VAR(0));
        }
        == 1 {
            AddKeyItem(SI_VAR(10));
        }
        == 2 {
            AddBadge(SI_VAR(10), SI_VAR(0));
        }
    }
    sleep 15;
    DisablePlayerInput(FALSE);
});

Script N(8024382C) = SCRIPT({
    SI_SAVE_FLAG(1071) = 1;
    AddKeyItem(ITEM_MYSTICAL_KEY);
    SetNpcVar(1, 0, 1);
});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAE30, 845, 0, 145, -35, ITEM_NONE, MAKE_ENTITY_END);
    AssignFlag(SI_SAVE_FLAG(1071));
    AssignScript(N(8024382C));
});

ApiStatus N(func_80240000_C55F40)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
    return ApiStatus_DONE1;
}

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

ApiStatus N(func_8024067C_C565BC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
    return ApiStatus_DONE1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_C56AD4)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= 0xBFFFFFFF;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_C55F40)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_C565BC)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc1.inc.c"

ApiStatus N(func_80240EBC_C56DFC)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = playerStatus;
    Npc *npc = get_npc_unsafe(0);
    f32 posX, posZ;

    if (isInitialCall) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        npc->moveSpeed = 3.7f;
        npc->yaw = atan2(posX, posZ, playerStatus->position.x, playerStatus->position.z);
        script->functionTemp[1].s = 0;
        npc->duration = 15;
    }

    if (script->functionTemp[1].s == 0) {
        if (npc->duration == 0) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus2->position.x, playerStatus2->position.z);
            npc->duration = 15;
        }
        npc->duration--;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    return ApiStatus_BLOCK;
}

const char N(dgb_01_name_hack)[] = "dgb_01";
