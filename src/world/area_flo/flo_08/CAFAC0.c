#include "flo_08.h"
#include "message_ids.h"
#include "sprite/npc/dayzee.h"
#include "sprite/npc/gate_flower.h"
#include "effects.h"
#include "entity.h"

enum {
    NPC_GATE_FLOWER,
    NPC_DAYZEE0,
    NPC_DAYZEE1,
    NPC_DAYZEE2,
    NPC_DAYZEE3,
    NPC_DAYZEE4,
    NPC_DAYZEE5,
    NPC_DAYZEE6,
    NPC_DAYZEE7,
};

// BSS
static s32 N(ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1]; // extra entry for list terminator
static s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1]; // extra entry for list terminator

// DATA
EntryList N(entryList) = {
    { -870.0f, 0.0f, 0.0f,  90.0f },
    {  570.0f, 0.0f, 0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_08_tattle },
};

EvtScript N(80241F40) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#define SUPER_BLOCK_MAPVAR MapVar(0)
#define SUPER_BLOCK_GAMEFLAG GF_FLO08_SuperBlock
#include "world/common/atomic/SuperBlockData.inc.c"

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), -780, 120, -110, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 510, 0, -90, 17, GF_FLO08_Item_StarPiece)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242680) = {
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

EvtScript N(exitWalk_8024292C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  6);

EvtScript N(exitWalk_80242988) = EXIT_WALK_SCRIPT(60,  1, "flo_24",  0);

EvtScript N(802429E4) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024292C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80242988), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_80242A2C)[] = {
    0x00000009, 0xC4070000, 0x00000000, 0x42480000, 0x0000000A, 0x42700000, 0x00000000, 0x42480000,
    0x0000000F, 0x42700000, 0x00000000, 0x42480000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244EC4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80245F5C))
    EVT_CALL(ModifyColliderFlags, 3, 19, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_80242A2C)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 22, 1)
    EVT_CALL(EnableTexPanning, 23, 1)
    EVT_CALL(EnableTexPanning, 25, 1)
    EVT_CALL(EnableTexPanning, 27, 1)
    EVT_CALL(EnableTexPanning, 29, 1)
    EVT_CALL(EnableTexPanning, 31, 1)
    EVT_CALL(EnableTexPanning, 41, 1)
    EVT_CALL(EnableTexPanning, 24, 1)
    EVT_CALL(EnableTexPanning, 26, 1)
    EVT_CALL(EnableTexPanning, 28, 1)
    EVT_CALL(EnableTexPanning, 30, 1)
    EVT_CALL(EnableTexPanning, 32, 1)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LABEL(0)
        EVT_ADD(LVar0, 140)
        EVT_IF_GT(LVar0, 65536)
            EVT_ADD(LVar0, -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
        EVT_ADD(LVar1, -200)
        EVT_IF_LT(LVar1, 0)
            EVT_ADD(LVar1, 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, 3, 21, 0x00000006)
    EVT_SET(LVar0, 140)
    EVT_SET(LVar1, -137)
    EVT_SET(LVar2, 340)
    EVT_SET(LVar3, -60)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242680))
    EVT_SET(LVar0, 450)
    EVT_SET(LVar1, -137)
    EVT_SET(LVar2, 590)
    EVT_SET(LVar3, -60)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80242680))
    EVT_EXEC(N(80245914))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LVar0, EVT_PTR(N(802429E4)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80241F40))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240D40_CAFA80))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2EA8)[] = {
    0x00000000, 0x00000000,
};

