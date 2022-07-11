#include "dro_01.h"
#include "effects.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/artist_toad.h"
#include "sprite/npc/chuck_quizmo.h"
#include "sprite/npc/dryite.h"
#include "sprite/npc/mouser.h"
#include "sprite/npc/three_sisters.h"
#include "sprite/npc/world_parakarry.h"

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

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_dro_01_tattle },
};

EvtScript N(80243BB0) = {
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

#include "world/common/atomic/PipeData.inc.c"

EvtScript N(exitWalk_80244960) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(EVT_SAVE_FLAG(761), 0)
    EVT_CALL(UseExitHeading, 60, 0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sbk_36"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_802449CC) = EXIT_WALK_SCRIPT(60,  1, "dro_02",  0);

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

EvtScript N(enterWalk_80244C14) = {
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
                EVT_CALL(PlaySound, SOUND_208E)
                EVT_SET(EVT_SAVE_FLAG(1939), 1)
                EVT_WAIT_FRAMES(30)
                EVT_CALL(SetPlayerActionState, 0)
                EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(EVT_VAR(10), EVT_PTR(N(80244A28)))
            EVT_EXEC_WAIT(N(Pipe_EnterVertical))
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

EvtScript N(main) = {
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
    .unk_2A = 16,
};

NpcAISettings N(npcAISettings_8024508C) = {
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

#include "world/common/atomic/QuizmoData.inc.c"

s32 N(D_802477E0_9629E0) = {
    0x00000000,
};

s32 N(D_802477E4_9629E4) = {
    0x00000000,
};

EvtScript N(802477E8) = {
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

EvtScript N(8024792C) = {
    EVT_CALL(N(BuildKeyItemChoiceList), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(802477E8), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024797C) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_CALL(N(LetterDelivery_CalcLetterPos), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_CALL(SetItemPos, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802479FC) = {
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
            EVT_CALL(N(LetterDelivery_CalcLetterPos), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
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

EvtScript N(80247D20) = {
    EVT_SET(EVT_VAR(0), EVT_VAR(11))
    EVT_SET(EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(BuildKeyItemChoiceList), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(802479FC), 0x10, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80242730_95D930), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(80247D90) = {
    EVT_SET(EVT_VAR(12), 0)
    EVT_IF_LT(EVT_SAVE_VAR(0), -70)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(LetterDelivery_SaveNpcAnim))
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
                        EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
                        EVT_CALL(AddKeyItem, EVT_VAR(6))
                    EVT_END_IF
                    EVT_SET(EVT_VAR(12), 2)
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
    EVT_CALL(N(LetterDelivery_Init), 6, NPC_ANIM_mouser_Palette_01_Anim_5, NPC_ANIM_mouser_Palette_01_Anim_1, 76, 69,
        MESSAGE_ID(0xD,0x89), MESSAGE_ID(0xD,0x8A), MESSAGE_ID(0xD,0x8B), MESSAGE_ID(0xD,0x8C), EVT_PTR(N(D_80248088_963288)))
    EVT_EXEC_WAIT(N(80247D90))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802480E0) = {
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

EvtScript N(init_802481F8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802480E0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_8024821C) = {
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

EvtScript N(init_802483A8) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_8024821C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802483CC) = {
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

EvtScript N(init_802484E0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802483CC)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80248504) = {
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

Unk_Struct_2 N(D_8024884C_963A4C) = {
    0x0000007D, 0x00000000, 0xFFFFFFD6, 0x0000004B, 0x0000004B, N(func_802430C8_95E2C8),
};

EvtScript N(interact_80248864) = {
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

EvtScript N(init_80248AE4) = {
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

EvtScript N(interact_80248BA0) = {
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

EvtScript N(init_80248CC8) = {
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

EvtScript N(interact_80248D54) = {
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
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddKeyItem, ITEM_MELODY)
            EVT_SET(EVT_SAVE_FLAG(754), 1)
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

EvtScript N(interact_80249750) = {
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

EvtScript N(init_8024981C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024918C)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249750)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249854) = {
    EVT_CALL(SpeakToPlayer, 7, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x008E))
    EVT_CALL(SpeakToPlayer, 8, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x008F))
    EVT_CALL(SpeakToPlayer, 9, NPC_ANIM_three_sisters_Palette_01_Anim_4, NPC_ANIM_three_sisters_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x0090))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802498C4) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80249854)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802498E8) = {
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

EvtScript N(init_80249ABC) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802498E8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80249AE0) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_dryite_Palette_01_Anim_4, NPC_ANIM_dryite_Palette_01_Anim_1, 0, MESSAGE_ID(0x0D, 0x009F))
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
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802483A8),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802484E0),
        .yaw = 61,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248AE4),
        .yaw = 74,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80248CC8),
        .yaw = 257,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249168),
        .yaw = 271,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_8024981C),
        .yaw = 180,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .settings = &N(Quizmo_NpcSettings),
        .pos = { -400.0f, 0.0f, 100.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .unk_1C = { 00, 00, 00, 01, 00, 03, 02, 00},
        .yaw = 263,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249ABC),
        .yaw = 257,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_80249B10),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 62,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 63,
        .dropFlags = NPC_DROP_FLAGS_80,
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(init_802498C4),
        .yaw = 244,
        .dropFlags = NPC_DROP_FLAGS_80,
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

#define NAMESPACE dro_01_dup
s32** N(varStash) = NULL;
#define NAMESPACE dro_01

EvtScript N(8024B5B4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8024B5E4) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
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

EvtScript N(8024B7B0) = {
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

EvtScript N(8024B894) = {
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

ShopOwner N(shopOwnerNPC_8024BA80) = {
    0x00000006, 0x00940101, 0x00940105, N(8024B894), 0x00000000, 0x00000000, N(intTable_8024B4A0),
};

s32 N(pad_BA9C) = {
    0x00000000,
};

EvtScript N(openDoor_8024BAA0) = {
    EVT_CALL(RotateModel, 103, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BAD0) = {
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

EvtScript N(dropDoor_8024BBB8) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIVF(EVT_VAR(1), 50)
    EVT_CALL(TranslateModel, 103, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 103, EVT_VAR(0), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(openDoor_8024BC24) = {
    EVT_CALL(RotateModel, 83, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BC54) = {
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

EvtScript N(openDoor_8024BD9C) = {
    EVT_CALL(RotateModel, 157, EVT_VAR(0), 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(dropDoor_8024BDCC) = {
    EVT_SET(EVT_VAR(1), EVT_VAR(0))
    EVT_DIV(EVT_VAR(1), 45)
    EVT_CALL(TranslateModel, 157, 0, EVT_VAR(1), 0)
    EVT_CALL(RotateModel, 157, EVT_VAR(0), 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(moveWalls_8024BE38) = {
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

EvtScript N(toggleVis_8024BFDC) = {
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, 127, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, 127, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(toggleVis_8024C040) = {
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

EvtScript N(toggleVis_8024C190) = {
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

EvtScript N(8024C218) = {
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

EvtScript N(8024C2EC) = {
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

EvtScript N(8024C41C) = {
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

EvtScript N(8024C4C8) = {
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

EvtScript N(8024C580) = {
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
    EVT_CALL(N(dup_Pipe_GetEntryPos))
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
    EVT_CALL(N(dup_Pipe_GetCurrentFloor))
    EVT_WAIT_FRAMES(1)
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(EVT_VAR(10))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C8D4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_CALL(N(dup_Pipe_GetEntryPos))
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
        EVT_CALL(N(dup_Pipe_GetPointAheadOfPlayer), EVT_FIXED(1.0))
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

EvtScript N(8024CCC4) = {
    EVT_CALL(N(dup_Pipe_AwaitDownInput))
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

EvtScript N(8024CDA0) = {
    EVT_CALL(N(dup_Pipe_SetAnimFlag))
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, EVT_VAR(1), EVT_VAR(3), 3)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, EVT_VAR(1), EVT_VAR(2), EVT_VAR(3))
    EVT_CALL(SetPlayerFlagBits, 2097152, 1)
    EVT_CALL(N(dup_Pipe_GetCameraYaw))
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

EvtScript N(8024CF7C) = {
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
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(dup_Pipe_SetAnimFlag))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(11), 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_VAR(10))
    EVT_CALL(N(dup_Pipe_GetEntryPos))
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
            EVT_CALL(N(dup_Pipe_GetPointAheadOfPlayer), EVT_FIXED(1.0))
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(25)
    EVT_EXEC_WAIT(EVT_VAR(12))
    EVT_RETURN
    EVT_END
};

extern const char N(dro_01_name_hack)[];

EvtScript N(8024D2B0) = {
    EVT_SET(EVT_SAVE_FLAG(761), 0)
    EVT_CALL(GotoMap, EVT_PTR(N(dro_01_name_hack)), 4)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -211, 60, -50, 30, MAKE_ENTITY_END)
    EVT_IF_EQ(EVT_SAVE_FLAG(1939), 0)
        EVT_IF_EQ(EVT_SAVE_FLAG(1933), 1)
            EVT_CALL(GetEntryID, EVT_VAR(0))
            EVT_IF_NE(EVT_VAR(0), 2)
                EVT_SET(EVT_SAVE_FLAG(1939), 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, &Entity_BlueWarpPipe, 430, 0, -120, 0, 2, EVT_PTR(N(8024D2B0)), 1939, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/atomic/Quizmo.inc.c"

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

#include "world/common/LetterDelivery.inc.c"

ApiStatus N(func_80243084_95E284)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->droTreeOrbitTime = playerData->frameCounter;
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
