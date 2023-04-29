#include "omo_16.h"

#include "../common/ToyTrain.inc.c"

EvtScript N(D_8024262C_DEE4FC) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, omo_16_ENTRY_0)
        EVT_WAIT(140)
        EVT_SWITCH(GB_OMO_TrainDestination)
            EVT_CASE_EQ(0)
                EVT_IF_EQ(AB_OMO_6, 1)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000B)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_IF_EQ(AB_OMO_6, 2)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000C)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_IF_EQ(AB_OMO_6, 3)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000D)
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_IF_EQ(AB_OMO_6, 0)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000A)
                EVT_END_IF
        EVT_END_SWITCH
    EVT_ELSE
        EVT_WAIT(140)
        EVT_SWITCH(GB_OMO_TrainDestination)
            EVT_CASE_EQ(0)
                EVT_IF_EQ(AB_OMO_6, 0)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000A)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_IF_EQ(AB_OMO_6, 1)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000B)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_IF_EQ(AB_OMO_6, 2)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000C)
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_IF_EQ(AB_OMO_6, 3)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000D)
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802428CC_DEE79C) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -2000)
        EVT_SET(LVar0, -2000)
    EVT_END_IF
    EVT_IF_GT(LVar0, 2000)
        EVT_SET(LVar0, 2000)
    EVT_END_IF
    EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, EVT_FLOAT(50.0), LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(D_80242984_DEE854)[] = {
    -1550, EVT_FLOAT(0.0), EVT_FLOAT(90.0), 1550, EVT_FLOAT(0.0),
    -1, -1, -1
};

s32 N(D_802429A4_DEE874)[] = {
    1550, EVT_FLOAT(0.0), EVT_FLOAT(270.0), -1550, EVT_FLOAT(0.0),
    -1, -1, -1
};

API_CALLABLE(N(CheckForSceneSkip)) {
    f32 trainPos = evt_get_float_variable(script, MV_TrainPos);

    script->varTable[0] = 0;
    if (fabsf(trainPos) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_A)) {
        script->varTable[0] = 1;
    }

    if (fabsf(trainPos) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_802429C4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(D_802428CC_DEE79C))
    EVT_EXEC(N(D_8024262C_DEE4FC))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, omo_16_ENTRY_0)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80242984_DEE854)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_THREAD
            EVT_LABEL(10)
            EVT_CALL(N(CheckForSceneSkip))
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(11)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_LT(MV_TrainPos, 1400)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_SWITCH(GB_OMO_TrainDestination)
                EVT_CASE_EQ(0)
                    EVT_CALL(GotoMap, EVT_PTR("omo_06"), omo_06_ENTRY_2)
                EVT_CASE_EQ(1)
                    EVT_CALL(GotoMap, EVT_PTR("omo_08"), omo_08_ENTRY_1)
                EVT_CASE_EQ(2)
                    EVT_CALL(GotoMap, EVT_PTR("omo_10"), omo_10_ENTRY_2)
                EVT_CASE_EQ(3)
                    EVT_CALL(GotoMap, EVT_PTR("omo_03"), omo_03_ENTRY_2)
            EVT_END_SWITCH
            EVT_WAIT(100)
            EVT_RETURN
            EVT_LABEL(11)
            EVT_EXEC_WAIT(N(EVS_TrainUnk_G))
        EVT_END_THREAD
    EVT_ELSE
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802429A4_DEE874)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_THREAD
            EVT_LABEL(30)
            EVT_CALL(N(CheckForSceneSkip))
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(31)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_GT(MV_TrainPos, -1400)
                EVT_GOTO(30)
            EVT_END_IF
            EVT_SWITCH(GB_OMO_TrainDestination)
                EVT_CASE_EQ(0)
                    EVT_CALL(GotoMap, EVT_PTR("omo_03"), omo_03_ENTRY_3)
                EVT_CASE_EQ(1)
                    EVT_CALL(GotoMap, EVT_PTR("omo_06"), omo_06_ENTRY_3)
                EVT_CASE_EQ(2)
                    EVT_CALL(GotoMap, EVT_PTR("omo_08"), omo_08_ENTRY_2)
                EVT_CASE_EQ(3)
                    EVT_CALL(GotoMap, EVT_PTR("omo_10"), omo_10_ENTRY_3)
            EVT_END_SWITCH
            EVT_WAIT(100)
            EVT_RETURN
            EVT_LABEL(31)
            EVT_EXEC_WAIT(N(EVS_TrainUnk_F))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
