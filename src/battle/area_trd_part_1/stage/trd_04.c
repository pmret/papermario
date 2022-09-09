#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_04

EvtScript N(80223FF0) = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetTexPanner, LocalVar(0), LocalVar(1))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LocalVar(10), 0, LocalVar(0), LocalVar(1))
        EVT_ADD(LocalVar(0), LocalVar(11))
        EVT_ADD(LocalVar(1), LocalVar(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802240C0) = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetTexPanner, LocalVar(0), LocalVar(1))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LocalVar(10), 0, LocalVar(0), 0)
        EVT_CALL(SetTexPanOffset, LocalVar(10), 1, LocalVar(1), 0)
        EVT_ADD(LocalVar(0), LocalVar(11))
        EVT_ADD(LocalVar(1), LocalVar(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802241AC) = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetTexPanner, LocalVar(0), LocalVar(1))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LocalVar(10), 0, 0, LocalVar(0))
        EVT_CALL(SetTexPanOffset, LocalVar(10), 1, 0, LocalVar(1))
        EVT_ADD(LocalVar(0), LocalVar(11))
        EVT_ADD(LocalVar(1), LocalVar(12))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80224298) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LocalVar(0), 13)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 40)
    EVT_SET(LocalVar(3), 0)
    EVT_EXEC(N(80223FF0))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80224320) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80224330)[] = {
    0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt04_shape",
    .hit = "trd_bt04_hit",
    .preBattle = &N(beforeBattle_80224298),
    .postBattle = &N(afterBattle_80224320),
    .foregroundModelList = N(foregroundModelList_80224330),
};
