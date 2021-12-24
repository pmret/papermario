#include "dgb_00.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_bombette.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kooper.h"
#include "sprite/npc/world_parakarry.h"

enum {
    NPC_BOO0,
    NPC_BOO1,
    NPC_BOO2,
    NPC_BOO3,
    NPC_BOO4,
    NPC_BOO5,
    NPC_SENTINEL,
};

NpcSettings N(npcSettings_80240640) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_8024066C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(80240698) = SCRIPT({
    EVT_VAR(3) = 0;
    EVT_VAR(3) -= EVT_VAR(2);
    ModifyColliderFlags(0, 18, 0x7FFFFE00);
    PlaySoundAtCollider(18, 455, 0);
    MakeLerp(0, 80, 30, 0);
10:
    UpdateLerp();
    RotateModel(7, EVT_VAR(0), 0, EVT_VAR(2), 0);
    RotateModel(5, EVT_VAR(0), 0, EVT_VAR(3), 0);
    sleep 1;
    if (EVT_VAR(1) != 0) {
        goto 10;
    }
});

EvtSource N(8024079C) = SCRIPT({
    EVT_VAR(3) = 0;
    EVT_VAR(3) -= EVT_VAR(2);
    MakeLerp(80, 0, 12, 0);
10:
    UpdateLerp();
    RotateModel(7, EVT_VAR(0), 0, EVT_VAR(2), 0);
    RotateModel(5, EVT_VAR(0), 0, EVT_VAR(3), 0);
    sleep 1;
    if (EVT_VAR(1) != 0) {
        goto 10;
    }
    ModifyColliderFlags(1, 18, 0x7FFFFE00);
    PlaySoundAtCollider(18, 456, 0);
});

EvtSource N(802408A0) = SCRIPT({
    GetNpcPos(NPC_BOO0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO0, EVT_VAR(0), EVT_VAR(2), 46);
});

EvtSource N(802408F8) = SCRIPT({
    GetNpcPos(NPC_BOO1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO1, EVT_VAR(0), EVT_VAR(2), 50);
});

EvtSource N(80240950) = SCRIPT({
    GetNpcPos(NPC_BOO2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO2, EVT_VAR(0), EVT_VAR(2), 53);
});

EvtSource N(802409A8) = SCRIPT({
    GetNpcPos(NPC_BOO3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO3, EVT_VAR(0), EVT_VAR(2), 46);
});

EvtSource N(80240A00) = SCRIPT({
    GetNpcPos(NPC_BOO4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO4, EVT_VAR(0), EVT_VAR(2), 50);
});

