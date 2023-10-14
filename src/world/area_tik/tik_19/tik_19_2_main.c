#include "tik_19.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_mac_00_3) = {
    EVT_CALL(GotoMap, EVT_PTR("mac_00"), mac_00_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_mac_00_3) = EVT_EXIT_PIPE_HORIZONTAL(tik_19_ENTRY_0, COLLIDER_ttd, N(EVS_GotoMap_mac_00_3));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_mac_00_3)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_TIK19_WATER)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK19_FLOW3, SOUND_SPACE_WITH_DEPTH, 0, -20, 30)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK19_FLOW4, SOUND_SPACE_WITH_DEPTH, 270, -20, 30)
    EVT_CALL(EnableTexPanning, MODEL_nagare, TRUE)
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
    EVT_CALL(SetRenderMode, MODEL_nagare, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
