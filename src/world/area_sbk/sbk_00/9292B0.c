#include "sbk_00.h"
#include "sprite/npc/pokey.h"
#include "entity.h"

#include "world/common/SetNpcB5_3.inc.c"

MobileAISettings N(npcAISettings_80240300) = {
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

EvtScript N(npcAI_80240330) = {
    EVT_CALL(N(SetNpcB5_3))
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_80240300)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024035C) = {
    .height = 72,
    .radius = 15,
    .ai = &N(npcAI_80240330),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 9,
};

StaticNpc N(npcGroup_80240388) = {
    .id = 0,
    .settings = &N(npcSettings_8024035C),
    .pos = { -40.0f, 0.0f, 160.0f },
    .flags = NPC_FLAG_JUMPING,
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
	.territory = { .temp = { -40, 0, 160, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_C,
        NPC_ANIM_pokey_Palette_00_Anim_C,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_80240578) = {
    .id = 1,
    .settings = &N(npcSettings_8024035C),
    .pos = { 245.0f, 0.0f, 75.0f },
    .flags = NPC_FLAG_JUMPING,
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
	.territory = { .temp = { 245, 0, 75, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_4,
        NPC_ANIM_pokey_Palette_00_Anim_C,
        NPC_ANIM_pokey_Palette_00_Anim_C,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
        NPC_ANIM_pokey_Palette_00_Anim_8,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(npcGroupList_80240768) = {
    NPC_GROUP(N(npcGroup_80240388), BATTLE_ID(10, 0, 0, 1)),
    NPC_GROUP(N(npcGroup_80240578), BATTLE_ID(10, 1, 0, 1)),
    {},
};

static s32 N(pad_78C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -230, 0, 155, 0, 152, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK00_ItemBlock_FrightJar)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 160, 0, 205, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK00_ItemBlock_Coin)
    EVT_RETURN
    EVT_END
};