EvtSource N(80240A58) = SCRIPT({
    GetNpcPos(NPC_BOO5, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 200;
    NpcMoveTo(NPC_BOO5, EVT_VAR(0), EVT_VAR(2), 53);
});

EvtSource N(80240AB0) = SCRIPT({
    spawn N(802408A0);
    spawn N(802408F8);
    spawn N(80240950);
    spawn N(802409A8);
    spawn N(80240A00);
    spawn N(80240A58);
});

EvtSource N(80240B08) = SCRIPT({
    SetNpcJumpscale(NPC_BOO0, -0.19921875);
    NpcJump0(NPC_BOO0, 257, 30, -90, 5);
    EnableNpcShadow(NPC_BOO0, FALSE);
    SetNpcAnimation(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240B74) = SCRIPT({
    SetNpcJumpscale(NPC_BOO1, -0.2998046875);
    NpcJump0(NPC_BOO1, 272, 112, -81, 12);
    EnableNpcShadow(NPC_BOO1, FALSE);
    SetNpcAnimation(NPC_BOO1, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240BE0) = SCRIPT({
    SetNpcJumpscale(NPC_BOO2, -0.3994140625);
    NpcJump0(NPC_BOO2, 237, 120, -118, 10);
    EnableNpcShadow(NPC_BOO2, FALSE);
    SetNpcAnimation(NPC_BOO2, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240C4C) = SCRIPT({
    SetNpcJumpscale(NPC_BOO3, -0.2998046875);
    NpcJump0(NPC_BOO3, 280, 60, -79, 8);
    EnableNpcShadow(NPC_BOO3, FALSE);
    SetNpcAnimation(NPC_BOO3, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240CB8) = SCRIPT({
    SetNpcJumpscale(NPC_BOO4, -0.3994140625);
    NpcJump0(NPC_BOO4, 250, 81, -97, 9);
    EnableNpcShadow(NPC_BOO4, FALSE);
    SetNpcAnimation(NPC_BOO4, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240D24) = SCRIPT({
    SetNpcJumpscale(NPC_BOO5, -0.5);
    NpcJump0(NPC_BOO5, 227, 43, -123, 15);
    EnableNpcShadow(NPC_BOO5, FALSE);
    SetNpcAnimation(NPC_BOO5, NPC_ANIM_boo_Palette_01_Anim_6);
});

EvtSource N(80240D90) = SCRIPT({
    spawn N(80240B74);
    spawn N(80240BE0);
    spawn N(80240C4C);
    spawn N(80240CB8);
    spawn N(80240D24);
});

EvtSource N(80240DDC) = SCRIPT({
    GetNpcPos(NPC_BOO0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    loop {
        RandInt(5, EVT_VAR(10));
        EVT_VAR(10) += 2;
        EVT_VAR(11) = 0;
10:
        EVT_VAR(3) = EVT_VAR(0);
        EVT_VAR(3) += 1;
        SetNpcPos(NPC_BOO0, EVT_VAR(3), EVT_VAR(1), EVT_VAR(2));
        sleep 1;
        EVT_VAR(3) = EVT_VAR(0);
        EVT_VAR(3) += -1;
        SetNpcPos(NPC_BOO0, EVT_VAR(3), EVT_VAR(1), EVT_VAR(2));
        sleep 1;
        EVT_VAR(11) += 1;
        if (EVT_VAR(11) < EVT_VAR(10)) {
            goto 10;
        }
        RandInt(10, EVT_VAR(10));
        EVT_VAR(10) += 10;
        sleep EVT_VAR(10);
    }
});

EvtSource N(80240F50) = SCRIPT({
    group 239;
    loop {
        RandInt(50, EVT_VAR(0));
        EVT_VAR(0) += 80;
        sleep EVT_VAR(0);
        if (EVT_MAP_VAR(0) == 0) {
            DisablePlayerInput(TRUE);
            PlaySoundAt(SOUND_B4, 0, 240, 10, -125);
            ShakeCam(0, 0, 20, 2.0);
            ShowMessageAtScreenPos(MESSAGE_ID(0x0E, 0x00EF), 160, 40);
            DisablePlayerInput(FALSE);
        }
    }
});

EvtSource N(8024103C) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetPlayerPos(350, 10, -150);
    InterpPlayerYaw(270, 1);
    SetNpcPos(NPC_PARTNER, 350, 10, -150);
    EnablePartnerAI();
    SetCamType(0, 4, 0);
    SetCamSpeed(0, 90.0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) = 175;
    EVT_VAR(1) = 0;
    EVT_VAR(2) = -75;
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 40;
    SetNpcPos(NPC_BOO0, -60, 10, -70);
    SetNpcPos(NPC_BOO1, -100, 10, -110);
    SetNpcPos(NPC_BOO2, -140, 10, -150);
    SetNpcPos(NPC_BOO3, -100, 10, -30);
    SetNpcPos(NPC_BOO4, -140, 10, -70);
    SetNpcPos(NPC_BOO5, -180, 10, -100);
    await N(80240AB0);
    sleep 60;
    InterpNpcYaw(NPC_BOO0, 270, 1);
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DB));
    SpeakToPlayer(NPC_BOO4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DC));
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DD));
    PlaySoundAt(SOUND_B4, 0, 240, 10, -125);
    ShakeCam(0, 0, 20, 2.0);
    sleep 10;
    PlaySoundAt(SOUND_B4, 0, 240, 10, -125);
    ShakeCam(0, 0, 20, 2.0);
    InterpNpcYaw(NPC_BOO0, 90, 1);
    ShowMessageAtScreenPos(MESSAGE_ID(0x0E, 0x00DE), 160, 40);
    SetPlayerPos(350, 10, -150);
    InterpPlayerYaw(270, 1);
    SetNpcPos(NPC_PARTNER, 350, 10, -150);
    EVT_VAR(2) = 1;
    await N(80240698);
});

EvtSource N(802413F4) = SCRIPT({
    SetPlayerSpeed(8.0);
    PlayerMoveTo(184, -44, 0);
    PlaySoundAtNpc(NPC_BOO0, SOUND_262, 0);
    PlaySoundAtNpc(NPC_BOO1, SOUND_262, 0);
    PlaySoundAtNpc(NPC_BOO2, SOUND_262, 0);
    PlaySoundAtNpc(NPC_BOO3, SOUND_262, 0);
    PlaySoundAtNpc(NPC_BOO4, SOUND_262, 0);
    PlaySoundAtNpc(NPC_BOO5, SOUND_262, 0);
    ShowEmote(0, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(1, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(2, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(3, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(4, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(5, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    sleep 50;
    EVT_VAR(2) = 1;
    spawn N(8024079C);
    spawn N(80240D90);
    sleep 20;
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 6.0);
    SetCamPitch(0, 15.0, -15.0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamDistance(0, 300);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    EVT_VAR(10) = spawn N(80240DDC);
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00DF));
    kill EVT_VAR(10);
    SetPlayerAnimation(ANIM_80007);
    sleep 20;
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E0));
    sleep 20;
    SetPlayerAnimation(ANIM_NOD_YES);
    sleep 20;
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E1));
    DisablePartnerAI(0);
    GetCurrentPartnerID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk, NPC_ANIM_world_goombario_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E2));
        }
        == 2 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_kooper_normal_talk, NPC_ANIM_world_kooper_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E3));
        }
        == 3 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_bombette_normal_idle_fast, NPC_ANIM_world_bombette_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E4));
        }
        == 4 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E5));
        }
        == 9 {
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E6));
        }
    }
    EnablePartnerAI();
    SetCamType(0, 4, 0);
    SetCamSpeed(0, 6.0);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    PlaySoundAt(SOUND_B4, 0, 240, 10, -125);
    ShakeCam(0, 0, 20, 2.0);
    sleep 5;
    PlaySoundAt(SOUND_B4, 0, 240, 10, -125);
    ShakeCam(0, 0, 20, 2.0);
    ShowMessageAtScreenPos(MESSAGE_ID(0x0E, 0x00E7), 160, 40);
    await N(80240B08);
    sleep 10;
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 5, MESSAGE_ID(0x0E, 0x00E8));
    SetNpcAnimation(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6);
    spawn N(80240F50);
    EVT_STORY_PROGRESS = STORY_CH3_ESCAPED_TUBBAS_MANOR;
    DisablePlayerInput(FALSE);
});

