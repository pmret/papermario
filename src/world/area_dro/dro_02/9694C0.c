#include "dro_02.h"
#include "effects.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/archeologist.h"
#include "sprite/npc/chuck_quizmo.h"
#include "sprite/npc/disguised_moustafa.h"
#include "sprite/npc/dryite.h"
#include "sprite/npc/mouser.h"
#include "sprite/npc/moustafa.h"
#include "sprite/npc/toad.h"
#include "sprite/npc/world_merlee.h"
#include "sprite/npc/world_parakarry.h"

#define CHUCK_QUIZMO_NPC_ID 10

extern s16 MessagePlural;
extern s16 MessageSingular;

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
static EffectInstance* N(D_8024EF90)[4]; // possibly bigger?
static s32 N(Quizmo_Worker);
static s32 N(pad_D_8024EFA4);
static s32 N(Quizmo_ScriptArray)[4];
static s32 N(Quizmo_AnswerResult);
static s8 N(pad_D_8024EFBC)[0x4];
static EffectInstance* N(Quizmo_StageEffect);
static EffectInstance* N(Quizmo_AudienceEffect);
static EffectInstance* N(Quizmo_VannaTEffect);
static Evt* N(D_8024EFCC);
static s32 N(D_8024EFD0)[16];
static D_8024F010_Struct N(D_8024F010)[3];
static s8 N(pad_D_8024F07C)[0x4];
static s32 N(KeyItemChoiceList)[ITEM_NUM_KEYS + 2];
static s32 N(ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1]; // extra entry for list terminator
static s32 N(LetterDelivery_SavedNpcAnim);

// DATA

EntryList N(entryList) = {
    { -473.0f, 0.0f, 12.0f, 90.0f },
    { 415.0f, 35.0f, -15.0f, 180.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_dro_02 },
};

EvtScript N(80243AF0) = {
    EVT_CMD(EVT_OP_CALL, EVT_PTR(GetEntryID), LVar0),
    EVT_CMD(EVT_OP_SWITCH, LVar0),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 2),
        EVT_CMD(EVT_OP_CASE_OR_EQ, 3),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
        EVT_CMD(EVT_OP_CASE_DEFAULT),
            EVT_CMD(EVT_OP_CALL, EVT_PTR(SetMusicTrack), 0, 21, 0, 8),
        EVT_CMD(EVT_OP_END_CASE_GROUP),
    EVT_CMD(EVT_OP_END_SWITCH),
    EVT_CMD(EVT_OP_RETURN),
    EVT_CMD(EVT_OP_END)
};

EvtScript N(80243B70) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243B9C) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MOUSTAFA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3BC8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_LETTER08, -135, 160, -245, 17, GF_DRO02_Item_Letter08)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 180, 173, -200, 0, 32, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_DRO02_HiddenPanel)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3C3C) = {
    0x00000000,
};

EvtScript N(exitWalk_80243C40) = EXIT_WALK_SCRIPT(60,  0, "dro_01",  1);

EvtScript N(80243C9C) = {
    EVT_BIND_TRIGGER(N(exitWalk_80243C40), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243CC8) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017C, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243D10) = {
    EVT_CALL(PlaySound, 0x80000060)
    EVT_CALL(UseSettingsFrom, 0, 190, 0, -37)
    EVT_CALL(SetPanTarget, 0, 190, 0, -37)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(13.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(N(UnkFunc27), 2, 0, 3)
    EVT_CALL(N(UnkFunc27), 1, -1, 3)
    EVT_CALL(N(UnkFunc26), 3, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 300, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_CALL(GotoMap, EVT_PTR("sbk_02"), 6)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("sbk_02"), 7)
        EVT_END_IF
        EVT_WAIT(100)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 9)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024EEF4)))
    EVT_CALL(InitVirtualEntityList)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC_WAIT(N(80244C78))
    EVT_EXEC(N(80243AF0))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(N(80243D10))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(80243C9C)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(SetTexPanner, 162, 1)
        EVT_SET(LVar0, 0)
        EVT_LABEL(123)
        EVT_ADD(LVar0, 420)
        EVT_IF_GT(LVar0, 65536)
            EVT_ADD(LVar0, -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(123)
    EVT_END_THREAD
    EVT_SET(MapFlag(0), 0)
    EVT_BIND_TRIGGER(N(80243CC8), TRIGGER_WALL_PRESS_A, 56, 1, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar2, -200)
                EVT_CALL(EnableGroup, 163, 1)
            EVT_ELSE
                EVT_CALL(EnableGroup, 163, 0)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.333984375))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_41B4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(802441C0) = {
    EVT_LABEL(9)
    EVT_CALL(MakeLerp, 10, -10, 30, 10)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 48, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeLerp, -10, 10, 30, 10)
    EVT_LABEL(11)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 48, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(802442F0) = {
    EVT_DIV(LVar0, 2)
    EVT_ADD(LVar0, 18)
    EVT_CALL(RotateModel, 21, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(openDoor_80244340) = {
    EVT_CALL(RotateModel, 108, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, 110, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_80244390) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, 104, 0, LVar1, 0)
    EVT_CALL(TranslateModel, 105, 0, LVar1, 0)
    EVT_CALL(TranslateModel, 106, 0, LVar1, 0)
    EVT_CALL(RotateModel, 104, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 105, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 106, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(dropDoor_80244474) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, 108, 0, LVar1, 0)
    EVT_CALL(TranslateModel, 110, 0, LVar1, 0)
    EVT_CALL(RotateModel, 108, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 110, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(openDoor_8024451C) = {
    EVT_CALL(RotateModel, 62, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024454C) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(RotateGroup, 61, LVar0, 0, 0, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024459C) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
        EVT_CASE_EQ(3)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.333984375))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_80244600) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 87, 1)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 87, 0)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.333984375))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_8024468C) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 132, 1)
            EVT_CALL(SetCamType, 0, 0, 0)
            EVT_CALL(SetCamDistance, 0, 260)
            EVT_CALL(SetCamPitch, 0, 22, -13)
            EVT_CALL(SetCamPosA, 0, 0, 290)
            EVT_CALL(SetCamPosB, 0, 0, -290)
            EVT_CALL(SetCamPosC, 0, 0, 0)
            EVT_CALL(SetPanTarget, 0, -395, 140, -150)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SetPanTarget, 0, -365, 140, -145)
            EVT_CALL(SetCamPitch, 0, 20, -7)
            EVT_CALL(SetCamDistance, 0, 400)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 132, 0)
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.333984375))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8024486C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 230, 10, 20)
    EVT_CALL(ModifyColliderFlags, 0, 8, 0x7FFFFE00)
    EVT_CALL(PlaySoundAtCollider, 8, 449, 0)
    EVT_CALL(MakeLerp, 18, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 21, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 230, -70, 15)
    EVT_CALL(MakeLerp, 80, 18, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 21, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, 8, 450, 0)
    EVT_CALL(ModifyColliderFlags, 1, 8, 0x7FFFFE00)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244A68) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 230, -70, 20)
    EVT_CALL(ModifyColliderFlags, 0, 10, 0x7FFFFE00)
    EVT_CALL(PlaySoundAtCollider, 10, 449, 0)
    EVT_CALL(MakeLerp, 18, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 21, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 230, 10, 15)
    EVT_CALL(MakeLerp, 80, 18, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 21, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, 10, 450, 0)
    EVT_CALL(ModifyColliderFlags, 1, 10, 0x7FFFFE00)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(npcList_80244C64)[] = {
    0x00000002, 0x00000005, 0xFFFFFFFF,
};

