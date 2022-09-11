#include "flo_21.h"
#include "message_ids.h"
#include "sprite/npc/huff_n_puff.h"
#include "sprite/npc/tuff_puff.h"

enum {
    NPC_HUFF_N_PUFF0,
    NPC_HUFF_N_PUFF1,
    NPC_HUFF_N_PUFF2,
    NPC_TUFF_PUFF0,
    NPC_TUFF_PUFF1,
    NPC_TUFF_PUFF2,
    NPC_TUFF_PUFF3,
    NPC_TUFF_PUFF4,
    NPC_TUFF_PUFF5,
    NPC_TUFF_PUFF6,
    NPC_TUFF_PUFF7,
    NPC_TUFF_PUFF8,
    NPC_TUFF_PUFF9,
    NPC_TUFF_PUFF10,
    NPC_TUFF_PUFF11,
    NPC_TUFF_PUFF12,
    NPC_TUFF_PUFF13,
    NPC_TUFF_PUFF14,
};

EntryList N(entryList) = {
    { -800.0f, -46.0f, 0.0f, 90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_21 },
};

EvtScript N(80240D40) = {
    EVT_IF_EQ(GB_StoryProgress, 56)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/StarSpiritEffectFunc.inc.c"

EvtScript N(80240DA0) = {
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

EvtScript N(80240E3C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(55)
            EVT_SET(LVar0, 0)
            EVT_IF_EQ(MapVar(10), 0)
                EVT_RETURN
            EVT_END_IF
            EVT_SET(GB_StoryProgress, 56)
        EVT_CASE_EQ(56)
            EVT_SET(LVar0, 1)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, 0, 650, 205, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, 0, 650, 150, 0)
        EVT_CALL(GetCamDistance, 0, LVar1)
        EVT_SUB(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_IF_NE(EVT_FLOAT(-5.5), 10000)
            EVT_CALL(GetCamPitch, 0, LVar2, LVar3)
            EVT_CALL(SetCamPitch, 0, LVar2, EVT_FLOAT(-5.5))
        EVT_END_IF
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 5, 180, 650, 170, 0, 650, 205, 0, 150, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, 0x80000067)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, 0x80000067)
            EVT_CALL(PlaySoundAt, 0xB2, 0, 650, 205, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, 65578)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, 0x137, 0, 650, 205, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_CALL(SetPanTarget, 0, 650, 120, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, 0, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, 0, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, 0, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 5, 650, 150, 0, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, 312, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, 57)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), 5, 14)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_802412F4) = EXIT_WALK_SCRIPT(60,  0, "flo_19",  1);

EvtScript N(80241350) = {
    EVT_BIND_TRIGGER(N(exitWalk_802412F4), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 39)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80245AEC)))
    EVT_EXEC(N(80241B98))
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(80241600))
    EVT_CALL(ModifyColliderFlags, 3, 5, 0x00000007)
    EVT_CALL(ModifyColliderFlags, 3, 7, 0x00000007)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(80241350)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80240D40))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240B00_CE7200))
    EVT_END_IF
    EVT_EXEC(N(80240E3C))
    EVT_RETURN
    EVT_END
};

s32 N(D_802414FC_CE7BFC)[] = {
    0,
    EVT_FLOAT(1), EVT_FLOAT(1), EVT_FLOAT(1),
    EVT_FLOAT(1), EVT_FLOAT(1), EVT_FLOAT(1),
    EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.1),
    EVT_FLOAT(1.1), EVT_FLOAT(1.1), EVT_FLOAT(1.1),
    EVT_FLOAT(1), EVT_FLOAT(1), EVT_FLOAT(1),
    EVT_FLOAT(1), EVT_FLOAT(1), EVT_FLOAT(1),
    EVT_FLOAT(0.9), EVT_FLOAT(0.9), EVT_FLOAT(0.9),
    EVT_FLOAT(0.9), EVT_FLOAT(0.9), EVT_FLOAT(0.9),
};