EvtSource N(80241AA0) = SCRIPT({
    SetNpcPos(NPC_BOO0, 246, 30, -110);
    SetNpcPos(NPC_BOO1, 276, 120, -80);
    SetNpcPos(NPC_BOO2, 216, 120, -140);
    SetNpcPos(NPC_BOO3, 276, 60, -80);
    SetNpcPos(NPC_BOO4, 246, 90, -110);
    SetNpcPos(NPC_BOO5, 216, 60, -130);
    InterpNpcYaw(NPC_BOO0, 70, 1);
    InterpNpcYaw(NPC_BOO1, 99, 1);
    InterpNpcYaw(NPC_BOO2, 93, 1);
    InterpNpcYaw(NPC_BOO3, 74, 1);
    InterpNpcYaw(NPC_BOO4, 78, 1);
    InterpNpcYaw(NPC_BOO5, 81, 1);
    SetNpcAnimation(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6);
    SetNpcAnimation(NPC_BOO1, NPC_ANIM_boo_Palette_01_Anim_6);
    SetNpcAnimation(NPC_BOO2, NPC_ANIM_boo_Palette_01_Anim_6);
    SetNpcAnimation(NPC_BOO3, NPC_ANIM_boo_Palette_01_Anim_6);
    SetNpcAnimation(NPC_BOO4, NPC_ANIM_boo_Palette_01_Anim_6);
    SetNpcAnimation(NPC_BOO5, NPC_ANIM_boo_Palette_01_Anim_6);
    EnableNpcShadow(NPC_BOO0, FALSE);
    EnableNpcShadow(NPC_BOO1, FALSE);
    EnableNpcShadow(NPC_BOO2, FALSE);
    EnableNpcShadow(NPC_BOO3, FALSE);
    EnableNpcShadow(NPC_BOO4, FALSE);
    EnableNpcShadow(NPC_BOO5, FALSE);
});

