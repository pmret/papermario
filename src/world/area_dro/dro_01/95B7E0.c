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

extern s16 gCurrentCamID;
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

// Extraneous END_CASE_MULTI
#ifdef NON_MATCHING
EvtSource N(80243BB0) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        3, 4 {}
        else {
            SetMusicTrack(0, SONG_DRY_DRY_OUTPOST, 0, 8);
        }
    }
});
#else
EvtSource N(80243BB0) = {
    SI_CMD(EVT_OP_CALL, GetEntryID, SI_VAR(0)),
    SI_CMD(EVT_OP_MATCH, SI_VAR(0)),
        SI_CMD(EVT_OP_CASE_MULTI_OR_EQ, 3),
        SI_CMD(EVT_OP_CASE_MULTI_OR_EQ, 4),
        SI_CMD(EVT_OP_END_CASE_MULTI),
        SI_CMD(EVT_OP_CASE_ELSE),
            SI_CMD(EVT_OP_CALL, SetMusicTrack, 0, SONG_DRY_DRY_OUTPOST, 0, 8),
        SI_CMD(EVT_OP_END_CASE_MULTI),
    SI_CMD(EVT_OP_END_MATCH),
    SI_CMD(EVT_OP_RETURN),
    SI_CMD(EVT_OP_END)
};
#endif

EvtSource N(80243C30) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_STAND_STILL);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
    }
    GetEntryID(SI_VAR(0));
    N(GetEntryPos)();
    SI_VAR(2) -= 40;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    PlaySound(0x163);
    func_802D286C(256);
    func_802D2520(ANIM_STAND_STILL, 5, 2, 1, 1, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    loop 40 {
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    sleep 3;
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            DisablePartnerAI(0);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcFlagBits(NPC_PARTNER, ((0x00000002)), FALSE);
            EnablePartnerAI();
            EnableNpcShadow(NPC_PARTNER, TRUE);
        }
    }
    sleep 2;
    func_802D2520(ANIM_STAND_STILL, 0, 0, 0, 0, 0);
    sleep 1;
    SetPlayerAnimation(ANIM_10002);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
    HidePlayerShadow(FALSE);
0:
    N(GetCurrentFloor)();
    sleep 1;
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    spawn 0xFE363C8A;
});

EvtSource N(80243F84) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    GetEntryID(SI_VAR(0));
    N(GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(2) += 2;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    if (SI_VAR(4) == 90) {
        SI_VAR(5) += 40;
    } else {
        SI_VAR(5) -= 40;
    }
    UseSettingsFrom(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetPanTarget(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        DisablePartnerAI(0);
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
        InterpNpcYaw(NPC_PARTNER, SI_VAR(0), 0);
    }
    sleep 1;
    PlaySound(0x163);
    spawn {
        sleep 25;
        HidePlayerShadow(FALSE);
    }
    func_802D286C(2304);
    func_802D2520(ANIM_10002, 5, 3, 1, 1, 0);
    loop 40 {
        N(SomeXYZFunc2)(1.0);
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            EnableNpcShadow(NPC_PARTNER, TRUE);
            EnablePartnerAI();
        }
    }
    sleep 5;
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    ModifyColliderFlags(1, SI_VAR(11), 0x7FFFFE00);
    DisablePlayerInput(FALSE);
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    spawn 0xFE363C8A;
});

EvtSource N(80244374) = SCRIPT({
    N(UnkFunc25)();
    if (SI_VAR(0) == 0) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    await N(80244450);
});

