#include "flo_07.h"
#include "message_ids.h"
#include "sprite/npc/posie.h"

enum {
    NPC_POSIE,
};

EntryList N(entryList) = {
    { 375.0f, 0.0f, 0.0f, 270.0f },
    { 325.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_07_tattle },
};

EvtSource N(802407A0) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(EVT_SAVE_VAR(0))
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(PlaySound, 0x80000021)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024086C) = {
    EVT_CALL(PushSong, 137, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240890) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_8CC) = {
    0x00000000,
};

EvtSource N(updateTexturePan_802408D0) = {
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

EvtSource N(8024096C) = {
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

EvtSource N(exitWalk_80240C18) = EXIT_WALK_SCRIPT(60,  0, "flo_25",  1);

EvtSource N(80240C74) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240C18), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
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
    EVT_SET(EVT_AREA_FLAG(6), 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80242B0C)))
    EVT_EXEC_WAIT(N(802428C4))
    EVT_CALL(ModifyColliderFlags, 3, 6, 0x00000006)
    EVT_SET(EVT_VAR(0), 297)
    EVT_SET(EVT_VAR(1), -95)
    EVT_SET(EVT_VAR(2), 383)
    EVT_SET(EVT_VAR(3), -65)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(EVT_VAR(0), 293)
    EVT_SET(EVT_VAR(1), 71)
    EVT_SET(EVT_VAR(2), 378)
    EVT_SET(EVT_VAR(3), 113)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(EVT_VAR(0), 21)
    EVT_SET(EVT_VAR(1), -346)
    EVT_SET(EVT_VAR(2), 147)
    EVT_SET(EVT_VAR(3), -242)
    EVT_SET(EVT_VAR(4), 20)
    EVT_EXEC(N(8024096C))
    EVT_SET(EVT_VAR(0), -350)
    EVT_SET(EVT_VAR(1), -190)
    EVT_SET(EVT_VAR(2), -81)
    EVT_SET(EVT_VAR(3), -106)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(8024096C))
    EVT_SET(EVT_VAR(0), -380)
    EVT_SET(EVT_VAR(1), 85)
    EVT_SET(EVT_VAR(2), -95)
    EVT_SET(EVT_VAR(3), 150)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(8024096C))
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 50, 1)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 2)
        EVT_SET(EVT_VAR(1), -100)
        EVT_SET(EVT_VAR(2), 100)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 1)
        EVT_SET(EVT_VAR(6), 1)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_802408D0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 3)
        EVT_SET(EVT_VAR(1), 0)
        EVT_SET(EVT_VAR(2), -1200)
        EVT_SET(EVT_VAR(3), 0)
        EVT_SET(EVT_VAR(4), 0)
        EVT_SET(EVT_VAR(5), 0)
        EVT_SET(EVT_VAR(6), 1)
        EVT_SET(EVT_VAR(7), 0)
        EVT_SET(EVT_VAR(8), 0)
        EVT_SET(EVT_VAR(9), 0)
        EVT_SET(EVT_VAR(10), 0)
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_EXEC(N(updateTexturePan_802408D0))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_EXEC(N(80241C14))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(EVT_VAR(0), EVT_PTR(N(80240C74)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(802424F4))
    EVT_END_IF
    EVT_EXEC_WAIT(N(802407A0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_CALL(N(func_80240344_CAC534))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1214)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80241220) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

#include "world/common/foliage.inc.c"

s32** N(D_80241BB0_CADDA0) = NULL;

EvtSource N(80241BB4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(80241BE4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(80241C14) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(11.0), EVT_FIXED(-11.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00C5))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_10"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241D6C) = {
    EVT_LABEL(0)
    EVT_CALL(ShakeCam, 0, 0, 1, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80241DBC) = {
    EVT_IF_EQ(EVT_AREA_FLAG(6), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0068))
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 300)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.0), EVT_FIXED(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(0.5))
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlaySound, 0x8000006B)
    EVT_EXEC_GET_TID(N(80241D6C), EVT_MAP_VAR(0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_6, NPC_ANIM_posie_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0069))
    EVT_KILL_THREAD(EVT_MAP_VAR(0))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.0), EVT_FIXED(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(8.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), EVT_VAR(2))
    EVT_IF_LT(EVT_VAR(0), -250)
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 100, -25, 13, EVT_SAVE_FLAG(1374))
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 100, 54, 13, EVT_SAVE_FLAG(1374))
        EVT_SET(EVT_SAVE_FLAG(1396), 1)
    EVT_END_IF
    EVT_CALL(PlaySound, 0x7BC)
    EVT_CALL(func_802D62E4, 956)
    EVT_SET(EVT_AREA_FLAG(6), 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006A))
    EVT_SET(EVT_SAVE_VAR(0), 47)
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80242044) = {
    EVT_EXEC_WAIT(N(8024086C))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(45)
            EVT_IF_EQ(EVT_AREA_FLAG(5), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0070))
                EVT_SET(EVT_AREA_FLAG(5), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0071))
            EVT_END_IF
        EVT_CASE_LT(46)
            EVT_CALL(AdjustCam, 0, EVT_FIXED(4.0), 0, EVT_FIXED(350.0), EVT_FIXED(18.0), EVT_FIXED(-7.5))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0065))
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_5)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_0)
            EVT_SET(EVT_VAR(0), 89)
            EVT_SET(EVT_VAR(1), 1)
            EVT_EXEC_WAIT(N(80241BB4))
            EVT_CALL(AddKeyItem, ITEM_FERTILE_SOIL)
            EVT_SET(EVT_SAVE_VAR(0), 46)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0066))
            EVT_IF_EQ(EVT_SAVE_FLAG(1379), 1)
                EVT_EXEC_WAIT(N(80241DBC))
            EVT_END_IF
            EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
        EVT_CASE_LT(47)
            EVT_IF_EQ(EVT_SAVE_FLAG(1379), 1)
                EVT_IF_EQ(EVT_AREA_FLAG(6), 0)
                    EVT_CALL(AdjustCam, 0, EVT_FIXED(4.0), 0, EVT_FIXED(350.0), EVT_FIXED(18.0), EVT_FIXED(-7.5))
                    EVT_EXEC_WAIT(N(80241DBC))
                    EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0072))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0072))
            EVT_END_IF
        EVT_CASE_LT(53)
            EVT_IF_EQ(EVT_SAVE_FLAG(1374), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0072))
            EVT_ELSE
                EVT_IF_LT(EVT_SAVE_VAR(0), 48)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0073))
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0074))
                EVT_END_IF
                EVT_CALL(ContinueSpeech, -1, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0075))
            EVT_END_IF
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0076))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0077))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80240890))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80242428) = {
    EVT_IF_EQ(EVT_SAVE_VAR(0), 47)
        EVT_IF_EQ(EVT_SAVE_FLAG(1374), 0)
            EVT_IF_EQ(EVT_SAVE_FLAG(1396), 0)
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 0, -25, 17, EVT_SAVE_FLAG(1374))
            EVT_ELSE
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 0, 54, 17, EVT_SAVE_FLAG(1374))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(5), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80242044)))
    EVT_RETURN
    EVT_END
};

