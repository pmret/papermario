#include "dro_02.h"
#include "sprite/player.h"

EvtScript N(EVS_PartyWatchingMoustafa) = {
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, NPC_Moustafa, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Moustafa, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Moustafa_SetCamBetween) = {
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
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(8.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Moustafa_ResetCam) = {
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Moustafa_Unveiling) = {
    EVT_CALL(SetNpcYaw, NPC_Moustafa, 270)
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_GrabCloak)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_ThrownCloak)
    EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Toss)
    EVT_CALL(SetNpcPos, NPC_Moustafa, -335, 163, -260)
    EVT_EXEC(N(EVS_PlayMoustafaMusic))
    EVT_CALL(MakeLerp, 0, 80, 30 * DT, EASING_CUBIC_OUT)
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
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, NPC_DisguisedMoustafa, 0, NPC_DISPOSE_POS_Y, -250)
    EVT_CALL(SetNpcAnimation, NPC_Moustafa, ANIM_Moustafa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_WAIT(30 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_DisguisedMoustafa) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_BOUGHT_SECRET_ITEMS)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(SetNpcPos, NPC_SELF, -335, 163, -260)
        EVT_CASE_GE(STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, NPC_DISPOSE_POS_Y, -250)
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
                EVT_EXEC(N(EVS_Moustafa_ResetCam))
                EVT_RETURN
            EVT_ELSE
                EVT_CALL(EndSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0)
            EVT_END_IF
            EVT_LABEL(1)
            EVT_CHOOSE_ANY_CONSUMABLE(2)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B8)
                    EVT_EXEC(N(EVS_Moustafa_ResetCam))
                    EVT_RETURN
                EVT_CASE_EQ(-1)
                    EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00B7)
                    EVT_EXEC(N(EVS_Moustafa_ResetCam))
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
                    EVT_EXEC_WAIT(N(EVS_Moustafa_SetCamBetween))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BD)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutDesert, TRUE)
                EVT_CASE_EQ(2)
                    EVT_EXEC_WAIT(N(EVS_Moustafa_SetCamBetween))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BE)
                    EVT_SET(GF_DRO02_Sheek_AskedAboutRuins, TRUE)
                EVT_CASE_EQ(3)
                    EVT_EXEC_WAIT(N(EVS_Moustafa_SetCamBetween))
                    EVT_CALL(ContinueSpeech, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00BF)
                EVT_CASE_EQ(4)
                    EVT_EXEC_WAIT(N(EVS_Moustafa_SetCamBetween))
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
            EVT_EXEC(N(EVS_Moustafa_ResetCam))
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_THREAD
                EVT_WAIT(10 * DT)
                EVT_CALL(func_802D2C14, 1)
            EVT_END_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
            EVT_CALL(PlayerMoveTo, -391, -260, 0)
            EVT_CALL(InterpPlayerYaw, 90, 3)
            EVT_CALL(SetNpcFlagBits, NPC_DisguisedMoustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_EXEC_GET_TID(N(EVS_PartyWatchingMoustafa), LVarA)
            EVT_CALL(SetNpcFlagBits, NPC_Moustafa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(FadeOutMusic, 0, 500)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutMoustafa, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C3)
                EVT_EXEC_WAIT(N(EVS_Moustafa_Unveiling))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_Moustafa, -425, 140, -206, 20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C4)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Talk, ANIM_DisguisedMoustafa_Idle, 0, MSG_CH2_00C5)
                EVT_EXEC_WAIT(N(EVS_Moustafa_Unveiling))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_Moustafa, -425, 140, -206, 20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C6)
            EVT_END_IF
            EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_Moustafa, -337, 140, -200, 20 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C7)
            EVT_CALL(SpeakToPlayer, NPC_Moustafa, ANIM_Moustafa_Shout, ANIM_Moustafa_Idle, 0, MSG_CH2_00C8)
            EVT_CALL(SetNpcJumpscale, NPC_Moustafa, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_Moustafa, -335, 163, -260, 20 * DT)
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
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                            EVT_WAIT(15)
                            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
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
