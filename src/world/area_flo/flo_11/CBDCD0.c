#include "flo_11.h"
#include "message_ids.h"
#include "sprite/npc/lakitu.h"

enum {
    NPC_LAKITU0,
    NPC_LAKITU1,
};

EntryList N(entryList) = {
    {  470.0f,  0.0f,  -15.0f, 270.0f },
    { -470.0f,  0.0f,  -15.0f,  90.0f },
    {  360.0f, 50.0f, -237.0f, 270.0f },
    {  118.0f, 50.0f, -420.0f, 270.0f },
    {    0.0f, 50.0f,    0.0f, 270.0f },
    { -120.0f, 50.0f,  357.0f,  90.0f },
    { -360.0f, 50.0f, -240.0f,  90.0f },
    { -360.0f, 35.0f,    0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_11_tattle },
};

EvtSource N(802403E0) = SCRIPT({
    match EVT_STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

EvtSource N(80240450) = SCRIPT({
    group 11;
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(1);
    EVT_VAR(12) = EVT_VAR(2);
    EVT_VAR(13) = EVT_VAR(3);
    EVT_VAR(14) = EVT_VAR(4);
    EVT_VAR(12) -= EVT_VAR(0);
    EVT_VAR(13) -= EVT_VAR(1);
    EVT_VAR(0) = (float) EVT_VAR(12);
    EVT_VAR(0) /= 100.0;
    EVT_VAR(15) = 100.0;
    EVT_VAR(15) /= (float) EVT_VAR(0);
    EVT_VAR(15) += 11;
    EVT_VAR(5) = 200;
    EVT_VAR(5) /= EVT_VAR(15);
    EVT_VAR(5) += 1;
    loop EVT_VAR(5) {
        RandInt(EVT_VAR(12), EVT_VAR(0));
        RandInt(EVT_VAR(13), EVT_VAR(1));
        RandInt(199, EVT_VAR(2));
        EVT_VAR(3) = 210;
        EVT_VAR(3) -= EVT_VAR(2);
        EVT_VAR(0) += EVT_VAR(10);
        EVT_VAR(1) += EVT_VAR(11);
        EVT_VAR(2) += EVT_VAR(14);
        PlayEffect(0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep EVT_VAR(15);
0:
    RandInt(EVT_VAR(12), EVT_VAR(0));
    RandInt(EVT_VAR(13), EVT_VAR(1));
    EVT_VAR(0) += EVT_VAR(10);
    EVT_VAR(1) += EVT_VAR(11);
    PlayEffect(0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep EVT_VAR(15);
    goto 0;
});

EvtSource N(802406FC) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_STAND_STILL);
    GetCurrentPartnerID(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
    }
    GetEntryID(EVT_VAR(0));
    N(GetEntryPos)();
    EVT_VAR(2) -= 40;
    SetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    InterpPlayerYaw(EVT_VAR(4), 0);
    PlaySound(0x163);
    func_802D286C(256);
    func_802D2520(ANIM_STAND_STILL, 5, 2, 1, 1, 0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    loop 40 {
        EVT_VAR(1) += 1;
        SetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        sleep 1;
    }
    sleep 3;
    GetCurrentPartnerID(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        spawn {
            DisablePartnerAI(0);
            GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetNpcFlagBits(NPC_PARTNER, ((0x00000002)), FALSE);
            EnablePartnerAI();
            EnableNpcShadow(NPC_PARTNER, TRUE);
        }
    }
    sleep 2;
    func_802D2520(ANIM_STAND_STILL, 0, 0, 0, 0, 0);
    sleep 1;
    SetPlayerAnimation(ANIM_10002);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
    HidePlayerShadow(FALSE);
0:
    N(GetCurrentFloor)();
    sleep 1;
    if (EVT_VAR(0) != -1) {
        goto 0;
    }
    spawn 0xFE363C8A;
});

EvtSource N(80240A50) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    ModifyColliderFlags(0, EVT_VAR(11), 0x7FFFFE00);
    GetEntryID(EVT_VAR(0));
    N(GetEntryPos)();
    EVT_VAR(5) = EVT_VAR(1);
    EVT_VAR(6) = EVT_VAR(2);
    EVT_VAR(7) = EVT_VAR(3);
    EVT_VAR(2) += 2;
    SetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    InterpPlayerYaw(EVT_VAR(4), 0);
    if (EVT_VAR(4) == 90) {
        EVT_VAR(5) += 40;
    } else {
        EVT_VAR(5) -= 40;
    }
    UseSettingsFrom(0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7));
    SetPanTarget(0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    GetCurrentPartnerID(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        DisablePartnerAI(0);
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
        InterpNpcYaw(NPC_PARTNER, EVT_VAR(0), 0);
    }
    sleep 1;
    PlaySound(0x163);
    spawn {
        sleep 25;
        HidePlayerShadow(FALSE);
    }
    func_802D286C(2304);
    func_802D2520(ANIM_10002, 5, 3, 1, 1, 0);
    loop 40 {
        N(SomeXYZFunc2)(1.0);
        SetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        sleep 1;
    }
    GetCurrentPartnerID(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        spawn {
            GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EnableNpcShadow(NPC_PARTNER, TRUE);
            EnablePartnerAI();
        }
    }
    sleep 5;
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    ModifyColliderFlags(1, EVT_VAR(11), 0x7FFFFE00);
    DisablePlayerInput(FALSE);
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    spawn 0xFE363C8A;
});

EvtSource N(80240E40) = SCRIPT({
    N(UnkFunc25)();
    if (EVT_VAR(0) == 0) {
        return;
    }
    GetCurrentPartner(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        GetCurrentPartnerID(EVT_VAR(1));
        if (EVT_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    await N(80240F1C);
});

EvtSource N(80240F1C) = SCRIPT({
    N(SetPlayerStatusAnimFlags100000)();
    group 27;
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    EVT_VAR(0) = EVT_VAR(10);
    N(GetEntryPos)();
    PlayerMoveTo(EVT_VAR(1), EVT_VAR(3), 3);
    EVT_VAR(0) = EVT_VAR(10);
    N(GetEntryPos)();
    SetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    SetPlayerFlagBits(2097152, 1);
    N(GetCurrentCameraYawClamped180)();
    InterpPlayerYaw(EVT_VAR(0), 0);
    sleep 2;
    SetPlayerFlagBits(2097152, 0);
    PlaySound(0x163);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    spawn {
        sleep 4;
        loop 40 {
            EVT_VAR(1) -= 1;
            SetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            sleep 1;
        }
    }
    func_802D286C(2048);
    func_802D2520(ANIM_10002, 5, 2, 1, 1, 0);
    sleep 25;
    await 0xFE363C8C;
});

EvtSource N(802410F8) = SCRIPT({
    IsPlayerOnValidFloor(EVT_VAR(0));
    if (EVT_VAR(0) == 0) {
        return;
    }
    GetPlayerActionState(EVT_VAR(0));
    if (EVT_VAR(0) == 26) {
        return;
    }
    GetCurrentPartner(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        GetCurrentPartnerID(EVT_VAR(1));
        if (EVT_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    group 27;
    N(SetPlayerStatusAnimFlags100000)();
    DisablePlayerPhysics(TRUE);
    ModifyColliderFlags(0, EVT_VAR(11), 0x7FFFFE00);
    EVT_VAR(0) = EVT_VAR(10);
    N(GetEntryPos)();
    EVT_VAR(5) = EVT_VAR(1);
    EVT_VAR(6) = EVT_VAR(2);
    EVT_VAR(6) += 2;
    EVT_VAR(7) = EVT_VAR(3);
    EVT_VAR(8) = EVT_VAR(4);
    EVT_VAR(8) += 180;
    if (EVT_VAR(4) >= 360) {
        EVT_VAR(4) -= 360;
    }
    InterpPlayerYaw(EVT_VAR(8), 1);
    sleep 1;
    PlaySound(0x163);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPlayerPos(EVT_VAR(0), EVT_VAR(6), EVT_VAR(7));
    SetPlayerAnimation(ANIM_STAND_STILL);
    func_802D286C(2048);
    func_802D2520(ANIM_STAND_STILL, 5, 3, 1, 1, 0);
    spawn {
        sleep 8;
        HidePlayerShadow(TRUE);
    }
    spawn {
        sleep 3;
        loop 40 {
            N(SomeXYZFunc2)(1.0);
            SetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            sleep 1;
        }
    }
    sleep 25;
    await 0xFE363C8C;
});

EvtSource N(exitWalk_8024142C) = EXIT_WALK_SCRIPT(60,  0, "flo_23",  1);

EvtSource N(exitWalk_80241488) = EXIT_WALK_SCRIPT(60,  1, "flo_12",  0);

EvtSource N(802414E4) = SCRIPT({
    group 27;
    GotoMap("flo_11", 5);
    sleep 100;
});

EvtSource N(80241520) = SCRIPT({
    group 27;
    GotoMap("flo_11", 6);
    sleep 100;
});

EvtSource N(8024155C) = SCRIPT({
    group 27;
    GotoMap("flo_11", 7);
    sleep 100;
});

EvtSource N(80241598) = SCRIPT({
    group 27;
    GotoMap("flo_11", 2);
    sleep 100;
});

EvtSource N(802415D4) = SCRIPT({
    group 27;
    GotoMap("flo_11", 3);
    sleep 100;
});

EvtSource N(80241610) = SCRIPT({
    group 27;
    GotoMap("flo_11", 4);
    sleep 100;
});

EvtSource N(8024164C) = SCRIPT({
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(1);
    EVT_VAR(12) = EVT_VAR(2);
    await N(80240E40);
});

EvtSource N(80241698) = SCRIPT({
    bind N(exitWalk_80241488) TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_8024142C) TRIGGER_FLOOR_ABOVE 4;
    EVT_VAR(0) = 2;
    EVT_VAR(1) = 35;
    EVT_VAR(2) = N(802414E4);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
    EVT_VAR(0) = 3;
    EVT_VAR(1) = 34;
    EVT_VAR(2) = N(80241520);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
    EVT_VAR(0) = 4;
    EVT_VAR(1) = 33;
    EVT_VAR(2) = N(8024155C);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
    EVT_VAR(0) = 5;
    EVT_VAR(1) = 32;
    EVT_VAR(2) = N(80241598);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
    EVT_VAR(0) = 6;
    EVT_VAR(1) = 31;
    EVT_VAR(2) = N(802415D4);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
    EVT_VAR(0) = 7;
    EVT_VAR(1) = 30;
    EVT_VAR(2) = N(80241610);
    bind N(8024164C) TRIGGER_FLOOR_TOUCH EVT_VAR(1);
});

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    func_80044238(5);
    MakeNpcs(0, N(npcGroupList_802430D4));
    await N(makeEntities);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    GetEntryID(EVT_VAR(0));
    if (EVT_VAR(0) <= 1) {
        EVT_VAR(0) = N(80241698);
        spawn EnterWalk;
        spawn N(80242240);
        sleep 1;
    } else {
        EVT_VAR(10) = N(80241698);
        spawn N(802406FC);
        sleep 1;
    }
    await N(802403E0);
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_802402E0_CBDFB0)();
    }
    ModifyColliderFlags(3, 9, 0x00000009);
    ModifyColliderFlags(3, 10, 0x00000009);
    ModifyColliderFlags(3, 11, 0x00000009);
    ModifyColliderFlags(3, 12, 0x00000009);
});

