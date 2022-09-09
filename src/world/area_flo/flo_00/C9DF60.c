#include "flo_00.h"
#include "script_api/common.h"
#include "message_ids.h"
#include "effects.h"
#include "entity.h"
#include "sprite/npc/bubulb.h"
#include "sprite/npc/lakilulu.h"
#include "sprite/npc/tolielup.h"
#include "sprite/npc/world_klevar.h"
#include "sprite/npc/world_lakilester.h"
#include "sprite/npc/world_parakarry.h"


enum {
    NPC_BUBULB0,
    NPC_BUBULB1,
    NPC_BUBULB2,
    NPC_BUBULB3,
    NPC_BUBULB4,
    NPC_TOLIELUP,
    NPC_WORLD_KLEVAR,
    NPC_LAKILULU,
};

EntryList N(entryList) = {
    {    0.0f, 0.0f, -310.0f, 170.0f },
    { -320.0f, 0.0f, -335.0f, 135.0f },
    { -470.0f, 0.0f,    0.0f,  90.0f },
    { -320.0f, 0.0f,  335.0f,  45.0f },
    {  320.0f, 0.0f, -335.0f, 225.0f },
    {  465.0f, 0.0f,    0.0f, 270.0f },
    {  320.0f, 0.0f,  335.0f, 315.0f },
    {  -30.0f, 0.0f,  120.0f, 270.0f },
    {  -30.0f, 0.0f,  120.0f, 270.0f },
    { -470.0f, 0.0f,    0.0f,  90.0f },
    {   40.0f, 0.0f,  -30.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_00_tattle },
};

EvtScript N(802414D0) = {
    EVT_CALL(GetEntryID, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(8)
            EVT_IF_NE(AreaFlag(44), 0)
                EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_IF
        EVT_CASE_EQ(9)
            EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
        EVT_CASE_EQ(10)
            EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_WAIT(1)
                    EVT_IF_GE(GameByte(0), 59)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_THREAD
        EVT_CASE_EQ(11)
            EVT_CALL(FadeInMusic, 0, 49, 0, 3000, 0, 127)
        EVT_CASE_DEFAULT
            EVT_SWITCH(GameByte(0))
                EVT_CASE_LT(53)
                    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_16BC) = {
    0x00000000,
};

EvtScript N(802416C0) = {
    EVT_SET_GROUP(11)
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(12), LW(2))
    EVT_SET(LW(13), LW(3))
    EVT_SET(LW(14), LW(4))
    EVT_SUB(LW(12), LW(0))
    EVT_SUB(LW(13), LW(1))
    EVT_SETF(LW(0), LW(12))
    EVT_DIVF(LW(0), EVT_FLOAT(100.0))
    EVT_SETF(LW(15), EVT_FLOAT(100.0))
    EVT_DIVF(LW(15), LW(0))
    EVT_ADD(LW(15), 11)
    EVT_SET(LW(5), 200)
    EVT_DIV(LW(5), LW(15))
    EVT_ADD(LW(5), 1)
    EVT_LOOP(LW(5))
        EVT_CALL(RandInt, LW(12), LW(0))
        EVT_CALL(RandInt, LW(13), LW(1))
        EVT_CALL(RandInt, 199, LW(2))
        EVT_SET(LW(3), 210)
        EVT_SUB(LW(3), LW(2))
        EVT_ADD(LW(0), LW(10))
        EVT_ADD(LW(1), LW(11))
        EVT_ADD(LW(2), LW(14))
        EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LW(0), LW(2), LW(1), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LW(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, LW(12), LW(0))
    EVT_CALL(RandInt, LW(13), LW(1))
    EVT_ADD(LW(0), LW(10))
    EVT_ADD(LW(1), LW(11))
    EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LW(0), LW(14), LW(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LW(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024196C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, 2, 0x7FFFFE00)
    EVT_CALL(PlayerMoveTo, 30, -170, 10)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(PlaySoundAtCollider, 2, 463, 0)
    EVT_CALL(MakeLerp, 0, -100, 20, 4)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, 28, LW(0), 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 0, -310, 30)
    EVT_CALL(func_802D2C14, 0)
    EVT_IF_EQ(GameByte(0), 59)
        EVT_SET(GameByte(0), 60)
    EVT_END_IF
    EVT_CALL(MakeLerp, -100, 0, 30, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, 28, LW(0), 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, 2, 464, 0)
    EVT_CALL(GotoMap, EVT_PTR("mac_01"), 5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241B90) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, 2, 0x7FFFFE00)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(PlaySoundAtCollider, 2, 463, 0)
    EVT_CALL(MakeLerp, 0, -100, 30, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, 28, LW(0), 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 0, -135, 30)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(MakeLerp, -100, 0, 30, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, 28, LW(0), 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, 2, 464, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(ModifyColliderFlags, 1, 2, 0x7FFFFE00)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80241D7C) = EXIT_WALK_SCRIPT(60,  1, "flo_14",  0);

EvtScript N(exitWalk_80241DD8) = EXIT_WALK_SCRIPT(60,  2, "flo_23",  0);

EvtScript N(exitWalk_80241E34) = EXIT_WALK_SCRIPT(60,  3, "flo_25",  0);

EvtScript N(exitWalk_80241E90) = EXIT_WALK_SCRIPT(60,  4, "flo_16",  0);

EvtScript N(exitWalk_80241EEC) = EXIT_WALK_SCRIPT(60,  5, "flo_09",  0);

EvtScript N(exitWalk_80241F48) = EXIT_WALK_SCRIPT(60,  6, "flo_08",  0);

const s32 N(pad_XXXX)[] = { 0, 0};