s32 N(npcList_80244C70)[] = {
    0x00000003, 0xFFFFFFFF,
};

EvtScript N(80244C78) = {
    EVT_EXEC(N(802441C0))
    EVT_CALL(ParentColliderToModel, 8, 21)
    EVT_IF_GE(GB_StoryProgress, -64)
        EVT_CALL(RotateModel, 21, 18, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, 8)
    EVT_END_IF
    EVT_CALL(MakeDoorAdvanced, 4, EVT_PTR(N(openDoor_80244340)), EVT_PTR(N(moveWalls_80244390)), EVT_PTR(N(dropDoor_80244474)), EVT_PTR(N(toggleVis_8024468C)), 15, 16, 133, EVT_PTR(N(npcList_80244C64)))
    EVT_IF_GE(GB_StoryProgress, -64)
        EVT_BIND_TRIGGER(N(8024486C), TRIGGER_WALL_PRESS_A, 8, 1, 0)
        EVT_BIND_TRIGGER(N(80244A68), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_END_IF
    EVT_CALL(MakeDoorAdvanced, 4101, EVT_PTR(N(openDoor_8024451C)), EVT_PTR(N(moveWalls_8024454C)), 0, EVT_PTR(N(toggleVis_80244600)), 12, 13, 94, EVT_PTR(N(npcList_80244C70)))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(toggleVis_8024468C))
    EVT_EXEC(N(8024459C))
    EVT_EXEC(N(toggleVis_80244600))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4DD4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/atomic/QuizmoData.inc.c"

MobileAISettings N(npcAISettings_80247408) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80247438) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_80247408)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80247458) = {
    .height = 35,
    .radius = 24,
    .ai = &N(npcAI_80247438),
    .level = 99,
    .actionFlags = 0x10,
};

NpcSettings N(npcSettings_80247484) = {
    .height = 42,
    .radius = 24,
    .ai = &N(npcAI_80247438),
    .level = 99,
};

