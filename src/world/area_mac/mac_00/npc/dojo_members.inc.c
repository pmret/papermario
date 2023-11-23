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
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_SET(LVar0, MSG_MAC_Gate_0015)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Gate_001B)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chan_Run, ANIM_Chan_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Chan) = {
    EVT_CALL(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_001D)
    EVT_CALL(SpeakToNpc, NPC_SELF, ANIM_Chan_Run, ANIM_Chan_Idle, 0, NPC_TheMaster, MSG_MAC_Gate_001E)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(func_802D2C14, 1)
        EVT_CALL(PlayerMoveTo, 348, -364, 20)
        EVT_CALL(InterpPlayerYaw, 20, 0)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Chan_Walk)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(NpcMoveTo, NPC_SELF, 380, -400, 30)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Chan_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 225, 0)
    EVT_WAIT(20)
    EVT_CALL(N(SetDojoBattle))
    EVT_CALL(StartBattle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Chan) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    EVT_CALL(N(ResetBackgroundPostBattle))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Chan_Walk)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(NpcMoveTo, NPC_SELF, 310, -390, 30)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Chan_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 0)
    EVT_END_THREAD
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_CALL(SetNpcVar, NPC_TheMaster, 1, LVar0)
    EVT_CALL(SetNpcVar, NPC_TheMaster, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Chan) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(SetNpcPos, NPC_SELF, 570, 20, -150)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Chan)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Lee) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_SET(LVar0, MSG_MAC_Gate_0016)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Gate_001C)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lee_Talk, ANIM_Lee_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Lee) = {
    EVT_CALL(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0024)
    EVT_CALL(SpeakToNpc, NPC_SELF, ANIM_Lee_Talk, ANIM_Lee_Idle, 0, NPC_TheMaster, MSG_MAC_Gate_0025)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(func_802D2C14, 1)
        EVT_CALL(PlayerMoveTo, 348, -364, 20)
        EVT_CALL(InterpPlayerYaw, 20, 0)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
        EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lee_Walk)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(NpcMoveTo, NPC_SELF, 380, -400, 30)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lee_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 225, 0)
    EVT_WAIT(20)
    EVT_CALL(N(SetDojoBattle))
    EVT_CALL(StartBattle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Lee) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    EVT_CALL(N(ResetBackgroundPostBattle))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lee_Walk)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(NpcMoveTo, NPC_SELF, 330, -410, 30)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lee_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 0)
    EVT_END_THREAD
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_CALL(SetNpcVar, NPC_TheMaster, 1, LVar0)
    EVT_CALL(SetNpcVar, NPC_TheMaster, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lee) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(SetNpcPos, NPC_SELF, 600, 20, -145)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Lee)))
    EVT_RETURN
    EVT_END
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
    EVT_LABEL(0)
        EVT_CALL(SetSelfVar, VAR_FINISHED_BATTLE, FALSE)
        EVT_CALL(SetSelfVar, VAR_STARTED_BATTLE, FALSE)
        // wait for battle to start
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, VAR_STARTED_BATTLE, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(DisablePlayerInput, TRUE)
        // wait for battle to end
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, VAR_FINISHED_BATTLE, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        // handle battle outcomes
        EVT_CALL(GetSelfVar, VAR_BATTLE_OUTCOME, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
                EVT_CALL(N(SetPlayer1HP))
                EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0042)
            EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
                EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0042)
            EVT_CASE_EQ(OUTCOME_PLAYER_WON)
                EVT_SWITCH(GB_MAC00_DojoRank)
                    EVT_CASE_EQ(0)
                        EVT_SET(LVar1, MSG_MAC_Gate_0023)
                        EVT_SET(LVar0, ITEM_FIRST_DEGREE_CARD)
                        EVT_SET(LVar2, ITEM_FIRST_DEGREE_CARD)
                    EVT_CASE_EQ(1)
                        EVT_SET(LVar1, MSG_MAC_Gate_002A)
                        EVT_SET(LVar0, ITEM_SECOND_DEGREE_CARD)
                        EVT_SET(LVar2, ITEM_FIRST_DEGREE_CARD)
                    EVT_CASE_EQ(2)
                        EVT_SET(LVar1, MSG_MAC_Gate_003E)
                        EVT_SET(LVar0, ITEM_THIRD_DEGREE_CARD)
                        EVT_SET(LVar2, ITEM_SECOND_DEGREE_CARD)
                    EVT_CASE_EQ(3)
                        EVT_SET(LVar1, MSG_MAC_Gate_003F)
                        EVT_SET(LVar0, ITEM_FOURTH_DEGREE_CARD)
                        EVT_SET(LVar2, ITEM_THIRD_DEGREE_CARD)
                    EVT_CASE_EQ(4)
                        EVT_SET(LVar1, MSG_MAC_Gate_0040)
                        EVT_SET(LVar0, ITEM_DIPLOMA)
                        EVT_SET(LVar2, ITEM_FOURTH_DEGREE_CARD)
                EVT_END_SWITCH
                EVT_ADD(GB_MAC00_DojoRank, 1)
                EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar1)
                EVT_CALL(FindKeyItem, LVar2, LVar1)
                EVT_IF_NE(LVar1, -1)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_END_IF
                EVT_SET(LVar1, 1)
                EVT_EXEC_WAIT(N(GiveItemReward))
                EVT_CALL(AddKeyItem, LVar0)
                EVT_IF_LT(GB_MAC00_DojoRank, 5)
                    EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0041)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        // restart cycle, waiting for the next battle
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Dojo) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_4, TRUE)
    EVT_CALL(N(ResetBackgroundPostBattle))
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_CALL(SetSelfVar, VAR_BATTLE_OUTCOME, LVar0)
    EVT_CALL(SetSelfVar, VAR_FINISHED_BATTLE, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TheMaster_InteractImpl) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_MAC00_Met_TheMaster, FALSE)
        EVT_SET(GF_MAC00_Met_TheMaster, TRUE)
        EVT_SET(LVar0, MSG_MAC_Gate_0017)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Gate_0018)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar0)
    EVT_CALL(ShowChoice, MSG_Choice_0016)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0019)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(GB_MAC00_DojoRank, 4)
        EVT_CALL(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_MAC_Gate_0043)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetSelfVar, VAR_STARTED_BATTLE, TRUE)
    EVT_WAIT(1)
    EVT_SWITCH(GB_MAC00_DojoRank)
        EVT_CASE_EQ(0)
            EVT_CALL(BindNpcDefeat, NPC_Chan, EVT_PTR(N(EVS_NpcDefeat_Chan)))
            EVT_CALL(BindNpcAI, NPC_Chan, EVT_PTR(N(EVS_NpcAI_Chan)))
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_CALL(BindNpcDefeat, NPC_Lee, EVT_PTR(N(EVS_NpcDefeat_Lee)))
            EVT_CALL(BindNpcAI, NPC_Lee, EVT_PTR(N(EVS_NpcAI_Lee)))
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_SET(LVar1, MSG_MAC_Gate_002B)
        EVT_CASE_EQ(3)
            EVT_SET(LVar1, MSG_MAC_Gate_002C)
        EVT_CASE_EQ(4)
            EVT_SET(LVar1, MSG_MAC_Gate_002D)
    EVT_END_SWITCH
    EVT_CALL(ContinueSpeech, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, LVar1)
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_THREAD
        EVT_CALL(func_802D2C14, 1)
        EVT_CALL(PlayerMoveTo, 348, -364, 20)
        EVT_CALL(InterpPlayerYaw, 20, 0)
        EVT_WAIT(20)
        EVT_CALL(func_802D2C14, 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, 375, -400, 30)
    EVT_CALL(InterpNpcYaw, NPC_TheMaster, 225, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcFlagBits, NPC_TheMaster, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Dojo)))
    EVT_WAIT(1)
    EVT_CALL(N(SetDojoBattle))
    EVT_IF_LT(GB_MAC00_DojoRank, 2)
        EVT_CALL(StartBattle)
    EVT_ELSE
        EVT_CALL(StartBattleWith, SONG_MASTER_BATTLE)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TheMaster) = {
    EVT_EXEC(N(EVS_TheMaster_InteractImpl))
    EVT_WAIT(30) // purpose unknown -- perhaps somehow prevents double interaction?
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TheMaster) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TheMaster)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TheMaster)))
    EVT_RETURN
    EVT_END
};
