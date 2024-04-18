#include "kpa_12.h"

API_CALLABLE(N(GetFloorBelow)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddPlatformPushVelocity)) {
    Bytecode* args = script->ptrReadPos;
    s32 velocity = evt_get_variable(script, *args++);
    s32 floor = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gCollisionStatus.curFloor == floor || gCollisionStatus.lastTouchedFloor == floor) {
        playerStatus->pushVel.x = velocity;
    }

    if (gPlayerData.curPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        if (partner->curFloor == floor) {
            partner->pos.x += velocity;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsPartnerLakilester)) {
    if (gPartnerStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SinkingPlatform_Update) = {
    SetGroup(EVT_GROUP_0B)
    SetF(LVar0, Float(0.0))
    Label(0)
        Call(TranslateGroup, LVar1, 0, LVar0, 0)
        Call(UpdateColliderTransform, LVar3)
        SubF(LVar0, Float(0.5))
        IfLt(LVar0, -40)
            Set(LVar0, -40)
        EndIf
        Wait(1)
        Call(N(GetFloorBelow), LVarB)
        Call(GetPlayerActionState, LVarC)
        IfEq(LVar3, LVarB)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
    Label(1)
        AddF(LVar0, Float(1.0))
        Call(TranslateGroup, LVar1, 0, LVar0, 0)
        Call(UpdateColliderTransform, LVar3)
        Wait(1)
        Call(N(GetFloorBelow), LVarB)
        Call(GetPlayerActionState, LVarC)
        IfEq(LVar3, LVarB)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
        IfLt(LVar0, 0)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_Touch_SinkingPlatform1) = {
    Set(LVar1, MODEL_dai01)
    Set(LVar3, COLLIDER_o405)
    ExecWait(N(EVS_SinkingPlatform_Update))
    Return
    End
};

EvtScript N(EVS_Touch_SinkingPlatform2) = {
    Set(LVar1, MODEL_dai02)
    Set(LVar3, COLLIDER_o407)
    ExecWait(N(EVS_SinkingPlatform_Update))
    Return
    End
};

EvtScript N(EVS_Touch_SinkingPlatform3) = {
    Set(LVar1, MODEL_dai03)
    Set(LVar3, COLLIDER_o409)
    ExecWait(N(EVS_SinkingPlatform_Update))
    Return
    End
};

EvtScript N(EVS_Touch_SinkingPlatform4) = {
    Set(LVar1, MODEL_dai04)
    Set(LVar3, COLLIDER_o411)
    ExecWait(N(EVS_SinkingPlatform_Update))
    Return
    End
};

EvtScript N(EVS_SinkingPlatform_Idle) = {
    SetGroup(EVT_GROUP_0B)
    Label(0)
        Call(MakeLerp, 0, -3, 20, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar2, 0, LVar0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(1)
            EndIf
        Call(MakeLerp, -3, 0, 20, EASING_LINEAR)
        Label(2)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar2, 0, LVar0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupSinkingPlatforms) = {
    Thread
        Set(LVar2, MODEL_dai01)
        ExecWait(N(EVS_SinkingPlatform_Idle))
    EndThread
    Wait(10)
    Thread
        Set(LVar2, MODEL_dai02)
        ExecWait(N(EVS_SinkingPlatform_Idle))
    EndThread
    Wait(10)
    Thread
        Set(LVar2, MODEL_dai03)
        ExecWait(N(EVS_SinkingPlatform_Idle))
    EndThread
    Wait(10)
    Set(LVar2, MODEL_dai04)
    ExecWait(N(EVS_SinkingPlatform_Idle))
    Return
    End
};

EvtScript N(EVS_SetupMovingPlatform) = {
    SetGroup(EVT_GROUP_0B)
    Call(ParentColliderToModel, COLLIDER_o414, MODEL_o522)
    Set(LVar0, 0)
    Set(LVar3, 0)
    Loop(0)
        Set(LVar1, 125)
        Sub(LVar1, LVar0)
        Call(MakeLerp, LVar0, 125, LVar1, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o414)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o414)
            IfGt(LVar0, 95)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, 81)
                        BreakLoop
                    EndIf
                EndIf
            EndIf
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20)
        Call(MakeLerp, LVar0, 0, LVar0, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o414)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o414)
            IfLt(LVar0, 30)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, 80)
                        BreakLoop
                    EndIf
                EndIf
            EndIf
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupPlatforms) = {
    Call(ParentColliderToModel, COLLIDER_o405, MODEL_o447)
    Call(ParentColliderToModel, COLLIDER_o407, MODEL_o449)
    Call(ParentColliderToModel, COLLIDER_o409, MODEL_o451)
    Call(ParentColliderToModel, COLLIDER_o411, MODEL_o453)
    BindTrigger(Ref(N(EVS_Touch_SinkingPlatform1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o405, 1, 0)
    BindTrigger(Ref(N(EVS_Touch_SinkingPlatform2)), TRIGGER_FLOOR_TOUCH, COLLIDER_o407, 1, 0)
    BindTrigger(Ref(N(EVS_Touch_SinkingPlatform3)), TRIGGER_FLOOR_TOUCH, COLLIDER_o409, 1, 0)
    BindTrigger(Ref(N(EVS_Touch_SinkingPlatform4)), TRIGGER_FLOOR_TOUCH, COLLIDER_o411, 1, 0)
    Exec(N(EVS_SetupSinkingPlatforms))
    Exec(N(EVS_SetupMovingPlatform))
    Return
    End
};
