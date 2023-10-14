#include "omo_06.h"

#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80244160_DBBA70) = {
    50, 45
};

s32 N(D_80244168_DBBA78)[] = {
    EVT_FLOAT(-1.825), EVT_FLOAT(-35.275), EVT_FLOAT(66.038),
    EVT_FLOAT(162.917), EVT_FLOAT(-108.494), EVT_FLOAT(353.442),
    EVT_FLOAT(-353.717), EVT_FLOAT(414.885), EVT_FLOAT(-426.942),
    -1, -1, -1
};

EvtScript N(D_80244198_DBBAA8) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 1)
    EVT_SET(LVar0, EVT_PTR(N(D_80244168_DBBA78)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244168_DBBA78)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_LT(MV_TrainPos, 350)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_0)
    EVT_SET(GB_OMO_TrainDestination, 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80244308_DBBC18)[] = {
    EVT_FLOAT(-1.825), EVT_FLOAT(-35.275), EVT_FLOAT(246.038),
    EVT_FLOAT(-166.506), EVT_FLOAT(37.917), EVT_FLOAT(-500.0),
    EVT_FLOAT(0.279), EVT_FLOAT(-600.0), EVT_FLOAT(0.558),
    -1, -1, -1
};

EvtScript N(D_80244338_DBBC48) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 1)
    EVT_SET(LVar0, EVT_PTR(N(D_80244308_DBBC18)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244308_DBBC18)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_GT(MV_TrainPos, -480)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_1)
    EVT_SET(GB_OMO_TrainDestination, 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_802444A8_DBBDB8)[] = {
    EVT_FLOAT(414.885),  EVT_FLOAT(-426.942), EVT_FLOAT(219.925),
    EVT_FLOAT(353.442),  EVT_FLOAT(-353.717), EVT_FLOAT(162.917),
    EVT_FLOAT(-108.494), EVT_FLOAT(-38.38),   EVT_FLOAT(-19.05),
    -1, -1, -1
};

s32 N(D_802444D8_DBBDE8)[] = {
    EVT_FLOAT(414.885), EVT_FLOAT(-426.942), EVT_FLOAT(219.925),
    EVT_FLOAT(353.442), EVT_FLOAT(-353.717), EVT_FLOAT(162.917),
    EVT_FLOAT(-108.494), EVT_FLOAT(-166.506), EVT_FLOAT(37.917),
    EVT_FLOAT(-500.0), EVT_FLOAT(0.279), EVT_FLOAT(-600.0),
    EVT_FLOAT(0.558),  -1, -1, -1
};

EvtScript N(D_80244518_DBBE28) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(AB_OMO_6, 1)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802444A8_DBBDB8)))
        EVT_SET(MV_TrainUnk_02, 2)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_WAIT(1)
        EVT_EXEC_GET_TID(N(EVS_TrainUnk_A), LVarB)
        EVT_LABEL(10)
        EVT_IF_EQ(MF_TrainUnk_00, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(20)
        EVT_KILL_THREAD(LVarB)
        EVT_EXEC(N(EVS_TrainUnk_B))
        EVT_CALL(N(EnableCameraFollowPlayerY))
        EVT_SET(LVar9, EVT_PTR(N(D_80244160_DBBA70)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000F)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC(N(EVS_TrainUnk_A))
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802444D8_DBBDE8)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_WAIT(1)
        EVT_EXEC(N(EVS_TrainUnk_H))
        EVT_LABEL(20)
        EVT_IF_GT(MV_TrainPos, -480)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_1)
        EVT_SET(GB_OMO_TrainDestination, 0)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_802447D0_DBC0E0)[] = {
    EVT_FLOAT(-600.0), EVT_FLOAT(0.558), EVT_FLOAT(89.875),
    EVT_FLOAT(-500.0), EVT_FLOAT(0.279), EVT_FLOAT(-166.506),
    EVT_FLOAT(37.917), EVT_FLOAT(34.74), EVT_FLOAT(-51.5),
    -1, -1, -1
};

s32 N(D_80244800_DBC110)[] = {
    EVT_FLOAT(-600.0), EVT_FLOAT(0.558), EVT_FLOAT(89.875),
    EVT_FLOAT(-500.0), EVT_FLOAT(0.279), EVT_FLOAT(-166.506),
    EVT_FLOAT(37.917), EVT_FLOAT(162.917), EVT_FLOAT(-108.494),
    EVT_FLOAT(353.442), EVT_FLOAT(-353.717), EVT_FLOAT(414.885),
    EVT_FLOAT(-426.942),
    -1, -1, -1
};

