#include "flo_13.h"
#include "message_ids.h"
#include "sprite/npc/lakilulu.h"
#include "sprite/npc/lakitu.h"
#include "sprite/npc/spiny.h"
#include "sprite/npc/world_lakilester.h"

enum {
    NPC_WORLD_LAKILESTER,
    NPC_LAKILULU0,
    NPC_LAKILULU1,
    NPC_LAKITU0,
    NPC_LAKITU1,
    NPC_SPINY0 = 50,
    NPC_SPINY1,
    NPC_SPINY2,
    NPC_SPINY3,
    NPC_SPINY4,
    NPC_SPINY5,
};

EntryList N(entryList) = {
    {  570.0f, 0.0f, 0.0f, 270.0f },
    { -570.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_13_tattle },
};

EvtScript N(802436D0) = {
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_LT(EVT_VAR(0), -500)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_LT(EVT_VAR(0), -500)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LABEL(10)
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_GT(EVT_VAR(0), -500)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802438B0) = {
    EVT_EXEC(N(802436D0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802438CC) = {
    EVT_CALL(SetMusicTrack, 0, SONG_NEW_PARTNER, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(802438F8) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3944)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80243950) = {
    EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_MEGA_SMASH, -61, 60, -85, 17, EVT_SAVE_FLAG(1385))
    EVT_CALL(MakeItemEntity, ITEM_SHOOTING_STAR, 128, 0, 157, 17, EVT_SAVE_FLAG(1386))
    EVT_IF_EQ(EVT_SAVE_FLAG(1385), 0)
        EVT_CALL(MakeEntity, 0x802BCF00, -160, 160, -90, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80243950)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3A3C) = {
    0x00000000,
};

EvtScript N(80243A40) = {
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

EvtScript N(exitWalk_80243CEC) = EXIT_WALK_SCRIPT(60,  0, "flo_14",  1);

EvtScript N(exitWalk_80243D48) = EXIT_WALK_SCRIPT(60,  1, "flo_15",  0);

EvtScript N(80243DA4) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243D48), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80243CEC), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80247984)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(ModifyColliderFlags, 3, 13, 0x00000006)
    EVT_SET(EVT_VAR(0), 274)
    EVT_SET(EVT_VAR(1), -137)
    EVT_SET(EVT_VAR(2), 583)
    EVT_SET(EVT_VAR(3), -64)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(EVT_VAR(0), 433)
    EVT_SET(EVT_VAR(1), 108)
    EVT_SET(EVT_VAR(2), 580)
    EVT_SET(EVT_VAR(3), 169)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(EVT_VAR(0), -460)
    EVT_SET(EVT_VAR(1), 90)
    EVT_SET(EVT_VAR(2), -125)
    EVT_SET(EVT_VAR(3), 130)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(EVT_VAR(0), -420)
    EVT_SET(EVT_VAR(1), -130)
    EVT_SET(EVT_VAR(2), -260)
    EVT_SET(EVT_VAR(3), -90)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(EVT_VAR(0), -220)
    EVT_SET(EVT_VAR(1), -137)
    EVT_SET(EVT_VAR(2), 0)
    EVT_SET(EVT_VAR(3), -50)
    EVT_SET(EVT_VAR(4), 160)
    EVT_EXEC(N(80243A40))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80243DA4)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802438B0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CC3810))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244100) = {
    .height = 32,
    .radius = 24,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 20,
};

f32 N(sixFloats)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80244144) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 60 },
    .unk_20 = 10,
    .chaseRadius = 80.0f,
    .unk_28 = { .f = 70.0f },
    .unk_2C = 1,
};

EvtScript N(npcAI_80244174) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 400)
    EVT_CALL(N(func_80241DB8_CC55C8), EVT_PTR(N(npcAISettings_80244144)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802441E4) = {
    .height = 28,
    .radius = 24,
    .ai = &N(npcAI_80244174),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 20,
};

NpcAISettings N(npcAISettings_80244210) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 3,
};

