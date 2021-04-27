#include "dro_02.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/archeologist.h"
#include "sprite/npc/chuck_quizmo.h"
#include "sprite/npc/disguised_moustafa.h"
#include "sprite/npc/dryite.h"
#include "sprite/npc/mouser.h"
#include "sprite/npc/moustafa.h"
#include "sprite/npc/toad.h"
#include "sprite/npc/world_merlee.h"
#include "world/area_dro/dro_02/img_1.png.h"

#define UNK_ALPHA_FUNC_NPC 10

extern s16 D_8014C290;
extern s16 D_8014C294;

enum {
    NPC_ARCHEOLOGIST,
    NPC_DRYITE0,
    NPC_DISGUISED_MOUSTAFA,
    NPC_TOAD,
    NPC_WORLD_MERLEE,
    NPC_MOUSTAFA,
    NPC_DRYITE1,
    NPC_MOUSER0,
    NPC_MOUSER1,
    NPC_MOUSER2,
    NPC_CHUCK_QUIZMO,
    NPC_DRYITE2,
};

// BSS

typedef struct {
    s32 flags;
    char unk_04[0x4];
    s32 unk_08;
    EffectInstanceDataThing* unk_0C;
} N(temp);

typedef struct {
    s32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
} D_8024F010_Struct; // size = 0x24

static s8 N(pad_D_8024EF80)[0x4];
static f32 N(D_8024EF84);
static s32 N(D_8024EF88);
static s8 N(pad_D_8024EF8C)[0x4];
static N(temp)* N(D_8024EF90)[4]; // possibly bigger?
static s8 N(pad_D_8024EF94)[0x18];
static s32 N(D_8024EFB8);
static s8 N(pad_D_8024EFBC)[0x4];
static Effect* N(D_8024EFC0);
static Effect* N(D_8024EFC4);
static Effect* N(D_8024EFC8);
static ScriptInstance* N(D_8024EFCC);
static s32 N(D_8024EFD0)[16];
static D_8024F010_Struct N(D_8024F010)[3];
static s8 N(pad_D_8024F07C)[0x4];
static s32 N(D_8024F080)[0x70];
static s8 N(pad_D_8024F244)[0x4]; // likely conencted to the above
static s32 N(D_8024F248)[0x5B];
static s8 N(pad_D_8024F3B4)[0x4]; // likely conencted to the above
static s32 N(D_8024F3B8);

// DATA

EntryList N(entryList) = {
    { -473.0f, 0.0f, 12.0f, 90.0f },
    { 415.0f, 35.0f, -15.0f, 180.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_dro_02_tattle,
};

// *INDENT-OFF*
Script N(80243AF0) = {
    SI_CMD(ScriptOpcode_CALL, GetEntryID, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, SetMusicTrack, 0, 21, 0, 8),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(80243B70) = SCRIPT({
    SetMusicTrack(0, SONG_TAKING_REST, 0, 8);
});

Script N(80243B9C) = SCRIPT({
    SetMusicTrack(0, SONG_MOUSTAFA_THEME, 0, 8);
});

static s32 N(pad_3BC8)[] = {
    0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeItemEntity(ITEM_LETTER08, -135, 160, -245, 17, SI_SAVE_FLAG(757));
    MakeEntity(0x802EAB04, 180, 173, -200, 0, ITEM_STOREROOM_KEY, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(756));
});

static s32 N(pad_3C3C) = {
    0x00000000,
};

Script N(exitWalk_80243C40) = EXIT_WALK_SCRIPT(60,  0, "dro_01",  1);

Script N(80243C9C) = SCRIPT({
    bind N(exitWalk_80243C40) to TRIGGER_FLOOR_ABOVE 4;
});

Script N(80243CC8) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x017C), 160, 40);
    DisablePlayerInput(FALSE);
});

Script N(80243D10) = SCRIPT({
    PlaySound(0x80000060);
    UseSettingsFrom(0, 190, 0, -37);
    SetPanTarget(0, 190, 0, -37);
    SetCamDistance(0, 200.0);
    SetCamPitch(0, 13.0, -10.0);
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
        if (SI_VAR(0) == 2) {
            GotoMap("sbk_02", 6);
        } else {
            GotoMap("sbk_02", 7);
        }
        sleep 100;
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_DRY_DRY_OUTPOST;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    MakeNpcs(0, N(npcGroupList_8024EEF4));
    func_802D3398();
    await N(makeEntities);
    await N(80244C78);
    spawn N(80243AF0);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        2, 3 {
            await N(80243D10);
        }
        else {
            SI_VAR(0) = N(80243C9C);
            spawn EnterWalk;
        }
    }
    sleep 1;
    spawn {
        SetTexPanner(162, 1);
        SI_VAR(0) = 0;
    123:
        SI_VAR(0) += 420;
        if (SI_VAR(0) > 65536) {
            SI_VAR(0) += -65536;
        }
        SetTexPanOffset(1, 0, 0, SI_VAR(0));
        sleep 1;
        goto 123;
    }
    SI_MAP_FLAG(0) = 0;
    bind N(80243CC8) to TRIGGER_WALL_PRESS_A 56;
    spawn {
        loop {
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            if (SI_VAR(2) < -200) {
                EnableGroup(163, 1);
            } else {
                EnableGroup(163, 0);
            }
            sleep 1;
        }
    }
    SetCamSpeed(0, 1.333984375);
});

static s32 N(pad_41B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(802441C0) = SCRIPT({
9:
    MakeLerp(10, -10, 30, 10);
10:
    UpdateLerp();
    RotateModel(48, SI_VAR(0), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 10;
    }
    MakeLerp(-10, 10, 30, 10);
11:
    UpdateLerp();
    RotateModel(48, SI_VAR(0), 1, 0, 0);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 11;
    }
    goto 9;
});

Script N(802442F0) = SCRIPT({
    SI_VAR(0) /= 2;
    SI_VAR(0) += 18;
    RotateModel(21, SI_VAR(0), 0, 1, 0);
});

Script N(openDoor_80244340) = SCRIPT({
    RotateModel(108, SI_VAR(0), 0, -1, 0);
    RotateModel(110, SI_VAR(0), 0, 1, 0);
});

Script N(moveWalls_80244390) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /=f 50;
    TranslateModel(104, 0, SI_VAR(1), 0);
    TranslateModel(105, 0, SI_VAR(1), 0);
    TranslateModel(106, 0, SI_VAR(1), 0);
    RotateModel(104, SI_VAR(0), 1, 0, 0);
    RotateModel(105, SI_VAR(0), 1, 0, 0);
    RotateModel(106, SI_VAR(0), 1, 0, 0);
});

Script N(dropDoor_80244474) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /=f 50;
    TranslateModel(108, 0, SI_VAR(1), 0);
    TranslateModel(110, 0, SI_VAR(1), 0);
    RotateModel(108, SI_VAR(0), 1, 0, 0);
    RotateModel(110, SI_VAR(0), 1, 0, 0);
});

Script N(openDoor_8024451C) = SCRIPT({
    RotateModel(62, SI_VAR(0), 0, 1, 0);
});

Script N(moveWalls_8024454C) = SCRIPT({
    SI_VAR(1) = SI_VAR(0);
    SI_VAR(1) /=f 50;
    RotateGroup(61, SI_VAR(0), 0, 0, -1);
});

Script N(8024459C) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            SetCamSpeed(0, 3.0);
        }
        == 3 {
            SetCamSpeed(0, 1.333984375);
        }
    }
});

Script N(toggleVis_80244600) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            SetGroupEnabled(87, 1);
            SetCamSpeed(0, 3.0);
        }
        == 3 {
            SetGroupEnabled(87, 0);
            SetCamSpeed(0, 1.333984375);
        }
    }
});

Script N(toggleVis_8024468C) = SCRIPT({
    match SI_VAR(0) {
        == 0 {
            SetGroupEnabled(132, 1);
            SetCamType(0, 0, 0);
            SetCamDistance(0, 260);
            SetCamPitch(0, 22, -13);
            SetCamPosA(0, 0, 290);
            SetCamPosB(0, 0, -290);
            SetCamPosC(0, 0, 0);
            SetPanTarget(0, -395, 140, -150);
            SetCamSpeed(0, 4.0);
            PanToTarget(0, 0, 1);
        }
        == 2 {
            SetPanTarget(0, -365, 140, -145);
            SetCamPitch(0, 20, -7);
            SetCamDistance(0, 400);
            SetCamSpeed(0, 4.0);
            WaitForCam(0, 1.0);
        }
        == 3 {
            SetGroupEnabled(132, 0);
            PanToTarget(0, 0, 0);
            SetCamSpeed(0, 1.333984375);
        }
    }
});

