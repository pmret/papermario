#include "kpa_134.h"
#include "sprite/player.h"

extern EvtScript N(EVS_LowerWaterLevel0);
extern EvtScript N(EVS_RaiseWaterLevel1);
extern EvtScript N(EVS_LowerWaterLevel1);
extern EvtScript N(EVS_RaiseWaterLevel2);
extern EvtScript N(EVS_SetupLowerChain);
extern EvtScript N(EVS_SetupUpperChain);

EvtScript N(EVS_SetupChains) = {
    EVT_CALL(SetRenderMode, MODEL_s_sui, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_o385, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(EnableModel, MODEL_o388, FALSE)
    EVT_CALL(EnableModel, MODEL_o389, FALSE)
    EVT_CALL(TranslateModel, MODEL_o387, 0, 30, 0)
    EVT_CALL(TranslateModel, MODEL_o505, 0, 0, 0)
    EVT_SWITCH(GB_KPA_WaterLevel)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupVisibility, MODEL_suimen, MODEL_GROUP_HIDDEN)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(1)
            EVT_CALL(EnableModel, MODEL_s_sui, FALSE)
            EVT_CALL(TranslateGroup, MODEL_sui1, 0, 120, 0)
            EVT_CALL(TranslateModel, MODEL_o385, 0, 120, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliaw, SURFACE_TYPE_DOCK_WALL)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_DOCK_WALL)
        EVT_CASE_EQ(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(EnableModel, MODEL_o385, FALSE)
            EVT_CALL(TranslateGroup, MODEL_sui1, 0, 220, 0)
            EVT_CALL(TranslateModel, MODEL_s_sui, 0, 220, 0)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupLowerChain))
    EVT_EXEC(N(EVS_SetupUpperChain))
    EVT_RETURN
    EVT_END
};

s32 N(ChainAnimOffsets)[] = {
    -2, -3, -2, -1,  0,
     1,  1,  1,  1,  1,
     0,  0,  0, -1, -1,
    -1, -2, -2, -2, -1,
};

