#include "hos_10.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(ResumeIntroState)) {
    if (gGameStatusPtr->introPart > INTRO_PART_NONE && gGameStatusPtr->introPart < INTRO_PART_5) {
        gGameStatusPtr->introPart++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

void N(lerp_value_with_max_step)(f32 start, f32 end, f32 current, f32 maxStep, f32* out) {
    f32 remaining = end - current;

    if (end - start > 0.0f) {
        if (remaining < 0.0f) {
            *out = end;
        } else if (maxStep < remaining) {
            *out += maxStep;
        } else {
            *out += remaining;
        }
    } else if (remaining > 0.0f) {
        *out = end;
    } else if (remaining < -maxStep) {
        *out -= maxStep;
    } else {
        *out += remaining;
    }
}

API_CALLABLE(N(MakeShootingStar)) {
    fx_star(FX_STAR_FOREGROUND, 200.0f, 400.0f, 1200.0f, -300.0f, -100.0f, 0.0f, 30.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_Unused_Impl) = {
    EVT_THREAD
        EVT_SETF(LVar0, 0)
        EVT_LOOP(310)
            EVT_CALL(TranslateModel, MODEL_o3, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-1.5))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_CALL(N(ResumeIntroState))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Rising_Impl) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  400,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(  600,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 1000,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_F)
        TEX_PAN_PARAMS_STEP(    0, 1000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_E)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_k2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k7, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k9, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k12, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_s1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_s2, TRUE)
    EVT_THREAD
        EVT_WAIT(510)
        EVT_CALL(N(MakeShootingStar))
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_CALL(SetTexPanner, MODEL_nagare, 1)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(560)
        EVT_CALL(EnableModel, MODEL_nagare, TRUE)
        EVT_LOOP(32)
            EVT_ADD(LVar0, 0x800)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, MODEL_nagare, FALSE)
        EVT_CALL(TranslateModel, MODEL_nagare, -400, 100, 0)
        EVT_SET(LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(100)
        EVT_CALL(EnableModel, MODEL_nagare, TRUE)
        EVT_LOOP(32)
            EVT_ADD(LVar0, 0x800)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SETF(LVar0, -1125)
        EVT_LOOP(1450)
            EVT_CALL(TranslateModel, MODEL_o3, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-1.5))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SETF(LVar0, -500)
        EVT_LOOP(1450)
            EVT_CALL(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-2.5))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(600)
        EVT_SETF(LVar0, 0)
        EVT_SETF(LVar1, 0)
        EVT_LOOP(1000)
            EVT_CALL(TranslateGroup, MODEL_starland, 0, LVar0, 0)
            EVT_CALL(RotateGroup, MODEL_stl_1, LVar1, 0, -1, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(-3.59375))
            EVT_ADDF(LVar1, EVT_FLOAT(1.0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(740)
    EVT_CALL(N(ResumeIntroState))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_UnusedWhiteScreen) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_EXEC(N(EVS_Scene_Unused_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RisingAboveClouds) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_EXEC(N(EVS_Scene_Rising_Impl))
    EVT_RETURN
    EVT_END
};
