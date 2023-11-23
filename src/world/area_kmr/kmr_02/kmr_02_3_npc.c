#include "kmr_02.h"
#include "effects.h"
#include "model.h"
#include "game_modes.h"
#include "sprite/player.h"

extern EvtScript N(EVS_NpcAI_Eldstar_02);
extern EvtScript N(EVS_NpcAI_Eldstar_02_NoAI);

BSS u8 N(savedColR); // r
BSS u8 N(savedColG); // g
BSS u8 N(savedColB); // b
BSS u8 N(savedColA); // a

BSS u8 oldPrimR, oldPrimG, oldPrimB;
BSS u8 oldEnvR, oldEnvG, oldEnvB;

#define QUIZMO_PRE_STATIC_PAD TRUE
#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/npc/Toad_Guard.inc.c"

#include "world/common/util/ChangeNpcToPartner.inc.c"

API_CALLABLE(N(func_80242014_8B2084)) {
    if (get_npc_unsafe(NPC_PARTNER)->flags & NPC_FLAG_GROUNDED) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

#include "world/common/npc/GoombaFamily_Wander.inc.c"
#include "world/common/npc/GoombaFamily.inc.c"
#include "world/common/enemy/Kammy_Guard.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"

#define NAME_SUFFIX _Npc
#include "wander_territories.inc.c"
#define NAME_SUFFIX

#include "world/common/atomic/MarioSalute.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_GoompapaTrade)[] = {
    ITEM_LETTER_CHAIN_GOOMPAPA_1,
    ITEM_NONE
};

EvtScript N(EVS_LetterTrade_Goompapa) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle,
        ITEM_LETTER_CHAIN_GOOMPAPA_1, ITEM_LETTER_CHAIN_MUSS_T,
        MSG_CH0_006F, MSG_CH0_0070, MSG_CH0_0071, MSG_CH0_0072,
        EVT_PTR(N(LetterList_GoompapaTrade)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

s32 N(LetterList_Goompapa)[] = {
    ITEM_LETTER_CHAIN_GOOMPAPA_2,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Goompapa) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle,
        ITEM_LETTER_CHAIN_GOOMPAPA_2, ITEM_NONE,
        MSG_CH0_0073, MSG_CH0_0074, MSG_CH0_0075, MSG_CH0_0076,
        EVT_PTR(N(LetterList_Goompapa)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Goompapa) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_BADGE_REWARD(ITEM_LUCKY_DAY)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(LetterList_Goompa)[] = {
    ITEM_LETTER_TO_GOOMPA,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Goompa) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle,
        ITEM_LETTER_TO_GOOMPA, ITEM_NONE,
        MSG_CH0_0045, MSG_CH0_0046, MSG_CH0_0047, MSG_CH0_0048,
        EVT_PTR(N(LetterList_Goompa)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Goompa) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_GoombaFamily_NoAI) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goombario) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(100)
            EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_CASE_OR_EQ(101)
        EVT_CASE_OR_EQ(102)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(103)
            EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goombario) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_IF_EQ(GF_KMR02_Met_Goombario, FALSE)
                EVT_SET(GF_KMR02_Met_Goombario, TRUE)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0 * DT), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.2), EVT_FLOAT(-7.5))
                EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004D)
                EVT_THREAD
                    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 * DT))
                EVT_END_THREAD
            EVT_ELSE
                EVT_IF_EQ(GF_KMR02_Goombario_SwapDialogue, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004E)
                    EVT_SET(GF_KMR02_Goombario_SwapDialogue, TRUE)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004F)
                    EVT_SET(GF_KMR02_Goombario_SwapDialogue, FALSE)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH0_GATE_CRUSHED)
            EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0051)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombario) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goombario)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goombario)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(N(SetWanderTerritory_Npc), NPC_Goombario, 2)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_Npc)))
        EVT_CASE_LT(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_SELF, 66, 0, -126)
        EVT_CASE_GE(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goombaria_NoAI) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandOverDolly) = {
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
    EVT_CALL(MakeItemEntity, ITEM_DOLLY, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(RemoveItemEntity, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goombaria_Kiss) = {
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    EVT_WAIT(5)
    EVT_ADD(LVar1, 10)
    EVT_CALL(GetAngleToNPC, NPC_Goombaria, LVarA)
    EVT_IF_GE(LVarA, 180)
        EVT_ADD(LVar0, 20)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Goombaria, SOUND_HEART_BOUNCE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goombaria_RequestDolly) = {
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0096)
    EVT_WAIT(10)
    EVT_IF_EQ(GF_KMR02_KeptDolly, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0097)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0098)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(ShowChoice, MSG_Choice_0011)
    EVT_WAIT(10)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(FindKeyItem, ITEM_DOLLY, LVar0)
        EVT_CALL(RemoveKeyItemAt, LVar0)
        EVT_EXEC_WAIT(N(EVS_HandOverDolly))
        EVT_CALL(ContinueSpeech, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_009A)
        EVT_WAIT(10)
        EVT_GIVE_STAR_PIECE()
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_009B)
        EVT_WAIT(10)
        EVT_EXEC(N(EVS_Goombaria_Kiss))
        EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Goombaria, LVar0, LVar1, LVar2, 10)
        EVT_WAIT(10)
        EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHIVER, 1, 1, 0)
        EVT_WAIT(35)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
        EVT_CALL(NpcFacePlayer, NPC_Goombaria, 3)
        EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
        EVT_WAIT(20)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0099)
        EVT_SET(GF_KMR02_KeptDolly, TRUE)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goombaria) = {
    EVT_CALL(HasKeyItem, ITEM_DOLLY, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_EXEC_WAIT(N(EVS_Goombaria_RequestDolly))
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_GOOMPA)
            EVT_SWITCH(AB_KMR_2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0088)
                    EVT_SET(AB_KMR_2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0089)
                    EVT_SET(AB_KMR_2, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008A)
                    EVT_SET(AB_KMR_2, 1)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008B)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008C)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008D)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008E)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008F)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008F)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goombaria, MSG_CH0_0090)
                EVT_CALL(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_PARTNER, MSG_CH0_0091)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0092)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0093)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goombaria, MSG_CH0_0094)
                EVT_CALL(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_PARTNER, MSG_CH0_0095)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goombaria)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_GOOMPA)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goombaria_NoAI)))
            EVT_CALL(SetNpcPos, NPC_SELF, 5, 0, -154)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goombaria_NoAI)))
            EVT_CALL(SetNpcPos, NPC_SELF, 215, 0, 215)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(N(SetWanderTerritory_Npc), NPC_Goombaria, 3)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_Npc)))
        EVT_CASE_LT(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_SELF, 94, 0, -109)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(IsPlayerHPFull)) {
    script->varTable[0] = (gPlayerData.curHP == gPlayerData.curMaxHP);
    return ApiStatus_DONE2;
}

