#include "flo_00.h"
#include "script_api/common.h"
#include "message_ids.h"
#include "sprite/npc/bubulb.h"
#include "sprite/npc/lakilulu.h"
#include "sprite/npc/tolielup.h"
#include "sprite/npc/world_klevar.h"
#include "sprite/npc/world_lakilester.h"
#include "sprite/npc/world_parakarry.h"

enum {
    NPC_BUBULB0,
    NPC_BUBULB1,
    NPC_BUBULB2,
    NPC_BUBULB3,
    NPC_BUBULB4,
    NPC_TOLIELUP,
    NPC_WORLD_KLEVAR,
    NPC_LAKILULU,
};

EntryList N(entryList) = {
    {    0.0f, 0.0f, -310.0f, 170.0f },
    { -320.0f, 0.0f, -335.0f, 135.0f },
    { -470.0f, 0.0f,    0.0f,  90.0f },
    { -320.0f, 0.0f,  335.0f,  45.0f },
    {  320.0f, 0.0f, -335.0f, 225.0f },
    {  465.0f, 0.0f,    0.0f, 270.0f },
    {  320.0f, 0.0f,  335.0f, 315.0f },
    {  -30.0f, 0.0f,  120.0f, 270.0f },
    {  -30.0f, 0.0f,  120.0f, 270.0f },
    { -470.0f, 0.0f,    0.0f,  90.0f },
    {   40.0f, 0.0f,  -30.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_00_tattle },
};

Script N(802414D0) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 8 {
            if (SI_AREA_FLAG(44) != 0) {
                SetMusicTrack(0, SONG_MAGIC_BEANSTALK, 1, 8);
            } else {
                SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
            }
        }
        == 9 {
            SetMusicTrack(0, SONG_SUNSHINE_RETURNS, 0, 8);
        }
        == 10 {
            SetMusicTrack(0, SONG_STAR_SPIRIT_THEME, 1, 8);
            spawn {
                loop {
                    sleep 1;
                    if (STORY_PROGRESS >= STORY_CH6_STAR_SPRIT_DEPARTED) {
                        break loop;
                    }
                }
                SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
            }
        }
        == 11 {
            FadeInMusic(0, 49, 0, 3000, 0, 127);
        } else {
            match STORY_PROGRESS {
                < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                    SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
                } else {
                    SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
                }
            }
        }
    }
});

static s32 N(pad_16BC) = {
    0x00000000,
};

Script N(802416C0) = SCRIPT({
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

Script N(8024196C) = SCRIPT({
    DisablePlayerInput(TRUE);
    ModifyColliderFlags(0, 2, 0x7FFFFE00);
    PlayerMoveTo(30, -170, 10);
    InterpPlayerYaw(0, 0);
    PlaySoundAtCollider(2, 463, 0);
    MakeLerp(0, -100, 20, 4);
    loop {
        UpdateLerp();
        RotateGroup(28, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    func_802D2C14(1);
    PlayerMoveTo(0, -310, 30);
    func_802D2C14(0);
    if (STORY_PROGRESS == STORY_CH6_STAR_SPRIT_DEPARTED) {
        STORY_PROGRESS = STORY_CH6_RETURNED_TO_TOAD_TOWN;
    }
    MakeLerp(-100, 0, 30, 1);
    loop {
        UpdateLerp();
        RotateGroup(28, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlaySoundAtCollider(2, 464, 0);
    GotoMap("mac_01", 5);
    sleep 100;
});

Script N(80241B90) = SCRIPT({
    DisablePlayerInput(TRUE);
    ModifyColliderFlags(0, 2, 0x7FFFFE00);
    InterpPlayerYaw(180, 0);
    PlaySoundAtCollider(2, 463, 0);
    MakeLerp(0, -100, 30, 1);
    loop {
        UpdateLerp();
        RotateGroup(28, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    func_802D2C14(1);
    PlayerMoveTo(0, -135, 30);
    func_802D2C14(0);
    MakeLerp(-100, 0, 30, 1);
    loop {
        UpdateLerp();
        RotateGroup(28, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlaySoundAtCollider(2, 464, 0);
    DisablePlayerInput(FALSE);
    ModifyColliderFlags(1, 2, 0x7FFFFE00);
});

Script N(exitWalk_80241D7C) = EXIT_WALK_SCRIPT(60,  1, "flo_14",  0);

Script N(exitWalk_80241DD8) = EXIT_WALK_SCRIPT(60,  2, "flo_23",  0);

Script N(exitWalk_80241E34) = EXIT_WALK_SCRIPT(60,  3, "flo_25",  0);

Script N(exitWalk_80241E90) = EXIT_WALK_SCRIPT(60,  4, "flo_16",  0);

Script N(exitWalk_80241EEC) = EXIT_WALK_SCRIPT(60,  5, "flo_09",  0);

Script N(exitWalk_80241F48) = EXIT_WALK_SCRIPT(60,  6, "flo_08",  0);

const s32 N(pad_XXXX)[] = { 0, 0};

Script N(80241FA4) = SCRIPT({
    bind N(exitWalk_80241D7C) to TRIGGER_FLOOR_ABOVE 5;
    bind N(exitWalk_80241DD8) to TRIGGER_FLOOR_ABOVE 9;
    bind N(exitWalk_80241E34) to TRIGGER_FLOOR_ABOVE 13;
    bind N(exitWalk_80241E90) to TRIGGER_FLOOR_ABOVE 17;
    bind N(exitWalk_80241EEC) to TRIGGER_FLOOR_ABOVE 21;
    bind N(exitWalk_80241F48) to TRIGGER_FLOOR_ABOVE 25;
});

Script N(enterWalk_8024205C) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(80241FA4);
    } else {
        GetEntryID(SI_VAR(0));
        if (SI_VAR(0) != 8) {
            SI_AREA_FLAG(44) = 0;
        }
        match SI_VAR(0) {
            == 0 {
                spawn {
                    await N(80241B90);
                    spawn N(80241FA4);
                }
            }
            1..6 {
                SI_VAR(0) = N(80241FA4);
                spawn EnterWalk;
            }
            == 7 {
                spawn {
                    await N(8024834C);
                    spawn N(80241FA4);
                }
            }
            == 8 {
                spawn {
                    await N(80247BCC);
                    spawn N(80241FA4);
                }
            }
            == 9 {
                spawn N(80242998);
                SI_VAR(0) = N(80241FA4);
                spawn EnterWalk;
            }
            == 10 {
                spawn N(80241FA4);
            }
            == 11 {
                spawn N(80245EB8);
            }
        }
    }
    bind N(80242FCC) to TRIGGER_WALL_PRESS_A 2;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SI_SAVE_FLAG(1984) = 1;
    if (STORY_PROGRESS < STORY_CH6_GREW_MAGIC_BEANSTALK) {
        ModifyColliderFlags(0, 48, 0x7FFFFE00);
    }
    SI_SAVE_FLAG(263) = 0;
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 11) {
        MakeNpcs(0, N(npcGroupList_80246834));
    } else {
        MakeNpcs(0, N(npcGroupList_80245DE4));
    }
    await N(makeEntities);
    ParentColliderToModel(46, 81);
    spawn N(80248F48);
    spawn N(80248E30);
    ModifyColliderFlags(3, 30, 0x00000006);
    ModifyColliderFlags(3, 31, 0x00000006);
    SI_VAR(0) = 150;
    SI_VAR(1) = -270;
    SI_VAR(2) = 410;
    SI_VAR(3) = 170;
    SI_VAR(4) = 0;
    spawn N(802416C0);
    SI_VAR(0) = 115;
    SI_VAR(1) = -450;
    SI_VAR(2) = 250;
    SI_VAR(3) = -270;
    SI_VAR(4) = 0;
    spawn N(802416C0);
    SI_VAR(0) = -330;
    SI_VAR(1) = 220;
    SI_VAR(2) = 45;
    SI_VAR(3) = 410;
    SI_VAR(4) = 0;
    spawn N(802416C0);
    SI_VAR(0) = -420;
    SI_VAR(1) = -260;
    SI_VAR(2) = -140;
    SI_VAR(3) = 160;
    SI_VAR(4) = 0;
    spawn N(802416C0);
    ModifyColliderFlags(0, 26, 0x7FFFFE00);
    ModifyColliderFlags(0, 18, 0x7FFFFE00);
    ModifyColliderFlags(0, 14, 0x7FFFFE00);
    ModifyColliderFlags(0, 6, 0x7FFFFE00);
    spawn N(enterWalk_8024205C);
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) != 1) {
        GetEntryID(SI_VAR(0));
        if (SI_VAR(0) == 10) {
            sleep 65;
        }
    }
    await N(802414D0);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_C9DF20)();
    }
    spawn {
        EnableTexPanning(35, 1);
        SI_VAR(0) = 0;
0:
        RandInt(300, SI_VAR(1));
        SI_VAR(1) += 100;
        RandInt(1, SI_VAR(2));
        SI_VAR(2) += 1;
        sleep SI_VAR(1);
        loop SI_VAR(2) {
            SetTexPanOffset(12, 0, -32768, 0);
            sleep 2;
            SetTexPanOffset(12, 0, -65536, 0);
            sleep 2;
            SetTexPanOffset(12, 0, -98304, 0);
            RandInt(5, SI_VAR(3));
            SI_VAR(3) += 2;
            sleep SI_VAR(3);
            SetTexPanOffset(12, 0, -65536, 0);
            sleep 2;
            SetTexPanOffset(12, 0, -32768, 0);
            sleep 2;
            SetTexPanOffset(12, 0, 0, 0);
            RandInt(5, SI_VAR(3));
            SI_VAR(3) += 2;
            sleep SI_VAR(3);
        }
        goto 0;
    }
});

NpcSettings N(npcSettings_80242840) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcAISettings N(npcAISettings_8024286C) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .unk_14 = -1,
    .unk_2C = 1,
};

Script N(npcAI_8024289C) = SCRIPT({
    N(func_80240BD4_C9EAF4)(N(npcAISettings_8024286C));
});

NpcSettings N(npcSettings_802428BC) = {
    .height = 42,
    .radius = 28,
    .ai = &N(npcAI_8024289C),
    .level = 99,
};

NpcSettings N(npcSettings_802428E8) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_80242914) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80242940) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_8024296C) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

