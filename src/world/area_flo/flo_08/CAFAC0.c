#include "flo_08.h"
#include "message_ids.h"
#include "sprite/npc/dayzee.h"
#include "sprite/npc/gate_flower.h"
#include "effects.h"

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
static s32 N(D_802462C0_B4AA30)[91];
static s8 N(D_802462C4_pad);
static s32 N(D_80246428)[91];
static s32 N(D_8024659C);

// DATA
EntryList N(entryList) = {
    { -870.0f, 0.0f, 0.0f,  90.0f },
    {  570.0f, 0.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_08_tattle },
};

EvtSource N(80241F40) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80241FB0_CB0CF0)[] = {
    0x001D00F0, 0x001D00F1,
};

s16 N(D_80241FB8_CB0CF8)[] = {
    0x0001, 0x0002, 0x0003, 0x0004,
    0x0009, 0x0006, 0x0007, 0x0008
};

s32 N(D_80241FC8_CB0D08)[8][2] = {
    { 0x001D00E0, 0x001D00E1 }, { 0x001D00E2, 0x001D00E3 },
    { 0x001D00E4, 0x001D00E5 }, { 0x001D00E6, 0x001D00E7 },
    { 0x001D00E8, 0x001D00E9 }, { 0x001D00EA, 0x001D00EB },
    { 0x001D00EC, 0x001D00ED }, { 0x001D00EE, 0x001D00EF }
};

f32 N(D_80242008_CB0D48)[3] = {
    140.0f, 180.0f, 220.0f
};

EvtSource N(80242014) = {
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySound, 0x212D)
    EVT_CALL(N(UnkFunc21), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(85)
    EVT_THREAD
        EVT_CALL(PlaySound, 0x212E)
        EVT_CALL(N(UnkFunc23), 70, 70)
        EVT_WAIT_FRAMES(27)
        EVT_CALL(PlaySound, SOUND_208E)
        EVT_CALL(N(UnkFunc23), 50, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(N(func_8024003C_CAED7C), EVT_MAP_VAR(0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(47)
        EVT_CALL(N(UnkFunc22))
        EVT_CALL(N(UnkPartnerPosFunc))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc2))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(3)
    EVT_CALL(N(func_80240600_CAF340), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(30)
    EVT_RETURN
    EVT_END
};

EvtSource N(80242178) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1402), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsStartingConversation, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkFunc40))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, 2097152)
    EVT_CALL(N(SetOverrideFlags_40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(N(UnkFunc20), EVT_MAP_VAR(0), EVT_VAR(9))
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, EVT_VAR(12))
    EVT_CALL(N(UnkFunc38))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DC), 160, 40)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(438), 0)
        EVT_SET(EVT_SAVE_FLAG(438), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DA), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DB), 160, 40)
    EVT_END_IF
    EVT_CALL(N(func_802401CC_CAEF0C))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), EVT_VAR(11))
        EVT_CALL(N(SwitchToPartner), EVT_VAR(11))
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DF), 160, 40)
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_CALL(CloseMessage)
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(80242014))
    EVT_CALL(N(UnkFunc18), EVT_VAR(11), EVT_VAR(13))
    EVT_SET(EVT_SAVE_FLAG(1402), 1)
    EVT_CALL(N(UnkFunc39), EVT_VAR(9))
    EVT_CALL(N(UnkFunc19))
    EVT_IF_EQ(EVT_VAR(13), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DD), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DE), 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
    EVT_CALL(N(UnkFunc17))
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA910, -780, 120, -110, 0, MAKE_ENTITY_END)
    EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1402))
    EVT_CALL(AssignScript, EVT_PTR(N(80242178)))
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 510, 0, -90, 17, EVT_SAVE_FLAG(1381))
    EVT_RETURN
    EVT_END
};

EvtSource N(80242680) = {
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

EvtSource N(exitWalk_8024292C) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  6);

EvtSource N(exitWalk_80242988) = EXIT_WALK_SCRIPT(60,  1, "flo_24",  0);

