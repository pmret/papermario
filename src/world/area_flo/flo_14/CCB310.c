#include "flo_14.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {  720.0f, 0.0f, 0.0f, 270.0f },
    { -720.0f, 0.0f, 0.0f,  90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_14_tattle },
};

EvtScript N(802423F0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(updateTexturePan_80242460) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(LocalVar(5), 1)
        EVT_IF_EQ(LocalVar(6), 1)
            EVT_IF_EQ(LocalVar(7), 1)
                EVT_IF_EQ(LocalVar(8), 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_802424FC) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  1);

EvtScript N(exitWalk_80242558) = EXIT_WALK_SCRIPT(60,  1, "flo_13",  0);

EvtScript N(802425B4) = {
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

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_80244F00)))
    EVT_EXEC(N(80244F30))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_ADDR(N(lavaResetList_802425FC)))
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
        EVT_SET(LocalVar(0), 1)
        EVT_SET(LocalVar(1), 140)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 2)
        EVT_SET(LocalVar(1), -200)
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 0)
        EVT_SET(LocalVar(5), 1)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(LocalVar(9), 0)
        EVT_SET(LocalVar(10), 0)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_EXEC(N(80243E78))
    EVT_EXEC(N(80245224))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LocalVar(0), EVT_ADDR(N(802425B4)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802423F0))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_8024030C_CCB61C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2BF4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80242C00) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_SET(LocalVar(12), LocalVar(2))
    EVT_SET(LocalVar(13), LocalVar(3))
    EVT_SET(LocalVar(14), LocalVar(4))
    EVT_SUB(LocalVar(12), LocalVar(0))
    EVT_SUB(LocalVar(13), LocalVar(1))
    EVT_SETF(LocalVar(0), LocalVar(12))
    EVT_DIVF(LocalVar(0), EVT_FLOAT(100.0))
    EVT_SETF(LocalVar(15), EVT_FLOAT(100.0))
    EVT_DIVF(LocalVar(15), LocalVar(0))
    EVT_ADD(LocalVar(15), 11)
    EVT_SET(LocalVar(5), 200)
    EVT_DIV(LocalVar(5), LocalVar(15))
    EVT_ADD(LocalVar(5), 1)
    EVT_LOOP(LocalVar(5))
        EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
        EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
        EVT_CALL(RandInt, 199, LocalVar(2))
        EVT_SET(LocalVar(3), 210)
        EVT_SUB(LocalVar(3), LocalVar(2))
        EVT_ADD(LocalVar(0), LocalVar(10))
        EVT_ADD(LocalVar(1), LocalVar(11))
        EVT_ADD(LocalVar(2), LocalVar(14))
        EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(2), LocalVar(1), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LocalVar(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
    EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
    EVT_ADD(LocalVar(0), LocalVar(10))
    EVT_ADD(LocalVar(1), LocalVar(11))
    EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(14), LocalVar(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LocalVar(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242EAC) = {
    EVT_SET(LocalVar(9), LocalVar(6))
    EVT_SET(LocalVar(8), LocalVar(5))
    EVT_SET(LocalVar(7), LocalVar(4))
    EVT_SET(LocalVar(6), LocalVar(3))
    EVT_SET(LocalVar(5), LocalVar(2))
    EVT_SET(LocalVar(4), LocalVar(1))
    EVT_SET(LocalVar(3), LocalVar(0))
    EVT_CALL(EnableModel, LocalVar(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LocalVar(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(LocalVar(10), 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LocalVar(0), LocalVar(3))
            EVT_SET(LocalVar(1), LocalVar(4))
            EVT_SET(LocalVar(2), LocalVar(5))
            EVT_ADD(LocalVar(1), 10)
            EVT_ADD(LocalVar(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_SUB(LocalVar(1), 10)
            EVT_CALL(MakeItemEntity, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LocalVar(8), LocalVar(0), 1, 0, 0)
    EVT_CALL(RotateModel, LocalVar(9), LocalVar(0), 1, 0, 0)
    EVT_IF_EQ(LocalVar(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LocalVar(7), 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_802431CC_CCE4DC) = {
    0x00000000,
};

EvtScript N(802431D0) = {
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(MakeLerp, LocalVar(1), 48, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LocalVar(2), LocalVar(3), LocalVar(4))
        EVT_CALL(SetCamTarget, 0, LocalVar(2), LocalVar(0), LocalVar(4))
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetCamTarget, 0, LocalVar(0), 48, LocalVar(2))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802432E8) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 20)
        EVT_ADD(LocalVar(2), -5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(1)
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

EvtScript N(80243420) = {
    EVT_WAIT(20)
    EVT_CALL(PlaySound, 0x80000023)
    EVT_CALL(LoadPath, 165, EVT_ADDR(N(vectorList_80243384)), 13, 10)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(TranslateModel, 123, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_ADD(LocalVar(2), -27)
    EVT_ADD(LocalVar(3), -10)
    EVT_CALL(SetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(N(func_8024046C_CCB77C), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_WAIT(1)
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(StopSound, 0x80000023)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024352C) = {
    EVT_CALL(IsPlayerWithin, 531, 81, 30, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartner, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetModelCenter, 123)
    EVT_THREAD
        EVT_ADD(LocalVar(2), -10)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
        EVT_CALL(PlayerJump, 531, 48, LocalVar(2), 10)
        EVT_CALL(SetPlayerActionState, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_ADD(LocalVar(2), -15)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.2))
        EVT_CALL(NpcJump0, NPC_PARTNER, 531, 68, LocalVar(2), 10)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(802431D0), MapVar(9))
    EVT_WAIT(15)
    EVT_CALL(N(func_802403D4_CCB6E4))
    EVT_IF_NE(LocalVar(14), 0)
        EVT_EXEC_GET_TID(N(802432E8), LocalVar(14))
    EVT_END_IF
    EVT_EXEC_WAIT(N(80243420))
    EVT_IF_NE(LocalVar(14), 0)
        EVT_KILL_THREAD(LocalVar(14))
        EVT_CALL(N(func_8024042C_CCB73C))
    EVT_END_IF
    EVT_CALL(GetModelCenter, 123)
    EVT_CALL(PlayEffect, 0x43, 0, LocalVar(0), LocalVar(1), LocalVar(2), 2, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAt, 0x2F3, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(EnableModel, 123, 0)
    EVT_SET(AreaFlag(37), 0)
    EVT_KILL_THREAD(MapVar(9))
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80243870) = {
    EVT_CALL(PlaySoundAt, 0x193, 0, 591, 55, 121)
    EVT_CALL(EnableModel, 123, 1)
    EVT_SETF(LocalVar(2), EVT_FLOAT(1.0))
    EVT_SETF(LocalVar(4), EVT_FLOAT(0.0))
    EVT_SETF(LocalVar(5), EVT_FLOAT(0.0))
    EVT_SETF(LocalVar(6), EVT_FLOAT(0.0))
    EVT_SET(LocalVar(7), -30)
    EVT_SET(LocalVar(8), 20)
    EVT_DIVF(LocalVar(7), EVT_FLOAT(90.0))
    EVT_DIVF(LocalVar(8), EVT_FLOAT(90.0))
    EVT_SET(LocalVar(9), 180)
    EVT_LOOP(LocalVar(9))
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_SETF(LocalVar(3), LocalVar(2))
        EVT_DIVF(LocalVar(3), 10)
        EVT_CALL(ScaleModel, 123, LocalVar(3), LocalVar(3), LocalVar(3))
        EVT_CALL(TranslateModel, 123, LocalVar(4), LocalVar(5), LocalVar(6))
        EVT_ADDF(LocalVar(2), EVT_FLOAT(0.05))
        EVT_IF_GT(LocalVar(9), 90)
            EVT_ADDF(LocalVar(4), LocalVar(7))
            EVT_ADDF(LocalVar(5), LocalVar(8))
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LocalVar(7), -30)
    EVT_SET(LocalVar(8), -40)
    EVT_DIVF(LocalVar(7), EVT_FLOAT(60.0))
    EVT_DIVF(LocalVar(8), EVT_FLOAT(60.0))
    EVT_LOOP(60)
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_CALL(ScaleModel, 123, LocalVar(3), LocalVar(3), LocalVar(3))
        EVT_CALL(TranslateModel, 123, LocalVar(4), LocalVar(5), LocalVar(6))
        EVT_ADDF(LocalVar(4), LocalVar(7))
        EVT_ADDF(LocalVar(6), LocalVar(8))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(AreaFlag(36), 0)
    EVT_SET(AreaFlag(37), 1)
    EVT_RETURN
    EVT_END
};

f32 N(D_80243B14_CCEE24) = 0.0f;

s32 N(D_80243B18_CCEE28) = {
    0x0000005A,
};

EvtScript N(80243B1C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LocalVar(15), LocalVar(0))
    EVT_LABEL(0)
    EVT_IF_EQ(AreaFlag(35), 1)
        EVT_WAIT(10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_USE_BUF(EVT_ADDR(N(D_802431CC_CCE4DC)))
    EVT_BUF_READ1(LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(RandInt, 10, LocalVar(0))
        EVT_ADD(LocalVar(0), 1)
        EVT_WAIT(LocalVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnableModel, LocalVar(15), 1)
    EVT_CALL(RandInt, 4, LocalVar(0))
    EVT_ADDF(LocalVar(0), EVT_FLOAT(4.0))
    EVT_MULF(LocalVar(0), EVT_FLOAT(-1.0))
    EVT_SETF(LocalVar(1), EVT_FLOAT(2.0))
    EVT_SETF(LocalVar(2), LocalVar(0))
    EVT_DIVF(LocalVar(2), EVT_FLOAT(10.0))
    EVT_SETF(LocalVar(3), EVT_FLOAT(0.4))
    EVT_SETF(LocalVar(4), EVT_FLOAT(591.0))
    EVT_SETF(LocalVar(5), EVT_FLOAT(60.0))
    EVT_SETF(LocalVar(6), EVT_FLOAT(121.0))
    EVT_CALL(RandInt, 3, LocalVar(7))
    EVT_ADDF(LocalVar(7), EVT_FLOAT(3.0))
    EVT_MULF(LocalVar(7), EVT_FLOAT(0.04))
    EVT_SETF(LocalVar(9), LocalVar(7))
    EVT_DIVF(LocalVar(9), EVT_FLOAT(5.0))
    EVT_CALL(RandInt, 50, LocalVar(8))
    EVT_ADD(LocalVar(8), 50)
    EVT_LOOP(LocalVar(8))
        EVT_SETF(LocalVar(14), LocalVar(2))
        EVT_SUBF(LocalVar(14), LocalVar(0))
        EVT_MULF(LocalVar(14), EVT_FLOAT(0.046875))
        EVT_ADDF(LocalVar(0), LocalVar(14))
        EVT_SETF(LocalVar(14), LocalVar(3))
        EVT_SUBF(LocalVar(14), LocalVar(1))
        EVT_MULF(LocalVar(14), EVT_FLOAT(0.046875))
        EVT_ADDF(LocalVar(1), LocalVar(14))
        EVT_ADDF(LocalVar(4), LocalVar(0))
        EVT_ADDF(LocalVar(5), LocalVar(1))
        EVT_SETF(LocalVar(14), LocalVar(7))
        EVT_SUBF(LocalVar(14), LocalVar(9))
        EVT_MULF(LocalVar(14), EVT_FLOAT(0.203125))
        EVT_ADDF(LocalVar(9), LocalVar(14))
        EVT_CALL(TranslateModel, LocalVar(15), LocalVar(4), LocalVar(5), LocalVar(6))
        EVT_CALL(ScaleModel, LocalVar(15), LocalVar(9), LocalVar(9), LocalVar(9))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LocalVar(15), 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};


EvtScript N(80243E78) = {
    EVT_CALL(ModifyColliderFlags, 3, 31, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 32, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 33, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 34, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 35, 0x00000006)
    EVT_SET(LocalVar(0), -730)
    EVT_SET(LocalVar(1), -130)
    EVT_SET(LocalVar(2), -470)
    EVT_SET(LocalVar(3), -70)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LocalVar(0), -730)
    EVT_SET(LocalVar(1), 70)
    EVT_SET(LocalVar(2), -470)
    EVT_SET(LocalVar(3), 140)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LocalVar(0), -280)
    EVT_SET(LocalVar(1), 130)
    EVT_SET(LocalVar(2), -110)
    EVT_SET(LocalVar(3), -70)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LocalVar(0), -280)
    EVT_SET(LocalVar(1), 70)
    EVT_SET(LocalVar(2), -10)
    EVT_SET(LocalVar(3), 140)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80242C00))
    EVT_CALL(GetModelCenter, 96)
    EVT_SET(LocalVar(3), 96)
    EVT_SET(LocalVar(4), 97)
    EVT_SET(LocalVar(5), 98)
    EVT_SET(LocalVar(6), 99)
    EVT_SET(LocalVar(10), 174)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 82)
    EVT_SET(LocalVar(3), 82)
    EVT_SET(LocalVar(4), 83)
    EVT_SET(LocalVar(5), 84)
    EVT_SET(LocalVar(6), 85)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 76)
    EVT_SET(LocalVar(3), 76)
    EVT_SET(LocalVar(4), 77)
    EVT_SET(LocalVar(5), 78)
    EVT_SET(LocalVar(6), 79)
    EVT_SET(LocalVar(10), 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 90)
    EVT_SET(LocalVar(3), 90)
    EVT_SET(LocalVar(4), 91)
    EVT_SET(LocalVar(5), 92)
    EVT_SET(LocalVar(6), 93)
    EVT_SET(LocalVar(10), 0)
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
    EVT_SET(LocalVar(0), 10001)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LocalVar(0), 10002)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LocalVar(0), 10003)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LocalVar(0), 10004)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LocalVar(0), 10005)
    EVT_EXEC(N(80243B1C))
    EVT_CALL(MakeLocalVertexCopy, 0, 123, 1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_ADDR(N(func_80240504_CCB814)), 0)
    EVT_CALL(SetModelCustomGfx, 123, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10001, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10002, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10003, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10004, 1, -1)
    EVT_CALL(SetModelCustomGfx, 10005, 1, -1)
    EVT_CALL(MakeLocalVertexCopy, 1, 57, 1)
    EVT_CALL(SetCustomGfxBuilders, 2, EVT_ADDR(N(func_802407D4_CCBAE4)), 0)
    EVT_CALL(SetModelCustomGfx, 57, 2, -1)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/TexturePan.inc.c"

