#include "arn_11.h"
#include "sprite/npc/tubbas_heart.h"

enum {
    NPC_TUBBAS_HEART,
};

EvtSource N(802400F0) = SCRIPT({
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 3.0);
    UseSettingsFrom(0, 60, 30, 0);
    SetPanTarget(0, 60, 30, 0);
    SetCamPitch(0, 20.0, -13.0);
    SetCamDistance(0, 275);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
});

EvtSource N(802401BC) = SCRIPT({
    DisablePlayerInput(TRUE);
    sleep 30;
    SetPlayerSpeed(3.0);
    PlayerMoveTo(6, 0, 0);
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BF));
    sleep 10;
    SetPlayerAnimation(ANIM_80007);
    sleep 40;
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C0));
    SetPlayerAnimation(ANIM_10002);
    sleep 10;
    SetPlayerAnimation(0x90000);
    sleep 30;
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C1));
    SetPlayerAnimation(ANIM_10002);
    sleep 20;
    SetPlayerAnimation(0x90000);
    spawn {
        SetNpcJumpscale(NPC_TUBBAS_HEART, 2.5);
        GetNpcPos(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
        NpcJump0(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        sleep 1;
        PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
        NpcJump0(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    }
    sleep 40;
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C2));
    SetPlayerAnimation(0x90000);
    sleep 10;
    SetNpcVar(0, 0, 1);
    DisablePlayerInput(FALSE);
});

EvtSource N(exitSingleDoor_80240428) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 2;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_13", 1);
    sleep 100;
});

EvtSource N(802404CC) = SCRIPT({
    bind N(exitSingleDoor_80240428) TRIGGER_WALL_PRESS_A 2;
});

EvtSource N(enterSingleDoor_802404F8) = SCRIPT({
    DisablePlayerInput(TRUE);
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    await EnterSingleDoor;
    spawn N(802404CC);
    if (SI_STORY_PROGRESS < STORY_CH3_HEART_FLED_FIRST_TUNNEL) {
        sleep 10;
        spawn N(802400F0);
        spawn N(802401BC);
        sleep 1;
    }
    DisablePlayerInput(FALSE);
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_WINDY_MILL;
    SetSpriteShading(524290);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_802410DC));
    spawn N(80240050);
    spawn N(enterSingleDoor_802404F8);
    sleep 1;
});

static s32 N(pad_674)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80240680) = SCRIPT({

});

EvtSource N(80240690) = SCRIPT({

});

NpcSettings N(npcSettings_802406A0) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240680),
    .onDefeat = &N(80240690),
    .level = 13,
};

EvtSource N(idle_802406CC) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) != 0) {
            break loop;
        }
        sleep 1;
    }
    spawn {
        SetCamType(0, 6, 1);
        SetCamSpeed(0, 4.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 50;
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 3000);
        PanToTarget(0, 0, 1);
        WaitForCam(0, 1.0);
    }
    StartBossBattle(11);
});

EvtSource N(8024081C) = SCRIPT({
    sleep 15;
    PlaySoundAtCollider(2, 449, 0);
    MakeLerp(0, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(0, SI_VAR(0), 0, -1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
});

EvtSource N(802408D8) = SCRIPT({
    MakeLerp(80, 0, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(0, SI_VAR(0), 0, -1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlaySoundAtCollider(2, 450, 0);
});

s32 N(intTable_80240988)[] = {
    0x00000064, 0x0000001E, 0x00000046, 0x00000019, 0x0000001E, 0x00000050, 0xFFFFD8F0, 0x00000000,
    0x00000000, 0xFFFFFFBA, 0x0000000A, 0x00000014, 0xFFFFFF4C, 0x00000000, 0x00000000, 0xFFFFFED4,
    0x00000000, 0x00000000, 0xFFFFD8F0, 0x00000000, 0x00000000,
};

EvtSource N(defeat_802409DC) = SCRIPT({
    spawn {
        SetCamType(0, 6, 1);
        SetCamSpeed(0, 90.0);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 50;
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamDistance(0, 450);
        PanToTarget(0, 0, 1);
    }
    sleep 10;
    PlayerFaceNpc(0, 1);
    loop 2 {
        GetNpcPos(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetNpcJumpscale(NPC_TUBBAS_HEART, 2.5);
        PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
        NpcJump0(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12);
        sleep 1;
    }
    spawn {
        sleep 10;
        SetCamType(0, 4, 1);
        SetCamSpeed(0, 2.0);
        SetCamPitch(0, 17.0, -7.0);
        SetCamDistance(0, 450);
        SetCamPosA(0, -56, 70);
        SetCamPosB(0, -90, 40);
        SetCamPosC(0, 0, 0);
        PanToTarget(0, 0, 1);
    }
    PlayerFaceNpc(0, 1);
    buf_use N(intTable_80240988);
    loop {
        buf_read SI_VAR(0) SI_VAR(1) SI_VAR(2);
        if (SI_VAR(0) == -10000) {
            break loop;
        }
        PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
        NpcJump0(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12);
        sleep 1;
    }
    spawn N(8024081C);
    loop {
        buf_read SI_VAR(0) SI_VAR(1) SI_VAR(2);
        if (SI_VAR(0) == -10000) {
            break loop;
        }
        PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
        NpcJump0(NPC_TUBBAS_HEART, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12);
        sleep 1;
    }
    spawn N(802408D8);
    sleep 30;
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 90.0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 450);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    SI_STORY_PROGRESS = STORY_CH3_HEART_FLED_FIRST_TUNNEL;
});

EvtSource N(init_80240E70) = SCRIPT({
    if (SI_STORY_PROGRESS >= STORY_CH3_HEART_FLED_FIRST_TUNNEL) {
        RemoveNpc(NPC_SELF);
    } else {
        SetSelfVar(0, 0);
        BindNpcIdle(NPC_SELF, N(idle_802406CC));
        BindNpcDefeat(NPC_SELF, N(defeat_802409DC));
    }
});

StaticNpc N(npcGroup_80240EEC) = {
    .id = NPC_TUBBAS_HEART,
    .settings = &N(npcSettings_802406A0),
    .pos = { 119.0f, 60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
    .init = &N(init_80240E70),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
    },
};

NpcGroupList N(npcGroupList_802410DC) = {
    NPC_GROUP(N(npcGroup_80240EEC), BATTLE_ID(14, 15, 0, 0)),
    {},
};
