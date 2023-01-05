#include "dgb_10.h"

EvtScript N(EVS_ExitWalk_dgb_09_3) = EVT_EXIT_WALK(40, dgb_10_ENTRY_0, "dgb_09", dgb_09_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_dgb_09_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_10_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(dgb_10_ENTRY_1)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 375, 0, -188)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 375, 0, -188)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_CALL(PlayerJump, 375, 0, -188, 20)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupHoles))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o117, FALSE)
    EVT_CALL(EnableModel, MODEL_o116, FALSE)
    EVT_CALL(EnableModel, MODEL_o113, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
