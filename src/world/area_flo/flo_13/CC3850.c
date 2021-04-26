#include "flo_13.h"
#include "message_ids.h"
#include "sprite/npc/lakilulu.h"
#include "sprite/npc/lakitu.h"
#include "sprite/npc/spiny.h"
#include "sprite/npc/world_lakilester.h"

enum {
    NPC_WORLD_LAKILESTER,
    NPC_LAKILULU0,
    NPC_LAKILULU1,
    NPC_LAKITU0,
    NPC_LAKITU1,
    NPC_SPINY0 = 50,
    NPC_SPINY1,
    NPC_SPINY2,
    NPC_SPINY3,
    NPC_SPINY4,
    NPC_SPINY5,
};

EntryList N(entryList) = {
    {  570.0f, 0.0f, 0.0f, 270.0f },
    { -570.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_flo_13_tattle,
};

Script N(802436D0) = SCRIPT({
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(0) < -500) {
        goto 10;
    }
0:
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
    loop {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(0) < -500) {
            break loop;
        }
        sleep 1;
    }
10:
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_SUN_TOWER_CLOUDY, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_SUN_TOWER_SUNNY, 0, 8);
        }
    }
    loop {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(0) > -500) {
            break loop;
        }
        sleep 1;
    }
    goto 0;
});

Script N(802438B0) = SCRIPT({
    spawn N(802436D0);
});

Script N(802438CC) = SCRIPT({
    SetMusicTrack(0, SONG_NEW_PARTNER, 0, 8);
});

Script N(802438F8) = SCRIPT({
    FadeOutMusic(0, 500);
    sleep 15;
    SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
});

static s32 N(pad_3944)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80243950) = SCRIPT({
    ModifyColliderFlags(0, 14, 0x7FFFFE00);
});

Script N(makeEntities) = SCRIPT({
    MakeItemEntity(ITEM_MEGA_SMASH, -61, 60, -85, 17, SI_SAVE_FLAG(1385));
    MakeItemEntity(ITEM_SHOOTING_STAR, 128, 0, 157, 17, SI_SAVE_FLAG(1386));
    if (SI_SAVE_FLAG(1385) == 0) {
        MakeEntity(0x802BCF00, -160, 160, -90, 0, MAKE_ENTITY_END);
        AssignScript(N(80243950));
    } else {
        ModifyColliderFlags(0, 14, 0x7FFFFE00);
    }
});

static s32 N(pad_3A3C) = {
    0x00000000,
};

Script N(80243A40) = SCRIPT({
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

Script N(exitWalk_80243CEC) = EXIT_WALK_SCRIPT(60,  0, "flo_14",  1);

Script N(exitWalk_80243D48) = EXIT_WALK_SCRIPT(60,  1, "flo_15",  0);

Script N(80243DA4) = SCRIPT({
    bind N(exitWalk_80243D48) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80243CEC) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80247984));
    await N(makeEntities);
    ModifyColliderFlags(3, 13, 0x00000006);
    SI_VAR(0) = 274;
    SI_VAR(1) = -137;
    SI_VAR(2) = 583;
    SI_VAR(3) = -64;
    SI_VAR(4) = 0;
    spawn N(80243A40);
    SI_VAR(0) = 433;
    SI_VAR(1) = 108;
    SI_VAR(2) = 580;
    SI_VAR(3) = 169;
    SI_VAR(4) = 0;
    spawn N(80243A40);
    SI_VAR(0) = -460;
    SI_VAR(1) = 90;
    SI_VAR(2) = -125;
    SI_VAR(3) = 130;
    SI_VAR(4) = 0;
    spawn N(80243A40);
    SI_VAR(0) = -420;
    SI_VAR(1) = -130;
    SI_VAR(2) = -260;
    SI_VAR(3) = -90;
    SI_VAR(4) = 0;
    spawn N(80243A40);
    SI_VAR(0) = -220;
    SI_VAR(1) = -137;
    SI_VAR(2) = 0;
    SI_VAR(3) = -50;
    SI_VAR(4) = 160;
    spawn N(80243A40);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80243DA4);
    spawn EnterWalk;
    await N(802438B0);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CC3810)();
    }
});

NpcSettings N(npcSettings_80244100) = {
    .height = 32,
    .radius = 24,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 20,
};

