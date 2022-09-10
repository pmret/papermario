#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kgr_kgr_01

#include "common/UnkFloatFunc005.inc.c"

EvtScript N(8021C330) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(N(UnkFloatFunc005), 0)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(11), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(11), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LW(11))
    EVT_ADD(LW(11), 30)
    EVT_LOOP(LW(11))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RandInt, 5, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc005), 3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(11), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(11), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LW(11))
    EVT_ADD(LW(11), 30)
    EVT_LOOP(LW(11))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C9C0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 1, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 2, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021CD64)[] = {
     0, -1, -1, -2, -2, -3, -5, -8,
    -8, -7, -6, -4, -2, -1,  0,  255,
};

EvtScript N(8021CDA4) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(5), 5)
    EVT_USE_BUF(EVT_ADDR(N(intTable_8021CD64)))
    EVT_LABEL(0)
    EVT_BUF_READ1(LW(1))
    EVT_IF_EQ(LW(1), 255)
        EVT_USE_BUF(EVT_ADDR(N(intTable_8021CD64)))
        EVT_BUF_READ1(LW(1))
    EVT_END_IF
    EVT_SET(LW(0), LW(5))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
    EVT_WAIT(1)
    EVT_ADD(LW(5), 1)
    EVT_SET(LW(12), LW(11))
    EVT_SUB(LW(12), 20)
    EVT_IF_GT(LW(5), LW(12))
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LW(0), LW(5))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
    EVT_WAIT(1)
    EVT_ADD(LW(5), 1)
    EVT_SET(LW(12), LW(11))
    EVT_SUB(LW(12), 20)
    EVT_IF_GT(LW(5), LW(12))
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_SET(LW(2), 0)
    EVT_LOOP(20)
        EVT_ADD(LW(5), 1)
        EVT_SUB(LW(1), 2)
        EVT_SET(LW(0), LW(5))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SUB(LW(5), 280)
    EVT_SET(LW(1), 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D010) = {
    EVT_SET(LW(10), LW(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8021D3B4) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LW(0), 19)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 20)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 21)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 22)
        EVT_EXEC(N(8021D010))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 14)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 15)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 16)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 17)
        EVT_EXEC(N(8021D010))
        EVT_WAIT(4)
        EVT_SET(LW(0), 18)
        EVT_EXEC(N(8021D010))
    EVT_END_THREAD
    EVT_SET(LW(0), 11)
    EVT_EXEC(N(8021D010))
    EVT_SET(LW(0), 12)
    EVT_EXEC(N(8021D010))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021D598) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021D5A8)[] = {
    0x00000009, 0x00000010, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kgr_tex",
    .shape = "kgr_bt01_shape",
    .hit = "kgr_bt01_hit",
    .preBattle = &N(beforeBattle_8021D3B4),
    .postBattle = &N(afterBattle_8021D598),
    .foregroundModelList = N(foregroundModelList_8021D5A8),
};
