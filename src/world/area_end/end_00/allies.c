#include "end_00.h"
#include "effects.h"

EvtScript N(EVS_ParadePhase_Luigi) = {
    Call(PlaySound, SOUND_LRAW_AUDIENCE_MURMUR)
    Wait(80 * DT)
    Thread
        Loop(9 * DT)
            Call(PlaySoundAtNpc, NPC_Luigi, SOUND_MSG_VOICE_1A, SOUND_SPACE_DEFAULT)
            Wait(15)
        EndLoop
    EndThread
    Call(NpcMoveTo, NPC_Luigi, PARADE_START, 0, 120 * DT)
    Call(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_Idle)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Luigi, 90, 0)
    Wait(25 * DT)
    Call(StopSound, SOUND_LRAW_AUDIENCE_MURMUR)
    Wait(15 * DT)
    Thread
        Wait(10 * DT)
        Loop(4 * DT)
            Call(PlaySoundAtNpc, NPC_Luigi, SOUND_MSG_VOICE_2B, SOUND_SPACE_DEFAULT)
            Wait(15)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_BlowWhistle)
    Wait(30 * DT)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_MarchInPlace)
    Wait(7 * DT)
    Call(SetMusic, 0, SONG_PARADE_DAY, 0, VOL_LEVEL_FULL)
    Wait(120 * DT)
    Wait(100 * DT)
    Call(InterpNpcYaw, NPC_Luigi, 270, 0)
    Wait(30 * DT)
    Return
    End
};

EvtScript N(EVS_ParadePhase_Partners) = {
    PlayEffect(EFFECT_CONFETTI, 3, -2545, 200, 0, 1, 800)
    Call(EnableNpcShadow, NPC_Goombario, FALSE)
    Call(EnableNpcShadow, NPC_Bombette, FALSE)
    ChildThread
        Loop(0)
            Wait(25)
            PlayEffect(EFFECT_CONFETTI, 4, -2530, 95, 5, 1, 20)
            Wait(20)
        EndLoop
    EndChildThread
    ChildThread
        Call(SetNpcJumpscale, NPC_Sushie, Float(1.0))
        Loop(0)
            Call(NpcJump0, NPC_Sushie, -2550, 35, 7, 15)
            Wait(10)
            Call(NpcJump0, NPC_Sushie, -2570, 61, 7, 15)
            Wait(10)
        EndLoop
    EndChildThread
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_PARTNERS + 545)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Twirler) = {
    Call(EnableNpcShadow, LVar1, FALSE)
    Call(SetNpcJumpscale, LVar1, Float(0.5))
    Loop(0)
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerWalk)
        Wait(30)
        ChildThread
            Call(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
            Add(LVar2, -7)
            Call(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            Call(NpcJump0, LVar1, LVar2, LVar3, LVar4, 40)
            Call(SetNpcPos, LVar1, 0, -500, 0)
        EndChildThread
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerToss)
        Wait(5)
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerCatch)
        Wait(5)
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerSpin)
        Wait(20)
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerToss)
        Wait(5)
        Call(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerCatch)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_QuizCrew) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN + 420)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_OpenHat)
    Wait(10)
    Call(GetNpcPos, NPC_ChuckQuizmo, LVar0, LVar1, LVar2)
    Add(LVar1, 80)
    PlayEffect(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Clap)
    Wait(60)
    Call(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_CloseHat)
    Wait(10)
    Call(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_Walk)
    Call(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Walk)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN + 600)
            BreakLoop
        EndIf
    EndLoop
    Call(InterpNpcYaw, NPC_VannaT, 90, 5)
    Call(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Wave)
    Wait(30)
    Call(InterpNpcYaw, NPC_VannaT, 270, 5)
    Call(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Walk)
    Return
    End
};

EvtScript N(EVS_ParadePhase_Toads) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar0, NPC_Twirler1)
    Set(LVar1, NPC_Baton1)
    ExecGetTID(N(EVS_Twirler), LVarA)
    Set(LVar0, NPC_Twirler2)
    Set(LVar1, NPC_Baton2)
    ExecGetTID(N(EVS_Twirler), LVarB)
    Set(LVar0, NPC_Twirler3)
    Set(LVar1, NPC_Baton3)
    ExecGetTID(N(EVS_Twirler), LVarC)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN + 250)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_QuizCrew))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN + 480)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    KillThread(LVarC)
    Return
    End
};
