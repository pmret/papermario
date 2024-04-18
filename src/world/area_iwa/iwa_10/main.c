#include "iwa_10.h"

EvtScript N(EVS_ExitWalk_iwa_00_0) = EVT_EXIT_WALK(60, iwa_10_ENTRY_1, "iwa_00", iwa_00_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, iwa_10_ENTRY_1)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Exec(N(EVS_ArriveFromToadTown))
        Exec(N(EVS_BindExitTriggers))
    EndIf
    Return
    End
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
    Set(GB_WorldLocation, LOCATION_MT_RUGGED)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Call(SetModelTexVariant, MODEL_o110, LVar0)
#endif
    Set(GF_MAP_MtRugged, TRUE)
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_InitializeTrainScene))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupFoliage))
    Call(PlaySoundAtF, SOUND_LOOP_IWA10_FLOW1, SOUND_SPACE_WITH_DEPTH, -560, 0, -233)
    Thread
        Set(LVarF, 0)
        Label(10)
            Add(LVarF, 1)
            Call(N(GetClockHandAngles))
            Call(RotateModel, MODEL_o148, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
            Wait(10)
            Goto(10)
    EndThread
    Thread
        Call(SetTexPanner, MODEL_o256, TEX_PANNER_2)
        Call(SetTexPanner, MODEL_o266, TEX_PANNER_2)
        Call(EnableTexPanning, MODEL_o256, TRUE)
        Call(EnableTexPanning, MODEL_o266, TRUE)
        Set(LVar0, 0)
        Label(20)
        Sub(LVar0, 3000)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        Wait(1)
        Goto(20)
    EndThread
    IfLt(GB_StoryProgress, STORY_CH2_SPOKE_WITH_PARAKARRY)
        Exec(N(EVS_Scene_MeetParakarry))
    EndIf
    Return
    End
};
