#include "flo_10.h"
#include "message_ids.h"
#include "effects.h"
#include "sprite/npc/lily.h"

enum {
    NPC_LILY,
};

EntryList N(entryList) = {
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -100.0f, -10.0f, -172.0f, 135.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { .get = N(func_80240000_CB9200) },
};

EvtScript N(802414E0) = {
    EVT_CALL(GetEntryID, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(GSW(0))
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_IF_GE(GSW(0), 49)
        EVT_CALL(PlaySound, 0x80000022)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802415C4) = {
    EVT_CALL(PushSong, 137, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(802415E8) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1624)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80241630) = {
    EVT_IF_GE(GSW(0), 49)
        EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_167C) = {
    0x00000000,
};

EvtScript N(80241680) = {
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

EvtScript N(exitWalk_8024192C) = EXIT_WALK_SCRIPT(60,  0, "flo_24",  1);

EvtScript N(80241988) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024192C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GSW(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_80244054)))
    EVT_EXEC_WAIT(N(80241630))
    EVT_EXEC(flo_10_80244A50)
    EVT_EXEC(flo_10_802435F8)
    EVT_EXEC(flo_10_80242AE8)
    EVT_EXEC(flo_10_80244074)
    EVT_CALL(ModifyColliderFlags, 3, 11, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 12, 0x00000006)
    EVT_SET(LW(0), -265)
    EVT_SET(LW(1), 247)
    EVT_SET(LW(2), 199)
    EVT_SET(LW(3), 313)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(80241680))
    EVT_SET(LW(0), -300)
    EVT_SET(LW(1), -275)
    EVT_SET(LW(2), -140)
    EVT_SET(LW(3), -185)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(80241680))
    EVT_SET(LW(0), 263)
    EVT_SET(LW(1), -248)
    EVT_SET(LW(2), 362)
    EVT_SET(LW(3), 146)
    EVT_SET(LW(4), 0)
    EVT_EXEC(N(80241680))
    EVT_CALL(GetEntryID, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_EXEC(flo_10_8024324C)
        EVT_CASE_EQ(2)
            EVT_EXEC(flo_10_802427EC)
            EVT_EXEC(N(80241988))
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
            EVT_SET(LW(0), EVT_ADDR(N(80241988)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802414E0))
    EVT_IF_GE(GSW(0), 53)
        EVT_CALL(N(func_80240040_CB9240))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1CA8)[] = {
    0x00000000, 0x00000000,
};

s32** N(varStash) = NULL;

