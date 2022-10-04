#include "common.h"
#include "battle/battle.h"
#include "mapfs/omo_bt06_shape.h"

#define NAMESPACE b_area_omo3_omo_06

EvtScript N(updateModels) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_LABEL(0)
    EVT_CALL(MakeLerp, 0, LVar9, LVar8, 10)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LVar9, 0, LVar8, 10)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 26)
        EVT_SET(LVar1, -50)
        EVT_SET(LVar2, 120)
        EVT_EXEC(N(updateModels))
        EVT_WAIT(10)
        EVT_SET(LVar0, 30)
        EVT_SET(LVar1, -80)
        EVT_SET(LVar2, 150)
        EVT_EXEC(N(updateModels))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_kuruma, MODEL_hosi, 0,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt06_shape",
    .hit = "omo_bt06_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
