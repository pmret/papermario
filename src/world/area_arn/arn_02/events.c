#include "arn_02.h"
#include "sprite/npc/cleft.h"
#include "sprite/npc/goomba.h"
#include "effects.h"
#include "entity.h"

EvtScript N(exitWalk_802410F0) = EXIT_WALK_SCRIPT(60,  0, "arn_05",  1);

EvtScript N(exitWalk_8024114C) = EXIT_WALK_SCRIPT(60,  1, "arn_04",  0);

EvtScript N(802411A8) = {
    EVT_BIND_TRIGGER(N(exitWalk_802410F0), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024114C), TRIGGER_FLOOR_ABOVE, 6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80241A9C)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80241040))
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802411A8)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_12C4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_DIZZY_DIAL, -248, 193, 45, 17, EVT_SAVE_FLAG(1005))
    EVT_CALL(MakeItemEntity, ITEM_LETTER07, 536, 260, 227, 17, EVT_SAVE_FLAG(1006))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -350, 172, 170, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1002))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 225, 265, 30, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1003))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 275, 265, 150, 0, 151, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1004))
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_802413D0) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.3f,
    .chaseTurnRate= 70,
    .chaseUpdateInterval = 1,
    .chaseRadius = 180.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80241400) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_802413D0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241420) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_80241400),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

NpcAISettings N(npcAISettings_8024144C) = {
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

EvtScript N(npcAI_8024147C) = {
    EVT_CALL(N(CleftAI_Main), EVT_PTR(N(npcAISettings_8024144C)), 8)
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802414A0) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_8024147C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 15,
};

StaticNpc N(npcGroup_802414CC) = {
    .id = 0,
    .settings = &N(npcSettings_802414A0),
    .pos = { -196.0f, 130.0f, 104.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { -196, 130, 104, 50, 30, -32767, 1, -196, 130, 104, 120 },
    .animations = {
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_walk,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_rock,
        NPC_ANIM_cleft_hyper_rock_darken,
        NPC_ANIM_cleft_hyper_from_rock,
        NPC_ANIM_cleft_hyper_into_rock,
        NPC_ANIM_cleft_hyper_charge_still,
        NPC_ANIM_cleft_hyper_charge,
        NPC_ANIM_cleft_hyper_rock_lighten,
        NPC_ANIM_cleft_hyper_still,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802416BC) = {
    .id = 1,
    .settings = &N(npcSettings_802414A0),
    .pos = { 641.0f, 268.0f, 202.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 3,
    .movement = { 641, 268, 202, 50, 30, -32767, 1, 641, 268, 202, 120 },
    .animations = {
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_walk,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_run,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_idle,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_skid,
        NPC_ANIM_cleft_hyper_rock,
        NPC_ANIM_cleft_hyper_rock_darken,
        NPC_ANIM_cleft_hyper_from_rock,
        NPC_ANIM_cleft_hyper_into_rock,
        NPC_ANIM_cleft_hyper_charge_still,
        NPC_ANIM_cleft_hyper_charge,
        NPC_ANIM_cleft_hyper_rock_lighten,
        NPC_ANIM_cleft_hyper_still,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802418AC) = {
    .id = 2,
    .settings = &N(npcSettings_80241420),
    .pos = { 333.0f, 215.0f, 85.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 333, 215, 85, 40, 30, -32767, 1, 360, 215, 150, 120, 137, 1 },
    .animations = {
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_walk,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80241A9C) = {
    NPC_GROUP(N(npcGroup_802414CC), BATTLE_ID(14, 10, 0, 1)),
    NPC_GROUP(N(npcGroup_802416BC), BATTLE_ID(14, 13, 0, 1)),
    NPC_GROUP(N(npcGroup_802418AC), BATTLE_ID(14, 3, 0, 1)),
    {},
};

#include "world/common/enemy/CleftAI.inc.c"