EvtScript N(80241560) = {
    EVT_ADDF(MapVar(0), EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(80241580) = {
    EVT_ADDF(MapVar(1), EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(802415A0) = {
    EVT_ADDF(MapVar(2), EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(802415C0) = {
    EVT_ADDF(MapVar(3), EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(802415E0) = {
    EVT_ADDF(MapVar(4), EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(80241600) = {
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(0)
        EVT_CALL(N(UnkFloatFunc), LVarF, LVar0, EVT_FLOAT(0.96875), EVT_FLOAT(1.03125), 15, 0, 0)
        EVT_CALL(N(UnkFloatFunc), LVarF, LVar1, EVT_FLOAT(1.03125), EVT_FLOAT(0.96875), 15, 0, 0)
        EVT_CALL(ScaleModel, 88, LVar1, LVar0, 1)
        EVT_CALL(ScaleModel, 90, LVar1, LVar0, 1)
        EVT_CALL(ScaleModel, 92, LVar0, LVar1, 1)
        EVT_CALL(ScaleModel, 94, LVar0, LVar1, 1)
        EVT_CALL(ScaleModel, 96, LVar0, LVar1, 1)
        EVT_CALL(ScaleModel, 98, LVar1, LVar0, 1)
        EVT_CALL(ScaleModel, 100, LVar0, LVar1, 1)
        EVT_CALL(ScaleModel, 102, LVar0, LVar1, 1)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

static s32 N(pad_17BC) = {
    0x00000000,
};

NpcSettings N(npcSettings_802417C0) = {
    .height = 24,
    .radius = 28,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 16,
};

NpcSettings N(npcSettings_802417EC) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80241818) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80241844) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80241870) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

Vec3f N(vectorList_8024189C)[] = {
    { 600.0, 104.0, 0.0 }, { 575.0, 204.0, 0.0 },
    { 550.0, 104.0, 0.0 },
};

EvtScript N(802418C0) = {
    EVT_LABEL(0)
    EVT_CALL(PlaySound, 0x20B6)
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241920) = {
    EVT_CALL(PlaySoundAtNpc, 0, 0x3C0, 0)
    EVT_CALL(PlayEffect, 0x25, 3, 650, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(SetNpcJumpscale, 1, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, 1, 650, 50, 0, 5)
    EVT_CALL(SetNpcPos, 0, 650, 50, 5)
    EVT_CALL(SetNpcPos, 1, 650, 50, 0)
    EVT_CALL(SetNpcPos, 2, 650, 50, 0)
    EVT_CALL(SetNpcJumpscale, 0, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, 1, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, 2, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_CALL(NpcJump0, 0, 650, 150, 5, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcJump0, 1, 650, 150, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcJump0, 2, 650, 150, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
        EVT_CALL(LoadPath, 30, EVT_PTR(N(vectorList_8024189C)), 3, 0)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241B98) = {
    EVT_IF_GE(GB_StoryProgress, 56)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 650, 0, 30)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_HUFF_N_PUFF_THEME, 0, 8)
    EVT_EXEC_GET_TID(N(802418C0), LVar9)
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(UseSettingsFrom, 0, LVar2, LVar3, LVar4)
    EVT_CALL(SetPanTarget, 0, LVar2, LVar3, LVar4)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(MakeLerp, LVar2, 600, 20, 0)
    EVT_SET(LVar2, LVar3)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 15)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar3, LVar4)
        EVT_IF_GT(LVar3, LVar5)
            EVT_SET(LVar3, LVar2)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetPanTarget, 0, LVar0, LVar2, LVar4)
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetPlayerPos, LVar0, LVar2, LVar4)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 25)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID_1100CA, 630, 120, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(30.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID_1100CB, 630, 120, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(func_802D2C14, 0)
    EVT_WAIT(10)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 8)
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID_1100CC, 630, 120, 0)
    EVT_ELSE
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID_1100CD, 630, 120, 0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(15)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 25)
        EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_SET(LVar3, 40)
        EVT_LOOP(5)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, 0, EVT_FLOAT(400.0))
            EVT_CALL(SetCamSpeed, 0, LVar3)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_SUB(LVar3, 10)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, 0, EVT_FLOAT(600.0))
            EVT_CALL(SetCamSpeed, 0, LVar3)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_ADD(LVar3, 7)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_EXEC_WAIT(N(80241920))
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(30)
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242290) = {
    EVT_SETF(LVar0, EVT_FLOAT(0.95))
    EVT_SETF(LVar1, EVT_FLOAT(1.1))
    EVT_LABEL(0)
    EVT_SWITCH(MapVar(13))
        EVT_CASE_EQ(0)
            EVT_SET(LVar3, 10)
            EVT_SET(LVar2, 2)
        EVT_CASE_EQ(1)
            EVT_SET(LVar3, 5)
            EVT_SET(LVar2, 1)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(LVar4, LVar3)
    EVT_LOOP(LVar4)
        EVT_CALL(SetNpcScale, 0, LVar0, LVar1, 1)
        EVT_CALL(SetNpcScale, 1, LVar0, LVar1, 1)
        EVT_CALL(SetNpcScale, 2, LVar0, LVar1, 1)
        EVT_ADDF(LVar0, EVT_FLOAT(0.015625))
        EVT_SUBF(LVar1, EVT_FLOAT(0.01))
        EVT_WAIT(LVar2)
    EVT_END_LOOP
    EVT_SET(LVar4, LVar3)
    EVT_LOOP(LVar4)
        EVT_CALL(SetNpcScale, 0, LVar0, LVar1, 1)
        EVT_CALL(SetNpcScale, 1, LVar0, LVar1, 1)
        EVT_CALL(SetNpcScale, 2, LVar0, LVar1, 1)
        EVT_SUBF(LVar0, EVT_FLOAT(0.015625))
        EVT_ADDF(LVar1, EVT_FLOAT(0.01))
        EVT_WAIT(LVar2)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8024249C)[] = {
    0x0000027B, 0x000000A5, 0x000001C2, 0x00000078, 0x00000280, 0x000000AA, 0x00000208, 0x0000010E,
    0x0000028A, 0x000000AF, 0x0000028A, 0x00000113, 0x00000294, 0x000000AA, 0x000002DA, 0x00000113,
    0x00000299, 0x000000A5, 0x00000352, 0x00000078, 0x00000276, 0x00000096, 0x000001C2, 0x0000009B,
    0x0000027D, 0x00000096, 0x00000258, 0x00000113, 0x0000028A, 0x00000096, 0x00000352, 0x0000009B,
    0x00000297, 0x00000096, 0x000002EE, 0x0000010E, 0x0000029E, 0x00000096, 0x00000352, 0x000000C3,
    0x0000027B, 0x00000087, 0x000001C2, 0x000000C3, 0x00000280, 0x00000082, 0x000001C2, 0x000000EB,
    0x0000028A, 0x0000007D, 0x000001C2, 0x0000010E, 0x00000294, 0x00000082, 0x00000352, 0x0000010E,
    0x00000299, 0x00000087, 0x00000352, 0x000000EB,
};

