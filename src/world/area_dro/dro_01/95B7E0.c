#include "dro_01.h"
#include "effects.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/WorldParakarry.h"

#define CHUCK_QUIZMO_NPC_ID 10

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

static s32 N(Quizmo_Worker);
static s8 N(pad_D_8024DFC4)[0x4];
static s32 N(Quizmo_ScriptArray)[4];
static s32 N(Quizmo_AnswerResult);
static s8 N(pad_D_8024DFDC)[0x4];
static EffectInstance* N(Quizmo_StageEffect);
static EffectInstance* N(Quizmo_AudienceEffect);
static EffectInstance* N(Quizmo_VannaTEffect);
static s8 N(pad_D_8024DFEC)[0x4];
static s32 N(KeyItemChoiceList)[112];
static s8 N(pad_D_8024E1B0)[0x4]; // Probably part of the above
static s32 N(LetterDelivery_SavedNpcAnim);

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

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_dro_01 },
};

EvtScript N(80243BB0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
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

#include "world/common/atomic/PipeData.inc.c"

EvtScript N(exitWalk_80244960) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, 0)
    EVT_CALL(UseExitHeading, 60, 0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sbk_36"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_802449CC) = EVT_EXIT_WALK(60,  1, "dro_02",  0);

EvtScript N(80244A28) = {
    EVT_BIND_TRIGGER(N(exitWalk_80244960), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802449CC), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80244A70) = {
    EVT_CALL(PlaySound, 0x80000060)
    EVT_CALL(UseSettingsFrom, 0, 175, 0, -201)
    EVT_CALL(SetPanTarget, 0, 175, 0, -201)
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
        EVT_IF_EQ(LVar0, 3)
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), 2)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), 3)
        EVT_END_IF
        EVT_WAIT(100)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_80244C14) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(80244A28))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
            EVT_IF_EQ(GF_DRO01_WarpPipe, 0)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerPos, LVar0, -1000, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_208E)
                EVT_SET(GF_DRO01_WarpPipe, 1)
                EVT_WAIT(30)
                EVT_CALL(SetPlayerActionState, 0)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(LVarA, EVT_PTR(N(80244A28)))
            EVT_EXEC_WAIT(N(Pipe_EnterVertical))
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_EXEC_WAIT(N(80244A70))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(10)
            EVT_EXEC(0x80285C50)
            EVT_EXEC(N(80244A28))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(80244A28)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
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
    EVT_SET(GF_MAP_DryDryOutpost, 1)
    EVT_IF_LT(GB_StoryProgress, -68)
        EVT_SET(GB_StoryProgress, -68)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
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
    EVT_WAIT(1)
    EVT_EXEC(N(8024DD78))
    EVT_RETURN
    EVT_END
};

s32 N(pad_5004)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

MobileAISettings N(npcAISettings_80245010) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80245040) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_80245010)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80245060) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_80245040),
    .level = 99,
    .actionFlags = 16,
};

MobileAISettings N(npcAISettings_8024508C) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802450BC) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_8024508C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802450DC) = {
    .height = 26,
    .radius = 23,
    .ai = &N(npcAI_802450BC),
    .level = 99,
    .actionFlags = 16,
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

#include "world/common/atomic/QuizmoData.inc.c"

s32 N(D_802477E0_9629E0) = {
    0x00000000,
};

s32 N(D_802477E4_9629E4) = {
    0x00000000,
};

EvtScript N(802477E8) = {
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
    EVT_CALL(N(func_80242784_95D984), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(8024792C) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(802477E8), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024797C) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        EVT_CALL(N(LetterDelivery_CalcLetterPos), LVar3, LVar4, LVar5)
        EVT_CALL(SetItemPos, LVar0, LVar3, LVar4, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802479FC) = {
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
            EVT_EXEC_GET_TID(N(8024797C), LVarA)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Walk)
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
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldParakarry_Idle)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, LVar9, 0)
            EVT_WAIT(5)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT(5)
    EVT_END_SWITCH
    EVT_CALL(N(func_80242784_95D984), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80247D20) = {
    EVT_SET(LVar0, LVarB)
    EVT_SET(LVar1, LVar2)
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(802479FC), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80247D90) = {
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
            EVT_EXEC_WAIT(N(80247D20))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(-1)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar8)
                    EVT_CALL(EnablePartnerAI)
                    EVT_SET(LVarC, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, LVar9)
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