EvtSource N(802429E4) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024292C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80242988), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_80242A2C)[] = {
    0x00000009, 0xC4070000, 0x00000000, 0x42480000, 0x0000000A, 0x42700000, 0x00000000, 0x42480000,
    0x0000000F, 0x42700000, 0x00000000, 0x42480000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
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
        EVT_SET(EVT_VAR(0), 0)
        EVT_SET(EVT_VAR(1), 0)
        EVT_LABEL(0)
        EVT_ADD(EVT_VAR(0), 140)
        EVT_IF_GT(EVT_VAR(0), 65536)
            EVT_ADD(EVT_VAR(0), -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, EVT_VAR(0), 0)
        EVT_ADD(EVT_VAR(1), -200)
        EVT_IF_LT(EVT_VAR(1), 0)
            EVT_ADD(EVT_VAR(1), 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, EVT_VAR(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, 3, 21, 0x00000006)
    EVT_SET(EVT_VAR(0), 140)
    EVT_SET(EVT_VAR(1), -137)
    EVT_SET(EVT_VAR(2), 340)
    EVT_SET(EVT_VAR(3), -60)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242680))
    EVT_SET(EVT_VAR(0), 450)
    EVT_SET(EVT_VAR(1), -137)
    EVT_SET(EVT_VAR(2), 590)
    EVT_SET(EVT_VAR(3), -60)
    EVT_SET(EVT_VAR(4), 0)
    EVT_EXEC(N(80242680))
    EVT_EXEC(N(80245914))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802429E4)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(80241F40))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240D40_CAFA80))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_2EA8)[] = {
    0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80242EB0) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 3,
    .chaseSpeed = 2.4f,
    .unk_1C = { .s = 15 },
    .unk_20 = 1,
    .chaseRadius = 140.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_80242EE0) = {
    EVT_CALL(N(func_8024150C_CB024C), EVT_PTR(N(npcAISettings_80242EB0)))
    EVT_RETURN
    EVT_END
};

EvtSource N(80242F00) = {
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 30)
    EVT_SUB(EVT_VAR(2), 2)
    EVT_CALL(PlayEffect, 0x11, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80242FB4) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_80242EE0),
    .onHit = EnemyNpcHit,
    .aux = &N(80242F00),
    .onDefeat = EnemyNpcDefeat,
    .level = 100,
};

