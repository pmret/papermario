#include "common.h"
#include "battle/battle.h"
#include "mapfs/kpa_bt13_shape.h"

#define NAMESPACE b_area_kmr_part_3_kpa_01

EvtScript N(EVS_TexPan_Unused) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetTexPanner, LVarA, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, 0x8000)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt13_shape",
    .hit = "kpa_bt13_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