MobileAISettings N(npcAISettings_802474B0) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802474E0) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_802474B0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80247500) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_802474E0),
    .level = 99,
    .actionFlags = 16,
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
    { .v = {{ -24,  2, 0 }, 0, {    0,   60 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{ -22,  0, 0 }, 0, {   85,    0 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{  22,  0, 0 }, 0, { 1963,    0 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{  24,  2, 0 }, 0, { 2048,   60 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{  24, 66, 0 }, 0, { 2048, 1988 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{  22, 68, 0 }, 0, { 1963, 2048 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{ -22, 68, 0 }, 0, {   85, 2048 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
    { .v = {{ -24, 66, 0 }, 0, {    0, 1988 }, { 0xFF, 0xFF, 0xFF, 0xFF }}},
};

Vtx N(D_80247888_970A48)[] = {
    { .v = {{ -30, 68, -2 }, 0, {    0, -160 }, { 0x00, 0x00, 0x00, 0x00 }}},
    { .v = {{  30, 68, -2 }, 0, { 1920, -160 }, { 0x00, 0x00, 0x00, 0x00 }}},
    { .v = {{ -30,  0, -2 }, 0, {    0, 2016 }, { 0x00, 0x00, 0x00, 0x00 }}},
    { .v = {{  30,  0, -2 }, 0, { 1920, 2016 }, { 0x00, 0x00, 0x00, 0x00 }}},
};

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

EvtScript N(init_80247A80) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(npcAI_80247A90) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80247AA0) = {
    EVT_USE_ARRAY(EVT_PTR(N(D_8024EFD0)))
    EVT_SET(ArrayVar(9), 0)
    EVT_CALL(GetNpcPos, 4, ArrayVar(4), ArrayVar(5), ArrayVar(6))
    EVT_ADD(ArrayVar(4), 60)
    EVT_ADD(ArrayVar(6), 0)
    EVT_CALL(PlaySoundAtNpc, 4, 0x201, 0)
    EVT_THREAD
        EVT_CALL(MakeLerp, 720, 0, 60, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 4, 0, LVar0, 0)
            EVT_IF_GT(LVar0, 360)
                EVT_ADD(LVar0, -360)
            EVT_END_IF
            EVT_SWITCH(LVar0)
                EVT_CASE_RANGE(90, 270)
                    EVT_SET(LVar2, 12189697)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar2, 12189698)
            EVT_END_SWITCH
            EVT_CALL(SetNpcAnimation, 4, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, 4, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_merlee_Palette_00_Anim_A)
        EVT_WAIT(200)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_merlee_Palette_00_Anim_9)
        EVT_WAIT(40)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_merlee_Palette_00_Anim_A)
        EVT_WAIT(75)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_merlee_Palette_00_Anim_B)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtNpc, 4, 0x202, 0)
    EVT_SET(LVar0, ArrayVar(5))
    EVT_ADD(LVar0, 25)
    EVT_CALL(PlayEffect, 0x4F, 0, ArrayVar(4), LVar0, ArrayVar(6), 1, -1, 0, 0, 0, 0, 0, 0, 0)
    EVT_SET(ArrayVar(8), LVarF)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(func_802D7B10, ArrayVar(8))
    EVT_END_THREAD
    EVT_CALL(N(func_802414C0_96A680))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(N(func_802416FC_96A8BC))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_EQ(ArrayVar(9), 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(9)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(4)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(4)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(2)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(6)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
        EVT_WAIT(3)
        EVT_CALL(PlaySound, -1342177251)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_IF_GE(ArrayVar(9), 3)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(9)
        EVT_CALL(N(func_8024303C_96C1FC))
        EVT_WAIT(2)
        EVT_CALL(N(func_80243068_96C228))
        EVT_LOOP(0)
            EVT_IF_GE(ArrayVar(9), 10)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(3)
        EVT_CALL(PlaySound, 0x204)
        EVT_LOOP(0)
            EVT_IF_GE(ArrayVar(9), 11)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(15)
        EVT_CALL(PlaySound, 0x205)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_IF_EQ(ArrayVar(9), 13)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, ArrayVar(4), ArrayVar(5), ArrayVar(6))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerPos, ArrayVar(4), ArrayVar(5), ArrayVar(6))
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(N(func_80241874_96AA34))
    EVT_THREAD
        EVT_CALL(N(func_802415CC_96A78C))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(802481D8) = {
    EVT_CALL(GetNpcPos, 4, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 200)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(8.0))
    EVT_CALL(SetCamPitch, 0, 20, -15)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802482A8) = {
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802482F8) = {
    EVT_CALL(func_802D2C14, 1)
    EVT_EXEC_WAIT(N(802481D8))
    EVT_SET(LVar0, 0)
    EVT_IF_EQ(GB_KootFavor_Current, 8)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(GF_HOS06_MerluvleeRequestedCrystalBall, 1)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(GF_DRO01_Gift_CrystalBall, 0)
        EVT_ADD(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00DC)
        EVT_SET(LVar0, 39)
        EVT_SET(LVar1, 1)
        EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
        EVT_CALL(AddKeyItem, ITEM_CRYSTAL_BALL)
        EVT_SET(GF_DRO01_Gift_CrystalBall, 1)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(802482A8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00D6)
    EVT_CALL(ShowChoice, MSG_Choice_0011)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00D7)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(802482A8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00D8)
    EVT_CALL(ShowCoinCounter, 1)
    EVT_CALL(ShowChoice, MSG_Choice_0018)
    EVT_CALL(ShowCoinCounter, 0)
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00D7)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(802482A8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(func_80241394_96A554), LVar0, LVar1)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00D9)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(802482A8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00DA)
    EVT_CALL(SetMusicTrack, 0, SONG_MERLEE_SPELL, 0, 8)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_EXEC_GET_TID(N(80247AA0), LVar9)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(LVar9, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_merlee_Palette_00_Anim_4)
    EVT_CALL(PlayerMoveTo, -100, -370, 8)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_merlee_Palette_00_Anim_7, NPC_ANIM_world_merlee_Palette_00_Anim_4, 0, MSG_CH2_00DB)
    EVT_EXEC(N(80243AF0))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(func_802D2C14, 0)
    EVT_EXEC_WAIT(N(802482A8))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80248754) = {
    .height = 32,
    .radius = 32,
    .otherAI = &N(init_80247A80),
    .onInteract = &N(802482F8),
    .ai = &N(npcAI_80247A90),
    .level = 99,
};

s32 N(ItemChoice_HasSelectedItem) = {
    0x00000000,
};

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80248788) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, 0x50000)
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

EvtScript N(802488CC) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(80248788), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024891C) = {
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

EvtScript N(80248A50) = {
    EVT_CALL(N(BuildItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(8024891C), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

extern Gfx N(D_8024A3B8_973578)[];
extern Vtx vtx_971F98[];

StaticAnimatorNode N(D_80248AA0_971C60) = {
    .displayList = N(D_8024A3B8_973578),
    .vertexStartOffset = 0x02EE,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248ACC_971C8C) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248AA0_971C60),
    .vertexStartOffset = 0x02BC,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248AF8_971CB8) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248ACC_971C8C),
    .vertexStartOffset = 0x028A,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248B24_971CE4) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248AF8_971CB8),
    .vertexStartOffset = 0x0258,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248B50_971D10) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248B24_971CE4),
    .vertexStartOffset = 0x0226,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248B7C_971D3C) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248B50_971D10),
    .vertexStartOffset = 0x01F4,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248BA8_971D68) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248B7C_971D3C),
    .vertexStartOffset = 0x01C2,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248BD4_971D94) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248BA8_971D68),
    .vertexStartOffset = 0x0190,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248C00_971DC0) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248BD4_971D94),
    .vertexStartOffset = 0x015E,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248C2C_971DEC) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248C00_971DC0),
    .vertexStartOffset = 0x012C,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248C58_971E18) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248C2C_971DEC),
    .vertexStartOffset = 0x00FA,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248C84_971E44) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248C58_971E18),
    .vertexStartOffset = 0x00C8,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248CB0_971E70) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248C84_971E44),
    .vertexStartOffset = 0x0096,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248CDC_971E9C) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248CB0_971E70),
    .vertexStartOffset = 0x0064,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248D08_971EC8) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248CDC_971E9C),
    .vertexStartOffset = 0x0032,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248D34_971EF4) = {
    .displayList = N(D_8024A3B8_973578),
    .sibling = &N(D_80248D08_971EC8),
    .vertexStartOffset = 0,
    .vtxList = vtx_971F98,
};

