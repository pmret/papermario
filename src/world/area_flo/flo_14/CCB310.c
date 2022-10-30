#include "flo_14.h"
#include "message_ids.h"
#include "effects.h"

EntryList N(entryList) = {
    {  720.0f, 0.0f, 0.0f, 270.0f },
    { -720.0f, 0.0f, 0.0f,  90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_14 },
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
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
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

EvtScript N(exitWalk_802424FC) = EVT_EXIT_WALK(60,  0, "flo_00",  1);

EvtScript N(exitWalk_80242558) = EVT_EXIT_WALK(60,  1, "flo_13",  0);

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
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, 140)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80242460))
    EVT_END_THREAD
    EVT_EXEC(N(80243E78))
    EVT_EXEC(N(80245224))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 5, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(802425B4)))
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
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, 0xD, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, 0xD, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242EAC) = {
    EVT_SET(LVar9, LVar6)
    EVT_SET(LVar8, LVar5)
    EVT_SET(LVar7, LVar4)
    EVT_SET(LVar6, LVar3)
    EVT_SET(LVar5, LVar2)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar3, LVar0)
    EVT_CALL(EnableModel, LVar6, 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, 1)
    EVT_END_THREAD
    EVT_IF_NE(LVarA, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_ADD(LVar1, 10)
            EVT_ADD(LVar2, 8)
            EVT_CALL(PlayEffect, 0x11, 4, LVar0, LVar1, LVar2, 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_SUB(LVar1, 10)
            EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, LVar3, LVar4, LVar5)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, LVar9, LVar0, 1, 0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_802431CC_CCE4DC) = FALSE;

