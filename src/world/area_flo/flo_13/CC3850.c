#include "flo_13.h"
#include "message_ids.h"
#include "entity.h"
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

MapSettings N(settings) = {
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
    EVT_SWITCH(GB_StoryProgress)
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
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(10)
    EVT_SWITCH(GB_StoryProgress)
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
        EVT_WAIT(1)
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
    EVT_WAIT(15)
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
    EVT_CALL(MakeItemEntity, ITEM_MEGA_SMASH, -61, 60, -85, 17, GF_FLO13_Item_MegaSmash)
    EVT_CALL(MakeItemEntity, ITEM_SHOOTING_STAR, 128, 0, 157, 17, GF_FLO13_Item_ShootingStar)
    EVT_IF_EQ(GF_FLO13_Item_MegaSmash, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), -160, 160, -90, 0, MAKE_ENTITY_END)
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
    EVT_SET_GROUP(EVT_GROUP_0B)
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
    EVT_WAIT(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(EVT_VAR(15))
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
    EVT_SET(GB_WorldLocation, 38)
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
    EVT_IF_GE(GB_StoryProgress, 53)
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

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_80244144) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 80.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80244174) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 400)
    EVT_CALL(N(LakituAI_Main), EVT_PTR(N(npcAISettings_80244144)))
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

MobileAISettings N(npcAISettings_80244210) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_80244240) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(SpinyAI_Main), EVT_PTR(N(npcAISettings_80244210)))
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
    EVT_WAIT(1)
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
    EVT_IF_LT(GB_StoryProgress, 51)
        EVT_CALL(GetAngleBetweenNPCs, 0, 1, EVT_VAR(11))
        EVT_CALL(InterpNpcYaw, 0, EVT_VAR(11), 0)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, 1, 0)
    EVT_WAIT(1)
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
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), -1)
            EVT_CALL(SetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), -1)
            EVT_CALL(SetNpcPos, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
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
        EVT_WAIT(5)
        EVT_CALL(SetPlayerAnimation, ANIM_1002B)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, 1, -1, -1, 512, MESSAGE_ID(0x11, 0x00A8))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(EndSpeech, 1, -1, -1, 512)
    EVT_END_THREAD
    EVT_SET(EVT_MAP_VAR(10), 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
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
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244BF8) = {
    EVT_IF_NE(GB_StoryProgress, 50)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 200, 20, 275)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, 0, -250, 120, 45)
    EVT_CALL(SetMusicTrack, 0, SONG_LAKILESTER_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x11, 0x00A0), 160, 40)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(SetPlayerAnimation, 65578)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(20)
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
    EVT_WAIT(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
    EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_WAIT(15)
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
    EVT_WAIT(10)
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
    EVT_WAIT(1)
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
    EVT_WAIT(5)
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
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_A, NPC_ANIM_world_lakilester_Palette_00_Anim_4, 0, MESSAGE_ID(0x11, 0x00A2))
    EVT_CALL(SetNpcPos, 1, -290, 120, 45)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_lakilester_Palette_00_Anim_1)
        EVT_CALL(SetPlayerAnimation, 65578)
        EVT_WAIT(20)
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
    EVT_WAIT(1)
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
    EVT_WAIT(1)
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(EVT_VAR(9))
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_9)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_WAIT(20)
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
        EVT_WAIT(10)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, 1, NPC_ANIM_lakilulu_Palette_00_Anim_4, NPC_ANIM_lakilulu_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00A9))
        EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_lakilulu_Palette_00_Anim_1)
        EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
        EVT_WAIT(20)
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
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_B, NPC_ANIM_world_lakilester_Palette_00_Anim_3, 0, MESSAGE_ID(0x11, 0x00AB))
        EVT_WAIT(10)
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
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_lakilulu_Palette_00_Anim_A, NPC_ANIM_lakilulu_Palette_00_Anim_9, 5, MESSAGE_ID(0x11, 0x00B2))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_world_lakilester_Palette_00_Anim_9, NPC_ANIM_world_lakilester_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x00B3))
    EVT_WAIT(10)
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
    EVT_WAIT(15)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x0190), 160, 40)
    EVT_EXEC(N(802438F8))
    EVT_WAIT(10)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(GB_StoryProgress, 51)
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
    EVT_IF_LE(GB_StoryProgress, 53)
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
    EVT_IF_LT(GB_StoryProgress, 51)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244BF8)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80246038)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802462D0) = {
    EVT_IF_LT(GB_StoryProgress, 58)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802461C0)))
        EVT_CALL(SetNpcCollisionSize, -1, 36, 28)
        EVT_IF_GE(GB_StoryProgress, 53)
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
    EVT_IF_EQ(GB_StoryProgress, 50)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802463E8) = {
    EVT_IF_EQ(GB_StoryProgress, 50)
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(init_80246280),
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
};

StaticNpc N(npcGroup_80246624) = {
    .id = NPC_LAKILULU0,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_802462D0),
    .yaw = 90,
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

StaticNpc N(npcGroup_80246814) = {
    .id = NPC_LAKILULU1,
    .settings = &N(npcSettings_80244100),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80246370),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_80246A04) = {
    .id = NPC_LAKITU0,
    .settings = &N(npcSettings_802441E4),
    .pos = { 335.0f, 90.0f, 45.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_802463B0),
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
	.territory = { .temp = { 335, 90, 45, 30, 0, -32767, 0, 335, 90, 45, 250, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80246BF4) = {
    .id = NPC_LAKITU1,
    .settings = &N(npcSettings_802441E4),
    .pos = { -320.0f, 90.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_802463B0),
    .yaw = 90,
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
	.territory = { .temp = { -320, 90, 0, 30, 0, -32767, 0, -320, 90, 0, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80246DE4) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80246FD4) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802471C4) = {
    .id = NPC_SPINY2,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802473B4) = {
    .id = NPC_SPINY3,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802475A4) = {
    .id = NPC_SPINY4,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80247794) = {
    .id = NPC_SPINY5,
    .settings = &N(npcSettings_8024437C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_802463E8),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 0, 0, 0, 0, 0, -32767 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
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

#define AI_LAKITU_FIRST_SPINY_ID    50
#define AI_LAKITU_LAST_SPINY_ID     55
#include "world/common/enemy/LakituAI.inc.c"
#include "world/common/enemy/SpinyAI.inc.c"

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
