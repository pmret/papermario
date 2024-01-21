#include "sprite/player.h"

s32 N(DojoBattleIDs)[] = {
    BTL_MAC_FORMATION_00,
    BTL_MAC_FORMATION_01,
    BTL_MAC_FORMATION_02,
    BTL_MAC_FORMATION_03,
    BTL_MAC_FORMATION_04
};

API_CALLABLE(N(SetDojoBattle)) {
    Enemy* enemy = script->owner1.enemy;
    s32 battleIndex = evt_get_variable(script, GB_MAC00_DojoRank);

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = N(DojoBattleIDs)[battleIndex];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ResetBackgroundPostBattle)) {
    mdl_group_set_custom_gfx(MODEL_minka_1, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
    mdl_set_shroud_tint_params(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_Chan) = {
    IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Set(LVar0, MSG_MAC_Gate_0015)
    Else
        Set(LVar0, MSG_MAC_Gate_001B)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Chan_Run, ANIM_Chan_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcAI_Chan) = {
    Call(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_001D)
    Call(SpeakToNpc, NPC_SELF, ANIM_Chan_Run, ANIM_Chan_Idle, 0, NPC_TheMaster, MSG_MAC_Gate_001E)
    Wait(10)
    Thread
        Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(func_802D2C14, 1)
        Call(PlayerMoveTo, 348, -364, 20)
        Call(InterpPlayerYaw, 20, 0)
        Wait(20)
        Call(func_802D2C14, 0)
        Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_Chan_Walk)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(NpcMoveTo, NPC_SELF, 380, -400, 30)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Chan_Idle)
    Call(InterpNpcYaw, NPC_SELF, 225, 0)
    Wait(20)
    Call(N(SetDojoBattle))
    Call(StartBattle)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Chan) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    Call(N(ResetBackgroundPostBattle))
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_Chan_Walk)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(NpcMoveTo, NPC_SELF, 310, -390, 30)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Chan_Idle)
        Call(InterpNpcYaw, NPC_SELF, 45, 0)
    EndThread
    Call(GetBattleOutcome, LVar0)
    Call(SetNpcVar, NPC_TheMaster, 1, LVar0)
    Call(SetNpcVar, NPC_TheMaster, 0, 1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Chan) = {
    IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Call(SetNpcPos, NPC_SELF, 570, 20, -150)
        Call(SetNpcYaw, NPC_SELF, 270)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Chan)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lee) = {
    IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Set(LVar0, MSG_MAC_Gate_0016)
    Else
        Set(LVar0, MSG_MAC_Gate_001C)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Lee_Talk, ANIM_Lee_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcAI_Lee) = {
    Call(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0024)
    Call(SpeakToNpc, NPC_SELF, ANIM_Lee_Talk, ANIM_Lee_Idle, 0, NPC_TheMaster, MSG_MAC_Gate_0025)
    Wait(10)
    Thread
        Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(func_802D2C14, 1)
        Call(PlayerMoveTo, 348, -364, 20)
        Call(InterpPlayerYaw, 20, 0)
        Wait(20)
        Call(func_802D2C14, 0)
        Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_Lee_Walk)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(NpcMoveTo, NPC_SELF, 380, -400, 30)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Lee_Idle)
    Call(InterpNpcYaw, NPC_SELF, 225, 0)
    Wait(20)
    Call(N(SetDojoBattle))
    Call(StartBattle)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Lee) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    Call(N(ResetBackgroundPostBattle))
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_Lee_Walk)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(NpcMoveTo, NPC_SELF, 330, -410, 30)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Lee_Idle)
        Call(InterpNpcYaw, NPC_SELF, 45, 0)
    EndThread
    Call(GetBattleOutcome, LVar0)
    Call(SetNpcVar, NPC_TheMaster, 1, LVar0)
    Call(SetNpcVar, NPC_TheMaster, 0, 1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Lee) = {
    IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Call(SetNpcPos, NPC_SELF, 600, 20, -145)
        Call(SetNpcYaw, NPC_SELF, 270)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lee)))
    Return
    End
};

API_CALLABLE(N(SetPlayer1HP)) {
    gPlayerData.curHP = 1;
    sync_status_bar();
    return ApiStatus_DONE2;
}

// NPC_TheMaster SelfVar indices
enum {
    VAR_FINISHED_BATTLE = 0,
    VAR_BATTLE_OUTCOME  = 1,
    VAR_STARTED_BATTLE  = 2,
};

