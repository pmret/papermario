#include "kpa_134.h"
#include "sprite/player.h"

extern EvtScript N(EVS_LowerWaterLevel0);
extern EvtScript N(EVS_RaiseWaterLevel1);
extern EvtScript N(EVS_LowerWaterLevel1);
extern EvtScript N(EVS_RaiseWaterLevel2);
extern EvtScript N(EVS_SetupLowerChain);
extern EvtScript N(EVS_SetupUpperChain);

EvtScript N(EVS_SetupChains) = {
    Call(SetRenderMode, MODEL_s_sui, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_o385, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(EnableModel, MODEL_o388, FALSE)
    Call(EnableModel, MODEL_o389, FALSE)
    Call(TranslateModel, MODEL_o387, 0, 30, 0)
    Call(TranslateModel, MODEL_o505, 0, 0, 0)
    Switch(GB_KPA_WaterLevel)
        CaseEq(0)
            Call(SetGroupVisibility, MODEL_suimen, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(1)
            Call(EnableModel, MODEL_s_sui, FALSE)
            Call(TranslateGroup, MODEL_sui1, 0, 120, 0)
            Call(TranslateModel, MODEL_o385, 0, 120, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliaw, SURFACE_TYPE_DOCK_WALL)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_DOCK_WALL)
        CaseEq(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
            Call(EnableModel, MODEL_o385, FALSE)
            Call(TranslateGroup, MODEL_sui1, 0, 220, 0)
            Call(TranslateModel, MODEL_s_sui, 0, 220, 0)
    EndSwitch
    Exec(N(EVS_SetupLowerChain))
    Exec(N(EVS_SetupUpperChain))
    Return
    End
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
    Call(N(CreateLowerChainShadow))
    Label(10)
        Call(N(DetectLowerChainGrab))
        Call(DisablePlayerPhysics, TRUE)
        Call(DisablePlayerInput, TRUE)
        Call(PlaySoundAtPlayer, SOUND_KPA_PULL_CHAIN, SOUND_SPACE_DEFAULT)
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
        Thread
            Set(LVar0, 150)
            Set(LVar1, 30)
            UseBuf(Ref(N(ChainAnimOffsets)))
            Loop(ARRAY_COUNT(N(ChainAnimOffsets)))
                BufRead1(LVar2)
                Add(LVar0, LVar2)
                Add(LVar1, LVar2)
                Call(SetPlayerPos, 50, LVar0, -34)
                Call(TranslateModel, MODEL_o387, 0, LVar1, 0)
                Wait(1)
            EndLoop
        EndThread
        IfEq(GB_KPA_WaterLevel, 0)
            ExecWait(N(EVS_RaiseWaterLevel1))
            Set(GB_KPA_WaterLevel, 1)
        Else
            ExecWait(N(EVS_LowerWaterLevel0))
            Set(GB_KPA_WaterLevel, 0)
        EndIf
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfEq(LVar1, 115)
                BreakLoop
            EndIf
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_LowerWaterLevel0) = {
    Wait(20)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 120, Float(1.0))
    EndThread
    Thread
        Call(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        Call(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Set(LVar2, LVar0)
        Wait(5)
        Call(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        Label(15)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(15)
        EndIf
    EndThread
    Call(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
    Call(EnableModel, MODEL_o385, TRUE)
    Call(PlaySound, SOUND_LOOP_KPA_DRAIN_WATER)
    Call(MakeLerp, 120, 20, 120, EASING_LINEAR)
    Label(30)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o385, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(30)
    EndIf
    Call(PlaySound, SOUND_LRAW_KPA_DRAIN_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(StopTrackingSoundPos, SOUND_LRAW_KPA_DRAIN_WATER)
    Call(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_HIDDEN)
    Call(EnableModel, MODEL_s_sui, FALSE)
    Call(EnableModel, MODEL_o385, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
    Wait(10)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Thread
        Set(LVar0, 17)
        Loop(13)
            Add(LVar0, 1)
            Call(TranslateModel, MODEL_o387, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_RaiseWaterLevel1) = {
    Wait(20)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 220, Float(1.0))
    EndThread
    Thread
        Wait(60)
        Call(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        Call(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Set(LVar2, LVar0)
        Wait(5)
        Call(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        Label(15)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(15)
        EndIf
    EndThread
    Call(PlaySoundAt, SOUND_LOOP_KPA_FILL_WATER, SOUND_SPACE_DEFAULT, 118, 115, -11)
    Wait(20)
    Thread
        Call(SetTexPanner, MODEL_o388, TEX_PANNER_2)
        Call(SetTexPanner, MODEL_o389, TEX_PANNER_3)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(1000)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar2)
            Add(LVar0, 1000)
            Add(LVar1, 4000)
            Add(LVar2, -1500)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(EnableModel, MODEL_o388, TRUE)
        Call(MakeLerp, 400, 0, 20, EASING_LINEAR)
        Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o388, -100, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Call(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
        Call(EnableModel, MODEL_o385, TRUE)
        Call(EnableModel, MODEL_o389, TRUE)
        Call(MakeLerp, 20, 120, 180, EASING_LINEAR)
        Label(30)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o385, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o389, -100, LVar0, 0)
        Call(TranslateModel, MODEL_o388, -100, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(30)
        EndIf
        Call(MakeLerp, 100, 1, 20, EASING_LINEAR)
        Label(40)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 100)
        Call(TranslateModel, MODEL_o389, -100, 120, 0)
        Call(TranslateModel, MODEL_o388, -100, 120, 0)
        Call(ScaleModel, MODEL_o389, LVar2, Float(1.0), LVar2)
        Call(ScaleModel, MODEL_o388, LVar2, Float(1.0), LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
        Call(PlaySound, SOUND_LRAW_KPA_FILL_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(StopTrackingSoundPos, SOUND_LRAW_KPA_FILL_WATER)
        Call(EnableModel, MODEL_o389, FALSE)
        Call(EnableModel, MODEL_o388, FALSE)
    EndThread
    Wait(230)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_hidari, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_migi, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deiliaw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_IGNORE_SHELL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliaw, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliaw, COLLIDER_FLAG_DOCK_WALL)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Thread
        Set(LVar0, 17)
        Loop(13)
            Add(LVar0, 1)
            Call(TranslateModel, MODEL_o387, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Return
    End
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
    Call(N(CreateUpperChainShadow))
    Label(10)
        Call(N(DetectUpperChainGrab))
        Call(DisablePlayerPhysics, TRUE)
        Call(DisablePlayerInput, TRUE)
        Call(PlaySoundAtPlayer, SOUND_KPA_PULL_CHAIN, SOUND_SPACE_DEFAULT)
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
        Thread
            Set(LVar0, 275)
            Set(LVar1, 0)
            UseBuf(Ref(N(ChainAnimOffsets)))
            Loop(20)
                BufRead1(LVar2)
                Add(LVar0, LVar2)
                Add(LVar1, LVar2)
                Call(SetPlayerPos, 680, LVar0, -35)
                Call(TranslateModel, MODEL_o505, 0, LVar1, 0)
                Wait(1)
            EndLoop
        EndThread
        IfEq(GB_KPA_WaterLevel, 1)
            ExecWait(N(EVS_RaiseWaterLevel2))
            Set(GB_KPA_WaterLevel, 2)
        Else
            ExecWait(N(EVS_LowerWaterLevel1))
            Set(GB_KPA_WaterLevel, 1)
        EndIf
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfEq(LVar1, 240)
                BreakLoop
            EndIf
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_LowerWaterLevel1) = {
    Wait(20)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 120, Float(1.0))
    EndThread
    Call(EnableModel, MODEL_s_sui, FALSE)
    Call(EnableModel, MODEL_o385, TRUE)
    Thread
        Call(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        Call(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Set(LVar2, LVar0)
        Wait(5)
        Call(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        Label(15)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(15)
        EndIf
    EndThread
    Call(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
    Call(PlaySound, SOUND_LOOP_KPA_DRAIN_WATER)
    Call(MakeLerp, 220, 120, 120, EASING_LINEAR)
    Label(30)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o385, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(30)
    EndIf
    Call(PlaySound, SOUND_LRAW_KPA_DRAIN_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(StopTrackingSoundPos, SOUND_LRAW_KPA_DRAIN_WATER)
    Wait(10)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Thread
        Set(LVar0, -13)
        Loop(13)
            Add(LVar0, 1)
            Call(TranslateModel, MODEL_o505, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_RaiseWaterLevel2) = {
    Wait(20)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 220, Float(1.0))
    EndThread
    Call(EnableModel, MODEL_s_sui, TRUE)
    Call(EnableModel, MODEL_o385, FALSE)
    Thread
        Wait(60)
        Call(func_802CA988, CAM_DEFAULT, LVar4, LVar5, LVar6, LVar7)
        Call(MakeLerp, LVar6, 600, 20, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar0, LVar7)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Set(LVar2, LVar0)
        Wait(5)
        Call(MakeLerp, LVar7, -20, 20, EASING_LINEAR)
        Label(15)
        Call(UpdateLerp)
        Call(func_802CABE8, CAM_DEFAULT, LVar4, LVar5, LVar2, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(15)
        EndIf
    EndThread
    Call(PlaySoundAt, SOUND_LOOP_KPA_FILL_WATER, SOUND_SPACE_DEFAULT, 500, 240, -25)
    Wait(20)
    Thread
        Call(SetTexPanner, MODEL_o388, 2)
        Call(SetTexPanner, MODEL_o389, 3)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(1000)
            Call(SetTexPanOffset, 2, 0, LVar0, LVar1)
            Call(SetTexPanOffset, 3, 0, 0, LVar2)
            Add(LVar0, 1000)
            Add(LVar1, 4000)
            Add(LVar2, -1500)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(EnableModel, MODEL_o388, TRUE)
        Call(MakeLerp, 400, 0, 20, EASING_LINEAR)
        Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o388, 300, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Call(SetGroupVisibility, MODEL_sui1, MODEL_GROUP_VISIBLE)
        Call(EnableModel, MODEL_o389, TRUE)
        Call(MakeLerp, 120, 220, 180, EASING_LINEAR)
        Label(30)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_sui1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_s_sui, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o388, 300, LVar0, 0)
        Call(TranslateModel, MODEL_o389, 300, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(30)
        EndIf
        Call(MakeLerp, 100, 1, 20, EASING_LINEAR)
        Label(40)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 100)
        Call(TranslateModel, MODEL_o389, 300, 220, 0)
        Call(TranslateModel, MODEL_o388, 300, 220, 0)
        Call(ScaleModel, MODEL_o389, LVar2, Float(1.0), LVar2)
        Call(ScaleModel, MODEL_o388, LVar2, Float(1.0), LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
        Call(PlaySound, SOUND_LRAW_KPA_FILL_WATER | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(StopTrackingSoundPos, SOUND_LRAW_KPA_FILL_WATER)
        Call(EnableModel, MODEL_o389, FALSE)
        Call(EnableModel, MODEL_o388, FALSE)
    EndThread
    Wait(230)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Thread
        Set(LVar0, -13)
        Loop(13)
            Add(LVar0, 1)
            Call(TranslateModel, MODEL_o505, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Return
    End
};
