#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_mac_mac_01

#include "common/UnkFloatFunc005.inc.c"

EvtScript N(80231770) = {
    EVT_SET(LVarA, LVar0)
    EVT_LABEL(0)
    EVT_CALL(N(UnkFloatFunc005), 0)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LVarB)
    EVT_ADD(LVarB, 30)
    EVT_LOOP(LVarB)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RandInt, 5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc005), 3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LVarB)
    EVT_ADD(LVarB, 30)
    EVT_LOOP(LVarB)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80231E00) = {
    EVT_SET(LVarA, LVar0)
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(intTable_802321A4)[] = {
    0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFB, 0xFFFFFFF8,
    0xFFFFFFF8, 0xFFFFFFF9, 0xFFFFFFFA, 0xFFFFFFFC, 0xFFFFFFFE, 0xFFFFFFFF, 0x00000000, 0x000000FF,
};

EvtScript N(802321E4) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVar5, 5)
    EVT_USE_BUF(EVT_PTR(N(intTable_802321A4)))
    EVT_LABEL(0)
    EVT_BUF_READ1(LVar1)
    EVT_IF_EQ(LVar1, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_802321A4)))
        EVT_BUF_READ1(LVar1)
    EVT_END_IF
    EVT_SET(LVar0, LVar5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar5, 1)
    EVT_SET(LVarC, LVarB)
    EVT_SUB(LVarC, 20)
    EVT_IF_GT(LVar5, LVarC)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LVar0, LVar5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar5, 1)
    EVT_SET(LVarC, LVarB)
    EVT_SUB(LVarC, 20)
    EVT_IF_GT(LVar5, LVarC)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_SET(LVar2, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar5, 1)
        EVT_SUB(LVar1, 2)
        EVT_SET(LVar0, LVar5)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SUB(LVar5, 280)
    EVT_SET(LVar1, 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80232450) = {
    EVT_SET(LVarA, LVar0)
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_802327F4) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 44)
        EVT_EXEC(N(80231E00))
        EVT_WAIT(5)
        EVT_SET(LVar0, 47)
        EVT_EXEC(N(80231E00))
        EVT_WAIT(5)
        EVT_SET(LVar0, 46)
        EVT_EXEC(N(80231E00))
        EVT_WAIT(5)
        EVT_SET(LVar0, 45)
        EVT_EXEC(N(80231E00))
    EVT_END_THREAD
    EVT_SET(LVar0, 40)
    EVT_EXEC(N(80231770))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802328F0) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_802327F4),
    .postBattle = &N(afterBattle_802328F0),
};
