#include "tik_06.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_01_0) = EVT_EXIT_WALK(60, tik_06_ENTRY_0, "tik_01", tik_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_tik_18_0) = EVT_EXIT_WALK(60, tik_06_ENTRY_1, "tik_18", tik_18_ENTRY_0);

EvtScript N(EVS_GotoMap_mac_02_4) = {
    EVT_CALL(GotoMap, EVT_PTR("mac_02"), mac_02_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_Upward) = EVT_EXIT_PIPE_HORIZONTAL(tik_06_ENTRY_3,
    COLLIDER_o89, N(EVS_GotoMap_mac_02_4));

EvtScript N(EVS_GotoMap_tik_08_3) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_08"), tik_08_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_Downward) = EVT_EXIT_PIPE_VERTICAL(tik_06_ENTRY_2,
    COLLIDER_o57, N(EVS_GotoMap_tik_08_3));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_Upward)), TRIGGER_WALL_PUSH, COLLIDER_o89, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_Downward)), TRIGGER_FLOOR_TOUCH, COLLIDER_o57, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_06_ENTRY_2)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(tik_06_ENTRY_3)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_SET(LVarB, COLLIDER_o89)
            EVT_EXEC(N(EVS_Pipe_EnterHorizontal))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_06)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_ToadTownTunnels, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_TIK06_WATER)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW2, SOUND_SPACE_WITH_DEPTH, -85, -180, 120)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW3, SOUND_SPACE_WITH_DEPTH, -25, -140, -130)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW4, SOUND_SPACE_WITH_DEPTH, -35, -180, 130)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(EnableTexPanning, MODEL_nagare1, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   50,  200,  110,  500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_mizu, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_mizu2, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0, -250, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_taki, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o72, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o73, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  -50, -900,  -70,-1200)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
