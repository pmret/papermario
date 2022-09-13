#include "common.h"

#ifndef CHUCK_QUIZMO_NPC_ID
#  error CHUCK_QUIZMO_NPC_ID must be defined for QuizmoData.inc.c
#endif

s32** N(Quizmo_varStash) = NULL;

EvtScript N(EVS_Quizmo_GiveItem_0) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_GiveItem_16) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

u8 N(Quizmo_Answers)[64] = {
    0x02, 0x01, 0x01, 0x02, 0x02, 0x00, 0x02, 0x00,
    0x02, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x02,
    0x00, 0x02, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02,
    0x01, 0x02, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01,
};

QuizRequirement N(Quizmo_Requirements)[] = {
    { STORY_CH0_KAMMY_RETURNED_TO_BOWSER, 0 },
    { STORY_CH1_BEGAN_PEACH_MISSION, 10 },
    { STORY_CH2_BEGAN_PEACH_MISSION, 20 },
    { STORY_CH3_BEGAN_PEACH_MISSION, 30 },
    { STORY_CH4_BEGAN_PEACH_MISSION, 37 },
    { STORY_CH5_STAR_SPRIT_DEPARTED, 44 },
    { STORY_CH6_BEGAN_PEACH_MISSION, 52 },
    { STORY_CH7_BEGAN_PEACH_MISSION, 60 },
    { STORY_EPILOGUE, 64 },
    { 0, 64 }, // end of list
};