EvtScript N(80241FA4) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241D7C), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241DD8), TRIGGER_FLOOR_ABOVE, 9, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241E34), TRIGGER_FLOOR_ABOVE, 13, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241E90), TRIGGER_FLOOR_ABOVE, 17, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241EEC), TRIGGER_FLOOR_ABOVE, 21, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241F48), TRIGGER_FLOOR_ABOVE, 25, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_8024205C) = {
    EVT_CALL(GetLoadType, LW(1))
    EVT_IF_EQ(LW(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(80241FA4))
    EVT_ELSE
        EVT_CALL(GetEntryID, LW(0))
        EVT_IF_NE(LW(0), 8)
            EVT_SET(AreaFlag(44), 0)
        EVT_END_IF
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(0)
                EVT_THREAD
                    EVT_EXEC_WAIT(N(80241B90))
                    EVT_EXEC(N(80241FA4))
                EVT_END_THREAD
            EVT_CASE_RANGE(1, 6)
                EVT_SET(LW(0), EVT_ADDR(N(80241FA4)))
                EVT_EXEC(EnterWalk)
            EVT_CASE_EQ(7)
                EVT_THREAD
                    EVT_EXEC_WAIT(flo_00_8024834C)
                    EVT_EXEC(N(80241FA4))
                EVT_END_THREAD
            EVT_CASE_EQ(8)
                EVT_THREAD
                    EVT_EXEC_WAIT(flo_00_80247BCC)
                    EVT_EXEC(N(80241FA4))
                EVT_END_THREAD
            EVT_CASE_EQ(9)
                EVT_EXEC(flo_00_80242998)
                EVT_SET(LW(0), EVT_ADDR(N(80241FA4)))
                EVT_EXEC(EnterWalk)
            EVT_CASE_EQ(10)
                EVT_EXEC(N(80241FA4))
            EVT_CASE_EQ(11)
                EVT_EXEC(flo_00_80245EB8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_BIND_TRIGGER(flo_00_80242FCC, TRIGGER_WALL_PRESS_A, 2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GameByte(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(GameFlag(1984), 1)
    EVT_IF_LT(GameByte(0), 55)
        EVT_CALL(ModifyColliderFlags, 0, 48, 0x7FFFFE00)
    EVT_END_IF
    EVT_SET(GameFlag(263), 0)
    EVT_CALL(GetEntryID, LW(0))
    EVT_IF_EQ(LW(0), 11)
        EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_80246834)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_80245DE4)))
    EVT_END_IF
    EVT_EXEC_WAIT(flo_00_makeEntities)
    EVT_CALL(ParentColliderToModel, 46, 81)
    EVT_EXEC(flo_00_80248F48)
    EVT_EXEC(flo_00_80248E30)
    EVT_CALL(ModifyColliderFlags, 3, 30, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 31, 0x00000006)
    EVT_SET(LW(0), 150)
    EVT_SET(LW(1), -270)
    EVT_SET(LW(2), 410)
    EVT_SET(LW(3), 170)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(802416C0))
    EVT_SET(LW(0), 115)
    EVT_SET(LW(1), -450)
    EVT_SET(LW(2), 250)
    EVT_SET(LW(3), -270)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(802416C0))
    EVT_SET(LW(0), -330)
    EVT_SET(LW(1), 220)
    EVT_SET(LW(2), 45)
    EVT_SET(LW(3), 410)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(802416C0))
    EVT_SET(LW(0), -420)
    EVT_SET(LW(1), -260)
    EVT_SET(LW(2), -140)
    EVT_SET(LW(3), 160)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(802416C0))
    EVT_CALL(ModifyColliderFlags, 0, 26, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 6, 0x7FFFFE00)
    EVT_EXEC(N(enterWalk_8024205C))
    EVT_CALL(GetLoadType, LW(1))
    EVT_IF_NE(LW(1), 1)
        EVT_CALL(GetEntryID, LW(0))
        EVT_IF_EQ(LW(0), 10)
            EVT_WAIT(65)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(802414D0))
    EVT_IF_GE(GameByte(0), STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(func_80240000_C9DF20))
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(EnableTexPanning, 35, 1)
        EVT_SET(LW(0), 0)
        EVT_LABEL(0)
        EVT_CALL(RandInt, 300, LW(1))
        EVT_ADD(LW(1), 100)
        EVT_CALL(RandInt, 1, LW(2))
        EVT_ADD(LW(2), 1)
        EVT_WAIT(LW(1))
        EVT_LOOP(LW(2))
            EVT_CALL(SetTexPanOffset, 12, 0, -32768, 0)
            EVT_WAIT(2)
            EVT_CALL(SetTexPanOffset, 12, 0, -65536, 0)
            EVT_WAIT(2)
            EVT_CALL(SetTexPanOffset, 12, 0, -98304, 0)
            EVT_CALL(RandInt, 5, LW(3))
            EVT_ADD(LW(3), 2)
            EVT_WAIT(LW(3))
            EVT_CALL(SetTexPanOffset, 12, 0, -65536, 0)
            EVT_WAIT(2)
            EVT_CALL(SetTexPanOffset, 12, 0, -32768, 0)
            EVT_WAIT(2)
            EVT_CALL(SetTexPanOffset, 12, 0, 0, 0)
            EVT_CALL(RandInt, 5, LW(3))
            EVT_ADD(LW(3), 2)
            EVT_WAIT(LW(3))
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80242840) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

MobileAISettings N(npcAISettings_8024286C) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_8024289C) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_ADDR(N(npcAISettings_8024286C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802428BC) = {
    .height = 42,
    .radius = 28,
    .ai = &N(npcAI_8024289C),
    .level = 99,
};

NpcSettings N(npcSettings_802428E8) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_80242914) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80242940) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_8024296C) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

extern const char N(flo_07_name_hack)[];

