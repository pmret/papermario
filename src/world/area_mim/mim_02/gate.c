#include "mim_02.h"

#include "../common/SupportGates.inc.c"

#include "../common/AnimateGates.inc.c"

EvtScript N(EVS_UseGate_North) = {
    Call(DisablePlayerInput, true)
    Set(LVar7, 0)
    Set(LVar8, 70)
    Set(LVar9, COLLIDER_monn)
    Set(LVarA, MODEL_monn)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_UseGate_South) = {
    Call(DisablePlayerInput, true)
    Set(LVar7, 0)
    Set(LVar8, -70)
    Set(LVar9, COLLIDER_mons)
    Set(LVarA, MODEL_mons)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_UseGate_East) = {
    Call(DisablePlayerInput, true)
    Set(LVar7, -70)
    Set(LVar8, 0)
    Set(LVar9, COLLIDER_mone)
    Set(LVarA, MODEL_mone)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_UseGate_West) = {
    Call(DisablePlayerInput, true)
    Set(LVar7, 70)
    Set(LVar8, 0)
    Set(LVar9, COLLIDER_monw)
    Set(LVarA, MODEL_monw)
    ExecWait(N(EVS_UseGate))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_SetupGates) = {
    IfEq(GF_MIM_ChoosingPath, false)
        Set(GF_MIM_ChoosingPath, true)
        Set(AB_MIM_1, 2)
        Set(LVar1, 2)
        Set(LVar2, -10)
    Else
        Set(GF_MIM_ChoosingPath, false)
        Set(AB_MIM_1, 0)
        Set(LVar1, 0)
        Set(LVar2, 10)
    EndIf
    ExecWait(N(EVS_SetGateCameraZones))
    Exec(N(EVS_InitializeGates))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    BindTrigger(Ref(N(EVS_UseGate_North)), TRIGGER_WALL_PRESS_A, COLLIDER_monn, 1, 0)
    BindTrigger(Ref(N(EVS_UseGate_South)), TRIGGER_WALL_PRESS_A, COLLIDER_mons, 1, 0)
    BindTrigger(Ref(N(EVS_UseGate_East)), TRIGGER_WALL_PRESS_A, COLLIDER_mone, 1, 0)
    IfGe(GB_StoryProgress, STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
        BindTrigger(Ref(N(EVS_UseGate_West)), TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnableWestGate) = {
    BindTrigger(Ref(N(EVS_UseGate_West)), TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    Return
    End
};
