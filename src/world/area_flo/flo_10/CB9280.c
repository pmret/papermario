#include "flo_10.h"
#include "message_ids.h"
#include "sprite/npc/lily.h"

enum {
    NPC_LILY,
};

EntryList N(entryList) = {
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -100.0f, -10.0f, -172.0f, 135.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = N(func_80240000_CB9200),
};

EvtSource N(802414E0) = SCRIPT({
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        SetMusicTrack(0, SONG_SUNSHINE_RETURNS, 0, 8);
    } else {
        match SI_STORY_PROGRESS {
            < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
            } else {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
            }
        }
    }
    if (SI_STORY_PROGRESS >= STORY_CH6_FILLED_SPRING_WITH_WATER) {
        PlaySound(0x80000022);
    }
});

EvtSource N(802415C4) = SCRIPT({
    PushSong(137, 2);
});

EvtSource N(802415E8) = SCRIPT({
    FadeOutMusic(0, 250);
    sleep 10;
    PopSong();
});

static s32 N(pad_1624)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80241630) = SCRIPT({
    if (SI_STORY_PROGRESS >= STORY_CH6_FILLED_SPRING_WITH_WATER) {
        MakeItemEntity(ITEM_WATER_STONE, 0, -60, 6, 1, 0);
    }
});

static s32 N(pad_167C) = {
    0x00000000,
};

EvtSource N(80241680) = SCRIPT({
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

EvtSource N(exitWalk_8024192C) = EXIT_WALK_SCRIPT(60,  0, "flo_24",  1);

EvtSource N(80241988) = SCRIPT({
    bind N(exitWalk_8024192C) TRIGGER_FLOOR_ABOVE 0;
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80244054));
    await N(80241630);
    spawn N(80244A50);
    spawn N(802435F8);
    spawn N(80242AE8);
    spawn N(80244074);
    ModifyColliderFlags(3, 11, 0x00000006);
    ModifyColliderFlags(3, 12, 0x00000006);
    SI_VAR(0) = -265;
    SI_VAR(1) = 247;
    SI_VAR(2) = 199;
    SI_VAR(3) = 313;
    SI_VAR(4) = 0;
    spawn N(80241680);
    SI_VAR(0) = -300;
    SI_VAR(1) = -275;
    SI_VAR(2) = -140;
    SI_VAR(3) = -185;
    SI_VAR(4) = 0;
    spawn N(80241680);
    SI_VAR(0) = 263;
    SI_VAR(1) = -248;
    SI_VAR(2) = 362;
    SI_VAR(3) = 146;
    SI_VAR(4) = 0;
    spawn N(80241680);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 1 {
            spawn N(8024324C);
        }
        == 2 {
            spawn N(802427EC);
            spawn N(80241988);
        } else {
            ModifyColliderFlags(0, 1, 0x7FFFFE00);
            SI_VAR(0) = N(80241988);
            spawn EnterWalk;
        }
    }
    await N(802414E0);
    if (SI_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240040_CB9240)();
    }
});

static s32 N(pad_1CA8)[] = {
    0x00000000, 0x00000000,
};

s32** N(D_80241CB0_CBAEB0) = NULL;

