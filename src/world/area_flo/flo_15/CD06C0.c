#include "flo_15.h"
#include "message_ids.h"
#include "sprite/npc/sun.h"

enum {
    NPC_SUN0 = 10,
    NPC_SUN1,
};

EntryList N(entryList) = {
    {  320.0f, 0.0f,  0.0f, 270.0f },
    { -170.0f, 0.0f, 55.0f,   0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_15_tattle },
};

EvtSource N(80240060) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(EVT_SAVE_VAR(0))
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_11C) = {
    0x00000000,
};

EvtSource N(exitWalk_80240120) = EXIT_WALK_SCRIPT(60,  0, "flo_13",  1);

EvtSource N(8024017C) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240120), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
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
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802412C0)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_EXEC(N(802404D8))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(EVT_VAR(0), EVT_PTR(N(8024017C)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
    EVT_EXEC(N(802413B0))
    EVT_EXEC_WAIT(N(80240060))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2FC) = {
    0x00000000,
};

NpcSettings N(npcSettings_80240300) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(8024032C) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 53)
        EVT_SET(EVT_VAR(3), 7)
        EVT_SET(EVT_VAR(4), 5)
    EVT_ELSE
        EVT_SET(EVT_VAR(3), 15)
        EVT_SET(EVT_VAR(4), 1)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_SET(EVT_VAR(5), EVT_VAR(3))
        EVT_LOOP(EVT_VAR(5))
            EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcPos, 11, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(EVT_VAR(4))
        EVT_END_LOOP
        EVT_SET(EVT_VAR(5), EVT_VAR(3))
        EVT_LOOP(EVT_VAR(5))
            EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), -1)
            EVT_CALL(SetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcPos, 11, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(EVT_VAR(4))
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802404D8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcPos, 10, 0, 270, 0)
    EVT_CALL(SetNpcPos, 11, 0, -1000, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 1050)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(10.0), EVT_FIXED(4.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(15.0), EVT_FIXED(-10.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(6.5))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_9, NPC_ANIM_sun_Palette_00_Anim_9, 517, MESSAGE_ID(0x11, 0x00C3))
    EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_sun_Palette_00_Anim_9)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 1000)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(5.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcJumpscale, 10, EVT_FIXED(0.0))
    EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 400)
    EVT_CALL(NpcJump0, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 40)
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), 9)
    EVT_WAIT_FRAMES(70)
    EVT_RETURN
    EVT_END
};

