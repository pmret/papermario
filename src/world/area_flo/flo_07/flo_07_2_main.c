#include "flo_07.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "../common/FlowerSpawnRegion.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_flo_25_1) = EVT_EXIT_WALK(60, flo_07_ENTRY_0, "flo_25", flo_25_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_25_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
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
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(AF_FLO_MadeCrystalBerry, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o76, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION(  297,  -95,  383,  -65,    0 )
    EVT_FLOWER_SPAWN_REGION(  293,   71,  378,  113,    0 )
    EVT_FLOWER_SPAWN_REGION(   21, -346,  147, -242,   20 )
    EVT_FLOWER_SPAWN_REGION( -350, -190,  -81, -106,    0 )
    EVT_FLOWER_SPAWN_REGION( -380,   85,  -95,  150,    0 )
    EVT_CALL(EnableTexPanning, MODEL_o51, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o36, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o37, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -100,  100,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0,-1200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_07_ENTRY_1)
        EVT_EXEC(N(EVS_Scene_SunReturns))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(EVS_TryKickingPlayerOut))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_CALL(N(CreateCrystalTreeSparkles))
    EVT_RETURN
    EVT_END
};
