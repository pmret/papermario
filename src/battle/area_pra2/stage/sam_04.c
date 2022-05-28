#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra2_sam_04

s32 D_802211E0_669930[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};


INCLUDE_ASM(s32, "battle/area_pra2/660E10", func_802186C0_660E10);

#include "common/Set80071270_0_16.inc.c"
#include "common/UnkFloatFunc2.inc.c"

void func_802189E0_661130(void) {
    enable_background_wave();
}

EvtScript N(802211F0) = {
    EVT_CALL(N(Set80071270_0_16))
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8022122C) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(RandInt, 30, LW(0))
    EVT_ADD(LW(0), 30)
    EVT_WAIT_FRAMES(LW(0))
    EVT_SET(LW(1), 0)
    EVT_LOOP(10)
        EVT_ADD(LW(1), 36)
        EVT_CALL(RotateModel, LW(10), LW(1), 0, 1, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802212F4) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_EXEC(N(8022122C))
    EVT_SET(LW(7), 0)
    EVT_LABEL(0)
    EVT_ADD(LW(7), 4)
    EVT_IF_GT(LW(7), 3599)
        EVT_SUB(LW(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc2), LW(7), LW(0), LW(1), LW(2))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802213D4) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(7), 0)
    EVT_LABEL(0)
    EVT_ADD(LW(7), 4)
    EVT_IF_GT(LW(7), 3599)
        EVT_SUB(LW(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc2), LW(7), LW(0), LW(1), LW(2))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_EXEC(N(802211F0))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt04_shape",
    .hit = "sam_bt04_hit",
    .bg = "sam_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
