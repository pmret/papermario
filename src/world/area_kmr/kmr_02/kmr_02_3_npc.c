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
    Call(N(LetterDelivery_Init),
        NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle,
        ITEM_LETTER_CHAIN_GOOMPAPA_1, ITEM_LETTER_CHAIN_MUSS_T,
        MSG_CH0_006F, MSG_CH0_0070, MSG_CH0_0071, MSG_CH0_0072,
        Ref(N(LetterList_GoompapaTrade)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

s32 N(LetterList_Goompapa)[] = {
    ITEM_LETTER_CHAIN_GOOMPAPA_2,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Goompapa) = {
    Call(N(LetterDelivery_Init),
        NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle,
        ITEM_LETTER_CHAIN_GOOMPAPA_2, ITEM_NONE,
        MSG_CH0_0073, MSG_CH0_0074, MSG_CH0_0075, MSG_CH0_0076,
        Ref(N(LetterList_Goompapa)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Goompapa) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_BADGE_REWARD(ITEM_LUCKY_DAY)
    EndIf
    Return
    End
};

s32 N(LetterList_Goompa)[] = {
    ITEM_LETTER_TO_GOOMPA,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Goompa) = {
    Call(N(LetterDelivery_Init),
        NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle,
        ITEM_LETTER_TO_GOOMPA, ITEM_NONE,
        MSG_CH0_0045, MSG_CH0_0046, MSG_CH0_0047, MSG_CH0_0048,
        Ref(N(LetterList_Goompa)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Goompa) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_GoombaFamily_NoAI) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goombario) = {
    Call(func_800445D4, LVar0)
    Switch(LVar0)
        CaseEq(100)
            ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        CaseOrEq(101)
        CaseOrEq(102)
        CaseOrEq(3)
        CaseOrEq(103)
            ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goombario) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            IfEq(GF_KMR02_Met_Goombario, FALSE)
                Set(GF_KMR02_Met_Goombario, TRUE)
                Call(AdjustCam, CAM_DEFAULT, Float(5.0 * DT), 0, Float(-275.0), Float(15.2), Float(-7.5))
                Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004D)
                Thread
                    Call(ResetCam, CAM_DEFAULT, Float(4.0 * DT))
                EndThread
            Else
                IfEq(GF_KMR02_Goombario_SwapDialogue, FALSE)
                    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004E)
                    Set(GF_KMR02_Goombario_SwapDialogue, TRUE)
                Else
                    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_004F)
                    Set(GF_KMR02_Goombario_SwapDialogue, FALSE)
                EndIf
            EndIf
        CaseEq(STORY_CH0_GATE_CRUSHED)
            Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0051)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombario) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goombario)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goombario)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(N(SetWanderTerritory_Npc), NPC_Goombario, 2)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SwitchedWander_Npc)))
        CaseLt(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            Call(SetNpcPos, NPC_SELF, 66, 0, -126)
        CaseGe(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goombaria_NoAI) = {
    Return
    End
};

EvtScript N(EVS_HandOverDolly) = {
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
    Call(MakeItemEntity, ITEM_DOLLY, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
    Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(RemoveItemEntity, LVar0)
    Return
    End
};

EvtScript N(EVS_Goombaria_Kiss) = {
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LeanOver)
    Call(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    Wait(5)
    Add(LVar1, 10)
    Call(GetAngleToNPC, NPC_Goombaria, LVarA)
    IfGe(LVarA, 180)
        Add(LVar0, 20)
    EndIf
    PlayEffect(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 0)
    Call(PlaySoundAtNpc, NPC_Goombaria, SOUND_HEART_BOUNCE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_Goombaria_RequestDolly) = {
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0096)
    Wait(10)
    IfEq(GF_KMR02_KeptDolly, FALSE)
        Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0097)
    Else
        Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0098)
    EndIf
    Wait(10)
    Call(ShowChoice, MSG_Choice_0011)
    Wait(10)
    IfEq(LVar0, 0)
        Call(FindKeyItem, ITEM_DOLLY, LVar0)
        Call(RemoveKeyItemAt, LVar0)
        ExecWait(N(EVS_HandOverDolly))
        Call(ContinueSpeech, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_009A)
        Wait(10)
        EVT_GIVE_STAR_PIECE()
        Wait(10)
        Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_009B)
        Wait(10)
        Exec(N(EVS_Goombaria_Kiss))
        Call(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_Goombaria, Float(1.0))
        Call(NpcJump0, NPC_Goombaria, LVar0, LVar1, LVar2, 10)
        Wait(10)
        Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHIVER, 1, 1, 0)
        Wait(35)
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
        Call(NpcFacePlayer, NPC_Goombaria, 3)
        Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
        Wait(20)
    Else
        Call(ContinueSpeech, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0099)
        Set(GF_KMR02_KeptDolly, TRUE)
        Wait(10)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goombaria) = {
    Call(HasKeyItem, ITEM_DOLLY, LVar0)
    IfNe(LVar0, 0)
        ExecWait(N(EVS_Goombaria_RequestDolly))
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_GOOMPA)
            Switch(AB_KMR_2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0088)
                    Set(AB_KMR_2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0089)
                    Set(AB_KMR_2, 2)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008A)
                    Set(AB_KMR_2, 1)
            EndSwitch
        CaseLt(STORY_CH0_GATE_CRUSHED)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008B)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008C)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008D)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008E)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008F)
            Else
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_008F)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goombaria, MSG_CH0_0090)
                Call(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_PARTNER, MSG_CH0_0091)
                Call(EnablePartnerAI)
            EndIf
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0092)
            Else
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0093)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goombaria, MSG_CH0_0094)
                Call(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_PARTNER, MSG_CH0_0095)
                Call(EnablePartnerAI)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goombaria)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_GOOMPA)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goombaria_NoAI)))
            Call(SetNpcPos, NPC_SELF, 5, 0, -154)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goombaria_NoAI)))
            Call(SetNpcPos, NPC_SELF, 215, 0, 215)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(N(SetWanderTerritory_Npc), NPC_Goombaria, 3)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SwitchedWander_Npc)))
        CaseLt(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            Call(SetNpcPos, NPC_SELF, 94, 0, -109)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(RemoveNpc, NPC_SELF)
            Return
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
        CaseDefault
    EndSwitch
    Return
    End
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
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002D)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002E)
        Call(ShowChoice, MSG_Choice_0013)
        IfEq(LVar0, 1)
            Call(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002F)
            Return
        EndIf
    EndIf
    Call(ContinueSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0030)
    Wait(10)
    Call(N(WaitForStartInput))
    Call(EndSpeech, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0)
    Wait(10)
    Set(GF_Tutorial_Badges, TRUE)
    Call(N(OpenPauseMenu))
    Call(N(CloseStatusBar))
    Set(GF_Tutorial_Badges, FALSE)
    Return
    End
};