s32 N(D_80248088_963288)[] = {
    ITEM_LETTER19, ITEM_NONE
};

EvtScript N(80248090) = {
    EVT_CALL(N(LetterDelivery_Init), 6, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 76, 69,
        MSG_CH2_0089, MSG_CH2_008A, MSG_CH2_008B, MSG_CH2_008C, EVT_PTR(N(D_80248088_963288)))
    EVT_EXEC_WAIT(N(80247D90))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802480E0) = {
    EVT_IF_GE(GB_StoryProgress, -53)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0062)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(AreaByte(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_005F)
            EVT_ADD(AreaByte(0), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0060)
            EVT_ADD(AreaByte(0), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_0061)
            EVT_SUB(AreaByte(0), 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802481F8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802480E0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024821C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_GE(GB_StoryProgress, -64)
                EVT_IF_EQ(AreaByte(1), 2)
                    EVT_SET(AreaByte(1), 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SWITCH(AreaByte(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0063)
                    EVT_ADD(AreaByte(1), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0064)
                    EVT_ADD(AreaByte(1), 1)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0065)
                    EVT_SET(AreaByte(1), 0)
            EVT_END_SWITCH
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0066)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 0, MSG_CH2_0067)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802483A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024821C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802483CC) = {
    EVT_SWITCH(AreaByte(2))
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0068)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0069)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006A)
            EVT_ADD(AreaByte(2), 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_006B)
            EVT_SET(AreaByte(2), 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802484E0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802483CC)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80248504) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, 8)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, 3, 0)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0078)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, 3, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(-300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0079)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007A)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(N(func_80243084_95E284))
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

Unk_Struct_2 N(D_8024884C_963A4C) = {
    0x0000007D, 0x00000000, 0xFFFFFFD6, 0x0000004B, 0x0000004B, N(func_802430C8_95E2C8),
};

EvtScript N(interact_80248864) = {
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, 1)
        EVT_IF_EQ(GF_DRO01_HeardHintAboutSpinningRoof, 1)
            EVT_CALL(N(func_802431B4_95E3B4))
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_007B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(1), 0)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006C)
                EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006D)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006E)
                EVT_SET(AreaFlag(1), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_006F)
                EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0070)
                EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0071)
                EVT_SET(AreaFlag(1), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0072)
            EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0073)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0074)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0075)
            EVT_CALL(SpeakToPlayer, 4, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0076)
            EVT_CALL(SpeakToPlayer, 3, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_0077)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80248AE4) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248864)))
    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, 1)
        EVT_THREAD
            EVT_CALL(N(func_80242858_95DA58), EVT_PTR(N(D_8024884C_963A4C)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80248BA0) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFaceNpc, 3, 4, 1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_802431FC_95E3FC))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.5))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
    EVT_WAIT(5)
    EVT_CALL(GetNpcYaw, -1, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80248CC8) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Dryite_Green_Talk)
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

