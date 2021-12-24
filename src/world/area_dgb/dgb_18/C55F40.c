#include "dgb_18.h"
#include "message_ids.h"
#include "sprite/npc/world_bombette.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kooper.h"
#include "sprite/npc/world_parakarry.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/yakkey.h"

enum {
    NPC_WORLD_TUBBA,
    NPC_YAKKEY,
};

EntryList N(entryList) = {
    { -120.0f, 0.0f, 180.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_18_tattle },
};

EvtSource N(802412C0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1358)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(exitDoubleDoor_80241360) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 17)
    EVT_SET(EVT_VAR(2), 8)
    EVT_SET(EVT_VAR(3), 10)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 6)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterDoubleDoor_80241414) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 8)
            EVT_SET(EVT_VAR(3), 10)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802436B4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802412C0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80241360), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_EXEC(N(enterDoubleDoor_80241414))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1578)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80241580) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .unk_10 = { .f = 90.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.9f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 170.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 1,
};

EvtSource N(802415B0) = {
    EVT_CALL(N(func_80240B94_C56AD4), EVT_PTR(N(npcAISettings_80241580)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802415D0) = {
    .height = 90,
    .radius = 65,
    .ai = &N(802415B0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_802415FC) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80241628) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtSource N(idle_80241654) = {
    EVT_LABEL(10)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_IF_LT(EVT_VAR(0), 700)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_GT(EVT_VAR(2), 185)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_LOOP(3)
        EVT_CALL(SetPlayerAnimation, ANIM_8001E)
        EVT_CALL(PlaySoundAt, SOUND_20F6, 0, 382, 0, 218)
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_WAIT_FRAMES(10)
    EVT_END_LOOP
    EVT_LOOP(2)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT_FRAMES(10)
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, 0, -40, 0, 180)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetPanTarget, 0, -40, 0, 180)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetPlayerPos, 740, 0, 180)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 765, 0, 180)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_8000C)
    EVT_CALL(PlaySoundAtCollider, 17, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 8, EVT_VAR(0), 0, -1, 0)
        EVT_CALL(RotateModel, 10, EVT_VAR(0), 0, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.3))
            EVT_WAIT_FRAMES(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_9)
    EVT_CALL(SetNpcPos, NPC_SELF, -210, 0, 180)
    EVT_CALL(NpcMoveTo, NPC_SELF, -60, 180, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 8, EVT_VAR(0), 0, -1, 0)
            EVT_CALL(RotateModel, 10, EVT_VAR(0), 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 17, 456, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 5, MESSAGE_ID(0x0E, 0x00F4))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_9)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.3))
            EVT_WAIT_FRAMES(9)
            EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.15))
            EVT_WAIT_FRAMES(12)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FIXED(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 45, 215, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 140, 245, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 615, 245, 0)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(15)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 5, MESSAGE_ID(0x0E, 0x00F5))
    EVT_WAIT_FRAMES(20)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_14)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_15)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_16)
        EVT_WAIT_FRAMES(5)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(0.7))
    EVT_CALL(NpcJump0, NPC_SELF, 600, 50, 115, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.3))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_5)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.2), EVT_FIXED(1.25))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.35), EVT_FIXED(1.15), EVT_FIXED(1.25))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.45), EVT_FIXED(1.05), EVT_FIXED(1.25))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.35), EVT_FIXED(1.15), EVT_FIXED(1.25))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.2), EVT_FIXED(1.25))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(0.5))
        EVT_CALL(NpcJump0, NPC_SELF, EVT_VAR(3), 30, EVT_VAR(5), 23)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(2)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 50, 18, 1)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CDE68, -1, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -90, 18, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, EVT_VAR(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FIXED(0.4))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(5)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(func_802CDE68, -1, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_24)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
    EVT_WAIT_FRAMES(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
            EVT_CALL(RandInt, 10, EVT_VAR(1))
            EVT_ADD(EVT_VAR(1), 15)
            EVT_CALL(ShowSleepBubble, 0, 0, 0, 2, 628, 121, 127, EVT_VAR(1), EVT_VAR(0))
            EVT_WAIT_FRAMES(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
            EVT_CALL(RandInt, 10, EVT_VAR(1))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_CALL(func_802D8248, EVT_VAR(0), EVT_VAR(1))
            EVT_WAIT_FRAMES(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(EVT_SAVE_VAR(0), -30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242494) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, 600, 50, 115)
    EVT_CALL(func_802CDE68, -1, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_24)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
    EVT_WAIT_FRAMES(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
            EVT_CALL(RandInt, 10, EVT_VAR(1))
            EVT_ADD(EVT_VAR(1), 15)
            EVT_CALL(ShowSleepBubble, 0, 0, 0, 2, 628, 121, 127, EVT_VAR(1), EVT_VAR(0))
            EVT_WAIT_FRAMES(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
            EVT_CALL(RandInt, 10, EVT_VAR(1))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_CALL(func_802D8248, EVT_VAR(0), EVT_VAR(1))
            EVT_WAIT_FRAMES(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(npcAI_802426B0) = {
    EVT_SET_GROUP(11)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
    EVT_CALL(ShowSleepBubble, 0, 0, 50, 2, 552, 111, 128, 30, EVT_VAR(0))
    EVT_WAIT_FRAMES(360)
    EVT_CALL(func_802D8248, EVT_VAR(0), 20)
    EVT_CALL(SetNpcVar, -1, 1, 2)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2F1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_19)
    EVT_WAIT_FRAMES(30)
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_SELF, 650, 0, 250, 25)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_1A)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_1B)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_1C)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(BindNpcAI, 0, EVT_PTR(N(npcAI_80242834)))
    EVT_RETURN
    EVT_END
};

