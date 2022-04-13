#include "flo_25.h"
#include "message_ids.h"
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
static s32 N(D_80245110)[91];
static s32 N(D_8024527C);

EntryList N(entryList) = {
    {  620.0f, 0.0f, 0.0f, 270.0f },
    { -620.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_25_tattle },
};

EvtScript N(80242330) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802423A0) = {
    EVT_SET_GROUP(EVT_GROUP_B)
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

EvtScript N(exitWalk_8024264C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  3);

EvtScript N(exitWalk_802426A8) = EXIT_WALK_SCRIPT(60,  1, "flo_07",  0);

EvtScript N(80242704) = {
    EVT_BIND_TRIGGER(N(exitWalk_802426A8), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024264C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80243C5C)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80244D0C))
    EVT_EXEC(N(802446BC))
    EVT_SET(EVT_VAR(0), -270)
    EVT_SET(EVT_VAR(1), -190)
    EVT_SET(EVT_VAR(2), 640)
    EVT_SET(EVT_VAR(3), -60)
    EVT_SET(EVT_VAR(4), 60)
    EVT_EXEC(N(802423A0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80242704)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80242330))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
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

f32 N(sixFloats)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80242934) = {
    .moveSpeed = 1.0f,
    .moveTime = 45,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .unk_14 = 3,
    .chaseSpeed = 3.6f,
    .unk_1C = { .s = 10 },
    .unk_20 = 1,
    .chaseRadius = 120.0f,
    .unk_2C = 1,
};

EvtScript N(npcAI_80242964) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(UnkNpcAIMainFunc10), EVT_PTR(N(npcAISettings_80242934)))
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

NpcAISettings N(npcAISettings_80242A00) = {
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

EvtScript N(npcAI_80242A30) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(UnkNpcAIMainFunc9), EVT_PTR(N(npcAISettings_80242A00)))
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

s32 N(D_80242ACC_CF569C) = {
    0x00000000,
};

s32 N(D_80242AD0_CF56A0) = {
    0x00000000,
};