EvtScript N(EVS_ReturnToVillage) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(func_80242014_8B2084))
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001D)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
    Call(NpcMoveTo, NPC_PARTNER, -295, -30, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_USE_KEY, SOUND_SPACE_DEFAULT)
    Wait(15 * DT)
    Call(PlaySoundAtCollider, COLLIDER_mm1, SOUND_GOOMBA_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 120, 20, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_m_d1, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_m_d2, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnablePartnerAI)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    Call(EnableNpcAI, NPC_Goombario, FALSE)
    Call(EnableNpcAI, NPC_Goombaria, FALSE)
    Call(EnableNpcAI, NPC_Gooma, FALSE)
    Call(EnableNpcAI, NPC_Goomama, FALSE)
    Call(SetNpcPos, NPC_Goombario, -95, 0, -86)
    Call(SetNpcPos, NPC_Goombaria, -92, 0, -46)
    Call(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -189, 0, -40)
    Call(SetPanTarget, CAM_DEFAULT, -189, 0, -40)
    Call(SetCamDistance, CAM_DEFAULT, -350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.3 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(SetNpcSpeed, NPC_Goombario, Float(4.0 / DT))
        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
        Call(NpcMoveTo, NPC_Goombario, -109, -61, 0)
        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EndThread
    Thread
        Call(SetNpcSpeed, NPC_Goombaria, Float(4.0 / DT))
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadRun)
        Call(NpcMoveTo, NPC_Goombaria, -142, -95, 0)
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    EndThread
    Thread
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, -238, -33, 0)
    EndThread
    Call(N(func_80242014_8B2084))
    Call(DisablePartnerAI, 0)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    Call(NpcMoveTo, NPC_PARTNER, -168, -15, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_001E)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_SadTalk, ANIM_Goombaria_SadIdle, 0, NPC_PARTNER, MSG_CH0_001F)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_Goompa_WearyTalk, ANIM_Goompa_WearyIdle, 0, NPC_Goombario, MSG_CH0_0020)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, -79, 0, -10)
    Call(SetPanTarget, CAM_DEFAULT, -22, 0, 12)
    Call(SetCamDistance, CAM_DEFAULT, -350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.4 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-6.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(30 * DT)
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, -79, -10, 0)
    EndThread
    Thread
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
        Call(NpcMoveTo, NPC_Goombario, -45, 40, 0)
        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EndThread
    Thread
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadRun)
        Call(NpcMoveTo, NPC_Goombaria, -23, -21, 0)
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_SadIdle)
    EndThread
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    Call(NpcMoveTo, NPC_PARTNER, 30, 35, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_WearyTalk, ANIM_Goompa_WearyIdle, 0, MSG_CH0_0021)
    Wait(10 * DT)
    Call(SetNpcSpeed, NPC_PARTNER, Float(4.0 / DT))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    Call(NpcMoveTo, NPC_PARTNER, 41, -147, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyIdle)
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_WearyWalk)
    Call(NpcMoveTo, NPC_PARTNER, 127, -157, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    Loop(10)
        Add(LVar0, -3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(NpcFacePlayer, NPC_Goombaria, 3)
    Call(NpcFacePlayer, NPC_Goombario, 3)
    Call(PlayerFaceNpc, NPC_Goombario, 3)
    IfEq(GF_KMR04_Tree3_Dolly, TRUE)
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(-350.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-6.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        EndThread
        Wait(30 * DT)
        Call(PlayerFaceNpc, NPC_Goombario, TRUE)
        Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0022)
        Wait(10 * DT)
        Call(ShowChoice, MSG_Choice_0011)
        Wait(10 * DT)
        Switch(LVar0)
            CaseEq(0)
                Call(CloseMessage)
                Call(FindKeyItem, ITEM_DOLLY, LVar0)
                Call(RemoveKeyItemAt, LVar0)
                Call(PlayerFaceNpc, NPC_Goombaria, TRUE)
                Call(PlayerMoveTo, -50, -24, 0)
                Call(InterpPlayerYaw, 94, 0)
                Wait(10 * DT)
                ExecWait(N(EVS_HandOverDolly))
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_SadTalk, ANIM_Goombaria_SadIdle, 0, MSG_CH0_0024)
                Wait(10 * DT)
                Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Inspect)
                Call(InterpNpcYaw, NPC_Goombaria, 90, 1)
                Wait(10 * DT)
                Call(InterpNpcYaw, NPC_Goombaria, 270, 1)
                Wait(10 * DT)
                Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0025)
                Wait(10 * DT)
                EVT_GIVE_STAR_PIECE()
                Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0026)
                Wait(10 * DT)
                Exec(N(EVS_Goombaria_Kiss))
                Call(SetNpcJumpscale, NPC_Goombaria, Float(1.0))
                Call(NpcJump0, NPC_Goombaria, -30, 0, -19, 10)
                Wait(10 * DT)
                Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHIVER, 1, 1, 0)
                Wait(35 * DT)
                Call(SetNpcSpeed, NPC_Goombaria, Float(3.0 / DT))
                Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Walk)
                Call(NpcMoveTo, NPC_Goombaria, -23, -21, 0)
                Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
                Call(NpcFacePlayer, NPC_Goombaria, 3)
                Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
                Call(PlayerMoveTo, -85, -10, 0)
                Call(PlayerFaceNpc, NPC_Goombaria, TRUE)
                Wait(20 * DT)
            CaseEq(1)
                Call(ContinueSpeech, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0023)
                Set(GF_KMR02_KeptDolly, TRUE)
                Wait(10)
        EndSwitch
        Thread
            Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), 30, Float(-275.0), Float(15.0), Float(-6.0))
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        EndThread
        Wait(60 * DT)
    Else
        Thread
            Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), 30, Float(-275.0), Float(15.0), Float(-6.0))
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        EndThread
        Wait(60 * DT)
    EndIf
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0027)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0028)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0029)
    Wait(10 * DT)
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(2.0 / DT), 40, Float(-350.0), Float(15.0), Float(-7.0))
    EndThread
    Call(SetNpcPos, NPC_PARTNER, 127, 0, -157)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    Call(NpcMoveTo, NPC_PARTNER, 32, -151, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(GetAngleBetweenNPCs, NPC_Goombaria, NPC_PARTNER, LVar0)
    Call(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    Call(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    Call(InterpNpcYaw, NPC_Goombario, LVar0, 0)
    Call(PlayerFaceNpc, NPC_PARTNER, 3)
    Set(LVar0, 30)
    Loop(10)
        Add(LVar0, -3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002A)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_002B)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    Call(NpcMoveTo, NPC_PARTNER, 3, 9, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(PlayerFaceNpc, NPC_PARTNER, 3)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_002C)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Walk)
    Call(NpcMoveTo, NPC_PARTNER, -60, -14, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Wait(10 * DT)
    EVT_GIVE_BADGE_REWARD(ITEM_POWER_JUMP)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Walk)
    Call(NpcMoveTo, NPC_PARTNER, 3, 9, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Wait(10 * DT)
    ExecWait(N(EVS_PromptForBadgeTutorial))
    Call(EnableNpcAI, NPC_Goombario, FALSE)
    Call(EnableNpcAI, NPC_Goombaria, FALSE)
    Call(EnableNpcAI, NPC_Gooma, FALSE)
    Call(EnableNpcAI, NPC_Goomama, FALSE)
    Call(N(LoadHeartBlockMsgImg))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0031)
    Wait(10 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), 30, Float(-275.0), Float(15.0), Float(-6.0))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0032)
    Wait(10 * DT)
    Thread
        Call(NpcFacePlayer, NPC_Goombaria, 3)
    EndThread
    Call(NpcFacePlayer, NPC_Goombario, 3)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0033)
    Wait(10 * DT)
    Thread
        Call(GetAngleBetweenNPCs, NPC_Goombaria, NPC_PARTNER, LVar0)
        Call(InterpNpcYaw, NPC_Goombaria, LVar0, 3)
    EndThread
    Call(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    Call(InterpNpcYaw, NPC_Goombario, LVar0, 3)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0034)
    Wait(10 * DT)
    Call(NpcFacePlayer, NPC_Goombario, 3)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0035)
    Wait(10 * DT)
    Call(NpcFacePlayer, NPC_Goombaria, 3)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0036)
    Wait(10 * DT)
    Call(GetAngleBetweenNPCs, NPC_Goombario, NPC_PARTNER, LVar0)
    Call(InterpNpcYaw, NPC_Goombario, LVar0, 3)
    Call(SpeakToNpc, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, NPC_Goombario, MSG_CH0_0037)
    Wait(10 * DT)
    Call(SetNpcJumpscale, NPC_Goombario, Float(1.2))
    Call(GetNpcPos, NPC_Goombario, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Goombario, LVar0, LVar1, LVar2, 7 * DT)
    Call(SpeakToNpc, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_PARTNER, MSG_CH0_0038)
    Call(N(LoadPartyImage))
    Exec(N(EVS_PushNewPartnerSong))
    Wait(10 * DT)
    Call(ShowMessageAtScreenPos, MSG_Menus_0189, 160, 40)
    Exec(N(EVS_PopSong))
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, NPC_Goombario, MSG_CH0_0039)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003A)
    Wait(10 * DT)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    Call(NpcMoveTo, NPC_PARTNER, 41, -143, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_Gooma, ANIM_Gooma_Run)
    Call(NpcMoveTo, NPC_Gooma, 127, -157, 0)
    Call(SetNpcAnimation, NPC_Gooma, ANIM_Gooma_Idle)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
    Call(NpcMoveTo, NPC_PARTNER, 80, -154, 0)
    Call(NpcMoveTo, NPC_PARTNER, 111, -200, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    Loop(10)
        Add(LVar0, -3)
        Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilit5, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(N(RemoveGoompaPartner))
    Call(N(IsPlayerHPFull))
    IfEq(LVar0, 1)
        Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_003B)
    Else
        Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_003C)
    EndIf
    Call(N(ChangeNpcToPartner), NPC_Goombario, PARTNER_GOOMBARIO)
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Goombario, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_Gooma, 115, 0, -309)
    Call(SetNpcFlagBits, NPC_Gooma, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_FLYING, FALSE)
    Call(SetNpcPos, NPC_Goompa, 184, 0, -149)
    Call(EnableNpcShadow, NPC_Goompa, TRUE)
    Call(SetNpcPos, NPC_SELF, 200, 0, 100)
    Call(RestartNpcAI, NPC_Goombaria)
    Call(EnableNpcAI, NPC_Gooma, TRUE)
    Call(EnableNpcAI, NPC_Goomama, TRUE)
    Thread
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    EndThread
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Set(GB_StoryProgress, STORY_CH0_GOOMBARIO_JOINED_PARTY)
    Unbind
    Call(SetNpcFlagBits, NPC_Goomama, NPC_FLAG_INACTIVE, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goompa) = {
    Return
    End
};

