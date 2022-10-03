#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sbk_bt02_shape.h"

#define NAMESPACE b_area_dig_dig_03

#include "common/UnkFloatFunc3.inc.c"

#include "common/GetModelPos.inc.c"

EvtScript N(updateModels) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar7, LVar1)
    EVT_MUL(LVar7, 10)
    EVT_CALL(N(GetModelPos))
    EVT_LABEL(0)
    EVT_ADD(LVar7, 1)
    EVT_IF_GT(LVar7, 3599)
        EVT_SUB(LVar7, 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc3), LVar7, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LVar0, MODEL_g60)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(updateModels))
    EVT_SET(LVar0, MODEL_g63)
    EVT_SET(LVar1, 120)
    EVT_EXEC(N(updateModels))
    EVT_SET(LVar0, MODEL_g62)
    EVT_SET(LVar1, 240)
    EVT_EXEC(N(updateModels))
    EVT_CALL(PlayEffect, EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_o322, MODEL_o321, MODEL_o320, MODEL_o319, 0,
};

Stage NAMESPACE = {
    .texture = "sbk_tex",
    .shape = "sbk_bt02_shape",
    .hit = "sbk_bt02_hit",
    .bg = "sbk_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
