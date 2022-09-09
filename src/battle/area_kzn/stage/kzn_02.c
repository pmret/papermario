#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_02

EvtScript N(802278B0) = {
    EVT_SET(LVarA, LocalVar(1))
    EVT_CALL(SetTexPanner, LocalVar(0), LocalVar(1))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LocalVar(0), 0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, LocalVar(1), 0)
        EVT_SUB(LocalVar(0), -300)
        EVT_SUB(LocalVar(1), -500)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8022797C) = {
    EVT_SET(LVarA, LocalVar(1))
    EVT_CALL(SetTexPanner, LocalVar(0), LocalVar(1))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LocalVar(0), LocalVar(1))
        EVT_ADD(LocalVar(0), 16384)
        EVT_ADD(LocalVar(1), 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80227A2C) = {
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LocalVar(9), LocalVar(1))
    EVT_SET(LocalVar(8), LocalVar(2))
    EVT_SET(LocalVar(7), LocalVar(3))
    EVT_LABEL(0)
    EVT_SET(LocalVar(2), LocalVar(8))
    EVT_ADD(LocalVar(2), LocalVar(9))
    EVT_CALL(MakeLerp, LocalVar(8), LocalVar(2), LocalVar(7), 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, LocalVar(0), 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LocalVar(2), LocalVar(8))
    EVT_ADD(LocalVar(2), LocalVar(9))
    EVT_CALL(MakeLerp, LocalVar(2), LocalVar(8), LocalVar(7), 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVarA, LocalVar(0), 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80227BDC) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LocalVar(0), 25)
    EVT_SET(LocalVar(1), 0)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 6)
    EVT_SET(LocalVar(1), 1)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 7)
    EVT_SET(LocalVar(1), 2)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 9)
    EVT_SET(LocalVar(1), 3)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 10)
    EVT_SET(LocalVar(1), 4)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 12)
    EVT_SET(LocalVar(1), 5)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 13)
    EVT_SET(LocalVar(1), 6)
    EVT_EXEC(N(802278B0))
    EVT_SET(LocalVar(0), 24)
    EVT_SET(LocalVar(1), 180)
    EVT_SET(LocalVar(2), 0)
    EVT_SET(LocalVar(3), 200)
    EVT_EXEC(N(80227A2C))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227D98) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227DA8)[] = {
    0x0000001E, 0x0000001F, 0x00000020, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt02_shape",
    .hit = "kzn_bt02_hit",
    .preBattle = &N(beforeBattle_80227BDC),
    .postBattle = &N(afterBattle_80227D98),
    .foregroundModelList = N(foregroundModelList_80227DA8),
};
