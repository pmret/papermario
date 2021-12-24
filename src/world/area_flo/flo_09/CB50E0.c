#include "flo_09.h"
#include "message_ids.h"
#include "sprite/npc/bzzap.h"
#include "sprite/npc/dayzee.h"

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

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_09_tattle },
};

EvtSource N(80241880) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(802418F0) = {
    EVT_SET_GROUP(11)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80241B9C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  5);

EvtSource N(exitWalk_80241BF8) = EXIT_WALK_SCRIPT(60,  1, "flo_03",  0);

EvtSource N(80241C54) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241B9C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80241BF8), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024414C)))
    EVT_EXEC(N(802425DC))
    EVT_EXEC(N(802434A8))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000006)
    EVT_SET(EVT_VAR(0), -511)
    EVT_SET(EVT_VAR(1), -4)
    EVT_SET(EVT_VAR(2), -319)
    EVT_SET(EVT_VAR(3), 10)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(EVT_VAR(0), -302)
    EVT_SET(EVT_VAR(1), 77)
    EVT_SET(EVT_VAR(2), -32)
    EVT_SET(EVT_VAR(3), 116)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(EVT_VAR(0), 51)
    EVT_SET(EVT_VAR(1), 18)
    EVT_SET(EVT_VAR(2), 141)
    EVT_SET(EVT_VAR(3), 127)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(EVT_VAR(0), 234)
    EVT_SET(EVT_VAR(1), 38)
    EVT_SET(EVT_VAR(2), 502)
    EVT_SET(EVT_VAR(3), 98)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(802418F0))
    EVT_SET(EVT_VAR(0), -525)
    EVT_SET(EVT_VAR(1), -163)
    EVT_SET(EVT_VAR(2), -400)
    EVT_SET(EVT_VAR(3), -80)
    EVT_SET(EVT_VAR(4), 60)
    EVT_EXEC(N(802418F0))
    EVT_SET(EVT_VAR(0), -346)
    EVT_SET(EVT_VAR(1), -148)
    EVT_SET(EVT_VAR(2), 517)
    EVT_SET(EVT_VAR(3), -91)
    EVT_SET(EVT_VAR(4), 60)
    EVT_EXEC(N(802418F0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80241C54)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80241880))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CB5000))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2004)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80242010) = {
    EVT_SET_GROUP(11)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802422BC) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(6))
    EVT_SET(EVT_VAR(8), EVT_VAR(5))
    EVT_SET(EVT_VAR(7), EVT_VAR(4))
    EVT_SET(EVT_VAR(6), EVT_VAR(3))
    EVT_SET(EVT_VAR(5), EVT_VAR(2))
    EVT_SET(EVT_VAR(4), EVT_VAR(1))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_CALL(EnableModel, EVT_VAR(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(EnableModel, EVT_VAR(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_SET(EVT_VAR(0), EVT_VAR(3))
            EVT_SET(EVT_VAR(1), EVT_VAR(4))
            EVT_SET(EVT_VAR(2), EVT_VAR(5))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_SUB(EVT_VAR(1), 10)
            EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, EVT_VAR(8), EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, EVT_VAR(9), EVT_VAR(0), 1, 0, 0)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, EVT_VAR(7), 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802425DC) = {
    EVT_CALL(GetModelCenter, 69)
    EVT_SET(EVT_VAR(3), 69)
    EVT_SET(EVT_VAR(4), 70)
    EVT_SET(EVT_VAR(5), 71)
    EVT_SET(EVT_VAR(6), 72)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 75)
    EVT_SET(EVT_VAR(3), 75)
    EVT_SET(EVT_VAR(4), 76)
    EVT_SET(EVT_VAR(5), 77)
    EVT_SET(EVT_VAR(6), 78)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 83)
    EVT_SET(EVT_VAR(3), 83)
    EVT_SET(EVT_VAR(4), 84)
    EVT_SET(EVT_VAR(5), 85)
    EVT_SET(EVT_VAR(6), 86)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 89)
    EVT_SET(EVT_VAR(3), 89)
    EVT_SET(EVT_VAR(4), 90)
    EVT_SET(EVT_VAR(5), 91)
    EVT_SET(EVT_VAR(6), 92)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 97)
    EVT_SET(EVT_VAR(3), 97)
    EVT_SET(EVT_VAR(4), 98)
    EVT_SET(EVT_VAR(5), 99)
    EVT_SET(EVT_VAR(6), 100)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802422BC))
    EVT_CALL(GetModelCenter, 103)
    EVT_SET(EVT_VAR(3), 103)
    EVT_SET(EVT_VAR(4), 104)
    EVT_SET(EVT_VAR(5), 105)
    EVT_SET(EVT_VAR(6), 106)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(802422BC))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2874)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/foliage.inc.c"