EvtSource N(80241CB4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

EvtSource N(80241CE4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

EvtSource N(updateTexturePan_80241D14) = SCRIPT({
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

EvtSource N(80241DB0) = SCRIPT({
    MakeLerp(-50, 170, 385, 0);
1:
    UpdateLerp();
    TranslateGroup(56, 0, SI_VAR(0), 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
});

EvtSource N(80241E40) = SCRIPT({
    MakeLerp(0, 100, 90, 1);
1:
    UpdateLerp();
    SI_VAR(2) = (float) SI_VAR(0);
    SI_VAR(3) = (float) SI_VAR(0);
    SI_VAR(2) /= 333.0;
    SI_VAR(3) /= 100.0;
    SI_VAR(2) += 0.703125;
    ScaleGroup(56, SI_VAR(2), SI_VAR(3), SI_VAR(2));
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
});

EvtSource N(80241F20) = SCRIPT({
    EnableTexPanning(53, 1);
    spawn {
        SI_VAR(0) = 10;
        SI_VAR(1) = -150;
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
        spawn N(updateTexturePan_80241D14);
    }
});

EvtSource N(80242030) = SCRIPT({
    sleep 60;
    EnableModel(53, 1);
    spawn N(80241F20);
});

EvtSource N(8024206C) = SCRIPT({
    sleep 80;
    EnableNpcShadow(NPC_LILY, FALSE);
    GetNpcPos(NPC_LILY, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    MakeLerp(10, 55, 108, 0);
    loop {
        UpdateLerp();
        SI_VAR(6) = SI_VAR(4);
        SI_VAR(6) += SI_VAR(0);
        SI_VAR(6) += -10;
        SetNpcPos(NPC_LILY, SI_VAR(3), SI_VAR(6), SI_VAR(5));
        TranslateGroup(60, 0, SI_VAR(0), 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(80242188) = SCRIPT({
    DisablePlayerPhysics(TRUE);
    sleep 40;
    SetPlayerAnimation(0x80024);
    GetPlayerPos(SI_VAR(2), SI_VAR(0), SI_VAR(3));
    MakeLerp(-50, 90, 60, 1);
    loop {
        UpdateLerp();
        SI_VAR(2) /= 1.2001953125;
        SI_VAR(3) /= 1.2001953125;
        SetPlayerPos(SI_VAR(2), SI_VAR(0), SI_VAR(3));
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    MakeLerp(90, 270, 280, 0);
    loop {
        UpdateLerp();
        SetPlayerPos(0, SI_VAR(0), 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    DisablePlayerPhysics(FALSE);
});

EvtSource N(8024230C) = SCRIPT({
    sleep 80;
    GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    UseSettingsFrom(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SetPanTarget(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SetCamSpeed(0, 0.7001953125);
    SetCamPitch(0, 25.0, -22.0);
    SetCamDistance(0, 450);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
});

EvtSource N(802423E4) = SCRIPT({
    DisablePartnerAI(0);
    spawn N(80241DB0);
    spawn N(80241E40);
    spawn N(80242030);
    spawn N(8024206C);
    spawn N(80242188);
    spawn N(8024230C);
});

EvtSource N(8024244C) = SCRIPT({
    MakeLerp(170, 75, 150, 0);
1:
    UpdateLerp();
    TranslateGroup(56, 0, SI_VAR(0), 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
});

EvtSource N(802424DC) = SCRIPT({
    MakeLerp(100, 15, 150, 1);
1:
    UpdateLerp();
    SI_VAR(2) = (float) SI_VAR(0);
    SI_VAR(3) = (float) SI_VAR(0);
    SI_VAR(2) /= 333.0;
    SI_VAR(3) /= 100.0;
    SI_VAR(2) += 0.703125;
    ScaleGroup(56, SI_VAR(2), SI_VAR(3), SI_VAR(2));
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
});

EvtSource N(802425BC) = SCRIPT({
    spawn N(8024244C);
    spawn N(802424DC);
});

const char N(flo_24_name_hack)[];

EvtSource N(802425E4) = SCRIPT({
    sleep 20;
    SetPlayerAnimation(ANIM_STAND_STILL);
    GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    UseSettingsFrom(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SetPanTarget(0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SetCamSpeed(0, 1.0);
    SetCamDistance(0, 600);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    EnableGroup(56, 1);
    TranslateGroup(56, 0, -50, 0);
    ScaleGroup(56, 0, 0, 0);
    EnableGroup(60, 1);
    await N(802423E4);
    sleep 20;
    PlaySound(0x80000024);
    sleep 360;
    InterpPlayerYaw(90, 0);
    SetPlayerAnimation(ANIM_80017);
    SetPlayerJumpscale(0.2001953125);
    PlayerJump1(-100, -10, -172, 75);
    ShakeCam(0, 0, 5, 1.0);
    await N(802425BC);
    sleep 60;
    GotoMap(N(flo_24_name_hack), 2);
    sleep 100;
});

EvtSource N(802427EC) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerPos(-100, -10, -172);
    InterpPlayerYaw(150, 0);
    SetPlayerAnimation(ANIM_DEAD_STILL);
    SetNpcPos(NPC_PARTNER, -129, 9, -177);
    EnablePartnerAI();
    ClearPartnerMoveHistory(-4);
    EnableGroup(52, 1);
    EnableGroup(19, 0);
    EnableGroup(61, 0);
    EnableGroup(60, 0);
    SetNpcPos(NPC_LILY, -57, -20, -105);
    InterpNpcYaw(NPC_LILY, 90, 0);
    AdjustCam(0, 90.0, 0, 450, 25.0, -6.0);
    sleep 30;
    SetPlayerAnimation(ANIM_GET_UP);
    sleep 20;
    SetPlayerAnimation(ANIM_10002);
    sleep 10;
    await N(802415C4);
    sleep 10;
    SpeakToPlayer(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x0082));
    NpcFacePlayer(NPC_LILY, 1);
    SpeakToPlayer(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0083));
    SetNpcAnimation(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_6);
    sleep 20;
    SetNpcAnimation(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_1);
    SI_VAR(0) = 90;
    SI_VAR(1) = 1;
    await N(80241CB4);
    AddKeyItem(ITEM_MIRACLE_WATER);
    SpeakToPlayer(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0084));
    EndSpeech(0, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0);
    SetNpcAnimation(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_1);
    ResetCam(0, 4.0);
    await N(802415E8);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
});

EvtSource N(80242AE8) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH6_FILLED_SPRING_WITH_WATER) {
        EnableGroup(52, 0);
        EnableGroup(61, 0);
        ModifyColliderFlags(0, 21, 0x7FFFFE00);
    } else {
        EnableGroup(19, 0);
        EnableGroup(61, 0);
        EnableGroup(60, 0);
        ModifyColliderFlags(0, 14, 0x7FFFFE00);
        ModifyColliderFlags(0, 15, 0x7FFFFE00);
        ModifyColliderFlags(0, 16, 0x7FFFFE00);
        ModifyColliderFlags(0, 17, 0x7FFFFE00);
    }
    EnableTexPanning(54, 1);
    EnableTexPanning(48, 1);
    EnableTexPanning(55, 1);
    EnableTexPanning(59, 1);
    EnableTexPanning(49, 1);
    EnableTexPanning(51, 1);
    spawn {
        SI_VAR(0) = 1;
        SI_VAR(1) = 0;
        SI_VAR(2) = -2000;
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
        spawn N(updateTexturePan_80241D14);
    }
    spawn {
        SI_VAR(0) = 3;
        SI_VAR(1) = -100;
        SI_VAR(2) = 80;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80241D14);
    }
    spawn {
        SI_VAR(0) = 5;
        SI_VAR(1) = -1000;
        SI_VAR(2) = 2000;
        SI_VAR(3) = 0;
        SI_VAR(4) = 0;
        SI_VAR(5) = 1;
        SI_VAR(6) = 1;
        SI_VAR(7) = 0;
        SI_VAR(8) = 0;
        SI_VAR(9) = 0;
        SI_VAR(10) = 0;
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        spawn N(updateTexturePan_80241D14);
    }
    spawn {
        SI_VAR(0) = 6;
        SI_VAR(1) = 0;
        SI_VAR(2) = -2000;
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
        spawn N(updateTexturePan_80241D14);
    }
    spawn {
        SI_VAR(0) = 8;
        SI_VAR(1) = 0;
        SI_VAR(2) = -1500;
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
        spawn N(updateTexturePan_80241D14);
    }
    spawn {
        SI_VAR(0) = 9;
        SI_VAR(1) = 0;
        SI_VAR(2) = -1000;
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
        spawn N(updateTexturePan_80241D14);
    }
    if (SI_STORY_PROGRESS >= STORY_CH6_FILLED_SPRING_WITH_WATER) {
        spawn N(80241F20);
    }
});

static s32 N(pad_3218)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80243220) = {
    .height = 45,
    .radius = 65,
    .level = 99,
};

const char N(flo_24_name_hack)[] = "flo_24";

EvtSource N(8024324C) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetNpcPos(NPC_LILY, 60, 0, 55);
    UseSettingsFrom(0, 0, 0, 0);
    SetPanTarget(0, 0, 0, 0);
    SetCamDistance(0, 450);
    SetCamPitch(0, 17.0, -6.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 20;
    SpeakToPlayer(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00C6));
    sleep 10;
    GotoMap("flo_12", 1);
    sleep 100;
});

s32 N(itemList_80243394)[] = {
    ITEM_WATER_STONE,
    ITEM_NONE,
};

EvtSource N(8024339C) = SCRIPT({
    if (SI_SAVE_FLAG(1376) == 1) {
        GetCurrentPartner(SI_VAR(10));
        if (SI_VAR(10) != 0) {
            AwaitPlayerLeave(0, 0, 19);
            return;
        }
        DisablePlayerInput(TRUE);
        group 0;
        SetTimeFreezeMode(1);
        ShowKeyChoicePopup();
        SI_VAR(2) = SI_VAR(0);
        match SI_VAR(2) {
            == -1 {
                CloseChoicePopup();
                SetTimeFreezeMode(0);
                sleep 10;
                SpeakToPlayer(NPC_LILY, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x0081));
            } else {
                GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
                PlayerMoveTo(-17, -17, 20);
                func_802CF56C(2);
                InterpPlayerYaw(100, 1);
                sleep 10;
                AdjustCam(0, 1.0, 0, 450, 25.0, -6.0);
                sleep 10;
                SetPlayerAnimation(0x60006);
                RemoveKeyItemAt(SI_VAR(1));
                MakeItemEntity(ITEM_WATER_STONE, 0, -60, 6, 1, 0);
                SI_VAR(10) = SI_VAR(0);
                CloseChoicePopup();
                SetTimeFreezeMode(0);
                await N(802425E4);
            }
        }
        DisablePlayerInput(FALSE);
        AwaitPlayerLeave(0, 0, 19);
    }
});

EvtSource N(802435F8) = SCRIPT({
    bind_padlock N(8024339C) TRIGGER_FLOOR_TOUCH 15 N(itemList_80243394);
});

EvtSource N(80243628) = SCRIPT({
    sleep 10;
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    if (SI_VAR(5) < SI_VAR(2)) {
        SI_VAR(6) = 30;
    } else {
        SI_VAR(6) = 20;
    }
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(4) = SI_VAR(0);
    SI_VAR(1) -= SI_VAR(6);
    SI_VAR(4) += SI_VAR(6);
    match SI_VAR(3) {
        SI_VAR(1) ... SI_VAR(4) {
            spawn {
                if (SI_VAR(3) < SI_VAR(0)) {
                    SI_VAR(0) -= 40;
                } else {
                    SI_VAR(0) += 40;
                }
                SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
                PlayerMoveTo(SI_VAR(0), SI_VAR(5), 15);
                PlayerFaceNpc(0, 1);
                SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), FALSE);
            }
        }
    }
});

EvtSource N(interact_802437C8) = SCRIPT({
    await N(802415C4);
    match SI_STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            spawn N(80243628);
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 325);
            SetCamPitch(0, 23.0, -9.0);
            SetCamSpeed(0, 4.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            sleep 10;
            SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11, 0x0078));
            EndSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_9, NPC_ANIM_lily_Palette_00_Anim_5, 5);
        }
        < STORY_CH6_GOT_WATER_STONE {
            if (SI_SAVE_FLAG(1375) == 0) {
                spawn N(80243628);
                GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SetCamDistance(0, 325);
                SetCamPitch(0, 23.0, -9.0);
                SetCamSpeed(0, 4.0);
                PanToTarget(0, 0, 1);
                WaitForCam(0, 1.0);
                sleep 10;
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11,
                              0x0079));
                NpcFacePlayer(NPC_SELF, 1);
                SetNpcAnimation(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_1);
                PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_262, 0);
                ShowEmote(-1, EMOTE_EXCLAMATION, 0, 15, 1, 0, 0, 0, 0);
                sleep 15;
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_1, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11,
                              0x007A));
                EndSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_5, NPC_ANIM_lily_Palette_00_Anim_1, 0);
                GetPlayerTargetYaw(SI_VAR(0));
                InterpNpcYaw(NPC_SELF, SI_VAR(0), 1);
                sleep 20;
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 5, MESSAGE_ID(0x11,
                              0x007B));
                NpcFacePlayer(NPC_SELF, 1);
                sleep 20;
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11,
                              0x007C));
                ShowChoice(MESSAGE_ID(0x1E, 0x0011));
                sleep 10;
                match SI_VAR(0) {
                    == 0 {
                        ContinueSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x007D));
                    }
                    == 1 {
                        ContinueSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x007E));
                    }
                }
                sleep 10;
                SI_SAVE_FLAG(1375) = 1;
                SetEnemyFlagBits(-1, 4194304, 0);
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11,
                              0x007F));
            }
        }
        < 49 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0080));
            SI_SAVE_FLAG(1376) = 1;
        }
        < 53 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x0085));
            EndSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0);
            EndSpeech(-1, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0);
        }
        < 60 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0086));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11,
                          0x0087));
        }
    }
    ResetCam(0, 4.0);
    await N(802415E8);
});

