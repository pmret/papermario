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
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LABEL(0)
        EVT_CALL(TranslateGroup, LVar1, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, LVar3)
        EVT_SUBF(LVar0, EVT_FLOAT(0.5))
        EVT_IF_LT(LVar0, -40)
            EVT_SET(LVar0, -40)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorBelow), LVarB)
        EVT_CALL(GetPlayerActionState, LVarC)
        EVT_IF_EQ(LVar3, LVarB)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_LABEL(1)
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(TranslateGroup, LVar1, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, LVar3)
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorBelow), LVarB)
        EVT_CALL(GetPlayerActionState, LVarC)
        EVT_IF_EQ(LVar3, LVarB)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_LT(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Touch_SinkingPlatform1) = {
    EVT_SET(LVar1, MODEL_dai01)
    EVT_SET(LVar3, COLLIDER_o405)
    EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Update))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Touch_SinkingPlatform2) = {
    EVT_SET(LVar1, MODEL_dai02)
    EVT_SET(LVar3, COLLIDER_o407)
    EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Update))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Touch_SinkingPlatform3) = {
    EVT_SET(LVar1, MODEL_dai03)
    EVT_SET(LVar3, COLLIDER_o409)
    EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Update))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Touch_SinkingPlatform4) = {
    EVT_SET(LVar1, MODEL_dai04)
    EVT_SET(LVar3, COLLIDER_o411)
    EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Update))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SinkingPlatform_Idle) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -3, 20, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, -3, 0, 20, EASING_LINEAR)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSinkingPlatforms) = {
    EVT_THREAD
        EVT_SET(LVar2, MODEL_dai01)
        EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Idle))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_SET(LVar2, MODEL_dai02)
        EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Idle))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_SET(LVar2, MODEL_dai03)
        EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Idle))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_SET(LVar2, MODEL_dai04)
    EVT_EXEC_WAIT(N(EVS_SinkingPlatform_Idle))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMovingPlatform) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(ParentColliderToModel, COLLIDER_o414, MODEL_o522)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_SET(LVar1, 125)
        EVT_SUB(LVar1, LVar0)
        EVT_CALL(MakeLerp, LVar0, 125, LVar1, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o414)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o414)
            EVT_IF_GT(LVar0, 95)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
                    EVT_CALL(N(GetFloorBelow), LVar2)
                    EVT_IF_EQ(LVar2, 81)
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
        EVT_CALL(MakeLerp, LVar0, 0, LVar0, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o414)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o414)
            EVT_IF_LT(LVar0, 30)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
                    EVT_CALL(N(GetFloorBelow), LVar2)
                    EVT_IF_EQ(LVar2, 80)
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

EvtScript N(EVS_SetupPlatforms) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o405, MODEL_o447)
    EVT_CALL(ParentColliderToModel, COLLIDER_o407, MODEL_o449)
    EVT_CALL(ParentColliderToModel, COLLIDER_o409, MODEL_o451)
    EVT_CALL(ParentColliderToModel, COLLIDER_o411, MODEL_o453)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_SinkingPlatform1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o405, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_SinkingPlatform2)), TRIGGER_FLOOR_TOUCH, COLLIDER_o407, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_SinkingPlatform3)), TRIGGER_FLOOR_TOUCH, COLLIDER_o409, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_SinkingPlatform4)), TRIGGER_FLOOR_TOUCH, COLLIDER_o411, 1, 0)
    EVT_EXEC(N(EVS_SetupSinkingPlatforms))
    EVT_EXEC(N(EVS_SetupMovingPlatform))
    EVT_RETURN
    EVT_END
};
