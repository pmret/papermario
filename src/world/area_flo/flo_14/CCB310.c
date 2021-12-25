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

EvtSource N(802423F0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(updateTexturePan_80242460) = {
    EVT_SET_GROUP(0)
    EVT_IF_EQ(EVT_VAR(5), 1)
        EVT_IF_EQ(EVT_VAR(6), 1)
            EVT_IF_EQ(EVT_VAR(7), 1)
                EVT_IF_EQ(EVT_VAR(8), 1)
                    EVT_CALL(N(UnkTexturePanFunc))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UnkTexturePanFunc2))
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_802424FC) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  1);

EvtSource N(exitWalk_80242558) = EXIT_WALK_SCRIPT(60,  1, "flo_13",  0);

EvtSource N(802425B4) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242558), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802424FC), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_802425FC)[] = {
    0x0000001F, 0xC3FA0000, 0x00000000, 0xC2B40000, 0x00000019, 0xC3FF0000, 0x00000000, 0x00000000,
    0x00000020, 0xC3FA0000, 0x00000000, 0x42DC0000, 0x00000021, 0xC37A0000, 0x00000000, 0xC2B40000,
    0x0000001A, 0xC3700000, 0x00000000, 0x00000000, 0x00000022, 0xC37A0000, 0x00000000, 0x42DC0000,
    0x0000001B, 0xC2480000, 0x00000000, 0x41C80000, 0x0000001C, 0x428C0000, 0x42700000, 0xC2BE0000,
    0x0000001D, 0x43CD0000, 0x42700000, 0xC2BE0000, 0x0000001E, 0x44098000, 0x00000000, 0x42480000,
    0x00000023, 0xC2480000, 0x00000000, 0x42DC0000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244F00)))
    EVT_EXEC(N(80244F30))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_802425FC)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 29, 1)
    EVT_CALL(EnableTexPanning, 31, 1)
    EVT_CALL(EnableTexPanning, 32, 1)
    EVT_CALL(EnableTexPanning, 35, 1)
    EVT_CALL(EnableTexPanning, 36, 1)
    EVT_CALL(EnableTexPanning, 39, 1)
    EVT_CALL(EnableTexPanning, 41, 1)
    EVT_CALL(EnableTexPanning, 43, 1)
    EVT_CALL(EnableTexPanning, 45, 1)
    EVT_CALL(EnableTexPanning, 47, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_CALL(EnableTexPanning, 53, 1)
    EVT_CALL(EnableTexPanning, 30, 1)
    EVT_CALL(EnableTexPanning, 33, 1)
    EVT_CALL(EnableTexPanning, 34, 1)
    EVT_CALL(EnableTexPanning, 37, 1)
    EVT_CALL(EnableTexPanning, 38, 1)
    EVT_CALL(EnableTexPanning, 42, 1)
    EVT_CALL(EnableTexPanning, 44, 1)
    EVT_CALL(EnableTexPanning, 46, 1)
    EVT_CALL(EnableTexPanning, 48, 1)
    EVT_CALL(EnableTexPanning, 50, 1)
    EVT_CALL(EnableTexPanning, 52, 1)
    EVT_CALL(EnableTexPanning, 54, 1)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 1)
        EVT_SET(EVT_VAR(1), 140)
        EVT_SET(EVT_VAR(2), 0)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 1)
        EVT_SET(EVT_VAR(6), 0)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 2)
        EVT_SET(EVT_VAR(1), -200)
        EVT_SET(EVT_VAR(2), 0)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 1)
        EVT_SET(EVT_VAR(6), 0)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_EXEC(N(80243E78))
    EVT_EXEC(N(80245224))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802425B4)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802423F0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_8024030C_CCB61C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2BF4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80242C00) = {
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

EvtSource N(80242EAC) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(6))
    EVT_SET(EVT_VAR(8), EVT_VAR(5))
    EVT_SET(EVT_VAR(7), EVT_VAR(4))
    EVT_SET(EVT_VAR(6), EVT_VAR(3))
    EVT_SET(EVT_VAR(5), EVT_VAR(2))
    EVT_SET(EVT_VAR(4), EVT_VAR(1))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_CALL(EnableModel, EVT_VAR(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(EnableModel, EVT_VAR(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_SET(EVT_VAR(0), EVT_VAR(3))
            EVT_SET(EVT_VAR(1), EVT_VAR(4))
            EVT_SET(EVT_VAR(2), EVT_VAR(5))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_SUB(EVT_VAR(1), 10)
            EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, EVT_VAR(8), EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, EVT_VAR(9), EVT_VAR(0), 1, 0, 0)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, EVT_VAR(7), 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_802431CC_CCE4DC) = {
    0x00000000,
};

EvtSource N(802431D0) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(MakeLerp, EVT_VAR(1), 48, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(SetCamTarget, 0, EVT_VAR(2), EVT_VAR(0), EVT_VAR(4))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamTarget, 0, EVT_VAR(0), 48, EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802432E8) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 20)
        EVT_ADD(EVT_VAR(2), -5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3f N(vectorList_80243384)[] = {
    { 531.0, 75.0, 81.0 }, { 481.0, 80.0, 81.0 },
    { 431.0, 75.0, 81.0 }, { 381.0, 70.0, 81.0 },
    { 331.0, 75.0, 81.0 }, { 281.0, 80.0, 81.0 },
    { 231.0, 75.0, 81.0 }, { 181.0, 70.0, 81.0 },
    { 131.0, 75.0, 81.0 }, { 81.0, 80.0, 81.0 },
    { 31.0, 75.0, 81.0 }, { -19.0, 70.0, 81.0 },
    { -69.0, 75.0, 81.0 },
};

EvtSource N(80243420) = {
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySound, 0x80000023)
    EVT_CALL(LoadPath, 165, EVT_PTR(N(vectorList_80243384)), 13, 10)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(TranslateModel, 123, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_ADD(EVT_VAR(2), -27)
    EVT_ADD(EVT_VAR(3), -10)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(N(func_8024046C_CCB77C), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(StopSound, 0x80000023)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024352C) = {
    EVT_CALL(IsPlayerWithin, 531, 81, 30, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT_FRAMES(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetModelCenter, 123)
    EVT_THREAD
        EVT_ADD(EVT_VAR(2), -10)
        EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.2))
        EVT_CALL(PlayerJump, 531, 48, EVT_VAR(2), 10)
        EVT_CALL(SetPlayerActionState, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_ADD(EVT_VAR(2), -15)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.2))
        EVT_CALL(NpcJump0, NPC_PARTNER, 531, 68, EVT_VAR(2), 10)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(802431D0), EVT_MAP_VAR(9))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(N(func_802403D4_CCB6E4))
    EVT_IF_NE(EVT_VAR(14), 0)
        EVT_EXEC_GET_TID(N(802432E8), EVT_VAR(14))
    EVT_END_IF
    EVT_EXEC_WAIT(N(80243420))
    EVT_IF_NE(EVT_VAR(14), 0)
        EVT_KILL_THREAD(EVT_VAR(14))
        EVT_CALL(N(func_8024042C_CCB73C))
    EVT_END_IF
    EVT_CALL(GetModelCenter, 123)
    EVT_CALL(PlayEffect, 0x43, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 2, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAt, 0x2F3, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(EnableModel, 123, 0)
    EVT_SET(EVT_AREA_FLAG(37), 0)
    EVT_KILL_THREAD(EVT_MAP_VAR(9))
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80243870) = {
    EVT_CALL(PlaySoundAt, 0x193, 0, 591, 55, 121)
    EVT_CALL(EnableModel, 123, 1)
    EVT_SETF(EVT_VAR(2), EVT_FIXED(1.0))
    EVT_SETF(EVT_VAR(4), EVT_FIXED(0.0))
    EVT_SETF(EVT_VAR(5), EVT_FIXED(0.0))
    EVT_SETF(EVT_VAR(6), EVT_FIXED(0.0))
    EVT_SET(EVT_VAR(7), -30)
    EVT_SET(EVT_VAR(8), 20)
    EVT_DIVF(EVT_VAR(7), EVT_FIXED(90.0))
    EVT_DIVF(EVT_VAR(8), EVT_FIXED(90.0))
    EVT_SET(EVT_VAR(9), 180)
    EVT_LOOP(EVT_VAR(9))
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_SETF(EVT_VAR(3), EVT_VAR(2))
        EVT_DIVF(EVT_VAR(3), 10)
        EVT_CALL(ScaleModel, 123, EVT_VAR(3), EVT_VAR(3), EVT_VAR(3))
        EVT_CALL(TranslateModel, 123, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
        EVT_ADDF(EVT_VAR(2), EVT_FIXED(0.05))
        EVT_IF_GT(EVT_VAR(9), 90)
            EVT_ADDF(EVT_VAR(4), EVT_VAR(7))
            EVT_ADDF(EVT_VAR(5), EVT_VAR(8))
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_VAR(7), -30)
    EVT_SET(EVT_VAR(8), -40)
    EVT_DIVF(EVT_VAR(7), EVT_FIXED(60.0))
    EVT_DIVF(EVT_VAR(8), EVT_FIXED(60.0))
    EVT_LOOP(60)
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_CALL(ScaleModel, 123, EVT_VAR(3), EVT_VAR(3), EVT_VAR(3))
        EVT_CALL(TranslateModel, 123, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
        EVT_ADDF(EVT_VAR(4), EVT_VAR(7))
        EVT_ADDF(EVT_VAR(6), EVT_VAR(8))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_AREA_FLAG(36), 0)
    EVT_SET(EVT_AREA_FLAG(37), 1)
    EVT_RETURN
    EVT_END
};

s32 N(D_80243B14_CCEE24) = {
    0x00000000,
};

s32 N(D_80243B18_CCEE28) = {
    0x0000005A,
};

EvtSource N(80243B1C) = {
    EVT_SET_GROUP(0)
    EVT_SET(EVT_VAR(15), EVT_VAR(0))
    EVT_LABEL(0)
    EVT_IF_EQ(EVT_AREA_FLAG(35), 1)
        EVT_WAIT_FRAMES(10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(D_802431CC_CCE4DC)))
    EVT_BUF_READ1(EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(RandInt, 10, EVT_VAR(0))
        EVT_ADD(EVT_VAR(0), 1)
        EVT_WAIT_FRAMES(EVT_VAR(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnableModel, EVT_VAR(15), 1)
    EVT_CALL(RandInt, 4, EVT_VAR(0))
    EVT_ADDF(EVT_VAR(0), EVT_FIXED(4.0))
    EVT_MULF(EVT_VAR(0), EVT_FIXED(-1.0))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(2.0))
    EVT_SETF(EVT_VAR(2), EVT_VAR(0))
    EVT_DIVF(EVT_VAR(2), EVT_FIXED(10.0))
    EVT_SETF(EVT_VAR(3), EVT_FIXED(0.4))
    EVT_SETF(EVT_VAR(4), EVT_FIXED(591.0))
    EVT_SETF(EVT_VAR(5), EVT_FIXED(60.0))
    EVT_SETF(EVT_VAR(6), EVT_FIXED(121.0))
    EVT_CALL(RandInt, 3, EVT_VAR(7))
    EVT_ADDF(EVT_VAR(7), EVT_FIXED(3.0))
    EVT_MULF(EVT_VAR(7), EVT_FIXED(0.04))
    EVT_SETF(EVT_VAR(9), EVT_VAR(7))
    EVT_DIVF(EVT_VAR(9), EVT_FIXED(5.0))
    EVT_CALL(RandInt, 50, EVT_VAR(8))
    EVT_ADD(EVT_VAR(8), 50)
    EVT_LOOP(EVT_VAR(8))
        EVT_SETF(EVT_VAR(14), EVT_VAR(2))
        EVT_SUBF(EVT_VAR(14), EVT_VAR(0))
        EVT_MULF(EVT_VAR(14), EVT_FIXED(0.046875))
        EVT_ADDF(EVT_VAR(0), EVT_VAR(14))
        EVT_SETF(EVT_VAR(14), EVT_VAR(3))
        EVT_SUBF(EVT_VAR(14), EVT_VAR(1))
        EVT_MULF(EVT_VAR(14), EVT_FIXED(0.046875))
        EVT_ADDF(EVT_VAR(1), EVT_VAR(14))
        EVT_ADDF(EVT_VAR(4), EVT_VAR(0))
        EVT_ADDF(EVT_VAR(5), EVT_VAR(1))
        EVT_SETF(EVT_VAR(14), EVT_VAR(7))
        EVT_SUBF(EVT_VAR(14), EVT_VAR(9))
        EVT_MULF(EVT_VAR(14), EVT_FIXED(0.203125))
        EVT_ADDF(EVT_VAR(9), EVT_VAR(14))
        EVT_CALL(TranslateModel, EVT_VAR(15), EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
        EVT_CALL(ScaleModel, EVT_VAR(15), EVT_VAR(9), EVT_VAR(9), EVT_VAR(9))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, EVT_VAR(15), 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};


EvtSource N(80243E78) = {
    EVT_CALL(ModifyColliderFlags, 3, 31, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 32, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 33, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 34, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 35, 0x00000006)
    EVT_SET(EVT_VAR(0), -730)
    EVT_SET(EVT_VAR(1), -130)
    EVT_SET(EVT_VAR(2), -470)
    EVT_SET(EVT_VAR(3), -70)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(EVT_VAR(0), -730)
    EVT_SET(EVT_VAR(1), 70)
    EVT_SET(EVT_VAR(2), -470)
    EVT_SET(EVT_VAR(3), 140)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(EVT_VAR(0), -280)
    EVT_SET(EVT_VAR(1), 130)
    EVT_SET(EVT_VAR(2), -110)
    EVT_SET(EVT_VAR(3), -70)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(EVT_VAR(0), -280)
    EVT_SET(EVT_VAR(1), 70)
    EVT_SET(EVT_VAR(2), -10)
    EVT_SET(EVT_VAR(3), 140)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_CALL(GetModelCenter, 96)
    EVT_SET(EVT_VAR(3), 96)
    EVT_SET(EVT_VAR(4), 97)
    EVT_SET(EVT_VAR(5), 98)
    EVT_SET(EVT_VAR(6), 99)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 82)
    EVT_SET(EVT_VAR(3), 82)
    EVT_SET(EVT_VAR(4), 83)
    EVT_SET(EVT_VAR(5), 84)
    EVT_SET(EVT_VAR(6), 85)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 76)
    EVT_SET(EVT_VAR(3), 76)
    EVT_SET(EVT_VAR(4), 77)
    EVT_SET(EVT_VAR(5), 78)
    EVT_SET(EVT_VAR(6), 79)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 90)
    EVT_SET(EVT_VAR(3), 90)
    EVT_SET(EVT_VAR(4), 91)
    EVT_SET(EVT_VAR(5), 92)
    EVT_SET(EVT_VAR(6), 93)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(ModifyColliderFlags, 0, 15, 0x7FFFFE00)
    EVT_CALL(CloneModel, 124, 10001)
    EVT_CALL(CloneModel, 124, 10002)
    EVT_CALL(CloneModel, 124, 10003)
    EVT_CALL(CloneModel, 124, 10004)
    EVT_CALL(CloneModel, 124, 10005)
    EVT_CALL(EnableModel, 123, 0)
    EVT_CALL(EnableModel, 124, 0)
    EVT_CALL(EnableModel, 10001, 0)
    EVT_CALL(EnableModel, 10002, 0)
    EVT_CALL(EnableModel, 10003, 0)
    EVT_CALL(EnableModel, 10004, 0)
    EVT_CALL(EnableModel, 10005, 0)
    EVT_SET(EVT_VAR(0), 10001)
    EVT_EXEC(N(80243B1C))
    EVT_SET(EVT_VAR(0), 10002)
    EVT_EXEC(N(80243B1C))
    EVT_SET(EVT_VAR(0), 10003)
    EVT_EXEC(N(80243B1C))
    EVT_SET(EVT_VAR(0), 10004)
    EVT_EXEC(N(80243B1C))
    EVT_SET(EVT_VAR(0), 10005)
    EVT_EXEC(N(80243B1C))
    EVT_CALL(MakeLocalVertexCopy, 0, 123, 1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_PTR(N(func_80240504_CCB814)), 0)
    EVT_CALL(SetModelCustomGfx, 123, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10001, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10002, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10003, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10004, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10005, 1, -1)
    EVT_CALL(MakeLocalVertexCopy, 1, 57, 1)
    EVT_CALL(SetCustomGfxBuilders, 2, EVT_PTR(N(func_802407D4_CCBAE4)), 0)
    EVT_CALL(SetModelCustomGfx, 57, 2, -1)
    EVT_RETURN
    EVT_END
};

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
