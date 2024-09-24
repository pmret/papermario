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
    SetGroup(EVT_GROUP_0B)
    Thread
        Call(ParentColliderToModel, COLLIDER_o1070, MODEL_o1083)
        Call(TranslateGroup, MODEL_dai05, 125, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o1070)
        IfEq(GF_KPA13_BlueSwitchA, FALSE)
            Label(11)
            IfEq(AF_KPA13_HitSwitchA, FALSE)
                Wait(1)
                Goto(11)
            EndIf
            Wait(20)
            Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.5))
            Set(GF_KPA13_BlueSwitchA, TRUE)
        EndIf
        Set(LVar0, 125)
        Set(LVar3, -100)
        Loop(0)
            Set(LVar1, LVar0)
            Sub(LVar1, -100)
            Call(MakeLerp, LVar0, -100, LVar1, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
                Call(UpdateColliderTransform, COLLIDER_o1070)
                Set(LVar4, LVar0)
                Sub(LVar4, LVar3)
                Set(LVar3, LVar0)
                Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1070)
                IfLt(LVar0, -70)
                    Call(N(IsPartnerLakilester))
                    IfEq(LVar9, 1)
                        Call(N(GetFloorBelow), LVar2)
                        IfEq(LVar2, 90)
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
            Set(LVar1, 125)
            Sub(LVar1, LVar0)
            Call(MakeLerp, LVar0, 125, LVar1, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateGroup, MODEL_dai05, LVar0, 0, 0)
                Call(UpdateColliderTransform, COLLIDER_o1070)
                Set(LVar4, LVar0)
                Sub(LVar4, LVar3)
                Set(LVar3, LVar0)
                Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1070)
                IfGt(LVar0, 95)
                    Call(N(IsPartnerLakilester))
                    IfEq(LVar9, 1)
                        Call(N(GetFloorBelow), LVar2)
                        IfEq(LVar2, 91)
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
    EndThread
    Call(ParentColliderToModel, COLLIDER_o1072, MODEL_o1087)
    Call(TranslateGroup, MODEL_dai06, 75, 0, 0)
    Call(UpdateColliderTransform, COLLIDER_o1072)
    IfEq(GF_KPA13_BlueSwitchB, FALSE)
        Label(12)
        IfEq(AF_KPA13_HitSwitchB, FALSE)
            Wait(1)
            Goto(12)
        EndIf
#if !VERSION_JP
        Wait(20)
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.5))
#endif
        Set(GF_KPA13_BlueSwitchB, TRUE)
    EndIf
    Set(LVar0, 75)
    Set(LVar3, -100)
    Loop(0)
        Set(LVar1, LVar0)
        Sub(LVar1, -100)
        Call(MakeLerp, LVar0, -100, LVar1, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai06, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o1072)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1072)
            IfLt(LVar0, -70)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, 90)
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
        Set(LVar1, 75)
        Sub(LVar1, LVar0)
        Call(MakeLerp, LVar0, 75, LVar1, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai06, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o1072)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o1072)
            IfGt(LVar0, 45)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, 91)
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
