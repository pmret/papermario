#include "kzn_06.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kzn_05) = EVT_EXIT_WALK(60, kzn_06_ENTRY_0, "kzn_05", kzn_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_08) = EVT_EXIT_WALK(60, kzn_06_ENTRY_2, "kzn_08", kzn_08_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_07) = EVT_EXIT_WALK(60, kzn_06_ENTRY_1, "kzn_07", kzn_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_05), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_08), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_07), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, unk); // can be fixed with subalign 16 for this map

EvtScript N(EVS_StartTexPanners) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yo1, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o349, TEX_PANNER_0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   0, -400,   0,   0)
        TEX_PAN_PARAMS_FREQ(   0,    1,   0,   0)
        TEX_PAN_PARAMS_INIT(   0,    0,   0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_yougan, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_spot, TEX_PANNER_1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 400,   0, 800,   0)
        TEX_PAN_PARAMS_FREQ(   1,   0,   1,   0)
        TEX_PAN_PARAMS_INIT(   0,   0,   0,   0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o250, .pos = {   10.0, 145.0, -35.0 }},
    { .colliderID = COLLIDER_o468, .pos = { -150.0, 145.0, -35.0 }},
    { .colliderID = COLLIDER_o394, .pos = { -210.0,  75.0, 100.0 }},
    { .colliderID = COLLIDER_o440, .pos = {   60.0,  75.0, 100.0 }},
    { .colliderID = COLLIDER_o437, .pos = {   60.0,  75.0, 100.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_06)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_KZN06_Visited, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_LAVA_STREAM_BLOCKED)
        EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_2)
    EVT_ELSE
        EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_END_IF
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan, SURFACE_TYPE_LAVA)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan1, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_StartTexPanners))
    EVT_EXEC(N(EVS_SetupLavaPuzzle))
    EVT_RETURN
    EVT_END
};

