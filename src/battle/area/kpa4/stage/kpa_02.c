#include "common.h"
#include "battle/battle.h"
#include "mapfs/kpa_bt02_shape.h"

#define NAMESPACE b_area_kpa4_kpa_02

EvtScript N(8022F300) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F3D0) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, LVar1, 0)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F4BC) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, 0, LVar0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, 0, LVar1)
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
    EVT_SET(LVar0, 16)
    EVT_SET(LVar1, 1)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(8022F3D0))
    EVT_SET(LVar0, 19)
    EVT_SET(LVar1, 3)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(8022F3D0))
    EVT_SET(LVar0, 17)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(8022F4BC))
    EVT_SET(LVar0, 18)
    EVT_SET(LVar1, 2)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(8022F4BC))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_saku,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt02_shape",
    .hit = "kpa_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
