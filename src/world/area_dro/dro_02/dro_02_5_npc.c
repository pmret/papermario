#include "dro_02.h"
#include "effects.h"
#include "script_api/battle.h"
#include "entity.h"
#include "sprite.h"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo

extern s16 MessagePlural;
extern s16 MessageSingular;

static f32 N(D_8024EF80);
static f32 N(D_8024EF84);
static s32 N(RitualStateTime);
static s8 N(pad_D_8024EF8C)[0x4];
static EffectInstance* N(D_8024EF90)[4];

#include "world/common/complete/Quizmo.inc.c"

MobileAISettings N(AISettings_Archeologist) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Archeologist) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Archeologist)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80247458) = {
    .height = 35,
    .radius = 24,
    .ai = &N(EVS_NpcAI_Archeologist),
    .level = 99,
    .actionFlags = ENEMY_AI_FLAGS_10,
};

NpcSettings N(NpcSettings_Archeologist) = {
    .height = 42,
    .radius = 24,
    .ai = &N(EVS_NpcAI_Archeologist),
    .level = 99,
};

MobileAISettings N(AISettings_MrE) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MrE) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_MrE)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MrE) = {
    .height = 26,
    .radius = 23,
    .ai = &N(EVS_NpcAI_MrE),
    .level = 99,
    .actionFlags = 16,
};

NpcSettings N(NpcSettings_Dryite_Green) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

NpcSettings N(NpcSettings_Mouser_Blue) = {
    .height = 22,
    .radius = 25,
    .level = 99,
};

NpcSettings N(NpcSettings_ToadHouseKeeper) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_802475B0) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

#include "dro_02_merlee.c"

#include "world/common/complete/KeyItemChoice.inc.c"
#include "world/common/complete/NormalItemChoice.inc.c"

extern IMG_BIN N(toad_house_blanket_img)[];
#include "dro_02_toad_house_blanket_skeleton.c"
#include "world/area_dro/dro_02/toad_house_blanket.vtx.inc.c"
#include "world/area_dro/dro_02/toad_house_blanket.gfx.inc.c"
#include "world/area_dro/dro_02/toad_house_blanket.png.inc.c"
#include "dro_02_toad_house_blanket_anim.c"

#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER17,
    ITEM_NONE
};

