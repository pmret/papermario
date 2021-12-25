#include "flo_03.h"
#include "message_ids.h"
#include "sprite/npc/dayzee.h"
#include "sprite/npc/monty_mole.h"
#include "sprite/npc/petunia.h"

enum {
    NPC_PETUNIA,
    NPC_DAYZEE,
    NPC_MONTY_MOLE0,
    NPC_MONTY_MOLE1,
    NPC_MONTY_MOLE2,
    NPC_MONTY_MOLE3,
};

EntryList N(entryList) = {
    { -325.0f, 0.0f, 0.0f,  90.0f },
    {  325.0f, 0.0f, 0.0f, 270.0f },
    { -325.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_03_tattle },
};

EvtSource N(802406A0) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 2)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(EVT_SAVE_VAR(0))
            EVT_CASE_LE(44)
                EVT_IF_EQ(EVT_SAVE_FLAG(1411), 0)
                    EVT_CALL(SetMusicTrack, 0, SONG_MONTY_MOLE_ASSAULT, 0, 8)
                EVT_ELSE
                    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
                EVT_END_IF
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(802407C0) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), 44)
        EVT_IF_EQ(EVT_SAVE_FLAG(1411), 1)
            EVT_CALL(PushSong, 137, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80240814) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), 44)
        EVT_IF_EQ(EVT_SAVE_FLAG(1411), 1)
            EVT_CALL(FadeOutMusic, 0, 250)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PopSong)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80240880) = {
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

EvtSource N(exitWalk_80240B2C) = EXIT_WALK_SCRIPT(60,  0, "flo_09",  1);

EvtSource N(exitWalk_80240B88) = EXIT_WALK_SCRIPT(60,  1, "flo_22",  0);

EvtSource N(80240BE4) = {
    EVT_BIND_TRIGGER(N(exitWalk_80240B2C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80240B88), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
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
    EVT_SET(EVT_AREA_FLAG(27), 0)
    EVT_SET(EVT_AREA_FLAG(28), 0)
    EVT_SET(EVT_AREA_VAR(1), 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024442C)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC_WAIT(N(80241EF4))
    EVT_EXEC(N(80244E54))
    EVT_EXEC(N(80244ED0))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000006)
    EVT_SET(EVT_VAR(0), -145)
    EVT_SET(EVT_VAR(1), -335)
    EVT_SET(EVT_VAR(2), 182)
    EVT_SET(EVT_VAR(3), -180)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80240880))
    EVT_SET(EVT_VAR(0), 200)
    EVT_SET(EVT_VAR(1), -170)
    EVT_SET(EVT_VAR(2), 310)
    EVT_SET(EVT_VAR(3), 150)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80240880))
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 2)
        EVT_EXEC(N(80240FFC))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
        EVT_SET(EVT_VAR(0), EVT_PTR(N(80240BE4)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_EXEC_WAIT(N(802406A0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CA72A0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_EA4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240EB0) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80240EDC) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

s32** N(D_80240F08_CA81A8) = NULL;

EvtSource N(80240F0C) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(80240F3C) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80240F6C)[] = {
    0xFFFFFF9C, 0x00000000, 0x000000D2, 0xFFFFFF60, 0x00000000, 0x0000011D, 0xFFFFFFDD, 0x00000000,
    0x00000131,
};

s32 N(intTable_80240F90)[] = {
    0xFFFFFF42, 0x00000000, 0x00000050, 0xFFFFFF7E, 0x00000000, 0x00000000, 0xFFFFFFBA, 0x00000000,
    0xFFFFFFC4,
};

s32 N(intTable_80240FB4)[] = {
    0x0000004B, 0x00000000, 0xFFFFFFF1, 0x00000023, 0x00000000, 0xFFFFFF9C, 0x00000082, 0x00000000,
    0x00000000,
};

s32 N(intTable_80240FD8)[] = {
    0x00000073, 0x00000000, 0x000000B4, 0x00000055, 0x00000000, 0x00000122, 0x00000091, 0x00000000,
    0x0000008C,
};

EvtSource N(80240FFC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcYaw, 0, 90)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-9.5))
    EVT_CALL(SetCamPosA, 0, -27, 0)
    EVT_CALL(SetCamPosB, 0, 0, -50)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00C8))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_petunia_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_18"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(npcAI_8024119C) = {
    EVT_CALL(N(func_80240158_CA73F8))
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802411B8) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_SAVE_FLAG(1366), 1)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8024122C) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), EVT_VAR(3))
    EVT_DIV(EVT_VAR(0), 2)
    EVT_CALL(SetCamProperties, 0, EVT_VAR(4), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 300, EVT_FIXED(20.0), EVT_FIXED(-9.5))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802412BC) = {
    EVT_EXEC_WAIT(N(802407C0))
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_SET(EVT_MAP_VAR(14), 1)
            EVT_SET(EVT_VAR(4), EVT_FIXED(3.5))
            EVT_EXEC_WAIT(N(8024122C))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0050))
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_6)
            EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0051))
            EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_12)
            EVT_CALL(SetNpcYaw, 2, 270)
            EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-8.0))
            EVT_CALL(SetCamDistance, 0, 200)
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(PlaySoundAtNpc, 2, SOUND_MOLE_SURFACE, 0)
            EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_16)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtNpc, 2, 0x263, 0)
            EVT_CALL(ShowEmote, 2, EMOTE_QUESTION, -45, 30, 1, 0, 0, 0, 0)
            EVT_CALL(GetNpcPos, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0052))
            EVT_CALL(SetNpcYaw, 3, 90)
            EVT_CALL(SetNpcPos, 3, 0, -1000, 0)
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 200)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-8.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_0)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(PlaySoundAtNpc, 3, SOUND_MOLE_SURFACE, 0)
            EVT_CALL(SetNpcPos, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_10)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0053))
            EVT_CALL(SetNpcYaw, 4, 270)
            EVT_CALL(GetNpcPos, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 200)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-8.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_monty_mole_Palette_01_Anim_14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0054))
            EVT_CALL(SetNpcYaw, 5, 270)
            EVT_CALL(GetNpcPos, 5, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 200)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-9.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_6)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_7)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_8)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0055))
            EVT_CALL(SetNpcPos, 1, -233, 0, -217)
            EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 300)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-9.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_dayzee_Palette_00_Anim_D)
            EVT_CALL(PlaySoundAtNpc, 1, SOUND_262, 0)
            EVT_CALL(ShowEmote, 1, EMOTE_EXCLAMATION, 45, 30, 1, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0056))
            EVT_SET(EVT_VAR(4), EVT_FIXED(90.0))
            EVT_EXEC_WAIT(N(8024122C))
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0057))
            EVT_CALL(SetEnemyFlagBits, 1, 1, 0)
            EVT_CALL(SetEnemyFlagBits, 2, 1, 0)
            EVT_CALL(SetEnemyFlagBits, 3, 1, 0)
            EVT_CALL(SetEnemyFlagBits, 4, 1, 0)
            EVT_CALL(SetEnemyFlagBits, 5, 1, 0)
            EVT_CALL(BindNpcAI, 1, EVT_PTR(N(npcAI_8024119C)))
            EVT_SET(EVT_MAP_VAR(14), 0)
            EVT_SET(EVT_MAP_VAR(15), 60)
            EVT_SET(EVT_SAVE_VAR(0), 44)
        EVT_CASE_EQ(44)
            EVT_IF_EQ(EVT_SAVE_FLAG(1411), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0, MESSAGE_ID(0x11, 0x0058))
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET(EVT_VAR(4), EVT_FIXED(3.5))
                EVT_EXEC_WAIT(N(8024122C))
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_8, NPC_ANIM_petunia_Palette_00_Anim_3, 0, MESSAGE_ID(0x11, 0x0059))
                EVT_CALL(EndSpeech, -1, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_4)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_1)
                EVT_SET(EVT_VAR(0), 88)
                EVT_SET(EVT_VAR(1), 1)
                EVT_EXEC_WAIT(N(80240F0C))
                EVT_CALL(AddKeyItem, ITEM_MAGICAL_BEAN)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x005A))
                EVT_CALL(EndSpeech, -1, NPC_ANIM_petunia_Palette_00_Anim_7, NPC_ANIM_petunia_Palette_00_Anim_6, 0)
                EVT_SET(EVT_SAVE_VAR(0), 45)
            EVT_END_IF
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x005B))
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x005C))
        EVT_CASE_DEFAULT
            EVT_IF_EQ(EVT_AREA_VAR(1), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x005D))
                EVT_SET(EVT_AREA_VAR(1), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_petunia_Palette_00_Anim_2, NPC_ANIM_petunia_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x005E))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ResetCam, 0, EVT_FIXED(8.0))
    EVT_EXEC_WAIT(N(80240814))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80241DA4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802412BC)))
    EVT_IF_EQ(EVT_SAVE_FLAG(1411), 0)
        EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_petunia_Palette_00_Anim_6)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_petunia_Palette_00_Anim_1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80241E10) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802411B8)))
    EVT_CALL(EnableNpcShadow, 1, FALSE)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(EVT_SAVE_FLAG(1366), 0)
                EVT_CALL(SetEnemyFlagBits, 1, 1, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_8024119C)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80241EF4) = {
    EVT_SET(EVT_MAP_VAR(14), 0)
    EVT_SET(EVT_MAP_VAR(10), 0)
    EVT_SET(EVT_MAP_VAR(11), 0)
    EVT_SET(EVT_MAP_VAR(12), 0)
    EVT_SET(EVT_MAP_VAR(13), 0)
    EVT_SET(EVT_MAP_VAR(15), 100)
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_80241F64) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetSelfNpcID, EVT_VAR(0))
            EVT_SWITCH(EVT_VAR(0))
                EVT_CASE_EQ(2)
                    EVT_SET(EVT_SAVE_FLAG(1367), 1)
                EVT_CASE_EQ(3)
                    EVT_SET(EVT_SAVE_FLAG(1368), 1)
                EVT_CASE_EQ(4)
                    EVT_SET(EVT_SAVE_FLAG(1369), 1)
                EVT_CASE_EQ(5)
                    EVT_SET(EVT_SAVE_FLAG(1370), 1)
            EVT_END_SWITCH
            EVT_SET(EVT_VAR(0), 0)
            EVT_ADD(EVT_VAR(0), EVT_SAVE_FLAG(1367))
            EVT_ADD(EVT_VAR(0), EVT_SAVE_FLAG(1368))
            EVT_ADD(EVT_VAR(0), EVT_SAVE_FLAG(1369))
            EVT_ADD(EVT_VAR(0), EVT_SAVE_FLAG(1370))
            EVT_IF_NE(EVT_VAR(0), 4)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_petunia_Palette_00_Anim_6)
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_petunia_Palette_00_Anim_1)
                EVT_SET(EVT_SAVE_FLAG(1411), 1)
                EVT_EXEC_WAIT(N(802406A0))
            EVT_END_IF
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_monty_mole_Palette_01_Anim_1)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_monty_mole_Palette_01_Anim_1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(hit_80242138) = {
    EVT_IF_EQ(EVT_SAVE_VAR(0), 44)
        EVT_CALL(GetOwnerEncounterTrigger, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_monty_mole_Palette_01_Anim_5)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8024219C) = {
    EVT_LOOP(0)
        EVT_IF_EQ(EVT_MAP_VAR(10), 0)
            EVT_IF_EQ(EVT_AREA_FLAG(23), 1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(EVT_VAR(3), 1)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(IsPlayerWithin, EVT_VAR(0), EVT_VAR(2), EVT_MAP_VAR(15), EVT_VAR(3))
        EVT_END_IF
        EVT_CALL(GetCurrentPartner, EVT_VAR(9))
        EVT_IF_EQ(EVT_VAR(9), 9)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_MAP_VAR(14), 1)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_VAR(3), 1)
            EVT_IF_EQ(EVT_AREA_FLAG(23), 0)
                EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_CALL(NpcFacePlayer, 2, 1)
                EVT_WAIT_FRAMES(1)
                EVT_SET(EVT_AREA_FLAG(23), 1)
                EVT_IF_NE(EVT_MAP_VAR(10), 0)
                    EVT_IF_LT(EVT_SAVE_VAR(0), 44)
                        EVT_SET(EVT_VAR(1), 4)
                    EVT_ELSE
                        EVT_SET(EVT_VAR(1), 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, 2, SOUND_262, 0)
                    EVT_CALL(ShowEmote, 2, EMOTE_EXCLAMATION, 0, EVT_VAR(1), 1, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(EVT_VAR(1))
                    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), TRUE)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, 2, SOUND_MOLE_DIG, 0)
                EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_11)
                EVT_WAIT_FRAMES(20)
                EVT_IF_EQ(EVT_SAVE_FLAG(1367), 0)
                    EVT_CALL(SetNpcPos, 2, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(EVT_AREA_FLAG(23), 1)
                EVT_IF_EQ(EVT_SAVE_FLAG(1367), 0)
                    EVT_CALL(RandInt, 2, EVT_VAR(0))
                    EVT_ADD(EVT_VAR(0), 1)
                    EVT_USE_BUF(EVT_PTR(N(intTable_80240F6C)))
                    EVT_LOOP(EVT_VAR(0))
                        EVT_BUF_READ3(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, 2, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_SET(EVT_AREA_FLAG(23), 0)
                EVT_CALL(NpcFacePlayer, 2, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(PlaySoundAtNpc, 2, SOUND_MOLE_SURFACE, 0)
                EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), FALSE)
                EVT_CALL(RandInt, 30, EVT_VAR(0))
                EVT_ADD(EVT_VAR(0), 60)
                EVT_SET(EVT_MAP_VAR(10), EVT_VAR(0))
            EVT_ELSE
                EVT_IF_GT(EVT_MAP_VAR(10), 0)
                    EVT_SUB(EVT_MAP_VAR(10), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242618) = {
    EVT_LOOP(0)
        EVT_IF_EQ(EVT_MAP_VAR(11), 0)
            EVT_IF_EQ(EVT_AREA_FLAG(24), 1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(EVT_VAR(3), 1)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(IsPlayerWithin, EVT_VAR(0), EVT_VAR(2), EVT_MAP_VAR(15), EVT_VAR(3))
        EVT_END_IF
        EVT_CALL(GetCurrentPartner, EVT_VAR(9))
        EVT_IF_EQ(EVT_VAR(9), 9)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_MAP_VAR(14), 1)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_VAR(3), 1)
            EVT_IF_EQ(EVT_AREA_FLAG(24), 0)
                EVT_CALL(SetNpcFlagBits, 3, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_CALL(NpcFacePlayer, 3, 1)
                EVT_WAIT_FRAMES(1)
                EVT_SET(EVT_AREA_FLAG(24), 1)
                EVT_IF_NE(EVT_MAP_VAR(11), 0)
                    EVT_IF_LT(EVT_SAVE_VAR(0), 44)
                        EVT_SET(EVT_VAR(1), 4)
                    EVT_ELSE
                        EVT_SET(EVT_VAR(1), 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, 3, SOUND_262, 0)
                    EVT_CALL(ShowEmote, 3, EMOTE_EXCLAMATION, 0, EVT_VAR(1), 1, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(EVT_VAR(1))
                    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), TRUE)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, 3, SOUND_MOLE_DIG, 0)
                EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_11)
                EVT_WAIT_FRAMES(20)
                EVT_IF_EQ(EVT_SAVE_FLAG(1368), 0)
                    EVT_CALL(SetNpcPos, 3, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(EVT_AREA_FLAG(24), 1)
                EVT_IF_EQ(EVT_SAVE_FLAG(1368), 0)
                    EVT_CALL(RandInt, 2, EVT_VAR(0))
                    EVT_ADD(EVT_VAR(0), 1)
                    EVT_USE_BUF(EVT_PTR(N(intTable_80240F90)))
                    EVT_LOOP(EVT_VAR(0))
                        EVT_BUF_READ3(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, 3, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, 3, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_SET(EVT_AREA_FLAG(24), 0)
                EVT_CALL(NpcFacePlayer, 3, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(PlaySoundAtNpc, 3, SOUND_MOLE_SURFACE, 0)
                EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), FALSE)
                EVT_CALL(RandInt, 35, EVT_VAR(0))
                EVT_ADD(EVT_VAR(0), 55)
                EVT_SET(EVT_MAP_VAR(11), EVT_VAR(0))
            EVT_ELSE
                EVT_IF_GT(EVT_MAP_VAR(11), 0)
                    EVT_SUB(EVT_MAP_VAR(11), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242A94) = {
    EVT_LOOP(0)
        EVT_IF_EQ(EVT_MAP_VAR(12), 0)
            EVT_IF_EQ(EVT_AREA_FLAG(25), 1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(EVT_VAR(3), 1)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(IsPlayerWithin, EVT_VAR(0), EVT_VAR(2), EVT_MAP_VAR(15), EVT_VAR(3))
        EVT_END_IF
        EVT_CALL(GetCurrentPartner, EVT_VAR(9))
        EVT_IF_EQ(EVT_VAR(9), 9)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_MAP_VAR(14), 1)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_VAR(3), 1)
            EVT_IF_EQ(EVT_AREA_FLAG(25), 0)
                EVT_CALL(SetNpcFlagBits, 4, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_CALL(NpcFacePlayer, 4, 1)
                EVT_WAIT_FRAMES(1)
                EVT_SET(EVT_AREA_FLAG(25), 1)
                EVT_IF_NE(EVT_MAP_VAR(12), 0)
                    EVT_IF_LT(EVT_SAVE_VAR(0), 44)
                        EVT_SET(EVT_VAR(1), 4)
                    EVT_ELSE
                        EVT_SET(EVT_VAR(1), 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, 4, SOUND_262, 0)
                    EVT_CALL(ShowEmote, 4, EMOTE_EXCLAMATION, 0, EVT_VAR(1), 1, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(EVT_VAR(1))
                    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), TRUE)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, 4, SOUND_MOLE_DIG, 0)
                EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_monty_mole_Palette_01_Anim_11)
                EVT_WAIT_FRAMES(20)
                EVT_IF_EQ(EVT_SAVE_FLAG(1369), 0)
                    EVT_CALL(SetNpcPos, 4, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(EVT_AREA_FLAG(25), 1)
                EVT_IF_EQ(EVT_SAVE_FLAG(1369), 0)
                    EVT_CALL(RandInt, 2, EVT_VAR(0))
                    EVT_ADD(EVT_VAR(0), 1)
                    EVT_USE_BUF(EVT_PTR(N(intTable_80240FB4)))
                    EVT_LOOP(EVT_VAR(0))
                        EVT_BUF_READ3(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, 4, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, 4, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_SET(EVT_AREA_FLAG(25), 0)
                EVT_CALL(NpcFacePlayer, 4, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(PlaySoundAtNpc, 4, SOUND_MOLE_SURFACE, 0)
                EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), FALSE)
                EVT_CALL(RandInt, 40, EVT_VAR(0))
                EVT_ADD(EVT_VAR(0), 50)
                EVT_SET(EVT_MAP_VAR(12), EVT_VAR(0))
            EVT_ELSE
                EVT_IF_GT(EVT_MAP_VAR(12), 0)
                    EVT_SUB(EVT_MAP_VAR(12), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242F10) = {
    EVT_LOOP(0)
        EVT_IF_EQ(EVT_MAP_VAR(13), 0)
            EVT_IF_EQ(EVT_AREA_FLAG(26), 1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(EVT_VAR(3), 1)
        EVT_ELSE
            EVT_LABEL(0)
            EVT_CALL(GetNpcPos, 5, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(IsPlayerWithin, EVT_VAR(0), EVT_VAR(2), EVT_MAP_VAR(15), EVT_VAR(3))
        EVT_END_IF
        EVT_CALL(GetCurrentPartner, EVT_VAR(9))
        EVT_IF_EQ(EVT_VAR(9), 9)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_MAP_VAR(14), 1)
            EVT_SET(EVT_VAR(3), 0)
        EVT_END_IF
        EVT_IF_EQ(EVT_VAR(3), 1)
            EVT_IF_EQ(EVT_AREA_FLAG(26), 0)
                EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_CALL(NpcFacePlayer, 5, 1)
                EVT_WAIT_FRAMES(1)
                EVT_SET(EVT_AREA_FLAG(26), 1)
                EVT_IF_NE(EVT_MAP_VAR(13), 0)
                    EVT_IF_LT(EVT_SAVE_VAR(0), 44)
                        EVT_SET(EVT_VAR(1), 4)
                    EVT_ELSE
                        EVT_SET(EVT_VAR(1), 10)
                    EVT_END_IF
                    EVT_CALL(PlaySoundAtNpc, 5, SOUND_262, 0)
                    EVT_CALL(ShowEmote, 5, EMOTE_EXCLAMATION, 0, EVT_VAR(1), 1, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(EVT_VAR(1))
                    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), TRUE)
                EVT_END_IF
                EVT_CALL(PlaySoundAtNpc, 5, SOUND_MOLE_DIG, 0)
                EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_11)
                EVT_WAIT_FRAMES(20)
                EVT_IF_EQ(EVT_SAVE_FLAG(1370), 0)
                    EVT_CALL(SetNpcPos, 5, 0, -50, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(45)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(EVT_AREA_FLAG(26), 1)
                EVT_IF_EQ(EVT_SAVE_FLAG(1370), 0)
                    EVT_CALL(RandInt, 2, EVT_VAR(0))
                    EVT_ADD(EVT_VAR(0), 1)
                    EVT_USE_BUF(EVT_PTR(N(intTable_80240FD8)))
                    EVT_LOOP(EVT_VAR(0))
                        EVT_BUF_READ3(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                    EVT_END_LOOP
                    EVT_CALL(SetNpcPos, 5, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000)), TRUE)
                EVT_SET(EVT_AREA_FLAG(26), 0)
                EVT_CALL(NpcFacePlayer, 5, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(PlaySoundAtNpc, 5, SOUND_MOLE_SURFACE, 0)
                EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_10000000)), FALSE)
                EVT_CALL(RandInt, 45, EVT_VAR(0))
                EVT_ADD(EVT_VAR(0), 45)
                EVT_SET(EVT_MAP_VAR(13), EVT_VAR(0))
            EVT_ELSE
                EVT_IF_GT(EVT_MAP_VAR(13), 0)
                    EVT_SUB(EVT_MAP_VAR(13), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024338C) = {
    EVT_CALL(BindNpcHit, -1, EVT_PTR(N(hit_80242138)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80241F64)))
    EVT_CALL(EnableNpcShadow, 2, FALSE)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024219C)))
            EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_10)
        EVT_CASE_EQ(44)
            EVT_IF_EQ(EVT_SAVE_FLAG(1367), 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024219C)))
                EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_CALL(SetEnemyFlagBits, 2, 1, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802434CC) = {
    EVT_CALL(BindNpcHit, -1, EVT_PTR(N(hit_80242138)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80241F64)))
    EVT_CALL(EnableNpcShadow, 3, FALSE)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242618)))
            EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_10)
        EVT_CASE_EQ(44)
            EVT_IF_EQ(EVT_SAVE_FLAG(1368), 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242618)))
                EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_CALL(SetEnemyFlagBits, 3, 1, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, 3, 0, -1000, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, 3, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024360C) = {
    EVT_CALL(BindNpcHit, -1, EVT_PTR(N(hit_80242138)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80241F64)))
    EVT_CALL(EnableNpcShadow, 4, FALSE)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242A94)))
            EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_monty_mole_Palette_01_Anim_10)
        EVT_CASE_EQ(44)
            EVT_IF_EQ(EVT_SAVE_FLAG(1369), 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242A94)))
                EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_CALL(SetEnemyFlagBits, 4, 1, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, 4, 0, -1000, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, 4, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024374C) = {
    EVT_CALL(BindNpcHit, -1, EVT_PTR(N(hit_80242138)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80241F64)))
    EVT_CALL(EnableNpcShadow, 5, FALSE)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(44)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242F10)))
            EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_10)
        EVT_CASE_EQ(44)
            EVT_IF_EQ(EVT_SAVE_FLAG(1370), 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242F10)))
                EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_monty_mole_Palette_01_Anim_10)
                EVT_CALL(SetEnemyFlagBits, 5, 1, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, 5, 0, -1000, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcPos, 5, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024388C) = {
    .id = NPC_PETUNIA,
    .settings = &N(npcSettings_80240EDC),
    .pos = { -30.0f, 0.0f, 100.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241DA4),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
        NPC_ANIM_petunia_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DD),
};