Script N(8024486C) = SCRIPT({
    group 0;
    DisablePlayerInput(TRUE);
    func_802D2C14(1);
    PlayerMoveTo(230, 10, 20);
    ModifyColliderFlags(0, 8, 0x7FFFFE00);
    PlaySoundAtCollider(8, 449, 0);
    MakeLerp(18, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(21, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlayerMoveTo(230, -70, 15);
    MakeLerp(80, 18, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(21, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlaySoundAtCollider(8, 450, 0);
    ModifyColliderFlags(1, 8, 0x7FFFFE00);
    func_802D2C14(0);
    DisablePlayerInput(FALSE);
});

Script N(80244A68) = SCRIPT({
    group 0;
    DisablePlayerInput(TRUE);
    func_802D2C14(1);
    PlayerMoveTo(230, -70, 20);
    ModifyColliderFlags(0, 10, 0x7FFFFE00);
    PlaySoundAtCollider(10, 449, 0);
    MakeLerp(18, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(21, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlayerMoveTo(230, 10, 15);
    MakeLerp(80, 18, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(21, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    PlaySoundAtCollider(10, 450, 0);
    ModifyColliderFlags(1, 10, 0x7FFFFE00);
    func_802D2C14(0);
    DisablePlayerInput(FALSE);
});

s32 N(npcList_80244C64)[] = {
    0x00000002, 0x00000005, 0xFFFFFFFF,
};

s32 N(npcList_80244C70)[] = {
    0x00000003, 0xFFFFFFFF,
};

Script N(80244C78) = SCRIPT({
    spawn N(802441C0);
    ParentColliderToModel(8, 21);
    if (STORY_PROGRESS >= STORY_CH2_BOUGHT_SECRET_ITEMS) {
        RotateModel(21, 18, 0, 1, 0);
        UpdateColliderTransform(8);
    }
    MakeDoorAdvanced(4, N(openDoor_80244340), N(moveWalls_80244390), N(dropDoor_80244474), N(toggleVis_8024468C), 15, 16, 133, N(npcList_80244C64));
    if (STORY_PROGRESS >= STORY_CH2_BOUGHT_SECRET_ITEMS) {
        bind N(8024486C) to TRIGGER_WALL_PRESS_A 8;
        bind N(80244A68) to TRIGGER_WALL_PRESS_A 10;
    }
    MakeDoorAdvanced(4101, N(openDoor_8024451C), N(moveWalls_8024454C), 0, N(toggleVis_80244600), 12, 13, 94, N(npcList_80244C70));
    SI_VAR(0) = 3;
    spawn N(toggleVis_8024468C);
    spawn N(8024459C);
    spawn N(toggleVis_80244600);
});

static s32 N(pad_4DD4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32** N(D_80244DE0_96DFA0) = NULL;

Script N(80244DE4) = SCRIPT({
    ShowGotItem(SI_VAR(0), 1, 0);
    return;
});

Script N(80244E14) = SCRIPT({
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

Script N(80244ED4) = SCRIPT({
    N(GetGameStatus75)();
    if (SI_VAR(0) <= 1) {
        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 300;
        SetNpcJumpscale(NPC_SELF, 1);
        SetNpcAnimation(NPC_SELF, 0xAF000C);
        sleep 40;
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

Script N(80244F84) = SCRIPT({
    N(GetCamVfov)(0, SI_ARRAY(0));
    N(SetCamVfov)(0, 25);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetCamType(0, SI_VAR(1), SI_VAR(2));
    SetCamType(0, SI_VAR(1), 0);
    GetCamDistance(0, SI_VAR(0));
    if (SI_VAR(0) > 0) {
        SI_VAR(0) =f 370;
    } else {
        SI_VAR(0) =f -370;
    }
    SetCamDistance(0, SI_VAR(0));
    GetCamPitch(0, SI_VAR(0), SI_VAR(1));
    SI_VAR(0) =f 13.0;
    SI_VAR(1) =f -10.0;
    SetCamPitch(0, SI_VAR(0), SI_VAR(1));
    PanToTarget(0, 0, 1);
    SetCamLeadPlayer(0, 0);
});

Script N(80245120) = SCRIPT({
    GetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 30;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetCamDistance(0, SI_VAR(0));
    if (SI_VAR(0) > 0) {
        SI_VAR(0) =f 17;
    } else {
        SI_VAR(0) =f -17;
    }
    SetCamDistance(0, SI_VAR(0));
    SetCamSpeed(0, 90.0);
    WaitForCam(0, 1.0);
    SetCamSpeed(0, 1);
});

Script N(8024521C) = SCRIPT({
    N(SetCamVfov)(0, SI_ARRAY(0));
    PanToTarget(0, 0, 0);
});

Script N(80245258) = SCRIPT({
    sleep 20;
    N(UnkCameraFunc)(SI_ARRAY(1), SI_ARRAY(3), 83, SI_VAR(0), SI_VAR(1));
    spawn {
        SI_VAR(2) =f 0;
        loop 60 {
            SI_VAR(3) =f SI_VAR(0);
            SI_VAR(4) =f SI_VAR(1);
            SI_VAR(3) *=f SI_VAR(2);
            SI_VAR(4) *=f SI_VAR(2);
            SI_VAR(3) /=f 60;
            SI_VAR(4) /=f 60;
            SI_VAR(3) +=f SI_ARRAY(1);
            SI_VAR(4) +=f SI_ARRAY(3);
            SetPlayerPos(SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
            SI_VAR(2) +=f 1;
            sleep 1;
        }
        SI_VAR(3) =f SI_VAR(0);
        SI_VAR(4) =f SI_VAR(1);
        SI_VAR(3) +=f SI_ARRAY(1);
        SI_VAR(4) +=f SI_ARRAY(3);
        SetPlayerPos(SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
    }
    N(UnkRotatePlayer)();
    func_802D2884(SI_ARRAY(1), SI_ARRAY(3), 0);
    SetPlayerAnimation(ANIM_10002);
});

Script N(80245408) = SCRIPT({
    GetNpcPos(NPC_PARTNER, SI_VAR(10), SI_VAR(11), SI_VAR(12));
    N(UnkCameraFunc)(SI_VAR(10), SI_VAR(12), 108, SI_VAR(0), SI_VAR(1));
    SI_VAR(5) =f SI_ARRAY(2);
    SI_VAR(5) -=f SI_VAR(11);
    spawn {
        N(UnkMovePartner)();
        SI_VAR(3) =f SI_VAR(0);
        SI_VAR(4) =f SI_VAR(1);
        SI_VAR(6) =f SI_VAR(5);
        SI_VAR(3) +=f SI_VAR(10);
        SI_VAR(4) +=f SI_VAR(12);
        SI_VAR(6) +=f SI_VAR(11);
        SetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(6), SI_VAR(4));
    }
    N(UnkRotatePartner)();
    NpcFacePlayer(NPC_PARTNER, 0);
    SetNpcAnimation(NPC_PARTNER, 0x106);
});

Script N(80245540) = SCRIPT({
    GetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(10), SI_VAR(11), SI_VAR(12));
    N(UnkCameraFunc)(SI_VAR(10), SI_VAR(12), -70, SI_VAR(0), SI_VAR(1));
    spawn {
        SI_VAR(2) =f 0;
        loop 60 {
            SI_VAR(3) =f SI_VAR(0);
            SI_VAR(4) =f SI_VAR(1);
            SI_VAR(3) *=f SI_VAR(2);
            SI_VAR(4) *=f SI_VAR(2);
            SI_VAR(3) /=f 60;
            SI_VAR(4) /=f 60;
            SI_VAR(3) +=f SI_VAR(10);
            SI_VAR(4) +=f SI_VAR(12);
            SetNpcPos(NPC_CHUCK_QUIZMO, SI_VAR(3), SI_ARRAY(2), SI_VAR(4));
            SI_VAR(2) +=f 1;
            sleep 1;
        }
    }
    sleep 60;
    NpcFacePlayer(NPC_CHUCK_QUIZMO, 0);
    SetNpcAnimation(NPC_CHUCK_QUIZMO, 0xAF0001);
});

Script N(802456AC) = SCRIPT({
    spawn N(80245258);
    spawn N(80245408);
    await N(80245540);
});

Script N(802456E0) = SCRIPT({
    loop {
        SetPlayerAnimation(ANIM_QUESTION);
        sleep 20;
    }
});

Script N(80245720) = SCRIPT({
    SetPlayerAnimation(ANIM_THROW);
    sleep 15;
    SetPlayerAnimation(ANIM_10002);
});

Script N(8024575C) = SCRIPT({
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

Script N(802462A4) = SCRIPT({
    SetPlayerAnimation(ANIM_SHOCK_STILL);
    loop {
        sleep 1;
    }
});

Script N(802462E4) = SCRIPT({
    spawn {
        N(UnkCameraFunc)(SI_ARRAY(1), SI_ARRAY(3), 25, SI_VAR(0), SI_VAR(1));
        SI_VAR(2) =f SI_ARRAY(1);
        SI_VAR(2) +=f SI_VAR(0);
        SI_VAR(3) =f SI_ARRAY(3);
        SI_VAR(3) +=f SI_VAR(1);
        SetNpcAnimation(NPC_PARTNER, 0x102);
        NpcMoveTo(NPC_PARTNER, SI_VAR(2), SI_VAR(3), 40);
        SetNpcAnimation(NPC_PARTNER, 0x106);
    }
    PlayerMoveTo(SI_ARRAY(1), SI_ARRAY(3), 40);
});

Script N(802463C0) = SCRIPT({
    SI_VAR(1) = spawn N(8024575C);
    sleep 60;
    kill SI_VAR(1);
    loop 5 {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 2;
    }
    sleep 20;
    await N(802462E4);
});

Script N(80246470) = SCRIPT({
    SI_VAR(1) = spawn N(802462A4);
    sleep 60;
    loop 5 {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += -1;
        SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 2;
    }
    sleep 20;
    kill SI_VAR(1);
    await N(802462E4);
});

// *INDENT-OFF*
Script N(80246520) = {
    SI_CMD(ScriptOpcode_IF_GT, SI_SAVE_VAR(352), 63),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_ARRAY(1), SI_ARRAY(2), SI_ARRAY(3)),
    SI_CMD(ScriptOpcode_CALL, NpcFacePlayer, -1, 16),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(352), 63),
        SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468804, 11468801, 0, 524298),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1767), 1),
            SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468804, 11468801, 0, 524297),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468804, 11468801, 0, 524296),
            SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(1767), 1),
        SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, ShowChoice, 1966093),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 1),
        SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 11468804, 11468801, 0, 524300),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80244ED4)),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(1793), 1),
    SI_CMD(ScriptOpcode_CALL, N(Set80151310_1)),
    SI_CMD(ScriptOpcode_CALL, N(UnkAlphaFunc)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80244F84)),
    SI_CMD(ScriptOpcode_CALL, DisablePartnerAI, 0),
    SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, -4, 512, 0),
    SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 10, 512, 0),
    SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, -4, 328, 1),
    SI_CMD(ScriptOpcode_CALL, SetNpcFlagBits, 10, 256, 1),
    SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, -4, 262),
    SI_CMD(ScriptOpcode_SPAWN_GET_ID, N(802456AC), SI_VAR(1)),
    SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 11468804, 11468801, 0, 524299),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 137),
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_SCRIPT_EXISTS, SI_VAR(1), SI_VAR(0)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
            SI_CMD(ScriptOpcode_BREAK_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_CALL, N(func_80240A70_969C30)),
    SI_CMD(ScriptOpcode_LOOP, 5),
        SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_ADD, SI_VAR(1), 1),
        SI_CMD(ScriptOpcode_CALL, SetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), 2883584),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), SI_SAVE_VAR(352)),
    SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468805, 11468806, 0, SI_VAR(0)),
    SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65576),
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), 2949120),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), SI_SAVE_VAR(352)),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 142),
    SI_CMD(ScriptOpcode_CALL, ShowChoice, SI_VAR(0)),
    SI_CMD(ScriptOpcode_KILL_SCRIPT, SI_VAR(1)),
    SI_CMD(ScriptOpcode_CALL, StopSound, 142),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80245720)),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
    SI_CMD(ScriptOpcode_CALL, PlaySound, 141),
    SI_CMD(ScriptOpcode_CALL, N(func_80240D70_969F30), SI_VAR(0)),
    SI_CMD(ScriptOpcode_SET, SI_ARRAY(4), 0),
    SI_CMD(ScriptOpcode_CALL, N(func_80241364_96A524)),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 40),
    SI_CMD(ScriptOpcode_CALL, N(func_802409EC_969BAC)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 110),
        SI_CMD(ScriptOpcode_CALL, CloseChoice),
        SI_CMD(ScriptOpcode_SET, SI_ARRAY(4), 0),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 1),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468807),
        SI_CMD(ScriptOpcode_SET, SI_ARRAY(4), 1),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, N(func_80240D3C_969EFC), 1),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_CALL, N(func_80240D3C_969EFC), 2),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, PlaySound, 540),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_CALL, PlaySound, 540),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_CALL, PlaySound, 540),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
            SI_CMD(ScriptOpcode_CALL, PlaySound, 540),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 138),
        SI_CMD(ScriptOpcode_CALL, N(func_80240E08_969FC8)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
            SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(0), SI_VAR(1), SI_VAR(2)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(1), 50),
            SI_CMD(ScriptOpcode_CALL, N(UnkCameraFunc), 0, 0, 83, SI_VAR(0), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 68, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(1), -3),
            SI_CMD(ScriptOpcode_CALL, N(UnkCameraFunc), 0, 0, 58, SI_VAR(0), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 68, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(1), 30),
            SI_CMD(ScriptOpcode_CALL, N(UnkCameraFunc), 0, 0, 93, SI_VAR(0), SI_VAR(2)),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 7, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_CALL, PlayEffect, 68, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_SPAWN_GET_ID, N(802463C0), SI_VAR(1)),
        SI_CMD(ScriptOpcode_ADD, SI_SAVE_VAR(352), 1),
        SI_CMD(ScriptOpcode_IF_GT, SI_SAVE_VAR(352), 63),
            SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, -1, -1, 0, 524304),
            SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468806),
            SI_CMD(ScriptOpcode_LOOP, 0),
                SI_CMD(ScriptOpcode_SCRIPT_EXISTS, SI_VAR(1), SI_VAR(0)),
                SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
                    SI_CMD(ScriptOpcode_BREAK_LOOP),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468805),
            SI_CMD(ScriptOpcode_SET, SI_VAR(0), 348),
            SI_CMD(ScriptOpcode_SET, SI_VAR(1), 3),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80244DE4)),
            SI_CMD(ScriptOpcode_CALL, AddStarPieces, 1),
            SI_CMD(ScriptOpcode_CALL, N(func_80240D3C_969EFC), 15),
            SI_CMD(ScriptOpcode_CALL, N(func_80240DF0_969FB0)),
            SI_CMD(ScriptOpcode_CALL, SetMessageValue, SI_SAVE_VAR(352), 0),
            SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468804, 11468801, 0, 524305),
        SI_CMD(ScriptOpcode_ELSE),
            SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, -1, -1, 0, 524302),
            SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468806),
            SI_CMD(ScriptOpcode_LOOP, 0),
                SI_CMD(ScriptOpcode_SCRIPT_EXISTS, SI_VAR(1), SI_VAR(0)),
                SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
                    SI_CMD(ScriptOpcode_BREAK_LOOP),
                SI_CMD(ScriptOpcode_END_IF),
                SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_END_LOOP),
            SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468805),
            SI_CMD(ScriptOpcode_SET, SI_VAR(0), 348),
            SI_CMD(ScriptOpcode_SET, SI_VAR(1), 1),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80244DE4)),
            SI_CMD(ScriptOpcode_CALL, AddStarPieces, 1),
            SI_CMD(ScriptOpcode_CALL, N(func_80240D3C_969EFC), 15),
            SI_CMD(ScriptOpcode_CALL, N(func_80240DF0_969FB0)),
            SI_CMD(ScriptOpcode_CALL, SetMessageValue, SI_SAVE_VAR(352), 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(352), 1),
                SI_CMD(ScriptOpcode_CALL, SetMessageString, &D_8014C294, 1),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_CALL, SetMessageString, &D_8014C290, 1),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 11468804, 11468801, 0, 524303),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 1),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468809),
        SI_CMD(ScriptOpcode_SET, SI_ARRAY(4), 2),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 541),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 139),
        SI_CMD(ScriptOpcode_SPAWN_GET_ID, N(80246470), SI_VAR(1)),
        SI_CMD(ScriptOpcode_CALL, GetPlayerPos, SI_VAR(2), SI_VAR(3), SI_VAR(4)),
        SI_CMD(ScriptOpcode_CALL, PlayEffect, 43, 0, SI_VAR(2), SI_VAR(3), SI_VAR(4), 0, 0, 0, 0, 0, 0, 0, 0, 0),
        SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, -1, -1, 0, 524301),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 10, 11468810),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_SCRIPT_EXISTS, SI_VAR(1), SI_VAR(0)),
            SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 0),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, N(func_80240D70_969F30), -1),
    SI_CMD(ScriptOpcode_CALL, EnablePartnerAI),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 143),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 45),
        SI_CMD(ScriptOpcode_CALL, StopSound, 137),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, N(func_80240E24_969FE4)),
    SI_CMD(ScriptOpcode_CALL, N(func_80240C88_969E48)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80244ED4)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(8024521C)),
    SI_CMD(ScriptOpcode_CALL, N(UnkFunc29)),
    SI_CMD(ScriptOpcode_CALL, N(Set80151310_0)),
    SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(1793), 0),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(80247250) = SCRIPT({
    N(func_8024043C_9695FC)();
    if (SI_VAR(0) == 0) {
        return;
    }
    SetNpcFlagBits(NPC_SELF, ((0x01000000)), FALSE);
    SetNpcSprite(-1, 0x00AF0001);
    N(UnkFunc31)();
});

Script N(802472C4) = {
    SI_CMD(ScriptOpcode_USE_ARRAY, &gPauseMenuTargetPosX),
    SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(1769), 1),
    SI_CMD(ScriptOpcode_CALL, DisablePlayerPhysics, 1),
    SI_CMD(ScriptOpcode_CALL, SetPlayerFlagBits, 4194304, 1),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80246520)),
    SI_CMD(ScriptOpcode_CALL, DisablePlayerPhysics, 0),
    SI_CMD(ScriptOpcode_CALL, SetPlayerFlagBits, 4194304, 0),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(80247344) = SCRIPT({
    N(GetNpcUnsafeOwner2)();
});

NpcAISettings N(npcAISettings_80247360) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .unk_14 = -1,
    .unk_2C = 1,
};

Script N(80247390) = SCRIPT({
    DoBasicAI(N(npcAISettings_80247360));
});

NpcSettings N(npcSettings_802473B0) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(80247250),
    .onInteract = &N(802472C4),
    .aux = &N(80247344),
    .flags = 0x00000D01,
    .level = 99,
};

NpcSettings N(npcSettings_802473DC) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(80247250),
    .onInteract = &N(802472C4),
    .ai = &N(80247390),
    .aux = &N(80247344),
    .flags = 0x00000C01,
    .level = 99,
    .unk_2A = 0x10,
};

NpcAISettings N(npcAISettings_80247408) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .unk_14 = -1,
    .unk_2C = 1,
};

Script N(npcAI_80247438) = SCRIPT({
    DoBasicAI(N(npcAISettings_80247408));
});

NpcSettings N(npcSettings_80247458) = {
    .height = 35,
    .radius = 24,
    .ai = &N(npcAI_80247438),
    .level = 99,
    .unk_2A = 0x10,
};

NpcSettings N(npcSettings_80247484) = {
    .height = 42,
    .radius = 24,
    .ai = &N(npcAI_80247438),
    .level = 99,
};

NpcAISettings N(npcAISettings_802474B0) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .unk_14 = -1,
    .unk_2C = 1,
};

Script N(npcAI_802474E0) = SCRIPT({
    DoBasicAI(N(npcAISettings_802474B0));
});

NpcSettings N(npcSettings_80247500) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_802474E0),
    .level = 99,
    .unk_2A = 16,
};

NpcSettings N(npcSettings_8024752C) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

NpcSettings N(npcSettings_80247558) = {
    .height = 22,
    .radius = 25,
    .level = 99,
};

NpcSettings N(npcSettings_80247584) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_802475B0) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

s8 N(D_802475DC_97079C)[] = {
    0x14, 0x0A, 0x05, 0x00,
};

s8 N(D_802475E0_9707A0)[] = {
    0x32, 0x14, 0x05, 0x00,
};

s32 N(pad_XX111)[] = { 0 };

