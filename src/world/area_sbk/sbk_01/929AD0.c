#include "sbk_01.h"
#include "sprite/npc/pokey.h"

#include "world/common/SetNpcB5_3.inc.c"

MobileAISettings N(npcAISettings_80240370) = {
    .moveSpeed = 1.8f,
    .moveTime = 50,
    .waitTime = 10,
    .alertRadius = 250.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 45,
    .chaseUpdateInterval = 6,
    .chaseRadius = 300.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802403A0) = {
    EVT_CALL(N(SetNpcB5_3))
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_80240370)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802403CC) = {
    .height = 72,
    .radius = 15,
    .ai = &N(npcAI_802403A0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 9,
};

StaticNpc N(npcGroup_802403F8) = {
    .id = 0,
    .settings = &N(npcSettings_802403CC),
    .pos = { 205.0f, 0.0f, -60.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 205, 0, -60, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 }},
    .animations = {
        ANIM_Pokey_Anim4,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim4,
        ANIM_Pokey_Anim4,
        ANIM_Pokey_AnimC,
        ANIM_Pokey_AnimC,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_802405E8) = {
    .id = 1,
    .settings = &N(npcSettings_802403CC),
    .pos = { -200.0f, 0.0f, 180.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { -200, 0, 180, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 }},
    .animations = {
        ANIM_Pokey_Anim4,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim4,
        ANIM_Pokey_Anim4,
        ANIM_Pokey_AnimC,
        ANIM_Pokey_AnimC,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
        ANIM_Pokey_Anim8,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(npcGroupList_802407D8) = {
    NPC_GROUP(N(npcGroup_802403F8), 0x0A03, 0x00),
    NPC_GROUP(N(npcGroup_802405E8), 0x0A01, 0x00),
    {},
};
