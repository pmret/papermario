#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_04

EvtScript N(80232970) = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetTexPanner, LW(0), LW(1))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LW(10), 0, LW(0), LW(1))
        EVT_ADD(LW(0), LW(11))
        EVT_ADD(LW(1), LW(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80232A40) = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetTexPanner, LW(0), LW(1))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LW(10), 0, LW(0), 0)
        EVT_CALL(SetTexPanOffset, LW(10), 1, LW(1), 0)
        EVT_ADD(LW(0), LW(11))
        EVT_ADD(LW(1), LW(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80232B2C) = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetTexPanner, LW(0), LW(1))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LW(10), 0, 0, LW(0))
        EVT_CALL(SetTexPanOffset, LW(10), 1, 0, LW(1))
        EVT_ADD(LW(0), LW(11))
        EVT_ADD(LW(1), LW(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80232C18) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LW(0), 13)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 40)
    EVT_SET(LW(3), 0)
    EVT_EXEC(N(80232970))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232CA0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232CB0)[] = {
    0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt04_shape",
    .hit = "trd_bt04_hit",
    .preBattle = &N(beforeBattle_80232C18),
    .postBattle = &N(afterBattle_80232CA0),
    .foregroundModelList = N(foregroundModelList_80232CB0),
};
