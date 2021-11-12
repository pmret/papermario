#include "flo_14.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {  720.0f, 0.0f, 0.0f, 270.0f },
    { -720.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_14_tattle },
};

EvtSource N(802423F0) = SCRIPT({
    match EVT_STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

EvtSource N(updateTexturePan_80242460) = SCRIPT({
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

EvtSource N(exitWalk_802424FC) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  1);

EvtSource N(exitWalk_80242558) = EXIT_WALK_SCRIPT(60,  1, "flo_13",  0);

EvtSource N(802425B4) = SCRIPT({
    bind N(exitWalk_80242558) TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_802424FC) TRIGGER_FLOOR_ABOVE 4;
});

s32 N(lavaResetList_802425FC)[] = {
    0x0000001F, 0xC3FA0000, 0x00000000, 0xC2B40000, 0x00000019, 0xC3FF0000, 0x00000000, 0x00000000,
    0x00000020, 0xC3FA0000, 0x00000000, 0x42DC0000, 0x00000021, 0xC37A0000, 0x00000000, 0xC2B40000,
    0x0000001A, 0xC3700000, 0x00000000, 0x00000000, 0x00000022, 0xC37A0000, 0x00000000, 0x42DC0000,
    0x0000001B, 0xC2480000, 0x00000000, 0x41C80000, 0x0000001C, 0x428C0000, 0x42700000, 0xC2BE0000,
    0x0000001D, 0x43CD0000, 0x42700000, 0xC2BE0000, 0x0000001E, 0x44098000, 0x00000000, 0x42480000,
    0x00000023, 0xC2480000, 0x00000000, 0x42DC0000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(main) = SCRIPT({
    EVT_WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80244F00));
    spawn N(80244F30);
    ModifyColliderFlags(3, 9, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_802425FC));
    }
    EnableTexPanning(29, 1);
    EnableTexPanning(31, 1);
    EnableTexPanning(32, 1);
    EnableTexPanning(35, 1);
    EnableTexPanning(36, 1);
    EnableTexPanning(39, 1);
    EnableTexPanning(41, 1);
    EnableTexPanning(43, 1);
    EnableTexPanning(45, 1);
    EnableTexPanning(47, 1);
    EnableTexPanning(49, 1);
    EnableTexPanning(51, 1);
    EnableTexPanning(53, 1);
    EnableTexPanning(30, 1);
    EnableTexPanning(33, 1);
    EnableTexPanning(34, 1);
    EnableTexPanning(37, 1);
    EnableTexPanning(38, 1);
    EnableTexPanning(42, 1);
    EnableTexPanning(44, 1);
    EnableTexPanning(46, 1);
    EnableTexPanning(48, 1);
    EnableTexPanning(50, 1);
    EnableTexPanning(52, 1);
    EnableTexPanning(54, 1);
    spawn {
        EVT_VAR(0) = 1;
        EVT_VAR(1) = 140;
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
        spawn N(updateTexturePan_80242460);
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
        spawn N(updateTexturePan_80242460);
    }
    spawn N(80243E78);
    spawn N(80245224);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    EVT_VAR(0) = N(802425B4);
    spawn EnterWalk;
    await N(802423F0);
    if (EVT_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_8024030C_CCB61C)();
    }
});