EvtScript N(80242998) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(UseSettingsFrom, 0, 50, 0, -200)
    EVT_CALL(SetPanTarget, 0, 50, 0, -200)
    EVT_CALL(SetCamDistance, 0, 700)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(10.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, 0, -27, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00C4), 0, 50, -200)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR(N(flo_07_name_hack)), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242AF0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, -170)
    EVT_CALL(SetPanTarget, 0, 0, 0, -170)
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(75)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x11, 0x0000), 160, 40)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
    EVT_CALL(PlayerJump1, LW(0), LW(1), LW(2), 12)
    EVT_WAIT(10)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(15)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(15)
    EVT_CALL(SetCamDistance, 0, 800)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(15.0), EVT_FLOAT(-5.8))
    EVT_CALL(SetCamPosA, 0, -2, 0)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, 0, -1, -1, 5, MESSAGE_ID(0x11, 0x0001))
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(InterpPlayerYaw, 350, 0)
    EVT_WAIT(15)
    EVT_CALL(ContinueSpeech, 0, -1, -1, 5, MESSAGE_ID(0x11, 0x0002))
    EVT_WAIT(10)
    EVT_CALL(SetCamDistance, 0, 333)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(9.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamPosA, 0, -2, 0)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(func_802D2C14, 1)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0003), 0, 70, -200)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(16.5), EVT_FLOAT(-11.8))
    EVT_CALL(SetCamDistance, 0, 525)
    EVT_CALL(SetCamPosA, 0, -14, 0)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80007)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0004), 0, 50, -200)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(9.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamDistance, 0, 333)
    EVT_CALL(SetCamPosA, 0, -2, 0)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0005), 0, 70, -200)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(90.0))
    EVT_SET(GameByte(0), 43)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242FCC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerActionState, LW(3))
    EVT_SET(LW(4), 0)
    EVT_IF_EQ(LW(3), 0)
        EVT_ADD(LW(4), 1)
    EVT_END_IF
    EVT_IF_EQ(LW(3), 1)
        EVT_ADD(LW(4), 1)
    EVT_END_IF
    EVT_IF_EQ(LW(3), 2)
        EVT_ADD(LW(4), 1)
    EVT_END_IF
    EVT_IF_EQ(LW(4), 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GameByte(0), 53)
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0006), 0, 50, -200)
        EVT_SET(GameByte(0), 54)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GameByte(0), 60)
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x000D), 0, 50, -200)
        EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x001F))
        EVT_WAIT(10)
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(0)
                EVT_SWITCH(GameByte(0))
                    EVT_CASE_LT(45)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x000E))
                    EVT_CASE_LT(46)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x000F))
                    EVT_CASE_LT(49)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0010))
                    EVT_CASE_LT(53)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0011))
                    EVT_CASE_LT(55)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0007))
                    EVT_CASE_LT(58)
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0012))
                    EVT_CASE_DEFAULT
                        EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0013))
                EVT_END_SWITCH
            EVT_CASE_EQ(1)
                EVT_CALL(CloseMessage)
                EVT_EXEC(N(8024196C))
                EVT_RETURN
            EVT_CASE_EQ(2)
                EVT_CALL(CloseMessage)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0014), 0, 50, -200)
        EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x001F))
        EVT_WAIT(10)
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(0)
                EVT_CALL(SwitchMessage, MESSAGE_ID(0x11, 0x0015))
            EVT_CASE_EQ(1)
                EVT_CALL(CloseMessage)
                EVT_EXEC(N(8024196C))
                EVT_RETURN
            EVT_CASE_EQ(2)
                EVT_CALL(CloseMessage)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243368) = {
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(90.0), 0, 600, EVT_FLOAT(21.0), EVT_FLOAT(-12.0))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x000B), 0, 50, -200)
    EVT_CALL(SetPanTarget, 0, 0, 0, -30)
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(25.0), EVT_FLOAT(-25.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x000C), 0, 50, -200)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(90.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243474) = {
    EVT_CALL(EnableGroup, 121, 0)
    EVT_CALL(EnableGroup, 80, 0)
    EVT_CALL(EnableGroup, 132, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 50, 70, -230)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_IF_LT(GameByte(0), STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
        EVT_EXEC(N(80242AF0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024352C) = {
    EVT_SWITCH(GameByte(0))
        EVT_CASE_LT(45)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_3, NPC_ANIM_bubulb_Palette_00_Anim_2, 0, MESSAGE_ID(0x11, 0x0016))
        EVT_CASE_LT(46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_3, NPC_ANIM_bubulb_Palette_00_Anim_2, 0, MESSAGE_ID(0x11, 0x0017))
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_3, NPC_ANIM_bubulb_Palette_00_Anim_2, 0, MESSAGE_ID(0x11, 0x0018))
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_3, NPC_ANIM_bubulb_Palette_00_Anim_2, 0, MESSAGE_ID(0x11, 0x0019))
        EVT_CASE_LT(57)
            EVT_SWITCH(AreaFlag(18))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_9, NPC_ANIM_bubulb_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x001A))
                    EVT_SET(AreaFlag(18), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_9, NPC_ANIM_bubulb_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x001B))
                    EVT_SET(AreaFlag(18), 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_00_Anim_9, NPC_ANIM_bubulb_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x001C))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802436C0) = {
    EVT_SWITCH(GameByte(0))
        EVT_CASE_LT(45)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x001D))
        EVT_CASE_LT(46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x001E))
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x001F))
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x0020))
        EVT_CASE_LT(57)
            EVT_SWITCH(AreaFlag(19))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x0021))
                    EVT_SET(AreaFlag(19), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x0022))
                    EVT_SET(AreaFlag(19), 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_01_Anim_3, NPC_ANIM_bubulb_Palette_01_Anim_2, 0, MESSAGE_ID(0x11, 0x0023))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80243854) = {
    EVT_SWITCH(GameByte(0))
        EVT_CASE_LT(45)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_3, NPC_ANIM_bubulb_Palette_02_Anim_2, 0, MESSAGE_ID(0x11, 0x0024))
        EVT_CASE_LT(46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_3, NPC_ANIM_bubulb_Palette_02_Anim_2, 0, MESSAGE_ID(0x11, 0x0025))
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_3, NPC_ANIM_bubulb_Palette_02_Anim_2, 0, MESSAGE_ID(0x11, 0x0026))
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_3, NPC_ANIM_bubulb_Palette_02_Anim_2, 0, MESSAGE_ID(0x11, 0x0027))
        EVT_CASE_LT(57)
            EVT_SWITCH(AreaFlag(20))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_9, NPC_ANIM_bubulb_Palette_02_Anim_8, 0, MESSAGE_ID(0x11, 0x0028))
                    EVT_SET(AreaFlag(20), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_9, NPC_ANIM_bubulb_Palette_02_Anim_8, 0, MESSAGE_ID(0x11, 0x0029))
                    EVT_SET(AreaFlag(20), 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_02_Anim_9, NPC_ANIM_bubulb_Palette_02_Anim_8, 0, MESSAGE_ID(0x11, 0x002A))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802439E8) = {
    EVT_SWITCH(GameByte(0))
        EVT_CASE_LT(45)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_3, NPC_ANIM_bubulb_Palette_03_Anim_2, 0, MESSAGE_ID(0x11, 0x002B))
        EVT_CASE_LT(46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_3, NPC_ANIM_bubulb_Palette_03_Anim_2, 0, MESSAGE_ID(0x11, 0x002C))
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_3, NPC_ANIM_bubulb_Palette_03_Anim_2, 0, MESSAGE_ID(0x11, 0x002D))
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_3, NPC_ANIM_bubulb_Palette_03_Anim_2, 0, MESSAGE_ID(0x11, 0x002E))
        EVT_CASE_LT(57)
            EVT_SWITCH(AreaFlag(21))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_9, NPC_ANIM_bubulb_Palette_03_Anim_8, 0, MESSAGE_ID(0x11, 0x002F))
                    EVT_SET(AreaFlag(21), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_9, NPC_ANIM_bubulb_Palette_03_Anim_8, 0, MESSAGE_ID(0x11, 0x0030))
                    EVT_SET(AreaFlag(21), 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_bubulb_Palette_03_Anim_9, NPC_ANIM_bubulb_Palette_03_Anim_8, 0, MESSAGE_ID(0x11, 0x0031))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243B7C) = {
    EVT_SET(AreaFlag(18), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_8024352C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243BB0) = {
    EVT_SET(AreaFlag(19), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802436C0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243BE4) = {
    EVT_SET(AreaFlag(20), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_80243854)))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243C18) = {
    EVT_SET(AreaFlag(21), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802439E8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80243C4C) = {
    EVT_IF_EQ(GameFlag(1373), 0)
        EVT_CALL(AdjustCam, 0, EVT_FLOAT(4.0), -30, 300, EVT_FLOAT(20.0), EVT_FLOAT(-9.5))
        EVT_SET(GameFlag(1373), 1)
    EVT_END_IF
    EVT_SWITCH(GameByte(0))
        EVT_CASE_LT(45)
            EVT_SWITCH(AreaByte(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0035))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0038))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0039))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(47)
            EVT_SWITCH(AreaByte(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0036))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0038))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0039))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(53)
            EVT_SWITCH(AreaByte(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0037))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0038))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0039))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(57)
            EVT_SWITCH(AreaByte(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0039))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
                    EVT_SET(AreaByte(0), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0038))
                    EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_tolielup_Palette_00_Anim_2, NPC_ANIM_tolielup_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x003A))
            EVT_CALL(EndSpeech, -1, NPC_ANIM_tolielup_Palette_00_Anim_3, NPC_ANIM_tolielup_Palette_00_Anim_3, 0)
    EVT_END_SWITCH
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024414C) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_80243C4C)))
    EVT_CALL(SetNpcCollisionSize, -1, 65, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244188) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024427C) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_SET(LW(3), LW(0))
    EVT_ADD(LW(3), -50)
    EVT_SET(LW(4), LW(1))
    EVT_ADD(LW(4), 26)
    EVT_CALL(SetNpcPos, 6, LW(3), LW(4), LW(2))
    EVT_CALL(PlayerFaceNpc, 6, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 6, 0)
    EVT_ADD(LW(0), -25)
    EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(475.0))
    EVT_CALL(SetCamPitch, 0, 18, -8)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_world_klevar_Palette_00_Anim_3, NPC_ANIM_world_klevar_Palette_00_Anim_1, 512, MESSAGE_ID(0x11, 0x00D8))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, 0, 18, -9)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, 6, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, 6, 0)
    EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_world_klevar_Palette_00_Anim_4)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_GOT_ITEM)
    EVT_CALL(PlaySoundAtPlayer, 313, 0)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_SET(LW(3), LW(1))
    EVT_ADD(LW(1), 50)
    EVT_ADD(LW(2), 10)
    EVT_ADD(LW(3), 30)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 3, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 1, LW(0), LW(3), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, 392, 0)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_CALL(PlayEffect, EFFECT_ENERGY_ORB_WAVE, 4, LW(0), LW(1), LW(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_world_klevar_Palette_00_Anim_1)
    EVT_CALL(EnableNpcAI, 6, 1)
    EVT_CALL(N(PostChapter6StatUpdate))
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x0196), 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, 6, LW(0), LW(1), LW(2))
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_world_klevar_Palette_00_Anim_3, NPC_ANIM_world_klevar_Palette_00_Anim_1, 512, MESSAGE_ID(0x11, 0x00D9))
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), -25)
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_world_klevar_Palette_00_Anim_3, NPC_ANIM_world_klevar_Palette_00_Anim_1, 512, MESSAGE_ID(0x11, 0x00DA))
    EVT_CALL(SetNpcFlagBits, 6, NPC_FLAG_40000, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, 6, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_SPARKLES, 4, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(2), 0)
        EVT_SET(LW(3), 1800)
        EVT_CALL(MakeLerp, LW(2), LW(3), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 6, 0, LW(0), 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LW(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, 6, LW(2), LW(3), LW(4))
        EVT_SET(LW(5), LW(3))
        EVT_ADD(LW(5), 180)
        EVT_CALL(MakeLerp, LW(3), LW(5), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, 6, LW(2), LW(0), LW(4))
            EVT_WAIT(1)
            EVT_IF_EQ(LW(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 6, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, 6, 0x2045, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_1002A)
    EVT_WAIT(110)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_SET(GameByte(0), 59)
    EVT_EXEC_WAIT(N(80243368))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244BF4) = {
    EVT_CALL(GetLoadType, LW(1))
    EVT_IF_NE(LW(1), 1)
        EVT_CALL(GetEntryID, LW(0))
        EVT_IF_EQ(LW(0), 10)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_ADDR(N(idle_80244188)))
            EVT_EXEC(N(8024427C))
        EVT_ELSE
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80244C98) = {
    EVT_IF_LE(GameByte(0), 53)
        EVT_CALL(SpeakToPlayer, 7, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0032))
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LW(0))
        EVT_IF_EQ(LW(0), 8)
            EVT_CALL(SpeakToPlayer, 7, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0032))
            EVT_WAIT(10)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_B, NPC_ANIM_world_lakilester_Palette_00_Anim_3, 5, MESSAGE_ID(0x11, 0x0033))
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
            EVT_CALL(EndSpeech, -4, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5)
            EVT_CALL(EnablePartnerAI)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, 7, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0034))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244DD0) = {
    EVT_IF_GE(GameByte(0), 58)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_80244C98)))
        EVT_CALL(SetNpcCollisionSize, -1, 36, 28)
        EVT_CALL(SetNpcPos, NPC_SELF, -200, 15, -300)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80244E64) = {
    .id = NPC_BUBULB0,
    .settings = &N(npcSettings_80242840),
    .pos = { -72.0f, 60.0f, -100.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_JUMPING,
    .init = &N(init_80243474),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
    },
};

