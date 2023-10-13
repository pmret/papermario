#include "kkj_29.h"
#include "sprite/player.h"

enum {
    CONTESTANT_LEFT     = 0,
    CONTESTANT_PEACH    = 1,
    CONTESTANT_RIGHT    = 2,
};

enum {
    ANSWER_NONE     = 0,
    ANSWER_PENDING  = 1,
    ANSWER_RIGHT    = 2,
    ANSWER_WRONG    = 3,
};

API_CALLABLE(N(AwaitPlayerBuzzIn)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    script->varTable[0]--;
    if (script->varTable[0] == 0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_GiveItemToKoopatrol) = {
    EVT_CALL(SetNpcAnimation, LVar1, ANIM_WorldKoopatrol_Anim1B)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetNpcPos, LVar1, LVar5, LVar6, LVar7)
    EVT_ADD(LVar6, 40)
    EVT_CALL(MakeItemEntity, LVarA, LVar5, LVar6, LVar7, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(PlaySound, SOUND_JINGLE_GOT_KEY)
    EVT_CALL(ShowMessageAtScreenPos, LVar2, 160, 40)
    EVT_CALL(RemoveItemEntity, LVarB)
    EVT_CALL(SetNpcAnimation, LVar1, ANIM_WorldKoopatrol_Anim03)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_Contestants) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -265, 0, -140)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -265, 0, -140)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateScores) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_IF_EQ(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                EVT_ADD(AB_KKJ29_LeftKoopatrolScore, 1)
            EVT_ELSE
                EVT_IF_GT(AB_KKJ29_LeftKoopatrolScore, 0)
                    EVT_SUB(AB_KKJ29_LeftKoopatrolScore, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_IF_EQ(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                EVT_ADD(AB_KKJ29_PeachScore, 1)
            EVT_ELSE
                EVT_IF_GT(AB_KKJ29_PeachScore, 0)
                    EVT_SUB(AB_KKJ29_PeachScore, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_IF_EQ(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                EVT_ADD(AB_KKJ29_RightKoopatrolScore, 1)
            EVT_ELSE
                EVT_IF_GT(AB_KKJ29_RightKoopatrolScore, 0)
                    EVT_SUB(AB_KKJ29_RightKoopatrolScore, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WaitForBuzzIn) = {
    EVT_CALL(PlaySound, SOUND_LRAW_QUIZ_TICKING)
    EVT_CALL(N(AwaitPlayerBuzzIn))
    EVT_IF_EQ(LVar0, 0) // time's up
        // player took too long, decide who will answer based on score
        EVT_IF_LE(AB_KKJ29_LeftKoopatrolScore, AB_KKJ29_PeachScore)
            EVT_SET(AB_KKJ29_AnsweringContestant, CONTESTANT_LEFT)
        EVT_ELSE
            EVT_SET(LVar0, AB_KKJ29_LeftKoopatrolScore)
            EVT_SUB(LVar0, 1)
            EVT_IF_LT(AB_KKJ29_RightKoopatrolScore, LVar0)
                EVT_SET(AB_KKJ29_AnsweringContestant, CONTESTANT_RIGHT)
            EVT_ELSE
                EVT_SET(AB_KKJ29_AnsweringContestant, CONTESTANT_LEFT)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        // player will answer
        EVT_SET(AB_KKJ29_AnsweringContestant, CONTESTANT_PEACH)
    EVT_END_IF
    EVT_CALL(StopSound, SOUND_LRAW_QUIZ_TICKING)
    EVT_SET(AB_KKJ29_AnswerScore, ANSWER_PENDING)
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            EVT_CALL(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00FA)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_CALL(PlaySoundAtPlayer, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            EVT_CALL(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F9)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_02, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            EVT_CALL(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00FB)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
    EVT_END_SWITCH
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-12.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

// LVar1  question
// LVar2  time
// LVar3  rival giving answer
// LVar4  choice message
// LVar5  rival choice selection
// LVar6  host response to wrong answer
EvtScript N(Script_DoRound) = {
    EVT_CALL(PlaySound, SOUND_QUIZ_NEXT_QUESTION)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, LVar1)
    EVT_SET(LVar0, LVar2)
    // wait for input
    EVT_EXEC_WAIT(N(EVS_WaitForBuzzIn))
    // get an answer
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03, ANIM_WorldKoopatrol_Anim03, 5, LVar3)
            EVT_SET(LVar0, LVar5)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_CALL(ShowChoice, LVar4)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_CALL(SpeakToPlayer, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim03, ANIM_WorldKoopatrol_Anim03, 5, LVar3)
            EVT_SET(LVar0, LVar5)
    EVT_END_SWITCH
    // handle the choice
    EVT_IF_EQ(LVar0, LVar5)
        EVT_CALL(PlaySound, SOUND_APPROVE)
        EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
        EVT_SET(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
        EVT_EXEC_WAIT(N(EVS_UpdateScores))
        EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0110)
    EVT_ELSE
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_CALL(PlaySound, SOUND_AUDIENCE_BOO)
        EVT_SET(AB_KKJ29_AnswerScore, ANSWER_WRONG)
        EVT_EXEC_WAIT(N(EVS_UpdateScores))
        EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, LVar6)
    EVT_END_IF
    EVT_WAIT(30 * DT)
    EVT_SET(AB_KKJ29_AnswerScore, ANSWER_NONE)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_SetCam_Contestants))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Podiums) = {
    EVT_CALL(SetTexPanner, MODEL_o19, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o62, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o88, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x8000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_VerticalStrips) = {
    EVT_CALL(SetTexPanner, MODEL_o22, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_o22, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o63, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_o63, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o89, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_o89, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x8000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Screens) = {
    EVT_CALL(SetTexPanner, MODEL_o27, TEX_PANNER_3)
    EVT_CALL(EnableTexPanning, MODEL_o27, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o64, TEX_PANNER_3)
    EVT_CALL(EnableTexPanning, MODEL_o64, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o90, TEX_PANNER_3)
    EVT_CALL(EnableTexPanning, MODEL_o90, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x4000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Stars) = {
    EVT_CALL(SetTexPanner, MODEL_o25, TEX_PANNER_4)
    EVT_CALL(EnableTexPanning, MODEL_o25, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o65, TEX_PANNER_4)
    EVT_CALL(EnableTexPanning, MODEL_o65, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o91, TEX_PANNER_4)
    EVT_CALL(EnableTexPanning, MODEL_o91, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x4000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FloorTrim) = {
    EVT_CALL(SetTexPanner, MODEL_o32, TEX_PANNER_5)
    EVT_CALL(EnableTexPanning, MODEL_o32, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o69, TEX_PANNER_5)
    EVT_CALL(EnableTexPanning, MODEL_o69, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o95, TEX_PANNER_5)
    EVT_CALL(EnableTexPanning, MODEL_o95, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x8000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_StarTrim) = {
    EVT_CALL(SetTexPanner, MODEL_o31, TEX_PANNER_6)
    EVT_CALL(EnableTexPanning, MODEL_o31, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o67, TEX_PANNER_6)
    EVT_CALL(EnableTexPanning, MODEL_o67, FALSE)
    EVT_CALL(SetTexPanner, MODEL_o93, TEX_PANNER_6)
    EVT_CALL(EnableTexPanning, MODEL_o93, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, -0x4800)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetNoAnswerEffects) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03)
            EVT_CALL(EnableTexPanning, MODEL_o25, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o32, FALSE)
            EVT_CALL(EnableModel, MODEL_o32, FALSE)
            EVT_CALL(EnableModel, MODEL_o28, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o31, FALSE)
            EVT_CALL(EnableModel, MODEL_o31, FALSE)
            EVT_CALL(EnableModel, MODEL_o24, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o22, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o27, FALSE)
            EVT_CALL(EnableModel, MODEL_o36, FALSE)
            EVT_CALL(EnableModel, MODEL_o37, FALSE)
            EVT_CALL(EnableModel, MODEL_o20, TRUE)
            EVT_SET(LVar2, MODEL_g8)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
            EVT_CALL(EnableTexPanning, MODEL_o65, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o69, FALSE)
            EVT_CALL(EnableModel, MODEL_o69, FALSE)
            EVT_CALL(EnableModel, MODEL_o68, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o67, FALSE)
            EVT_CALL(EnableModel, MODEL_o67, FALSE)
            EVT_CALL(EnableModel, MODEL_o66, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o63, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o64, FALSE)
            EVT_CALL(EnableModel, MODEL_o117, FALSE)
            EVT_CALL(EnableModel, MODEL_o116, FALSE)
            EVT_CALL(EnableModel, MODEL_o118, TRUE)
            EVT_SET(LVar2, MODEL_g18)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim03)
            EVT_CALL(EnableTexPanning, MODEL_o91, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o95, FALSE)
            EVT_CALL(EnableModel, MODEL_o95, FALSE)
            EVT_CALL(EnableModel, MODEL_o94, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o93, FALSE)
            EVT_CALL(EnableModel, MODEL_o93, FALSE)
            EVT_CALL(EnableModel, MODEL_o92, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o89, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o90, FALSE)
            EVT_CALL(EnableModel, MODEL_o120, FALSE)
            EVT_CALL(EnableModel, MODEL_o121, FALSE)
            EVT_CALL(EnableModel, MODEL_o119, TRUE)
            EVT_SET(LVar2, MODEL_g25)
    EVT_END_SWITCH
    EVT_CALL(MakeLerp, 90, 0, 4, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVar2, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetPendingAnswerEffects) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_SET(LVar0, MODEL_o22)
            EVT_SET(LVar1, MODEL_o27)
            EVT_SET(LVar2, MODEL_g8)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_SET(LVar0, MODEL_o63)
            EVT_SET(LVar1, MODEL_o64)
            EVT_SET(LVar2, MODEL_g18)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_SET(LVar0, MODEL_o89)
            EVT_SET(LVar1, MODEL_o90)
            EVT_SET(LVar2, MODEL_g25)
    EVT_END_SWITCH
    EVT_CALL(EnableTexPanning, LVar0, TRUE)
    EVT_CALL(EnableTexPanning, LVar1, TRUE)
    EVT_CALL(MakeLerp, 0, 90, 4, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVar2, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetRightAnswerEffects) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_CALL(EnableTexPanning, MODEL_o25, TRUE)
            EVT_CALL(EnableModel, MODEL_o28, FALSE)
            EVT_CALL(EnableModel, MODEL_o32, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o32, TRUE)
            EVT_CALL(EnableModel, MODEL_o24, FALSE)
            EVT_CALL(EnableModel, MODEL_o31, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o31, TRUE)
            EVT_CALL(EnableModel, MODEL_o20, FALSE)
            EVT_CALL(EnableModel, MODEL_o36, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim19)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_CALL(EnableTexPanning, MODEL_o65, TRUE)
            EVT_CALL(EnableModel, MODEL_o68, FALSE)
            EVT_CALL(EnableModel, MODEL_o69, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o69, TRUE)
            EVT_CALL(EnableModel, MODEL_o66, FALSE)
            EVT_CALL(EnableModel, MODEL_o67, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o67, TRUE)
            EVT_CALL(EnableModel, MODEL_o118, FALSE)
            EVT_CALL(EnableModel, MODEL_o117, TRUE)
            EVT_THREAD
                EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_ShoutJoy)
                EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_LOOP(3)
                    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardHappy)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_CALL(EnableTexPanning, MODEL_o91, TRUE)
            EVT_CALL(EnableModel, MODEL_o94, FALSE)
            EVT_CALL(EnableModel, MODEL_o95, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o95, TRUE)
            EVT_CALL(EnableModel, MODEL_o92, FALSE)
            EVT_CALL(EnableModel, MODEL_o93, TRUE)
            EVT_CALL(EnableTexPanning, MODEL_o93, TRUE)
            EVT_CALL(EnableModel, MODEL_o119, FALSE)
            EVT_CALL(EnableModel, MODEL_o120, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim19)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWrongAnswerEffects) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_CALL(EnableTexPanning, MODEL_o22, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o27, FALSE)
            EVT_CALL(EnableModel, MODEL_o20, FALSE)
            EVT_CALL(EnableModel, MODEL_o37, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim1A)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_CALL(EnableTexPanning, MODEL_o63, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o64, FALSE)
            EVT_CALL(EnableModel, MODEL_o118, FALSE)
            EVT_CALL(EnableModel, MODEL_o116, TRUE)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_CALL(EnableTexPanning, MODEL_o89, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_o90, FALSE)
            EVT_CALL(EnableModel, MODEL_o119, FALSE)
            EVT_CALL(EnableModel, MODEL_o121, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim1A)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitScoreBar) = {
    EVT_SET(LVar0, MODEL_o38)
    EVT_LOOP(10)
        EVT_CALL(SetModelTexVariant, LVar0, 2)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_SET(LVar0, MODEL_o76)
    EVT_LOOP(10)
        EVT_CALL(SetModelTexVariant, LVar0, 2)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_SET(LVar0, MODEL_o102)
    EVT_LOOP(10)
        EVT_CALL(SetModelTexVariant, LVar0, 2)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateScoreBar) = {
    EVT_SWITCH(AB_KKJ29_AnsweringContestant)
        EVT_CASE_EQ(CONTESTANT_LEFT)
            EVT_SET(LVar0, MODEL_o38)
            EVT_SET(LVar1, AB_KKJ29_LeftKoopatrolScore)
        EVT_CASE_EQ(CONTESTANT_PEACH)
            EVT_SET(LVar0, MODEL_o76)
            EVT_SET(LVar1, AB_KKJ29_PeachScore)
        EVT_CASE_EQ(CONTESTANT_RIGHT)
            EVT_SET(LVar0, MODEL_o102)
            EVT_SET(LVar1, AB_KKJ29_RightKoopatrolScore)
    EVT_END_SWITCH
    EVT_SET(LVar2, 10)
    EVT_SUB(LVar2, LVar1)
    EVT_IF_NE(LVar1, 0)
        EVT_LOOP(LVar1)
            EVT_CALL(SetModelTexVariant, LVar0, 0)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_IF_NE(LVar2, 0)
        EVT_LOOP(LVar2)
            EVT_CALL(SetModelTexVariant, LVar0, 2)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DoScoreBarCycling) = {
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 1)
    EVT_SET(LVar2, 2)
    EVT_SET(LVar3, 1)
    EVT_SET(LVar4, 0)
    EVT_LOOP(0)
        EVT_SWITCH(AB_KKJ29_AnsweringContestant)
            EVT_CASE_EQ(CONTESTANT_LEFT)
                EVT_CALL(SetModelTexVariant, MODEL_o47, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o46, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o45, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o44, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o43, LVar0)
                EVT_CALL(SetModelTexVariant, MODEL_o42, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o41, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o40, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o39, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o38, LVar0)
            EVT_CASE_EQ(CONTESTANT_PEACH)
                EVT_CALL(SetModelTexVariant, MODEL_o85, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o84, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o83, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o82, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o81, LVar0)
                EVT_CALL(SetModelTexVariant, MODEL_o80, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o79, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o78, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o77, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o76, LVar0)
            EVT_CASE_EQ(CONTESTANT_RIGHT)
                EVT_CALL(SetModelTexVariant, MODEL_o111, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o110, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o109, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o108, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o107, LVar0)
                EVT_CALL(SetModelTexVariant, MODEL_o106, LVar4)
                EVT_CALL(SetModelTexVariant, MODEL_o105, LVar3)
                EVT_CALL(SetModelTexVariant, MODEL_o104, LVar2)
                EVT_CALL(SetModelTexVariant, MODEL_o103, LVar1)
                EVT_CALL(SetModelTexVariant, MODEL_o102, LVar0)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_IF_EQ(AB_KKJ29_AnswerScore, ANSWER_NONE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_EQ(AB_KKJ29_AnswerScore, ANSWER_WRONG)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_SET(LVar5, LVar4)
        EVT_SET(LVar4, LVar3)
        EVT_SET(LVar3, LVar2)
        EVT_SET(LVar2, LVar1)
        EVT_SET(LVar1, LVar0)
        EVT_SET(LVar0, LVar5)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_UpdateScoreBar))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageStageEffects) = {
    EVT_EXEC(N(EVS_TexPan_Podiums))
    EVT_EXEC(N(EVS_TexPan_VerticalStrips))
    EVT_EXEC(N(EVS_TexPan_Screens))
    EVT_EXEC(N(EVS_TexPan_Stars))
    EVT_EXEC(N(EVS_TexPan_FloorTrim))
    EVT_EXEC(N(EVS_TexPan_StarTrim))
    EVT_CALL(EnableModel, MODEL_o31, FALSE)
    EVT_CALL(EnableModel, MODEL_o32, FALSE)
    EVT_CALL(EnableModel, MODEL_o36, FALSE)
    EVT_CALL(EnableModel, MODEL_o37, FALSE)
    EVT_CALL(EnableModel, MODEL_o67, FALSE)
    EVT_CALL(EnableModel, MODEL_o69, FALSE)
    EVT_CALL(EnableModel, MODEL_o116, FALSE)
    EVT_CALL(EnableModel, MODEL_o117, FALSE)
    EVT_CALL(EnableModel, MODEL_o93, FALSE)
    EVT_CALL(EnableModel, MODEL_o95, FALSE)
    EVT_CALL(EnableModel, MODEL_o120, FALSE)
    EVT_CALL(EnableModel, MODEL_o121, FALSE)
    EVT_EXEC(N(EVS_InitScoreBar))
    EVT_LABEL(0)
        EVT_SET(LVar0, AB_KKJ29_AnswerScore)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, AB_KKJ29_AnswerScore)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SWITCH(AB_KKJ29_AnswerScore)
            EVT_CASE_EQ(ANSWER_NONE)
                EVT_EXEC_WAIT(N(EVS_SetNoAnswerEffects))
            EVT_CASE_EQ(ANSWER_PENDING)
                EVT_EXEC(N(EVS_DoScoreBarCycling))
                EVT_EXEC_WAIT(N(EVS_SetPendingAnswerEffects))
            EVT_CASE_EQ(ANSWER_RIGHT)
                EVT_EXEC_WAIT(N(EVS_SetRightAnswerEffects))
            EVT_CASE_EQ(ANSWER_WRONG)
                EVT_EXEC_WAIT(N(EVS_SetWrongAnswerEffects))
        EVT_END_SWITCH
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