EvtSource N(80244450) = SCRIPT({
    N(SetPlayerStatusAnimFlags100000)();
    group 27;
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    PlayerMoveTo(SI_VAR(1), SI_VAR(3), 3);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SetPlayerFlagBits(2097152, 1);
    N(GetCurrentCameraYawClamped180)();
    InterpPlayerYaw(SI_VAR(0), 0);
    sleep 2;
    SetPlayerFlagBits(2097152, 0);
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        sleep 4;
        loop 40 {
            SI_VAR(1) -= 1;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    func_802D286C(2048);
    func_802D2520(ANIM_10002, 5, 2, 1, 1, 0);
    sleep 25;
    await 0xFE363C8C;
});

EvtSource N(8024462C) = SCRIPT({
    IsPlayerOnValidFloor(SI_VAR(0));
    if (SI_VAR(0) == 0) {
        return;
    }
    GetPlayerActionState(SI_VAR(0));
    if (SI_VAR(0) == 26) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    group 27;
    N(SetPlayerStatusAnimFlags100000)();
    DisablePlayerPhysics(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    SI_VAR(0) = SI_VAR(10);
    N(GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(6) += 2;
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(8) = SI_VAR(4);
    SI_VAR(8) += 180;
    if (SI_VAR(4) >= 360) {
        SI_VAR(4) -= 360;
    }
    InterpPlayerYaw(SI_VAR(8), 1);
    sleep 1;
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerPos(SI_VAR(0), SI_VAR(6), SI_VAR(7));
    SetPlayerAnimation(ANIM_STAND_STILL);
    func_802D286C(2048);
    func_802D2520(ANIM_STAND_STILL, 5, 3, 1, 1, 0);
    spawn {
        sleep 8;
        HidePlayerShadow(TRUE);
    }
    spawn {
        sleep 3;
        loop 40 {
            N(SomeXYZFunc2)(1.0);
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    sleep 25;
    await 0xFE363C8C;
});

EvtSource N(exitWalk_80244960) = SCRIPT({
    group 27;
    SI_SAVE_FLAG(761) = 0;
    UseExitHeading(60, 0);
    spawn ExitWalk;
    GotoMap("sbk_36", 1);
    sleep 100;
});

EvtSource N(exitWalk_802449CC) = EXIT_WALK_SCRIPT(60,  1, "dro_02",  0);

EvtSource N(80244A28) = SCRIPT({
    bind N(exitWalk_80244960) TRIGGER_FLOOR_ABOVE 1;
    bind N(exitWalk_802449CC) TRIGGER_FLOOR_ABOVE 5;
});

EvtSource N(80244A70) = SCRIPT({
    PlaySound(0x80000060);
    UseSettingsFrom(0, 175, 0, -201);
    SetPanTarget(0, 175, 0, -201);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    N(UnkFunc27)(2, 0, 3);
    N(UnkFunc27)(1, -1, 3);
    N(UnkFunc26)(3, 44, 32, 177, 0, 0, 0, 0, 0, 0);
    DisablePlayerInput(TRUE);
    spawn {
        ShakeCam(0, 0, 300, 0.2001953125);
    }
    spawn {
        sleep 60;
        GetEntryID(SI_VAR(0));
        if (SI_VAR(0) == 3) {
            GotoMap("dro_02", 2);
        } else {
            GotoMap("dro_02", 3);
        }
        sleep 100;
    }
});

EvtSource N(enterWalk_80244C14) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(80244A28);
        return;
    }
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 2 {
            if (SI_SAVE_FLAG(1939) == 0) {
                DisablePlayerInput(TRUE);
                DisablePlayerPhysics(TRUE);
                GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SetPlayerPos(SI_VAR(0), -1000, SI_VAR(2));
                sleep 30;
                PlaySound(SOUND_UNKNOWN_208E);
                SI_SAVE_FLAG(1939) = 1;
                sleep 30;
                SetPlayerActionState(0);
                SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
                SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                DisablePlayerPhysics(FALSE);
                DisablePlayerInput(FALSE);
            }
            SI_VAR(10) = N(80244A28);
            await N(80243C30);
        }
        3, 4 {
            await N(80244A70);
        }
        == 10 {
            spawn 0x80285C50;
            spawn N(80244A28);
        } else {
            SI_VAR(0) = N(80244A28);
            spawn EnterWalk;
        }
    }
    sleep 1;
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_DRY_DRY_OUTPOST;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    SI_SAVE_FLAG(1973) = 1;
    if (SI_STORY_PROGRESS < STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST) {
        SI_STORY_PROGRESS = STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST;
    }
    match SI_STORY_PROGRESS {
        -53 ... 6 {
            MakeNpcs(0, N(npcGroupList_8024B47C));
        } else {
            MakeNpcs(0, N(npcGroupList_8024B464));
        }
    }
    InitVirtualEntityList();
    await N(makeEntities);
    MakeShop(N(shopItemPositions_8024BA68), N(shopInventory_8024B4FC), N(shopPriceList_8024B550), 0);
    MakeShopOwner(N(shopOwnerNPC_8024BA80));
    await N(8024C218);
    spawn N(8024C2EC);
    spawn N(80243BB0);
    spawn N(enterWalk_80244C14);
    sleep 1;
    spawn N(8024DD78);
});

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

EvtSource N(npcAI_80245040) = SCRIPT({
    DoBasicAI(N(npcAISettings_80245010));
});

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

EvtSource N(npcAI_802450BC) = SCRIPT({
    N(func_80241174_95C374)(N(npcAISettings_8024508C));
});

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

EvtSource N(802451BC) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

EvtSource N(802451EC) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

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

typedef struct {
    s32 unk_00;
    s32 unk_04;
} N(quizReqStruct);

N(quizReqStruct) N(quizRequirements)[] = {
    { -108, 0 }, { -76, 10 },
    { -54, 20 }, { -14, 30 },
    {   6, 37 }, {  39, 44 },
    {  58, 52 }, {  88, 60 },
    {  96, 64 }, {   0, 64 },
};

EvtSource N(802452AC) = SCRIPT({
    N(GetGameStatus75)();
    if (SI_VAR(0) <= 1) {
        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 300;
        SetNpcJumpscale(NPC_SELF, 1);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_C));
        sleep 40;
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(8024535C) = SCRIPT({
    N(GetCamVfov)(0, SI_ARRAY(0));
    N(SetCamVfov)(0, 25);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetCamType(0, SI_VAR(1), SI_VAR(2));
    SetCamType(0, SI_VAR(1), 0);
    GetCamDistance(0, SI_VAR(0));
    if (SI_VAR(0) > 0) {
        SI_VAR(0) = (float) 370;
    } else {
        SI_VAR(0) = (float) -370;
    }
    SetCamDistance(0, SI_VAR(0));
    GetCamPitch(0, SI_VAR(0), SI_VAR(1));
    SI_VAR(0) = 13.0;
    SI_VAR(1) = -10.0;
    SetCamPitch(0, SI_VAR(0), SI_VAR(1));
    PanToTarget(0, 0, 1);
    SetCamLeadPlayer(0, 0);
});

EvtSource N(802454F8) = SCRIPT({
    GetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 30;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetCamDistance(0, SI_VAR(0));
    if (SI_VAR(0) > 0) {
        SI_VAR(0) = (float) 17;
    } else {
        SI_VAR(0) = (float) -17;
    }
    SetCamDistance(0, SI_VAR(0));
    SetCamSpeed(0, 90.0);
    WaitForCam(0, 1.0);
    SetCamSpeed(0, 1);
});

EvtSource N(802455F4) = SCRIPT({
    N(SetCamVfov)(0, SI_ARRAY(0));
    PanToTarget(0, 0, 0);
});

EvtSource N(80245630) = SCRIPT({
    sleep 20;
    N(UnkCameraFunc)(SI_ARRAY(1), SI_ARRAY(3), 83, SI_VAR(0), SI_VAR(1));
    spawn {
        SI_VAR(2) = (float) 0;
        loop 60 {
            SI_VAR(3) = (float) SI_VAR(0);
            SI_VAR(4) = (float) SI_VAR(1);
            SI_VAR(3) *= (float) SI_VAR(2);
            SI_VAR(4) *= (float) SI_VAR(2);
            SI_VAR(3) /= (float) 60;
            SI_VAR(4) /= (float) 60;
            SI_VAR(3) += (float) SI_ARRAY(1);
            SI_VAR(4) += (float) SI_ARRAY(3);
            SetPlayerPos(SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
            SI_VAR(2) += (float) 1;
            sleep 1;
        }
        SI_VAR(3) = (float) SI_VAR(0);
        SI_VAR(4) = (float) SI_VAR(1);
        SI_VAR(3) += (float) SI_ARRAY(1);
        SI_VAR(4) += (float) SI_ARRAY(3);
        SetPlayerPos(SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
    }
    N(UnkRotatePlayer)();
    func_802D2884(SI_ARRAY(1), SI_ARRAY(3), 0);
    SetPlayerAnimation(ANIM_10002);
});

EvtSource N(802457E0) = SCRIPT({
    GetNpcPos(NPC_PARTNER, SI_VAR(10), SI_VAR(11), SI_VAR(12));
    N(UnkCameraFunc)(SI_VAR(10), SI_VAR(12), 108, SI_VAR(0), SI_VAR(1));
    SI_VAR(5) = (float) SI_ARRAY(2);
    SI_VAR(5) -= (float) SI_VAR(11);
    spawn {
        N(UnkMovePartner)();
        SI_VAR(3) = (float) SI_VAR(0);
        SI_VAR(4) = (float) SI_VAR(1);
        SI_VAR(6) = (float) SI_VAR(5);
        SI_VAR(3) += (float) SI_VAR(10);
        SI_VAR(4) += (float) SI_VAR(12);
        SI_VAR(6) += (float) SI_VAR(11);
        SetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(6), SI_VAR(4));
    }
    N(UnkRotatePartner)();
    NpcFacePlayer(NPC_PARTNER, 0);
    SetNpcAnimation(NPC_PARTNER, 0x106);
});

EvtSource N(80245918) = SCRIPT({
    GetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(10), SI_VAR(11), SI_VAR(12));
    N(UnkCameraFunc)(SI_VAR(10), SI_VAR(12), -70, SI_VAR(0), SI_VAR(1));
    spawn {
        SI_VAR(2) = (float) 0;
        loop 60 {
            SI_VAR(3) = (float) SI_VAR(0);
            SI_VAR(4) = (float) SI_VAR(1);
            SI_VAR(3) *= (float) SI_VAR(2);
            SI_VAR(4) *= (float) SI_VAR(2);
            SI_VAR(3) /= (float) 60;
            SI_VAR(4) /= (float) 60;
            SI_VAR(3) += (float) SI_VAR(10);
            SI_VAR(4) += (float) SI_VAR(12);
            SetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
            SI_VAR(2) += (float) 1;
            sleep 1;
        }
    }
    sleep 60;
    NpcFacePlayer(NPC_CHUCK_QUIZMO, 0);
    SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_1));
});

EvtSource N(80245A84) = SCRIPT({
    spawn N(80245630);
    spawn N(802457E0);
    await N(80245918);
});

EvtSource N(80245AB8) = SCRIPT({
    loop {
        SetPlayerAnimation(ANIM_QUESTION);
        sleep 20;
    }
});

EvtSource N(80245AF8) = SCRIPT({
    SetPlayerAnimation(ANIM_THROW);
    sleep 15;
    SetPlayerAnimation(ANIM_10002);
});

EvtSource N(80245B34) = SCRIPT({
    loop {
        SetPlayerAnimation(ANIM_10002);
        sleep 1;
        SetPlayerAnimation(ANIM_BEFORE_JUMP);
        sleep 2;
        SetPlayerAnimation(ANIM_MIDAIR_STILL);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_MIDAIR);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_10009);
        sleep 2;
        sleep 1;
        SetPlayerAnimation(ANIM_BEFORE_JUMP);
        sleep 2;
        SetPlayerAnimation(ANIM_MIDAIR_STILL);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_MIDAIR);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_10009);
        sleep 2;
        sleep 1;
        SetPlayerAnimation(ANIM_BEFORE_JUMP);
        sleep 2;
        SetPlayerAnimation(ANIM_MIDAIR_STILL);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_MIDAIR);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += 0;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -2;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SI_VAR(1) += -3;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        SetPlayerAnimation(ANIM_10009);
        sleep 2;
    }
    SetPlayerAnimation(ANIM_10002);
    SetPlayerPos(SI_VAR(0), SI_ARRAY(2), SI_VAR(2));
    sleep 1;
});

EvtSource N(8024667C) = SCRIPT({
    SetPlayerAnimation(ANIM_SHOCK_STILL);
    loop {
        sleep 1;
    }
});

EvtSource N(802466BC) = SCRIPT({
    spawn {
        N(UnkCameraFunc)(SI_ARRAY(1), SI_ARRAY(3), 25, SI_VAR(0), SI_VAR(1));
        SI_VAR(2) = (float) SI_ARRAY(1);
        SI_VAR(2) += (float) SI_VAR(0);
        SI_VAR(3) = (float) SI_ARRAY(3);
        SI_VAR(3) += (float) SI_VAR(1);
        SetNpcAnimation(NPC_PARTNER, 0x102);
        NpcMoveTo(NPC_PARTNER, SI_VAR(2), SI_VAR(3), 40);
        SetNpcAnimation(NPC_PARTNER, 0x106);
    }
    PlayerMoveTo(SI_ARRAY(1), SI_ARRAY(3), 40);
});

EvtSource N(80246798) = SCRIPT({
    SI_VAR(1) = spawn N(80245B34);
    sleep 60;
    kill SI_VAR(1);
    loop 5 {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 2;
    }
    sleep 20;
    await N(802466BC);
});

EvtSource N(80246848) = SCRIPT({
    SI_VAR(1) = spawn N(8024667C);
    sleep 60;
    loop 5 {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 2;
    }
    sleep 20;
    kill SI_VAR(1);
    await N(802466BC);
});

