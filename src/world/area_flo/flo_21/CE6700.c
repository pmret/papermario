#include "flo_21.h"
#include "effects.h"
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

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_21_tattle },
};

EvtSource N(80240D40) = {
    EVT_IF_EQ(EVT_SAVE_VAR(0), 56)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/StarSpiritEffectFunc.inc.c"

EvtSource N(80240DA0) = {
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

EvtSource N(80240E3C) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_EQ(55)
            EVT_SET(EVT_VAR(0), 0)
            EVT_IF_EQ(EVT_MAP_VAR(10), 0)
                EVT_RETURN
            EVT_END_IF
            EVT_SET(EVT_SAVE_VAR(0), 56)
        EVT_CASE_EQ(56)
            EVT_SET(EVT_VAR(0), 1)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, 0, 650, 205, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(0.6))
        EVT_CALL(SetPanTarget, 0, 650, 150, 0)
        EVT_CALL(GetCamDistance, 0, EVT_VAR(1))
        EVT_SUB(EVT_VAR(1), 100)
        EVT_CALL(SetCamDistance, 0, EVT_VAR(1))
        EVT_IF_NE(EVT_FIXED(-5.5), 10000)
            EVT_CALL(GetCamPitch, 0, EVT_VAR(2), EVT_VAR(3))
            EVT_CALL(SetCamPitch, 0, EVT_VAR(2), EVT_FIXED(-5.5))
        EVT_END_IF
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 5, 180, 650, 170, 0, 650, 205, 0, 150, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(1)
            EVT_CALL(PlaySound, 0x80000067)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, 0x80000067)
            EVT_CALL(PlaySoundAt, 0xB2, 0, 650, 205, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(45)
            EVT_CALL(SetPlayerAnimation, 65578)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(180)
            EVT_WAIT_FRAMES(115)
            EVT_CALL(PlaySoundAt, 0x137, 0, 650, 205, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT_FRAMES(80)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_END_THREAD
        EVT_ADD(EVT_VAR(1), 100)
        EVT_CALL(SetCamDistance, 0, EVT_VAR(1))
        EVT_CALL(SetPanTarget, 0, 650, 120, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(1.0))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(PanToTarget, 0, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 5, 650, 150, 0, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT_FRAMES(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, 312, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_SAVE_VAR(0), 57)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), 5, 14)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_802412F4) = EXIT_WALK_SCRIPT(60,  0, "flo_19",  1);

EvtSource N(80241350) = {
    EVT_BIND_TRIGGER(N(exitWalk_802412F4), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 39)
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
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80241350)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80240D40))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240B00_CE7200))
    EVT_END_IF
    EVT_EXEC(N(80240E3C))
    EVT_RETURN
    EVT_END
};

s32 N(D_802414FC_CE7BFC)[] = {
    0,
    EVT_FIXED(1), EVT_FIXED(1), EVT_FIXED(1),
    EVT_FIXED(1), EVT_FIXED(1), EVT_FIXED(1),
    EVT_FIXED(1.1005859375), EVT_FIXED(1.1005859375), EVT_FIXED(1.1005859375),
    EVT_FIXED(1.1005859375), EVT_FIXED(1.1005859375), EVT_FIXED(1.1005859375),
    EVT_FIXED(1), EVT_FIXED(1), EVT_FIXED(1),
    EVT_FIXED(1), EVT_FIXED(1), EVT_FIXED(1),
    EVT_FIXED(0.900390625), EVT_FIXED(0.900390625), EVT_FIXED(0.900390625),
    EVT_FIXED(0.900390625), EVT_FIXED(0.900390625), EVT_FIXED(0.900390625),
};

