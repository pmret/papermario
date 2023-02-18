#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn2_kzn_04

EvtScript N(80227DE0) = {
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

EvtScript N(80227EAC) = {
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

EvtScript N(80227F5C) = {
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
    EVT_CALL(SetGroupVisibility, 30, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 44, MODEL_GROUP_HIDDEN)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 5)
    EVT_SET(LVar1, 1)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 6)
    EVT_SET(LVar1, 2)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 7)
    EVT_SET(LVar1, 3)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 15)
    EVT_SET(LVar1, 4)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 32)
    EVT_SET(LVar1, 5)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 33)
    EVT_SET(LVar1, 6)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 43)
    EVT_SET(LVar1, 7)
    EVT_EXEC(N(80227DE0))
    EVT_SET(LVar0, 13)
    EVT_SET(LVar1, 8)
    EVT_EXEC(N(80227EAC))
    EVT_SET(LVar0, 14)
    EVT_SET(LVar1, 9)
    EVT_EXEC(N(80227EAC))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0x00000014,
    0x00000015,
    0x00000016,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt04_shape",
    .hit = "kzn_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