EvtScript N(80242AD4) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(1))
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, EVT_VAR(1))
            EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(N(AddPlayerHandsOffset), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(MakeItemEntity, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, EVT_VAR(0))
    EVT_END_SWITCH
    EVT_CALL(N(func_80241DAC_CF497C), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80242C08) = {
    EVT_CALL(N(BuildItemChoiceList), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(80242AD4), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80241D58_CF4928), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80242C58) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(EVT_SAVE_FLAG(1363), 0)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.5), EVT_FIXED(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003B))
        EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
        EVT_CALL(N(func_80241FB4_CF4B84))
        EVT_SET(EVT_VAR(0), EVT_PTR(N(D_80245110)))
        EVT_SET(EVT_VAR(1), 0)
        EVT_EXEC_WAIT(N(80242C08))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0, MESSAGE_ID(0x11, 0x003C))
            EVT_CASE_DEFAULT
                EVT_SET(EVT_VAR(8), EVT_VAR(0))
                EVT_CALL(N(func_80241F44_CF4B14), EVT_VAR(0))
                EVT_CALL(MakeItemEntity, EVT_VAR(8), 505, 20, -24, 1, 0)
                EVT_SET(EVT_VAR(7), EVT_VAR(0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_3)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                EVT_SWITCH(EVT_VAR(8))
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
                            EVT_SETF(EVT_VAR(8), EVT_VAR(0))
                            EVT_SETF(EVT_VAR(9), EVT_VAR(0))
                            EVT_MULF(EVT_VAR(8), EVT_FIXED(0.5))
                            EVT_MULF(EVT_VAR(9), EVT_FIXED(1.2))
                            EVT_CALL(RotateModel, 86, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 87, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 88, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 82, EVT_VAR(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 83, EVT_VAR(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 84, EVT_VAR(9), 0, 1, 0)
                            EVT_WAIT_FRAMES(1)
                            EVT_IF_NE(EVT_VAR(1), 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_5)
                        EVT_SET(EVT_SAVE_FLAG(1363), 1)
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
                        EVT_CALL(MakeItemEntity, EVT_VAR(8), -125, 20, 0, 1, 0)
                        EVT_SET(EVT_VAR(7), EVT_VAR(0))
                        EVT_WAIT_FRAMES(5)
                        EVT_CALL(GetAngleToPlayer, -1, EVT_VAR(0))
                        EVT_IF_LT(EVT_VAR(0), 180)
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(EVT_VAR(2), EVT_FIXED(-0.5))
                                EVT_SETF(EVT_VAR(3), EVT_FIXED(-0.2))
                                EVT_SETF(EVT_VAR(4), EVT_FIXED(0.9))
                                EVT_MULF(EVT_VAR(2), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(3), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(4), EVT_VAR(0))
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(500.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-20.0))
                                EVT_CALL(N(func_80241E80_CF4A50), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
                                EVT_WAIT_FRAMES(1)
                                EVT_IF_NE(EVT_VAR(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_ELSE
                            EVT_CALL(MakeLerp, 0, 100, 7, 0)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(EVT_VAR(2), EVT_FIXED(0.5))
                                EVT_SETF(EVT_VAR(3), EVT_FIXED(-0.2))
                                EVT_SETF(EVT_VAR(4), EVT_FIXED(0.9))
                                EVT_MULF(EVT_VAR(2), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(3), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(4), EVT_VAR(0))
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(510.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-20.0))
                                EVT_CALL(N(func_80241E80_CF4A50), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
                                EVT_WAIT_FRAMES(1)
                                EVT_IF_NE(EVT_VAR(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                        EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_01_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_01_Anim_2, NPC_ANIM_gate_flower_Palette_01_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FIXED(6.0))
        EVT_END_THREAD
        EVT_WAIT_FRAMES(10)
    EVT_ELSE
        EVT_IF_LT(EVT_SAVE_VAR(0), 57)
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
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80242C58)))
    EVT_IF_EQ(EVT_SAVE_FLAG(1363), 1)
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243564),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 10,
    .itemDrops = {
        { ITEM_THUNDER_RAGE, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -200, 45, 0, 30, 0, -32767, 0, -200, 45, 0, 200 },
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
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_80243A6C) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80242AA0),
    .pos = { 150.0f, 55.0f, 0.0f },
    .flags = NPC_FLAG_LOCK_ANIMS,
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
    .movement = { 150, 50, 0, 30, 0, -32767, 0, 150, 50, 0, 200, 0, 0, 1 },
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

NpcGroupList N(npcGroupList_80243C5C) = {
    NPC_GROUP(N(npcGroup_8024387C), BATTLE_ID(24, 34, 0, 6)),
    NPC_GROUP(N(npcGroup_80243A6C), BATTLE_ID(24, 26, 0, 2)),
    NPC_GROUP(N(npcGroup_8024368C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_3C8C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAB04, -390, 0, 0, 0, 8, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, EVT_SAVE_FLAG(1407))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3CD8)[] = {
    0x00000000, 0x00000000,
};

#include "world/common/atomic/enemy/UnkAI_9.inc.c"

#include "world/common/atomic/enemy/UnkAI_10.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80241D58_CF4928)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242ACC_CF569C) = FALSE;
    }

    if (N(D_80242ACC_CF569C)) {
        N(D_80242ACC_CF569C) = FALSE;
        evt_set_variable(script, *args, N(D_80242AD0_CF56A0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241DAC_CF497C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242AD0_CF56A0) = evt_get_variable(script, *args);
    N(D_80242ACC_CF569C) = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/atomic/MakeConsumableChoice.inc.c"

ApiStatus N(func_80241E80_CF4A50)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(itemIdx);

    item->position.x = var1;
    item->position.y = var2;
    item->position.z = var3;

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241F44_CF4B14)(Evt* script, s32 isInitialCall) {
    s32 itemId = evt_get_variable(script, *script->ptrReadPos);
    ItemData* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241FB4_CF4B84)(Evt* script, s32 isInitialCall) {
    s32 i;

    // iterate over range of valid consumables
    for (i = 0; i <= (ITEM_LAST_VALID_CONSUMABLE - ITEM_FIRST_CONSUMABLE); i++) {
        N(D_80245110)[i] = ITEM_FIRST_CONSUMABLE + i;
    }

    N(D_8024527C) = 0;
    return ApiStatus_DONE2;
}