EvtSource N(802468F8) = SCRIPT({
    if (SI_SAVE_VAR(352) > 63) {
        SI_VAR(0) = 0;
        return;
    }
    GetPlayerPos(SI_ARRAY(1), SI_ARRAY(2), SI_ARRAY(3));
    NpcFacePlayer(NPC_SELF, 16);
    if (SI_SAVE_VAR(352) == 63) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x000A));
    } else {
        if (SI_SAVE_FLAG(1767) == 1) {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x0009));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x0008));
            SI_SAVE_FLAG(1767) = 1;
        }
    }
    ShowChoice(MESSAGE_ID(0x1E, 0x000D));
    if (SI_VAR(0) == 1) {
        ContinueSpeech(-1, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x000C));
        await N(802452AC);
        SI_VAR(0) = 0;
        return;
    }
    SI_SAVE_FLAG(1793) = 1;
    N(Set80151310_1)();
    N(UnkAlphaFunc)();
    spawn N(8024535C);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_CHUCK_QUIZMO, ((NPC_FLAG_GRAVITY)), FALSE);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100)), TRUE);
    SetNpcFlagBits(NPC_CHUCK_QUIZMO, ((NPC_FLAG_100)), TRUE);
    SetNpcAnimation(NPC_PARTNER, 0x106);
    SI_VAR(1) = spawn N(80245A84);
    ContinueSpeech(-1, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x000B));
    PlaySound(0x89);
    loop {
        SI_VAR(0) = does_script_exist SI_VAR(1);
        if (SI_VAR(0) == 0) {
            break loop;
        }
        sleep 1;
    }
    N(func_80241BE0_95CDE0)();
    loop 5 {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 2;
    }
    SI_VAR(0) = 2883584;
    SI_VAR(0) += SI_SAVE_VAR(352);
    SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_5), NPC_ANIM(chuck_quizmo, Palette_00, Anim_6), 0, SI_VAR(0));
    SetPlayerAnimation(ANIM_QUESTION);
    SI_VAR(0) = 2949120;
    SI_VAR(0) += SI_SAVE_VAR(352);
    PlaySound(0x8E);
    ShowChoice(SI_VAR(0));
    kill SI_VAR(1);
    StopSound(142);
    spawn N(80245AF8);
    sleep 15;
    PlaySound(0x8D);
    N(func_80241EE0_95D0E0)(SI_VAR(0));
    SI_ARRAY(4) = 0;
    N(func_802424D4_95D6D4)();
    sleep 40;
    N(func_80241B5C_95CD5C)();
    spawn {
        sleep 110;
        CloseChoice();
        SI_ARRAY(4) = 0;
    }
    if (SI_VAR(0) == 1) {
        SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_7));
        SI_ARRAY(4) = 1;
        spawn {
            N(func_80241EAC_95D0AC)(1);
            sleep 6;
            sleep 6;
            sleep 6;
            N(func_80241EAC_95D0AC)(2);
        }
        spawn {
            PlaySound(0x21C);
            sleep 6;
            PlaySound(0x21C);
            sleep 6;
            PlaySound(0x21C);
            sleep 6;
            PlaySound(0x21C);
        }
        PlaySound(0x8A);
        N(func_80241F78_95D178)();
        spawn {
            sleep 15;
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 50;
            N(UnkCameraFunc)(0, 0, 83, SI_VAR(0), SI_VAR(2));
            PlayEffect(0x7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            PlayEffect(0x44, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) += -3;
            N(UnkCameraFunc)(0, 0, 58, SI_VAR(0), SI_VAR(2));
            PlayEffect(0x7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            PlayEffect(0x44, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) += 30;
            N(UnkCameraFunc)(0, 0, 93, SI_VAR(0), SI_VAR(2));
            PlayEffect(0x7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            PlayEffect(0x44, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
        }
        sleep 20;
        SI_VAR(1) = spawn N(80246798);
        SI_SAVE_VAR(352) += 1;
        if (SI_SAVE_VAR(352) > 63) {
            ContinueSpeech(-1, -1, -1, 0, MESSAGE_ID(0x08, 0x0010));
            SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_6));
            loop {
                SI_VAR(0) = does_script_exist SI_VAR(1);
                if (SI_VAR(0) == 0) {
                    break loop;
                }
                sleep 1;
            }
            SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_5));
            SI_VAR(0) = 348;
            SI_VAR(1) = 3;
            await N(802451BC);
            AddStarPieces(1);
            N(func_80241EAC_95D0AC)(15);
            N(func_80241F60_95D160)();
            SetMessageValue(SI_SAVE_VAR(352), 0);
            SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x0011));
        } else {
            ContinueSpeech(-1, -1, -1, 0, MESSAGE_ID(0x08, 0x000E));
            SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_6));
            loop {
                SI_VAR(0) = does_script_exist SI_VAR(1);
                if (SI_VAR(0) == 0) {
                    break loop;
                }
                sleep 1;
            }
            SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_5));
            SI_VAR(0) = 348;
            SI_VAR(1) = 1;
            await N(802451BC);
            AddStarPieces(1);
            N(func_80241EAC_95D0AC)(15);
            N(func_80241F60_95D160)();
            SetMessageValue(SI_SAVE_VAR(352), 0);
            if (SI_SAVE_VAR(352) == 1) {
                SetMessageString(2148844180, 1);
            } else {
                SetMessageString(2148844176, 1);
            }
            SpeakToPlayer(NPC_SELF, NPC_ANIM(chuck_quizmo, Palette_00, Anim_4), NPC_ANIM(chuck_quizmo, Palette_00, Anim_1), 0, MESSAGE_ID(0x08, 0x000F));
        }
        SI_VAR(0) = 1;
    } else {
        SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_9));
        SI_ARRAY(4) = 2;
        PlaySound(0x21D);
        PlaySound(0x8B);
        SI_VAR(1) = spawn N(80246848);
        GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
        PlayEffect(0x2B, 0, SI_VAR(2), SI_VAR(3), SI_VAR(4), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        ContinueSpeech(-1, -1, -1, 0, MESSAGE_ID(0x08, 0x000D));
        SetNpcAnimation(NPC_CHUCK_QUIZMO, NPC_ANIM(chuck_quizmo, Palette_00, Anim_A));
        loop {
            SI_VAR(0) = does_script_exist SI_VAR(1);
            if (SI_VAR(0) == 0) {
                break loop;
            }
            sleep 1;
        }
        SI_VAR(0) = 0;
    }
    N(func_80241EE0_95D0E0)(-1);
    EnablePartnerAI();
    spawn {
        sleep 30;
        PlaySound(0x8F);
    }
    spawn {
        sleep 45;
        StopSound(137);
    }
    N(func_80241F94_95D194)();
    N(func_80241DF8_95CFF8)();
    await N(802452AC);
    spawn N(802455F4);
    N(UnkFunc29)();
    N(Set80151310_0)();
    SI_SAVE_FLAG(1793) = 0;
});

EvtSource N(80247628) = SCRIPT({
    N(func_802415AC_95C7AC)();
    if (SI_VAR(0) == 0) {
        return;
    }
    SetNpcFlagBits(NPC_SELF, ((0x01000000)), FALSE);
    SetNpcSprite(-1, 0xAF0001);
    N(UnkFunc31)();
});

EvtSource N(8024769C) = SCRIPT({
    arr_use 0x8024DFC8; // TODO rawptr
    SI_SAVE_FLAG(1769) = 1;
    DisablePlayerPhysics(TRUE);
    SetPlayerFlagBits(4194304, 1);
    await N(802468F8);
    DisablePlayerPhysics(FALSE);
    SetPlayerFlagBits(4194304, 0);
});

EvtSource N(8024771C) = SCRIPT({
    N(GetNpcUnsafeOwner2)();
});

NpcAISettings N(npcAISettings_80247738) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .unk_14 = -1,
    .unk_2C = 1,
};

EvtSource N(80247768) = SCRIPT({
    DoBasicAI(N(npcAISettings_80247738));
});

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

EvtSource N(802477E8) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    ShowKeyChoicePopup();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(AddPlayerHandsOffset)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            SI_VAR(0) |= (const)  0x50000;
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80242784_95D984)(SI_VAR(10));
    CloseChoicePopup();
    unbind;
});

EvtSource N(8024792C) = SCRIPT({
    N(func_802427BC_95D9BC)(SI_VAR(0));
    bind_padlock N(802477E8) 0x10 0 N(D_8024DFF0);
    N(func_80242730_95D930)(SI_VAR(0));
});

EvtSource N(8024797C) = SCRIPT({
    loop {
        GetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
        N(UnkYawFunc)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
        SetItemPos(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5));
        sleep 1;
    }
});

