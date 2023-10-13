#include "iwa_10.h"

EvtScript N(EVS_ExitWalk_iwa_00_0) = EVT_EXIT_WALK(60, iwa_10_ENTRY_1, "iwa_00", iwa_00_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
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
    EVT_IF_EQ(LVar0, iwa_10_ENTRY_1)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_EXEC(N(EVS_ArriveFromToadTown))
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(GetClockHandAngles)) {
    if (script->varTable[15] > 720) {
        script->varTable[15] = 0;
    }
    script->varTable[0] = script->varTable[15] * 6;
    script->varTable[1] = script->varTable[15] / 2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_o110, LVar0)
#endif
    EVT_SET(GF_MAP_MtRugged, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_InitializeTrainScene))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_IWA10_FLOW1, SOUND_SPACE_WITH_DEPTH, -560, 0, -233)
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(10)
            EVT_ADD(LVarF, 1)
            EVT_CALL(N(GetClockHandAngles))
            EVT_CALL(RotateModel, MODEL_o148, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
            EVT_WAIT(10)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o256, TEX_PANNER_2)
        EVT_CALL(SetTexPanner, MODEL_o266, TEX_PANNER_2)
        EVT_CALL(EnableTexPanning, MODEL_o256, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_o266, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LABEL(20)
        EVT_SUB(LVar0, 3000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_THREAD
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_SPOKE_WITH_PARAKARRY)
        EVT_EXEC(N(EVS_Scene_MeetParakarry))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
