#include "omo_03.h"

#define INCLUDE_ALTERNATES 1
#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80246080_DAB2C0) = {
    170, -115
};

Vec2i N(D_80246088_DAB2C8) = {
    -383, -240
};

Vec2i N(D_80246090_DAB2D0)[] = {
    { -360, -195 },
    { -335, -215 },
};

s32 N(D_802460A0_DAB2E0)[] = {
    EVT_FLOAT(-298.93), EVT_FLOAT(-288.62), EVT_FLOAT(140.0),
    EVT_FLOAT(-262.5), EVT_FLOAT(-245.336), EVT_FLOAT(0.0),
    EVT_FLOAT(-175.0), EVT_FLOAT(169.89), EVT_FLOAT(-220.49),
    -1, -1, -1
};

s32 N(D_802460D0_DAB310)[] = {
    EVT_FLOAT(-298.93), EVT_FLOAT(-288.62), EVT_FLOAT(140.0),
    EVT_FLOAT(-262.5), EVT_FLOAT(-245.336), EVT_FLOAT(0.0),
    EVT_FLOAT(-175.0), EVT_FLOAT(262.5), EVT_FLOAT(-245.336),
    EVT_FLOAT(479.165), EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(EVS_80246108) = {
    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0014)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(1.0))
            EVT_CALL(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
            EVT_LOOP(2)
                EVT_CALL(NpcJump1, NPC_Conductor, LVar0, LVar1, LVar2, 15)
            EVT_END_LOOP
            EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0015)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC_GET_TID(N(EVS_TrainUnk_C), LVarB)
        EVT_SET(LVar0, EVT_PTR(N(D_802460A0_DAB2E0)))
        EVT_SET(LVar9, EVT_PTR(N(D_80246090_DAB2D0)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_AltD))
        EVT_IF_EQ(AB_OMO_6, 0)
            EVT_SET(MV_TrainUnk_00, 0)
            EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802460A0_DAB2E0)))
            EVT_SET(MV_TrainUnk_02, 3)
            EVT_SET(MF_TrainUnk_00, TRUE)
            EVT_LABEL(20)
            EVT_IF_EQ(MF_TrainUnk_00, TRUE)
                EVT_WAIT(1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_KILL_THREAD(LVarB)
            EVT_EXEC(N(EVS_TrainUnk_B))
            EVT_CALL(N(EnableCameraFollowPlayerY))
            EVT_SET(LVar9, EVT_PTR(N(D_80246080_DAB2C0)))
            EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_ELSE
            EVT_SET(MV_TrainUnk_00, 0)
            EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802460D0_DAB310)))
            EVT_SET(MV_TrainUnk_02, 1)
            EVT_SET(MF_TrainUnk_00, TRUE)
            EVT_WAIT(1)
            EVT_EXEC(N(EVS_TrainUnk_H))
            EVT_LABEL(30)
            EVT_IF_LT(MV_TrainPos, 350)
                EVT_WAIT(1)
                EVT_GOTO(30)
            EVT_END_IF
            EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_0)
            EVT_SET(GB_OMO_TrainDestination, 0)
            EVT_WAIT(100)
        EVT_END_IF
    EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(D_80246510_DAB750)[] = {
    EVT_FLOAT(131.251), EVT_FLOAT(-210.168), EVT_FLOAT(74.997),
    EVT_FLOAT(262.5), EVT_FLOAT(-245.336), EVT_FLOAT(479.165),
    EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246538_DAB778) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 0)
    EVT_SET(LVar0, EVT_PTR(N(D_80246510_DAB750)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80246510_DAB750)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_LT(MV_TrainPos, 350)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_0)
    EVT_SET(GB_OMO_TrainDestination, 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_802466C0_DAB900)[] = {
    EVT_FLOAT(131.251), EVT_FLOAT(-210.168), EVT_FLOAT(254.997),
    EVT_FLOAT(0.0), EVT_FLOAT(-175.0), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(-353.418), EVT_FLOAT(-353.688),
    EVT_FLOAT(-479.165), EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_802466F8_DAB938) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_TrainUnk_C))
    EVT_SET(AB_OMO_5, 0)
    EVT_SET(LVar0, EVT_PTR(N(D_802466C0_DAB900)))
    EVT_EXEC_WAIT(N(EVS_TrainUnk_D))
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802466C0_DAB900)))
    EVT_SET(MV_TrainUnk_02, 1)
    EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_LABEL(10)
    EVT_IF_GT(MV_TrainPos, -350)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_16"), omo_16_ENTRY_1)
    EVT_SET(GB_OMO_TrainDestination, 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80246880_DABAC0)[] = {
    EVT_FLOAT(414.885), EVT_FLOAT(-426.942), EVT_FLOAT(219.92),
    EVT_FLOAT(353.553), EVT_FLOAT(-353.553), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(92.61), EVT_FLOAT(-199.49),
    -1, -1, -1
};

