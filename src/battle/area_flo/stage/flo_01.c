#include "common.h"
#include "battle/battle.h"
#include "mapfs/flo_bt01_shape.h"
#include "effects.h"

#define NAMESPACE b_area_flo_flo_01

EvtScript N(80230E90) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 0)
    EVT_CALL(RandInt, 40, LVar2)
    EVT_SUB(LVar2, 100)
    EVT_CALL(RandInt, 30, LVar3)
    EVT_ADD(LVar3, 90)
    EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, 20, LVar0)
    EVT_ADD(LVar0, 20)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230FA8) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 0)
    EVT_CALL(RandInt, 50, LVar2)
    EVT_ADD(LVar2, 71)
    EVT_CALL(RandInt, 30, LVar3)
    EVT_ADD(LVar3, 90)
    EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 20)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802310C0) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 50)
    EVT_CALL(RandInt, 40, LVar2)
    EVT_ADD(LVar2, -124)
    EVT_CALL(RandInt, 30, LVar3)
    EVT_ADD(LVar3, 90)
    EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 20)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/MakeSun.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 37, 1)
    EVT_CALL(SetGroupEnabled, 28, 0)
    EVT_CALL(SetGroupEnabled, 22, 0)
    EVT_EXEC(N(80230E90))
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_o400, MODEL_o401, MODEL_o407, MODEL_o411, MODEL_o422, MODEL_o423, MODEL_o424, 0,
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt01_shape",
    .hit = "flo_bt01_hit",
    .bg = "fla_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
