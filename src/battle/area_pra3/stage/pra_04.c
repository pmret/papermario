#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_pra3_pra_04

EvtScript N(802320D0) = {
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

EvtScript N(802321A0) = {
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

EvtScript N(8023228C) = {
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

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LocalVar(0), 1)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 3000)
    EVT_SET(LocalVar(3), 0)
    EVT_EXEC(N(802320D0))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 1)
    EVT_SET(LocalVar(2), 3000)
    EVT_SET(LocalVar(3), 0)
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