s32 N(D_802468B0_DABAF0)[] = {
    EVT_FLOAT(414.885), EVT_FLOAT(-426.942), EVT_FLOAT(219.92),
    EVT_FLOAT(353.553), EVT_FLOAT(-353.553), EVT_FLOAT(262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(0.0), EVT_FLOAT(-175.0),
    EVT_FLOAT(-262.5), EVT_FLOAT(-245.336), EVT_FLOAT(-353.418),
    EVT_FLOAT(-353.688), EVT_FLOAT(-479.165), EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_802468F8_DABB38) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(AB_OMO_6, 0)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80246880_DABAC0)))
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
        EVT_SET(LVar9, EVT_PTR(N(D_80246080_DAB2C0)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC(N(EVS_TrainUnk_A))
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_802468B0_DABAF0)))
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
        EVT_SET(GB_OMO_TrainDestination, 3)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80246BE0_DABE20)[] = {
    EVT_FLOAT(-414.885), EVT_FLOAT(-426.942), EVT_FLOAT(140.075),
    EVT_FLOAT(-353.418), EVT_FLOAT(-353.688), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(0.0), EVT_FLOAT(-175.0),
    EVT_FLOAT(169.89), EVT_FLOAT(-220.49),
    -1, -1, -1
};

s32 N(D_80246C18_DABE58)[] = {
    EVT_FLOAT(-414.885), EVT_FLOAT(-426.942), EVT_FLOAT(140.075),
    EVT_FLOAT(-353.418), EVT_FLOAT(-353.688), EVT_FLOAT(-273.25),
    EVT_FLOAT(-257.95),
    -1, -1, -1
};

s32 N(D_80246C40_DABE80)[] = {
    EVT_FLOAT(-414.885), EVT_FLOAT(-426.942), EVT_FLOAT(140.075),
    EVT_FLOAT(-353.418), EVT_FLOAT(-353.688), EVT_FLOAT(-262.5),
    EVT_FLOAT(-245.336), EVT_FLOAT(0.0), EVT_FLOAT(-175.0),
    EVT_FLOAT(262.5), EVT_FLOAT(-245.336), EVT_FLOAT(479.165),
    EVT_FLOAT(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246C80_DABEC0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, FALSE)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80246C18_DABE58)))
    EVT_ELSE
        EVT_IF_EQ(AB_OMO_6, 0)
            EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80246BE0_DABE20)))
        EVT_ELSE
            EVT_GOTO(15)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(MV_TrainUnk_00, 0)
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
    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, TRUE)
        EVT_SET(LVar9, EVT_PTR(N(D_80246080_DAB2C0)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_E))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
    EVT_ELSE
        EVT_SET(LVar9, EVT_PTR(N(D_80246088_DAB2C8)))
        EVT_EXEC_WAIT(N(EVS_TrainUnk_AltE))
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0013)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_LABEL(15)
    EVT_EXEC(N(EVS_TrainUnk_A))
    EVT_SET(MV_TrainUnk_00, 0)
    EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80246C40_DABE80)))
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
    EVT_SET(GB_OMO_TrainDestination, 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80247044_DAC284)[] = {
    3, 2, 1,
};

s32 N(D_80247050_DAC290)[] = {
    1, 2, 3,
};

