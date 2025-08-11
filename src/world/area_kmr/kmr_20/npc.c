#include "kmr_20.h"
#include "effects.h"
#include "animation_script.h"
#include "sprite/player.h"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

#include "world/common/npc/Luigi.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(PlaySpringLaunchAnimation)) {
    Entity* entity = get_entity_by_index(0);

    if (entity == nullptr) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/MarioSalute.inc.c"

EvtScript N(EVS_KootFavorCheck_Luigi) = {
    IfNe(GB_KootFavor_Current, KOOT_FAVOR_CH3_1)
        Return
    EndIf
    IfNe(GF_KMR20_Gift_LuigisAutograph, false)
        Return
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    ExecWait(N(EVS_MarioSalute))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0103)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(40)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0104)
    Call(GetNpcYaw, NPC_SELF, LVar0)
    Set(LVar1, LVar0)
    Add(LVar1, 180)
    Call(InterpNpcYaw, NPC_SELF, LVar1, 5)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleBack)
    Wait(40)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Call(InterpNpcYaw, NPC_SELF, LVar0, 5)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0105)
    Wait(10)
    Set(LVar0, ITEM_KOOT_LUIGI_AUTOGRAPH)
    Set(LVar1, 1)
    ExecWait(N(GiveItemReward))
    Call(AddKeyItem, LVar0)
    Set(GF_KMR20_Gift_LuigisAutograph, true)
    IfGe(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        IfLt(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
                Wait(1)
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_LuigiWaitingAround) = {
    Call(DisablePlayerInput, true)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
    Call(SetNpcPos, NPC_Luigi_1, 379, 20, -60)
    Call(InterpNpcYaw, NPC_Luigi_1, 39, 0)
    Call(SetNpcCollisionSize, NPC_Luigi_1, 43, 24)
    Call(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
    Call(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
    Call(SetCamDistance, CAM_DEFAULT, Float(620.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Thread
        Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        Add(LVar1, 25)
        Add(LVar2, 2)
        Loop(3)
            PlayEffect(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
            Wait(13)
            PlayEffect(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
            Wait(22)
        EndLoop
        PlayEffect(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
    EndThread
    Thread
        Loop(3)
            Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
            Wait(10)
            Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_TalkSit)
            Wait(25)
        EndLoop
        Wait(10)
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
    EndThread
    Wait(70)
    Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(80)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 5, MSG_CH0_00DB)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, -30, 40, EMOTER_NPC, 0, 0, 0, 0)
    Wait(25)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
        Call(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
        Call(SetCamDistance, CAM_DEFAULT, Float(620.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Wait(20)
    Set(MF_ReadyForPlayerEntry, true)
    Wait(15)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, true)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_FLYING, false)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Luigi_1, EMOTE_EXCLAMATION, -30, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Luigi_1, LVar0, LVar1, LVar2, 10)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Wait(15)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00DC)
    Thread
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
        Call(NpcMoveTo, NPC_Luigi_1, 531, -128, 50)
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EndThread
    Thread
        Loop(10)
            Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
            Wait(6)
        EndLoop
    EndThread
    Thread
        Wait(10)
        Call(DisablePlayerPhysics, false)
        Call(PlayerMoveTo, 556, -158, 30)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Wait(15)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(NpcMoveTo, NPC_PARTNER, 554, -195, 28)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Wait(3)
    Call(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
    Call(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
    Call(SetCamDistance, CAM_DEFAULT, Float(620.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(15)
    Call(UseSettingsFrom, CAM_DEFAULT, 564, 0, -176)
    Call(SetPanTarget, CAM_DEFAULT, 556, 0, -158)
    Call(SetCamDistance, CAM_DEFAULT, Float(270.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(40)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DD)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Wait(10)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_StillBack)
    Wait(30)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, -30, 30, EMOTER_NPC, 0, 0, 0, 0)
    Wait(30)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_Luigi_1, 524, -152, 10)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Wait(15)
    Thread
        Wait(20)
        Call(InterpNpcYaw, NPC_PARTNER, 39, 0)
        Wait(45)
        Call(InterpNpcYaw, NPC_PARTNER, 219, 0)
    EndThread
    Call(ShowEmote, NPC_Luigi_1, EMOTE_ELLIPSIS, 20, 85, EMOTER_NPC, 0, 0, 0, 0)
    Wait(15)
    Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PARTNER, EMOTE_QUESTION, -20, 70, EMOTER_NPC, 0, 0, 0, 0)
    Wait(110)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DE)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00DF)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E0)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E1)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E2)
        CaseDefault
            Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_STILL, PARTNER_ANIM_HURT, 5, MSG_CH0_00DB)
    EndSwitch
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E3)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_FLYING, true)
    Call(EnablePartnerAI)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.5))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Wait(15)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcAux_Luigi_WhistleAtopObstacle) = {
    Label(20)
        Call(GetNpcVar, NPC_SELF, 0, LVar0)
        IfEq(LVar0, 1)
            Goto(21)
        EndIf
        Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Add(LVarB, 25)
        Add(LVarC, 2)
        PlayEffect(EFFECT_MUSIC_NOTE, 2, LVarA, LVarB, LVarC)
        Wait(13)
        Call(GetNpcVar, NPC_SELF, 0, LVar0)
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Add(LVarB, 25)
        Add(LVarC, 2)
        PlayEffect(EFFECT_MUSIC_NOTE, 2, LVarA, LVarB, LVarC)
        IfEq(LVar0, 1)
            Goto(21)
        EndIf
        Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_TalkSit)
        Wait(22)
        Goto(20)
    Label(21)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Luigi_InBasement) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Label(10)
        Wait(1)
        IfEq(MF_Unk_0C, false)
            Goto(10)
        EndIf
    Label(20)
        IfEq(MF_Unk_0C, false)
            Goto(10)
        EndIf
        Call(GetNpcVar, NPC_SELF, 0, LVar0)
        IfEq(LVar0, 1)
            Goto(21)
        EndIf
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Add(LVarA, 6)
        Add(LVarB, 58)
        Add(LVarC, 2)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(20)
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Sub(LVarA, 4)
        Add(LVarB, 55)
        Sub(LVarC, 1)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        IfEq(MF_Unk_0C, false)
            Goto(10)
        EndIf
        Call(GetNpcVar, NPC_SELF, 0, LVar0)
        IfEq(LVar0, 1)
            Goto(21)
        EndIf
        Wait(28)
        Goto(20)
    Label(21)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Luigi_InBedroom) = {
    Label(10)
        Set(LVar0, MF_Unk_0C)
        IfEq(LVar0, 1)
            Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_INVISIBLE, false)
        Else
            Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_INVISIBLE, true)
        EndIf
        Wait(3)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Scene_CaughtLuigiInBasement) = {
    Set(GF_KMR20_CaughtLuigiInBasement, true)
    Set(AF_KMR_0C, true)
    Call(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Idle)
    Call(SetNpcVar, NPC_Luigi_0, 0, 1)
    Wait(1)
    Call(DisablePlayerInput, true)
    Wait(2)
    Thread
        Wait(20)
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Add(LVarB, 45)
        Add(LVarC, 1)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        Wait(25)
        PlayEffect(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
    EndThread
    Wait(20)
    Thread
        Call(GetNpcPos, NPC_Luigi_0, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.5))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Wait(25)
    Call(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E9)
    Wait(15)
    Call(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    Wait(25)
    Call(InterpNpcYaw, NPC_Luigi_0, 90, 0)
    Wait(6)
    Call(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    Wait(5)
    Thread
        Call(GetNpcPos, NPC_Luigi_0, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Luigi_0, LVar0, LVar1, LVar2, 9)
    EndThread
    Call(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EA)
    Call(InterpNpcYaw, NPC_Luigi_0, 90, 0)
    Wait(5)
    Call(EnableModel, MODEL_o200, false)
    Call(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    Wait(5)
    Call(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EB)
    Wait(3)
    Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_Luigi_0, -130, -17, 15)
    Call(NpcJump0, NPC_Luigi_0, -145, -54, -45, 10)
    Call(PlaySoundAtNpc, NPC_Luigi_0, SOUND_SPRING, SOUND_SPACE_DEFAULT)
    Call(N(PlaySpringLaunchAnimation))
    Thread
        Wait(3)
        Exec(N(EVS_SecretPanel_Flip))
    EndThread
    Call(NpcJump0, NPC_Luigi_0, -145, 30, -45, 20)
    Thread
        Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
        Call(NpcMoveTo, NPC_Luigi_0, 20, -80, 15)
        Call(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Idle)
        Call(SetNpcPos, NPC_Luigi_0, 48, 30, -5)
        Call(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Luigi_ReadingMail) = {
    Label(10)
    IfEq(MF_Unk_0C, false)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, true)
        Wait(1)
        Goto(10)
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar0, 0)
        Wait(1)
        Goto(10)
    EndIf
    Call(DisablePlayerInput, true)
    Set(GF_KMR20_CaughtLuigiReadingLetter, true)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, -30, 15, EMOTER_NPC, 0, 0, 0, 0)
    Wait(15)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Wait(10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_SELF, 37, -72, 16)
    Call(InterpPlayerYaw, 90, 0)
    Call(DisablePlayerInput, false)
    Call(NpcMoveTo, NPC_SELF, 42, -6, 10)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Luigi) = {
    Call(SetNpcSpeed, NPC_SELF, Float(3.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(SetSelfVar, 0, 0)
    Label(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_SELF, 635, -108, 0)
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 0)
        Goto(100)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_SELF, 528, 20, 0)
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 0)
        Goto(100)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_SELF, 635, -108, 0)
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 0)
        Goto(100)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_SELF, 528, 20, 0)
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 0)
        Goto(100)
    EndIf
    Goto(10)
    Label(100)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Call(InterpNpcYaw, NPC_SELF, 39, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Luigi) = {
    IfEq(MF_LuigiWaiting, true)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E5)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E6)
            CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E7)
            CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E8)
            CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00ED)
            CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
                IfEq(GF_KMR20_ChasedOffShyGuy, false)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00EE)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00EF)
                EndIf
            CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F0)
            CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F1)
            CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F2)
            CaseLt(STORY_EPILOGUE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 16, MSG_CH0_00F3)
        EndSwitch
    EndIf
    ExecWait(N(EVS_KootFavorCheck_Luigi))
    IfNe(MF_LuigiWaiting, true)
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            EndCaseGroup
            CaseLt(STORY_EPILOGUE)
                Call(InterpNpcYaw, NPC_SELF, 39, 5)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Luigi_0) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Call(SetNpcCollisionSize, NPC_SELF, 45, 24)
    IfEq(MF_LuigiWaiting, true)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Luigi)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, -145, 30, -50)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Luigi_InBedroom)))
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            IfEq(GF_KMR20_CaughtLuigiInBasement, false)
                Call(SetNpcPos, NPC_SELF, -83, -80, -54)
                Call(InterpNpcYaw, NPC_SELF, 90, 0)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Luigi_InBasement)))
                Set(MF_LuigiInBasement, true)
            Else
                Call(SetNpcPos, NPC_Luigi_0, 48, 30, -5)
                Call(InterpNpcYaw, NPC_Luigi_0, 90, 0)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            IfEq(GF_KMR20_CaughtLuigiReadingLetter, false)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_ReadLetter)
                Call(SetNpcPos, NPC_SELF, -102, 30, -85)
                Call(InterpNpcYaw, NPC_SELF, 270, 0)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Luigi_ReadingMail)))
            Else
                Call(SetNpcPos, NPC_SELF, 42, 30, -6)
                Call(InterpNpcYaw, NPC_SELF, 90, 0)
            EndIf
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_EPILOGUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Luigi_1) = {
    Call(SetNpcVar, NPC_SELF, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    Call(SetNpcCollisionSize, NPC_SELF, 45, 24)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Luigi)))
    IfEq(MF_LuigiWaiting, true)
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Call(SetNpcPos, NPC_SELF, 500, 0, -200)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, 300, 50, 150)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, 560, 0, -75)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Luigi)))
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(SetNpcPos, NPC_SELF, 300, 50, 150)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, 300, 115, 150)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        CaseLt(STORY_EPILOGUE)
            Call(SetNpcPos, NPC_SELF, 306, 30, -145)
            Call(InterpNpcYaw, NPC_SELF, 39, 0)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER, true)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Luigi_0) = {
    .id = NPC_Luigi_0,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Luigi_0),
    .settings = &N(NpcSettings_Luigi),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = LUIGI_ANIMS,
    .tattle = MSG_NpcTattle_Luigi,
};