EvtSource N(802479FC) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    ShowKeyChoicePopup();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(SI_VAR(1));
            DisablePartnerAI(0);
            GetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(UnkYawFunc)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            SI_VAR(0) |= (const)  0x50000;
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SI_VAR(10) = spawn N(8024797C);
            SetNpcAnimation(NPC_PARTNER, NPC_ANIM(world_parakarry, Palette_00, Anim_2));
            GetAngleBetweenNPCs(SI_VAR(9), -4, SI_VAR(11));
            GetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
            GetNpcPos(SI_VAR(9), SI_VAR(6), SI_VAR(7), SI_VAR(8));
            SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
            if (SI_VAR(11) <= 180) {
                SI_VAR(6) += 20;
            } else {
                SI_VAR(6) += -20;
            }
            SI_VAR(7) += 10;
            SetNpcJumpscale(NPC_PARTNER, 0.0);
            NpcJump1(NPC_PARTNER, SI_VAR(6), SI_VAR(7), SI_VAR(8), 20);
            kill SI_VAR(10);
            RemoveItemEntity(SI_VAR(0));
            sleep 20;
            GetNpcYaw(-4, SI_VAR(10));
            SI_VAR(10) += 180;
            InterpNpcYaw(NPC_PARTNER, SI_VAR(10), 0);
            sleep 5;
            NpcJump1(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5), 20);
            SetNpcAnimation(NPC_PARTNER, NPC_ANIM(world_parakarry, Palette_00, Anim_1));
            NpcFaceNpc(NPC_PARTNER, SI_VAR(9), 0);
            sleep 5;
            SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), FALSE);
            EnablePartnerAI();
            sleep 5;
        }
    }
    N(func_80242784_95D984)(SI_VAR(10));
    CloseChoicePopup();
    unbind;
});

EvtSource N(80247D20) = SCRIPT({
    SI_VAR(0) = SI_VAR(11);
    SI_VAR(1) = SI_VAR(2);
    N(func_802427BC_95D9BC)(SI_VAR(0));
    bind_padlock N(802479FC) 0x10 0 N(D_8024DFF0);
    N(func_80242730_95D930)(SI_VAR(0));
});

EvtSource N(80247D90) = SCRIPT({
    SI_VAR(12) = 0;
    if (SI_STORY_PROGRESS < STORY_CH2_PARAKARRY_JOINED_PARTY) {
        return;
    }
    N(func_80243014_95E214)();
    GetCurrentPartnerID(SI_VAR(0));
    FindKeyItem(SI_VAR(5), SI_VAR(1));
    if (SI_VAR(0) == 4) {
        if (SI_VAR(1) != -1) {
            DisablePartnerAI(0);
            PlayerFaceNpc(SI_VAR(2), 0);
            sleep 1;
            GetNpcPos(SI_VAR(2), SI_VAR(13), SI_VAR(0), SI_VAR(14));
            GetNpcPos(NPC_PARTNER, SI_VAR(13), SI_VAR(14), SI_VAR(15));
            SetNpcJumpscale(NPC_PARTNER, 0.0);
            SI_VAR(0) += 10;
            NpcJump1(NPC_PARTNER, SI_VAR(13), SI_VAR(0), SI_VAR(15), 10);
            SpeakToNpc(-4, 262150, 262145, 0, SI_VAR(2), SI_VAR(7));
            EnablePartnerAI();
            await N(80247D20);
            match SI_VAR(0) {
                == -1 {
                    DisablePartnerAI(0);
                    sleep 1;
                    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_parakarry, Palette_00, Anim_6), NPC_ANIM(world_parakarry, Palette_00, Anim_1), 5, SI_VAR(8));
                    EnablePartnerAI();
                    SI_VAR(12) = 1;
                } else {
                    DisablePartnerAI(0);
                    sleep 1;
                    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_parakarry, Palette_00, Anim_6), NPC_ANIM(world_parakarry, Palette_00, Anim_1),
                                  5, SI_VAR(9));
                    if (SI_VAR(10) != 0) {
                        SpeakToPlayer(SI_VAR(2), SI_VAR(3), SI_VAR(4), 0, SI_VAR(10));
                    }
                    EnablePartnerAI();
                    if (SI_VAR(6) != 0) {
                        SI_VAR(0) = SI_VAR(6);
                        SI_VAR(1) = 1;
                        await N(802451BC);
                        AddKeyItem(SI_VAR(6));
                    }
                    SI_VAR(12) = 2;
                }
            }
        }
    }
    N(func_80243058_95E258)();
});

s32 N(D_80248088_963288)[] = {
    0x0000004C, 0x00000000,
};

EvtSource N(80248090) = SCRIPT({
    N(SetManyVars)(6, 9699589, 9699585, 76, 69, 852105, 852106, 852107, 852108, N(D_80248088_963288));
    await N(80247D90);
});

EvtSource N(interact_802480E0) = SCRIPT({
    if (SI_STORY_PROGRESS >= STORY_CH2_STAR_SPRIT_DEPARTED) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(mouser, Palette_00, Anim_5), NPC_ANIM(mouser, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x0062));
        return;
    }
    match SI_AREA_VAR(0) {
        == 0 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(mouser, Palette_00, Anim_5), NPC_ANIM(mouser, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x005F));
            SI_AREA_VAR(0) += 1;
        }
        == 1 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(mouser, Palette_00, Anim_5), NPC_ANIM(mouser, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0060));
            SI_AREA_VAR(0) += 1;
        }
        == 2 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(mouser, Palette_00, Anim_5), NPC_ANIM(mouser, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0061));
            SI_AREA_VAR(0) -= 1;
        }
    }
});

EvtSource N(init_802481F8) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802480E0));
});

EvtSource N(interact_8024821C) = SCRIPT({
    match SI_STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_STORY_PROGRESS >= STORY_CH2_BOUGHT_SECRET_ITEMS) {
                if (SI_AREA_VAR(1) == 2) {
                    SI_AREA_VAR(1) = 0;
                }
            }
            match SI_AREA_VAR(1) {
                == 0 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_03, Anim_4), NPC_ANIM(dryite, Palette_03, Anim_1), 0, MESSAGE_ID(0x0D, 0x0063));
                    SI_AREA_VAR(1) += 1;
                }
                == 1 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_03, Anim_4), NPC_ANIM(dryite, Palette_03, Anim_1), 0, MESSAGE_ID(0x0D, 0x0064));
                    SI_AREA_VAR(1) += 1;
                }
                == 2 {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_03, Anim_4), NPC_ANIM(dryite, Palette_03, Anim_1), 0, MESSAGE_ID(0x0D, 0x0065));
                    SI_AREA_VAR(1) = 0;
                }
            }
        }
        < 39 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_03, Anim_4), NPC_ANIM(dryite, Palette_03, Anim_1), 0, MESSAGE_ID(0x0D, 0x0066));
        } else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_03, Anim_4), NPC_ANIM(dryite, Palette_03, Anim_1), 0, MESSAGE_ID(0x0D,
                          0x0067));
        }
    }
});

EvtSource N(init_802483A8) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024821C));
});

EvtSource N(interact_802483CC) = SCRIPT({
    match SI_AREA_VAR(2) {
        == 0 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_02, Anim_4), NPC_ANIM(dryite, Palette_02, Anim_1), 0, MESSAGE_ID(0x0D, 0x0068));
            SI_AREA_VAR(2) += 1;
        }
        == 1 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_02, Anim_4), NPC_ANIM(dryite, Palette_02, Anim_1), 0, MESSAGE_ID(0x0D, 0x0069));
            SI_AREA_VAR(2) += 1;
        }
        == 2 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_02, Anim_4), NPC_ANIM(dryite, Palette_02, Anim_1), 0, MESSAGE_ID(0x0D, 0x006A));
            SI_AREA_VAR(2) += 1;
        }
        == 3 {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_02, Anim_4), NPC_ANIM(dryite, Palette_02, Anim_1), 0, MESSAGE_ID(0x0D, 0x006B));
            SI_AREA_VAR(2) = 0;
        }
    }
});

EvtSource N(init_802484E0) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802483CC));
});

