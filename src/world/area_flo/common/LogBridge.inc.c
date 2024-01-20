#include "common.h"

API_CALLABLE(N(GetFloorBelowLog)) {
    evt_set_variable(script, *script->ptrReadPos, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_LogBridge) = {
    Loop(0)
        Call(N(GetFloorBelowLog), LVar0)
        IfEq(LVar0, LVar4)
            Call(GetPlayerActionState, LVar0)
            IfNe(LVar0, ACTION_STATE_HIT_LAVA)
                IfEq(LVar8, 0)
                    Thread
                        Call(GetModelCenter, LVar5)
                        Call(PlaySoundAt, SOUND_FLO_LOG_OPEN, SOUND_PARAM_QUIET | SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    EndThread
                EndIf
                IfLt(LVar7, 90)
                    IfEq(LVar7, 0)
                        Wait(5)
                        Set(LVar8, 6)
                        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar9, COLLIDER_FLAGS_UPPER_MASK)
                    EndIf
                    Add(LVar8, 1)
                    Add(LVar7, LVar8)
                EndIf
                Goto(50)
            EndIf
        EndIf
        IfNe(LVar7, 0)
            Sub(LVar8, 1)
            Add(LVar7, LVar8)
            IfLe(LVar7, 0)
                Set(LVar8, 0)
                Set(LVar7, 0)
                Thread
                    Call(GetModelCenter, LVar5)
                    Call(PlaySoundAt, SOUND_FLO_LOG_CLOSE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                EndThread
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar9, COLLIDER_FLAGS_UPPER_MASK)
            EndIf
        EndIf
        Label(50)
        IfGe(LVar7, 90)
            Set(LVar8, -1)
            Set(LVar7, 90)
        EndIf
        Call(RotateModel, LVar5, LVar7, -1, 0, 0)
        Call(RotateModel, LVar6, LVar7, -1, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

#define EVT_MAKE_LOG_BRIDGE(collider, roofCollider, outsideModel, insideModel, rotAngleVar, rotVelocityVar) \
    Set(LVar4, collider) \
    Set(LVar5, outsideModel) \
    Set(LVar6, insideModel) \
    Set(LVar7, rotAngleVar) \
    Set(LVar8, rotVelocityVar) \
    Set(LVar9, roofCollider) \
    Exec(N(EVS_LogBridge))