EvtScript N(EVS_KootFavorCheck_Goompa) = {
    IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH2_2)
        IfEq(GF_KMR02_Gift_TheTape, FALSE)
            Set(GF_KMR02_Gift_TheTape, TRUE)
            ExecWait(N(EVS_MarioSalute))
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0049)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004A)
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamSpeed, CAM_DEFAULT, Float(0.2))
                Call(SetPanTarget, CAM_DEFAULT, 297, LVar1, -84)
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
            EndThread
            Call(GetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
            Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Walk)
            Call(SetNpcSpeed, NPC_Goompa, Float(2.0))
            Call(NpcMoveTo, NPC_Goompa, 260, -94, 0)
            Call(NpcMoveTo, NPC_Goompa, 344, -113, 0)
            Call(NpcMoveTo, NPC_Goompa, 381, -93, 0)
            Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Idle)
            Wait(30)
            Thread
                Wait(20)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 0)
            EndThread
            Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Walk)
            Call(NpcMoveTo, NPC_Goompa, 344, -113, 0)
            Call(NpcMoveTo, NPC_Goompa, 260, -94, 0)
            Call(NpcMoveTo, NPC_Goompa, LVar0, LVar2, 0)
            Call(SetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
            Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004B)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_THE_TAPE)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_004C)
        EndIf
    EndIf
    Return
    End
};