void fx_sun();

ApiStatus N(func_8024030C_CCB61C)(Evt* script, s32 isInitialCall) {
    fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc43.inc.c"

ApiStatus N(func_802403D4_CCB6E4)(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        script->varTable[14] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = 1;
    evt_set_variable(NULL, MapVar(0), get_npc_unsafe(-4)->flags);
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024042C_CCB73C)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(-4);

    npc->flags = evt_get_variable(NULL, MapVar(0));
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
void N(func_80240504_CCB814)(void) {
    Matrix4f matrix;
    Vtx* sp50;
    Vtx* sp54;
    s32 sp58;

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

    mdl_get_copied_vertices(0, &sp50, &sp54, &sp58);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));

    N(D_80243B14_CCEE24) += 1.0f;
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_14/CCB310", flo_14_func_80240504_CCB814, void);
#endif

void N(func_802407D4_CCBAE4)(void) {
    s32 i;
    Vtx* verts;
    Vtx* copied;
    s32 numCopied;
    f32 openedScale; // controls how open the flower is
    f32 lengthScale; // controls longitudinal pulsing

    mdl_get_copied_vertices(1, &verts, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        Vtx* src = &verts[i];
        Vtx* copy = &copied[i];

        if (src->v.ob[0] <= 600) {
            openedScale = 0.7 + (sin_rad((N(D_80243B18_CCEE28) / 180.0f) * PI_D) * 0.3);
            lengthScale = 0.2 - (sin_rad((N(D_80243B18_CCEE28) / 180.0f) * PI_D) * 0.2);
            copy->v.ob[0] = ((src->v.ob[0] - 616) * openedScale) + 616.0f + (lengthScale * -48.0f);
            copy->v.ob[1] = ((src->v.ob[1] -  44) * openedScale) +  44.0f + (lengthScale *  25.0f);
            copy->v.ob[2] = ((src->v.ob[2] - 113) * openedScale) + 113.0f + (lengthScale * -87.0f);
        }
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(1));

    if (evt_get_variable(NULL, AreaFlag(36)) != 0) {
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
