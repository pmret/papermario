#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa4_kpa_04

EvtScript N(8022F7F0) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetTexPanner, LVarA, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, 32768)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 15, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 17, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 16, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 26, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 18, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 20, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 22, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 24, MODEL_GROUP_HIDDEN)
    EVT_SET(LVar0, 32)
    EVT_EXEC(N(8022F7F0))
    EVT_SET(LVar0, 34)
    EVT_EXEC(N(8022F7F0))
    EVT_SET(LVar0, 36)
    EVT_EXEC(N(8022F7F0))
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
