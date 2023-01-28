#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_02

EvtScript N(8022B810) = {
    EVT_SET(LVarA, LVar0)
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, LVarA, 0, 2, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, 0, 2, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 30)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8022B918) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_THREAD
        EVT_SET(LVar0, 19)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 20)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 21)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 22)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 23)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 24)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 25)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 26)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 27)
        EVT_EXEC(N(8022B810))
        EVT_WAIT(5)
        EVT_SET(LVar0, 28)
        EVT_EXEC(N(8022B810))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022BACC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022BADC)[] = {
    0x0000001F, 0x00000020, 0x0000001E, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt02_shape",
    .hit = "nok_bt02_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_8022B918),
    .postBattle = &N(afterBattle_8022BACC),
    .foregroundModelList = N(foregroundModelList_8022BADC),
};