StaticAnimatorNode N(D_80248D60_971F20) = {
    .child = &N(D_80248D34_971EF4),
    .vertexStartOffset = -1,
};

StaticAnimatorNode* N(D_80248D8C_971F4C)[] = {
    &N(D_80248D60_971F20), &N(D_80248D34_971EF4), &N(D_80248D08_971EC8), &N(D_80248CDC_971E9C),
    &N(D_80248CB0_971E70), &N(D_80248C84_971E44), &N(D_80248C58_971E18), &N(D_80248C2C_971DEC),
    &N(D_80248C00_971DC0), &N(D_80248BD4_971D94), &N(D_80248BA8_971D68), &N(D_80248B7C_971D3C),
    &N(D_80248B50_971D10), &N(D_80248B24_971CE4), &N(D_80248AF8_971CB8), &N(D_80248ACC_971C8C),
    &N(D_80248AA0_971C60), 0x00000000,            0x00000000,
};

#include "world/area_dro/dro_02/vtx/971F98.vtx.inc.c"

#include "world/area_dro/dro_02/vtx/9722B8.vtx.inc.c"

extern s32 N(image2)[];

Gfx N(D_8024A3B8_973578)[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPLoadTextureBlock(N(image2), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPVertex(vtx_9722B8, 32, 0),
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
    gsSPVertex(vtx_9722B8, 18, 0),
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

EvtScript N(8024AC14) = {
    EVT_CALL(EnableModel, LVar4, 0)
    EVT_CALL(EnableModel, LVar5, 1)
    EVT_CALL(RotateModel, LVar6, 0, 0, 0, 1)
    EVT_CALL(RotateModel, LVar7, 0, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024AC8C) = {
    EVT_SET(LVar9, LVar7)
    EVT_SET(LVar8, LVar6)
    EVT_SET(LVar7, LVar5)
    EVT_SET(LVar6, LVar4)
    EVT_WAIT(70)
    EVT_CALL(EnableModel, LVar6, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, 1)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, LVar9, LVar0, 0, 0, -1)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024ADE4) = {
    EVT_CALL(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    EVT_EXEC_WAIT(N(8024D434))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVarA, LVar2)
    EVT_SET(LVarB, LVar3)
    EVT_CALL(N(ToadHouse_DoesPlayerNeedSleep))
    EVT_IF_EQ(LVar1, 0)
        EVT_SET(LVar8, LVar0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_toad_Palette_00_Anim_4, NPC_ANIM_toad_Palette_00_Anim_1, 0, LVar8)
    EVT_CALL(ShowChoice, MSG_Choice_0006)
    EVT_WAIT(3)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_toad_Palette_00_Anim_4, NPC_ANIM_toad_Palette_00_Anim_1, 0, LVar9)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_toad_Palette_00_Anim_4, NPC_ANIM_toad_Palette_00_Anim_1, 0, LVarA)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(N(ToadHouse_DisableStatusMenu))
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC(N(8024AC8C))
    EVT_END_IF
    EVT_CALL(N(ToadHouse_PutPartnerAway), LVarA)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(8024D494))
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 60, 0)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(FullyRestoreHPandFP)
        EVT_CALL(FullyRestoreSP)
        EVT_IF_NE(LVar4, 0)
            EVT_EXEC(N(8024AC14))
        EVT_END_IF
        EVT_CALL(N(ToadHouse_GetPartnerBackOut), LVarA)
        EVT_WAIT(45)
        EVT_CALL(MakeLerp, 255, 0, 30, 0)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(105)
    EVT_EXEC_WAIT(N(8024D700))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_toad_Palette_00_Anim_4, NPC_ANIM_toad_Palette_00_Anim_1, 0, LVarB)
    EVT_CALL(N(ToadHouse_ShowStatusMenu))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B18C) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
        EVT_CALL(SetItemPos, LVar0, LVar3, LVar4, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B20C) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, 0x50000)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, 1, 0)
            EVT_EXEC_GET_TID(N(8024B18C), LVarA)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_2)
            EVT_CALL(GetAngleBetweenNPCs, LVar9, -4, LVarB)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
            EVT_CALL(GetNpcPos, LVar9, LVar6, LVar7, LVar8)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
            EVT_IF_LE(LVarB, 180)
                EVT_ADD(LVar6, 20)
            EVT_ELSE
                EVT_ADD(LVar6, -20)
            EVT_END_IF
            EVT_ADD(LVar7, 10)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
            EVT_CALL(NpcJump1, NPC_PARTNER, LVar6, LVar7, LVar8, 20)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(RemoveItemEntity, LVar0)
            EVT_WAIT(20)
            EVT_CALL(GetNpcYaw, -4, LVarA)
            EVT_ADD(LVarA, 180)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
            EVT_WAIT(5)
            EVT_CALL(NpcJump1, NPC_PARTNER, LVar3, LVar4, LVar5, 20)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, LVar9, 0)
            EVT_WAIT(5)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT(5)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B530) = {
    EVT_SET(LVar0, LVarB)
    EVT_SET(LVar1, LVar2)
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(8024B20C), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B5A0) = {
    EVT_SET(LVarC, 0)
    EVT_IF_LT(GB_StoryProgress, -70)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_SaveNpcAnim))
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(FindKeyItem, LVar5, LVar1)
    EVT_IF_EQ(LVar0, 4)
        EVT_IF_NE(LVar1, -1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(PlayerFaceNpc, LVar2, 0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, LVar2, LVarD, LVar0, LVarE)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVarD, LVarE, LVarF)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
            EVT_ADD(LVar0, 10)
            EVT_CALL(NpcJump1, NPC_PARTNER, LVarD, LVar0, LVarF, 10)
            EVT_CALL(SpeakToNpc, -4, 262150, 262145, 0, LVar2, LVar7)
            EVT_CALL(EnablePartnerAI)
            EVT_EXEC_WAIT(N(8024B530))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(-1)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 5, LVar8)
                    EVT_CALL(EnablePartnerAI)
                    EVT_SET(LVarC, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 5, LVar9)
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(SpeakToPlayer, LVar2, LVar3, LVar4, 0, LVarA)
                    EVT_END_IF
                    EVT_CALL(EnablePartnerAI)
                    EVT_IF_NE(LVar6, 0)
                        EVT_SET(LVar0, LVar6)
                        EVT_SET(LVar1, 1)
                        EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
                        EVT_CALL(AddKeyItem, LVar6)
                    EVT_END_IF
                    EVT_SET(LVarC, 2)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_RestoreNpcAnim))
    EVT_RETURN
    EVT_END
};