EvtScript N(D_80244840_DBC150) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(AB_OMO_6, 1)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802447D0_DBC0E0)))
        EVT_SET(MV_TrainUnk_02, 2)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_WAIT(1)
        EVT_EXEC_GET_TID(N(EVS_TrainUnk_A), LVarB)
        EVT_LABEL(10)
        EVT_IF_EQ(MF_TrainUnk_00, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(20)
        EVT_KILL_THREAD(LVarB)
        EVT_EXEC(N(EVS_TrainUnk_B))
        EVT_CALL(N(EnableCameraFollowPlayerY))
        EVT_SET(LVar9, EVT_PTR(N(D_80244160_DBBA70)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000F)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC(N(EVS_TrainUnk_A))
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244800_DBC110)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_WAIT(1)
        EVT_EXEC(N(EVS_TrainUnk_H))
        EVT_LABEL(20)
        EVT_IF_LT(MV_TrainPos, 350)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_0)
        EVT_SET(GB_OMO_TrainDestination, 1)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80244AF8_DBC408)[] = {
    0, 3, 2,
};

s32 N(D_80244B04_DBC414)[] = {
    2, 3, 0,
};

EvtScript N(D_80244B10_DBC420) = {
    EVT_IF_EQ(MF_EitherSwitchPressed, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    EVT_ELSE
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, FALSE)
                EVT_CALL(ShowChoice, MSG_Choice_003D)
                EVT_IF_NE(LVar0, 1)
                    EVT_CALL(CloseMessage)
                    EVT_USE_BUF(EVT_PTR(N(D_80244AF8_DBC408)))
                    EVT_ADD(LVar0, 1)
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ1(LVar1)
                    EVT_END_LOOP
                    EVT_SET(AB_OMO_6, LVar1)
                    EVT_EXEC_WAIT(N(D_80244338_DBBC48))
                EVT_ELSE
                    EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(ShowChoice, MSG_Choice_003E)
                EVT_IF_NE(LVar0, 3)
                    EVT_CALL(CloseMessage)
                    EVT_USE_BUF(EVT_PTR(N(D_80244AF8_DBC408)))
                    EVT_ADD(LVar0, 1)
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ1(LVar1)
                    EVT_END_LOOP
                    EVT_SET(AB_OMO_6, LVar1)
                    EVT_EXEC_WAIT(N(D_80244338_DBBC48))
                EVT_ELSE
                    EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH4_PULLED_SWITCH_SWITCH)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0012)
                EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                    EVT_CALL(ShowChoice, MSG_Choice_003B)
                    EVT_IF_NE(LVar0, 1)
                        EVT_CALL(CloseMessage)
                        EVT_USE_BUF(EVT_PTR(N(D_80244B04_DBC414)))
                        EVT_ADD(LVar0, 1)
                        EVT_LOOP(LVar0)
                            EVT_BUF_READ1(LVar1)
                        EVT_END_LOOP
                        EVT_SET(AB_OMO_6, LVar1)
                        EVT_EXEC_WAIT(N(D_80244198_DBBAA8))
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EVT_END_IF
                EVT_CASE_GE(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                    EVT_CALL(ShowChoice, MSG_Choice_003C)
                    EVT_IF_NE(LVar0, 3)
                        EVT_CALL(CloseMessage)
                        EVT_USE_BUF(EVT_PTR(N(D_80244B04_DBC414)))
                        EVT_ADD(LVar0, 1)
                        EVT_LOOP(LVar0)
                            EVT_BUF_READ1(LVar1)
                        EVT_END_LOOP
                        EVT_SET(AB_OMO_6, LVar1)
                        EVT_EXEC_WAIT(N(D_80244198_DBBAA8))
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80244F28_DBC838)[] = {
    EVT_FLOAT(-1.825), EVT_FLOAT(-35.275), EVT_FLOAT(66.038),
    -1, -1, -1
};

EvtScript N(EVS_80244F40) = {
    EVT_EXEC_WAIT(N(EVS_SetupSwitches))
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244F28_DBC838)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(omo_06_ENTRY_2)
                EVT_EXEC(N(D_80244840_DBC150))
            EVT_CASE_EQ(omo_06_ENTRY_3)
                EVT_EXEC(N(D_80244518_DBBE28))
            EVT_CASE_DEFAULT
                EVT_SET(MV_TrainUnk_00, 0)
                EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244F28_DBC838)))
                EVT_SET(MV_TrainUnk_02, 0)
                EVT_EXEC(N(EVS_Scene_RideTrain))
                EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