static s32 N(pad_1AB8)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80241AC0) = {
    .height = 32,
    .radius = 24,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 20,
};

s32 N(vectorList_80241AEC)[] = {
    0x43E60000, 0x43480000, 0xC3700000, 0x43B40000, 0x43160000, 0xC30C0000, 0x43820000, 0x42C80000,
    0xC3700000, 0x43B40000, 0x42C80000, 0xC3DC0000, 0x43E60000, 0x42C80000, 0xC3700000, 0x43B40000,
    0x42C80000, 0xC30C0000, 0x43820000, 0x42C80000, 0xC3700000, 0x43B40000, 0x42C80000, 0xC3DC0000,
};

s32 N(vectorList_80241B4C)[] = {
    0xC2C80000, 0x43480000, 0xC2480000, 0x00000000, 0x43160000, 0xC3160000, 0x42C80000, 0x42C80000,
    0xC2480000, 0x00000000, 0x42C80000, 0x42480000, 0xC2C80000, 0x42C80000, 0xC2480000, 0x00000000,
    0x42C80000, 0xC3160000, 0x42C80000, 0x42C80000, 0xC2480000, 0x00000000, 0x42C80000, 0x42480000,
};

s32 N(vectorList_80241BAC)[] = {
    0x43B40000, 0x42C80000, 0xC3DC0000, 0x43AF0000, 0x42F00000, 0xC35C0000, 0x43960000, 0x42F00000,
    0xC3240000, 0x43200000, 0x42DC0000, 0xC3340000,
};

