#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_sam_01

INCLUDE_ASM(s32, "battle/area_kmr_part_3/448E80", func_80219A40_448E80);

#include "common/Set80071270_0_16.inc.c"

#include "common/UnkFloatFunc2.inc.c"

s32 N(D_802336E0_43AB20)[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(802336F0) = {
    EVT_CALL(N(Set80071270_0_16))
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8023372C) = {
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

EvtScript N(802337F4) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_EXEC(N(8023372C))
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

EvtScript N(802338D4) = {
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

EvtScript N(beforeBattle_80233998) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_EXEC(N(802336F0))
    EVT_THREAD
        EVT_SET(LW(0), 22)
        EVT_SET(LW(1), 1)
        EVT_EXEC(N(802337F4))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 20)
        EVT_SET(LW(1), 3)
        EVT_EXEC(N(802337F4))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 18)
        EVT_SET(LW(1), 4)
        EVT_EXEC(N(802337F4))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 16)
        EVT_SET(LW(1), 2)
        EVT_EXEC(N(802337F4))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80233AA8) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80233AB8)[] = {
    0xFFFFFFFF, 0x0000001A, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt01_shape",
    .hit = "sam_bt01_hit",
    .bg = "yki_bg",
    .preBattle = &N(beforeBattle_80233998),
    .postBattle = &N(afterBattle_80233AA8),
    .foregroundModelList = N(foregroundModelList_80233AB8),
};
