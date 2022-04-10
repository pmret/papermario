#include "common.h"

// #define CHUCK_QUIZMO_NPC_ID 10

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

Quizmo_Requirements N(Quizmo_Requirements)[] = {
    { STORY_CH0_KAMMY_RETURNED_TO_BOWSER, 0 },
    { STORY_CH1_BEGAN_PEACH_MISSION, 10 },
    { STORY_CH2_BEGAN_PEACH_MISSION, 20 },
    { STORY_CH3_BEGAN_PEACH_MISSION, 30 },
    { STORY_CH4_BEGAN_PEACH_MISSION, 37 },
    { STORY_CH5_STAR_SPRIT_DEPARTED, 44 },
    { STORY_CH6_BEGAN_PEACH_MISSION, 52 },
    { STORY_CH7_BEGAN_PEACH_MISSION, 60 },
    { STORY_EPILOGUE, 64 },
    { 0, 64 },
};

EvtScript N(EVS_Quizmo_Exit) = {
    EVT_CALL(N(Quizmo_GetGameStatus75))
    EVT_IF_LE(EVT_VAR(0), 1)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_C)
        EVT_WAIT_FRAMES(40)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetQuizCamera) = {
    EVT_CALL(N(Quizmo_GetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(N(SetCamVfov), 0, 25) //TODO
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamType, 0, EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamType, 0, EVT_VAR(1), 0)
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 370)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -370)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(GetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(13.0))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(-10.0))
    EVT_CALL(SetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_OtherCamScript) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 30)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 17)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -17)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetCamSpeed, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ResetCamera) = {
    EVT_CALL(N(SetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePlayerToPodium) = {
    EVT_WAIT_FRAMES(20)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_ARRAY(1), EVT_ARRAY(3), 83, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
            EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
            EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
        EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPlayer))
    EVT_CALL(func_802D2884, EVT_ARRAY(1), EVT_ARRAY(3), 0)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePartnerToPodium) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_VAR(10), EVT_VAR(12), 108, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(5), EVT_ARRAY(2))
    EVT_SUBF(EVT_VAR(5), EVT_VAR(11))
    EVT_THREAD
        EVT_CALL(N(Quizmo_UpdatePartnerPosition))
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
        EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
        EVT_ADDF(EVT_VAR(6), EVT_VAR(11))
        EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(6), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPartner))
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MoveQuizmoToMicrophone) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_VAR(10), EVT_VAR(12), -70, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
            EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
            EVT_CALL(SetNpcPos, 10, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(60)
    EVT_CALL(NpcFacePlayer, 10, 0)
    EVT_CALL(SetNpcAnimation, 10, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1)
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
        EVT_CALL(SetPlayerAnimation, ANIM_QUESTION)
        EVT_WAIT_FRAMES(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerHitBuzzer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_THROW)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_RightAnswer) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_ARRAY(2), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_WrongAnswer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_SHOCK_STILL)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ReturnPlayerToOriginalPos) = {
    EVT_THREAD
        EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_ARRAY(1), EVT_ARRAY(3), 25, EVT_VAR(0), EVT_VAR(1))
        EVT_SETF(EVT_VAR(2), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(2), EVT_VAR(0))
        EVT_SETF(EVT_VAR(3), EVT_ARRAY(3))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(1))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x102)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, EVT_VAR(2), EVT_VAR(3), 40)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x106)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, EVT_ARRAY(1), EVT_ARRAY(3), 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_RightAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_RightAnswer), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_WrongAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_WrongAnswer), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};