EvtSource N(npcAI_80242834) = {
    EVT_SET_GROUP(11)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_tubba_Palette_00_Anim_D)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(2.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(func_80240B94_C56AD4), EVT_PTR(N(npcAISettings_80241580)))
    EVT_RETURN
    EVT_END
};

const char N(dgb_01_name_hack)[];

EvtSource N(defeat_802428E8) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_01_name_hack)), 6)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

const char N(pad_XXX)[] = { 0, 0 };

EvtSource N(init_80242924) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802428E8)))
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-30)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80241654)))
        EVT_CASE_LT(-29)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242494)))
        EVT_CASE_LT(-28)
            EVT_CALL(SetNpcPos, NPC_SELF, 245, 0, 250)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80242834)))
        EVT_CASE_LT(-26)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80242A24) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 845, 0, 140)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(0.8))
    EVT_CALL(NpcJump1, NPC_SELF, 845, 35, 145, 15)
    EVT_CALL(PlayerFaceNpc, -1, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPosB, 0, 800, 245)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E, 0x00F6))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E, 0x00F7))
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00F8))
    EVT_ELSE
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00F9))
    EVT_END_IF
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(UseSettingsFrom, 0, 740, EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(SetCamPosB, 0, 800, 245)
    EVT_CALL(SetPanTarget, 0, 740, EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_THREAD
        EVT_SET(EVT_MAP_FLAG(0), 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 517, MESSAGE_ID(0x0E, 0x00FA))
        EVT_SET(EVT_MAP_FLAG(0), 1)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LOOP(0)
        EVT_CALL(SetCamDistance, 0, EVT_FIXED(550.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_CALL(SetPanTarget, 0, 740, EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetCamDistance, 0, EVT_FIXED(600.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_CALL(SetPanTarget, 0, 740, EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_MAP_FLAG(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
    EVT_CALL(SetNpcVar, 0, 1, 1)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_tubba_Palette_00_Anim_25)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcVar, 0, 1, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(RandInt, 40, EVT_VAR(0))
            EVT_CALL(RandInt, 40, EVT_VAR(1))
            EVT_ADD(EVT_VAR(0), 537)
            EVT_ADD(EVT_VAR(1), 110)
            EVT_CALL(PlayEffect, 0x27, 2, EVT_VAR(0), EVT_VAR(1), 128, EVT_FIXED(0.3), 24, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_tubba_Palette_00_Anim_5)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_tubba_Palette_00_Anim_13, NPC_ANIM_world_tubba_Palette_00_Anim_5, 5, MESSAGE_ID(0x0E, 0x00FB))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk, NPC_ANIM_world_goombario_normal_idle, 0, MESSAGE_ID(0x0E, 0x00FC))
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_kooper_normal_talk, NPC_ANIM_world_kooper_normal_idle, 0, MESSAGE_ID(0x0E, 0x00FD))
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bombette_normal_idle_fast, NPC_ANIM_world_bombette_normal_idle, 0, MESSAGE_ID(0x0E, 0x00FE))
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00FF))
        EVT_CASE_EQ(9)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x0100))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(BindNpcAI, 0, EVT_PTR(N(npcAI_802426B0)))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_SUB(EVT_VAR(1), 10)
    EVT_CALL(NpcJump0, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(EVT_SAVE_VAR(0), -29)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024329C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242A24)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802432D4) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802415FC),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_80242924),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 5, 0, 0, 240, 175, 0, 240, 350, 0, 240, 525, 0, 240, 700, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 300, 0, 240, 1000, 250, 1, 1 },
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_A,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_19,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
    },
};

StaticNpc N(npcGroup_802434C4) = {
    .id = NPC_YAKKEY,
    .settings = &N(npcSettings_80241628),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024329C),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_802436B4) = {
    NPC_GROUP(N(npcGroup_802432D4), BATTLE_ID(15, 4, 0, 0)),
    NPC_GROUP(N(npcGroup_802434C4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_36D8)[] = {
    0x00000000, 0x00000000,
};

s32** N(D_802436E0_C59620) = NULL; // StashVars.inc.c data

EvtSource N(802436E4) = {
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 2)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ShowGotItem, EVT_VAR(0), 0, 0)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(8024374C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_EXEC_WAIT(N(802436E4))
    EVT_END_IF
    EVT_SWITCH(EVT_VAR(11))
        EVT_CASE_EQ(0)
            EVT_CALL(AddItem, EVT_VAR(10), EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_CALL(AddKeyItem, EVT_VAR(10))
        EVT_CASE_EQ(2)
            EVT_CALL(AddBadge, EVT_VAR(10), EVT_VAR(0))
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024382C) = {
    EVT_SET(EVT_SAVE_FLAG(1071), 1)
    EVT_CALL(AddKeyItem, ITEM_MYSTICAL_KEY)
    EVT_CALL(SetNpcVar, 1, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAE30, 845, 0, 145, -35, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignFlag, EVT_SAVE_FLAG(1071))
    EVT_CALL(AssignScript, EVT_PTR(N(8024382C)))
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_C56AD4)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc1.inc.c"

ApiStatus N(func_80240EBC_C56DFC)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(0);
    f32 posX, posZ;

    if (isInitialCall) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        npc->moveSpeed = 3.7f;
        npc->yaw = atan2(posX, posZ, playerStatus->position.x, playerStatus->position.z);
        script->functionTemp[1] = 0;
        npc->duration = 15;
    }

    if (script->functionTemp[1] == 0) {
        if (npc->duration == 0) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            npc->duration = 15;
        }
        npc->duration--;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    return ApiStatus_BLOCK;
}

const char N(dgb_01_name_hack)[] = "dgb_01";
