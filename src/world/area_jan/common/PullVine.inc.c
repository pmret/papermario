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
    EVT_CALL(GetModelCenter, LVarE)
    EVT_SET(LVar6, LVar0)
    EVT_SET(LVar7, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_ADD(LVar7, -20)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(N(PullVine_WaitForPlayerGrab), LVar6, LVar7, LVar8, 20)
        EVT_CALL(GetPlayerActionState, LVar1)
        EVT_IF_NE(LVar1, ACTION_STATE_JUMP)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(GetModelCenter, LVarD)
            EVT_CALL(PlaySoundAt, SOUND_PULL_VINE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
            EVT_SETF(LVar0, EVT_FLOAT(0.0))
            EVT_SETF(LVar1, EVT_FLOAT(0.0))
            EVT_THREAD
                EVT_LOOP(3)
                    EVT_IF_NE(LVar9, 0)
                        EVT_CALL(TranslateModel, LVar9, -2, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarB, 0)
                        EVT_CALL(TranslateModel, LVarB, 2, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(1)
                    EVT_IF_NE(LVar9, 0)
                        EVT_CALL(TranslateModel, LVar9, 2, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarB, 0)
                        EVT_CALL(TranslateModel, LVarB, -2, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, 0, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, 0, 0, 0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_IF_EQ(LVar5, 0)
                EVT_EXEC(PULL_VINE_CALLBACK_SCRIPT)
            EVT_ELSE
                EVT_THREAD
                    EVT_WAIT(LVar5)
                    EVT_EXEC(PULL_VINE_CALLBACK_SCRIPT)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
            EVT_LOOP(50)
                EVT_CALL(N(PullVine_UpdatePosition), LVar0, EVT_FLOAT(-15.0), LVar2)
                EVT_ADDF(LVar1, LVar2)
                EVT_MULF(LVar1, EVT_FLOAT(0.93))
                EVT_ADDF(LVar0, LVar1)
                EVT_CALL(TranslateModel, LVarD, 0, LVar0, 0)
                EVT_CALL(TranslateModel, LVarE, 0, LVar0, 0)
                EVT_SET(LVar3, LVar7)
                EVT_ADD(LVar3, LVar0)
                EVT_SET(LVar4, LVar8)
                EVT_ADD(LVar4, 2)
                EVT_ADD(LVar3, 5)
                EVT_CALL(SetPlayerPos, LVar6, LVar3, LVar4)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetModelCenter, LVarF)
            EVT_CALL(SetPlayerJumpscale, 1)
            EVT_CALL(PlayerJump, LVar6, LVar1, LVar4, 10)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_CALL(GetModelCenter, LVarD)
            EVT_CALL(PlaySoundAt, SOUND_PULL_VINE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_LOOP(5)
                    EVT_IF_NE(LVar9, 0)
                        EVT_CALL(TranslateModel, LVar9, -2, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarB, 0)
                        EVT_CALL(TranslateModel, LVarB, 2, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(1)
                    EVT_IF_NE(LVar9, 0)
                        EVT_CALL(TranslateModel, LVar9, 2, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarA, 0)
                        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
                    EVT_END_IF
                    EVT_IF_NE(LVarB, 0)
                        EVT_CALL(TranslateModel, LVarB, -2, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_NE(LVar9, 0)
                    EVT_CALL(TranslateModel, LVar9, 0, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarA, 0)
                    EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
                EVT_END_IF
                EVT_IF_NE(LVarB, 0)
                    EVT_CALL(TranslateModel, LVarB, 0, 0, 0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_SETF(LVar0, EVT_FLOAT(-15.0))
                EVT_SETF(LVar1, EVT_FLOAT(0.0))
                EVT_LOOP(100)
                    EVT_CALL(N(PullVine_UpdatePosition), LVar0, EVT_FLOAT(20.0), LVar2)
                    EVT_ADDF(LVar1, LVar2)
                    EVT_MULF(LVar1, EVT_FLOAT(0.93))
                    EVT_ADDF(LVar0, LVar1)
                    EVT_CALL(TranslateModel, LVarD, 0, LVar0, 0)
                    EVT_CALL(TranslateModel, LVarE, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