f32 N(D_8024412C_CC793C)[] = {
     4.5f, 3.5f, 2.6f, 2.0f,
     1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80244144) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 60 },
    .unk_20 = 10,
    .chaseRadius = 80.0f,
    .unk_28 = { .f = 70.0f },
    .unk_2C = 1,
};

Script N(npcAI_80244174) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 400);
    N(func_80241DB8_CC55C8)(N(npcAISettings_80244144));
});

NpcSettings N(npcSettings_802441E4) = {
    .height = 28,
    .radius = 24,
    .ai = &N(npcAI_80244174),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 20,
};

NpcAISettings N(npcAISettings_80244210) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 3,
};

Script N(npcAI_80244240) = SCRIPT({
    SetSelfVar(2, 3);
    SetSelfVar(3, 18);
    SetSelfVar(5, 3);
    SetSelfVar(7, 4);
    N(func_80242A6C_CC627C)(N(npcAISettings_80244210));
});

Script N(802442B0) = SCRIPT({
    SetNpcRotation(NPC_SELF, 0, 0, 0);
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetSelfVar(10, 100);
            DoNpcDefeat();
        }
        == 2 {
            func_80045900(0);
        }
        == 3 {
            SetEnemyFlagBits(-1, 16, 1);
            RemoveNpc(NPC_SELF);
        }
    }
});

NpcSettings N(npcSettings_8024437C) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_80244240),
    .onHit = EnemyNpcHit,
    .onDefeat = &N(802442B0),
    .level = 19,
};

Vec3f N(vectorList_802443A8)[] = {
     { -250.0, 130.0, 100.0 }, { -150.0, 90.0, 70.0 },
     { 50.0, 70.0, 10.0 }, { 200.0, 35.0, 30.0 },
     { 30.0, 10.0, 45.0 },
};

Vec3f N(vectorList_802443E4)[] = {
     { -285.0, 130.0, 45.0 }, { -185.0, 90.0, 25.0 },
     { 15.0, 70.0, 10.0 }, { 165.0, 35.0, 30.0 },
     { -5.0, 10.0, 45.0 },
};

Vec3f N(vectorList_80244420)[] = {
     { 10.0, 0.0, 45.0 }, { -90.0, 20.0, 45.0 },
     { -190.0, 60.0, 45.0 }, { -290.0, 140.0, 45.0 },
     { -390.0, 300.0, 45.0 },
};

