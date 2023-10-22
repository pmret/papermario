#include "tik_08.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_09_1) = EVT_EXIT_WALK(60, tik_08_ENTRY_0, "tik_09", tik_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_tik_20_0) = EVT_EXIT_WALK(60, tik_08_ENTRY_1, "tik_20", tik_20_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_06_2) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_06"), tik_06_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_06_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_06_ENTRY_3, COLLIDER_ttd, N(EVS_GotoMap_tik_06_2));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_06_2)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_08)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_TIK08_WATER)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK08_FLOW1, SOUND_SPACE_WITH_DEPTH, -30, -30, -85)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(EnableTexPanning, MODEL_nagare1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o92, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,  100,  100,  130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_taki, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  -50, -900,  -70,-1200)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_takib, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-1400,-2600,  -60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o77, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o75, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o77, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o75, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_08_ENTRY_2)
            EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_08_ENTRY_4)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_08_ENTRY_3)
            EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
