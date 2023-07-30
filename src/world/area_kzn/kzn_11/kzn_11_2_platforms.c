#include "kzn_11.h"

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

API_CALLABLE(N(GetCurrentFloor)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
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

EvtScript N(EVS_UpdateLeftPlatform) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(ParentColliderToModel, COLLIDER_o67, MODEL_o67)
    EVT_CALL(ParentColliderToModel, COLLIDER_o68, MODEL_o68)
    EVT_CALL(ParentColliderToModel, COLLIDER_o69, MODEL_o69)
    EVT_SET(LVar0, 60)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, LVar0, -60, 120, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g7, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o67)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o68)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o69)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, 26, 25)
            EVT_IF_LT(LVar0, -45)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
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
        EVT_CALL(MakeLerp, LVar0, 60, 120, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g7, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o67)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o68)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o69)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, 26, 25)
            EVT_IF_GT(LVar0, 45)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
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
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateRightPlatform) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(ParentColliderToModel, COLLIDER_o26, MODEL_o26)
    EVT_CALL(ParentColliderToModel, COLLIDER_o27, MODEL_o27)
    EVT_CALL(ParentColliderToModel, COLLIDER_o28, MODEL_o28)
    EVT_SET(LVar0, 135)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, LVar0, -60, 195, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g14, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o26)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o27)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o28)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, 30, 29)
            EVT_IF_LT(LVar0, -45)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
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
        EVT_CALL(MakeLerp, LVar0, 135, 195, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g14, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o26)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o27)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o28)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPushVelocity), LVar4, 30, 29)
            EVT_IF_GT(LVar0, 120)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
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
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