const char N(flo_07_name_hack)[];

Script N(80242998) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    UseSettingsFrom(0, 50, 0, -200);
    SetPanTarget(0, 50, 0, -200);
    SetCamDistance(0, 700);
    SetCamPitch(0, 10.0, -11.0);
    SetCamPosA(0, -27, 0);
    SetCamPosB(0, 0, -50);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 20;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x00C4), 0, 50, -200);
    sleep 10;
    GotoMap(N(flo_07_name_hack), 1);
    sleep 100;
});

Script N(80242AF0) = SCRIPT({
    DisablePlayerInput(TRUE);
    UseSettingsFrom(0, 0, 0, -170);
    SetPanTarget(0, 0, 0, -170);
    SetCamDistance(0, 300);
    SetCamPitch(0, 17.0, -8.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 75;
    ShowMessageAtScreenPos(MESSAGE_ID(0x11, 0x0000), 160, 40);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerJumpscale(1.5);
    PlayerJump1(SI_VAR(0), SI_VAR(1), SI_VAR(2), 12);
    sleep 10;
    DisablePartnerAI(0);
    InterpPlayerYaw(270, 0);
    InterpNpcYaw(NPC_PARTNER, 270, 0);
    sleep 15;
    InterpPlayerYaw(90, 0);
    InterpNpcYaw(NPC_PARTNER, 90, 0);
    sleep 15;
    SetCamDistance(0, 800);
    SetCamPitch(0, 15.0, -5.7998046875);
    SetCamPosA(0, -2, 0);
    PanToTarget(0, 0, 1);
    sleep 15;
    SpeakToPlayer(NPC_BUBULB0, -1, -1, 5, MESSAGE_ID(0x11, 0x0001));
    SetPlayerAnimation(ANIM_10002);
    InterpPlayerYaw(350, 0);
    sleep 15;
    ContinueSpeech(0, -1, -1, 5, MESSAGE_ID(0x11, 0x0002));
    sleep 10;
    SetCamDistance(0, 333);
    SetCamPitch(0, 9.0, -22.0);
    SetCamPosA(0, -2, 0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    EnablePartnerAI();
    func_802D2C14(1);
    sleep 10;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0003), 0, 70, -200);
    SetCamPitch(0, 16.5, -11.7998046875);
    SetCamDistance(0, 525);
    SetCamPosA(0, -14, 0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    SetPlayerAnimation(ANIM_80007);
    sleep 20;
    SetPlayerAnimation(ANIM_10002);
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0004), 0, 50, -200);
    SetCamPitch(0, 9.0, -22.0);
    SetCamDistance(0, 333);
    SetCamPosA(0, -2, 0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0005), 0, 70, -200);
    ResetCam(0, 90.0);
    STORY_PROGRESS = STORY_CH6_ARRIVED_AT_FLOWER_FIELDS;
    func_802D2C14(0);
    DisablePlayerInput(FALSE);
});

Script N(80242FCC) = SCRIPT({
    DisablePlayerInput(TRUE);
    sleep 2;
    GetPlayerActionState(SI_VAR(3));
    SI_VAR(4) = 0;
    if (SI_VAR(3) == 0) {
        SI_VAR(4) += 1;
    }
    if (SI_VAR(3) == 1) {
        SI_VAR(4) += 1;
    }
    if (SI_VAR(3) == 2) {
        SI_VAR(4) += 1;
    }
    if (SI_VAR(4) == 0) {
        DisablePlayerInput(FALSE);
        return;
    }
    if (STORY_PROGRESS == STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0006), 0, 50, -200);
        STORY_PROGRESS = STORY_CH6_WISTERWOOD_GAVE_HINT;
        DisablePlayerInput(FALSE);
        return;
    }
    if (STORY_PROGRESS < STORY_CH6_RETURNED_TO_TOAD_TOWN) {
        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x000D), 0, 50, -200);
        ShowChoice(MESSAGE_ID(0x1E, 0x001F));
        sleep 10;
        match SI_VAR(0) {
            == 0 {
                match STORY_PROGRESS {
                    < STORY_CH6_GOT_MAGICAL_BEAN {
                        SwitchMessage(MESSAGE_ID(0x11, 0x000E));
                    }
                    < STORY_CH6_GOT_FERTILE_SOIL {
                        SwitchMessage(MESSAGE_ID(0x11, 0x000F));
                    }
                    < STORY_CH6_FILLED_SPRING_WITH_WATER {
                        SwitchMessage(MESSAGE_ID(0x11, 0x0010));
                    }
                    < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
                        SwitchMessage(MESSAGE_ID(0x11, 0x0011));
                    }
                    < STORY_CH6_GREW_MAGIC_BEANSTALK {
                        SwitchMessage(MESSAGE_ID(0x11, 0x0007));
                    }
                    < STORY_CH6_BEGAN_PEACH_MISSION {
                        SwitchMessage(MESSAGE_ID(0x11, 0x0012));
                    } else {
                        SwitchMessage(MESSAGE_ID(0x11, 0x0013));
                    }
                }
            }
            == 1 {
                CloseMessage();
                spawn N(8024196C);
                return;
            }
            == 2 {
                CloseMessage();
            }
        }
    } else {
        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0014), 0, 50, -200);
        ShowChoice(MESSAGE_ID(0x1E, 0x001F));
        sleep 10;
        match SI_VAR(0) {
            == 0 {
                SwitchMessage(MESSAGE_ID(0x11, 0x0015));
            }
            == 1 {
                CloseMessage();
                spawn N(8024196C);
                return;
            }
            == 2 {
                CloseMessage();
            }
        }
    }
    DisablePlayerInput(FALSE);
});

