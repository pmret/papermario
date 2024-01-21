#include "kzn_22.h"

#include "world/area_kzn/common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_20_1) = EVT_EXIT_WALK_FIXED(60, kzn_22_ENTRY_0, "kzn_20", kzn_20_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_20_1), TRIGGER_FLOOR_TOUCH, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_UpdateTexPan_LavaRiver) = {
    SetGroup(EVT_GROUP_00)
    Call(EnableTexPanning, MODEL_yougan1_1, TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_AUX, LVar1, LVar2)
        Add(LVar0, -1100)
        Add(LVar1, 300)
        Add(LVar2, -500)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_UpdateTexPan_LavaFall) = {
    SetGroup(EVT_GROUP_00)
    Call(EnableTexPanning, MODEL_yougan2_2, TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar0, 300)
        Add(LVar1, -500)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_InterruptPartnersInLava) = {
    Loop(0)
        Loop(0)
            Wait(1)
            Call(GetModelCenter, MODEL_yu)
            Call(GetPlayerPos, LVar0, LVar3, LVar2)
            IfLt(LVar3, LVar1)
                BreakLoop
            EndIf
        EndLoop
        Call(GetCurrentPartnerID, LVar1)
        IfNe(LVar1, PARTNER_LAKILESTER)
            Call(InterruptUsePartner)
            Call(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
            Wait(30)
        EndIf
    EndLoop
    Return
    End
};

API_CALLABLE(N(GetFloorCollider1)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateLavaLevel) = {
    SetGroup(EVT_GROUP_EF)
    Call(SetTexPanner, MODEL_yu1, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_yu, TEX_PANNER_2)
    Call(EnableModel, MODEL_yu, FALSE)
    Call(ParentColliderToModel, COLLIDER_o591, MODEL_yu)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    SetF(LVar4, Float(0.0))
    SetF(LVar5, Float(0.0))
    Set(LVarA, 0)
    Label(10)
        // update lava texture panning
        Call(UpdateColliderTransform, COLLIDER_o591)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar2, LVar3)
        Sub(LVar0, 700)
        Add(LVar1, 700)
        Add(LVar2, 200)
        Sub(LVar3, 300)
        // update lava level
        Switch(LVarA)
            CaseEq(0)
                // state 0: wait for player to stand on one of the steps
                Call(N(GetFloorCollider1), LVar0)
                IfEq(LVar0, COLLIDER_o357)
                    Exec(N(EVS_InterruptPartnersInLava))
                    Call(EnableModel, MODEL_yu, TRUE)
                    Call(EnableModel, MODEL_yu1, FALSE)
                    Set(LVarA, 10) // set state to 10
                EndIf
            CaseEq(10)
                // state 10: raise the lava level
                IfLt(LVar4, 140)
                    Set(LVar5, Float(1.5))
                Else
                    IfEq(AF_KZN22_FlewAway, FALSE)
                        Set(LVar5, Float(0.0))
                    Else
                        IfLt(LVar4, 285)
                            Set(LVar5, Float(2.8))
                        Else
                            Set(LVar5, Float(0.0))
                            Set(LVarA, -1)
                        EndIf
                    EndIf
                EndIf
        EndSwitch
        AddF(LVar4, LVar5)
        Call(TranslateModel, MODEL_yu, 0, LVar4, 0)
        Wait(1)
        Goto(10)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o582, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = COLLIDER_o357, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_22)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o591, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Exec(N(EVS_UpdateTexPan_LavaRiver))
    Exec(N(EVS_UpdateTexPan_LavaFall))
    Exec(N(EVS_UpdateLavaLevel))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Return
    End
};
