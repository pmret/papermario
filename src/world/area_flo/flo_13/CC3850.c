#include "flo_13.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/Lakilulu.h"
#include "sprite/npc/Lakitu.h"
#include "sprite/npc/Spiny.h"
#include "sprite/npc/WorldLakilester.h"

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
    .tattle = { MSG_MapTattle_flo_13 },
};

EvtScript N(802436D0) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -500)
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
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -500)
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
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -500)
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
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, 0xD, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, 0xD, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
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
    EVT_SET(LVar0, 274)
    EVT_SET(LVar1, -137)
    EVT_SET(LVar2, 583)
    EVT_SET(LVar3, -64)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(LVar0, 433)
    EVT_SET(LVar1, 108)
    EVT_SET(LVar2, 580)
    EVT_SET(LVar3, 169)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(LVar0, -460)
    EVT_SET(LVar1, 90)
    EVT_SET(LVar2, -125)
    EVT_SET(LVar3, 130)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(LVar0, -420)
    EVT_SET(LVar1, -130)
    EVT_SET(LVar2, -260)
    EVT_SET(LVar3, -90)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80243A40))
    EVT_SET(LVar0, -220)
    EVT_SET(LVar1, -137)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, -50)
    EVT_SET(LVar4, 160)
    EVT_EXEC(N(80243A40))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(80243DA4)))
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
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
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
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, 0, LVar3, LVar4, LVar5)
    EVT_CALL(N(UnkFunc42))
    EVT_CALL(InterpNpcYaw, 0, LVarA, 0)
    EVT_SET(LVar0, LVar3)
    EVT_SET(LVar1, LVar4)
    EVT_SET(LVar2, LVar5)
    EVT_CALL(GetAngleBetweenNPCs, -4, 0, LVarA)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244560) = {
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, 1, LVar3, LVar4, LVar5)
    EVT_CALL(N(UnkFunc42))
    EVT_CALL(InterpNpcYaw, 1, LVarA, 0)
    EVT_SET(LVar0, LVar3)
    EVT_SET(LVar1, LVar4)
    EVT_SET(LVar2, LVar5)
    EVT_CALL(GetAngleBetweenNPCs, -4, 1, LVarA)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    EVT_IF_LT(GB_StoryProgress, 51)
        EVT_CALL(GetAngleBetweenNPCs, 0, 1, LVarB)
        EVT_CALL(InterpNpcYaw, 0, LVarB, 0)
    EVT_END_IF
    EVT_CALL(PlayerFaceNpc, 1, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802446AC) = {
    EVT_SET(MapVar(10), 0)
    EVT_LOOP(0)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, 2, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, 2, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, 1, LVar0, LVar1, LVar2)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, 2, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, 2, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, 1, LVar0, LVar1, LVar2)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_IF_EQ(MapVar(10), 1)
            EVT_SET(MapVar(10), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80244888) = {
    EVT_EXEC(N(802446AC))
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_Lift)
    EVT_CALL(GetNpcPos, 1, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, -5)
    EVT_ADD(LVar2, 30)
    EVT_ADD(LVar3, 2)
    EVT_CALL(SetNpcYaw, 2, 270)
    EVT_CALL(SetNpcPos, 2, LVar1, LVar2, LVar3)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, 1, -1, -1, 512, MSG_CH6_00A8)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(EndSpeech, 1, -1, -1, 512)
    EVT_END_THREAD
    EVT_SET(MapVar(10), 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MapVar(10), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_Throw)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, 5)
    EVT_ADD(LVar2, 20)
    EVT_CALL(SetNpcJumpscale, 2, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, 2, LVar1, LVar2, LVar3, 7)
    EVT_ADD(LVar1, -100)
    EVT_ADD(LVar2, 10)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, 2, EVT_FLOAT(1.5))
        EVT_CALL(NpcJump0, 2, LVar1, LVar2, LVar3, 15)
        EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, 225, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_FallBack)
    EVT_SET(LVar0, 90)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 144)
        EVT_IF_GT(LVar0, 359)
            EVT_SUB(LVar0, 360)
        EVT_END_IF
        EVT_CALL(InterpPlayerYaw, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_Idle)
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
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH6_00A0, 160, 40)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(SetPlayerAnimation, 65578)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Run)
    EVT_THREAD
        EVT_CALL(N(func_802434D4_CC6CE4))
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(8024445C), LVar9)
    EVT_CALL(LoadPath, 80, EVT_PTR(N(vectorList_802443A8)), 5, 0)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 0, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Idle)
    EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 200)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(18.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, -75, 65, 10)
        EVT_CALL(PlayerFaceNpc, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A1)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Run)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Idle)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 1000)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(80245014) = {
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 120)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, 0, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(5.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(NpcFaceNpc, 1, 0, 1)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00B4)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 1, 1)
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(10.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 130, -200)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(N(func_802433C0_CC6BD0), 55)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, 1, ((NPC_FLAG_100)), TRUE)
    EVT_EXEC_GET_TID(N(80244560), LVar9)
    EVT_CALL(LoadPath, 55, EVT_PTR(N(vectorList_80244420)), 5, 0)
    EVT_LABEL(20)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(BringPartnerOut, 8)
    EVT_IF_NE(LVar0, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30)
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00B5)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80245444) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_TiredTalk, ANIM_WorldLakilester_Tired, 0, MSG_CH6_00A2)
    EVT_CALL(SetNpcPos, 1, -290, 120, 45)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Idle)
        EVT_CALL(SetPlayerAnimation, 65578)
        EVT_WAIT(20)
        EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 5, MSG_CH6_00A3)
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_Panic)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 500)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(5.5), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, 0, 0, 0)
    EVT_CALL(SetCamPosB, 0, 130, -200)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, 400)
        EVT_CALL(SetCamPosB, 0, 130, 60)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_802433C0_CC6BD0), 80)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(80244560), LVar9)
    EVT_CALL(LoadPath, 80, EVT_PTR(N(vectorList_802443E4)), 5, 0)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, 1, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_ConcernedNod)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_WAIT(20)
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(5.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A4)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Shout, ANIM_Lakilulu_Shout, 0, MSG_CH6_00A5)
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00A6)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Idle)
    EVT_CALL(EndSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(10.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_LABEL(10)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 0, MSG_CH6_00A7)
    EVT_CALL(ShowChoice, MSG_Choice_0020)
    EVT_IF_NE(LVar0, 0)
        EVT_EXEC_WAIT(N(80244888))
        EVT_WAIT(10)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00A9)
        EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_Idle)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
        EVT_WAIT(20)
        EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, 0, 250)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AA)
        EVT_CALL(SetNpcAnimation, 0, ANIM_WorldLakilester_Idle)
        EVT_CALL(EndSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 40)
        EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(5.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AB)
        EVT_WAIT(10)
        EVT_CALL(ShowChoice, MSG_Choice_0021)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
            EVT_CASE_EQ(0)
                EVT_CALL(ContinueSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AC)
            EVT_CASE_EQ(1)
                EVT_CALL(ContinueSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AD)
            EVT_CASE_EQ(2)
                EVT_CALL(ContinueSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AE)
            EVT_CASE_EQ(3)
                EVT_CALL(ContinueSpeech, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AF)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, 1, 90, 1)
    EVT_CALL(SetNpcAnimation, 1, ANIM_Lakilulu_ConcernedNod)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B0)
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B1)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B2)
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(ResetCam, 0, EVT_FLOAT(90.0))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetNpcSpeed, 0, EVT_FLOAT(3.5))
    EVT_CALL(NpcMoveTo, 0, LVar0, 60, 0)
    EVT_CALL(N(UnkFunc41), 0, 8)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(802438CC))
    EVT_WAIT(15)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0190, 160, 40)
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
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Tired)
            EVT_CALL(SetCamType, 0, 6, 1)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar1, LVar2)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar3)
            EVT_DIV(LVar0, 2)
            EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, 0, 300)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_EXEC(N(80245444))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802461C0) = {
    EVT_IF_LE(GB_StoryProgress, 53)
        EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_NE(LVar0, 8)
            EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0034)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, 1, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
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
    EVT_CALL(SetNpcAnimation, 2, ANIM_Lakilulu_Spiny)
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
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Idle,
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
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
    },
    .tattle = MSG_NpcTattle_Lakilulu,
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
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
        ANIM_Lakilulu_Idle,
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
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim02,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim04,
        ANIM_Lakitu_Anim04,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
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
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim02,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim04,
        ANIM_Lakitu_Anim04,
        ANIM_Lakitu_Anim03,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
        ANIM_Lakitu_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
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
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim03,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim04,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim09,
        ANIM_Spiny_Anim06,
        ANIM_Spiny_Anim08,
        ANIM_Spiny_Anim07,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
        ANIM_Spiny_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_80247984) = {
    NPC_GROUP(N(npcGroup_80246A04), 0x1806, 0x04),
    NPC_GROUP(N(npcGroup_80246BF4), 0x1804, 0x04),
    NPC_GROUP(N(npcGroup_80246DE4), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_80246FD4), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_802471C4), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_802473B4), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_802475A4), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_80247794), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_80246434), 0x1905, 0x01),
    NPC_GROUP(N(npcGroup_80246624)),
    NPC_GROUP(N(npcGroup_80246814)),
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
