#include "kzn_22.h"

#include "world/area_kzn/common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_20_1) = EVT_EXIT_WALK_FIXED(60, kzn_22_ENTRY_0, "kzn_20", kzn_20_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_20_1), TRIGGER_FLOOR_TOUCH, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTexPan_LavaRiver) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan1_1, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_AUX, LVar1, LVar2)
        EVT_ADD(LVar0, -1100)
        EVT_ADD(LVar1, 300)
        EVT_ADD(LVar2, -500)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTexPan_LavaFall) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan2_2, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, -500)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InterruptPartnersInLava) = {
    EVT_LOOP(0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_yu)
            EVT_CALL(GetPlayerPos, LVar0, LVar3, LVar2)
            EVT_IF_LT(LVar3, LVar1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_LAKILESTER)
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(GetFloorCollider1)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateLavaLevel) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(SetTexPanner, MODEL_yu1, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_yu, TEX_PANNER_2)
    EVT_CALL(EnableModel, MODEL_yu, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o591, MODEL_yu)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_SET(LVarA, 0)
    EVT_LABEL(10)
        // update lava texture panning
        EVT_CALL(UpdateColliderTransform, COLLIDER_o591)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar2, LVar3)
        EVT_SUB(LVar0, 700)
        EVT_ADD(LVar1, 700)
        EVT_ADD(LVar2, 200)
        EVT_SUB(LVar3, 300)
        // update lava level
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(0)
                // state 0: wait for player to stand on one of the steps
                EVT_CALL(N(GetFloorCollider1), LVar0)
                EVT_IF_EQ(LVar0, COLLIDER_o357)
                    EVT_EXEC(N(EVS_InterruptPartnersInLava))
                    EVT_CALL(EnableModel, MODEL_yu, TRUE)
                    EVT_CALL(EnableModel, MODEL_yu1, FALSE)
                    EVT_SET(LVarA, 10) // set state to 10
                EVT_END_IF
            EVT_CASE_EQ(10)
                // state 10: raise the lava level
                EVT_IF_LT(LVar4, 140)
                    EVT_SET(LVar5, EVT_FLOAT(1.5))
                EVT_ELSE
                    EVT_IF_EQ(AF_KZN22_FlewAway, FALSE)
                        EVT_SET(LVar5, EVT_FLOAT(0.0))
                    EVT_ELSE
                        EVT_IF_LT(LVar4, 285)
                            EVT_SET(LVar5, EVT_FLOAT(2.8))
                        EVT_ELSE
                            EVT_SET(LVar5, EVT_FLOAT(0.0))
                            EVT_SET(LVarA, -1)
                        EVT_END_IF
                    EVT_END_IF
                EVT_END_IF
        EVT_END_SWITCH
        EVT_ADDF(LVar4, LVar5)
        EVT_CALL(TranslateModel, MODEL_yu, 0, LVar4, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o582, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = COLLIDER_o357, .pos = { 200.0, 150.0, 180.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_22)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o591, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_UpdateTexPan_LavaRiver))
    EVT_EXEC(N(EVS_UpdateTexPan_LavaFall))
    EVT_EXEC(N(EVS_UpdateLavaLevel))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_RETURN
    EVT_END
};