EvtSource N(802431E4) = {
    EVT_CALL(GetNpcPos, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_IF_LT(EVT_VAR(1), 0)
        EVT_CALL(GetModelCenter, EVT_VAR(9))
        EVT_ADD(EVT_VAR(2), 35)
        EVT_CALL(SetNpcPos, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(tree1_Callback) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1382), 0)
        EVT_IF_EQ(EVT_AREA_VAR(5), 1)
            EVT_CALL(MakeItemEntity, ITEM_HAPPY_FLOWER_B, -250, 100, 0, 13, EVT_SAVE_FLAG(1382))
        EVT_ELSE
            EVT_SET(EVT_VAR(9), 14)
            EVT_EXEC(N(802431E4))
        EVT_END_IF
        EVT_SET(EVT_AREA_VAR(4), 0)
        EVT_SET(EVT_AREA_VAR(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(tree2_Callback) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1382), 0)
        EVT_SET(EVT_AREA_VAR(4), 1)
        EVT_SET(EVT_AREA_VAR(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(tree3_Callback) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1382), 0)
        EVT_IF_EQ(EVT_AREA_VAR(4), 1)
            EVT_IF_EQ(EVT_AREA_VAR(5), 0)
                EVT_SET(EVT_AREA_VAR(5), 1)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_SET(EVT_VAR(9), 22)
        EVT_EXEC(N(802431E4))
        EVT_SET(EVT_AREA_VAR(4), 0)
        EVT_SET(EVT_AREA_VAR(5), 0)
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

EvtSource N(802434A8) = {
    EVT_SET(EVT_AREA_VAR(4), 0)
    EVT_SET(EVT_AREA_VAR(5), 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 15, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243428)), 1, 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree2)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 16, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243460)), 1, 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree3)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 17, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80243498)), 1, 0)
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_802435B0) = {
    .moveSpeed = 1.0f,
    .moveTime = 500,
    .waitTime = 10,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 3.5f,
    .unk_1C = { .s = 40 },
    .unk_20 = 3,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_802435E0) = {
    EVT_CALL(DoBasicAI, EVT_PTR(N(npcAISettings_802435B0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243600) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_802435E0),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

f32 N(D_8024362C_CB862C)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80243644) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 2,
    .chaseSpeed = 4.5f,
    .unk_1C = { .s = 6 },
    .unk_20 = 1,
    .chaseRadius = 90.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_80243674) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(func_8024162C_CB662C), EVT_PTR(N(npcAISettings_80243644)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802436E4) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80243674),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

NpcSettings N(npcSettings_80243710) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtSource N(npcAI_8024373C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_EQ(0)
                EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_IF_GT(EVT_VAR(1), 0)
                    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
                    EVT_CALL(NpcJump0, NPC_SELF, EVT_VAR(0), 50, EVT_VAR(2), 15)
                    EVT_CALL(SetSelfVar, 0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(npcAI_80243674)))
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT_FRAMES(25)
                EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_2)), FALSE)
                EVT_CALL(SetSelfVar, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_802438C8) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
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

EvtSource N(init_80243954) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_8024373C)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802438C8)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024398C) = {
    .id = NPC_DAYZEE0,
    .settings = &N(npcSettings_80243600),
    .pos = { -350.0f, 0.0f, 40.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { -350, 0, 40, 30, 0, -32767, 0, -350, 0, 40, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_2,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_6,
        NPC_ANIM_dayzee_Palette_00_Anim_7,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243B7C) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_80243600),
    .pos = { 260.0f, 0.0f, 75.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(4),
    .maxCoinBonus = 3,
    .movement = { 260, 0, 75, 30, 0, -32767, 0, 260, 0, 75, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_2,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_3,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_8,
        NPC_ANIM_dayzee_Palette_00_Anim_6,
        NPC_ANIM_dayzee_Palette_00_Anim_7,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
        NPC_ANIM_dayzee_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243D6C) = {
    .id = NPC_BZZAP0,
    .settings = &N(npcSettings_802436E4),
    .pos = { -50.0f, 55.0f, 90.0f },
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
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
    .movement = { -50, 55, 90, 30, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_4,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243F5C) = {
    .id = NPC_BZZAP1,
    .settings = &N(npcSettings_80243710),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80243954),
    .yaw = 90,
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
    .movement = { -50, 55, 90, 100, 0, -32767, 0, -50, 50, 90, 250, 0, 0, 1 },
    .animations = {
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_4,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_8024414C) = {
    NPC_GROUP(N(npcGroup_8024398C), BATTLE_ID(24, 16, 0, 5)),
    NPC_GROUP(N(npcGroup_80243B7C), BATTLE_ID(24, 21, 0, 5)),
    NPC_GROUP(N(npcGroup_80243D6C), BATTLE_ID(24, 23, 0, 2)),
    NPC_GROUP(N(npcGroup_80243F5C), BATTLE_ID(24, 23, 0, 2)),
    {},
};

