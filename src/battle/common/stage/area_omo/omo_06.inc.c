#include "battle/battle.h"
#include "mapfs/omo_bt06_shape.h"

#define NAMESPACE A(omo_06)

EvtScript N(EVS_UpdateMovingPlatforms) = {
    EVT_SET(LVarA, LVar0) // modelID
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, LVar9, LVar8, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVarA, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, LVar9, 0, LVar8, EASING_COS_IN_OUT)
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

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_ere1)
        EVT_SET(LVar1, -50)
        EVT_SET(LVar2, 120)
        EVT_EXEC(N(EVS_UpdateMovingPlatforms))
        EVT_WAIT(10)
        EVT_SET(LVar0, MODEL_ere2)
        EVT_SET(LVar1, -80)
        EVT_SET(LVar2, 150)
        EVT_EXEC(N(EVS_UpdateMovingPlatforms))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_kuruma,
    MODEL_hosi,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt06_shape",
    .hit = "omo_bt06_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
