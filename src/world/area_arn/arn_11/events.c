#include "arn_11.h"
#include "sprite/npc/tubbas_heart.h"

enum {
    NPC_TUBBAS_HEART,
};

EvtSource N(802400F0) = {
    EVT_CALL(SetCamType, 0, 6, 1)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(3.0))
    EVT_CALL(UseSettingsFrom, 0, 60, 30, 0)
    EVT_CALL(SetPanTarget, 0, 60, 30, 0)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(20.0), EVT_FIXED(-13.0))
    EVT_CALL(SetCamDistance, 0, 275)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_RETURN
    EVT_END
};

EvtSource N(802401BC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetPlayerSpeed, EVT_FIXED(3.0))
    EVT_CALL(PlayerMoveTo, 6, 0, 0)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00BF))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80007)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00C0))
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, 589824)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00C1))
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetPlayerAnimation, 589824)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, 0, EVT_FIXED(2.5))
        EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
        EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
        EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00C2))
    EVT_CALL(SetPlayerAnimation, 589824)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitSingleDoor_80240428) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 2)
    EVT_SET(EVT_VAR(2), 0)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_13"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(802404CC) = {
    EVT_BIND_TRIGGER(N(exitSingleDoor_80240428), TRIGGER_WALL_PRESS_A, 2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterSingleDoor_802404F8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(2), 0)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_EXEC(N(802404CC))
    EVT_IF_LT(EVT_SAVE_VAR(0), -22)
        EVT_WAIT_FRAMES(10)
        EVT_EXEC(N(802400F0))
        EVT_EXEC(N(802401BC))
        EVT_WAIT_FRAMES(1)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 35)
    EVT_CALL(SetSpriteShading, 524290)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802410DC)))
    EVT_EXEC(N(80240050))
    EVT_EXEC(N(enterSingleDoor_802404F8))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_674)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80240680) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(80240690) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802406A0) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240680),
    .onDefeat = &N(80240690),
    .level = 13,
};

EvtSource N(idle_802406CC) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(SetCamType, 0, 6, 1)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 50)
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 3000)
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, 11)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024081C) = {
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtCollider, 2, 449, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 0, EVT_VAR(0), 0, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802408D8) = {
    EVT_CALL(MakeLerp, 80, 0, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 0, EVT_VAR(0), 0, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, 2, 450, 0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80240988)[] = {
    0x00000064, 0x0000001E, 0x00000046, 0x00000019, 0x0000001E, 0x00000050, 0xFFFFD8F0, 0x00000000,
    0x00000000, 0xFFFFFFBA, 0x0000000A, 0x00000014, 0xFFFFFF4C, 0x00000000, 0x00000000, 0xFFFFFED4,
    0x00000000, 0x00000000, 0xFFFFD8F0, 0x00000000, 0x00000000,
};

EvtSource N(defeat_802409DC) = {
    EVT_THREAD
        EVT_CALL(SetCamType, 0, 6, 1)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 50)
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 450)
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlayerFaceNpc, 0, 1)
    EVT_LOOP(2)
        EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetNpcJumpscale, 0, EVT_FIXED(2.5))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
        EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 12)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetCamType, 0, 4, 1)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-7.0))
        EVT_CALL(SetCamDistance, 0, 450)
        EVT_CALL(SetCamPosA, 0, -56, 70)
        EVT_CALL(SetCamPosB, 0, -90, 40)
        EVT_CALL(SetCamPosC, 0, 0, 0)
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, 0, 1)
    EVT_USE_BUF(EVT_PTR(N(intTable_80240988)))
    EVT_LOOP(0)
        EVT_BUF_READ3(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_EQ(EVT_VAR(0), -10000)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
        EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 12)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_EXEC(N(8024081C))
    EVT_LOOP(0)
        EVT_BUF_READ3(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_EQ(EVT_VAR(0), -10000)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
        EVT_CALL(NpcJump0, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 12)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_EXEC(N(802408D8))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetCamType, 0, 6, 1)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(EVT_SAVE_VAR(0), -22)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80240E70) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), -22)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_802406CC)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802409DC)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80240EEC) = {
    .id = NPC_TUBBAS_HEART,
    .settings = &N(npcSettings_802406A0),
    .pos = { 119.0f, 60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
    .init = &N(init_80240E70),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_802410DC) = {
    NPC_GROUP(N(npcGroup_80240EEC), BATTLE_ID(14, 15, 0, 0)),
    {},
};