// 32x32 Ci4
s32 N(image1)[] = {
    0x66000000, 0x00000000, 0x00000000, 0x00000000, 0x60000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000333, 0x33333333, 0x33333333, 0x33333333,
    0x00000333, 0x33333333, 0x33333333, 0x33333333, 0x00000334, 0x44442024, 0x44444444, 0x20244444,
    0x00000334, 0x41120202, 0x11444112, 0x02021144, 0x00000334, 0x11202120, 0x21141120, 0x21202114,
    0x00000334, 0x12021112, 0x02141202, 0x11120214, 0x00000334, 0x20211511, 0x20242021, 0x15112024,
    0x00000332, 0x02115551, 0x12020211, 0x55511202, 0x00000330, 0x21155555, 0x11202115, 0x55551120,
    0x00000332, 0x02115551, 0x12020211, 0x55511202, 0x00000334, 0x20211511, 0x20212021, 0x15112021,
    0x00000334, 0x12021112, 0x02111202, 0x11120211, 0x00000334, 0x11202120, 0x21131120, 0x21202113,
    0x00000334, 0x41120202, 0x11333112, 0x02021133, 0x00000334, 0x44442021, 0x13333311, 0x20211333,
    0x00000334, 0x44442021, 0x13333311, 0x20211333, 0x00000334, 0x44442021, 0x13333311, 0x20211333,
    0x00000334, 0x41120202, 0x11333112, 0x02021133, 0x00000334, 0x11202120, 0x21131120, 0x21202113,
    0x00000334, 0x12021112, 0x02111202, 0x11120211, 0x00000334, 0x20211511, 0x20212021, 0x12112021,
    0x00000332, 0x02115551, 0x12020211, 0x22211202, 0x00000330, 0x21155555, 0x11202112, 0x22221120,
    0x00000332, 0x02115551, 0x12020211, 0x22211202, 0x00000334, 0x20211511, 0x20212021, 0x12112021,
    0x00000334, 0x12021112, 0x02111202, 0x11120211, 0x00000334, 0x11202120, 0x21131120, 0x21202113,
    0x00000334, 0x41120202, 0x11333112, 0x02021133, 0x00000334, 0x44442021, 0x13333311, 0x20211333,
};

// Above palette
s32 N(image1_pal)[] = {
    0xEF7BB18D, 0xCCABCD4F, 0x998DC30F, 0xEF7BEDF2, 0x0D2F0000, 0x00000000, 0x00000000, 0x00000000,
};


Vtx N(D_80247808_9709C8)[] = {
    VTX(-24, 2, 0, 0, 60, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-22, 0, 0, 85, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 0, 0, 1963, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 2, 0, 2048, 60, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 66, 0, 2048, 1988, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 68, 0, 1963, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-22, 68, 0, 85, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 66, 0, 0, 1988, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx N(D_80247888_970A48)[] = {
    VTX(-30, 68, -2, 0, -160, 0x00, 0x00, 0x00, 0x00),
    VTX(30, 68, -2, 1920, -160, 0x00, 0x00, 0x00, 0x00),
    VTX(-30, 0, -2, 0, 2016, 0x00, 0x00, 0x00, 0x00),
    VTX(30, 0, -2, 1920, 2016, 0x00, 0x00, 0x00, 0x00),
};

extern void* world_area_dro_dro_02_img_1_pal_png;
extern void* world_area_dro_dro_02_img_1_png;

Gfx N(D_802478C8_970A88)[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPLoadTLUT_pal16(0, N(image1_pal)),
    gsDPLoadTextureTile_4b(N(image1), G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPEndDisplayList(),
};

Gfx N(D_802479B8_970B78)[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(N(D_80247808_9709C8), 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 6, 7, 0),
    gsDPPipeSync(),
    gsDPSetCombineLERP(0, 0, 0, 1, 0, 0, 0, TEXEL0, 0, 0, 0, 1, 0, 0, 0, TEXEL0),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPSetGeometryMode(G_CULL_FRONT),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx N(D_80247A38_970BF8)[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BOTH),
    gsSPSetGeometryMode(G_CULL_FRONT),
    gsSPVertex(N(D_80247888_970A48), 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Script N(init_80247A80) = SCRIPT({

});

Script N(npcAI_80247A90) = SCRIPT({

});

// *INDENT-OFF*
Script N(80247AA0) = {
    SI_CMD(ScriptOpcode_USE_ARRAY, N(D_8024EFD0)),
    SI_CMD(ScriptOpcode_SET, SI_ARRAY(9), 0),
    SI_CMD(ScriptOpcode_CALL, GetNpcPos, 4, SI_ARRAY(4), SI_ARRAY(5), SI_ARRAY(6)),
    SI_CMD(ScriptOpcode_ADD, SI_ARRAY(4), 60),
    SI_CMD(ScriptOpcode_ADD, SI_ARRAY(6), 0),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 4, 513, 0),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, MakeLerp, 720, 0, 60, 0),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_CALL, UpdateLerp),
            SI_CMD(ScriptOpcode_CALL, SetNpcRotation, 4, 0, SI_VAR(0), 0),
            SI_CMD(ScriptOpcode_IF_GT, SI_VAR(0), 360),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), -360),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
                SI_CMD(ScriptOpcode_CASE_RANGE, 90, 270),
                    SI_CMD(ScriptOpcode_SET, SI_VAR(2), 12189697),
                SI_CMD(ScriptOpcode_CASE_ELSE),
                    SI_CMD(ScriptOpcode_SET, SI_VAR(2), 12189698),
            SI_CMD(ScriptOpcode_END_MATCH),
            SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, SI_VAR(2)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
            SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(1), 0),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_CALL, SetNpcRotation, 4, 0, 0, 0),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 12189706),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 200),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 12189705),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 40),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 12189706),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 75),
        SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 12189707),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 60),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtNpc, 4, 514, 0),
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), SI_ARRAY(5)),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 25),
    SI_CMD(ScriptOpcode_CALL, PlayEffect, 79, 0, SI_ARRAY(4), SI_VAR(0), SI_ARRAY(6), 1, -1, 0, 0, 0, 0, 0, 0, 0),
    SI_CMD(ScriptOpcode_SET, SI_ARRAY(8), SI_VAR(15)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 30),
        SI_CMD(ScriptOpcode_CALL, func_802D7B10, SI_ARRAY(8)),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, N(func_802414C0_96A680)),
    SI_CMD(ScriptOpcode_CALL, DisablePlayerPhysics, 1),
    SI_CMD(ScriptOpcode_CALL, InterpPlayerYaw, 0, 0),
    SI_CMD(ScriptOpcode_CALL, N(func_802416FC_96A8BC)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_ARRAY(9), 2),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 10),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 9),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 6),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, -1342177251),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_IF_GE, SI_ARRAY(9), 3),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 9),
        SI_CMD(ScriptOpcode_CALL, N(func_8024303C_96C1FC)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 2),
        SI_CMD(ScriptOpcode_CALL, N(func_80243068_96C228)),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_IF_GE, SI_ARRAY(9), 10),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 3),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 516),
        SI_CMD(ScriptOpcode_LOOP, 0),
            SI_CMD(ScriptOpcode_IF_GE, SI_ARRAY(9), 11),
                SI_CMD(ScriptOpcode_BREAK_LOOP),
            SI_CMD(ScriptOpcode_END_IF),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
        SI_CMD(ScriptOpcode_CALL, PlaySound, 517),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_IF_EQ, SI_ARRAY(9), 13),
            SI_CMD(ScriptOpcode_BREAK_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_CALL, SetPlayerPos, SI_ARRAY(4), SI_ARRAY(5), SI_ARRAY(6)),
    SI_CMD(ScriptOpcode_CALL, SetPlayerAnimation, 65567),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, SetPlayerPos, SI_ARRAY(4), SI_ARRAY(5), SI_ARRAY(6)),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, DisablePlayerPhysics, 0),
    SI_CMD(ScriptOpcode_CALL, N(func_80241874_96AA34)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, N(func_802415CC_96A78C)),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(802481D8) = SCRIPT({
    GetNpcPos(NPC_WORLD_MERLEE, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 200);
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 8.0);
    SetCamPitch(0, 20, -15);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
});

Script N(802482A8) = SCRIPT({
    PanToTarget(0, 0, 0);
    SetCamSpeed(0, 3.0);
    WaitForCam(0, 1.0);
});

// *INDENT-OFF*
Script N(802482F8) = {
    SI_CMD(ScriptOpcode_CALL, func_802D2C14, 1),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802481D8)),
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_VAR(348), 8),
        SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(536), 1),
        SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(759), 0),
        SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 3),
        SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 12189703, 12189700, 0, 852188),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 39),
        SI_CMD(ScriptOpcode_SET, SI_VAR(1), 1),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80244DE4)),
        SI_CMD(ScriptOpcode_CALL, AddKeyItem, 39),
        SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(759), 1),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_CALL, func_802D2C14, 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802482A8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 12189703, 12189700, 0, 852182),
    SI_CMD(ScriptOpcode_CALL, ShowChoice, 1966097),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 12189703, 12189700, 0, 852183),
        SI_CMD(ScriptOpcode_CALL, func_802D2C14, 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802482A8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 12189703, 12189700, 0, 852184),
    SI_CMD(ScriptOpcode_CALL, ShowCoinCounter, 1),
    SI_CMD(ScriptOpcode_CALL, ShowChoice, 1966104),
    SI_CMD(ScriptOpcode_CALL, ShowCoinCounter, 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 3),
        SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 12189703, 12189700, 0, 852183),
        SI_CMD(ScriptOpcode_CALL, func_802D2C14, 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802482A8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, N(func_80241394_96A554), SI_VAR(0), SI_VAR(1)),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(1), 0),
        SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 12189703, 12189700, 0, 852185),
        SI_CMD(ScriptOpcode_CALL, func_802D2C14, 0),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802482A8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_CALL, ContinueSpeech, -1, 12189703, 12189700, 0, 852186),
    SI_CMD(ScriptOpcode_CALL, SetMusicTrack, 0, 124, 0, 8),
    SI_CMD(ScriptOpcode_CALL, DisablePartnerAI, 0),
    SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, -4, 262),
    SI_CMD(ScriptOpcode_SPAWN_GET_ID, N(80247AA0), SI_VAR(9)),
    SI_CMD(ScriptOpcode_LOOP, 0),
        SI_CMD(ScriptOpcode_SCRIPT_EXISTS, SI_VAR(9), SI_VAR(1)),
        SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(1), 0),
            SI_CMD(ScriptOpcode_BREAK_LOOP),
        SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 60),
    SI_CMD(ScriptOpcode_CALL, SetNpcAnimation, 4, 12189700),
    SI_CMD(ScriptOpcode_CALL, PlayerMoveTo, -100, -370, 8),
    SI_CMD(ScriptOpcode_CALL, SpeakToPlayer, -1, 12189703, 12189700, 0, 852187),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(80243AF0)),
    SI_CMD(ScriptOpcode_CALL, EnablePartnerAI),
    SI_CMD(ScriptOpcode_CALL, func_802D2C14, 0),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(802482A8)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

NpcSettings N(npcSettings_80248754) = {
    .height = 32,
    .radius = 32,
    .otherAI = &N(init_80247A80),
    .onInteract = &N(802482F8),
    .ai = &N(npcAI_80247A90),
    .level = 99,
};

s32 N(D_80248780_971940) = {
    0x00000000,
};

s32 N(D_80248784_971944) = {
    0x00000000,
};

Script N(80248788) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    func_802D6420();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(AddPlayerHandsOffset)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            SI_VAR(0) |=c 0x50000;
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80243314_96C4D4)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(802488CC) = {
    SI_CMD(ScriptOpcode_CALL, N(func_8024334C_96C50C), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80248788), 0x10, 0, N(D_8024F080), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_802432C0_96C480), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(8024891C) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    func_802D663C();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(AddPlayerHandsOffset)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80243314_96C4D4)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(80248A50) = {
    SI_CMD(ScriptOpcode_CALL, N(func_802433E8_96C5A8), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(8024891C), 0x10, 0, N(D_8024F248), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_802432C0_96C480), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Gfx N(D_8024A3B8_973578)[];
s32 N(D_80248DD8_971F98)[];

s32 N(D_80248AA0_971C60)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x02EE0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248ACC_971C8C)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248AA0_971C60), 0x00000000,
    0x02BC0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248AF8_971CB8)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248ACC_971C8C), 0x00000000,
    0x028A0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248B24_971CE4)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248AF8_971CB8), 0x00000000,
    0x02580000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248B50_971D10)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248B24_971CE4), 0x00000000,
    0x02260000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248B7C_971D3C)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248B50_971D10), 0x00000000,
    0x01F40000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248BA8_971D68)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248B7C_971D3C), 0x00000000,
    0x01C20000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248BD4_971D94)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248BA8_971D68), 0x00000000,
    0x01900000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248C00_971DC0)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248BD4_971D94), 0x00000000,
    0x015E0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248C2C_971DEC)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248C00_971DC0), 0x00000000,
    0x012C0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248C58_971E18)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248C2C_971DEC), 0x00000000,
    0x00FA0000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248C84_971E44)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248C58_971E18), 0x00000000,
    0x00C80000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248CB0_971E70)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248C84_971E44), 0x00000000,
    0x00960000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248CDC_971E9C)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248CB0_971E70), 0x00000000,
    0x00640000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248D08_971EC8)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248CDC_971E9C), 0x00000000,
    0x00320000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248D34_971EF4)[] = {
    N(D_8024A3B8_973578), 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, N(D_80248D08_971EC8), 0x00000000,
    0x00000000, N(D_80248DD8_971F98), 0x00000000,
};

s32 N(D_80248D60_971F20)[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, N(D_80248D34_971EF4),
    0xFFFF0000, 0x00000000, 0x00000000, N(D_80248D60_971F20), 
    N(D_80248D34_971EF4), N(D_80248D08_971EC8), N(D_80248CDC_971E9C), N(D_80248CB0_971E70),
    N(D_80248C84_971E44), N(D_80248C58_971E18), N(D_80248C2C_971DEC), N(D_80248C00_971DC0), 
    N(D_80248BD4_971D94), N(D_80248BA8_971D68), N(D_80248B7C_971D3C), N(D_80248B50_971D10),
    N(D_80248B24_971CE4), N(D_80248AF8_971CB8), N(D_80248ACC_971C8C), N(D_80248AA0_971C60), 
    0x00000000, 0x00000000,
};