enum {
    OUTCOME_PEACH_WON   = -2,
    OUTCOME_LEFT_WON    = 1,
    OUTCOME_RIGHT_WON   = 2,
    OUTCOME_TIE         = 3,
};

EvtScript N(EVS_DeclareWinner) = {
    EVT_SET(LVar0, OUTCOME_LEFT_WON)
    EVT_SET(LVar1, AB_KKJ29_LeftKoopatrolScore)
    EVT_SWITCH(AB_KKJ29_PeachScore)
        EVT_CASE_GT(LVar1)
            // peach beat left koopatrol
            EVT_SET(LVar0, OUTCOME_PEACH_WON)
            EVT_SET(LVar1, AB_KKJ29_PeachScore)
        EVT_CASE_EQ(LVar1)
            // peach tied
            EVT_SET(LVar0, OUTCOME_TIE)
    EVT_END_SWITCH
    EVT_SWITCH(AB_KKJ29_RightKoopatrolScore)
        EVT_CASE_GT(LVar1)
            // peach lost to right koopatrol
            EVT_SET(LVar0, OUTCOME_RIGHT_WON)
        EVT_CASE_EQ(LVar1)
            // all tied
            EVT_SET(LVar0, OUTCOME_TIE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_LEFT_WON)
            EVT_SET(LVar1, -280)
            EVT_SET(LVar2, -320)
        EVT_CASE_EQ(OUTCOME_PEACH_WON)
            EVT_SET(LVar1, -270)
            EVT_SET(LVar2, -230)
        EVT_CASE_EQ(OUTCOME_RIGHT_WON)
            EVT_SET(LVar1, -180)
            EVT_SET(LVar2, -140)
        EVT_CASE_EQ(OUTCOME_TIE)
            EVT_SET(LVar1, -270)
            EVT_SET(LVar2, -230)
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    EVT_CALL(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_HammerBros, -400, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar1, 0, 0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(NpcFaceNpc, NPC_HammerBros, LVar0, 7)
    EVT_END_IF
    EVT_IF_NE(LVar0, 3)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar1, -60, 0)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    EVT_CALL(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, 30, -140)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, 30, -140)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_LEFT_WON)
            EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_01, MSG_Peach_011B)
            EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim19)
            EVT_CALL(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_011C)
            EVT_WAIT(10)
            EVT_SET(LVar0, ITEM_JAMMIN_JELLY)
            EVT_SET(LVar1, NPC_Koopatrol_01)
            EVT_SET(LVar2, MSG_Peach_011D)
            EVT_EXEC_WAIT(N(EVS_GiveItemToKoopatrol))
            EVT_WAIT(10)
        EVT_CASE_EQ(OUTCOME_PEACH_WON)
            EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0121)
            EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
            EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Delighted)
            EVT_WAIT(1)
            EVT_CALL(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0122)
            EVT_WAIT(10)
            EVT_CALL(ShowGotItem, ITEM_JAMMIN_JELLY, TRUE, ITEM_PICKUP_FLAG_NO_ANIMS)
            EVT_SET(GF_KKJ29_PeachWonJamminJelly, TRUE)
            EVT_WAIT(10)
        EVT_CASE_EQ(OUTCOME_RIGHT_WON)
            EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_02, MSG_Peach_011E)
            EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim19)
            EVT_CALL(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_011F)
            EVT_WAIT(10)
            EVT_SET(LVar0, ITEM_JAMMIN_JELLY)
            EVT_SET(LVar1, NPC_Koopatrol_02)
            EVT_SET(LVar2, MSG_Peach_0120)
            EVT_EXEC_WAIT(N(EVS_GiveItemToKoopatrol))
            EVT_WAIT(10)
        EVT_CASE_EQ(OUTCOME_TIE)
            EVT_IF_EQ(AB_KKJ29_PeachScore, 0)
                EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0124)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0123)
            EVT_END_IF
            EVT_CALL(PlaySound, SOUND_AUDIENCE_BOO)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Vec3f N(TwinkHidePath)[] = {
    {  290.0,    25.0,  -30.0 },
    {  310.0,    70.0,  -70.0 },
    {  300.0,    35.0, -110.0 },
    {  290.0,    33.0, -110.0 },
};

