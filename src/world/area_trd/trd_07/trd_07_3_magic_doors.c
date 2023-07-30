#include "trd_07.h"
#include "effects.h"

API_CALLABLE(N(GetPointsWithCamRelativeOffset)) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);

    script->varTable[0] = EVT_FLOAT_TO_FIXED(posX + (sin_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 270.0f)) * 1000.0f));
    script->varTable[1] = EVT_FLOAT_TO_FIXED(posZ - (cos_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 270.0f)) * 1000.0f));
    script->varTable[2] = EVT_FLOAT_TO_FIXED(posX + (sin_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 90.0f)) * 1000.0f));
    script->varTable[3] = EVT_FLOAT_TO_FIXED(posZ - (cos_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 90.0f)) * 1000.0f));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnMovingDoorDust)) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    f32 yaw = evt_get_variable(script, *args++);

    fx_walking_dust(1, posX, posY + 10, posZ, sin_deg(yaw), -cos_deg(yaw));
    return ApiStatus_DONE2;
}

// LVar0 = modelID
EvtScript N(EVS_AnimateDoorRaising) = {
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2B)
    EVT_END_THREAD
    EVT_THREAD
        // input LVar0 ignored in this thread
        EVT_CALL(MakeLerp, 100, 120, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleZ, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CALL(MakeLerp, 120, 80, 20, EASING_QUADRATIC_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleZ, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 80, 100, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleZ, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        // input LVar0 ignored in this thread
        EVT_CALL(MakeLerp, 100, 80, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleY, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CALL(MakeLerp, 80, 120, 20, EASING_QUADRATIC_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleY, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 120, 100, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SETF(MV_DoorScaleY, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_SETF(MV_DoorScaleZ, EVT_FLOAT(1.0))
    EVT_SETF(MV_DoorScaleY, EVT_FLOAT(1.0))
    EVT_THREAD
        // input LVar0 used in this thread!
        EVT_SET(LVar9, LVar0)
        EVT_LOOP(20)
            EVT_CALL(ScaleGroup, LVar9, EVT_FLOAT(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 0, 80, 30, EASING_QUADRATIC_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
            EVT_CALL(ScaleGroup, LVar9, EVT_FLOAT(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 80, 70, 10, EASING_QUADRATIC_IN)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
            EVT_CALL(ScaleGroup, LVar9, EVT_FLOAT(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(61)
    EVT_RETURN
    EVT_END
};

// LVar0 = modelID
EvtScript N(EVS_AnimateDoorLowering) = {
    EVT_SET(LVar9, LVar0)
    EVT_CALL(MakeLerp, 70, 0, 20, EASING_CUBIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySound, SOUND_2C)
    EVT_IF_EQ(LVar9, MODEL_migi)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, -40, 270)
    EVT_ELSE
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, -40, 90)
    EVT_END_IF
    EVT_CALL(MakeLerp, 0, 20, 10, EASING_QUADRATIC_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(MakeLerp, 20, 0, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(PlaySound, SOUND_2C)
    EVT_IF_EQ(LVar9, MODEL_migi)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, -40, 270)
    EVT_ELSE
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, -40, 90)
    EVT_END_IF
    EVT_CALL(MakeLerp, 0, 10, 5, EASING_QUADRATIC_OUT)
    EVT_LABEL(3)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(3)
        EVT_END_IF
    EVT_CALL(MakeLerp, 10, 0, 5, EASING_QUADRATIC_IN)
    EVT_LABEL(4)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LVar9, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(4)
        EVT_END_IF
    EVT_CALL(PlaySound, SOUND_2C)
    EVT_IF_EQ(LVar9, MODEL_migi)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        EVT_CALL(N(SpawnMovingDoorDust), 270, 0, -40, 270)
        EVT_CALL(EnableModel, MODEL_o44, FALSE)
    EVT_ELSE
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        EVT_CALL(N(SpawnMovingDoorDust), -255, 0, -40, 90)
        EVT_CALL(EnableModel, MODEL_o43, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseMagicDoors) = {
    // for for enter walk scrip to complete
    EVT_LABEL(10)
        EVT_IS_THREAD_RUNNING(MV_EnterWalkScriptID, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySound, SOUND_A)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, EVT_FLOAT(30.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableModel, MODEL_o44, TRUE)
    EVT_SET(LVar0, MODEL_migi)
    EVT_EXEC_WAIT(N(EVS_AnimateDoorRaising))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 400)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, EVT_FLOAT(-60.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableModel, MODEL_o43, TRUE)
    EVT_SET(LVar0, MODEL_hidari)
    EVT_EXEC_WAIT(N(EVS_AnimateDoorRaising))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerMagicDoors) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_B)
    EVT_WAIT(15)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_VEC3I_SET(LVar0, 220, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, EVT_FLOAT(30.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(LVar0, MODEL_migi)
    EVT_EXEC_WAIT(N(EVS_AnimateDoorLowering))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(1)
    EVT_VEC3I_SET(LVar0, 220, 0, 0)
    EVT_SUB(LVar0, 400)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, EVT_FLOAT(-60.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(LVar0, MODEL_hidari)
    EVT_EXEC_WAIT(N(EVS_AnimateDoorLowering))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RestoreMagicDoors) = {
    EVT_EXEC(N(EVS_LowerMagicDoors))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMagicDoors) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o44, FALSE)
    EVT_CALL(EnableModel, MODEL_o43, FALSE)
    EVT_IF_EQ(GF_TRD07_Defeated_DungeonAmbush, FALSE)
        EVT_EXEC(N(EVS_RaiseMagicDoors))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