Script N(80243368) = SCRIPT({
    AdjustCam(0, 90.0, 0, 600, 21.0, -12.0);
    sleep 20;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x000B), 0, 50, -200);
    SetPanTarget(0, 0, 0, -30);
    SetCamDistance(0, 250);
    SetCamPitch(0, 25.0, -25.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x000C), 0, 50, -200);
    ResetCam(0, 90.0);
});

Script N(init_80243474) = SCRIPT({
    EnableGroup(121, 0);
    EnableGroup(80, 0);
    EnableGroup(132, 0);
    SetNpcPos(NPC_SELF, 50, 70, -230);
    SetNpcFlagBits(NPC_SELF, ((0x00000002)), TRUE);
    EnableNpcShadow(NPC_SELF, FALSE);
    if (STORY_PROGRESS < STORY_CH6_ARRIVED_AT_FLOWER_FIELDS) {
        spawn N(80242AF0);
    }
});

Script N(interact_8024352C) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_3), NPC_ANIM(bubulb, Palette_00, Anim_2), 0, MESSAGE_ID(0x11, 0x0016));
        }
        < STORY_CH6_GOT_FERTILE_SOIL {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_3), NPC_ANIM(bubulb, Palette_00, Anim_2), 0, MESSAGE_ID(0x11, 0x0017));
        }
        < STORY_CH6_FILLED_SPRING_WITH_WATER {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_3), NPC_ANIM(bubulb, Palette_00, Anim_2), 0, MESSAGE_ID(0x11, 0x0018));
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_3), NPC_ANIM(bubulb, Palette_00, Anim_2), 0, MESSAGE_ID(0x11, 0x0019));
        }
        < STORY_CH6_STAR_SPIRIT_RESCUED {
            match SI_AREA_FLAG(18) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_9), NPC_ANIM(bubulb, Palette_00, Anim_8), 0, MESSAGE_ID(0x11, 0x001A));
                    SI_AREA_FLAG(18) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_9), NPC_ANIM(bubulb, Palette_00, Anim_8), 0, MESSAGE_ID(0x11, 0x001B));
                    SI_AREA_FLAG(18) = 0;
                }
            }
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_00, Anim_9), NPC_ANIM(bubulb, Palette_00, Anim_8), 0, MESSAGE_ID(0x11,
                          0x001C));
        }
    }
});

Script N(interact_802436C0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x001D));
        }
        < STORY_CH6_GOT_FERTILE_SOIL {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x001E));
        }
        < STORY_CH6_FILLED_SPRING_WITH_WATER {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x001F));
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x0020));
        }
        < STORY_CH6_STAR_SPIRIT_RESCUED {
            match SI_AREA_FLAG(19) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x0021));
                    SI_AREA_FLAG(19) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11, 0x0022));
                    SI_AREA_FLAG(19) = 0;
                }
            }
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_01, Anim_3), NPC_ANIM(bubulb, Palette_01, Anim_2), 0, MESSAGE_ID(0x11,
                          0x0023));
        }
    }
});

Script N(interact_80243854) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_3), NPC_ANIM(bubulb, Palette_02, Anim_2), 0, MESSAGE_ID(0x11, 0x0024));
        }
        < STORY_CH6_GOT_FERTILE_SOIL {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_3), NPC_ANIM(bubulb, Palette_02, Anim_2), 0, MESSAGE_ID(0x11, 0x0025));
        }
        < STORY_CH6_FILLED_SPRING_WITH_WATER {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_3), NPC_ANIM(bubulb, Palette_02, Anim_2), 0, MESSAGE_ID(0x11, 0x0026));
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_3), NPC_ANIM(bubulb, Palette_02, Anim_2), 0, MESSAGE_ID(0x11, 0x0027));
        }
        < STORY_CH6_STAR_SPIRIT_RESCUED {
            match SI_AREA_FLAG(20) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_9), NPC_ANIM(bubulb, Palette_02, Anim_8), 0, MESSAGE_ID(0x11, 0x0028));
                    SI_AREA_FLAG(20) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_9), NPC_ANIM(bubulb, Palette_02, Anim_8), 0, MESSAGE_ID(0x11, 0x0029));
                    SI_AREA_FLAG(20) = 0;
                }
            }
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_02, Anim_9), NPC_ANIM(bubulb, Palette_02, Anim_8), 0, MESSAGE_ID(0x11,
                          0x002A));
        }
    }
});

Script N(interact_802439E8) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_3), NPC_ANIM(bubulb, Palette_03, Anim_2), 0, MESSAGE_ID(0x11, 0x002B));
        }
        < STORY_CH6_GOT_FERTILE_SOIL {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_3), NPC_ANIM(bubulb, Palette_03, Anim_2), 0, MESSAGE_ID(0x11, 0x002C));
        }
        < STORY_CH6_FILLED_SPRING_WITH_WATER {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_3), NPC_ANIM(bubulb, Palette_03, Anim_2), 0, MESSAGE_ID(0x11, 0x002D));
        }
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_3), NPC_ANIM(bubulb, Palette_03, Anim_2), 0, MESSAGE_ID(0x11, 0x002E));
        }
        < STORY_CH6_STAR_SPIRIT_RESCUED {
            match SI_AREA_FLAG(21) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_9), NPC_ANIM(bubulb, Palette_03, Anim_8), 0, MESSAGE_ID(0x11, 0x002F));
                    SI_AREA_FLAG(21) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_9), NPC_ANIM(bubulb, Palette_03, Anim_8), 0, MESSAGE_ID(0x11, 0x0030));
                    SI_AREA_FLAG(21) = 0;
                }
            }
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(bubulb, Palette_03, Anim_9), NPC_ANIM(bubulb, Palette_03, Anim_8), 0, MESSAGE_ID(0x11,
                          0x0031));
        }
    }
});

Script N(init_80243B7C) = SCRIPT({
    SI_AREA_FLAG(18) = 0;
    BindNpcInteract(NPC_SELF, N(interact_8024352C));
});

Script N(init_80243BB0) = SCRIPT({
    SI_AREA_FLAG(19) = 0;
    BindNpcInteract(NPC_SELF, N(interact_802436C0));
});

Script N(init_80243BE4) = SCRIPT({
    SI_AREA_FLAG(20) = 0;
    BindNpcInteract(NPC_SELF, N(interact_80243854));
});

Script N(init_80243C18) = SCRIPT({
    SI_AREA_FLAG(21) = 0;
    BindNpcInteract(NPC_SELF, N(interact_802439E8));
});

