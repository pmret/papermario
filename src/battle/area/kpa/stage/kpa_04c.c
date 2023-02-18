#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa_kpa_04c

EvtScript N(8022FC20) = {
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

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 30, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 39, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 38, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 36, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 34, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 32, MODEL_GROUP_HIDDEN)
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

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt04_shape",
    .hit = "kpa_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