s32 N(vectorList_80241BDC)[] = {
    0x00000000, 0x42C80000, 0x42480000, 0x43480000, 0x42DC0000, 0x41E80000, 0x43670000, 0x42DC0000,
    0xC1900000, 0x42E60000, 0x42C80000, 0xC3160000,
};

s32 N(vectorList_80241C0C)[] = {
    0x438E8000, 0x42F00000, 0xC2D80000, 0x43B90000, 0x42C80000, 0xC3020000, 0x43E30000, 0x42700000,
    0xC1A00000,
};

s32 N(vectorList_80241C30)[] = {
    0x43838000, 0x42DC0000, 0xC2840000, 0x43B40000, 0x42B40000, 0x42480000, 0x43E30000, 0x42480000,
    0x41A00000,
};

s32 N(vectorList_80241C54)[] = {
    0x43C80000, 0x41F00000, 0xC2200000, 0x43960000, 0x42A00000, 0xC2200000, 0x43160000, 0x43480000,
    0xC2200000, 0x42C80000, 0x43AF0000, 0xC2200000,
};

s32 N(vectorList_80241C84)[] = {
    0x43C80000, 0x41F00000, 0x42200000, 0x43960000, 0x42A00000, 0x42200000, 0x43160000, 0x43480000,
    0x42200000, 0x42C80000, 0x43AF0000, 0x42200000,
};

