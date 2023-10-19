#include "jan_09.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_jan_10_0) = EVT_EXIT_WALK(60, jan_09_ENTRY_2, "jan_10", jan_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_08_2) = EVT_EXIT_WALK(60, jan_09_ENTRY_0, "jan_08", jan_08_ENTRY_2);
EvtScript N(EVS_ExitWalk_jan_06_3) = EVT_EXIT_WALK(60, jan_09_ENTRY_1, "jan_06", jan_06_ENTRY_3);

EvtScript N(EVS_GotoMap_jan_11_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(GotoMap, EVT_PTR("jan_11"), jan_11_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchFloor_Pipe) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o245, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_08_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_06_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_SET(LVar0, jan_09_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_o208)
    EVT_SET(LVar2, EVT_PTR(N(EVS_GotoMap_jan_11_0)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchFloor_Pipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(SetZoneEnabled, ZONE_o79, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o97, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o99, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o99, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1, SURFACE_TYPE_WATER)
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, jan_09_ENTRY_3)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(N(EVS_Pipe_EnterVertical))
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(MakeTransformGroup, MODEL_g51)
    EVT_CALL(EnableTexPanning, MODEL_o180, TRUE)
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
