#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_05

EvtScript N(80228E40) = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, LVar1, 0)
        EVT_SUB(LVar0, -300)
        EVT_SUB(LVar1, -500)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80228F0C) = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, LVar1)
        EVT_ADD(LVar0, 16384)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80228FBC) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_LABEL(0)
    EVT_SET(LVar2, LVar8)
    EVT_ADD(LVar2, LVar9)
    EVT_CALL(MakeLerp, LVar8, LVar2, LVar7, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar2, LVar8)
    EVT_ADD(LVar2, LVar9)
    EVT_CALL(MakeLerp, LVar2, LVar8, LVar7, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, LVar0, 0, 0)
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
    EVT_SET(LVar0, 17)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(80228E40))
    EVT_SET(LVar0, 15)
    EVT_SET(LVar1, 1)
    EVT_EXEC(N(80228E40))
    EVT_SET(LVar0, 10)
    EVT_SET(LVar1, 2)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LVar0, 11)
    EVT_SET(LVar1, 3)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LVar0, 26)
    EVT_SET(LVar1, 4)
    EVT_EXEC(N(80228F0C))
    EVT_SET(LVar0, 27)
    EVT_SET(LVar1, 5)
    EVT_EXEC(N(80228F0C))
    EVT_CALL(EnableModel, 29, FALSE)
    EVT_CALL(EnableModel, 30, FALSE)
    EVT_CALL(EnableModel, 31, FALSE)
    EVT_CALL(EnableModel, 32, FALSE)
    EVT_CALL(EnableModel, 33, FALSE)
    EVT_CALL(EnableModel, 34, FALSE)
    EVT_CALL(EnableModel, 35, FALSE)
    EVT_CALL(EnableModel, 36, FALSE)
    EVT_CALL(EnableModel, 37, FALSE)
    EVT_CALL(EnableModel, 38, FALSE)
    EVT_CALL(EnableModel, 39, FALSE)
    EVT_CALL(EnableModel, 40, FALSE)
    EVT_CALL(EnableModel, 41, FALSE)
    EVT_CALL(EnableModel, 42, FALSE)
    EVT_CALL(EnableModel, 43, FALSE)
    EVT_CALL(EnableModel, 44, FALSE)
    EVT_CALL(EnableModel, 45, FALSE)
    EVT_CALL(EnableModel, 46, FALSE)
    EVT_CALL(EnableModel, 47, FALSE)
    EVT_CALL(EnableModel, 48, FALSE)
    EVT_CALL(EnableModel, 49, FALSE)
    EVT_CALL(EnableModel, 50, FALSE)
    EVT_CALL(EnableModel, 51, FALSE)
    EVT_CALL(EnableModel, 52, FALSE)
    EVT_CALL(EnableModel, 53, FALSE)
    EVT_CALL(EnableModel, 54, FALSE)
    EVT_CALL(EnableModel, 55, FALSE)
    EVT_CALL(EnableModel, 56, FALSE)
    EVT_CALL(EnableModel, 57, FALSE)
    EVT_CALL(EnableModel, 58, FALSE)
    EVT_CALL(EnableModel, 59, FALSE)
    EVT_CALL(EnableModel, 60, FALSE)
    EVT_CALL(EnableModel, 61, FALSE)
    EVT_CALL(EnableModel, 62, FALSE)
    EVT_CALL(EnableModel, 63, FALSE)
    EVT_CALL(EnableModel, 64, FALSE)
    EVT_CALL(EnableModel, 65, FALSE)
    EVT_CALL(EnableModel, 66, FALSE)
    EVT_CALL(EnableModel, 67, FALSE)
    EVT_CALL(EnableModel, 68, FALSE)
    EVT_CALL(EnableModel, 69, FALSE)
    EVT_CALL(EnableModel, 70, FALSE)
    EVT_CALL(EnableModel, 71, FALSE)
    EVT_CALL(EnableModel, 72, FALSE)
    EVT_CALL(EnableModel, 73, FALSE)
    EVT_CALL(EnableModel, 74, FALSE)
    EVT_CALL(EnableModel, 75, FALSE)
    EVT_CALL(EnableModel, 76, FALSE)
    EVT_CALL(EnableModel, 78, FALSE)
    EVT_CALL(EnableModel, 79, FALSE)
    EVT_CALL(EnableModel, 80, FALSE)
    EVT_CALL(EnableModel, 81, FALSE)
    EVT_CALL(EnableModel, 82, FALSE)
    EVT_CALL(EnableModel, 83, FALSE)
    EVT_CALL(EnableModel, 84, FALSE)
    EVT_CALL(EnableModel, 85, FALSE)
    EVT_CALL(EnableModel, 86, FALSE)
    EVT_CALL(EnableModel, 87, FALSE)
    EVT_CALL(EnableModel, 88, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt05_shape",
    .hit = "kzn_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
