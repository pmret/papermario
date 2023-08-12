#include "flo_16.h"

API_CALLABLE(N(CheckForPoundInput)) {
    script->varTable[0] = FALSE;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnTouch_RedPillar) = {
    EVT_CALL(N(CheckForPoundInput))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AF_FLO_RaisedRedPillar, FALSE)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 50)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 180)
        EVT_SET(AF_FLO_RaisedRedPillar, TRUE)
    EVT_ELSE
        EVT_SET(LVar5, 50)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 180)
        EVT_SET(LVar8, 0)
        EVT_SET(AF_FLO_RaisedRedPillar, FALSE)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_FLO_MOVE_PILLAR)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g81, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g82, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_g85, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g86, 0, LVar0, 0)
        EVT_CALL(RotateGroup, MODEL_g82, LVar7, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g86, LVar7, 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o242)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o250)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o244)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o252)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g81, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g82, 0, LVar6, 0)
        EVT_CALL(TranslateModel, MODEL_g85, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g86, 0, LVar6, 0)
        EVT_CALL(RotateGroup, MODEL_g82, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g86, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_GreenPillar) = {
    EVT_CALL(N(CheckForPoundInput))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AF_FLO_RaisedGreenPillar, FALSE)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 50)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 180)
        EVT_SET(AF_FLO_RaisedGreenPillar, TRUE)
    EVT_ELSE
        EVT_SET(LVar5, 50)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 180)
        EVT_SET(LVar8, 0)
        EVT_SET(AF_FLO_RaisedGreenPillar, FALSE)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_FLO_MOVE_PILLAR)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g83, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g84, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_g87, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g88, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_g91, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g92, 0, LVar0, 0)
        EVT_CALL(RotateGroup, MODEL_g84, LVar7, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g88, LVar7, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g92, LVar7, 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o243)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o251)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o245)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o253)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o247)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o255)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g83, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g84, 0, LVar6, 0)
        EVT_CALL(TranslateModel, MODEL_g87, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g88, 0, LVar6, 0)
        EVT_CALL(TranslateModel, MODEL_g91, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g92, 0, LVar6, 0)
        EVT_CALL(RotateGroup, MODEL_g84, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g88, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g92, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_PurplePillar) = {
    EVT_CALL(N(CheckForPoundInput))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AF_FLO_LoweredPurplePillar, FALSE)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, -50)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 180)
        EVT_SET(AF_FLO_LoweredPurplePillar, TRUE)
    EVT_ELSE
        EVT_SET(LVar5, -50)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 180)
        EVT_SET(LVar8, 0)
        EVT_SET(AF_FLO_LoweredPurplePillar, FALSE)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_FLO_MOVE_PILLAR)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g89, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g90, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_g93, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g94, 0, LVar0, 0)
        EVT_CALL(RotateGroup, MODEL_g90, LVar7, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g94, LVar7, 1, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o246)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o254)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o248)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o256)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g89, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g90, 0, LVar6, 0)
        EVT_CALL(TranslateModel, MODEL_g93, 0, LVar6, 0)
        EVT_CALL(TranslateGroup, MODEL_g94, 0, LVar6, 0)
        EVT_CALL(RotateGroup, MODEL_g90, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g94, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPillarPuzzle) = {
    EVT_SET(AF_FLO_RaisedRedPillar, FALSE)
    EVT_SET(AF_FLO_RaisedGreenPillar, FALSE)
    EVT_SET(AF_FLO_LoweredPurplePillar, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o242, MODEL_g81)
    EVT_CALL(ParentColliderToModel, COLLIDER_o250, MODEL_g81)
    EVT_CALL(ParentColliderToModel, COLLIDER_o243, MODEL_g83)
    EVT_CALL(ParentColliderToModel, COLLIDER_o251, MODEL_g83)
    EVT_CALL(ParentColliderToModel, COLLIDER_o244, MODEL_g85)
    EVT_CALL(ParentColliderToModel, COLLIDER_o252, MODEL_g85)
    EVT_CALL(ParentColliderToModel, COLLIDER_o245, MODEL_g87)
    EVT_CALL(ParentColliderToModel, COLLIDER_o253, MODEL_g87)
    EVT_CALL(ParentColliderToModel, COLLIDER_o246, MODEL_g89)
    EVT_CALL(ParentColliderToModel, COLLIDER_o254, MODEL_g89)
    EVT_CALL(ParentColliderToModel, COLLIDER_o247, MODEL_g91)
    EVT_CALL(ParentColliderToModel, COLLIDER_o255, MODEL_g91)
    EVT_CALL(ParentColliderToModel, COLLIDER_o248, MODEL_g93)
    EVT_CALL(ParentColliderToModel, COLLIDER_o256, MODEL_g93)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_RedPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o242, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o243, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_RedPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o244, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o245, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_PurplePillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o246, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o247, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_PurplePillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o248, 1, 0)
    EVT_RETURN
    EVT_END
};