EvtSource N(interact_80241CD8) = SCRIPT({
    EVT_MAP_VAR(0) = 1;
    SpeakToPlayer(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 5, MESSAGE_ID(0x0E, 0x00E9));
    SetNpcAnimation(NPC_BOO0, NPC_ANIM_boo_Palette_01_Anim_6);
    DisablePartnerAI(0);
    GetCurrentPartnerID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1 {
            AdjustCam(0, 6.0, 0, -275.0, 15.0, -6.0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk, NPC_ANIM_world_goombario_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EA));
            ResetCam(0, 6.0);
        }
        == 2 {
            AdjustCam(0, 6.0, 0, -275.0, 15.0, -6.0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_kooper_normal_talk, NPC_ANIM_world_kooper_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EB));
            ResetCam(0, 6.0);
        }
        == 3 {
            AdjustCam(0, 6.0, 0, -275.0, 15.0, -6.0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_bombette_normal_idle_fast, NPC_ANIM_world_bombette_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EC));
            ResetCam(0, 6.0);
        }
        == 4 {
            AdjustCam(0, 6.0, 0, -275.0, 15.0, -6.0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00ED));
            ResetCam(0, 6.0);
        }
        == 9 {
            AdjustCam(0, 6.0, 0, -275.0, 15.0, -6.0);
            SpeakToPlayer(NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00EE));
            ResetCam(0, 6.0);
        }
    }
    EnablePartnerAI();
    EVT_MAP_VAR(0) = 0;
});

EvtSource N(init_80241F70) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241CD8));
});

EvtSource N(init_80241F94) = SCRIPT({

});

EvtSource N(init_80241FA4) = SCRIPT({

});

EvtSource N(init_80241FB4) = SCRIPT({

});

EvtSource N(init_80241FC4) = SCRIPT({

});

EvtSource N(init_80241FD4) = SCRIPT({

});

StaticNpc N(npcGroup_80241FE4) = {
    .id = NPC_BOO0,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_400000,
    .init = &N(init_80241F70),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00B5),
};

StaticNpc N(npcGroup_802421D4) = {
    .id = NPC_BOO1,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241F94),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
};

StaticNpc N(npcGroup_802423C4) = {
    .id = NPC_BOO2,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FA4),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
};

StaticNpc N(npcGroup_802425B4) = {
    .id = NPC_BOO3,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FB4),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
};

StaticNpc N(npcGroup_802427A4) = {
    .id = NPC_BOO4,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FC4),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
};

StaticNpc N(npcGroup_80242994) = {
    .id = NPC_BOO5,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FD4),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_2,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_1,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_0,
        NPC_ANIM_boo_Palette_01_Anim_A,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
        NPC_ANIM_boo_Palette_01_Anim_3,
    },
};