Script N(8024445C) = SCRIPT({
    GetNpcPos(NPC_WORLD_LAKILESTER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
0:
    GetNpcPos(NPC_WORLD_LAKILESTER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    N(UnkFunc42)();
    InterpNpcYaw(NPC_WORLD_LAKILESTER, SI_VAR(10), 0);
    SI_VAR(0) = SI_VAR(3);
    SI_VAR(1) = SI_VAR(4);
    SI_VAR(2) = SI_VAR(5);
    GetAngleBetweenNPCs(-4, 0, SI_VAR(10));
    InterpNpcYaw(NPC_PARTNER, SI_VAR(10), 0);
    PlayerFaceNpc(0, 0);
    sleep 1;
    goto 0;
});

Script N(80244560) = SCRIPT({
    GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
0:
    GetNpcPos(NPC_LAKILULU0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    N(UnkFunc42)();
    InterpNpcYaw(NPC_LAKILULU0, SI_VAR(10), 0);
    SI_VAR(0) = SI_VAR(3);
    SI_VAR(1) = SI_VAR(4);
    SI_VAR(2) = SI_VAR(5);
    GetAngleBetweenNPCs(-4, 1, SI_VAR(10));
    InterpNpcYaw(NPC_PARTNER, SI_VAR(10), 0);
    if (STORY_PROGRESS < STORY_CH6_LAKILESTER_JOINED_PARTY) {
        GetAngleBetweenNPCs(0, 1, SI_VAR(11));
        InterpNpcYaw(NPC_WORLD_LAKILESTER, SI_VAR(11), 0);
    }
    PlayerFaceNpc(1, 0);
    sleep 1;
    goto 0;
});

Script N(802446AC) = SCRIPT({
    SI_MAP_VAR(10) = 0;
    loop {
        loop 2 {
            GetNpcPos(NPC_LAKILULU1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_LAKILULU1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 2;
        }
        sleep 1;
        loop 2 {
            GetNpcPos(NPC_LAKILULU1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += -1;
            SetNpcPos(NPC_LAKILULU1, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += -1;
            SetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 2;
        }
        sleep 1;
        if (SI_MAP_VAR(10) == 1) {
            SI_MAP_VAR(10) = 2;
            break loop;
        }
    }
});

Script N(80244888) = SCRIPT({
    spawn N(802446AC);
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_C));
    GetNpcPos(NPC_LAKILULU0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SI_VAR(1) += -5;
    SI_VAR(2) += 30;
    SI_VAR(3) += 2;
    SetNpcYaw(NPC_LAKILULU1, 270);
    SetNpcPos(NPC_LAKILULU1, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    spawn {
        sleep 5;
        SetPlayerAnimation(ANIM_1002B);
    }
    ContinueSpeech(1, -1, -1, 512, MESSAGE_ID(0x11, 0x00A8));
    spawn {
        sleep 15;
        EndSpeech(1, -1, -1, 512);
    }
    SI_MAP_VAR(10) = 1;
    loop {
        sleep 1;
        if (SI_MAP_VAR(10) == 2) {
            break loop;
        }
    }
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_D));
    GetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SI_VAR(1) += 5;
    SI_VAR(2) += 20;
    SetNpcJumpscale(NPC_LAKILULU1, 0.0);
    NpcJump0(NPC_LAKILULU1, SI_VAR(1), SI_VAR(2), SI_VAR(3), 7);
    SI_VAR(1) += -100;
    SI_VAR(2) += 10;
    spawn {
        SetNpcJumpscale(NPC_LAKILULU1, 1.5);
        NpcJump0(NPC_LAKILULU1, SI_VAR(1), SI_VAR(2), SI_VAR(3), 15);
        SetNpcPos(NPC_LAKILULU1, 0, -1000, 0);
    }
    spawn {
        ShakeCam(0, 0, 10, 2.0);
    }
    PlaySoundAtPlayer(225, 0);
    SetPlayerAnimation(ANIM_FALL_BACK);
    SI_VAR(0) = 90;
    loop 20 {
        SI_VAR(0) += 144;
        if (SI_VAR(0) > 359) {
            SI_VAR(0) -= 360;
        }
        InterpPlayerYaw(SI_VAR(0), 1);
        sleep 1;
    }
    SetPlayerAnimation(ANIM_STAND_STILL);
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_1));
});

Script N(idle_80244BF8) = SCRIPT({
    if (STORY_PROGRESS != STORY_CH6_SPOKE_WITH_THE_SUN) {
        return;
    }
    AwaitPlayerApproach(200, 20, 275);
    DisablePlayerInput(TRUE);
    SetNpcPos(NPC_WORLD_LAKILESTER, -250, 120, 45);
    SetMusicTrack(0, SONG_LAKILESTER_THEME, 0, 8);
    ShowMessageAtScreenPos(MESSAGE_ID(0x11, 0x00A0), 160, 40);
    func_802D2B6C();
    SetPlayerAnimation(0x1002A);
    sleep 20;
    InterpPlayerYaw(270, 1);
    sleep 20;
    InterpPlayerYaw(90, 1);
    sleep 20;
    SetPlayerAnimation(ANIM_STAND_STILL);
    func_802CF56C(2);
    SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_7));
    spawn {
        N(func_802434D4_CC6CE4)();
    }
    SI_VAR(9) = spawn N(8024445C);
    LoadPath(80, N(vectorList_802443A8), 5, 0);
0:
    GetNextPathPos();
    SetNpcPos(NPC_WORLD_LAKILESTER, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 0;
    }
    kill SI_VAR(9);
    SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
    PlayerFaceNpc(0, 0);
    sleep 15;
    GetNpcPos(NPC_WORLD_LAKILESTER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 200);
    SetCamPitch(0, 18.0, -8.5);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    spawn {
        PlayerMoveTo(-75, 65, 10);
        PlayerFaceNpc(0, 0);
    }
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00A1));
    SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_7));
    sleep 10;
    SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
    spawn {
        SetCamDistance(0, 1000);
        SetCamPitch(0, 17.0, -6.0);
        SetCamSpeed(0, 4.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
    }
    DisablePlayerInput(FALSE);
    StartBossBattle(3);
});