// Vertexes?
s32 N(D_80248DD8_971F98)[] = {
    0x00000000, 0x00000000, 0x04000000, 0xDB1396FF, 0x00000000, 0x00000000, 0x04120038, 0xB615A5FF,
    0x00000000, 0x00000000, 0x04000038, 0xD05CC5FF, 0x00000000, 0x00000000, 0x03ED0000, 0xF94FB2FF,
    0x00000000, 0x00000000, 0x04000071, 0xBB15A1FF, 0x00000000, 0x00000000, 0x03ED0071, 0xD75CC0FF,
    0x00000000, 0x00000000, 0x041200AA, 0xB615A5FF, 0x00000000, 0x00000000, 0x040000AA, 0xD05CC5FF,
    0x00000000, 0x00000000, 0x040000E3, 0xAE15ACFF, 0x00000000, 0x00000000, 0x03ED00E3, 0xC65BCFFF,
    0x00000000, 0x00000000, 0x0412011C, 0xB615A5FF, 0x00000000, 0x00000000, 0x0400011C, 0xD05CC5FF,
    0x00000000, 0x00000000, 0x04000155, 0xBF159FFF, 0x00000000, 0x00000000, 0x03ED0155, 0xDC5BBDFF,
    0x00000000, 0x00000000, 0x0412018E, 0xB615A5FF, 0x00000000, 0x00000000, 0x0400018E, 0xD05CC5FF,
    0x00000000, 0x00000000, 0x040001C7, 0xA515BAFF, 0x00000000, 0x00000000, 0x03ED01C7, 0xBB56DEFF,
    0x00000000, 0x00000000, 0x0400041C, 0x8E20F5FF, 0x00000000, 0x00000000, 0x03ED0400, 0xAC55F8FF,
    0x00000000, 0x00000000, 0x001201C7, 0x14564BFF, 0x00000000, 0x00000000, 0x001203FF, 0xF85554FF,
    0x00000000, 0x00000000, 0x0000041C, 0xF52072FF, 0x00000000, 0x00000000, 0x000001C7, 0x321567FF,
    0x00000000, 0x00000000, 0x00000038, 0x305C3BFF, 0x00000000, 0x00000000, 0x00120000, 0x4B4F16FF,
    0x00000000, 0x00000000, 0x00120071, 0x365C35FF, 0x00000000, 0x00000000, 0x000000AA, 0x305C3BFF,
    0x00000000, 0x00000000, 0x001200E3, 0x245B43FF, 0x00000000, 0x00000000, 0x0000011C, 0x305C3BFF,
    0x00000000, 0x00000000, 0x00120155, 0x3A5B31FF, 0x00000000, 0x00000000, 0x0000018E, 0x305C3BFF,
    0x00000000, 0x00000000, 0x00120000, 0x4B4F16FF, 0x00000000, 0x00000000, 0x00000038, 0x305C3BFF,
    0x00000000, 0x00000000, 0xFFEE0038, 0x4A155BFF, 0x00000000, 0x00000000, 0x00000000, 0x601339FF,
    0x00000000, 0x00000000, 0x00120071, 0x365C35FF, 0x00000000, 0x00000000, 0x00000071, 0x4F1557FF,
    0x00000000, 0x00000000, 0x000000AA, 0x305C3BFF, 0x00000000, 0x00000000, 0xFFEE00AA, 0x4A155BFF,
    0x00000000, 0x00000000, 0x001200E3, 0x245B43FF, 0x00000000, 0x00000000, 0x000000E3, 0x411561FF,
    0x00000000, 0x00000000, 0x0000011C, 0x305C3BFF, 0x00000000, 0x00000000, 0xFFEE011C, 0x4A155BFF,
    0x00000000, 0x00000000, 0x00120155, 0x3A5B31FF, 0x00000000, 0x00000000, 0x00000155, 0x521554FF,
    0x00000000, 0x00000000, 0x0000018E, 0x305C3BFF, 0x00000000, 0x00000000, 0xFFEE018E, 0x4A155BFF,
    0x00000000, 0x00000000, 0x001201C7, 0x14564BFF, 0x00000000, 0x00000000, 0x000001C7, 0x321567FF,
};

// vertexes but vtxdis ignores the flag entirely, and it's set here
s32 N(D_802490F8_9722B8)[] = {
    0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F,
    0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C,
    0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8,
    0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84,
    0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE,
    0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B,
    0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E,
    0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8,
    0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053,
    0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75,
    0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C,
    0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E,
    0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B,
    0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8,
    0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F,
    0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4,
    0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE,
    0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038,
    0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D,
    0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C,
    0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C,
    0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8,
    0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C,
    0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5,
    0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA,
    0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8,
    0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027,
    0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6,
    0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C,
    0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C,
    0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7,
    0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE,
    0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE,
    0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E,
    0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE,
    0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005,
    0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14,
    0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8,
    0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51,
    0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4,
    0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C,
    0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D,
    0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43,
    0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C,
    0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC,
    0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23,
    0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C,
    0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47,
    0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED,
    0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C,
    0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD,
    0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79,
    0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE,
    0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2,
    0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49,
    0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE,
    0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B,
    0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12,
    0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C,
    0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B,
    0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE,
    0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE,
    0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6,
    0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61,
    0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8,
    0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21,
    0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22,
    0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C,
    0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3,
    0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6,
    0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE,
    0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD,
    0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F,
    0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE,
    0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D,
    0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F,
    0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C,
    0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8,
    0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84,
    0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE,
    0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B,
    0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E,
    0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8,
    0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053,
    0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75,
    0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C,
    0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E,
    0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B,
    0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8,
    0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F,
    0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4,
    0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE,
    0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038,
    0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D,
    0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C,
    0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C,
    0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8,
    0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C,
    0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5,
    0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA,
    0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8,
    0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027,
    0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6,
    0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C,
    0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C,
    0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7,
    0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE,
    0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE,
    0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E,
    0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE,
    0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005,
    0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14,
    0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8,
    0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51,
    0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4,
    0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C,
    0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D,
    0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43,
    0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C,
    0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC,
    0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23,
    0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C,
    0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47,
    0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED,
    0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C,
    0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD,
    0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79,
    0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE,
    0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2,
    0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49,
    0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE,
    0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21, 0xFE5300C8, 0xFE29FE75, 0x00BEFE1B,
    0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22, 0x00C8FE51, 0xFE0C008C, 0xFE64FE12,
    0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C, 0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C,
    0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3, 0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B,
    0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6, 0x008C005D, 0xFFAA00C8, 0xFFCDFFBE,
    0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE, 0xFFFFFF43, 0x00C8001F, 0xFF1D00BE,
    0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD, 0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6,
    0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F, 0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61,
    0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE, 0x0030FF23, 0x008C0038, 0xFF0E00C8,
    0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D, 0xFE6F008C, 0xFE14FE4D, 0x008CFE21,
    0xFE5300C8, 0xFE29FE75, 0x00BEFE1B, 0xFE39008C, 0xFE3FFE3F, 0x00BEFE47, 0xFE1C008C, 0xFE49FE22,
    0x00C8FE51, 0xFE0C008C, 0xFE64FE12, 0x00BEFE6C, 0xFDE6008C, 0xFE75FDED, 0x00C8FE7C, 0xFDCE008C,
    0xFE96FDD4, 0x00BEFE9E, 0xFDB1008C, 0xFEA0FDB7, 0x00C8FEA8, 0xFDA1008C, 0xFEBBFDA8, 0x00BEFEC3,
    0xFD2D008C, 0xFF1AFD3B, 0x00BEFF1B, 0xFEF000BE, 0x0055FE84, 0x00BE00AD, 0xFE83008C, 0x00BBFEF6,
    0x008C005D, 0xFFAA00C8, 0xFFCDFFBE, 0x00BEFFAE, 0xFF8800BE, 0xFFDAFF79, 0x00C8FFF5, 0xFF5B00BE,
    0xFFFFFF43, 0x00C8001F, 0xFF1D00BE, 0x0030FF0E, 0x00C8004B, 0xFFBE00BE, 0xFFAEFFAA, 0x00C8FFCD,
    0xFFB0008C, 0xFFD4FFC4, 0x008CFFB6, 0xFF8800BE, 0xFFDAFF8E, 0x008CFFE2, 0xFF7900C8, 0xFFF5FF7F,
    0x008CFFFC, 0xFF5B00BE, 0xFFFFFF61, 0x008C0005, 0xFF4300C8, 0x001FFF49, 0x008C0027, 0xFF1D00BE,
    0x0030FF23, 0x008C0038, 0xFF0E00C8, 0x004BFF14, 0x008C0053, 0xFEF000BE, 0x0055FEF6, 0x008C005D,
};

s32 N(image2)[];