s32 N(D_8024B898_974A58)[] = {
    0x0000004A, 0x00000000,
};

EvtScript N(8024B8A0) = {
    EVT_CALL(N(LetterDelivery_Init), 1, 9634308, 9634305, 74, 75, 852117, 852118, 852119, 852120, EVT_PTR(N(D_8024B898_974A58)))
    EVT_EXEC_WAIT(N(8024B5A0))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024B8F0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, 1)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_archeologist_Palette_00_Anim_4, NPC_ANIM_archeologist_Palette_00_Anim_1, 0, MSG_CH2_00B2)
            EVT_ELSE
                EVT_SWITCH(AreaByte(3))
                    EVT_CASE_EQ(0)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_archeologist_Palette_00_Anim_4, NPC_ANIM_archeologist_Palette_00_Anim_1, 0, MSG_CH2_00AF)
                        EVT_SET(AreaByte(3), 1)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_archeologist_Palette_00_Anim_4, NPC_ANIM_archeologist_Palette_00_Anim_1, 0, MSG_CH2_00B0)
                        EVT_SET(AreaByte(3), 2)
                    EVT_CASE_EQ(2)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_archeologist_Palette_00_Anim_4, NPC_ANIM_archeologist_Palette_00_Anim_1, 0, MSG_CH2_00B1)
                        EVT_SET(AreaByte(3), 1)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_archeologist_Palette_00_Anim_4, NPC_ANIM_archeologist_Palette_00_Anim_1, 0, MSG_CH2_00B3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024BA50) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024B8F0)))
    EVT_IF_GE(GB_StoryProgress, -52)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024BA9C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutDesert, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MSG_CH2_0091)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MSG_CH2_0092)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MSG_CH2_0093)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_02_Anim_4, NPC_ANIM_dryite_Palette_02_Anim_1, 0, MSG_CH2_0094)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(8024B8A0))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024BBAC) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024BA9C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024BBD0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(3), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MSG_CH2_00A1)
                EVT_SET(AreaFlag(3), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MSG_CH2_00A2)
                EVT_SET(AreaFlag(3), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MSG_CH2_00A3)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MSG_CH2_00A4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024BCD4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024BBD0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024BCF8) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_00_Anim_4, NPC_ANIM_dryite_Palette_00_Anim_1, 0, MSG_CH2_00A0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024BD28) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024BCF8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024BD4C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(4), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00A5)
                EVT_SET(AreaFlag(4), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00A6)
                EVT_SET(AreaFlag(4), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_IF_EQ(AreaFlag(4), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00A7)
                EVT_SET(AreaFlag(4), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00A8)
                EVT_SET(AreaFlag(4), 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AreaFlag(4), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00A9)
                EVT_SET(AreaFlag(4), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00AA)
                EVT_SET(AreaFlag(4), 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024BF10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024BD4C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024BF34) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(5), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00AB)
                EVT_SET(AreaFlag(5), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00AC)
                EVT_SET(AreaFlag(5), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00AD)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_mouser_Palette_00_Anim_5, NPC_ANIM_mouser_Palette_00_Anim_1, 0, MSG_CH2_00AE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024C038) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024BF34)))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C05C) = {
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, 5, 0)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, 5, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C0B8) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 275)
    EVT_CALL(GetNpcPos, 2, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(8.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C1F8) = {
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C248) = {
    EVT_CALL(SetNpcYaw, 5, 270)
    EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_5)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_6)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_moustafa_Palette_00_Anim_7)
    EVT_CALL(SetNpcPos, 5, -335, 163, -260)
    EVT_EXEC(N(80243B9C))
    EVT_CALL(MakeLerp, 0, 80, 30, 5)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_SET(LVar2, -335)
    EVT_SET(LVar3, 163)
    EVT_SUB(LVar2, LVar0)
    EVT_ADD(LVar3, LVar0)
    EVT_CALL(SetNpcPos, 2, LVar2, LVar3, -260)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(SetNpcPos, 2, 0, -1000, -250)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_moustafa_Palette_00_Anim_1)
    EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), FALSE)
    EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_100)), FALSE)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8024C450) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-64)
        EVT_CASE_LT(-63)
            EVT_CALL(SetNpcPos, NPC_SELF, -335, 163, -260)
        EVT_CASE_GE(-63)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, -250)
            EVT_CALL(SetNpcPos, 5, -335, 163, -260)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024C4EC) = {
    EVT_IF_EQ(GF_DRO02_Moustafa_UnusedDialogOverride, 1)
        EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CF)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-64)
            EVT_SET(LVarB, 0)
            EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B4)
            EVT_LABEL(0)
            EVT_CALL(ShowChoice, MSG_Choice_0019)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B6)
                EVT_EXEC(N(8024C1F8))
                EVT_RETURN
            EVT_ELSE
                EVT_CALL(EndSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0)
            EVT_END_IF
            EVT_LABEL(1)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 2)
            EVT_EXEC_WAIT(N(80248A50))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B8)
                    EVT_EXEC(N(8024C1F8))
                    EVT_RETURN
                EVT_CASE_EQ(-1)
                    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B7)
                    EVT_EXEC(N(8024C1F8))
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(GB_DRO02_SheekLemonGiftCount, 0)
                EVT_IF_EQ(LVarA, 156)
                    EVT_SET(GB_DRO02_SheekLemonGiftCount, 1)
                    EVT_SET(GB_DRO02_SheekGiftCount, 10)
                    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BB)
                    EVT_CALL(ShowChoice, MSG_Choice_001C)
                EVT_ELSE
                    EVT_ADD(GB_DRO02_SheekGiftCount, 1)
                    EVT_IF_LE(GB_DRO02_SheekGiftCount, 2)
                        EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B5)
                        EVT_GOTO(0)
                    EVT_END_IF
                    EVT_IF_EQ(GB_DRO02_SheekGiftCount, 3)
                        EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B9)
                        EVT_CALL(ShowChoice, MSG_Choice_001B)
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BA)
                        EVT_CALL(ShowChoice, MSG_Choice_001B)
                        EVT_SET(GB_DRO02_SheekGiftCount, 10)
                    EVT_END_IF
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BA)
                EVT_CALL(ShowChoice, MSG_Choice_001C)
            EVT_END_IF
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BC)
                EVT_CASE_EQ(1)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BD)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutDesert, 1)
                EVT_CASE_EQ(2)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BE)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutRuins, 1)
                EVT_CASE_EQ(3)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00BF)
                EVT_CASE_EQ(4)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C1)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutMoustafa, 1)
                    EVT_SET(LVarB, 1)
            EVT_END_SWITCH
            EVT_SET(GF_DRO02_Sheek_SpokeTo, 1)
            EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C0)
            EVT_CALL(ShowChoice, MSG_Choice_001A)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(EndSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0)
                EVT_GOTO(1)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00B6)
            EVT_END_IF
            EVT_IF_EQ(LVarB, 1)
                EVT_IF_EQ(MapFlag(0), 0)
                    EVT_SET(MapFlag(0), 1)
                    EVT_THREAD
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 50)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C2)
                        EVT_CALL(DisablePlayerInput, FALSE)
                        EVT_SET(MapFlag(0), 0)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
            EVT_EXEC(N(8024C1F8))
        EVT_CASE_LT(-63)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(func_802D2C14, 1)
            EVT_END_THREAD
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
            EVT_CALL(PlayerMoveTo, -391, -260, 0)
            EVT_CALL(InterpPlayerYaw, 90, 3)
            EVT_CALL(SetNpcFlagBits, 2, ((NPC_FLAG_100)), FALSE)
            EVT_EXEC_GET_TID(N(8024C05C), LVarA)
            EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(FadeOutMusic, 0, 500)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutMoustafa, 1)
                EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C3)
                EVT_EXEC_WAIT(N(8024C248))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, 5, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, 5, -425, 140, -206, 20)
                EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_4, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C5)
                EVT_EXEC_WAIT(N(8024C248))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, 5, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, 5, -425, 140, -206, 20)
                EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C6)
            EVT_END_IF
            EVT_CALL(SetNpcJumpscale, 5, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, 5, -337, 140, -200, 20)
            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C7)
            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C8)
            EVT_CALL(SetNpcJumpscale, 5, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, 5, -335, 163, -260, 20)
            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00C9)
            EVT_SET(LVar0, 18)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddKeyItem, ITEM_PULSE_STONE)
            EVT_SET(GB_StoryProgress, -63)
            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CA)
            EVT_KILL_THREAD(LVarA)
            EVT_EXEC(N(80243AF0))
        EVT_CASE_GE(-63)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(-62)
                    EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CB)
                EVT_CASE_GE(-62)
                    EVT_IF_GE(GB_StoryProgress, -56)
                        EVT_IF_EQ(GF_DRO02_Moustafa_HeardAboutDryDryRuins, 0)
                            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CD)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                            EVT_WAIT(15)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
                            EVT_WAIT(30)
                            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CE)
                            EVT_SET(GF_DRO02_Moustafa_HeardAboutDryDryRuins, 1)
                        EVT_ELSE
                            EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00D0)
                        EVT_END_IF
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_moustafa_Palette_00_Anim_5, NPC_ANIM_moustafa_Palette_00_Anim_1, 0, MSG_CH2_00CC)
                    EVT_END_IF
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024D04C) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SetNpcPos, NPC_SELF, 200, 0, -15)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_200000)), TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_disguised_moustafa_Palette_00_Anim_5)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024C450)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024C4EC)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024D130) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024C4EC)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8024D154) = {
    EVT_CALL(InterpNpcYaw, 2, 270, 0)
    EVT_LABEL(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_7)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1)
    EVT_LOOP(50)
        EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_1)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_7)
    EVT_LOOP(50)
        EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_LABEL(20)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_disguised_moustafa_Palette_00_Anim_1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_mouser_Palette_01_Anim_4)
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
    EVT_CALL(EnableNpcBlur, -1, 1)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x174, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -83, 11, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -239, 5, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -371, 5, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -487, 5, 20)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, -66)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024D3E8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024D154)))
    EVT_IF_GE(GB_StoryProgress, -66)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024D434) = {
    EVT_SET(LVar0, 852177)
    EVT_SET(LVar8, 852178)
    EVT_SET(LVar1, 852179)
    EVT_SET(LVar2, 852180)
    EVT_SET(LVar3, 852181)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024D494) = {
    EVT_EXEC(N(80243B70))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -179, -198, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, 0, 4, 0)
        EVT_CALL(SetCamPitch, 0, 95, -61)
        EVT_CALL(SetCamDistance, 0, 108)
        EVT_CALL(SetCamPosA, 0, 202, 62)
        EVT_CALL(SetCamPosB, 0, -89, -141)
        EVT_CALL(SetCamPosC, 0, 0, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -187, -267, 0)
    EVT_CALL(InterpPlayerYaw, 230, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 7, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001D)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(81)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(8024D700) = {
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 0, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -187, 0, -240)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -168, -195, 0)
    EVT_EXEC(N(80243AF0))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024D790) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024ADE4)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024D7B4)[] = {
    {
        .id = NPC_ARCHEOLOGIST,
        .settings = &N(npcSettings_80247484),
        .pos = { -320.0f, 0.0f, -14.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BA50),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .territory = { .temp = { -303, 0, 22, 146, 38, -32767, 1, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_2,
            NPC_ANIM_archeologist_Palette_00_Anim_3,
            NPC_ANIM_archeologist_Palette_00_Anim_3,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
            NPC_ANIM_archeologist_Palette_00_Anim_1,
        },
        .tattle = MSG_NpcTattle_Archeologist,
    },
    {
        .id = NPC_DRYITE0,
        .settings = &N(npcSettings_80247500),
        .pos = { -20.0f, 0.0f, 40.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BBAC),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .territory = { .temp = { -20, 0, 40, 60, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
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
        .tattle = MSG_NpcTattle_DRO_DryiteE,
    },
    {
        .id = NPC_DISGUISED_MOUSTAFA,
        .settings = &N(npcSettings_80247558),
        .pos = { 245.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D04C),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
            NPC_ANIM_disguised_moustafa_Palette_00_Anim_1,
        },
        .tattle = MSG_NpcTattle_Sheek,
    },
    {
        .id = NPC_TOAD,
        .settings = &N(npcSettings_80247584),
        .pos = { -143.0f, 0.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D790),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            NPC_ANIM_toad_Palette_00_Anim_1,
            NPC_ANIM_toad_Palette_00_Anim_2,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_1,
            NPC_ANIM_toad_Palette_00_Anim_1,
            NPC_ANIM_toad_Palette_00_Anim_6,
            NPC_ANIM_toad_Palette_00_Anim_6,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
            NPC_ANIM_toad_Palette_00_Anim_3,
        },
        .tattle = MSG_NpcTattle_DRO_ToadHouseToad,
    },
    {
        .id = NPC_WORLD_MERLEE,
        .settings = &N(npcSettings_80248754),
        .pos = { -130.0f, 0.0f, -400.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80247A80),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_5,
            NPC_ANIM_world_merlee_Palette_00_Anim_6,
            NPC_ANIM_world_merlee_Palette_00_Anim_6,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
            NPC_ANIM_world_merlee_Palette_00_Anim_4,
        },
        .tattle = MSG_NpcTattle_Merlee,
    },
    {
        .id = NPC_MOUSTAFA,
        .settings = &N(npcSettings_80247558),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D130),
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_4,
            NPC_ANIM_moustafa_Palette_00_Anim_4,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
            NPC_ANIM_moustafa_Palette_00_Anim_1,
        },
        .tattle = MSG_NpcTattle_Moustafa,
    },
    {
        .id = NPC_DRYITE1,
        .settings = &N(npcSettings_8024752C),
        .pos = { 25.0f, 0.0f, -38.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BCD4),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_DRO_DryiteF,
    },
    {
        .id = NPC_DRYITE2,
        .settings = &N(npcSettings_8024752C),
        .pos = { -375.0f, 0.0f, -10.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BD28),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_DRO_VisitedShootingStarSummit,
    },
    {
        .id = NPC_MOUSER0,
        .settings = &N(npcSettings_80247558),
        .pos = { -50.0f, 0.0f, -470.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024BF10),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_DRO_CrushingOnMerlee,
    },
    {
        .id = NPC_MOUSER1,
        .settings = &N(npcSettings_80247558),
        .pos = { -270.0f, 0.0f, 91.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024C038),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_DRO_TellsTales,
    },
    {
        .id = NPC_MOUSER2,
        .settings = &N(npcSettings_80247558),
        .pos = { 210.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024D3E8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    },
    {
        .id = NPC_CHUCK_QUIZMO,
        .settings = &N(Quizmo_NpcSettings),
        .pos = { -335.0f, 0.0f, 90.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .initVarCount = 1,
        .initVar = { .value = 0x00030201 },
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
};

NpcGroupList N(npcGroupList_8024EEF4) = {
    NPC_GROUP(N(npcGroup_8024D7B4)),
    {},
};

#include "world/common/atomic/Quizmo.inc.c"

ApiStatus N(func_80241394_96A554)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = *args;
    u8 coins1 = N(D_802475E0_9707A0)[var1];
    u8 coins2 = N(D_802475DC_97079C)[var1];

    if (playerData->coins < coins1) {
        evt_set_variable(script, var2, 1);
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
        evt_set_variable(script, var2, 0);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802414C0_96A680)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != 0 && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != NPC_WORLD_MERLEE) {
                npc->flags |= 0x800000;
            }
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] >= 0x100) {
        script->functionTemp[0] = 255;
    }
    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    return (script->functionTemp[0] == 255) * ApiStatus_DONE2;
}

