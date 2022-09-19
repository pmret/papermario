#include "flo_11.h"
#include "message_ids.h"
#include "sprite/npc/lakitu.h"
#include "entity.h"

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

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_11 },
};

EvtScript N(802403E0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80240450) = {
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

#include "world/common/atomic/PipeData.inc.c"

EvtScript N(exitWalk_8024142C) = EXIT_WALK_SCRIPT(60,  0, "flo_23",  1);

EvtScript N(exitWalk_80241488) = EXIT_WALK_SCRIPT(60,  1, "flo_12",  0);

EvtScript N(802414E4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241520) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024155C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 7)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241598) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802415D4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241610) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("flo_11"), 4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024164C) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_EXEC_WAIT(N(Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(80241698) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241488), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024142C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, 35)
    EVT_SET(LVar2, EVT_PTR(N(802414E4)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, 3)
    EVT_SET(LVar1, 34)
    EVT_SET(LVar2, EVT_PTR(N(80241520)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar1, 33)
    EVT_SET(LVar2, EVT_PTR(N(8024155C)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, 5)
    EVT_SET(LVar1, 32)
    EVT_SET(LVar2, EVT_PTR(N(80241598)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, 6)
    EVT_SET(LVar1, 31)
    EVT_SET(LVar2, EVT_PTR(N(802415D4)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_SET(LVar0, 7)
    EVT_SET(LVar1, 30)
    EVT_SET(LVar2, EVT_PTR(N(80241610)))
    EVT_BIND_TRIGGER(N(8024164C), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
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
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LE(LVar0, 1)
        EVT_SET(LVar0, EVT_PTR(N(80241698)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(80242240))
        EVT_WAIT(1)
    EVT_ELSE
        EVT_SET(LVarA, EVT_PTR(N(80241698)))
        EVT_EXEC(N(Pipe_EnterVertical))
        EVT_WAIT(1)
    EVT_END_IF
    EVT_EXEC_WAIT(N(802403E0))
    EVT_IF_GE(GB_StoryProgress, 53)
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
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
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

EvtScript N(80241CB4) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySound, SOUND_295)
        EVT_WAIT(LVar0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80241CF4) = {
    EVT_SET(LVar0, 5)
    EVT_EXEC_GET_TID(N(80241CB4), MapVar(11))
    EVT_THREAD
        EVT_CALL(LoadPath, 160, EVT_PTR(N(vectorList_80241AEC)), 8, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 160, EVT_PTR(N(vectorList_80241B4C)), 8, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MapVar(10), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E4C) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 30, EVT_PTR(N(vectorList_80241BAC)), 4, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 45, EVT_PTR(N(vectorList_80241BDC)), 4, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(MapVar(11))
    EVT_RETURN
    EVT_END
};

EvtScript N(80241F80) = {
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(80241CB4), MapVar(11))
    EVT_THREAD
        EVT_CALL(LoadPath, 35, EVT_PTR(N(vectorList_80241C0C)), 3, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 35, EVT_PTR(N(vectorList_80241C30)), 3, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802420C8) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 40, EVT_PTR(N(vectorList_80241C54)), 4, 0)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 40, EVT_PTR(N(vectorList_80241C84)), 4, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_WAIT(40)
    EVT_KILL_THREAD(MapVar(11))
    EVT_RETURN
    EVT_END
};

EvtScript N(80242240) = {
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, 45)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, 0, 460, 200, -240)
    EVT_CALL(SetNpcPos, 1, -100, 200, -50)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 440)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(MapVar(10), 0)
    EVT_EXEC(N(80241CF4))
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(25.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_SET(LVar0, 270)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar2, -87)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, 0, 87, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(SetCamPosC, 0, 87, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_CALL(SetCamDistance, 0, 150)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-16.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MapVar(10), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFaceNpc, 0, 1, 1)
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_EXEC(N(80241E4C))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim1, 0, MSG_CH6_0088)
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim1, 0, MSG_CH6_0089)
    EVT_CALL(InterpNpcYaw, 0, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim1, 0, MSG_CH6_008A)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim1, 0, MSG_CH6_008B)
    EVT_CALL(SetCamType, 0, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(SetCamPosA, 0, 87, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_EXEC(N(80241F80))
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80242810) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(AdjustCam, 0, EVT_FLOAT(4.0), 0, 1000, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_802428B8) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetNpcPos, 0, 400, 20, -40)
            EVT_CALL(SetNpcPos, 1, 400, 20, 40)
            EVT_CALL(InterpNpcYaw, 0, 270, 0)
            EVT_CALL(InterpNpcYaw, 1, 270, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, -60)
            EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, 0, 900)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(24.0), EVT_FLOAT(-4.0))
            EVT_CALL(SetCamPosA, 0, EVT_FLOAT(-95.0), EVT_FLOAT(0.0))
            EVT_CALL(SetCamPosB, 0, EVT_FLOAT(0.0), EVT_FLOAT(-50.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_EXEC_WAIT(N(802420C8))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
            EVT_SET(GF_FLO11_Defeated_Lakitus, 1)
            EVT_SET(MapVar(0), 1)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80242AC4) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_LABEL(0)
            EVT_IF_EQ(MapVar(0), 0)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80242B58) = {
    EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, 0)
        EVT_IF_GE(GB_StoryProgress, 45)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 1)
                EVT_SET(MapVar(0), 0)
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

EvtScript N(init_80242C38) = {
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, 0)
        EVT_IF_GE(GB_StoryProgress, 45)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 1)
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(init_80242B58),
        .yaw = 270,
        .drops = {
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
        },
	.animations = {
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim2,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim4,
            ANIM_Lakitu_Anim4,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
        },
    },
    {
        .id = NPC_LAKITU1,
        .settings = &N(npcSettings_80241AC0),
        .pos = { 553.0f, 60.0f, 52.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(init_80242C38),
        .yaw = 270,
        .drops = {
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
        },
	.animations = {
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim2,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim4,
            ANIM_Lakitu_Anim4,
            ANIM_Lakitu_Anim3,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
            ANIM_Lakitu_Anim1,
        },
    },
};

NpcGroupList N(npcGroupList_802430D4) = {
    NPC_GROUP(N(npcGroup_80242CF4), 0x1807, 0x08),
    {},
};

static s32 N(pad_30EC) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -220, 60, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO11_MultiCoinBrick)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/Pipe.inc.c"

void fx_sun();

ApiStatus N(func_802402E0_CBDFB0)(Evt* script, s32 isInitialCall) {
    fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
