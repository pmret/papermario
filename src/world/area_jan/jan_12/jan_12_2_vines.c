#include "jan_12.h"

#include "world/common/todo/PullVine.inc.c"

// LVarF  ground modelID
// LVarD  vine modelID 1
// LVarE  vine modelID 2
// LVar9  tree leaves modelID 1
// LVarA  tree leaves modelID 2
// LVarB  tree leaves modelID 3
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
            EVT_CALL(PlaySoundAt, SOUND_2089, 0, LVar0, LVar1, LVar2)
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
                EVT_EXEC(MV_Unk_0A)
            EVT_ELSE
                EVT_THREAD
                    EVT_WAIT(LVar5)
                    EVT_EXEC(MV_Unk_0A)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000D)
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
            EVT_CALL(PlaySoundAt, SOUND_2089, 0, LVar0, LVar1, LVar2)
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

#include "world/common/todo/PullVineSub.inc.c"

EvtScript N(EVS_MoveBushes_Separate) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o12, SOUND_209F, 0)
    EVT_SET(LVar0, MV_BushOffsetL)
    EVT_SET(LVar1, MV_BushOffsetR)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_LOOP(60)
        EVT_SETF(LVar2, MV_BushOffsetL)
        EVT_SETF(LVar3, MV_BushOffsetR)
        EVT_SUBF(LVar2, LVar0)
        EVT_SUBF(LVar3, LVar1)
        EVT_SETF(LVar4, LVar2)
        EVT_SETF(LVar5, LVar3)
        EVT_MULF(LVar4, EVT_FLOAT(0.09375))
        EVT_MULF(LVar5, EVT_FLOAT(0.09375))
        EVT_MULF(LVar6, EVT_FLOAT(0.8))
        EVT_MULF(LVar7, EVT_FLOAT(0.8))
        EVT_ADDF(LVar6, LVar4)
        EVT_ADDF(LVar7, LVar5)
        EVT_ADDF(LVar0, LVar6)
        EVT_ADDF(LVar1, LVar7)
        EVT_CALL(TranslateModel, MODEL_o12, MV_BushOffsetL, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o26, MV_BushOffsetR, 0, 0)
        EVT_CALL(N(PullVine_ShearBushModel), 28, LVar6)
        EVT_CALL(N(PullVine_ShearBushModel), 30, LVar7)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_MoveBushes) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_MoveBushes_Separate))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_BushOffsetR, LVar0)
        EVT_SETF(MV_BushOffsetL, MV_BushOffsetR)
        EVT_MULF(MV_BushOffsetL, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnVineDrop) = {
    EVT_CALL(GetModelCenter, LVar9)
    EVT_ADD(LVar2, 10)
    EVT_CALL(MakeItemEntity, ITEM_EGG, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN12_PullVine_Egg2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupVines) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_MoveBushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o12, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_12_ENTRY_1)
        EVT_EXEC(N(EVS_Inspect_MoveBushes))
    EVT_END_IF
    EVT_SET(MV_Unk_0A, EVT_PTR(N(EVS_SpawnVineDrop)))
    EVT_SET(LVarF, MODEL_o47)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, MODEL_o76)
    EVT_SET(LVarE, MODEL_o77)
    EVT_SET(LVar9, MODEL_o6)
    EVT_SET(LVarA, MODEL_o62)
    EVT_SET(LVarB, MODEL_o63)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_RETURN
    EVT_END
};