Gfx N(D_8024A3B8_973578)[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPLoadTextureBlock(N(image2), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPVertex(N(D_802490F8_9722B8), 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 7, 0),
    gsSP2Triangles(8, 10, 11, 0, 8, 11, 9, 0),
    gsSP2Triangles(10, 12, 13, 0, 10, 13, 11, 0),
    gsSP2Triangles(12, 14, 15, 0, 12, 15, 13, 0),
    gsSP2Triangles(14, 16, 17, 0, 14, 17, 15, 0),
    gsSP2Triangles(16, 18, 19, 0, 16, 19, 17, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(3, 2, 24, 0, 3, 24, 25, 0),
    gsSP2Triangles(2, 5, 26, 0, 2, 26, 24, 0),
    gsSP2Triangles(5, 7, 27, 0, 5, 27, 26, 0),
    gsSP2Triangles(7, 9, 28, 0, 7, 28, 27, 0),
    gsSP2Triangles(9, 11, 29, 0, 9, 29, 28, 0),
    gsSP2Triangles(11, 13, 30, 0, 11, 30, 29, 0),
    gsSP2Triangles(13, 15, 31, 0, 13, 31, 30, 0),
    gsSP2Triangles(15, 17, 20, 0, 15, 20, 31, 0),
    gsSP2Triangles(17, 19, 21, 0, 17, 21, 20, 0),
    gsSP2Triangles(19, 18, 22, 0, 19, 22, 21, 0),
    gsSPVertex(N(D_802490F8_9722B8), 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSP2Triangles(6, 8, 9, 0, 6, 9, 7, 0),
    gsSP2Triangles(8, 10, 11, 0, 8, 11, 9, 0),
    gsSP2Triangles(10, 12, 13, 0, 10, 13, 11, 0),
    gsSP2Triangles(12, 14, 15, 0, 12, 15, 13, 0),
    gsSP2Triangles(14, 16, 17, 0, 14, 17, 15, 0),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

// 16x32 RGA16 texture
s32 N(image2)[] = {
    0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D, 0x9D1D9D1D,
    0x9D1DBDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5,
    0x9D1DBDE5, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB,
    0x9D1DBDE5, 0xD6ABDEF7, 0xD6ABDEF7, 0xD6ABDEF7, 0xD6ABDEF7, 0xD6ABDEF7, 0xD6ABDEF7, 0xD6ABDEF7,
    0x9D1DBDE5, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB, 0xDEF7D6AB,
    0x9D1DBDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5, 0xBDE5BDE5,
    0x33E93C6B, 0x3C6B3C6B, 0x3C6B3C6B, 0x3C6B3C6B, 0x3C6B3C6B, 0x3C6B3C6B, 0x3C6B3C6B, 0x3C6B3C6B,
    0x3C6B44F1, 0x44F144F1, 0x44F15D73, 0x5D7344F1, 0x44F15D73, 0x5D7344F1, 0x44F144F1, 0x44F144F1,
    0x33E93C6B, 0x44F144F1, 0x44F144F1, 0x5D735D73, 0x5D735D73, 0x44F144F1, 0x44F144F1, 0x3C6B33E9,
    0x9D1D33E9, 0x3C6B44F1, 0x44F144F1, 0x44F15D73, 0x5D7344F1, 0x44F144F1, 0x44F13C6B, 0x33E99D1D,
    0xBDE59D1D, 0x33E93C6B, 0x44F144F1, 0x44F144F1, 0x44F144F1, 0x44F144F1, 0x3C6B33E9, 0x9D1D9D1D,
    0xBDE5BDE5, 0x9D1D33E9, 0x3C6B44F1, 0x44F144F1, 0x44F144F1, 0x44F13C6B, 0x33E99D1D, 0x9D1D9B01,
    0xBDE5BDE5, 0xBDE59D1D, 0x33E93C6B, 0x44F144F1, 0x44F144F1, 0x3C6B33E9, 0x9D1DBDE5, 0x9B01C405,
    0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D33E9, 0x3C6B44F1, 0x44F13C6B, 0x23659D1D, 0xBDE59D1D, 0x9B01C405,
    0xD6ABD6AB, 0xBDE5BDE5, 0xBDE59D1D, 0x33E93C6B, 0x3C6B2365, 0x9D1DBDE5, 0x9D1D9B01, 0xC405D48B,
    0xBDE5D6AB, 0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D33E9, 0x23659D1D, 0x9D1D9D1D, 0x9D1D9B01, 0xC405D48B,
    0xBDE5D6AB, 0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D9B01, 0x9B019B01, 0x9B019B01, 0x9B01C405, 0xD48BD48B,
    0xD6ABD6AB, 0xBDE5BDE5, 0xBDE59D1D, 0x33E99B01, 0xC405C405, 0xC405C405, 0xC405D48B, 0xD48BD48B,
    0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D33E9, 0x3C6B33E9, 0x9B01C405, 0xC405C405, 0xD48BD48B, 0x9B01D48B,
    0xBDE5BDE5, 0xBDE59D1D, 0x33E93C6B, 0x44F13C6B, 0x33E99B01, 0x9B01C405, 0xC405D48B, 0x9B01D48B,
    0xBDE5BDE5, 0x9D1D33E9, 0x3C6B44F1, 0x44F144F1, 0x3C6B33E9, 0x23659B01, 0xC405D48B, 0x9B01D48B,
    0xBDE59D1D, 0x33E93C6B, 0x44F144F1, 0x44F144F1, 0x44F13C6B, 0x33E99B01, 0xC405D48B, 0xD48BD48B,
    0x9D1D33E9, 0x3C6B44F1, 0x44F15D73, 0x44F144F1, 0x3C6B33E9, 0x23659B01, 0xC405D48B, 0xD48BD48B,
    0x33E93C6B, 0x44F144F1, 0x5D735D73, 0x44F144F1, 0x3C6B33E9, 0x9B01C405, 0xC405C405, 0xC405C405,
    0x33E93C6B, 0x44F144F1, 0x5D735D73, 0x44F144F1, 0x3C6B33E9, 0x9B01C405, 0xC405C405, 0x9B019B01,
    0x9D1D33E9, 0x3C6B44F1, 0x44F15D73, 0x44F13C6B, 0x33E99B01, 0xC405C405, 0xC4059B01, 0x23659D1D,
    0xBDE59D1D, 0x33E93C6B, 0x44F144F1, 0x44F13C6B, 0x33E99B01, 0xC4059B01, 0x9B012365, 0x9D1DBDE5,
    0xBDE5BDE5, 0x9D1D33E9, 0x3C6B44F1, 0x44F13C6B, 0x33E99B01, 0x9B0133E9, 0x23659D1D, 0xBDE5BDE5,
    0xBDE5BDE5, 0xBDE59D1D, 0x33E93C6B, 0x44F144F1, 0x3C6B33E9, 0x33E92365, 0x9D1DBDE5, 0xBDE5BDE5,
    0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D33E9, 0x3C6B44F1, 0x3C6B3C6B, 0x33E99D1D, 0xBDE5BDE5, 0xBDE5D6AB,
    0xD6ABD6AB, 0xBDE5BDE5, 0xBDE59D1D, 0x33E93C6B, 0x3C6B33E9, 0x9D1DBDE5, 0xBDE5BDE5, 0xD6ABD6AB,
    0xBDE5D6AB, 0xD6ABBDE5, 0xBDE5BDE5, 0x9D1D33E9, 0x33E99D1D, 0xBDE5BDE5, 0xBDE5D6AB, 0xD6AB05EF,
    0x00130005, 0x00010000, 0x00000000, 0x00080001, 0x00000000, 0x00000011, 0x000100B6, 0x00B600B6,
    0x00050002, 0x00000000, 0x00000008, 0x00020000, 0x00000000, 0x00110002, 0x00B600B6, 0x00B60005,
    0x00030000, 0x00000000, 0x00080003, 0x00000000, 0x00000011, 0x000300B6, 0x00B600B6, 0x00050004,
    0x00000000, 0x00000008, 0x00040000, 0x00000000, 0x00110004, 0x00B600B6, 0x00B60005, 0x00050000,
    0x00000000, 0x00080005, 0x00000000, 0x00000011, 0x000500B6, 0x00B600B6, 0x00050006, 0x00000000,
    0x00000008, 0x00060000, 0x00000000, 0x00110006, 0x00B600B6, 0x00B60005, 0x00070000, 0x00000000,
    0x00080007, 0x00000000, 0x00000011, 0x000700B6, 0x00B600B6, 0x00050008, 0x00000000, 0x00000008,
    0x00080000, 0x00000000, 0x00110008, 0x00B600B6, 0x00B60005, 0x00090000, 0x00000000, 0x00080009,
    0x00000000, 0x00000011, 0x000900B6, 0x00B600B6, 0x0005000A, 0x00000000, 0x00000008, 0x000A0000,
    0x00000000, 0x0011000A, 0x00B600B6, 0x00B60005, 0x000B0000, 0x00000000, 0x0008000B, 0x00000000,
    0x00000011, 0x000B00B6, 0x00B600B6, 0x0005000C, 0x00000000, 0x00000008, 0x000C0000, 0x00000000,
    0x0011000C, 0x00B600B6, 0x00B60005, 0x000D0000, 0x00000000, 0x0008000D, 0x00000000, 0x00000011,
    0x000D00B6, 0x00B600B6, 0x0005000E, 0x00000000, 0x00000008, 0x000E0000, 0x00000000, 0x0011000E,
    0x00B600B6, 0x00B60005, 0x000F0000, 0x00000000, 0x0008000F, 0x00000000, 0x00000011, 0x000F00B6,
    0x00B600B6, 0x00050010, 0x00000000, 0x00000008, 0x00100000, 0x00000000, 0x00110010, 0x00B600B6,
    0x00B60005, 0x00110000, 0x00000000, 0x00080011, 0x00000000, 0x00000011, 0x001100B6, 0x00B600B6,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00030000,
};

Script N(8024AC14) = SCRIPT({
    EnableModel(SI_VAR(4), 0);
    EnableModel(SI_VAR(5), 1);
    RotateModel(SI_VAR(6), 0, 0, 0, 1);
    RotateModel(SI_VAR(7), 0, 0, 0, 1);
});

Script N(8024AC8C) = SCRIPT({
    SI_VAR(9) = SI_VAR(7);
    SI_VAR(8) = SI_VAR(6);
    SI_VAR(7) = SI_VAR(5);
    SI_VAR(6) = SI_VAR(4);
    sleep 70;
    EnableModel(SI_VAR(6), 0);
    spawn {
        sleep 5;
        EnableModel(SI_VAR(6), 1);
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(SI_VAR(8), SI_VAR(0), 0, 0, -1);
    RotateModel(SI_VAR(9), SI_VAR(0), 0, 0, -1);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(SI_VAR(7), 0);
});

Script N(interact_8024ADE4) = SCRIPT({
    N(UnkFunc35)(0, 0, 0);
    await N(8024D434);
    if (SI_VAR(0) == 0) {
        return;
    }
    SI_VAR(9) = SI_VAR(1);
    SI_VAR(10) = SI_VAR(2);
    SI_VAR(11) = SI_VAR(3);
    N(UnkFunc34)();
    if (SI_VAR(1) == 0) {
        SI_VAR(8) = SI_VAR(0);
    }
    SpeakToPlayer(NPC_SELF, 0x830004, 0x830001, 0, SI_VAR(8));
    ShowChoice(MESSAGE_ID(0x1E, 0x0006));
    sleep 3;
    if (SI_VAR(0) == 1) {
        ContinueSpeech(-1, 0x830004, 0x830001, 0, SI_VAR(9));
        return;
    }
    ContinueSpeech(-1, 0x830004, 0x830001, 0, SI_VAR(10));
    SetPlayerJumpscale(1);
    DisablePlayerPhysics(TRUE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
    N(Call800E9894)();
    if (SI_VAR(4) != 0) {
        spawn N(8024AC8C);
    }
    N(GetPartnerCall800EB168)(SI_VAR(10));
    sleep 20;
    await N(8024D494);
    spawn {
        MakeLerp(0, 255, 60, 0);
    0:
        UpdateLerp();
        N(UnkFunc32)(3, SI_VAR(0));
        sleep 1;
        if (SI_VAR(1) == 1) {
            goto 0;
        }
        FullyRestoreHPandFP();
        FullyRestoreSP();
        if (SI_VAR(4) != 0) {
            spawn N(8024AC14);
        }
        N(Call800EB168)(SI_VAR(10));
        sleep 45;
        MakeLerp(255, 0, 30, 0);
    1:
        UpdateLerp();
        N(UnkFunc32)(0, SI_VAR(0));
        sleep 1;
        if (SI_VAR(1) == 1) {
            goto 1;
        }
    }
    sleep 105;
    await N(8024D700);
    DisablePlayerPhysics(FALSE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), FALSE);
    SpeakToPlayer(NPC_SELF, 0x830004, 0x830001, 0, SI_VAR(11));
    N(Call800E98C4SyncStatusMenu)();
});

Script N(8024B18C) = SCRIPT({
    loop {
        GetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
        N(UnkYawFunc)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
        SetItemPos(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5));
        sleep 1;
    }
});

Script N(8024B20C) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    func_802D6420();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveKeyItemAt(SI_VAR(1));
            DisablePartnerAI(0);
            GetNpcPos(NPC_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(UnkYawFunc)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            SI_VAR(0) |=c 0x50000;
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SI_VAR(10) = spawn N(8024B18C);
            SetNpcAnimation(NPC_PARTNER, 0x40002);
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
            SetNpcAnimation(NPC_PARTNER, 0x40001);
            NpcFaceNpc(NPC_PARTNER, SI_VAR(9), 0);
            sleep 5;
            SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), FALSE);
            EnablePartnerAI();
            sleep 5;
        }
    }
    N(func_80243314_96C4D4)(SI_VAR(10));
    func_802D6954();
    unbind;
});

Script N(8024B530) = {
    SI_CMD(ScriptOpcode_SET, SI_VAR(0), SI_VAR(11)),
    SI_CMD(ScriptOpcode_SET, SI_VAR(1), SI_VAR(2)),
    SI_CMD(ScriptOpcode_CALL, N(func_8024334C_96C50C), SI_VAR(0)),
    SI_CMD(ScriptOpcode_BIND_PADLOCK, N(8024B20C), 0x10, 0, N(D_8024F080), 0, 1),
    SI_CMD(ScriptOpcode_CALL, N(func_802432C0_96C480), SI_VAR(0)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(8024B5A0) = SCRIPT({
    SI_VAR(12) = 0;
    if (STORY_PROGRESS < STORY_CH2_PARAKARRY_JOINED_PARTY) {
        return;
    }
    N(func_802439FC_96CBBC)();
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
            await N(8024B530);
            match SI_VAR(0) {
                == -1 {
                    DisablePartnerAI(0);
                    sleep 1;
                    SpeakToPlayer(NPC_PARTNER, 0x40006, 0x40001, 5, SI_VAR(8));
                    EnablePartnerAI();
                    SI_VAR(12) = 1;
                }
                else {
                    DisablePartnerAI(0);
                    sleep 1;
                    SpeakToPlayer(NPC_PARTNER, 0x40006, 0x40001, 5, SI_VAR(9));
                    if (SI_VAR(10) != 0) {
                        SpeakToPlayer(SI_VAR(2), SI_VAR(3), SI_VAR(4), 0, SI_VAR(10));
                    }
                    EnablePartnerAI();
                    if (SI_VAR(6) != 0) {
                        SI_VAR(0) = SI_VAR(6);
                        SI_VAR(1) = 1;
                        await N(80244DE4);
                        AddKeyItem(SI_VAR(6));
                    }
                    SI_VAR(12) = 2;
                }
            }
        }
    }
    N(func_80243A40_96CC00)();
});

s32 N(D_8024B898_974A58)[] = {
    0x0000004A, 0x00000000,
};

Script N(8024B8A0) = SCRIPT({
    N(SetManyVars)(1, 9634308, 9634305, 74, 75, 852117, 852118, 852119, 852120, N(D_8024B898_974A58));
    await N(8024B5A0);
});

Script N(interact_8024B8F0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_SAVE_FLAG(787) == 1) {
                SpeakToPlayer(NPC_SELF, 0xB80004, 0xB80001, 0, MESSAGE_ID(0x0D, 0x00B2));
            } else {
                match SI_AREA_VAR(3) {
                    == 0 {
                        SpeakToPlayer(NPC_SELF, 0xB80004, 0xB80001, 0, MESSAGE_ID(0x0D, 0x00AF));
                        SI_AREA_VAR(3) = 1;
                    }
                    == 1 {
                        SpeakToPlayer(NPC_SELF, 0xB80004, 0xB80001, 0, MESSAGE_ID(0x0D, 0x00B0));
                        SI_AREA_VAR(3) = 2;
                    }
                    == 2 {
                        SpeakToPlayer(NPC_SELF, 0xB80004, 0xB80001, 0, MESSAGE_ID(0x0D, 0x00B1));
                        SI_AREA_VAR(3) = 1;
                    }
                }
            }
        }
        else {
            SpeakToPlayer(NPC_SELF, 0xB80004, 0xB80001, 0, MESSAGE_ID(0x0D, 0x00B3));
        }
    }
});

Script N(init_8024BA50) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024B8F0));
    if (STORY_PROGRESS >= STORY_UNUSED_FFFFFFCC) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(interact_8024BA9C) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_SAVE_FLAG(747) == 0) {
                SpeakToPlayer(NPC_SELF, 0x930204, 0x930201, 0, MESSAGE_ID(0x0D, 0x0091));
            } else {
                SpeakToPlayer(NPC_SELF, 0x930204, 0x930201, 0, MESSAGE_ID(0x0D, 0x0092));
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, 0x930204, 0x930201, 0, MESSAGE_ID(0x0D, 0x0093));
        }
        else {
            SpeakToPlayer(NPC_SELF, 0x930204, 0x930201, 0, MESSAGE_ID(0x0D, 0x0094));
        }
    }
    await N(8024B8A0);
    if (SI_VAR(12) != 0) {
        return;
    }
});

Script N(init_8024BBAC) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024BA9C));
});

Script N(interact_8024BBD0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(3) == 0) {
                SpeakToPlayer(NPC_SELF, 0x930004, 0x930001, 0, MESSAGE_ID(0x0D, 0x00A1));
                SI_AREA_FLAG(3) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, 0x930004, 0x930001, 0, MESSAGE_ID(0x0D, 0x00A2));
                SI_AREA_FLAG(3) = 0;
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, 0x930004, 0x930001, 0, MESSAGE_ID(0x0D, 0x00A3));
        }
        else {
            SpeakToPlayer(NPC_SELF, 0x930004, 0x930001, 0, MESSAGE_ID(0x0D, 0x00A4));
        }
    }
});

Script N(init_8024BCD4) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024BBD0));
});

Script N(interact_8024BCF8) = SCRIPT({
    SpeakToPlayer(NPC_SELF, 0x930004, 0x930001, 0, MESSAGE_ID(0x0D, 0x00A0));
});

Script N(init_8024BD28) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024BCF8));
});

Script N(interact_8024BD4C) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(4) == 0) {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00A5));
                SI_AREA_FLAG(4) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00A6));
                SI_AREA_FLAG(4) = 0;
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(4) == 0) {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00A7));
                SI_AREA_FLAG(4) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00A8));
                SI_AREA_FLAG(4) = 0;
            }
        }
        else {
            if (SI_AREA_FLAG(4) == 0) {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00A9));
                SI_AREA_FLAG(4) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00AA));
                SI_AREA_FLAG(4) = 0;
            }
        }
    }
});

Script N(init_8024BF10) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024BD4C));
});

Script N(interact_8024BF34) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_STAR_SPRIT_DEPARTED {
            if (SI_AREA_FLAG(5) == 0) {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00AB));
                SI_AREA_FLAG(5) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00AC));
                SI_AREA_FLAG(5) = 0;
            }
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00AD));
        }
        else {
            SpeakToPlayer(NPC_SELF, 0x940005, 0x940001, 0, MESSAGE_ID(0x0D, 0x00AE));
        }
    }
});

Script N(init_8024C038) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024BF34));
});

Script N(8024C05C) = SCRIPT({
    loop {
        PlayerFaceNpc(5, 0);
        NpcFaceNpc(NPC_PARTNER, NPC_MOUSTAFA, 0);
        sleep 1;
    }
});

Script N(8024C0B8) = SCRIPT({
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 275);
    GetNpcPos(NPC_DISGUISED_MOUSTAFA, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(1) += SI_VAR(4);
    SI_VAR(2) += SI_VAR(5);
    SI_VAR(0) /= 2;
    SI_VAR(1) /= 2;
    SI_VAR(2) /= 2;
    SI_VAR(1) += 15;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 8.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
});

Script N(8024C1F8) = SCRIPT({
    PanToTarget(0, 0, 0);
    SetCamSpeed(0, 3.0);
    WaitForCam(0, 1.0);
});

