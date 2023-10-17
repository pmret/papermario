#include "obk_03.h"
#include "effects.h"

EvtScript N(EVS_DropStep) = {
    EVT_CALL(MakeLerp, LVar0, 0, LVar1, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayDropStepFX) = {
    EVT_CALL(PlaySoundAt, SOUND_OBK_STAIRS_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(LVarA)
    EVT_SET(LVar3, LVar0)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar5, LVar2)
    EVT_ADD(LVar3, 0)
    EVT_ADD(LVar4, -8)
    EVT_ADD(LVar5, -70)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar3, LVar4, LVar5, 0)
    EVT_SET(LVar6, LVar0)
    EVT_SET(LVar7, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_ADD(LVar6, 0)
    EVT_ADD(LVar7, -8)
    EVT_ADD(LVar8, 70)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar6, LVar7, LVar8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_FocusOnStairs) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_ResetFocus) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

// first step only
#define EVT_DROP_STEP_1(x, y, z, delay, dist, modelID) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_EXEC_WAIT(N(EVS_Cam_FocusOnStairs)) \
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(3.0)) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_SET(LVarA, delay) \
    EVT_EXEC(N(EVS_PlayDropStepFX)) \
    EVT_SET(LVar0, dist) \
    EVT_SET(LVar1, 5 * DT) \
    EVT_SET(LVar2, modelID) \
    EVT_EXEC(N(EVS_DropStep)) \
    EVT_WAIT(5)

// second step only
#define EVT_DROP_STEP_2(x, y, z, delay, dist, modelID) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_EXEC(N(EVS_Cam_FocusOnStairs)) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_SET(LVarA, delay) \
    EVT_EXEC(N(EVS_PlayDropStepFX)) \
    EVT_SET(LVar0, dist) \
    EVT_SET(LVar1, 5 * DT) \
    EVT_SET(LVar2, modelID) \
    EVT_EXEC(N(EVS_DropStep)) \
    EVT_WAIT(5)

// other steps
#define EVT_DROP_STEP_N(x, y, z, delay, dist, modelID) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_EXEC_WAIT(N(EVS_Cam_FocusOnStairs)) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_SET(LVarA, delay) \
    EVT_EXEC(N(EVS_PlayDropStepFX)) \
    EVT_SET(LVar0, dist) \
    EVT_SET(LVar1, 5 * DT) \
    EVT_SET(LVar2, modelID) \
    EVT_EXEC(N(EVS_DropStep)) \
    EVT_WAIT(5)

// last step only
#define EVT_DROP_STEP_L(x, y, z, delay, dist, modelID) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_EXEC_WAIT(N(EVS_Cam_FocusOnStairs)) \
    EVT_SET(LVar0, x) \
    EVT_SET(LVar1, y) \
    EVT_SET(LVar2, z) \
    EVT_SET(LVarA, delay) \
    EVT_EXEC(N(EVS_PlayDropStepFX)) \
    EVT_SET(LVar0, dist) \
    EVT_SET(LVar1, 2 * DT) \
    EVT_SET(LVar2, modelID) \
    EVT_EXEC_WAIT(N(EVS_DropStep)) \

EvtScript N(EVS_Scene_DropSteps) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableModel, MODEL_yk1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_k1, TRUE)
    EVT_CALL(EnableModel, MODEL_k2, TRUE)
    EVT_CALL(EnableModel, MODEL_k3, TRUE)
    EVT_CALL(EnableModel, MODEL_k4, TRUE)
    EVT_CALL(EnableModel, MODEL_k5, TRUE)
    EVT_CALL(EnableModel, MODEL_k6, TRUE)
    EVT_CALL(EnableModel, MODEL_k7, TRUE)
    EVT_CALL(EnableModel, MODEL_k8, TRUE)
    EVT_CALL(TranslateModel, MODEL_k1, 0, 180, 0)
    EVT_CALL(TranslateModel, MODEL_k2, 0, 155, 0)
    EVT_CALL(TranslateModel, MODEL_k3, 0, 130, 0)
    EVT_CALL(TranslateModel, MODEL_k4, 0, 105, 0)
    EVT_CALL(TranslateModel, MODEL_k5, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_k6, 0, 55, 0)
    EVT_CALL(TranslateModel, MODEL_k7, 0, 30, 0)
    EVT_CALL(TranslateModel, MODEL_k8, 0, 5, 0)
    EVT_DROP_STEP_1(275, -185, 188, 28, 175, MODEL_k1)
    EVT_DROP_STEP_2(225, -160, 188, 28, 150, MODEL_k2)
    EVT_DROP_STEP_N(175, -135, 188, 28, 125, MODEL_k3)
    EVT_DROP_STEP_N(125, -110, 188, 26, 100, MODEL_k4)
    EVT_DROP_STEP_N( 75,  -85, 188, 25,  75, MODEL_k5)
    EVT_DROP_STEP_N (25,  -60, 188, 14,  50, MODEL_k6)
    EVT_DROP_STEP_N(-25,  -35, 188,  9,  25, MODEL_k7)
    EVT_DROP_STEP_L(-75,  -10, 188,  4,   0, MODEL_k8)
    EVT_CALL(EnableModel, MODEL_kage, TRUE)
    EVT_CALL(EnableModel, MODEL_kage_no, FALSE)
    EVT_WAIT(30 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k5, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k6, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k7, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kaidan, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStairs) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_HIT_HUGE_BLUE_SWITCH)
        EVT_CALL(EnableModel, MODEL_k1, FALSE)
        EVT_CALL(EnableModel, MODEL_k2, FALSE)
        EVT_CALL(EnableModel, MODEL_k3, FALSE)
        EVT_CALL(EnableModel, MODEL_k4, FALSE)
        EVT_CALL(EnableModel, MODEL_k5, FALSE)
        EVT_CALL(EnableModel, MODEL_k6, FALSE)
        EVT_CALL(EnableModel, MODEL_k7, FALSE)
        EVT_CALL(EnableModel, MODEL_k8, FALSE)
        EVT_CALL(EnableModel, MODEL_kage, FALSE)
        EVT_CALL(EnableModel, MODEL_kage_no, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k3, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k4, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k5, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k6, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k7, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kaidan, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_yk1, FALSE)
        EVT_CALL(EnableModel, MODEL_kage, TRUE)
        EVT_CALL(EnableModel, MODEL_kage_no, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