API_CALLABLE(N(AddGoompaRenderYaw)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = resolve_npc(script, NPC_Goompa);

    npc->renderYaw += evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Goompa_TurnAround) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Loop(5)
        Call(N(AddGoompaRenderYaw), Float(-18.0))
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Idle)
    Call(N(AddGoompaRenderYaw), Float(-180.0))
    Loop(5)
        Call(N(AddGoompaRenderYaw), Float(-18.0))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Goompa_TurnBack) = {
    Loop(5)
        Call(N(AddGoompaRenderYaw), Float(18.0))
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Rummage)
    Call(N(AddGoompaRenderYaw), Float(180.0))
    Loop(5)
        Call(N(AddGoompaRenderYaw), Float(18.0))
        Wait(1)
    EndLoop
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goompa) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            IfEq(GF_KMR02_Met_Goompa, FALSE)
                Call(AdjustCam, CAM_DEFAULT, Float(5.0 * DT), 0, Float(-275.0), Float(20.0), Float(-8.5))
                ExecWait(N(EVS_Goompa_TurnAround))
                Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0019)
                ExecWait(N(EVS_Goompa_TurnBack))
                Call(UseSettingsFrom, CAM_DEFAULT, 499, 0, -378)
                Call(SetPanTarget, CAM_DEFAULT, 499, 70, -378)
                Call(SetCamDistance, CAM_DEFAULT, 370)
                Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 * DT))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Set(GF_KMR02_Met_Goompa, TRUE)
                Set(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                Call(SetNpcPos, NPC_Goombaria, 215, 0, 215)
                Call(BindNpcAI, NPC_Goombaria, Ref(N(EVS_NpcAI_GoombaFamily_NoAI)))
                IfEq(GF_KMR02_Met_Goompapa, TRUE)
                    Call(SetNpcPos, NPC_Goompapa, 265, 0, 245)
                    Call(BindNpcAI, NPC_Goompapa, Ref(N(EVS_NpcAI_GoombaFamily_NoAI)))
                    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
                EndIf
            Else
                ExecWait(N(EVS_Goompa_TurnAround))
                IfEq(GF_KMR02_Goompa_SwapDialogue, FALSE)
                    Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001A)
                    Set(GF_KMR02_Goompa_SwapDialogue, TRUE)
                Else
                    Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_001B)
                    Set(GF_KMR02_Goompa_SwapDialogue, FALSE)
                EndIf
                ExecWait(N(EVS_Goompa_TurnBack))
            EndIf
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003D)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003E)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_003F)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0040)
            Else
                Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0041)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0042)
            Else
                Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_0043)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goompa, MSG_CH0_0044)
                Call(EnablePartnerAI)
            EndIf
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_Goompa))
    ExecWait(N(EVS_LetterReward_Goompa))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    ExecWait(N(EVS_KootFavorCheck_Goompa))
    Return
    End
};

