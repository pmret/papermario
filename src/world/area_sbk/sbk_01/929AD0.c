#include "sbk_01.h"
#include "sprite/npc/pokey.h"

#include "world/common/SetNpcB5_3.inc.c"

NpcAISettings N(npcAISettings_80240370) = {
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
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 205, 0, -60, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 },
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
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802405E8) = {
    .id = 1,
    .settings = &N(npcSettings_802403CC),
    .pos = { -200.0f, 0.0f, 180.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { -200, 0, 180, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 },
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
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_802407D8) = {
    NPC_GROUP(N(npcGroup_802403F8), BATTLE_ID(10, 3, 0, 1)),
    NPC_GROUP(N(npcGroup_802405E8), BATTLE_ID(10, 1, 0, 1)),
    {},
};
