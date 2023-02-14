#include "tik_04.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_05_0) = EVT_EXIT_WALK(60, tik_04_ENTRY_0, "tik_05", tik_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_tik_07_0) = EVT_EXIT_WALK(60, tik_04_ENTRY_1, "tik_07", tik_07_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_03_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_03"), tik_03_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_03_1) = EVT_EXIT_PIPE_HORIZONTAL(tik_04_ENTRY_2, COLLIDER_ttd, N(EVS_GotoMap_tik_03_1));

EvtScript N(EVS_GotoMap_tik_12_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_12"), tik_12_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_12_0) = EVT_EXIT_PIPE_VERTICAL(tik_04_ENTRY_3, COLLIDER_ttd2, N(EVS_GotoMap_tik_12_0));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_03_1)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_12_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_ttd2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_04)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(EnableTexPanning, MODEL_mizu, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupPlatforms))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_04_ENTRY_2)
            EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_04_ENTRY_3)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
