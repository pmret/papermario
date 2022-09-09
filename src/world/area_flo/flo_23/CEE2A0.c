#include "flo_23.h"
#include "message_ids.h"
#include "sprite/npc/gate_flower.h"
#include "sprite/npc/spiny.h"
#include "effects.h"
#include "entity.h"

enum {
    NPC_SPINY0,
    NPC_SPINY1,
    NPC_GATE_FLOWER,
};

static s32 N(ItemChoiceList)[91];
static s8 N(D_8024284C_pad)[4];
static s32 N(FlowerGuard_ItemChoiceList)[91];

EntryList N(entryList) = {
    {  470.0f, 0.0f, 0.0f, 270.0f },
    { -470.0f, 0.0f, 0.0f,  90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_23_tattle },
};

EvtScript N(80240D30) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80240DA0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_SET(LocalVar(12), LocalVar(2))
    EVT_SET(LocalVar(13), LocalVar(3))
    EVT_SET(LocalVar(14), LocalVar(4))
    EVT_SUB(LocalVar(12), LocalVar(0))
    EVT_SUB(LocalVar(13), LocalVar(1))
    EVT_SETF(LocalVar(0), LocalVar(12))
    EVT_DIVF(LocalVar(0), EVT_FIXED(100.0))
    EVT_SETF(LocalVar(15), EVT_FIXED(100.0))
    EVT_DIVF(LocalVar(15), LocalVar(0))
    EVT_ADD(LocalVar(15), 11)
    EVT_SET(LocalVar(5), 200)
    EVT_DIV(LocalVar(5), LocalVar(15))
    EVT_ADD(LocalVar(5), 1)
    EVT_LOOP(LocalVar(5))
        EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
        EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
        EVT_CALL(RandInt, 199, LocalVar(2))
        EVT_SET(LocalVar(3), 210)
        EVT_SUB(LocalVar(3), LocalVar(2))
        EVT_ADD(LocalVar(0), LocalVar(10))
        EVT_ADD(LocalVar(1), LocalVar(11))
        EVT_ADD(LocalVar(2), LocalVar(14))
        EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(2), LocalVar(1), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LocalVar(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, LocalVar(12), LocalVar(0))
    EVT_CALL(RandInt, LocalVar(13), LocalVar(1))
    EVT_ADD(LocalVar(0), LocalVar(10))
    EVT_ADD(LocalVar(1), LocalVar(11))
    EVT_CALL(PlayEffect, 0xD, LocalVar(0), LocalVar(14), LocalVar(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LocalVar(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_8024104C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  2);

EvtScript N(exitWalk_802410A8) = EXIT_WALK_SCRIPT(60,  1, "flo_11",  0);

EvtScript N(80241104) = {
    EVT_BIND_TRIGGER(N(exitWalk_802410A8), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024104C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
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
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80242568)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_SET(LocalVar(0), -290)
    EVT_SET(LocalVar(1), -190)
    EVT_SET(LocalVar(2), 480)
    EVT_SET(LocalVar(3), -90)
    EVT_SET(LocalVar(4), 0)
    EVT_EXEC(N(80240DA0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(LocalVar(0), EVT_PTR(N(80241104)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80240D30))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240000_CEE260))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_12D8)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_802412E0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

s32 N(ItemChoice_HasSelectedItem) = {
    0x00000000,
};

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80241314) = {
    EVT_SET(LocalVar(9), LocalVar(1))
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(LocalVar(10), LocalVar(0))
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
    EVT_CALL(N(ItemChoice_SaveSelected), LocalVar(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80241448) = {
    EVT_CALL(N(BuildItemChoiceList), LocalVar(0))
    EVT_BIND_PADLOCK(N(80241314), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LocalVar(0))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_80241498) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 3,
};

EvtScript N(npcAI_802414C8) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(npcAISettings_80241498)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241538) = {
    .height = 21,
    .radius = 22,
    .ai = &N(npcAI_802414C8),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

EvtScript N(interact_80241564) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO23_GaveBlueBerry, 0)
        EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.5), EVT_FIXED(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0049))
        EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_SET(LocalVar(0), EVT_PTR(N(FlowerGuard_ItemChoiceList)))
        EVT_SET(LocalVar(1), 2)
        EVT_EXEC_WAIT(N(80241448))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004A))
            EVT_CASE_DEFAULT
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LocalVar(0))
                EVT_CALL(MakeItemEntity, LocalVar(8), 385, 20, -34, 1, 0)
                EVT_SET(LocalVar(7), LocalVar(0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_3)
                EVT_WAIT(20)
                EVT_CALL(RemoveItemEntity, LocalVar(7))
                EVT_SWITCH(LocalVar(8))
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_4, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004D))
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x21C, 0)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_00_Anim_9, NPC_ANIM_gate_flower_Palette_00_Anim_8, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_7)
                        EVT_CALL(PlaySoundAtCollider, 13, 457, 0)
                        EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
                        EVT_CALL(MakeLerp, 0, 100, 30, 1)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LocalVar(8), LocalVar(0))
                            EVT_SETF(LocalVar(9), LocalVar(0))
                            EVT_MULF(LocalVar(8), EVT_FIXED(0.5))
                            EVT_MULF(LocalVar(9), EVT_FIXED(1.2))
                            EVT_CALL(RotateModel, 59, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 60, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 61, LocalVar(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 55, LocalVar(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 56, LocalVar(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 57, LocalVar(9), 0, 1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LocalVar(1), 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_5)
                        EVT_SET(GF_FLO23_GaveBlueBerry, 1)
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_4, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004C))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_4, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004C))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_4, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004B))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_6)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x2096, 0)
                        EVT_CALL(MakeItemEntity, LocalVar(8), 375, 20, 0, 1, 0)
                        EVT_SET(LocalVar(7), LocalVar(0))
                        EVT_WAIT(5)
                        EVT_CALL(GetAngleToPlayer, -1, LocalVar(0))
                        EVT_IF_LT(LocalVar(0), 180)
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LocalVar(2), EVT_FIXED(-0.5))
                                EVT_SETF(LocalVar(3), EVT_FIXED(-0.2))
                                EVT_SETF(LocalVar(4), EVT_FIXED(0.9))
                                EVT_MULF(LocalVar(2), LocalVar(0))
                                EVT_MULF(LocalVar(3), LocalVar(0))
                                EVT_MULF(LocalVar(4), LocalVar(0))
                                EVT_ADDF(LocalVar(2), EVT_FIXED(380.0))
                                EVT_ADDF(LocalVar(3), EVT_FIXED(15.0))
                                EVT_ADDF(LocalVar(4), EVT_FIXED(-30.0))
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
                                EVT_SETF(LocalVar(2), EVT_FIXED(0.5))
                                EVT_SETF(LocalVar(3), EVT_FIXED(-0.2))
                                EVT_SETF(LocalVar(4), EVT_FIXED(1.0))
                                EVT_MULF(LocalVar(2), LocalVar(0))
                                EVT_MULF(LocalVar(3), LocalVar(0))
                                EVT_MULF(LocalVar(4), LocalVar(0))
                                EVT_ADDF(LocalVar(2), EVT_FIXED(390.0))
                                EVT_ADDF(LocalVar(3), EVT_FIXED(15.0))
                                EVT_ADDF(LocalVar(4), EVT_FIXED(-30.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LocalVar(7), LocalVar(2), LocalVar(3), LocalVar(4))
                                EVT_WAIT(1)
                                EVT_IF_NE(LocalVar(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                        EVT_CALL(RemoveItemEntity, LocalVar(7))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FIXED(6.0))
        EVT_END_THREAD
        EVT_WAIT(10)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, 57)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_9, NPC_ANIM_gate_flower_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x004E))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_9, NPC_ANIM_gate_flower_Palette_00_Anim_8, 0, MESSAGE_ID(0x11, 0x004F))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241E70) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241564)))
    EVT_IF_EQ(GF_FLO23_GaveBlueBerry, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_5)
        EVT_CALL(ModifyColliderFlags, 0, 13, 0x7FFFFE00)
        EVT_CALL(RotateModel, 59, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 60, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 61, 50, 0, -1, 0)
        EVT_CALL(RotateModel, 55, 120, 0, 1, 0)
        EVT_CALL(RotateModel, 56, 120, 0, 1, 0)
        EVT_CALL(RotateModel, 57, 120, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80241F98) = {
    .id = NPC_GATE_FLOWER,
    .settings = &N(npcSettings_802412E0),
    .pos = { 385.0f, 0.0f, -35.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80241E70),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
        NPC_ANIM_gate_flower_Palette_00_Anim_1,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00DC),
};