EvtSource N(80241560) = {
    EVT_ADDF(EVT_MAP_VAR(0), EVT_FIXED(-1.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(80241580) = {
    EVT_ADDF(EVT_MAP_VAR(1), EVT_FIXED(-1.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(802415A0) = {
    EVT_ADDF(EVT_MAP_VAR(2), EVT_FIXED(-1.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(802415C0) = {
    EVT_ADDF(EVT_MAP_VAR(3), EVT_FIXED(-1.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(802415E0) = {
    EVT_ADDF(EVT_MAP_VAR(4), EVT_FIXED(-1.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(80241600) = {
    EVT_THREAD
        EVT_SET(EVT_VAR(15), 0)
        EVT_LABEL(0)
        EVT_CALL(N(UnkFloatFunc), EVT_VAR(15), EVT_VAR(0), EVT_FIXED(0.96875), EVT_FIXED(1.03125), 15, 0, 0)
        EVT_CALL(N(UnkFloatFunc), EVT_VAR(15), EVT_VAR(1), EVT_FIXED(1.03125), EVT_FIXED(0.96875), 15, 0, 0)
        EVT_CALL(ScaleModel, 88, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 90, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 92, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 94, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 96, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 98, EVT_VAR(1), EVT_VAR(0), 1)
        EVT_CALL(ScaleModel, 100, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(ScaleModel, 102, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_ADD(EVT_VAR(15), 1)
        EVT_IF_GE(EVT_VAR(15), 30)
            EVT_SET(EVT_VAR(15), 0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
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
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
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

EvtSource N(802418C0) = {
    EVT_LABEL(0)
    EVT_CALL(PlaySound, 0x20B6)
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241920) = {
    EVT_CALL(PlaySoundAtNpc, 0, 0x3C0, 0)
    EVT_CALL(PlayEffect, 0x25, 3, 650, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcJumpscale, 1, EVT_FIXED(0.0))
    EVT_CALL(NpcJump0, 1, 650, 50, 0, 5)
    EVT_CALL(SetNpcPos, 0, 650, 50, 5)
    EVT_CALL(SetNpcPos, 1, 650, 50, 0)
    EVT_CALL(SetNpcPos, 2, 650, 50, 0)
    EVT_CALL(SetNpcJumpscale, 0, EVT_FIXED(0.0))
    EVT_CALL(SetNpcJumpscale, 1, EVT_FIXED(0.0))
    EVT_CALL(SetNpcJumpscale, 2, EVT_FIXED(0.0))
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
        EVT_CALL(SetPlayerAnimation, ANIM_80017)
        EVT_CALL(LoadPath, 30, EVT_PTR(N(vectorList_8024189C)), 3, 0)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(0), 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_1002B)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241B98) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), 56)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 650, 0, 30)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_HUFF_N_PUFF_THEME, 0, 8)
    EVT_EXEC_GET_TID(N(802418C0), EVT_VAR(9))
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT_FRAMES(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetPlayerAnimation, ANIM_1002B)
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(MakeLerp, EVT_VAR(2), 600, 20, 0)
    EVT_SET(EVT_VAR(2), EVT_VAR(3))
    EVT_SET(EVT_VAR(5), EVT_VAR(3))
    EVT_ADD(EVT_VAR(5), 15)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(EVT_VAR(3), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4))
        EVT_IF_GT(EVT_VAR(3), EVT_VAR(5))
            EVT_SET(EVT_VAR(3), EVT_VAR(2))
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(2), EVT_VAR(4))
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(2), EVT_VAR(4))
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 25)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(300.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-9.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00CA), 630, 120, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(600.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(30.0), EVT_FIXED(-9.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00CB), 630, 120, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(300.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-9.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(func_802D2C14, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 8)
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00CC), 630, 120, 0)
    EVT_ELSE
        EVT_CALL(ShowMessageAtWorldPos, MESSAGE_ID(0x11, 0x00CD), 630, 120, 0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 25)
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-6.0))
        EVT_SET(EVT_VAR(3), 40)
        EVT_LOOP(5)
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, EVT_FIXED(400.0))
            EVT_CALL(SetCamSpeed, 0, EVT_VAR(3))
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_SUB(EVT_VAR(3), 10)
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, EVT_FIXED(600.0))
            EVT_CALL(SetCamSpeed, 0, EVT_VAR(3))
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_ADD(EVT_VAR(3), 7)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_EXEC_WAIT(N(80241920))
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT_FRAMES(15)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242290) = {
    EVT_SETF(EVT_VAR(0), EVT_FIXED(0.95))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(1.1))
    EVT_LABEL(0)
    EVT_SWITCH(EVT_MAP_VAR(13))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(3), 10)
            EVT_SET(EVT_VAR(2), 2)
        EVT_CASE_EQ(1)
            EVT_SET(EVT_VAR(3), 5)
            EVT_SET(EVT_VAR(2), 1)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(EVT_VAR(4), EVT_VAR(3))
    EVT_LOOP(EVT_VAR(4))
        EVT_CALL(SetNpcScale, 0, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(SetNpcScale, 1, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(SetNpcScale, 2, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_ADDF(EVT_VAR(0), EVT_FIXED(0.015625))
        EVT_SUBF(EVT_VAR(1), EVT_FIXED(0.01))
        EVT_WAIT_FRAMES(EVT_VAR(2))
    EVT_END_LOOP
    EVT_SET(EVT_VAR(4), EVT_VAR(3))
    EVT_LOOP(EVT_VAR(4))
        EVT_CALL(SetNpcScale, 0, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(SetNpcScale, 1, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_CALL(SetNpcScale, 2, EVT_VAR(0), EVT_VAR(1), 1)
        EVT_SUBF(EVT_VAR(0), EVT_FIXED(0.015625))
        EVT_ADDF(EVT_VAR(1), EVT_FIXED(0.01))
        EVT_WAIT_FRAMES(EVT_VAR(2))
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

EvtSource N(8024263C) = {
    EVT_SETF(EVT_VAR(0), 10)
    EVT_SETF(EVT_VAR(1), 1)
    EVT_CHILD_THREAD
        EVT_LOOP(8)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), FALSE)
            EVT_WAIT_FRAMES(EVT_VAR(0))
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), TRUE)
            EVT_WAIT_FRAMES(EVT_VAR(1))
            EVT_SUBF(EVT_VAR(0), 0)
            EVT_ADDF(EVT_VAR(1), 0)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), FALSE)
            EVT_WAIT_FRAMES(EVT_VAR(0))
            EVT_CALL(SetNpcFlagBits, 0, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_2)), TRUE)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2)), TRUE)
            EVT_WAIT_FRAMES(EVT_VAR(1))
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 0, 255, 10, 4)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 0, 9, EVT_VAR(0), EVT_VAR(0), EVT_VAR(0), 0)
                EVT_CALL(func_802CFD30, 1, 9, EVT_VAR(0), EVT_VAR(0), EVT_VAR(0), 0)
                EVT_CALL(func_802CFD30, 2, 9, EVT_VAR(0), EVT_VAR(0), EVT_VAR(0), 0)
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(EVT_VAR(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242918) = {
    EVT_SETF(EVT_MAP_VAR(11), EVT_FIXED(1.0))
    EVT_SETF(EVT_MAP_VAR(12), EVT_FIXED(1.0))
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(intTable_8024258C)))
        EVT_LOOP(6)
            EVT_CALL(PlaySoundAtNpc, 0, 0x20B6, 0)
            EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
            EVT_CALL(MakeLerp, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 11)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(EVT_VAR(0), 10)
                EVT_SETF(EVT_MAP_VAR(11), EVT_VAR(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(EVT_VAR(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(intTable_802425D4)))
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtNpc, 0, 0x20B6, 0)
                EVT_BUF_READ2(EVT_VAR(6), EVT_VAR(7))
                EVT_CALL(MakeLerp, EVT_VAR(6), EVT_VAR(7), 4, 11)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(EVT_VAR(0), 10)
                    EVT_SETF(EVT_MAP_VAR(11), EVT_VAR(0))
                    EVT_WAIT_FRAMES(1)
                    EVT_IF_EQ(EVT_VAR(1), 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(intTable_802425E4)))
        EVT_LOOP(6)
            EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
            EVT_CALL(MakeLerp, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 11)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(EVT_VAR(0), 10)
                EVT_SETF(EVT_MAP_VAR(12), EVT_VAR(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(EVT_VAR(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(intTable_8024262C)))
            EVT_LOOP(2)
                EVT_BUF_READ2(EVT_VAR(6), EVT_VAR(7))
                EVT_CALL(MakeLerp, EVT_VAR(6), EVT_VAR(7), 4, 11)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(EVT_VAR(0), 10)
                    EVT_SETF(EVT_MAP_VAR(12), EVT_VAR(0))
                    EVT_WAIT_FRAMES(1)
                    EVT_IF_EQ(EVT_VAR(1), 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(100)
        EVT_CALL(SetNpcScale, 0, EVT_MAP_VAR(11), EVT_MAP_VAR(12), 1)
        EVT_CALL(SetNpcScale, 1, EVT_MAP_VAR(11), EVT_MAP_VAR(12), 1)
        EVT_CALL(SetNpcScale, 2, EVT_MAP_VAR(11), EVT_MAP_VAR(12), 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80242D34) = {
    EVT_CHILD_THREAD
        EVT_SET(EVT_VAR(1), 0)
        EVT_LOOP(0)
            EVT_SET(EVT_VAR(0), 3)
            EVT_LOOP(15)
                EVT_CALL(SetNpcRotation, EVT_VAR(0), 0, EVT_VAR(1), 0)
                EVT_ADD(EVT_VAR(0), 1)
            EVT_END_LOOP
            EVT_ADD(EVT_VAR(1), 60)
            EVT_IF_GT(EVT_VAR(1), 360)
                EVT_ADD(EVT_VAR(1), -360)
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_USE_BUF(EVT_PTR(N(intTable_8024249C)))
    EVT_SET(EVT_VAR(8), 3)
    EVT_LOOP(14)
        EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_THREAD
            EVT_CALL(RandInt, 5, EVT_VAR(5))
            EVT_WAIT_FRAMES(EVT_VAR(5))
            EVT_CALL(SetNpcPos, EVT_VAR(8), EVT_VAR(1), EVT_VAR(2), -30)
            EVT_CALL(RandInt, 2, EVT_VAR(5))
            EVT_ADD(EVT_VAR(5), 8)
            EVT_CALL(PlaySoundAtNpc, EVT_VAR(8), 0x3D5, 0)
            EVT_CALL(NpcJump0, EVT_VAR(8), EVT_VAR(3), EVT_VAR(4), -15, EVT_VAR(5))
            EVT_CALL(SetNpcPos, EVT_VAR(8), 0, -1000, 0)
        EVT_END_THREAD
        EVT_ADD(EVT_VAR(8), 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
    EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetNpcPos, EVT_VAR(8), EVT_VAR(1), EVT_VAR(2), -30)
    EVT_CALL(PlaySoundAtNpc, EVT_VAR(8), 0x3D6, 0)
    EVT_CALL(NpcJump0, EVT_VAR(8), EVT_VAR(3), EVT_VAR(4), -15, 10)
    EVT_CALL(SetNpcPos, EVT_VAR(8), 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80243010) = {
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_huff_n_puff_Palette_00_Anim_4)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_huff_n_puff_Palette_00_Anim_5)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_huff_n_puff_Palette_00_Anim_6)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), -15)
    EVT_ADD(EVT_VAR(2), 40)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(350.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-5.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_huff_n_puff_Palette_00_Anim_30, NPC_ANIM_huff_n_puff_Palette_00_Anim_5, 256, -30, 30, MESSAGE_ID(0x11, 0x00CE))
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_SET(EVT_MAP_VAR(13), 2)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_THREAD
        EVT_SET(EVT_VAR(3), EVT_VAR(0))
        EVT_SET(EVT_VAR(4), EVT_VAR(0))
        EVT_ADD(EVT_VAR(3), -35)
        EVT_ADD(EVT_VAR(4), 35)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x19, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(PlayEffect, 0x19, 0, EVT_VAR(3), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_ADD(EVT_VAR(3), 7)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(PlayEffect, 0x19, 0, EVT_VAR(4), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_ADD(EVT_VAR(4), -7)
            EVT_WAIT_FRAMES(14)
        EVT_END_LOOP
        EVT_CALL(PlayEffect, 0x19, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ShakeCam, 0, 0, 30, EVT_FIXED(1.5))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_LOOP(10)
            EVT_CALL(PlayEffect, 0x3A, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 40, 65, 12, 15, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(7)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(8024263C))
    EVT_EXEC_WAIT(N(80242918))
    EVT_EXEC_WAIT(N(80242D34))
    EVT_WAIT_FRAMES(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80243428) = {
    EVT_LABEL(0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_MAP_VAR(13), 1)
    EVT_CALL(StartBossBattle, 14)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802434D8) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetEncounterStatusFlags, 1, 1)
            EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(3))
            EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(3), -20)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(3))
            EVT_EXEC_WAIT(N(80243010))
            EVT_WAIT_FRAMES(50)
            EVT_SET(EVT_MAP_VAR(10), 1)
            EVT_EXEC(N(80240E3C))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802435D4) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802435E4) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 56)
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

EvtSource N(init_80243684) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 56)
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

EvtSource N(init_8024371C) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 56)
        EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802435D4)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_huff_n_puff_Palette_00_Anim_19)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802437A8) = {
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
    ANIM_END,
};

StaticNpc N(npcGroup_80243804)[] = {
    {
        .id = NPC_HUFF_N_PUFF0,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_802435E4),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_80243684),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_8024371C),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
    ANIM_END,
};

StaticNpc N(npcGroup_80243DDC)[] = {
    {
        .id = NPC_TUFF_PUFF0,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
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
    NPC_GROUP(N(npcGroup_80243804), BATTLE_ID(25, 0, 0, 8)),
    NPC_GROUP(N(npcGroup_80243DDC), BATTLE_ID(24, 31, 0, 8)),
    {},
};

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

EffectInstance* playFX_82();

ApiStatus N(func_80240B00_CE7200)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
