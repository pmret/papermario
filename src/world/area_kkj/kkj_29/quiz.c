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
    Call(SetNpcAnimation, LVar1, ANIM_WorldKoopatrol_Anim1B)
    Set(LVarA, LVar0)
    Call(GetNpcPos, LVar1, LVar5, LVar6, LVar7)
    Add(LVar6, 40)
    Call(MakeItemEntity, LVarA, LVar5, LVar6, LVar7, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVarB, LVar0)
    Call(PlaySound, SOUND_JINGLE_GOT_KEY)
    Call(ShowMessageAtScreenPos, LVar2, 160, 40)
    Call(RemoveItemEntity, LVarB)
    Call(SetNpcAnimation, LVar1, ANIM_WorldKoopatrol_Anim03)
    Return
    End
};

EvtScript N(EVS_SetCam_Contestants) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -265, 0, -140)
    Call(SetPanTarget, CAM_DEFAULT, -265, 0, -140)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Return
    End
};

EvtScript N(EVS_UpdateScores) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            IfEq(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                Add(AB_KKJ29_LeftKoopatrolScore, 1)
            Else
                IfGt(AB_KKJ29_LeftKoopatrolScore, 0)
                    Sub(AB_KKJ29_LeftKoopatrolScore, 1)
                EndIf
            EndIf
        CaseEq(CONTESTANT_PEACH)
            IfEq(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                Add(AB_KKJ29_PeachScore, 1)
            Else
                IfGt(AB_KKJ29_PeachScore, 0)
                    Sub(AB_KKJ29_PeachScore, 1)
                EndIf
            EndIf
        CaseEq(CONTESTANT_RIGHT)
            IfEq(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
                Add(AB_KKJ29_RightKoopatrolScore, 1)
            Else
                IfGt(AB_KKJ29_RightKoopatrolScore, 0)
                    Sub(AB_KKJ29_RightKoopatrolScore, 1)
                EndIf
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_WaitForBuzzIn) = {
    Call(PlaySound, SOUND_LRAW_QUIZ_TICKING)
    Call(N(AwaitPlayerBuzzIn))
    IfEq(LVar0, 0) // time's up
        // player took too long, decide who will answer based on score
        IfLe(AB_KKJ29_LeftKoopatrolScore, AB_KKJ29_PeachScore)
            Set(AB_KKJ29_AnsweringContestant, CONTESTANT_LEFT)
        Else
            Set(LVar0, AB_KKJ29_LeftKoopatrolScore)
            Sub(LVar0, 1)
            IfLt(AB_KKJ29_RightKoopatrolScore, LVar0)
                Set(AB_KKJ29_AnsweringContestant, CONTESTANT_RIGHT)
            Else
                Set(AB_KKJ29_AnsweringContestant, CONTESTANT_LEFT)
            EndIf
        EndIf
    Else
        // player will answer
        Set(AB_KKJ29_AnsweringContestant, CONTESTANT_PEACH)
    EndIf
    Call(StopSound, SOUND_LRAW_QUIZ_TICKING)
    Set(AB_KKJ29_AnswerScore, ANSWER_PENDING)
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Call(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            Call(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00FA)
            Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        CaseEq(CONTESTANT_PEACH)
            Call(PlaySoundAtPlayer, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            Call(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F9)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
        CaseEq(CONTESTANT_RIGHT)
            Call(PlaySoundAtNpc, NPC_Koopatrol_02, SOUND_QUIZ_BUZZER, SOUND_SPACE_DEFAULT)
            Call(EndSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5)
            Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00FB)
            Call(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
    EndSwitch
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-12.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

// LVar1  question
// LVar2  time
// LVar3  rival giving answer
// LVar4  choice message
// LVar5  rival choice selection
// LVar6  host response to wrong answer
EvtScript N(Script_DoRound) = {
    Call(PlaySound, SOUND_QUIZ_NEXT_QUESTION)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, LVar1)
    Set(LVar0, LVar2)
    // wait for input
    ExecWait(N(EVS_WaitForBuzzIn))
    // get an answer
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03, ANIM_WorldKoopatrol_Anim03, 5, LVar3)
            Set(LVar0, LVar5)
        CaseEq(CONTESTANT_PEACH)
            Call(ShowChoice, LVar4)
        CaseEq(CONTESTANT_RIGHT)
            Call(SpeakToPlayer, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim03, ANIM_WorldKoopatrol_Anim03, 5, LVar3)
            Set(LVar0, LVar5)
    EndSwitch
    // handle the choice
    IfEq(LVar0, LVar5)
        Call(PlaySound, SOUND_APPROVE)
        Call(PlaySound, SOUND_AUDIENCE_CHEER)
        Set(AB_KKJ29_AnswerScore, ANSWER_RIGHT)
        ExecWait(N(EVS_UpdateScores))
        Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0110)
    Else
        Call(PlaySound, SOUND_MENU_ERROR)
        Call(PlaySound, SOUND_AUDIENCE_BOO)
        Set(AB_KKJ29_AnswerScore, ANSWER_WRONG)
        ExecWait(N(EVS_UpdateScores))
        Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, LVar6)
    EndIf
    Wait(30 * DT)
    Set(AB_KKJ29_AnswerScore, ANSWER_NONE)
    Wait(10 * DT)
    ExecWait(N(EVS_SetCam_Contestants))
    Return
    End
};

EvtScript N(EVS_TexPan_Podiums) = {
    Call(SetTexPanner, MODEL_o19, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o62, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o88, TEX_PANNER_1)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x8000)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_VerticalStrips) = {
    Call(SetTexPanner, MODEL_o22, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_o22, false)
    Call(SetTexPanner, MODEL_o63, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_o63, false)
    Call(SetTexPanner, MODEL_o89, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_o89, false)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x8000)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_Screens) = {
    Call(SetTexPanner, MODEL_o27, TEX_PANNER_3)
    Call(EnableTexPanning, MODEL_o27, false)
    Call(SetTexPanner, MODEL_o64, TEX_PANNER_3)
    Call(EnableTexPanning, MODEL_o64, false)
    Call(SetTexPanner, MODEL_o90, TEX_PANNER_3)
    Call(EnableTexPanning, MODEL_o90, false)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x4000)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, 0)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_Stars) = {
    Call(SetTexPanner, MODEL_o25, TEX_PANNER_4)
    Call(EnableTexPanning, MODEL_o25, false)
    Call(SetTexPanner, MODEL_o65, TEX_PANNER_4)
    Call(EnableTexPanning, MODEL_o65, false)
    Call(SetTexPanner, MODEL_o91, TEX_PANNER_4)
    Call(EnableTexPanning, MODEL_o91, false)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x4000)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar0, 0)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FloorTrim) = {
    Call(SetTexPanner, MODEL_o32, TEX_PANNER_5)
    Call(EnableTexPanning, MODEL_o32, false)
    Call(SetTexPanner, MODEL_o69, TEX_PANNER_5)
    Call(EnableTexPanning, MODEL_o69, false)
    Call(SetTexPanner, MODEL_o95, TEX_PANNER_5)
    Call(EnableTexPanning, MODEL_o95, false)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x8000)
        Call(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar0, 0)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_StarTrim) = {
    Call(SetTexPanner, MODEL_o31, TEX_PANNER_6)
    Call(EnableTexPanning, MODEL_o31, false)
    Call(SetTexPanner, MODEL_o67, TEX_PANNER_6)
    Call(EnableTexPanning, MODEL_o67, false)
    Call(SetTexPanner, MODEL_o93, TEX_PANNER_6)
    Call(EnableTexPanning, MODEL_o93, false)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, -0x4800)
        Call(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar0, 0)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetNoAnswerEffects) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03)
            Call(EnableTexPanning, MODEL_o25, false)
            Call(EnableTexPanning, MODEL_o32, false)
            Call(EnableModel, MODEL_o32, false)
            Call(EnableModel, MODEL_o28, true)
            Call(EnableTexPanning, MODEL_o31, false)
            Call(EnableModel, MODEL_o31, false)
            Call(EnableModel, MODEL_o24, true)
            Call(EnableTexPanning, MODEL_o22, false)
            Call(EnableTexPanning, MODEL_o27, false)
            Call(EnableModel, MODEL_o36, false)
            Call(EnableModel, MODEL_o37, false)
            Call(EnableModel, MODEL_o20, true)
            Set(LVar2, MODEL_g8)
        CaseEq(CONTESTANT_PEACH)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
            Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
            Call(EnableTexPanning, MODEL_o65, false)
            Call(EnableTexPanning, MODEL_o69, false)
            Call(EnableModel, MODEL_o69, false)
            Call(EnableModel, MODEL_o68, true)
            Call(EnableTexPanning, MODEL_o67, false)
            Call(EnableModel, MODEL_o67, false)
            Call(EnableModel, MODEL_o66, true)
            Call(EnableTexPanning, MODEL_o63, false)
            Call(EnableTexPanning, MODEL_o64, false)
            Call(EnableModel, MODEL_o117, false)
            Call(EnableModel, MODEL_o116, false)
            Call(EnableModel, MODEL_o118, true)
            Set(LVar2, MODEL_g18)
        CaseEq(CONTESTANT_RIGHT)
            Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim03)
            Call(EnableTexPanning, MODEL_o91, false)
            Call(EnableTexPanning, MODEL_o95, false)
            Call(EnableModel, MODEL_o95, false)
            Call(EnableModel, MODEL_o94, true)
            Call(EnableTexPanning, MODEL_o93, false)
            Call(EnableModel, MODEL_o93, false)
            Call(EnableModel, MODEL_o92, true)
            Call(EnableTexPanning, MODEL_o89, false)
            Call(EnableTexPanning, MODEL_o90, false)
            Call(EnableModel, MODEL_o120, false)
            Call(EnableModel, MODEL_o121, false)
            Call(EnableModel, MODEL_o119, true)
            Set(LVar2, MODEL_g25)
    EndSwitch
    Call(MakeLerp, 90, 0, 4, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, LVar2, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetPendingAnswerEffects) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Set(LVar0, MODEL_o22)
            Set(LVar1, MODEL_o27)
            Set(LVar2, MODEL_g8)
        CaseEq(CONTESTANT_PEACH)
            Set(LVar0, MODEL_o63)
            Set(LVar1, MODEL_o64)
            Set(LVar2, MODEL_g18)
        CaseEq(CONTESTANT_RIGHT)
            Set(LVar0, MODEL_o89)
            Set(LVar1, MODEL_o90)
            Set(LVar2, MODEL_g25)
    EndSwitch
    Call(EnableTexPanning, LVar0, true)
    Call(EnableTexPanning, LVar1, true)
    Call(MakeLerp, 0, 90, 4, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, LVar2, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetRightAnswerEffects) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Call(EnableTexPanning, MODEL_o25, true)
            Call(EnableModel, MODEL_o28, false)
            Call(EnableModel, MODEL_o32, true)
            Call(EnableTexPanning, MODEL_o32, true)
            Call(EnableModel, MODEL_o24, false)
            Call(EnableModel, MODEL_o31, true)
            Call(EnableTexPanning, MODEL_o31, true)
            Call(EnableModel, MODEL_o20, false)
            Call(EnableModel, MODEL_o36, true)
            Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim19)
        CaseEq(CONTESTANT_PEACH)
            Call(EnableTexPanning, MODEL_o65, true)
            Call(EnableModel, MODEL_o68, false)
            Call(EnableModel, MODEL_o69, true)
            Call(EnableTexPanning, MODEL_o69, true)
            Call(EnableModel, MODEL_o66, false)
            Call(EnableModel, MODEL_o67, true)
            Call(EnableTexPanning, MODEL_o67, true)
            Call(EnableModel, MODEL_o118, false)
            Call(EnableModel, MODEL_o117, true)
            Thread
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_ShoutJoy)
                Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Loop(3)
                    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
                EndLoop
            EndThread
            Call(SetPlayerAnimation, ANIM_Peach2_ForwardHappy)
        CaseEq(CONTESTANT_RIGHT)
            Call(EnableTexPanning, MODEL_o91, true)
            Call(EnableModel, MODEL_o94, false)
            Call(EnableModel, MODEL_o95, true)
            Call(EnableTexPanning, MODEL_o95, true)
            Call(EnableModel, MODEL_o92, false)
            Call(EnableModel, MODEL_o93, true)
            Call(EnableTexPanning, MODEL_o93, true)
            Call(EnableModel, MODEL_o119, false)
            Call(EnableModel, MODEL_o120, true)
            Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim19)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetWrongAnswerEffects) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Call(EnableTexPanning, MODEL_o22, false)
            Call(EnableTexPanning, MODEL_o27, false)
            Call(EnableModel, MODEL_o20, false)
            Call(EnableModel, MODEL_o37, true)
            Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim1A)
        CaseEq(CONTESTANT_PEACH)
            Call(EnableTexPanning, MODEL_o63, false)
            Call(EnableTexPanning, MODEL_o64, false)
            Call(EnableModel, MODEL_o118, false)
            Call(EnableModel, MODEL_o116, true)
            Call(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
        CaseEq(CONTESTANT_RIGHT)
            Call(EnableTexPanning, MODEL_o89, false)
            Call(EnableTexPanning, MODEL_o90, false)
            Call(EnableModel, MODEL_o119, false)
            Call(EnableModel, MODEL_o121, true)
            Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim1A)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_InitScoreBar) = {
    Set(LVar0, MODEL_o38)
    Loop(10)
        Call(SetModelTexVariant, LVar0, 2)
        Add(LVar0, 1)
    EndLoop
    Set(LVar0, MODEL_o76)
    Loop(10)
        Call(SetModelTexVariant, LVar0, 2)
        Add(LVar0, 1)
    EndLoop
    Set(LVar0, MODEL_o102)
    Loop(10)
        Call(SetModelTexVariant, LVar0, 2)
        Add(LVar0, 1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateScoreBar) = {
    Switch(AB_KKJ29_AnsweringContestant)
        CaseEq(CONTESTANT_LEFT)
            Set(LVar0, MODEL_o38)
            Set(LVar1, AB_KKJ29_LeftKoopatrolScore)
        CaseEq(CONTESTANT_PEACH)
            Set(LVar0, MODEL_o76)
            Set(LVar1, AB_KKJ29_PeachScore)
        CaseEq(CONTESTANT_RIGHT)
            Set(LVar0, MODEL_o102)
            Set(LVar1, AB_KKJ29_RightKoopatrolScore)
    EndSwitch
    Set(LVar2, 10)
    Sub(LVar2, LVar1)
    IfNe(LVar1, 0)
        Loop(LVar1)
            Call(SetModelTexVariant, LVar0, 0)
            Add(LVar0, 1)
        EndLoop
    EndIf
    IfNe(LVar2, 0)
        Loop(LVar2)
            Call(SetModelTexVariant, LVar0, 2)
            Add(LVar0, 1)
        EndLoop
    EndIf
    Return
    End
};

EvtScript N(EVS_DoScoreBarCycling) = {
    Set(LVar0, 0)
    Set(LVar1, 1)
    Set(LVar2, 2)
    Set(LVar3, 1)
    Set(LVar4, 0)
    Loop(0)
        Switch(AB_KKJ29_AnsweringContestant)
            CaseEq(CONTESTANT_LEFT)
                Call(SetModelTexVariant, MODEL_o47, LVar4)
                Call(SetModelTexVariant, MODEL_o46, LVar3)
                Call(SetModelTexVariant, MODEL_o45, LVar2)
                Call(SetModelTexVariant, MODEL_o44, LVar1)
                Call(SetModelTexVariant, MODEL_o43, LVar0)
                Call(SetModelTexVariant, MODEL_o42, LVar4)
                Call(SetModelTexVariant, MODEL_o41, LVar3)
                Call(SetModelTexVariant, MODEL_o40, LVar2)
                Call(SetModelTexVariant, MODEL_o39, LVar1)
                Call(SetModelTexVariant, MODEL_o38, LVar0)
            CaseEq(CONTESTANT_PEACH)
                Call(SetModelTexVariant, MODEL_o85, LVar4)
                Call(SetModelTexVariant, MODEL_o84, LVar3)
                Call(SetModelTexVariant, MODEL_o83, LVar2)
                Call(SetModelTexVariant, MODEL_o82, LVar1)
                Call(SetModelTexVariant, MODEL_o81, LVar0)
                Call(SetModelTexVariant, MODEL_o80, LVar4)
                Call(SetModelTexVariant, MODEL_o79, LVar3)
                Call(SetModelTexVariant, MODEL_o78, LVar2)
                Call(SetModelTexVariant, MODEL_o77, LVar1)
                Call(SetModelTexVariant, MODEL_o76, LVar0)
            CaseEq(CONTESTANT_RIGHT)
                Call(SetModelTexVariant, MODEL_o111, LVar4)
                Call(SetModelTexVariant, MODEL_o110, LVar3)
                Call(SetModelTexVariant, MODEL_o109, LVar2)
                Call(SetModelTexVariant, MODEL_o108, LVar1)
                Call(SetModelTexVariant, MODEL_o107, LVar0)
                Call(SetModelTexVariant, MODEL_o106, LVar4)
                Call(SetModelTexVariant, MODEL_o105, LVar3)
                Call(SetModelTexVariant, MODEL_o104, LVar2)
                Call(SetModelTexVariant, MODEL_o103, LVar1)
                Call(SetModelTexVariant, MODEL_o102, LVar0)
        EndSwitch
        Wait(1)
        IfEq(AB_KKJ29_AnswerScore, ANSWER_NONE)
            BreakLoop
        EndIf
        IfEq(AB_KKJ29_AnswerScore, ANSWER_WRONG)
            BreakLoop
        EndIf
        Set(LVar5, LVar4)
        Set(LVar4, LVar3)
        Set(LVar3, LVar2)
        Set(LVar2, LVar1)
        Set(LVar1, LVar0)
        Set(LVar0, LVar5)
    EndLoop
    Exec(N(EVS_UpdateScoreBar))
    Return
    End
};

EvtScript N(EVS_ManageStageEffects) = {
    Exec(N(EVS_TexPan_Podiums))
    Exec(N(EVS_TexPan_VerticalStrips))
    Exec(N(EVS_TexPan_Screens))
    Exec(N(EVS_TexPan_Stars))
    Exec(N(EVS_TexPan_FloorTrim))
    Exec(N(EVS_TexPan_StarTrim))
    Call(EnableModel, MODEL_o31, false)
    Call(EnableModel, MODEL_o32, false)
    Call(EnableModel, MODEL_o36, false)
    Call(EnableModel, MODEL_o37, false)
    Call(EnableModel, MODEL_o67, false)
    Call(EnableModel, MODEL_o69, false)
    Call(EnableModel, MODEL_o116, false)
    Call(EnableModel, MODEL_o117, false)
    Call(EnableModel, MODEL_o93, false)
    Call(EnableModel, MODEL_o95, false)
    Call(EnableModel, MODEL_o120, false)
    Call(EnableModel, MODEL_o121, false)
    Exec(N(EVS_InitScoreBar))
    Label(0)
        Set(LVar0, AB_KKJ29_AnswerScore)
        Loop(0)
            Wait(1)
            IfNe(LVar0, AB_KKJ29_AnswerScore)
                BreakLoop
            EndIf
        EndLoop
        Switch(AB_KKJ29_AnswerScore)
            CaseEq(ANSWER_NONE)
                ExecWait(N(EVS_SetNoAnswerEffects))
            CaseEq(ANSWER_PENDING)
                Exec(N(EVS_DoScoreBarCycling))
                ExecWait(N(EVS_SetPendingAnswerEffects))
            CaseEq(ANSWER_RIGHT)
                ExecWait(N(EVS_SetRightAnswerEffects))
            CaseEq(ANSWER_WRONG)
                ExecWait(N(EVS_SetWrongAnswerEffects))
        EndSwitch
        Goto(0)
    Return
    End
};

enum {
    OUTCOME_PEACH_WON   = -2,
    OUTCOME_LEFT_WON    = 1,
    OUTCOME_RIGHT_WON   = 2,
    OUTCOME_TIE         = 3,
};

EvtScript N(EVS_DeclareWinner) = {
    Set(LVar0, OUTCOME_LEFT_WON)
    Set(LVar1, AB_KKJ29_LeftKoopatrolScore)
    Switch(AB_KKJ29_PeachScore)
        CaseGt(LVar1)
            // peach beat left koopatrol
            Set(LVar0, OUTCOME_PEACH_WON)
            Set(LVar1, AB_KKJ29_PeachScore)
        CaseEq(LVar1)
            // peach tied
            Set(LVar0, OUTCOME_TIE)
    EndSwitch
    Switch(AB_KKJ29_RightKoopatrolScore)
        CaseGt(LVar1)
            // peach lost to right koopatrol
            Set(LVar0, OUTCOME_RIGHT_WON)
        CaseEq(LVar1)
            // all tied
            Set(LVar0, OUTCOME_TIE)
    EndSwitch
    Switch(LVar0)
        CaseEq(OUTCOME_LEFT_WON)
            Set(LVar1, -280)
            Set(LVar2, -320)
        CaseEq(OUTCOME_PEACH_WON)
            Set(LVar1, -270)
            Set(LVar2, -230)
        CaseEq(OUTCOME_RIGHT_WON)
            Set(LVar1, -180)
            Set(LVar2, -140)
        CaseEq(OUTCOME_TIE)
            Set(LVar1, -270)
            Set(LVar2, -230)
    EndSwitch
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    Call(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, true)
    Call(SetNpcSpeed, NPC_HammerBros, Float(3.0))
    Call(NpcMoveTo, NPC_HammerBros, -400, 0, 0)
    Call(NpcMoveTo, NPC_HammerBros, LVar1, 0, 0)
    IfEq(LVar0, 1)
        Call(NpcFaceNpc, NPC_HammerBros, LVar0, 7)
    EndIf
    IfNe(LVar0, 3)
        Call(NpcMoveTo, NPC_HammerBros, LVar1, -60, 0)
    EndIf
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    Call(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, false)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar2, 30, -140)
    Call(SetPanTarget, CAM_DEFAULT, LVar2, 30, -140)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Switch(LVar0)
        CaseEq(OUTCOME_LEFT_WON)
            Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_01, MSG_Peach_011B)
            Call(PlaySound, SOUND_AUDIENCE_CHEER)
            Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim19)
            Call(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_011C)
            Wait(10)
            Set(LVar0, ITEM_JAMMIN_JELLY)
            Set(LVar1, NPC_Koopatrol_01)
            Set(LVar2, MSG_Peach_011D)
            ExecWait(N(EVS_GiveItemToKoopatrol))
            Wait(10)
        CaseEq(OUTCOME_PEACH_WON)
            Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0121)
            Call(PlaySound, SOUND_AUDIENCE_CHEER)
            Call(SetPlayerAnimation, ANIM_Peach2_Delighted)
            Wait(1)
            Call(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0122)
            Wait(10)
            Call(ShowGotItem, ITEM_JAMMIN_JELLY, true, ITEM_PICKUP_FLAG_NO_ANIMS)
            Set(GF_KKJ29_PeachWonJamminJelly, true)
            Wait(10)
        CaseEq(OUTCOME_RIGHT_WON)
            Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_02, MSG_Peach_011E)
            Call(PlaySound, SOUND_AUDIENCE_CHEER)
            Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim19)
            Call(ContinueSpeech, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_011F)
            Wait(10)
            Set(LVar0, ITEM_JAMMIN_JELLY)
            Set(LVar1, NPC_Koopatrol_02)
            Set(LVar2, MSG_Peach_0120)
            ExecWait(N(EVS_GiveItemToKoopatrol))
            Wait(10)
        CaseEq(OUTCOME_TIE)
            IfEq(AB_KKJ29_PeachScore, 0)
                Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0124)
            Else
                Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_0123)
            EndIf
            Call(PlaySound, SOUND_AUDIENCE_BOO)
    EndSwitch
    Return
    End
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
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ApproachPeach) = {
    Call(SetNpcVar, NPC_HammerBros, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim09)
        Call(SetNpcSpeed, NPC_HammerBros, Float(5.0))
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        Call(NpcFacePlayer, NPC_HammerBros, 5)
        Call(SetNpcVar, NPC_HammerBros, 0, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_HammerBros, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_PickUpPeach) = {
    Thread
        Call(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim13)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Add(LVar0, 10)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway) = {
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
            Add(LVar0, 32)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_HammerBros, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim08)
        Call(SetNpcSpeed, NPC_HammerBros, Float(5.0))
        Call(NpcMoveTo, NPC_HammerBros, 404, -26, 0)
        Call(SetNpcVar, NPC_HammerBros, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, 436, -22, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_OpenDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 120, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o57, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseDoor) = {
    Call(MakeLerp, 120, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o57, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_TwinkHide) = {
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    Call(LoadPath, 20 * DT, Ref(N(TwinkHidePath)), ARRAY_COUNT(N(TwinkHidePath)), EASING_LINEAR)
    ExecWait(N(EVS_TwinkFollowPath))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Sad)
    Return
    End
};

EvtScript N(EVS_PeachSweat) = {
    Loop(0)
        Call(ShowSweat, 0, 1, -45, EMOTER_PLAYER, 0, 0, 0, 0, 20)
        Wait(20 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TwinkSweat) = {
    Loop(0)
        Call(ShowSweat, NPC_PARTNER, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Wait(20 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ManageQuizGame) = {
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(RotateModel, MODEL_o57, 120, 0, 1, 0)
    Call(func_802D1270, 250, -30, Float(2.0 / DT))
    ExecWait(N(EVS_CloseDoor))
    Call(DisablePartnerAI, 0)
    Exec(N(EVS_TwinkHide))
    Thread
        Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
        Wait(60 * DT)
        Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    EndThread
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_Koopatrol_01, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Koopatrol_01, EMOTE_QUESTION, -45, 15, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim17)
    Call(NpcJump0, NPC_Koopatrol_01, 175, 0, -25, 10 * DT)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_00EF)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim09)
    Call(SetNpcSpeed, NPC_HammerBros, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_HammerBros, 130, -25, 0)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    Call(UseSettingsFrom, CAM_DEFAULT, 190, 0, -25)
    Call(SetPanTarget, CAM_DEFAULT, 190, 0, -25)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, NPC_Koopatrol_01, MSG_Peach_00F0)
    Call(InterpNpcYaw, NPC_Koopatrol_01, 270, 0)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_00F1)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    Call(SetNpcSpeed, NPC_HammerBros, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_HammerBros, 130, 0, 0)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_00F2)
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 5)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
    Call(SetNpcSpeed, NPC_Koopatrol_01, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
    Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_00F3)
    Thread
        Call(func_802D1270, 0, -25, Float(2.0 / DT))
        Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
        Call(SetPlayerPos, -230, 23, -140)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Koopatrol_01, 0, -25, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim03)
        Call(SetNpcPos, NPC_Koopatrol_01, -320, 30, -140)
        Call(SetNpcYaw, NPC_Koopatrol_01, 90)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
        Call(NpcMoveTo, NPC_HammerBros, 0, -25, 0)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        Call(SetNpcPos, NPC_HammerBros, -230, 0, 0)
        Call(SetNpcYaw, NPC_HammerBros, 90)
    EndThread
    Wait(60 * DT)
    Call(LoadPath, 50 * DT, Ref(N(TwinkFollowPath1)), ARRAY_COUNT(N(TwinkFollowPath1)), EASING_LINEAR)
    ExecWait(N(EVS_TwinkFollowPath))
    ExecGetTID(N(EVS_TwinkSweat), LVarA)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Shout, ANIM_Twink_Shout, 5, MSG_Peach_00F4)
    KillThread(LVarA)
    Call(UseSettingsFrom, CAM_DEFAULT, -230, 0, -140)
    Call(SetPanTarget, CAM_DEFAULT, -230, 0, -140)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.961))
