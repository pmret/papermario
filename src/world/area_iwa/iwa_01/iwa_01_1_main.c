#include "iwa_01.h"

EvtScript N(EVS_ExitWalk_iwa_00_1) = EVT_EXIT_WALK(60, iwa_01_ENTRY_0, "iwa_00", iwa_00_ENTRY_1);
EvtScript N(EVS_ExitWalk_iwa_03_0) = EVT_EXIT_WALK(60, iwa_01_ENTRY_1, "iwa_03", iwa_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_iwa_02_0) = EVT_EXIT_WALK(60, iwa_01_ENTRY_2, "iwa_02", iwa_02_ENTRY_0);
EvtScript N(EVS_ExitWalk_iwa_02_1) = EVT_EXIT_WALK(60, iwa_01_ENTRY_3, "iwa_02", iwa_02_ENTRY_1);

EvtScript N(EVS_TexPan_Water) = {
    EVT_CALL(EnableTexPanning, MODEL_o946, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o947, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_SUB(LVar0, 3000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243568_912C18) = {
    EVT_CALL(EnableTexPanning, MODEL_o952, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o956, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o957, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, LVar1)
        EVT_ADD(LVar0, 0x8000)
        EVT_ADD(LVar1, 0x8000)
        EVT_WAIT(2)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, LVar1)
        EVT_ADD(LVar1, 0x8000)
        EVT_WAIT(2)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(D_80243568_912C18))
    EVT_EXEC_WAIT(N(EVS_MakeSplashes))
    EVT_EXEC(N(EVS_BindSlideTriggers2))
    EVT_EXEC(N(EVS_BindSlideTriggers1))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_IWA01_FLOW1, SOUND_SPACE_WITH_DEPTH, -570, -180, 425)
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_IWA01_FLOW2, SOUND_SPACE_WITH_DEPTH, 740, -170, 330)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, pad);
