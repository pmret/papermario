#include "tik_14.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_15_0) = EVT_EXIT_WALK(60, tik_14_ENTRY_1, "tik_15", tik_15_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_21_2) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_21"), tik_21_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_21_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_14_ENTRY_0, COLLIDER_o47, N(EVS_GotoMap_tik_21_2));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_21_2)), TRIGGER_WALL_PUSH, COLLIDER_o47, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o47, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_14_ENTRY_0)
            EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o47, N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_14_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_14)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(EnableTexPanning, MODEL_mizu, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o47, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