Script N(80245014) = SCRIPT({
    GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    AwaitPlayerLeave(SI_VAR(0), SI_VAR(2), 120);
    DisablePlayerInput(TRUE);
    GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), 0, SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 250);
    SetCamPitch(0, 5.5, -7.5);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    NpcFaceNpc(NPC_LAKILULU0, NPC_WORLD_LAKILESTER, 1);
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00B4));
    NpcFaceNpc(NPC_PARTNER, NPC_LAKILULU0, 1);
    SetCamDistance(0, 600);
    SetCamPitch(0, 10.0, -8.0);
    SetCamPosA(0, 0, 0);
    SetCamPosB(0, 130, -200);
    SetCamPosC(0, 0, 0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    spawn {
        N(func_802433C0_CC6BD0)(55);
    }
    SetNpcFlagBits(NPC_LAKILULU0, ((NPC_FLAG_100)), TRUE);
    SI_VAR(9) = spawn N(80244560);
    LoadPath(55, N(vectorList_80244420), 5, 0);
20:
    GetNextPathPos();
    SetNpcPos(NPC_LAKILULU0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 20;
    }
    kill SI_VAR(9);
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
    DisablePartnerAI(0);
    InterpNpcYaw(NPC_PARTNER, 270, 0);
    sleep 5;
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 5, MESSAGE_ID(0x11, 0x00B5));
    EnablePartnerAI();
    PutPartnerAway();
    ResetCam(0, 90.0);
    DisablePlayerInput(FALSE);
});

Script N(80245444) = SCRIPT({
    DisablePlayerInput(TRUE);
    sleep 30;
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_A), NPC_ANIM(world_lakilester, Palette_00, Anim_4), 0, MESSAGE_ID(0x11, 0x00A2));
    SetNpcPos(NPC_LAKILULU0, -290, 120, 45);
    spawn {
        sleep 10;
        SetNpcAnimation(NPC_SELF, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
        SetPlayerAnimation(0x1002A);
        sleep 20;
        InterpPlayerYaw(270, 1);
    }
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 5, MESSAGE_ID(0x11, 0x00A3));
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_7));
    UseSettingsFrom(0, 0, 0, 0);
    SetPanTarget(0, 0, 0, 0);
    SetCamDistance(0, 500);
    SetCamPitch(0, 5.5, -6.0);
    SetCamPosA(0, 0, 0);
    SetCamPosB(0, 130, -200);
    SetCamPosC(0, 0, 0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 1;
    spawn {
        SetCamDistance(0, 400);
        SetCamPosB(0, 130, 60);
        SetCamSpeed(0, 1.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
    }
    spawn {
        N(func_802433C0_CC6BD0)(80);
    }
    SI_VAR(9) = spawn N(80244560);
    LoadPath(80, N(vectorList_802443E4), 5, 0);
0:
    GetNextPathPos();
    SetNpcPos(NPC_LAKILULU0, SI_VAR(1), SI_VAR(2), SI_VAR(3));
    sleep 1;
    if (SI_VAR(0) == 1) {
        goto 0;
    }
    kill SI_VAR(9);
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_9));
    SetPlayerAnimation(ANIM_STAND_STILL);
    sleep 20;
    GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 250);
    SetCamPitch(0, 5.5, -7.5);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00A4));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 40;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_8), NPC_ANIM(lakilulu, Palette_00, Anim_8), 0, MESSAGE_ID(0x11, 0x00A5));
    GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 250);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_B), NPC_ANIM(world_lakilester, Palette_00, Anim_3), 0, MESSAGE_ID(0x11, 0x00A6));
    SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
    EndSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 40;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 350);
    SetCamSpeed(0, 10.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
10:
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_A), NPC_ANIM(lakilulu, Palette_00, Anim_9), 0, MESSAGE_ID(0x11, 0x00A7));
    ShowChoice(MESSAGE_ID(0x1E, 0x0020));
    if (SI_VAR(0) != 0) {
        await N(80244888);
        sleep 10;
        goto 10;
    } else {
        ContinueSpeech(1, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00A9));
        SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_1));
        SetPlayerAnimation(ANIM_NOD_YES);
        sleep 10;
        SetPlayerAnimation(ANIM_STAND_STILL);
        sleep 20;
        GetNpcPos(NPC_LAKILULU0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 20;
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 250);
        SetCamSpeed(0, 90.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_B), NPC_ANIM(world_lakilester, Palette_00, Anim_3), 0, MESSAGE_ID(0x11, 0x00AA));
        SetNpcAnimation(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_1));
        EndSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 40;
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 350);
        SetCamSpeed(0, 5.0);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
        sleep 10;
        SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_B), NPC_ANIM(world_lakilester, Palette_00, Anim_3), 0, MESSAGE_ID(0x11, 0x00AB));
        sleep 10;
        ShowChoice(MESSAGE_ID(0x1E, 0x0021));
        match SI_VAR(0) {
            == -1 {}
            == 0 {
                ContinueSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00AC));
            }
            == 1 {
                ContinueSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00AD));
            }
            == 2 {
                ContinueSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00AE));
            }
            == 3 {
                ContinueSpeech(0, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00AF));
            }
        }
    }
    InterpNpcYaw(NPC_LAKILULU0, 90, 1);
    SetNpcAnimation(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_9));
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_A), NPC_ANIM(lakilulu, Palette_00, Anim_9), 5, MESSAGE_ID(0x11, 0x00B0));
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00B1));
    sleep 15;
    SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_A), NPC_ANIM(lakilulu, Palette_00, Anim_9), 5, MESSAGE_ID(0x11, 0x00B2));
    SpeakToPlayer(NPC_WORLD_LAKILESTER, NPC_ANIM(world_lakilester, Palette_00, Anim_9), NPC_ANIM(world_lakilester, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x00B3));
    sleep 10;
    spawn {
        ResetCam(0, 90.0);
    }
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetNpcSpeed(NPC_WORLD_LAKILESTER, 3.5);
    NpcMoveTo(NPC_WORLD_LAKILESTER, SI_VAR(0), 60, 0);
    N(UnkFunc41)(0, 8);
    N(func_802435D0_CC6DE0)();
    spawn N(802438CC);
    sleep 15;
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0190), 160, 40);
    spawn N(802438F8);
    sleep 10;
    PanToTarget(0, 0, 0);
    STORY_PROGRESS = STORY_CH6_LAKILESTER_JOINED_PARTY;
    EnablePartnerAI();
    DisablePlayerInput(FALSE);
    await N(80245014);
});