ApiStatus N(func_802415CC_96A78C)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        set_background_color_blend(0, 0, 0, 0xFF);
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }
    script->functionTemp[0] -= 8;
    if (script->functionTemp[0] < 0) {
        script->functionTemp[0] = 0;
    }
    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    if (script->functionTemp[0] == 0 && script->functionTemp[1] == 0) {
        script->functionTemp[1] = 1;
    } else if (script->functionTemp[1] == 1) {
        mdl_set_all_fog_mode(0);
        *D_801512F0 = 0;
        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != NPC_WORLD_MERLEE) {
                npc->flags &= ~0x00800000;
            }
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802416FC_96A8BC)(Evt* script, s32 isInitialCall) {
    s32 ret;

    N(D_8024EFCC) = script;

    ret = func_8013A704(1);
    fold_update(ret, 5, 0xF, 1, 1, 0, 0x800);
    evt_set_variable(script, ArrayVar(0), ret);
    ret = func_8013A704(1);
    fold_update(ret, 5, 0x10, 1, 1, 0, 0x800);
    evt_set_variable(script, ArrayVar(1), ret);
    ret = func_8013A704(1);
    fold_update(ret, 5, 0x11, 1, 1, 0, 0x800);
    evt_set_variable(script, ArrayVar(2), ret);
    ret = func_8013A704(1);
    fold_update(ret, 5, 0x12, 1, 1, 0, 0x800);
    evt_set_variable(script, ArrayVar(3), ret);

    evt_set_variable(script, ArrayVar(7), create_generic_entity_world(N(func_8024240C_96B5CC), N(func_80242EAC_96C06C)));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80241874_96AA34)(Evt* script, s32 isInitialCall) {
    func_8013A854(evt_get_variable(script, ArrayVar(0)));
    func_8013A854(evt_get_variable(script, ArrayVar(1)));
    func_8013A854(evt_get_variable(script, ArrayVar(2)));
    func_8013A854(evt_get_variable(script, ArrayVar(3)));
    free_generic_entity(evt_get_variable(script, ArrayVar(7)));
    return ApiStatus_DONE2;
}

