#include "dro_02.h"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_ExitWalk_dro_01_1) = EVT_EXIT_WALK(60, dro_02_ENTRY_0, "dro_01", dro_01_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_dro_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_OnReadPoster) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_017C, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_EnterScene) = {
    Call(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    Call(UseSettingsFrom, CAM_DEFAULT, 190, 0, -37)
    Call(SetPanTarget, CAM_DEFAULT, 190, 0, -37)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(13.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(0.2))
    EndThread
    Thread
        Wait(60)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, dro_02_ENTRY_2)
            Call(GotoMap, Ref("sbk_02"), sbk_02_ENTRY_6)
        Else
            Call(GotoMap, Ref("sbk_02"), sbk_02_ENTRY_7)
        EndIf
        Wait(100)
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_OUTPOST)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(InitVirtualEntityList)
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupRooms))
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_02_ENTRY_2)
        CaseOrEq(dro_02_ENTRY_3)
            ExecWait(N(EVS_EnterScene))
        EndCaseGroup
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Wait(1)
    Thread
        Call(SetTexPanner, MODEL_kemuri, 1)
        Set(LVar0, 0)
        Label(123)
            Add(LVar0, 420)
            IfGt(LVar0, 0x10000)
                Add(LVar0, -0x10000)
            EndIf
            Call(SetTexPanOffset, 1, 0, 0, LVar0)
            Wait(1)
            Goto(123)
    EndThread
    Set(MF_Unk_00, FALSE)
    BindTrigger(Ref(N(EVS_OnReadPoster)), TRIGGER_WALL_PRESS_A, COLLIDER_poster, 1, 0)
    Thread
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfLt(LVar2, -200)
                Call(EnableGroup, MODEL_mazinai, TRUE)
            Else
                Call(EnableGroup, MODEL_mazinai, FALSE)
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.334))
    Return
    End
};