EvtScript N(npcAI_80244240) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(UnkNpcAIMainFunc6), EVT_PTR(N(npcAISettings_80244210)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802442B0) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetSelfVar, 10, 100)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(2)
            EVT_CALL(func_80045900, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024437C) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_80244240),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(802442B0),
    .level = 19,
};

Vec3f N(vectorList_802443A8)[] = {
    { -250.0, 130.0, 100.0 }, { -150.0, 90.0, 70.0 },
    { 50.0, 70.0, 10.0 }, { 200.0, 35.0, 30.0 },
    { 30.0, 10.0, 45.0 },
};

Vec3f N(vectorList_802443E4)[] = {
    { -285.0, 130.0, 45.0 }, { -185.0, 90.0, 25.0 },
    { 15.0, 70.0, 10.0 }, { 165.0, 35.0, 30.0 },
    { -5.0, 10.0, 45.0 },
};

Vec3f N(vectorList_80244420)[] = {
    { 10.0, 0.0, 45.0 }, { -90.0, 20.0, 45.0 },
    { -190.0, 60.0, 45.0 }, { -290.0, 140.0, 45.0 },
    { -390.0, 300.0, 45.0 },
};

EvtScript N(8024445C) = {
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(N(UnkFunc42))
    EVT_CALL(InterpNpcYaw, 0, EVT_VAR(10), 0)
    EVT_SET(EVT_VAR(0), EVT_VAR(3))
    EVT_SET(EVT_VAR(1), EVT_VAR(4))
    EVT_SET(EVT_VAR(2), EVT_VAR(5))
    EVT_CALL(GetAngleBetweenNPCs, -4, 0, EVT_VAR(10))
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(10), 0)
    EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244560) = {
    EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, 1, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(N(UnkFunc42))
    EVT_CALL(InterpNpcYaw, 1, EVT_VAR(10), 0)
    EVT_SET(EVT_VAR(0), EVT_VAR(3))
    EVT_SET(EVT_VAR(1), EVT_VAR(4))
    EVT_SET(EVT_VAR(2), EVT_VAR(5))
    EVT_CALL(GetAngleBetweenNPCs, -4, 1, EVT_VAR(10))
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(10), 0)
    EVT_IF_LT(EVT_SAVE_VAR(0), 51)
        EVT_CALL(GetAngleBetweenNPCs, 0, 1, EVT_VAR(11))
        EVT_CALL(InterpNpcYaw, 0, EVT_VAR(11), 0)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, 1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802446AC) = {
    EVT_SET(EVT_MAP_VAR(10), 0)
    EVT_LOOP(0)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(2)
        EVT_END_LOOP
        EVT_WAIT_FRAMES(1)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), -1)
            EVT_CALL(SetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), -1)
            EVT_CALL(SetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(2)
        EVT_END_LOOP
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_MAP_VAR(10), 1)
            EVT_SET(EVT_MAP_VAR(10), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80244888) = {
    EVT_EXEC(N(802446AC))
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_C)
    EVT_CALL(GetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_ADD(EVT_VAR(1), -5)
    EVT_ADD(EVT_VAR(2), 30)
    EVT_ADD(EVT_VAR(3), 2)
    EVT_CALL(SetNpcYaw, 2, 270)
    EVT_CALL(SetNpcPos, 2, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetPlayerAnimation, ANIM_1002B)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, 1, -1, -1, 512, MESSAGE_ID(0x11, 0x00A8))
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(EndSpeech, 1, -1, -1, 512)
    EVT_END_THREAD
    EVT_SET(EVT_MAP_VAR(10), 1)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_MAP_VAR(10), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_D)
    EVT_CALL(GetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_ADD(EVT_VAR(1), 5)
    EVT_ADD(EVT_VAR(2), 20)
    EVT_CALL(SetNpcJumpscale, 2, EVT_FIXED(0.0))
    EVT_CALL(NpcJump0, 2, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 7)
    EVT_ADD(EVT_VAR(1), -100)
    EVT_ADD(EVT_VAR(2), 10)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, 2, EVT_FIXED(1.5))
        EVT_CALL(NpcJump0, 2, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 15)
        EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FIXED(2.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, 225, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_FALL_BACK)
    EVT_SET(EVT_VAR(0), 90)
    EVT_LOOP(20)
        EVT_ADD(EVT_VAR(0), 144)
        EVT_IF_GT(EVT_VAR(0), 359)
            EVT_SUB(EVT_VAR(0), 360)
        EVT_END_IF
        EVT_CALL(InterpPlayerYaw, EVT_VAR(0), 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244BF8) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), 50)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 200, 20, 275)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, 0, -250, 120, 45)
    EVT_CALL(SetMusicTrack, 0, SONG_LAKILESTER_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x11, 0x00A0), 160, 40)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(SetPlayerAnimation, 65578)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_7)
    EVT_THREAD
        EVT_CALL(N(func_802434D4_CC6CE4))
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(8024445C), EVT_VAR(9))
    EVT_CALL(LoadPath, 80, EVT_PTR(N(vectorList_802443A8)), 5, 0)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 0, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
    EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(GetNpcPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 200)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.0), EVT_FIXED(-8.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, -75, 65, 10)
        EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00A1))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_7)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 1000)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-6.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(80245014) = {
    EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(AwaitPlayerLeave, EVT_VAR(0), EVT_VAR(2), 120)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), 0, EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(5.5), EVT_FIXED(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00B4))
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 1, 1)
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(10.0), EVT_FIXED(-8.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 130, -200)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_THREAD
        EVT_CALL(N(func_802433C0_CC6BD0), 55)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
    EVT_EXEC_GET_TID(N(80244560), EVT_VAR(9))
    EVT_CALL(LoadPath, 55, EVT_PTR(N(vectorList_80244420)), 5, 0)
    EVT_LABEL(20)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(EVT_VAR(0), 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
        EVT_CALL(GetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
        EVT_ADD(EVT_VAR(1), 20)
        EVT_ADD(EVT_VAR(2), 20)
        EVT_ADD(EVT_VAR(3), 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 30)
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00B5))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FIXED(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80245444) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_A, NPC_ANIM_world_lakilester_Palette_00_Anim_4, 0, MESSAGE_ID(0x11, 0x00A2))
    EVT_CALL(SetNpcPos, 1, -290, 120, 45)
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
        EVT_CALL(SetPlayerAnimation, 65578)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 5, MESSAGE_ID(0x11, 0x00A3))
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_7)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 500)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(5.5), EVT_FIXED(-6.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 130, -200)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 400)
        EVT_CALL(SetCamPosB, 0, 130, 60)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(1.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802433C0_CC6BD0), 80)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(80244560), EVT_VAR(9))
    EVT_CALL(LoadPath, 80, EVT_PTR(N(vectorList_802443E4)), 5, 0)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 1, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_9)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 20)
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(5.5), EVT_FIXED(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00A4))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 40)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_8, NPC_ANIM_lakilulu_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x00A5))
    EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 20)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_B, NPC_ANIM_world_lakilester_Palette_00_Anim_3, 0, MESSAGE_ID(0x11, 0x00A6))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
    EVT_CALL(EndSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 40)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(10.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_LABEL(10)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_A, NPC_ANIM_lakilulu_Palette_00_Anim_9, 0, MESSAGE_ID(0x11, 0x00A7))
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x0020))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_EXEC_WAIT(N(80244888))
        EVT_WAIT_FRAMES(10)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00A9))
        EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_1)
        EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 20)
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 250)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_B, NPC_ANIM_world_lakilester_Palette_00_Anim_3, 0, MESSAGE_ID(0x11, 0x00AA))
        EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
        EVT_CALL(EndSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 40)
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(5.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_B, NPC_ANIM_world_lakilester_Palette_00_Anim_3, 0, MESSAGE_ID(0x11, 0x00AB))
        EVT_WAIT_FRAMES(10)
        EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x0021))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_EQ(-1)
            EVT_CASE_EQ(0)
                EVT_CALL(ContinueSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00AC))
            EVT_CASE_EQ(1)
                EVT_CALL(ContinueSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00AD))
            EVT_CASE_EQ(2)
                EVT_CALL(ContinueSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00AE))
            EVT_CASE_EQ(3)
                EVT_CALL(ContinueSpeech, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00AF))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, 1, 90, 1)
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_9)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_A, NPC_ANIM_lakilulu_Palette_00_Anim_9, 5, MESSAGE_ID(0x11, 0x00B0))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00B1))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_A, NPC_ANIM_lakilulu_Palette_00_Anim_9, 5, MESSAGE_ID(0x11, 0x00B2))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00B3))
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_CALL(ResetCam, 0, EVT_FIXED(90.0))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetNpcSpeed, 0, EVT_FIXED(3.5))
    EVT_CALL(NpcMoveTo, 0, EVT_VAR(0), 60, 0)
    EVT_CALL(N(UnkFunc41), 0, 8)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(802438CC))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x0190), 160, 40)
    EVT_EXEC(N(802438F8))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(EVT_SAVE_VAR(0), 51)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC_WAIT(N(80245014))
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80246038) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_lakilester_Palette_00_Anim_4)
            EVT_CALL(SetCamType, 0, 6, 1)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(0), EVT_VAR(3))
            EVT_DIV(EVT_VAR(0), 2)
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamDistance, 0, 300)
            EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-7.5))
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_EXEC(N(80245444))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802461C0) = {
    EVT_IF_LE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0032))
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), 8)
            EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0034))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0032))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246280) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 51)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244BF8)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80246038)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802462D0) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), 58)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802461C0)))
        EVT_CALL(SetNpcCollisionSize, -1, 36, 28)
        EVT_IF_GE(EVT_SAVE_VAR(0), 53)
            EVT_CALL(SetNpcPos, NPC_SELF, -50, 180, -50)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80246370) = {
    EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_lakilulu_Palette_00_Anim_B)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802463B0) = {
    EVT_IF_EQ(EVT_SAVE_VAR(0), 50)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802463E8) = {
    EVT_IF_EQ(EVT_SAVE_VAR(0), 50)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_CALL(SetSelfVar, 13, 1)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246434) = {
    .id = NPC_WORLD_LAKILESTER,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
    .init = &N(init_80246280),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
};

