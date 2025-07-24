#include "kkj_00.h"

EvtScript N(EVS_OpenAndCloseFrontDoor_Intro) = {
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door2, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_door1, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30 * DT)
    Call(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door2, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_door1, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_Scene_Intro) = {
    Call(DisablePlayerInput, true)
    Exec(N(EVS_OpenAndCloseFrontDoor_Intro))
    Thread
        Call(SetNpcSpeed, NPC_Luigi, Float(4.0))
        Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_RunBack)
        Call(NpcMoveTo, NPC_Luigi, 20, 320, 0)
        Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EndThread
    Call(func_802D1270, 80, 300, Float(4.0 / DT))
    Call(InterpPlayerYaw, 270, 5)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_Intro_0024)
    Wait(20 * DT)
    Call(DisablePlayerInput, false)
    Return
    End
};