EvtScript N(80241CB4) = {
    EVT_CALL(ShowGotItem, LW(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241CE4) = {
    EVT_CALL(ShowGotItem, LW(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(updateTexturePan_80241D14) = {
    EVT_SET_GROUP(0)
    EVT_IF_EQ(LW(5), 1)
        EVT_IF_EQ(LW(6), 1)
            EVT_IF_EQ(LW(7), 1)
                EVT_IF_EQ(LW(8), 1)
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

EvtScript N(80241DB0) = {
    EVT_CALL(MakeLerp, -50, 170, 385, 0)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, 56, 0, LW(0), 0)
    EVT_IF_EQ(LW(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E40) = {
    EVT_CALL(MakeLerp, 0, 100, 90, 1)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_SETF(LW(2), LW(0))
    EVT_SETF(LW(3), LW(0))
    EVT_DIVF(LW(2), EVT_FLOAT(333.0))
    EVT_DIVF(LW(3), EVT_FLOAT(100.0))
    EVT_ADDF(LW(2), EVT_FLOAT(0.703125))
    EVT_CALL(ScaleGroup, 56, LW(2), LW(3), LW(2))
    EVT_IF_EQ(LW(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80241F20) = {
    EVT_CALL(EnableTexPanning, 53, 1)
    EVT_THREAD
        EVT_SET(LW(0), 10)
        EVT_SET(LW(1), -150)
        EVT_SET(LW(2), 0)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 1)
        EVT_SET(LW(6), 0)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(80242030) = {
    EVT_WAIT(60)
    EVT_CALL(EnableModel, 53, 1)
    EVT_EXEC(N(80241F20))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024206C) = {
    EVT_WAIT(80)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_CALL(GetNpcPos, 0, LW(3), LW(4), LW(5))
    EVT_CALL(MakeLerp, 10, 55, 108, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LW(6), LW(4))
        EVT_ADD(LW(6), LW(0))
        EVT_ADD(LW(6), -10)
        EVT_CALL(SetNpcPos, 0, LW(3), LW(6), LW(5))
        EVT_CALL(TranslateGroup, 60, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80242188) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, 524324)
    EVT_CALL(GetPlayerPos, LW(2), LW(0), LW(3))
    EVT_CALL(MakeLerp, -50, 90, 60, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LW(2), EVT_FLOAT(1.2))
        EVT_DIVF(LW(3), EVT_FLOAT(1.2))
        EVT_CALL(SetPlayerPos, LW(2), LW(0), LW(3))
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 90, 270, 280, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024230C) = {
    EVT_WAIT(80)
    EVT_CALL(GetPlayerPos, LW(3), LW(4), LW(5))
    EVT_CALL(UseSettingsFrom, 0, LW(3), LW(4), LW(5))
    EVT_CALL(SetPanTarget, 0, LW(3), LW(4), LW(5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.7))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(25.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802423E4) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(80241DB0))
    EVT_EXEC(N(80241E40))
    EVT_EXEC(N(80242030))
    EVT_EXEC(N(8024206C))
    EVT_EXEC(N(80242188))
    EVT_EXEC(N(8024230C))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024244C) = {
    EVT_CALL(MakeLerp, 170, 75, 150, 0)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, 56, 0, LW(0), 0)
    EVT_IF_EQ(LW(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802424DC) = {
    EVT_CALL(MakeLerp, 100, 15, 150, 1)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_SETF(LW(2), LW(0))
    EVT_SETF(LW(3), LW(0))
    EVT_DIVF(LW(2), EVT_FLOAT(333.0))
    EVT_DIVF(LW(3), EVT_FLOAT(100.0))
    EVT_ADDF(LW(2), EVT_FLOAT(0.703125))
    EVT_CALL(ScaleGroup, 56, LW(2), LW(3), LW(2))
    EVT_IF_EQ(LW(1), 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802425BC) = {
    EVT_EXEC(N(8024244C))
    EVT_EXEC(N(802424DC))
    EVT_RETURN
    EVT_END
};

extern const char N(flo_24_name_hack)[];

EvtScript N(802425E4) = {
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(GetPlayerPos, LW(3), LW(4), LW(5))
    EVT_CALL(UseSettingsFrom, 0, LW(3), LW(4), LW(5))
    EVT_CALL(SetPanTarget, 0, LW(3), LW(4), LW(5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(EnableGroup, 56, 1)
    EVT_CALL(TranslateGroup, 56, 0, -50, 0)
    EVT_CALL(ScaleGroup, 56, 0, 0, 0)
    EVT_CALL(EnableGroup, 60, 1)
    EVT_EXEC_WAIT(N(802423E4))
    EVT_WAIT(20)
    EVT_CALL(PlaySound, 0x80000024)
    EVT_WAIT(360)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
    EVT_CALL(PlayerJump1, -100, -10, -172, 75)
    EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(802425BC))
    EVT_WAIT(60)
    EVT_CALL(GotoMap, EVT_PTR(N(flo_24_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802427EC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -100, -10, -172)
    EVT_CALL(InterpPlayerYaw, 150, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_DEAD_STILL)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -129, 9, -177)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(EnableGroup, 52, 1)
    EVT_CALL(EnableGroup, 19, 0)
    EVT_CALL(EnableGroup, 61, 0)
    EVT_CALL(EnableGroup, 60, 0)
    EVT_CALL(SetNpcPos, 0, -57, -20, -105)
    EVT_CALL(InterpNpcYaw, 0, 90, 0)
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(90.0), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_GET_UP)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(802415C4))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x0082))
    EVT_CALL(NpcFacePlayer, 0, 1)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0083))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_lily_Palette_00_Anim_6)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_lily_Palette_00_Anim_1)
    EVT_SET(LW(0), 90)
    EVT_SET(LW(1), 1)
    EVT_EXEC_WAIT(N(80241CB4))
    EVT_CALL(AddKeyItem, ITEM_MIRACLE_WATER)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0084))
    EVT_CALL(EndSpeech, 0, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_lily_Palette_00_Anim_1)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(802415E8))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242AE8) = {
    EVT_IF_LT(GSW(0), 49)
        EVT_CALL(EnableGroup, 52, 0)
        EVT_CALL(EnableGroup, 61, 0)
        EVT_CALL(ModifyColliderFlags, 0, 21, 0x7FFFFE00)
    EVT_ELSE
        EVT_CALL(EnableGroup, 19, 0)
        EVT_CALL(EnableGroup, 61, 0)
        EVT_CALL(EnableGroup, 60, 0)
        EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 15, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 16, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 17, 0x7FFFFE00)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, 54, 1)
    EVT_CALL(EnableTexPanning, 48, 1)
    EVT_CALL(EnableTexPanning, 55, 1)
    EVT_CALL(EnableTexPanning, 59, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_THREAD
        EVT_SET(LW(0), 1)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), -2000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 0)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 3)
        EVT_SET(LW(1), -100)
        EVT_SET(LW(2), 80)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 1)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 5)
        EVT_SET(LW(1), -1000)
        EVT_SET(LW(2), 2000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 1)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 6)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), -2000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 0)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 8)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), -1500)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 0)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 9)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), -1000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 0)
        EVT_SET(LW(5), 0)
        EVT_SET(LW(6), 1)
        EVT_SET(LW(7), 0)
        EVT_SET(LW(8), 0)
        EVT_SET(LW(9), 0)
        EVT_SET(LW(10), 0)
        EVT_SET(LW(11), 0)
        EVT_SET(LW(12), 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_IF_GE(GSW(0), 49)
        EVT_EXEC(N(80241F20))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3218)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80243220) = {
    .height = 45,
    .radius = 65,
    .level = 99,
};

