#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa_kpa_04c

EvtScript N(8022FC20) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetTexPanner, LVarA, 1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, 1, 0, LVar0, LVar1)
        EVT_ADD(LVar0, 32768)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 30, 0)
    EVT_CALL(SetGroupEnabled, 39, 0)
    EVT_CALL(SetGroupEnabled, 38, 0)
    EVT_CALL(SetGroupEnabled, 36, 0)
    EVT_CALL(SetGroupEnabled, 34, 0)
    EVT_CALL(SetGroupEnabled, 32, 0)
    EVT_SET(LVar0, 18)
    EVT_EXEC(N(8022FC20))
    EVT_SET(LVar0, 20)
    EVT_EXEC(N(8022FC20))
    EVT_SET(LVar0, 22)
    EVT_EXEC(N(8022FC20))
    EVT_SET(LVar0, 24)
    EVT_EXEC(N(8022FC20))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt04_shape",
    .hit = "kpa_bt04_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
