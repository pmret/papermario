#include "omo_10.h"

#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80243AC0_DDB470) = {
    10, -105
};

s32 N(D_80243AC8_DDB478)[] = {
    EVT_FLOAT(-2.266),   EVT_FLOAT(-209.494), EVT_FLOAT(90.0),
    EVT_FLOAT(124.202),  EVT_FLOAT(-209.494), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(479.165),  EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243AF8_DDB4A8) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 3)
    EVT_SET(LVar0, EVT_PTR(N(D_80243AC8_DDB478)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80243AC8_DDB478)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_LT(MV_TrainPos, 350)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_0)
    EVT_SET(GB_OMO_TrainDestination, 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80243C68_DDB618)[] = {
    EVT_FLOAT(-2.266),   EVT_FLOAT(-209.494), EVT_FLOAT(270.0),
    EVT_FLOAT(-128.733), EVT_FLOAT(-209.494), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(-353.418), EVT_FLOAT(-353.688),
    EVT_FLOAT(-479.165), EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243CA0_DDB650) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 3)
    EVT_SET(LVar0, EVT_PTR(N(D_80243C68_DDB618)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80243C68_DDB618)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_GT(MV_TrainPos, -350)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_1)
    EVT_SET(GB_OMO_TrainDestination, 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80243E10_DDB7C0)[] = {
    EVT_FLOAT(414.885),  EVT_FLOAT(-426.942), EVT_FLOAT(219.92),
    EVT_FLOAT(353.553),  EVT_FLOAT(-353.553), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(124.202),  EVT_FLOAT(-209.494),
    EVT_FLOAT(-42.27),   EVT_FLOAT(-209.49),
    -1, -1, -1
};

s32 N(D_80243E48_DDB7F8)[] = {
    EVT_FLOAT(414.885),  EVT_FLOAT(-426.942), EVT_FLOAT(219.92),
    EVT_FLOAT(353.553),  EVT_FLOAT(-353.553), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(124.202),  EVT_FLOAT(-209.494),
    EVT_FLOAT(-128.733), EVT_FLOAT(-209.494), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(-353.418), EVT_FLOAT(-353.688),
    EVT_FLOAT(-479.165), EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243E98_DDB848) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(AB_OMO_6, 3)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80243E10_DDB7C0)))
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
        EVT_SET(LVar9, EVT_PTR(N(D_80243AC0_DDB470)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0011)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC(N(EVS_TrainUnk_A))
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80243E48_DDB7F8)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_WAIT(1)
        EVT_EXEC(N(EVS_TrainUnk_H))
        EVT_LABEL(20)
        EVT_IF_GT(MV_TrainPos, -350)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_1)
        EVT_SET(GB_OMO_TrainDestination, 2)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80244150_DDBB00)[] = {
    EVT_FLOAT(-414.885), EVT_FLOAT(-426.942), EVT_FLOAT(140.075),
    EVT_FLOAT(-353.418), EVT_FLOAT(-353.688), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(-128.733), EVT_FLOAT(-209.494),
    EVT_FLOAT(37.73), EVT_FLOAT(-209.49),
    -1, -1, -1
};

s32 N(D_80244188_DDBB38)[] = {
    EVT_FLOAT(-414.885), EVT_FLOAT(-426.942), EVT_FLOAT(140.075),
    EVT_FLOAT(-353.418), EVT_FLOAT(-353.688), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(-128.733), EVT_FLOAT(-209.494),
    EVT_FLOAT(124.202),  EVT_FLOAT(-209.494), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(479.165),  EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_802441D0_DDBB80) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(AB_OMO_6, 3)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244150_DDBB00)))
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
        EVT_SET(LVar9, EVT_PTR(N(D_80243AC0_DDB470)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0011)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC(N(EVS_TrainUnk_A))
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80244188_DDBB38)))
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
        EVT_SET(GB_OMO_TrainDestination, 3)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80244488_DDBE38)[] = {
    2, 1, 0,
};

s32 N(D_80244494_DDBE44)[] = {
    0, 1, 2,
};

EvtScript N(D_802444A0_DDBE50) = {
    EVT_IF_EQ(MF_EitherSwitchPressed, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    EVT_ELSE
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            EVT_CALL(ShowChoice, MSG_Choice_0043)
            EVT_IF_NE(LVar0, 3)
                EVT_CALL(CloseMessage)
                EVT_USE_BUF(EVT_PTR(N(D_80244488_DDBE38)))
                EVT_ADD(LVar0, 1)
                EVT_LOOP(LVar0)
                    EVT_BUF_READ1(LVar1)
                EVT_END_LOOP
                EVT_SET(AB_OMO_6, LVar1)
                EVT_EXEC_WAIT(N(D_80243CA0_DDB650))
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            EVT_CALL(ShowChoice, MSG_Choice_0042)
            EVT_IF_NE(LVar0, 3)
                EVT_CALL(CloseMessage)
                EVT_USE_BUF(EVT_PTR(N(D_80244494_DDBE44)))
                EVT_ADD(LVar0, 1)
                EVT_LOOP(LVar0)
                    EVT_BUF_READ1(LVar1)
                EVT_END_LOOP
                EVT_SET(AB_OMO_6, LVar1)
                EVT_EXEC_WAIT(N(D_80243AF8_DDB4A8))
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_802446B8_DDC068)[] = {
    EVT_FLOAT(-2.266), EVT_FLOAT(-209.494), EVT_FLOAT(90.0),
    -1, -1, -1
};

EvtScript N(EVS_SetupTrain) = {
    EVT_EXEC_WAIT(N(EVS_SetupSwitches))
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802446B8_DDC068)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(omo_10_ENTRY_2)
                EVT_EXEC(N(D_802441D0_DDBB80))
            EVT_CASE_EQ(omo_10_ENTRY_3)
                EVT_EXEC(N(D_80243E98_DDB848))
            EVT_CASE_DEFAULT
                EVT_SET(MV_TrainUnk_00, 0)
                EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802446B8_DDC068)))
                EVT_SET(MV_TrainUnk_02, 0)
                EVT_EXEC(N(EVS_Scene_RideTrain))
                EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