EvtScript N(EVS_NpcInit_Goompa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goompa)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goompa)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            Call(SetNpcPos, NPC_SELF, 535, 25, -369)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Rummage)
            Call(InterpNpcYaw, NPC_SELF, 200, 0)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
        CaseLt(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            BindTrigger(Ref(N(EVS_ReturnToVillage)), TRIGGER_WALL_PRESS_A, COLLIDER_mm1, 1, 0)
        CaseGe(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            Call(SetNpcPos, NPC_Goompa, 172, 0, -183)
            Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
            Call(RotateModel, MODEL_m_d1, 120, 0, -1, 0)
            Call(RotateModel, MODEL_m_d2, 120, 0, 1, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mm1, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mm2, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Return
    End
};

EvtScript N(D_8024BEF8_8BBF68) = {
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Walk)
    Call(NpcMoveTo, NPC_Goompapa, 272, 281, 20 * DT)
    Call(GetNpcYaw, NPC_Goompapa, LVar3)
    Set(LVar4, LVar3)
    Add(LVar4, 180)
    Call(InterpNpcYaw, NPC_Goompapa, LVar4, 0)
    Wait(7)
    Call(InterpNpcYaw, NPC_Goompapa, LVar3, 0)
    Wait(7)
    Call(NpcMoveTo, NPC_Goompapa, 266, 228, 20 * DT)
    Call(GetNpcYaw, NPC_Goompapa, LVar3)
    Set(LVar4, LVar3)
    Add(LVar4, 180)
    Call(InterpNpcYaw, NPC_Goompapa, LVar4, 0)
    Wait(7)
    Call(InterpNpcYaw, NPC_Goompapa, LVar3, 0)
    Wait(7)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goompapa) = {
    Label(0)
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH0_MET_GOOMPA)
                ExecWait(N(D_8024BEF8_8BBF68))
            CaseLt(STORY_CH0_GATE_CRUSHED)
                IfEq(GF_KMR02_Met_Goompapa, FALSE)
                    ExecWait(N(D_8024BEF8_8BBF68))
                EndIf
            CaseLt(STORY_CH0_SMASHED_GATE_BLOCK)
            CaseDefault
                ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goompapa) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_GOOMPA)
            IfEq(GF_KMR02_Met_Goompapa, FALSE)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0052)
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Wait(10)
                Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
                Wait(10)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0053)
                Set(GF_KMR02_Met_Goompapa, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0054)
            EndIf
        CaseEq(STORY_CH0_MET_GOOMPA)
            IfEq(GF_KMR02_Met_Goompapa, FALSE)
                Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0056)
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Wait(10)
                Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
                Wait(30)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0057)
                Call(BindNpcAI, NPC_Goompapa, Ref(N(EVS_NpcAI_GoombaFamily_NoAI)))
                Set(GF_KMR02_Met_Goompapa, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0055)
            EndIf
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0058)
            Thread
                Call(FadeOutMusic, 0, 500)
                Wait(45)
                Call(FadeInMusic, 0, SONG_KAMMY_KOOPA_THEME, 0, 500, 0, 127)
            EndThread
            ExecWait(N(EVS_Scene_KammyStrikes))
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0063)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR02_Goompapa_SaidFarewell, FALSE)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goompapa, MSG_CH0_0064)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldGoombario_Idle)
                Wait(10)
                Call(EnablePartnerAI)
                Call(SpeakToNpc, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, NPC_PARTNER, MSG_CH0_0065)
                Set(GF_KMR02_Goompapa_SaidFarewell, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0068)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldGoombario_Idle)
            EndIf
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0069)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006A)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006B)
            Else
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006C)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006D)
            Else
                Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_006E)
            EndIf
    EndSwitch
    ExecWait(N(EVS_LetterTrade_Goompapa))
    IfNe(LVarC, 0)
        Return
    EndIf
    ExecWait(N(EVS_LetterPrompt_Goompapa))
    ExecWait(N(EVS_LetterReward_Goompapa))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Goompapa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goompapa)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goompapa)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_GOOMPA)
        CaseEq(STORY_CH0_MET_GOOMPA)
            IfEq(GF_KMR02_Met_Goompapa, TRUE)
                Call(SetNpcPos, NPC_Goompapa, 265, 0, 245)
                Call(BindNpcAI, NPC_Goompapa, Ref(N(EVS_NpcAI_GoombaFamily_NoAI)))
                Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
            EndIf
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(N(SetWanderTerritory_Npc), NPC_Goompapa, 0)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SwitchedWander_Npc)))
        CaseLt(STORY_CH0_SMASHED_GATE_BLOCK)
            Call(SetNpcPos, NPC_SELF, 258, 0, 258)
            Call(InterpNpcYaw, NPC_SELF, 106, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goomama) = {
    Call(func_800445D4, LVar0)
    Switch(LVar0)
        CaseEq(100)
            ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        CaseOrEq(101)
        CaseOrEq(102)
        CaseOrEq(3)
        CaseOrEq(103)
            ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goomama) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            IfEq(GF_KMR02_Met_Goomama, FALSE)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0077)
                Set(GF_KMR02_Met_Goomama, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0078)
            EndIf
        CaseLt(STORY_CH0_LEFT_THE_PLAYGROUND)
            Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0079)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR02_Goomama_SaidFarewell, FALSE)
                Call(DisablePartnerAI, 0)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007A)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
                Wait(10)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007B)
                Wait(10)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007C)
                Wait(10)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007D)
                Wait(10)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH0_007E)
                Wait(10)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_007F)
                Wait(10)
                Set(GF_KMR02_Goomama_SaidFarewell, TRUE)
                Call(EnablePartnerAI)
            Else
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0080)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0081)
            Call(GetCurrentPartnerID, LVar0)
            IfEq(LVar0, PARTNER_GOOMBARIO)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goomama, MSG_CH0_0082)
                Call(EnablePartnerAI)
            EndIf
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0083)
            Else
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0084)
                Call(DisablePartnerAI, 0)
                Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Goomama, MSG_CH0_0085)
                Call(EnablePartnerAI)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0086)
            Else
                Call(SpeakToPlayer, NPC_Goomama, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_CH0_0087)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomama) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_INNKEEPER)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomama)))
        CaseLt(STORY_CH0_GATE_CRUSHED)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(N(SetWanderTerritory_Npc), NPC_Goomama, 1)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SwitchedWander_Npc)))
        CaseLt(STORY_CH0_LEFT_THE_PLAYGROUND)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomama)))
        CaseLt(STORY_CH0_GOOMBARIO_JOINED_PARTY)
            Call(SetNpcPos, NPC_SELF, 200, 0, 100)
            Wait(1)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomama)))
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomama)))
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(RemoveNpc, NPC_SELF)
            Return
        CaseDefault
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomama)))
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goomama)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Gooma) = {
    Call(func_800445D4, LVar0)
    Switch(LVar0)
        CaseEq(100)
            Label(0)
            Switch(GB_StoryProgress)
                CaseEq(STORY_CH0_GOOMBARIO_JOINED_PARTY)
                    ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
            EndSwitch
            Wait(1)
            Goto(0)
        CaseOrEq(101)
        CaseOrEq(102)
        CaseOrEq(3)
        CaseOrEq(103)
            ExecWait(N(EVS_NpcAI_GoombaFamily_Wander))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Gooma) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            IfEq(GF_KMR02_Met_Gooma, FALSE)
                Set(GF_KMR02_Met_Gooma, TRUE)
                Call(AdjustCam, CAM_DEFAULT, Float(5.0 * DT), 0, Float(-275.5), Float(15.5), Float(-10.0))
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 5, MSG_CH0_009C)
                Thread
                    Call(ResetCam, CAM_DEFAULT, Float(4.0 * DT))
                EndThread
            Else
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 5, MSG_CH0_009D)
            EndIf
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_009E)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR02_Gooma_HealthAdvice, FALSE)
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_009F)
                Set(GF_KMR02_Gooma_HealthAdvice, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A0)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A1)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A2)
            Else
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A3)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(GetCurrentPartnerID, LVar0)
            IfNe(LVar0, PARTNER_GOOMBARIO)
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A4)
            Else
                Call(SpeakToPlayer, NPC_Gooma, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_CH0_00A5)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Gooma) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Gooma)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Gooma)))
    Return
    End
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    Call(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    Label(0)
        Call(N(GetKammyBroomEmitterPos))
        Call(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        Set(LVar3, LVar9)
        Set(LVar4, LVarA)
        Set(LVar5, LVarB)
        SubF(LVar3, LVar6)
        SubF(LVar4, LVar7)
        SubF(LVar5, LVar8)
        SetF(LVar6, LVar9)
        SetF(LVar7, LVarA)
        SetF(LVar8, LVarB)
        IfNe(LVar3, 0)
            IfNe(LVar5, 0)
                PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
            EndIf
        EndIf
        Wait(3)
        Goto(0)
    Return
    End
};

s32 N(KammyHoverOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Kammy) = {
    Label(0)
        UseBuf(Ref(N(KammyHoverOffsets)))
        Loop(ARRAY_COUNT(N(KammyHoverOffsets)))
            BufRead1(LVar1)
            Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Add(LVar3, LVar1)
            Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Wait(3)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kammy)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Kammy)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad) = {
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0012)
    Return
    End
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
    Call(FadeOutMusic, 0, 500)
    Call(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_HIDING, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_HIDING, TRUE)
    Call(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_HIDING, TRUE)
    Call(SetNpcFlagBits, NPC_Goomama, NPC_FLAG_HIDING, TRUE)
    Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_HIDING, TRUE)
    Call(SetNpcFlagBits, NPC_Gooma, NPC_FLAG_HIDING, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(-375.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(N(func_80242BA8_8B2C18))
    Call(N(func_8024295C_8B29CC), 0, 0, 0, 255, 0)
    Call(N(func_80242F08_8B2F78))
    Call(N(func_80242BC0_8B2C30), 30, 30, 30, 0, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_Root, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_kinopi, MODEL_GROUP_VISIBLE)
    Call(EnableModel, MODEL_o561, FALSE)
    Call(DisablePlayerInput, TRUE)
    Call(FullyRestoreHPandFP)
    Call(N(SyncStatusBar))
    Call(InterpPlayerYaw, 143, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    Call(GetPlayerPos, -220, 33, -342)
    Wait(90 * DT)
    Call(PlaySoundAtNpc, NPC_Eldstar_02, SOUND_STAR_SPIRIT_APPEAR_A, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_SPARKLES, 0, -198, 115, -272, 10)
    Call(SetNpcPos, NPC_Eldstar_02, -198, 140, -272)
    Set(MV_Unk_01, 120)
    SetF(MV_Unk_00, 0)
    Call(BindNpcAI, NPC_Eldstar_02, Ref(N(EVS_NpcAI_Eldstar_02)))
    Thread
        Call(MakeLerp, 0, 120, 80 * DT, EASING_LINEAR)
        Label(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_Eldstar_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 0, 2880, 80 * DT, EASING_QUADRATIC_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Eldstar_02, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 140, 60, 80 * DT, EASING_QUADRATIC_OUT)
        Label(2)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Eldstar_02, -198, LVar0, -272)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndThread
    Wait(100 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(-250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(30.0), Float(-22.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-160.0), Float(-310.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar_02, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_CH0_0009)
    Call(MakeLerp, 120, 60, 20 * DT, EASING_LINEAR)
    Label(5)
        Call(UpdateLerp)
        Set(MV_Unk_01, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(5)
        EndIf
    SetF(MV_Unk_00, 50)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(-375.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-190.0), Float(-310.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Thread
        Call(MakeLerp, 60, 0, 40 * DT, EASING_LINEAR)
        Label(6)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_Eldstar_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(6)
            EndIf
    EndThread
    Call(BindNpcAI, NPC_Eldstar_02, Ref(N(EVS_NpcAI_Eldstar_02_NoAI)))
    Call(GetNpcPos, NPC_Eldstar_02, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Wait(15 * DT)
    Call(PlaySoundAtNpc, NPC_Eldstar_02, SOUND_STAR_SPIRIT_APPEAR_A, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 10)
    Call(SetNpcPos, NPC_Eldstar_02, NPC_DISPOSE_LOCATION)
    Wait(60 * DT)
    Exec(N(EVS_FadeOutMusic))
    Thread
        Call(N(func_80242F08_8B2F78))
        Call(N(func_80242BC0_8B2C30), 255, 255, 255, 0, 0, 0, 50 * DT)
    EndThread
    Wait(110 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    Wait(30 * DT)
    Call(SetGroupVisibility, MODEL_Root, MODEL_GROUP_VISIBLE)
    Call(N(func_80242F28_8B2F98))
    Call(EnableModel, MODEL_o561, FALSE)
    Call(EnableGroup, MODEL_2, FALSE)
    Call(EnableGroup, MODEL_4, FALSE)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, -180, 19, -335, 10)
    Call(InterpPlayerYaw, 143, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(20 * DT)
    Call(InterpPlayerYaw, 143, 3)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 323, 3)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 143, 3)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 323, 3)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 143, 3)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 323, 3)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(SetNpcPos, NPC_Toad, -197, 39, -188)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_GRAVITY, TRUE)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_deilit7, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, 90, 10 * DT, EASING_LINEAR)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Wait(10 * DT)
        Call(MakeLerp, 90, 0, 10 * DT, EASING_LINEAR)
        Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        Call(PlaySoundAtCollider, COLLIDER_deilit7, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(NpcMoveTo, NPC_Toad, -192, -230, 20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000A)
    Wait(5 * DT)
    Call(NpcMoveTo, NPC_Toad, -160, -310, 33 * DT)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000B)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000C)
    Call(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000D)
    Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
    Wait(20 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(-300.0), Float(20.0), Float(-10.0))
    Wait(15 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_Surprise)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000E)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_000F)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Question)
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 60, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(55 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0010)
    Wait(15 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH0_0011)
    Wait(5 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(-375.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPlayerAnimation, ANIM_Mario1_Jump)
    Call(SetPlayerJumpscale, Float(2.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(PlayerJump, LVar0, LVar1, LVar2, 10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(BindNpcInteract, NPC_Toad, Ref(N(EVS_NpcInteract_Toad)))
    Set(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
    Wait(1)
    Call(DisablePlayerInput, FALSE)
    Return
    End
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
    Return
    End
};

EvtScript N(EVS_NpcAI_Eldstar_02) = {
    Thread
        Call(N(func_80242F7C_8B2FEC))
    EndThread
    Call(RandInt, 100, LVar0)
    Add(LVar0, 1)
    Wait(LVar0)
    MallocArray(1, LVarA)
    UseArray(LVarA)
    Thread
        UseArray(LVarA)
        Label(0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        SetF(ArrayVar(0), Float(10.0))
        Wait(LVar0)
        Call(RandInt, 100, LVar1)
        IfLt(LVar1, 80)
            Set(LVar1, 1)
        Else
            Set(LVar1, 2)
        EndIf
        Loop(LVar1)
            SetF(ArrayVar(0), Float(90.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
            SetF(ArrayVar(0), Float(100.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
            SetF(ArrayVar(0), Float(130.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
            SetF(ArrayVar(0), Float(120.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
            SetF(ArrayVar(0), Float(110.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
            SetF(ArrayVar(0), Float(100.0))
            AddF(ArrayVar(0), MV_Unk_00)
            Wait(1)
        EndLoop
        Goto(0)
    EndThread
    SetF(LVar0, Float(100.0))
    Label(1)
    Loop(50)
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), 0, MV_Unk_01)
        Wait(1)
    EndLoop
    Loop(50)
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), 0, MV_Unk_01)
        Wait(1)
    EndLoop
    Goto(1)
    Return
    End
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
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouse)))
    Return
    End
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
    IfNe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_02_ENTRY_5)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_EldstarsPlea)))
        Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcPos, NPC_Toad, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar_02) = {
    IfNe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_02_ENTRY_5)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Eldstar_02_NoAI)))
    EndIf
    Return
    End
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
    Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Jump)
    Call(SetNpcJumpscale, NPC_Goombario, Float(2.0))
    Call(GetNpcPos, NPC_Goombario, LVarA, LVarB, LVarC)
    Call(NpcJump0, NPC_Goombario, LVarA, LVarB, LVarC, 5)
    Call(SetNpcSpeed, NPC_Goombario, Float(3.0))
    Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
    Return
    End
};

