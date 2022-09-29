#include "kzn_19.h"

EvtScript N(D_80247E00_C959B0) = {
    EVT_CALL(EnableGroup, MODEL_naka, FALSE)
    EVT_CALL(EnableGroup, MODEL_g93, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SETF(LVar0, 0)
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.33398438))
            EVT_CALL(RotateModel, MODEL_o2, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.5))
            EVT_CALL(RotateModel, MODEL_o3, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.25))
            EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(120)
        EVT_SUBF(LVar0, EVT_FLOAT(0.25))
        EVT_CALL(TranslateModel, MODEL_o6, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(AF_KZN_08, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247FDC_C95B8C) = {
    EVT_CALL(RotateModel, MODEL_o2, 20, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o3, 30, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o4, 15, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o6, 0, -30, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248068) = {
    EVT_SET(AF_KZN_08, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_NE(AF_KZN_08, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 170, 25, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(2.0))
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
        EVT_EXEC(N(D_80247E00_C959B0))
        EVT_CALL(MakeLerp, 200, 50, 75, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 1, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_ELSE
        EVT_EXEC(N(D_80247FDC_C95B8C))
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, 0, COLLIDER_hoshi, COLLIDER_FLAGS_UPPER_MASK)
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