StaticNpc N(npcGroup_80245054)[] = {
    {
        .id = NPC_BUBULB1,
        .settings = &N(npcSettings_802428BC),
        .pos = { -59.0f, 0.0f, -40.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243B7C),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, -59, 0, -40, -80, 0, -40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 }},
        .animations = {
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_E,
            NPC_ANIM_bubulb_Palette_00_Anim_E,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
            NPC_ANIM_bubulb_Palette_00_Anim_2,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D5),
    },
    {
        .id = NPC_BUBULB2,
        .settings = &N(npcSettings_802428BC),
        .pos = { 67.0f, 0.0f, 85.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243BB0),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, 67, 0, 85, 97, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 }},
        .animations = {
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_E,
            NPC_ANIM_bubulb_Palette_01_Anim_E,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
            NPC_ANIM_bubulb_Palette_01_Anim_2,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D6),
    },
    {
        .id = NPC_BUBULB3,
        .settings = &N(npcSettings_802428BC),
        .pos = { 90.0f, 0.0f, 410.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243BE4),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, 90, 0, 410, 120, 0, 410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 }},
        .animations = {
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_E,
            NPC_ANIM_bubulb_Palette_02_Anim_E,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
            NPC_ANIM_bubulb_Palette_02_Anim_2,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D7),
    },
    {
        .id = NPC_BUBULB4,
        .settings = &N(npcSettings_802428BC),
        .pos = { 200.0f, 0.0f, 430.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80243C18),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, 200, 0, 430, 240, 0, 430, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, -59, 0, -40, 100, 0, 0, 1 }},
        .animations = {
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_E,
            NPC_ANIM_bubulb_Palette_03_Anim_E,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
            NPC_ANIM_bubulb_Palette_03_Anim_2,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00D8),
    },
};

StaticNpc N(npcGroup_80245814) = {
    .id = NPC_TOLIELUP,
    .settings = &N(npcSettings_802428E8),
    .pos = { -400.0f, 0.0f, 190.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_8024414C),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
        NPC_ANIM_tolielup_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00D9),
};