StaticNpc N(npcGroup_80246624) = {
    .id = NPC_LAKILULU0,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802462D0),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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

StaticNpc N(npcGroup_80246814) = {
    .id = NPC_LAKILULU1,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80246370),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
};

StaticNpc N(npcGroup_80246A04) = {
    .id = NPC_LAKITU0,
    .settings = &N(npcSettings_802441E4),
    .pos = { 335.0f, 90.0f, 45.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802463B0),
    .yaw = 270,
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
    .movement = { 335, 90, 45, 30, 0, -32767, 0, 335, 90, 45, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_2,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246BF4) = {
    .id = NPC_LAKITU1,
    .settings = &N(npcSettings_802441E4),
    .pos = { -320.0f, 90.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_802463B0),
    .yaw = 90,
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
    .movement = { -320, 90, 0, 30, 0, -32767, 0, -320, 90, 0, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_2,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_4,
        NPC_ANIM_lakitu_Palette_00_Anim_3,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
        NPC_ANIM_lakitu_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246DE4) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80246FD4) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802471C4) = {
    .id = NPC_SPINY2,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802473B4) = {
    .id = NPC_SPINY3,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802475A4) = {
    .id = NPC_SPINY4,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80247794) = {
    .id = NPC_SPINY5,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 0, 0, 0, 0, 0, -32767 },
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80247984) = {
    NPC_GROUP(N(npcGroup_80246A04), BATTLE_ID(24, 6, 0, 5)),
    NPC_GROUP(N(npcGroup_80246BF4), BATTLE_ID(24, 4, 0, 5)),
    NPC_GROUP(N(npcGroup_80246DE4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80246FD4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802471C4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802473B4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_802475A4), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80247794), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80246434), BATTLE_ID(25, 5, 0, 2)),
    NPC_GROUP(N(npcGroup_80246624), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246814), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/UnkFunc41.inc.c"

