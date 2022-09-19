#include "arn_04.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/cleft.h"
#include "effects.h"
#include "entity.h"

EvtScript N(exitWalk_80243480) = EXIT_WALK_SCRIPT(60,  0, "arn_02",  1);

EvtScript N(exitWalk_802434DC) = EXIT_WALK_SCRIPT(60,  1, "dgb_00",  0);

EvtScript N(80243538) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243480), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802434DC), TRIGGER_FLOOR_ABOVE, 6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244000)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802433D0))
    EVT_SET(LVar0, EVT_PTR(N(80243538)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3654)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

MobileAISettings N(npcAISettings_80243660) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80243690) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_80243660)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802436B0) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_80243690),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

#include "world/common/enemy/FlyingAI.inc.c"

MobileAISettings N(npcAISettings_802436F4) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 4.0f,
    .chaseTurnRate= 5,
    .chaseUpdateInterval = 1,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80243724) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(npcAISettings_802436F4)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243794) = {
    .height = 18,
    .radius = 20,
    .ai = &N(npcAI_80243724),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
    .actionFlags = 1,
};

MobileAISettings N(npcAISettings_802437C0) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 8.5f,
    .chaseTurnRate= 60,
    .chaseUpdateInterval = 3,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802437F0) = {
    EVT_CALL(N(CleftAI_Main), EVT_PTR(N(npcAISettings_802437C0)), 8)
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243814) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_802437F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 15,
};

StaticNpc N(npcGroup_80243840) = {
    .id = 0,
    .settings = &N(npcSettings_80243794),
    .pos = { -350.0f, 180.0f, 150.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { -350, 180, 150, 30, 0, -32767, 0, -350, 180, 150, 150 }},
    .animations = {
        ANIM_Paragoomba_Hyper_Anim1,
        ANIM_Paragoomba_Hyper_Anim3,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim1,
        ANIM_Paragoomba_Hyper_Anim1,
        ANIM_Paragoomba_Hyper_Anim6,
        ANIM_Paragoomba_Hyper_Anim6,
        ANIM_Paragoomba_Hyper_Anim5,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
        ANIM_Paragoomba_Hyper_Anim4,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_80243A30) = {
    .id = 1,
    .settings = &N(npcSettings_802436B0),
    .pos = { 360.0f, 208.0f, 100.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 360, 208, 100, 30, 0, -32767, 0, 360, 208, 100, 150 }},
    .animations = {
        ANIM_Goomba_Hyper_Anim1,
        ANIM_Goomba_Hyper_Anim2,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim1,
        ANIM_Goomba_Hyper_Anim1,
        ANIM_Goomba_Hyper_Anim5,
        ANIM_Goomba_Hyper_Anim5,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
        ANIM_Goomba_Hyper_Anim3,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_80243C20) = {
    .id = 2,
    .settings = &N(npcSettings_80243814),
    .pos = { 150.0f, 177.0f, 160.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { 150, 177, 160, 30, 0, -32767, 0, 150, 177, 160, 150 }},
    .animations = {
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim6,
        ANIM_Cleft_Hyper_Anim7,
        ANIM_Cleft_Hyper_Anim7,
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim8,
        ANIM_Cleft_Hyper_Anim8,
        ANIM_Cleft_Hyper_Anim14,
        ANIM_Cleft_Hyper_Anim17,
        ANIM_Cleft_Hyper_Anim13,
        ANIM_Cleft_Hyper_Anim15,
        ANIM_Cleft_Hyper_Anim10,
        ANIM_Cleft_Hyper_Anim11,
        ANIM_Cleft_Hyper_Anim16,
        ANIM_Cleft_Hyper_Anim0,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_80243E10) = {
    .id = 3,
    .settings = &N(npcSettings_80243814),
    .pos = { 550.0f, 230.0f, 125.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { 550, 230, 125, 30, 0, -32767, 0, 550, 230, 125, 150 }},
    .animations = {
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim6,
        ANIM_Cleft_Hyper_Anim7,
        ANIM_Cleft_Hyper_Anim7,
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim2,
        ANIM_Cleft_Hyper_Anim8,
        ANIM_Cleft_Hyper_Anim8,
        ANIM_Cleft_Hyper_Anim14,
        ANIM_Cleft_Hyper_Anim17,
        ANIM_Cleft_Hyper_Anim13,
        ANIM_Cleft_Hyper_Anim15,
        ANIM_Cleft_Hyper_Anim10,
        ANIM_Cleft_Hyper_Anim11,
        ANIM_Cleft_Hyper_Anim16,
        ANIM_Cleft_Hyper_Anim0,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(npcGroupList_80244000) = {
    NPC_GROUP(N(npcGroup_80243840), 0x0E09, 0x00),
    NPC_GROUP(N(npcGroup_80243A30), 0x0E03, 0x00),
    NPC_GROUP(N(npcGroup_80243C20), 0x0E0C, 0x00),
    NPC_GROUP(N(npcGroup_80243E10), 0x0E0E, 0x00),
    {},
};

static s32 N(pad_403C)[] = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 450, 285, 120, 0, 140, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_ItemBlock_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 720, 333, 75, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 600, 290, 200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_MultiCoinBrick)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 540, 230, 13, 17, GF_ARN04_Item_StarPiece)
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/CleftAI.inc.c"