StaticNpc N(npcGroup_80243A7C) = {
    .id = NPC_DAYZEE,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -233.0f, 0.0f, -217.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80241E10),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_2,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_6,
        NPC_ANIM_dayzee_Palette_00_Anim_7,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80243C6C) = {
    .id = NPC_MONTY_MOLE0,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -100.0f, 0.0f, 210.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024338C),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_2,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
    },
};

StaticNpc N(npcGroup_80243E5C) = {
    .id = NPC_MONTY_MOLE1,
    .settings = &N(npcSettings_80240EB0),
    .pos = { -130.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802434CC),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_2,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
    },
};

StaticNpc N(npcGroup_8024404C) = {
    .id = NPC_MONTY_MOLE2,
    .settings = &N(npcSettings_80240EB0),
    .pos = { 75.0f, 0.0f, 20.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024360C),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_2,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
    },
};

StaticNpc N(npcGroup_8024423C) = {
    .id = NPC_MONTY_MOLE3,
    .settings = &N(npcSettings_80240EB0),
    .pos = { 71.0f, 0.0f, 200.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024374C),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_2,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_3,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_1,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_5,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
        NPC_ANIM_monty_mole_Palette_01_Anim_0,
    },
};

NpcGroupList N(npcGroupList_8024442C) = {
    NPC_GROUP(N(npcGroup_8024388C), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243A7C), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_80243C6C), BATTLE_ID(25, 2, 0, 2)),
    NPC_GROUP(N(npcGroup_80243E5C), BATTLE_ID(25, 1, 0, 2)),
    NPC_GROUP(N(npcGroup_8024404C), BATTLE_ID(25, 3, 0, 2)),
    NPC_GROUP(N(npcGroup_8024423C), BATTLE_ID(25, 4, 0, 2)),
    {},
};