EvtScript N(interact_80248D54) = {
    EVT_IF_EQ(GF_DRO01_Gift_Melody, 1)
        EVT_CALL(FindKeyItem, ITEM_MELODY, LVar0)
        EVT_IF_NE(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0084)
            EVT_RETURN
        EVT_ELSE
            EVT_IF_EQ(GF_DRO01_Gift_ToldComposerAboutMelody, 0)
                EVT_IF_LT(GB_StoryProgress, 88)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0085)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
                    EVT_WAIT(30)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0086)
                    EVT_SET(GF_DRO01_Gift_ToldComposerAboutMelody, 1)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-53)
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007C)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007D)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
        EVT_CASE_LT(39)
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007E)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007F)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AreaFlag(2), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0080)
                EVT_SET(AreaFlag(2), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0081)
                EVT_SET(AreaFlag(2), 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(LVar0, EVT_PTR(N(D_80248D4C_963F4C)))
    EVT_SET(LVar1, 5)
    EVT_EXEC_WAIT(N(8024792C))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0082)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Write)
            EVT_WAIT(60)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Idle)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0083)
            EVT_SET(LVar0, 104)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddKeyItem, ITEM_MELODY)
            EVT_SET(GF_DRO01_Gift_Melody, 1)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80249168) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80248D54)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8024918C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-67)
            EVT_CALL(N(func_80243350_95E550), 16, 190, -134, -131)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -180)
            EVT_EXEC_WAIT(N(8024C41C))
            EVT_WAIT(10)
            EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, 0, 32, 0, -67)
            EVT_CALL(SetCamDistance, 0, -210)
            EVT_CALL(SetCamPitch, 0, 20, -12)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_WAIT(20)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetCamDistance, 0, -350)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.8))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, -23, -105, 20)
            EVT_WAIT(10)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 65, 0)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(8024C4C8))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 37, -27, 20)
            EVT_CALL(UseSettingsFrom, 0, LVarA, LVarB, LVarC)
            EVT_CALL(SetPanTarget, 0, 142, 0, -67)
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 62, -6, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 103, 11, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 554, -12, 20)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_WAIT(30)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, 0, 0, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(GB_StoryProgress, -67)
        EVT_CASE_LT(-66)
        EVT_CASE_LT(-65)
            EVT_CALL(EnableNpcBlur, -1, 1)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, 372, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, 470, 0, 18)
            EVT_CALL(NpcMoveTo, NPC_SELF, 287, 9, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, 102, -14, 20)
            EVT_CALL(NpcMoveTo, NPC_SELF, -32, -96, 20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(8024C41C))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
            EVT_CALL(NpcMoveTo, NPC_SELF, 20, -375, 30)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_EXEC_WAIT(N(8024C4C8))
            EVT_CALL(EnableNpcBlur, -1, 0)
            EVT_SET(GB_StoryProgress, -65)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
            EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -375)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249750) = {
    EVT_IF_EQ(AreaByte(4), 4)
        EVT_IF_EQ(AreaByte(5), 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
            EVT_EXEC_WAIT(N(80248090))
            EVT_IF_NE(LVarC, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(0x80284054)
    EVT_EXEC_WAIT(N(80248090))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024981C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024918C)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249750)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249854) = {
    EVT_CALL(SpeakToPlayer, 7, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_008E)
    EVT_CALL(SpeakToPlayer, 8, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_008F)
    EVT_CALL(SpeakToPlayer, 9, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, MSG_CH2_0090)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802498C4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249854)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802498E8) = {
    EVT_CALL(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    EVT_CALL(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    EVT_CALL(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    EVT_CALL(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    EVT_CALL(FindKeyItem, ITEM_DIPLOMA, LVar5)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009A)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009B)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar3, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009C)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar4, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009D)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar5, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009E)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_0099)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80249ABC) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802498E8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249AE0) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Brown_Talk, ANIM_Dryite_Brown_Idle, 0, MSG_CH2_009F)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80249B10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249AE0)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80249B34)[] = {
    {
        .id = NPC_MOUSER0,
        .settings = &N(npcSettings_80245134),
        .pos = { -332.0f, 0.0f, 188.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802481F8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Run,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
            ANIM_Mouser_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_Greeter,
    },
    {
        .id = NPC_DRYITE0,
        .settings = &N(npcSettings_80245060),
        .pos = { -235.0f, 0.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802483A8),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { -235, 0, 160, 30, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Walk,
            ANIM_Dryite_Yellow_Run,
            ANIM_Dryite_Yellow_Run,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Still,
            ANIM_Dryite_Yellow_Still,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
            ANIM_Dryite_Yellow_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteA,
    },
    {
        .id = NPC_DRYITE1,
        .settings = &N(npcSettings_80245108),
        .pos = { -380.0f, 0.0f, -15.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802484E0),
        .yaw = 61,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Walk,
            ANIM_Dryite_Blue_Run,
            ANIM_Dryite_Blue_Run,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Still,
            ANIM_Dryite_Blue_Still,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
            ANIM_Dryite_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteD,
    },
    {
        .id = NPC_DRYITE2,
        .settings = &N(npcSettings_80245108),
        .pos = { 195.0f, 0.0f, -75.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248AE4),
        .yaw = 74,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Walk,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteB,
    },
    {
        .id = NPC_DRYITE3,
        .settings = &N(npcSettings_80245108),
        .pos = { 225.0f, 0.0f, -83.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248CC8),
        .yaw = 257,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Walk,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Run,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Still,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
            ANIM_Dryite_Green_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DryiteC,
    },
    {
        .id = NPC_ARTIST_TOAD,
        .settings = &N(npcSettings_80245108),
        .pos = { 285.0f, 0.0f, -274.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249168),
        .yaw = 271,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Musician_Composer_Idle,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
            ANIM_Musician_Composer_Still,
        },
        .tattle = MSG_NpcTattle_Composer,
    },
    {
        .id = NPC_MOUSER1,
        .settings = &N(npcSettings_80245134),
        .pos = { 31.0f, 0.0f, -374.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024981C),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Run,
            ANIM_Mouser_Purple_Run,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
            ANIM_Mouser_Purple_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_ShopOwner,
    },
    {
        .id = NPC_CHUCK_QUIZMO,
        .settings = &N(Quizmo_NpcSettings),
        .pos = { -400.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .initVarCount = 1,
        .initVar = { .value = 0x00030200 },
        .yaw = 263,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Walk,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Idle,
            ANIM_ChuckQuizmo_Still,
            ANIM_ChuckQuizmo_Still,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
            ANIM_ChuckQuizmo_Run,
        },
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
    {
        .id = NPC_DRYITE4,
        .settings = &N(npcSettings_80245060),
        .pos = { -120.0f, 0.0f, 134.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249ABC),
        .yaw = 257,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { -120, 0, 134, 40, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Walk,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_DojoGraduate,
    },
    {
        .id = NPC_DRYITE5,
        .settings = &N(npcSettings_802450DC),
        .pos = { 40.0f, 0.0f, 105.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249B10),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.territory = { .temp = { 2, 40, 0, 105, -30, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Walk,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Run,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Still,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
            ANIM_Dryite_Brown_Idle,
        },
        .tattle = MSG_NpcTattle_DRO_WorriedDryite,
    },
};

StaticNpc N(npcGroup_8024AE94)[] = {
    {
        .id = NPC_THREE_SISTERS0,
        .settings = &N(npcSettings_80245160),
        .pos = { -141.0f, 0.0f, -18.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 62,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_THREE_SISTERS1,
        .settings = &N(npcSettings_80245160),
        .pos = { -124.0f, 0.0f, -61.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 63,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_THREE_SISTERS2,
        .settings = &N(npcSettings_80245160),
        .pos = { -80.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 244,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Walk,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Idle,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Disappointed,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
            ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

NpcGroupList N(npcGroupList_8024B464) = {
    NPC_GROUP(N(npcGroup_80249B34)),
    {},
};

NpcGroupList N(npcGroupList_8024B47C) = {
    NPC_GROUP(N(npcGroup_80249B34)),
    NPC_GROUP(N(npcGroup_8024AE94)),
    {},
};

s32 N(intTable_8024B4A0)[] = {
    MSG_Shop_0049, MSG_Shop_004A, MSG_Shop_004B, MSG_Shop_004C,
    MSG_Shop_004D, MSG_Shop_004E, MSG_Shop_004F, MSG_Shop_0050,
    MSG_Shop_0051, MSG_Shop_0052, MSG_Shop_0053, MSG_Shop_0054,
    MSG_Shop_0055, MSG_Shop_0056, MSG_Shop_0057, MSG_Shop_0058,
    MSG_Shop_0059, MSG_Shop_005A, MSG_Shop_005B, MSG_Shop_005C,
    MSG_Shop_005D, MSG_Shop_005E, MSG_Shop_005F,
};

N(shopInventory) N(shopInventory_8024B4FC)[] = {
    { ITEM_THUNDER_BOLT,    5, MSG_ItemShopDesc_ThunderBolt },
    { ITEM_DUSTY_HAMMER,    2, MSG_ItemShopDesc_DustyHammer },
    { ITEM_HONEY_SYRUP,     5, MSG_ItemShopDesc_HoneySyrup },
    { ITEM_DRIED_SHROOM,    2, MSG_ItemShopDesc_DriedShroom },
    { ITEM_DRIED_PASTA,     3, MSG_ItemShopDesc_DriedPasta },
    { ITEM_MUSHROOM,        3, MSG_ItemShopDesc_Mushroom },
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

#define NAMESPACE dro_01_dup
s32** N(varStash) = NULL;
#define NAMESPACE dro_01

EvtScript N(8024B5B4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B5E4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B614) = {
    EVT_CALL(NpcJump0, 6, -31, 0, -283, 10)
    EVT_CALL(NpcJump0, 6, -30, 0, -283, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B664) = {
    EVT_CALL(NpcJump0, 6, 20, 0, -259, 10)
    EVT_CALL(NpcJump0, 6, 20, 0, -259, 4)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B6B4) = {
    EVT_CALL(N(func_80243578_95E778))
    EVT_CALL(func_802D2C14, 1)
    EVT_EXEC_WAIT(N(8024B614))
    EVT_IF_LT(GB_StoryProgress, -64)
        EVT_CALL(SpeakToPlayer, 6, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0087)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, 6, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_0088)
    EVT_SET(GB_StoryProgress, -64)
    EVT_CALL(func_802D2C14, 0)
    EVT_EXEC_WAIT(N(8024B664))
    EVT_END_IF // @bug
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B7B0) = {
    EVT_IF_EQ(GF_DRO01_Gift_RedJar, 0)
        EVT_CALL(N(func_80243578_95E778))
        EVT_CALL(func_802D2C14, 1)
        EVT_EXEC_WAIT(N(8024B614))
        EVT_CALL(SpeakToPlayer, 6, ANIM_Mouser_Purple_Talk, ANIM_Mouser_Purple_Idle, 0, MSG_CH2_008D)
        EVT_SET(LVar0, 119)
        EVT_SET(LVar1, 1)
        EVT_EXEC_WAIT(N(8024B5B4))
        EVT_CALL(AddKeyItem, ITEM_KOOT_RED_JAR)
        EVT_SET(GF_DRO01_Gift_RedJar, 1)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_EXEC_WAIT(N(8024B664))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B894) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, AreaByte(4))
            EVT_SET(LVar3, AreaByte(5))
            EVT_SET(LVar4, AreaByte(6))
            EVT_SET(AreaByte(5), LVar2)
            EVT_SET(AreaByte(6), LVar3)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(141)
                    EVT_SET(AreaByte(4), 1)
                    EVT_IF_EQ(LVar2, 2)
                        EVT_IF_EQ(LVar3, 3)
                            EVT_IF_EQ(LVar4, 2)
                                EVT_EXEC_WAIT(N(8024B7B0))
                                EVT_SET(AreaByte(4), 0)
                            EVT_END_IF
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(134)
                    EVT_SET(AreaByte(4), 2)
                    EVT_IF_EQ(LVar2, 1)
                        EVT_IF_LT(GB_StoryProgress, -63)
                            EVT_EXEC_WAIT(N(8024B6B4))
                            EVT_SET(AreaByte(4), 0)
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_EQ(167)
                    EVT_SET(AreaByte(4), 3)
                EVT_CASE_DEFAULT
                    EVT_SET(AreaByte(4), 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(shopItemPositions_8024BA68)[] = {
    0x004C0021, 0x004B0022, 0x00490023, 0x004A0024, 0x00480025, 0x00470026,
};

ShopOwner N(shopOwnerNPC_8024BA80) = {
    0x00000006, 0x00940101, 0x00940105, N(8024B894), 0x00000000, 0x00000000, N(intTable_8024B4A0),
};

s32 N(pad_BA9C) = {
    0x00000000,
};

EvtScript N(openDoor_8024BAA0) = {
    EVT_CALL(RotateModel, 103, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BAD0) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, 98, 0, LVar1, 0)
    EVT_CALL(TranslateModel, 97, 0, LVar1, 0)
    EVT_CALL(RotateModel, 98, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 97, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 100, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 101, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(dropDoor_8024BBB8) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, 103, 0, LVar1, 0)
    EVT_CALL(RotateModel, 103, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(openDoor_8024BC24) = {
    EVT_CALL(RotateModel, 83, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BC54) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, 47, 0, LVar1, 0)
    EVT_CALL(TranslateModel, 48, 0, LVar1, 0)
    EVT_CALL(RotateModel, 47, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 48, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 41, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 42, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 43, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 44, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 45, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(openDoor_8024BD9C) = {
    EVT_CALL(RotateModel, 157, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(dropDoor_8024BDCC) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIV(LVar1, 45)
    EVT_CALL(TranslateModel, 157, 0, LVar1, 0)
    EVT_CALL(RotateModel, 157, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BE38) = {
    EVT_IF_EQ(LVar0, 90)
        EVT_CALL(EnableModel, 142, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, 142, 1)
    EVT_END_IF
    EVT_SET(LVar1, LVar0)
    EVT_DIV(LVar1, 45)
    EVT_SET(LVar2, LVar0)
    EVT_SUB(LVar2, -90)
    EVT_DIV(LVar2, -90)
    EVT_CALL(TranslateModel, 140, 0, LVar1, 0)
    EVT_CALL(RotateModel, 140, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 138, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 137, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 136, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 135, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, 143, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, 142, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_8024BFDC) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 127, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 127, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_8024C040) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(-66)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017B, 160, 40)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
                EVT_CASE_LT(-65)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_CALL(SetGroupEnabled, 82, 1)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT(45)
                EVT_CALL(SetNpcPos, 6, 33, 0, -375)
                EVT_CALL(SetNpcYaw, 6, 180)
            EVT_END_THREAD
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 82, 0)
            EVT_SET(AreaByte(4), 0)
            EVT_SET(AreaByte(5), 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_8024C190) = {
    EVT_SWITCH(LVar0)
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

EvtScript N(8024C218) = {
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BAA0)), EVT_PTR(N(moveWalls_8024BAD0)), EVT_PTR(N(dropDoor_8024BBB8)), EVT_PTR(N(toggleVis_8024BFDC)), 15, 16, 128, EVT_PTR(N(npcList_8024C200)))
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BC24)), EVT_PTR(N(moveWalls_8024BC54)), 0, EVT_PTR(N(toggleVis_8024C040)), 23, 24, 91, EVT_PTR(N(npcList_8024C208)))
    EVT_CALL(MakeDoorAdvanced, 5, EVT_PTR(N(openDoor_8024BD9C)), EVT_PTR(N(moveWalls_8024BE38)), EVT_PTR(N(dropDoor_8024BDCC)), EVT_PTR(N(toggleVis_8024C190)), 29, 30, 159, EVT_PTR(N(npcList_8024C210)))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(toggleVis_8024BFDC))
    EVT_EXEC(N(toggleVis_8024C040))
    EVT_EXEC(N(toggleVis_8024C190))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C2EC) = {
    EVT_LABEL(9)
    EVT_CALL(MakeLerp, 10, -10, 30, 10)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 34, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeLerp, -10, 10, 30, 10)
    EVT_LABEL(11)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 34, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C41C) = {
    EVT_CALL(SetGroupEnabled, 82, 1)
    EVT_CALL(PlaySoundAtCollider, 23, 449, 0)
    EVT_CALL(MakeLerp, 0, 100, 15, 4)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_EXEC(N(openDoor_8024BC24))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C4C8) = {
    EVT_CALL(MakeLerp, 100, 0, 15, 4)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_EXEC(N(openDoor_8024BC24))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
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

EvtScript N(8024C580) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_SUB(LVar2, 40)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(func_802D286C, 256)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(40)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(3)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 0, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(dup_Pipe_GetCurrentFloor))
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C8D4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, 0x7FFFFE00)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_IF_EQ(LVar4, 90)
        EVT_ADD(LVar5, 40)
    EVT_ELSE
        EVT_SUB(LVar5, 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, LVar5, LVar6, LVar7)
    EVT_CALL(SetPanTarget, 0, LVar5, LVar6, LVar7)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PlaySound, 355)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2304)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(dup_Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, LVarB, 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024CCC4) = {
    EVT_CALL(N(dup_Pipe_AwaitDownInput))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(8024CDA0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024CDA0) = {
    EVT_CALL(N(dup_Pipe_SetAnimFlag))
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(SetPlayerFlagBits, 2097152, 1)
    EVT_CALL(N(dup_Pipe_GetCameraYaw))
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerFlagBits, 2097152, 0)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 2, 1, 1, 0)
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024CF7C) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, 26)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, 6)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(dup_Pipe_SetAnimFlag))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, 0x7FFFFE00)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_ADD(LVar6, 2)
    EVT_SET(LVar7, LVar3)
    EVT_SET(LVar8, LVar4)
    EVT_ADD(LVar8, 180)
    EVT_IF_GE(LVar4, 360)
        EVT_SUB(LVar4, 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, LVar8, 1)
    EVT_WAIT(1)
    EVT_CALL(PlaySound, 355)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, LVar6, LVar7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802D286C, 2048)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_LOOP(40)
            EVT_CALL(N(dup_Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

extern const char N(dro_01_name_hack)[];

EvtScript N(8024D2B0) = {
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, 0)
    EVT_CALL(GotoMap, EVT_PTR(N(dro_01_name_hack)), 4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -211, 60, -50, 30, MAKE_ENTITY_END)
    EVT_IF_EQ(GF_DRO01_WarpPipe, 0)
        EVT_IF_EQ(GF_TIK01_WarpPipes, 1)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_SET(GF_DRO01_WarpPipe, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, &Entity_BlueWarpPipe, 430, 0, -120, 0, 2, EVT_PTR(N(8024D2B0)), 1939, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

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
        evt_set_variable(script, *args++, N(D_802477E4_9629E4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242784_95D984)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802477E4_9629E4) = evt_get_variable(script, *args++);
    N(D_802477E0_9629E0) = 1;
    return ApiStatus_DONE2;
}

#include "world/common/atomic/MakeKeyChoice.inc.c"

ApiStatus N(func_80242858_95DA58)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Unk_Struct_2* temp_s1 = (Unk_Struct_2*) evt_get_variable(script, *script->ptrReadPos);
    Unk_Struct_1* ptr;
    s32 atan_res1, atan_res2;
    s32 clamp;
    s32 res;

    if (isInitialCall) {
        script->functionTempPtr[1] = heap_malloc(0x3C);
        ptr = script->functionTempPtr[1];
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

    ptr = script->functionTempPtr[1];
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

#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus N(func_80243084_95E284)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->droTreeOrbitTime = playerData->frameCounter;
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"

void N(func_802430C8_95E2C8)(Unk_Struct_1* ptr, s32 arg1) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (arg1) {
        case 2:
            if (ptr->unk_1C >= 6) {
                if (fabsf(get_clamped_angle_diff(atan2(125.0f, -42.0f, 152.0f, -61.0f), atan2(125.0f, -42.0f, playerStatus->position.x,
                                                 playerStatus->position.z))) < 30.0f) {
                    start_script(&N(80248504), EVT_PRIORITY_1, 0);
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
    s32 val = (playerData->frameCounter - playerData->droTreeOrbitTime) / 3600;

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