Script N(interact_80243C4C) = SCRIPT({
    if (SI_SAVE_FLAG(1373) == 0) {
        AdjustCam(0, 4.0, -30, 300, 20.0, -9.5);
        SI_SAVE_FLAG(1373) = 1;
    }
    match STORY_PROGRESS {
        < STORY_CH6_GOT_MAGICAL_BEAN {
            match SI_AREA_VAR(0) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0035));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0038));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 2;
                }
                == 2 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0039));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 0;
                }
            }
        }
        < 47 {
            match SI_AREA_VAR(0) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0036));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0038));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 2;
                }
                == 2 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0039));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 0;
                }
            }
        }
        < 53 {
            match SI_AREA_VAR(0) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0037));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0038));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 2;
                }
                == 2 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0039));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 0;
                }
            }
        }
        < 57 {
            match SI_AREA_VAR(0) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0039));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                    SI_AREA_VAR(0) = 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0038));
                    EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
                }
            }
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(tolielup, Palette_00, Anim_2), NPC_ANIM(tolielup, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x11, 0x003A));
            EndSpeech(-1, NPC_ANIM(tolielup, Palette_00, Anim_3), NPC_ANIM(tolielup, Palette_00, Anim_3), 0);
        }
    }
    ResetCam(0, 4.0);
});

Script N(init_8024414C) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80243C4C));
    SetNpcCollisionSize(-1, 65, 50);
});

Script N(idle_80244188) = SCRIPT({
    loop {
        loop 10 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) -= 1;
            SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
        loop 10 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
});

Script N(8024427C) = SCRIPT({
    DisablePartnerAI(0);
    func_802CF56C(2);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(0);
    SI_VAR(3) += -50;
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(4) += 26;
    SetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(3), SI_VAR(4), SI_VAR(2));
    PlayerFaceNpc(6, 0);
    NpcFaceNpc(NPC_PARTNER, NPC_WORLD_KLEVAR, 0);
    SI_VAR(0) += -25;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 475.0);
    SetCamPitch(0, 18, -8);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 1;
    WaitForPlayerInputEnabled();
    DisablePlayerInput(TRUE);
    sleep 40;
    SpeakToPlayer(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_3), NPC_ANIM(world_klevar, Palette_00, Anim_1), 512, MESSAGE_ID(0x11, 0x00D8));
    SetCamDistance(0, 300.0);
    SetCamPitch(0, 18, -9);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    MakeLerp(0, 360, 10, 0);
    loop {
        UpdateLerp();
        SetNpcRotation(NPC_WORLD_KLEVAR, 0, SI_VAR(0), 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    EnableNpcAI(6, 0);
    SetNpcAnimation(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_4));
    sleep 20;
    SetPlayerAnimation(ANIM_GOT_ITEM);
    PlaySoundAtPlayer(313, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(1);
    SI_VAR(1) += 50;
    SI_VAR(2) += 10;
    SI_VAR(3) += 30;
    loop 5 {
        PlayEffect(0x11, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 6;
        PlayEffect(0x11, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 6;
    }
    sleep 20;
    PlaySoundAtPlayer(392, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(0x52, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 30, 0, 0, 0, 0, 0, 0, 0);
    sleep 30;
    SetPlayerAnimation(ANIM_10002);
    SetNpcAnimation(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_1));
    EnableNpcAI(6, 1);
    N(PostChapter6StatUpdate)();
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0196), 160, 40);
    sleep 10;
    GetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 250.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    SpeakToPlayer(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_3), NPC_ANIM(world_klevar, Palette_00, Anim_1), 512, MESSAGE_ID(0x11, 0x00D9));
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -25;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300.0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    SpeakToPlayer(NPC_WORLD_KLEVAR, NPC_ANIM(world_klevar, Palette_00, Anim_3), NPC_ANIM(world_klevar, Palette_00, Anim_1), 512, MESSAGE_ID(0x11, 0x00DA));
    SetNpcFlagBits(NPC_WORLD_KLEVAR, ((NPC_FLAG_40000)), TRUE);
    spawn {
        loop 25 {
            GetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 4;
        }
    }
    spawn {
        SI_VAR(2) = 0;
        SI_VAR(3) = 1800;
        MakeLerp(SI_VAR(2), SI_VAR(3), 100, 2);
        loop {
            UpdateLerp();
            SetNpcRotation(NPC_WORLD_KLEVAR, 0, SI_VAR(0), 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    spawn {
        GetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        SI_VAR(5) = SI_VAR(3);
        SI_VAR(5) += 180;
        MakeLerp(SI_VAR(3), SI_VAR(5), 100, 2);
        loop {
            UpdateLerp();
            SetNpcPos(NPC_WORLD_KLEVAR, SI_VAR(2), SI_VAR(0), SI_VAR(4));
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        SetNpcPos(NPC_WORLD_KLEVAR, 0, -1000, 0);
    }
    spawn {
        sleep 15;
        PlaySoundAtNpc(NPC_WORLD_KLEVAR, 0x2045, 0);
    }
    sleep 10;
    SetPlayerAnimation(0x1002A);
    sleep 110;
    SetPlayerAnimation(ANIM_10002);
    STORY_PROGRESS = STORY_CH6_STAR_SPRIT_DEPARTED;
    await N(80243368);
    EnablePartnerAI();
    DisablePlayerInput(FALSE);
});

Script N(init_80244BF4) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) != 1) {
        GetEntryID(SI_VAR(0));
        if (SI_VAR(0) == 10) {
            BindNpcIdle(NPC_SELF, N(idle_80244188));
            spawn N(8024427C);
        } else {
            SetNpcPos(NPC_SELF, 0, -1000, 0);
        }
    }
});

Script N(interact_80244C98) = SCRIPT({
    if (STORY_PROGRESS <= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SpeakToPlayer(NPC_LAKILULU, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0,
                      MESSAGE_ID(0x11, 0x0032));
    } else {
        GetCurrentPartnerID(SI_VAR(0));
        if (SI_VAR(0) == 8) {
            SpeakToPlayer(NPC_LAKILULU, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x11, 0x0032));
            sleep 10;
            DisablePartnerAI(0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_B), NPC_ANIM(world_lakilester, Palette_00,
                          Anim_3), 5, MESSAGE_ID(0x11, 0x0033));
            SetNpcAnimation(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
            EndSpeech(-4, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 5);
            EnablePartnerAI();
        } else {
            SpeakToPlayer(NPC_LAKILULU, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x11, 0x0034));
        }
    }
});

Script N(init_80244DD0) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH6_BEGAN_PEACH_MISSION) {
        BindNpcInteract(NPC_SELF, N(interact_80244C98));
        SetNpcCollisionSize(-1, 36, 28);
        SetNpcPos(NPC_SELF, -200, 15, -300);
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

StaticNpc N(npcGroup_80244E64) = {
    .id = NPC_BUBULB0,
    .settings = &N(npcSettings_80242840),
    .pos = { -72.0f, 60.0f, -100.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80243474),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_E),
        NPC_ANIM(bubulb, Palette_00, Anim_E),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
        NPC_ANIM(bubulb, Palette_00, Anim_2),
    },
};