EvtScript N(802431D0) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(MakeLerp, LVar1, 48, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamTarget, 0, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, 0, LVar0, 48, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802432E8) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
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
    EVT_CALL(LoadPath, 165, EVT_PTR(N(vectorList_80243384)), 13, 10)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(TranslateModel, 123, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, -27)
    EVT_ADD(LVar3, -10)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(N(func_8024046C_CCB77C), LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(StopSound, 0x80000023)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024352C) = {
    EVT_CALL(IsPlayerWithin, 531, 81, 30, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetModelCenter, 123)
    EVT_THREAD
        EVT_ADD(LVar2, -10)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
        EVT_CALL(PlayerJump, 531, 48, LVar2, 10)
        EVT_CALL(SetPlayerActionState, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_ADD(LVar2, -15)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.2))
        EVT_CALL(NpcJump0, NPC_PARTNER, 531, 68, LVar2, 10)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(802431D0), MapVar(9))
    EVT_WAIT(15)
    EVT_CALL(N(func_802403D4_CCB6E4))
    EVT_IF_NE(LVarE, 0)
        EVT_EXEC_GET_TID(N(802432E8), LVarE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80243420))
    EVT_IF_NE(LVarE, 0)
        EVT_KILL_THREAD(LVarE)
        EVT_CALL(N(func_8024042C_CCB73C))
    EVT_END_IF
    EVT_CALL(GetModelCenter, 123)
    EVT_CALL(PlayEffect, 0x43, 0, LVar0, LVar1, LVar2, 2, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAt, 0x2F3, 0, LVar0, LVar1, LVar2)
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
    EVT_SETF(LVar2, EVT_FLOAT(1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_SETF(LVar6, EVT_FLOAT(0.0))
    EVT_SET(LVar7, -30)
    EVT_SET(LVar8, 20)
    EVT_DIVF(LVar7, EVT_FLOAT(90.0))
    EVT_DIVF(LVar8, EVT_FLOAT(90.0))
    EVT_SET(LVar9, 180)
    EVT_LOOP(LVar9)
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_SETF(LVar3, LVar2)
        EVT_DIVF(LVar3, 10)
        EVT_CALL(ScaleModel, 123, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, 123, LVar4, LVar5, LVar6)
        EVT_ADDF(LVar2, EVT_FLOAT(0.05))
        EVT_IF_GT(LVar9, 90)
            EVT_ADDF(LVar4, LVar7)
            EVT_ADDF(LVar5, LVar8)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar7, -30)
    EVT_SET(LVar8, -40)
    EVT_DIVF(LVar7, EVT_FLOAT(60.0))
    EVT_DIVF(LVar8, EVT_FLOAT(60.0))
    EVT_LOOP(60)
        EVT_CALL(TranslateModel, 123, 591, 55, 121)
        EVT_CALL(ScaleModel, 123, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, 123, LVar4, LVar5, LVar6)
        EVT_ADDF(LVar4, LVar7)
        EVT_ADDF(LVar6, LVar8)
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
    EVT_SET(LVarF, LVar0)
    EVT_LABEL(0)
    EVT_IF_EQ(AreaFlag(35), 1)
        EVT_WAIT(10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(D_802431CC_CCE4DC)))
    EVT_BUF_READ1(LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnableModel, LVarF, 1)
    EVT_CALL(RandInt, 4, LVar0)
    EVT_ADDF(LVar0, EVT_FLOAT(4.0))
    EVT_MULF(LVar0, EVT_FLOAT(-1.0))
    EVT_SETF(LVar1, EVT_FLOAT(2.0))
    EVT_SETF(LVar2, LVar0)
    EVT_DIVF(LVar2, EVT_FLOAT(10.0))
    EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_SETF(LVar4, EVT_FLOAT(591.0))
    EVT_SETF(LVar5, EVT_FLOAT(60.0))
    EVT_SETF(LVar6, EVT_FLOAT(121.0))
    EVT_CALL(RandInt, 3, LVar7)
    EVT_ADDF(LVar7, EVT_FLOAT(3.0))
    EVT_MULF(LVar7, EVT_FLOAT(0.04))
    EVT_SETF(LVar9, LVar7)
    EVT_DIVF(LVar9, EVT_FLOAT(5.0))
    EVT_CALL(RandInt, 50, LVar8)
    EVT_ADD(LVar8, 50)
    EVT_LOOP(LVar8)
        EVT_SETF(LVarE, LVar2)
        EVT_SUBF(LVarE, LVar0)
        EVT_MULF(LVarE, EVT_FLOAT(0.046875))
        EVT_ADDF(LVar0, LVarE)
        EVT_SETF(LVarE, LVar3)
        EVT_SUBF(LVarE, LVar1)
        EVT_MULF(LVarE, EVT_FLOAT(0.046875))
        EVT_ADDF(LVar1, LVarE)
        EVT_ADDF(LVar4, LVar0)
        EVT_ADDF(LVar5, LVar1)
        EVT_SETF(LVarE, LVar7)
        EVT_SUBF(LVarE, LVar9)
        EVT_MULF(LVarE, EVT_FLOAT(0.203125))
        EVT_ADDF(LVar9, LVarE)
        EVT_CALL(TranslateModel, LVarF, LVar4, LVar5, LVar6)
        EVT_CALL(ScaleModel, LVarF, LVar9, LVar9, LVar9)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarF, 0)
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
    EVT_SET(LVar0, -730)
    EVT_SET(LVar1, -130)
    EVT_SET(LVar2, -470)
    EVT_SET(LVar3, -70)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LVar0, -730)
    EVT_SET(LVar1, 70)
    EVT_SET(LVar2, -470)
    EVT_SET(LVar3, 140)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LVar0, -280)
    EVT_SET(LVar1, 130)
    EVT_SET(LVar2, -110)
    EVT_SET(LVar3, -70)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242C00))
    EVT_SET(LVar0, -280)
    EVT_SET(LVar1, 70)
    EVT_SET(LVar2, -10)
    EVT_SET(LVar3, 140)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242C00))
    EVT_CALL(GetModelCenter, 96)
    EVT_SET(LVar3, 96)
    EVT_SET(LVar4, 97)
    EVT_SET(LVar5, 98)
    EVT_SET(LVar6, 99)
    EVT_SET(LVarA, 174)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 82)
    EVT_SET(LVar3, 82)
    EVT_SET(LVar4, 83)
    EVT_SET(LVar5, 84)
    EVT_SET(LVar6, 85)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 76)
    EVT_SET(LVar3, 76)
    EVT_SET(LVar4, 77)
    EVT_SET(LVar5, 78)
    EVT_SET(LVar6, 79)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(GetModelCenter, 90)
    EVT_SET(LVar3, 90)
    EVT_SET(LVar4, 91)
    EVT_SET(LVar5, 92)
    EVT_SET(LVar6, 93)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80242EAC))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 15, 0x7FFFFE00)
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
    EVT_SET(LVar0, 10001)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LVar0, 10002)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LVar0, 10003)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LVar0, 10004)
    EVT_EXEC(N(80243B1C))
    EVT_SET(LVar0, 10005)
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

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus N(func_8024030C_CCB61C)(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc43.inc.c"

ApiStatus N(func_802403D4_CCB6E4)(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        script->varTable[14] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = 1;
    evt_set_variable(NULL, MapVar(0), get_npc_unsafe(NPC_PARTNER)->flags);
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024042C_CCB73C)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_PARTNER);

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

void N(func_80240504_CCB814)(void) {
    Matrix4f matrix;
    Vtx* sp50;
    Vtx* sp54;
    s32 sp58;
    s32 new_var;

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

    new_var = 0;
    while (new_var); // TODO required to match

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));

    N(D_80243B14_CCEE24) += 1.0f;
}

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
            N(D_802431CC_CCE4DC) = TRUE;
        } else {
            N(D_802431CC_CCE4DC) = FALSE;
        }
        N(D_80243B18_CCEE28) += 5;
    }

    if (N(D_80243B18_CCEE28) >= 360) {
        N(D_80243B18_CCEE28) -= 360;
    }
}
