#include "flo_16.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/tuff_puff.h"

enum {
    NPC_TUFF_PUFF0,
    NPC_TUFF_PUFF1,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_80244028) = {
    .moveSpeed = 1.0f,
    .moveTime = 45,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.6f,
    .chaseTurnRate= 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 120.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80244058) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(npcAISettings_80244028)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802440C8) = {
    .height = 24,
    .radius = 28,
    .ai = &N(npcAI_80244058),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

StaticNpc N(npcGroup_802440F4) = {
    .id = NPC_TUFF_PUFF0,
    .settings = &N(npcSettings_802440C8),
    .pos = { 440.0f, 145.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 10,
        .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 440, 145, 15, 30, 0, -32767, 0, 485, 145, 55, 225, 95, 1 }},
    .animations = {
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802442E4) = {
    .id = NPC_TUFF_PUFF1,
    .settings = &N(npcSettings_802440C8),
    .pos = { 600.0f, 145.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 10,
        .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 600, 145, 15, 30, 0, -32767, 0, 485, 145, 55, 225, 95, 1 }},
    .animations = {
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_0,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_6,
        NPC_ANIM_tuff_puff_Palette_00_Anim_5,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
        NPC_ANIM_tuff_puff_Palette_00_Anim_1,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_802444D4) = {
    NPC_GROUP(N(npcGroup_802440F4), 0x1824, 0x05),
    NPC_GROUP(N(npcGroup_802442E4), 0x1820, 0x05),
    {},
};

static s32 N(pad_44F8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80244500) = {
    EVT_CALL(N(func_80242940_CD4770))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AreaFlag(41), 0)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), 50)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 180)
        EVT_SET(AreaFlag(41), 1)
    EVT_ELSE
        EVT_SET(LocalVar(5), 50)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 180)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(AreaFlag(41), 0)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, 0x204D)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LocalVar(5), LocalVar(6), 30, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 94, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 97, 0, LocalVar(0), 0)
        EVT_CALL(TranslateModel, 108, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 111, 0, LocalVar(0), 0)
        EVT_CALL(RotateGroup, 97, LocalVar(7), 1, 0, 0)
        EVT_CALL(RotateGroup, 111, LocalVar(7), 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, 26)
        EVT_CALL(UpdateColliderTransform, 27)
        EVT_CALL(UpdateColliderTransform, 32)
        EVT_CALL(UpdateColliderTransform, 33)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LocalVar(7), LocalVar(8), 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 94, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 97, 0, LocalVar(6), 0)
        EVT_CALL(TranslateModel, 108, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 111, 0, LocalVar(6), 0)
        EVT_CALL(RotateGroup, 97, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateGroup, 111, LocalVar(0), 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802448FC) = {
    EVT_CALL(N(func_80242940_CD4770))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AreaFlag(42), 0)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), 50)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 180)
        EVT_SET(AreaFlag(42), 1)
    EVT_ELSE
        EVT_SET(LocalVar(5), 50)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 180)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(AreaFlag(42), 0)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, 0x204D)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LocalVar(5), LocalVar(6), 30, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 101, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 104, 0, LocalVar(0), 0)
        EVT_CALL(TranslateModel, 115, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 118, 0, LocalVar(0), 0)
        EVT_CALL(TranslateModel, 129, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 132, 0, LocalVar(0), 0)
        EVT_CALL(RotateGroup, 104, LocalVar(7), 1, 0, 0)
        EVT_CALL(RotateGroup, 118, LocalVar(7), 1, 0, 0)
        EVT_CALL(RotateGroup, 132, LocalVar(7), 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, 29)
        EVT_CALL(UpdateColliderTransform, 30)
        EVT_CALL(UpdateColliderTransform, 35)
        EVT_CALL(UpdateColliderTransform, 36)
        EVT_CALL(UpdateColliderTransform, 41)
        EVT_CALL(UpdateColliderTransform, 42)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LocalVar(7), LocalVar(8), 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 101, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 104, 0, LocalVar(6), 0)
        EVT_CALL(TranslateModel, 115, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 118, 0, LocalVar(6), 0)
        EVT_CALL(TranslateModel, 129, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 132, 0, LocalVar(6), 0)
        EVT_CALL(RotateGroup, 104, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateGroup, 118, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateGroup, 132, LocalVar(0), 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80244DC8) = {
    EVT_CALL(N(func_80242940_CD4770))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AreaFlag(43), 0)
        EVT_SET(LocalVar(5), 0)
        EVT_SET(LocalVar(6), -50)
        EVT_SET(LocalVar(7), 0)
        EVT_SET(LocalVar(8), 180)
        EVT_SET(AreaFlag(43), 1)
    EVT_ELSE
        EVT_SET(LocalVar(5), -50)
        EVT_SET(LocalVar(6), 0)
        EVT_SET(LocalVar(7), 180)
        EVT_SET(LocalVar(8), 0)
        EVT_SET(AreaFlag(43), 0)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, 0x204D)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LocalVar(5), LocalVar(6), 30, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 122, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 125, 0, LocalVar(0), 0)
        EVT_CALL(TranslateModel, 136, 0, LocalVar(0), 0)
        EVT_CALL(TranslateGroup, 139, 0, LocalVar(0), 0)
        EVT_CALL(RotateGroup, 125, LocalVar(7), 1, 0, 0)
        EVT_CALL(RotateGroup, 139, LocalVar(7), 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, 38)
        EVT_CALL(UpdateColliderTransform, 39)
        EVT_CALL(UpdateColliderTransform, 44)
        EVT_CALL(UpdateColliderTransform, 45)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LocalVar(7), LocalVar(8), 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 122, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 125, 0, LocalVar(6), 0)
        EVT_CALL(TranslateModel, 136, 0, LocalVar(6), 0)
        EVT_CALL(TranslateGroup, 139, 0, LocalVar(6), 0)
        EVT_CALL(RotateGroup, 125, LocalVar(0), 1, 0, 0)
        EVT_CALL(RotateGroup, 139, LocalVar(0), 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802451C4) = {
    EVT_SET(AreaFlag(41), 0)
    EVT_SET(AreaFlag(42), 0)
    EVT_SET(AreaFlag(43), 0)
    EVT_CALL(ParentColliderToModel, 26, 94)
    EVT_CALL(ParentColliderToModel, 27, 94)
    EVT_CALL(ParentColliderToModel, 29, 101)
    EVT_CALL(ParentColliderToModel, 30, 101)
    EVT_CALL(ParentColliderToModel, 32, 108)
    EVT_CALL(ParentColliderToModel, 33, 108)
    EVT_CALL(ParentColliderToModel, 35, 115)
    EVT_CALL(ParentColliderToModel, 36, 115)
    EVT_CALL(ParentColliderToModel, 38, 122)
    EVT_CALL(ParentColliderToModel, 39, 122)
    EVT_CALL(ParentColliderToModel, 41, 129)
    EVT_CALL(ParentColliderToModel, 42, 129)
    EVT_CALL(ParentColliderToModel, 44, 136)
    EVT_CALL(ParentColliderToModel, 45, 136)
    EVT_BIND_TRIGGER(N(80244500), TRIGGER_FLOOR_TOUCH, 26, 1, 0)
    EVT_BIND_TRIGGER(N(802448FC), TRIGGER_FLOOR_TOUCH, 29, 1, 0)
    EVT_BIND_TRIGGER(N(80244500), TRIGGER_FLOOR_TOUCH, 32, 1, 0)
    EVT_BIND_TRIGGER(N(802448FC), TRIGGER_FLOOR_TOUCH, 35, 1, 0)
    EVT_BIND_TRIGGER(N(80244DC8), TRIGGER_FLOOR_TOUCH, 38, 1, 0)
    EVT_BIND_TRIGGER(N(802448FC), TRIGGER_FLOOR_TOUCH, 41, 1, 0)
    EVT_BIND_TRIGGER(N(80244DC8), TRIGGER_FLOOR_TOUCH, 44, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"