EvtScript N(EVS_Goombaria_JumpAround) = {
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Jump)
    Call(SetNpcJumpscale, NPC_Goombaria, Float(2.0))
    Call(GetNpcPos, NPC_Goombaria, LVarA, LVarB, LVarC)
    Call(NpcJump0, NPC_Goombaria, LVarA, LVarB, LVarC, 5)
    Call(SetNpcSpeed, NPC_Goombaria, Float(3.0))
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Return
    End
};

EvtScript N(EVS_Goombario_RunAround) = {
    Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Run)
    Call(SetNpcSpeed, NPC_Goombario, Float(3.0))
    Call(NpcMoveTo, NPC_Goombario, 11, 63, 0)
    Call(NpcMoveTo, NPC_Goombario, -42, 17, 0)
    ExecWait(N(EVS_Goombario_JumpAround))
    Call(SetNpcSpeed, NPC_Goombario, Float(3.0))
    Call(NpcMoveTo, NPC_Goombario, 11, -71, 0)
    Call(NpcMoveTo, NPC_Goombario, 117, -54, 0)
    Call(NpcMoveTo, NPC_Goombario, 151, 56, 0)
    ExecWait(N(EVS_Goombario_JumpAround))
    Call(NpcMoveTo, NPC_Goombario, 70, 51, 0)
    Call(NpcMoveTo, NPC_Goombario, 11, 63, 0)
    Return
    End
};