EvtSource N(802424F4) = {
    EVT_IF_NE(EVT_AREA_VAR(3), 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT_FRAMES(10)
        EVT_IF_LT(EVT_AREA_VAR(3), 5)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006E))
            EVT_CALL(GetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
            EVT_CALL(PlayerMoveTo, 410, EVT_VAR(3), 10)
            EVT_ADD(EVT_AREA_VAR(3), 1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_2, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006F))
            EVT_SET(EVT_AREA_VAR(3), 0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

const char N(flo_25_name_hack)[];

EvtSource N(tree1_Callback) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(EVT_SAVE_VAR(0), 47)
        EVT_CALL(NpcFacePlayer, 0, 1)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_4, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0067))
        EVT_IF_EQ(EVT_SAVE_VAR(0), 46)
            EVT_IF_EQ(EVT_SAVE_FLAG(1379), 1)
                EVT_CALL(UseSettingsFrom, 0, -250, 0, 0)
                EVT_CALL(SetPanTarget, 0, -250, 0, 0)
                EVT_CALL(SetCamDistance, 0, 350)
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_EXEC_WAIT(N(80241DBC))
                EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(EVT_SAVE_FLAG(1374), 0)
            EVT_CALL(NpcFacePlayer, 0, 1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_4, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0067))
        EVT_ELSE
            EVT_ADD(EVT_AREA_VAR(2), 1)
            EVT_SWITCH(EVT_AREA_VAR(2))
                EVT_CASE_LT(2)
                    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_3, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006B))
                EVT_CASE_LT(5)
                    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_3, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006C))
                EVT_CASE_GE(5)
                    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_posie_Palette_00_Anim_3, NPC_ANIM_posie_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x006D))
                    EVT_SET(EVT_AREA_VAR(3), 1)
                    EVT_CALL(GotoMap, EVT_PTR(N(flo_25_name_hack)), 1)
                    EVT_WAIT_FRAMES(100)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(tree1_Leaves) = {
    .count = 3,
    .models = { 19, 20, 21 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 18 }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .callback = &N(tree1_Callback),
};

Vec4f N(triggerCoord_802428B4) = { -309.0f, 0.0f, 31.0f, 0.0f };

EvtSource N(802428C4) = {
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 4, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_802428B4)), 1, 0)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024291C) = {
    .id = NPC_POSIE,
    .settings = &N(npcSettings_80241220),
    .pos = { -260.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80242428),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
        NPC_ANIM_posie_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DE),
};

NpcGroupList N(npcGroupList_80242B0C) = {
    NPC_GROUP(N(npcGroup_8024291C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_8024061C_CAC80C)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241BB0_CADDA0) == NULL) {
        N(D_80241BB0_CADDA0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241BB0_CADDA0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241BB0_CADDA0)[i];
        }
        heap_free(N(D_80241BB0_CADDA0));
        N(D_80241BB0_CADDA0) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

const char N(flo_25_name_hack)[] = "flo_25";
