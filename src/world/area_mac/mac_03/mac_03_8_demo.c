#include "mac_03.h"

EvtScript N(EVS_DemoFollowTrainCamera) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_EQ(MF_TrainReverseDir, FALSE)
            EVT_IF_GT(LVar0, 350)
                EVT_SET(LVar0, 350)
            EVT_END_IF
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 30)
            EVT_ADD(LVar2, 40)
        EVT_ELSE
            EVT_IF_GT(LVar0, 350)
                EVT_SET(LVar0, 350)
            EVT_END_IF
            EVT_ADD(LVar0, -40)
            EVT_SET(LVar1, 30)
            EVT_ADD(LVar2, 40)
        EVT_END_IF
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DemoUpdatePassengerPos) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_TrainMoveDist)
    EVT_IF_EQ(MF_TrainReverseDir, FALSE)
        EVT_ADD(LVar0, -425)
    EVT_ELSE
        EVT_ADD(LVar0, -335)
    EVT_END_IF
    EVT_SET(LVar3, LVar0)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar5, LVar2)
    EVT_IF_EQ(MF_TrainReverseDir, FALSE)
        EVT_ADD(LVar3, -57)
    EVT_ELSE
        EVT_ADD(LVar3, 57)
    EVT_END_IF
    EVT_ADD(LVar4, -31)
    EVT_ADD(LVar5, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_EQ(MF_TrainReverseDir, FALSE)
        EVT_ADD(LVar0, 0)
    EVT_ELSE
        EVT_ADD(LVar0, 0)
    EVT_END_IF
    EVT_ADD(LVar1, -6)
    EVT_ADD(LVar2, -40)
    EVT_CALL(SetNpcPos, NPC_TrainToad_02, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DemoDepartForMtRugged) = {
    EVT_CALL(EnableWorldStatusBar, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_SET(MV_TrainMoveDist, 0)
    EVT_SET(MV_TrainMoveSpeed, 0)
    EVT_SET(MF_TrainReverseDir, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitk, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_humikiri, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_fumikiri, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerPos, -425, 45, 20)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, -410)
    EVT_SET(LVar1, 45)
    EVT_SET(LVar2, 20)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_SET(MF_TrainMoving, TRUE)
    EVT_EXEC(N(EVS_DemoUpdatePassengerPos))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(240.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-100.0), EVT_FLOAT(-50.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-2.5), EVT_FLOAT(-3.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 100)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_LOOP(1000)
            EVT_ADDF(MV_TrainMoveSpeed, EVT_FLOAT(0.031))
            EVT_IF_GT(MV_TrainMoveSpeed, 10)
                EVT_SETF(MV_TrainMoveSpeed, EVT_FLOAT(10.0))
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_EXEC_GET_TID(N(EVS_DemoFollowTrainCamera), LVar9)
    EVT_WAIT(180)
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("mac_03"), mac_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    EVT_WAIT(110)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorDemoState) = {
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_CALL(GetDemoState, LVar0)
        EVT_IF_EQ(LVar0, DEMO_STATE_CHANGE_MAP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_EQ(GF_DemoSceneDone, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("mac_03"), mac_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayDemoScene) = {
    EVT_SET(GF_DemoSceneDone, FALSE)
    EVT_EXEC(N(EVS_MonitorDemoState))
    EVT_EXEC(N(EVS_DemoDepartForMtRugged))
    EVT_RETURN
    EVT_END
};
