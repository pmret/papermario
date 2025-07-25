#include "iwa_11.h"

#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(N(GetSmallWheelsAngle)) {
    f32 angle = clamp_angle(script->varTable[2] * -2.4f);

    evt_set_float_variable(script, LVar0, angle);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetLargeWheelAngle)) {
    f32 angle = clamp_angle(script->varTable[2] * -2.4f * 0.6f);

    evt_set_float_variable(script, LVar0, angle);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpawnSmoke) = {
    Call(PlaySoundAtModel, MODEL_07, SOUND_SEQ_TRAIN_CHUG, SOUND_SPACE_DEFAULT)
    SetF(LVar0, MV_TrainMoveDist)
    IfEq(MF_TrainReverseDir, false)
        AddF(LVar0, -310)
    Else
        AddF(LVar0, -450)
    EndIf
    SetF(LVar1, 140)
    SetF(LVar2, 0)
    SetF(LVar3, Float(1.0))
    SetF(LVar4, Float(3.0))
    Add(LVarB, CLONED_MODEL(0))
    Call(EnableModel, LVarB, true)
    Loop(20)
        Call(TranslateModel, LVarB, LVar0, LVar1, LVar2)
        Call(ScaleModel, LVarB, LVar3, LVar3, 1)
        AddF(LVar1, LVar4)
        AddF(LVar3, Float(0.046))
        MulF(LVar4, Float(0.906))
        Wait(1)
    EndLoop
    Call(EnableModel, LVarB, false)
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
        IfEq(MF_TrainReverseDir, true)
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
        IfEq(MF_TrainReverseDir, false)
            Set(LVar2, MV_TrainMoveDist)
        Else
            Set(LVar2, 1000)
            Sub(LVar2, MV_TrainMoveDist)
        EndIf
        Call(N(GetSmallWheelsAngle))
        Call(RotateModel, MODEL_11, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_12, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_13, LVar0, 0, 0, 1)
        Call(N(GetLargeWheelAngle))
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
        Call(N(CosInterpMinMax), LVarC, LVar0, -30, 30, 10, 0, 0)
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
        IfEq(MF_TrainArriveDoorOpen, true)
            Set(LVar8, 10)
            Set(LFlag1, true)
            Set(MF_TrainArriveDoorOpen, false)
        EndIf
        IfEq(MF_TrainArrivePlayerDisembark, true)
            Set(LVar8, -10)
            Set(LFlag1, true)
            Set(MF_TrainArrivePlayerDisembark, false)
        EndIf
        IfEq(MF_TrainDepartDoorOpen, true)
            Set(LVar8, 10)
            Set(LFlag2, true)
            Set(MF_TrainDepartDoorOpen, false)
        EndIf
        IfEq(MF_TrainDepartPlayerBoard, true)
            Set(LVar8, -10)
            Set(LFlag2, true)
            Set(MF_TrainDepartPlayerBoard, false)
        EndIf
        IfEq(LFlag1, true)
            Add(LVar9, LVar8)
            IfGe(LVar9, 90)
                Set(LVar9, 90)
                Set(LFlag1, false)
            EndIf
            IfLe(LVar9, 0)
                Set(LVar9, 0)
                Set(LFlag1, false)
            EndIf
        EndIf
        IfEq(LFlag2, true)
            Add(LVarA, LVar8)
            IfGe(LVarA, 90)
                Set(LVarA, 90)
                Set(LFlag2, false)
            EndIf
            IfLe(LVarA, 0)
                Set(LVarA, 0)
                Set(LFlag2, false)
            EndIf
        EndIf
        Call(RotateModel, MODEL_omote, LVar9, 0, -1, 0)
        Call(RotateModel, MODEL_ura, LVar9, 0, -1, 0)
        Call(RotateModel, MODEL_omote2, LVarA, 0, 1, 0)
        Call(RotateModel, MODEL_ura2, LVarA, 0, 1, 0)
        IfEq(MF_TrainScrolling, true)
            IfEq(MF_TrainReverseDir, false)
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
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Set(LVar0, MV_TrainMoveDist)
        IfEq(MF_TrainReverseDir, false)
            Add(LVar0, -425)
        Else
            Add(LVar0, -335)
        EndIf
        EVT_VEC3I_VSET(LVar3, LVar0)
        IfEq(MF_TrainReverseDir, false)
            Add(LVar3, -57)
        Else
            Add(LVar3, 57)
        EndIf
        Add(LVar4, -31)
        Add(LVar5, 0)
        Call(SetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        IfEq(MF_TrainReverseDir, false)
            Add(LVar0, 0)
        Else
            Add(LVar0, 0)
        EndIf
        Add(LVar1, -6)
        Add(LVar2, -40)
        Call(SetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_FollowTrainCamera) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfEq(MF_TrainReverseDir, false)
            IfLt(LVar0, -1100)
                Set(LVar0, -1100)
            EndIf
            Add(LVar0, 40)
            Set(LVar1, 30)
            Add(LVar2, 40)
        Else
            IfLt(LVar0, -1100)
                Set(LVar0, -1100)
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

EvtScript N(EVS_TravelToToadTown) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(EnableNpcShadow, NPC_PARTNER, false)
    Call(HidePlayerShadow, true)
    Set(MF_TrainScrolling, true)
    Set(MF_TrainReverseDir, true)
    Exec(N(EVS_UpdatePassengerPos))
    Thread
        Call(MakeLerp, 6400, -5600, 1200, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_TrainMoveDist, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Loop(0)
            Wait(1)
        EndLoop
    EndThread
    Wait(1200)
    Call(GotoMap, Ref("mac_03"), mac_03_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TravelToMtRugged) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(EnableNpcShadow, NPC_PARTNER, false)
    Call(HidePlayerShadow, true)
    Exec(N(EVS_UpdatePassengerPos))
    Set(MF_TrainScrolling, true)
    Call(MakeLerp, 0, 6350, 600, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_TrainMoveDist, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    IfLt(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
        Set(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
    EndIf
    IfEq(GF_StartedChapter2, false)
        Set(GF_StartedChapter2, true)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_2, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("iwa_10"), iwa_10_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_InitializeTrainScene) = {
    Call(EnableModel, MODEL_km, false)
    Call(SetModelFlags, MODEL_km, MODEL_FLAG_BILLBOARD, true)
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
    Set(MF_TrainReverseDir, false)
    Set(MV_TrainMoveDist, -6000)
    Set(MV_TrainMoveSpeed, 10)
    Exec(N(EVS_AnimateTrain))
    Wait(1)
    Return
    End
};
