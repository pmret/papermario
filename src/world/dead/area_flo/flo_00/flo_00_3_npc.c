#include "flo_00.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Bubulb_Patrol.inc.c"
#include "world/common/npc/Tolielup.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

API_CALLABLE(N(UpgradeStarPowerCh6)) {
    set_max_star_power(6);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 0, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 700)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -27, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00C4, 0, 50, -200)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_07"), flo_07_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Wisterwood_Introduction) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, -170)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -170)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(75)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH6_0000, 160, 40)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 12)
    EVT_WAIT(10)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(15)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(15)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 800)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-5.8))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -2, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_Dummy_Wisterwood, -1, -1, 5, MSG_CH6_0001)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 350, 0)
    EVT_WAIT(15)
    EVT_CALL(ContinueSpeech, NPC_Dummy_Wisterwood, -1, -1, 5, MSG_CH6_0002)
    EVT_WAIT(10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 333)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(9.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -2, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(func_802D2C14, 1)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0003, 0, 70, -200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.5), EVT_FLOAT(-11.8))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 525)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -14, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0004, 0, 50, -200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(9.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 333)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -2, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0005, 0, 70, -200)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_SET(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_Wisterwood) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerActionState, LVar3)
    EVT_SET(LVar4, 0)
    EVT_IF_EQ(LVar3, ACTION_STATE_IDLE)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_WALK)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_RUN)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar4, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0006, 0, 50, -200)
        EVT_SET(GB_StoryProgress, STORY_CH6_WISTERWOOD_GAVE_HINT)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
        EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_000D, 0, 50, -200)
        EVT_CALL(ShowChoice, MSG_Choice_001F)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_SWITCH(GB_StoryProgress)
                    EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
                        EVT_CALL(SwitchMessage, MSG_CH6_000E)
                    EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
                        EVT_CALL(SwitchMessage, MSG_CH6_000F)
                    EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
                        EVT_CALL(SwitchMessage, MSG_CH6_0010)
                    EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                        EVT_CALL(SwitchMessage, MSG_CH6_0011)
                    EVT_CASE_LT(STORY_CH6_GREW_MAGIC_BEANSTALK)
                        EVT_CALL(SwitchMessage, MSG_CH6_0007)
                    EVT_CASE_LT(STORY_CH6_BEGAN_PEACH_MISSION)
                        EVT_CALL(SwitchMessage, MSG_CH6_0012)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SwitchMessage, MSG_CH6_0013)
                EVT_END_SWITCH
            EVT_CASE_EQ(1)
                EVT_CALL(CloseMessage)
                EVT_EXEC(N(EVS_Wisterwood_Exit))
                EVT_RETURN
            EVT_CASE_EQ(2)
                EVT_CALL(CloseMessage)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0014, 0, 50, -200)
        EVT_CALL(ShowChoice, MSG_Choice_001F)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(SwitchMessage, MSG_CH6_0015)
            EVT_CASE_EQ(1)
                EVT_CALL(CloseMessage)
                EVT_EXEC(N(EVS_Wisterwood_Exit))
                EVT_RETURN
            EVT_CASE_EQ(2)
                EVT_CALL(CloseMessage)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Wisterwood_Farewell) = {
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 600, EVT_FLOAT(21.0), EVT_FLOAT(-12.0))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_000B, 0, 50, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -30)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-25.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_000C, 0, 50, -200)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Wisterwood) = {
    EVT_CALL(EnableGroup, MODEL_ha, FALSE)
    EVT_CALL(EnableGroup, MODEL_tuta, FALSE)
    EVT_CALL(EnableGroup, MODEL_g54, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 50, 70, -230)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
        EVT_EXEC(N(EVS_Wisterwood_Introduction))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb1) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0016)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0017)
        EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0018)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_CH6_0019)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(AF_FLO_PinkBubulbDialogueToggle)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001A)
                    EVT_SET(AF_FLO_PinkBubulbDialogueToggle, TRUE)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001B)
                    EVT_SET(AF_FLO_PinkBubulbDialogueToggle, FALSE)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_HappyTalk, ANIM_Bubulb_Pink_HappyGentle, 0, MSG_CH6_001C)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb2) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001D)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001E)
        EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_001F)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0020)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(AF_FLO_PurpleBubulbDialogueToggle)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0021)
                    EVT_SET(AF_FLO_PurpleBubulbDialogueToggle, TRUE)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0022)
                    EVT_SET(AF_FLO_PurpleBubulbDialogueToggle, FALSE)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH6_0023)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0024)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0025)
        EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0026)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_Talk, ANIM_Bubulb_Green_Idle, 0, MSG_CH6_0027)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(AF_FLO_GreenBubulbDialogueToggle)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_0028)
                    EVT_SET(AF_FLO_GreenBubulbDialogueToggle, TRUE)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_0029)
                    EVT_SET(AF_FLO_GreenBubulbDialogueToggle, FALSE)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Green_HappyTalk, ANIM_Bubulb_Green_HappyGentle, 0, MSG_CH6_002A)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002B)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002C)
        EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002D)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_Talk, ANIM_Bubulb_Yellow_Idle, 0, MSG_CH6_002E)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(AF_FLO_YellowBubulbDialogueToggle)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_002F)
                    EVT_SET(AF_FLO_YellowBubulbDialogueToggle, TRUE)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_0030)
                    EVT_SET(AF_FLO_YellowBubulbDialogueToggle, FALSE)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Yellow_HappyTalk, ANIM_Bubulb_Yellow_HappyGentle, 0, MSG_CH6_0031)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb_01) = {
    EVT_SET(AF_FLO_PinkBubulbDialogueToggle, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb1)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb_02) = {
    EVT_SET(AF_FLO_PurpleBubulbDialogueToggle, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb2)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb_03) = {
    EVT_SET(AF_FLO_GreenBubulbDialogueToggle, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb_04) = {
    EVT_SET(AF_FLO_YellowBubulbDialogueToggle, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Tolielup) = {
    EVT_IF_EQ(GF_FLO00_Met_Tolielup, FALSE)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), -30, 300, EVT_FLOAT(20.0), EVT_FLOAT(-9.5))
        EVT_SET(GF_FLO00_Met_Tolielup, TRUE)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_SWITCH(AB_FLO_TolielupDialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0035)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_GOT_CRYSTAL_BERRY)
            EVT_SWITCH(AB_FLO_TolielupDialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0036)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SWITCH(AB_FLO_TolielupDialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0037)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(AB_FLO_TolielupDialogue)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0039)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
                    EVT_SET(AB_FLO_TolielupDialogue, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_0038)
                    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Tolielup_Talk, ANIM_Tolielup_Idle, 0, MSG_CH6_003A)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Tolielup_Laugh, ANIM_Tolielup_Laugh, 0)
    EVT_END_SWITCH
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tolielup) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Tolielup)))
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 65, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Klevar) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RescuedKlevar) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_SET(LVar4, LVar1)
    EVT_ADD(LVar4, 26)
    EVT_CALL(SetNpcPos, NPC_Klevar, LVar3, LVar4, LVar2)
    EVT_CALL(PlayerFaceNpc, NPC_Klevar, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Klevar, 0)
    EVT_ADD(LVar0, -25)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(475.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00D8)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Klevar, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Leap)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Idle)
    EVT_CALL(EnableNpcAI, NPC_Klevar, TRUE)
    EVT_CALL(N(UpgradeStarPowerCh6))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0196, 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00D9)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, SPEECH_FLAG_200, MSG_CH6_00DA)
    EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Klevar, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Klevar, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_Klevar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(110)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_SET(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
    EVT_EXEC_WAIT(N(EVS_Wisterwood_Farewell))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_NE(LVar1, 1)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, flo_00_ENTRY_A)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Klevar)))
            EVT_EXEC(N(EVS_Scene_RescuedKlevar))
        EVT_ELSE
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Lakilulu) = {
    EVT_IF_LE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_LAKILESTER)
            EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
            EVT_WAIT(10)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 5, MSG_CH6_0033)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldLakilester_Idle)
            EVT_CALL(EndSpeech, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5)
            EVT_CALL(EnablePartnerAI)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0034)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilulu) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Lakilulu)))
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 36, 28)
        EVT_CALL(SetNpcPos, NPC_SELF, -200, 15, -300)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Wisterwood) = {
    .id = NPC_Dummy_Wisterwood,
    .pos = { -72.0f, 60.0f, -100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Wisterwood),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BUBULB_PINK_ANIMS,
};

