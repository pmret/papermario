#include "dro_01.h"
#include "effects.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/artist_toad.h"
#include "sprite/npc/chuck_quizmo.h"
#include "sprite/npc/dryite.h"
#include "sprite/npc/mouser.h"
#include "sprite/npc/three_sisters.h"
#include "sprite/npc/world_parakarry.h"

#define UNK_ALPHA_FUNC_NPC 10

extern s16 MessagePlural;
extern s16 MessageSingular;

enum {
    NPC_MOUSER0,
    NPC_DRYITE0,
    NPC_DRYITE1,
    NPC_DRYITE2,
    NPC_DRYITE3,
    NPC_ARTIST_TOAD,
    NPC_MOUSER1,
    NPC_THREE_SISTERS0,
    NPC_THREE_SISTERS1,
    NPC_THREE_SISTERS2,
    NPC_CHUCK_QUIZMO,
    NPC_DRYITE4,
    NPC_DRYITE5,
};

typedef struct Unk_Struct_1 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void (*unk_14)(struct Unk_Struct_1*, s32);
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    s32 unk_38;
} Unk_Struct_1;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void (*unk_14)(Unk_Struct_1*, s32);
} Unk_Struct_2;

void N(func_802430C8_95E2C8)(Unk_Struct_1* ptr, s32 arg1);

EvtSource N(80248504);

typedef struct {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 instanceCounter;
    /* 0x0C */ EffectInstanceDataThing* unk_0C;
    /* 0x10 */ void (*update)(EffectInstance* effectInst);
    /* 0x14 */ void (*renderWorld)(EffectInstance* effectInst);
    /* 0x18 */ void (*unk_18)(EffectInstance* effectInst);
    /* 0x1C */ void* unk_1C;
} N(temp);

static s32 N(D_8024DFC0);
static s8 N(pad_D_8024DFC4)[0x4];
static s32 N(pad_D_8024DFC8)[4];
static s32 N(D_8024DFD8);
static s8 N(pad_D_8024DFDC)[0x4];
static N(temp)* N(D_8024DFE0);
static N(temp)* N(D_8024DFE4);
static N(temp)* N(D_8024DFE8);
static s8 N(pad_D_8024DFEC)[0x4];
static s32 N(D_8024DFF0)[112];
static s8 N(pad_D_8024E1B0)[0x4]; // Probably part of the above
static s32 N(D_8024E1B4);

EntryList N(entryList) = {
    { -342.0f, 0.0f, 316.0f, 45.0f },
    { 488.0f, 1.0f, 4.0f, 270.0f },
    { 430.0f, 35.0f, -120.0f, 180.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { -211.0f, 50.0f, -50.0f, 120.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_dro_01_tattle },
};

EvtSource N(80243BB0) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_OUTPOST, 0, 8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80243C30) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(GetEntryPos))
    EVT_SUB(EVT_VAR(2), 40)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(func_802D286C, 256)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LOOP(40)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(3)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(2)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(GetCurrentFloor))
    EVT_WAIT_FRAMES(1)
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(80243F84) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_IF_EQ(EVT_VAR(4), 90)
        EVT_ADD(EVT_VAR(5), 40)
    EVT_ELSE
        EVT_SUB(EVT_VAR(5), 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(0), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 355)
    EVT_THREAD
        EVT_WAIT_FRAMES(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2304)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(SomeXYZFunc2), EVT_FIXED(1.0))
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_802D2520, ANIM_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(80244374) = {
    EVT_CALL(N(UnkFunc25))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80244450))
    EVT_RETURN
    EVT_END
};

EvtSource N(80244450) = {
    EVT_CALL(N(SetPlayerStatusAnimFlags100000))
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_CALL(PlayerMoveTo, EVT_VAR(1), EVT_VAR(3), 3)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(SetPlayerFlagBits, 2097152, 1)
    EVT_CALL(N(GetCurrentCameraYawClamped180))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetPlayerFlagBits, 2097152, 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_LOOP(40)
            EVT_SUB(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 2, 1, 1, 0)
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024462C) = {
    EVT_CALL(IsPlayerOnValidFloor, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 26)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(27)
    EVT_CALL(N(SetPlayerStatusAnimFlags100000))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_ADD(EVT_VAR(6), 2)
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_SET(EVT_VAR(8), EVT_VAR(4))
    EVT_ADD(EVT_VAR(8), 180)
    EVT_IF_GE(EVT_VAR(4), 360)
        EVT_SUB(EVT_VAR(4), 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, EVT_VAR(8), 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_LOOP(40)
            EVT_CALL(N(SomeXYZFunc2), EVT_FIXED(1.0))
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80244960) = {
    EVT_SET_GROUP(27)
    EVT_SET(EVT_SAVE_FLAG(761), 0)
    EVT_CALL(UseExitHeading, 60, 0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sbk_36"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_802449CC) = EXIT_WALK_SCRIPT(60,  1, "dro_02",  0);

EvtSource N(80244A28) = {
    EVT_BIND_TRIGGER(N(exitWalk_80244960), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802449CC), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80244A70) = {
    EVT_CALL(PlaySound, 0x80000060)
    EVT_CALL(UseSettingsFrom, 0, 175, 0, -201)
    EVT_CALL(SetPanTarget, 0, 175, 0, -201)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(N(UnkFunc27), 2, 0, 3)
    EVT_CALL(N(UnkFunc27), 1, -1, 3)
    EVT_CALL(N(UnkFunc26), 3, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 300, EVT_FIXED(0.2))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(60)
        EVT_CALL(GetEntryID, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 3)
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), 2)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), 3)
        EVT_END_IF
        EVT_WAIT_FRAMES(100)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(enterWalk_80244C14) = {
    EVT_CALL(GetLoadType, EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(80244A28))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(2)
            EVT_IF_EQ(EVT_SAVE_FLAG(1939), 0)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(SetPlayerPos, EVT_VAR(0), -1000, EVT_VAR(2))
                EVT_WAIT_FRAMES(30)
                EVT_CALL(PlaySound, SOUND_UNKNOWN_208E)
                EVT_SET(EVT_SAVE_FLAG(1939), 1)
                EVT_WAIT_FRAMES(30)
                EVT_CALL(SetPlayerActionState, 0)
                EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(EVT_VAR(10), EVT_PTR(N(80244A28)))
            EVT_EXEC_WAIT(N(80243C30))
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_EXEC_WAIT(N(80244A70))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(10)
            EVT_EXEC(0x80285C50)
            EVT_EXEC(N(80244A28))
        EVT_CASE_DEFAULT
            EVT_SET(EVT_VAR(0), EVT_PTR(N(80244A28)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 9)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_SET(EVT_SAVE_FLAG(1973), 1)
    EVT_IF_LT(EVT_SAVE_VAR(0), -68)
        EVT_SET(EVT_SAVE_VAR(0), -68)
    EVT_END_IF
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_RANGE(-53, 6)
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024B47C)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024B464)))
    EVT_END_SWITCH
    EVT_CALL(InitVirtualEntityList)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_CALL(MakeShop, EVT_PTR(N(shopItemPositions_8024BA68)), EVT_PTR(N(shopInventory_8024B4FC)), EVT_PTR(N(shopPriceList_8024B550)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(shopOwnerNPC_8024BA80)))
    EVT_EXEC_WAIT(N(8024C218))
    EVT_EXEC(N(8024C2EC))
    EVT_EXEC(N(80243BB0))
    EVT_EXEC(N(enterWalk_80244C14))
    EVT_WAIT_FRAMES(1)
    EVT_EXEC(N(8024DD78))
    EVT_RETURN
    EVT_END
};

s32 N(pad_5004)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

NpcAISettings N(npcAISettings_80245010) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .unk_14 = -1,
    .unk_2C = 1,
};

EvtSource N(npcAI_80245040) = {
    EVT_CALL(DoBasicAI, EVT_PTR(N(npcAISettings_80245010)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80245060) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_80245040),
    .level = 99,
    .unk_2A = 16,
};