u32 N(func_8024190C_96AACC)(D_8024F010_Struct*, Matrix4f);
INCLUDE_ASM(u32, "world/area_dro/dro_02/9694C0", dro_02_func_8024190C_96AACC, D_8024F010_Struct* ptr, Matrix4f matrix);

void N(func_80242214_96B3D4)(s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4) {
    D_8024F010_Struct* F010_ptr;
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;

    guPositionF(spA0, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, SPRITE_WORLD_SCALE_F,
                evt_get_variable(N(D_8024EFCC), ArrayVar(4)), evt_get_variable(N(D_8024EFCC), ArrayVar(5)),
                evt_get_variable(N(D_8024EFCC), ArrayVar(6)));

    F010_ptr = &N(D_8024F010)[arg0];
    guTranslateF(sp60, F010_ptr->unk_04, F010_ptr->unk_08, F010_ptr->unk_0C);
    guMtxCatF(sp60, spA0, sp20);
    guRotateF(sp60, F010_ptr->unk_10, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp60, sp20, sp20);
    guTranslateF(sp60, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    *arg1 = sp20[3][0];
    *arg2 = sp20[3][1];
    *arg3 = sp20[3][2];
    *arg4 = clamp_angle(F010_ptr->unk_10);
}

INCLUDE_ASM(void, "world/area_dro/dro_02/9694C0", dro_02_func_8024240C_96B5CC, Evt* script,
            s32 isInitialCall);

void N(func_80242EAC_96C06C)(Evt* script, s32 isInitialCall) {
    Matrix4f sp20;
    u32 temp_s1;

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, SPRITE_WORLD_SCALE_F,
                evt_get_variable(N(D_8024EFCC), ArrayVar(4)), evt_get_variable(N(D_8024EFCC), ArrayVar(5)),
                evt_get_variable(N(D_8024EFCC), ArrayVar(6)));

    temp_s1 = N(func_8024190C_96AACC)(&N(D_8024F010)[0], sp20);
    N(func_8024190C_96AACC)(&N(D_8024F010)[1], sp20);
    N(func_8024190C_96AACC)(&N(D_8024F010)[2], sp20);
    if ((N(D_8024F010)[0].unk_00 == 2) && ((temp_s1 - 1) < 2)) {
        evt_set_variable(N(D_8024EFCC), ArrayVar(9), 3);
    }
    if ((N(D_8024F010)[0].unk_00 == 3) && ((temp_s1 - 1) < 2)) {
        evt_set_variable(N(D_8024EFCC), ArrayVar(9), 0xB);
    }
}

ApiStatus N(func_8024303C_96C1FC)(Evt* script, s32 isInitialCall) {
    sfx_play_sound_with_params(0x202A, 0, 0x18, 0);
    return ApiStatus_DONE2;
}

ApiStatus N(func_80243068_96C228)(Evt* script, s32 isInitialCall) {
    sfx_play_sound_with_params(0x202B, 0, 0x68, 0);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeKeyChoice.inc.c"

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/LetterDelivery.inc.c"