StaticNpc N(npcGroup_80242188) = {
    .id = NPC_SPINY0,
    .settings = &N(npcSettings_80241538),
    .pos = { 80.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { 80, 0, 0, 30, 0, -32767, 0, 80, 0, 0, 200, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80242378) = {
    .id = NPC_SPINY1,
    .settings = &N(npcSettings_80241538),
    .pos = { -320.0f, 0.0f, 0.0f },
    .flags = NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 1,
    },
	.territory = { .temp = { -320, 0, 0, 30, 0, -32767, 0, -320, 0, 0, 200, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_3,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_4,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_9,
        NPC_ANIM_spiny_Palette_00_Anim_6,
        NPC_ANIM_spiny_Palette_00_Anim_8,
        NPC_ANIM_spiny_Palette_00_Anim_7,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
        NPC_ANIM_spiny_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_80242568) = {
    NPC_GROUP(N(npcGroup_80242188), 0x180C, 0x02),
    NPC_GROUP(N(npcGroup_80242378), 0x180D, 0x02),
    NPC_GROUP(N(npcGroup_80241F98)),
    {},
};

static s32 N(pad_2598)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 100, 60, 5, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 100, 145, 0, 0, 131, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO23_HiddenItem_ShootingStar)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 25, 60, 0, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO23_HiddenItem_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), -50, 0, 0, 90, 60, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"
