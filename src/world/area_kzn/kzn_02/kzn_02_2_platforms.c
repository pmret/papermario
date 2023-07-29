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
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LABEL(0)
        EVT_CALL(TranslateModel, MODEL_o29, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o30, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o31, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o146)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o147)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o148)
        EVT_WAIT(1)
        EVT_SUBF(LVar0, EVT_FLOAT(0.7))
        EVT_IF_GE(LVar0, -22)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_ADDF(LVar0, EVT_FLOAT(1.1))
        EVT_CALL(TranslateModel, MODEL_o29, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o30, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o31, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o146)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o147)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o148)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateSinkingPlatform) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(N(GetCurrentFloor), LVarA)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, LVar1, 0, LVar0, 0)
    EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
    EVT_CALL(TranslateModel, LVar3, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, LVar4)
    EVT_CALL(UpdateColliderTransform, LVar5)
    EVT_CALL(UpdateColliderTransform, LVar6)
    EVT_SUBF(LVar0, EVT_FLOAT(0.6))
    EVT_IF_LT(LVar0, -30)
        EVT_SET(LVar0, -30)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(N(GetCurrentFloor), LVarB)
    EVT_CALL(GetPlayerActionState, LVarC)
    EVT_IF_EQ(LVarB, LVar4)
        EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarB, LVar5)
        EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(1)
    EVT_IF_LE(LVar0, -20)
        EVT_CALL(IsPlayerWithin, LVar7, LVar8, LVar9, LVarD)
        EVT_IF_EQ(LVarD, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(1.1))
        EVT_END_IF
    EVT_ELSE
        EVT_ADDF(LVar0, EVT_FLOAT(1.1))
    EVT_END_IF
    EVT_CALL(TranslateModel, LVar1, 0, LVar0, 0)
    EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
    EVT_CALL(TranslateModel, LVar3, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, LVar4)
    EVT_CALL(UpdateColliderTransform, LVar5)
    EVT_CALL(UpdateColliderTransform, LVar6)
    EVT_WAIT(1)
    EVT_CALL(N(GetCurrentFloor), LVarB)
    EVT_CALL(GetPlayerActionState, LVarC)
    EVT_CALL(N(GetActingPartner), LVarD)
    EVT_IF_EQ(LVarD, PARTNER_LAKILESTER)
        EVT_CALL(IsPlayerWithin, LVar7, LVar8, LVar9, LVarD)
        EVT_IF_EQ(LVarD, 1)
            EVT_GOTO(0)
        EVT_ELSE
            EVT_GOTO(15)
        EVT_END_IF
    EVT_ELSE
        EVT_LABEL(15)
        EVT_IF_EQ(LVarB, LVar4)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVarB, LVar5)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_IF_LT(LVar0, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform1) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(1), 0)
        EVT_SET(ArrayVar(1), 1)
        EVT_SET(LVar1, MODEL_o29)
        EVT_SET(LVar2, MODEL_o30)
        EVT_SET(LVar3, MODEL_o31)
        EVT_SET(LVar4, COLLIDER_o146)
        EVT_SET(LVar5, COLLIDER_o147)
        EVT_SET(LVar6, COLLIDER_o148)
        EVT_CALL(N(GetModelLateralPos), MODEL_o30)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(1), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform2) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(2), 0)
        EVT_SET(ArrayVar(2), 1)
        EVT_SET(LVar1, MODEL_o26)
        EVT_SET(LVar2, MODEL_o27)
        EVT_SET(LVar3, MODEL_o28)
        EVT_SET(LVar4, COLLIDER_o143)
        EVT_SET(LVar5, COLLIDER_o144)
        EVT_SET(LVar6, COLLIDER_o145)
        EVT_CALL(N(GetModelLateralPos), MODEL_o27)
        EVT_SET(LVar9, 60)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(2), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform3) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(3), 0)
        EVT_SET(ArrayVar(3), 1)
        EVT_SET(LVar1, MODEL_o21)
        EVT_SET(LVar2, MODEL_o22)
        EVT_SET(LVar3, MODEL_o18)
        EVT_SET(LVar4, COLLIDER_o140)
        EVT_SET(LVar5, COLLIDER_o141)
        EVT_SET(LVar6, COLLIDER_o142)
        EVT_CALL(N(GetModelLateralPos), MODEL_o22)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(3), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform4) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(4), 0)
        EVT_SET(ArrayVar(4), 1)
        EVT_SET(LVar1, MODEL_o70)
        EVT_SET(LVar2, MODEL_o71)
        EVT_SET(LVar3, MODEL_o72)
        EVT_SET(LVar4, COLLIDER_o131)
        EVT_SET(LVar5, COLLIDER_o132)
        EVT_SET(LVar6, COLLIDER_o133)
        EVT_CALL(N(GetModelLateralPos), MODEL_o71)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(4), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform5) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(5), 0)
        EVT_SET(ArrayVar(5), 1)
        EVT_SET(LVar1, MODEL_o67)
        EVT_SET(LVar2, MODEL_o68)
        EVT_SET(LVar3, MODEL_o69)
        EVT_SET(LVar4, COLLIDER_o134)
        EVT_SET(LVar5, COLLIDER_o135)
        EVT_SET(LVar6, COLLIDER_o136)
        EVT_CALL(N(GetModelLateralPos), MODEL_o68)
        EVT_SET(LVar9, 60)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchSinkingPlatform6) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(6), 0)
        EVT_SET(ArrayVar(6), 1)
        EVT_SET(LVar1, MODEL_o64)
        EVT_SET(LVar2, MODEL_o65)
        EVT_SET(LVar3, MODEL_o66)
        EVT_SET(LVar4, COLLIDER_o137)
        EVT_SET(LVar5, COLLIDER_o138)
        EVT_SET(LVar6, COLLIDER_o139)
        EVT_CALL(N(GetModelLateralPos), MODEL_o65)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(EVS_UpdateSinkingPlatform))
        EVT_SET(ArrayVar(6), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdatePlatformBobbing) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -3, 30, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar3, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar4, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, -3, 0, 30, EASING_LINEAR)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar3, 0, LVar0, 0)
            EVT_CALL(TranslateModel, LVar4, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform1) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, MODEL_o29)
    EVT_SET(LVar3, MODEL_o30)
    EVT_SET(LVar4, MODEL_o31)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform2) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, MODEL_o26)
    EVT_SET(LVar3, MODEL_o27)
    EVT_SET(LVar4, MODEL_o28)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform3) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, MODEL_o21)
    EVT_SET(LVar3, MODEL_o22)
    EVT_SET(LVar4, MODEL_o18)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform4) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, MODEL_o70)
    EVT_SET(LVar3, MODEL_o71)
    EVT_SET(LVar4, MODEL_o72)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform5) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, MODEL_o67)
    EVT_SET(LVar3, MODEL_o68)
    EVT_SET(LVar4, MODEL_o69)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBobbingPlatform6) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, MODEL_o64)
    EVT_SET(LVar3, MODEL_o65)
    EVT_SET(LVar4, MODEL_o66)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatformBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateMovingPlatform) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(ParentColliderToModel, COLLIDER_o128, MODEL_o123)
    EVT_CALL(ParentColliderToModel, COLLIDER_o129, MODEL_o124)
    EVT_CALL(ParentColliderToModel, COLLIDER_o130, MODEL_o125)
    EVT_SET(LVar0, -105)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, LVar0, 110, 215, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g22, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o128)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o129)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o130)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, COLLIDER_o128, COLLIDER_o129)
            EVT_IF_GT(LVar0, 95)
                EVT_CALL(N(GetActingPartner), LVar9)
                EVT_IF_EQ(LVar9, PARTNER_LAKILESTER)
                    EVT_CALL(N(GetCurrentFloor), LVar2)
                    EVT_IF_EQ(LVar2, COLLIDER_pp2)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, LVar0, -105, 215, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g22, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o128)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o129)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o130)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, COLLIDER_o128, COLLIDER_o129)
            EVT_IF_LT(LVar0, -90)
                EVT_CALL(N(GetActingPartner), LVar9)
                EVT_IF_EQ(LVar9, PARTNER_LAKILESTER)
                    EVT_CALL(N(GetCurrentFloor), LVar2)
                    EVT_IF_EQ(LVar2, COLLIDER_pp1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitializePlatforms) = {
    EVT_MALLOC_ARRAY(6, LVarA)
    EVT_SET(ArrayVar(0), 0)
    EVT_SET(ArrayVar(1), 0)
    EVT_SET(ArrayVar(2), 0)
    EVT_SET(ArrayVar(3), 0)
    EVT_SET(ArrayVar(4), 0)
    EVT_SET(ArrayVar(5), 0)
    EVT_SET(ArrayVar(6), 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o146, MODEL_o29)
    EVT_CALL(ParentColliderToModel, COLLIDER_o147, MODEL_o30)
    EVT_CALL(ParentColliderToModel, COLLIDER_o148, MODEL_o31)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform1), TRIGGER_FLOOR_TOUCH, COLLIDER_o146, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform1), TRIGGER_FLOOR_TOUCH, COLLIDER_o147, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o143, MODEL_o26)
    EVT_CALL(ParentColliderToModel, COLLIDER_o144, MODEL_o27)
    EVT_CALL(ParentColliderToModel, COLLIDER_o145, MODEL_o28)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform2), TRIGGER_FLOOR_TOUCH, COLLIDER_o143, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform2), TRIGGER_FLOOR_TOUCH, COLLIDER_o144, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o140, MODEL_o21)
    EVT_CALL(ParentColliderToModel, COLLIDER_o141, MODEL_o22)
    EVT_CALL(ParentColliderToModel, COLLIDER_o142, MODEL_o18)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform3), TRIGGER_FLOOR_TOUCH, COLLIDER_o140, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform3), TRIGGER_FLOOR_TOUCH, COLLIDER_o141, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o131, MODEL_o70)
    EVT_CALL(ParentColliderToModel, COLLIDER_o132, MODEL_o71)
    EVT_CALL(ParentColliderToModel, COLLIDER_o133, MODEL_o72)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform4), TRIGGER_FLOOR_TOUCH, COLLIDER_o131, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform4), TRIGGER_FLOOR_TOUCH, COLLIDER_o132, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o134, MODEL_o67)
    EVT_CALL(ParentColliderToModel, COLLIDER_o135, MODEL_o68)
    EVT_CALL(ParentColliderToModel, COLLIDER_o136, MODEL_o69)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform5), TRIGGER_FLOOR_TOUCH, COLLIDER_o134, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform5), TRIGGER_FLOOR_TOUCH, COLLIDER_o135, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o137, MODEL_o64)
    EVT_CALL(ParentColliderToModel, COLLIDER_o138, MODEL_o65)
    EVT_CALL(ParentColliderToModel, COLLIDER_o139, MODEL_o66)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform6), TRIGGER_FLOOR_TOUCH, COLLIDER_o137, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(EVS_OnTouchSinkingPlatform6), TRIGGER_FLOOR_TOUCH, COLLIDER_o138, 1, 0)
    EVT_EXEC(N(EVS_StartBobbingPlatform1))
    EVT_EXEC(N(EVS_StartBobbingPlatform2))
    EVT_EXEC(N(EVS_StartBobbingPlatform3))
    EVT_EXEC(N(EVS_StartBobbingPlatform4))
    EVT_EXEC(N(EVS_StartBobbingPlatform5))
    EVT_EXEC(N(EVS_StartBobbingPlatform6))
    EVT_EXEC(N(EVS_UpdateMovingPlatform))
    EVT_RETURN
    EVT_END
};
