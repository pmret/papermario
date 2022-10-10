#include "common.h"
#include "battle/battle.h"
#include "mapfs/kpa_bt01_shape.h"

#define NAMESPACE b_area_kpa4_kpa_01b

EvtScript N(8022F180) = {
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
    EVT_CALL(SetGroupEnabled, 25, 0)
    EVT_SET(LVar0, 37)
    EVT_EXEC(N(8022F180))
    EVT_SET(LVar0, 39)
    EVT_EXEC(N(8022F180))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_o383, MODEL_o382, MODEL_o381, 0,
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt01_shape",
    .hit = "kpa_bt01_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
