#include "dgb_10.h"

EvtScript N(EVS_ExitWalk_dgb_09_3) = EVT_EXIT_WALK(40, dgb_10_ENTRY_0, "dgb_09", dgb_09_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_dgb_09_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_10_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(dgb_10_ENTRY_1)
            Call(UseSettingsFrom, CAM_DEFAULT, 375, 0, -188)
            Call(SetPanTarget, CAM_DEFAULT, 375, 0, -188)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(DisablePlayerInput, TRUE)
            Call(DisablePlayerPhysics, TRUE)
            Call(SetPlayerActionState, ACTION_STATE_JUMP)
            Wait(1)
            Call(SetPlayerJumpscale, Float(0.7))
            Call(PlayerJump, 375, 0, -188, 20)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Call(DisablePlayerPhysics, FALSE)
            Call(DisablePlayerInput, FALSE)
            Call(SetPlayerActionState, ACTION_STATE_IDLE)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupHoles))
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o117, FALSE)
    Call(EnableModel, MODEL_o116, FALSE)
    Call(EnableModel, MODEL_o113, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitt3, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Return
    End
};