NpcData N(NpcData_Luigi_1) = {
    .id = NPC_Luigi_1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Luigi_1),
    .settings = &N(NpcSettings_Luigi),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = LUIGI_ANIMS,
    .tattle = MSG_NpcTattle_Luigi,
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    Call(SetNpcPos, NPC_SELF, 500, 0, -195)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Loop(0)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 482, 0, -286, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 726, 0, -153, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 603, 0, 0, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 557, 0, 130, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 357, 0, 87, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 344, 30, -8, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 276, 138, 22, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 360, 61, -117, 15)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 427, 55, -182, 15)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    Call(DisablePlayerInput, true)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 495, 0, -108, 15)
    Wait(3)
    Call(NpcMoveTo, NPC_SELF, 550, -170, 15)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 594, 30, -220, 15)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetNpcImgFXFlags, NPC_SELF, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 10)
    Loop(30)
        Sub(LVar1, 1)
        Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcHit_ShyGuy) = {
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Set(GF_KMR20_ChasedOffShyGuy, true)
    Call(SetNpcVar, NPC_Luigi_1, 0, 1)
    Wait(2)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, true)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    IfNe(GF_KMR20_ChasedOffShyGuy, false)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_ShyGuy)))
    Return
    End
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Stationary),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Luigi_0)),
    NPC_GROUP(N(NpcData_Luigi_1)),
    NPC_GROUP(N(NpcData_ShyGuy)),
    {}
};
