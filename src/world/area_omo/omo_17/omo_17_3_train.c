#include "omo_17.h"

#include "../common/ToyTrain.inc.c"

EvtScript N(D_80245CEC_DF4B8C) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -600)
            EVT_SET(LVar0, -600)
        EVT_END_IF
        EVT_IF_GT(LVar0, 600)
            EVT_SET(LVar0, 600)
        EVT_END_IF
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, EVT_FLOAT(50.0), LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(EVS_TrainPath_LeftToRight)[] = {
    EVT_FLOAT(-720.0), EVT_FLOAT(0.0), EVT_FLOAT(90.0),
    EVT_FLOAT(720.0), EVT_FLOAT(0.0),
    -1, -1, -1,
};

s32 N(EVS_TrainPath_RightToLeft)[] = {
    EVT_FLOAT(720.0), EVT_FLOAT(0.0), EVT_FLOAT(270.0),
    EVT_FLOAT(-720.0), EVT_FLOAT(0.0),
    -1, -1, -1,
};

EvtScript N(EVS_EnterTrain) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_p1, MODEL_o1)
    EVT_CALL(ParentColliderToModel, COLLIDER_pp1, MODEL_o1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(D_80245CEC_DF4B8C))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(omo_17_ENTRY_4)
            EVT_SET(MV_TrainUnk_00, 0)
            EVT_SET(MV_TrainUnk_01, EVT_PTR(N(EVS_TrainPath_LeftToRight)))
            EVT_SET(MV_TrainUnk_02, 0)
            EVT_EXEC(N(EVS_Scene_RideTrain))
            EVT_SET(MF_TrainUnk_00, TRUE)
            EVT_THREAD
                EVT_LABEL(10)
                EVT_IF_LT(MV_TrainPos, 600)
                    EVT_WAIT(1)
                    EVT_GOTO(10)
                EVT_END_IF
                EVT_CALL(GotoMap, EVT_PTR("omo_06"), omo_06_ENTRY_0)
                EVT_WAIT(100)
            EVT_END_THREAD
        EVT_CASE_EQ(omo_17_ENTRY_5)
            EVT_SET(MV_TrainUnk_00, 0)
            EVT_SET(MV_TrainUnk_01, EVT_PTR(N(EVS_TrainPath_RightToLeft)))
            EVT_SET(MV_TrainUnk_02, 0)
            EVT_EXEC(N(EVS_Scene_RideTrain))
            EVT_SET(MF_TrainUnk_00, TRUE)
            EVT_THREAD
                EVT_LABEL(20)
                EVT_IF_GT(MV_TrainPos, -600)
                    EVT_WAIT(1)
                    EVT_GOTO(20)
                EVT_END_IF
                EVT_CALL(GotoMap, EVT_PTR("omo_05"), omo_05_ENTRY_1)
                EVT_WAIT(100)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, strings);
