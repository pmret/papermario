#include "battle/battle.h"

EvtScript N(EVS_TexPan_Lava) = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_AUX, LVar1, 0)
        EVT_SUB(LVar0, -300)
        EVT_SUB(LVar1, -500)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexAnim_LavaBubble) = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, 0x4000)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MovingPlatform) = {
    EVT_SET(LVarA, LVar0) // modelID
    EVT_SET(LVar9, LVar1) // start X
    EVT_SET(LVar8, LVar2) // end X
    EVT_SET(LVar7, LVar3) // move time
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
