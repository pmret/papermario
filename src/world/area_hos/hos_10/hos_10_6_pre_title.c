#include "hos_10.h"
#include "effects.h"
#include "sprite/player.h"

#define NAME_SUFFIX _PreTitle
#include "world/common/atomic/TexturePan.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_Scene_PreTitle) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableModel, MODEL_o2, FALSE)
    EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  400,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan_PreTitle))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(  600,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan_PreTitle))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 1000,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan_PreTitle))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_k2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k7, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k9, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k12, TRUE)
    EVT_THREAD
        EVT_SETF(LVar0, -1800)
        EVT_LOOP(450 * DT)
            EVT_CALL(TranslateModel, MODEL_o3, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(1.5 / DT))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SETF(LVar0, -1725)
        EVT_LOOP(450 * DT)
            EVT_CALL(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(2.5 / DT))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_mario_o)
            EVT_IF_LT(LVar1, -130)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 0, -130, 480, 0)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 350, -200, 400 * DT, EASING_LINEAR)
    EVT_SET(LVar2, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_mario_o, 0, LVar0, 480)
        EVT_CALL(ScaleModel, MODEL_mario_o, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
        EVT_CALL(RotateModel, MODEL_mario_o, LVar2, 1, 0, 0)
        EVT_ADD(LVar2, EVT_FLOAT(22.5))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_21"), kmr_21_ENTRY_0, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};