EvtSource N(80241CB4) = SCRIPT({
    loop {
        PlaySound(0x295);
        sleep EVT_VAR(0);
    }
});

EvtSource N(80241CF4) = SCRIPT({
    EVT_VAR(0) = 5;
    EVT_MAP_VAR(11) = spawn N(80241CB4);
    spawn {
        LoadPath(160, N(vectorList_80241AEC), 8, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) == 0) {
                break loop;
            }
        }
    }
    LoadPath(160, N(vectorList_80241B4C), 8, 0);
    loop {
        GetNextPathPos();
        SetNpcPos(NPC_LAKITU1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        sleep 1;
        if (EVT_VAR(0) == 0) {
            break loop;
        }
    }
    EVT_MAP_VAR(10) = 1;
});

EvtSource N(80241E4C) = SCRIPT({
    spawn {
        LoadPath(30, N(vectorList_80241BAC), 4, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) == 0) {
                break loop;
            }
        }
    }
    LoadPath(45, N(vectorList_80241BDC), 4, 0);
    loop {
        GetNextPathPos();
        SetNpcPos(NPC_LAKITU1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        sleep 1;
        if (EVT_VAR(0) == 0) {
            break loop;
        }
    }
    kill EVT_MAP_VAR(11);
});

EvtSource N(80241F80) = SCRIPT({
    EVT_VAR(0) = 4;
    EVT_MAP_VAR(11) = spawn N(80241CB4);
    spawn {
        LoadPath(35, N(vectorList_80241C0C), 3, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) == 0) {
                break loop;
            }
        }
    }
    LoadPath(35, N(vectorList_80241C30), 3, 0);
    loop {
        GetNextPathPos();
        SetNpcPos(NPC_LAKITU1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        sleep 1;
        if (EVT_VAR(0) == 0) {
            break loop;
        }
    }
});

