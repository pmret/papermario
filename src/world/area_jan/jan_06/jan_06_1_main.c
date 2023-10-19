#include "jan_06.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_jan_05_3) = EVT_EXIT_WALK(60, jan_06_ENTRY_0, "jan_05", jan_05_ENTRY_3);
EvtScript N(EVS_ExitWalk_jan_07_0) = EVT_EXIT_WALK(60, jan_06_ENTRY_1, "jan_07", jan_07_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_12_0) = EVT_EXIT_WALK(60, jan_06_ENTRY_2, "jan_12", jan_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_09_1) = EVT_EXIT_WALK(60, jan_06_ENTRY_3, "jan_09", jan_09_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_05_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitRavenStatueObjects) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_MOVED_RAVEN_STATUE)
        EVT_CALL(TranslateModel, MODEL_o55, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o56, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o57, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o58, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o146, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o147, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o148, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o151, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o162, 0, 0, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o180, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(TranslateModel, MODEL_o55, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o56, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o57, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o58, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o146, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o147, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o148, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o151, -100, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o162, -100, 0, 0)
        EVT_CALL(RotateModel, MODEL_o55, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o56, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o57, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o146, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o147, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o148, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o151, 0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o162, 0, 0, 1, 0)
        EVT_CALL(MakeItemEntity, ITEM_JADE_RAVEN, -100, 15, -400, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o247, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(SetZoneEnabled, ZONE_o59, FALSE)
    EVT_EXEC(N(EVS_InitRavenStatueObjects))
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o69, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o71, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o74, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o69, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o71, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o74, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o257, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o258, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o259, SURFACE_TYPE_WATER)
    EVT_EXEC(N(EVS_SetupStatue))
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_SetupLogs))
    EVT_CALL(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(MakeTransformGroup, MODEL_g14)
    EVT_CALL(EnableTexPanning, MODEL_o61, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