NpcAISettings N(npcAISettings_8024508C) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .unk_14 = -1,
    .unk_2C = 1,
};

EvtSource N(npcAI_802450BC) = {
    EVT_CALL(N(func_80241174_95C374), EVT_PTR(N(npcAISettings_8024508C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802450DC) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_802450BC),
    .level = 99,
    .unk_2A = 16,
};

NpcSettings N(npcSettings_80245108) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

NpcSettings N(npcSettings_80245134) = {
    .height = 22,
    .radius = 25,
    .level = 99,
};

NpcSettings N(npcSettings_80245160) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_8024518C) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

s32** N(D_802451B8_9603B8) = NULL;

EvtSource N(802451BC) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(802451EC) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

u8 N(quizAnswers)[] = {
    0x02, 0x01, 0x01, 0x02, 0x02, 0x00, 0x02, 0x00,
    0x02, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x02,
    0x00, 0x02, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02,
    0x01, 0x02, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01,
};

QuizRequirements N(quizRequirements)[] = {
    { -108, 0 }, { -76, 10 },
    { -54, 20 }, { -14, 30 },
    {   6, 37 }, {  39, 44 },
    {  58, 52 }, {  88, 60 },
    {  96, 64 }, {   0, 64 },
};

EvtSource N(802452AC) = {
    EVT_CALL(N(GetGameStatus75))
    EVT_IF_LE(EVT_VAR(0), 1)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_C)
        EVT_WAIT_FRAMES(40)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(8024535C) = {
    EVT_CALL(N(GetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(N(SetCamVfov), 0, 25)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamType, 0, EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamType, 0, EVT_VAR(1), 0)
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 370)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -370)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(GetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(13.0))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(-10.0))
    EVT_CALL(SetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802454F8) = {
    EVT_CALL(GetNpcPos, 10, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 30)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 17)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -17)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetCamSpeed, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(802455F4) = {
    EVT_CALL(N(SetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80245630) = {
    EVT_WAIT_FRAMES(20)
    EVT_CALL(N(UnkCameraFunc), EVT_ARRAY(1), EVT_ARRAY(3), 83, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
            EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
            EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
        EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(UnkRotatePlayer))
    EVT_CALL(func_802D2884, EVT_ARRAY(1), EVT_ARRAY(3), 0)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtSource N(802457E0) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(UnkCameraFunc), EVT_VAR(10), EVT_VAR(12), 108, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(5), EVT_ARRAY(2))
    EVT_SUBF(EVT_VAR(5), EVT_VAR(11))
    EVT_THREAD
        EVT_CALL(N(UnkMovePartner))
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
        EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
        EVT_ADDF(EVT_VAR(6), EVT_VAR(11))
        EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(6), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(UnkRotatePartner))
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_RETURN
    EVT_END
};

EvtSource N(80245918) = {
    EVT_CALL(GetNpcPos, 10, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(UnkCameraFunc), EVT_VAR(10), EVT_VAR(12), -70, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
            EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
            EVT_CALL(SetNpcPos, 10, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(60)
    EVT_CALL(NpcFacePlayer, 10, 0)
    EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtSource N(80245A84) = {
    EVT_EXEC(N(80245630))
    EVT_EXEC(N(802457E0))
    EVT_EXEC_WAIT(N(80245918))
    EVT_RETURN
    EVT_END
};

EvtSource N(80245AB8) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_QUESTION)
        EVT_WAIT_FRAMES(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80245AF8) = {
    EVT_CALL(SetPlayerAnimation, ANIM_THROW)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtSource N(80245B34) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_ARRAY(2), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024667C) = {
    EVT_CALL(SetPlayerAnimation, ANIM_SHOCK_STILL)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802466BC) = {
    EVT_THREAD
        EVT_CALL(N(UnkCameraFunc), EVT_ARRAY(1), EVT_ARRAY(3), 25, EVT_VAR(0), EVT_VAR(1))
        EVT_SETF(EVT_VAR(2), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(2), EVT_VAR(0))
        EVT_SETF(EVT_VAR(3), EVT_ARRAY(3))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(1))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x102)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, EVT_VAR(2), EVT_VAR(3), 40)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, EVT_ARRAY(1), EVT_ARRAY(3), 40)
    EVT_RETURN
    EVT_END
};

EvtSource N(80246798) = {
    EVT_EXEC_GET_TID(N(80245B34), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(802466BC))
    EVT_RETURN
    EVT_END
};

EvtSource N(80246848) = {
    EVT_EXEC_GET_TID(N(8024667C), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_EXEC_WAIT(N(802466BC))
    EVT_RETURN
    EVT_END
};

EvtSource N(802468F8) = {
    EVT_IF_GT(EVT_SAVE_VAR(352), 63)
        EVT_SET(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, EVT_ARRAY(1), EVT_ARRAY(2), EVT_ARRAY(3))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 16)
    EVT_IF_EQ(EVT_SAVE_VAR(352), 63)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000A))
    EVT_ELSE
        EVT_IF_EQ(EVT_SAVE_FLAG(1767), 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0009))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0008))
            EVT_SET(EVT_SAVE_FLAG(1767), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000C))
        EVT_EXEC_WAIT(N(802452AC))
        EVT_SET(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_SAVE_FLAG(1793), 1)
    EVT_CALL(N(Set80151310_1))
    EVT_CALL(N(UnkAlphaFunc))
    EVT_EXEC(N(8024535C))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(SetNpcFlagBits, 10, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcFlagBits, 10, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_EXEC_GET_TID(N(80245A84), EVT_VAR(1))
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000B))
    EVT_CALL(PlaySound, 137)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(N(func_80241BE0_95CDE0))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_SET(EVT_VAR(0), 2883584)
    EVT_ADD(EVT_VAR(0), EVT_SAVE_VAR(352))
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6, 0, EVT_VAR(0))
    EVT_CALL(SetPlayerAnimation, ANIM_QUESTION)
    EVT_SET(EVT_VAR(0), 2949120)
    EVT_ADD(EVT_VAR(0), EVT_SAVE_VAR(352))
    EVT_CALL(PlaySound, 142)
    EVT_CALL(ShowChoice, EVT_VAR(0))
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_CALL(StopSound, 142)
    EVT_EXEC(N(80245AF8))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySound, 141)
    EVT_CALL(N(func_80241EE0_95D0E0), EVT_VAR(0))
    EVT_SET(EVT_ARRAY(4), 0)
    EVT_CALL(N(func_802424D4_95D6D4))
    EVT_WAIT_FRAMES(40)
    EVT_CALL(N(func_80241B5C_95CD5C))
    EVT_THREAD
        EVT_WAIT_FRAMES(110)
        EVT_CALL(CloseChoice)
        EVT_SET(EVT_ARRAY(4), 0)
    EVT_END_THREAD
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_7)
        EVT_SET(EVT_ARRAY(4), 1)
        EVT_THREAD
            EVT_CALL(N(func_80241EAC_95D0AC), 1)
            EVT_WAIT_FRAMES(6)
            EVT_WAIT_FRAMES(6)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(N(func_80241EAC_95D0AC), 2)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlaySound, 540)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, 540)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, 540)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, 540)
        EVT_END_THREAD
        EVT_CALL(PlaySound, 138)
        EVT_CALL(N(func_80241F78_95D178))
        EVT_THREAD
            EVT_WAIT_FRAMES(15)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 50)
            EVT_CALL(N(UnkCameraFunc), 0, 0, 83, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_ADD(EVT_VAR(1), -3)
            EVT_CALL(N(UnkCameraFunc), 0, 0, 58, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_ADD(EVT_VAR(1), 30)
            EVT_CALL(N(UnkCameraFunc), 0, 0, 93, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
        EVT_END_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_GET_TID(N(80246798), EVT_VAR(1))
        EVT_ADD(EVT_SAVE_VAR(352), 1)
        EVT_IF_GT(EVT_SAVE_VAR(352), 63)
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x0010))
            EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
                EVT_IF_EQ(EVT_VAR(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(EVT_VAR(0), 348)
            EVT_SET(EVT_VAR(1), 3)
            EVT_EXEC_WAIT(N(802451BC))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(func_80241EAC_95D0AC), 15)
            EVT_CALL(N(func_80241F60_95D160))
            EVT_CALL(SetMessageValue, EVT_SAVE_VAR(352), 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0011))
        EVT_ELSE
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x000E))
            EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
                EVT_IF_EQ(EVT_VAR(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(EVT_VAR(0), 348)
            EVT_SET(EVT_VAR(1), 1)
            EVT_EXEC_WAIT(N(802451BC))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(func_80241EAC_95D0AC), 15)
            EVT_CALL(N(func_80241F60_95D160))
            EVT_CALL(SetMessageValue, EVT_SAVE_VAR(352), 0)
            EVT_IF_EQ(EVT_SAVE_VAR(352), 1)
                EVT_CALL(SetMessageMsg, EVT_PTR(MessageSingular), 1)
            EVT_ELSE
                EVT_CALL(SetMessageMsg, EVT_PTR(MessagePlural), 1)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000F))
        EVT_END_IF
        EVT_SET(EVT_VAR(0), 1)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_9)
        EVT_SET(EVT_ARRAY(4), 2)
        EVT_CALL(PlaySound, SOUND_MENU_BADGE_ERROR)
        EVT_CALL(PlaySound, 139)
        EVT_EXEC_GET_TID(N(80246848), EVT_VAR(1))
        EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(PlayEffect, 0x2B, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x000D))
        EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_A)
        EVT_LOOP(0)
            EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_SET(EVT_VAR(0), 0)
    EVT_END_IF
    EVT_CALL(N(func_80241EE0_95D0E0), -1)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySound, 143)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(45)
        EVT_CALL(StopSound, 137)
    EVT_END_THREAD
    EVT_CALL(N(func_80241F94_95D194))
    EVT_CALL(N(func_80241DF8_95CFF8))
    EVT_EXEC_WAIT(N(802452AC))
    EVT_EXEC(N(802455F4))
    EVT_CALL(N(UnkFunc29))
    EVT_CALL(N(Set80151310_0))
    EVT_SET(EVT_SAVE_FLAG(1793), 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80247628) = {
    EVT_CALL(N(UnkQuizFunc))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_1000000)), FALSE)
    EVT_CALL(SetNpcSprite, -1, 0x00AF0001)
    EVT_CALL(N(UnkFunc31))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024769C) = {
    EVT_USE_ARRAY(EVT_PTR(N(pad_D_8024DFC8)))
    EVT_SET(EVT_SAVE_FLAG(1769), 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerFlagBits, 4194304, 1)
    EVT_EXEC_WAIT(N(802468F8))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerFlagBits, 4194304, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024771C) = {
    EVT_CALL(N(GetNpcUnsafeOwner2))
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_80247738) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .unk_14 = -1,
    .unk_2C = 1,
};

