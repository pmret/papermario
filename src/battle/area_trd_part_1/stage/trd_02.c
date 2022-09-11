#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_02

EvtScript N(80222B60) = {
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

EvtScript N(80222C78) = {
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

EvtScript N(beforeBattle_80223224) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 12, 0)
    EVT_THREAD
        EVT_SET(LVar0, 19)
        EVT_EXEC(N(80222C78))
        EVT_WAIT(5)
        EVT_SET(LVar0, 17)
        EVT_EXEC(N(80222C78))
        EVT_WAIT(5)
        EVT_SET(LVar0, 15)
        EVT_EXEC(N(80222C78))
        EVT_WAIT(5)
        EVT_SET(LVar0, 13)
        EVT_EXEC(N(80222C78))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223318) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223328)[] = {
    0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = &N(beforeBattle_80223224),
    .postBattle = &N(afterBattle_80223318),
    .foregroundModelList = N(foregroundModelList_80223328),
};
