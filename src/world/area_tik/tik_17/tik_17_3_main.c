#include "tik_17.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_sam_02_2) = {
    EVT_IF_EQ(GF_StartedChapter7, FALSE)
        EVT_SET(GF_StartedChapter7, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_7, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("sam_02"), sam_02_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_sam_02_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_17_ENTRY_1, COLLIDER_o105, N(EVS_GotoMap_sam_02_2));

EvtScript N(EVS_GotoMap_tik_22_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_22"), tik_22_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_22_1) = EVT_EXIT_PIPE_VERTICAL(tik_17_ENTRY_0, COLLIDER_o58, N(EVS_GotoMap_tik_22_1));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_sam_02_2)), TRIGGER_WALL_PUSH, COLLIDER_o105, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_22_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o58, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, tik_17_ENTRY_0)
        EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o105, N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(SetTexPanner, MODEL_kiri, TEX_PANNER_1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -300,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
