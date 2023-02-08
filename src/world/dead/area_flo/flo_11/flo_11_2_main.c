#include "flo_11.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_23_1) = EVT_EXIT_WALK(60, flo_11_ENTRY_0, "flo_23", flo_23_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_12_0) = EVT_EXIT_WALK(60, flo_11_ENTRY_1, "flo_12", flo_12_ENTRY_0);

// template for GotoMap exits used with pipes in the maze
#define EVT_GOTO_MAP(mapName, entry) \
{ \
    EVT_SET_GROUP(EVT_GROUP_1B) \
    EVT_CALL(GotoMap, EVT_PTR(mapName), entry) \
    EVT_WAIT(100) \
    EVT_RETURN \
    EVT_END \
}

// template for binding the event for the generic EVS_OnEnterPipe
#define EVT_SETUP_PIPE(entry, collider, exitScript) \
    EVT_SET(LVar0, entry) \
    EVT_SET(LVar1, collider) \
    EVT_SET(LVar2, EVT_PTR(exitScript)) \
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)

EvtScript N(EVS_GotoMap_flo_11_5) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_5);
EvtScript N(EVS_GotoMap_flo_11_6) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_6);
EvtScript N(EVS_GotoMap_flo_11_7) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_7);
EvtScript N(EVS_GotoMap_flo_11_2) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_2);
EvtScript N(EVS_GotoMap_flo_11_3) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_3);
EvtScript N(EVS_GotoMap_flo_11_4) = EVT_GOTO_MAP("flo_11", flo_11_ENTRY_4);

EvtScript N(EVS_OnEnterPipe) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_23_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_SETUP_PIPE(flo_11_ENTRY_2, COLLIDER_o91, N(EVS_GotoMap_flo_11_5)) // link 2 <--> 5
    EVT_SETUP_PIPE(flo_11_ENTRY_3, COLLIDER_o92, N(EVS_GotoMap_flo_11_6)) // link 3 <--> 6
    EVT_SETUP_PIPE(flo_11_ENTRY_4, COLLIDER_o93, N(EVS_GotoMap_flo_11_7)) // link 4 <--> 7
    EVT_SETUP_PIPE(flo_11_ENTRY_5, COLLIDER_o94, N(EVS_GotoMap_flo_11_2)) // link 2 <--> 5
    EVT_SETUP_PIPE(flo_11_ENTRY_6, COLLIDER_o95, N(EVS_GotoMap_flo_11_3)) // link 3 <--> 6
    EVT_SETUP_PIPE(flo_11_ENTRY_7, COLLIDER_o96, N(EVS_GotoMap_flo_11_4)) // link 4 <--> 7
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(func_80044238, 7)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LE(LVar0, flo_11_ENTRY_1)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_EXEC(N(EVS_Scene_LakituAmbush))
        EVT_WAIT(1)
    EVT_ELSE
        EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(N(EVS_Pipe_EnterVertical))
        EVT_WAIT(1)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o90, SURFACE_TYPE_HEDGES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o104, SURFACE_TYPE_HEDGES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o105, SURFACE_TYPE_HEDGES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o109, SURFACE_TYPE_HEDGES)
    EVT_RETURN
    EVT_END
};
