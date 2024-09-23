#include "trd_07.h"
#include "effects.h"

API_CALLABLE(N(GetPointsWithCamRelativeOffset)) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);

    script->varTable[0] = FLOAT_TO_FIXED(posX + (sin_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 270.0f)) * 1000.0f));
    script->varTable[1] = FLOAT_TO_FIXED(posZ - (cos_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 270.0f)) * 1000.0f));
    script->varTable[2] = FLOAT_TO_FIXED(posX + (sin_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 90.0f)) * 1000.0f));
    script->varTable[3] = FLOAT_TO_FIXED(posZ - (cos_deg(clamp_angle(gCameras[CAM_DEFAULT].curYaw + angle + 90.0f)) * 1000.0f));
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
    Thread
        Wait(20)
        Call(PlaySound, SOUND_TRD_MAGIC_DOOR_JUMP)
    EndThread
    Thread
        // input LVar0 ignored in this thread
        Call(MakeLerp, 100, 120, 20, EASING_QUADRATIC_IN)
        Label(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleZ, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
        Call(MakeLerp, 120, 80, 20, EASING_QUADRATIC_OUT)
        Label(1)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleZ, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 80, 100, 20, EASING_QUADRATIC_IN)
        Label(2)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleZ, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndThread
    Thread
        // input LVar0 ignored in this thread
        Call(MakeLerp, 100, 80, 20, EASING_QUADRATIC_IN)
        Label(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleY, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
        Call(MakeLerp, 80, 120, 20, EASING_QUADRATIC_OUT)
        Label(1)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleY, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 120, 100, 20, EASING_QUADRATIC_IN)
        Label(2)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SetF(MV_DoorScaleY, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndThread
    SetF(MV_DoorScaleZ, Float(1.0))
    SetF(MV_DoorScaleY, Float(1.0))
    Thread
        // input LVar0 used in this thread!
        Set(LVar9, LVar0)
        Loop(20)
            Call(ScaleGroup, LVar9, Float(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            Wait(1)
        EndLoop
        Call(MakeLerp, 0, 80, 30, EASING_QUADRATIC_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar9, 0, LVar0, 0)
            Call(ScaleGroup, LVar9, Float(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 80, 70, 10, EASING_QUADRATIC_IN)
        Label(2)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar9, 0, LVar0, 0)
            Call(ScaleGroup, LVar9, Float(1.0), MV_DoorScaleY, MV_DoorScaleZ)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndThread
    Wait(61)
    Return
    End
};

// LVar0 = modelID
EvtScript N(EVS_AnimateDoorLowering) = {
    Set(LVar9, LVar0)
    Call(MakeLerp, 70, 0, 20, EASING_CUBIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateGroup, LVar9, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(PlaySound, SOUND_TRD_MAGIC_DOOR_LAND)
    IfEq(LVar9, MODEL_migi)
        Call(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        Call(N(SpawnMovingDoorDust), 270, 0, -40, 270)
    Else
        Call(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        Call(N(SpawnMovingDoorDust), -255, 0, -40, 90)
    EndIf
    Call(MakeLerp, 0, 20, 10, EASING_QUADRATIC_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateGroup, LVar9, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(MakeLerp, 20, 0, 10, EASING_QUADRATIC_IN)
    Label(2)
        Call(UpdateLerp)
        Call(TranslateGroup, LVar9, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(PlaySound, SOUND_TRD_MAGIC_DOOR_LAND)
    IfEq(LVar9, MODEL_migi)
        Call(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        Call(N(SpawnMovingDoorDust), 270, 0, -40, 270)
    Else
        Call(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        Call(N(SpawnMovingDoorDust), -255, 0, -40, 90)
    EndIf
    Call(MakeLerp, 0, 10, 5, EASING_QUADRATIC_OUT)
    Label(3)
        Call(UpdateLerp)
        Call(TranslateGroup, LVar9, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Call(MakeLerp, 10, 0, 5, EASING_QUADRATIC_IN)
    Label(4)
        Call(UpdateLerp)
        Call(TranslateGroup, LVar9, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(4)
        EndIf
    Call(PlaySound, SOUND_TRD_MAGIC_DOOR_LAND)
    IfEq(LVar9, MODEL_migi)
        Call(N(SpawnMovingDoorDust), 270, 0, 40, 270)
        Call(N(SpawnMovingDoorDust), 270, 0, -40, 270)
        Call(EnableModel, MODEL_o44, FALSE)
    Else
        Call(N(SpawnMovingDoorDust), -255, 0, 40, 90)
        Call(N(SpawnMovingDoorDust), -255, 0, -40, 90)
        Call(EnableModel, MODEL_o43, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RaiseMagicDoors) = {
    // for for enter walk scrip to complete
    Label(10)
        IsThreadRunning(MV_EnterWalkScriptID, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(10)
        EndIf
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(DisablePlayerInput, TRUE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, Float(30.0))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableModel, MODEL_o44, TRUE)
    Set(LVar0, MODEL_migi)
    ExecWait(N(EVS_AnimateDoorRaising))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, 400)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, Float(-60.0))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableModel, MODEL_o43, TRUE)
    Set(LVar0, MODEL_hidari)
    ExecWait(N(EVS_AnimateDoorRaising))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    ResumeGroup(EVT_GROUP_01)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_LowerMagicDoors) = {
    Call(DisablePlayerInput, TRUE)
    Wait(15)
    Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    Wait(15)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_VEC3I_SET(LVar0, 220, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, Float(30.0))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(LVar0, MODEL_migi)
    ExecWait(N(EVS_AnimateDoorLowering))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Wait(1)
    EVT_VEC3I_SET(LVar0, 220, 0, 0)
    Sub(LVar0, 400)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetPointsWithCamRelativeOffset), LVar0, LVar2, Float(-60.0))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(LVar0, MODEL_hidari)
    ExecWait(N(EVS_AnimateDoorLowering))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_RestoreMagicDoors) = {
    Exec(N(EVS_LowerMagicDoors))
    Return
    End
};

EvtScript N(EVS_SetupMagicDoors) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o44, FALSE)
    Call(EnableModel, MODEL_o43, FALSE)
    IfEq(GF_TRD07_Defeated_DungeonAmbush, FALSE)
        Exec(N(EVS_RaiseMagicDoors))
    EndIf
    Return
    End
};