EvtSource N(80247768) = {
    EVT_CALL(DoBasicAI, EVT_PTR(N(npcAISettings_80247738)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80247788) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(80247628),
    .onInteract = &N(8024769C),
    .aux = &N(8024771C),
    .flags = 0x00000D01,
    .level = 99,
};

NpcSettings N(npcSettings_802477B4) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(80247628),
    .onInteract = &N(8024769C),
    .ai = &N(80247768),
    .aux = &N(8024771C),
    .flags = 0x00000C01,
    .level = 99,
    .unk_2A = 16,
};

s32 N(D_802477E0_9629E0) = {
    0x00000000,
};

s32 N(D_802477E4_9629E4) = {
    0x00000000,
};

EvtSource N(802477E8) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(1))
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, EVT_VAR(1))
            EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(N(AddPlayerHandsOffset), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_BITWISE_OR_CONST(EVT_VAR(0), 0x50000)
            EVT_CALL(MakeItemEntity, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, 393221)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, EVT_VAR(0))
    EVT_END_SWITCH
    EVT_CALL(N(func_80242784_95D984), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(8024792C) = {
    EVT_CALL(N(func_802427BC_95D9BC), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(802477E8), 0x10, 0, EVT_PTR(N(D_8024DFF0)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024797C) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_CALL(N(UnkYawFunc), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_CALL(SetItemPos, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(802479FC) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(1))
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, EVT_VAR(1))
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(N(UnkYawFunc), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_BITWISE_OR_CONST(EVT_VAR(0), 0x50000)
            EVT_CALL(MakeItemEntity, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0)
            EVT_EXEC_GET_TID(N(8024797C), EVT_VAR(10))
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_2)
            EVT_CALL(GetAngleBetweenNPCs, EVT_VAR(9), -4, EVT_VAR(11))
            EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(GetNpcPos, EVT_VAR(9), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
            EVT_IF_LE(EVT_VAR(11), 180)
                EVT_ADD(EVT_VAR(6), 20)
            EVT_ELSE
                EVT_ADD(EVT_VAR(6), -20)
            EVT_END_IF
            EVT_ADD(EVT_VAR(7), 10)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
            EVT_CALL(NpcJump1, NPC_PARTNER, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 20)
            EVT_KILL_THREAD(EVT_VAR(10))
            EVT_CALL(RemoveItemEntity, EVT_VAR(0))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(GetNpcYaw, -4, EVT_VAR(10))
            EVT_ADD(EVT_VAR(10), 180)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(10), 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(NpcJump1, NPC_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 20)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, EVT_VAR(9), 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT_FRAMES(5)
    EVT_END_SWITCH
    EVT_CALL(N(func_80242784_95D984), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80247D20) = {
    EVT_SET(EVT_VAR(0), EVT_VAR(11))
    EVT_SET(EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(func_802427BC_95D9BC), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(802479FC), 0x10, 0, EVT_PTR(N(D_8024DFF0)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtSource N(80247D90) = {
    EVT_SET(EVT_VAR(12), 0)
    EVT_IF_LT(EVT_SAVE_VAR(0), -70)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(func_80243014_95E214))
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_CALL(FindKeyItem, EVT_VAR(5), EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(0), 4)
        EVT_IF_NE(EVT_VAR(1), -1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(PlayerFaceNpc, EVT_VAR(2), 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetNpcPos, EVT_VAR(2), EVT_VAR(13), EVT_VAR(0), EVT_VAR(14))
            EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(13), EVT_VAR(14), EVT_VAR(15))
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.0))
            EVT_ADD(EVT_VAR(0), 10)
            EVT_CALL(NpcJump1, NPC_PARTNER, EVT_VAR(13), EVT_VAR(0), EVT_VAR(15), 10)
            EVT_CALL(SpeakToNpc, -4, 262150, 262145, 0, EVT_VAR(2), EVT_VAR(7))
            EVT_CALL(EnablePartnerAI)
            EVT_EXEC_WAIT(N(80247D20))
            EVT_SWITCH(EVT_VAR(0))
                EVT_CASE_EQ(-1)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 5, EVT_VAR(8))
                    EVT_CALL(EnablePartnerAI)
                    EVT_SET(EVT_VAR(12), 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 5, EVT_VAR(9))
                    EVT_IF_NE(EVT_VAR(10), 0)
                        EVT_CALL(SpeakToPlayer, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4), 0, EVT_VAR(10))
                    EVT_END_IF
                    EVT_CALL(EnablePartnerAI)
                    EVT_IF_NE(EVT_VAR(6), 0)
                        EVT_SET(EVT_VAR(0), EVT_VAR(6))
                        EVT_SET(EVT_VAR(1), 1)
                        EVT_EXEC_WAIT(N(802451BC))
                        EVT_CALL(AddKeyItem, EVT_VAR(6))
                    EVT_END_IF
                    EVT_SET(EVT_VAR(12), 2)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(func_80243058_95E258))
    EVT_RETURN
    EVT_END
};

s32 N(D_80248088_963288)[] = {
    0x0000004C, 0x00000000,
};

EvtSource N(80248090) = {
    EVT_CALL(N(SetManyVars), 6, 9699589, 9699585, 76, 69, 852105, 852106, 852107, 852108, EVT_PTR(N(D_80248088_963288)))
    EVT_EXEC_WAIT(N(80247D90))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802480E0) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), -53)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0062))
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(EVT_AREA_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x005F))
            EVT_ADD(EVT_AREA_VAR(0), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0060))
            EVT_ADD(EVT_AREA_VAR(0), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0061))
            EVT_SUB(EVT_AREA_VAR(0), 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802481F8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802480E0)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_8024821C) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-53)
            EVT_IF_GE(EVT_SAVE_VAR(0), -64)
                EVT_IF_EQ(EVT_AREA_VAR(1), 2)
                    EVT_SET(EVT_AREA_VAR(1), 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SWITCH(EVT_AREA_VAR(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_03_Anim_4, NPC_ANIM_dryite_Palette_03_Anim_1, 0, MESSAGE_ID(0x0D, 0x0063))
                    EVT_ADD(EVT_AREA_VAR(1), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_03_Anim_4, NPC_ANIM_dryite_Palette_03_Anim_1, 0, MESSAGE_ID(0x0D, 0x0064))
                    EVT_ADD(EVT_AREA_VAR(1), 1)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_03_Anim_4, NPC_ANIM_dryite_Palette_03_Anim_1, 0, MESSAGE_ID(0x0D, 0x0065))
                    EVT_SET(EVT_AREA_VAR(1), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_03_Anim_4, NPC_ANIM_dryite_Palette_03_Anim_1, 0, MESSAGE_ID(0x0D, 0x0066))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_03_Anim_4, NPC_ANIM_dryite_Palette_03_Anim_1, 0, MESSAGE_ID(0x0D, 0x0067))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802483A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024821C)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802483CC) = {
    EVT_SWITCH(EVT_AREA_VAR(2))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MESSAGE_ID(0x0D, 0x0068))
            EVT_ADD(EVT_AREA_VAR(2), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MESSAGE_ID(0x0D, 0x0069))
            EVT_ADD(EVT_AREA_VAR(2), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MESSAGE_ID(0x0D, 0x006A))
            EVT_ADD(EVT_AREA_VAR(2), 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MESSAGE_ID(0x0D, 0x006B))
            EVT_SET(EVT_AREA_VAR(2), 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802484E0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802483CC)))
    EVT_RETURN
    EVT_END
};

