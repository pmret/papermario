#include "flo_19.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_21_0) = EVT_EXIT_WALK(60, flo_19_ENTRY_1, "flo_21", flo_21_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_21_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CLOUDY_CLIMB)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_CloudyClimb, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ParentColliderToModel, COLLIDER_o117, MODEL_o142)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(EVS_SetupBeanstalk))
    EVT_EXEC(N(EVS_SetupClouds))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o122, SURFACE_TYPE_CLOUD)
    EVT_CALL(EnableTexPanning, MODEL_o59, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o60, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -120,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  -90,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, flo_19_ENTRY_3)
        EVT_SET(AF_FLO_RidingBeanstalk, FALSE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(flo_19_ENTRY_0)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(flo_19_ENTRY_1)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(flo_19_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_BeanstalkGrowing))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(flo_19_ENTRY_3)
            EVT_EXEC(N(EVS_Enter_Beanstalk))
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