#else
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Angry)
    Call(LoadPath, 100 * DT, Ref(N(TwinkFollowPath2)), ARRAY_COUNT(N(TwinkFollowPath2)), EASING_LINEAR)
    ExecWait(N(EVS_TwinkFollowPath))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Wait(30 * DT)
    Call(SetMusic, 0, SONG_PEACH_QUIZ_INTRO, 0, VOL_LEVEL_FULL)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F5)
    Call(PlaySound, SOUND_AUDIENCE_CHEER)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F6)
    Call(PlaySound, SOUND_AUDIENCE_CHEER)
    Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(13 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, -45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(13 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 45, 13, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardIdle)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    Call(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, true)
    Call(NpcMoveTo, NPC_HammerBros, -395, 0, 0)
    Call(InterpNpcYaw, NPC_HammerBros, 90, 7 * DT)
    Call(NpcMoveTo, NPC_HammerBros, -395, -30, 0)
    Call(SetNpcFlagBits, NPC_HammerBros, NPC_FLAG_GRAVITY, false)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, -395, 10, -40)
    Call(SetPanTarget, CAM_DEFAULT, -395, 10, -40)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-370.0), Float(40.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetMusic, 0, SONG_PEACH_QUIZ_INTRO, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_00F8)
    ExecWait(N(EVS_SetCam_Contestants))
    Set(AB_KKJ29_LeftKoopatrolScore, 0)
    Set(AB_KKJ29_PeachScore, 0)
    Set(AB_KKJ29_RightKoopatrolScore, 0)
    // round 1
    Set(LVar1, MSG_Peach_00FC)
    Set(LVar2, 40 * DT)
    Set(LVar3, MSG_Peach_00FD)
    Set(LVar4, MSG_Choice_002C)
    Set(LVar5, 1)
    Set(LVar6, MSG_Peach_0111)
    ExecWait(N(Script_DoRound))
    // round 2
    Set(LVar1, MSG_Peach_00FE)
    Set(LVar2, 10 * DT)
    Set(LVar3, MSG_Peach_00FF)
    Set(LVar4, MSG_Choice_002D)
    Set(LVar5, 0)
    Set(LVar6, MSG_Peach_0112)
    ExecWait(N(Script_DoRound))
    // round 3
    Set(LVar1, MSG_Peach_0100)
    Set(LVar2, 60 * DT)
    Set(LVar3, MSG_Peach_0101)
    Set(LVar4, MSG_Choice_002E)
    Set(LVar5, 2)
    Set(LVar6, MSG_Peach_0113)
    ExecWait(N(Script_DoRound))
    // round 4
    Set(LVar1, MSG_Peach_0102)
    Set(LVar2, 10 * DT)
    Set(LVar3, MSG_Peach_0103)
    Set(LVar4, MSG_Choice_002F)
    Set(LVar5, 0)
    Set(LVar6, MSG_Peach_0114)
    ExecWait(N(Script_DoRound))
    // round 5
    Set(LVar1, MSG_Peach_0104)
    Set(LVar2, 30 * DT)
    Set(LVar3, MSG_Peach_0105)
    Set(LVar4, MSG_Choice_0030)
    Set(LVar5, 2)
    Set(LVar6, MSG_Peach_0115)
    ExecWait(N(Script_DoRound))
    // round 6
    Set(LVar1, MSG_Peach_0106)
    Set(LVar2, 20)
    Set(LVar3, MSG_Peach_0107)
    Set(LVar4, MSG_Choice_0031)
    Set(LVar5, 0)
    Set(LVar6, MSG_Peach_0116)
    ExecWait(N(Script_DoRound))
    // round 7
    Set(LVar1, MSG_Peach_0108)
    Set(LVar2, 30 * DT)
    Set(LVar3, MSG_Peach_0109)
    Set(LVar4, MSG_Choice_0032)
    Set(LVar5, 1)
    Set(LVar6, MSG_Peach_0117)
    ExecWait(N(Script_DoRound))
    // round 8
    Set(LVar1, MSG_Peach_010A)
    Set(LVar2, 60 * DT)
    Set(LVar3, MSG_Peach_010B)
    Set(LVar4, MSG_Choice_0033)
    Set(LVar5, 1)
    Set(LVar6, MSG_Peach_0118)
    ExecWait(N(Script_DoRound))
    // round 9
    Set(LVar1, MSG_Peach_010C)
    Set(LVar2, 60 * DT)
    Set(LVar3, MSG_Peach_010D)
    Set(LVar4, MSG_Choice_0034)
    Set(LVar5, 0)
    Set(LVar6, MSG_Peach_0119)
    ExecWait(N(Script_DoRound))
    // round 10
    Set(LVar1, MSG_Peach_010E)
    Set(LVar2, 30 * DT)
    Set(LVar3, MSG_Peach_010F)
    Set(LVar4, MSG_Choice_0035)
    Set(LVar5, 0)
    Set(LVar6, MSG_Peach_011A)
    ExecWait(N(Script_DoRound))
    Call(SetMusic, 0, SONG_PEACH_MISSION, 0, VOL_LEVEL_FULL)
    ExecWait(N(EVS_DeclareWinner))
    Call(SetPanTarget, CAM_DEFAULT, -230, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim06)
    Call(NpcMoveTo, NPC_HammerBros, -230, 0, 0)
    Call(InterpNpcYaw, NPC_HammerBros, 90, 0)
    Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
    Call(SetMusic, 0, SONG_PEACH_QUIZ_INTRO, BGM_VARIATION_2, VOL_LEVEL_FULL)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0125)
    Call(SetNpcVar, NPC_HammerBros, 0, 1)
    Thread
        Wait(20 * DT)
        Call(DisablePlayerPhysics, false)
        Call(PlayerMoveTo, -185, -140, 20)
        Call(PlayerMoveTo, -185, 0, 70)
        Call(DisablePlayerPhysics, true)
        Call(SetNpcVar, NPC_HammerBros, 0, 0)
    EndThread
    Thread
        Wait(20 * DT)
        Call(NpcFlyTo, NPC_PARTNER, -160, 50, 0, 90, 0, EASING_LINEAR)
    EndThread
    Thread
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
        Call(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_GRAVITY, true)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(2.0 / DT))
        Call(NpcMoveTo, NPC_Koopatrol_01, -400, -140, 0)
        Call(SetNpcFlagBits, NPC_Koopatrol_01, NPC_FLAG_GRAVITY, false)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim04)
        Call(SetNpcFlagBits, NPC_Koopatrol_02, NPC_FLAG_GRAVITY, true)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(2.0 / DT))
        Call(NpcMoveTo, NPC_Koopatrol_02, 0, -140, 0)
        Call(SetNpcFlagBits, NPC_Koopatrol_02, NPC_FLAG_GRAVITY, false)
        Call(SetNpcPos, NPC_Koopatrol_02, NPC_DISPOSE_LOCATION)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_HammerBros, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPanTarget, CAM_DEFAULT, -190, 0, 70)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0126)
    Call(ShowGotItem, ITEM_SNEAKY_PARASOL, true, 0)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 0, MSG_Peach_0127)
    Wait(10 * DT)
    Call(SetMusic, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_FULL)
    Call(UseSettingsFrom, CAM_DEFAULT, 330, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 330, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(250.0), Float(40.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(20 * DT)
    Call(SetNpcPos, NPC_HammerBros, -350, 0, 0)
    Call(SetNpcPos, NPC_Koopatrol_01, -325, 0, -30)
    Call(SetNpcYaw, NPC_Koopatrol_01, 90)
    Exec(N(EVS_OpenDoor))
    Call(SetNpcPos, NPC_Bowser, 410, 0, -25)
    Call(SetNpcSpeed, NPC_Bowser, Float(2.0 / DT))
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Bowser, 250, -25, 0)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_HammerBros, MSG_Peach_0128)
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, MSG_Peach_0129)
    Call(SetNpcVar, NPC_Bowser, 1, 1)
    Thread
        Call(SetPlayerPos, -185, 0, -100)
        Call(InterpPlayerYaw, 90, 0)
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
            IfLt(LVar0, -20)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpPlayerYaw, 270, 0)
        ExecGetTID(N(EVS_PeachSweat), LVarA)
        Loop(0)
            Wait(1)
            Call(GetNpcVar, NPC_Bowser, 1, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        KillThread(LVarA)
        Wait(10 * DT)
        Call(InterpPlayerYaw, 90, 7)
        Call(func_802D1270, -180, -24, Float(2.0 / DT))
        Call(func_802D1270, -120, -24, Float(2.0 / DT))
    EndThread
    Thread
        Call(SetNpcPos, NPC_PARTNER, -175, 60, -100)
        Call(SetNpcYaw, NPC_PARTNER, 90)
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
            IfLt(LVar0, -10)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        ExecGetTID(N(EVS_TwinkSweat), LVarA)
        Loop(0)
            Wait(1)
            Call(GetNpcVar, NPC_Bowser, 1, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        KillThread(LVarA)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
        Call(LoadPath, 50 * DT, Ref(N(TwinkFlyAwayPath)), ARRAY_COUNT(N(TwinkFlyAwayPath)), EASING_LINEAR)
        ExecWait(N(EVS_TwinkFollowPath))
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetPanTarget, CAM_DEFAULT, -300, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    EndThread
    Call(SetNpcSpeed, NPC_Bowser, Float(3.75 / DT))
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Bowser, -260, 0, 0)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SetNpcVar, NPC_Bowser, 0, 0)
    Call(SetNpcVar, NPC_Bowser, 1, 0)
    Wait(10 * DT)
    Loop(2)
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Talk)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        Wait(3 * DT)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim0B)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim03)
        Wait(3 * DT)
    EndLoop
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_HammerBros, MSG_Peach_012A)
    Call(InterpNpcYaw, NPC_Bowser, 90, 5)
    Call(SetPanTarget, CAM_DEFAULT, -190, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Thread
        Wait(10 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
        Call(InterpPlayerYaw, 270, 5)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
        Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    EndThread
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Shock, ANIM_WorldBowser_Shock, 5, MSG_Peach_012B)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 5, MSG_Peach_012C)
    ExecWait(N(EVS_ApproachPeach))
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0B, ANIM_HammerBros_Anim03, 5, MSG_Peach_012D)
    ExecWait(N(EVS_PickUpPeach))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_012E)
    ExecWait(N(EVS_CarryPeachAway))
    Wait(30 * DT)
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter5))
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};
