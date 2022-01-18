#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_04

EvtScript N(80227DE0) = {
    EVT_SET(LW(10), LW(1))
    EVT_CALL(SetTexPanner, LW(0), LW(1))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LW(10), 0, LW(0), 0)
        EVT_CALL(SetTexPanOffset, LW(10), 1, LW(1), 0)
        EVT_SUB(LW(0), -300)
        EVT_SUB(LW(1), -500)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80227EAC) = {
    EVT_SET(LW(10), LW(1))
    EVT_CALL(SetTexPanner, LW(0), LW(1))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LW(10), 0, LW(0), LW(1))
        EVT_ADD(LW(0), 16384)
        EVT_ADD(LW(1), 0)
        EVT_WAIT_FRAMES(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80227F5C) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(9), LW(1))
    EVT_SET(LW(8), LW(2))
    EVT_SET(LW(7), LW(3))
    EVT_LABEL(0)
    EVT_SET(LW(2), LW(8))
    EVT_ADD(LW(2), LW(9))
    EVT_CALL(MakeLerp, LW(8), LW(2), LW(7), 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LW(10), LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LW(2), LW(8))
    EVT_ADD(LW(2), LW(9))
    EVT_CALL(MakeLerp, LW(2), LW(8), LW(7), 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LW(10), LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8022810C) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 30, 0)
    EVT_CALL(SetGroupEnabled, 44, 0)
    EVT_SET(LW(0), 4)
    EVT_SET(LW(1), 0)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 5)
    EVT_SET(LW(1), 1)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 6)
    EVT_SET(LW(1), 2)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 7)
    EVT_SET(LW(1), 3)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 15)
    EVT_SET(LW(1), 4)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 32)
    EVT_SET(LW(1), 5)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 33)
    EVT_SET(LW(1), 6)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 43)
    EVT_SET(LW(1), 7)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LW(0), 13)
    EVT_SET(LW(1), 8)
    EVT_EXEC(N(80227EAC))
    EVT_SET(LW(0), 14)
    EVT_SET(LW(1), 9)
    EVT_EXEC(N(80227EAC))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80228328) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80228338)[] = {
    0x00000014, 0x00000015, 0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt04_shape",
    .hit = "kzn_bt04_hit",
    .preBattle = N(beforeBattle_8022810C),
    .postBattle = N(afterBattle_80228328),
    .foregroundModelList = N(foregroundModelList_80228338),
};