Script N(8024C248) = SCRIPT({
    SetNpcYaw(NPC_MOUSTAFA, 270);
    SetNpcFlagBits(NPC_DISGUISED_MOUSTAFA, ((NPC_FLAG_100)), TRUE);
    SetNpcFlagBits(NPC_MOUSTAFA, ((NPC_FLAG_100)), TRUE);
    SetNpcAnimation(NPC_DISGUISED_MOUSTAFA, 0xBC0005);
    sleep 30;
    SetNpcAnimation(NPC_DISGUISED_MOUSTAFA, 0xBC0006);
    SetNpcAnimation(NPC_MOUSTAFA, 0xBD0007);
    SetNpcPos(NPC_MOUSTAFA, -335, 163, -260);
    spawn N(80243B9C);
    MakeLerp(0, 80, 30, 5);
10:
    UpdateLerp();
    SI_VAR(2) = -335;
    SI_VAR(3) = 163;
    SI_VAR(2) -= SI_VAR(0);
    SI_VAR(3) += SI_VAR(0);
    SetNpcPos(NPC_DISGUISED_MOUSTAFA, SI_VAR(2), SI_VAR(3), -260);
    sleep 1;
    if (SI_VAR(1) == 1) {
        goto 10;
    }
    SetNpcFlagBits(NPC_DISGUISED_MOUSTAFA, ((NPC_FLAG_100)), FALSE);
    SetNpcPos(NPC_DISGUISED_MOUSTAFA, 0, -1000, -250);
    SetNpcAnimation(NPC_MOUSTAFA, 0xBD0001);
    SetNpcFlagBits(NPC_DISGUISED_MOUSTAFA, ((NPC_FLAG_100)), FALSE);
    SetNpcFlagBits(NPC_MOUSTAFA, ((NPC_FLAG_100)), FALSE);
    sleep 30;
});

Script N(idle_8024C450) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH2_BOUGHT_SECRET_ITEMS {}
        < STORY_CH2_GOT_PULSE_STONE {
            SetNpcPos(NPC_SELF, -335, 163, -260);
        }
        >= STORY_CH2_GOT_PULSE_STONE {
            SetNpcPos(NPC_SELF, 0, -1000, -250);
            SetNpcPos(NPC_MOUSTAFA, -335, 163, -260);
        }
    }
});

Script N(interact_8024C4EC) = SCRIPT({
    if (SI_SAVE_FLAG(750) == 1) {
        SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CF));
        return;
    }
    match STORY_PROGRESS {
        < STORY_CH2_BOUGHT_SECRET_ITEMS {
            SI_VAR(11) = 0;
            SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B4));
        0:
            ShowChoice(MESSAGE_ID(0x1E, 0x0019));
            if (SI_VAR(0) == 1) {
                ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B6));
                spawn N(8024C1F8);
                return;
            } else {
                EndSpeech(2, 12320772, 12320769, 0);
            }
        1:
            SI_VAR(0) = 0;
            SI_VAR(1) = 2;
            await N(80248A50);
            match SI_VAR(0) {
                == 0 {
                    SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B8));
                    spawn N(8024C1F8);
                    return;
                }
                == -1 {
                    SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B7));
                    spawn N(8024C1F8);
                    return;
                }
            }
            SI_VAR(10) = SI_VAR(0);
            if (SI_SAVE_VAR(135) == 0) {
                if (SI_VAR(10) == 156) {
                    SI_SAVE_VAR(135) = 1;
                    SI_SAVE_VAR(134) = 10;
                    SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BB));
                    ShowChoice(MESSAGE_ID(0x1E, 0x001C));
                } else {
                    SI_SAVE_VAR(134) += 1;
                    if (SI_SAVE_VAR(134) <= 2) {
                        SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B5));
                        goto 0;
                    }
                    if (SI_SAVE_VAR(134) == 3) {
                        SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B9));
                        ShowChoice(MESSAGE_ID(0x1E, 0x001B));
                    } else {
                        SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BA));
                        ShowChoice(MESSAGE_ID(0x1E, 0x001B));
                        SI_SAVE_VAR(134) = 10;
                    }
                }
            } else {
                SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BA));
                ShowChoice(MESSAGE_ID(0x1E, 0x001C));
            }
            match SI_VAR(0) {
                == 0 {
                    ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BC));
                }
                == 1 {
                    await N(8024C0B8);
                    ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BD));
                    SI_SAVE_FLAG(747) = 1;
                }
                == 2 {
                    await N(8024C0B8);
                    ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BE));
                    SI_SAVE_FLAG(748) = 1;
                }
                == 3 {
                    await N(8024C0B8);
                    ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00BF));
                }
                == 4 {
                    await N(8024C0B8);
                    ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00C1));
                    SI_SAVE_FLAG(749) = 1;
                    SI_VAR(11) = 1;
                }
            }
            SI_SAVE_FLAG(746) = 1;
            ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00C0));
            ShowChoice(MESSAGE_ID(0x1E, 0x001A));
            if (SI_VAR(0) == 0) {
                EndSpeech(2, 12320772, 12320769, 0);
                goto 1;
            } else {
                ContinueSpeech(2, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00B6));
            }
            if (SI_VAR(11) == 1) {
                if (SI_MAP_FLAG(0) == 0) {
                    SI_MAP_FLAG(0) = 1;
                    spawn {
                        GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                        AwaitPlayerLeave(SI_VAR(0), SI_VAR(2), 50);
                        DisablePlayerInput(TRUE);
                        SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00C2));
                        DisablePlayerInput(FALSE);
                        SI_MAP_FLAG(0) = 0;
                    }
                }
            }
            spawn N(8024C1F8);
        }
        < -63 {
            spawn {
                sleep 10;
                func_802D2C14(1);
            }
            SetNpcFlagBits(NPC_DISGUISED_MOUSTAFA, ((NPC_FLAG_100)), TRUE);
            SetPlayerSpeed(3.0);
            PlayerMoveTo(-391, -260, 0);
            InterpPlayerYaw(90, 3);
            SetNpcFlagBits(NPC_DISGUISED_MOUSTAFA, ((NPC_FLAG_100)), FALSE);
            SI_VAR(10) = spawn N(8024C05C);
            SetNpcFlagBits(NPC_MOUSTAFA, ((NPC_FLAG_100)), TRUE);
            FadeOutMusic(0, 500);
            if (SI_SAVE_FLAG(749) == 1) {
                SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00C3));
                await N(8024C248);
                func_802D2C14(0);
                SetNpcJumpscale(NPC_MOUSTAFA, 1.0);
                NpcJump0(NPC_MOUSTAFA, -425, 140, -206, 20);
                SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00C4));
            } else {
                SpeakToPlayer(NPC_DISGUISED_MOUSTAFA, 0xBC0004, 0xBC0001, 0, MESSAGE_ID(0x0D, 0x00C5));
                await N(8024C248);
                func_802D2C14(0);
                SetNpcJumpscale(NPC_MOUSTAFA, 1.0);
                NpcJump0(NPC_MOUSTAFA, -425, 140, -206, 20);
                SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00C6));
            }
            SetNpcJumpscale(NPC_MOUSTAFA, 1.0);
            NpcJump0(NPC_MOUSTAFA, -337, 140, -200, 20);
            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00C7));
            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00C8));
            SetNpcJumpscale(NPC_MOUSTAFA, 1.0);
            NpcJump0(NPC_MOUSTAFA, -335, 163, -260, 20);
            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00C9));
            SI_VAR(0) = 18;
            SI_VAR(1) = 1;
            await N(80244DE4);
            AddKeyItem(ITEM_PULSE_STONE);
            STORY_PROGRESS = STORY_CH2_GOT_PULSE_STONE;
            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CA));
            kill SI_VAR(10);
            spawn N(80243AF0);
        }
        >= -63 {
            match STORY_PROGRESS {
                < STORY_CH2_UNCOVERED_DRY_DRY_RUINS {
                    SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CB));
                }
                >= STORY_CH2_UNCOVERED_DRY_DRY_RUINS {
                    if (STORY_PROGRESS >= STORY_CH2_DEFEATED_TUTANKOOPA) {
                        if (SI_SAVE_FLAG(751) == 0) {
                            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CD));
                            SetPlayerAnimation(ANIM_10002);
                            sleep 15;
                            SetPlayerAnimation(ANIM_80007);
                            sleep 30;
                            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CE));
                            SI_SAVE_FLAG(751) = 1;
                        } else {
                            SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00D0));
                        }
                    } else {
                        SpeakToPlayer(NPC_MOUSTAFA, 0xBD0005, 0xBD0001, 0, MESSAGE_ID(0x0D, 0x00CC));
                    }
                }
            }
        }
    }
});

Script N(init_8024D04C) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        2, 3 {
            SetNpcPos(NPC_SELF, 200, 0, -15);
            InterpNpcYaw(NPC_SELF, 270, 0);
            SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_200000)), TRUE);
            SetNpcAnimation(NPC_SELF, 0xBC0005);
        }
        else {
            BindNpcIdle(NPC_SELF, N(idle_8024C450));
            BindNpcInteract(NPC_SELF, N(interact_8024C4EC));
        }
    }
});

Script N(init_8024D130) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024C4EC));
});

Script N(idle_8024D154) = SCRIPT({
    InterpNpcYaw(NPC_DISGUISED_MOUSTAFA, 270, 0);
10:
    SetNpcAnimation(NPC_SELF, 0x940107);
    SetNpcAnimation(NPC_DISGUISED_MOUSTAFA, 0xBC0001);
    loop 50 {
        IsPlayerWithin(200, 50, 100, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            goto 20;
        }
        sleep 1;
    }
    SetNpcAnimation(NPC_SELF, 0x940101);
    SetNpcAnimation(NPC_DISGUISED_MOUSTAFA, 0xBC0007);
    loop 50 {
        IsPlayerWithin(200, 50, 100, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            goto 20;
        }
        sleep 1;
    }
    goto 10;
20:
    SetNpcAnimation(NPC_DISGUISED_MOUSTAFA, 0xBC0001);
    SetNpcAnimation(NPC_SELF, 0x940104);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
    SetNpcAnimation(NPC_SELF, 0x940104);
    NpcMoveTo(NPC_SELF, 150, 18, 20);
    EnableNpcBlur(-1, 1);
    PlaySoundAtNpc(NPC_SELF, 0x174, 0);
    NpcMoveTo(NPC_SELF, -83, 11, 20);
    NpcMoveTo(NPC_SELF, -239, 5, 20);
    NpcMoveTo(NPC_SELF, -371, 5, 20);
    NpcMoveTo(NPC_SELF, -487, 5, 20);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    STORY_PROGRESS = STORY_CH2_SPOKE_WITH_SHEEK;
});

Script N(init_8024D3E8) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024D154));
    if (STORY_PROGRESS >= STORY_CH2_SPOKE_WITH_SHEEK) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(8024D434) = SCRIPT({
    SI_VAR(0) = 852177;
    SI_VAR(8) = 852178;
    SI_VAR(1) = 852179;
    SI_VAR(2) = 852180;
    SI_VAR(3) = 852181;
});

Script N(8024D494) = SCRIPT({
    spawn N(80243B70);
    SetPlayerSpeed(3.0);
    PlayerMoveTo(-179, -198, 0);
    spawn {
        sleep 15;
        N(UnkFunc33)(0, 40);
        SetCamType(0, 4, 0);
        SetCamPitch(0, 95, -61);
        SetCamDistance(0, 108);
        SetCamPosA(0, 202, 62);
        SetCamPosB(0, -89, -141);
        SetCamPosC(0, 0, 0);
        SetCamSpeed(0, 90.0);
        PanToTarget(0, 0, 1);
    }
    PlayerMoveTo(-187, -267, 0);
    InterpPlayerYaw(230, 1);
    HidePlayerShadow(TRUE);
    SetPlayerAnimation(ANIM_10002);
    func_802D286C(2048);
    func_802D2520(ANIM_10002, 5, 7, 1, 1, 0);
    spawn {
        sleep 60;
        SetPlayerAnimation(ANIM_8001D);
    }
    sleep 20;
    spawn {
        sleep 81;
        N(UnkFunc33)(0, 25);
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 1;
        PanToTarget(0, 0, 0);
    }
});

Script N(8024D700) = SCRIPT({
    HidePlayerShadow(FALSE);
    func_802D2520(ANIM_10002, 0, 0, 0, 0, 0);
    SetPlayerPos(-187, 0, -240);
    SetPlayerSpeed(3.0);
    PlayerMoveTo(-168, -195, 0);
    spawn N(80243AF0);
});

Script N(init_8024D790) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_8024ADE4));
});

StaticNpc N(npcGroup_8024D7B4)[] = {
    {
        .id = NPC_ARCHEOLOGIST,
        .settings = &N(npcSettings_80247484),
        .pos = { -320.0f, 0.0f, -14.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BA50),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { -303, 0, 22, 146, 38, -32767, 1, 0, 0, 0, 0, 0, 0, 1 },
        .animations = {
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_2),
            NPC_ANIM(archeologist, Palette_00, Anim_3),
            NPC_ANIM(archeologist, Palette_00, Anim_3),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
            NPC_ANIM(archeologist, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x0001),
    },
    {
        .id = NPC_DRYITE0,
        .settings = &N(npcSettings_80247500),
        .pos = { -20.0f, 0.0f, 40.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BBAC),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { -20, 0, 40, 60, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 },
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
        .tattle = MESSAGE_ID(0x1A, 0x009C),
    },
    {
        .id = NPC_DISGUISED_MOUSTAFA,
        .settings = &N(npcSettings_80247558),
        .pos = { 245.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D04C),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
            NPC_ANIM(disguised_moustafa, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x0098),
    },
    {
        .id = NPC_TOAD,
        .settings = &N(npcSettings_80247584),
        .pos = { -143.0f, 0.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D790),
        .yaw = 180,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(toad, Palette_00, Anim_1),
            NPC_ANIM(toad, Palette_00, Anim_2),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_1),
            NPC_ANIM(toad, Palette_00, Anim_1),
            NPC_ANIM(toad, Palette_00, Anim_6),
            NPC_ANIM(toad, Palette_00, Anim_6),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
            NPC_ANIM(toad, Palette_00, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x009A),
    },
    {
        .id = NPC_WORLD_MERLEE,
        .settings = &N(npcSettings_80248754),
        .pos = { -130.0f, 0.0f, -400.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80247A80),
        .yaw = 180,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_5),
            NPC_ANIM(world_merlee, Palette_00, Anim_6),
            NPC_ANIM(world_merlee, Palette_00, Anim_6),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
            NPC_ANIM(world_merlee, Palette_00, Anim_4),
        },
        .tattle = MESSAGE_ID(0x1A, 0x009B),
    },
    {
        .id = NPC_MOUSTAFA,
        .settings = &N(npcSettings_80247558),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D130),
        .yaw = 0,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_4),
            NPC_ANIM(moustafa, Palette_00, Anim_4),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
            NPC_ANIM(moustafa, Palette_00, Anim_1),
        },
        .tattle = MESSAGE_ID(0x1A, 0x0099),
    },
    {
        .id = NPC_DRYITE1,
        .settings = &N(npcSettings_8024752C),
        .pos = { 25.0f, 0.0f, -38.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BCD4),
        .yaw = 270,
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
        .tattle = MESSAGE_ID(0x1A, 0x009D),
    },
    {
        .id = NPC_DRYITE2,
        .settings = &N(npcSettings_8024752C),
        .pos = { -375.0f, 0.0f, -10.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BD28),
        .yaw = 270,
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
        .tattle = MESSAGE_ID(0x1A, 0x00A0),
    },
    {
        .id = NPC_MOUSER0,
        .settings = &N(npcSettings_80247558),
        .pos = { -50.0f, 0.0f, -470.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BF10),
        .yaw = 180,
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
        .tattle = MESSAGE_ID(0x1A, 0x009E),
    },
    {
        .id = NPC_MOUSER1,
        .settings = &N(npcSettings_80247558),
        .pos = { -270.0f, 0.0f, 91.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024C038),
        .yaw = 270,
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
        .tattle = MESSAGE_ID(0x1A, 0x009F),
    },
    {
        .id = NPC_MOUSER2,
        .settings = &N(npcSettings_80247558),
        .pos = { 210.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D3E8),
        .yaw = 90,
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
    },
    {
        .id = NPC_CHUCK_QUIZMO,
        .settings = &N(npcSettings_802473B0),
        .pos = { -335.0f, 0.0f, 90.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_NO_PROJECT_SHADOW,
        .unk_1C = { 00, 00, 00, 01, 00, 03, 02, 01},
        .yaw = 270,
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
};

NpcGroupList N(npcGroupList_8024EEF4) = {
    NPC_GROUP(N(npcGroup_8024D7B4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_80240300_9694C0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80244DE0_96DFA0) == NULL) {
        N(D_80244DE0_96DFA0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80244DE0_96DFA0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80244DE0_96DFA0)[i];
        }
        heap_free(N(D_80244DE0_96DFA0));
        N(D_80244DE0_96DFA0) = NULL;
    }
    return ApiStatus_DONE2;
}

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