const char N(flo_24_name_hack)[] = "flo_24";

EvtScript N(8024324C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcPos, 0, 60, 0, 55)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00C6))
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_12"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80243394)[] = {
    ITEM_WATER_STONE,
    ITEM_NONE,
};

EvtScript N(8024339C) = {
    EVT_IF_EQ(GSWF(1376), 1)
        EVT_CALL(GetCurrentPartner, LW(10))
        EVT_IF_NE(LW(10), 0)
            EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_SET_GROUP(0)
        EVT_CALL(SetTimeFreezeMode, 1)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LW(2), LW(0))
        EVT_SWITCH(LW(2))
            EVT_CASE_EQ(-1)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x0081))
            EVT_CASE_DEFAULT
                EVT_CALL(GetPlayerPos, LW(3), LW(4), LW(5))
                EVT_CALL(PlayerMoveTo, -17, -17, 20)
                EVT_CALL(func_802CF56C, 2)
                EVT_CALL(InterpPlayerYaw, 100, 1)
                EVT_WAIT(10)
                EVT_CALL(AdjustCam, 0, EVT_FLOAT(1.0), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
                EVT_WAIT(10)
                EVT_CALL(SetPlayerAnimation, 393222)
                EVT_CALL(RemoveKeyItemAt, LW(1))
                EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, 1, 0)
                EVT_SET(LW(10), LW(0))
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_EXEC_WAIT(N(802425E4))
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802435F8) = {
    EVT_BIND_PADLOCK(N(8024339C), TRIGGER_FLOOR_TOUCH, 15, EVT_ADDR(N(itemList_80243394)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243628) = {
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetPlayerPos, LW(3), LW(4), LW(5))
    EVT_IF_LT(LW(5), LW(2))
        EVT_SET(LW(6), 30)
    EVT_ELSE
        EVT_SET(LW(6), 20)
    EVT_END_IF
    EVT_SET(LW(1), LW(0))
    EVT_SET(LW(4), LW(0))
    EVT_SUB(LW(1), LW(6))
    EVT_ADD(LW(4), LW(6))
    EVT_SWITCH(LW(3))
        EVT_CASE_RANGE(LW(1), LW(4))
            EVT_THREAD
                EVT_IF_LT(LW(3), LW(0))
                    EVT_SUB(LW(0), 40)
                EVT_ELSE
                    EVT_ADD(LW(0), 40)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
                EVT_CALL(PlayerMoveTo, LW(0), LW(5), 15)
                EVT_CALL(PlayerFaceNpc, 0, 1)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802437C8) = {
    EVT_EXEC_WAIT(N(802415C4))
    EVT_SWITCH(GSW(0))
        EVT_CASE_LT(45)
            EVT_EXEC(N(80243628))
            EVT_CALL(GetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
            EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
            EVT_CALL(SetCamDistance, 0, 325)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11, 0x0078))
            EVT_CALL(EndSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_9, NPC_ANIM_lily_Palette_00_Anim_5, 5)
        EVT_CASE_LT(48)
            EVT_IF_EQ(GSWF(1375), 0)
                EVT_EXEC(N(80243628))
                EVT_CALL(GetNpcPos, NPC_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(UseSettingsFrom, 0, LW(0), LW(1), LW(2))
                EVT_CALL(SetPanTarget, 0, LW(0), LW(1), LW(2))
                EVT_CALL(SetCamDistance, 0, 325)
                EVT_CALL(SetCamPitch, 0, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
                EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11, 0x0079))
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_1)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
                EVT_CALL(ShowEmote, -1, EMOTE_EXCLAMATION, 0, 15, 1, 0, 0, 0, 0)
                EVT_WAIT(15)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_1, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x007A))
                EVT_CALL(EndSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_5, NPC_ANIM_lily_Palette_00_Anim_1, 0)
                EVT_CALL(GetPlayerTargetYaw, LW(0))
                EVT_CALL(InterpNpcYaw, NPC_SELF, LW(0), 1)
                EVT_WAIT(20)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x007B))
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_WAIT(20)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x007C))
                EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x0011))
                EVT_WAIT(10)
                EVT_SWITCH(LW(0))
                    EVT_CASE_EQ(0)
                        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x007D))
                    EVT_CASE_EQ(1)
                        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x007E))
                EVT_END_SWITCH
                EVT_WAIT(10)
                EVT_SET(GSWF(1375), 1)
                EVT_CALL(SetEnemyFlagBits, -1, 4194304, 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 5, MESSAGE_ID(0x11, 0x007F))
            EVT_END_IF
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0080))
            EVT_SET(GSWF(1376), 1)
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x0085))
            EVT_CALL(EndSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0)
            EVT_CALL(EndSpeech, -1, NPC_ANIM_lily_Palette_00_Anim_4, NPC_ANIM_lily_Palette_00_Anim_8, 0)
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_3, NPC_ANIM_lily_Palette_00_Anim_7, 0, MESSAGE_ID(0x11, 0x0086))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_2, NPC_ANIM_lily_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0087))
    EVT_END_SWITCH
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(802415E8))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243D78) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_802437C8)))
    EVT_SWITCH(GSW(0))
        EVT_CASE_LT(48)
            EVT_IF_EQ(GSWF(1375), 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_lily_Palette_00_Anim_8)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
                EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
            EVT_END_IF
        EVT_CASE_EQ(48)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CASE_GE(49)
            EVT_CALL(SetNpcPos, NPC_SELF, -67, -20, -105)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243E64) = {
    .id = NPC_LILY,
    .settings = &N(npcSettings_80243220),
    .pos = { 80.0f, -60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80243D78),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
        NPC_ANIM_lily_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DF),
};

NpcGroupList N(npcGroupList_80244054) = {
    NPC_GROUP(N(npcGroup_80243E64)),
    {},
};

static s32 N(pad_406C) = {
    0x00000000,
};

s32 N(D_80244070_CBD270) = {
    0x00000000,
};

EvtScript N(80244074) = {
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4084)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