StaticNpc N(npcGroup_80245054)[] = {
    {
        .id = NPC_BUBULB1,
        .settings = &N(npcSettings_802428BC),
        .pos = { -59.0f, 0.0f, -40.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243B7C),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, -59, 0, -40, -80, 0, -40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 },
        .animations = {
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_E),
            NPC_ANIM(bubulb, Palette_00, Anim_E),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
            NPC_ANIM(bubulb, Palette_00, Anim_2),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D5),
    },
    {
        .id = NPC_BUBULB2,
        .settings = &N(npcSettings_802428BC),
        .pos = { 67.0f, 0.0f, 85.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243BB0),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 67, 0, 85, 97, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 },
        .animations = {
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_E),
            NPC_ANIM(bubulb, Palette_01, Anim_E),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
            NPC_ANIM(bubulb, Palette_01, Anim_2),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D6),
    },
    {
        .id = NPC_BUBULB3,
        .settings = &N(npcSettings_802428BC),
        .pos = { 90.0f, 0.0f, 410.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243BE4),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 90, 0, 410, 120, 0, 410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 },
        .animations = {
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_E),
            NPC_ANIM(bubulb, Palette_02, Anim_E),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
            NPC_ANIM(bubulb, Palette_02, Anim_2),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D7),
    },
    {
        .id = NPC_BUBULB4,
        .settings = &N(npcSettings_802428BC),
        .pos = { 200.0f, 0.0f, 430.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243C18),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 200, 0, 430, 240, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 },
        .animations = {
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_E),
            NPC_ANIM(bubulb, Palette_03, Anim_E),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
            NPC_ANIM(bubulb, Palette_03, Anim_2),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D8),
    },
};

StaticNpc N(npcGroup_80245814) = {
    .id = NPC_TOLIELUP,
    .settings = &N(npcSettings_802428E8),
    .pos = { -400.0f, 0.0f, 190.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_8024414C),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
        NPC_ANIM(tolielup, Palette_00, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00D9),
};

StaticNpc N(npcGroup_80245A04) = {
    .id = NPC_WORLD_KLEVAR,
    .settings = &N(npcSettings_80242914),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80244BF4),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_0),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
        NPC_ANIM(world_klevar, Palette_00, Anim_1),
    },
};

StaticNpc N(npcGroup_80245BF4) = {
    .id = NPC_LAKILULU,
    .settings = &N(npcSettings_80242840),
    .pos = { 198.0f, 0.0f, 363.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80244DD0),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
        NPC_ANIM(lakilulu, Palette_00, Anim_1),
    },
    .tattle = MESSAGE_ID(0x1A, 0x00E2),
};

NpcGroupList N(npcGroupList_80245DE4) = {
    NPC_GROUP(N(npcGroup_80244E64), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80245054), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80245814), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80245A04), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80245BF4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_5E2C) = {
    0x00000000,
};

NpcSettings N(npcSettings_80245E30) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80245E5C) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .unk_2A = 16,
};

f32 N(D_80245E88_CA3DA8)[] = {
    266.0f,  20.0f, 322.0f, 310.0f,
    30.0f, 312.0f, 346.0f,  90.0f,
    300.0f, 400.0f, 200.0f, 287.0f,
};

const char N(sam_11_name_hack)[];

Script N(80245EB8) = SCRIPT({
    SetPlayerPos(-400, 0, 200);
    SetNpcPos(NPC_PARTNER, -380, 0, 200);
    func_802CF56C(2);
    DisablePartnerAI(0);
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SI_VAR(0) = 230;
    SI_VAR(1) = 0;
    SI_VAR(2) = 350;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 17.0, -10.0);
    SetCamDistance(0, 350);
    SetCamPosA(0, 17.5, 35.0);
    SetCamPosB(0, 0, -50);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 70;
    InterpNpcYaw(NPC_BUBULB0, 90, 0);
    sleep 10;
    SetNpcAnimation(NPC_BUBULB0, NPC_ANIM(world_lakilester, Palette_00, Anim_9));
    sleep 40;
    SetNpcAnimation(NPC_BUBULB0, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
    SetNpcAnimation(NPC_BUBULB2, NPC_ANIM(world_parakarry, Palette_00, Anim_6));
    sleep 40;
    SetNpcAnimation(NPC_BUBULB2, NPC_ANIM(world_parakarry, Palette_00, Anim_1));
    InterpNpcYaw(NPC_BUBULB2, 90, 0);
    NpcFlyTo(2, 400, 200, 287, 80, -5, 0);
    InterpNpcYaw(NPC_BUBULB0, 270, 0);
    sleep 40;
    FadeOutMusic(0, 1000);
    GotoMap(N(sam_11_name_hack), 2);
    sleep 100;
});

Script N(init_80246170) = SCRIPT({
    SetPlayerPos(-400, 0, 200);
    SetNpcPos(NPC_PARTNER, -380, 0, 200);
    SetNpcPos(NPC_BUBULB0, 196, 20, 354);
    SetNpcYaw(NPC_BUBULB0, 270);
});

Script N(init_802461E4) = SCRIPT({
    SetNpcPos(NPC_BUBULB1, 163, 20, 370);
    SetNpcYaw(NPC_BUBULB1, 90);
});

Script N(init_80246224) = SCRIPT({
    SetNpcPos(NPC_BUBULB2, 266, 20, 322);
    SetNpcYaw(NPC_BUBULB2, 270);
});

StaticNpc N(npcGroup_80246264)[] = {
    {
        .id = NPC_BUBULB0,
        .settings = &N(npcSettings_80245E30),
        .pos = { 144.0f, 0.0f, 374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80246170),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
            NPC_ANIM(world_lakilester, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_BUBULB1,
        .settings = &N(npcSettings_80245E30),
        .pos = { 198.0f, 0.0f, 363.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802461E4),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
            NPC_ANIM(lakilulu, Palette_00, Anim_1),
        },
    },
    {
        .id = NPC_BUBULB2,
        .settings = &N(npcSettings_80245E5C),
        .pos = { 266.0f, 0.0f, 322.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80246224),
        .yaw = 0,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_2),
            NPC_ANIM(world_parakarry, Palette_00, Anim_3),
            NPC_ANIM(world_parakarry, Palette_00, Anim_3),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_0),
            NPC_ANIM(world_parakarry, Palette_00, Anim_0),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
            NPC_ANIM(world_parakarry, Palette_00, Anim_1),
        },
    },
};

