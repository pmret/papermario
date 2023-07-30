#include "flo_00.h"
#include "sprite/player.h"

#define BEANSTALK_BASE_X -83
#define BEANSTALK_BASE_Z  87

API_CALLABLE(N(GetPlayerAngles)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayerRideBeanstalk)) {
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[9], script->varTable[11]);
    f32 angle = atan2(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    gPlayerStatus.pos.x = BEANSTALK_BASE_X + (dist * temp);
    gPlayerStatus.pos.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    gPlayerStatus.pos.z = BEANSTALK_BASE_Z - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PartnerRideBeanstalk)) {
    Npc* npc = get_npc_by_index(NPC_Dummy_Wisterwood);
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[12], script->varTable[14]);
    f32 angle = atan2(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    npc->pos.x = BEANSTALK_BASE_X + (dist * temp);
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    npc->pos.z = BEANSTALK_BASE_Z - (dist * temp);

    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

#include "world/common/todo/SyncStatusBar.inc.c"

API_CALLABLE(N(DisableStatusBar)) {
    increment_status_bar_disabled();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableWorldStatusBar)) {
    decrement_status_bar_disabled();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetExteriorVineGrowth) = {
    EVT_SETF(LVar1, LVar0) // input: expect range from -700 (no growth) to 0 (fully grown)
    EVT_SUBF(LVar1, EVT_FLOAT(-700.0))
    EVT_DIVF(LVar1, EVT_FLOAT(100.0))
    EVT_SETF(LVar2, LVar1)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_IF_GT(LVar2, 100)
        EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleGroup, MODEL_g35, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o117, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o141, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o140, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o138, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o139, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o143, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o144, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o145, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o146, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o188, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o187, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o186, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o185, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o182, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o183, LVar1, 1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o181, LVar1, 1, LVar1)
    EVT_CALL(TranslateGroup, MODEL_g35, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o117, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o141, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o140, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o138, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o139, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o143, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o144, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o145, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o188, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o187, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o186, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o185, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o182, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o183, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o181, 0, LVar0, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, MODEL_g35, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o117, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o141, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o140, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o138, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o139, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o143, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o144, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o145, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o146, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o188, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o187, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o186, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o185, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o182, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o183, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o181, LVar1, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o117, EVT_FLOAT(8.122), EVT_FLOAT(56.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o141, EVT_FLOAT(-6.8779296875), EVT_FLOAT(91.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o140, EVT_FLOAT(13.122), EVT_FLOAT(106.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o138, EVT_FLOAT(-9.8779296875), EVT_FLOAT(136.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o139, EVT_FLOAT(-7.8779296875), EVT_FLOAT(201.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o143, EVT_FLOAT(13.122), EVT_FLOAT(221.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o144, EVT_FLOAT(8.127), EVT_FLOAT(261.229), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o145, EVT_FLOAT(-12.8779296875), EVT_FLOAT(266.153), EVT_FLOAT(1.166))
    EVT_CALL(TranslateModel, MODEL_o146, EVT_FLOAT(8.122), EVT_FLOAT(316.153), EVT_FLOAT(-13.833984375))
    EVT_CALL(TranslateModel, MODEL_o188, EVT_FLOAT(-10.943359375), EVT_FLOAT(391.153), EVT_FLOAT(10.566))
    EVT_CALL(TranslateModel, MODEL_o187, EVT_FLOAT(-7.001953125), EVT_FLOAT(456.153), EVT_FLOAT(0.947))
    EVT_CALL(TranslateModel, MODEL_o186, EVT_FLOAT(12.998), EVT_FLOAT(471.153), EVT_FLOAT(0.947))
    EVT_CALL(TranslateModel, MODEL_o185, EVT_FLOAT(-10.001953125), EVT_FLOAT(501.153), EVT_FLOAT(0.947))
    EVT_CALL(TranslateModel, MODEL_o182, EVT_FLOAT(8.003), EVT_FLOAT(536.229), EVT_FLOAT(0.947))
    EVT_CALL(TranslateModel, MODEL_o183, EVT_FLOAT(12.998), EVT_FLOAT(586.153), EVT_FLOAT(0.947))
    EVT_CALL(TranslateModel, MODEL_o181, EVT_FLOAT(-13.001953125), EVT_FLOAT(631.153), EVT_FLOAT(0.947))
    EVT_SETF(LVar1, LVar0)
    EVT_SUBF(LVar1, EVT_FLOAT(-700.0))
    EVT_DIVF(LVar1, EVT_FLOAT(300.0))
    EVT_SETF(LVar2, LVar1)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_IF_GT(LVar2, 100)
        EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleModel, MODEL_o117, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o141, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o140, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o138, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o139, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o143, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o144, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o145, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o146, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o188, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o187, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o186, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o185, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o182, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o183, LVar1, LVar1, LVar1)
    EVT_CALL(ScaleModel, MODEL_o181, LVar1, LVar1, LVar1)
    EVT_CALL(TranslateModel, MODEL_o117, EVT_FLOAT(-8.12109375), EVT_FLOAT(-56.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o141, EVT_FLOAT(6.879), EVT_FLOAT(-91.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o140, EVT_FLOAT(-13.12109375), EVT_FLOAT(-106.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o138, EVT_FLOAT(9.879), EVT_FLOAT(-136.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o139, EVT_FLOAT(7.879), EVT_FLOAT(-201.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o143, EVT_FLOAT(-13.12109375), EVT_FLOAT(-221.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o144, EVT_FLOAT(-8.1259765625), EVT_FLOAT(-261.228515625), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o145, EVT_FLOAT(12.879), EVT_FLOAT(-266.15234375), EVT_FLOAT(-1.1650390625))
    EVT_CALL(TranslateModel, MODEL_o146, EVT_FLOAT(-8.12109375), EVT_FLOAT(-316.15234375), EVT_FLOAT(13.835))
    EVT_CALL(TranslateModel, MODEL_o188, EVT_FLOAT(10.944), EVT_FLOAT(-391.15234375), EVT_FLOAT(-10.5654296875))
    EVT_CALL(TranslateModel, MODEL_o187, EVT_FLOAT(7.003), EVT_FLOAT(-456.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, MODEL_o186, EVT_FLOAT(-12.9970703125), EVT_FLOAT(-471.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, MODEL_o185, EVT_FLOAT(10.003), EVT_FLOAT(-501.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, MODEL_o182, EVT_FLOAT(-8.001953125), EVT_FLOAT(-536.228515625), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, MODEL_o183, EVT_FLOAT(-12.9970703125), EVT_FLOAT(-586.15234375), EVT_FLOAT(-0.9462890625))
    EVT_CALL(TranslateModel, MODEL_o181, EVT_FLOAT(13.003), EVT_FLOAT(-631.15234375), EVT_FLOAT(-0.9462890625))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetInteriorVineGrowth) = {
    EVT_SETF(LVar1, LVar0) // input: expect range from -700 (no growth) to 0 (fully grown)
    EVT_SUBF(LVar1, EVT_FLOAT(-700.0))
    EVT_DIVF(LVar1, EVT_FLOAT(100.0))
    EVT_SETF(LVar2, LVar1)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_IF_GT(LVar2, 100)
        EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleGroup, MODEL_g37, LVar1, 1, LVar1)
    EVT_CALL(TranslateGroup, MODEL_g37, 0, LVar0, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, MODEL_g37, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetSproutGrowth) = {
    EVT_CALL(TranslateModel, MODEL_o147, EVT_FLOAT(9.5), EVT_FLOAT(12.0), EVT_FLOAT(15.0))
    EVT_CALL(TranslateModel, MODEL_o149, EVT_FLOAT(-9.5), EVT_FLOAT(12.0), EVT_FLOAT(15.0))
    EVT_CALL(TranslateModel, MODEL_o148, EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(17.0))
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(90.0))
    EVT_CALL(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o149, LVar1, 0, 0, 1)
    EVT_CALL(TranslateModel, MODEL_o147, EVT_FLOAT(-9.5), EVT_FLOAT(-12.0), EVT_FLOAT(-15.0))
    EVT_CALL(TranslateModel, MODEL_o149, EVT_FLOAT(9.5), EVT_FLOAT(-12.0), EVT_FLOAT(-15.0))
    EVT_CALL(TranslateModel, MODEL_o148, EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(-17.0))
    EVT_CALL(ScaleModel, MODEL_o147, LVar0, LVar0, LVar0)
    EVT_CALL(ScaleModel, MODEL_o149, LVar0, LVar0, LVar0)
    EVT_CALL(ScaleModel, MODEL_o148, LVar0, LVar0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetBigLeafGrowth) = {
    EVT_CALL(ScaleModel, MODEL_o142, LVar0, LVar0, LVar0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(90.0))
    EVT_ADDF(LVar1, EVT_FLOAT(-90.0))
    EVT_CALL(RotateModel, MODEL_o142, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetBigLeafPosition) = {
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-3.0))
    EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(-0.26), LVar0, EVT_FLOAT(1.477))
    EVT_CALL(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o240)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Exit_Beanstalk) = {
    EVT_IF_EQ(AF_FLO_RidingBeanstalk, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(15)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_SET(AF_FLO_RidingBeanstalk, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
        EVT_VEC3I_SET(LVar9, EVT_FLOAT(-59.0), EVT_FLOAT(22.0), EVT_FLOAT(125.0)) // target player pos
        EVT_VEC3I_SET(LVarC, EVT_FLOAT(-55.0), EVT_FLOAT(24.0), EVT_FLOAT(145.0)) // target partner pos
        EVT_CALL(PlayerMoveTo, LVar9, LVarB, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, LVarC, LVarD, LVarE, 5)
        EVT_CALL(PlaySound, SOUND_19C)
        EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(N(GetPlayerAngles), LVar3, LVar4)
        EVT_SWITCH(LVar4)
            EVT_CASE_LT(90)
                EVT_SET(AF_FLO_BeanstalkFacingRight, FALSE)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_GE(270)
                EVT_SET(AF_FLO_BeanstalkFacingRight, TRUE)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
        EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(-0.26), EVT_FLOAT(2.0), EVT_FLOAT(1.477))
        EVT_CALL(UpdateColliderTransform, COLLIDER_o240)
        EVT_SET(MV_BeanstalkSceneSync, FALSE)
        EVT_THREAD
            EVT_SET(LVarF, 0)
            EVT_LOOP(0)
                EVT_ADD(LVarF, 1)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, 0, 700, 800, 0, 0)
                EVT_EXEC(N(EVS_SetBigLeafPosition))
                EVT_SETF(LVar2, LVar0)
                EVT_MULF(LVar2, EVT_FLOAT(-3.0))
                EVT_SETF(LVar3, LVar0)
                EVT_CALL(N(PlayerRideBeanstalk))
                EVT_CALL(N(PartnerRideBeanstalk))
                EVT_IF_EQ(LVarF, 350)
                    EVT_SET(MV_BeanstalkSceneSync, TRUE)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_LABEL(10)
            EVT_IF_EQ(MV_BeanstalkSceneSync, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("flo_19"), flo_19_ENTRY_3)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Enter_Beanstalk) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(LVar9, EVT_FLOAT(-59.0))
    EVT_SET(LVarA, EVT_FLOAT(22.0))
    EVT_SET(LVarB, EVT_FLOAT(125.0))
    EVT_SET(LVarC, EVT_FLOAT(-55.0))
    EVT_SET(LVarD, EVT_FLOAT(23.0))
    EVT_SET(LVarE, EVT_FLOAT(145.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_SWITCH(AF_FLO_BeanstalkFacingRight)
            EVT_CASE_EQ(0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_EQ(1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(-0.26), EVT_FLOAT(2.0), EVT_FLOAT(1.477))
    EVT_CALL(UpdateColliderTransform, COLLIDER_o240)
    EVT_SET(LVarF, 0)
    EVT_LOOP(120)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, 70, 0, 120, 0, 0)
        EVT_EXEC(N(EVS_SetBigLeafPosition))
        EVT_SETF(LVar2, LVar0)
        EVT_MULF(LVar2, EVT_FLOAT(-3.0))
        EVT_SETF(LVar3, LVar0)
        EVT_CALL(N(PlayerRideBeanstalk))
        EVT_CALL(N(PartnerRideBeanstalk))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(PlayerJump, 10, 0, 110, 20)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(AF_FLO_RidingBeanstalk, FALSE)
    EVT_CALL(StopSound, SOUND_19D)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeanstalkGrowing) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o261, SOUND_19B, SOUND_SPACE_MODE_0)
    EVT_SET(LVarF, 0)
    EVT_LOOP(100)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, 0, EVT_FLOAT(1.0), 100, 0, 0)
        EVT_EXEC(N(EVS_SetSproutGrowth))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MV_BeanstalkSceneSync, FALSE)
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LOOP(1200)
            EVT_ADD(LVarF, 1)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, -700, 0, 1200, 0, 0)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(1.0))
            EVT_SETF(LVar0, LVar2)
            EVT_EXEC(N(EVS_SetExteriorVineGrowth))
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(1.0))
            EVT_SETF(LVar0, LVar2)
            EVT_EXEC(N(EVS_SetInteriorVineGrowth))
            EVT_SWITCH(LVarF)
                EVT_CASE_EQ(200)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
                EVT_CASE_EQ(250)
                    EVT_SET(LVar0, -60)
                    EVT_SET(LVar1, 0)
                    EVT_SET(LVar2, 65)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.5), EVT_FLOAT(-7.0))
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, 800)
                    EVT_CALL(SetCamPosA, CAM_DEFAULT, -200, 0)
                    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -300)
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_GT(LVarF, 550)
                EVT_SET(MV_BeanstalkSceneSync, TRUE)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(10)
        EVT_IF_EQ(MV_BeanstalkSceneSync, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(FadeInMusic, 0, SONG_CLOUDY_CLIMB, 0, 3000, 0, 127)
    EVT_CALL(FadeOutMusic, 1, 3000)
    EVT_CALL(GotoMap, EVT_PTR("flo_19"), flo_19_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeanstalkGrewRemark) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 200, 0)
    EVT_CALL(SetPlayerPos, -60, 0, 30)
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -20, 0, 10)
    EVT_SET(LVar0, -60)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 65)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.5), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 800)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -200, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -300)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(LVarF, 0)
    EVT_LOOP(5)
        EVT_ADD(LVarF, 20)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.0), EVT_FLOAT(1.0), 100, 0, 0)
        EVT_EXEC(N(EVS_SetBigLeafGrowth))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_000A, 0, 50, -200)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(BeanstalkIngredients)[] = {
    ITEM_FERTILE_SOIL,
    ITEM_MAGICAL_BEAN,
    ITEM_MIRACLE_WATER,
    ITEM_NONE
};

