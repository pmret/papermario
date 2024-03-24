#include "kpa_63.h"

EvtScript N(EVS_OpenHangerDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_AIRSHIP_DOCK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 100, 0, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar5, LVar0)
        MulF(LVar5, Float(0.01))
        Call(ScaleGroup, MODEL_g75, LVar5, 1, 1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseHangerDoor) = {
    Call(MakeLerp, 0, 100, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar5, LVar0)
        MulF(LVar5, Float(0.01))
        Call(ScaleGroup, MODEL_g75, LVar5, 1, 1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_AIRSHIP_DOCK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kpa_62_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Exec(N(EVS_OpenHangerDoor))
    Wait(15)
    Call(UseExitHeading, 60, kpa_63_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("kpa_62"), kpa_62_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_kpa_62_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kpa_63_ENTRY_1)
        Exec(N(EVS_Starship_Arrive))
        Exec(N(EVS_BindExitTriggers))
    Else
        Exec(N(EVS_CloseHangerDoor))
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Set(GF_MAP_BowsersCastle, TRUE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_Starship_Depart)), TRIGGER_FLOOR_TOUCH, COLLIDER_o400, 1, 0)
    Exec(N(EVS_SetupStarship))
    Return
    End
};
