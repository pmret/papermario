#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt02_shape.h"

#define NAMESPACE b_area_pra3_pra_02

EvtScript N(80231B40) = {
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

EvtScript N(80231C10) = {
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

EvtScript N(80231CFC) = {
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
    EVT_CALL(func_802536A8, 1)
    EVT_SET(LW(0), 17)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 3000)
    EVT_SET(LW(3), 0)
    EVT_EXEC(N(80231B40))
    EVT_SET(LW(0), 18)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 3000)
    EVT_SET(LW(3), 0)
    EVT_EXEC(N(80231B40))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_o383, MODEL_o384, MODEL_o385, 0,
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt02_shape",
    .hit = "pra_bt02_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