EvtSource N(80248504) = SCRIPT({
    loop {
        N(GetFloorCollider)(SI_VAR(0));
        if (SI_VAR(0) == 8) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    func_802CF56C(1);
    spawn {
        sleep 20;
        func_802CF56C(0);
        NpcFacePlayer(NPC_PARTNER, 0);
    }
    PlayerFaceNpc(3, 0);
    SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0078));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_DRYITE2, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += (float) SI_VAR(3);
    SI_VAR(1) += (float) SI_VAR(4);
    SI_VAR(2) += (float) SI_VAR(5);
    SI_VAR(0) /= 2.0;
    SI_VAR(1) /= 2.0;
    SI_VAR(2) /= 2.0;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, -300.0);
    SetCamSpeed(0, 5.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SetPlayerAnimation(ANIM_10002);
    SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0079));
    SetPlayerAnimation(ANIM_80007);
    sleep 30;
    SetPlayerAnimation(ANIM_10002);
    SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x007A));
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    N(func_80243084_95E284)();
    SI_SAVE_FLAG(761) = 1;
    DisablePlayerInput(FALSE);
});

s32 N(D_8024884C_963A4C)[] = {
    0x0000007D, 0x00000000, 0xFFFFFFD6, 0x0000004B, 0x0000004B, N(func_802430C8_95E2C8),
};

EvtSource N(interact_80248864) = SCRIPT({
    if (SI_SAVE_FLAG(253) == 1) {
        if (SI_SAVE_FLAG(761) == 1) {
            N(func_802431B4_95E3B4)();
            if (SI_VAR(0) == 1) {
                SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x007B));
                return;
            }
        }
    }
    match SI_STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(1) == 0) {
                SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x006C));
                SpeakToPlayer(NPC_DRYITE3, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x006D));
                SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x006E));
                SI_AREA_FLAG(1) = 1;
            } else {
                SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x006F));
                SpeakToPlayer(NPC_DRYITE3, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x0070));
                SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x0071));
                SI_AREA_FLAG(1) = 0;
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0072));
            SpeakToPlayer(NPC_DRYITE3, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0073));
            SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0, MESSAGE_ID(0x0D, 0x0074));
        } else {
            SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0075));
            SpeakToPlayer(NPC_DRYITE3, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0076));
            SpeakToPlayer(NPC_DRYITE2, NPC_ANIM(dryite, Palette_00, Anim_4), NPC_ANIM(dryite, Palette_00, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0077));
        }
    }
});

EvtSource N(init_80248AE4) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        3, 4 {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(dryite, Palette_00, Anim_4));
            return;
        }
    }
    BindNpcInteract(NPC_SELF, N(interact_80248864));
    if (SI_SAVE_FLAG(253) == 1) {
        spawn {
            N(func_80242858_95DA58)(N(D_8024884C_963A4C));
        }
    }
});

EvtSource N(interact_80248BA0) = SCRIPT({
    parallel {
        loop {
            NpcFaceNpc(NPC_DRYITE2, NPC_DRYITE3, 1);
        }
    }
    N(func_802431FC_95E3FC)();
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(dryite, Palette_00, Anim_3));
    SetNpcSpeed(NPC_SELF, 3.5);
    NpcMoveTo(NPC_SELF, SI_VAR(0), SI_VAR(1), 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(dryite, Palette_00, Anim_1));
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), FALSE);
    sleep 5;
    GetNpcYaw(-1, SI_VAR(0));
    SI_VAR(0) += 180;
    InterpNpcYaw(NPC_SELF, SI_VAR(0), 0);
});

EvtSource N(init_80248CC8) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        3, 4 {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(dryite, Palette_00, Anim_4));
            return;
        }
    }
    BindNpcInteract(NPC_SELF, N(interact_80248BA0));
});

s32 N(D_80248D4C_963F4C)[] = {
    0x00000067, 0x00000000,
};

EvtSource N(interact_80248D54) = SCRIPT({
    if (SI_SAVE_FLAG(754) == 1) {
        FindKeyItem(ITEM_MELODY, SI_VAR(0));
        if (SI_VAR(0) != -1) {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0084));
            return;
        } else {
            if (SI_SAVE_FLAG(755) == 0) {
                if (SI_STORY_PROGRESS < STORY_CH7_BEGAN_PEACH_MISSION) {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                                  MESSAGE_ID(0x0D, 0x0085));
                    SetPlayerAnimation(ANIM_NOD_YES);
                    sleep 30;
                    SetPlayerAnimation(ANIM_10002);
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                                  MESSAGE_ID(0x0D, 0x0086));
                    SI_SAVE_FLAG(755) = 1;
                    return;
                }
            }
        }
    }
    match SI_STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(2) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x007C));
                SI_AREA_FLAG(2) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x007D));
                SI_AREA_FLAG(2) = 0;
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(2) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x007E));
                SI_AREA_FLAG(2) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x007F));
                SI_AREA_FLAG(2) = 0;
            }
        } else {
            if (SI_AREA_FLAG(2) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x0080));
                SI_AREA_FLAG(2) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                              MESSAGE_ID(0x0D, 0x0081));
                SI_AREA_FLAG(2) = 0;
            }
        }
    }
    SI_VAR(0) = N(D_80248D4C_963F4C);
    SI_VAR(1) = 5;
    await N(8024792C);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0082));
            SetNpcAnimation(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_3));
            sleep 60;
            SetNpcAnimation(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_1));
            SpeakToPlayer(NPC_SELF, NPC_ANIM(artist_toad, Palette_01, Anim_2), NPC_ANIM(artist_toad, Palette_01, Anim_1), 0,
                          MESSAGE_ID(0x0D, 0x0083));
            SI_VAR(0) = 104;
            SI_VAR(1) = 1;
            await N(802451BC);
            AddKeyItem(ITEM_MELODY);
            SI_SAVE_FLAG(754) = 1;
            return;
        }
    }
});

EvtSource N(init_80249168) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80248D54));
});

EvtSource N(idle_8024918C) = SCRIPT({
    match SI_STORY_PROGRESS {
        < STORY_CH2_SHADY_MOUSE_LEFT_SHOP {
            N(func_80243350_95E550)(16, 190, -134, -131);
            DisablePlayerInput(TRUE);
            SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
            SetNpcPos(NPC_SELF, 0, 0, -180);
            await N(8024C41C);
            sleep 10;
            GetPlayerPos(SI_VAR(10), SI_VAR(11), SI_VAR(12));
            UseSettingsFrom(0, SI_VAR(10), SI_VAR(11), SI_VAR(12));
            SetPanTarget(0, 32, 0, -67);
            SetCamDistance(0, -210);
            SetCamPitch(0, 20, -12);
            SetCamSpeed(0, 90.0);
            PanToTarget(0, 0, 1);
            sleep 20;
            UseSettingsFrom(0, SI_VAR(10), SI_VAR(11), SI_VAR(12));
            SetCamDistance(0, -350);
            SetCamSpeed(0, 0.80078125);
            PanToTarget(0, 0, 1);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_4));
            NpcMoveTo(NPC_SELF, -23, -105, 20);
            sleep 10;
            InterpNpcYaw(NPC_SELF, 65, 0);
            sleep 10;
            await N(8024C4C8);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_4));
            NpcMoveTo(NPC_SELF, 37, -27, 20);
            UseSettingsFrom(0, SI_VAR(10), SI_VAR(11), SI_VAR(12));
            SetPanTarget(0, 142, 0, -67);
            PanToTarget(0, 0, 1);
            NpcMoveTo(NPC_SELF, 62, -6, 20);
            NpcMoveTo(NPC_SELF, 103, 11, 20);
            NpcMoveTo(NPC_SELF, 150, 18, 20);
            EnableNpcBlur(-1, 1);
            PlaySoundAtNpc(NPC_SELF, 0x174, 0);
            NpcMoveTo(NPC_SELF, 554, -12, 20);
            SetNpcPos(NPC_SELF, 0, -1000, 0);
            sleep 30;
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamSpeed(0, 2.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            PanToTarget(0, 0, 0);
            DisablePlayerInput(FALSE);
            SI_STORY_PROGRESS = STORY_CH2_SHADY_MOUSE_LEFT_SHOP;
        }
        < STORY_CH2_SPOKE_WITH_SHEEK {}
        < STORY_CH2_SHADY_MOUSE_ENTERED_SHOP {
            EnableNpcBlur(-1, 1);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_4));
            PlaySoundAtNpc(NPC_SELF, 0x174, 0);
            SetNpcPos(NPC_SELF, 470, 0, 18);
            NpcMoveTo(NPC_SELF, 287, 9, 20);
            NpcMoveTo(NPC_SELF, 102, -14, 20);
            NpcMoveTo(NPC_SELF, -32, -96, 20);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_1));
            await N(8024C41C);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_4));
            NpcMoveTo(NPC_SELF, 20, -375, 30);
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_1));
            await N(8024C4C8);
            EnableNpcBlur(-1, 0);
            SI_STORY_PROGRESS = STORY_CH2_SHADY_MOUSE_ENTERED_SHOP;
        } else {
            SetNpcAnimation(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_1));
            SetNpcPos(NPC_SELF, 20, 0, -375);
        }
    }
});