NpcData N(NpcData_Bubulbs)[] = {
    {
        .id = NPC_Bubulb_01,
        .pos = { -59.0f, 0.0f, -40.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -59, 0, -40 },
                    { -80, 0, -40 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_01),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_PINK_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbA,
    },
    {
        .id = NPC_Bubulb_02,
        .pos = { 67.0f, 0.0f, 85.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 67, 0, 85 },
                    { 97, 0, 85 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_02),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbB,
    },
    {
        .id = NPC_Bubulb_03,
        .pos = { 90.0f, 0.0f, 410.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 90, 0, 410 },
                    { 120, 0, 410 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_03),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbC,
    },
    {
        .id = NPC_Bubulb_04,
        .pos = { 200.0f, 0.0f, 430.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 200, 0, 430 },
                    { 240, 0, 430 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -59, 0, -40 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bubulb_04),
        .settings = &N(NpcSettings_Bubulb_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BUBULB_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_FLO_BubulbD,
    },
};

NpcData N(NpcData_Tolielup) = {
    .id = NPC_Tolielup,
    .pos = { -400.0f, 0.0f, 190.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Tolielup),
    .settings = &N(NpcSettings_Tolielup),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = TOLIELUP_ANIMS,
    .tattle = MSG_NpcTattle_Tolielup,
};

NpcData N(NpcData_Klevar) = {
    .id = NPC_Klevar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Klevar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KLEVAR_ANIMS,
};

NpcData N(NpcData_Lakilulu) = {
    .id = NPC_Lakilulu,
    .pos = { 198.0f, 0.0f, 363.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Lakilulu),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
    .tattle = MSG_NpcTattle_Lakilulu,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Wisterwood)),
    NPC_GROUP(N(NpcData_Bubulbs)),
    NPC_GROUP(N(NpcData_Tolielup)),
    NPC_GROUP(N(NpcData_Klevar)),
    NPC_GROUP(N(NpcData_Lakilulu)),
    {}
};