ApiStatus N(func_80240040_CA72E0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240F08_CA81A8) == NULL) {
        N(D_80240F08_CA81A8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240F08_CA81A8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240F08_CA81A8)[i];
        }
        heap_free(N(D_80240F08_CA81A8));
        N(D_80240F08_CA81A8) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

ApiStatus N(func_80240158_CA73F8)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 clamp = clamp_angle(atan2(-210.0f, -183.0f, gPlayerStatus.position.x, gPlayerStatus.position.z) + 180.0f);
    f32 sp10 = -210.0f;
    f32 sp14 = -183.0f;

    f32 temp_f20;
    f32 temp_f4_2;
    f64 temp_f4;
    f32 phi_f2;

    add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
    temp_f4 = dist2D(npc->pos.x, npc->pos.z, sp10, sp14);
    if (temp_f4 > 2.0) {
        temp_f20 = clamp_angle(atan2(-210.0f, -183.0f, npc->pos.x, npc->pos.z));
        temp_f4_2 = temp_f20 - clamp_angle(atan2(-210.0f, -183.0f, sp10, sp14));
        if (abs(temp_f4_2) >= 0x15) {
            phi_f2 = temp_f4_2;
            if (temp_f4_2 >= 180.0f) {
                phi_f2 = temp_f4_2 - 360.0f;
            }
            if (phi_f2 <= -180.0f) {
                phi_f2 += 360.0f;
            }
            if (temp_f4_2 == phi_f2) {
                sp10 = -210.0f;
                sp14 = -183.0f;
                if (temp_f4_2 >= 0.0f) {
                    clamp = clamp_angle(temp_f20 - 20.0f);
                } else {
                    clamp = clamp_angle(temp_f20 + 20.0f);
                }
                add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
            }
        }
        npc->currentAnim.w = enemy->animList[2];
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc_move_heading(npc, 2.0f, npc->yaw);
    } else if (temp_f4 > 0.2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[1];
    } else {
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[0];
    }
    return ApiStatus_BLOCK;
}

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 1,
    .models = { 23 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 22 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_RED_BERRY,
            .pos = { -256, 102, -169 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(27),
        },
        {
            .itemID = ITEM_RED_BERRY,
            .pos = { -156, 102, -169 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(28),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80244E44) = { -208.0f, 0.0f, -182.0f, 0.0f };

EvtSource N(80244E54) = {
    EVT_SET(EVT_AREA_FLAG(27), 0)
    EVT_SET(EVT_AREA_FLAG(28), 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 16, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80244E44)), 1, 0)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4ECC) = {
    0x00000000,
};

EvtSource N(80244ED0) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAB04, -175, 0, 150, 0, 8, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, EVT_SAVE_FLAG(1404))
    EVT_RETURN
    EVT_END
};