Script N(defeat_80246038) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(world_lakilester, Palette_00, Anim_4));
            SetCamType(0, 6, 1);
            GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(1), SI_VAR(2));
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(0) += SI_VAR(3);
            SI_VAR(0) /= 2;
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 300);
            SetCamPitch(0, 17.0, -7.5);
            SetCamSpeed(0, 90.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            spawn N(80245444);
        }
        == 1 {}
        == 2 {
        }
    }
});

Script N(interact_802461C0) = SCRIPT({
    if (STORY_PROGRESS <= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0032));
    } else {
        GetCurrentPartnerID(SI_VAR(0));
        if (SI_VAR(0) != 8) {
            SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0034));
        } else {
            SpeakToPlayer(NPC_LAKILULU0, NPC_ANIM(lakilulu, Palette_00, Anim_4), NPC_ANIM(lakilulu, Palette_00, Anim_1), 0, MESSAGE_ID(0x11, 0x0032));
        }
    }
});

Script N(init_80246280) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_LAKILESTER_JOINED_PARTY) {
        BindNpcIdle(NPC_SELF, N(idle_80244BF8));
        BindNpcDefeat(NPC_SELF, N(defeat_80246038));
    }
});

Script N(init_802462D0) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH6_BEGAN_PEACH_MISSION) {
        BindNpcInteract(NPC_SELF, N(interact_802461C0));
        SetNpcCollisionSize(-1, 36, 28);
        if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
            SetNpcPos(NPC_SELF, -50, 180, -50);
        }
    } else {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_80246370) = SCRIPT({
    SetNpcPos(NPC_LAKILULU1, 0, -1000, 0);
    SetNpcAnimation(NPC_LAKILULU1, NPC_ANIM(lakilulu, Palette_00, Anim_B));
});

