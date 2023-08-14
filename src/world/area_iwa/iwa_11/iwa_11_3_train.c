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
    EVT_CALL(PlaySoundAtModel, MODEL_07, SOUND_SEQ_TRAIN_CHUG, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, MV_TrainMoveDist)
    EVT_IF_EQ(MF_TrainReverseDir, FALSE)
        EVT_ADDF(LVar0, -310)
    EVT_ELSE
        EVT_ADDF(LVar0, -450)
    EVT_END_IF
    EVT_SETF(LVar1, 140)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_SETF(LVar4, EVT_FLOAT(3.0))
    EVT_ADD(LVarB, CLONED_MODEL(0))
    EVT_CALL(EnableModel, LVarB, TRUE)
    EVT_LOOP(20)
        EVT_CALL(TranslateModel, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, LVarB, LVar3, LVar3, 1)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar3, EVT_FLOAT(0.046))
        EVT_MULF(LVar4, EVT_FLOAT(0.906))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarB, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateTrain) = {
    EVT_LABEL(0)
        EVT_SET(LVar0, MV_TrainMoveDist)
        EVT_CALL(TranslateModel, MODEL_08, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_07, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_10, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_11, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_12, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_13, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_09, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_01, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_02, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_03, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_04, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_05, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_06, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_ura, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_omote, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_ura2, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_omote2, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_14, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_15, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_16, LVar0, 0, 0)
        EVT_IF_EQ(MF_TrainReverseDir, TRUE)
            EVT_SET(LVar0, 180)
            EVT_CALL(TranslateModel, MODEL_08, -69, -50, 0)
            EVT_CALL(TranslateModel, MODEL_07, -69, -50, 0)
            EVT_CALL(TranslateModel, MODEL_10, 75, 25, 2)
            EVT_CALL(TranslateModel, MODEL_11, 30, 30, 2)
            EVT_CALL(TranslateModel, MODEL_12, -10, 30, 2)
            EVT_CALL(TranslateModel, MODEL_13, -50, 30, 2)
            EVT_CALL(TranslateModel, MODEL_09, -1, -58, 0)
            EVT_CALL(TranslateModel, MODEL_ura, 82, -19, -35)
            EVT_CALL(TranslateModel, MODEL_omote, 82, -19, -35)
            EVT_CALL(TranslateModel, MODEL_ura2, 82, -19, 35)
            EVT_CALL(TranslateModel, MODEL_omote2, 82, -19, 35)
            EVT_CALL(TranslateModel, MODEL_14, -21, 30, 0)
            EVT_CALL(TranslateModel, MODEL_15, -25, 30, 0)
            EVT_CALL(TranslateModel, MODEL_16, -63, 15, 0)
            EVT_CALL(RotateModel, MODEL_08, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_07, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_10, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_11, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_12, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_13, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_09, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_01, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_02, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_03, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_04, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_05, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_06, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_ura, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_omote, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_ura2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_omote2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_14, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_15, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_16, LVar0, 0, 1, 0)
            EVT_CALL(TranslateModel, MODEL_08, 69, 50, 0)
            EVT_CALL(TranslateModel, MODEL_07, 69, 50, 0)
            EVT_CALL(TranslateModel, MODEL_10, -75, -25, -2)
            EVT_CALL(TranslateModel, MODEL_11, -30, -30, -2)
            EVT_CALL(TranslateModel, MODEL_12, 10, -30, -2)
            EVT_CALL(TranslateModel, MODEL_13, 50, -30, -2)
            EVT_CALL(TranslateModel, MODEL_09, 1, 58, 0)
            EVT_CALL(TranslateModel, MODEL_ura, -82, 19, 35)
            EVT_CALL(TranslateModel, MODEL_omote, -82, 19, 35)
            EVT_CALL(TranslateModel, MODEL_ura2, -82, 19, -35)
            EVT_CALL(TranslateModel, MODEL_omote2, -82, 19, -35)
            EVT_CALL(TranslateModel, MODEL_14, 21, -30, 0)
            EVT_CALL(TranslateModel, MODEL_15, 25, -30, 0)
            EVT_CALL(TranslateModel, MODEL_16, 63, -15, 0)
        EVT_END_IF
        EVT_IF_EQ(MF_TrainReverseDir, FALSE)
            EVT_SET(LVar2, MV_TrainMoveDist)
        EVT_ELSE
            EVT_SET(LVar2, 1000)
            EVT_SUB(LVar2, MV_TrainMoveDist)
        EVT_END_IF
        EVT_CALL(N(GetSmallWheelsAngle))
        EVT_CALL(RotateModel, MODEL_11, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_12, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_13, LVar0, 0, 0, 1)
        EVT_CALL(N(GetLargeWheelAngle))
        EVT_CALL(RotateModel, MODEL_10, LVar0, 0, 0, 1)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar1, -10, 10, 75, 0, -90)
        EVT_CALL(TranslateModel, MODEL_14, LVar0, LVar1, 0)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        EVT_ADD(LVar0, 5)
        EVT_CALL(TranslateModel, MODEL_16, LVar0, -14, 0)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar0, 0, -20, 75, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar1, -10, 10, 75, 0, -90)
        EVT_CALL(TranslateModel, MODEL_15, LVar0, LVar1, 0)
        EVT_CALL(N(CosInterpMinMax), LVar2, LVar0, -40, 40, 75, 0, 90)
        EVT_CALL(RotateModel, MODEL_15, LVar0, 0, 0, 1)
        EVT_CALL(N(CosInterpMinMax), LVarC, LVar0, -30, 30, 10, 0, 0)
        EVT_CALL(RotateModel, MODEL_09, LVar0, 0, 0, 1)
        EVT_IF_NE(MV_TrainMoveSpeed, 0)
            EVT_IF_EQ(LVarD, 0)
                EVT_THREAD
                    EVT_WAIT(18)
                    EVT_EXEC(N(EVS_SpawnSmoke))
                EVT_END_THREAD
            EVT_END_IF
        EVT_END_IF
        EVT_IF_LE(LVarD, 20)
            EVT_CALL(N(CosInterpMinMax), LVarD, LVar0, EVT_FLOAT(0.703), EVT_FLOAT(1.0), 10, 0, 180)
            EVT_CALL(N(CosInterpMinMax), LVarD, LVar2, EVT_FLOAT(0.0), EVT_FLOAT(0.296), 10, 0, 180)
            EVT_SETF(LVar1, EVT_FLOAT(0.296))
            EVT_SUBF(LVar1, LVar2)
            EVT_ADDF(LVar1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_07, LVar1, LVar0, LVar1)
            EVT_CALL(ScaleModel, MODEL_08, LVar1, LVar0, LVar1)
        EVT_ELSE
            EVT_SETF(LVar0, EVT_FLOAT(1.0))
            EVT_SETF(LVar2, EVT_FLOAT(0.296))
            EVT_SETF(LVar1, EVT_FLOAT(0.296))
            EVT_SUBF(LVar1, LVar2)
            EVT_ADDF(LVar1, EVT_FLOAT(1.0))
            EVT_CALL(ScaleModel, MODEL_07, LVar1, LVar0, LVar1)
            EVT_CALL(ScaleModel, MODEL_08, LVar1, LVar0, LVar1)
        EVT_END_IF
        EVT_IF_EQ(MF_TrainArriveDoorOpen, TRUE)
            EVT_SET(LVar8, 10)
            EVT_SET(LFlag1, TRUE)
            EVT_SET(MF_TrainArriveDoorOpen, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MF_TrainArrivePlayerDisembark, TRUE)
            EVT_SET(LVar8, -10)
            EVT_SET(LFlag1, TRUE)
            EVT_SET(MF_TrainArrivePlayerDisembark, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MF_TrainDepartDoorOpen, TRUE)
            EVT_SET(LVar8, 10)
            EVT_SET(LFlag2, TRUE)
            EVT_SET(MF_TrainDepartDoorOpen, FALSE)
        EVT_END_IF
        EVT_IF_EQ(MF_TrainDepartPlayerBoard, TRUE)
            EVT_SET(LVar8, -10)
            EVT_SET(LFlag2, TRUE)
            EVT_SET(MF_TrainDepartPlayerBoard, FALSE)
        EVT_END_IF
        EVT_IF_EQ(LFlag1, TRUE)
            EVT_ADD(LVar9, LVar8)
            EVT_IF_GE(LVar9, 90)
                EVT_SET(LVar9, 90)
                EVT_SET(LFlag1, FALSE)
            EVT_END_IF
            EVT_IF_LE(LVar9, 0)
                EVT_SET(LVar9, 0)
                EVT_SET(LFlag1, FALSE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LFlag2, TRUE)
            EVT_ADD(LVarA, LVar8)
            EVT_IF_GE(LVarA, 90)
                EVT_SET(LVarA, 90)
                EVT_SET(LFlag2, FALSE)
            EVT_END_IF
            EVT_IF_LE(LVarA, 0)
                EVT_SET(LVarA, 0)
                EVT_SET(LFlag2, FALSE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_omote, LVar9, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_ura, LVar9, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_omote2, LVarA, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_ura2, LVarA, 0, 1, 0)
        EVT_IF_EQ(MF_TrainScrolling, TRUE)
            EVT_IF_EQ(MF_TrainReverseDir, FALSE)
                EVT_SET(LVar0, MV_TrainMoveDist)
                EVT_ADD(LVar0, -425)
                EVT_ADD(LVar1, 75)
                EVT_ADD(LVar2, 20)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ELSE
                EVT_SET(LVar0, MV_TrainMoveDist)
                EVT_ADD(LVar0, -335)
                EVT_ADD(LVar1, 75)
                EVT_ADD(LVar2, 20)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(MV_TrainMoveDist, MV_TrainMoveSpeed)
        EVT_SET(LVar0, MV_TrainMoveDist)
        EVT_DIV(LVar0, 75)
        EVT_IF_NE(LVar0, LVarE)
            EVT_SET(LVarE, LVar0)
            EVT_SET(LVarD, -1)
            EVT_ADD(LVarB, 1)
            EVT_IF_EQ(LVarB, 10)
                EVT_SET(LVarB, 0)
            EVT_END_IF
        EVT_END_IF
        EVT_ADDF(LVarD, 1)
        EVT_IF_GT(LVarD, 1000)
            EVT_SET(LVarD, 1000)
        EVT_END_IF
        EVT_ADDF(LVarC, 1)
        EVT_IF_GT(LVarC, 1000)
            EVT_SET(LVarC, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdatePassengerPos) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(LVar0, MV_TrainMoveDist)
        EVT_IF_EQ(MF_TrainReverseDir, FALSE)
            EVT_ADD(LVar0, -425)
        EVT_ELSE
            EVT_ADD(LVar0, -335)
        EVT_END_IF
        EVT_VEC3I_VSET(LVar3, LVar0)
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
        EVT_CALL(SetNpcPos, NPC_TrainToad, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FollowTrainCamera) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_EQ(MF_TrainReverseDir, FALSE)
            EVT_IF_LT(LVar0, -1100)
                EVT_SET(LVar0, -1100)
            EVT_END_IF
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 30)
            EVT_ADD(LVar2, 40)
        EVT_ELSE
            EVT_IF_LT(LVar0, -1100)
                EVT_SET(LVar0, -1100)
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

