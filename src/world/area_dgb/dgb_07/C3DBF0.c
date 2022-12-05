#include "dgb_07.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/WorldClubba.h"

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
};

EntryList N(entryList) = {
    { -450.0f,   0.0f,  -40.0f,   0.0f },
    {  250.0f, 190.0f, -250.0f, 180.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_07 },
};

EvtScript N(80241490) = {
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

static s32 N(pad_1528)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitSingleDoor_80241530) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 6)
    EVT_SET(LVar2, 22)
    EVT_SET(LVar3, -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_802415E4) = {
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 22)
            EVT_SET(LVar3, -1)
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
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80241E5C)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_BIND_TRIGGER(N(exitSingleDoor_80241530), TRIGGER_WALL_PRESS_A, 6, 1, 0)
    EVT_EXEC(N(80241490))
    EVT_EXEC(N(enterSingleDoor_802415E4))
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -220, 75, -210, 17, GF_DGB07_Item_StarPiece)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -370, 0, -200, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -410, 0, -200, 0, -1, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_17E4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(802417F0) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, ENEMY_FLAGS_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_802418AC)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim0C,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim11,
    ANIM_WorldClubba_Anim12,
    ANIM_LIST_END,
};

s32 N(extraAnimationList_802418D4)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_LIST_END,
};

MobileAISettings N(npcAISettings_802418DC) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .chaseOffsetDist = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_8024190C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_PTR(N(npcAISettings_802418DC)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024197C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_8024190C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtScript N(npcAI_802419A8) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 32)
    EVT_CALL(SetSelfVar, 2, 50)
    EVT_CALL(SetSelfVar, 3, 32)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, 8389)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241A50) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_802419A8),
    .onDefeat = &N(802417F0),
    .level = 13,
    .actionFlags = 8,
};

StaticNpc N(npcGroup_80241A7C)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_8024197C),
        .pos = { -500.0f, 0.0f, -240.0f },
        .flags = ENEMY_FLAGS_800,
        .yaw = 270,
        .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
            .heartDrops = STANDARD_HEART_DROPS(3),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 2,
            .maxCoinBonus = 3,
        },
    .territory = { .temp = { -500, 0, -240, 40, 0, -32767, 0, -500, 0, -240, 200, 0, 0, 1 }},
        .animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
        .extraAnimations = N(extraAnimationList_802418AC),
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80241A50),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_800000,
        .yaw = 0,
        .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
    .animations = {
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim03,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim04,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim0C,
            ANIM_WorldClubba_Anim11,
            ANIM_WorldClubba_Anim12,
            ANIM_WorldClubba_Anim07,
            ANIM_WorldClubba_Anim08,
            ANIM_WorldClubba_Anim01,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
            ANIM_WorldClubba_Anim02,
        },
        .extraAnimations = N(extraAnimationList_802418D4),
    },
};

NpcGroupList N(npcGroupList_80241E5C) = {
    NPC_GROUP(N(npcGroup_80241A7C), 0x0F01, 0x02),
    {},
};

static const s32 N(pad_1E74)[] = {
    0x00000000, 0x00000000
};

#include "world/common/enemy/ai/ClubbaNappingAI.inc.c"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"
