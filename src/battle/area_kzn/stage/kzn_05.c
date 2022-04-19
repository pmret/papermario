#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_05

EvtScript N(80228E40) = {
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

EvtScript N(80228F0C) = {
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

EvtScript N(80228FBC) = {
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

EvtScript N(beforeBattle_8022916C) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LW(0), 17)
    EVT_SET(LW(1), 0)
    EVT_EXEC(N(80228E40))
    EVT_SET(LW(0), 15)
    EVT_SET(LW(1), 1)
    EVT_EXEC(N(80228E40))
    EVT_SET(LW(0), 10)
    EVT_SET(LW(1), 2)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LW(0), 11)
    EVT_SET(LW(1), 3)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LW(0), 26)
    EVT_SET(LW(1), 4)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LW(0), 27)
    EVT_SET(LW(1), 5)
    EVT_EXEC(N(80228F0C))
    EVT_CALL(EnableModel, 29, 0)
    EVT_CALL(EnableModel, 30, 0)
    EVT_CALL(EnableModel, 31, 0)
    EVT_CALL(EnableModel, 32, 0)
    EVT_CALL(EnableModel, 33, 0)
    EVT_CALL(EnableModel, 34, 0)
    EVT_CALL(EnableModel, 35, 0)
    EVT_CALL(EnableModel, 36, 0)
    EVT_CALL(EnableModel, 37, 0)
    EVT_CALL(EnableModel, 38, 0)
    EVT_CALL(EnableModel, 39, 0)
    EVT_CALL(EnableModel, 40, 0)
    EVT_CALL(EnableModel, 41, 0)
    EVT_CALL(EnableModel, 42, 0)
    EVT_CALL(EnableModel, 43, 0)
    EVT_CALL(EnableModel, 44, 0)
    EVT_CALL(EnableModel, 45, 0)
    EVT_CALL(EnableModel, 46, 0)
    EVT_CALL(EnableModel, 47, 0)
    EVT_CALL(EnableModel, 48, 0)
    EVT_CALL(EnableModel, 49, 0)
    EVT_CALL(EnableModel, 50, 0)
    EVT_CALL(EnableModel, 51, 0)
    EVT_CALL(EnableModel, 52, 0)
    EVT_CALL(EnableModel, 53, 0)
    EVT_CALL(EnableModel, 54, 0)
    EVT_CALL(EnableModel, 55, 0)
    EVT_CALL(EnableModel, 56, 0)
    EVT_CALL(EnableModel, 57, 0)
    EVT_CALL(EnableModel, 58, 0)
    EVT_CALL(EnableModel, 59, 0)
    EVT_CALL(EnableModel, 60, 0)
    EVT_CALL(EnableModel, 61, 0)
    EVT_CALL(EnableModel, 62, 0)
    EVT_CALL(EnableModel, 63, 0)
    EVT_CALL(EnableModel, 64, 0)
    EVT_CALL(EnableModel, 65, 0)
    EVT_CALL(EnableModel, 66, 0)
    EVT_CALL(EnableModel, 67, 0)
    EVT_CALL(EnableModel, 68, 0)
    EVT_CALL(EnableModel, 69, 0)
    EVT_CALL(EnableModel, 70, 0)
    EVT_CALL(EnableModel, 71, 0)
    EVT_CALL(EnableModel, 72, 0)
    EVT_CALL(EnableModel, 73, 0)
    EVT_CALL(EnableModel, 74, 0)
    EVT_CALL(EnableModel, 75, 0)
    EVT_CALL(EnableModel, 76, 0)
    EVT_CALL(EnableModel, 78, 0)
    EVT_CALL(EnableModel, 79, 0)
    EVT_CALL(EnableModel, 80, 0)
    EVT_CALL(EnableModel, 81, 0)
    EVT_CALL(EnableModel, 82, 0)
    EVT_CALL(EnableModel, 83, 0)
    EVT_CALL(EnableModel, 84, 0)
    EVT_CALL(EnableModel, 85, 0)
    EVT_CALL(EnableModel, 86, 0)
    EVT_CALL(EnableModel, 87, 0)
    EVT_CALL(EnableModel, 88, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022974C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt05_shape",
    .hit = "kzn_bt05_hit",
    .preBattle = &N(beforeBattle_8022916C),
    .postBattle = &N(afterBattle_8022974C),
};
