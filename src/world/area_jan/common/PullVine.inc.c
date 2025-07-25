#include "common.h"
#include "sprite/player.h"

// ----------------------------------------------------------------
// Requirements

// Script to execute when a vine is pulled (can be a MapVar)
#ifndef PULL_VINE_CALLBACK_SCRIPT
    #error PULL_VINE_CALLBACK_SCRIPT is not defined!
#endif

// ----------------------------------------------------------------
// Implementation

API_CALLABLE(N(PullVine_WaitForPlayerGrab)) {
    Bytecode* args = script->ptrReadPos;
    f32 modelX, modelY, modelZ;
    f32 dx, dy, dz;
    f32 dist;
    s32 result;

    modelX = evt_get_float_variable(script, *args++);
    modelY = evt_get_float_variable(script, *args++) + 15.0f;
    modelZ = evt_get_float_variable(script, *args++);
    dist = evt_get_float_variable(script, *args++);
    dx = script->varTable[0] - modelX;
    dy = script->varTable[1] - modelY;
    dz = script->varTable[2] - modelZ;
    result = 1;
    if (!(SQ(dx) + SQ(dy) + SQ(dz) < SQ(dist))) {
        result = 0;
    }
    script->varTable[0] = result;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PullVine_UpdatePosition)) {
    Bytecode* args = script->ptrReadPos;
    f32 x1 = evt_get_float_variable(script, *args++);
    f32 x2 = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, *args++, (x2 - x1) / 10.0f);
    return ApiStatus_DONE2;
}

// LVarF  ground modelID
// LVarD  vine modelID 1
// LVarE  vine modelID 2
// LVar9  tree leaves modelID 1
// LVarA  tree leaves modelID 2
// LVarB  tree leaves modelID 3
// LVarC  unique vine index
// LVar5  drop delay
EvtScript N(EVS_PullVine_Manage) = {
    Call(GetModelCenter, LVarE)
    Set(LVar6, LVar0)
    Set(LVar7, LVar1)
    Set(LVar8, LVar2)
    Add(LVar7, -20)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(N(PullVine_WaitForPlayerGrab), LVar6, LVar7, LVar8, 20)
        Call(GetPlayerActionState, LVar1)
        IfNe(LVar1, ACTION_STATE_JUMP)
            Set(LVar0, 0)
        EndIf
        IfEq(LVar0, 1)
            Call(DisablePlayerInput, true)
            Call(DisablePlayerPhysics, true)
            Call(GetModelCenter, LVarD)
            Call(PlaySoundAt, SOUND_PULL_VINE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
            SetF(LVar0, Float(0.0))
            SetF(LVar1, Float(0.0))
            Thread
                Loop(3)
                    IfNe(LVar9, 0)
                        Call(TranslateModel, LVar9, -2, 0, 0)
                    EndIf
                    IfNe(LVarA, 0)
                        Call(TranslateModel, LVarA, -1, 0, 0)
                    EndIf
                    IfNe(LVarB, 0)
                        Call(TranslateModel, LVarB, 2, 0, 0)
                    EndIf
                    Wait(1)
                    IfNe(LVar9, 0)
                        Call(TranslateModel, LVar9, 2, 0, 0)
                    EndIf
                    IfNe(LVarA, 0)
                        Call(TranslateModel, LVarA, 1, 0, 0)
                    EndIf
                    IfNe(LVarB, 0)
                        Call(TranslateModel, LVarB, -2, 0, 0)
                    EndIf
                    Wait(1)
                EndLoop
                IfNe(LVar9, 0)
                    Call(TranslateModel, LVar9, 0, 0, 0)
                EndIf
                IfNe(LVarA, 0)
                    Call(TranslateModel, LVarA, 0, 0, 0)
                EndIf
                IfNe(LVarB, 0)
                    Call(TranslateModel, LVarB, 0, 0, 0)
                EndIf
            EndThread
            IfEq(LVar5, 0)
                Exec(PULL_VINE_CALLBACK_SCRIPT)
            Else
                Thread
                    Wait(LVar5)
                    Exec(PULL_VINE_CALLBACK_SCRIPT)
                EndThread
            EndIf
            Call(SetPlayerActionState, ACTION_STATE_LAND)
            Wait(1)
            Call(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
            Loop(50)
                Call(N(PullVine_UpdatePosition), LVar0, Float(-15.0), LVar2)
                AddF(LVar1, LVar2)
                MulF(LVar1, Float(0.93))
                AddF(LVar0, LVar1)
                Call(TranslateModel, LVarD, 0, LVar0, 0)
                Call(TranslateModel, LVarE, 0, LVar0, 0)
                Set(LVar3, LVar7)
                Add(LVar3, LVar0)
                Set(LVar4, LVar8)
                Add(LVar4, 2)
                Add(LVar3, 5)
                Call(SetPlayerPos, LVar6, LVar3, LVar4)
                Wait(1)
            EndLoop
            Call(GetModelCenter, LVarF)
            Call(SetPlayerJumpscale, 1)
            Call(PlayerJump, LVar6, LVar1, LVar4, 10)
            Call(SetPlayerActionState, ACTION_STATE_IDLE)
            Call(GetModelCenter, LVarD)
            Call(PlaySoundAt, SOUND_PULL_VINE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
            Thread
                Wait(10)
                Loop(5)
                    IfNe(LVar9, 0)
                        Call(TranslateModel, LVar9, -2, 0, 0)
                    EndIf
                    IfNe(LVarA, 0)
                        Call(TranslateModel, LVarA, -1, 0, 0)
                    EndIf
                    IfNe(LVarB, 0)
                        Call(TranslateModel, LVarB, 2, 0, 0)
                    EndIf
                    Wait(1)
                    IfNe(LVar9, 0)
                        Call(TranslateModel, LVar9, 2, 0, 0)
                    EndIf
                    IfNe(LVarA, 0)
                        Call(TranslateModel, LVarA, 1, 0, 0)
                    EndIf
                    IfNe(LVarB, 0)
                        Call(TranslateModel, LVarB, -2, 0, 0)
                    EndIf
                    Wait(1)
                EndLoop
                IfNe(LVar9, 0)
                    Call(TranslateModel, LVar9, 0, 0, 0)
                EndIf
                IfNe(LVarA, 0)
                    Call(TranslateModel, LVarA, 0, 0, 0)
                EndIf
                IfNe(LVarB, 0)
                    Call(TranslateModel, LVarB, 0, 0, 0)
                EndIf
            EndThread
            Thread
                SetF(LVar0, Float(-15.0))
                SetF(LVar1, Float(0.0))
                Loop(100)
                    Call(N(PullVine_UpdatePosition), LVar0, Float(20.0), LVar2)
                    AddF(LVar1, LVar2)
                    MulF(LVar1, Float(0.93))
                    AddF(LVar0, LVar1)
                    Call(TranslateModel, LVarD, 0, LVar0, 0)
                    Call(TranslateModel, LVarE, 0, LVar0, 0)
                    Wait(1)
                EndLoop
            EndThread
            Call(DisablePlayerPhysics, false)
            Call(DisablePlayerInput, false)
            Return
        EndIf
        Wait(1)
    Goto(0)
    Return
    End
};