EvtScript N(EVS_NpcIdle_TheMaster) = {
    Label(0)
        Call(SetSelfVar, VAR_FINISHED_BATTLE, FALSE)
        Call(SetSelfVar, VAR_STARTED_BATTLE, FALSE)
        // wait for battle to start
        Loop(0)
            Call(GetSelfVar, VAR_STARTED_BATTLE, LVar0)
            IfTrue(LVar0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(DisablePlayerInput, TRUE)
        // wait for battle to end
        Loop(0)
            Call(GetSelfVar, VAR_FINISHED_BATTLE, LVar0)
            IfTrue(LVar0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        // handle battle outcomes
        Call(GetSelfVar, VAR_BATTLE_OUTCOME, LVar0)
        Switch(LVar0)
            CaseEq(OUTCOME_PLAYER_LOST)
                Call(N(SetPlayer1HP))
                Call(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0042)
            CaseEq(OUTCOME_PLAYER_FLED)
                Call(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0042)
            CaseEq(OUTCOME_PLAYER_WON)
                Switch(GB_MAC00_DojoRank)
                    CaseEq(0)
                        Set(LVar1, MSG_MAC_Gate_0023)
                        Set(LVar0, ITEM_FIRST_DEGREE_CARD)
                        Set(LVar2, ITEM_FIRST_DEGREE_CARD)
                    CaseEq(1)
                        Set(LVar1, MSG_MAC_Gate_002A)
                        Set(LVar0, ITEM_SECOND_DEGREE_CARD)
                        Set(LVar2, ITEM_FIRST_DEGREE_CARD)
                    CaseEq(2)
                        Set(LVar1, MSG_MAC_Gate_003E)
                        Set(LVar0, ITEM_THIRD_DEGREE_CARD)
                        Set(LVar2, ITEM_SECOND_DEGREE_CARD)
                    CaseEq(3)
                        Set(LVar1, MSG_MAC_Gate_003F)
                        Set(LVar0, ITEM_FOURTH_DEGREE_CARD)
                        Set(LVar2, ITEM_THIRD_DEGREE_CARD)
                    CaseEq(4)
                        Set(LVar1, MSG_MAC_Gate_0040)
                        Set(LVar0, ITEM_DIPLOMA)
                        Set(LVar2, ITEM_FOURTH_DEGREE_CARD)
                EndSwitch
                Add(GB_MAC00_DojoRank, 1)
                Call(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar1)
                Call(FindKeyItem, LVar2, LVar1)
                IfNe(LVar1, -1)
                    Call(RemoveKeyItemAt, LVar1)
                EndIf
                Set(LVar1, 1)
                ExecWait(N(GiveItemReward))
                Call(AddKeyItem, LVar0)
                IfLt(GB_MAC00_DojoRank, 5)
                    Call(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0041)
                EndIf
        EndSwitch
        Call(DisablePlayerInput, FALSE)
        // restart cycle, waiting for the next battle
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Dojo) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    Call(N(ResetBackgroundPostBattle))
    Call(GetBattleOutcome, LVar0)
    Call(SetSelfVar, VAR_BATTLE_OUTCOME, LVar0)
    Call(SetSelfVar, VAR_FINISHED_BATTLE, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_TheMaster_InteractImpl) = {
    Call(DisablePlayerInput, TRUE)
    IfEq(GF_MAC00_Met_TheMaster, FALSE)
        Set(GF_MAC00_Met_TheMaster, TRUE)
        Set(LVar0, MSG_MAC_Gate_0017)
    Else
        Set(LVar0, MSG_MAC_Gate_0018)
    EndIf
    Call(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar0)
    Call(ShowChoice, MSG_Choice_0016)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0019)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    IfGt(GB_MAC00_DojoRank, 4)
        Call(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0043)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(SetSelfVar, VAR_STARTED_BATTLE, TRUE)
    Wait(1)
    Switch(GB_MAC00_DojoRank)
        CaseEq(0)
            Call(BindNpcDefeat, NPC_Chan, Ref(N(EVS_NpcDefeat_Chan)))
            Call(BindNpcAI, NPC_Chan, Ref(N(EVS_NpcAI_Chan)))
            Call(DisablePlayerInput, FALSE)
            Return
        CaseEq(1)
            Call(BindNpcDefeat, NPC_Lee, Ref(N(EVS_NpcDefeat_Lee)))
            Call(BindNpcAI, NPC_Lee, Ref(N(EVS_NpcAI_Lee)))
            Call(DisablePlayerInput, FALSE)
            Return
        CaseEq(2)
            Set(LVar1, MSG_MAC_Gate_002B)
        CaseEq(3)
            Set(LVar1, MSG_MAC_Gate_002C)
        CaseEq(4)
            Set(LVar1, MSG_MAC_Gate_002D)
    EndSwitch
    Call(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar1)
    Wait(10)
    Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Thread
        Call(func_802D2C14, 1)
        Call(PlayerMoveTo, 348, -364, 20)
        Call(InterpPlayerYaw, 20, 0)
        Wait(20)
        Call(func_802D2C14, 0)
    EndThread
    Call(NpcMoveTo, NPC_SELF, 375, -400, 30)
    Call(InterpNpcYaw, NPC_TheMaster, 225, 0)
    Wait(30)
    Call(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Dojo)))
    Wait(1)
    Call(N(SetDojoBattle))
    IfLt(GB_MAC00_DojoRank, 2)
        Call(StartBattle)
    Else
        Call(StartBattleWith, SONG_MASTER_BATTLE)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_TheMaster) = {
    Exec(N(EVS_TheMaster_InteractImpl))
    Wait(30) // purpose unknown -- perhaps somehow prevents double interaction?
    Return
    End
};

EvtScript N(EVS_NpcInit_TheMaster) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TheMaster)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TheMaster)))
    Return
    End
};
