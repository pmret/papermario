#include "flo_24.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_Scene_FillWithWater) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(TranslateGroup, MODEL_g73, 0, 45, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 170, 0, 160)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 170, -90, 160)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 800)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-300.0), EVT_FLOAT(200.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(300.0), EVT_FLOAT(-150.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(PlaySound, SOUND_LOOP_FLO_FILL_WATER_POOL)
    //@bug thread is never terminated
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 90, 10, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o219, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o220, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        // should end thread here
    //@bug thread is never terminated
    EVT_THREAD
        EVT_CALL(MakeLerp, 45, 100, 150, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g73, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        // should end thread here
    EVT_WAIT(30)
    EVT_SET(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
    EVT_CALL(GotoMap, EVT_PTR("flo_10"), flo_10_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupWater) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        EVT_CALL(EnableGroup, MODEL_water1, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g60, FALSE)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, flo_24_ENTRY_2)
        EVT_CALL(EnableGroup, MODEL_g67, FALSE)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, MODEL_o165, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o215, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o166, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o216, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o189, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o192, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o219, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o220, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o218, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  140,  -80,  -70,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  -70,  100,  100,  -40)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0, -800,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0, -800, -200,  100)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-2500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(    0,-2500, -200,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
