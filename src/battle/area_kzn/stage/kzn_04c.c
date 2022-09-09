#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_04c

EvtScript N(80228900) = {
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

EvtScript N(802289CC) = {
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

EvtScript N(80228A7C) = {
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

EvtScript N(beforeBattle_80228C2C) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 39, 0)
    EVT_CALL(SetGroupEnabled, 30, 0)
    EVT_SET(LocalVar(0), 4)
    EVT_SET(LocalVar(1), 0)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 5)
    EVT_SET(LocalVar(1), 1)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 6)
    EVT_SET(LocalVar(1), 2)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 7)
    EVT_SET(LocalVar(1), 3)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 15)
    EVT_SET(LocalVar(1), 4)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 43)
    EVT_SET(LocalVar(1), 7)
    EVT_EXEC(N(80228900))
    EVT_SET(LocalVar(0), 13)
    EVT_SET(LocalVar(1), 8)
    EVT_EXEC(N(802289CC))
    EVT_SET(LocalVar(0), 14)
    EVT_SET(LocalVar(1), 9)
    EVT_EXEC(N(802289CC))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80228DF0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80228E00)[] = {
    0x00000014, 0x00000015, 0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt04_shape",
    .hit = "kzn_bt04_hit",
    .preBattle = &N(beforeBattle_80228C2C),
    .postBattle = &N(afterBattle_80228DF0),
    .foregroundModelList = N(foregroundModelList_80228E00),
};