EvtScript N(EVS_BeanPatch_ItemPrompt) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FacePlayerTowardPoint, -85, 85, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(GF_FLO00_PlacedFertileSoil, FALSE)
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        EVT_LABEL(10)
            EVT_CALL(ShowKeyChoicePopup)
            EVT_SET(LVar2, LVar0)
            EVT_SWITCH(LVar2)
                EVT_CASE_LE(ITEM_NONE)
                    EVT_CALL(CloseChoicePopup)
                    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                    EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
                    EVT_RETURN
                EVT_CASE_EQ(ITEM_FERTILE_SOIL)
                    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                    EVT_WAIT(5)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                    EVT_CALL(MakeItemEntity, ITEM_FERTILE_SOIL, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                    EVT_SET(MV_BeanstalkItemEntity, LVar0)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
                    EVT_WAIT(20)
                EVT_CASE_DEFAULT
                    EVT_SWITCH(AF_FLO_PlatingInstructionsToggle)
                        EVT_CASE_EQ(0)
                            EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0008, 0, 10, -200)
                            EVT_SET(AF_FLO_PlatingInstructionsToggle, TRUE)
                        EVT_CASE_DEFAULT
                            EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0009, 0, 10, -200)
                    EVT_END_SWITCH
            EVT_END_SWITCH
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_IF_NE(LVar2, 89)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_SET(GF_FLO00_PlacedFertileSoil, TRUE)
    EVT_END_IF
    EVT_IF_EQ(GF_FLO00_PlacedMagicalBean, FALSE)
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        EVT_LABEL(20)
            EVT_CALL(ShowKeyChoicePopup)
            EVT_SET(LVar2, LVar0)
            EVT_SWITCH(LVar2)
                EVT_CASE_LE(ITEM_NONE)
                    EVT_CALL(CloseChoicePopup)
                    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                    EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
                    EVT_RETURN
                EVT_CASE_EQ(ITEM_MAGICAL_BEAN)
                    EVT_CALL(RemoveItemEntity, MV_BeanstalkItemEntity)
                    EVT_WAIT(5)
                    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                    EVT_WAIT(5)
                    EVT_CALL(RemoveKeyItemAt, LVar1)
                    EVT_CALL(MakeItemEntity, ITEM_MAGICAL_BEAN, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                    EVT_SET(MV_BeanstalkItemEntity, LVar0)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
                    EVT_WAIT(20)
                EVT_CASE_DEFAULT
                    EVT_SWITCH(AF_FLO_PlatingInstructionsToggle)
                        EVT_CASE_EQ(0)
                            EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0008, 0, 10, -200)
                            EVT_SET(AF_FLO_PlatingInstructionsToggle, TRUE)
                        EVT_CASE_DEFAULT
                            EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_0009, 0, 10, -200)
                    EVT_END_SWITCH
            EVT_END_SWITCH
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_IF_NE(LVar2, 88)
                EVT_GOTO(20)
            EVT_END_IF
        EVT_SET(GF_FLO00_PlacedMagicalBean, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_LABEL(30)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LVar2, LVar0)
        EVT_SWITCH(LVar2)
            EVT_CASE_LE(ITEM_NONE)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                EVT_CALL(AwaitPlayerLeave, -85, 85, 28)
                EVT_RETURN
            EVT_CASE_EQ(ITEM_MIRACLE_WATER)
                EVT_CALL(RemoveItemEntity, MV_BeanstalkItemEntity)
                EVT_WAIT(5)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                EVT_WAIT(5)
                EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_CALL(N(SyncStatusBar))
                EVT_CALL(MakeItemEntity, ITEM_MIRACLE_WATER, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(MV_BeanstalkItemEntity, LVar0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
                EVT_WAIT(30)
                EVT_CALL(RemoveItemEntity, MV_BeanstalkItemEntity)
                EVT_WAIT(30)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(PlayerMoveTo, -60, 30, 20)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(InterpPlayerYaw, 200, 0)
                EVT_CALL(func_802CF56C, 2)
                EVT_WAIT(60)
                EVT_CALL(FadeInMusic, 1, SONG_MAGIC_BEANSTALK, 0, 3000, 0, 127)
                EVT_CALL(FadeOutMusic, 0, 3000)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -85, 0, 75)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, -85, 0, 75)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_EXEC_WAIT(N(EVS_Scene_BeanstalkGrowing))
        EVT_END_SWITCH
        EVT_IF_NE(LVar2, 90)
            EVT_GOTO(30)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BeanPatch_TryInteract) = {
    EVT_LABEL(0)
    EVT_CALL(IsPlayerWithin, -85, 85, 20, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(IsPlayerOnValidFloor, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(DisableStatusBar))
    EVT_EXEC_WAIT(N(EVS_BeanPatch_ItemPrompt))
    EVT_CALL(N(EnableWorldStatusBar))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBeanPatch) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH6_WISTERWOOD_GAVE_HINT)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_EQ(GF_FLO00_PlacedFertileSoil, TRUE)
            EVT_IF_EQ(GF_FLO00_PlacedMagicalBean, FALSE)
                EVT_CALL(MakeItemEntity, ITEM_FERTILE_SOIL, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_ELSE
                EVT_CALL(MakeItemEntity, ITEM_MAGICAL_BEAN, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_END_IF
            EVT_SET(MV_BeanstalkItemEntity, LVar0)
        EVT_END_IF
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_BeanPatch_TryInteract)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(BeanstalkIngredients)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBeanstalk) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Exit_Beanstalk)), TRIGGER_FLOOR_TOUCH, COLLIDER_o240, 1, 0)
    EVT_CALL(EnableGroup, MODEL_ha, TRUE)
    EVT_CALL(EnableGroup, MODEL_tuta, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH6_WISTERWOOD_GAVE_HINT)
            EVT_SET(LVar0, -700)
            EVT_EXEC(N(EVS_SetExteriorVineGrowth))
            EVT_EXEC(N(EVS_SetInteriorVineGrowth))
            EVT_SET(LVar0, 0)
            EVT_EXEC(N(EVS_SetSproutGrowth))
            EVT_SET(LVar0, 0)
            EVT_EXEC(N(EVS_SetBigLeafGrowth))
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_GE(STORY_CH6_GREW_MAGIC_BEANSTALK)
            EVT_SET(LVar0, 1)
            EVT_EXEC(N(EVS_SetSproutGrowth))
            EVT_SET(LVar0, 1)
            EVT_EXEC(N(EVS_SetBigLeafGrowth))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, -700)
            EVT_EXEC(N(EVS_SetExteriorVineGrowth))
            EVT_EXEC(N(EVS_SetInteriorVineGrowth))
            EVT_SET(LVar0, 0)
            EVT_EXEC(N(EVS_SetSproutGrowth))
            EVT_SET(LVar0, 0)
            EVT_EXEC(N(EVS_SetBigLeafGrowth))
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
