#include "kzn_02.h"

API_CALLABLE(N(func_80240310_C5AA50));
API_CALLABLE(N(GetFloorCollider));
API_CALLABLE(N(func_802403B0_C5AAF0));
API_CALLABLE(N(func_802403DC_C5AB1C));

EvtScript N(D_80243270_C5D9B0) = {
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

EvtScript N(D_80243430_C5DB70) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(N(GetFloorCollider), LVarA)
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
    EVT_CALL(N(GetFloorCollider), LVarB)
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
    EVT_CALL(N(GetFloorCollider), LVarB)
    EVT_CALL(GetPlayerActionState, LVarC)
    EVT_CALL(N(func_802403B0_C5AAF0), LVarD)
    EVT_IF_EQ(LVarD, 8)
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

EvtScript N(D_80243834_C5DF74) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(1), 0)
        EVT_SET(ArrayVar(1), 1)
        EVT_SET(LVar1, 9)
        EVT_SET(LVar2, 11)
        EVT_SET(LVar3, 10)
        EVT_SET(LVar4, 31)
        EVT_SET(LVar5, 32)
        EVT_SET(LVar6, 33)
        EVT_CALL(N(func_80240310_C5AA50), 11)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(1), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243914_C5E054) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(2), 0)
        EVT_SET(ArrayVar(2), 1)
        EVT_SET(LVar1, 13)
        EVT_SET(LVar2, 15)
        EVT_SET(LVar3, 14)
        EVT_SET(LVar4, 35)
        EVT_SET(LVar5, 36)
        EVT_SET(LVar6, 37)
        EVT_CALL(N(func_80240310_C5AA50), 15)
        EVT_SET(LVar9, 60)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(2), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802439F4_C5E134) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(3), 0)
        EVT_SET(ArrayVar(3), 1)
        EVT_SET(LVar1, 17)
        EVT_SET(LVar2, 19)
        EVT_SET(LVar3, 18)
        EVT_SET(LVar4, 39)
        EVT_SET(LVar5, 40)
        EVT_SET(LVar6, 41)
        EVT_CALL(N(func_80240310_C5AA50), 19)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(3), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243AD4_C5E214) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(4), 0)
        EVT_SET(ArrayVar(4), 1)
        EVT_SET(LVar1, 30)
        EVT_SET(LVar2, 29)
        EVT_SET(LVar3, 31)
        EVT_SET(LVar4, 47)
        EVT_SET(LVar5, 48)
        EVT_SET(LVar6, 49)
        EVT_CALL(N(func_80240310_C5AA50), 29)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(4), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243BB4_C5E2F4) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(5), 0)
        EVT_SET(ArrayVar(5), 1)
        EVT_SET(LVar1, 26)
        EVT_SET(LVar2, 25)
        EVT_SET(LVar3, 27)
        EVT_SET(LVar4, 51)
        EVT_SET(LVar5, 52)
        EVT_SET(LVar6, 53)
        EVT_CALL(N(func_80240310_C5AA50), 25)
        EVT_SET(LVar9, 60)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(5), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243C94_C5E3D4) = {
    EVT_USE_ARRAY(LVar0)
    EVT_IF_EQ(ArrayVar(6), 0)
        EVT_SET(ArrayVar(6), 1)
        EVT_SET(LVar1, 22)
        EVT_SET(LVar2, 21)
        EVT_SET(LVar3, 23)
        EVT_SET(LVar4, 55)
        EVT_SET(LVar5, 56)
        EVT_SET(LVar6, 57)
        EVT_CALL(N(func_80240310_C5AA50), 21)
        EVT_SET(LVar9, 50)
        EVT_EXEC_WAIT(N(D_80243430_C5DB70))
        EVT_SET(ArrayVar(6), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243D74_C5E4B4) = {
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

EvtScript N(D_80243F18_C5E658) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, 9)
    EVT_SET(LVar3, 11)
    EVT_SET(LVar4, 10)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243F70_C5E6B0) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, 13)
    EVT_SET(LVar3, 15)
    EVT_SET(LVar4, 14)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243FC8_C5E708) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, 17)
    EVT_SET(LVar3, 19)
    EVT_SET(LVar4, 18)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244020_C5E760) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, 30)
    EVT_SET(LVar3, 29)
    EVT_SET(LVar4, 31)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244078_C5E7B8) = {
    EVT_WAIT(5)
    EVT_SET(LVar2, 26)
    EVT_SET(LVar3, 25)
    EVT_SET(LVar4, 27)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802440D0_C5E810) = {
    EVT_WAIT(10)
    EVT_SET(LVar2, 22)
    EVT_SET(LVar3, 21)
    EVT_SET(LVar4, 23)
    EVT_EXEC_WAIT(N(D_80243D74_C5E4B4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244128_C5E868) = {
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
            EVT_CALL(N(func_802403DC_C5AB1C), LVar4, 43, 44)
            EVT_IF_GT(LVar0, 95)
                EVT_CALL(N(func_802403B0_C5AAF0), LVar9)
                EVT_IF_EQ(LVar9, 8)
                    EVT_CALL(N(GetFloorCollider), LVar2)
                    EVT_IF_EQ(LVar2, 86)
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
            EVT_CALL(N(func_802403DC_C5AB1C), LVar4, 43, 44)
            EVT_IF_LT(LVar0, -90)
                EVT_CALL(N(func_802403B0_C5AAF0), LVar9)
                EVT_IF_EQ(LVar9, 8)
                    EVT_CALL(N(GetFloorCollider), LVar2)
                    EVT_IF_EQ(LVar2, 85)
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

EvtScript N(EVS_802444A4) = {
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
    EVT_BIND_TRIGGER(N(D_80243834_C5DF74), TRIGGER_FLOOR_TOUCH, COLLIDER_o146, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243834_C5DF74), TRIGGER_FLOOR_TOUCH, COLLIDER_o147, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o143, MODEL_o26)
    EVT_CALL(ParentColliderToModel, COLLIDER_o144, MODEL_o27)
    EVT_CALL(ParentColliderToModel, COLLIDER_o145, MODEL_o28)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243914_C5E054), TRIGGER_FLOOR_TOUCH, COLLIDER_o143, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243914_C5E054), TRIGGER_FLOOR_TOUCH, COLLIDER_o144, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o140, MODEL_o21)
    EVT_CALL(ParentColliderToModel, COLLIDER_o141, MODEL_o22)
    EVT_CALL(ParentColliderToModel, COLLIDER_o142, MODEL_o18)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_802439F4_C5E134), TRIGGER_FLOOR_TOUCH, COLLIDER_o140, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_802439F4_C5E134), TRIGGER_FLOOR_TOUCH, COLLIDER_o141, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o131, MODEL_o70)
    EVT_CALL(ParentColliderToModel, COLLIDER_o132, MODEL_o71)
    EVT_CALL(ParentColliderToModel, COLLIDER_o133, MODEL_o72)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243AD4_C5E214), TRIGGER_FLOOR_TOUCH, COLLIDER_o131, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243AD4_C5E214), TRIGGER_FLOOR_TOUCH, COLLIDER_o132, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o134, MODEL_o67)
    EVT_CALL(ParentColliderToModel, COLLIDER_o135, MODEL_o68)
    EVT_CALL(ParentColliderToModel, COLLIDER_o136, MODEL_o69)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243BB4_C5E2F4), TRIGGER_FLOOR_TOUCH, COLLIDER_o134, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243BB4_C5E2F4), TRIGGER_FLOOR_TOUCH, COLLIDER_o135, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o137, MODEL_o64)
    EVT_CALL(ParentColliderToModel, COLLIDER_o138, MODEL_o65)
    EVT_CALL(ParentColliderToModel, COLLIDER_o139, MODEL_o66)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243C94_C5E3D4), TRIGGER_FLOOR_TOUCH, COLLIDER_o137, 1, 0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(N(D_80243C94_C5E3D4), TRIGGER_FLOOR_TOUCH, COLLIDER_o138, 1, 0)
    EVT_EXEC(N(D_80243F18_C5E658))
    EVT_EXEC(N(D_80243F70_C5E6B0))
    EVT_EXEC(N(D_80243FC8_C5E708))
    EVT_EXEC(N(D_80244020_C5E760))
    EVT_EXEC(N(D_80244078_C5E7B8))
    EVT_EXEC(N(D_802440D0_C5E810))
    EVT_EXEC(N(D_80244128_C5E868))
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_80240310_C5AA50)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(evt_get_variable(script, *args++), &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
    script->varTable[7] = centerX;
    script->varTable[8] = centerZ;
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

ApiStatus N(func_802403B0_C5AAF0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    evt_set_variable(script, *args++, gPartnerActionStatus.actingPartner);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802403DC_C5AB1C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s1 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus= &gCollisionStatus;
    Npc* partner;

    if ((collisionStatus->currentFloor == temp_s1) || ((collisionStatus->lastTouchedFloor == temp_s1)) || (collisionStatus->currentFloor == temp_s0_3) || (collisionStatus->lastTouchedFloor == temp_s0_3)) {
        playerStatus->extraVelocity.x = temp_s2;
    }
    if (gPlayerData.currentPartner != PARTNER_NONE){
        partner = get_npc_unsafe(NPC_PARTNER);
        if ((partner->currentFloor == temp_s1) || (partner->currentFloor == temp_s0_3)) {
            partner->pos.x += temp_s2;
        }
    }
    return ApiStatus_DONE2;
}
