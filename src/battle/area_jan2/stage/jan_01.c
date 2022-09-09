#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_01

EvtScript N(8021E300) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_LABEL(0)
    EVT_CALL(RotateGroup, LocalVar(10), 2, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LocalVar(10), 1, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LocalVar(10), -2, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RotateGroup, LocalVar(10), 1, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(RandInt, 30, LocalVar(0))
    EVT_ADD(LocalVar(0), 30)
    EVT_WAIT(LocalVar(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E418) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LocalVar(10), 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 1, EVT_FLOAT(-0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 1, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(1.5), -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 2, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(2.5), EVT_FLOAT(-1.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -3, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 3, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(2.5), -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 2, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 2, EVT_FLOAT(-1.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 2, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(1.5), EVT_FLOAT(-0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 1, EVT_FLOAT(0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 1, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(0.5), 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 0, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(-0.5), 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), -1, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), -1, EVT_FLOAT(0.5), 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LocalVar(10), -1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, LocalVar(10), 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8021E9C4) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 63, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_SET(LocalVar(0), 9)
        EVT_EXEC(N(8021E418))
        EVT_WAIT(5)
        EVT_SET(LocalVar(0), 10)
        EVT_EXEC(N(8021E418))
        EVT_WAIT(5)
        EVT_SET(LocalVar(0), 11)
        EVT_EXEC(N(8021E418))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021EA9C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021EAAC)[] = {
    0x00000012, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt01_shape",
    .hit = "jan_bt01_hit",
    .bg = "yos_bg",
    .preBattle = &N(beforeBattle_8021E9C4),
    .postBattle = &N(afterBattle_8021EA9C),
    .foregroundModelList = N(foregroundModelList_8021EAAC),
};
