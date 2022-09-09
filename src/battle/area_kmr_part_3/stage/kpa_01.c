#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kpa_01

EvtScript N(80234CB0) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_CALL(SetTexPanner, LocalVar(10), 1)
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, 1, 0, LocalVar(0), LocalVar(1))
        EVT_ADD(LocalVar(0), 32768)
        EVT_ADD(LocalVar(1), 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80234D60) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80234D9C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt13_shape",
    .hit = "kpa_bt13_hit",
    .preBattle = &N(beforeBattle_80234D60),
    .postBattle = &N(afterBattle_80234D9C),
};