EvtSource N(802420C8) = SCRIPT({
    spawn {
        LoadPath(40, N(vectorList_80241C54), 4, 0);
        loop {
            GetNextPathPos();
            SetNpcPos(NPC_LAKITU0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
            sleep 1;
            if (EVT_VAR(0) == 0) {
                break loop;
            }
        }
        SetNpcPos(NPC_LAKITU0, 0, -1000, 0);
    }
    LoadPath(40, N(vectorList_80241C84), 4, 0);
    loop {
        GetNextPathPos();
        SetNpcPos(NPC_LAKITU1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
        sleep 1;
        if (EVT_VAR(0) == 0) {
            break loop;
        }
    }
    SetNpcPos(NPC_LAKITU1, 0, -1000, 0);
    sleep 40;
    kill EVT_MAP_VAR(11);
});

EvtSource N(80242240) = SCRIPT({
    if (EVT_SAVE_FLAG(1377) == 1) {
        return;
    }
    if (EVT_STORY_PROGRESS < STORY_CH6_GOT_MAGICAL_BEAN) {
        return;
    }
    if (EVT_SAVE_FLAG(1375) == 0) {
        return;
    }
    SetNpcPos(NPC_LAKITU0, 460, 200, -240);
    SetNpcPos(NPC_LAKITU1, -100, 200, -50);
    loop {
        sleep 1;
        GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        if (EVT_VAR(0) < 440) {
            break loop;
        }
    }
    DisablePlayerInput(TRUE);
    EVT_MAP_VAR(10) = 0;
    spawn N(80241CF4);
    SetCamType(0, 1, 0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 25.0, -7.0);
    SetCamDistance(0, 450);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 20;
    EVT_VAR(0) = 270;
    EVT_VAR(1) = 100;
    EVT_VAR(2) = -87;
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamPitch(0, 14.0, -11.0);
    SetCamPosA(0, 87, 0);
    SetCamPosB(0, 0, -50);
    SetCamPosC(0, 87, 0);
    SetCamSpeed(0, 1.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 30;
    SetCamDistance(0, 150);
    SetCamPitch(0, 17.0, -16.0);
    PanToTarget(0, 0, 1);
    loop {
        sleep 1;
        if (EVT_MAP_VAR(10) == 1) {
            break loop;
        }
    }
    NpcFaceNpc(NPC_LAKITU0, NPC_LAKITU1, 1);
    NpcFaceNpc(NPC_LAKITU1, NPC_LAKITU0, 1);
    spawn N(80241E4C);
    sleep 30;
    SpeakToPlayer(NPC_LAKITU0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0088));
    NpcFaceNpc(NPC_LAKITU1, NPC_LAKITU0, 1);
    SpeakToPlayer(NPC_LAKITU1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0089));
    InterpNpcYaw(NPC_LAKITU0, 0, 1);
    sleep 20;
    SpeakToPlayer(NPC_LAKITU0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x008A));
    SpeakToPlayer(NPC_LAKITU1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x008B));
    SetCamType(0, 1, 0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 14.0, -11.0);
    SetCamDistance(0, 450);
    SetCamPosA(0, 87, 0);
    SetCamPosB(0, 0, -50);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    spawn N(80241F80);
    SetNpcVar(0, 0, 1);
});

