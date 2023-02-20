#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt04_shape.h"

#define NAMESPACE b_area_pra_pra_04

EvtScript N(EVS_TexPan_Glass) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802321A0) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  LVar1, 0)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8023228C) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, 0, LVar0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_kira1)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, 3000)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexPan_Glass))
    EVT_SET(LVar0, MODEL_kira2)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_SET(LVar2, 3000)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexPan_Glass))
    EVT_CALL(EnableBattleFloorReflections, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt04_shape",
    .hit = "pra_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