EvtScript N(EVS_Quizmo_Exit) = {
    EVT_CALL(N(Quizmo_ShouldQuizmoLeave))
    EVT_IF_LE(LVar0, 1)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_C)
        EVT_WAIT(40)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetQuizCamera) = {
    EVT_CALL(N(Quizmo_GetCamVfov), 0, ArrayVar(0))
    EVT_CALL(N(Quizmo_SetCamVfov), 0, 25) //TODO
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamType, 0, LVar1, LVar2)
    EVT_CALL(SetCamType, 0, LVar1, 0)
    EVT_CALL(GetCamDistance, 0, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, 370)
    EVT_ELSE
        EVT_SETF(LVar0, -370)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, LVar0)
    EVT_CALL(GetCamPitch, 0, LVar0, LVar1)
    EVT_SETF(LVar0, EVT_FLOAT(13.0))
    EVT_SETF(LVar1, EVT_FLOAT(-10.0))
    EVT_CALL(SetCamPitch, 0, LVar0, LVar1)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_OtherCamScript) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamDistance, 0, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, 17)
    EVT_ELSE
        EVT_SETF(LVar0, -17)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, LVar0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ResetCamera) = {
    EVT_CALL(N(Quizmo_SetCamVfov), 0, ArrayVar(0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePlayerToPodium) = {
    EVT_WAIT(20)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), ArrayVar(1), ArrayVar(3), 83, LVar0, LVar1)
    EVT_THREAD
        EVT_SETF(LVar2, 0)
        EVT_LOOP(60)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_MULF(LVar3, LVar2)
            EVT_MULF(LVar4, LVar2)
            EVT_DIVF(LVar3, 60)
            EVT_DIVF(LVar4, 60)
            EVT_ADDF(LVar3, ArrayVar(1))
            EVT_ADDF(LVar4, ArrayVar(3))
            EVT_CALL(SetPlayerPos, LVar3, ArrayVar(2), LVar4)
            EVT_ADDF(LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SETF(LVar3, LVar0)
        EVT_SETF(LVar4, LVar1)
        EVT_ADDF(LVar3, ArrayVar(1))
        EVT_ADDF(LVar4, ArrayVar(3))
        EVT_CALL(SetPlayerPos, LVar3, ArrayVar(2), LVar4)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPlayer))
    EVT_CALL(func_802D2884, ArrayVar(1), ArrayVar(3), 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePartnerToPodium) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVarA, LVarB, LVarC)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, 108, LVar0, LVar1)
    EVT_SETF(LVar5, ArrayVar(2))
    EVT_SUBF(LVar5, LVarB)
    EVT_THREAD
        EVT_CALL(N(Quizmo_UpdatePartnerPosition))
        EVT_SETF(LVar3, LVar0)
        EVT_SETF(LVar4, LVar1)
        EVT_SETF(LVar6, LVar5)
        EVT_ADDF(LVar3, LVarA)
        EVT_ADDF(LVar4, LVarC)
        EVT_ADDF(LVar6, LVarB)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar3, LVar6, LVar4)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPartner))
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MoveQuizmoToMicrophone) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVarA, LVarB, LVarC)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, -70, LVar0, LVar1)
    EVT_THREAD
        EVT_SETF(LVar2, 0)
        EVT_LOOP(60)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_MULF(LVar3, LVar2)
            EVT_MULF(LVar4, LVar2)
            EVT_DIVF(LVar3, 60)
            EVT_DIVF(LVar4, 60)
            EVT_ADDF(LVar3, LVarA)
            EVT_ADDF(LVar4, LVarC)
            EVT_CALL(SetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar3, ArrayVar(2), LVar4)
            EVT_ADDF(LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(NpcFacePlayer, CHUCK_QUIZMO_NPC_ID, 0)
    EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetCharacterPositons) = {
    EVT_EXEC(N(EVS_Quizmo_MovePlayerToPodium))
    EVT_EXEC(N(EVS_Quizmo_MovePartnerToPodium))
    EVT_EXEC_WAIT(N(EVS_Quizmo_MoveQuizmoToMicrophone))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerThinking) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_Question)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerHitBuzzer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Throw)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_RightAnswer) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidairStill)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidair)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10009)
        EVT_WAIT(2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidairStill)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidair)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10009)
        EVT_WAIT(2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidairStill)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimMidair)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10009)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetPlayerPos, LVar0, ArrayVar(2), LVar2)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_WrongAnswer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_ShockStill)
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ReturnPlayerToOriginalPos) = {
    EVT_THREAD
        EVT_CALL(N(Quizmo_AddViewRelativeOffset), ArrayVar(1), ArrayVar(3), 25, LVar0, LVar1)
        EVT_SETF(LVar2, ArrayVar(1))
        EVT_ADDF(LVar2, LVar0)
        EVT_SETF(LVar3, ArrayVar(3))
        EVT_ADDF(LVar3, LVar1)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_JUMP)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar2, LVar3, 40)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, ArrayVar(1), ArrayVar(3), 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_RightAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_RightAnswer), LVar1)
    EVT_WAIT(60)
    EVT_KILL_THREAD(LVar1)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_WrongAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_WrongAnswer), LVar1)
    EVT_WAIT(60)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_KILL_THREAD(LVar1)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_QuizMain) = {
    EVT_IF_GT(GB_CompletedQuizzes, 63)
        EVT_SET(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, ArrayVar(1), ArrayVar(2), ArrayVar(3))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 16)
    EVT_IF_EQ(GB_CompletedQuizzes, 63)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_000A)
    EVT_ELSE
        EVT_IF_EQ(GF_Met_ChuckQuizmo, 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_0009)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_0008)
            EVT_SET(GF_Met_ChuckQuizmo, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_000C)
        EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
        EVT_SET(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_Quizmo_TakingQuiz, 1)
    EVT_CALL(N(Quizmo_HideEntities))
    EVT_CALL(N(Quizmo_HideWorld))
    EVT_EXEC(N(EVS_Quizmo_SetQuizCamera))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_EXEC_GET_TID(N(EVS_Quizmo_SetCharacterPositons), LVar1)
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_000B)
    EVT_CALL(PlaySound, 137)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(LVar1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(Quizmo_CreateStage))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_SET(LVar0, MSG_QuizQuestion_01)
    EVT_ADD(LVar0, GB_CompletedQuizzes)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6, 0, LVar0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Question)
    EVT_SET(LVar0, MSG_QuizChoice_01)
    EVT_ADD(LVar0, GB_CompletedQuizzes)
    EVT_CALL(PlaySound, 142)
    EVT_CALL(ShowChoice, LVar0)
    EVT_KILL_THREAD(LVar1)
    EVT_CALL(StopSound, 142)
    EVT_EXEC(N(EVS_Quizmo_PlayerHitBuzzer))
    EVT_WAIT(15)
    EVT_CALL(PlaySound, 141)
    EVT_CALL(N(Quizmo_UnkStageEffectMode), LVar0)
    EVT_SET(ArrayVar(4), 0)
    EVT_CALL(N(Quizmo_CreateWorker))
    EVT_WAIT(40)
    EVT_CALL(N(Quizmo_UpdateRecords))
    EVT_THREAD
        EVT_WAIT(110)
        EVT_CALL(CloseChoice)
        EVT_SET(ArrayVar(4), 0)
    EVT_END_THREAD
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_7)
        EVT_SET(ArrayVar(4), 1)
        EVT_THREAD
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 1)
            EVT_WAIT(6)
            EVT_WAIT(6)
            EVT_WAIT(6)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 2)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
        EVT_END_THREAD
        EVT_CALL(PlaySound, SOUND_8A)
        EVT_CALL(N(Quizmo_SetVannaAnim_Clap))
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 50)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 83, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_ADD(LVar1, -3)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 58, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_ADD(LVar1, 30)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 93, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_RightAnswer), LVar1)
        EVT_ADD(GB_CompletedQuizzes, 1)
        EVT_IF_GT(GB_CompletedQuizzes, 63)
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_0010)
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(LVar1, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(LVar0, ITEM_STAR_PIECE)
            EVT_SET(LVar1, 3)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, GB_CompletedQuizzes, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_0011)
        EVT_ELSE
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000E)
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(LVar1, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(LVar0, ITEM_STAR_PIECE)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, GB_CompletedQuizzes, 0)
            EVT_IF_EQ(GB_CompletedQuizzes, 1)
                EVT_CALL(SetMessageMsg, EVT_PTR(MessageSingular), 1)
            EVT_ELSE
                EVT_CALL(SetMessageMsg, EVT_PTR(MessagePlural), 1)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MSG_MGM_000F)
        EVT_END_IF
        EVT_SET(LVar0, 1)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_9)
        EVT_SET(ArrayVar(4), 2)
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_CALL(PlaySound, SOUND_8B)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_WrongAnswer), LVar1)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(PlayEffect, 0x2B, 0, LVar2, LVar3, LVar4, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000D)
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_A)
        EVT_LOOP(0)
            EVT_IS_THREAD_RUNNING(LVar1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(N(Quizmo_UnkStageEffectMode), -1)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(PlaySound, SOUND_8F)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(45)
        EVT_CALL(StopSound, SOUND_89)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SetVannaAnim_Wave))
    EVT_CALL(N(Quizmo_DestroyEffects))
    EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
    EVT_EXEC(N(EVS_Quizmo_ResetCamera))
    EVT_CALL(N(Quizmo_FadeInWorld))
    EVT_CALL(N(Quizmo_ShowEntities))
    EVT_SET(GF_Quizmo_TakingQuiz, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_OtherAI) = {
    EVT_CALL(N(Quizmo_ShouldAppear))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_1000000, FALSE)
    EVT_CALL(SetNpcSprite, -1, 0x00AF0001)
    EVT_CALL(N(Quizmo_RenderInit))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Interact) = {
    EVT_USE_ARRAY(EVT_PTR(N(Quizmo_ScriptArray)))
    EVT_SET(GF_Quizmo_ChangedLocation, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_400000, 1)
    EVT_EXEC_WAIT(N(EVS_Quizmo_QuizMain))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_400000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Aux) = {
    EVT_CALL(N(Quizmo_NPC_Aux_Impl))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(Quizmo_MobileAISettings) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_Quizmo_Npc_AI) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(Quizmo_MobileAISettings)))
    EVT_RETURN
    EVT_END
};

// primary quizmo NpcSettings
NpcSettings N(Quizmo_NpcSettings) = {
    .defaultAnim = 0x00AF0001,
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .level = 99,
};

// alternate (unused?) variant of quizmo with AI and NPC_FLAG_100 unset
NpcSettings N(Quizmo_AltNpcSettings) = {
    .defaultAnim = 0x00AF0001,
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .ai = &N(EVS_Quizmo_Npc_AI),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .level = 99,
    .actionFlags = 16,
};