EvtSource N(interact_80249750) = SCRIPT({
    if (SI_AREA_VAR(4) == 4) {
        if (SI_AREA_VAR(5) == 1) {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(mouser, Palette_01, Anim_5), NPC_ANIM(mouser, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                          0x0088));
            await N(80248090);
            if (SI_VAR(12) != 0) {
                return;
            }
            return;
        }
    }
    await 0x80284054;
    await N(80248090);
    if (SI_VAR(12) != 0) {
        return;
    }
});

EvtSource N(init_8024981C) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024918C));
    BindNpcInteract(NPC_SELF, N(interact_80249750));
});

EvtSource N(interact_80249854) = SCRIPT({
    SpeakToPlayer(NPC_THREE_SISTERS0, NPC_ANIM(three_sisters, Palette_01, Anim_4), NPC_ANIM(three_sisters, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x008E));
    SpeakToPlayer(NPC_THREE_SISTERS1, NPC_ANIM(three_sisters, Palette_01, Anim_4), NPC_ANIM(three_sisters, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x008F));
    SpeakToPlayer(NPC_THREE_SISTERS2, NPC_ANIM(three_sisters, Palette_01, Anim_4), NPC_ANIM(three_sisters, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x0090));
});

EvtSource N(init_802498C4) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80249854));
});

EvtSource N(interact_802498E8) = SCRIPT({
    FindKeyItem(ITEM_FIRST_DEGREE_CARD, SI_VAR(1));
    FindKeyItem(ITEM_SECOND_DEGREE_CARD, SI_VAR(2));
    FindKeyItem(ITEM_THIRD_DEGREE_CARD, SI_VAR(3));
    FindKeyItem(ITEM_FOURTH_DEGREE_CARD, SI_VAR(4));
    FindKeyItem(ITEM_DIPLOMA, SI_VAR(5));
    if (SI_VAR(1) != -1) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x009A));
        return;
    }
    if (SI_VAR(2) != -1) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x009B));
        return;
    }
    if (SI_VAR(3) != -1) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x009C));
        return;
    }
    if (SI_VAR(4) != -1) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x009D));
        return;
    }
    if (SI_VAR(5) != -1) {
        SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D,
                      0x009E));
        return;
    }
    SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x0099));
});

EvtSource N(init_80249ABC) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_802498E8));
});

EvtSource N(interact_80249AE0) = SCRIPT({
    SpeakToPlayer(NPC_SELF, NPC_ANIM(dryite, Palette_01, Anim_4), NPC_ANIM(dryite, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x009F));
});

EvtSource N(init_80249B10) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80249AE0));
});

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
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_4),
            NPC_ANIM(mouser, Palette_00, Anim_4),
            NPC_ANIM(mouser, Palette_00, Anim_4),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
            NPC_ANIM(mouser, Palette_00, Anim_1),
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
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_2),
            NPC_ANIM(dryite, Palette_03, Anim_3),
            NPC_ANIM(dryite, Palette_03, Anim_3),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_0),
            NPC_ANIM(dryite, Palette_03, Anim_0),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
            NPC_ANIM(dryite, Palette_03, Anim_1),
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
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_2),
            NPC_ANIM(dryite, Palette_02, Anim_3),
            NPC_ANIM(dryite, Palette_02, Anim_3),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_0),
            NPC_ANIM(dryite, Palette_02, Anim_0),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
            NPC_ANIM(dryite, Palette_02, Anim_1),
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
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_2),
            NPC_ANIM(dryite, Palette_00, Anim_3),
            NPC_ANIM(dryite, Palette_00, Anim_3),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_0),
            NPC_ANIM(dryite, Palette_00, Anim_0),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
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
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_2),
            NPC_ANIM(dryite, Palette_00, Anim_3),
            NPC_ANIM(dryite, Palette_00, Anim_3),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_0),
            NPC_ANIM(dryite, Palette_00, Anim_0),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
            NPC_ANIM(dryite, Palette_00, Anim_1),
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
            NPC_ANIM(artist_toad, Palette_01, Anim_1),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
            NPC_ANIM(artist_toad, Palette_01, Anim_0),
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
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_4),
            NPC_ANIM(mouser, Palette_01, Anim_4),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
            NPC_ANIM(mouser, Palette_01, Anim_1),
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
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_1),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_2),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_1),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_1),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_0),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_0),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
            NPC_ANIM(chuck_quizmo, Palette_00, Anim_3),
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
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_2),
            NPC_ANIM(dryite, Palette_01, Anim_3),
            NPC_ANIM(dryite, Palette_01, Anim_3),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_0),
            NPC_ANIM(dryite, Palette_01, Anim_0),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
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
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_2),
            NPC_ANIM(dryite, Palette_01, Anim_3),
            NPC_ANIM(dryite, Palette_01, Anim_3),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_0),
            NPC_ANIM(dryite, Palette_01, Anim_0),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
            NPC_ANIM(dryite, Palette_01, Anim_1),
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
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_2),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
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
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_2),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
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
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_2),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_1),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_6),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
            NPC_ANIM(three_sisters, Palette_01, Anim_3),
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

EvtSource N(8024B5B4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

EvtSource N(8024B5E4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 16);
    return;
});

EvtSource N(8024B614) = SCRIPT({
    NpcJump0(NPC_MOUSER1, -31, 0, -283, 10);
    NpcJump0(NPC_MOUSER1, -30, 0, -283, 8);
});

EvtSource N(8024B664) = SCRIPT({
    NpcJump0(NPC_MOUSER1, 20, 0, -259, 10);
    NpcJump0(NPC_MOUSER1, 20, 0, -259, 4);
});

// Extraneous END_IF
#ifdef NON_MATCHING
EvtSource N(8024B6B4) = SCRIPT({
    N(func_80243578_95E778)();
    func_802D2C14(1);
    await N(8024B614);
    if (SI_STORY_PROGRESS < STORY_CH2_BOUGHT_SECRET_ITEMS) {
        SpeakToPlayer(NPC_MOUSER1, NPC_ANIM(mouser, Palette_01, Anim_5), NPC_ANIM(mouser, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x0087));
        SetPlayerAnimation(ANIM_10002);
        sleep 10;
        SetPlayerAnimation(ANIM_80007);
        sleep 30;
    }
    SpeakToPlayer(NPC_MOUSER1, NPC_ANIM(mouser, Palette_01, Anim_5), NPC_ANIM(mouser, Palette_01, Anim_1), 0, MESSAGE_ID(0x0D, 0x0088));
    SI_STORY_PROGRESS = STORY_CH2_BOUGHT_SECRET_ITEMS;
    func_802D2C14(0);
    await N(8024B664);
});
#else
EvtSource N(8024B6B4) = {
    SI_CMD(EVT_OP_CALL, N(func_80243578_95E778)),
    SI_CMD(EVT_OP_CALL, func_802D2C14, 1),
    SI_CMD(EVT_OP_AWAIT_SCRIPT, N(8024B614)),
    SI_CMD(EVT_OP_IF_LT, SI_STORY_PROGRESS, -64),
        SI_CMD(EVT_OP_CALL, SpeakToPlayer, 6, 9699589, 9699585, 0, 852103),
        SI_CMD(EVT_OP_CALL, SetPlayerAnimation, 65538),
        SI_CMD(EVT_OP_SLEEP_FRAMES, 10),
        SI_CMD(EVT_OP_CALL, SetPlayerAnimation, 524295),
        SI_CMD(EVT_OP_SLEEP_FRAMES, 30),
    SI_CMD(EVT_OP_END_IF),
    SI_CMD(EVT_OP_CALL, SpeakToPlayer, 6, 9699589, 9699585, 0, 852104),
    SI_CMD(EVT_OP_SET, SI_STORY_PROGRESS, -64),
    SI_CMD(EVT_OP_CALL, func_802D2C14, 0),
    SI_CMD(EVT_OP_AWAIT_SCRIPT, N(8024B664)),
SI_CMD(EVT_OP_END_IF),
SI_CMD(EVT_OP_RETURN),
SI_CMD(EVT_OP_END)
};
#endif

EvtSource N(8024B7B0) = SCRIPT({
    if (SI_SAVE_FLAG(758) == 0) {
        N(func_80243578_95E778)();
        func_802D2C14(1);
        await N(8024B614);
        SpeakToPlayer(NPC_MOUSER1, NPC_ANIM(mouser, Palette_01, Anim_5), NPC_ANIM(mouser, Palette_01, Anim_1), 0,
                      MESSAGE_ID(0x0D, 0x008D));
        SI_VAR(0) = 119;
        SI_VAR(1) = 1;
        await N(8024B5B4);
        AddKeyItem(ITEM_RED_JAR);
        SI_SAVE_FLAG(758) = 1;
        sleep 20;
        func_802D2C14(0);
        await N(8024B664);
    }
});