EvtScript N(EVS_TravelToToadTown) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(MF_TrainScrolling, TRUE)
    EVT_SET(MF_TrainReverseDir, TRUE)
    EVT_EXEC(N(EVS_UpdatePassengerPos))
    EVT_THREAD
        EVT_CALL(MakeLerp, 6400, -5600, 1200, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_TrainMoveDist, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(1200)
    EVT_CALL(GotoMap, EVT_PTR("mac_03"), mac_03_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TravelToMtRugged) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(EVS_UpdatePassengerPos))
    EVT_SET(MF_TrainScrolling, TRUE)
    EVT_CALL(MakeLerp, 0, 6350, 600, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_TrainMoveDist, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
        EVT_SET(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
    EVT_END_IF
    EVT_IF_EQ(GF_StartedChapter2, FALSE)
        EVT_SET(GF_StartedChapter2, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_2, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("iwa_10"), iwa_10_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitializeTrainScene) = {
    EVT_CALL(EnableModel, MODEL_km, FALSE)
    EVT_CALL(SetModelFlags, MODEL_km, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(0))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(1))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(2))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(3))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(4))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(5))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(6))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(7))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(8))
    EVT_CALL(CloneModel, MODEL_km, CLONED_MODEL(9))
    EVT_SET(MF_TrainReverseDir, FALSE)
    EVT_SET(MV_TrainMoveDist, -6000)
    EVT_SET(MV_TrainMoveSpeed, 10)
    EVT_EXEC(N(EVS_AnimateTrain))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