EvtSource N(80248504) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorCollider), EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 8)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, 3, 0)
    EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0078))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, 3, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADDF(EVT_VAR(0), EVT_VAR(3))
    EVT_ADDF(EVT_VAR(1), EVT_VAR(4))
    EVT_ADDF(EVT_VAR(2), EVT_VAR(5))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(2.0))
    EVT_DIVF(EVT_VAR(1), EVT_FIXED(2.0))
    EVT_DIVF(EVT_VAR(2), EVT_FIXED(2.0))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(-300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(5.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0079))
    EVT_CALL(SetPlayerAnimation, ANIM_80007)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x007A))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(N(func_80243084_95E284))
    EVT_SET(EVT_SAVE_FLAG(761), 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(D_8024884C_963A4C)[] = {
    0x0000007D, 0x00000000, 0xFFFFFFD6, 0x0000004B, 0x0000004B, N(func_802430C8_95E2C8),
};

EvtSource N(interact_80248864) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(253), 1)
        EVT_IF_EQ(EVT_SAVE_FLAG(761), 1)
            EVT_CALL(N(func_802431B4_95E3B4))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x007B))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-53)
            EVT_IF_EQ(EVT_AREA_FLAG(1), 0)
                EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x006C))
                EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x006D))
                EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x006E))
                EVT_SET(EVT_AREA_FLAG(1), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x006F))
                EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0070))
                EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0071))
                EVT_SET(EVT_AREA_FLAG(1), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0072))
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0073))
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0074))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0075))
            EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0076))
            EVT_CALL(SpeakToPlayer, 3, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MESSAGE_ID(0x0D, 0x0077))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80248AE4) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248864)))
    EVT_IF_EQ(EVT_SAVE_FLAG(253), 1)
        EVT_THREAD
            EVT_CALL(N(func_80242858_95DA58), EVT_PTR(N(D_8024884C_963A4C)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80248BA0) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFaceNpc, 3, 4, 1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_802431FC_95E3FC))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_3)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FIXED(3.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(0), EVT_VAR(1), 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(GetNpcYaw, -1, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, EVT_VAR(0), 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80248CC8) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248BA0)))
    EVT_RETURN
    EVT_END
};

s32 N(D_80248D4C_963F4C)[] = {
    0x00000067, 0x00000000,
};

