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
            mdl_group_set_visibility(MODEL_g70, MODEL_FLAG_HIDDEN, MODEL_GROUP_HIDDEN);
            N(PrevPalmTreeVisibility) = FALSE;
        }
    } else {
        if (currentFloor == COLLIDER_o319 || currentFloor == COLLIDER_o316) {
            mdl_group_set_visibility(MODEL_g70, MODEL_FLAG_HIDDEN, MODEL_GROUP_VISIBLE);
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
    SetGroup(EVT_GROUP_1B)
    Call(N(ClearTrackVols))
    Call(UseExitHeading, 60, jan_02_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("jan_01"), jan_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_jan_03_0) = EVT_EXIT_WALK(60, jan_02_ENTRY_1, "jan_03", jan_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

s32 N(PrevPalmTreeVisibility) = TRUE;

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_YOSHIS_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Call(SetModelTexVariant, MODEL_o120, LVar0)
#endif
    Set(GF_MAP_YoshisVillage, TRUE)
    Set(AF_JAN02_RaphaelComment, FALSE)
    Set(AF_JAN02_MetCouncillor, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupFoliage))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_JAN_BEACH_WAVES)
    Call(EnableTexPanning, MODEL_o202, TRUE)
    Call(EnableTexPanning, MODEL_o203, TRUE)
    Call(EnableTexPanning, MODEL_o103, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -100,  200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        Call(N(ManageBigPalmTreeVisibility))
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o337, SURFACE_TYPE_WATER)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o338, SURFACE_TYPE_WATER)
    Return
    End
};