NpcGroupList N(npcGroupList_80246834) = {
    NPC_GROUP(N(npcGroup_80246264), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_684C) = {
    0x00000000,
};

Script N(80246850) = SCRIPT({
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) -= -700.0;
    SI_VAR(1) /= 100.0;
    SI_VAR(2) = (float) SI_VAR(1);
    SI_VAR(2) *= 100.0;
    if (SI_VAR(2) > 100) {
        SI_VAR(1) = 1.0;
    }
    ScaleGroup(74, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(89, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(91, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(93, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(95, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(97, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(99, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(101, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(103, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(105, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(107, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(109, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(111, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(113, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(115, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(117, SI_VAR(1), 1, SI_VAR(1));
    ScaleModel(119, SI_VAR(1), 1, SI_VAR(1));
    TranslateGroup(74, 0, SI_VAR(0), 0);
    TranslateModel(89, 0, SI_VAR(0), 0);
    TranslateModel(91, 0, SI_VAR(0), 0);
    TranslateModel(93, 0, SI_VAR(0), 0);
    TranslateModel(95, 0, SI_VAR(0), 0);
    TranslateModel(97, 0, SI_VAR(0), 0);
    TranslateModel(99, 0, SI_VAR(0), 0);
    TranslateModel(101, 0, SI_VAR(0), 0);
    TranslateModel(103, 0, SI_VAR(0), 0);
    TranslateModel(105, 0, SI_VAR(0), 0);
    TranslateModel(107, 0, SI_VAR(0), 0);
    TranslateModel(109, 0, SI_VAR(0), 0);
    TranslateModel(111, 0, SI_VAR(0), 0);
    TranslateModel(113, 0, SI_VAR(0), 0);
    TranslateModel(115, 0, SI_VAR(0), 0);
    TranslateModel(117, 0, SI_VAR(0), 0);
    TranslateModel(119, 0, SI_VAR(0), 0);
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) *= -12.0;
    RotateGroup(74, SI_VAR(1), 0, 1, 0);
    RotateModel(89, SI_VAR(1), 0, 1, 0);
    RotateModel(91, SI_VAR(1), 0, 1, 0);
    RotateModel(93, SI_VAR(1), 0, 1, 0);
    RotateModel(95, SI_VAR(1), 0, 1, 0);
    RotateModel(97, SI_VAR(1), 0, 1, 0);
    RotateModel(99, SI_VAR(1), 0, 1, 0);
    RotateModel(101, SI_VAR(1), 0, 1, 0);
    RotateModel(103, SI_VAR(1), 0, 1, 0);
    RotateModel(105, SI_VAR(1), 0, 1, 0);
    RotateModel(107, SI_VAR(1), 0, 1, 0);
    RotateModel(109, SI_VAR(1), 0, 1, 0);
    RotateModel(111, SI_VAR(1), 0, 1, 0);
    RotateModel(113, SI_VAR(1), 0, 1, 0);
    RotateModel(115, SI_VAR(1), 0, 1, 0);
    RotateModel(117, SI_VAR(1), 0, 1, 0);
    RotateModel(119, SI_VAR(1), 0, 1, 0);
    TranslateModel(89, 8.1220703125, 56.1533203125, 1.166015625);
    TranslateModel(91, -6.8779296875, 91.1533203125, 1.166015625);
    TranslateModel(93, 13.1220703125, 106.1533203125, 1.166015625);
    TranslateModel(95, -9.8779296875, 136.1533203125, 1.166015625);
    TranslateModel(97, -7.8779296875, 201.1533203125, 1.166015625);
    TranslateModel(99, 13.1220703125, 221.1533203125, 1.166015625);
    TranslateModel(101, 8.126953125, 261.2294921875, 1.166015625);
    TranslateModel(103, -12.8779296875, 266.1533203125, 1.166015625);
    TranslateModel(105, 8.1220703125, 316.1533203125, -13.833984375);
    TranslateModel(107, -10.943359375, 391.1533203125, 10.56640625);
    TranslateModel(109, -7.001953125, 456.1533203125, 0.947265625);
    TranslateModel(111, 12.998046875, 471.1533203125, 0.947265625);
    TranslateModel(113, -10.001953125, 501.1533203125, 0.947265625);
    TranslateModel(115, 8.0029296875, 536.2294921875, 0.947265625);
    TranslateModel(117, 12.998046875, 586.1533203125, 0.947265625);
    TranslateModel(119, -13.001953125, 631.1533203125, 0.947265625);
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) -= -700.0;
    SI_VAR(1) /= 300.0;
    SI_VAR(2) = (float) SI_VAR(1);
    SI_VAR(2) *= 100.0;
    if (SI_VAR(2) > 100) {
        SI_VAR(1) = 1.0;
    }
    ScaleModel(89, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(91, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(93, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(95, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(97, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(99, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(101, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(103, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(105, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(107, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(109, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(111, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(113, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(115, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(117, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    ScaleModel(119, SI_VAR(1), SI_VAR(1), SI_VAR(1));
    TranslateModel(89, -8.12109375, -56.15234375, -1.1650390625);
    TranslateModel(91, 6.87890625, -91.15234375, -1.1650390625);
    TranslateModel(93, -13.12109375, -106.15234375, -1.1650390625);
    TranslateModel(95, 9.87890625, -136.15234375, -1.1650390625);
    TranslateModel(97, 7.87890625, -201.15234375, -1.1650390625);
    TranslateModel(99, -13.12109375, -221.15234375, -1.1650390625);
    TranslateModel(101, -8.1259765625, -261.228515625, -1.1650390625);
    TranslateModel(103, 12.87890625, -266.15234375, -1.1650390625);
    TranslateModel(105, -8.12109375, -316.15234375, 13.8349609375);
    TranslateModel(107, 10.9443359375, -391.15234375, -10.5654296875);
    TranslateModel(109, 7.0029296875, -456.15234375, -0.9462890625);
    TranslateModel(111, -12.9970703125, -471.15234375, -0.9462890625);
    TranslateModel(113, 10.0029296875, -501.15234375, -0.9462890625);
    TranslateModel(115, -8.001953125, -536.228515625, -0.9462890625);
    TranslateModel(117, -12.9970703125, -586.15234375, -0.9462890625);
    TranslateModel(119, 13.0029296875, -631.15234375, -0.9462890625);
});

Script N(80247488) = SCRIPT({
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) -= -700.0;
    SI_VAR(1) /= 100.0;
    SI_VAR(2) = (float) SI_VAR(1);
    SI_VAR(2) *= 100.0;
    if (SI_VAR(2) > 100) {
        SI_VAR(1) = 1.0;
    }
    ScaleGroup(79, SI_VAR(1), 1, SI_VAR(1));
    TranslateGroup(79, 0, SI_VAR(0), 0);
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) *= -12.0;
    RotateGroup(79, SI_VAR(1), 0, 1, 0);
});

Script N(80247588) = SCRIPT({
    TranslateModel(83, 9.5, 12.0, 15.0);
    TranslateModel(85, -9.5, 12.0, 15.0);
    TranslateModel(87, 0.0, 0.0, 17.0);
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) *= 90.0;
    RotateModel(83, SI_VAR(1), 0, 0, -1);
    RotateModel(85, SI_VAR(1), 0, 0, 1);
    TranslateModel(83, -9.5, -12.0, -15.0);
    TranslateModel(85, 9.5, -12.0, -15.0);
    TranslateModel(87, 0.0, 0.0, -17.0);
    ScaleModel(83, SI_VAR(0), SI_VAR(0), SI_VAR(0));
    ScaleModel(85, SI_VAR(0), SI_VAR(0), SI_VAR(0));
    ScaleModel(87, SI_VAR(0), SI_VAR(0), SI_VAR(0));
});

Script N(802476F4) = SCRIPT({
    ScaleModel(81, SI_VAR(0), SI_VAR(0), SI_VAR(0));
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) *= 90.0;
    SI_VAR(1) += -90.0;
    RotateModel(81, SI_VAR(1), 1, 0, 0);
});

Script N(80247770) = SCRIPT({
    SI_VAR(1) = (float) SI_VAR(0);
    SI_VAR(1) *= -3.0;
    TranslateModel(81, -0.259765625, SI_VAR(0), 1.4775390625);
    RotateModel(81, SI_VAR(1), 0, 1, 0);
    UpdateColliderTransform(46);
});

const char N(flo_19_name_hack)[];

Script N(802477EC) = SCRIPT({
    if (SI_AREA_FLAG(44) == 0) {
        DisablePlayerInput(TRUE);
        func_802D2B6C();
        sleep 15;
        DisablePartnerAI(0);
        SI_AREA_FLAG(44) = 1;
        ModifyColliderFlags(0, 47, 0x7FFFFE00);
        ModifyColliderFlags(0, 48, 0x7FFFFE00);
        SI_VAR(9) = (int) -59.0;
        SI_VAR(10) = (int) 22.0;
        SI_VAR(11) = (int) 125.0;
        SI_VAR(12) = (int) -55.0;
        SI_VAR(13) = (int) 24.0;
        SI_VAR(14) = (int) 145.0;
        PlayerMoveTo(SI_VAR(9), SI_VAR(11), 8);
        SetNpcJumpscale(NPC_PARTNER, 0.0);
        NpcJump0(NPC_PARTNER, SI_VAR(12), SI_VAR(13), SI_VAR(14), 5);
        PlaySound(0x19C);
        SetMusicTrack(0, SONG_MAGIC_BEANSTALK, 1, 8);
        SetNpcAnimation(NPC_PARTNER, 0x106);
        SetPlayerAnimation(ANIM_WALKING);
        N(func_80240F10_C9EE30)(SI_VAR(3), SI_VAR(4));
        match SI_VAR(4) {
            < 90 {
                SI_AREA_FLAG(16) = 0;
                InterpPlayerYaw(90, 0);
                InterpNpcYaw(NPC_PARTNER, 90, 0);
            }
            >= 270 {
                SI_AREA_FLAG(16) = 1;
                InterpPlayerYaw(270, 0);
                InterpNpcYaw(NPC_PARTNER, 270, 0);
            }
        }
        TranslateModel(81, -0.259765625, 2.0, 1.4775390625);
        UpdateColliderTransform(46);
        SI_MAP_VAR(10) = 0;
        spawn {
            SI_VAR(15) = 0;
            loop {
                SI_VAR(15) += 1;
                N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), 0, 700, 800, 0, 0);
                spawn N(80247770);
                SI_VAR(2) = (float) SI_VAR(0);
                SI_VAR(2) *= -3.0;
                SI_VAR(3) = (float) SI_VAR(0);
                N(func_80240F80_C9EEA0)();
                N(func_802410B4_C9EFD4)();
                if (SI_VAR(15) == 350) {
                    SI_MAP_VAR(10) = 1;
                }
                sleep 1;
            }
        }
10:
        if (SI_MAP_VAR(10) == 0) {
            sleep 1;
            goto 10;
        }
        GotoMap(N(flo_19_name_hack), 3);
        sleep 100;
    }
});

Script N(80247BCC) = SCRIPT({
    DisablePlayerInput(TRUE);
    SetPlayerActionState(10);
    ModifyColliderFlags(0, 47, 0x7FFFFE00);
    ModifyColliderFlags(0, 48, 0x7FFFFE00);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    SI_VAR(9) = (int) -59.0;
    SI_VAR(10) = (int) 22.0;
    SI_VAR(11) = (int) 125.0;
    SI_VAR(12) = (int) -55.0;
    SI_VAR(13) = (int) 23.0;
    SI_VAR(14) = (int) 145.0;
    spawn {
        sleep 5;
        SetNpcAnimation(NPC_PARTNER, 0x106);
        SetPlayerAnimation(ANIM_WALKING);
        match SI_AREA_FLAG(16) {
            == 0 {
                InterpPlayerYaw(90, 0);
                InterpNpcYaw(NPC_PARTNER, 90, 0);
            }
            == 1 {
                InterpPlayerYaw(270, 0);
                InterpNpcYaw(NPC_PARTNER, 270, 0);
            }
        }
    }
    TranslateModel(81, -0.259765625, 2.0, 1.4775390625);
    UpdateColliderTransform(46);
    SI_VAR(15) = 0;
    loop 120 {
        SI_VAR(15) += 1;
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), 70, 0, 120, 0, 0);
        spawn N(80247770);
        SI_VAR(2) = (float) SI_VAR(0);
        SI_VAR(2) *= -3.0;
        SI_VAR(3) = (float) SI_VAR(0);
        N(func_80240F80_C9EEA0)();
        N(func_802410B4_C9EFD4)();
        sleep 1;
    }
    EnablePartnerAI();
    ClearPartnerMoveHistory(-4);
    SetPlayerJumpscale(1);
    PlayerJump(10, 0, 110, 20);
    SetPlayerActionState(10);
    InterpPlayerYaw(90, 0);
    sleep 5;
    ModifyColliderFlags(1, 47, 0x7FFFFE00);
    ModifyColliderFlags(1, 48, 0x7FFFFE00);
    SI_AREA_FLAG(44) = 0;
    StopSound(413);
    await N(802414D0);
    ResetCam(0, 1.0);
    DisablePlayerInput(FALSE);
});

Script N(80247FAC) = SCRIPT({
    PlaySoundAtCollider(47, 411, 0);
    SI_VAR(15) = 0;
    loop 100 {
        SI_VAR(15) += 1;
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), 0, 1.0, 100, 0, 0);
        spawn N(80247588);
        sleep 1;
    }
    SI_MAP_VAR(10) = 0;
    spawn {
        SI_VAR(15) = 0;
        loop 1200 {
            SI_VAR(15) += 1;
            N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), -700, 0, 1200, 0, 0);
            SI_VAR(2) = (float) SI_VAR(0);
            SI_VAR(2) *= 1.0;
            SI_VAR(0) = (float) SI_VAR(2);
            spawn N(80246850);
            SI_VAR(2) = (float) SI_VAR(0);
            SI_VAR(2) *= 1.0;
            SI_VAR(0) = (float) SI_VAR(2);
            spawn N(80247488);
            match SI_VAR(15) {
                == 200 {
                    SetPlayerAnimation(0x1002A);
                }
                == 250 {
                    SI_VAR(0) = -60;
                    SI_VAR(1) = 0;
                    SI_VAR(2) = 65;
                    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    SetCamSpeed(0, 90.0);
                    SetCamPitch(0, 12.5, -7.0);
                    SetCamDistance(0, 800);
                    SetCamPosA(0, -200, 0);
                    SetCamPosB(0, 0, -300);
                    PanToTarget(0, 0, 1);
                    WaitForCam(0, 1.0);
                } else {
                }
            }
            if (SI_VAR(15) > 550) {
                SI_MAP_VAR(10) = 1;
            }
            sleep 1;
        }
    }
10:
    if (SI_MAP_VAR(10) == 0) {
        sleep 1;
        goto 10;
    }
    FadeInMusic(0, 50, 0, 3000, 0, 127);
    FadeOutMusic(1, 3000);
    GotoMap(N(flo_19_name_hack), 2);
    sleep 100;
});

Script N(8024834C) = SCRIPT({
    DisablePlayerInput(TRUE);
    InterpPlayerYaw(200, 0);
    SetPlayerPos(-60, 0, 30);
    NpcFacePlayer(NPC_PARTNER, 1);
    SetNpcPos(NPC_PARTNER, -20, 0, 10);
    SI_VAR(0) = -60;
    SI_VAR(1) = 0;
    SI_VAR(2) = 65;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 12.5, -7.0);
    SetCamDistance(0, 800);
    SetCamPosA(0, -200, 0);
    SetCamPosB(0, 0, -300);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SI_VAR(15) = 0;
    loop 5 {
        SI_VAR(15) += 20;
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), 0.0, 1.0, 100, 0, 0);
        spawn N(802476F4);
        sleep 1;
    }
    ModifyColliderFlags(1, 46, 0x7FFFFE00);
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x000A), 0, 50, -200);
    ResetCam(0, 90.0);
    DisablePlayerInput(FALSE);
});

s32 N(itemList_80248598)[] = {
    ITEM_FERTILE_SOIL,
    ITEM_MAGICAL_BEAN,
    ITEM_MIRACLE_WATER,
    ITEM_NONE,
};

Script N(802485A8) = SCRIPT({
    DisablePlayerInput(TRUE);
    func_802D2884(-85, 85, 0);
    func_802CF56C(2);
    DisablePlayerInput(FALSE);
    if (SI_SAVE_FLAG(1371) == 0) {
        group 0;
        SetTimeFreezeMode(1);
10:
        ShowKeyChoicePopup();
        SI_VAR(2) = SI_VAR(0);
        match SI_VAR(2) {
            <= 0 {
                CloseChoicePopup();
                SetTimeFreezeMode(0);
                AwaitPlayerLeave(-85, 85, 28);
                return;
            }
            == 89 {
                SetPlayerAnimation(0x60006);
                sleep 5;
                RemoveKeyItemAt(SI_VAR(1));
                MakeItemEntity(ITEM_FERTILE_SOIL, -83, 0, 87, 1, 0);
                SI_MAP_VAR(11) = SI_VAR(0);
                SetPlayerAnimation(ANIM_STAND_STILL);
                sleep 20;
            } else {
                match SI_AREA_FLAG(17) {
                    == 0 {
                        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0008), 0, 10, -200);
                        SI_AREA_FLAG(17) = 1;
                    } else {
                        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0009), 0, 10, -200);
                    }
                }
            }
        }
        DisablePlayerInput(FALSE);
        DisablePlayerPhysics(FALSE);
        if (SI_VAR(2) != 89) {
            goto 10;
        }
        SI_SAVE_FLAG(1371) = 1;
    }
    if (SI_SAVE_FLAG(1372) == 0) {
        group 0;
        SetTimeFreezeMode(1);
20:
        ShowKeyChoicePopup();
        SI_VAR(2) = SI_VAR(0);
        match SI_VAR(2) {
            <= 0 {
                CloseChoicePopup();
                SetTimeFreezeMode(0);
                AwaitPlayerLeave(-85, 85, 28);
                return;
            }
            == 88 {
                RemoveItemEntity(SI_MAP_VAR(11));
                sleep 5;
                SetPlayerAnimation(0x60006);
                sleep 5;
                RemoveKeyItemAt(SI_VAR(1));
                MakeItemEntity(ITEM_MAGICAL_BEAN, -83, 0, 87, 1, 0);
                SI_MAP_VAR(11) = SI_VAR(0);
                SetPlayerAnimation(ANIM_STAND_STILL);
                sleep 20;
            } else {
                match SI_AREA_FLAG(17) {
                    == 0 {
                        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0008), 0, 10, -200);
                        SI_AREA_FLAG(17) = 1;
                    } else {
                        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x0009), 0, 10, -200);
                    }
                }
            }
        }
        DisablePlayerInput(FALSE);
        DisablePlayerPhysics(FALSE);
        if (SI_VAR(2) != 88) {
            goto 20;
        }
        SI_SAVE_FLAG(1372) = 1;
    }
    group 0;
    SetTimeFreezeMode(1);
30:
    ShowKeyChoicePopup();
    SI_VAR(2) = SI_VAR(0);
    match SI_VAR(2) {
        <= 0 {
            CloseChoicePopup();
            SetTimeFreezeMode(0);
            AwaitPlayerLeave(-85, 85, 28);
            return;
        }
        == 90 {
            RemoveItemEntity(SI_MAP_VAR(11));
            sleep 5;
            SetPlayerAnimation(0x60006);
            sleep 5;
            RemoveKeyItemAt(SI_VAR(1));
            N(SyncStatusMenu)();
            MakeItemEntity(ITEM_MIRACLE_WATER, -83, 0, 87, 1, 0);
            SI_MAP_VAR(11) = SI_VAR(0);
            SetPlayerAnimation(ANIM_STAND_STILL);
            sleep 30;
            RemoveItemEntity(SI_MAP_VAR(11));
            sleep 30;
            ModifyColliderFlags(0, 47, 0x7FFFFE00);
            PlayerMoveTo(-60, 30, 20);
            ModifyColliderFlags(1, 47, 0x7FFFFE00);
            ModifyColliderFlags(1, 48, 0x7FFFFE00);
            InterpPlayerYaw(200, 0);
            func_802CF56C(2);
            sleep 60;
            FadeInMusic(1, 123, 0, 3000, 0, 127);
            FadeOutMusic(0, 3000);
            UseSettingsFrom(0, -85, 0, 75);
            SetPanTarget(0, -85, 0, 75);
            SetCamSpeed(0, 1.0);
            SetCamPitch(0, 17.0, -6.0);
            SetCamDistance(0, 250);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            await N(80247FAC);
        }
    }
    if (SI_VAR(2) != 90) {
        goto 30;
    }
});

Script N(80248D3C) = SCRIPT({
0:
    IsPlayerWithin(-85, 85, 20, SI_VAR(0));
    if (SI_VAR(0) == 0) {
        return;
    } else {
        IsPlayerOnValidFloor(SI_VAR(0));
        if (SI_VAR(0) == 0) {
            sleep 1;
            goto 0;
        }
        GetCurrentPartner(SI_VAR(0));
        if (SI_VAR(0) != 0) {
            return;
        }
    }
    N(func_8024139C_C9F2BC)();
    await N(802485A8);
    N(func_802413BC_C9F2DC)();
});

// *INDENT-OFF*
Script N(80248E30) = {
    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), 55),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(0), 54),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1371), 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1372), 0),
                SI_CMD(ScriptOpcode_CALL, MakeItemEntity, 89, -83, 0, 87, 1, 0),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_CALL, MakeItemEntity, 88, -83, 0, 87, 1, 0),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SET, SI_MAP_VAR(11), SI_VAR(0)),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80248D3C), 0x10, 0, N(itemList_80248598), 0, 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(80248F48) = SCRIPT({
    bind N(802477EC) to TRIGGER_FLOOR_TOUCH 46;
    EnableGroup(121, 1);
    EnableGroup(80, 1);
    match STORY_PROGRESS {
        == STORY_CH6_WISTERWOOD_GAVE_HINT {
            SI_VAR(0) = -700;
            spawn N(80246850);
            spawn N(80247488);
            SI_VAR(0) = 0;
            spawn N(80247588);
            SI_VAR(0) = 0;
            spawn N(802476F4);
            ModifyColliderFlags(0, 46, 0x7FFFFE00);
            ModifyColliderFlags(0, 47, 0x7FFFFE00);
        }
        >= STORY_CH6_GREW_MAGIC_BEANSTALK {
            SI_VAR(0) = 1;
            spawn N(80247588);
            SI_VAR(0) = 1;
            spawn N(802476F4);
        } else {
            SI_VAR(0) = -700;
            spawn N(80246850);
            spawn N(80247488);
            SI_VAR(0) = 0;
            spawn N(80247588);
            SI_VAR(0) = 0;
            spawn N(802476F4);
            ModifyColliderFlags(0, 46, 0x7FFFFE00);
            ModifyColliderFlags(0, 47, 0x7FFFFE00);
        }
    }
});

static s32 N(pad_9128)[] = {
    0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    if (STORY_PROGRESS < STORY_EPILOGUE) {
        MakeEntity(0x802E9A18, 110, 60, -100, 0, MAKE_ENTITY_END);
    }
});

ApiStatus N(func_80240040_C9DF60)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
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

    npc->currentAnim.w = enemy->animList[1];
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

ApiStatus N(func_802406BC_C9E5DC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim.w = enemy->animList[1];
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

ApiStatus N(func_80240BD4_C9EAF4)(ScriptInstance* script, s32 isInitialCall) {
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
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
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
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240040_C9DF60)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_802406BC_C9E5DC)(script, npcAISettings, territoryPtr);
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

ApiStatus N(PostChapter6StatUpdate)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(6);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

const char N(flo_07_name_hack)[] = "flo_07";
const s32 N(pad_XXX)[] = { 0, 0 };
const char N(sam_11_name_hack)[] = "sam_11";
const char N(flo_19_name_hack)[] = "flo_19";
