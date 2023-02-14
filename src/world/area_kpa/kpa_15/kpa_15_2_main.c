#include "kpa_15.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(D_8024074C_A59ADC) = EVT_EXIT_WALK(40, kpa_15_ENTRY_0, "kpa_13", kpa_13_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_8024074C_A59ADC)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802407D4_A59B64) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240800_A59B90) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o811, 0)
    EVT_CALL(SetTexPanner, MODEL_o813, 0)
    EVT_CALL(SetTexPanner, MODEL_o814, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(EnableGroup, MODEL_after, FALSE)
        EVT_EXEC(N(D_80240800_A59B90))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_END_IF
    EVT_EXEC(N(D_802407D4_A59B64))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o781, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_LAVA)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