BSS MessageImageData N(HeartBlockMsgImg);

#include "world/area_kmr/kmr_02/heart_block.png.h"

API_CALLABLE(N(LoadHeartBlockMsgImg)) {
    N(HeartBlockMsgImg).raster   = N(heart_block_img);
    N(HeartBlockMsgImg).palette  = N(heart_block_pal);
    N(HeartBlockMsgImg).width    = N(heart_block_img_width);
    N(HeartBlockMsgImg).height   = N(heart_block_img_height);
    N(HeartBlockMsgImg).format   = G_IM_FMT_CI;
    N(HeartBlockMsgImg).bitDepth = G_IM_SIZ_4b;
    set_message_images(&N(HeartBlockMsgImg));
    return ApiStatus_DONE1;
}

API_CALLABLE(N(RemoveGoompaPartner)) {
    gPlayerData.partners[PARTNER_GOOMPA].enabled = FALSE;
    func_800EB2A4(PARTNER_NONE);
    return ApiStatus_DONE1;
}

API_CALLABLE(N(WaitForStartInput)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_START) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(OpenPauseMenu)) {
    set_game_mode(GAME_MODE_PAUSE);
    return ApiStatus_DONE1;
}

API_CALLABLE(N(CloseStatusBar)) {
    close_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PromptForBadgeTutorial) = {
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002D)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002E)
        EVT_CALL(ShowChoice, MSG_Choice_0013)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002F)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0030)
    EVT_WAIT(10)
    EVT_CALL(N(WaitForStartInput))
    EVT_CALL(EndSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0)
    EVT_WAIT(10)
    EVT_SET(GF_Tutorial_Badges, TRUE)
    EVT_CALL(N(OpenPauseMenu))
    EVT_CALL(N(CloseStatusBar))
    EVT_SET(GF_Tutorial_Badges, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnToVillage) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(func_80242014_8B2084))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001D)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, -295, -30, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_USE_KEY, SOUND_SPACE_DEFAULT)
    EVT_WAIT(15 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mm1, SOUND_GOOMBA_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 120, 20, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_m_d1, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_m_d2, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    EVT_CALL(EnableNpcAI, NPC_Goombario, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Goombaria, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Gooma, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Goomama, FALSE)
    EVT_CALL(SetNpcPos, NPC_Goombario, -95, 0, -86)
    EVT_CALL(SetNpcPos, NPC_Goombaria, -92, 0, -46)
    EVT_CALL(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -189, 0, -40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -189, 0, -40)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.3 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(4.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
        EVT_CALL(NpcMoveTo, NPC_Goombario, -109, -61, 0)
        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(4.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadRun)
        EVT_CALL(NpcMoveTo, NPC_Goombaria, -142, -95, 0)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, -238, -33, 0)
    EVT_END_THREAD
    EVT_CALL(N(func_80242014_8B2084))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, -168, -15, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_001E)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_SadTalk, ANIM_Goombaria_SadIdle, 0, NPC_PARTNER, MSG_CH0_001F)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_Goompa_WearyTalk, ANIM_Goompa_WearyIdle, 0, NPC_Goombario, MSG_CH0_0020)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -79, 0, -10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -22, 0, 12)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.4 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, -79, -10, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
        EVT_CALL(NpcMoveTo, NPC_Goombario, -45, 40, 0)
        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadRun)
        EVT_CALL(NpcMoveTo, NPC_Goombaria, -23, -21, 0)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 30, 35, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_WearyTalk, ANIM_Goompa_WearyIdle, 0, MSG_CH0_0021)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 41, -147, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 127, -157, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 3)
    EVT_CALL(NpcFacePlayer, NPC_Goombario, 3)
    EVT_CALL(PlayerFaceNpc, NPC_Goombario, 3)
    EVT_IF_EQ(GF_KMR04_Tree3_Dolly, TRUE)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-350.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_Goombario, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0022)
        EVT_WAIT(10 * DT)
        EVT_CALL(ShowChoice, MSG_Choice_0011)
        EVT_WAIT(10 * DT)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(CloseMessage)
                EVT_CALL(FindKeyItem, ITEM_DOLLY, LVar0)
                EVT_CALL(RemoveKeyItemAt, LVar0)
                EVT_CALL(PlayerFaceNpc, NPC_Goombaria, TRUE)
                EVT_CALL(PlayerMoveTo, -50, -24, 0)
                EVT_CALL(InterpPlayerYaw, 94, 0)
                EVT_WAIT(10 * DT)
                EVT_EXEC_WAIT(N(EVS_HandOverDolly))
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_SadTalk, ANIM_Goombaria_SadIdle, 0, MSG_CH0_0024)
                EVT_WAIT(10 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Inspect)
                EVT_CALL(InterpNpcYaw, NPC_Goombaria, 90, 1)
                EVT_WAIT(10 * DT)
                EVT_CALL(InterpNpcYaw, NPC_Goombaria, 270, 1)
                EVT_WAIT(10 * DT)
                EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0025)
                EVT_WAIT(10 * DT)
                EVT_GIVE_STAR_PIECE()
                EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0026)
                EVT_WAIT(10 * DT)
                EVT_EXEC(N(EVS_Goombaria_Kiss))
                EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_Goombaria, -30, 0, -19, 10)
                EVT_WAIT(10 * DT)
                EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHIVER, 1, 1, 0)
                EVT_WAIT(35 * DT)
                EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(3.0 / DT))
                EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Walk)
                EVT_CALL(NpcMoveTo, NPC_Goombaria, -23, -21, 0)
                EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
                EVT_CALL(NpcFacePlayer, NPC_Goombaria, 3)
                EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
                EVT_CALL(PlayerMoveTo, -85, -10, 0)
                EVT_CALL(PlayerFaceNpc, NPC_Goombaria, TRUE)
                EVT_WAIT(20 * DT)
            EVT_CASE_EQ(1)
                EVT_CALL(ContinueSpeech, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0023)
                EVT_SET(GF_KMR02_KeptDolly, TRUE)
                EVT_WAIT(10)
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), 30, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_WAIT(60 * DT)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), 30, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_WAIT(60 * DT)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0027)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0028)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0029)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT), 40, EVT_FLOAT(-350.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_PARTNER, 127, 0, -157)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 32, -151, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_PARTNER, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombario, LVar0, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PARTNER, 3)
    EVT_SET(LVar0, 30)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002A)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_002B)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 3, 9, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(PlayerFaceNpc, NPC_PARTNER, 3)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002C)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Walk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, -60, -14, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_WAIT(10 * DT)
    EVT_GIVE_BADGE_REWARD(ITEM_POWER_JUMP)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Walk)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 3, 9, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_PromptForBadgeTutorial))
    EVT_CALL(EnableNpcAI, NPC_Goombario, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Goombaria, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Gooma, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Goomama, FALSE)
    EVT_CALL(N(LoadHeartBlockMsgImg))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0031)
    EVT_WAIT(10 * DT)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), 30, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0032)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(NpcFacePlayer, NPC_Goombaria, 3)
    EVT_END_THREAD
    EVT_CALL(NpcFacePlayer, NPC_Goombario, 3)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0033)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_PARTNER, LVar0)
        EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 3)
    EVT_END_THREAD
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombario, LVar0, 3)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0034)
    EVT_WAIT(10 * DT)
    EVT_CALL(NpcFacePlayer, NPC_Goombario, 3)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0035)
    EVT_WAIT(10 * DT)
    EVT_CALL(NpcFacePlayer, NPC_Goombaria, 3)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0036)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombario, LVar0, 3)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, NPC_Goombario, MSG_CH0_0037)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_Goombario, EVT_FLOAT(1.2))
    EVT_CALL(GetNpcPos, NPC_Goombario, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Goombario, LVar0, LVar1, LVar2, 7 * DT)
    EVT_CALL(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_0038)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushNewPartnerSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0189, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_Goombario, MSG_CH0_0039)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003A)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 41, -143, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Gooma, ANIM_Gooma_Run)
    EVT_CALL(NpcMoveTo, NPC_Gooma, 127, -157, 0)
    EVT_CALL(SetNpcAnimation, NPC_Gooma, ANIM_Gooma_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 80, -154, 0)
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 111, -200, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(RemoveGoompaPartner))
    EVT_CALL(N(IsPlayerHPFull))
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_003B)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_003C)
    EVT_END_IF
    EVT_CALL(N(ChangeNpcToPartner), NPC_Goombario, PARTNER_GOOMBARIO)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Goombario, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_Gooma, 115, 0, -309)
    EVT_CALL(SetNpcFlagBits, NPC_Gooma, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_FLYING, FALSE)
    EVT_CALL(SetNpcPos, NPC_Goompa, 184, 0, -149)
    EVT_CALL(EnableNpcShadow, NPC_Goompa, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 200, 0, 100)
    EVT_CALL(RestartNpcAI, NPC_Goombaria)
    EVT_CALL(EnableNpcAI, NPC_Gooma, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Goomama, TRUE)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH0_GOOMBARIO_JOINED_PARTY)
    EVT_UNBIND
    EVT_CALL(SetNpcFlagBits, NPC_Goomama, NPC_FLAG_INACTIVE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goompa) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KootFavorCheck_Goompa) = {
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH2_2)
        EVT_IF_EQ(GF_KMR02_Gift_TheTape, FALSE)
            EVT_SET(GF_KMR02_Gift_TheTape, TRUE)
            EVT_EXEC_WAIT(N(EVS_MarioSalute))
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0049)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004A)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2))
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 297, LVar1, -84)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_END_THREAD
            EVT_CALL(GetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Walk)
            EVT_CALL(SetNpcSpeed, NPC_Goompa, EVT_FLOAT(2.0))
            EVT_CALL(NpcMoveTo, NPC_Goompa, 260, -94, 0)
            EVT_CALL(NpcMoveTo, NPC_Goompa, 344, -113, 0)
            EVT_CALL(NpcMoveTo, NPC_Goompa, 381, -93, 0)
            EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Idle)
            EVT_WAIT(30)
            EVT_THREAD
                EVT_WAIT(20)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Walk)
            EVT_CALL(NpcMoveTo, NPC_Goompa, 344, -113, 0)
            EVT_CALL(NpcMoveTo, NPC_Goompa, 260, -94, 0)
            EVT_CALL(NpcMoveTo, NPC_Goompa, LVar0, LVar2, 0)
            EVT_CALL(SetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004B)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_THE_TAPE)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004C)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(AddGoompaRenderYaw)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = resolve_npc(script, NPC_Goompa);

    npc->renderYaw += evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Goompa_TurnAround) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_LOOP(5)
        EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(-18.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Idle)
    EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(-180.0))
    EVT_LOOP(5)
        EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(-18.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goompa_TurnBack) = {
    EVT_LOOP(5)
        EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(18.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Rummage)
    EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(180.0))
    EVT_LOOP(5)
        EVT_CALL(N(AddGoompaRenderYaw), EVT_FLOAT(18.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goompa) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_IF_EQ(GF_KMR02_Met_Goompa, FALSE)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0 * DT), 0, EVT_FLOAT(-275.0), EVT_FLOAT(20.0), EVT_FLOAT(-8.5))
                EVT_EXEC_WAIT(N(EVS_Goompa_TurnAround))
                EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0019)
                EVT_EXEC_WAIT(N(EVS_Goompa_TurnBack))
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 499, 0, -378)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 499, 70, -378)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 370)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 * DT))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_SET(GF_KMR02_Met_Goompa, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                EVT_CALL(SetNpcPos, NPC_Goombaria, 215, 0, 215)
                EVT_CALL(BindNpcAI, NPC_Goombaria, EVT_PTR(N(EVS_NpcAI_GoombaFamily_NoAI)))
                EVT_IF_EQ(GF_KMR02_Met_Goompapa, TRUE)
                    EVT_CALL(SetNpcPos, NPC_Goompapa, 265, 0, 245)
                    EVT_CALL(BindNpcAI, NPC_Goompapa, EVT_PTR(N(EVS_NpcAI_GoombaFamily_NoAI)))
                    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Goompa_TurnAround))
                EVT_IF_EQ(GF_KMR02_Goompa_SwapDialogue, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001A)
                    EVT_SET(GF_KMR02_Goompa_SwapDialogue, TRUE)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001B)
                    EVT_SET(GF_KMR02_Goompa_SwapDialogue, FALSE)
                EVT_END_IF
                EVT_EXEC_WAIT(N(EVS_Goompa_TurnBack))
            EVT_END_IF
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003D)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003E)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003F)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0040)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0041)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0042)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0043)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goompa, MSG_CH0_0044)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Goompa))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Goompa))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_KootFavorCheck_Goompa))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goompa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goompa)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goompa)))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_CALL(SetNpcPos, NPC_SELF, 535, 25, -369)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Rummage)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 200, 0)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CASE_LT(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ReturnToVillage)), TRIGGER_WALL_PRESS_A, COLLIDER_mm1, 1, 0)
        EVT_CASE_GE(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_Goompa, 172, 0, -183)
            EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
            EVT_CALL(RotateModel, MODEL_m_d1, 120, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m_d2, 120, 0, 1, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm1, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BEF8_8BBF68) = {
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Walk)
    EVT_CALL(NpcMoveTo, NPC_Goompapa, 272, 281, 20 * DT)
    EVT_CALL(GetNpcYaw, NPC_Goompapa, LVar3)
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, 180)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar4, 0)
    EVT_WAIT(7)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar3, 0)
    EVT_WAIT(7)
    EVT_CALL(NpcMoveTo, NPC_Goompapa, 266, 228, 20 * DT)
    EVT_CALL(GetNpcYaw, NPC_Goompapa, LVar3)
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, 180)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar4, 0)
    EVT_WAIT(7)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar3, 0)
    EVT_WAIT(7)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goompapa) = {
    EVT_LABEL(0)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH0_MET_GOOMPA)
                EVT_EXEC_WAIT(N(D_8024BEF8_8BBF68))
            EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
                EVT_IF_EQ(GF_KMR02_Met_Goompapa, FALSE)
                    EVT_EXEC_WAIT(N(D_8024BEF8_8BBF68))
                EVT_END_IF
            EVT_CASE_LT(STORY_CH0_SMASHED_GATE_BLOCK)
            EVT_CASE_DEFAULT
                EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goompapa) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_GOOMPA)
            EVT_IF_EQ(GF_KMR02_Met_Goompapa, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0052)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_WAIT(10)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0053)
                EVT_SET(GF_KMR02_Met_Goompapa, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0054)
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH0_MET_GOOMPA)
            EVT_IF_EQ(GF_KMR02_Met_Goompapa, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0056)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_WAIT(10)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
                EVT_WAIT(30)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0057)
                EVT_CALL(BindNpcAI, NPC_Goompapa, EVT_PTR(N(EVS_NpcAI_GoombaFamily_NoAI)))
                EVT_SET(GF_KMR02_Met_Goompapa, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0055)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0058)
            EVT_THREAD
                EVT_CALL(FadeOutMusic, 0, 500)
                EVT_WAIT(45)
                EVT_CALL(FadeInMusic, 0, SONG_KAMMY_KOOPA_THEME, 0, 500, 0, 127)
            EVT_END_THREAD
            EVT_EXEC_WAIT(N(EVS_Scene_KammyStrikes))
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0063)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR02_Goompapa_SaidFarewell, FALSE)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goompapa, MSG_CH0_0064)
                EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldGoombario_Idle)
                EVT_WAIT(10)
                EVT_CALL(EnablePartnerAI)
                EVT_CALL(SpeakToNpc, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, NPC_PARTNER, MSG_CH0_0065)
                EVT_SET(GF_KMR02_Goompapa_SaidFarewell, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0068)
                EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldGoombario_Idle)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0069)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006A)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006B)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006C)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006D)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006E)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterTrade_Goompapa))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Goompapa))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Goompapa))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goompapa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goompapa)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goompapa)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_GOOMPA)
        EVT_CASE_EQ(STORY_CH0_MET_GOOMPA)
            EVT_IF_EQ(GF_KMR02_Met_Goompapa, TRUE)
                EVT_CALL(SetNpcPos, NPC_Goompapa, 265, 0, 245)
                EVT_CALL(BindNpcAI, NPC_Goompapa, EVT_PTR(N(EVS_NpcAI_GoombaFamily_NoAI)))
                EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(N(SetWanderTerritory_Npc), NPC_Goompapa, 0)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_Npc)))
        EVT_CASE_LT(STORY_CH0_SMASHED_GATE_BLOCK)
            EVT_CALL(SetNpcPos, NPC_SELF, 258, 0, 258)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 106, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goomama) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(100)
            EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_CASE_OR_EQ(101)
        EVT_CASE_OR_EQ(102)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(103)
            EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goomama) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_IF_EQ(GF_KMR02_Met_Goomama, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0077)
                EVT_SET(GF_KMR02_Met_Goomama, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0078)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH0_LEFT_THE_PLAYGROUND)
            EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0079)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR02_Goomama_SaidFarewell, FALSE)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007A)
                EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007B)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007C)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007D)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007E)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007F)
                EVT_WAIT(10)
                EVT_SET(GF_KMR02_Goomama_SaidFarewell, TRUE)
                EVT_CALL(EnablePartnerAI)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0080)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0081)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_EQ(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goomama, MSG_CH0_0082)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0083)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0084)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goomama, MSG_CH0_0085)
                EVT_CALL(EnablePartnerAI)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0086)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0087)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomama) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_INNKEEPER)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomama)))
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(N(SetWanderTerritory_Npc), NPC_Goomama, 1)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_Npc)))
        EVT_CASE_LT(STORY_CH0_LEFT_THE_PLAYGROUND)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomama)))
        EVT_CASE_LT(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_SELF, 200, 0, 100)
            EVT_WAIT(1)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomama)))
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomama)))
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomama)))
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goomama)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Gooma) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(100)
            EVT_LABEL(0)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_EQ(STORY_CH0_GOOMBARIO_JOINED_PARTY)
                    EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
            EVT_END_SWITCH
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_CASE_OR_EQ(101)
        EVT_CASE_OR_EQ(102)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(103)
            EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Gooma) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_IF_EQ(GF_KMR02_Met_Gooma, FALSE)
                EVT_SET(GF_KMR02_Met_Gooma, TRUE)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0 * DT), 0, EVT_FLOAT(-275.5), EVT_FLOAT(15.5), EVT_FLOAT(-10.0))
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 5, MSG_CH0_009C)
                EVT_THREAD
                    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 * DT))
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 5, MSG_CH0_009D)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_009E)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR02_Gooma_HealthAdvice, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_009F)
                EVT_SET(GF_KMR02_Gooma_HealthAdvice, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A1)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A2)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A3)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_NE(LVar0, PARTNER_GOOMBARIO)
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A5)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Gooma) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Gooma)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Gooma)))
    EVT_RETURN
    EVT_END
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    EVT_LABEL(0)
        EVT_CALL(N(GetKammyBroomEmitterPos))
        EVT_CALL(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        EVT_SET(LVar3, LVar9)
        EVT_SET(LVar4, LVarA)
        EVT_SET(LVar5, LVarB)
        EVT_SUBF(LVar3, LVar6)
        EVT_SUBF(LVar4, LVar7)
        EVT_SUBF(LVar5, LVar8)
        EVT_SETF(LVar6, LVar9)
        EVT_SETF(LVar7, LVarA)
        EVT_SETF(LVar8, LVarB)
        EVT_IF_NE(LVar3, 0)
            EVT_IF_NE(LVar5, 0)
                EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(3)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(KammyHoverOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Kammy) = {
    EVT_LABEL(0)
        EVT_USE_BUF(EVT_PTR(N(KammyHoverOffsets)))
        EVT_LOOP(ARRAY_COUNT(N(KammyHoverOffsets)))
            EVT_BUF_READ1(LVar1)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_ADD(LVar3, LVar1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_WAIT(3)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kammy)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Kammy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0012)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/SyncStatusBar.inc.c"

NOP_FIX // TODO figure out BSS nop issue
API_CALLABLE(N(func_8024295C_8B29CC)) {
    Bytecode* args = script->ptrReadPos;
    s32 targetColR = evt_get_variable(script, *args++);
    s32 targetColG = evt_get_variable(script, *args++);
    s32 targetColB = evt_get_variable(script, *args++);
    s32 targetColA = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    if (isInitialCall) {
        mdl_get_shroud_tint_params(&N(savedColR), &N(savedColG), &N(savedColB), &N(savedColA));
        script->functionTemp[0] = 0;
    }

    if (duration > 0) {
        mdl_set_shroud_tint_params(
            N(savedColR) + (((targetColR - N(savedColR)) * script->functionTemp[0]) / duration),
            N(savedColG) + (((targetColG - N(savedColG)) * script->functionTemp[0]) / duration),
            N(savedColB) + (((targetColB - N(savedColB)) * script->functionTemp[0]) / duration),
            N(savedColA) + (((targetColA - N(savedColA)) * script->functionTemp[0]) / duration)
        );

        script->functionTemp[0]++;
        if (duration < script->functionTemp[0]) {
            return ApiStatus_DONE2;
        }
    } else {
        mdl_set_shroud_tint_params(targetColR, targetColG, targetColB, targetColA);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
NOP_UNFIX

API_CALLABLE(N(func_80242BA8_8B2C18)) {
    *gBackgroundTintModePtr = ENV_TINT_SHROUD;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242BC0_8B2C30)) {
    Bytecode* args;

    s32 newEnvR, newEnvB, newEnvG;
    s32 newPrimR, newPrimG, newPrimB;
    s32 duration;

    args = script->ptrReadPos;
    newPrimR = evt_get_variable(script, *args++);
    newPrimG = evt_get_variable(script, *args++);
    newPrimB = evt_get_variable(script, *args++);
    newEnvR = evt_get_variable(script, *args++);
    newEnvG = evt_get_variable(script, *args++);
    newEnvB = evt_get_variable(script, *args++);
    duration = evt_get_variable(script, *args++);
    if (isInitialCall) {
        mdl_get_remap_tint_params(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        script->functionTemp[0] = 0;
    }
    if (duration > 0) {
        mdl_set_remap_tint_params(
            oldPrimR + ((newPrimR - oldPrimR) * script->functionTemp[0]) / duration,
            oldPrimG + ((newPrimG - oldPrimG) * script->functionTemp[0]) / duration,
            oldPrimB + ((newPrimB - oldPrimB) * script->functionTemp[0]) / duration,
            oldEnvR  + ( (newEnvR - oldEnvR) * script->functionTemp[0]) / duration,
            oldEnvG  + ( (newEnvG - oldEnvG) * script->functionTemp[0]) / duration,
            oldEnvB  + ( (newEnvB - oldEnvB) * script->functionTemp[0]) / duration);
            script->functionTemp[0]++;
        if (duration < script->functionTemp[0]) {
            return 2;
        }
    } else {
        mdl_set_remap_tint_params(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return 2;
    }
    return 0;
}

API_CALLABLE(N(func_80242F08_8B2F78)) {
    mdl_set_all_tint_type(ENV_TINT_REMAP);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242F28_8B2F98)) {
    mdl_group_set_custom_gfx(MODEL_kinopi, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
    mdl_set_shroud_tint_params(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_EldstarsPlea) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goomama, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Gooma, NPC_FLAG_HIDING, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-375.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(func_80242BA8_8B2C18))
    EVT_CALL(N(func_8024295C_8B29CC), 0, 0, 0, 255, 0)
    EVT_CALL(N(func_80242F08_8B2F78))
    EVT_CALL(N(func_80242BC0_8B2C30), 30, 30, 30, 0, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, MODEL_Root, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_kinopi, MODEL_GROUP_VISIBLE)
    EVT_CALL(EnableModel, MODEL_o561, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FullyRestoreHPandFP)
    EVT_CALL(N(SyncStatusBar))
    EVT_CALL(InterpPlayerYaw, 143, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    EVT_CALL(GetPlayerPos, -220, 33, -342)
    EVT_WAIT(90 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Eldstar_02, SOUND_STAR_SPIRIT_APPEAR_A, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -198, 115, -272, 10)
    EVT_CALL(SetNpcPos, NPC_Eldstar_02, -198, 140, -272)
    EVT_SET(MV_Unk_01, 120)
    EVT_SETF(MV_Unk_00, 0)
    EVT_CALL(BindNpcAI, NPC_Eldstar_02, EVT_PTR(N(EVS_NpcAI_Eldstar_02)))
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 120, 80 * DT, EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_Eldstar_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 2880, 80 * DT, EASING_QUADRATIC_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Eldstar_02, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 140, 60, 80 * DT, EASING_QUADRATIC_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Eldstar_02, -198, LVar0, -272)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(100 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(30.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-160.0), EVT_FLOAT(-310.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar_02, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_CH0_0009)
    EVT_CALL(MakeLerp, 120, 60, 20 * DT, EASING_LINEAR)
    EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Unk_01, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_SETF(MV_Unk_00, 50)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-375.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-190.0), EVT_FLOAT(-310.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(MakeLerp, 60, 0, 40 * DT, EASING_LINEAR)
        EVT_LABEL(6)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_Eldstar_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(6)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(BindNpcAI, NPC_Eldstar_02, EVT_PTR(N(EVS_NpcAI_Eldstar_02_NoAI)))
    EVT_CALL(GetNpcPos, NPC_Eldstar_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_WAIT(15 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Eldstar_02, SOUND_STAR_SPIRIT_APPEAR_A, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcPos, NPC_Eldstar_02, NPC_DISPOSE_LOCATION)
    EVT_WAIT(60 * DT)
    EVT_EXEC(N(EVS_FadeOutMusic))
    EVT_THREAD
        EVT_CALL(N(func_80242F08_8B2F78))
        EVT_CALL(N(func_80242BC0_8B2C30), 255, 255, 255, 0, 0, 0, 50 * DT)
    EVT_END_THREAD
    EVT_WAIT(110 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetGroupVisibility, MODEL_Root, MODEL_GROUP_VISIBLE)
    EVT_CALL(N(func_80242F28_8B2F98))
    EVT_CALL(EnableModel, MODEL_o561, FALSE)
    EVT_CALL(EnableGroup, MODEL_2, FALSE)
    EVT_CALL(EnableGroup, MODEL_4, FALSE)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, -180, 19, -335, 10)
    EVT_CALL(InterpPlayerYaw, 143, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpPlayerYaw, 143, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 323, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 143, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 323, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 143, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 323, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(SetNpcPos, NPC_Toad, -197, 39, -188)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    EVT_CALL(SetNpcFlagBits, NPC_Toad, NPC_FLAG_GRAVITY, TRUE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit7, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, 90, 10 * DT, EASING_LINEAR)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_WAIT(10 * DT)
        EVT_CALL(MakeLerp, 90, 0, 10 * DT, EASING_LINEAR)
        EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilit7, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Toad, -192, -230, 20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000A)
    EVT_WAIT(5 * DT)
    EVT_CALL(NpcMoveTo, NPC_Toad, -160, -310, 33 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000B)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000C)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000D)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
    EVT_WAIT(20 * DT)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(-300.0), EVT_FLOAT(20.0), EVT_FLOAT(-10.0))
    EVT_WAIT(15 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Surprise)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000E)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000F)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 60, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(55 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0010)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0011)
    EVT_WAIT(5 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-375.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(BindNpcInteract, NPC_Toad, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_SET(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s16 N(D_8024E538_8BE5A8)[] = {
    1, 3, 5, 7, 7, 5, 3
};

API_CALLABLE(N(func_80242F7C_8B2FEC)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = N(D_8024E538_8BE5A8)[script->owner2.npcID];
    }

    if (script->functionTemp[3] != 0) {
        script->functionTemp[3]--;
        return ApiStatus_BLOCK;
    }
    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAI_Eldstar_02_NoAI) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Eldstar_02) = {
    EVT_THREAD
        EVT_CALL(N(func_80242F7C_8B2FEC))
    EVT_END_THREAD
    EVT_CALL(RandInt, 100, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_MALLOC_ARRAY(1, LVarA)
    EVT_USE_ARRAY(LVarA)
    EVT_THREAD
        EVT_USE_ARRAY(LVarA)
        EVT_LABEL(0)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_SETF(ArrayVar(0), EVT_FLOAT(10.0))
        EVT_WAIT(LVar0)
        EVT_CALL(RandInt, 100, LVar1)
        EVT_IF_LT(LVar1, 80)
            EVT_SET(LVar1, 1)
        EVT_ELSE
            EVT_SET(LVar1, 2)
        EVT_END_IF
        EVT_LOOP(LVar1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(90.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(100.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(130.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(120.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(110.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(100.0))
            EVT_ADDF(ArrayVar(0), MV_Unk_00)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_SETF(LVar0, EVT_FLOAT(100.0))
    EVT_LABEL(1)
    EVT_LOOP(50)
        EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), 0, MV_Unk_01)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), 0, MV_Unk_01)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GoombaFamily)[] = {
    {
        .id = NPC_Goompa,
        .pos = { 506.0f, 30.0f, -364.0f },
        .yaw = 45,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 506, 30, -364 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 412, 28, -453 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goompa),
        .settings = &N(NpcSettings_GoombaFamily_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMPA_ANIMS,
        .tattle = MSG_NpcTattle_Goompa,
    },
    {
        .id = NPC_Goombaria,
        .pos = { 92.0f, 0.0f, 76.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 92, 0, 76 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 124, 0, -35 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goombaria),
        .settings = &N(NpcSettings_GoombaFamily_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMBARIA_ANIMS,
        .tattle = MSG_NpcTattle_Goombaria,
    },
    {
        .id = NPC_Goombario,
        .pos = { -50.0f, 0.0f, -30.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -50, 0, -30 },
                .wanderSize = { 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -50, 0, -30 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goombario),
        .settings = &N(NpcSettings_GoombaFamily_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMBARIO_ANIMS,
    },
    {
        .id = NPC_Gooma,
        .pos = { 100.0f, 0.0f, -256.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, -256 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 100, 0, -256 },
                .detectSize = { 30 },
            }
        },
        .init = &N(EVS_NpcInit_Gooma),
        .settings = &N(NpcSettings_GoombaFamily_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMA_ANIMS,
        .tattle = MSG_NpcTattle_Gooma,
    },
    {
        .id = NPC_Goompapa,
        .pos = { 163.0f, 0.0f, 283.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 163, 0, 283 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 267, 0, 245 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goompapa),
        .settings = &N(NpcSettings_GoombaFamily_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMPAPA_ANIMS,
        .tattle = MSG_NpcTattle_Goompapa,
    },
};

NpcData N(NpcData_Goomama) = {
    .id = NPC_Goomama,
    .pos = { -200.0f, 0.0f, 100.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 0, 100 },
            .wanderSize = { 70 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -200, 0, 100 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_Goomama),
    .settings = &N(NpcSettings_GoombaFamily_Wander),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = GOOMAMA_ANIMS,
    .tattle = MSG_NpcTattle_Goomama,
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouse)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { -138.0f, 19.0f, -297.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Guard),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_KMR_ToadHouseToad,
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim16,
    ANIM_WorldKammy_Anim13,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_Kammy),
    .settings = &N(NpcSettings_Kammy_Guard),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { -300.0f, 0.0f, 175.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_KMR, QUIZ_COUNT_KMR, QUIZ_MAP_KMR_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

EvtScript N(EVS_NpcInit_Eldstar_01) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_02_ENTRY_5)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_EldstarsPlea)))
        EVT_CALL(SetNpcFlagBits, NPC_Toad, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_Toad, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar_02) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_02_ENTRY_5)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Eldstar_02_NoAI)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    ANIM_Goompa_Still, // ??
    ANIM_LIST_END
};