Script N(init_802463B0) = SCRIPT({
    if (STORY_PROGRESS == STORY_CH6_SPOKE_WITH_THE_SUN) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(init_802463E8) = SCRIPT({
    if (STORY_PROGRESS == STORY_CH6_SPOKE_WITH_THE_SUN) {
        RemoveNpc(NPC_SELF);
    }
    SetSelfVar(13, 1);
});

StaticNpc N(npcGroup_80246434) = {
    .id = NPC_WORLD_LAKILESTER,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
    .init = &N(init_80246280),
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
};

StaticNpc N(npcGroup_80246624) = {
    .id = NPC_LAKILULU0,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802462D0),
    .yaw = 90,
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

StaticNpc N(npcGroup_80246814) = {
    .id = NPC_LAKILULU1,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80246370),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_80246A04) = {
    .id = NPC_LAKITU0,
    .settings = &N(npcSettings_802441E4),
    .pos = { 335.0f, 90.0f, 45.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802463B0),
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
    .movement = { 335, 90, 45, 30, 0, -32767, 0, 335, 90, 45, 250, 0, 0, 1 },
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
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246BF4) = {
    .id = NPC_LAKITU1,
    .settings = &N(npcSettings_802441E4),
    .pos = { -320.0f, 90.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802463B0),
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
    .movement = { -320, 90, 0, 30, 0, -32767, 0, -320, 90, 0, 200, 0, 0, 1 },
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
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246DE4) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246FD4) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802471C4) = {
    .id = NPC_SPINY2,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802473B4) = {
    .id = NPC_SPINY3,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802475A4) = {
    .id = NPC_SPINY4,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80247794) = {
    .id = NPC_SPINY5,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = 0x80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_3),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_4),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_9),
        NPC_ANIM(spiny, Palette_00, Anim_6),
        NPC_ANIM(spiny, Palette_00, Anim_8),
        NPC_ANIM(spiny, Palette_00, Anim_7),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
        NPC_ANIM(spiny, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80247984) = {
    NPC_GROUP(N(npcGroup_80246A04), BATTLE_ID(24, 6, 0, 5)),
    NPC_GROUP(N(npcGroup_80246BF4), BATTLE_ID(24, 4, 0, 5)),
    NPC_GROUP(N(npcGroup_80246DE4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80246FD4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802471C4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802473B4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802475A4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80247794), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80246434), BATTLE_ID(25, 5, 0, 2)),
    NPC_GROUP(N(npcGroup_80246624), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246814), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/UnkFunc41.inc.c"

void N(func_802401C4_CC39D4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
INCLUDE_ASM(void, "world/area_flo/flo_13/CC3850", flo_13_func_80240374_CC3B84, ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240E18_CC4628)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024412C_CC793C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_802414D0_CC4CE0)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
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
            N(func_802401C4_CC39D4)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240374_CC3B84)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240E18_CC4628)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

s32 N(func_802416BC_CC4ECC)(void) {
    s32 i;

    for (i = 50; i < 56; i++) {
        if (get_enemy(i)->varTable[10] == 0) {
            return i;
        }
    }

    return -1;
}

void N(func_80241704_CC4F14)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                func_800494C0(npc, 0x2F4, 0x200000);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0].s = 12;
                return;
            }
        }
        script->functionTemp[1].s--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0].s = 2;
        script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1].s == 0)) {
            script->functionTemp[0].s = 0;
        }
    }
}

void N(func_80241B68_CC5378)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);
    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        func_800494C0(npc, 0x2F4, 0x200000);
        script->functionTemp[0].s = 12;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->functionTemp[0].s = 0;
    }
}