s32 N(intTable_8024258C)[] = {
    0x0000000A, 0x0000000E, 0x00000007, 0x0000000E, 0x00000005, 0x00000006, 0x00000005, 0x0000000C,
    0x00000006, 0x0000000C, 0x00000005, 0x00000005, 0x00000005, 0x0000000A, 0x00000005, 0x0000000A,
    0x00000005, 0x00000004,
};

s32 N(intTable_802425D4)[] = {
    0x00000008, 0x0000000A, 0x0000000A, 0x00000008,
};

s32 N(intTable_802425E4)[] = {
    0x0000000A, 0x00000005, 0x00000007, 0x00000005, 0x0000000E, 0x00000006, 0x0000000E, 0x00000005,
    0x00000006, 0x00000005, 0x0000000C, 0x00000005, 0x0000000C, 0x00000005, 0x00000005, 0x00000005,
    0x0000000A, 0x00000004,
};

s32 N(intTable_8024262C)[] = {
    0x0000000A, 0x00000006, 0x00000006, 0x0000000A,
};

EvtScript N(8024263C) = {
    EVT_SETF(LVar0, 10)
    EVT_SETF(LVar1, 1)
    EVT_CHILD_THREAD
        EVT_LOOP(8)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), FALSE)
            EVT_WAIT(LVar0)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), TRUE)
            EVT_WAIT(LVar1)
            EVT_SUBF(LVar0, 0)
            EVT_ADDF(LVar1, 0)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), FALSE)
            EVT_WAIT(LVar0)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), TRUE)
            EVT_WAIT(LVar1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 0, 255, 10, 4)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 0, 9, LVar0, LVar0, LVar0, 0)
                EVT_CALL(func_802CFD30, 1, 9, LVar0, LVar0, LVar0, 0)
                EVT_CALL(func_802CFD30, 2, 9, LVar0, LVar0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242918) = {
    EVT_SETF(MapVar(11), EVT_FLOAT(1.0))
    EVT_SETF(MapVar(12), EVT_FLOAT(1.0))
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(intTable_8024258C)))
        EVT_LOOP(6)
            EVT_CALL(PlaySoundAtNpc, 0, 0x20B6, 0)
            EVT_BUF_READ3(LVar6, LVar7, LVar8)
            EVT_CALL(MakeLerp, LVar6, LVar7, LVar8, 11)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(LVar0, 10)
                EVT_SETF(MapVar(11), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(intTable_802425D4)))
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtNpc, 0, 0x20B6, 0)
                EVT_BUF_READ2(LVar6, LVar7)
                EVT_CALL(MakeLerp, LVar6, LVar7, 4, 11)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(LVar0, 10)
                    EVT_SETF(MapVar(11), LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(intTable_802425E4)))
        EVT_LOOP(6)
            EVT_BUF_READ3(LVar6, LVar7, LVar8)
            EVT_CALL(MakeLerp, LVar6, LVar7, LVar8, 11)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(LVar0, 10)
                EVT_SETF(MapVar(12), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(intTable_8024262C)))
            EVT_LOOP(2)
                EVT_BUF_READ2(LVar6, LVar7)
                EVT_CALL(MakeLerp, LVar6, LVar7, 4, 11)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(LVar0, 10)
                    EVT_SETF(MapVar(12), LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(100)
        EVT_CALL(SetNpcScale, 0, MapVar(11), MapVar(12), 1)
        EVT_CALL(SetNpcScale, 1, MapVar(11), MapVar(12), 1)
        EVT_CALL(SetNpcScale, 2, MapVar(11), MapVar(12), 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80242D34) = {
    EVT_CHILD_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_SET(LVar0, 3)
            EVT_LOOP(15)
                EVT_CALL(SetNpcRotation, LVar0, 0, LVar1, 0)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_ADD(LVar1, 60)
            EVT_IF_GT(LVar1, 360)
                EVT_ADD(LVar1, -360)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_USE_BUF(EVT_PTR(N(intTable_8024249C)))
    EVT_SET(LVar8, 3)
    EVT_LOOP(14)
        EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
        EVT_THREAD
            EVT_CALL(RandInt, 5, LVar5)
            EVT_WAIT(LVar5)
            EVT_CALL(SetNpcPos, LVar8, LVar1, LVar2, -30)
            EVT_CALL(RandInt, 2, LVar5)
            EVT_ADD(LVar5, 8)
            EVT_CALL(PlaySoundAtNpc, LVar8, 0x3D5, 0)
            EVT_CALL(NpcJump0, LVar8, LVar3, LVar4, -15, LVar5)
            EVT_CALL(SetNpcPos, LVar8, 0, -1000, 0)
        EVT_END_THREAD
        EVT_ADD(LVar8, 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_WAIT(5)
    EVT_CALL(SetNpcPos, LVar8, LVar1, LVar2, -30)
    EVT_CALL(PlaySoundAtNpc, LVar8, 0x3D6, 0)
    EVT_CALL(NpcJump0, LVar8, LVar3, LVar4, -15, 10)
    EVT_CALL(SetNpcPos, LVar8, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243010) = {
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_huff_n_puff_Palette_00_Anim_4)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_huff_n_puff_Palette_00_Anim_5)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_huff_n_puff_Palette_00_Anim_6)
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -15)
    EVT_ADD(LVar2, 40)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_huff_n_puff_Palette_00_Anim_30, NPC_ANIM_huff_n_puff_Palette_00_Anim_5, 256, -30, 30, MESSAGE_ID_1100CE)
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_SET(MapVar(13), 2)
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar3, LVar0)
        EVT_SET(LVar4, LVar0)
        EVT_ADD(LVar3, -35)
        EVT_ADD(LVar4, 35)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x19, 0, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(12)
            EVT_CALL(PlayEffect, 0x19, 0, LVar3, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_ADD(LVar3, 7)
            EVT_WAIT(8)
            EVT_CALL(PlayEffect, 0x19, 0, LVar4, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_ADD(LVar4, -7)
            EVT_WAIT(14)
        EVT_END_LOOP
        EVT_CALL(PlayEffect, 0x19, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ShakeCam, 0, 0, 30, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_LOOP(10)
            EVT_CALL(PlayEffect, 0x3A, 0, LVar0, LVar1, LVar2, 40, 65, 12, 15, 0, 0, 0, 0, 0)
            EVT_WAIT(7)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(8024263C))
    EVT_EXEC_WAIT(N(80242918))
    EVT_EXEC_WAIT(N(80242D34))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80243428) = {
    EVT_LABEL(0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MapVar(13), 1)
    EVT_CALL(StartBossBattle, 14)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_802434D8) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetEncounterStatusFlags, 1, 1)
            EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar3)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar3, -20)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar3)
            EVT_EXEC_WAIT(N(80243010))
            EVT_WAIT(50)
            EVT_SET(MapVar(10), 1)
            EVT_EXEC(N(80240E3C))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_802435D4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802435E4) = {
    EVT_IF_LT(GB_StoryProgress, 56)
        EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80243428)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802434D8)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_huff_n_puff_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243684) = {
    EVT_IF_LT(GB_StoryProgress, 56)
        EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802435D4)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_huff_n_puff_Palette_00_Anim_1)
        EVT_EXEC(N(80242290))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024371C) = {
    EVT_IF_LT(GB_StoryProgress, 56)
        EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802435D4)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_huff_n_puff_Palette_00_Anim_19)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802437A8) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tuff_puff_Palette_00_Anim_B)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_802437E0)[] = {
    NPC_ANIM_huff_n_puff_Palette_00_Anim_0,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_2,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_4,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_5,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_31,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_19,
    NPC_ANIM_huff_n_puff_Palette_00_Anim_2D,
    ANIM_LIST_END,
};

