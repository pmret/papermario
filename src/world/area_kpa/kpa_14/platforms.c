
#include "kpa_14.h"

API_CALLABLE(N(GetFloorBelow)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddPlatformPushVelocity)) {
    Bytecode* args = script->ptrReadPos;
    s32 velX = evt_get_variable(script, *args++);
    s32 floor = evt_get_variable(script, *args++);
    s32 temp_a0 = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gCollisionStatus.curFloor == floor || gCollisionStatus.lastTouchedFloor == floor) {
        if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP &&
            playerStatus->actionState != ACTION_STATE_SPIN_JUMP &&
            temp_a0 == 0)
        {
            playerStatus->pushVel.x = velX;
        }
    }
    if (gPlayerData.curPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        if (partner->curFloor == floor) {
            partner->pos.x += velX;
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
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(ParentColliderToModel, COLLIDER_o852, MODEL_o860)
    Set(LVar0, 0)
    Set(LVar3, 0)
    Loop(0)
        Call(MakeLerp, LVar0, 175, 175, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai01, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o852)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o852, MV_TakingLavaFallDamage)
            IfGt(LVar0, 145)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, COLLIDER_o858)
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
        Call(MakeLerp, LVar0, 0, 175, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_dai01, LVar0, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o852)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            Set(LVar3, LVar0)
            Call(N(AddPlatformPushVelocity), LVar4, COLLIDER_o852, MV_TakingLavaFallDamage)
            IfLt(LVar0, 30)
                Call(N(IsPartnerLakilester))
                IfEq(LVar9, 1)
                    Call(N(GetFloorBelow), LVar2)
                    IfEq(LVar2, COLLIDER_o857)
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
