#include "kzn_02.h"

API_CALLABLE(N(GetModelLateralPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
    script->varTable[7] = centerX;
    script->varTable[8] = centerZ;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCurrentFloor)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetActingPartner)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gPartnerStatus.actingPartner);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddPushVelocity)) {
    Bytecode* args = script->ptrReadPos;
    s32 velX = evt_get_variable(script, *args++);
    s32 floorA = evt_get_variable(script, *args++);
    s32 floorB = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus= &gCollisionStatus;
    Npc* partner;

    if ((collisionStatus->curFloor == floorA) || (collisionStatus->lastTouchedFloor == floorA)
     || (collisionStatus->curFloor == floorB) || (collisionStatus->lastTouchedFloor == floorB)) {
        playerStatus->pushVel.x = velX;
    }
    if (gPlayerData.curPartner != PARTNER_NONE){
        partner = get_npc_unsafe(NPC_PARTNER);
        if ((partner->curFloor == floorA) || (partner->curFloor == floorB)) {
            partner->pos.x += velX;
        }
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_KoloradoSinkingPlatform) = {
    SetF(LVar0, Float(0.0))
    Label(0)
        Call(TranslateModel, MODEL_o29, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o30, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o31, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o146)
        Call(UpdateColliderTransform, COLLIDER_o147)
        Call(UpdateColliderTransform, COLLIDER_o148)
        Wait(1)
        SubF(LVar0, Float(0.7))
        IfGe(LVar0, -22)
            Goto(0)
        EndIf
    Label(1)
        AddF(LVar0, Float(1.1))
        Call(TranslateModel, MODEL_o29, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o30, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o31, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o146)
        Call(UpdateColliderTransform, COLLIDER_o147)
        Call(UpdateColliderTransform, COLLIDER_o148)
        Wait(1)
        IfLt(LVar0, 0)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_UpdateSinkingPlatform) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(N(GetCurrentFloor), LVarA)
    SetF(LVar0, Float(0.0))
    Label(0)
    Call(TranslateModel, LVar1, 0, LVar0, 0)
    Call(TranslateModel, LVar2, 0, LVar0, 0)
    Call(TranslateModel, LVar3, 0, LVar0, 0)
    Call(UpdateColliderTransform, LVar4)
    Call(UpdateColliderTransform, LVar5)
    Call(UpdateColliderTransform, LVar6)
    SubF(LVar0, Float(0.6))
    IfLt(LVar0, -30)
        Set(LVar0, -30)
    EndIf
    Wait(1)
    Call(N(GetCurrentFloor), LVarB)
    Call(GetPlayerActionState, LVarC)
    IfEq(LVarB, LVar4)
        IfNe(LVarC, ACTION_STATE_JUMP)
            Goto(0)
        EndIf
    EndIf
    IfEq(LVarB, LVar5)
        IfNe(LVarC, ACTION_STATE_JUMP)
            Goto(0)
        EndIf
    EndIf
    Label(1)
    IfLe(LVar0, -20)
        Call(IsPlayerWithin, LVar7, LVar8, LVar9, LVarD)
        IfEq(LVarD, 0)
            AddF(LVar0, Float(1.1))
        EndIf
    Else
        AddF(LVar0, Float(1.1))
    EndIf
    Call(TranslateModel, LVar1, 0, LVar0, 0)
    Call(TranslateModel, LVar2, 0, LVar0, 0)
    Call(TranslateModel, LVar3, 0, LVar0, 0)
    Call(UpdateColliderTransform, LVar4)
    Call(UpdateColliderTransform, LVar5)
    Call(UpdateColliderTransform, LVar6)
    Wait(1)
    Call(N(GetCurrentFloor), LVarB)
    Call(GetPlayerActionState, LVarC)
    Call(N(GetActingPartner), LVarD)
    IfEq(LVarD, PARTNER_LAKILESTER)
        Call(IsPlayerWithin, LVar7, LVar8, LVar9, LVarD)
        IfEq(LVarD, 1)
            Goto(0)
        Else
            Goto(15)
        EndIf
    Else
        Label(15)
        IfEq(LVarB, LVar4)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
        IfEq(LVarB, LVar5)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
    EndIf
    IfLt(LVar0, 0)
        Goto(1)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform1) = {
    UseArray(LVar0)
    IfEq(ArrayVar(1), 0)
        Set(ArrayVar(1), 1)
        Set(LVar1, MODEL_o29)
        Set(LVar2, MODEL_o30)
        Set(LVar3, MODEL_o31)
        Set(LVar4, COLLIDER_o146)
        Set(LVar5, COLLIDER_o147)
        Set(LVar6, COLLIDER_o148)
        Call(N(GetModelLateralPos), MODEL_o30)
        Set(LVar9, 50)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(1), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform2) = {
    UseArray(LVar0)
    IfEq(ArrayVar(2), 0)
        Set(ArrayVar(2), 1)
        Set(LVar1, MODEL_o26)
        Set(LVar2, MODEL_o27)
        Set(LVar3, MODEL_o28)
        Set(LVar4, COLLIDER_o143)
        Set(LVar5, COLLIDER_o144)
        Set(LVar6, COLLIDER_o145)
        Call(N(GetModelLateralPos), MODEL_o27)
        Set(LVar9, 60)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(2), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform3) = {
    UseArray(LVar0)
    IfEq(ArrayVar(3), 0)
        Set(ArrayVar(3), 1)
        Set(LVar1, MODEL_o21)
        Set(LVar2, MODEL_o22)
        Set(LVar3, MODEL_o18)
        Set(LVar4, COLLIDER_o140)
        Set(LVar5, COLLIDER_o141)
        Set(LVar6, COLLIDER_o142)
        Call(N(GetModelLateralPos), MODEL_o22)
        Set(LVar9, 50)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(3), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform4) = {
    UseArray(LVar0)
    IfEq(ArrayVar(4), 0)
        Set(ArrayVar(4), 1)
        Set(LVar1, MODEL_o70)
        Set(LVar2, MODEL_o71)
        Set(LVar3, MODEL_o72)
        Set(LVar4, COLLIDER_o131)
        Set(LVar5, COLLIDER_o132)
        Set(LVar6, COLLIDER_o133)
        Call(N(GetModelLateralPos), MODEL_o71)
        Set(LVar9, 50)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(4), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform5) = {
    UseArray(LVar0)
    IfEq(ArrayVar(5), 0)
        Set(ArrayVar(5), 1)
        Set(LVar1, MODEL_o67)
        Set(LVar2, MODEL_o68)
        Set(LVar3, MODEL_o69)
        Set(LVar4, COLLIDER_o134)
        Set(LVar5, COLLIDER_o135)
        Set(LVar6, COLLIDER_o136)
        Call(N(GetModelLateralPos), MODEL_o68)
        Set(LVar9, 60)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(5), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchSinkingPlatform6) = {
    UseArray(LVar0)
    IfEq(ArrayVar(6), 0)
        Set(ArrayVar(6), 1)
        Set(LVar1, MODEL_o64)
        Set(LVar2, MODEL_o65)
        Set(LVar3, MODEL_o66)
        Set(LVar4, COLLIDER_o137)
        Set(LVar5, COLLIDER_o138)
        Set(LVar6, COLLIDER_o139)
        Call(N(GetModelLateralPos), MODEL_o65)
        Set(LVar9, 50)
        ExecWait(N(EVS_UpdateSinkingPlatform))
        Set(ArrayVar(6), 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_UpdatePlatformBobbing) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Label(0)
        Call(MakeLerp, 0, -3, 30, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(TranslateModel, LVar2, 0, LVar0, 0)
            Call(TranslateModel, LVar3, 0, LVar0, 0)
            Call(TranslateModel, LVar4, 0, LVar0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(1)
            EndIf
        Call(MakeLerp, -3, 0, 30, EASING_LINEAR)
        Label(2)
            Call(UpdateLerp)
            Call(TranslateModel, LVar2, 0, LVar0, 0)
            Call(TranslateModel, LVar3, 0, LVar0, 0)
            Call(TranslateModel, LVar4, 0, LVar0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform1) = {
    Wait(5)
    Set(LVar2, MODEL_o29)
    Set(LVar3, MODEL_o30)
    Set(LVar4, MODEL_o31)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform2) = {
    Wait(10)
    Set(LVar2, MODEL_o26)
    Set(LVar3, MODEL_o27)
    Set(LVar4, MODEL_o28)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform3) = {
    Wait(5)
    Set(LVar2, MODEL_o21)
    Set(LVar3, MODEL_o22)
    Set(LVar4, MODEL_o18)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform4) = {
    Wait(10)
    Set(LVar2, MODEL_o70)
    Set(LVar3, MODEL_o71)
    Set(LVar4, MODEL_o72)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform5) = {
    Wait(5)
    Set(LVar2, MODEL_o67)
    Set(LVar3, MODEL_o68)
    Set(LVar4, MODEL_o69)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_StartBobbingPlatform6) = {
    Wait(10)
    Set(LVar2, MODEL_o64)
    Set(LVar3, MODEL_o65)
    Set(LVar4, MODEL_o66)
    ExecWait(N(EVS_UpdatePlatformBobbing))
    Return
    End
};

EvtScript N(EVS_UpdateMovingPlatform) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(ParentColliderToModel, COLLIDER_o128, MODEL_o123)
    Call(ParentColliderToModel, COLLIDER_o129, MODEL_o124)
    Call(ParentColliderToModel, COLLIDER_o130, MODEL_o125)
    Set(LVar0, -105)
    Set(LVar3, 0)
    Loop(0)
        Call(MakeLerp, LVar0, 110, 215, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g22, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o128)
            Call(UpdateColliderTransform, COLLIDER_o129)
            Call(UpdateColliderTransform, COLLIDER_o130)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, COLLIDER_o128, COLLIDER_o129)
            IfGt(LVar0, 95)
                Call(N(GetActingPartner), LVar9)
                IfEq(LVar9, PARTNER_LAKILESTER)
                    Call(N(GetCurrentFloor), LVar2)
                    IfEq(LVar2, COLLIDER_pp2)
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
        Call(MakeLerp, LVar0, -105, 215, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g22, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o128)
            Call(UpdateColliderTransform, COLLIDER_o129)
            Call(UpdateColliderTransform, COLLIDER_o130)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, COLLIDER_o128, COLLIDER_o129)
            IfLt(LVar0, -90)
                Call(N(GetActingPartner), LVar9)
                IfEq(LVar9, PARTNER_LAKILESTER)
                    Call(N(GetCurrentFloor), LVar2)
                    IfEq(LVar2, COLLIDER_pp1)
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

EvtScript N(EVS_InitializePlatforms) = {
    MallocArray(6, LVarA)
    Set(ArrayVar(0), 0)
    Set(ArrayVar(1), 0)
    Set(ArrayVar(2), 0)
    Set(ArrayVar(3), 0)
    Set(ArrayVar(4), 0)
    Set(ArrayVar(5), 0)
    Set(ArrayVar(6), 0)
    Call(ParentColliderToModel, COLLIDER_o146, MODEL_o29)
    Call(ParentColliderToModel, COLLIDER_o147, MODEL_o30)
    Call(ParentColliderToModel, COLLIDER_o148, MODEL_o31)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform1), TRIGGER_FLOOR_TOUCH, COLLIDER_o146, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform1), TRIGGER_FLOOR_TOUCH, COLLIDER_o147, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o143, MODEL_o26)
    Call(ParentColliderToModel, COLLIDER_o144, MODEL_o27)
    Call(ParentColliderToModel, COLLIDER_o145, MODEL_o28)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform2), TRIGGER_FLOOR_TOUCH, COLLIDER_o143, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform2), TRIGGER_FLOOR_TOUCH, COLLIDER_o144, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o140, MODEL_o21)
    Call(ParentColliderToModel, COLLIDER_o141, MODEL_o22)
    Call(ParentColliderToModel, COLLIDER_o142, MODEL_o18)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform3), TRIGGER_FLOOR_TOUCH, COLLIDER_o140, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform3), TRIGGER_FLOOR_TOUCH, COLLIDER_o141, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o131, MODEL_o70)
    Call(ParentColliderToModel, COLLIDER_o132, MODEL_o71)
    Call(ParentColliderToModel, COLLIDER_o133, MODEL_o72)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform4), TRIGGER_FLOOR_TOUCH, COLLIDER_o131, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform4), TRIGGER_FLOOR_TOUCH, COLLIDER_o132, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o134, MODEL_o67)
    Call(ParentColliderToModel, COLLIDER_o135, MODEL_o68)
    Call(ParentColliderToModel, COLLIDER_o136, MODEL_o69)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform5), TRIGGER_FLOOR_TOUCH, COLLIDER_o134, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform5), TRIGGER_FLOOR_TOUCH, COLLIDER_o135, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o137, MODEL_o64)
    Call(ParentColliderToModel, COLLIDER_o138, MODEL_o65)
    Call(ParentColliderToModel, COLLIDER_o139, MODEL_o66)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform6), TRIGGER_FLOOR_TOUCH, COLLIDER_o137, 1, 0)
    Set(LVar0, LVarA)
    BindTrigger(N(EVS_OnTouchSinkingPlatform6), TRIGGER_FLOOR_TOUCH, COLLIDER_o138, 1, 0)
    Exec(N(EVS_StartBobbingPlatform1))
    Exec(N(EVS_StartBobbingPlatform2))
    Exec(N(EVS_StartBobbingPlatform3))
    Exec(N(EVS_StartBobbingPlatform4))
    Exec(N(EVS_StartBobbingPlatform5))
    Exec(N(EVS_StartBobbingPlatform6))
    Exec(N(EVS_UpdateMovingPlatform))
    Return
    End
};