NpcSettings N(npcSettings_80242FE0) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcAISettings N(npcAISettings_8024300C) = {
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

EvtSource N(npcAI_8024303C) = {
    EVT_CALL(DoBasicAI, EVT_PTR(N(npcAISettings_8024300C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024305C) = {
    .height = 30,
    .radius = 24,
    .ai = &N(npcAI_8024303C),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

s32 N(D_80243088_CB1DC8) = FALSE;

s32 N(D_8024308C_CB1DCC) = {
    0x00000000,
};

EvtSource N(80243090) = {
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
    EVT_CALL(N(func_802419C4_CB0704), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(802431C4) = {
    EVT_CALL(N(func_802419FC_CB073C), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(80243090), 0x10, 0, EVT_PTR(D_802462C0_B4AA30), 0, 1)
    EVT_CALL(N(func_80241970_CB06B0), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80243214) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(EVT_SAVE_FLAG(1364), 0)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetCamDistance, 0, 350)
        EVT_CALL(SetCamPitch, 0, EVT_FIXED(18.5), EVT_FIXED(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0042))
        EVT_CALL(SetPlayerAnimation, ANIM_THINKING)
        EVT_CALL(N(func_80241BCC_CB090C))
        EVT_SET(EVT_VAR(0), EVT_PTR(N(D_80246428)))
        EVT_SET(EVT_VAR(1), 0)
        EVT_EXEC_WAIT(N(802431C4))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0, MESSAGE_ID(0x11, 0x0043))
            EVT_CASE_DEFAULT
                EVT_SET(EVT_VAR(8), EVT_VAR(0))
                EVT_CALL(N(func_80241B5C_CB089C), EVT_VAR(0))
                EVT_CALL(MakeItemEntity, EVT_VAR(8), -695, 20, -29, 1, 0)
                EVT_SET(EVT_VAR(7), EVT_VAR(0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_3)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                EVT_SWITCH(EVT_VAR(8))
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
                            EVT_SETF(EVT_VAR(8), EVT_VAR(0))
                            EVT_SETF(EVT_VAR(9), EVT_VAR(0))
                            EVT_MULF(EVT_VAR(8), EVT_FIXED(0.5))
                            EVT_MULF(EVT_VAR(9), EVT_FIXED(1.2))
                            EVT_CALL(RotateModel, 103, EVT_VAR(8), 0, 1, 0)
                            EVT_CALL(RotateModel, 104, EVT_VAR(8), 0, 1, 0)
                            EVT_CALL(RotateModel, 105, EVT_VAR(8), 0, 1, 0)
                            EVT_CALL(RotateModel, 99, EVT_VAR(9), 0, -1, 0)
                            EVT_CALL(RotateModel, 100, EVT_VAR(9), 0, -1, 0)
                            EVT_CALL(RotateModel, 101, EVT_VAR(9), 0, -1, 0)
                            EVT_WAIT_FRAMES(1)
                            EVT_IF_NE(EVT_VAR(1), 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_5)
                        EVT_SET(EVT_SAVE_FLAG(1364), 1)
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
                        EVT_CALL(MakeItemEntity, EVT_VAR(8), 125, 20, 0, 1, 0)
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
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(-700.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-25.0))
                                EVT_CALL(N(func_80241A98_CB07D8), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
                                EVT_WAIT_FRAMES(1)
                                EVT_IF_EQ(EVT_VAR(1), 0)
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
                                EVT_ADDF(EVT_VAR(2), EVT_FIXED(-690.0))
                                EVT_ADDF(EVT_VAR(3), EVT_FIXED(15.0))
                                EVT_ADDF(EVT_VAR(4), EVT_FIXED(-25.0))
                                EVT_CALL(N(func_80241A98_CB07D8), EVT_VAR(7), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
                                EVT_WAIT_FRAMES(1)
                                EVT_IF_EQ(EVT_VAR(1), 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                        EVT_CALL(RemoveItemEntity, EVT_VAR(7))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_gate_flower_Palette_02_Anim_1)
                        EVT_CALL(EndSpeech, -1, NPC_ANIM_gate_flower_Palette_02_Anim_2, NPC_ANIM_gate_flower_Palette_02_Anim_1, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, 0, EVT_FIXED(6.0))
        EVT_END_THREAD
        EVT_WAIT_FRAMES(10)
    EVT_ELSE
        EVT_IF_LT(EVT_SAVE_VAR(0), 57)
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

EvtSource N(init_80243B20) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80243214)))
    EVT_IF_EQ(EVT_SAVE_FLAG(1364), 1)
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
    .init = &N(init_80243B20),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
    .movement = { 205, 0, -80, 30, 0, -32767, 0, 205, 0, -80, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_80244028) = {
    .id = NPC_DAYZEE1,
    .settings = &N(npcSettings_8024305C),
    .pos = { 275.0f, 0.0f, -115.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
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
    .movement = { 275, 0, -115, 30, 0, -32767, 0, 275, 0, -115, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_80244218) = {
    .id = NPC_DAYZEE2,
    .settings = &N(npcSettings_8024305C),
    .pos = { -230.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
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
    .movement = { -230, 60, -110, 30, 0, -32767, 0, -230, 60, -110, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_80244408) = {
    .id = NPC_DAYZEE3,
    .settings = &N(npcSettings_8024305C),
    .pos = { -330.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
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
    .movement = { -330, 60, -110, 30, 0, -32767, 0, -330, 60, -110, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_802445F8) = {
    .id = NPC_DAYZEE4,
    .settings = &N(npcSettings_8024305C),
    .pos = { -430.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
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
    .movement = { -430, 60, -110, 30, 0, -32767, 0, -430, 60, -110, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_802447E8) = {
    .id = NPC_DAYZEE5,
    .settings = &N(npcSettings_8024305C),
    .pos = { -530.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
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
    .movement = { -530, 60, -110, 30, 0, -32767, 0, -530, 60, -110, 200, 0, 0, 1 },
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

StaticNpc N(npcGroup_802449D8) = {
    .id = NPC_DAYZEE6,
    .settings = &N(npcSettings_8024305C),
    .pos = { -630.0f, 60.0f, -110.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
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
    .movement = { -630, 60, -110, 30, 0, -32767, 0, -630, 60, -110, 150, 0, 0, 1 },
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

EvtSource N(init_80244BC8) = {
    EVT_THREAD
        EVT_WAIT_FRAMES(2)
        EVT_CALL(GetNpcPointer, 2, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(RandInt, 100, EVT_VAR(0))
        EVT_IF_LT(EVT_VAR(0), 30)
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(init_80244BC8),
    .yaw = 270,
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
    .movement = { 240, 0, -90, 30, 0, -32767, 0, 240, 0, -90, 200, 0, 0, 1 },
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
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244EC4) = {
    NPC_GROUP(N(npcGroup_80243C48), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80243E38), BATTLE_ID(24, 20, 0, 1)),
    NPC_GROUP(N(npcGroup_80244028), BATTLE_ID(24, 15, 0, 1)),
    NPC_GROUP(N(npcGroup_80244218), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_80244408), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802445F8), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802447E8), BATTLE_ID(24, 15, 0, 2)),
    NPC_GROUP(N(npcGroup_802449D8), BATTLE_ID(24, 18, 0, 2)),
    NPC_GROUP(N(npcGroup_80244CD4), BATTLE_ID(24, 28, 0, 1)),
    {},
};

static s32 N(pad_4F3C) = {
    0x00000000,
};

void N(func_80240D80_CAFAC0)(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 temp_f0;
    f32 temp_f20;
    f64 temp_f2;
    f32 phi_f22;
    f32 phi_f24;
    f32 phi_f26;
    s32 phi_s3;

    f32 subroutine_arg8;
    f32 subroutine_arg9;
    f32 subroutine_argA;
    f32 subroutine_argB;
    f32 subroutine_argC;
    f32 subroutine_argD;
    f32 subroutine_argE;
    f32 subroutine_argF;
    f32 subroutine_arg10;

    npc->duration = npcAISettings->unk_20 / 2 + rand_int(npcAISettings->unk_20 / 2 + 1);
    npc->currentAnim.w = enemy->animList[3];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    phi_s3 = FALSE;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
    if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
        temp_f20 = npc->yaw;
        if (temp_f0 < 0.0f) {
            temp_f20 += -npcAISettings->unk_1C.s;
        } else {
            temp_f20 += npcAISettings->unk_1C.s;
        }
    }

    npc->yaw = clamp_angle(temp_f20);

    subroutine_arg8 = npc->pos.x;
    subroutine_arg9 = npc->pos.y;
    subroutine_argA = npc->pos.z;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    phi_f22 = 0.0f;
    phi_f24 = 0.0f;
    phi_f26 = 0.0f;

    if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_arg8, &subroutine_arg9, &subroutine_argA, npc->moveSpeed * 4.5, temp_f20,
                      npc->collisionHeight, npc->collisionRadius) != 0) {
        phi_f22 = dist2D(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);

        subroutine_argB = npc->pos.x;
        subroutine_argC = npc->pos.y;
        subroutine_argD = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_argB, &subroutine_argC, &subroutine_argD, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 + 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f24 = dist2D(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
        }

        subroutine_argE = npc->pos.x;
        subroutine_argF = npc->pos.y;
        subroutine_arg10 = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_argE, &subroutine_argF, &subroutine_arg10, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 - 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f26 = dist2D(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
        }

        dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if ((phi_f22 < npc->moveSpeed * 1.5) && (phi_f24 < npc->moveSpeed * 1.5) && (phi_f26 < npc->moveSpeed * 1.5) &&
            (func_800490B4(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_10.f, 0) != 0)) {
            phi_s3 = TRUE;
        }

        if (!phi_s3) {
            if ((phi_f24 < phi_f22) && (phi_f26 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f24 < phi_f22) && (phi_f24 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f22 < phi_f24) && (phi_f26 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f26 < phi_f24) && (phi_f22 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f22 < phi_f26) && (phi_f24 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            } else if ((phi_f24 < phi_f26) && (phi_f22 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            }

            temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
            if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
                temp_f20 = npc->yaw;
                if (temp_f0 < 0.0f) {
                    temp_f20 += -npcAISettings->unk_1C.s;
                } else {
                    temp_f20 += npcAISettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(temp_f20);
        }
    }
    if (phi_s3) {
        npc->duration = 0xA;
        npc->currentAnim.w = enemy->animList[8];
    }
    script->functionTemp[0] = 0xD;
}

void N(func_80241364_CB00A4)(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, npcAISettings->chaseRadius, npcAISettings->unk_28.f, 1) == 0) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0] = 14;
    } else {
        if (npc->currentAnim.w != enemy->animList[8]) {
            if (npc->moveSpeed < 4.0) {
                func_8003D660(npc, 0);
            } else {
                func_8003D660(npc, 1);
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
        if (npc->duration > 0) {
            npc->duration--;
            return;
        } else {
            script->functionTemp[0] = 12;
        }
    }
}

void N(func_802414C8_CB0208)(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = NULL;
    }
}

ApiStatus N(func_8024150C_CB024C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, npcAISettings, territoryPtr);
        case 1:
            func_800496B8(script, npcAISettings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, npcAISettings, territoryPtr);
        case 3:
            func_80049C04(script, npcAISettings, territoryPtr);
            break;
        case 10:
            func_80049E3C(script, npcAISettings, territoryPtr);
        case 11:
            func_80049ECC(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(func_80240D80_CAFAC0)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80241364_CB00A4)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(func_802414C8_CB0208)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80241970_CB06B0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80243088_CB1DC8) = FALSE;
    }

    if (N(D_80243088_CB1DC8)) {
        N(D_80243088_CB1DC8) = FALSE;
        evt_set_variable(script, *args, N(D_8024308C_CB1DCC));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802419C4_CB0704)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024308C_CB1DCC) = evt_get_variable(script, *args);
    N(D_80243088_CB1DC8) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802419FC_CB073C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802462C0_B4AA30)[i] = ptr[i];
        }
        N(D_802462C0_B4AA30)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_802462C0_B4AA30)[i] = i + 128;
            N(D_802462C0_B4AA30)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241A98_CB07D8)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_80241B5C_CB089C)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_80241BCC_CB090C)(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_80246428)[i] = 128 + i;
    }

    N(D_8024659C) = 0;
    return ApiStatus_DONE2;
}