EvtSource N(8024B894) = SCRIPT({
    match SI_VAR(0) {
        == 3 {}
        == 4 {}
        == 1 {
            SI_VAR(2) = SI_AREA_VAR(4);
            SI_VAR(3) = SI_AREA_VAR(5);
            SI_VAR(4) = SI_AREA_VAR(6);
            SI_AREA_VAR(5) = SI_VAR(2);
            SI_AREA_VAR(6) = SI_VAR(3);
            match SI_VAR(1) {
                == 141 {
                    SI_AREA_VAR(4) = 1;
                    if (SI_VAR(2) == 2) {
                        if (SI_VAR(3) == 3) {
                            if (SI_VAR(4) == 2) {
                                await N(8024B7B0);
                                SI_AREA_VAR(4) = 0;
                            }
                        }
                    }
                }
                == 134 {
                    SI_AREA_VAR(4) = 2;
                    if (SI_VAR(2) == 1) {
                        if (SI_STORY_PROGRESS < STORY_CH2_GOT_PULSE_STONE) {
                            await N(8024B6B4);
                            SI_AREA_VAR(4) = 0;
                        }
                    }
                }
                == 167 {
                    SI_AREA_VAR(4) = 3;
                } else {
                    SI_AREA_VAR(4) = 0;
                }
            }
        }
        == 2 {
        }
    }
});

s32 N(shopItemPositions_8024BA68)[] = {
    0x004C0021, 0x004B0022, 0x00490023, 0x004A0024, 0x00480025, 0x00470026,
};

s32 N(shopOwnerNPC_8024BA80)[] = {
    0x00000006, 0x00940101, 0x00940105, N(8024B894), 0x00000000, 0x00000000, N(intTable_8024B4A0),
};

s32 N(pad_BA9C) = {
    0x00000000,
};

EvtSource N(openDoor_8024BAA0) = SCRIPT({
    RotateModel(103, SI_VAR(0), 0, 1, 0);
});

EvtSource N(moveWalls_8024BAD0) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /= (float) 50;
    TranslateModel(98, 0, SI_VAR(1), 0);
    TranslateModel(97, 0, SI_VAR(1), 0);
    RotateModel(98, SI_VAR(0), 1, 0, 0);
    RotateModel(97, SI_VAR(0), 1, 0, 0);
    RotateModel(100, SI_VAR(0), -1, 0, 0);
    RotateModel(101, SI_VAR(0), -1, 0, 0);
});

EvtSource N(dropDoor_8024BBB8) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /= (float) 50;
    TranslateModel(103, 0, SI_VAR(1), 0);
    RotateModel(103, SI_VAR(0), 1, 0, 0);
});

EvtSource N(openDoor_8024BC24) = SCRIPT({
    RotateModel(83, SI_VAR(0), 0, 1, 0);
});

EvtSource N(moveWalls_8024BC54) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /= (float) 50;
    TranslateModel(47, 0, SI_VAR(1), 0);
    TranslateModel(48, 0, SI_VAR(1), 0);
    RotateModel(47, SI_VAR(0), 1, 0, 0);
    RotateModel(48, SI_VAR(0), 1, 0, 0);
    RotateModel(41, SI_VAR(0), -1, 0, 0);
    RotateModel(42, SI_VAR(0), -1, 0, 0);
    RotateModel(43, SI_VAR(0), -1, 0, 0);
    RotateModel(44, SI_VAR(0), -1, 0, 0);
    RotateModel(45, SI_VAR(0), -1, 0, 0);
});

EvtSource N(openDoor_8024BD9C) = SCRIPT({
    RotateModel(157, SI_VAR(0), 0, 1, 0);
});

EvtSource N(dropDoor_8024BDCC) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /= 45;
    TranslateModel(157, 0, SI_VAR(1), 0);
    RotateModel(157, SI_VAR(0), 1, 0, 0);
});

EvtSource N(moveWalls_8024BE38) = SCRIPT({
    if (SI_VAR(0) == 90) {
        EnableModel(142, 0);
    } else {
        EnableModel(142, 1);
    }
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /= 45;
    SI_VAR(2) = SI_VAR(0);
    SI_VAR(2) -= -90;
    SI_VAR(2) /= -90;
    TranslateModel(140, 0, SI_VAR(1), 0);
    RotateModel(140, SI_VAR(0), 1, 0, 0);
    RotateModel(138, SI_VAR(0), -1, 0, 0);
    RotateModel(137, SI_VAR(0), -1, 0, 0);
    RotateModel(136, SI_VAR(0), -1, 0, 0);
    RotateModel(135, SI_VAR(0), -1, 0, 0);
    RotateModel(143, SI_VAR(0), 1, 0, 0);
    RotateModel(142, SI_VAR(0), 1, 0, 0);
});

EvtSource N(toggleVis_8024BFDC) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            SetGroupEnabled(127, 1);
        }
        == 3 {
            SetGroupEnabled(127, 0);
        }
    }
});

EvtSource N(toggleVis_8024C040) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            match SI_STORY_PROGRESS {
                < STORY_CH2_SPOKE_WITH_SHEEK {
                    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x017B), 160, 40);
                    SI_VAR(0) = -1;
                    return;
                }
                < STORY_CH2_SHADY_MOUSE_ENTERED_SHOP {
                    SI_VAR(0) = -1;
                    return;
                }
            }
            SetGroupEnabled(82, 1);
        }
        == 2 {
            spawn {
                sleep 45;
                SetNpcPos(NPC_MOUSER1, 33, 0, -375);
                SetNpcYaw(NPC_MOUSER1, 180);
            }
        }
        == 3 {
            SetGroupEnabled(82, 0);
            SI_AREA_VAR(4) = 0;
            SI_AREA_VAR(5) = 0;
        }
    }
});

EvtSource N(toggleVis_8024C190) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            SetGroupEnabled(156, 1);
        }
        == 2 {}
        == 3 {
            SetGroupEnabled(156, 0);
        }
    }
});

s32 N(npcList_8024C200)[] = {
    0x00000002, 0xFFFFFFFF,
};

s32 N(npcList_8024C208)[] = {
    0x00000006, 0xFFFFFFFF,
};

s32 N(npcList_8024C210)[] = {
    0x00000005, 0xFFFFFFFF,
};

EvtSource N(8024C218) = SCRIPT({
    MakeDoorAdvanced(5, N(openDoor_8024BAA0), N(moveWalls_8024BAD0), N(dropDoor_8024BBB8), N(toggleVis_8024BFDC), 15, 16, 128, N(npcList_8024C200));
    MakeDoorAdvanced(5, N(openDoor_8024BC24), N(moveWalls_8024BC54), 0, N(toggleVis_8024C040), 23, 24, 91, N(npcList_8024C208));
    MakeDoorAdvanced(5, N(openDoor_8024BD9C), N(moveWalls_8024BE38), N(dropDoor_8024BDCC), N(toggleVis_8024C190), 29, 30, 159, N(npcList_8024C210));
    SI_VAR(0) = 3;
    spawn N(toggleVis_8024BFDC);
    spawn N(toggleVis_8024C040);
    spawn N(toggleVis_8024C190);
});

EvtSource N(8024C2EC) = SCRIPT({
9:
    MakeLerp(10, -10, 30, 10);
10:
    UpdateLerp();
    RotateModel(34, SI_VAR(0), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 10;
    }
    MakeLerp(-10, 10, 30, 10);
11:
    UpdateLerp();
    RotateModel(34, SI_VAR(0), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 11;
    }
    goto 9;
});

EvtSource N(8024C41C) = SCRIPT({
    SetGroupEnabled(82, 1);
    PlaySoundAtCollider(23, 449, 0);
    MakeLerp(0, 100, 15, 4);
10:
    UpdateLerp();
    spawn N(openDoor_8024BC24);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 10;
    }
});

EvtSource N(8024C4C8) = SCRIPT({
    MakeLerp(100, 0, 15, 4);
10:
    UpdateLerp();
    spawn N(openDoor_8024BC24);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 10;
    }
    PlaySoundAtCollider(23, 450, 0);
    SetGroupEnabled(82, 0);
});

s32 N(pad_C574)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(8024C580) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    DisablePartnerAI(0);
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_STAND_STILL);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
    }
    GetEntryID(SI_VAR(0));
    N(dup_GetEntryPos)();
    SI_VAR(2) -= 40;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    PlaySound(0x163);
    func_802D286C(256);
    func_802D2520(ANIM_STAND_STILL, 5, 2, 1, 1, 0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    loop 40 {
        SI_VAR(1) += 1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    sleep 3;
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            DisablePartnerAI(0);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetNpcFlagBits(NPC_PARTNER, ((0x00000002)), FALSE);
            EnablePartnerAI();
            EnableNpcShadow(NPC_PARTNER, TRUE);
        }
    }
    sleep 2;
    func_802D2520(ANIM_STAND_STILL, 0, 0, 0, 0, 0);
    sleep 1;
    SetPlayerAnimation(ANIM_10002);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
    HidePlayerShadow(FALSE);
