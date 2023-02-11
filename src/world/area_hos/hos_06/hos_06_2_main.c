#include "hos_06.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_TexPan_MysticPyramid) = {
    EVT_CALL(EnableTexPanning, MODEL_o185, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x4000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Animate_MysticPyramid) = {
    EVT_EXEC(N(EVS_TexPan_MysticPyramid))
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_CALL(RotateGroup, MODEL_g87, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g88, LVar0, 0, 1, 0)
        EVT_ADD(LVar0, 6)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_hos_00_2) = EVT_EXIT_WALK(60, hos_06_ENTRY_0, "hos_00", hos_00_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_00_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Stars) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -100,    0,   40,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o103, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -200,    0,  100,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o105, TEX_PANNER_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_SET(AF_HOS06_SpokeWithMerluvlee, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMagicChest))
    EVT_EXEC(N(EVS_Animate_MysticPyramid))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_TexPan_Stars))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_AskForHint)), TRIGGER_WALL_PRESS_A, COLLIDER_o224, 1, 0)
    EVT_RETURN
    EVT_END
};
