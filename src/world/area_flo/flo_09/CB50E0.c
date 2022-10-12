#include "flo_09.h"
#include "message_ids.h"
#include "sprite/npc/Bzzap.h"
#include "sprite/npc/Dayzee.h"

enum {
    NPC_DAYZEE0,
    NPC_DAYZEE1,
    NPC_BZZAP0,
    NPC_BZZAP1,
};

EntryList N(entryList) = {
    { -520.0f, 0.0f, 0.0f,  90.0f },
    {  520.0f, 0.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_09 },
};

EvtScript N(80241880) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802418F0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, 0xD, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, 0xD, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80241B9C) = EVT_EXIT_WALK(60,  0, "flo_00",  5);

EvtScript N(exitWalk_80241BF8) = EVT_EXIT_WALK(60,  1, "flo_03",  0);

EvtScript N(80241C54) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241B9C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241BF8), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024414C)))
    EVT_EXEC(N(802425DC))
    EVT_EXEC(N(802434A8))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000006)
    EVT_SET(LVar0, -511)
    EVT_SET(LVar1, -4)
    EVT_SET(LVar2, -319)
    EVT_SET(LVar3, 10)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(LVar0, -302)
    EVT_SET(LVar1, 77)
    EVT_SET(LVar2, -32)
    EVT_SET(LVar3, 116)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(LVar0, 51)
    EVT_SET(LVar1, 18)
    EVT_SET(LVar2, 141)
    EVT_SET(LVar3, 127)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(LVar0, 234)
    EVT_SET(LVar1, 38)
    EVT_SET(LVar2, 502)
    EVT_SET(LVar3, 98)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(LVar0, -525)
    EVT_SET(LVar1, -163)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -80)
    EVT_SET(LVar4, 60)
    EVT_EXEC(N(802418F0))
    EVT_SET(LVar0, -346)
    EVT_SET(LVar1, -148)
    EVT_SET(LVar2, 517)
    EVT_SET(LVar3, -91)
    EVT_SET(LVar4, 60)
    EVT_EXEC(N(802418F0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, 5, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(80241C54)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80241880))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CB5000))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2004)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80242010) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, 0xD, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, 0xD, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802422BC) = {
    EVT_SET(LVar9, LVar6)
    EVT_SET(LVar8, LVar5)
    EVT_SET(LVar7, LVar4)
    EVT_SET(LVar6, LVar3)
    EVT_SET(LVar5, LVar2)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar3, LVar0)
    EVT_CALL(EnableModel, LVar6, 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, 1)
    EVT_END_THREAD
    EVT_IF_NE(LVarA, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_ADD(LVar1, 10)
            EVT_ADD(LVar2, 8)
            EVT_CALL(PlayEffect, 0x11, 4, LVar0, LVar1, LVar2, 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_SUB(LVar1, 10)
            EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, LVar3, LVar4, LVar5)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, LVar9, LVar0, 1, 0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802425DC) = {
    EVT_CALL(GetModelCenter, 69)
    EVT_SET(LVar3, 69)
    EVT_SET(LVar4, 70)
    EVT_SET(LVar5, 71)
    EVT_SET(LVar6, 72)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 75)
    EVT_SET(LVar3, 75)
    EVT_SET(LVar4, 76)
    EVT_SET(LVar5, 77)
    EVT_SET(LVar6, 78)
    EVT_SET(LVarA, 174)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 83)
    EVT_SET(LVar3, 83)
    EVT_SET(LVar4, 84)
    EVT_SET(LVar5, 85)
    EVT_SET(LVar6, 86)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 89)
    EVT_SET(LVar3, 89)
    EVT_SET(LVar4, 90)
    EVT_SET(LVar5, 91)
    EVT_SET(LVar6, 92)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 97)
    EVT_SET(LVar3, 97)
    EVT_SET(LVar4, 98)
    EVT_SET(LVar5, 99)
    EVT_SET(LVar6, 100)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 103)
    EVT_SET(LVar3, 103)
    EVT_SET(LVar4, 104)
    EVT_SET(LVar5, 105)
    EVT_SET(LVar6, 106)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(802422BC))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2874)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "common/foliage.inc.c"

