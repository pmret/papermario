#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_01b

EvtScript N(8021EAE0) = {
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

EvtScript N(8021EBF8) = {
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

EvtScript N(beforeBattle_8021F1A4) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 40, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_SET(LVar0, 9)
        EVT_EXEC(N(8021EBF8))
        EVT_WAIT(5)
        EVT_SET(LVar0, 10)
        EVT_EXEC(N(8021EBF8))
        EVT_WAIT(5)
        EVT_SET(LVar0, 11)
        EVT_EXEC(N(8021EBF8))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021F27C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021F28C)[] = {
    0x00000012, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt01_shape",
    .hit = "jan_bt01_hit",
    .bg = "yos_bg",
    .preBattle = &N(beforeBattle_8021F1A4),
    .postBattle = &N(afterBattle_8021F27C),
    .foregroundModelList = N(foregroundModelList_8021F28C),
};
