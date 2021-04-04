#include "sbk_00.h"
#include "sprite/npc/pokey.h"

#include "world/common/SetNpcB5_3.inc.c"

NpcAISettings N(npcAISettings_80240300) = {
    .moveSpeed = 1.8f,
    .moveTime = 50,
    .waitTime = 10,
    .alertRadius = 250.0f,
    .unk_14 = 2,
    .chaseSpeed = 3.5f,
    .unk_1C = 45,
    .unk_20 = 6,
    .chaseRadius = 300.0f,
    .unk_2C = 1,
};

Script N(npcAI_80240330) = SCRIPT({
    N(SetNpcB5_3)();
    DoBasicAI(N(npcAISettings_80240300));
});

NpcSettings N(npcSettings_8024035C) = {
    .height = 72,
    .radius = 15,
    .ai = &N(npcAI_80240330),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 9,
};

StaticNpc N(npcGroup_80240388) = {
    .id = 0,
    .settings = &N(npcSettings_8024035C),
    .pos = { -40.0f, 0.0f, 160.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { -40, 0, 160, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 },
    .animations = {
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_C),
        NPC_ANIM(pokey, Palette_00, Anim_C),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80240578) = {
    .id = 1,
    .settings = &N(npcSettings_8024035C),
    .pos = { 245.0f, 0.0f, 75.0f },
    .flags = NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_DRIED_FRUIT, 9, 0 },
        { ITEM_TASTY_TONIC, 1, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 245, 0, 75, 100, 0, -32767, 0, 0, 0, 0, 1000, 0, 0, 1 },
    .animations = {
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_4),
        NPC_ANIM(pokey, Palette_00, Anim_C),
        NPC_ANIM(pokey, Palette_00, Anim_C),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
        NPC_ANIM(pokey, Palette_00, Anim_8),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80240768) = {
    NPC_GROUP(N(npcGroup_80240388), BATTLE_ID(10, 0, 0, 1)),
    NPC_GROUP(N(npcGroup_80240578), BATTLE_ID(10, 1, 0, 1)),
    {},
};

static s32 N(pad_78C) = {
    0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA564, -230, 0, 155, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(797));
    MakeEntity(0x802EA564, 160, 0, 205, 0, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(798));
});