#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

#include "world/common/SixFloatsFunc.inc.c"

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

#include "world/common/UnkNpcAIMainFunc9.inc.c"

s32 N(func_802416BC_CC4ECC)(void) {
    s32 i;

    for (i = 50; i < 56; i++) {
        if (get_enemy(i)->varTable[10] == 0) {
            return i;
        }
    }

    return -1;
}

void N(func_80241704_CC4F14)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0] = 12;
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.point.x,
                               enemy->territory->wander.point.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSizeX,
                               enemy->territory->wander.wanderSizeZ) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0] = 2;
        script->functionTemp[1] = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1] == 0)) {
            script->functionTemp[0] = 0;
        }
    }
}

void N(func_80241B68_CC5378)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
    npc->pos.y = y + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);
    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        script->functionTemp[0] = 12;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->functionTemp[0] = 0;
    }
}

// enemy2 is being copied to a0
#ifdef NON_EQUIVALENT
ApiStatus N(func_80241DB8_CC55C8)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings =(NpcAISettings*) evt_get_variable(script, *args);
    f32 temp_f4;
    f32 dist;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
        script->functionTemp[0] = 0;
    }
    npc->unk_AB = -3;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }


    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);

        case 1:
            N(func_80241704_CC4F14)(script, aiSettings, territoryPtr);
            break;

        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);

        case 3:
            N(func_80241B68_CC5378)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->functionTemp[0] == 12) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enemy->varTable[4] = N(func_802416BC_CC4ECC)();
        if (enemy->varTable[4] >= 0) {
            Enemy* enemy2 = get_enemy(enemy->varTable[4]);
            enemy2->varTable[10] = 1;
            enemy2->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->currentAnim.w = 0x490014;
            script->functionTemp[0] = 30;
        }
    }

    switch (script->functionTemp[0]) {
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    switch (script->functionTemp[0]) {
        case 30:
            npc->duration--;
            if (npc->duration <= 0) {
                get_enemy(enemy->varTable[4])->varTable[10] = 2;
                npc->duration = 5;
                script->functionTemp[0] = 31;
            }

        case 31:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->currentAnim.w = 0x490015;
                get_enemy(enemy->varTable[4])->varTable[10] = 3;
                npc->duration = 10;
                script->functionTemp[0] = 32;
            }

        case 32:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->duration = 3;
                script->functionTemp[0] = 33;
            }

        case 33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->functionTemp[0] = 0;
            }
            break;
    }

    if (((u32)script->functionTemp[0] - 30) < 2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, npc->pos.x, npc->pos.z);
        if (!is_point_within_region(territoryPtr->shape, territoryPtr->pointX, territoryPtr->pointZ, npc->pos.x, npc->pos.z,
                                    territoryPtr->sizeX, territoryPtr->sizeZ)) {
            if ((dist > 30.0) && (npc->turnAroundYawAdjustment == 0)) {
                temp_f4 = dist - 20.0;
                if (temp_f4 < 0.0) {
                    temp_f4 = 0.0f;
                }
                if (temp_f4 > 200.0) {
                    temp_f4 = 200.0f;
                }
                npc->moveSpeed = update_lerp(0, aiSettings->moveSpeed, aiSettings->chaseSpeed, temp_f4, 200);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
        }
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_13/CC3850", flo_13_func_80241DB8_CC55C8, Evt* script,
            s32 isInitialCall);
#endif

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

#include "world/common/UnkNpcAIMainFunc5.inc.c"

#include "world/common/UnkNpcAIMainFunc6.inc.c"

#include "world/common/UnkFunc42.inc.c"

ApiStatus N(func_802433C0_CC6BD0)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(1);
    s16 param1;
    s16 param2;

    script->functionTemp[1] = evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], script->functionTemp[1]));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[1] < script->functionTemp[0]) * ApiStatus_DONE2;
}

ApiStatus N(func_802434D4_CC6CE4)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);
    s16 param1;
    s16 param2;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], 0x50));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[0] > 0x50) * ApiStatus_DONE2;
}