static s32 N(pad_2BF4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80242C00) = SCRIPT({
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

EvtSource N(80242EAC) = SCRIPT({
    EVT_VAR(9) = EVT_VAR(6);
    EVT_VAR(8) = EVT_VAR(5);
    EVT_VAR(7) = EVT_VAR(4);
    EVT_VAR(6) = EVT_VAR(3);
    EVT_VAR(5) = EVT_VAR(2);
    EVT_VAR(4) = EVT_VAR(1);
    EVT_VAR(3) = EVT_VAR(0);
    EnableModel(EVT_VAR(6), 0);
0:
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    N(UnkFunc43)();
    if (EVT_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(EVT_VAR(6), 1);
    }
    if (EVT_VAR(10) != 0) {
        spawn {
            sleep 5;
            EVT_VAR(0) = EVT_VAR(3);
            EVT_VAR(1) = EVT_VAR(4);
            EVT_VAR(2) = EVT_VAR(5);
            EVT_VAR(1) += 10;
            EVT_VAR(2) += 8;
            PlayEffect(0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            EVT_VAR(1) -= 10;
            MakeItemEntity(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(EVT_VAR(8), EVT_VAR(0), 1, 0, 0);
    RotateModel(EVT_VAR(9), EVT_VAR(0), 1, 0, 0);
    if (EVT_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(EVT_VAR(7), 0);
});

s32 N(D_802431CC_CCE4DC) = {
    0x00000000,
};

EvtSource N(802431D0) = SCRIPT({
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    MakeLerp(EVT_VAR(1), 48, 15, 0);
    loop {
        UpdateLerp();
        GetPlayerPos(EVT_VAR(2), EVT_VAR(3), EVT_VAR(4));
        SetCamTarget(0, EVT_VAR(2), EVT_VAR(0), EVT_VAR(4));
        sleep 1;
        if (EVT_VAR(1) == 0) {
            break loop;
        }
    }
    loop {
        GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        SetCamTarget(0, EVT_VAR(0), 48, EVT_VAR(2));
        sleep 1;
    }
});

EvtSource N(802432E8) = SCRIPT({
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    loop {
        GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 20;
        EVT_VAR(2) += -5;
        SetNpcPos(NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        sleep 1;
    }
});

Vec3f N(vectorList_80243384)[] = {
    { 531.0, 75.0, 81.0 }, { 481.0, 80.0, 81.0 },
    { 431.0, 75.0, 81.0 }, { 381.0, 70.0, 81.0 },
    { 331.0, 75.0, 81.0 }, { 281.0, 80.0, 81.0 },
    { 231.0, 75.0, 81.0 }, { 181.0, 70.0, 81.0 },
    { 131.0, 75.0, 81.0 }, { 81.0, 80.0, 81.0 },
    { 31.0, 75.0, 81.0 }, { -19.0, 70.0, 81.0 },
    { -69.0, 75.0, 81.0 },
};

EvtSource N(80243420) = SCRIPT({
    sleep 20;
    PlaySound(0x80000023);
    LoadPath(165, N(vectorList_80243384), 13, 10);
0:
    GetNextPathPos();
    TranslateModel(123, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    EVT_VAR(2) += -27;
    EVT_VAR(3) += -10;
    SetPlayerPos(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    N(func_8024046C_CCB77C)(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    sleep 1;
    if (EVT_VAR(0) == 1) {
        goto 0;
    }
    StopSound(0x80000023);
});

EvtSource N(8024352C) = SCRIPT({
    IsPlayerWithin(531, 81, 30, EVT_VAR(0));
    if (EVT_VAR(0) == 0) {
        return;
    }
    DisablePlayerInput(TRUE);
    GetCurrentPartner(EVT_VAR(0));
    if (EVT_VAR(0) != 0) {
        func_802D2B6C();
        sleep 20;
    }
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    GetModelCenter(123);
    spawn {
        EVT_VAR(2) += -10;
        SetPlayerJumpscale(0.2001953125);
        PlayerJump(531, 48, EVT_VAR(2), 10);
        SetPlayerActionState(10);
    }
    spawn {
        sleep 5;
        EVT_VAR(2) += -15;
        SetNpcJumpscale(NPC_PARTNER, 0.2001953125);
        NpcJump0(NPC_PARTNER, 531, 68, EVT_VAR(2), 10);
    }
    EVT_MAP_VAR(9) = spawn N(802431D0);
    sleep 15;
    N(func_802403D4_CCB6E4)();
    if (EVT_VAR(14) != 0) {
        EVT_VAR(14) = spawn N(802432E8);
    }
    await N(80243420);
    if (EVT_VAR(14) != 0) {
        kill EVT_VAR(14);
        N(func_8024042C_CCB73C)();
    }
    GetModelCenter(123);
    PlayEffect(0x43, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 2, 0, 0, 0, 0, 0, 0, 0, 0);
    PlaySoundAt(0x2F3, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    ClearPartnerMoveHistory(-4);
    EnableModel(123, 0);
    EVT_AREA_FLAG(37) = 0;
    kill EVT_MAP_VAR(9);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE);
    EnablePartnerAI();
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
    unbind;
});

EvtSource N(80243870) = SCRIPT({
    PlaySoundAt(0x193, 0, 591, 55, 121);
    EnableModel(123, 1);
    EVT_VAR(2) = 1.0;
    EVT_VAR(4) = 0.0;
    EVT_VAR(5) = 0.0;
    EVT_VAR(6) = 0.0;
    EVT_VAR(7) = -30;
    EVT_VAR(8) = 20;
    EVT_VAR(7) /= 90.0;
    EVT_VAR(8) /= 90.0;
    EVT_VAR(9) = 180;
    loop EVT_VAR(9) {
        TranslateModel(123, 591, 55, 121);
        EVT_VAR(3) = (float) EVT_VAR(2);
        EVT_VAR(3) /= (float) 10;
        ScaleModel(123, EVT_VAR(3), EVT_VAR(3), EVT_VAR(3));
        TranslateModel(123, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6));
        EVT_VAR(2) += 0.05078125;
        if (EVT_VAR(9) > 90) {
            EVT_VAR(4) += (float) EVT_VAR(7);
            EVT_VAR(5) += (float) EVT_VAR(8);
        }
        sleep 1;
    }
    EVT_VAR(7) = -30;
    EVT_VAR(8) = -40;
    EVT_VAR(7) /= 60.0;
    EVT_VAR(8) /= 60.0;
    loop 60 {
        TranslateModel(123, 591, 55, 121);
        ScaleModel(123, EVT_VAR(3), EVT_VAR(3), EVT_VAR(3));
        TranslateModel(123, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6));
        EVT_VAR(4) += (float) EVT_VAR(7);
        EVT_VAR(6) += (float) EVT_VAR(8);
        sleep 1;
    }
    EVT_AREA_FLAG(36) = 0;
    EVT_AREA_FLAG(37) = 1;
});

s32 N(D_80243B14_CCEE24) = {
    0x00000000,
};

s32 N(D_80243B18_CCEE28) = {
    0x0000005A,
};

EvtSource N(80243B1C) = SCRIPT({
    group 0;
    EVT_VAR(15) = EVT_VAR(0);
0:
    if (EVT_AREA_FLAG(35) == 1) {
        sleep 10;
        goto 0;
    }
    buf_use N(D_802431CC_CCE4DC);
    buf_read EVT_VAR(0);
    if (EVT_VAR(0) == 0) {
        RandInt(10, EVT_VAR(0));
        EVT_VAR(0) += 1;
        sleep EVT_VAR(0);
        goto 0;
    }
    EnableModel(EVT_VAR(15), 1);
    RandInt(4, EVT_VAR(0));
    EVT_VAR(0) += 4.0;
    EVT_VAR(0) *= -1.0;
    EVT_VAR(1) = 2.0;
    EVT_VAR(2) = (float) EVT_VAR(0);
    EVT_VAR(2) /= 10.0;
    EVT_VAR(3) = 0.4;
    EVT_VAR(4) = 591.0;
    EVT_VAR(5) = 60.0;
    EVT_VAR(6) = 121.0;
    RandInt(3, EVT_VAR(7));
    EVT_VAR(7) += 3.0;
    EVT_VAR(7) *= 0.04;
    EVT_VAR(9) = (float) EVT_VAR(7);
    EVT_VAR(9) /= 5.0;
    RandInt(50, EVT_VAR(8));
    EVT_VAR(8) += 50;
    loop EVT_VAR(8) {
        EVT_VAR(14) = (float) EVT_VAR(2);
        EVT_VAR(14) -= (float) EVT_VAR(0);
        EVT_VAR(14) *= 0.046875;
        EVT_VAR(0) += (float) EVT_VAR(14);
        EVT_VAR(14) = (float) EVT_VAR(3);
        EVT_VAR(14) -= (float) EVT_VAR(1);
        EVT_VAR(14) *= 0.046875;
        EVT_VAR(1) += (float) EVT_VAR(14);
        EVT_VAR(4) += (float) EVT_VAR(0);
        EVT_VAR(5) += (float) EVT_VAR(1);
        EVT_VAR(14) = (float) EVT_VAR(7);
        EVT_VAR(14) -= (float) EVT_VAR(9);
        EVT_VAR(14) *= 0.203125;
        EVT_VAR(9) += (float) EVT_VAR(14);
        TranslateModel(EVT_VAR(15), EVT_VAR(4), EVT_VAR(5), EVT_VAR(6));
        ScaleModel(EVT_VAR(15), EVT_VAR(9), EVT_VAR(9), EVT_VAR(9));
        sleep 1;
    }
    EnableModel(EVT_VAR(15), 0);
    goto 0;
});


EvtSource N(80243E78) = SCRIPT({
    ModifyColliderFlags(3, 31, 0x00000006);
    ModifyColliderFlags(3, 32, 0x00000006);
    ModifyColliderFlags(3, 33, 0x00000006);
    ModifyColliderFlags(3, 34, 0x00000006);
    ModifyColliderFlags(3, 35, 0x00000006);
    EVT_VAR(0) = -730;
    EVT_VAR(1) = -130;
    EVT_VAR(2) = -470;
    EVT_VAR(3) = -70;
    EVT_VAR(4) = 0;
    spawn N(80242C00);
    EVT_VAR(0) = -730;
    EVT_VAR(1) = 70;
    EVT_VAR(2) = -470;
    EVT_VAR(3) = 140;
    EVT_VAR(4) = 0;
    spawn N(80242C00);
    EVT_VAR(0) = -280;
    EVT_VAR(1) = 130;
    EVT_VAR(2) = -110;
    EVT_VAR(3) = -70;
    EVT_VAR(4) = 0;
    spawn N(80242C00);
    EVT_VAR(0) = -280;
    EVT_VAR(1) = 70;
    EVT_VAR(2) = -10;
    EVT_VAR(3) = 140;
    EVT_VAR(4) = 0;
    spawn N(80242C00);
    GetModelCenter(96);
    EVT_VAR(3) = 96;
    EVT_VAR(4) = 97;
    EVT_VAR(5) = 98;
    EVT_VAR(6) = 99;
    EVT_VAR(10) = 174;
    spawn N(80242EAC);
    GetModelCenter(82);
    EVT_VAR(3) = 82;
    EVT_VAR(4) = 83;
    EVT_VAR(5) = 84;
    EVT_VAR(6) = 85;
    EVT_VAR(10) = 0;
    spawn N(80242EAC);
    GetModelCenter(76);
    EVT_VAR(3) = 76;
    EVT_VAR(4) = 77;
    EVT_VAR(5) = 78;
    EVT_VAR(6) = 79;
    EVT_VAR(10) = 0;
    spawn N(80242EAC);
    GetModelCenter(90);
    EVT_VAR(3) = 90;
    EVT_VAR(4) = 91;
    EVT_VAR(5) = 92;
    EVT_VAR(6) = 93;
    EVT_VAR(10) = 0;
    spawn N(80242EAC);
    ModifyColliderFlags(0, 15, 0x7FFFFE00);
    CloneModel(124, 10001);
    CloneModel(124, 10002);
    CloneModel(124, 10003);
    CloneModel(124, 10004);
    CloneModel(124, 10005);
    EnableModel(123, 0);
    EnableModel(124, 0);
    EnableModel(10001, 0);
    EnableModel(10002, 0);
    EnableModel(10003, 0);
    EnableModel(10004, 0);
    EnableModel(10005, 0);
    EVT_VAR(0) = 10001;
    spawn N(80243B1C);
    EVT_VAR(0) = 10002;
    spawn N(80243B1C);
    EVT_VAR(0) = 10003;
    spawn N(80243B1C);
    EVT_VAR(0) = 10004;
    spawn N(80243B1C);
    EVT_VAR(0) = 10005;
    spawn N(80243B1C);
    MakeLocalVertexCopy(0, 123, 1);
    SetCustomGfxBuilders(1, N(func_80240504_CCB814), 0);
    SetModelCustomGfx(123, 1, -1);
    SetModelCustomGfx(10001, 1, -1);
    SetModelCustomGfx(10002, 1, -1);
    SetModelCustomGfx(10003, 1, -1);
    SetModelCustomGfx(10004, 1, -1);
    SetModelCustomGfx(10005, 1, -1);
    MakeLocalVertexCopy(1, 57, 1);
    SetCustomGfxBuilders(2, N(func_802407D4_CCBAE4), 0);
    SetModelCustomGfx(57, 2, -1);
});

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

void playFX_82();

ApiStatus N(func_8024030C_CCB61C)(Evt* script, s32 isInitialCall) {
    playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc43.inc.c"

ApiStatus N(func_802403D4_CCB6E4)(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        script->varTable[14] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = 1;
    evt_set_variable(NULL, EVT_MAP_VAR(0), get_npc_unsafe(-4)->flags);
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024042C_CCB73C)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(-4);

    npc->flags = evt_get_variable(NULL, EVT_MAP_VAR(0));
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024046C_CCB77C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(0x194, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    return ApiStatus_DONE2;
}

// graphics macros
#ifdef NON_EQUIVALENT
s32 mdl_get_copied_gfx(s32);
void mdl_get_copied_vertices(s32, s32*, s32*, s32*);
void guMtxF2L(Matrix4f, Mtx* m);
void guMtxIdentF(Matrix4f);

void N(func_80240504_CCB814)(void) {
    Matrix4f matrix;
    s32 x, y, z;

    guMtxIdentF(matrix);

    matrix[0][0] = (sin_rad(N(D_80243B14_CCEE24) / 11.0f) * 0.04) + 0.98;
    matrix[0][1] = sin_rad(N(D_80243B14_CCEE24) / 12.0f) * 0.04;
    matrix[0][2] = cos_rad(N(D_80243B14_CCEE24) / 13.0f) * 0.04;

    matrix[1][1] = (sin_rad(N(D_80243B14_CCEE24) / 7.0f + 1.0f) * 0.04) + 0.98;
    matrix[1][0] = sin_rad(N(D_80243B14_CCEE24) / 14.0f) * 0.04;
    matrix[1][2] = cos_rad(N(D_80243B14_CCEE24) / 15.0f) * 0.04;

    matrix[2][2] = (sin_rad(N(D_80243B14_CCEE24) * 0.25f + 2.0f)  * 0.04) + 0.98;
    matrix[2][0] = sin_rad(N(D_80243B14_CCEE24) * 0.0625f) * 0.04;
    matrix[2][1] = cos_rad(N(D_80243B14_CCEE24) / 17.0f) * 0.04;

    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);

    mdl_get_copied_vertices(0, &x, &y, &z);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));

    N(D_80243B14_CCEE24) += 1.0f;
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_14/CCB310", flo_14_func_80240504_CCB814, void);
#endif

typedef struct {
    /* 0x00 */s16 unk_00;
    /* 0x02 */s16 unk_02;
    /* 0x04 */s16 unk_04;
    /* 0x06 */char unk_06[0xA];
} N(UnkStruct); // size = 0x10

void N(func_802407D4_CCBAE4)(void) {
    s32 i;
    N(UnkStruct)* x;
    N(UnkStruct)* y;
    s32 z;
    f32 temp_f20;
    f32 temp_f0;

    mdl_get_copied_vertices(1, &x, &y, &z);

    for (i = 0; i < z; i++) {
        N(UnkStruct)* ptr1 = &x[i];
        N(UnkStruct)* ptr2 = &y[i];

        if (ptr1->unk_00 < 0x259) {
            temp_f20 = (sin_rad((N(D_80243B18_CCEE28) / 180.0f) * 3.141592) * 0.3) + 0.7;
            temp_f0 = 0.2 - (sin_rad((N(D_80243B18_CCEE28) / 180.0f) * 3.141592) * 0.2);
            ptr2->unk_00 = ((ptr1->unk_00 - 0x268) * temp_f20) + 616.0f + (temp_f0 * -48.0f);
            ptr2->unk_02 = ((ptr1->unk_02 - 0x2C) * temp_f20) + 44.0f + (temp_f0 * 25.0f);
            ptr2->unk_04 = ((ptr1->unk_04 - 0x71) * temp_f20) + 113.0f + (temp_f0 * -87.0f);
        }
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(1));

    if (evt_get_variable(NULL, EVT_AREA_FLAG(36)) != 0) {
        if (N(D_80243B18_CCEE28) > 90) {
            N(D_80243B18_CCEE28) -= 360;
        }
        if (N(D_80243B18_CCEE28) >= -90) {
            N(D_80243B18_CCEE28) += 5;
        } else {
            N(D_80243B18_CCEE28) += 20;
        }
        if (N(D_80243B18_CCEE28) >= 90) {
            N(D_80243B18_CCEE28) = 90;
        }
    } else {
        if (((u32)N(D_80243B18_CCEE28) - 141) < 119) {
            N(D_802431CC_CCE4DC) = 1;
        } else {
            N(D_802431CC_CCE4DC) = 0;
        }
        N(D_80243B18_CCEE28) += 5;
    }

    if (N(D_80243B18_CCEE28) >= 360) {
        N(D_80243B18_CCEE28) -= 360;
    }
}
