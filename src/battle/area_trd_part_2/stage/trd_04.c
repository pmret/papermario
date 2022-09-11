#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_04

EvtScript N(80232970) = {
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

EvtScript N(80232A40) = {
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

EvtScript N(80232B2C) = {
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

EvtScript N(beforeBattle_80232C18) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LVar0, 13)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 40)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(80232970))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232CA0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232CB0)[] = {
    0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt04_shape",
    .hit = "trd_bt04_hit",
    .preBattle = &N(beforeBattle_80232C18),
    .postBattle = &N(afterBattle_80232CA0),
    .foregroundModelList = N(foregroundModelList_80232CB0),
};
