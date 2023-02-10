#include "end_00.h"

EvtScript N(EVS_ParadePhase_Yoshis) = {
    EVT_CHILD_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o119, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 512)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetNpcScale, NPC_RaphaelRaven, EVT_FLOAT(2.0), EVT_FLOAT(2.0), 1)
        EVT_LOOP(0)
            EVT_CALL(NpcFlyTo, NPC_RaphaelRaven, 357, 0, -30, 10, 0, EASING_LINEAR)
            EVT_WAIT(60)
            EVT_CALL(NpcFlyTo, NPC_RaphaelRaven, 357, -120, -30, 10, 0, EASING_LINEAR)
            EVT_WAIT(60)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
        EVT_LOOP(0)
            EVT_WAIT(60)
            EVT_LOOP(10)
                EVT_ADD(LVar0, 5)
                EVT_ADD(LVar1, 5)
                EVT_CALL(SetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(60)
            EVT_LOOP(10)
                EVT_SUB(LVar0, 5)
                EVT_SUB(LVar1, 5)
                EVT_CALL(SetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 800)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
