#include "jan_02.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

extern s32 N(PrevPalmTreeVisibility);

API_CALLABLE(N(ClearTrackVols)) {
    bgm_clear_track_volumes(0, TRACK_VOLS_0);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ManageBigPalmTreeVisibility)) {
    u16 currentFloor = gCollisionStatus.curFloor;

    if (N(PrevPalmTreeVisibility) != 0) {
        if (currentFloor == COLLIDER_o327 || currentFloor == COLLIDER_o330) {
            set_model_group_visibility(MODEL_g70, MODEL_FLAG_HIDDEN, MODEL_GROUP_HIDDEN);
            N(PrevPalmTreeVisibility) = FALSE;
        }
    } else {
        if (currentFloor == COLLIDER_o319 || currentFloor == COLLIDER_o316) {
            set_model_group_visibility(MODEL_g70, MODEL_FLAG_HIDDEN, MODEL_GROUP_VISIBLE);
            N(PrevPalmTreeVisibility) = TRUE;
        }
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_jan_01_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(ClearTrackVols))
    EVT_CALL(UseExitHeading, 60, jan_02_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("jan_01"), jan_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_jan_03_0) = EVT_EXIT_WALK(60, jan_02_ENTRY_1, "jan_03", jan_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(PrevPalmTreeVisibility) = TRUE;

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_YOSHIS_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_o120, LVar0)
#endif
    EVT_SET(GF_MAP_YoshisVillage, TRUE)
    EVT_SET(AF_JAN02_RaphaelComment, FALSE)
    EVT_SET(AF_JAN02_MetCouncillor, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_80000017)
    EVT_CALL(EnableTexPanning, MODEL_o202, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o203, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o103, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -100,  200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(ManageBigPalmTreeVisibility))
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o337, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o338, SURFACE_TYPE_WATER)
    EVT_RETURN
    EVT_END
};
