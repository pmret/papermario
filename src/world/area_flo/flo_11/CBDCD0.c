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

EvtSource N(802403E0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80240450) = {
    EVT_SET_GROUP(11)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802406FC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(GetEntryPos))
    EVT_SUB(EVT_VAR(2), 40)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_CALL(PlaySound, 0x163)
    EVT_CALL(func_802D286C, 256)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LOOP(40)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(3)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(2)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(GetCurrentFloor))
    EVT_WAIT_FRAMES(1)
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(80240A50) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_IF_EQ(EVT_VAR(4), 90)
        EVT_ADD(EVT_VAR(5), 40)
    EVT_ELSE
        EVT_SUB(EVT_VAR(5), 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(0), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 0x163)
    EVT_THREAD
        EVT_WAIT_FRAMES(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2304)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(SomeXYZFunc2), EVT_FIXED(1.0))
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_802D2520, ANIM_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(80240E40) = {
    EVT_CALL(N(UnkFunc25))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80240F1C))
    EVT_RETURN
    EVT_END
};

EvtSource N(80240F1C) = {
    EVT_CALL(N(SetPlayerStatusAnimFlags100000))
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_CALL(PlayerMoveTo, EVT_VAR(1), EVT_VAR(3), 3)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(SetPlayerFlagBits, 2097152, 1)
    EVT_CALL(N(GetCurrentCameraYawClamped180))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetPlayerFlagBits, 2097152, 0)
    EVT_CALL(PlaySound, 0x163)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_LOOP(40)
            EVT_SUB(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 2, 1, 1, 0)
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

EvtSource N(802410F8) = {
    EVT_CALL(IsPlayerOnValidFloor, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 26)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(27)
    EVT_CALL(N(SetPlayerStatusAnimFlags100000))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_ADD(EVT_VAR(6), 2)
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_SET(EVT_VAR(8), EVT_VAR(4))
    EVT_ADD(EVT_VAR(8), 180)
    EVT_IF_GE(EVT_VAR(4), 360)
        EVT_SUB(EVT_VAR(4), 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, EVT_VAR(8), 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 0x163)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_LOOP(40)
            EVT_CALL(N(SomeXYZFunc2), EVT_FIXED(1.0))
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_8024142C) = EXIT_WALK_SCRIPT(60,  0, "flo_23",  1);

EvtSource N(exitWalk_80241488) = EXIT_WALK_SCRIPT(60,  1, "flo_12",  0);

EvtSource N(802414E4) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 5)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241520) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 6)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024155C) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 7)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241598) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(802415D4) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 3)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241610) = {
    EVT_SET_GROUP(27)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 4)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024164C) = {
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_EXEC_WAIT(N(80240E40))
    EVT_RETURN
    EVT_END
};