StaticNpc N(npcGroup_80243804)[] = {
    {
        .id = NPC_HUFF_N_PUFF0,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(init_802435E4),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
    {
        .id = NPC_HUFF_N_PUFF1,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, 100.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(init_80243684),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
    {
        .id = NPC_HUFF_N_PUFF2,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(init_8024371C),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
            NPC_ANIM_huff_n_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
};

s32 N(extraAnimationList_80243DD4)[] = {
    NPC_ANIM_tuff_puff_Palette_00_Anim_B,
    ANIM_LIST_END,
};

StaticNpc N(npcGroup_80243DDC)[] = {
    {
        .id = NPC_TUFF_PUFF0,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF1,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF2,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF3,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF4,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF5,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF6,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF7,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF8,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF9,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF10,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF11,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF12,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF13,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF14,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_802437A8),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_0,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_6,
            NPC_ANIM_tuff_puff_Palette_00_Anim_5,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
            NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
};

NpcGroupList N(npcGroupList_80245AEC) = {
    NPC_GROUP(N(npcGroup_80243804), 0x1900, 0x07),
    NPC_GROUP(N(npcGroup_80243DDC), 0x181F, 0x07),
    {},
};

#include "world/common/atomic/TexturePan.inc.c"

EffectInstance* fx_sun();

ApiStatus N(func_80240B00_CE7200)(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