EvtSource N(80242B84) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    SetNpcPos(NPC_PARTNER, 320, 10, -160);
    PlaySound(SOUND_32E);
    spawn {
        loop 180 {
            GetNpcPos(NPC_SENTINEL, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
            N(func_80240060_BFA100)();
            sleep 1;
        }
    }
    SetPlayerPos(320, 50, -160);
    InterpPlayerYaw(270, 0);
    SetPlayerAnimation(ANIM_80017);
    SetNpcPos(NPC_SENTINEL, 320, 70, -158);
    InterpNpcYaw(NPC_SENTINEL, 270, 0);
    SetNpcAnimation(NPC_SENTINEL, NPC_ANIM_sentinel_Palette_00_Anim_8);
    UseSettingsFrom(0, 175, 0, -35);
    SetPanTarget(0, 175, 0, -35);
    SetCamDistance(0, 540.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 20;
    spawn {
        EVT_VAR(2) = 1;
        spawn N(80240698);
    }
    sleep 15;
    spawn {
        SetPlayerJumpscale(0);
        PlayerJump1(175, 50, -35, 40);
    }
    spawn {
        DisablePartnerAI(0);
        sleep 1;
        InterpNpcYaw(NPC_PARTNER, 270, 0);
        SetNpcAnimation(NPC_PARTNER, 0x107);
        sleep 85;
        func_802CF56C(2);
        sleep 1;
        EnablePartnerAI();
    }
    NpcMoveTo(NPC_SENTINEL, 175, -33, 40);
    sleep 20;
    SetNpcPos(NPC_SENTINEL, 175, 85, -33);
    SetNpcAnimation(NPC_SENTINEL, NPC_ANIM_sentinel_Palette_00_Anim_9);
    sleep 20;
    PlaySoundAtNpc(NPC_SENTINEL, SOUND_2F7, 0);
    SetNpcAnimation(NPC_SENTINEL, NPC_ANIM_sentinel_Palette_00_Anim_2);
    SetNpcPos(NPC_SENTINEL, 175, 70, -33);
    spawn {
        sleep 40;
        SetNpcAnimation(NPC_SENTINEL, NPC_ANIM_sentinel_Palette_00_Anim_3);
        NpcMoveTo(NPC_SENTINEL, 270, -120, 30);
        StopSound(814);
        SetNpcPos(NPC_SENTINEL, 0, -1000, 0);
    }
    spawn {
        sleep 60;
        EVT_VAR(2) = 1;
        spawn N(8024079C);
    }
    SetPlayerJumpscale(0);
    PlayerJump1(175, 0, -35, 10);
    PlaySoundAtNpc(NPC_SENTINEL, SOUND_162, 0);
    SetPlayerAnimation(ANIM_80003);
    spawn {
        sleep 2;
        PlayEffect(0x10, 3, 0, 175, 0, -35, 20, -20, 30, 0, 0, 0, 0, 0);
    }
    spawn {
        SetCamDistance(0, 320.0);
        SetCamPitch(0, 15.0, -7.5);
        SetCamSpeed(0, 2.0);
        PanToTarget(0, 0, 1);
    }
    sleep 65;
    GetCurrentPartnerID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1 {
            SetNpcFlagBits(NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE);
        }
        == 2 {
            SetNpcFlagBits(NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE);
        }
        == 3 {
            SetNpcFlagBits(NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE);
        }
    }
    DisablePartnerAI(0);
    GetCurrentPartnerID(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1 {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D6));
        }
        == 2 {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D7));
        }
        == 3 {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D8));
        }
        == 4 {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D9));
        }
        == 9 {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00DA));
        } else {
            SpeakToPlayer(NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D6));
        }
    }
    EnablePartnerAI();
    sleep 5;
    SetPlayerAnimation(ANIM_GET_UP);
    sleep 20;
    SetPlayerAnimation(ANIM_DUST_OFF);
    sleep 7;
    PlaySoundAtPlayer(370, 0);
    sleep 8;
    PlaySoundAtPlayer(370, 0);
    sleep 15;
    SetPlayerAnimation(ANIM_8001B);
    sleep 25;
    InterpPlayerYaw(90, 0);
    sleep 1;
    SetPlayerAnimation(ANIM_10002);
    InterpPlayerYaw(45, 0);
    sleep 10;
    SetPlayerAnimation(ANIM_MIDAIR_STILL);
    SetPlayerJumpscale(1);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    PlayerJump1(EVT_VAR(0), 0, EVT_VAR(2), 10);
    PlayerJump1(EVT_VAR(0), 0, EVT_VAR(2), 10);
    SetPlayerAnimation(ANIM_10002);
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    UseSettingsFrom(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetPanTarget(0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    EnablePartnerAI();
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
});

EvtSource N(init_802434EC) = SCRIPT({

});

StaticNpc N(npcGroup_802434FC) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_8024066C),
    .pos = { 0.0f, 0.0f, -1000.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_400000,
    .init = &N(init_802434EC),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_802436EC) = {
    NPC_GROUP(N(npcGroup_80241FE4), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802421D4), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802423C4), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802425B4), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802427A4), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80242994), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80243740) = {
    NPC_GROUP(N(npcGroup_802434FC), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_3758)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802E9A18, -65, 60, -240, 0, MAKE_ENTITY_END);
});

ApiStatus N(func_80240060_BFA100)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(get_enemy(6)->npcID);

    sfx_adjust_env_sound_pos(0x32E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}
