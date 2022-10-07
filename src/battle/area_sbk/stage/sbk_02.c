#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_sbk_sbk_02

#include "common/UnkFloatFunc3.inc.c"

#include "common/GetModelPos.inc.c"

EvtScript N(8021F720) = {
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

EvtScript N(beforeBattle_8021F800) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(8021F720))
    EVT_SET(LVar0, 3)
    EVT_SET(LVar1, 120)
    EVT_EXEC(N(8021F720))
    EVT_SET(LVar0, 5)
    EVT_SET(LVar1, 240)
    EVT_EXEC(N(8021F720))
    EVT_PLAY_EFFECT(EFFECT_SUN)
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