EvtSource N(idle_80242810) = SCRIPT({
    loop {
        GetSelfVar(0, EVT_VAR(0));
        if (EVT_VAR(0) != 0) {
            break loop;
        }
        sleep 1;
    }
    spawn {
        AdjustCam(0, 4.0, 0, 1000, 14.0, -11.0);
    }
    StartBossBattle(3);
});

EvtSource N(defeat_802428B8) = SCRIPT({
    GetBattleOutcome(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
            SetNpcPos(NPC_LAKITU0, 400, 20, -40);
            SetNpcPos(NPC_LAKITU1, 400, 20, 40);
            InterpNpcYaw(NPC_LAKITU0, 270, 0);
            InterpNpcYaw(NPC_LAKITU1, 270, 0);
            GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            EVT_VAR(2) += -60;
            UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            SetCamDistance(0, 900);
            SetCamPitch(0, 24.0, -4.0);
            SetCamPosA(0, -95.0, 0.0);
            SetCamPosB(0, 0.0, -50.0);
            SetCamSpeed(0, 90.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            await N(802420C8);
            ResetCam(0, 4.0);
            EVT_SAVE_FLAG(1377) = 1;
            EVT_MAP_VAR(0) = 1;
            DisablePlayerInput(FALSE);
        }
        == 1 {}
        == 2 {
        }
    }
});

EvtSource N(defeat_80242AC4) = SCRIPT({
    GetBattleOutcome(EVT_VAR(0));
    match EVT_VAR(0) {
        == 0 {
0:
            if (EVT_MAP_VAR(0) == 0) {
                sleep 1;
                goto 0;
            }
        }
        == 1 {}
        == 2 {
        }
    }
});

EvtSource N(init_80242B58) = SCRIPT({
    SetNpcPos(NPC_LAKITU0, 0, -1000, 0);
    if (EVT_SAVE_FLAG(1377) == 0) {
        if (EVT_STORY_PROGRESS >= STORY_CH6_GOT_MAGICAL_BEAN) {
            if (EVT_SAVE_FLAG(1375) == 1) {
                EVT_MAP_VAR(0) = 0;
                BindNpcIdle(NPC_SELF, N(idle_80242810));
                BindNpcDefeat(NPC_SELF, N(defeat_802428B8));
                SetNpcPos(NPC_LAKITU0, 350, 120, -220);
                InterpNpcYaw(NPC_LAKITU0, 270, 1);
            }
        }
    }
});

EvtSource N(init_80242C38) = SCRIPT({
    SetNpcPos(NPC_LAKITU1, 0, -1000, 0);
    if (EVT_SAVE_FLAG(1377) == 0) {
        if (EVT_STORY_PROGRESS >= STORY_CH6_GOT_MAGICAL_BEAN) {
            if (EVT_SAVE_FLAG(1375) == 1) {
                BindNpcDefeat(NPC_SELF, N(defeat_80242AC4));
                SetNpcPos(NPC_LAKITU1, 200, 110, 29);
                InterpNpcYaw(NPC_LAKITU1, 0, 1);
            }
        }
    }
});

StaticNpc N(npcGroup_80242CF4)[] = {
    {
        .id = NPC_LAKITU0,
        .settings = &N(npcSettings_80241AC0),
        .pos = { 553.0f, 60.0f, 52.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_80242B58),
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
    },
    {
        .id = NPC_LAKITU1,
        .settings = &N(npcSettings_80241AC0),
        .pos = { 553.0f, 60.0f, 52.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_80242C38),
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
    },
};

NpcGroupList N(npcGroupList_802430D4) = {
    NPC_GROUP(N(npcGroup_80242CF4), BATTLE_ID(24, 7, 0, 9)),
    {},
};

static s32 N(pad_30EC) = {
    0x00000000,
};

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA0E8, -220, 60, -75, 0, MAKE_ENTITY_END);
    AssignBlockFlag(EVT_SAVE_FLAG(1384));
});

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

void playFX_82();

ApiStatus N(func_802402E0_CBDFB0)(Evt* script, s32 isInitialCall) {
    playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
