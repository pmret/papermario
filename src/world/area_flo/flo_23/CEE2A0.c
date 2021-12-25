#include "flo_23.h"
#include "message_ids.h"
#include "sprite/npc/gate_flower.h"
#include "sprite/npc/spiny.h"
#include "effects.h"

enum {
    NPC_SPINY0,
    NPC_SPINY1,
    NPC_GATE_FLOWER,
};

static s32 N(D_802426E0)[91];
static s8 N(D_8024284C_pad)[4];
static s32 N(D_80242850)[91];
static s32 N(D_802429BC);

EntryList N(entryList) = {
    {  470.0f, 0.0f, 0.0f, 270.0f },
    { -470.0f, 0.0f, 0.0f,  90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_23_tattle },
};

EvtSource N(80240D30) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80240DA0) = {
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

EvtSource N(exitWalk_8024104C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  2);

EvtSource N(exitWalk_802410A8) = EXIT_WALK_SCRIPT(60,  1, "flo_11",  0);

EvtSource N(80241104) = {
    EVT_BIND_TRIGGER(N(exitWalk_802410A8), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024104C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80242568)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_SET(EVT_VAR(0), -290)
    EVT_SET(EVT_VAR(1), -190)
    EVT_SET(EVT_VAR(2), 480)
    EVT_SET(EVT_VAR(3), -90)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80240DA0))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80241104)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80240D30))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
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

s32 N(D_8024130C_CEF56C) = {
    0x00000000,
};

s32 N(D_80241310_CEF570) = {
    0x00000000,
};

EvtSource N(80241314) = {
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
    EVT_CALL(N(func_802402C0_CEE520), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80241448) = {
    EVT_CALL(N(func_802402F8_CEE558), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(80241314), 0x10, 0, EVT_PTR(N(D_802426E0)), 0, 1)
    EVT_CALL(N(func_8024026C_CEE4CC), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_80241498) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 3,
};

EvtSource N(npcAI_802414C8) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(func_80240728_CEE988), EVT_PTR(N(npcAISettings_80241498)))
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

EvtSource N(interact_80241564) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(EVT_SAVE_FLAG(1365), 0)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.5), EVT_FIXED(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x0049))
        EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
        EVT_CALL(N(func_80240C9C_CEEEFC))
        EVT_SET(EVT_VAR(0), EVT_PTR(N(D_80242850)))
        EVT_SET(EVT_VAR(1), 2)
        EVT_EXEC_WAIT(N(80241448))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0, MESSAGE_ID(0x11, 0x004A))
            EVT_CASE_DEFAULT
                EVT_SET(EVT_VAR(8), EVT_VAR(0))
                EVT_CALL(N(func_80240C2C_CEEE8C), EVT_VAR(0))
                EVT_CALL(MakeItemEntity, EVT_VAR(8), 385, 20, -34, 1, 0)
                EVT_SET(EVT_VAR(7), EVT_VAR(0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_3)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                EVT_SWITCH(EVT_VAR(8))
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
                            EVT_SETF(EVT_VAR(8), EVT_VAR(0))
                            EVT_SETF(EVT_VAR(9), EVT_VAR(0))
                            EVT_MULF(EVT_VAR(8), EVT_FIXED(0.5))
                            EVT_MULF(EVT_VAR(9), EVT_FIXED(1.2))
                            EVT_CALL(RotateModel, 59, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 60, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 61, EVT_VAR(8), 0, -1, 0)
                            EVT_CALL(RotateModel, 55, EVT_VAR(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 56, EVT_VAR(9), 0, 1, 0)
                            EVT_CALL(RotateModel, 57, EVT_VAR(9), 0, 1, 0)
                            EVT_WAIT_FRAMES(1)
                            EVT_IF_NE(EVT_VAR(1), 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_5)
                        EVT_SET(EVT_SAVE_FLAG(1365), 1)
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
                        EVT_CALL(MakeItemEntity, EVT_VAR(8), 375, 20, 0, 1, 0)
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
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(380.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-30.0))
                                EVT_CALL(N(func_80240B68_CEEDC8), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
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
                                EVT_SETF(EVT_VAR(4), EVT_FIXED(1.0))
                                EVT_MULF(EVT_VAR(2), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(3), EVT_VAR(0))
                                EVT_MULF(EVT_VAR(4), EVT_VAR(0))
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(390.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-30.0))
                                EVT_CALL(N(func_80240B68_CEEDC8), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
                                EVT_WAIT_FRAMES(1)
                                EVT_IF_NE(EVT_VAR(1), 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                        EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_00_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_00_Anim_2, NPC_ANIM_gate_flower_Palette_00_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FIXED(6.0))
        EVT_END_THREAD
        EVT_WAIT_FRAMES(10)
    EVT_ELSE
        EVT_IF_LT(EVT_SAVE_VAR(0), 57)
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

EvtSource N(init_80241E70) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241564)))
    EVT_IF_EQ(EVT_SAVE_FLAG(1365), 1)
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80241E70),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { 80, 0, 0, 30, 0, -32767, 0, 80, 0, 0, 200, 0, 0, 1 },
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
    .flags = NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 1,
    .movement = { -320, 0, 0, 30, 0, -32767, 0, -320, 0, 0, 200, 0, 0, 1 },
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
    NPC_GROUP(N(npcGroup_80242188), BATTLE_ID(24, 12, 0, 3)),
    NPC_GROUP(N(npcGroup_80242378), BATTLE_ID(24, 13, 0, 3)),
    NPC_GROUP(N(npcGroup_80241F98), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_2598)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(D_802EA0C4), 100, 60, 5, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, 0x802EA588, 100, 145, 0, 0, 131, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1409))
    EVT_CALL(MakeEntity, 0x802EA588, 25, 60, 0, 0, 343, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1408))
    EVT_CALL(MakeEntity, 0x802EAA54, -50, 0, 0, 90, 60, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_8024026C_CEE4CC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024130C_CEF56C) = FALSE;
    }

    if (N(D_8024130C_CEF56C)) {
        N(D_8024130C_CEF56C) = FALSE;
        evt_set_variable(script, *args, N(D_80241310_CEF570));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802402C0_CEE520)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241310_CEF570) = evt_get_variable(script, *args);
    N(D_8024130C_CEF56C) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802402F8_CEE558)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802426E0)[i] = ptr[i];
        }
        N(D_802426E0)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_802426E0)[i] = i + 128;
            N(D_802426E0)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

ApiStatus N(func_80240728_CEE988)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args);
    s32 var;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if ((npc->currentAnim.w + 0xFFAAFFD2) < 2) {
                npc->currentAnim.w = 0x55000C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 0x21) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim.w = 0x55002F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim.w = 0x55002E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 99:
            func_8004A73C(script);
            break;

    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim.w + 0xFFAAFFFC) {
                case 0:
                case 8:
                case 10:
                case 12:
                case 14:
                case 18:
                case 20:
                    npc->currentAnim.w++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80240B68_CEEDC8)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_80240C2C_CEEE8C)(Evt* script, s32 isInitialCall) {
    s32 itemId = evt_get_variable(script, *script->ptrReadPos);
    StaticItem* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & 0x80) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240C9C_CEEEFC)(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_80242850)[i] = 128 + i;
    }

    N(D_802429BC) = 0;
    return ApiStatus_DONE2;
}