EvtSource N(init_80243D78) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802437C8));
    match SI_STORY_PROGRESS {
        < STORY_CH6_GOT_WATER_STONE {
            if (SI_SAVE_FLAG(1375) == 0) {
                SetNpcAnimation(NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_8);
                InterpNpcYaw(NPC_SELF, 90, 1);
                SetEnemyFlagBits(-1, 4194304, 1);
            }
        }
        == STORY_CH6_GOT_WATER_STONE {
            InterpNpcYaw(NPC_SELF, 270, 1);
        }
        >= STORY_CH6_FILLED_SPRING_WITH_WATER {
            SetNpcPos(NPC_SELF, -67, -20, -105);
        }
    }
});

StaticNpc N(npcGroup_80243E64) = {
    .id = NPC_LILY,
    .settings = &N(npcSettings_80243220),
    .pos = { 80.0f, -60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80243D78),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DF),
};

NpcGroupList N(npcGroupList_80244054) = {
    NPC_GROUP(N(npcGroup_80243E64), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_406C) = {
    0x00000000,
};

s32 N(D_80244070_CBD270) = {
    0x00000000,
};

EvtSource N(80244074) = SCRIPT({

});

static s32 N(pad_4084)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

ApiStatus N(func_80240080_CB9280)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241CB0_CBAEB0) == NULL) {
        N(D_80241CB0_CBAEB0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241CB0_CBAEB0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241CB0_CBAEB0)[i];
        }
        heap_free(N(D_80241CB0_CBAEB0));
        N(D_80241CB0_CBAEB0) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"
