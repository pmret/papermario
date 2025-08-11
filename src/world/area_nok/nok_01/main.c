#include "nok_01.h"

EvtScript N(EVS_ExitWalk_nok_13_1) = {
    IfEq(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        Set(GF_KootFavor_LeftKoopaVillage, true)
    EndIf
    Call(N(StopAllRadioStations))
    Call(ClearAmbientSounds, 250)
    Call(UseExitHeading, 60, nok_01_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_13"), nok_13_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_nok_02_0) = {
    Call(N(StopAllRadioStations))
    Call(ClearAmbientSounds, 250)
    Call(UseExitHeading, 60, nok_01_ENTRY_1)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_02"), nok_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
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
    Set(LFlag0, false)
    IfEq(LVar0, nok_01_ENTRY_0)
        IfLt(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
            Set(LFlag0, true)
            Thread
                Wait(30)
                Exec(N(EVS_BindExitTriggers))
            EndThread
        EndIf
    EndIf
    IfEq(LFlag0, false)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    Return
    End
};

EvtScript N(EVS_TexPan_Flowers) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTexPanner, MODEL_o298, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o320, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o402, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o396, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o397, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o398, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o399, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o400, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o401, TEX_PANNER_0)
    Label(10)
        Loop(12)
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
            Wait(1)
        EndLoop
        Loop(12)
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0x4000, 0)
            Wait(1)
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Call(SetModelTexVariant, MODEL_o340, LVar0)
#endif
    Set(GF_MAP_KoopaVillage, true)
    Set(AF_NOK01_Dialogue_RelaxedKoopa, false)
    Set(AF_NOK01_Dialogue_Bobomb_01_Crisis, false)
    Set(AF_NOK01_Dialogue_Bobomb_02, false)
    Set(AF_NOK_0E, false)
    Set(GF_NOK01_Bush4_KoopaLeaf, false)
    IfGe(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Set(GF_NOK01_RecoveredShellA, true)
        Set(GF_NOK01_RecoveredBlockShell, true)
        Set(GF_NOK01_RecoveredTreeShell, true)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(MakeNpcs, false, Ref(N(CrisisNPCs)))
    Else
        Call(MakeNpcs, false, Ref(N(NormalNPCs)))
    EndIf
    Call(ClearDefeatedEnemies)
    Exec(N(EVS_SetupShop))
    Exec(N(EVS_SetupRadio))
    Exec(N(EVS_TexPan_Flowers))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_MakeRooms))
    Wait(1)
    ExecWait(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupMusic))
    Set(AB_NOK_0, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