MobileAISettings N(npcAISettings_80242EB0) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 2.4f,
    .chaseTurnRate= 15,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80242EE0) = {
    EVT_CALL(N(UnkFloAI_Main), EVT_PTR(N(npcAISettings_80242EB0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80242F00) = {
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_SUB(LVar2, 2)
    EVT_CALL(PlayEffect, 0x11, 3, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80242FB4) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_80242EE0),
    .onHit = &EnemyNpcHit,
    .aux = &N(80242F00),
    .onDefeat = &EnemyNpcDefeat,
    .level = 100,
};

NpcSettings N(npcSettings_80242FE0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

MobileAISettings N(npcAISettings_8024300C) = {
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

EvtScript N(npcAI_8024303C) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_8024300C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024305C) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_8024303C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

s32 N(ItemChoice_HasSelectedItem) = FALSE;

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80243090) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(802431C4) = {
    EVT_CALL(N(BuildItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(80243090), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80243214) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO08_GaveYellowBerry, 0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0042))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_SET(LVar0, EVT_PTR(N(FlowerGuard_ItemChoiceList)))
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(N(802431C4))
        EVT_SWITCH(LVar0)
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0043))
            EVT_CASE_DEFAULT
                EVT_SET(LVar8, LVar0)
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LVar0)
                EVT_CALL(MakeItemEntity, LVar8, -695, 20, -29, 1, 0)
                EVT_SET(LVar7, LVar0)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_3)
                EVT_WAIT(20)
                EVT_CALL(RemoveItemEntity, LVar7)
                EVT_SWITCH(LVar8)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_4, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0046))
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x21C, 0)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_02_Anim_9, NPC_ANIM_gate_flower_Palette_02_Anim_8, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_7)
                        EVT_CALL(PlaySoundAtCollider, 17, 457, 0)
                        EVT_CALL(ModifyColliderFlags, 0, 17, 0x7FFFFE00)
                        EVT_CALL(MakeLerp, 0, 100, 30, 1)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LVar8, LVar0)
                            EVT_SETF(LVar9, LVar0)
                            EVT_MULF(LVar8, EVT_FLOAT(0.5))
                            EVT_MULF(LVar9, EVT_FLOAT(1.2))
                            EVT_CALL(RotateModel, 103, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, 104, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, 105, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, 99, LVar9, 0, -1, 0)
                            EVT_CALL(RotateModel, 100, LVar9, 0, -1, 0)
                            EVT_CALL(RotateModel, 101, LVar9, 0, -1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LVar1, 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_5)
                        EVT_SET(GF_FLO08_GaveYellowBerry, 1)
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_4, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0045))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_4, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0045))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_4, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0044))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_6)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x2096, 0)
                        EVT_CALL(MakeItemEntity, LVar8, 125, 20, 0, 1, 0)
                        EVT_SET(LVar7, LVar0)
                        EVT_WAIT(5)
                        EVT_CALL(GetAngleToPlayer, -1, LVar0)
                        EVT_IF_LT(LVar0, 180)
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LVar2, EVT_FLOAT(-0.5))
                                EVT_SETF(LVar3, EVT_FLOAT(-0.2))
                                EVT_SETF(LVar4, EVT_FLOAT(0.9))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(-700.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-25.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_ELSE
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LVar2, EVT_FLOAT(0.5))
                                EVT_SETF(LVar3, EVT_FLOAT(-0.2))
                                EVT_SETF(LVar4, EVT_FLOAT(0.9))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(-690.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-25.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                        EVT_CALL(RemoveItemEntity, LVar7)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_END_THREAD
        EVT_WAIT(10)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, 57)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_9, NPC_ANIM_gate_flower_Palette_02_Anim_8, 0, MESSAGE_ID(0x11, 0x0047))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_9, NPC_ANIM_gate_flower_Palette_02_Anim_8, 0, MESSAGE_ID(0x11, 0x0048))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243B20) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80243214)))
    EVT_IF_EQ(GF_FLO08_GaveYellowBerry, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_5)
        EVT_CALL(ModifyColliderFlags, 0, 17, 0x7FFFFE00)
        EVT_CALL(RotateModel, 103, 50, 0, 1, 0)
        EVT_CALL(RotateModel, 104, 50, 0, 1, 0)
        EVT_CALL(RotateModel, 105, 50, 0, 1, 0)
        EVT_CALL(RotateModel, 99, 120, 0, -1, 0)
        EVT_CALL(RotateModel, 100, 120, 0, -1, 0)
        EVT_CALL(RotateModel, 101, 120, 0, -1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243C48) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_80242FE0),
    .pos = { -695.0f, 0.0f, -30.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243B20),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
        NPC_ANIM_gate_flower_Palette_02_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DB),
};