NpcData N(NpcData_Eldstar_Prologue)[] = {
    {
        .id = NPC_Eldstar_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Eldstar_01),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Eldstar_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Eldstar_02),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
};

EvtScript N(EVS_Goombario_JumpAround) = {
    EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Goombario, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_Goombario, LVarA, LVarB, LVarC)
    EVT_CALL(NpcJump0, NPC_Goombario, LVarA, LVarB, LVarC, 5)
    EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goombaria_JumpAround) = {
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Jump)
    EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_Goombaria, LVarA, LVarB, LVarC)
    EVT_CALL(NpcJump0, NPC_Goombaria, LVarA, LVarB, LVarC, 5)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goombario_RunAround) = {
    EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Goombario, 11, 63, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombario, -42, 17, 0)
    EVT_EXEC_WAIT(N(EVS_Goombario_JumpAround))
    EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Goombario, 11, -71, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombario, 117, -54, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombario, 151, 56, 0)
    EVT_EXEC_WAIT(N(EVS_Goombario_JumpAround))
    EVT_CALL(NpcMoveTo, NPC_Goombario, 70, 51, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombario, 11, 63, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Goombaria_RunAround) = {
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 84, 69, 0)
    EVT_EXEC_WAIT(N(EVS_Goombaria_JumpAround))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 10, 48, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, -48, -58, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 42, -102, 0)
    EVT_EXEC_WAIT(N(EVS_Goombaria_JumpAround))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 133, -20, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 136, 33, 0)
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 84, 69, 0)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetInvitationLetterScale)) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Eldstar_Epilogue) = {
    EVT_EXEC(N(EVS_Goombaria_RunAround))
    EVT_EXEC_WAIT(N(EVS_Goombario_RunAround))
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcPos, NPC_Parakarry, 210, 115, 70)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_000F)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Goombaria, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_Goombaria, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Goombario, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Goombario, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Goombario, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(NpcFlyTo, NPC_Parakarry, 46, 15, 66, 50, 0, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, 270, 0)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 46, 0, 10)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 46, 0, 10)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-6.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0010)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0011)
    EVT_THREAD
        EVT_CALL(DropResizableItemEntity, ITEM_LETTER_TO_KOLORADO, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(SetInvitationLetterScale))
        EVT_LOOP(20)
            EVT_CALL(GetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
            EVT_ADD(LVar1, -12)
            EVT_ADD(LVar2, 4)
            EVT_ADD(LVar3, 5)
            EVT_CALL(SetItemPos, LVar0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(35)
        EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Parakarry, 30, 66, 20)
    EVT_WAIT(35)
    EVT_CALL(NpcMoveTo, NPC_Parakarry, 46, 66, 20)
    EVT_CALL(SetNpcYaw, NPC_Parakarry, 270)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0012)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0013)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
    EVT_CALL(NpcFlyTo, NPC_Parakarry, 210, 115, 70, 50, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0014)
    EVT_THREAD
        EVT_CALL(MakeLerp, 460, 310, 25, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar0, LVar0)
        EVT_DIVF(LVar0, 10)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, 10)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 10)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-6.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Read)
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_Goombaria, EVT_FLOAT(1.0))
    EVT_CALL(NpcMoveTo, NPC_Goombaria, 46, 66, 0)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 5, MSG_Outro_0015)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Read, ANIM_WorldGoombario_Read, 5, MSG_Outro_0016)
    EVT_WAIT(20)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR("nok_02"), nok_02_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar_Epilogue) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 60, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 60, 0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcPos, NPC_Goombario, 11, 0, 63)
    EVT_CALL(SetNpcPos, NPC_Goombaria, 84, 0, 69)
    EVT_CALL(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Eldstar_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombario_Epilogue) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombaria_Epilogue) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Parakarry_Epilogue) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Eldstar_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Eldstar_Epilogue),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Parakarry,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Parakarry_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
    {
        .id = NPC_Goombario,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Goombario_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GOOMBARIO_ANIMS,
    },
    {
        .id = NPC_Goombaria,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Goombaria_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = GOOMBARIA_ANIMS,
    },
};

NpcGroupList N(PrologueNPCs) = {
    NPC_GROUP(N(NpcData_Eldstar_Prologue)),
    NPC_GROUP(N(NpcData_GoombaFamily)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_Kammy)),
    NPC_GROUP(N(NpcData_Goomama)),
    {}
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_GoombaFamily)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_Goomama)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GoombaFamily)),
    NPC_GROUP(N(NpcData_Toad)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    NPC_GROUP(N(NpcData_Goomama)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Epilogue)),
    {}
};
