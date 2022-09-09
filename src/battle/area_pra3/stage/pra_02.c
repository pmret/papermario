#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt02_shape.h"

#define NAMESPACE b_area_pra3_pra_02

EvtScript N(80231B40) = {
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

EvtScript N(80231C10) = {
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

EvtScript N(80231CFC) = {
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
    EVT_CALL(func_802536A8, 1)
    EVT_SET(LocalVar(0), 17)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 3000)
    EVT_SET(LocalVar(3), 0)
    EVT_EXEC(N(80231B40))
    EVT_SET(LocalVar(0), 18)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 3000)
    EVT_SET(LocalVar(3), 0)
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