// enemy2 is being copied to a0
#ifdef NON_MATCHING
ApiStatus N(func_80241DB8_CC55C8)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    f32 temp_f4;
    f32 dist;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
        script->functionTemp[0].s = 0;
    }
    npc->unk_AB = -3;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }


    switch (script->functionTemp[0].s) {
        case 0:
            N(func_802401C4_CC39D4)(script, aiSettings, territoryPtr);

        case 1:
            N(func_80241704_CC4F14)(script, aiSettings, territoryPtr);
            break;

        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);

        case 3:
            N(func_80241B68_CC5378)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->functionTemp[0].s == 12) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enemy->varTable[4] = N(func_802416BC_CC4ECC)();
        if (enemy->varTable[4] >= 0) {
            Enemy* enemy2 = get_enemy(enemy->varTable[4]);
            enemy2->varTable[10] = 1;
            enemy2->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->currentAnim = 0x490014;
            script->functionTemp[0].s = 30;
        }
    }

    switch (script->functionTemp[0].s) {
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    switch (script->functionTemp[0].s) {
        case 30:
            npc->duration--;
            if (npc->duration <= 0) {
                get_enemy(enemy->varTable[4])->varTable[10] = 2;
                npc->duration = 5;
                script->functionTemp[0].s = 31;
            }

        case 31:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->currentAnim = 0x490015;
                get_enemy(enemy->varTable[4])->varTable[10] = 3;
                npc->duration = 10;
                script->functionTemp[0].s = 32;
            }

        case 32:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->duration = 3;
                script->functionTemp[0].s = 33;
            }

        case 33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->functionTemp[0].s = 0;
            }
            break;
    }

    if (((u32)script->functionTemp[0].s - 30) < 2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, npc->pos.x, npc->pos.z);
        if (!is_point_within_region(territoryPtr->shape, territoryPtr->pointX, territoryPtr->pointZ, npc->pos.x, npc->pos.z, territoryPtr->sizeX, territoryPtr->sizeZ)) {
            if ((dist > 30.0) && (npc->turnAroundYawAdjustment == 0)) {
                temp_f4 = dist - 20.0;
                if (temp_f4 < 0.0) {
                    temp_f4 = 0.0f;
                }
                if (temp_f4 > 200.0) {
                    temp_f4 = 200.0f;
                }
                npc->moveSpeed = update_lerp(0, aiSettings->moveSpeed, aiSettings->chaseSpeed, temp_f4, 200);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
        }
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_13/CC3850", flo_13_func_80241DB8_CC55C8, ScriptInstance *script, s32 isInitialCall);
#endif

#include "world/common/set_script_owner_npc_anim.inc.c"

void N(func_80242314_CC5B24)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->currentAnim = enemy->animList[9];
            npc->moveSpeed = aiSettings->chaseSpeed;
            if ((enemy->varTable[7] == 5) || (enemy->varTable[7] == 0) || (enemy->varTable[7] == 1)) {
                npc->collisionHeight = enemy->varTable[6] / 2;
            }
            npc->duration = (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) / npc->moveSpeed) + 0.8;
            if (npc->duration < enemy->varTable[3]) {
                npc->duration = enemy->varTable[3];
            }
            enemy->varTable[4] = npc->duration;
            script->functionTemp[0].s = 14;
        }
    }
}

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