#include "world/common/foliage.inc.c"

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
            .spawnFlag = EVT_AREA_FLAG(29),
        },
        {
            .itemID = ITEM_BLUE_BERRY,
            .pos = { 440, 102, -89 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(30),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_80245904) = { 391.0f, 0.0f, -102.0f, 0.0f };

EvtSource N(80245914) = {
    EVT_SET(EVT_AREA_FLAG(29), 0)
    EVT_SET(EVT_AREA_FLAG(30), 0)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(tree1)))
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_WALL_HAMMER, 22, 1, 0)
    EVT_BIND_TRIGGER(N(shakeTree), TRIGGER_POINT_BOMB, EVT_PTR(N(triggerCoord_80245904)), 1, 0)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_598C) = {
    0x00000000,
};

EvtSource N(80245990) = {
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

EvtSource N(80245C3C) = {
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

EvtSource N(80245F5C) = {
    EVT_CALL(GetModelCenter, 60)
    EVT_SET(EVT_VAR(3), 60)
    EVT_SET(EVT_VAR(4), 61)
    EVT_SET(EVT_VAR(5), 62)
    EVT_SET(EVT_VAR(6), 63)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 54)
    EVT_SET(EVT_VAR(3), 54)
    EVT_SET(EVT_VAR(4), 55)
    EVT_SET(EVT_VAR(5), 56)
    EVT_SET(EVT_VAR(6), 57)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 48)
    EVT_SET(EVT_VAR(3), 48)
    EVT_SET(EVT_VAR(4), 49)
    EVT_SET(EVT_VAR(5), 50)
    EVT_SET(EVT_VAR(6), 51)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(80245C3C))
    EVT_CALL(GetModelCenter, 67)
    EVT_SET(EVT_VAR(3), 67)
    EVT_SET(EVT_VAR(4), 66)
    EVT_SET(EVT_VAR(5), 68)
    EVT_SET(EVT_VAR(6), 69)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(80245C3C))
    EVT_RETURN
    EVT_END
};
