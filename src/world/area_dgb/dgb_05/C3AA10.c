#include "dgb_05.h"
#include "sprite/npc/world_clubba.h"
#include "message_ids.h"
#include "entity.h"

enum {
    NPC_WORLD_CLUBBA0,
    NPC_WORLD_CLUBBA1,
    NPC_WORLD_CLUBBA2 = 3,
    NPC_WORLD_CLUBBA3,
};

EntryList N(entryList) = {
    { 515.0f, 0.0f, 310.0f, 0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_05_tattle },
};

EvtScript N(802414E0) = {
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

static s32 N(pad_1578)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitSingleDoor_80241580) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 16)
    EVT_SET(EVT_VAR(2), 30)
    EVT_SET(EVT_VAR(3), -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80241634) = {
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 30)
            EVT_SET(EVT_VAR(3), -1)
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
        EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_8024230C)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802417F0))
    EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
    EVT_CALL(EnableModel, 20, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_80241580), TRIGGER_WALL_PRESS_A, 16, 1, 0)
    EVT_EXEC(N(802414E0))
    EVT_EXEC(N(enterSingleDoor_80241634))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_17E8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(802417F0) = {
    EVT_CALL(N(func_80240000_C3AA10))
    EVT_CALL(func_802CA988, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(N(func_80240030_C3AA40))
    EVT_SET(GF_DGB05_BoardedFloor, 1)
    EVT_CALL(GotoMap, EVT_PTR("dgb_06"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1868)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_IF_EQ(GF_DGB05_BoardedFloor, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 510, -210, 100, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_18BC) = {
    0x00000000,
};

EvtScript N(802418C0) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(unk_missing_8024197C)[] = {
    0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011,
    0x00390012, 0xFFFFFFFF,
};

s32 N(extraAnimationList_802419A4)[] = {
    NPC_ANIM_world_clubba_Palette_00_Anim_0,
    ANIM_END,
};

MobileAISettings N(npcAISettings_802419AC) = {
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

EvtScript N(npcAI_802419DC) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_PTR(N(npcAISettings_802419AC)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241A4C) = {
    .height = 36,
    .radius = 34,
    .ai = &N(npcAI_802419DC),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

EvtScript N(npcAI_80241A78) = {
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

NpcSettings N(npcSettings_80241B20) = {
    .height = 14,
    .radius = 18,
    .ai = &N(npcAI_80241A78),
    .onDefeat = &N(802418C0),
    .level = 13,
    .actionFlags = 8,
};

StaticNpc N(npcGroup_80241B4C)[] = {
    {
        .id = NPC_WORLD_CLUBBA0,
        .settings = &N(npcSettings_80241A4C),
        .pos = { 132.0f, -110.0f, 238.0f },
        .flags = NPC_FLAG_LOCK_ANIMS,
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
	.territory = { .temp = { 132, -110, 238, 0, 0, -32767, 0, 325, 0, 185, 200 }},
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA1,
        .settings = &N(npcSettings_80241B20),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_802419A4),
    },
};

StaticNpc N(npcGroup_80241F2C)[] = {
    {
        .id = NPC_WORLD_CLUBBA2,
        .settings = &N(npcSettings_80241A4C),
        .pos = { 503.0f, -210.0f, 225.0f },
        .flags = NPC_FLAG_LOCK_ANIMS,
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
	.territory = { .temp = { 503, -210, 225, 0, 0, -32767, 0, 503, -210, 290, 200, 150, 1 }},
        .animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_WORLD_CLUBBA3,
        .settings = &N(npcSettings_80241B20),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_3,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_4,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_C,
            NPC_ANIM_world_clubba_Palette_00_Anim_11,
            NPC_ANIM_world_clubba_Palette_00_Anim_12,
            NPC_ANIM_world_clubba_Palette_00_Anim_7,
            NPC_ANIM_world_clubba_Palette_00_Anim_8,
            NPC_ANIM_world_clubba_Palette_00_Anim_1,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
            NPC_ANIM_world_clubba_Palette_00_Anim_2,
        },
        .extraAnimations = N(extraAnimationList_802419A4),
    },
};

NpcGroupList N(npcGroupList_8024230C) = {
    NPC_GROUP(N(npcGroup_80241B4C), BATTLE_ID(15, 1, 0, 3)),
    NPC_GROUP(N(npcGroup_80241F2C), BATTLE_ID(15, 2, 0, 3)),
    {},
};

ApiStatus N(func_80240000_C3AA10)(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y >= -210.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240030_C3AA40)(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y > -270.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

#include "world/common/enemy/ClubbaNappingAI.inc.c"
#include "world/common/enemy/WanderMeleeAI.inc.c"
