#include "dgb_00.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "arn_20_shape");
    sprintf(wMapHitName, "arn_20_hit");
    sprintf(wMapTexName, "arn_tex");
    return FALSE;
}

EvtScript N(EVS_ExitWalk_arn_04_1) = EVT_EXIT_WALK(60, dgb_00_ENTRY_0, "arn_04", arn_04_ENTRY_1);

EvtScript N(EVS_ExitDoors_dgb_01_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_00_ENTRY_1)
    Set(LVar1, COLLIDER_deiliwt)
    Set(LVar2, MODEL_d1)
    Set(LVar3, MODEL_d2)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_arn_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
            BindTrigger(Ref(N(EVS_ExitDoors_dgb_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwt, 1, 0)
        CaseLt(STORY_CH3_ESCAPED_TUBBAS_MANOR)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Exec(N(EVS_TubbaTaunting))
            ExecWait(N(EVS_SetBoosBracingDoor))
        CaseDefault
            BindTrigger(Ref(N(EVS_ExitDoors_dgb_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwt, 1, 0)
    EndSwitch
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
    Switch(LVar0)
        CaseEq(dgb_00_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(dgb_00_ENTRY_1)
            IfGe(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
                IfLt(GB_StoryProgress, STORY_CH3_ESCAPED_TUBBAS_MANOR)
                    Exec(N(EVS_BindExitTriggers))
                    Thread
                        ExecWait(N(EVS_Scene_BoosApproachManor))
                        ExecWait(N(EVS_Scene_EscapeFromTubba))
                    EndThread
                    Return
                EndIf
            EndIf
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_d1)
            Set(LVar3, MODEL_d2)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(dgb_00_ENTRY_2)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_Scene_ThrownOutBySentinel))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Set(GF_MAP_TubbasManor, TRUE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, dgb_00_ENTRY_2)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(BooNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
