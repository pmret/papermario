#include "common.h"
#include "battle/battle.h"
#include "mapfs/hos_bt02_shape.h"

#define NAMESPACE b_area_hos_hos_02

EvtScript N(beforeBattle_802258E0) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o372, TEX_PANNER_1)
        EVT_CALL(SetTexPanner, MODEL_o375, TEX_PANNER_1)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, -50)
            EVT_ADD(LVar1, 300)
            EVT_ADD(LVar2, 90)
            EVT_ADD(LVar3, -200)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVarA, 0)
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -7, 7, 40, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o371, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o372, 0, LVar0, 0)
        EVT_MUL(LVar0, 3)
        EVT_CALL(RotateModel, 17, LVarA, 0, 0, 1)
        EVT_ADD(LVarA, -3)
        EVT_CALL(ClampAngleFloat, LVarA)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 7, -7, 40, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o371, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o372, 0, LVar0, 0)
        EVT_MUL(LVar0, 3)
        EVT_CALL(RotateModel, 17, LVarA, 0, 0, 1)
        EVT_ADD(LVarA, -3)
        EVT_CALL(ClampAngleFloat, LVarA)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVarA, 0)
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -10, 4, 40, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o376, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o375, 0, LVar0, 0)
        EVT_MUL(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_o376, LVarA, 0, 0, 1)
        EVT_ADD(LVarA, -3)
        EVT_CALL(ClampAngleFloat, LVarA)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 4, -10, 40, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o376, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o375, 0, LVar0, 0)
        EVT_MUL(LVar0, -3)
        EVT_CALL(RotateModel, MODEL_o376, LVarA, 0, 0, 1)
        EVT_ADD(LVarA, -3)
        EVT_CALL(ClampAngleFloat, LVarA)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
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
    .preBattle = &N(beforeBattle_802258E0),
    .postBattle = &N(afterBattle_80225E20),
};