ApiStatus N(func_8024262C_CC5E3C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= 0xBFFFFFFF;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if ((npc->currentAnim + 0xFFAAFFD2) < 2) {
                npc->currentAnim = 0x55000C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 0x21) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim = 0x55002F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim = 0x55002E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);

        case 13:
            N(func_80242314_CC5B24)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 99:
            func_8004A73C(script);
            break;

    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim + 0xFFAAFFFC) {
                case 0:
                case 8:
                case 10:
                case 12:
                case 14:
                case 18:
                case 20:
                    npc->currentAnim++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242A6C_CC627C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;
    u32 x, y, z;
    f32 x2, y2, z2, w2;
    Npc* npc2;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->varTable[10] == 100)) {
        script->functionTemp[0].s = 100;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        enemy->flags |= 0x200000;
        npc->flags = (npc->flags & ~0x200) | 8;
        enemy->varTable[10] = 0;
        enemy->varTable[11] = -1;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
    }

    if (enemy->unk_B0 & 4) {
        npc->duration = 0;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B0 &= ~4;
        if (npc->flags & 0x800) {
            npc->currentAnim = 0x4A0018;
            npc->moveSpeed = 0.0f;
            npc->jumpVelocity = 0.0f;
            npc->jumpScale = 1.0f;
            script->functionTemp[0].s = 102;
        } else {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            npc->currentAnim = enemy->animList[0];
            script->functionTemp[1].s = 0;
            script->functionTemp[0].s = 200;
        }
    }
    get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &x, &y, &z);
    if ((script->functionTemp[0].s < 100) && ((x + 50) >= 421)) {
        script->functionTemp[0].s = 110;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            if (enemy->varTable[13] != 0) {
                if (npc->pos.y <= 0.0) {
                    npc->flags = (npc->flags & ~0x200) | 8;
                } else {
                    npc->flags = (npc->flags | 0x200) & ~8;
                }
            }
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);
        
        case 13:
            N(func_80242314_CC5B24)(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 100:
            if (enemy->varTable[10] != 2) {
                break;
            }
            npc2 = get_npc_unsafe(get_enemy(enemy->varTable[11])->npcID);
            if (npc2->yaw < 180.0) {
                npc->pos.x = npc2->pos.x + 12.0;
            } else {
                npc->pos.x = npc2->pos.x - 12.0;
            }
            npc->pos.y = npc2->pos.y + 25.0;
            npc->pos.z = npc2->pos.z + 1.0;
            npc->rotation.y = 0.0f;
            npc->flags |= 8;
            npc->flags &= ~2;
            npc->flags &= ~0x200;
            npc->renderYaw = 0.0f;
            npc->currentAnim = 0x4A0018;
            script->functionTemp[0].s = 101;

        case 101:
            if (enemy->varTable[10] != 3) {
                break;
            }
            enemy->varTable[10] = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            npc->moveSpeed = 2.5f;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 0.8f;
            npc->flags |= 0x800;
            script->functionTemp[0].s = 102;

        case 102:
            if (npc->moveSpeed > 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y;
                z2 = npc->pos.z;
                if (func_800DDC44(npc->unk_80, &x2, &y2, &z2, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionRadius) == 0) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                } else {
                    npc->moveSpeed = 0.0f;
                }
            }
            

            if (npc->jumpVelocity < 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y + 13.0;
                z2 = npc->pos.z;
                w2 = fabsf(npc->jumpVelocity) + 16.0;
                if ((func_800DCB7C(npc->unk_80, &x2, &y2, &z2, &w2) != 0) && (w2 <= (fabsf(npc->jumpVelocity) + 13.0))) {
                    npc->pos.y = y2;
                    enemy->territory->wander.point.x = npc->pos.x;
                    enemy->territory->wander.point.y = npc->pos.y;
                    enemy->territory->wander.point.z = npc->pos.z;
                    enemy->territory->wander.detect.x = npc->pos.x;
                    enemy->territory->wander.detect.y = npc->pos.y;
                    enemy->territory->wander.detect.z = npc->pos.z;
                    enemy->varTable[10] = 5;
                    if (enemy->varTable[13] != 0) {
                        if (npc->pos.y <= 0.0) {
                            npc->flags = (npc->flags & ~0x200) | 8;
                        } else {
                            npc->flags = (npc->flags | 0x200) & ~8;
                        }
                    } else if (!enemy->territory->wander.isFlying) {
                        npc->flags = (npc->flags | 0x200) & ~8;
                    } else {
                        npc->flags = (npc->flags & ~0x200) | 8;
                    }
                    npc->flags = (npc->flags | 0x40000) & ~0x800;
                    npc->jumpVelocity = 0.0f;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                    npc->currentAnim = 0x4A001A;
                    npc->duration = 3;
                    script->functionTemp[0].s = 103;
                    break;
                }
            }
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            break;

        case 103:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags &= 0xFFFBFFFF;
                npc->currentAnim = 0x4A0001;
                script->functionTemp[0].s = 0;
            }
            break;

        case 110:
            npc->duration = 30;
            npc->pos.x = 0.0f;
            npc->pos.z = 0.0f;
            npc->pos.y = -1000.0f;
            npc->flags = (npc->flags | 0xA) & ~0x200;
            script->functionTemp[0].s = 111;

        case 111:
            npc->duration--;
            if (npc->duration <= 0) {
                enemy->varTable[10] = 0;
                script->functionTemp[0].s = 100;
            }
            break;

        case 200:
            func_8004A73C(script);
            break;

    }
    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc42.inc.c"

ApiStatus N(func_802433C0_CC6BD0)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(1);
    s16 param1;
    s16 param2;

    script->functionTemp[1].s = get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }
    if (script->functionTemp[0].s == (script->functionTemp[0].s / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z, 
            &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2, 
            update_lerp(0, 500.0f, 0.0f, script->functionTemp[0].s, script->functionTemp[1].s));
    }

    script->functionTemp[0].s++;
    return (script->functionTemp[1].s < script->functionTemp[0].s) * ApiStatus_DONE2;
}

ApiStatus N(func_802434D4_CC6CE4)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(0);
    s16 param1;
    s16 param2;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }
    if (script->functionTemp[0].s == (script->functionTemp[0].s / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z, 
            &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2, 
            update_lerp(0, 500.0f, 0.0f, script->functionTemp[0].s, 0x50));
    }

    script->functionTemp[0].s++;
    return (script->functionTemp[0].s > 0x50) * ApiStatus_DONE2;
}