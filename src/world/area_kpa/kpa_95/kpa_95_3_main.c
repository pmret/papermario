#include "kpa_95.h"

EvtScript N(EVS_OpenCellDoor) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlayerMoveTo, -30, 15, 20)
    EVT_CALL(InterpPlayerYaw, 90, 2)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 140, 60, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o199, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_g35, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o297, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_94_0) = EVT_EXIT_WALK(60, kpa_95_ENTRY_0, "kpa_94", kpa_94_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_94_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o297, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
