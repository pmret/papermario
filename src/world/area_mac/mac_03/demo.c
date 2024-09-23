#include "mac_03.h"

EvtScript N(EVS_DemoFollowTrainCamera) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(MF_TrainReverseDir, FALSE)
            IfGt(LVar0, 350)
                Set(LVar0, 350)
            EndIf
            Add(LVar0, 40)
            Set(LVar1, 30)
            Add(LVar2, 40)
        Else
            IfGt(LVar0, 350)
                Set(LVar0, 350)
            EndIf
            Add(LVar0, -40)
            Set(LVar1, 30)
            Add(LVar2, 40)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_DemoUpdatePassengerPos) = {
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar0, MV_TrainMoveDist)
    IfEq(MF_TrainReverseDir, FALSE)
        Add(LVar0, -425)
    Else
        Add(LVar0, -335)
    EndIf
    Set(LVar3, LVar0)
    Set(LVar4, LVar1)
    Set(LVar5, LVar2)
    IfEq(MF_TrainReverseDir, FALSE)
        Add(LVar3, -57)
    Else
        Add(LVar3, 57)
    EndIf
    Add(LVar4, -31)
    Add(LVar5, 0)
    Call(SetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
    IfEq(MF_TrainReverseDir, FALSE)
        Add(LVar0, 0)
    Else
        Add(LVar0, 0)
    EndIf
    Add(LVar1, -6)
    Add(LVar2, -40)
    Call(SetNpcPos, NPC_TrainToad_02, LVar0, LVar1, LVar2)
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_DemoDepartForMtRugged) = {
    Call(EnableWorldStatusBar, FALSE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Set(MV_TrainMoveDist, 0)
    Set(MV_TrainMoveSpeed, 0)
    Set(MF_TrainReverseDir, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitk, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_humikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_fumikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerPos, -425, 45, 20)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar0, -410)
    Set(LVar1, 45)
    Set(LVar2, 20)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(InterpPlayerYaw, 90, 1)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Set(MF_TrainMoving, TRUE)
    Exec(N(EVS_DemoUpdatePassengerPos))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(240.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-100.0), Float(-50.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-2.5), Float(-3.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 100)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Loop(1000)
            AddF(MV_TrainMoveSpeed, Float(0.031))
            IfGt(MV_TrainMoveSpeed, 10)
                SetF(MV_TrainMoveSpeed, Float(10.0))
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Wait(40)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    ExecGetTID(N(EVS_DemoFollowTrainCamera), LVar9)
    Wait(180)
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("mac_03"), mac_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_BLACK)
    Wait(110)
    Return
    End
};

EvtScript N(EVS_MonitorDemoState) = {
    Wait(10)
    Loop(0)
        Call(GetDemoState, LVar0)
        IfEq(LVar0, DEMO_STATE_CHANGE_MAP)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    IfEq(GF_DemoSceneDone, TRUE)
        Return
    EndIf
    Set(GF_DemoSceneDone, TRUE)
    Call(GotoMapSpecial, Ref("mac_03"), mac_03_ENTRY_2, TRANSITION_END_DEMO_SCENE_WHITE)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_PlayDemoScene) = {
    Set(GF_DemoSceneDone, FALSE)
    Exec(N(EVS_MonitorDemoState))
    Exec(N(EVS_DemoDepartForMtRugged))
    Return
    End
};