EvtScript N(EVS_Goombaria_RunAround) = {
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Run)
    Call(SetNpcSpeed, NPC_Goombaria, Float(3.0))
    Call(NpcMoveTo, NPC_Goombaria, 84, 69, 0)
    ExecWait(N(EVS_Goombaria_JumpAround))
    Call(NpcMoveTo, NPC_Goombaria, 10, 48, 0)
    Call(NpcMoveTo, NPC_Goombaria, -48, -58, 0)
    Call(NpcMoveTo, NPC_Goombaria, 42, -102, 0)
    ExecWait(N(EVS_Goombaria_JumpAround))
    Call(NpcMoveTo, NPC_Goombaria, 133, -20, 0)
    Call(NpcMoveTo, NPC_Goombaria, 136, 33, 0)
    Call(NpcMoveTo, NPC_Goombaria, 84, 69, 0)
    Return
    End
};

API_CALLABLE(N(SetInvitationLetterScale)) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Eldstar_Epilogue) = {
    Exec(N(EVS_Goombaria_RunAround))
    ExecWait(N(EVS_Goombario_RunAround))
    Wait(5)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    Call(SetNpcSpeed, NPC_Parakarry, Float(3.0))
    Call(SetNpcPos, NPC_Parakarry, 210, 115, 70)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_000F)
    Wait(10)
    Thread
        Call(PlaySoundAtNpc, NPC_Goombaria, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_Goombaria, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EndThread
    Call(PlaySoundAtNpc, NPC_Goombario, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Goombario, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    Wait(10)
    Call(InterpNpcYaw, NPC_Goombario, 90, 0)
    Call(InterpNpcYaw, NPC_Goombaria, 90, 0)
    Wait(20)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    Call(NpcFlyTo, NPC_Parakarry, 46, 15, 66, 50, 0, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    Call(InterpNpcYaw, NPC_Goombaria, 270, 0)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 46, 0, 10)
        Call(SetPanTarget, CAM_DEFAULT, 46, 0, 10)
        Call(SetCamDistance, CAM_DEFAULT, Float(-300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-6.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Wait(30)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0010)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0011)
    Thread
        Call(DropResizableItemEntity, ITEM_LETTER_TO_KOLORADO, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        Call(N(SetInvitationLetterScale))
        Loop(20)
            Call(GetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
            Add(LVar1, -12)
            Add(LVar2, 4)
            Add(LVar3, 5)
            Call(SetItemPos, LVar0, LVar1, LVar2, LVar3)
            Wait(1)
        EndLoop
        Wait(35)
        Call(RemoveItemEntity, LVar0)
    EndThread
    Call(NpcMoveTo, NPC_Parakarry, 30, 66, 20)
    Wait(35)
    Call(NpcMoveTo, NPC_Parakarry, 46, 66, 20)
    Call(SetNpcYaw, NPC_Parakarry, 270)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0012)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0013)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    Call(SetNpcSpeed, NPC_Parakarry, Float(3.0))
    Call(NpcFlyTo, NPC_Parakarry, 210, 115, 70, 50, 0, EASING_LINEAR)
    Call(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_Outro_0014)
    Thread
        Call(MakeLerp, 460, 310, 25, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        SetF(LVar0, LVar0)
        DivF(LVar0, 10)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, 10)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 10)
        Call(SetCamDistance, CAM_DEFAULT, Float(-300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-6.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    EndThread
    Thread
        Wait(10)
        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Read)
    EndThread
    Call(SetNpcSpeed, NPC_Goombaria, Float(1.0))
    Call(NpcMoveTo, NPC_Goombaria, 46, 66, 0)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 5, MSG_Outro_0015)
    Wait(10)
    Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Read, ANIM_WorldGoombario_Read, 5, MSG_Outro_0016)
    Wait(20)
    Call(FadeOutMusic, 0, 1000)
    Call(GotoMap, Ref("nok_02"), nok_02_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar_Epilogue) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 60, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 60, 0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcPos, NPC_Goombario, 11, 0, 63)
    Call(SetNpcPos, NPC_Goombaria, 84, 0, 69)
    Call(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Goombario, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_GRAVITY, FALSE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Eldstar_Epilogue)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombario_Epilogue) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombaria_Epilogue) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Parakarry_Epilogue) = {
    Return
    End
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
