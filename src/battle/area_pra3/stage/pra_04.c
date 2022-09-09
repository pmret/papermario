#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_pra3_pra_04

EvtScript N(802320D0) = {
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

EvtScript N(802321A0) = {
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

EvtScript N(8023228C) = {
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

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LW(0), 1)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 3000)
    EVT_SET(LW(3), 0)
    EVT_EXEC(N(802320D0))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 1)
    EVT_SET(LW(2), 3000)
    EVT_SET(LW(3), 0)
    EVT_EXEC(N(802320D0))
    EVT_CALL(func_802536A8, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt04_shape",
    .hit = "pra_bt04_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
