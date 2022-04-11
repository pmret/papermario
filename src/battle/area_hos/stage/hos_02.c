#include "common.h"
#include "battle/battle.h"
#include "mapfs/hos_bt02_shape.h"

#define NAMESPACE b_area_hos_hos_02

EvtScript N(beforeBattle_802258E0) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o372, 1)
        EVT_CALL(SetTexPanner, MODEL_o375, 1)
        EVT_SET(LW(0), 0)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), 0)
        EVT_SET(LW(3), 0)
        EVT_LOOP(0)
            EVT_ADD(LW(0), -50)
            EVT_ADD(LW(1), 300)
            EVT_ADD(LW(2), 90)
            EVT_ADD(LW(3), -200)
            EVT_CALL(SetTexPanOffset, 1, 0, LW(0), LW(1))
            EVT_CALL(SetTexPanOffset, 1, 1, LW(2), LW(3))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(10), 0)
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -7, 7, 40, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o371, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o372, 0, LW(0), 0)
        EVT_MUL(LW(0), 3)
        EVT_CALL(RotateModel, 17, LW(10), 0, 0, 1)
        EVT_ADD(LW(10), -3)
        EVT_CALL(ClampAngleFloat, LW(10))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 7, -7, 40, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o371, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o372, 0, LW(0), 0)
        EVT_MUL(LW(0), 3)
        EVT_CALL(RotateModel, 17, LW(10), 0, 0, 1)
        EVT_ADD(LW(10), -3)
        EVT_CALL(ClampAngleFloat, LW(10))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(10), 0)
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -10, 4, 40, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o376, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o375, 0, LW(0), 0)
        EVT_MUL(LW(0), -3)
        EVT_CALL(RotateModel, MODEL_o376, LW(10), 0, 0, 1)
        EVT_ADD(LW(10), -3)
        EVT_CALL(ClampAngleFloat, LW(10))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 4, -10, 40, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o376, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o375, 0, LW(0), 0)
        EVT_MUL(LW(0), -3)
        EVT_CALL(RotateModel, MODEL_o376, LW(10), 0, 0, 1)
        EVT_ADD(LW(10), -3)
        EVT_CALL(ClampAngleFloat, LW(10))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80225E20) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "hos_tex",
    .shape = "hos_bt02_shape",
    .hit = "hos_bt02_hit",
    .bg = "nok_bg",
    .preBattle = N(beforeBattle_802258E0),
    .postBattle = N(afterBattle_80225E20),
};
