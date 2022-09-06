#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_sbk_sbk_02

#include "common/UnkFloatFunc3.inc.c"

#include "common/GetModelPos.inc.c"

EvtScript N(8021F720) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(7), LW(1))
    EVT_MUL(LW(7), 10)
    EVT_CALL(N(GetModelPos))
    EVT_LABEL(0)
    EVT_ADD(LW(7), 1)
    EVT_IF_GT(LW(7), 3599)
        EVT_SUB(LW(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc3), LW(7), LW(0), LW(1), LW(2))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8021F800) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LW(0), 1)
    EVT_SET(LW(1), 0)
    EVT_EXEC(N(8021F720))
    EVT_SET(LW(0), 3)
    EVT_SET(LW(1), 120)
    EVT_EXEC(N(8021F720))
    EVT_SET(LW(0), 5)
    EVT_SET(LW(1), 240)
    EVT_EXEC(N(8021F720))
    EVT_CALL(PlayEffect, EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021F8E8) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021F8F8)[] = {
    0x00000028, 0x00000027, 0x00000026, 0x00000025, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "sbk_tex",
    .shape = "sbk_bt02_shape",
    .hit = "sbk_bt02_hit",
    .bg = "sbk_bg",
    .preBattle = &N(beforeBattle_8021F800),
    .postBattle = &N(afterBattle_8021F8E8),
    .foregroundModelList = N(foregroundModelList_8021F8F8),
};
