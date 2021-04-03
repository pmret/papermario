#include "arn_11.h"
#include "sprite/npc/tubbas_heart.h"

Script N(802400F0) = SCRIPT({
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 3.0);
    UseSettingsFrom(0, 60, 30, 0);
    SetPanTarget(0, 60, 30, 0);
    SetCamPitch(0, 20.0, -13.0);
    SetCamDistance(0, 275);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
});

Script N(802401BC) = SCRIPT({
    DisablePlayerInput(TRUE);
    sleep 30;
    SetPlayerSpeed(3.0);
    PlayerMoveTo(6, 0, 0);
    SpeakToPlayer(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00BF));
    sleep 10;
    SetPlayerAnimation(0x80007);
    sleep 40;
    SpeakToPlayer(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C0));
    SetPlayerAnimation(ANIM_10002);
    sleep 10;
    SetPlayerAnimation(0x90000);
    sleep 30;
    SpeakToPlayer(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C1));
    SetPlayerAnimation(ANIM_10002);
    sleep 20;
    SetPlayerAnimation(0x90000);
    spawn {
        SetNpcJumpscale(NPC_PLAYER, 2.5);
        GetNpcPos(NPC_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlaySoundAtNpc(NPC_PLAYER, 0x20C8, 0);
        NpcJump0(NPC_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        sleep 1;
        PlaySoundAtNpc(NPC_PLAYER, 0x20C8, 0);
        NpcJump0(NPC_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    }
    sleep 40;
    SpeakToPlayer(NPC_PLAYER, NPC_ANIM(tubbas_heart, Palette_00, Anim_B), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00C2));
    SetPlayerAnimation(0x90000);
    sleep 10;
    SetNpcVar(0, 0, 1);
    DisablePlayerInput(FALSE);
});

Script N(exitSingleDoor_80240428) = SCRIPT({
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

Script N(802404CC) = SCRIPT({
    bind N(exitSingleDoor_80240428) to TRIGGER_WALL_PRESS_A 2;
});

Script N(enterSingleDoor_802404F8) = SCRIPT({
    DisablePlayerInput(TRUE);
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    await EnterSingleDoor;
    spawn N(802404CC);
    if (STORY_PROGRESS < STORY_CH3_HEART_FLED_FIRST_TUNNEL) {
        sleep 10;
        spawn N(802400F0);
        spawn N(802401BC);
        sleep 1;
    }
    DisablePlayerInput(FALSE);
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_WINDY_MILL;
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

Script N(80240680) = SCRIPT({

});

Script N(80240690) = SCRIPT({

});

NpcSettings N(npcSettings_802406A0) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240680),
    .onDefeat = &N(80240690),
    .level = 13,
};

Script N(idle_802406CC) = SCRIPT({
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

Script N(8024081C) = SCRIPT({
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

Script N(802408D8) = SCRIPT({
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

// *INDENT-OFF*
Script N(defeat_802409DC) = {
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetCamType, 0, 6, 1),
        SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(90.0)),
        SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 50),
        SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_CALL, SetCamDistance, 0, 450),
        SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
    SI_CMD(ScriptOpcode_CALL, PlayerFaceNpc, 0, 1),
    SI_CMD(ScriptOpcode_LOOP, 2),
        SI_CMD(ScriptOpcode_CALL, GetNpcPos, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_CALL, SetNpcJumpscale, 0, SI_FIXED(2.5)),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, -1, 8392, 0),
        SI_CMD(ScriptOpcode_CALL, NpcJump0, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
        SI_CMD(ScriptOpcode_CALL, SetCamType, 0, 4, 1),
        SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(2.0)),
        SI_CMD(ScriptOpcode_CALL, SetCamPitch, 0, SI_FIXED(17.0), SI_FIXED(-7.0)),
        SI_CMD(ScriptOpcode_CALL, SetCamDistance, 0, 450),
        SI_CMD(ScriptOpcode_CALL, SetCamPosA, 0, -56, 70),
        SI_CMD(ScriptOpcode_CALL, SetCamPosB, 0, -90, 40),
        SI_CMD(ScriptOpcode_CALL, SetCamPosC, 0, 0, 0),
        SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, PlayerFaceNpc, 0, 1),
    SI_CMD(ScriptOpcode_USE_BUFFER, N(intTable_80240988)),
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), -10000),
            SI_CMD(ScriptOpcode_BREAK_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, -1, 8392, 0),
        SI_CMD(ScriptOpcode_CALL, NpcJump0, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(8024081C)),
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), -10000),
            SI_CMD(ScriptOpcode_BREAK_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, -1, 8392, 0),
        SI_CMD(ScriptOpcode_CALL, NpcJump0, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 12),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(802408D8)),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
    SI_CMD(ScriptOpcode_CALL, SetCamType, 0, 6, 1),
    SI_CMD(ScriptOpcode_CALL, SetCamSpeed, 0, SI_FIXED(90.0)),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
    SI_CMD(ScriptOpcode_CALL, UseSettingsFrom, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
    SI_CMD(ScriptOpcode_CALL, SetPanTarget, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
    SI_CMD(ScriptOpcode_CALL, SetCamDistance, 0, 450),
    SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 1),
    SI_CMD(ScriptOpcode_CALL, WaitForCam, 0, SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_CALL, PanToTarget, 0, 0, 0),
    SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(0), -22),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(init_80240E70) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH3_HEART_FLED_FIRST_TUNNEL) {
        RemoveNpc(NPC_SELF);
    } else {
        SetSelfVar(0, 0);
        BindNpcIdle(NPC_SELF, N(idle_802406CC));
        BindNpcDefeat(NPC_SELF, N(defeat_802409DC));
    }
});

StaticNpc N(npcGroup_80240EEC) = {
    .id = 0,
    .settings = &N(npcSettings_802406A0),
    .pos = { 119.0f, 60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_200 | NPC_FLAG_IGNORE_HEIGHT | 0x00040000,
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