EvtScript N(802431E4) = {
    EVT_CALL(GetNpcPos, 3, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 0)
        EVT_CALL(GetModelCenter, LVar9)
        EVT_ADD(LVar2, 35)
        EVT_CALL(SetNpcPos, 3, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(tree1_Callback) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, 0)
        EVT_IF_EQ(AreaByte(5), 1)
            EVT_CALL(MakeItemEntity, ITEM_HAPPY_FLOWER_B, -250, 100, 0, 13, GF_FLO09_Item_HappyFlowerB)
        EVT_ELSE
            EVT_SET(LVar9, 14)
            EVT_EXEC(N(802431E4))
        EVT_END_IF
        EVT_SET(AreaByte(4), 0)
        EVT_SET(AreaByte(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(tree2_Callback) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, 0)
        EVT_SET(AreaByte(4), 1)
        EVT_SET(AreaByte(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(tree3_Callback) = {
    EVT_IF_EQ(GF_FLO09_Item_HappyFlowerB, 0)
        EVT_IF_EQ(AreaByte(4), 1)
            EVT_IF_EQ(AreaByte(5), 0)
                EVT_SET(AreaByte(5), 1)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_SET(LVar9, 22)
        EVT_EXEC(N(802431E4))
        EVT_SET(AreaByte(4), 0)
        EVT_SET(AreaByte(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

FoliageModelList N(tree1_Leaves) = {
    .count = 2,
    .models = { 15, 16 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 14 }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .callback = &N(tree1_Callback),
};

Vec4f N(triggerCoord_80243428) = { -200.0f, 0.0f, 1.0f, 0.0f };

FoliageModelList N(tree2_Leaves) = {
    .count = 2,
    .models = { 19, 20 }
};

FoliageModelList N(tree2_Trunk) = {
    .count = 1,
    .models = { 18 }
};

ShakeTreeConfig N(tree2) = {
    .leaves = &N(tree2_Leaves),
    .trunk = &N(tree2_Trunk),
    .callback = &N(tree2_Callback),
};

Vec4f N(triggerCoord_80243460) = { 0.0f, 0.0f, 1.0f, 0.0f };

FoliageModelList N(tree3_Leaves) = {
    .count = 2,
    .models = { 23, 24 }
};

FoliageModelList N(tree3_Trunk) = {
    .count = 1,
    .models = { 22 }
};

ShakeTreeConfig N(tree3) = {
    .leaves = &N(tree3_Leaves),
    .trunk = &N(tree3_Trunk),
    .callback = &N(tree3_Callback),
};

Vec4f N(triggerCoord_80243498) = { 200.0f, 0.0f, 1.0f, 0.0f };

EvtScript N(802434A8) = {
    EVT_SET(AreaByte(4), 0)
    EVT_SET(AreaByte(5), 0)
    EVT_SET(LVar0, EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 15, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243428)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(tree2)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 16, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243460)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(tree3)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 17, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243498)), 1, 0)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_802435B0) = {
    .moveSpeed = 1.0f,
    .moveTime = 500,
    .waitTime = 10,
    .alertRadius = 50.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.5f,
    .chaseTurnRate= 40,
    .chaseUpdateInterval = 3,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802435E0) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_802435B0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243600) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_802435E0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_80243644) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 4.5f,
    .chaseTurnRate= 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80243674) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(npcAISettings_80243644)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802436E4) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80243674),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

NpcSettings N(npcSettings_80243710) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtScript N(npcAI_8024373C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_GT(LVar1, 0)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
                    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 50, LVar2, 15)
                    EVT_CALL(SetSelfVar, 0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_80243674)))
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_2)), FALSE)
                EVT_CALL(SetSelfVar, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_802438C8) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetSelfVar, 0, 2)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_8024373C)))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243954) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_8024373C)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802438C8)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024398C) = {
    .id = NPC_DAYZEE0,
    .settings = &N(npcSettings_80243600),
    .pos = { -350.0f, 0.0f, 40.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(4),
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { -350, 0, 40, 30, 0, -32767, 0, -350, 0, 40, 200, 0, 0, 1 }},
    .animations = {
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim02,
        ANIM_Dayzee_Anim03,
        ANIM_Dayzee_Anim03,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim08,
        ANIM_Dayzee_Anim08,
        ANIM_Dayzee_Anim06,
        ANIM_Dayzee_Anim07,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80243B7C) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_80243600),
    .pos = { 260.0f, 0.0f, 75.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(4),
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { 260, 0, 75, 30, 0, -32767, 0, 260, 0, 75, 200, 0, 0, 1 }},
    .animations = {
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim02,
        ANIM_Dayzee_Anim03,
        ANIM_Dayzee_Anim03,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim08,
        ANIM_Dayzee_Anim08,
        ANIM_Dayzee_Anim06,
        ANIM_Dayzee_Anim07,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
        ANIM_Dayzee_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80243D6C) = {
    .id = NPC_BZZAP0,
    .settings = &N(npcSettings_802436E4),
    .pos = { -50.0f, 55.0f, 90.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 4,
    },
	.territory = { .temp = { -50, 55, 90, 30, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 }},
    .animations = {
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim03,
        ANIM_Bzzap_Anim03,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim06,
        ANIM_Bzzap_Anim06,
        ANIM_Bzzap_Anim04,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80243F5C) = {
    .id = NPC_BZZAP1,
    .settings = &N(npcSettings_80243710),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80243954),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 4,
    },
	.territory = { .temp = { -50, 55, 90, 100, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 }},
    .animations = {
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim03,
        ANIM_Bzzap_Anim03,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim06,
        ANIM_Bzzap_Anim06,
        ANIM_Bzzap_Anim04,
        ANIM_Bzzap_Anim02,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
        ANIM_Bzzap_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_8024414C) = {
    NPC_GROUP(N(npcGroup_8024398C), 0x1810, 0x04),
    NPC_GROUP(N(npcGroup_80243B7C), 0x1815, 0x04),
    NPC_GROUP(N(npcGroup_80243D6C), 0x1817, 0x01),
    NPC_GROUP(N(npcGroup_80243F5C), 0x1817, 0x01),
    {},
};