API_CALLABLE(N(CreateLowerChainShadow)) {
    create_shadow_type(SHADOW_VARYING_CIRCLE, 50.0f, 115.0f, -34.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DetectLowerChainGrab)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_FALLING) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.x - 50.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.y - 150.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.z - -34.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    playerStatus->pos.x = 50.0f;
    playerStatus->pos.y = 150.0f;
    playerStatus->pos.z = -34.0f;
    playerStatus->curSpeed = 0.0f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupLowerChain) = {
    EVT_CALL(N(CreateLowerChainShadow))
    EVT_LABEL(10)
        EVT_CALL(N(DetectLowerChainGrab))
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(PlaySoundAtPlayer, SOUND_KPA_PULL_CHAIN, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
        EVT_THREAD
            EVT_SET(LVar0, 150)
            EVT_SET(LVar1, 30)
            EVT_USE_BUF(EVT_PTR(N(ChainAnimOffsets)))
            EVT_LOOP(ARRAY_COUNT(N(ChainAnimOffsets)))
                EVT_BUF_READ1(LVar2)
                EVT_ADD(LVar0, LVar2)
                EVT_ADD(LVar1, LVar2)
                EVT_CALL(SetPlayerPos, 50, LVar0, -34)
                EVT_CALL(TranslateModel, MODEL_o387, 0, LVar1, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_IF_EQ(GB_KPA_WaterLevel, 0)
            EVT_EXEC_WAIT(N(EVS_RaiseWaterLevel1))
            EVT_SET(GB_KPA_WaterLevel, 1)
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_LowerWaterLevel0))
            EVT_SET(GB_KPA_WaterLevel, 0)
        EVT_END_IF
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 115)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerWaterLevel0) = {
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 120, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        EVT_CALL(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, LVar0)
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        EVT_LABEL(15)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
    EVT_CALL(EnableModel, MODEL_o385, TRUE)
    EVT_CALL(PlaySound, SOUND_LOOP_KPA_DRAIN_WATER)
    EVT_CALL(MakeLerp, 120, 20, 120, EASING_LINEAR)
    EVT_LABEL(30)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o385, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_LRAW_KPA_DRAIN_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_KPA_DRAIN_WATER)
    EVT_CALL(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_HIDDEN)
    EVT_CALL(EnableModel, MODEL_s_sui, FALSE)
    EVT_CALL(EnableModel, MODEL_o385, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, 17)
        EVT_LOOP(13)
            EVT_ADD(LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_o387, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseWaterLevel1) = {
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 220, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        EVT_CALL(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, LVar0)
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        EVT_LABEL(15)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_LOOP_KPA_FILL_WATER, SOUND_SPACE_DEFAULT, 118, 115, -11)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o388, TEX_PANNER_2)
        EVT_CALL(SetTexPanner, MODEL_o389, TEX_PANNER_3)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(1000)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar2)
            EVT_ADD(LVar0, 1000)
            EVT_ADD(LVar1, 4000)
            EVT_ADD(LVar2, -1500)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(EnableModel, MODEL_o388, TRUE)
        EVT_CALL(MakeLerp, 400, 0, 20, EASING_LINEAR)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o388, -100, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
        EVT_CALL(EnableModel, MODEL_o385, TRUE)
        EVT_CALL(EnableModel, MODEL_o389, TRUE)
        EVT_CALL(MakeLerp, 20, 120, 180, EASING_LINEAR)
        EVT_LABEL(30)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o385, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o389, -100, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o388, -100, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(30)
        EVT_END_IF
        EVT_CALL(MakeLerp, 100, 1, 20, EASING_LINEAR)
        EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 100)
        EVT_CALL(TranslateModel, MODEL_o389, -100, 120, 0)
        EVT_CALL(TranslateModel, MODEL_o388, -100, 120, 0)
        EVT_CALL(ScaleModel, MODEL_o389, LVar2, EVT_FLOAT(1.0), LVar2)
        EVT_CALL(ScaleModel, MODEL_o388, LVar2, EVT_FLOAT(1.0), LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
        EVT_CALL(PlaySound, SOUND_LRAW_KPA_FILL_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_KPA_FILL_WATER)
        EVT_CALL(EnableModel, MODEL_o389, FALSE)
        EVT_CALL(EnableModel, MODEL_o388, FALSE)
    EVT_END_THREAD
    EVT_WAIT(230)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_IGNORE_SHELL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliaw, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, 17)
        EVT_LOOP(13)
            EVT_ADD(LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_o387, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(CreateUpperChainShadow)) {
    create_shadow_type(SHADOW_VARYING_CIRCLE, 680.0f, 240.0f, -35.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DetectUpperChainGrab)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_FALLING) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.x - 680.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.y - 275.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->pos.z - -35.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    playerStatus->pos.x = 680.0f;
    playerStatus->pos.y = 275.0f;
    playerStatus->pos.z = -35.0f;
    playerStatus->curSpeed = 0.0f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupUpperChain) = {
    EVT_CALL(N(CreateUpperChainShadow))
    EVT_LABEL(10)
        EVT_CALL(N(DetectUpperChainGrab))
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(PlaySoundAtPlayer, SOUND_KPA_PULL_CHAIN, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
        EVT_THREAD
            EVT_SET(LVar0, 275)
            EVT_SET(LVar1, 0)
            EVT_USE_BUF(EVT_PTR(N(ChainAnimOffsets)))
            EVT_LOOP(20)
                EVT_BUF_READ1(LVar2)
                EVT_ADD(LVar0, LVar2)
                EVT_ADD(LVar1, LVar2)
                EVT_CALL(SetPlayerPos, 680, LVar0, -35)
                EVT_CALL(TranslateModel, MODEL_o505, 0, LVar1, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_IF_EQ(GB_KPA_WaterLevel, 1)
            EVT_EXEC_WAIT(N(EVS_RaiseWaterLevel2))
            EVT_SET(GB_KPA_WaterLevel, 2)
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_LowerWaterLevel1))
            EVT_SET(GB_KPA_WaterLevel, 1)
        EVT_END_IF
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 240)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerWaterLevel1) = {
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 120, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_s_sui, FALSE)
    EVT_CALL(EnableModel, MODEL_o385, TRUE)
    EVT_THREAD
        EVT_CALL(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        EVT_CALL(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, LVar0)
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        EVT_LABEL(15)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
    EVT_CALL(PlaySound, SOUND_LOOP_KPA_DRAIN_WATER)
    EVT_CALL(MakeLerp, 220, 120, 120, EASING_LINEAR)
    EVT_LABEL(30)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_o385, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_LRAW_KPA_DRAIN_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_KPA_DRAIN_WATER)
    EVT_WAIT(10)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, -13)
        EVT_LOOP(13)
            EVT_ADD(LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_o505, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseWaterLevel2) = {
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 220, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_s_sui, TRUE)
    EVT_CALL(EnableModel, MODEL_o385, FALSE)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        EVT_CALL(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, LVar0)
        EVT_WAIT(5)
        EVT_CALL(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        EVT_LABEL(15)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_LOOP_KPA_FILL_WATER, SOUND_SPACE_DEFAULT, 500, 240, -25)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o388, 2)
        EVT_CALL(SetTexPanner, MODEL_o389, 3)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(1000)
            EVT_CALL(SetTexPanOffset, 2, 0, LVar0, LVar1)
            EVT_CALL(SetTexPanOffset, 3, 0, 0, LVar2)
            EVT_ADD(LVar0, 1000)
            EVT_ADD(LVar1, 4000)
            EVT_ADD(LVar2, -1500)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(EnableModel, MODEL_o388, TRUE)
        EVT_CALL(MakeLerp, 400, 0, 20, EASING_LINEAR)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o388, 300, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
        EVT_CALL(EnableModel, MODEL_o389, TRUE)
        EVT_CALL(MakeLerp, 120, 220, 180, EASING_LINEAR)
        EVT_LABEL(30)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_s_sui, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o388, 300, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o389, 300, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(30)
        EVT_END_IF
        EVT_CALL(MakeLerp, 100, 1, 20, EASING_LINEAR)
        EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 100)
        EVT_CALL(TranslateModel, MODEL_o389, 300, 220, 0)
        EVT_CALL(TranslateModel, MODEL_o388, 300, 220, 0)
        EVT_CALL(ScaleModel, MODEL_o389, LVar2, EVT_FLOAT(1.0), LVar2)
        EVT_CALL(ScaleModel, MODEL_o388, LVar2, EVT_FLOAT(1.0), LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
        EVT_CALL(PlaySound, SOUND_LRAW_KPA_FILL_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_KPA_FILL_WATER)
        EVT_CALL(EnableModel, MODEL_o389, FALSE)
        EVT_CALL(EnableModel, MODEL_o388, FALSE)
    EVT_END_THREAD
    EVT_WAIT(230)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, -13)
        EVT_LOOP(13)
            EVT_ADD(LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_o505, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