EvtSource N(interact_80248D54) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(754), 1)
        EVT_CALL(FindKeyItem, ITEM_MELODY, EVT_VAR(0))
        EVT_IF_NE(EVT_VAR(0), -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0084))
            EVT_RETURN
        EVT_ELSE
            EVT_IF_EQ(EVT_SAVE_FLAG(755), 0)
                EVT_IF_LT(EVT_SAVE_VAR(0), 88)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0085))
                    EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
                    EVT_WAIT_FRAMES(30)
                    EVT_CALL(SetPlayerAnimation, ANIM_10002)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0086))
                    EVT_SET(EVT_SAVE_FLAG(755), 1)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-53)
            EVT_IF_EQ(EVT_AREA_FLAG(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x007C))
                EVT_SET(EVT_AREA_FLAG(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x007D))
                EVT_SET(EVT_AREA_FLAG(2), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_IF_EQ(EVT_AREA_FLAG(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x007E))
                EVT_SET(EVT_AREA_FLAG(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x007F))
                EVT_SET(EVT_AREA_FLAG(2), 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(EVT_AREA_FLAG(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0080))
                EVT_SET(EVT_AREA_FLAG(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0081))
                EVT_SET(EVT_AREA_FLAG(2), 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(EVT_VAR(0), EVT_PTR(N(D_80248D4C_963F4C)))
    EVT_SET(EVT_VAR(1), 5)
    EVT_EXEC_WAIT(N(8024792C))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0082))
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_3)
            EVT_WAIT_FRAMES(60)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_artist_toad_Palette_01_Anim_2, NPC_ANIM_artist_toad_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0083))
            EVT_SET(EVT_VAR(0), 104)
            EVT_SET(EVT_VAR(1), 1)
            EVT_EXEC_WAIT(N(802451BC))
            EVT_CALL(AddKeyItem, ITEM_MELODY)
            EVT_SET(EVT_SAVE_FLAG(754), 1)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80249168) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248D54)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8024918C) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-67)
            EVT_CALL(N(func_80243350_95E550), 16, 190, -134, -131)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -180)
            EVT_EXEC_WAIT(N(8024C41C))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetPlayerPos, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
            EVT_CALL(SetPanTarget, 0, 32, 0, -67)
            EVT_CALL(SetCamDistance, 0, -210)
            EVT_CALL(SetCamPitch, 0, 20, -12)
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
            EVT_CALL(SetCamDistance, 0, -350)
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(0.8))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
            EVT_CALL(NpcMoveTo, NPC_SELF, -23, -105, 20)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 65, 0)
            EVT_WAIT_FRAMES(10)
            EVT_EXEC_WAIT(N(8024C4C8))
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
            EVT_CALL(NpcMoveTo, NPC_SELF, 37, -27, 20)
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
            EVT_CALL(SetPanTarget, 0, 142, 0, -67)
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 62, -6, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 103, 11, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 554, -12, 20)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(EVT_SAVE_VAR(0), -67)
        EVT_CASE_LT(-66)
        EVT_CASE_LT(-65)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, 470, 0, 18)
            EVT_CALL(NpcMoveTo, NPC_SELF, 287, 9, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 102, -14, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, -32, -96, 20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_1)
            EVT_EXEC_WAIT(N(8024C41C))
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
            EVT_CALL(NpcMoveTo, NPC_SELF, 20, -375, 30)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_1)
            EVT_EXEC_WAIT(N(8024C4C8))
            EVT_CALL(EnableNpcBlur, -1, 0)
            EVT_SET(EVT_SAVE_VAR(0), -65)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_1)
            EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -375)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80249750) = {
    EVT_IF_EQ(EVT_AREA_VAR(4), 4)
        EVT_IF_EQ(EVT_AREA_VAR(5), 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_5, NPC_ANIM_mouser_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0088))
            EVT_EXEC_WAIT(N(80248090))
            EVT_IF_NE(EVT_VAR(12), 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(0x80284054)
    EVT_EXEC_WAIT(N(80248090))
    EVT_IF_NE(EVT_VAR(12), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024981C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024918C)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249750)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80249854) = {
    EVT_CALL(SpeakToPlayer, 7, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x008E))
    EVT_CALL(SpeakToPlayer, 8, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x008F))
    EVT_CALL(SpeakToPlayer, 9, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0090))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802498C4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249854)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802498E8) = {
    EVT_CALL(FindKeyItem, ITEM_FIRST_DEGREE_CARD, EVT_VAR(1))
    EVT_CALL(FindKeyItem, ITEM_SECOND_DEGREE_CARD, EVT_VAR(2))
    EVT_CALL(FindKeyItem, ITEM_THIRD_DEGREE_CARD, EVT_VAR(3))
    EVT_CALL(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, EVT_VAR(4))
    EVT_CALL(FindKeyItem, ITEM_DIPLOMA, EVT_VAR(5))
    EVT_IF_NE(EVT_VAR(1), -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009A))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(EVT_VAR(2), -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009B))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(EVT_VAR(3), -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009C))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(EVT_VAR(4), -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009D))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(EVT_VAR(5), -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009E))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0099))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80249ABC) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802498E8)))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80249AE0) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009F))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80249B10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249AE0)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80249B34)[] = {
    {
        .id = NPC_MOUSER0,
        .settings = &N(npcSettings_80245134),
        .pos = { -332.0f, 0.0f, 188.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802481F8),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_4,
            NPC_ANIM_mouser_Palette_00_Anim_4,
            NPC_ANIM_mouser_Palette_00_Anim_4,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
            NPC_ANIM_mouser_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0090),
    },
    {
        .id = NPC_DRYITE0,
        .settings = &N(npcSettings_80245060),
        .pos = { -235.0f, 0.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802483A8),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { -235, 0, 160, 30, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
        .animations = {
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_2,
            NPC_ANIM_dryite_Palette_03_Anim_3,
            NPC_ANIM_dryite_Palette_03_Anim_3,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_0,
            NPC_ANIM_dryite_Palette_03_Anim_0,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
            NPC_ANIM_dryite_Palette_03_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0091),
    },
    {
        .id = NPC_DRYITE1,
        .settings = &N(npcSettings_80245108),
        .pos = { -380.0f, 0.0f, -15.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802484E0),
        .yaw = 61,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_2,
            NPC_ANIM_dryite_Palette_02_Anim_3,
            NPC_ANIM_dryite_Palette_02_Anim_3,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_0,
            NPC_ANIM_dryite_Palette_02_Anim_0,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
            NPC_ANIM_dryite_Palette_02_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0094),
    },
    {
        .id = NPC_DRYITE2,
        .settings = &N(npcSettings_80245108),
        .pos = { 195.0f, 0.0f, -75.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248AE4),
        .yaw = 74,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_2,
            NPC_ANIM_dryite_Palette_00_Anim_3,
            NPC_ANIM_dryite_Palette_00_Anim_3,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_0,
            NPC_ANIM_dryite_Palette_00_Anim_0,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0092),
    },
    {
        .id = NPC_DRYITE3,
        .settings = &N(npcSettings_80245108),
        .pos = { 225.0f, 0.0f, -83.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248CC8),
        .yaw = 257,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_2,
            NPC_ANIM_dryite_Palette_00_Anim_3,
            NPC_ANIM_dryite_Palette_00_Anim_3,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_0,
            NPC_ANIM_dryite_Palette_00_Anim_0,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
            NPC_ANIM_dryite_Palette_00_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0093),
    },
    {
        .id = NPC_ARTIST_TOAD,
        .settings = &N(npcSettings_80245108),
        .pos = { 285.0f, 0.0f, -274.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249168),
        .yaw = 271,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_artist_toad_Palette_01_Anim_1,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
            NPC_ANIM_artist_toad_Palette_01_Anim_0,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0095),
    },
    {
        .id = NPC_MOUSER1,
        .settings = &N(npcSettings_80245134),
        .pos = { 31.0f, 0.0f, -374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024981C),
        .yaw = 180,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_4,
            NPC_ANIM_mouser_Palette_01_Anim_4,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
            NPC_ANIM_mouser_Palette_01_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x008F),
    },
    {
        .id = NPC_CHUCK_QUIZMO,
        .settings = &N(npcSettings_80247788),
        .pos = { -400.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .unk_1C = { 00, 00, 00, 01, 00, 03, 02, 00},
        .yaw = 263,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_1,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_2,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_1,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_1,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_0,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_0,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
            NPC_ANIM_chuck_quizmo_Palette_00_Anim_3,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0002),
    },
    {
        .id = NPC_DRYITE4,
        .settings = &N(npcSettings_80245060),
        .pos = { -120.0f, 0.0f, 134.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249ABC),
        .yaw = 257,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { -120, 0, 134, 40, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
        .animations = {
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_2,
            NPC_ANIM_dryite_Palette_01_Anim_3,
            NPC_ANIM_dryite_Palette_01_Anim_3,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_0,
            NPC_ANIM_dryite_Palette_01_Anim_0,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0096),
    },
    {
        .id = NPC_DRYITE5,
        .settings = &N(npcSettings_802450DC),
        .pos = { 40.0f, 0.0f, 105.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249B10),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 40, 0, 105, -30, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 1 },
        .animations = {
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_2,
            NPC_ANIM_dryite_Palette_01_Anim_3,
            NPC_ANIM_dryite_Palette_01_Anim_3,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_0,
            NPC_ANIM_dryite_Palette_01_Anim_0,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
            NPC_ANIM_dryite_Palette_01_Anim_1,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0097),
    },
};

StaticNpc N(npcGroup_8024AE94)[] = {
    {
        .id = NPC_THREE_SISTERS0,
        .settings = &N(npcSettings_80245160),
        .pos = { -141.0f, 0.0f, -18.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 62,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_2,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0003),
    },
    {
        .id = NPC_THREE_SISTERS1,
        .settings = &N(npcSettings_80245160),
        .pos = { -124.0f, 0.0f, -61.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 63,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_2,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0004),
    },
    {
        .id = NPC_THREE_SISTERS2,
        .settings = &N(npcSettings_80245160),
        .pos = { -80.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 244,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_2,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_1,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_6,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
            NPC_ANIM_three_sisters_Palette_01_Anim_3,
        },
        .tattle = MESSAGE_ID(0x1A, 0x0005),
    },
};

NpcGroupList N(npcGroupList_8024B464) = {
    NPC_GROUP(N(npcGroup_80249B34), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_8024B47C) = {
    NPC_GROUP(N(npcGroup_80249B34), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_8024AE94), BATTLE_ID(0, 0, 0, 0)),
    {},
};

s32 N(intTable_8024B4A0)[] = {
    MESSAGE_ID(0x27, 0x0049), MESSAGE_ID(0x27, 0x004A), MESSAGE_ID(0x27, 0x004B), MESSAGE_ID(0x27, 0x004C),
    MESSAGE_ID(0x27, 0x004D), MESSAGE_ID(0x27, 0x004E), MESSAGE_ID(0x27, 0x004F), MESSAGE_ID(0x27, 0x0050),
    MESSAGE_ID(0x27, 0x0051), MESSAGE_ID(0x27, 0x0052), MESSAGE_ID(0x27, 0x0053), MESSAGE_ID(0x27, 0x0054),
    MESSAGE_ID(0x27, 0x0055), MESSAGE_ID(0x27, 0x0056), MESSAGE_ID(0x27, 0x0057), MESSAGE_ID(0x27, 0x0058),
    MESSAGE_ID(0x27, 0x0059), MESSAGE_ID(0x27, 0x005A), MESSAGE_ID(0x27, 0x005B), MESSAGE_ID(0x27, 0x005C),
    MESSAGE_ID(0x27, 0x005D), MESSAGE_ID(0x27, 0x005E), MESSAGE_ID(0x27, 0x005F),
};