StaticNpc N(npcGroup_80243E38) = {
    .id = NPC_DAYZEE0,
    .settings = &N(npcSettings_8024305C),
    .pos = { 205.0f, 0.0f, -80.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
	.territory = { .temp = { 205, 0, -80, 30, 0, -32767, 0, 205, 0, -80, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80244028) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_8024305C),
    .pos = { 275.0f, 0.0f, -115.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
	.territory = { .temp = { 275, 0, -115, 30, 0, -32767, 0, 275, 0, -115, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80244218) = {
    .id = NPC_DAYZEE2,
    .settings = &N(npcSettings_8024305C),
    .pos = { -230.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
	.territory = { .temp = { -230, 60, -110, 30, 0, -32767, 0, -230, 60, -110, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_80244408) = {
    .id = NPC_DAYZEE3,
    .settings = &N(npcSettings_8024305C),
    .pos = { -330.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
	.territory = { .temp = { -330, 60, -110, 30, 0, -32767, 0, -330, 60, -110, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802445F8) = {
    .id = NPC_DAYZEE4,
    .settings = &N(npcSettings_8024305C),
    .pos = { -430.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
	.territory = { .temp = { -430, 60, -110, 30, 0, -32767, 0, -430, 60, -110, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802447E8) = {
    .id = NPC_DAYZEE5,
    .settings = &N(npcSettings_8024305C),
    .pos = { -530.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
	.territory = { .temp = { -530, 60, -110, 30, 0, -32767, 0, -530, 60, -110, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(npcGroup_802449D8) = {
    .id = NPC_DAYZEE6,
    .settings = &N(npcSettings_8024305C),
    .pos = { -630.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
	.territory = { .temp = { -630, 60, -110, 30, 0, -32767, 0, -630, 60, -110, 150, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

EvtScript N(init_80244BC8) = {
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(GetNpcPointer, 2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 30)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_2 | NPC_FLAG_4)), TRUE)
            EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
        EVT_ELSE
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_2 | NPC_FLAG_4)), TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80244CD4) = {
    .id = NPC_DAYZEE7,
    .settings = &N(npcSettings_80242FB4),
    .pos = { 240.0f, 0.0f, -90.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80244BC8),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
        { ITEM_HONEY_SYRUP, 24, 0 },
        { ITEM_MAPLE_SYRUP, 25, 0 },
        { ITEM_JAMMIN_JELLY, 1, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(6),
        .minCoinBonus = 5,
        .maxCoinBonus = 8,
    },
	.territory = { .temp = { 240, 0, -90, 30, 0, -32767, 0, 240, 0, -90, 200, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_2,
        NPC_ANIM_dayzee_Palette_01_Anim_3,
        NPC_ANIM_dayzee_Palette_01_Anim_3,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_8,
        NPC_ANIM_dayzee_Palette_01_Anim_8,
        NPC_ANIM_dayzee_Palette_01_Anim_6,
        NPC_ANIM_dayzee_Palette_01_Anim_7,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
        NPC_ANIM_dayzee_Palette_01_Anim_1,
    },
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_80244EC4) = {
    NPC_GROUP(N(npcGroup_80243C48)),
    NPC_GROUP(N(npcGroup_80243E38), 0x1814, 0x00),
    NPC_GROUP(N(npcGroup_80244028), 0x180F, 0x00),
    NPC_GROUP(N(npcGroup_80244218), 0x180F, 0x01),
    NPC_GROUP(N(npcGroup_80244408), 0x180F, 0x01),
    NPC_GROUP(N(npcGroup_802445F8), 0x180F, 0x01),
    NPC_GROUP(N(npcGroup_802447E8), 0x180F, 0x01),
    NPC_GROUP(N(npcGroup_802449D8), 0x1812, 0x01),
    NPC_GROUP(N(npcGroup_80244CD4), 0x181C, 0x00),
    {},
};

static s32 N(pad_4F3C) = {
    0x00000000,
};

#include "world/common/enemy/UnkFloAI.inc.c"

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"

#include "common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 1,
    .models = { 46 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 45 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 340, 102, -89 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(29),
        },
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 440, 102, -89 },
            .spawnMode = 0xC,
            .spawnFlag = AreaFlag(30),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80245904) = { 391.0f, 0.0f, -102.0f, 0.0f };

EvtScript N(80245914) = {
    EVT_SET(AreaFlag(29), 0)
    EVT_SET(AreaFlag(30), 0)
    EVT_SET(LVar0, EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80245904)), 1, 0)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_598C) = {
    0x00000000,
};

EvtScript N(80245990) = {
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

EvtScript N(80245C3C) = {
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

EvtScript N(80245F5C) = {
    EVT_CALL(GetModelCenter, 60)
    EVT_SET(LVar3, 60)
    EVT_SET(LVar4, 61)
    EVT_SET(LVar5, 62)
    EVT_SET(LVar6, 63)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 54)
    EVT_SET(LVar3, 54)
    EVT_SET(LVar4, 55)
    EVT_SET(LVar5, 56)
    EVT_SET(LVar6, 57)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 48)
    EVT_SET(LVar3, 48)
    EVT_SET(LVar4, 49)
    EVT_SET(LVar5, 50)
    EVT_SET(LVar6, 51)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 67)
    EVT_SET(LVar3, 67)
    EVT_SET(LVar4, 66)
    EVT_SET(LVar5, 68)
    EVT_SET(LVar6, 69)
    EVT_SET(LVarA, 174)
    EVT_EXEC(N(80245C3C))
    EVT_RETURN
    EVT_END
};