StaticNpc N(npcGroup_80245A04) = {
    .id = NPC_WORLD_KLEVAR,
    .settings = &N(npcSettings_80242914),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80244BF4),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_0,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
        NPC_ANIM_world_klevar_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80245BF4) = {
    .id = NPC_LAKILULU,
    .settings = &N(npcSettings_80242840),
    .pos = { 198.0f, 0.0f, 363.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80244DD0),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
        NPC_ANIM_lakilulu_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00E2),
};

NpcGroupList N(npcGroupList_80245DE4) = {
    NPC_GROUP(N(npcGroup_80244E64)),
    NPC_GROUP(N(npcGroup_80245054)),
    NPC_GROUP(N(npcGroup_80245814)),
    NPC_GROUP(N(npcGroup_80245A04)),
    NPC_GROUP(N(npcGroup_80245BF4)),
    {},
};

static s32 N(pad_5E2C) = {
    0x00000000,
};

NpcSettings N(npcSettings_80245E30) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80245E5C) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = 16,
};

f32 N(D_80245E88_CA3DA8)[] = {
    266.0f,  20.0f, 322.0f, 310.0f,
    30.0f, 312.0f, 346.0f,  90.0f,
    300.0f, 400.0f, 200.0f, 287.0f,
};

extern const char N(sam_11_name_hack)[];

