#include "kpa_13.h"

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

EvtScript N(EVS_SetupPlatforms) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_THREAD
        EVT_CALL(ParentColliderToModel, COLLIDER_o1070, MODEL_o1083)
        EVT_CALL(TranslateGroup, MODEL_dai05, 125, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1070)
        EVT_IF_EQ(GF_KPA13_BlueSwitchA, FALSE)
            EVT_LABEL(11)
            EVT_IF_EQ(AF_KPA13_HitSwitchA, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(11)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.5))
            EVT_SET(GF_KPA13_BlueSwitchA, TRUE)
        EVT_END_IF
        EVT_SET(LVar0, 125)
        EVT_SET(LVar3, -100)
        EVT_LOOP(0)
            EVT_SET(LVar1, LVar0)
            EVT_SUB(LVar1, -100)
            EVT_CALL(MakeLerp, LVar0, -100, LVar1, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
                EVT_CALL(UpdateColliderTransform, COLLIDER_o1070)
                EVT_SET(LVar4, LVar0)
                EVT_SUB(LVar4, LVar3)
                EVT_SET(LVar3, LVar0)
                EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1070)
                EVT_IF_LT(LVar0, -70)
                    EVT_CALL(N(IsPartnerLakilester))
                    EVT_IF_EQ(LVar9, 1)
                        EVT_CALL(N(GetFloorBelow), LVar2)
                        EVT_IF_EQ(LVar2, 90)
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
            EVT_SET(LVar1, 125)
            EVT_SUB(LVar1, LVar0)
            EVT_CALL(MakeLerp, LVar0, 125, LVar1, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
                EVT_CALL(UpdateColliderTransform, COLLIDER_o1070)
                EVT_SET(LVar4, LVar0)
                EVT_SUB(LVar4, LVar3)
                EVT_SET(LVar3, LVar0)
                EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1070)
                EVT_IF_GT(LVar0, 95)
                    EVT_CALL(N(IsPartnerLakilester))
                    EVT_IF_EQ(LVar9, 1)
                        EVT_CALL(N(GetFloorBelow), LVar2)
                        EVT_IF_EQ(LVar2, 91)
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
    EVT_END_THREAD
    EVT_CALL(ParentColliderToModel, COLLIDER_o1072, MODEL_o1087)
    EVT_CALL(TranslateGroup, MODEL_dai06, 75, 0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o1072)
    EVT_IF_EQ(GF_KPA13_BlueSwitchB, FALSE)
        EVT_LABEL(12)
        EVT_IF_EQ(AF_KPA13_HitSwitchB, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(12)
        EVT_END_IF
        EVT_WAIT(20)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.5))
        EVT_SET(GF_KPA13_BlueSwitchB, TRUE)
    EVT_END_IF
    EVT_SET(LVar0, 75)
    EVT_SET(LVar3, -100)
    EVT_LOOP(0)
        EVT_SET(LVar1, LVar0)
        EVT_SUB(LVar1, -100)
        EVT_CALL(MakeLerp, LVar0, -100, LVar1, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_dai06, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o1072)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1072)
            EVT_IF_LT(LVar0, -70)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
                    EVT_CALL(N(GetFloorBelow), LVar2)
                    EVT_IF_EQ(LVar2, 90)
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
        EVT_SET(LVar1, 75)
        EVT_SUB(LVar1, LVar0)
        EVT_CALL(MakeLerp, LVar0, 75, LVar1, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_dai06, LVar0, 0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o1072)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_SET(LVar3, LVar0)
            EVT_CALL(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1072)
            EVT_IF_GT(LVar0, 45)
                EVT_CALL(N(IsPartnerLakilester))
                EVT_IF_EQ(LVar9, 1)
                    EVT_CALL(N(GetFloorBelow), LVar2)
                    EVT_IF_EQ(LVar2, 91)
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