EvtSource N(aux_8024079C) = {
    EVT_CALL(func_802CDE68, 11, 48)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, -30, 30, 20, 11)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 11, 0, 0, EVT_VAR(0))
            EVT_CALL(GetNpcPos, 10, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
            EVT_CALL(SetNpcPos, 11, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 30, -30, 20, 11)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 11, 0, 0, EVT_VAR(0))
            EVT_CALL(GetNpcPos, 10, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
            EVT_CALL(SetNpcPos, 11, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(8024094C) = {
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_GT(EVT_VAR(1), 220)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlayerFaceNpc, 10, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, 10, EVT_FIXED(0.0))
    EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(1), 400)
    EVT_CALL(NpcJump0, 10, EVT_VAR(0), 275, EVT_VAR(2), 30)
    EVT_EXEC_GET_TID(N(8024032C), EVT_VAR(9))
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_AREA_FLAG(38), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(10)
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(SetNpcFlagBits, 10, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(NpcJump0, 10, EVT_VAR(0), 450, EVT_VAR(2), 30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80240B28) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(50)
            EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009A))
            EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetPlayerAnimation, ANIM_80007)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009B))
            EVT_SET(EVT_SAVE_VAR(0), 50)
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009C))
        EVT_CASE_LT(57)
            EVT_IF_EQ(EVT_SAVE_FLAG(1410), 0)
                EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009D))
                EVT_SET(EVT_SAVE_FLAG(1410), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009E))
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, 10, NPC_ANIM_sun_Palette_00_Anim_7, NPC_ANIM_sun_Palette_00_Anim_1, 517, MESSAGE_ID(0x11, 0x009F))
    EVT_END_SWITCH
    EVT_SET(EVT_AREA_FLAG(38), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80240CD0) = {
    EVT_CALL(SetNpcCollisionSize, 10, 64, 40)
    EVT_CALL(EnableNpcShadow, 10, FALSE)
    EVT_IF_LT(EVT_SAVE_VAR(0), 53)
        EVT_CALL(SetNpcPos, 10, 0, 270, 0)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80240B28)))
        EVT_EXEC(N(8024032C))
    EVT_ELSE
        EVT_CALL(SetNpcPos, 10, 0, 450, 0)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80240B28)))
        EVT_SET(EVT_AREA_FLAG(38), 0)
        EVT_EXEC(N(8024094C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80240DB4) = {
    EVT_CALL(EnableNpcShadow, 11, FALSE)
    EVT_CALL(SetNpcAnimation, 11, NPC_ANIM_sun_Palette_00_Anim_2)
    EVT_CALL(SetNpcPaletteSwapMode, 10, 3)
    EVT_CALL(SetNpcPaletteSwapMode, 11, 3)
    EVT_CALL(SetNpcPaletteSwapping, 10, 0, 1, 5, 5, 13, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, 11, 0, 1, 5, 5, 13, 5, 0, 0)
    EVT_IF_LT(EVT_SAVE_VAR(0), 53)
        EVT_CALL(SetNpcPos, 11, 0, 270, -5)
    EVT_ELSE
        EVT_CALL(SetNpcPos, 11, 0, 450, -5)
        EVT_CALL(BindNpcAux, -1, EVT_PTR(N(aux_8024079C)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80240EE0)[] = {
    {
        .id = NPC_SUN0,
        .settings = &N(npcSettings_80240300),
        .pos = { 0.0f, 250.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_400000,
        .init = &N(init_80240CD0),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E1),
    },
    {
        .id = NPC_SUN1,
        .settings = &N(npcSettings_80240300),
        .pos = { 0.0f, 250.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_8000,
        .init = &N(init_80240DB4),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
            NPC_ANIM_sun_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00E1),
    },
};

NpcGroupList N(npcGroupList_802412C0) = {
    NPC_GROUP(N(npcGroup_80240EE0), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_12D8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(802412E0) = {
    EVT_SET(EVT_SAVE_FLAG(1401), 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1401), 0)
        EVT_CALL(MakeEntity, 0x802BCF00, -180, 0, -18, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(802412E0)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_135C) = {
    0x00000000,
};

s32 N(intTable_80241360)[] = {
    0x0000000A, 0xF24A7CE7, 0x0000000D, 0xF24A7D80, 0x00000010, 0xF24A7E1A, 0x00000013, 0xF24A7EB4,
    0x00000016, 0xF24A7F4D, 0x00000019, 0xF24A7EB4, 0x00000018, 0xF24A7E1A, 0x00000019, 0xF24A7D80,
    0x00000018, 0xF24A7CE7, 0x0000000A, 0xF24A814D,
};

EvtSource N(802413B0) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1401), 0)
        EVT_LABEL(0)
        EVT_IF_EQ(EVT_SAVE_FLAG(1401), 0)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_USE_BUF(EVT_PTR(N(intTable_80241360)))
            EVT_LOOP(10)
                EVT_BUF_READ2(EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(ShakeCam, 0, 0, EVT_VAR(1), EVT_VAR(2))
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(UseSettingsFrom, 0, -170, 0, 35)
        EVT_CALL(SetPanTarget, 0, -170, 0, 35)
        EVT_CALL(SetCamDistance, 0, 600)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(25.0), EVT_FIXED(-9.0))
        EVT_CALL(SetCamPosA, 0, EVT_FIXED(-50.0), EVT_FIXED(25.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(1.5))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_THREAD
            EVT_WAIT_FRAMES(100)
            EVT_CALL(PlayEffect, 0x6, 4, -180, 0, -15, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x6, 4, -190, 0, -35, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(6)
                EVT_CALL(PlaySoundAtCollider, 11, 391, 0)
                EVT_WAIT_FRAMES(20)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, -50, 120, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, 16, 0, EVT_VAR(0), 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, 0, 12, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 1, 14, 0x7FFFFE00)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(ResetCam, 0, EVT_FIXED(90.0))
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 12, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 1, 14, 0x7FFFFE00)
        EVT_CALL(TranslateGroup, 16, 0, -50, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
