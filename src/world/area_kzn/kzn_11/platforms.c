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
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(ParentColliderToModel, COLLIDER_o67, MODEL_o67)
    Call(ParentColliderToModel, COLLIDER_o68, MODEL_o68)
    Call(ParentColliderToModel, COLLIDER_o69, MODEL_o69)
    Set(LVar0, 60)
    Set(LVar3, 0)
    Loop(0)
        Call(MakeLerp, LVar0, -60, 120, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g7, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o67)
            Call(UpdateColliderTransform, COLLIDER_o68)
            Call(UpdateColliderTransform, COLLIDER_o69)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, 26, 25)
            IfLt(LVar0, -45)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
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
        Call(MakeLerp, LVar0, 60, 120, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g7, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o67)
            Call(UpdateColliderTransform, COLLIDER_o68)
            Call(UpdateColliderTransform, COLLIDER_o69)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, 26, 25)
            IfGt(LVar0, 45)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
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
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateRightPlatform) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(ParentColliderToModel, COLLIDER_o26, MODEL_o26)
    Call(ParentColliderToModel, COLLIDER_o27, MODEL_o27)
    Call(ParentColliderToModel, COLLIDER_o28, MODEL_o28)
    Set(LVar0, 135)
    Set(LVar3, 0)
    Loop(0)
        Call(MakeLerp, LVar0, -60, 195, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g14, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o26)
            Call(UpdateColliderTransform, COLLIDER_o27)
            Call(UpdateColliderTransform, COLLIDER_o28)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, 30, 29)
            IfLt(LVar0, -45)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
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
        Call(MakeLerp, LVar0, 135, 195, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g14, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o26)
            Call(UpdateColliderTransform, COLLIDER_o27)
            Call(UpdateColliderTransform, COLLIDER_o28)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPushVelocity), LVar4, 30, 29)
            IfGt(LVar0, 120)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
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
    EndLoop
    Return
    End
};
