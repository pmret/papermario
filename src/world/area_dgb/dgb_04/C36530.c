#include "dgb_04.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/sentinel.h"
#include "message_ids.h"
#include "entity.h"

enum {
    NPC_SENTINEL,
};

EntryList N(entryList) = {
    { 575.0f,    0.0f, 180.0f, 270.0f },
    { 575.0f, -420.0f, 180.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_04_tattle },
};

EvtScript N(80243170) = {
    EVT_SWITCH(GB_StoryProgress)
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

static s32 N(pad_3208)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitSingleDoor_80243210) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 16)
    EVT_SET(LocalVar(2), 16)
    EVT_SET(LocalVar(3), 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_06"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802432C4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LocalVar(0), 1)
    EVT_SET(LocalVar(1), 20)
    EVT_SET(LocalVar(2), 13)
    EVT_SET(LocalVar(3), 11)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80243378) = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 3)
            EVT_SET(LocalVar(2), 13)
            EVT_SET(LocalVar(3), 11)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LocalVar(2), 16)
            EVT_SET(LocalVar(3), 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(GB_StoryProgress, -15)
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80243D18)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_BIND_TRIGGER(N(exitSingleDoor_80243210), TRIGGER_WALL_PRESS_A, 16, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802432C4), TRIGGER_WALL_PRESS_A, 20, 1, 0)
    EVT_EXEC(N(80243170))
    EVT_EXEC(N(enterSingleDoor_80243378))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3558)[] = {
    0x00000000, 0x00000000,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80243578) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_802435B4) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 1,
    .chaseRadius = 240.0f,
    .unk_AI_2C = 1,
};

extern const char N(dgb_00_name_hack)[];

EvtScript N(npcAI_802435E4) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_802435B4)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_CALL(SetNpcPos, NPC_SELF, LocalVar(0), LocalVar(4), LocalVar(2))
    EVT_CALL(GetPlayerActionState, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_ADD(LocalVar(2), 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_WAIT(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(1), 1)
            EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2), 10)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243A0C) = {
    EVT_CALL(GetOwnerEncounterTrigger, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, LocalVar(0))
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80243A98) = {
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243AFC) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80243578),
    .ai = &N(npcAI_802435E4),
    .level = 99,
};

StaticNpc N(npcGroup_80243B28) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_80243AFC),
    .pos = { 70.0f, -220.0f, 186.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 70, -220, 186, 15, 40, -32767, 1, 80, -220, 170, 80, 150, 1 }},
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(npcGroupList_80243D18) = {
    NPC_GROUP(N(npcGroup_80243B28)),
    {},
};

#define SUPER_BLOCK_MAPVAR MapVar(0)
#define SUPER_BLOCK_GAMEFLAG GF_DGB04_SuperBlock
#include "world/common/atomic/SuperBlockData.inc.c"

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), 500, -360, 110, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_RETURN
    EVT_END
};

#define AI_SENTINEL_FIRST_NPC 0
#define AI_SENTINEL_LAST_NPC  0
#include "world/common/enemy/SentinelAI.inc.c"

#include "world/common/atomic/SuperBlock.inc.c"

const char N(dgb_00_name_hack)[] = "dgb_00";
