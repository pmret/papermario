#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn2_kzn_04b

EvtScript N(80228370) = {
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

EvtScript N(8022843C) = {
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

EvtScript N(802284EC) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVar8, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_LABEL(0)
    EVT_SET(LVar2, LVar8)
    EVT_ADD(LVar2, LVar9)
    EVT_CALL(MakeLerp, LVar8, LVar2, LVar7, 0)
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
    EVT_CALL(MakeLerp, LVar2, LVar8, LVar7, 0)
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

EvtScript N(beforeBattle_8022869C) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 39, 0)
    EVT_CALL(SetGroupEnabled, 44, 0)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 5)
    EVT_SET(LVar1, 1)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 6)
    EVT_SET(LVar1, 2)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 7)
    EVT_SET(LVar1, 3)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 15)
    EVT_SET(LVar1, 4)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 24)
    EVT_SET(LVar1, 5)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 25)
    EVT_SET(LVar1, 6)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 43)
    EVT_SET(LVar1, 7)
    EVT_EXEC(N(80228370))
    EVT_SET(LVar0, 13)
    EVT_SET(LVar1, 8)
    EVT_EXEC(N(8022843C))
    EVT_SET(LVar0, 14)
    EVT_SET(LVar1, 9)
    EVT_EXEC(N(8022843C))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802288B8) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802288C8)[] = {
    0x00000014, 0x00000015, 0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt04_shape",
    .hit = "kzn_bt04_hit",
    .preBattle = &N(beforeBattle_8022869C),
    .postBattle = &N(afterBattle_802288B8),
    .foregroundModelList = N(foregroundModelList_802288C8),
};
