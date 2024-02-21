#include "obk_03.h"
#include "effects.h"

EvtScript N(EVS_DropStep) = {
    Call(MakeLerp, LVar0, 0, LVar1, EASING_COS_FAST_OVERSHOOT)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, LVar2, 0, LVar0, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_PlayDropStepFX) = {
    Call(PlaySoundAt, SOUND_OBK_STAIRS_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Wait(LVarA)
    Set(LVar3, LVar0)
    Set(LVar4, LVar1)
    Set(LVar5, LVar2)
    Add(LVar3, 0)
    Add(LVar4, -8)
    Add(LVar5, -70)
    PlayEffect(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
    Set(LVar6, LVar0)
    Set(LVar7, LVar1)
    Set(LVar8, LVar2)
    Add(LVar6, 0)
    Add(LVar7, -8)
    Add(LVar8, 70)
    PlayEffect(EFFECT_LANDING_DUST, 1, LVar6, LVar7, LVar8, 0)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnStairs) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Sub(LVar1, 15)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_Cam_ResetFocus) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

// first step only
#define EVT_DROP_STEP_1(x, y, z, delay, dist, modelID) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    ExecWait(N(EVS_Cam_FocusOnStairs)) \
    Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(3.0)) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    Set(LVarA, delay) \
    Exec(N(EVS_PlayDropStepFX)) \
    Set(LVar0, dist) \
    Set(LVar1, 5 * DT) \
    Set(LVar2, modelID) \
    Exec(N(EVS_DropStep)) \
    Wait(5)

// second step only
#define EVT_DROP_STEP_2(x, y, z, delay, dist, modelID) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    Exec(N(EVS_Cam_FocusOnStairs)) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    Set(LVarA, delay) \
    Exec(N(EVS_PlayDropStepFX)) \
    Set(LVar0, dist) \
    Set(LVar1, 5 * DT) \
    Set(LVar2, modelID) \
    Exec(N(EVS_DropStep)) \
    Wait(5)

// other steps
#define EVT_DROP_STEP_N(x, y, z, delay, dist, modelID) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    ExecWait(N(EVS_Cam_FocusOnStairs)) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    Set(LVarA, delay) \
    Exec(N(EVS_PlayDropStepFX)) \
    Set(LVar0, dist) \
    Set(LVar1, 5 * DT) \
    Set(LVar2, modelID) \
    Exec(N(EVS_DropStep)) \
    Wait(5)

// last step only
#define EVT_DROP_STEP_L(x, y, z, delay, dist, modelID) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    ExecWait(N(EVS_Cam_FocusOnStairs)) \
    Set(LVar0, x) \
    Set(LVar1, y) \
    Set(LVar2, z) \
    Set(LVarA, delay) \
    Exec(N(EVS_PlayDropStepFX)) \
    Set(LVar0, dist) \
    Set(LVar1, 2 * DT) \
    Set(LVar2, modelID) \
    ExecWait(N(EVS_DropStep)) \

EvtScript N(EVS_Scene_DropSteps) = {
    Call(DisablePlayerInput, TRUE)
    Call(EnableModel, MODEL_yk1, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_k1, TRUE)
    Call(EnableModel, MODEL_k2, TRUE)
    Call(EnableModel, MODEL_k3, TRUE)
    Call(EnableModel, MODEL_k4, TRUE)
    Call(EnableModel, MODEL_k5, TRUE)
    Call(EnableModel, MODEL_k6, TRUE)
    Call(EnableModel, MODEL_k7, TRUE)
    Call(EnableModel, MODEL_k8, TRUE)
    Call(TranslateModel, MODEL_k1, 0, 180, 0)
    Call(TranslateModel, MODEL_k2, 0, 155, 0)
    Call(TranslateModel, MODEL_k3, 0, 130, 0)
    Call(TranslateModel, MODEL_k4, 0, 105, 0)
    Call(TranslateModel, MODEL_k5, 0, 80, 0)
    Call(TranslateModel, MODEL_k6, 0, 55, 0)
    Call(TranslateModel, MODEL_k7, 0, 30, 0)
    Call(TranslateModel, MODEL_k8, 0, 5, 0)
    EVT_DROP_STEP_1(275, -185, 188, 28, 175, MODEL_k1)
    EVT_DROP_STEP_2(225, -160, 188, 28, 150, MODEL_k2)
    EVT_DROP_STEP_N(175, -135, 188, 28, 125, MODEL_k3)
    EVT_DROP_STEP_N(125, -110, 188, 26, 100, MODEL_k4)
    EVT_DROP_STEP_N( 75,  -85, 188, 25,  75, MODEL_k5)
    EVT_DROP_STEP_N (25,  -60, 188, 14,  50, MODEL_k6)
    EVT_DROP_STEP_N(-25,  -35, 188,  9,  25, MODEL_k7)
    EVT_DROP_STEP_L(-75,  -10, 188,  4,   0, MODEL_k8)
    Call(EnableModel, MODEL_kage, TRUE)
    Call(EnableModel, MODEL_kage_no, FALSE)
    Wait(30 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k4, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k5, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k6, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k7, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kaidan, COLLIDER_FLAGS_UPPER_MASK)
    ExecWait(N(EVS_Cam_ResetFocus))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupStairs) = {
    IfLt(GB_StoryProgress, STORY_CH3_HIT_HUGE_BLUE_SWITCH)
        Call(EnableModel, MODEL_k1, FALSE)
        Call(EnableModel, MODEL_k2, FALSE)
        Call(EnableModel, MODEL_k3, FALSE)
        Call(EnableModel, MODEL_k4, FALSE)
        Call(EnableModel, MODEL_k5, FALSE)
        Call(EnableModel, MODEL_k6, FALSE)
        Call(EnableModel, MODEL_k7, FALSE)
        Call(EnableModel, MODEL_k8, FALSE)
        Call(EnableModel, MODEL_kage, FALSE)
        Call(EnableModel, MODEL_kage_no, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k1, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k3, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k4, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k5, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k6, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k7, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kaidan, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableModel, MODEL_yk1, FALSE)
        Call(EnableModel, MODEL_kage, TRUE)
        Call(EnableModel, MODEL_kage_no, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
