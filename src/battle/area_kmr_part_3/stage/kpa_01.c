#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kpa_01

EvtSource N(80234CB0) = {
    EVT_SET(LW(10), LW(0))
    EVT_CALL(SetTexPanner, LW(10), 1)
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, 1, 0, LW(0), LW(1))
        EVT_ADD(LW(0), 32768)
        EVT_ADD(LW(1), 0)
        EVT_WAIT_FRAMES(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(beforeBattle_80234D60) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80234D9C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt13_shape",
    .hit = "kpa_bt13_hit",
    .preBattle = N(beforeBattle_80234D60),
    .postBattle = N(afterBattle_80234D9C),
};