N(shopInventory) N(shopInventory_8024B4FC)[] = {
    { ITEM_THUNDER_BOLT,    5, MESSAGE_ID(0x24, 0x0003) },
    { ITEM_DUSTY_HAMMER,    2, MESSAGE_ID(0x24, 0x0005) },
    { ITEM_HONEY_SYRUP,     5, MESSAGE_ID(0x24, 0x0016) },
    { ITEM_DRIED_SHROOM,    2, MESSAGE_ID(0x24, 0x000D) },
    { ITEM_DRIED_PASTA,     3, MESSAGE_ID(0x24, 0x001D) },
    { ITEM_MUSHROOM,        3, MESSAGE_ID(0x24, 0x0009) },
    {},
};

N(shopPrice) N(shopPriceList_8024B550)[] = {
    { ITEM_SNOWMAN_DOLL,    12, 0x00000000 },
    { ITEM_MELON,           10, 0x00000000 },
    { ITEM_ICED_POTATO,     10, 0x00000000 },
    { ITEM_TASTY_TONIC,      5, 0x00000000 },
    { ITEM_SUPER_SODA,       6, 0x00000000 },
    { ITEM_SPECIAL_SHAKE,   15, 0x00000000 },
    { ITEM_DRIED_PASTA,      2, 0x00000000 },
    {},
};

s32** N(D_8024B5B0_9667B0) = NULL;