ApiStatus N(func_8024043C_9695FC)(ScriptInstance *script, s32 isInitialCall) {
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
    temp_v0 = get_variable(NULL, SI_SAVE_VAR(0));

    for (i = 0; i < 8; i++) {
        if (temp_v0 < (*(N(quizRequirements) + i)).unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < (*(N(quizRequirements) + i)).unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) || 
        ((gGameStatusPtr->unk_75 != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc31.inc.c"

#include "world/common/GetNpcUnsafeOwner2.inc.c"

#include "world/common/UnkFunc28.inc.c"

#include "world/common/UnkAlphaFunc.inc.c"

#include "world/common/UnkFunc29.inc.c"

ApiStatus N(func_802409EC_969BAC)(ScriptInstance *script, s32 isInitialCall) {
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

ApiStatus N(func_80240A70_969C30)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(D_8024EFC0) = func_800715D0(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        N(D_8024EFC4) = func_80071810(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)));
        N(D_8024EFC8) = func_80072890(0, get_variable(script, SI_ARRAY(1)), get_variable(script, SI_ARRAY(2)), get_variable(script, SI_ARRAY(3)), 1.0f, 0);

        effectPtr = N(D_8024EFC0)->unk_0C;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = N(D_8024EFC0)->unk_0C;

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

ApiStatus N(func_80240C88_969E48)(ScriptInstance *script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(D_8024EFC4)->flags |= 0x10;
        N(D_8024EFC8)->flags |= 0x10;
    }

    effectPtr = N(D_8024EFC0)->unk_0C;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(N(D_8024EFC0), effectPtr);
        free_dynamic_entity(gPauseMenuCursorPosY);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80240D3C_969EFC)(ScriptInstance *script, s32 isInitialCall) {
    ((N(temp)*)N(D_8024EFC0))->unk_0C->unk_34 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240D70_969F30)(ScriptInstance *script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    EffectInstanceDataThing* effectPtr = N(D_8024EFC0)->unk_0C;

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

ApiStatus N(func_80240DF0_969FB0)(ScriptInstance *script, s32 isInitialCall) {
    ((N(temp)*)N(D_8024EFC8))->unk_0C->unk_1C = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240E08_969FC8)(ScriptInstance *script, s32 isInitialCall) {
    ((N(temp)*)N(D_8024EFC8))->unk_0C->unk_1C = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_80240E24_969FE4)(ScriptInstance *script, s32 isInitialCall) {
    ((N(temp)*)N(D_8024EFC8))->unk_0C->unk_1C = 2;
    return ApiStatus_DONE2;
}

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

void N(func_802412F8_96A4B8)(void) {
    s32 var = get_variable(NULL, N(D_8024EFB8));

    if (var == 1) {
        func_80071690(0, 0, 0, 0);
    } else if (var == 2) {
        func_80071690(1, 0, 0, 0);
    }
}

ApiStatus N(func_80241364_96A524)(ScriptInstance *script, s32 isInitialCall) {
    gPauseMenuCursorPosY = create_dynamic_entity_frontUI(NULL, N(func_802412F8_96A4B8));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241394_96A554)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = *args;
    u8 coins1 = N(D_802475E0_9707A0)[var1];
    u8 coins2 = N(D_802475DC_97079C)[var1];

    if (playerData->coins < coins1) {
        set_variable(script, var2, 1);
    } else {
        playerData->coins = playerData->coins - coins1;
        if (playerData->merleeCastsLeft < coins2) {
            playerData->merleeCastsLeft = coins2;
        }
        playerData->merleeTurnCount = rand_int(2) + 1;
        switch (rand_int(3)) {
            case 0:
                playerData->merleeSpellType = 1;
                break;
            case 1:
                playerData->merleeSpellType = 2;
                break;
            case 2:
                playerData->merleeSpellType = 3;
                break;
            case 3:
                playerData->merleeSpellType = 4;
                break;
        }
        set_variable(script, var2, 0);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802414C0_96A680)(ScriptInstance *script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        func_8011D82C(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != 0 && npc->flags != 0 && npc->npcID != -4 && npc->npcID != 4) {
                npc->flags |= 0x800000;
            }
        }
        script->functionTemp[0].s = 0;
    }

    script->functionTemp[0].s += 8;
    if (script->functionTemp[0].s >= 0x100) {
        script->functionTemp[0].s = 255;
    }
    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);

    return (script->functionTemp[0].s == 255) * ApiStatus_DONE2;
}

ApiStatus N(func_802415CC_96A78C)(ScriptInstance *script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        set_background_color_blend(0, 0, 0, 0xFF);
        script->functionTemp[0].s = 255;
        script->functionTemp[1].s = 0;
    }
    script->functionTemp[0].s -= 8;
    if (script->functionTemp[0].s < 0) {
        script->functionTemp[0].s = 0;
    }
    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);

    if ((script->functionTemp[0].s == 0) && (script->functionTemp[1].s == 0)) {
        script->functionTemp[1].s = 1;
    } else if (script->functionTemp[1].s == 1) {
        func_8011D82C(0);
        *D_801512F0 = 0;
        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != -4 && npc->npcID != 4) {
                npc->flags &= 0xFF7FFFFF;
            }
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802416FC_96A8BC)(ScriptInstance *script, s32 isInitialCall) {
    s32 ret;

    N(D_8024EFCC) = script;

    ret = func_8013A704(1);
    func_8013AA9C(ret, 5, 0xF, 1, 1, 0, 0x800);
    set_variable(script, SI_ARRAY(0), ret);
    ret = func_8013A704(1);
    func_8013AA9C(ret, 5, 0x10, 1, 1, 0, 0x800);
    set_variable(script, SI_ARRAY(1), ret);
    ret = func_8013A704(1);
    func_8013AA9C(ret, 5, 0x11, 1, 1, 0, 0x800);
    set_variable(script, SI_ARRAY(2), ret);
    ret = func_8013A704(1);
    func_8013AA9C(ret, 5, 0x12, 1, 1, 0, 0x800);
    set_variable(script, SI_ARRAY(3), ret);

    set_variable(script, SI_ARRAY(7), create_dynamic_entity_world(N(func_8024240C_96B5CC), N(func_80242EAC_96C06C)));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241874_96AA34)(ScriptInstance *script, s32 isInitialCall) {
    func_8013A854(get_variable(script, SI_ARRAY(0)));
    func_8013A854(get_variable(script, SI_ARRAY(1)));
    func_8013A854(get_variable(script, SI_ARRAY(2)));
    func_8013A854(get_variable(script, SI_ARRAY(3)));
    free_dynamic_entity(get_variable(script, SI_ARRAY(7)));
    return ApiStatus_DONE2;
}

//#define NON_MATCHING
#ifdef NON_MATCHING
s32 func_8024190C_96AACC(D_8024F010_Struct* ptr, Matrix4f matrix) {
    Matrix4f subroutine_arg6;
    Matrix4f subroutine_arg16;
    s32 subroutine_arg26;
    s32 subroutine_arg2C;
    s32 subroutine_arg2D;
    s32 subroutine_arg2E;
    s32 subroutine_arg2F;

    if (ptr->unk_00 == 0) {
        return 1;
    }

    gSPDisplayList(gMasterGfxPos++, N(D_802478C8_970A88));

    if ((ptr->unk_00 == 1) || (ptr->unk_00 == 4) || (ptr->unk_00 == 5)) {
        guTranslateF(&subroutine_arg16, ptr->unk_04, ptr->unk_08, ptr->unk_0C);
        guMtxCatF(&subroutine_arg16, matrix, &subroutine_arg6);
        guRotateF(&subroutine_arg16, ptr->unk_10, 0.0f, 1.0f, 0.0f);
        guMtxCatF(&subroutine_arg16, subroutine_arg6, subroutine_arg6);
        guRotateF(&subroutine_arg16, ptr->unk_14, 1.0f, 0.0f, 0.0f);
        guMtxCatF(&subroutine_arg16, subroutine_arg6, subroutine_arg6);
        guMtxF2L(&subroutine_arg6, &gDisplayContext->matrixStack[gMatrixListPos++]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((ptr->unk_00 == 1) || (ptr->unk_00 == 4)) {
            gSPDisplayList(gMasterGfxPos++, N(D_802479B8_970B78));
        }

        if ((ptr->unk_00 == 1) || (ptr->unk_00 == 5)) {
            func_802DE044(&subroutine_arg2C, ptr->unk_18, ptr->unk_1C);

            gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
            gDPLoadTLUT_pal16(gMasterGfxPos++, 0, 0xFFFFFFFF);
            gDPTileSync(gMasterGfxPos++);
            gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync(gMasterGfxPos++);
            gDPLoadTLUTCmd(gMasterGfxPos++, G_TX_LOADTILE, 15);
            gDPPipeSync(gMasterGfxPos++);

            gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, subroutine_arg2E, subroutine_arg2C);
            gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 0, subroutine_arg2E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);

            gDPLoadSync(gMasterGfxPos++);
            gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, subroutine_arg2E, subroutine_arg2F);

            gDPPipeSync(gMasterGfxPos++);
            gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 0, subroutine_arg2E, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 8, G_TX_NOLOD);
            gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, subroutine_arg2E, subroutine_arg2F);

            guTranslateF(&subroutine_arg6, ptr->unk_20 - (subroutine_arg2E / 2) - 30, 0.0f, 0.0f);
            guMtxF2L(&subroutine_arg6, &gDisplayContext->matrixStack[gMatrixListPos++]);
            
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, N(D_80247A38_970BF8));
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        return 1;
    }

    if (ptr->unk_00 == 2) {
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x047C, 0x047C);

        guTranslateF(&subroutine_arg16, N(D_8024F010)[0].unk_04, N(D_8024F010)[0].unk_08, N(D_8024F010)[0].unk_0C);
        guMtxCatF(&subroutine_arg16, matrix, subroutine_arg6);
        guMtxF2L(&subroutine_arg6, &gDisplayContext->matrixStack[gMatrixListPos++]);
        
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        func_8013AF70(get_variable(N(D_8024EFCC), SI_ARRAY(0)), &subroutine_arg26, 0x30, &subroutine_arg6);
        
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

        return 1;
    }

    if (ptr->unk_00 == 3) {
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0x0400, 0x0400, 0x047C, 0x047C);

        guTranslateF(&subroutine_arg16, N(D_8024F010)[0].unk_04, N(D_8024F010)[0].unk_08, N(D_8024F010)[0].unk_0C);
        guMtxCatF(&subroutine_arg16, matrix, &subroutine_arg6);
        guMtxF2L(&subroutine_arg6, &gDisplayContext->matrixStack[gMatrixListPos++]);
        
        gSPMatrix(gMasterGfxPos++, 0xFFFFFFFF, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        func_8013AF70(get_variable(N(D_8024EFCC), SI_ARRAY(1)), &subroutine_arg26, 0x30, &subroutine_arg6);
        func_8013AF70(get_variable(N(D_8024EFCC), SI_ARRAY(2)), &subroutine_arg26, 0x30, &subroutine_arg6);
        
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

        guTranslateF(&subroutine_arg16, N(D_8024F010)[0].unk_04, N(D_8024F010)[0].unk_08, N(D_8024F010)[0].unk_0C);
        guMtxCatF(&subroutine_arg16, matrix, &subroutine_arg6);
        guMtxF2L(&subroutine_arg6, &gDisplayContext->matrixStack[gMatrixListPos++]);
        
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gMatrixListPos++;

        func_802DE044(&subroutine_arg2C, ptr->unk_18, ptr->unk_1C);
        func_8013AF70(get_variable(N(D_8024EFCC), SI_ARRAY(3)), subroutine_arg2C, subroutine_arg2D, subroutine_arg2E, subroutine_arg2F, -(subroutine_arg2E / 2), subroutine_arg2F / 2, 0xFF, &subroutine_arg26, 0x10, &subroutine_arg6);
        
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
    return 1;
}
#else
INCLUDE_ASM(u32, "world/area_dro/dro_02/9694C0", dro_02_func_8024190C_96AACC, D_8024F010_Struct* ptr, Matrix4f matrix);
#endif

void N(func_80242214_96B3D4)(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32* CC_ptr = &N(D_8024EFCC);
    D_8024F010_Struct* F010_ptr;
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;

    guPositionF(&spA0, 0.0f, -CURRENT_CAM->currentYaw, 0.0f, 0.71428573f, get_variable(*CC_ptr, SI_ARRAY(4)), get_variable(*CC_ptr, SI_ARRAY(5)), get_variable(*CC_ptr, SI_ARRAY(6)));
    
    F010_ptr = ({ D_8024F010_Struct* a = &N(D_8024F010); &a[arg0]; });
    guTranslateF(&sp60, F010_ptr->unk_04, F010_ptr->unk_08, F010_ptr->unk_0C);
    guMtxCatF(&sp60, &spA0, &sp20);
    guRotateF(&sp60, F010_ptr->unk_10, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp60, &sp20, &sp20);
    guTranslateF(&sp60, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp60, &sp20, &sp20);
    *arg1 = sp20[3][0];
    *arg2 = sp20[3][1];
    *arg3 = sp20[3][2];
    *arg4 = clamp_angle(F010_ptr->unk_10);
}