EvtScript N(EVS_MrE_LetterPrompt) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Dryite_01, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle,
        ITEM_LETTER17, ITEM_LETTER18,
        MSG_CH2_0095, MSG_CH2_0096, MSG_CH2_0097, MSG_CH2_0098,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Archeologist) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B2)
            EVT_ELSE
                EVT_SWITCH(AB_DRO_3)
                    EVT_CASE_EQ(0)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00AF)
                        EVT_SET(AB_DRO_3, 1)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B0)
                        EVT_SET(AB_DRO_3, 2)
                    EVT_CASE_EQ(2)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B1)
                        EVT_SET(AB_DRO_3, 1)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Archeologist) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Archeologist)))
    EVT_IF_GE(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MrE) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutDesert, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0091)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0092)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0093)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0094)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MrE_LetterPrompt))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MrE) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MrE)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_03, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A1)
                EVT_SET(AF_DRO_03, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A2)
                EVT_SET(AF_DRO_03, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A3)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A5)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A6)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A7)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A8)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A9)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AA)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_05, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AB)
                EVT_SET(AF_DRO_05, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AC)
                EVT_SET(AF_DRO_05, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AD)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PartyWatchingMousatafa) = {
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, NPC_Moustafa, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Moustafa, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C0B8) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(GetNpcPos, NPC_DisguisedMoustafa, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar0, 2)
    EVT_DIV(LVar1, 2)
    EVT_DIV(LVar2, 2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(8.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C1F8) = {
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024C248) = {
    EVT_CALL(SetNpcYaw, NPC_Moustafa, 270)
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_GrabCloak)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_ThrownCloak)
    EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
    EVT_CALL(SetNpcPos, NPC_Moustafa, -335, 163, -260)
    EVT_EXEC(N(EVS_PlayMoustafaMusic))
    EVT_CALL(MakeLerp, 0, 80, 30, EASING_CUBIC_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_SET(LVar2, -335)
    EVT_SET(LVar3, 163)
    EVT_SUB(LVar2, LVar0)
    EVT_ADD(LVar3, LVar0)
    EVT_CALL(SetNpcPos, NPC_DisguisedMoustafa, LVar2, LVar3, -260)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcPos, NPC_DisguisedMoustafa, 0, -1000, -250)
    EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_100, FALSE)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_DisguisedMoustafa) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_BOUGHT_SECRET_ITEMS)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(SetNpcPos, NPC_SELF, -335, 163, -260)
        EVT_CASE_GE(STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, -250)
            EVT_CALL(SetNpcPos, NPC_Moustafa, -335, 163, -260)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Moustafa) = {
    EVT_IF_EQ(GF_DRO02_Moustafa_UnusedDialogOverride, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CF)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_BOUGHT_SECRET_ITEMS)
            EVT_SET(LVarB, 0)
            EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B4)
            EVT_LABEL(0)
            EVT_CALL(ShowChoice, MSG_Choice_0019)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B6)
                EVT_EXEC(N(8024C1F8))
                EVT_RETURN
            EVT_ELSE
                EVT_CALL(EndSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0)
            EVT_END_IF
            EVT_LABEL(1)
            EVT_CHOOSE_ANY_CONSUMABLE()
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B8)
                    EVT_EXEC(N(8024C1F8))
                    EVT_RETURN
                EVT_CASE_EQ(-1)
                    EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B7)
                    EVT_EXEC(N(8024C1F8))
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(GB_DRO02_SheekLemonGiftCount, 0)
                EVT_IF_EQ(LVarA, ITEM_LEMON)
                    EVT_SET(GB_DRO02_SheekLemonGiftCount, 1)
                    EVT_SET(GB_DRO02_SheekGiftCount, 10)
                    EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BB)
                    EVT_CALL(ShowChoice, MSG_Choice_001C)
                EVT_ELSE
                    EVT_ADD(GB_DRO02_SheekGiftCount, 1)
                    EVT_IF_LE(GB_DRO02_SheekGiftCount, 2)
                        EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B5)
                        EVT_GOTO(0)
                    EVT_END_IF
                    EVT_IF_EQ(GB_DRO02_SheekGiftCount, 3)
                        EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B9)
                        EVT_CALL(ShowChoice, MSG_Choice_001B)
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BA)
                        EVT_CALL(ShowChoice, MSG_Choice_001B)
                        EVT_SET(GB_DRO02_SheekGiftCount, 10)
                    EVT_END_IF
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BA)
                EVT_CALL(ShowChoice, MSG_Choice_001C)
            EVT_END_IF
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BC)
                EVT_CASE_EQ(1)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BD)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutDesert, TRUE)
                EVT_CASE_EQ(2)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BE)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutRuins, TRUE)
                EVT_CASE_EQ(3)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BF)
                EVT_CASE_EQ(4)
                    EVT_EXEC_WAIT(N(8024C0B8))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C1)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutMoustafa, TRUE)
                    EVT_SET(LVarB, 1)
            EVT_END_SWITCH
            EVT_SET(GF_DRO02_Sheek_SpokeTo, TRUE)
            EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C0)
            EVT_CALL(ShowChoice, MSG_Choice_001A)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(EndSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0)
                EVT_GOTO(1)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B6)
            EVT_END_IF
            EVT_IF_EQ(LVarB, 1)
                EVT_IF_EQ(MF_Unk_00, FALSE)
                    EVT_SET(MF_Unk_00, TRUE)
                    EVT_THREAD
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 50)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C2)
                        EVT_CALL(DisablePlayerInput, FALSE)
                        EVT_SET(MF_Unk_00, FALSE)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
            EVT_EXEC(N(8024C1F8))
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(func_802D2C14, 1)
            EVT_END_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_100, TRUE)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
            EVT_CALL(PlayerMoveTo, -391, -260, 0)
            EVT_CALL(InterpPlayerYaw, 90, 3)
            EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_100, FALSE)
            EVT_EXEC_GET_TID(N(EVS_PartyWatchingMousatafa), LVarA)
            EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_100, TRUE)
            EVT_CALL(FadeOutMusic, 0, 500)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutMoustafa, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C3)
                EVT_EXEC_WAIT(N(8024C248))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_Moustafa, -425, 140, -206, 20)
                EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C5)
                EVT_EXEC_WAIT(N(8024C248))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_Moustafa, -425, 140, -206, 20)
                EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C6)
            EVT_END_IF
            EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_Moustafa, -337, 140, -200, 20)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C7)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C8)
            EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_Moustafa, -335, 163, -260, 20)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C9)
            EVT_GIVE_KEY_REWARD(ITEM_PULSE_STONE)
            EVT_SET(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CA)
            EVT_KILL_THREAD(LVarA)
            EVT_EXEC(N(EVS_SetupMusic))
        EVT_CASE_GE(STORY_CH2_GOT_PULSE_STONE)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
                    EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CB)
                EVT_CASE_GE(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
                    EVT_IF_GE(GB_StoryProgress, STORY_CH2_DEFEATED_TUTANKOOPA)
                        EVT_IF_EQ(GF_DRO02_Moustafa_HeardAboutDryDryRuins, FALSE)
                            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CD)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                            EVT_WAIT(15)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
                            EVT_WAIT(30)
                            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CE)
                            EVT_SET(GF_DRO02_Moustafa_HeardAboutDryDryRuins, TRUE)
                        EVT_ELSE
                            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00D0)
                        EVT_END_IF
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00CC)
                    EVT_END_IF
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DisguisedMoustafa) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(dro_02_ENTRY_2)
        EVT_CASE_OR_EQ(dro_02_ENTRY_3)
            EVT_CALL(SetNpcPos, NPC_SELF, 200, 0, -15)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_200000, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_DisguisedMoustafa_GrabCloak)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_DisguisedMoustafa)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Moustafa)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Moustafa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Moustafa)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Mouser_03) = {
    EVT_CALL(InterpNpcYaw, NPC_DisguisedMoustafa, 270, 0)
    EVT_LABEL(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Gossip)
        EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
        EVT_LOOP(50)
            EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
        EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_TalkAlt)
        EVT_LOOP(50)
            EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_LABEL(20)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
    EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_174, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -83, 11, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -239, 5, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -371, 5, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -487, 5, 20)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Mouser_03)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetToadHouseDialogue) = {
    EVT_SET(LVar0, MSG_CH2_00D1)
    EVT_SET(LVar8, MSG_CH2_00D2)
    EVT_SET(LVar1, MSG_CH2_00D3)
    EVT_SET(LVar2, MSG_CH2_00D4)
    EVT_SET(LVar3, MSG_CH2_00D5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestMusic))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -179, -198, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 95, -61)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 108)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 202, 62)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, -89, -141)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -187, -267, 0)
    EVT_CALL(InterpPlayerYaw, 230, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(func_802D286C, 0x00000800)
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
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 0, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -187, 0, -240)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -168, -195, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(PassiveNPCs)[] = {
    {
        .id = NPC_Archeologist,
        .settings = &N(NpcSettings_Archeologist),
        .pos = { -320.0f, 0.0f, -14.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Archeologist),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .territory = { .temp = { -303, 0, 22, 146, 38, -32767, 1, 0, 0, 0, 0, 0, 0, 1 }},
        .animations = {
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Walk,
            ANIM_Archeologist_Run,
            ANIM_Archeologist_Run,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
        },
        .tattle = MSG_NpcTattle_Archeologist,
    },
    {
        .id = NPC_Dryite_01,
        .settings = &N(NpcSettings_MrE),
        .pos = { -20.0f, 0.0f, 40.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_MrE),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .territory = { .temp = { -20, 0, 40, 60, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
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
        .tattle = MSG_NpcTattle_DRO_DryiteE,
    },
    {
        .id = NPC_DisguisedMoustafa,
        .settings = &N(NpcSettings_Mouser_Blue),
        .pos = { 245.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_DisguisedMoustafa),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
            ANIM_DisguisedMoustafa_Idle,
        },
        .tattle = MSG_NpcTattle_Sheek,
    },
    {
        .id = NPC_Toad,
        .settings = &N(NpcSettings_ToadHouseKeeper),
        .pos = { -143.0f, 0.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_ToadHouseKeeper),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            ANIM_Toad_Red_Idle,
            ANIM_Toad_Red_Walk,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Idle,
            ANIM_Toad_Red_Idle,
            ANIM_Toad_Red_Disappointed,
            ANIM_Toad_Red_Disappointed,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
            ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_DRO_ToadHouseToad,
    },
    {
        .id = NPC_Merlee,
        .settings = &N(NpcSettings_Merlee),
        .pos = { -130.0f, 0.0f, -400.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcAuxAI_Merlee),
        .yaw = 180,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Walk,
            ANIM_WorldMerlee_Run,
            ANIM_WorldMerlee_Run,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
        },
        .tattle = MSG_NpcTattle_Merlee,
    },
    {
        .id = NPC_Moustafa,
        .settings = &N(NpcSettings_Mouser_Blue),
        .pos = { NPC_DISPOSE_LOCATION },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Moustafa),
        .yaw = 0,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	    .animations = {
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Run,
            ANIM_Moustafa_Run,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
            ANIM_Moustafa_Idle,
        },
        .tattle = MSG_NpcTattle_Moustafa,
    },
    {
        .id = NPC_Dryite_02,
        .settings = &N(NpcSettings_Dryite_Green),
        .pos = { 25.0f, 0.0f, -38.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_02),
        .yaw = 270,
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
        .tattle = MSG_NpcTattle_DRO_DryiteF,
    },
    {
        .id = NPC_Dryite_03,
        .settings = &N(NpcSettings_Dryite_Green),
        .pos = { -375.0f, 0.0f, -10.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Dryite_03),
        .yaw = 270,
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
        .tattle = MSG_NpcTattle_DRO_VisitedShootingStarSummit,
    },
    {
        .id = NPC_Mouser_01,
        .settings = &N(NpcSettings_Mouser_Blue),
        .pos = { -50.0f, 0.0f, -470.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Mouser_01),
        .yaw = 180,
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
        .tattle = MSG_NpcTattle_DRO_CrushingOnMerlee,
    },
    {
        .id = NPC_Mouser_02,
        .settings = &N(NpcSettings_Mouser_Blue),
        .pos = { -270.0f, 0.0f, 91.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Mouser_02),
        .yaw = 270,
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
        .tattle = MSG_NpcTattle_DRO_TellsTales,
    },
    {
        .id = NPC_Mouser_03,
        .settings = &N(NpcSettings_Mouser_Blue),
        .pos = { 210.0f, 0.0f, -35.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .init = &N(EVS_NpcInit_Mouser_03),
        .yaw = 90,
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
    },
    {
        .id = NPC_ChuckQuizmo,
        .settings = &N(Quizmo_NpcSettings),
        .pos = { -335.0f, 0.0f, 90.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
        .initVarCount = 1,
        .initVar = { .bytes = { 0, QUIZ_AREA_DRO, QUIZ_COUNT_DRO, QUIZ_MAP_DRO_02 } },
        .yaw = 270,
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
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(PassiveNPCs)),
    {},
};
