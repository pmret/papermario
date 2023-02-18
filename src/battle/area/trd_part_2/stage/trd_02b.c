#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_02b

EvtScript N(80231CE0) = {
    EVT_SET(LVarA, LVar0)
    EVT_LABEL(0)
    EVT_CALL(RotateGroup, LVarA, 2, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LVarA, 1, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LVarA, -2, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LVarA, 1, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 30)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80231DF8) = {
    EVT_SET(LVarA, LVar0)
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 1, EVT_FLOAT(-0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 1, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(1.5), -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(2.5), EVT_FLOAT(-1.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(2.5), -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 2, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 2, EVT_FLOAT(-1.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(1.5), EVT_FLOAT(-0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 1, EVT_FLOAT(0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 1, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(0.5), 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(-0.5), 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, -1, EVT_FLOAT(0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, 22, FALSE)
    EVT_CALL(EnableModel, 9, FALSE)
    EVT_CALL(EnableModel, 10, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, 19)
        EVT_EXEC(N(80231DF8))
        EVT_WAIT(5)
        EVT_SET(LVar0, 17)
        EVT_EXEC(N(80231DF8))
        EVT_WAIT(5)
        EVT_SET(LVar0, 15)
        EVT_EXEC(N(80231DF8))
        EVT_WAIT(5)
        EVT_SET(LVar0, 13)
        EVT_EXEC(N(80231DF8))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