Vec3f N(TwinkFollowPath1)[] = {
    {  290.0,    33.0, -110.0 },
    {  300.0,    35.0, -110.0 },
    {  310.0,    10.0,  -70.0 },
    {  240.0,    25.0,  -30.0 },
};

Vec3f N(TwinkFollowPath2)[] = {
    {  240.0,    25.0,  -30.0 },
    {  230.0,    20.0,  -30.0 },
    {   40.0,    80.0,  -60.0 },
    { -140.0,   150.0, -100.0 },
    { -180.0,   130.0, -100.0 },
    { -195.0,    80.0, -100.0 },
};

Vec3f N(TwinkFlyAwayPath)[] = {
    { -175.0,    60.0, -100.0 },
    { -160.0,   130.0, -100.0 },
    { -120.0,   150.0, -100.0 },
    {  -70.0,   200.0, -100.0 },
};

EvtScript N(EVS_TwinkFollowPath) = {
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ApproachPeach) = {
    EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim09)
        EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        EVT_CALL(NpcFacePlayer, NPC_HammerBros, 5)
        EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_HammerBros, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim13)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_ADD(LVar0, 10)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 32)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim08)
        EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_HammerBros, 404, -26, 0)
        EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, 436, -22, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 120, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o57, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseDoor) = {
    EVT_CALL(MakeLerp, 120, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o57, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TwinkHide) = {
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    EVT_CALL(LoadPath, 20 * DT, EVT_PTR(N(TwinkHidePath)), ARRAY_COUNT(N(TwinkHidePath)), EASING_LINEAR)
    EVT_EXEC_WAIT(N(EVS_TwinkFollowPath))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Sad)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PeachSweat) = {
    EVT_LOOP(0)
        EVT_CALL(ShowSweat, 0, 1, -45, EMOTER_PLAYER, 0, 0, 0, 0, 20)
        EVT_WAIT(20 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TwinkSweat) = {
    EVT_LOOP(0)
        EVT_CALL(ShowSweat, NPC_PARTNER, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_WAIT(20 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageQuizGame) = {
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(RotateModel, MODEL_o57, 120, 0, 1, 0)
    EVT_CALL(func_802D1270, 250, -30, EVT_FLOAT(2.0 / DT))
    EVT_EXEC_WAIT(N(EVS_CloseDoor))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(EVS_TwinkHide))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
        EVT_WAIT(60 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Koopatrol_01, EMOTE_QUESTION, -45, 15, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim17)
    EVT_CALL(NpcJump0, NPC_Koopatrol_01, 175, 0, -25, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_00EF)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim09)
    EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_HammerBros, 130, -25, 0)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 190, 0, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 190, 0, -25)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_01, MSG_Peach_00F0)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 270, 0)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_00F1)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_HammerBros, 130, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_00F2)
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
    EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_00F3)
    EVT_THREAD
        EVT_CALL(func_802D1270, 0, -25, EVT_FLOAT(2.0 / DT))
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
        EVT_CALL(SetPlayerPos, -230, 23, -140)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, 0, -25, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_01, -320, 30, -140)
        EVT_CALL(SetNpcYaw, NPC_Koopatrol_01, 90)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, 0, -25, 0)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        EVT_CALL(SetNpcPos, NPC_HammerBros, -230, 0, 0)
        EVT_CALL(SetNpcYaw, NPC_HammerBros, 90)
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(TwinkFollowPath1)), ARRAY_COUNT(N(TwinkFollowPath1)), EASING_LINEAR)
    EVT_EXEC_WAIT(N(EVS_TwinkFollowPath))
    EVT_EXEC_GET_TID(N(EVS_TwinkSweat), LVarA)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 5, MSG_Peach_00F4)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -230, 0, -140)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -230, 0, -140)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.961))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Angry)
    EVT_CALL(LoadPath, 100 * DT, EVT_PTR(N(TwinkFollowPath2)), ARRAY_COUNT(N(TwinkFollowPath2)), EASING_LINEAR)
    EVT_EXEC_WAIT(N(EVS_TwinkFollowPath))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_QUIZ_INTRO, 0, 8)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F5)
    EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F6)
    EVT_CALL(PlaySound, SOUND_AUDIENCE_CHEER)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(13 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(13 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    EVT_CALL(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(NpcMoveTo, NPC_HammerBros, -395, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_HammerBros, 90, 7 * DT)
    EVT_CALL(NpcMoveTo, NPC_HammerBros, -395, -30, 0)
    EVT_CALL(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -395, 10, -40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -395, 10, -40)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-370.0), EVT_FLOAT(40.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_QUIZ_INTRO, 1, 8)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F8)
    EVT_EXEC_WAIT(N(EVS_SetCam_Contestants))
    EVT_SET(AB_KKJ29_LeftKoopatrolScore, 0)
    EVT_SET(AB_KKJ29_PeachScore, 0)
    EVT_SET(AB_KKJ29_RightKoopatrolScore, 0)
    // round 1
    EVT_SET(LVar1, MSG_Peach_00FC)
    EVT_SET(LVar2, 40 * DT)
    EVT_SET(LVar3, MSG_Peach_00FD)
    EVT_SET(LVar4, MSG_Choice_002C)
    EVT_SET(LVar5, 1)
    EVT_SET(LVar6, MSG_Peach_0111)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 2
    EVT_SET(LVar1, MSG_Peach_00FE)
    EVT_SET(LVar2, 10 * DT)
    EVT_SET(LVar3, MSG_Peach_00FF)
    EVT_SET(LVar4, MSG_Choice_002D)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar6, MSG_Peach_0112)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 3
    EVT_SET(LVar1, MSG_Peach_0100)
    EVT_SET(LVar2, 60 * DT)
    EVT_SET(LVar3, MSG_Peach_0101)
    EVT_SET(LVar4, MSG_Choice_002E)
    EVT_SET(LVar5, 2)
    EVT_SET(LVar6, MSG_Peach_0113)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 4
    EVT_SET(LVar1, MSG_Peach_0102)
    EVT_SET(LVar2, 10 * DT)
    EVT_SET(LVar3, MSG_Peach_0103)
    EVT_SET(LVar4, MSG_Choice_002F)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar6, MSG_Peach_0114)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 5
    EVT_SET(LVar1, MSG_Peach_0104)
    EVT_SET(LVar2, 30 * DT)
    EVT_SET(LVar3, MSG_Peach_0105)
    EVT_SET(LVar4, MSG_Choice_0030)
    EVT_SET(LVar5, 2)
    EVT_SET(LVar6, MSG_Peach_0115)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 6
    EVT_SET(LVar1, MSG_Peach_0106)
    EVT_SET(LVar2, 20)
    EVT_SET(LVar3, MSG_Peach_0107)
    EVT_SET(LVar4, MSG_Choice_0031)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar6, MSG_Peach_0116)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 7
    EVT_SET(LVar1, MSG_Peach_0108)
    EVT_SET(LVar2, 30 * DT)
    EVT_SET(LVar3, MSG_Peach_0109)
    EVT_SET(LVar4, MSG_Choice_0032)
    EVT_SET(LVar5, 1)
    EVT_SET(LVar6, MSG_Peach_0117)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 8
    EVT_SET(LVar1, MSG_Peach_010A)
    EVT_SET(LVar2, 60 * DT)
    EVT_SET(LVar3, MSG_Peach_010B)
    EVT_SET(LVar4, MSG_Choice_0033)
    EVT_SET(LVar5, 1)
    EVT_SET(LVar6, MSG_Peach_0118)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 9
    EVT_SET(LVar1, MSG_Peach_010C)
    EVT_SET(LVar2, 60 * DT)
    EVT_SET(LVar3, MSG_Peach_010D)
    EVT_SET(LVar4, MSG_Choice_0034)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar6, MSG_Peach_0119)
    EVT_EXEC_WAIT(N(Script_DoRound))
    // round 10
    EVT_SET(LVar1, MSG_Peach_010E)
    EVT_SET(LVar2, 30 * DT)
    EVT_SET(LVar3, MSG_Peach_010F)
    EVT_SET(LVar4, MSG_Choice_0035)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar6, MSG_Peach_011A)
    EVT_EXEC_WAIT(N(Script_DoRound))
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
    EVT_EXEC_WAIT(N(EVS_DeclareWinner))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -230, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    EVT_CALL(NpcMoveTo, NPC_HammerBros, -230, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_HammerBros, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_QUIZ_INTRO, 2, 8)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0125)
    EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 1)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(PlayerMoveTo, -185, -140, 20)
        EVT_CALL(PlayerMoveTo, -185, 0, 70)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -160, 50, 0, 90, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(2.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -400, -140, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(SetNpcFlagBits, NPC_Koopatrol_02, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(2.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, 0, -140, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Koopatrol_02, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_02, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_HammerBros, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -190, 0, 70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0126)
    EVT_CALL(ShowGotItem, ITEM_SNEAKY_PARASOL, TRUE, 0)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0127)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 330, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 330, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(250.0), EVT_FLOAT(40.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcPos, NPC_HammerBros, -350, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_01, -325, 0, -30)
    EVT_CALL(SetNpcYaw, NPC_Koopatrol_01, 90)
    EVT_EXEC(N(EVS_OpenDoor))
    EVT_CALL(SetNpcPos, NPC_Bowser, 410, 0, -25)
    EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bowser, 250, -25, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_HammerBros, MSG_Peach_0128)
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, MSG_Peach_0129)
    EVT_CALL(SetNpcVar, NPC_Bowser, 1, 1)
    EVT_THREAD
        EVT_CALL(SetPlayerPos, -185, 0, -100)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -20)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_EXEC_GET_TID(N(EVS_PeachSweat), LVarA)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Bowser, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_KILL_THREAD(LVarA)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 7)
        EVT_CALL(func_802D1270, -180, -24, EVT_FLOAT(2.0 / DT))
        EVT_CALL(func_802D1270, -120, -24, EVT_FLOAT(2.0 / DT))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_PARTNER, -175, 60, -100)
        EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -10)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_EXEC_GET_TID(N(EVS_TwinkSweat), LVarA)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_Bowser, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_KILL_THREAD(LVarA)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 5)
        EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(TwinkFlyAwayPath)), ARRAY_COUNT(N(TwinkFlyAwayPath)), EASING_LINEAR)
        EVT_EXEC_WAIT(N(EVS_TwinkFollowPath))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -300, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(3.75 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bowser, -260, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SetNpcVar, NPC_Bowser, 0, 0)
    EVT_CALL(SetNpcVar, NPC_Bowser, 1, 0)
    EVT_WAIT(10 * DT)
    EVT_LOOP(2)
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Talk)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        EVT_WAIT(3 * DT)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim0B)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        EVT_WAIT(3 * DT)
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_HammerBros, MSG_Peach_012A)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -190, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
        EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Shock, ANIM_WorldBowser_Shock, 5, MSG_Peach_012B)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, MSG_Peach_012C)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach))
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_012D)
    EVT_EXEC_WAIT(N(EVS_PickUpPeach))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_012E)
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway))
    EVT_WAIT(30 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter5))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