0:
    N(dup_GetCurrentFloor)();
    sleep 1;
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    spawn 0xFE363C8A;
});

EvtSource N(8024C8D4) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    GetEntryID(SI_VAR(0));
    N(dup_GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(2) += 2;
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    InterpPlayerYaw(SI_VAR(4), 0);
    if (SI_VAR(4) == 90) {
        SI_VAR(5) += 40;
    } else {
        SI_VAR(5) -= 40;
    }
    UseSettingsFrom(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetPanTarget(0, SI_VAR(5), SI_VAR(6), SI_VAR(7));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        DisablePartnerAI(0);
        EnableNpcShadow(NPC_PARTNER, FALSE);
        SetNpcPos(NPC_PARTNER, 0, -1000, 0);
        InterpNpcYaw(NPC_PARTNER, SI_VAR(0), 0);
    }
    sleep 1;
    PlaySound(0x163);
    spawn {
        sleep 25;
        HidePlayerShadow(FALSE);
    }
    func_802D286C(2304);
    func_802D2520(ANIM_10002, 5, 3, 1, 1, 0);
    loop 40 {
        N(dup_SomeXYZFunc2)(1.0);
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
    }
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        spawn {
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(2) -= 3;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            EnableNpcShadow(NPC_PARTNER, TRUE);
            EnablePartnerAI();
        }
    }
    sleep 5;
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    ModifyColliderFlags(1, SI_VAR(11), 0x7FFFFE00);
    DisablePlayerInput(FALSE);
    DisablePlayerPhysics(FALSE);
    PanToTarget(0, 0, 0);
    spawn 0xFE363C8A;
});

EvtSource N(8024CCC4) = SCRIPT({
    N(dup_UnkFunc25)();
    if (SI_VAR(0) == 0) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    await N(8024CDA0);
});

EvtSource N(8024CDA0) = SCRIPT({
    N(dup_SetPlayerStatusAnimFlags100000)();
    group 27;
    DisablePlayerPhysics(TRUE);
    HidePlayerShadow(TRUE);
    SI_VAR(0) = SI_VAR(10);
    N(dup_GetEntryPos)();
    PlayerMoveTo(SI_VAR(1), SI_VAR(3), 3);
    SI_VAR(0) = SI_VAR(10);
    N(dup_GetEntryPos)();
    SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SetPlayerFlagBits(2097152, 1);
    N(dup_GetCurrentCameraYawClamped180)();
    InterpPlayerYaw(SI_VAR(0), 0);
    sleep 2;
    SetPlayerFlagBits(2097152, 0);
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        sleep 4;
        loop 40 {
            SI_VAR(1) -= 1;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    func_802D286C(2048);
    func_802D2520(ANIM_10002, 5, 2, 1, 1, 0);
    sleep 25;
    await 0xFE363C8C;
});

EvtSource N(8024CF7C) = SCRIPT({
    IsPlayerOnValidFloor(SI_VAR(0));
    if (SI_VAR(0) == 0) {
        return;
    }
    GetPlayerActionState(SI_VAR(0));
    if (SI_VAR(0) == 26) {
        return;
    }
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        GetCurrentPartnerID(SI_VAR(1));
        if (SI_VAR(1) != 6) {
            return;
        } else {
            func_802D2B6C();
            DisablePlayerInput(TRUE);
        }
    } else {
        DisablePlayerInput(TRUE);
    }
    group 27;
    N(dup_SetPlayerStatusAnimFlags100000)();
    DisablePlayerPhysics(TRUE);
    ModifyColliderFlags(0, SI_VAR(11), 0x7FFFFE00);
    SI_VAR(0) = SI_VAR(10);
    N(dup_GetEntryPos)();
    SI_VAR(5) = SI_VAR(1);
    SI_VAR(6) = SI_VAR(2);
    SI_VAR(6) += 2;
    SI_VAR(7) = SI_VAR(3);
    SI_VAR(8) = SI_VAR(4);
    SI_VAR(8) += 180;
    if (SI_VAR(4) >= 360) {
        SI_VAR(4) -= 360;
    }
    InterpPlayerYaw(SI_VAR(8), 1);
    sleep 1;
    PlaySound(0x163);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPlayerPos(SI_VAR(0), SI_VAR(6), SI_VAR(7));
    SetPlayerAnimation(ANIM_STAND_STILL);
    func_802D286C(2048);
    func_802D2520(ANIM_STAND_STILL, 5, 3, 1, 1, 0);
    spawn {
        sleep 8;
        HidePlayerShadow(TRUE);
    }
    spawn {
        sleep 3;
        loop 40 {
            N(dup_SomeXYZFunc2)(1.0);
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    sleep 25;
    await 0xFE363C8C;
});

const char N(dro_01_name_hack)[];

EvtSource N(8024D2B0) = SCRIPT({
    SI_SAVE_FLAG(761) = 0;
    GotoMap(N(dro_01_name_hack), 4);
    sleep 100;
});

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802E9A18, -211, 60, -50, 30, MAKE_ENTITY_END);
    if (SI_SAVE_FLAG(1939) == 0) {
        if (SI_SAVE_FLAG(1933) == 1) {
            GetEntryID(SI_VAR(0));
            if (SI_VAR(0) != 2) {
                SI_SAVE_FLAG(1939) = 1;
            }
        }
    }
    MakeEntity(0x802EAF80, 430, 0, -120, 0, ITEM_SPIN_JUMP, N(8024D2B0), 1939, MAKE_ENTITY_END);
});

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
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
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

// Ok good luck.
ApiStatus N(func_802415AC_95C7AC)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemyID;
    u16 phi_s0 = get_variable(script, SI_SAVE_FLAG(1768));
    u16 phi_s7 = get_variable(script, SI_SAVE_FLAG(1769));
    u16 temp_s6 = get_variable(script, SI_SAVE_VAR(350));
    u16 phi_s5 = get_variable(script, SI_SAVE_VAR(351));
    s32 var;
    s32 i;

    s32 test2;
    u16 temp_s3 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 sp_10 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 temp_s2 = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 sp_1e = (enemy->varTable[0] & 0xFF) >> 0;
    s32 temp_v0;
    s32 temp_s0_2;

    if (temp_s3 != temp_s6) {
        phi_s7 = 0;
        phi_s0 = 0;
    }

    if (phi_s0 == 0) {
        if (rand_int(100) < 30) {
            phi_s5 = rand_int(temp_s2 - 1);
            temp_s6 = temp_s3;
            set_variable(script, SI_SAVE_VAR(350), temp_s6);
            set_variable(script, SI_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    set_variable(script, SI_SAVE_FLAG(1768), phi_s0);
    set_variable(script, SI_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = get_variable(NULL, SI_SAVE_VAR(352));
    temp_v0 = get_variable(NULL, SI_STORY_PROGRESS);

    for (i = 0; i < 8; i++) {
        if (temp_v0 < (*(N(quizRequirements) + i)).unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < (*(N(quizRequirements) + i)).unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) ||
        ((gGameStatusPtr->debugQuizmo != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc31.inc.c"

ApiStatus N(func_80241B5C_95CD5C)(Evt* script, s32 isInitialCall) {
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 999) {
        gPlayerData.quizzesAnswered++;
    }

    if (script->varTable[0] == N(quizAnswers)[get_variable(NULL, SI_SAVE_VAR(352))]) {
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
        N(D_8024DFE0) = playFX_4E(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)),
                                      get_variable(script, SI_ARRAY(3)));
        N(D_8024DFE4) = playFX_54(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)),
                                      get_variable(script, SI_ARRAY(3)));
        N(D_8024DFE8) = playFX_80(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)),
                                      get_variable(script, SI_ARRAY(3)), 1.0f, 0);

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
    N(D_8024DFE0)->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241EE0_95D0E0)(Evt* script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
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
    s32 var = get_variable(NULL, N(D_8024DFD8));

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
        set_variable(script, *args, N(D_802477E4_9629E4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242784_95D984)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802477E4_9629E4) = get_variable(script, *args);
    N(D_802477E0_9629E0) = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802427BC_95D9BC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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
    Unk_Struct_2* temp_s1 = get_variable(script, *script->ptrReadPos);
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
    f32 var1 = get_variable(script, *args++);
    f32 var2 = get_variable(script, *args++);
    f32 var3 = get_variable(script, *args++);
    f32 var4 = get_variable(script, *args++);
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