EvtScript N(EVS_8024705C) = {
    EVT_IF_EQ(MF_EitherSwitchPressed, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    EVT_ELSE
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 5, MSG_CH4_0012)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                EVT_CALL(ShowChoice, MSG_Choice_003A)
                EVT_IF_NE(LVar0, 3)
                    EVT_CALL(CloseMessage)
                    EVT_USE_BUF(EVT_PTR(N(D_80247044_DAC284)))
                    EVT_ADD(LVar0, 1)
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ1(LVar1)
                    EVT_END_LOOP
                    EVT_SET(AB_OMO_6, LVar1)
                    EVT_EXEC_WAIT(N(D_802466F8_DAB938))
                EVT_ELSE
                    EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH4_PULLED_SWITCH_SWITCH)
                    EVT_CALL(ShowChoice, MSG_Choice_0037)
                    EVT_IF_NE(LVar0, 1)
                        EVT_CALL(CloseMessage)
                        EVT_USE_BUF(EVT_PTR(N(D_80247050_DAC290)))
                        EVT_ADD(LVar0, 1)
                        EVT_LOOP(LVar0)
                            EVT_BUF_READ1(LVar1)
                        EVT_END_LOOP
                        EVT_SET(AB_OMO_6, LVar1)
                        EVT_EXEC_WAIT(N(D_80246538_DAB778))
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EVT_END_IF
                EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    EVT_CALL(ShowChoice, MSG_Choice_0038)
                    EVT_IF_NE(LVar0, 2)
                        EVT_CALL(CloseMessage)
                        EVT_USE_BUF(EVT_PTR(N(D_80247050_DAC290)))
                        EVT_ADD(LVar0, 1)
                        EVT_LOOP(LVar0)
                            EVT_BUF_READ1(LVar1)
                        EVT_END_LOOP
                        EVT_SET(AB_OMO_6, LVar1)
                        EVT_EXEC_WAIT(N(D_80246538_DAB778))
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EVT_END_IF
                EVT_CASE_GE(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    EVT_CALL(ShowChoice, MSG_Choice_0039)
                    EVT_IF_NE(LVar0, 3)
                        EVT_CALL(CloseMessage)
                        EVT_USE_BUF(EVT_PTR(N(D_80247050_DAC290)))
                        EVT_ADD(LVar0, 1)
                        EVT_LOOP(LVar0)
                            EVT_BUF_READ1(LVar1)
                        EVT_END_LOOP
                        EVT_SET(AB_OMO_6, LVar1)
                        EVT_EXEC_WAIT(N(D_80246538_DAB778))
                    EVT_ELSE
                        EVT_CALL(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_80247454_DAC694)[] = {
    EVT_FLOAT(131.251), EVT_FLOAT(-210.168), EVT_FLOAT(74.997),
    -1, -1, -1
};

EvtScript N(EVS_8024746C) = {
    EVT_EXEC_WAIT(N(EVS_SetupSwitches))
    EVT_CALL(EnableGroup, MODEL_po, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        EVT_CALL(EnableGroup, MODEL_popo, FALSE)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_eki1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_SET(MV_TrainUnk_00, 0)
        EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80247454_DAC694)))
        EVT_SET(MV_TrainUnk_02, 0)
        EVT_EXEC(N(EVS_Scene_RideTrain))
        EVT_SET(MF_TrainUnk_00, TRUE)
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(omo_03_ENTRY_2)
                EVT_EXEC(N(D_80246C80_DABEC0))
            EVT_CASE_EQ(omo_03_ENTRY_3)
                EVT_EXEC(N(D_802468F8_DABB38))
            EVT_CASE_EQ(omo_03_ENTRY_6)
                EVT_CALL(EnableGroup, MODEL_popo, FALSE)
                EVT_CALL(EnableGroup, MODEL_po, TRUE)
            EVT_CASE_DEFAULT
                EVT_SET(MV_TrainUnk_00, 0)
                EVT_SET(MV_TrainUnk_01, EVT_PTR(N(D_80247454_DAC694)))
                EVT_SET(MV_TrainUnk_02, 0)
                EVT_EXEC(N(EVS_Scene_RideTrain))
                EVT_SET(MF_TrainUnk_00, TRUE)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
