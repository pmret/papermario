#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan_jan_00

EvtScript N(80226B00) = {
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

EvtScript N(80226C18) = {
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

EvtScript N(beforeBattle_802271C4) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LVar0, 32)
    EVT_EXEC(N(80226B00))
    EVT_SET(LVar0, 43)
    EVT_EXEC(N(80226B00))
    EVT_SET(LVar0, 53)
    EVT_EXEC(N(80226C18))
    EVT_CALL(PlayEffect, EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227298) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt00_shape",
    .hit = "jan_bt00_hit",
    .bg = "yos_bg",
    .preBattle = &N(beforeBattle_802271C4),
    .postBattle = &N(afterBattle_80227298),
};