EvtScript N(80245EB8) = {
    EVT_CALL(SetPlayerPos, -400, 0, 200)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_SET(LW(0), 230)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 350)
    EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamPosA, 0, EVT_FLOAT(17.5), EVT_FLOAT(35.0))
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(70)
    EVT_CALL(InterpNpcYaw, 0, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_world_parakarry_Palette_00_Anim_6)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_world_parakarry_Palette_00_Anim_1)
    EVT_CALL(InterpNpcYaw, 2, 90, 0)
    EVT_CALL(NpcFlyTo, 2, 400, 200, 287, 80, -5, 0)
    EVT_CALL(InterpNpcYaw, 0, 270, 0)
    EVT_WAIT(40)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR(N(sam_11_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246170) = {
    EVT_CALL(SetPlayerPos, -400, 0, 200)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    EVT_CALL(SetNpcPos, 0, 196, 20, 354)
    EVT_CALL(SetNpcYaw, 0, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802461E4) = {
    EVT_CALL(SetNpcPos, 1, 163, 20, 370)
    EVT_CALL(SetNpcYaw, 1, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246224) = {
    EVT_CALL(SetNpcPos, 2, 266, 20, 322)
    EVT_CALL(SetNpcYaw, 2, 270)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246264)[] = {
    {
        .id = NPC_BUBULB0,
        .settings = &N(npcSettings_80245E30),
        .pos = { 144.0f, 0.0f, 374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
        .init = &N(init_80246170),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
            NPC_ANIM_world_lakilester_Palette_00_Anim_1,
        },
    },
    {
        .id = NPC_BUBULB1,
        .settings = &N(npcSettings_80245E30),
        .pos = { 198.0f, 0.0f, 363.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
        .init = &N(init_802461E4),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
            NPC_ANIM_lakilulu_Palette_00_Anim_1,
        },
    },
    {
        .id = NPC_BUBULB2,
        .settings = &N(npcSettings_80245E5C),
        .pos = { 266.0f, 0.0f, 322.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
        .init = &N(init_80246224),
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_2,
            NPC_ANIM_world_parakarry_Palette_00_Anim_3,
            NPC_ANIM_world_parakarry_Palette_00_Anim_3,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_0,
            NPC_ANIM_world_parakarry_Palette_00_Anim_0,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
            NPC_ANIM_world_parakarry_Palette_00_Anim_1,
        },
    },
};

NpcGroupList N(npcGroupList_80246834) = {
    NPC_GROUP(N(npcGroup_80246264)),
    {},
};

static s32 N(pad_684C) = {
    0x00000000,
};

EvtScript N(80246850) = {
    EVT_SETF(LW(1), LW(0))
    EVT_SUBF(LW(1), EVT_FLOAT(-700.0))
    EVT_DIVF(LW(1), EVT_FLOAT(100.0))
    EVT_SETF(LW(2), LW(1))
    EVT_MULF(LW(2), EVT_FLOAT(100.0))
    EVT_IF_GT(LW(2), 100)
        EVT_SETF(LW(1), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleGroup, 74, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 89, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 91, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 93, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 95, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 97, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 99, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 101, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 103, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 105, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 107, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 109, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 111, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 113, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 115, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 117, LW(1), 1, LW(1))
    EVT_CALL(ScaleModel, 119, LW(1), 1, LW(1))
    EVT_CALL(TranslateGroup, 74, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 89, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 91, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 93, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 95, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 97, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 99, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 101, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 103, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 105, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 107, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 109, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 111, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 113, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 115, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 117, 0, LW(0), 0)
    EVT_CALL(TranslateModel, 119, 0, LW(0), 0)
    EVT_SETF(LW(1), LW(0))
    EVT_MULF(LW(1), EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, 74, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 89, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 91, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 93, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 95, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 97, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 99, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 101, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 103, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 105, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 107, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 109, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 111, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 113, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 115, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 117, LW(1), 0, 1, 0)
    EVT_CALL(RotateModel, 119, LW(1), 0, 1, 0)
    EVT_CALL(TranslateModel, 89, EVT_FLOAT(8.1220703125), EVT_FLOAT(56.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 91, EVT_FLOAT(-6.8779296875), EVT_FLOAT(91.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 93, EVT_FLOAT(13.1220703125), EVT_FLOAT(106.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 95, EVT_FLOAT(-9.8779296875), EVT_FLOAT(136.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 97, EVT_FLOAT(-7.8779296875), EVT_FLOAT(201.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 99, EVT_FLOAT(13.1220703125), EVT_FLOAT(221.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 101, EVT_FLOAT(8.126953125), EVT_FLOAT(261.2294921875), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 103, EVT_FLOAT(-12.8779296875), EVT_FLOAT(266.1533203125), EVT_FLOAT(1.166015625))
    EVT_CALL(TranslateModel, 105, EVT_FLOAT(8.1220703125), EVT_FLOAT(316.1533203125), EVT_FLOAT(-13.833984375))
    EVT_CALL(TranslateModel, 107, EVT_FLOAT(-10.943359375), EVT_FLOAT(391.1533203125), EVT_FLOAT(10.56640625))
    EVT_CALL(TranslateModel, 109, EVT_FLOAT(-7.001953125), EVT_FLOAT(456.1533203125), EVT_FLOAT(0.947265625))
    EVT_CALL(TranslateModel, 111, EVT_FLOAT(12.998046875), EVT_FLOAT(471.1533203125), EVT_FLOAT(0.947265625))
    EVT_CALL(TranslateModel, 113, EVT_FLOAT(-10.001953125), EVT_FLOAT(501.1533203125), EVT_FLOAT(0.947265625))
    EVT_CALL(TranslateModel, 115, EVT_FLOAT(8.0029296875), EVT_FLOAT(536.2294921875), EVT_FLOAT(0.947265625))
    EVT_CALL(TranslateModel, 117, EVT_FLOAT(12.998046875), EVT_FLOAT(586.1533203125), EVT_FLOAT(0.947265625))
    EVT_CALL(TranslateModel, 119, EVT_FLOAT(-13.001953125), EVT_FLOAT(631.1533203125), EVT_FLOAT(0.947265625))
    EVT_SETF(LW(1), LW(0))
    EVT_SUBF(LW(1), EVT_FLOAT(-700.0))
    EVT_DIVF(LW(1), EVT_FLOAT(300.0))
    EVT_SETF(LW(2), LW(1))
    EVT_MULF(LW(2), EVT_FLOAT(100.0))
    EVT_IF_GT(LW(2), 100)
        EVT_SETF(LW(1), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleModel, 89, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 91, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 93, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 95, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 97, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 99, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 101, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 103, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 105, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 107, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 109, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 111, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 113, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 115, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 117, LW(1), LW(1), LW(1))
    EVT_CALL(ScaleModel, 119, LW(1), LW(1), LW(1))
    EVT_CALL(TranslateModel, 89, EVT_FLOAT(-8.12109375), EVT_FLOAT(-56.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 91, EVT_FLOAT(6.87890625), EVT_FLOAT(-91.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 93, EVT_FLOAT(-13.12109375), EVT_FLOAT(-106.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 95, EVT_FLOAT(9.87890625), EVT_FLOAT(-136.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 97, EVT_FLOAT(7.87890625), EVT_FLOAT(-201.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 99, EVT_FLOAT(-13.12109375), EVT_FLOAT(-221.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 101, EVT_FLOAT(-8.1259765625), EVT_FLOAT(-261.228515625), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 103, EVT_FLOAT(12.87890625), EVT_FLOAT(-266.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, 105, EVT_FLOAT(-8.12109375), EVT_FLOAT(-316.15234375), EVT_FLOAT(13.8349609375))
    EVT_CALL(TranslateModel, 107, EVT_FLOAT(10.9443359375), EVT_FLOAT(-391.15234375), EVT_FLOAT(-10.5654296875))
    EVT_CALL(TranslateModel, 109, EVT_FLOAT(7.0029296875), EVT_FLOAT(-456.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, 111, EVT_FLOAT(-12.9970703125), EVT_FLOAT(-471.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, 113, EVT_FLOAT(10.0029296875), EVT_FLOAT(-501.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, 115, EVT_FLOAT(-8.001953125), EVT_FLOAT(-536.228515625), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, 117, EVT_FLOAT(-12.9970703125), EVT_FLOAT(-586.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, 119, EVT_FLOAT(13.0029296875), EVT_FLOAT(-631.15234375), EVT_FLOAT(-0.9462890625))
    EVT_RETURN
    EVT_END
};

EvtScript N(80247488) = {
    EVT_SETF(LW(1), LW(0))
    EVT_SUBF(LW(1), EVT_FLOAT(-700.0))
    EVT_DIVF(LW(1), EVT_FLOAT(100.0))
    EVT_SETF(LW(2), LW(1))
    EVT_MULF(LW(2), EVT_FLOAT(100.0))
    EVT_IF_GT(LW(2), 100)
        EVT_SETF(LW(1), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleGroup, 79, LW(1), 1, LW(1))
    EVT_CALL(TranslateGroup, 79, 0, LW(0), 0)
    EVT_SETF(LW(1), LW(0))
    EVT_MULF(LW(1), EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, 79, LW(1), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80247588) = {
    EVT_CALL(TranslateModel, 83, EVT_FLOAT(9.5), EVT_FLOAT(12.0), EVT_FLOAT(15.0))
    EVT_CALL(TranslateModel, 85, EVT_FLOAT(-9.5), EVT_FLOAT(12.0), EVT_FLOAT(15.0))
    EVT_CALL(TranslateModel, 87, EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(17.0))
    EVT_SETF(LW(1), LW(0))
    EVT_MULF(LW(1), EVT_FLOAT(90.0))
    EVT_CALL(RotateModel, 83, LW(1), 0, 0, -1)
    EVT_CALL(RotateModel, 85, LW(1), 0, 0, 1)
    EVT_CALL(TranslateModel, 83, EVT_FLOAT(-9.5), EVT_FLOAT(-12.0), EVT_FLOAT(-15.0))
    EVT_CALL(TranslateModel, 85, EVT_FLOAT(9.5), EVT_FLOAT(-12.0), EVT_FLOAT(-15.0))
    EVT_CALL(TranslateModel, 87, EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(-17.0))
    EVT_CALL(ScaleModel, 83, LW(0), LW(0), LW(0))
    EVT_CALL(ScaleModel, 85, LW(0), LW(0), LW(0))
    EVT_CALL(ScaleModel, 87, LW(0), LW(0), LW(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802476F4) = {
    EVT_CALL(ScaleModel, 81, LW(0), LW(0), LW(0))
    EVT_SETF(LW(1), LW(0))
    EVT_MULF(LW(1), EVT_FLOAT(90.0))
    EVT_ADDF(LW(1), EVT_FLOAT(-90.0))
    EVT_CALL(RotateModel, 81, LW(1), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80247770) = {
    EVT_SETF(LW(1), LW(0))
    EVT_MULF(LW(1), EVT_FLOAT(-3.0))
    EVT_CALL(TranslateModel, 81, EVT_FLOAT(-0.26), LW(0), EVT_FLOAT(1.4775390625))
    EVT_CALL(RotateModel, 81, LW(1), 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, 46)
    EVT_RETURN
    EVT_END
};

extern const char N(flo_19_name_hack)[];

EvtScript N(802477EC) = {
    EVT_IF_EQ(AreaFlag(44), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT(15)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_SET(AreaFlag(44), 1)
        EVT_CALL(ModifyColliderFlags, 0, 47, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 48, 0x7FFFFE00)
        EVT_SET(LW(9), EVT_FLOAT(-59.0))
        EVT_SET(LW(10), EVT_FLOAT(22.0))
        EVT_SET(LW(11), EVT_FLOAT(125.0))
        EVT_SET(LW(12), EVT_FLOAT(-55.0))
        EVT_SET(LW(13), EVT_FLOAT(24.0))
        EVT_SET(LW(14), EVT_FLOAT(145.0))
        EVT_CALL(PlayerMoveTo, LW(9), LW(11), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, LW(12), LW(13), LW(14), 5)
        EVT_CALL(PlaySound, 0x19C)
        EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x000106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_CALL(N(func_80240F10_C9EE30), LW(3), LW(4))
        EVT_SWITCH(LW(4))
            EVT_CASE_LT(90)
                EVT_SET(AreaFlag(16), 0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_GE(270)
                EVT_SET(AreaFlag(16), 1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
        EVT_CALL(TranslateModel, 81, EVT_FLOAT(-0.26), EVT_FLOAT(2.0), EVT_FLOAT(1.4775390625))
        EVT_CALL(UpdateColliderTransform, 46)
        EVT_SET(MapVar(10), 0)
        EVT_THREAD
            EVT_SET(LW(15), 0)
            EVT_LOOP(0)
                EVT_ADD(LW(15), 1)
                EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), 0, 700, 800, 0, 0)
                EVT_EXEC(N(80247770))
                EVT_SETF(LW(2), LW(0))
                EVT_MULF(LW(2), EVT_FLOAT(-3.0))
                EVT_SETF(LW(3), LW(0))
                EVT_CALL(N(func_80240F80_C9EEA0))
                EVT_CALL(N(func_802410B4_C9EFD4))
                EVT_IF_EQ(LW(15), 350)
                    EVT_SET(MapVar(10), 1)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_LABEL(10)
        EVT_IF_EQ(MapVar(10), 0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR(N(flo_19_name_hack)), 3)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80247BCC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(ModifyColliderFlags, 0, 47, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 48, 0x7FFFFE00)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_SET(LW(9), EVT_FLOAT(-59.0))
    EVT_SET(LW(10), EVT_FLOAT(22.0))
    EVT_SET(LW(11), EVT_FLOAT(125.0))
    EVT_SET(LW(12), EVT_FLOAT(-55.0))
    EVT_SET(LW(13), EVT_FLOAT(23.0))
    EVT_SET(LW(14), EVT_FLOAT(145.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x000106)
        EVT_CALL(SetPlayerAnimation, ANIM_WALKING)
        EVT_SWITCH(AreaFlag(16))
            EVT_CASE_EQ(0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_EQ(1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(TranslateModel, 81, EVT_FLOAT(-0.26), EVT_FLOAT(2.0), EVT_FLOAT(1.4775390625))
    EVT_CALL(UpdateColliderTransform, 46)
    EVT_SET(LW(15), 0)
    EVT_LOOP(120)
        EVT_ADD(LW(15), 1)
        EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), 70, 0, 120, 0, 0)
        EVT_EXEC(N(80247770))
        EVT_SETF(LW(2), LW(0))
        EVT_MULF(LW(2), EVT_FLOAT(-3.0))
        EVT_SETF(LW(3), LW(0))
        EVT_CALL(N(func_80240F80_C9EEA0))
        EVT_CALL(N(func_802410B4_C9EFD4))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(PlayerJump, 10, 0, 110, 20)
    EVT_CALL(SetPlayerActionState, 10)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(ModifyColliderFlags, 1, 47, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 1, 48, 0x7FFFFE00)
    EVT_SET(AreaFlag(44), 0)
    EVT_CALL(StopSound, 413)
    EVT_EXEC_WAIT(N(802414D0))
    EVT_CALL(ResetCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80247FAC) = {
    EVT_CALL(PlaySoundAtCollider, 47, 411, 0)
    EVT_SET(LW(15), 0)
    EVT_LOOP(100)
        EVT_ADD(LW(15), 1)
        EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), 0, EVT_FLOAT(1.0), 100, 0, 0)
        EVT_EXEC(N(80247588))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MapVar(10), 0)
    EVT_THREAD
        EVT_SET(LW(15), 0)
        EVT_LOOP(1200)
            EVT_ADD(LW(15), 1)
            EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), -700, 0, 1200, 0, 0)
            EVT_SETF(LW(2), LW(0))
            EVT_MULF(LW(2), EVT_FLOAT(1.0))
            EVT_SETF(LW(0), LW(2))
            EVT_EXEC(N(80246850))
            EVT_SETF(LW(2), LW(0))
            EVT_MULF(LW(2), EVT_FLOAT(1.0))
            EVT_SETF(LW(0), LW(2))
            EVT_EXEC(N(80247488))
            EVT_SWITCH(LW(15))
                EVT_CASE_EQ(200)
                    EVT_CALL(SetPlayerAnimation, ANIM_1002A)
                EVT_CASE_EQ(250)
                    EVT_SET(LW(0), -60)
                    EVT_SET(LW(1), 0)
                    EVT_SET(LW(2), 65)
                    EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
                    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
                    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
                    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(12.5), EVT_FLOAT(-7.0))
                    EVT_CALL(SetCamDistance, 0, 800)
                    EVT_CALL(SetCamPosA, 0, -200, 0)
                    EVT_CALL(SetCamPosB, 0, 0, -300)
                    EVT_CALL(PanToTarget, 0, 0, 1)
                    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_GT(LW(15), 550)
                EVT_SET(MapVar(10), 1)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(10)
    EVT_IF_EQ(MapVar(10), 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(FadeInMusic, 0, 50, 0, 3000, 0, 127)
    EVT_CALL(FadeOutMusic, 1, 3000)
    EVT_CALL(GotoMap, EVT_PTR(N(flo_19_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024834C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 200, 0)
    EVT_CALL(SetPlayerPos, -60, 0, 30)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -20, 0, 10)
    EVT_SET(LW(0), -60)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 65)
    EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(12.5), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, 0, 800)
    EVT_CALL(SetCamPosA, 0, -200, 0)
    EVT_CALL(SetCamPosB, 0, 0, -300)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_SET(LW(15), 0)
    EVT_LOOP(5)
        EVT_ADD(LW(15), 20)
        EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), EVT_FLOAT(0.0), EVT_FLOAT(1.0), 100, 0, 0)
        EVT_EXEC(N(802476F4))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, 1, 46, 0x7FFFFE00)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x000A), 0, 50, -200)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80248598)[] = {
    ITEM_FERTILE_SOIL,
    ITEM_MAGICAL_BEAN,
    ITEM_MIRACLE_WATER,
    ITEM_NONE,
};

EvtScript N(802485A8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2884, -85, 85, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(GameFlag(1371), 0)
        EVT_SET_GROUP(0)
        EVT_CALL(SetTimeFreezeMode, 1)
        EVT_LABEL(10)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LW(2), LW(0))
        EVT_SWITCH(LW(2))
            EVT_CASE_LE(0)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
                EVT_RETURN
            EVT_CASE_EQ(89)
                EVT_CALL(SetPlayerAnimation, 393222)
                EVT_WAIT(5)
                EVT_CALL(RemoveKeyItemAt, LW(1))
                EVT_CALL(MakeItemEntity, ITEM_FERTILE_SOIL, -83, 0, 87, 1, 0)
                EVT_SET(MapVar(11), LW(0))
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_WAIT(20)
            EVT_CASE_DEFAULT
                EVT_SWITCH(AreaFlag(17))
                    EVT_CASE_EQ(0)
                        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0008), 0, 10, -200)
                        EVT_SET(AreaFlag(17), 1)
                    EVT_CASE_DEFAULT
                        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0009), 0, 10, -200)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_IF_NE(LW(2), 89)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(GameFlag(1371), 1)
    EVT_END_IF
    EVT_IF_EQ(GameFlag(1372), 0)
        EVT_SET_GROUP(0)
        EVT_CALL(SetTimeFreezeMode, 1)
        EVT_LABEL(20)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LW(2), LW(0))
        EVT_SWITCH(LW(2))
            EVT_CASE_LE(0)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
                EVT_RETURN
            EVT_CASE_EQ(88)
                EVT_CALL(RemoveItemEntity, MapVar(11))
                EVT_WAIT(5)
                EVT_CALL(SetPlayerAnimation, 393222)
                EVT_WAIT(5)
                EVT_CALL(RemoveKeyItemAt, LW(1))
                EVT_CALL(MakeItemEntity, ITEM_MAGICAL_BEAN, -83, 0, 87, 1, 0)
                EVT_SET(MapVar(11), LW(0))
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_WAIT(20)
            EVT_CASE_DEFAULT
                EVT_SWITCH(AreaFlag(17))
                    EVT_CASE_EQ(0)
                        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0008), 0, 10, -200)
                        EVT_SET(AreaFlag(17), 1)
                    EVT_CASE_DEFAULT
                        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x0009), 0, 10, -200)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_IF_NE(LW(2), 88)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_SET(GameFlag(1372), 1)
    EVT_END_IF
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_LABEL(30)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LW(2), LW(0))
    EVT_SWITCH(LW(2))
        EVT_CASE_LE(0)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, 0)
            EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
            EVT_RETURN
        EVT_CASE_EQ(90)
            EVT_CALL(RemoveItemEntity, MapVar(11))
            EVT_WAIT(5)
            EVT_CALL(SetPlayerAnimation, 393222)
            EVT_WAIT(5)
            EVT_CALL(RemoveKeyItemAt, LW(1))
            EVT_CALL(N(SyncStatusMenu))
            EVT_CALL(MakeItemEntity, ITEM_MIRACLE_WATER, -83, 0, 87, 1, 0)
            EVT_SET(MapVar(11), LW(0))
            EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
            EVT_WAIT(30)
            EVT_CALL(RemoveItemEntity, MapVar(11))
            EVT_WAIT(30)
            EVT_CALL(ModifyColliderFlags, 0, 47, 0x7FFFFE00)
            EVT_CALL(PlayerMoveTo, -60, 30, 20)
            EVT_CALL(ModifyColliderFlags, 1, 47, 0x7FFFFE00)
            EVT_CALL(ModifyColliderFlags, 1, 48, 0x7FFFFE00)
            EVT_CALL(InterpPlayerYaw, 200, 0)
            EVT_CALL(func_802CF56C, 2)
            EVT_WAIT(60)
            EVT_CALL(FadeInMusic, 1, 123, 0, 3000, 0, 127)
            EVT_CALL(FadeOutMusic, 0, 3000)
            EVT_CALL(UseSettingsFrom, 0, -85, 0, 75)
            EVT_CALL(SetPanTarget, 0, -85, 0, 75)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
            EVT_CALL(SetCamDistance, 0, 250)
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_EXEC_WAIT(N(80247FAC))
    EVT_END_SWITCH
    EVT_IF_NE(LW(2), 90)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80248D3C) = {
    EVT_LABEL(0)
    EVT_CALL(IsPlayerWithin, -85, 85, 20, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(IsPlayerOnValidFloor, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(GetCurrentPartner, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(func_8024139C_C9F2BC))
    EVT_EXEC_WAIT(N(802485A8))
    EVT_CALL(N(func_802413BC_C9F2DC))
    EVT_RETURN
    EVT_END
};

EvtScript N(80248E30) = {
    EVT_IF_LT(GameByte(0), 55)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_EQ(GameByte(0), 54)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_EQ(GameFlag(1371), 1)
            EVT_IF_EQ(GameFlag(1372), 0)
                EVT_CALL(MakeItemEntity, ITEM_FERTILE_SOIL, -83, 0, 87, 1, 0)
            EVT_ELSE
                EVT_CALL(MakeItemEntity, ITEM_MAGICAL_BEAN, -83, 0, 87, 1, 0)
            EVT_END_IF
            EVT_SET(MapVar(11), LW(0))
        EVT_END_IF
        EVT_BIND_PADLOCK(N(80248D3C), 0x10, 0, EVT_ADDR(N(itemList_80248598)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80248F48) = {
    EVT_BIND_TRIGGER(N(802477EC), TRIGGER_FLOOR_TOUCH, 46, 1, 0)
    EVT_CALL(EnableGroup, 121, 1)
    EVT_CALL(EnableGroup, 80, 1)
    EVT_SWITCH(GameByte(0))
        EVT_CASE_EQ(54)
            EVT_SET(LW(0), -700)
            EVT_EXEC(N(80246850))
            EVT_EXEC(N(80247488))
            EVT_SET(LW(0), 0)
            EVT_EXEC(N(80247588))
            EVT_SET(LW(0), 0)
            EVT_EXEC(N(802476F4))
            EVT_CALL(ModifyColliderFlags, 0, 46, 0x7FFFFE00)
            EVT_CALL(ModifyColliderFlags, 0, 47, 0x7FFFFE00)
        EVT_CASE_GE(55)
            EVT_SET(LW(0), 1)
            EVT_EXEC(N(80247588))
            EVT_SET(LW(0), 1)
            EVT_EXEC(N(802476F4))
        EVT_CASE_DEFAULT
            EVT_SET(LW(0), -700)
            EVT_EXEC(N(80246850))
            EVT_EXEC(N(80247488))
            EVT_SET(LW(0), 0)
            EVT_EXEC(N(80247588))
            EVT_SET(LW(0), 0)
            EVT_EXEC(N(802476F4))
            EVT_CALL(ModifyColliderFlags, 0, 46, 0x7FFFFE00)
            EVT_CALL(ModifyColliderFlags, 0, 47, 0x7FFFFE00)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_9128)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_IF_LT(GameByte(0), 96)
        EVT_CALL(MakeEntity, EVT_ADDR(Entity_SavePoint), 110, 60, -100, 0, 0x80000000)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

ApiStatus N(PostChapter6StatUpdate)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(6);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

const char N(flo_07_name_hack)[] = "flo_07";
const s32 N(pad_XXX)[] = { 0, 0 };
const char N(sam_11_name_hack)[] = "sam_11";
const char N(flo_19_name_hack)[] = "flo_19";
