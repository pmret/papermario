#include "mac_03.h"

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_OpenCrossingGates) = {
    Set(LVarF, 0)
    Loop(40)
        Add(LVarF, 1)
        Set(LVar1, LVarF)
        Call(N(CosInterpMinMax), LVar1, LVar0, 0, 105, 40, 1, 0)
        Call(RotateModel, MODEL_o183, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o184, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o191, LVar0, 0, 1, 0)
        Set(LVar1, LVarF)
        Call(N(CosInterpMinMax), LVar1, LVar0, 0, 75, 40, 1, 0)
        Call(RotateModel, MODEL_o187, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o188, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseCrossingGates) = {
    Set(LVarF, 0)
    Loop(40)
        Add(LVarF, 1)
        Set(LVar1, LVarF)
        Call(N(CosInterpMinMax), LVar1, LVar0, 105, 0, 40, 1, 0)
        Call(RotateModel, MODEL_o183, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o184, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o191, LVar0, 0, 1, 0)
        Set(LVar1, LVarF)
        Call(N(CosInterpMinMax), LVar1, LVar0, 75, 0, 40, 1, 0)
        Call(RotateModel, MODEL_o187, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o188, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SpawnSmoke) = {
    Call(PlaySoundAtModel, MODEL_07, SOUND_SEQ_TRAIN_CHUG, SOUND_SPACE_DEFAULT)
    SetF(LVar0, MV_TrainMoveDist)
    IfEq(MF_TrainReverseDir, FALSE)
        AddF(LVar0, -310)
    Else
        AddF(LVar0, -450)
    EndIf
    SetF(LVar1, 140)
    SetF(LVar2, 0)
    SetF(LVar3, Float(1.0))
    SetF(LVar4, Float(3.0))
    Add(LVarB, CLONED_MODEL(0))
    Call(EnableModel, LVarB, TRUE)
    Loop(20)
        Call(TranslateModel, LVarB, LVar0, LVar1, LVar2)
        Call(ScaleModel, LVarB, LVar3, LVar3, 1)
        AddF(LVar1, LVar4)
        AddF(LVar3, Float(0.046))
        MulF(LVar4, Float(0.906))
        Wait(1)
    EndLoop
    Call(EnableModel, LVarB, FALSE)
    Return
    End
};

EvtScript N(EVS_AnimateTrain) = {
    Label(0)
        Set(LVar0, MV_TrainMoveDist)
        Call(TranslateModel, MODEL_08, LVar0, 0, 0)
        Call(TranslateModel, MODEL_07, LVar0, 0, 0)
        Call(TranslateModel, MODEL_10, LVar0, 0, 0)
        Call(TranslateModel, MODEL_11, LVar0, 0, 0)
        Call(TranslateModel, MODEL_12, LVar0, 0, 0)
        Call(TranslateModel, MODEL_13, LVar0, 0, 0)
        Call(TranslateModel, MODEL_09, LVar0, 0, 0)
        Call(TranslateModel, MODEL_01, LVar0, 0, 0)
        Call(TranslateModel, MODEL_02, LVar0, 0, 0)
        Call(TranslateModel, MODEL_03, LVar0, 0, 0)
        Call(TranslateModel, MODEL_04, LVar0, 0, 0)
        Call(TranslateModel, MODEL_05, LVar0, 0, 0)
        Call(TranslateModel, MODEL_06, LVar0, 0, 0)
        Call(TranslateModel, MODEL_ura, LVar0, 0, 0)
        Call(TranslateModel, MODEL_omote, LVar0, 0, 0)
        Call(TranslateModel, MODEL_ura2, LVar0, 0, 0)
        Call(TranslateModel, MODEL_omote2, LVar0, 0, 0)
        Call(TranslateModel, MODEL_14, LVar0, 0, 0)
        Call(TranslateModel, MODEL_15, LVar0, 0, 0)
        Call(TranslateModel, MODEL_16, LVar0, 0, 0)
        IfEq(MF_TrainReverseDir, TRUE)
            Set(LVar0, 180)
            Call(TranslateModel, MODEL_08, -69, -50, 0)
            Call(TranslateModel, MODEL_07, -69, -50, 0)
            Call(TranslateModel, MODEL_10, 75, 25, 2)
            Call(TranslateModel, MODEL_11, 30, 30, 2)
            Call(TranslateModel, MODEL_12, -10, 30, 2)
            Call(TranslateModel, MODEL_13, -50, 30, 2)
            Call(TranslateModel, MODEL_09, -1, -58, 0)
            Call(TranslateModel, MODEL_ura, 82, -19, -35)
            Call(TranslateModel, MODEL_omote, 82, -19, -35)
            Call(TranslateModel, MODEL_ura2, 82, -19, 35)
            Call(TranslateModel, MODEL_omote2, 82, -19, 35)
            Call(TranslateModel, MODEL_14, -21, 30, 0)
            Call(TranslateModel, MODEL_15, -25, 30, 0)
            Call(TranslateModel, MODEL_16, -63, 15, 0)
            Call(RotateModel, MODEL_08, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_07, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_10, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_11, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_12, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_13, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_09, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_01, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_02, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_03, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_04, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_05, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_06, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_ura, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_omote, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_ura2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_omote2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_14, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_15, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_16, LVar0, 0, 1, 0)
            Call(TranslateModel, MODEL_08, 69, 50, 0)
            Call(TranslateModel, MODEL_07, 69, 50, 0)
            Call(TranslateModel, MODEL_10, -75, -25, -2)
            Call(TranslateModel, MODEL_11, -30, -30, -2)
            Call(TranslateModel, MODEL_12, 10, -30, -2)
            Call(TranslateModel, MODEL_13, 50, -30, -2)
            Call(TranslateModel, MODEL_09, 1, 58, 0)
            Call(TranslateModel, MODEL_ura, -82, 19, 35)
            Call(TranslateModel, MODEL_omote, -82, 19, 35)
            Call(TranslateModel, MODEL_ura2, -82, 19, -35)
            Call(TranslateModel, MODEL_omote2, -82, 19, -35)
            Call(TranslateModel, MODEL_14, 21, -30, 0)
            Call(TranslateModel, MODEL_15, 25, -30, 0)
            Call(TranslateModel, MODEL_16, 63, -15, 0)
        EndIf
        IfEq(MF_TrainReverseDir, FALSE)
            Set(LVar2, MV_TrainMoveDist)
        Else
            Set(LVar2, 1000)
            Sub(LVar2, MV_TrainMoveDist)
        EndIf
        SetF(LVar0, LVar2)
        MulF(LVar0, Float(-2.40625))
        Call(RotateModel, MODEL_11, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_12, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_13, LVar0, 0, 0, 1)
        MulF(LVar0, Float(0.6))
        Call(RotateModel, MODEL_10, LVar0, 0, 0, 1)
        Call(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        Call(N(CosInterpMinMax), LVar2, LVar1, -10, 10, 75, 0, -90)
        Call(TranslateModel, MODEL_14, LVar0, LVar1, 0)
        Call(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        Add(LVar0, 5)
        Call(TranslateModel, MODEL_16, LVar0, -14, 0)
        Call(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        Call(N(CosInterpMinMax), LVar2, LVar1, -10, 10, 75, 0, -90)
        Call(TranslateModel, MODEL_15, LVar0, LVar1, 0)
        Call(N(CosInterpMinMax), LVar2, LVar0, -40, 40, 75, 0, 90)
        Call(RotateModel, MODEL_15, LVar0, 0, 0, 1)
        Call(N(CosInterpMinMax), LVarC, LVar0, Float(-3.0), Float(3.0), 10, 0, 0)
        MulF(LVar0, MV_TrainMoveSpeed)
        Call(RotateModel, MODEL_09, LVar0, 0, 0, 1)
        IfNe(MV_TrainMoveSpeed, 0)
            IfEq(LVarD, 0)
                Thread
                    Wait(18)
                    Exec(N(EVS_SpawnSmoke))
                EndThread
            EndIf
        EndIf
        IfLe(LVarD, 20)
            Call(N(CosInterpMinMax), LVarD, LVar0, Float(0.703), Float(1.0), 10, 0, 180)
            Call(N(CosInterpMinMax), LVarD, LVar2, Float(0.0), Float(0.296), 10, 0, 180)
            SetF(LVar1, Float(0.296))
            SubF(LVar1, LVar2)
            AddF(LVar1, Float(1.0))
            Call(ScaleModel, MODEL_07, LVar1, LVar0, LVar1)
            Call(ScaleModel, MODEL_08, LVar1, LVar0, LVar1)
        Else
            SetF(LVar0, Float(1.0))
            SetF(LVar2, Float(0.296))
            SetF(LVar1, Float(0.296))
            SubF(LVar1, LVar2)
            AddF(LVar1, Float(1.0))
            Call(ScaleModel, MODEL_07, LVar1, LVar0, LVar1)
            Call(ScaleModel, MODEL_08, LVar1, LVar0, LVar1)
        EndIf
        IfEq(MF_TrainDepartDoorOpen, TRUE)
            Call(PlaySoundAt, SOUND_TRAIN_DOOR_OPEN, SOUND_SPACE_DEFAULT, -435, 84, 37)
            Set(LVar8, 10)
            Set(LFlag1, TRUE)
            Set(MF_TrainDepartDoorOpen, FALSE)
        EndIf
        IfEq(MF_TrainDepartPlayerBoard, TRUE)
            Set(LVar8, -10)
            Set(LFlag1, TRUE)
            Set(MF_TrainDepartPlayerBoard, FALSE)
        EndIf
        IfEq(MF_TrainArriveDoorOpen, TRUE)
            Call(PlaySoundAt, SOUND_TRAIN_DOOR_OPEN, SOUND_SPACE_DEFAULT, -413, 84, 38)
            Set(LVar8, 10)
            Set(LFlag2, TRUE)
            Set(MF_TrainArriveDoorOpen, FALSE)
        EndIf
        IfEq(MF_TrainArrivePlayerDisembark, TRUE)
            Set(LVar8, -10)
            Set(LFlag2, TRUE)
            Set(MF_TrainArrivePlayerDisembark, FALSE)
        EndIf
        IfEq(LFlag1, TRUE)
            Add(LVar9, LVar8)
            IfGe(LVar9, 90)
                Set(LVar9, 90)
                Set(LFlag1, FALSE)
            EndIf
            IfLe(LVar9, 0)
                Set(LVar9, 0)
                Set(LFlag1, FALSE)
                Call(PlaySoundAt, SOUND_TRAIN_DOOR_CLOSE, SOUND_SPACE_DEFAULT, -435, 84, 37)
            EndIf
        EndIf
        IfEq(LFlag2, TRUE)
            Add(LVarA, LVar8)
            IfGe(LVarA, 90)
                Set(LVarA, 90)
                Set(LFlag2, FALSE)
            EndIf
            IfLe(LVarA, 0)
                Set(LVarA, 0)
                Set(LFlag2, FALSE)
                Call(PlaySoundAt, SOUND_TRAIN_DOOR_CLOSE, SOUND_SPACE_DEFAULT, -413, 84, 38)
            EndIf
        EndIf
        Call(RotateModel, MODEL_omote, LVar9, 0, -1, 0)
        Call(RotateModel, MODEL_ura, LVar9, 0, -1, 0)
        Call(RotateModel, MODEL_omote2, LVarA, 0, 1, 0)
        Call(RotateModel, MODEL_ura2, LVarA, 0, 1, 0)
        IfGt(MV_TrainMoveDist, 100)
            IfLt(MV_TrainMoveDist, 600)
                IfEq(LFlag0, FALSE)
                    Set(LFlag0, TRUE)
                    Exec(N(EVS_OpenCrossingGates))
                EndIf
            EndIf
        EndIf
        IfLe(MV_TrainMoveDist, 100)
            IfEq(LFlag0, TRUE)
                Set(LFlag0, FALSE)
                Exec(N(EVS_CloseCrossingGates))
            EndIf
        EndIf
        IfGe(MV_TrainMoveDist, 600)
            IfEq(LFlag0, TRUE)
                Set(LFlag0, FALSE)
                Exec(N(EVS_CloseCrossingGates))
            EndIf
        EndIf
        IfEq(MF_TrainMoving, TRUE)
            IfEq(MF_TrainReverseDir, FALSE)
                Set(LVar0, MV_TrainMoveDist)
                Add(LVar0, -425)
                Add(LVar1, 75)
                Add(LVar2, 20)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Else
                Set(LVar0, MV_TrainMoveDist)
                Add(LVar0, -335)
                Add(LVar1, 75)
                Add(LVar2, 20)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
            EndIf
        EndIf
        Add(MV_TrainMoveDist, MV_TrainMoveSpeed)
        Set(LVar0, MV_TrainMoveDist)
        Div(LVar0, 75)
        IfNe(LVar0, LVarE)
            Set(LVarE, LVar0)
            Set(LVarD, -1)
            Add(LVarB, 1)
            IfEq(LVarB, 10)
                Set(LVarB, 0)
            EndIf
        EndIf
        AddF(LVarD, 1)
        IfGt(LVarD, 1000)
            Set(LVarD, 1000)
        EndIf
        AddF(LVarC, 1)
        IfGt(LVarC, 1000)
            Set(LVarC, 0)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdatePassengerPos) = {
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

EvtScript N(EVS_FollowTrainCamera) = {
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

EvtScript N(EVS_ArriveFromMtRugged) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    Call(HidePlayerShadow, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitk, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_humikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_fumikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    ExecGetTID(N(EVS_FollowTrainCamera), LVar9)
    ExecGetTID(N(EVS_UpdatePassengerPos), LVarE)
    Set(MF_TrainMoving, TRUE)
    Set(MV_TrainMoveDist, 1200)
    Set(MV_TrainMoveSpeed, 0)
    Set(MF_TrainReverseDir, TRUE)
    Wait(60)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Set(MV_TrainMoveDist, 1200)
    Set(MV_TrainMoveSpeed, -10)
    Set(MF_TrainReverseDir, TRUE)
    Label(0)
        SetF(MV_TrainMoveSpeed, -90)
        SubF(MV_TrainMoveSpeed, MV_TrainMoveDist)
        SubF(MV_TrainMoveSpeed, Float(10.0))
        DivF(MV_TrainMoveSpeed, Float(10.0))
        IfLt(MV_TrainMoveSpeed, -10)
            Set(MV_TrainMoveSpeed, -10)
        EndIf
        IfLe(MV_TrainMoveDist, -90)
            Goto(1)
        EndIf
        Wait(1)
        Goto(0)
    Label(1)
    Set(MV_TrainMoveDist, -90)
    Set(MV_TrainMoveSpeed, 0)
    Call(PlaySound, SOUND_TRAIN_RELEASE_STEAM)
    KillThread(LVarE)
    Set(MF_TrainMoving, FALSE)
    Call(SetPlayerJumpscale, Float(1.0))
    Set(LVar0, -425)
    Set(LVar1, 45)
    Set(LVar2, 20)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(PlayerJump, LVar0, LVar1, LVar2, 15)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar0, -410)
    Set(LVar1, 45)
    Set(LVar2, 20)
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    KillThread(LVar9)
    Call(EnableNpcShadow, NPC_PARTNER, TRUE)
    Call(HidePlayerShadow, FALSE)
    Set(MF_TrainArriveDoorOpen, TRUE)
    Wait(20)
    Call(UseSettingsFrom, CAM_DEFAULT, -420, 20, 97)
    Call(SetPanTarget, CAM_DEFAULT, -420, 20, 97)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(PlayerJump, -420, 20, 97, 15)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(NpcJump0, NPC_PARTNER, -406, 20, 71, 15)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitk, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kisya1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kisya2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_kisya3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_humikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_fumikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(DisablePlayerPhysics, FALSE)
    Call(EnablePartnerAI)
    Set(MF_TrainArrivePlayerDisembark, TRUE)
    Wait(20)
    Call(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0005)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_DepartForMtRugged) = {
    IfEq(GF_MAC03_BombedRock, FALSE)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_03_ENTRY_1)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Set(MV_TrainMoveDist, 0)
    Set(MV_TrainMoveSpeed, 0)
    Set(MF_TrainReverseDir, FALSE)
    Set(MF_TrainDepartDoorOpen, TRUE)
    Wait(20)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitk, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_kisya3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_humikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_fumikiri, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcFlagBits, NPC_TrainToad_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -425, 70, 0)
    Call(SetPlayerJumpscale, Float(1.0))
    Set(LVar0, -425)
    Set(LVar1, 45)
    Set(LVar2, 20)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(PlayerJump, LVar0, LVar1, LVar2, 15)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(NpcMoveTo, NPC_PARTNER, -425, 70, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Set(LVar0, -425)
    Set(LVar1, 45)
    Set(LVar2, 20)
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    Set(MF_TrainDepartPlayerBoard, TRUE)
    Wait(20)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar2, -50)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerJumpscale, Float(1.0))
    Set(LVar0, -425)
    Set(LVar1, 75)
    Set(LVar2, 20)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Call(PlayerJump, LVar0, LVar1, LVar2, 15)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(InterpPlayerYaw, 90, 0)
    Set(MF_TrainMoving, TRUE)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -57)
    Add(LVar1, -31)
    Add(LVar2, 0)
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Exec(N(EVS_UpdatePassengerPos))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(240.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-100.0), Float(-50.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-2.5), Float(-3.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 100)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_TrainToad_02, ANIM_TrainToad_Talk, ANIM_TrainToad_Still, 5, MSG_MAC_Station_0009)
    Call(PlaySound, SOUND_TRAIN_DEPARTURE)
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
    ExecGetTID(N(EVS_FollowTrainCamera), LVar9)
    Wait(170)
    Wait(100)
    Call(GotoMap, Ref("iwa_11"), iwa_11_ENTRY_0)
    Return
    End
};

EvtScript N(EVS_InitializeTrainScene) = {
    Call(SetModelFlags, MODEL_km, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    Call(EnableModel, MODEL_km, FALSE)
    Call(CloneModel, MODEL_km, CLONED_MODEL(0))
    Call(CloneModel, MODEL_km, CLONED_MODEL(1))
    Call(CloneModel, MODEL_km, CLONED_MODEL(2))
    Call(CloneModel, MODEL_km, CLONED_MODEL(3))
    Call(CloneModel, MODEL_km, CLONED_MODEL(4))
    Call(CloneModel, MODEL_km, CLONED_MODEL(5))
    Call(CloneModel, MODEL_km, CLONED_MODEL(6))
    Call(CloneModel, MODEL_km, CLONED_MODEL(7))
    Call(CloneModel, MODEL_km, CLONED_MODEL(8))
    Call(CloneModel, MODEL_km, CLONED_MODEL(9))
    Exec(N(EVS_AnimateTrain))
    Wait(1)
    Return
    End
};