// Too much work, maybe try again later
#ifdef NON_MATCHING
void func_8024240C_96B5CC(ScriptInstance *script, s32 isInitialCall) {
    N(temp)** effect;
    N(temp)** effect2;
    N(temp)** effect3;
    EffectInstanceDataThing* effectPtr;
    s32 var = get_variable(N(D_8024EFCC), SI_ARRAY(9));
    s32 i, j, x;
    f32 subroutine_arg6;
    f32 subroutine_arg7;
    f32 subroutine_arg8;
    f32 subroutine_arg9;

    f32 subroutine_argA;
    f32 subroutine_argB;
    f32 subroutine_argC;
    f32 subroutine_argD;

    f32 subroutine_argE;
    f32 subroutine_argF;
    f32 subroutine_arg10;
    f32 subroutine_arg11;

    f32 subroutine_arg12;
    f32 subroutine_arg13;
    f32 subroutine_arg14;
    f32 subroutine_arg15;

    f32 subroutine_arg16;
    f32 subroutine_arg17;
    f32 subroutine_arg18;
    f32 subroutine_arg19;
    
    f32 subroutine_arg1A;
    f32 subroutine_arg1B;
    f32 subroutine_arg1C;
    f32 subroutine_arg1D;

    D_8024F010_Struct* ptr;
    s32* ptr2;
    s32* ptr3;
    s32* ptr4;
    s32* ptr5;
    s32* ptr6;
    s32* ptr7;
    s32* ptr8;
    s32* ptr9;
    s32* ptr10;
    f32* ptr11;
    D_8024F010_Struct* ptr12;

    f32 testf1;
    f32 testf2;

    switch (var) {
        case 0:
            N(D_8024EF88) = 0;
            set_variable(N(D_8024EFCC), SI_ARRAY(9), 1);
            
            N(D_8024F010)[0].unk_00 = 1;
            N(D_8024F010)[0].unk_04 = -200.0f;
            N(D_8024F010)[0].unk_08 = 0;
            N(D_8024F010)[0].unk_0C = 0;
            N(D_8024F010)[0].unk_14 = 0;
            N(D_8024F010)[0].unk_10 = 0;
            N(D_8024F010)[0].unk_18 = 1;
            N(D_8024F010)[0].unk_1C = 0xC;
            N(D_8024F010)[0].unk_20 = 2;

            N(D_8024F010)[1].unk_00 = 1;
            N(D_8024F010)[1].unk_04 = 200.0f;
            N(D_8024F010)[1].unk_08 = 0;
            N(D_8024F010)[1].unk_0C = 1.0f;
            N(D_8024F010)[1].unk_14 = 0;
            N(D_8024F010)[1].unk_10 = 0;
            N(D_8024F010)[1].unk_18 = 1;
            N(D_8024F010)[1].unk_1C = 0x30;
            N(D_8024F010)[1].unk_20 = 0;

            N(D_8024F010)[2].unk_00 = 1;
            N(D_8024F010)[2].unk_04 = 0;
            N(D_8024F010)[2].unk_08 = 200.0f;
            N(D_8024F010)[2].unk_0C = 2.0f;
            N(D_8024F010)[2].unk_14 = 0;
            N(D_8024F010)[2].unk_10 = 0;
            N(D_8024F010)[2].unk_18 = 8;
            N(D_8024F010)[2].unk_1C = 5;
            N(D_8024F010)[2].unk_20 = 4;
            break;

        case 1:
            N(D_8024F010)[0].unk_04 += 10.0f;
            N(D_8024F010)[1].unk_04 += -10.0f;
            N(D_8024F010)[2].unk_08 += -10.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 0x12) {
                gPlayerStatus.position.y = -1000.0f;
            }
            if (N(D_8024EF88) == 0x14) {
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 2);
                N(D_8024EF88) = 0;
            }
            break;

        case 2:
            N(D_8024F010)[0].unk_00 = 2;
            N(D_8024F010)[1].unk_00 = 0;
            N(D_8024F010)[2].unk_00 = 0;
            N(D_8024F010)[0].unk_04 = 0;
            N(D_8024F010)[0].unk_08 = 0;
            N(D_8024F010)[0].unk_0C = 0;
            break;

        case 3:
            N(D_8024F010)[0].unk_00 = 1;
            N(D_8024F010)[1].unk_00 = 1;
            N(D_8024F010)[2].unk_00 = 1;
            N(D_8024F010)[0].unk_04 -= 10.0f;
            N(D_8024F010)[1].unk_04 += 10.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 4);
            }
            break;

        case 4:
            N(D_8024F010)[0].unk_08 = 0;
            N(D_8024F010)[0].unk_0C = 0;
            N(D_8024F010)[1].unk_08 = 0;
            N(D_8024F010)[2].unk_04 = 0;
            N(D_8024F010)[2].unk_08 = 0;
            N(D_8024F010)[0].unk_04 = -100.0f;
            N(D_8024F010)[1].unk_04 = 100.0f;
            N(D_8024F010)[1].unk_0C = 1.0f;
            N(D_8024F010)[2].unk_0C = 2.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 0x14) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 5);
                sfx_play_sound_with_params(0x203, 0, 0x18, 0);
            }
            break;

        case 5:
            N(D_8024F010)[1].unk_10 = 0;
            N(D_8024F010)[2].unk_10 = 0;
            N(D_8024F010)[0].unk_10 += 18.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 8) {
                N(func_80242214_96B3D4)(0, &subroutine_arg6, &subroutine_arg7, &subroutine_arg8, &subroutine_arg9);
                func_8006FEF0(0, subroutine_arg6, subroutine_arg7 + 20.0f, subroutine_arg8, 30.0f);
            }
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 6);
                sfx_play_sound_with_params(0x203, 0, 0x40, 0);
            }
            break;

        case 6:
            N(D_8024F010)[1].unk_10 = 0;
            N(D_8024F010)[0].unk_10 += 18.0f;
            N(D_8024F010)[2].unk_10 += 18.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 8) {
                N(func_80242214_96B3D4)(2, &subroutine_argA, &subroutine_argB, &subroutine_argC, &subroutine_argD);
                func_8006FEF0(0, subroutine_argA, subroutine_argB + 20.0f, subroutine_argC, 30.0f);
            }
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 7);
                sfx_play_sound_with_params(0x203, 0, 0x68, 0);
            }
            break;

        case 7:
            N(D_8024F010)[0].unk_10 = 0;
            N(D_8024F010)[1].unk_10 += 18.0f;
            N(D_8024F010)[2].unk_10 += 18.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 8) {
                N(func_80242214_96B3D4)(1, &subroutine_argE, &subroutine_argF, &subroutine_arg10, &subroutine_arg11);
                func_8006FEF0(0, subroutine_argE, subroutine_argF + 20.0f, subroutine_arg10, 30.0f);
            }
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 8);
            }
            break;

        case 8:
            N(D_8024F010)[0].unk_10 = 0;
            N(D_8024F010)[2].unk_10 = 0;
            N(D_8024F010)[1].unk_10 += 18.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 9);
            }
            break;

        case 9:
            N(D_8024F010)[0].unk_08 = 0;
            N(D_8024F010)[0].unk_10 = 0;
            N(D_8024F010)[1].unk_08 = 0;
            N(D_8024F010)[1].unk_10 = 0;
            N(D_8024F010)[2].unk_04 = 0;
            N(D_8024F010)[2].unk_08 = 0;
            N(D_8024F010)[2].unk_10 = 0;
            N(D_8024F010)[0].unk_04 += 10.0f;
            N(D_8024F010)[1].unk_04 -= 10.0f;
            N(D_8024EF88)++;
            if (N(D_8024EF88) == 0xA) {
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 10);
            }
            break;

        case 10:
            N(D_8024F010)[0].unk_00 = 3;
            N(D_8024F010)[0].unk_18 = 8;
            N(D_8024F010)[1].unk_00 = 0;
            N(D_8024F010)[2].unk_00 = 0;
            N(D_8024F010)[0].unk_1C = 0x11;
            return;

        case 11:
            N(D_8024F010)[0].unk_00 = 4;
            N(D_8024F010)[1].unk_00 = 5;
            N(D_8024F010)[1].unk_18 = 8;
            N(D_8024F010)[0].unk_04 = 0;
            N(D_8024F010)[0].unk_0C = 0;
            N(D_8024F010)[1].unk_04 = 0;
            N(D_8024F010)[1].unk_0C = 0;
            N(D_8024F010)[1].unk_1C = 0xA;
            N(D_8024F010)[1].unk_20 = 0;
            N(D_8024EF88) = 0;
            N(D_8024F010)[0].unk_08 = 68.0f;
            N(D_8024F010)[0].unk_10 = 180.0f;
            N(D_8024F010)[1].unk_08 = 68.0f;
            N(D_8024F010)[1].unk_10 = 180.0f;
            set_variable(N(D_8024EFCC), SI_ARRAY(9), 0xC);
            gPauseMenuTabs[0].unk_00 = 0;
            N(D_8024EF84) = 1.0f;
            N(func_80242214_96B3D4)(1, &subroutine_arg12, &subroutine_arg13, &subroutine_arg14, &subroutine_arg15);
            
            effect = &N(D_8024EF90);
            for (i = 0; i < 4; i++) {
                (*effect) = func_800720B0(2, subroutine_arg12, subroutine_arg13 + 20.0f, subroutine_arg14, 8.0f, -1);

                (*effect)->unk_0C->unk_28 = 0xD7;
                (*effect)->unk_0C->unk_2C = 0x37;
                (*effect)->unk_0C->unk_30 = 0xFF;
                effect++;

                j = 1;
                while (j < (*effect)->unk_08) {
                    (*effect)->unk_0C->unk_48->unk_38[j++] *= 0.1;
                }
            }
            break;

        case 12: {
            MenuTab* menuTabs;
            s32 y;

            N(func_80242214_96B3D4)(1, &subroutine_arg16, &subroutine_arg17, &subroutine_arg18, &subroutine_arg19);
            for (y = 0; y < 4; y++) {
                N(D_8024EF90)[y]->unk_0C->unk_04 = subroutine_arg16;
                N(D_8024EF90)[y]->unk_0C->unk_08 = subroutine_arg17 + 20.0f;
                N(D_8024EF90)[y]->unk_0C->unk_0C = subroutine_arg18;
                N(D_8024EF90)[y]->unk_0C->unk_34 -= 0.1;
                if (N(D_8024EF90)[y]->unk_0C->unk_34 < 0.1) {
                    N(D_8024EF90)[y]->unk_0C->unk_34 = 0.1f;
                }

                j = 1;
                while (j < N(D_8024EF90)[y]->unk_08) {
                    N(temp)** eff2 = &N(D_8024EF90)[y];

                    (*eff2)->unk_0C->unk_48->unk_38[j++] += 0.01;
                }
            }

            N(D_8024F010)[0].unk_08 += gPauseMenuTabs[0].unk_00;
            N(D_8024F010)[1].unk_08 += N(D_8024EF84);
            gPauseMenuTabs[0].unk_00 += 0.4;
            N(D_8024EF84) -= 0.05;
            N(D_8024EF88)++;
            if (N(D_8024F010)[1].unk_08 < -5.0f) {
                N(D_8024F010)[1].unk_08 = -5.0f;
                N(D_8024EF88) = 0;
                set_variable(N(D_8024EFCC), SI_ARRAY(9), 0xD);
                N(D_8024F010)[0].unk_00 = 0;
                N(D_8024F010)[1].unk_00 = 0;
                N(func_80242214_96B3D4)(1, &subroutine_arg1A, &subroutine_arg1B, &subroutine_arg1C, &subroutine_arg1D);
                func_8006FEF0(0, subroutine_arg1A, subroutine_arg1B + 20.0f, subroutine_arg1C, 30.0f);
                sfx_play_sound(0x206);
                for (x = 0; x < 4; x++) {
                    N(D_8024EF90)[x]->flags |= 0x10;
                }
            }
            break;
        }

        case 13:
            break;
    }
}
#else
INCLUDE_ASM(void, "world/area_dro/dro_02/9694C0", dro_02_func_8024240C_96B5CC, ScriptInstance *script, s32 isInitialCall);
#endif

void N(func_80242EAC_96C06C)(ScriptInstance *script, s32 isInitialCall) {
    Matrix4f sp20;
    u32 temp_s1;

    guPositionF(&sp20, 0.0f, -CURRENT_CAM->currentYaw, 0.0f, 0.71428573f, get_variable(N(D_8024EFCC), SI_ARRAY(4)), get_variable(N(D_8024EFCC), SI_ARRAY(5)), get_variable(N(D_8024EFCC), SI_ARRAY(6)));
    
    temp_s1 = func_8024190C_96AACC(&N(D_8024F010)[0], &sp20);
    func_8024190C_96AACC(&N(D_8024F010)[1], &sp20);
    func_8024190C_96AACC(&N(D_8024F010)[2], &sp20);
    if ((N(D_8024F010)[0].unk_00 == 2) && ((temp_s1 - 1) < 2)) {
        set_variable(N(D_8024EFCC), SI_ARRAY(9), 3);
    }
    if ((N(D_8024F010)[0].unk_00 == 3) && ((temp_s1 - 1) < 2)) {
        set_variable(N(D_8024EFCC), SI_ARRAY(9), 0xB);
    }
}

ApiStatus N(func_8024303C_96C1FC)(ScriptInstance *script, s32 isInitialCall) {
    sfx_play_sound_with_params(0x202A, 0, 0x18, 0);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80243068_96C228)(ScriptInstance *script, s32 isInitialCall) {
    sfx_play_sound_with_params(0x202B, 0, 0x68, 0);
    return ApiStatus_DONE2;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_802432C0_96C480)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80248780_971940) = 0;
    }

    if (N(D_80248780_971940) != NULL) {
        N(D_80248780_971940) = 0;
        set_variable(script, *args, N(D_80248784_971944));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80243314_96C4D4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    N(D_80248784_971944) = get_variable(script, *args);
    N(D_80248780_971940) = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024334C_96C50C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_8024F080)[i] = ptr[i];
        }
        N(D_8024F080)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_8024F080)[i] = i + 16;
            N(D_8024F080)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_802433E8_96C5A8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_8024F248)[i] = ptr[i];
        }
        N(D_8024F248)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_8024F248)[i] = i + 128;
            N(D_8024F248)[0x5B] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

#include "world/common/UnkFunc32.inc.c"

#include "world/common/UnkFunc33.inc.c"

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

#include "world/common/UnkFunc34.inc.c"

#include "world/common/UnkFunc35.inc.c"

#include "world/common/GetPartnerCall800EB168.inc.c"

#include "world/common/UnkFunc36.inc.c"

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

ApiStatus N(func_802439FC_96CBBC)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    N(D_8024F3B8) = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}

ApiStatus N(func_80243A40_96CC00)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = N(D_8024F3B8);
    return ApiStatus_DONE2;
}