EvtSource N(80241698) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241488), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024142C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_SET(EVT_VAR(0), 2)
    EVT_SET(EVT_VAR(1), 35)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(802414E4)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_SET(EVT_VAR(0), 3)
    EVT_SET(EVT_VAR(1), 34)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(80241520)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_SET(EVT_VAR(0), 4)
    EVT_SET(EVT_VAR(1), 33)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(8024155C)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_SET(EVT_VAR(0), 5)
    EVT_SET(EVT_VAR(1), 32)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(80241598)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_SET(EVT_VAR(0), 6)
    EVT_SET(EVT_VAR(1), 31)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(802415D4)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_SET(EVT_VAR(0), 7)
    EVT_SET(EVT_VAR(1), 30)
    EVT_SET(EVT_VAR(2), EVT_PTR(N(80241610)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, EVT_VAR(1), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(func_80044238, 5)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802430D4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_LE(EVT_VAR(0), 1)
        EVT_SET(EVT_VAR(0), EVT_PTR(N(80241698)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(80242240))
        EVT_WAIT_FRAMES(1)
    EVT_ELSE
        EVT_SET(EVT_VAR(10), EVT_PTR(N(80241698)))
        EVT_EXEC(N(802406FC))
        EVT_WAIT_FRAMES(1)
    EVT_END_IF
    EVT_EXEC_WAIT(N(802403E0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_802402E0_CBDFB0))
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000009)
    EVT_CALL(ModifyColliderFlags, 3, 10, 0x00000009)
    EVT_CALL(ModifyColliderFlags, 3, 11, 0x00000009)
    EVT_CALL(ModifyColliderFlags, 3, 12, 0x00000009)
    EVT_RETURN
    EVT_END
};

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

EvtSource N(80241CB4) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySound, SOUND_295)
        EVT_WAIT_FRAMES(EVT_VAR(0))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80241CF4) = {
    EVT_SET(EVT_VAR(0), 5)
    EVT_EXEC_GET_TID(N(80241CB4), EVT_MAP_VAR(11))
    EVT_THREAD
        EVT_CALL(LoadPath, 160, EVT_PTR(N(vectorList_80241AEC)), 8, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 160, EVT_PTR(N(vectorList_80241B4C)), 8, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(EVT_MAP_VAR(10), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241E4C) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 30, EVT_PTR(N(vectorList_80241BAC)), 4, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 45, EVT_PTR(N(vectorList_80241BDC)), 4, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(EVT_MAP_VAR(11))
    EVT_RETURN
    EVT_END
};

EvtSource N(80241F80) = {
    EVT_SET(EVT_VAR(0), 4)
    EVT_EXEC_GET_TID(N(80241CB4), EVT_MAP_VAR(11))
    EVT_THREAD
        EVT_CALL(LoadPath, 35, EVT_PTR(N(vectorList_80241C0C)), 3, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 35, EVT_PTR(N(vectorList_80241C30)), 3, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802420C8) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 40, EVT_PTR(N(vectorList_80241C54)), 4, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 40, EVT_PTR(N(vectorList_80241C84)), 4, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_WAIT_FRAMES(40)
    EVT_KILL_THREAD(EVT_MAP_VAR(11))
    EVT_RETURN
    EVT_END
};

EvtSource N(80242240) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1377), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(EVT_SAVE_VAR(0), 45)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(1375), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, 0, 460, 200, -240)
    EVT_CALL(SetNpcPos, 1, -100, 200, -50)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_LT(EVT_VAR(0), 440)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_MAP_VAR(10), 0)
    EVT_EXEC(N(80241CF4))
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(25.0), EVT_FIXED(-7.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(20)
    EVT_SET(EVT_VAR(0), 270)
    EVT_SET(EVT_VAR(1), 100)
    EVT_SET(EVT_VAR(2), -87)
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(14.0), EVT_FIXED(-11.0))
    EVT_CALL(SetCamPosA, 0, 87, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(SetCamPosC, 0, 87, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetCamDistance, 0, 150)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-16.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_MAP_VAR(10), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFaceNpc, 0, 1, 1)
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_EXEC(N(80241E4C))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0088))
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0089))
    EVT_CALL(InterpNpcYaw, 0, 0, 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x008A))
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakitu_Palette_00_Anim_16, NPC_ANIM_lakitu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x008B))
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(14.0), EVT_FIXED(-11.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(SetCamPosA, 0, 87, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_EXEC(N(80241F80))
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242810) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(AdjustCam, 0, EVT_FIXED(4.0), 0, 1000, EVT_FIXED(14.0), EVT_FIXED(-11.0))
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802428B8) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetNpcPos, 0, 400, 20, -40)
            EVT_CALL(SetNpcPos, 1, 400, 20, 40)
            EVT_CALL(InterpNpcYaw, 0, 270, 0)
            EVT_CALL(InterpNpcYaw, 1, 270, 0)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(2), -60)
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 900)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(24.0), EVT_FIXED(-4.0))
            EVT_CALL(SetCamPosA, 0, EVT_FIXED(-95.0), EVT_FIXED(0.0))
            EVT_CALL(SetCamPosB, 0, EVT_FIXED(0.0), EVT_FIXED(-50.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_EXEC_WAIT(N(802420C8))
            EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
            EVT_SET(EVT_SAVE_FLAG(1377), 1)
            EVT_SET(EVT_MAP_VAR(0), 1)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_80242AC4) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_LABEL(0)
            EVT_IF_EQ(EVT_MAP_VAR(0), 0)
                EVT_WAIT_FRAMES(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80242B58) = {
    EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1377), 0)
        EVT_IF_GE(EVT_SAVE_VAR(0), 45)
            EVT_IF_EQ(EVT_SAVE_FLAG(1375), 1)
                EVT_SET(EVT_MAP_VAR(0), 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242810)))
                EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802428B8)))
                EVT_CALL(SetNpcPos, 0, 350, 120, -220)
                EVT_CALL(InterpNpcYaw, 0, 270, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80242C38) = {
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1377), 0)
        EVT_IF_GE(EVT_SAVE_VAR(0), 45)
            EVT_IF_EQ(EVT_SAVE_FLAG(1375), 1)
                EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80242AC4)))
                EVT_CALL(SetNpcPos, 1, 200, 110, 29)
                EVT_CALL(InterpNpcYaw, 1, 0, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80242CF4)[] = {
    {
        .id = NPC_LAKITU0,
        .settings = &N(npcSettings_80241AC0),
        .pos = { 553.0f, 60.0f, 52.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_80242B58),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .dropFlags = NPC_DROP_FLAGS_80,
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

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA0E8, -220, 60, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1384))
    EVT_RETURN
    EVT_END
};

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
