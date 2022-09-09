#include "flo_25.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/bzzap.h"
#include "sprite/npc/gate_flower.h"
#include "sprite/npc/tuff_puff.h"

enum {
    NPC_GATE_FLOWER,
    NPC_TUFF_PUFF,
    NPC_BZZAP,
};

static s32 N(ItemChoiceList)[91];
static s8 N(D_8024510C_pad)[4];
static s32 N(FlowerGuard_ItemChoiceList)[91];

EntryList N(entryList) = {
    {  620.0f, 0.0f, 0.0f, 270.0f },
    { -620.0f, 0.0f, 0.0f,  90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_25_tattle },
};

EvtScript N(80242330) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802423A0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LVarB, LocalVar(1))
    EVT_SET(LVarC, LocalVar(2))
    EVT_SET(LVarD, LocalVar(3))
    EVT_SET(LVarE, LocalVar(4))
    EVT_SUB(LVarC, LocalVar(0))
    EVT_SUB(LVarD, LocalVar(1))
    EVT_SETF(LocalVar(0), LVarC)
    EVT_DIVF(LocalVar(0), EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LocalVar(0))
    EVT_ADD(LVarF, 11)
    EVT_SET(LocalVar(5), 200)
    EVT_DIV(LocalVar(5), LVarF)
    EVT_ADD(LocalVar(5), 1)
    EVT_LOOP(LocalVar(5))
        EVT_CALL(RandInt, LVarC, LocalVar(0))
        EVT_CALL(RandInt, LVarD, LocalVar(1))
        EVT_CALL(RandInt, 199, LocalVar(2))
        EVT_SET(LocalVar(3), 210)
        EVT_SUB(LocalVar(3), LocalVar(2))
        EVT_ADD(LocalVar(0), LVarA)
        EVT_ADD(LocalVar(1), LVarB)
        EVT_ADD(LocalVar(2), LVarE)
        EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(2), LocalVar(1), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LocalVar(0))
    EVT_CALL(RandInt, LVarD, LocalVar(1))
    EVT_ADD(LocalVar(0), LVarA)
    EVT_ADD(LocalVar(1), LVarB)
    EVT_CALL(PlayEffect, 0xD, LocalVar(0), LVarE, LocalVar(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_8024264C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  3);

EvtScript N(exitWalk_802426A8) = EXIT_WALK_SCRIPT(60,  1, "flo_07",  0);

EvtScript N(80242704) = {
    EVT_BIND_TRIGGER(N(exitWalk_802426A8), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024264C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList_80243C5C)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80244D0C))
    EVT_EXEC(N(802446BC))
    EVT_SET(LocalVar(0), -270)
    EVT_SET(LocalVar(1), -190)
    EVT_SET(LocalVar(2), 640)
    EVT_SET(LocalVar(3), -60)
    EVT_SET(LocalVar(4), 60)
    EVT_EXEC(N(802423A0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LocalVar(0), EVT_ADDR(N(80242704)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80242330))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CF2BD0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802428F0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_80242934) = {
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

EvtScript N(npcAI_80242964) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_ADDR(N(npcAISettings_80242934)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802429D4) = {
    .height = 24,
    .radius = 28,
    .ai = &N(npcAI_80242964),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

MobileAISettings N(npcAISettings_80242A00) = {
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

EvtScript N(npcAI_80242A30) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(FlyingAI_Main), EVT_ADDR(N(npcAISettings_80242A00)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80242AA0) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80242A30),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

s32 N(ItemChoice_HasSelectedItem) = {
    0x00000000,
};

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80242AD4) = {
    EVT_SET(LocalVar(9), LocalVar(1))
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(LVarA, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, LocalVar(1))
            EVT_CALL(GetPlayerPos, LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_CALL(N(AddPlayerHandsOffset), LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_CALL(MakeItemEntity, LocalVar(0), LocalVar(3), LocalVar(4), LocalVar(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, LocalVar(0))
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80242C08) = {
    EVT_CALL(N(BuildItemChoiceList), LocalVar(0))
    EVT_BIND_PADLOCK(N(80242AD4), 0x10, 0, EVT_ADDR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LocalVar(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80242C58) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO25_GaveRedBerry, 0)
        EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003B))
        EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_SET(LocalVar(0), EVT_ADDR(N(FlowerGuard_ItemChoiceList)))
        EVT_SET(LocalVar(1), 0)
        EVT_EXEC_WAIT(N(80242C08))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003C))
            EVT_CASE_DEFAULT
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LocalVar(0))
                EVT_CALL(MakeItemEntity, LocalVar(8), 505, 20, -24, 1, 0)
                EVT_SET(LocalVar(7), LocalVar(0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_3)
                EVT_WAIT(20)
                EVT_CALL(RemoveItemEntity, LocalVar(7))
                EVT_SWITCH(LocalVar(8))
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_4, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003F))
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x21C, 0)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_01_Anim_9, NPC_ANIM_gate_flower_Palette_01_Anim_8, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_7)
                        EVT_CALL(PlaySoundAtCollider, 14, 457, 0)
                        EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
                        EVT_CALL(MakeLerp, 0, 100, 30, 1)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LocalVar(8), LocalVar(0))
                            EVT_SETF(LocalVar(9), LocalVar(0))
                            EVT_MULF(LocalVar(8), EVT_FLOAT(0.5))
                            EVT_MULF(LocalVar(9), EVT_FLOAT(1.2))
                            EVT_CALL(RotateModel, 86, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 87, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 88, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 82, LocalVar(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 83, LocalVar(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 84, LocalVar(9), 0, 1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LocalVar(1), 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_5)
                        EVT_SET(GF_FLO25_GaveRedBerry, 1)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_4, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003E))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_4, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003E))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_4, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003D))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_6)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x2096, 0)
                        EVT_CALL(MakeItemEntity, LocalVar(8), -125, 20, 0, 1, 0)
                        EVT_SET(LocalVar(7), LocalVar(0))
                        EVT_WAIT(5)
                        EVT_CALL(GetAngleToPlayer, -1, LocalVar(0))
                        EVT_IF_LT(LocalVar(0), 180)
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LocalVar(2), EVT_FLOAT(-0.5))
                                EVT_SETF(LocalVar(3), EVT_FLOAT(-0.2))
                                EVT_SETF(LocalVar(4), EVT_FLOAT(0.9))
                                EVT_MULF(LocalVar(2), LocalVar(0))
                                EVT_MULF(LocalVar(3), LocalVar(0))
                                EVT_MULF(LocalVar(4), LocalVar(0))
                                EVT_ADDF(LocalVar(2), EVT_FLOAT(500.0))
                                EVT_ADDF(LocalVar(3), EVT_FLOAT(15.0))
                                EVT_ADDF(LocalVar(4), EVT_FLOAT(-20.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LocalVar(7), LocalVar(2), LocalVar(3), LocalVar(4))
                                EVT_WAIT(1)
                                EVT_IF_NE(LocalVar(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_ELSE
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LocalVar(2), EVT_FLOAT(0.5))
                                EVT_SETF(LocalVar(3), EVT_FLOAT(-0.2))
                                EVT_SETF(LocalVar(4), EVT_FLOAT(0.9))
                                EVT_MULF(LocalVar(2), LocalVar(0))
                                EVT_MULF(LocalVar(3), LocalVar(0))
                                EVT_MULF(LocalVar(4), LocalVar(0))
                                EVT_ADDF(LocalVar(2), EVT_FLOAT(510.0))
                                EVT_ADDF(LocalVar(3), EVT_FLOAT(15.0))
                                EVT_ADDF(LocalVar(4), EVT_FLOAT(-20.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LocalVar(7), LocalVar(2), LocalVar(3), LocalVar(4))
                                EVT_WAIT(1)
                                EVT_IF_NE(LocalVar(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                        EVT_CALL(RemoveItemEntity, LocalVar(7))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_END_THREAD
        EVT_WAIT(10)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, 57)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_9, NPC_ANIM_gate_flower_Palette_01_Anim_8, 0, MESSAGE_ID(0x11, 0x0040))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_9, NPC_ANIM_gate_flower_Palette_01_Anim_8, 0, MESSAGE_ID(0x11, 0x0041))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243564) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_ADDR(N(interact_80242C58)))
    EVT_IF_EQ(GF_FLO25_GaveRedBerry, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_5)
        EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
        EVT_CALL(RotateModel, 86, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 87, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 88, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 82, 120, 0, 1, 0)
        EVT_CALL(RotateModel, 83, 120, 0, 1, 0)
        EVT_CALL(RotateModel, 84, 120, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024368C) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_802428F0),
    .pos = { 505.0f, 0.0f, -25.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243564),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
        NPC_ANIM_gate_flower_Palette_01_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DA),
};

StaticNpc N(npcGroup_8024387C) = {
    .id = NPC_TUFF_PUFF,
    .settings = &N(npcSettings_802429D4),
    .pos = { -200.0f, 45.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
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
	.territory = { .temp = { -200, 45, 0, 30, 0, -32767, 0, -200, 45, 0, 200 }},
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

StaticNpc N(npcGroup_80243A6C) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80242AA0),
    .pos = { 150.0f, 55.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
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
	.territory = { .temp = { 150, 50, 0, 30, 0, -32767, 0, 150, 50, 0, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_80243C5C) = {
    NPC_GROUP(N(npcGroup_8024387C), 0x1822, 0x05),
    NPC_GROUP(N(npcGroup_80243A6C), 0x181A, 0x01),
    NPC_GROUP(N(npcGroup_8024368C)),
    {},
};

static s32 N(pad_3C8C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, &Entity_HiddenPanel, -390, 0, 0, 0, 8, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_FLO25_HiddenPanel)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3CD8)[] = {
    0x00000000, 0x00000000,
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"