EvtSource N(8024B5B4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B5E4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B614) = {
    EVT_CALL(NpcJump0, 6, -31, 0, -283, 10)
    EVT_CALL(NpcJump0, 6, -30, 0, -283, 8)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B664) = {
    EVT_CALL(NpcJump0, 6, 20, 0, -259, 10)
    EVT_CALL(NpcJump0, 6, 20, 0, -259, 4)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B6B4) = {
    EVT_CALL(N(func_80243578_95E778))
    EVT_CALL(func_802D2C14, 1)
    EVT_EXEC_WAIT(N(8024B614))
    EVT_IF_LT(EVT_SAVE_VAR(0), -64)
        EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_mouser_Palette_01_Anim_5, NPC_ANIM_mouser_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0087))
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetPlayerAnimation, ANIM_80007)
        EVT_WAIT_FRAMES(30)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_mouser_Palette_01_Anim_5, NPC_ANIM_mouser_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0088))
    EVT_SET(EVT_SAVE_VAR(0), -64)
    EVT_CALL(func_802D2C14, 0)
    EVT_EXEC_WAIT(N(8024B664))
    EVT_END_IF // @bug
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B7B0) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(758), 0)
        EVT_CALL(N(func_80243578_95E778))
        EVT_CALL(func_802D2C14, 1)
        EVT_EXEC_WAIT(N(8024B614))
        EVT_CALL(SpeakToPlayer, 6, NPC_ANIM_mouser_Palette_01_Anim_5, NPC_ANIM_mouser_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x008D))
        EVT_SET(EVT_VAR(0), 119)
        EVT_SET(EVT_VAR(1), 1)
        EVT_EXEC_WAIT(N(8024B5B4))
        EVT_CALL(AddKeyItem, ITEM_KOOT_RED_JAR)
        EVT_SET(EVT_SAVE_FLAG(758), 1)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(8024B664))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(8024B894) = {
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
            EVT_SET(EVT_VAR(2), EVT_AREA_VAR(4))
            EVT_SET(EVT_VAR(3), EVT_AREA_VAR(5))
            EVT_SET(EVT_VAR(4), EVT_AREA_VAR(6))
            EVT_SET(EVT_AREA_VAR(5), EVT_VAR(2))
            EVT_SET(EVT_AREA_VAR(6), EVT_VAR(3))
            EVT_SWITCH(EVT_VAR(1))
                EVT_CASE_EQ(141)
                    EVT_SET(EVT_AREA_VAR(4), 1)
                    EVT_IF_EQ(EVT_VAR(2), 2)
                        EVT_IF_EQ(EVT_VAR(3), 3)
                            EVT_IF_EQ(EVT_VAR(4), 2)
                                EVT_EXEC_WAIT(N(8024B7B0))
                                EVT_SET(EVT_AREA_VAR(4), 0)
                            EVT_END_IF
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(134)
                    EVT_SET(EVT_AREA_VAR(4), 2)
                    EVT_IF_EQ(EVT_VAR(2), 1)
                        EVT_IF_LT(EVT_SAVE_VAR(0), -63)
                            EVT_EXEC_WAIT(N(8024B6B4))
                            EVT_SET(EVT_AREA_VAR(4), 0)
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(167)
                    EVT_SET(EVT_AREA_VAR(4), 3)
                EVT_CASE_DEFAULT
                    EVT_SET(EVT_AREA_VAR(4), 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(shopItemPositions_8024BA68)[] = {
    0x004C0021, 0x004B0022, 0x00490023, 0x004A0024, 0x00480025, 0x00470026,
};

s32 N(shopOwnerNPC_8024BA80)[] = {
    0x00000006, 0x00940101, 0x00940105, N(8024B894), 0x00000000, 0x00000000, N(intTable_8024B4A0),
};

s32 N(pad_BA9C) = {
    0x00000000,
};

EvtSource N(openDoor_8024BAA0) = {
    EVT_CALL(RotateModel, 103, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(moveWalls_8024BAD0) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIVF(EVT_VAR(1), 50)
    EVT_CALL(TranslateModel, 98, 0, EVT_VAR(1), 0)
    EVT_CALL(TranslateModel, 97, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 98, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 97, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 100, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 101, EVT_VAR(0), -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(dropDoor_8024BBB8) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIVF(EVT_VAR(1), 50)
    EVT_CALL(TranslateModel, 103, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 103, EVT_VAR(0), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(openDoor_8024BC24) = {
    EVT_CALL(RotateModel, 83, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(moveWalls_8024BC54) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIVF(EVT_VAR(1), 50)
    EVT_CALL(TranslateModel, 47, 0, EVT_VAR(1), 0)
    EVT_CALL(TranslateModel, 48, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 47, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 48, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 41, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 42, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 43, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 44, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 45, EVT_VAR(0), -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(openDoor_8024BD9C) = {
    EVT_CALL(RotateModel, 157, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(dropDoor_8024BDCC) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIV(EVT_VAR(1), 45)
    EVT_CALL(TranslateModel, 157, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 157, EVT_VAR(0), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(moveWalls_8024BE38) = {
    EVT_IF_EQ(EVT_VAR(0), 90)
        EVT_CALL(EnableModel, 142, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, 142, 1)
    EVT_END_IF
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIV(EVT_VAR(1), 45)
    EVT_SET(EVT_VAR(2), EVT_VAR(0))
    EVT_SUB(EVT_VAR(2), -90)
    EVT_DIV(EVT_VAR(2), -90)
    EVT_CALL(TranslateModel, 140, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 140, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 138, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 137, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 136, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 135, EVT_VAR(0), -1, 0, 0)
    EVT_CALL(RotateModel, 143, EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, 142, EVT_VAR(0), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(toggleVis_8024BFDC) = {
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 127, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 127, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(toggleVis_8024C040) = {
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SWITCH(EVT_SAVE_VAR(0))
                EVT_CASE_LT(-66)
                    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x017B), 160, 40)
                    EVT_SET(EVT_VAR(0), -1)
                    EVT_RETURN
                EVT_CASE_LT(-65)
                    EVT_SET(EVT_VAR(0), -1)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_CALL(SetGroupEnabled, 82, 1)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT_FRAMES(45)
                EVT_CALL(SetNpcPos, 6, 33, 0, -375)
                EVT_CALL(SetNpcYaw, 6, 180)
            EVT_END_THREAD
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 82, 0)
            EVT_SET(EVT_AREA_VAR(4), 0)
            EVT_SET(EVT_AREA_VAR(5), 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(toggleVis_8024C190) = {
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 156, 1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 156, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(npcList_8024C200)[] = {
    0x00000002, 0xFFFFFFFF,
};

s32 N(npcList_8024C208)[] = {
    0x00000006, 0xFFFFFFFF,
};

s32 N(npcList_8024C210)[] = {
    0x00000005, 0xFFFFFFFF,
};

EvtSource N(8024C218) = {
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BAA0)), EVT_PTR(N(moveWalls_8024BAD0)), EVT_PTR(N(dropDoor_8024BBB8)), EVT_PTR(N(toggleVis_8024BFDC)), 15, 16, 128, EVT_PTR(N(npcList_8024C200)))
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BC24)), EVT_PTR(N(moveWalls_8024BC54)), 0, EVT_PTR(N(toggleVis_8024C040)), 23, 24, 91, EVT_PTR(N(npcList_8024C208)))
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BD9C)), EVT_PTR(N(moveWalls_8024BE38)), EVT_PTR(N(dropDoor_8024BDCC)), EVT_PTR(N(toggleVis_8024C190)), 29, 30, 159, EVT_PTR(N(npcList_8024C210)))
    EVT_SET(EVT_VAR(0), 3)
    EVT_EXEC(N(toggleVis_8024BFDC))
    EVT_EXEC(N(toggleVis_8024C040))
    EVT_EXEC(N(toggleVis_8024C190))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024C2EC) = {
    EVT_LABEL(9)
    EVT_CALL(MakeLerp, 10, -10, 30, 10)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 34, EVT_VAR(0), 1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeLerp, -10, 10, 30, 10)
    EVT_LABEL(11)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 34, EVT_VAR(0), 1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024C41C) = {
    EVT_CALL(SetGroupEnabled, 82, 1)
    EVT_CALL(PlaySoundAtCollider, 23, 449, 0)
    EVT_CALL(MakeLerp, 0, 100, 15, 4)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_EXEC(N(openDoor_8024BC24))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(8024C4C8) = {
    EVT_CALL(MakeLerp, 100, 0, 15, 4)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_EXEC(N(openDoor_8024BC24))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, 23, 450, 0)
    EVT_CALL(SetGroupEnabled, 82, 0)
    EVT_RETURN
    EVT_END
};

s32 N(pad_C574)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(8024C580) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(dup_GetEntryPos))
    EVT_SUB(EVT_VAR(2), 40)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(func_802D286C, 256)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_LOOP(40)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(3)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(2)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(dup_GetCurrentFloor))
    EVT_WAIT_FRAMES(1)
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024C8D4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(dup_GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(4), 0)
    EVT_IF_EQ(EVT_VAR(4), 90)
        EVT_ADD(EVT_VAR(5), 40)
    EVT_ELSE
        EVT_SUB(EVT_VAR(5), 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, EVT_VAR(0), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 355)
    EVT_THREAD
        EVT_WAIT_FRAMES(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2304)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(dup_SomeXYZFunc2), EVT_FIXED(1.0))
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_802D2520, ANIM_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024CCC4) = {
    EVT_CALL(N(dup_UnkFunc25))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(8024CDA0))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024CDA0) = {
    EVT_CALL(N(dup_SetPlayerStatusAnimFlags100000))
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_GetEntryPos))
    EVT_CALL(PlayerMoveTo, EVT_VAR(1), EVT_VAR(3), 3)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_GetEntryPos))
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(SetPlayerFlagBits, 2097152, 1)
    EVT_CALL(N(dup_GetCurrentCameraYawClamped180))
    EVT_CALL(InterpPlayerYaw, EVT_VAR(0), 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetPlayerFlagBits, 2097152, 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_LOOP(40)
            EVT_SUB(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 2, 1, 1, 0)
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

EvtSource N(8024CF7C) = {
    EVT_CALL(IsPlayerOnValidFloor, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 26)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(GetCurrentPartnerID, EVT_VAR(1))
        EVT_IF_NE(EVT_VAR(1), 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(27)
    EVT_CALL(N(dup_SetPlayerStatusAnimFlags100000))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_GetEntryPos))
    EVT_SET(EVT_VAR(5), EVT_VAR(1))
    EVT_SET(EVT_VAR(6), EVT_VAR(2))
    EVT_ADD(EVT_VAR(6), 2)
    EVT_SET(EVT_VAR(7), EVT_VAR(3))
    EVT_SET(EVT_VAR(8), EVT_VAR(4))
    EVT_ADD(EVT_VAR(8), 180)
    EVT_IF_GE(EVT_VAR(4), 360)
        EVT_SUB(EVT_VAR(4), 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, EVT_VAR(8), 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(6), EVT_VAR(7))
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_LOOP(40)
            EVT_CALL(N(dup_SomeXYZFunc2), EVT_FIXED(1.0))
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

const char N(dro_01_name_hack)[];

EvtSource N(8024D2B0) = {
    EVT_SET(EVT_SAVE_FLAG(761), 0)
    EVT_CALL(GotoMap, EVT_PTR(N(dro_01_name_hack)), 4)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(D_802E9A18), -211, 60, -50, 30, MAKE_ENTITY_END)
    EVT_IF_EQ(EVT_SAVE_FLAG(1939), 0)
        EVT_IF_EQ(EVT_SAVE_FLAG(1933), 1)
            EVT_CALL(GetEntryID, EVT_VAR(0))
            EVT_IF_NE(EVT_VAR(0), 2)
                EVT_SET(EVT_SAVE_FLAG(1939), 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, 0x802EAF80, 430, 0, -120, 0, 2, EVT_PTR(N(8024D2B0)), 1939, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80241174_95C374)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, npcAISettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241470_95C670)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802451B8_9603B8) == NULL) {
        N(D_802451B8_9603B8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802451B8_9603B8)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802451B8_9603B8)[i];
        }
        heap_free(N(D_802451B8_9603B8));
        N(D_802451B8_9603B8) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

#include "world/common/UnkQuizFunc.inc.c"

#include "world/common/UnkFunc31.inc.c"

