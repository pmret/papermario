#include "trd_03.h"

#define FLOOR_RETRACT_LENGTH -95
#define WALL_RETRACT_LENGTH -145

API_CALLABLE(N(GetLeftRightPoints)) {
    Bytecode* args = script->ptrReadPos;
    s32 switchPosX = evt_get_variable(script, *args++);
    s32 switchPosZ = evt_get_variable(script, *args++);
    f32 dist = evt_get_variable(script, *args++);

    script->varTable[0] = switchPosX + (sin_deg(gCameras[CAM_DEFAULT].currentYaw + 270.0f + dist) * 100.0f);
    script->varTable[1] = switchPosZ - (cos_deg(gCameras[CAM_DEFAULT].currentYaw + 270.0f + dist) * 100.0f);
    script->varTable[2] = switchPosX + (sin_deg(gCameras[CAM_DEFAULT].currentYaw + 90.0f + dist) * 100.0f);
    script->varTable[3] = switchPosZ - (cos_deg(gCameras[CAM_DEFAULT].currentYaw + 90.0f + dist) * 100.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_InitializePlatforms) = {
    EVT_CALL(TranslateModel, MODEL_1, 0, 0, FLOOR_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_2, 0, 0, FLOOR_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_3, 0, 0, FLOOR_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_4, 0, 0, FLOOR_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_5, 0, 0, WALL_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_6, 0, 0, WALL_RETRACT_LENGTH)
    EVT_CALL(TranslateModel, MODEL_7, 0, 0, WALL_RETRACT_LENGTH)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o75, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o74, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o73, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(MV_PlatformsExtended, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RetractPlatform) = {
    EVT_CALL(MakeLerp, 0, LVar8, 7, EASING_CUBIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar9, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, 0, LVar7, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySound, SOUND_26)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExtendPlatform) = {
    EVT_CALL(MakeLerp, LVar8, 0, 7, EASING_CUBIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar9, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar7, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySound, SOUND_26)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TogglePlatforms_LeftSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(123)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
        EVT_GOTO(123)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -315, 120, -50)
    EVT_CALL(N(GetLeftRightPoints), -315, -100, 60)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_IF_EQ(MV_PlatformsExtended, FALSE)
        EVT_SET(LVar7, COLLIDER_o73)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_7)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_4)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_4)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_3)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_3)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o74)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_6)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_2)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_2)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_1)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_1)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o75)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_5)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(MV_PlatformsExtended, TRUE)
    EVT_ELSE
        EVT_SET(LVar7, COLLIDER_o75)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_5)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_1)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_1)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_2)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_2)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o74)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_6)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_3)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_3)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_4)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_4)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o73)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_7)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(MV_PlatformsExtended, FALSE)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TogglePlatforms_RightSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(123)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
        EVT_GOTO(123)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 210, 120, -50)
    EVT_CALL(N(GetLeftRightPoints), 210, -100, -60)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_IF_EQ(MV_PlatformsExtended, FALSE)
        EVT_SET(LVar7, COLLIDER_o75)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_5)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_1)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_1)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_2)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_2)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o74)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_6)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_3)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_3)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_4)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_4)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o73)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_7)
        EVT_EXEC(N(EVS_ExtendPlatform))
        EVT_WAIT(9)
        EVT_SET(MV_PlatformsExtended, TRUE)
    EVT_ELSE
        EVT_SET(LVar7, COLLIDER_o73)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_7)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_4)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_4)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_3)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_3)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o74)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_6)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_2)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_2)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_1)
        EVT_SET(LVar8, FLOOR_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_1)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(LVar7, COLLIDER_o75)
        EVT_SET(LVar8, WALL_RETRACT_LENGTH)
        EVT_SET(LVar9, MODEL_5)
        EVT_EXEC(N(EVS_RetractPlatform))
        EVT_WAIT(9)
        EVT_SET(MV_PlatformsExtended, FALSE)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
