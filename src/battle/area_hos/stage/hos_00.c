#include "common.h"
#include "battle/battle.h"
#include "mapfs/nok_bt02_shape.h"

#define NAMESPACE b_area_hos_hos_00

// Shakes a model (ID input on EVT_VAR(0)) on loop, waiting up to 30 frames between.
EvtScript N(802255E0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, LW(10), 0, 2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RandInt, 30, LW(0))
    EVT_ADD(LW(0), 30)
    EVT_WAIT_FRAMES(LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_802256E8) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_THREAD
        EVT_SET(LW(0), MODEL_h1)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h3)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h4)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h5)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h6)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h7)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h9)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h10)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h11)
        EVT_EXEC(N(802255E0))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), MODEL_h12)
        EVT_EXEC(N(802255E0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022589C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802258AC)[] = {
    MODEL_hap, MODEL_kusa3, 0,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt02_shape",
    .hit = "nok_bt02_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_802256E8),
    .postBattle = &N(afterBattle_8022589C),
    .foregroundModelList = N(foregroundModelList_802258AC),
};