ApiStatus N(func_80241B5C_95CD5C)(Evt* script, s32 isInitialCall) {
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 999) {
        gPlayerData.quizzesAnswered++;
    }

    if (script->varTable[0] == N(quizAnswers)[evt_get_variable(NULL, EVT_SAVE_VAR(352))]) {
        script->varTable[0] = 1;
        gPlayerData.quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241BE0_95CDE0)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(D_8024DFE0) = playFX_4E(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(D_8024DFE4) = playFX_54(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(D_8024DFE8) = playFX_80(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)), 1.0f, 0);

        effectPtr = N(D_8024DFE0)->unk_0C;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = N(D_8024DFE0)->unk_0C;

    effectPtr->unk_20 += 10;
    effectPtr->unk_28 += 10;
    effectPtr->unk_24.s += 10;
    effectPtr->unk_18 += 10;
    effectPtr->unk_1C += 10;
    if (effectPtr->unk_18 >= 255) {
        effectPtr->unk_18 = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241DF8_95CFF8)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(D_8024DFE4)->flags |= 0x10;
        N(D_8024DFE8)->flags |= 0x10;
    }

    effectPtr = N(D_8024DFE0)->unk_0C;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(N(D_8024DFE0));
        free_generic_entity(N(D_8024DFC0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80241EAC_95D0AC)(Evt* script, s32 isInitialCall) {
    N(D_8024DFE0)->unk_0C->unk_34 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241EE0_95D0E0)(Evt* script, s32 isInitialCall) {
    s32 var = evt_get_variable(script, *script->ptrReadPos);
    EffectInstanceDataThing* effectPtr = N(D_8024DFE0)->unk_0C;

    switch (var) {
        case 0:
            effectPtr->unk_38 = 0xC0;
            break;
        case 1:
            effectPtr->unk_38 = 0x80;
            break;
        case 2:
            effectPtr->unk_38 = 0x40;
            break;
        default:
            effectPtr->unk_38 = 0;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80241F60_95D160)(Evt* script, s32 isInitialCall) {
    N(D_8024DFE8)->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241F78_95D178)(Evt* script, s32 isInitialCall) {
    N(D_8024DFE8)->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241F94_95D194)(Evt* script, s32 isInitialCall) {
    N(D_8024DFE8)->unk_0C->unk_1C = 2;
    return ApiStatus_DONE2;
}

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

void N(func_80242468_95D668)(void) {
    s32 var = evt_get_variable(NULL, N(D_8024DFD8));

    if (var == 1) {
        playFX_50(0, 0, 0, 0);
    } else if (var == 2) {
        playFX_50(1, 0, 0, 0);
    }
}

ApiStatus N(func_802424D4_95D6D4)(Evt* script, s32 isInitialCall) {
    N(D_8024DFC0) = create_generic_entity_frontUI(NULL, N(func_80242468_95D668));
    return ApiStatus_DONE2;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80242730_95D930)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &N(D_802477E0_9629E0);
        *ptr = 0;
    }

    ptr = &N(D_802477E0_9629E0);
    if (*ptr != NULL) {
        ptr = &N(D_802477E0_9629E0);
        *ptr = 0;
        evt_set_variable(script, *args, N(D_802477E4_9629E4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242784_95D984)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802477E4_9629E4) = evt_get_variable(script, *args);
    N(D_802477E0_9629E0) = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802427BC_95D9BC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_8024DFF0)[i] = ptr[i];
        }
        N(D_8024DFF0)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_8024DFF0)[i] = i + 16;
            N(D_8024DFF0)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242858_95DA58)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Unk_Struct_2* temp_s1 = evt_get_variable(script, *script->ptrReadPos);
    Unk_Struct_1* ptr;
    s32 atan_res1, atan_res2;
    s32 clamp;
    s32 res;

    if (isInitialCall) {
        script->functionTemp[1] = (Unk_Struct_1*)heap_malloc(0x3C);
        ptr = script->functionTemp[1];
        ptr->unk_00 = temp_s1->unk_00;
        ptr->unk_04 = temp_s1->unk_04;
        ptr->unk_08 = temp_s1->unk_08;
        ptr->unk_0C = temp_s1->unk_0C;
        ptr->unk_10 = temp_s1->unk_10;
        ptr->unk_14 = temp_s1->unk_14;
        ptr->unk_18 = 0;
        ptr->unk_1C = 0;
        ptr->unk_20 = 0;
        ptr->unk_24 = 0;
        ptr->unk_28 = 0;
        ptr->unk_2C = 0;
        ptr->unk_30 = 0;
        ptr->unk_34 = 0;
        ptr->unk_38 = 0;
    }

    ptr = script->functionTemp[1];
    switch (ptr->unk_20) {
        case 0:
            res = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (res < ptr->unk_0C) {
                ptr->unk_24 = playerStatus->position.x;
                ptr->unk_28 = playerStatus->position.z;
                ptr->unk_20++;
            }
            break;

        case 1:
            res = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (res < ptr->unk_0C) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_24, ptr->unk_28);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                ptr->unk_34 = signF(clamp);
                ptr->unk_20++;
                break;
            }
            ptr->unk_20 = 0;
            break;

        case 2:
            res = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (res < ptr->unk_0C) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_2C, ptr->unk_30);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                if (ptr->unk_34 == signF(clamp)) {
                    atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_24, ptr->unk_28);
                    atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                    clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                    if (fabsf(clamp) > 90.0f) {
                        if (ptr->unk_14 != NULL) {
                            ptr->unk_14(ptr, 0);
                        }
                        ptr->unk_18 = ptr->unk_18 + fabsf(clamp);
                        ptr->unk_20++;
                    }
                    break;
                }
            }
            ptr->unk_20 = 0;
            break;

        case 3:
            res = get_xz_dist_to_player(ptr->unk_00, ptr->unk_08);
            if (res < ptr->unk_10) {
                atan_res1 = atan2(ptr->unk_00, ptr->unk_08, ptr->unk_2C, ptr->unk_30);
                atan_res2 = atan2(ptr->unk_00, ptr->unk_08, playerStatus->position.x, playerStatus->position.z);
                clamp = get_clamped_angle_diff(atan_res1, atan_res2);
                if (ptr->unk_34 != signF(clamp)) {
                    if (ptr->unk_14 != NULL) {
                        ptr->unk_14(ptr, 3);
                    }
                    ptr->unk_20++;
                } else {
                    ptr->unk_18 = ptr->unk_18 + fabsf(clamp);
                    ptr->unk_1C = ptr->unk_18 / 360;
                    if (ptr->unk_1C != ptr->unk_38) {
                        if (ptr->unk_14 != NULL) {
                            ptr->unk_14(ptr, 1);
                        }
                        ptr->unk_38 = ptr->unk_1C;
                    }
                }
                if (ptr->unk_14 != NULL) {
                    ptr->unk_14(ptr, 2);
                }
            } else {
                if (ptr->unk_14 != NULL) {
                    ptr->unk_14(ptr, 4);
                }
                ptr->unk_20++;
            }
            break;

        case 4:
            ptr->unk_18 = 0.0f;
            ptr->unk_1C = 0;
            ptr->unk_38 = 0;
            ptr->unk_20 = 0;
            break;
    }

    ptr->unk_2C = playerStatus->position.x;
    ptr->unk_30 = playerStatus->position.z;

    return ApiStatus_BLOCK;
}

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

ApiStatus N(func_80243014_95E214)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    N(D_8024E1B4) = npc->currentAnim.w;
    npc->currentAnim.w = script->varTable[4];
    return ApiStatus_DONE2;
}

ApiStatus N(func_80243058_95E258)(Evt* script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim.w = N(D_8024E1B4);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80243084_95E284)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->unk_328 = playerData->frameCounter;
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

void N(func_802430C8_95E2C8)(Unk_Struct_1* ptr, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (arg1) {
        case 2:
            if (ptr->unk_1C >= 6) {
                if (fabsf(get_clamped_angle_diff(atan2(125.0f, -42.0f, 152.0f, -61.0f), atan2(125.0f, -42.0f, playerStatus->position.x,
                                                 playerStatus->position.z))) < 30.0f) {
                    start_script(N(80248504), 1, 0);
                    ptr->unk_20 = 4;
                }
            }
            break;

        case 0:
        case 1:
        case 3:
        case 4:
            break;
    }
}

ApiStatus N(func_802431B4_95E3B4)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 val = (playerData->frameCounter - playerData->unk_328) / 3600;

    if (val < 30) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802431FC_95E3FC)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    s32 rand;
    f32 temp_f22;
    f32 temp_f24;

    temp_f24 = atan2(183.0f, -75.0f, playerStatus->position.x, playerStatus->position.z);
    temp_f22 = atan2(183.0f, -75.0f, npc->pos.x, npc->pos.z);
    temp_f24 = get_clamped_angle_diff(temp_f22, temp_f24);
    rand = rand_int(10) + 30;
    if (temp_f24 < 0.0f) {
        temp_f22 += rand;
    } else {
        temp_f22 -= rand;
    }
    rand = rand_int(20) + 30;
    script->varTable[0] = (sin_deg(temp_f22) * rand) + 183.0f;
    script->varTable[1] = -75.0f - (cos_deg(temp_f22) * rand);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80243350_95E550)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_variable(script, *args++);
    f32 temp_f0 = (var4 - var2) / (var3 - var1);

    if (playerStatus->position.z < ((temp_f0 * playerStatus->position.x) + (var2 - (temp_f0 * var1)))) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_BLOCK;
}

const s32 N(pad_XXX)[] = { 0 };

const char N(dro_01_name_hack)[] = "tik_01";
