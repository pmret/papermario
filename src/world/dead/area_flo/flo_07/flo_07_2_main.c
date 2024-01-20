#include "flo_07.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_flo_25_1) = EVT_EXIT_WALK(60, flo_07_ENTRY_0, "flo_25", flo_25_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_25_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

API_CALLABLE(N(CreateCrystalTreeSparkles)) {
    EffectInstance* effect = fx_misc_particles(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    effect->data.miscParticles->innerColor.r = 240;
    effect->data.miscParticles->innerColor.g = 240;
    effect->data.miscParticles->innerColor.b = 240;
    effect->data.miscParticles->glowColor.r = 230;
    effect->data.miscParticles->glowColor.g = 230;
    effect->data.miscParticles->glowColor.b = 240;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    Set(AF_FLO_MadeCrystalBerry, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_SetupFoliage))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o76, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION(  297,  -95,  383,  -65,    0 )
    EVT_FLOWER_SPAWN_REGION(  293,   71,  378,  113,    0 )
    EVT_FLOWER_SPAWN_REGION(   21, -346,  147, -242,   20 )
    EVT_FLOWER_SPAWN_REGION( -350, -190,  -81, -106,    0 )
    EVT_FLOWER_SPAWN_REGION( -380,   85,  -95,  150,    0 )
    Call(EnableTexPanning, MODEL_o51, TRUE)
    Call(EnableTexPanning, MODEL_o36, TRUE)
    Call(EnableTexPanning, MODEL_o37, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -100,  100,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0,-1200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_07_ENTRY_1)
        Exec(N(EVS_Scene_SunReturns))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Exec(N(EVS_TryKickingPlayerOut))
    EndIf
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Call(N(CreateCrystalTreeSparkles))
    Return
    End
};
