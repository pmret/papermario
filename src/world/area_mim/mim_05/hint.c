#include "mim_05.h"

EvtScript N(EVS_FlickerTexPanner) = {
    UseArray(LVar0)
    Switch(LVar1)
        CaseEq(0)
            Set(LVarA, ArrayVar(0))
        CaseEq(1)
            Set(LVarA, ArrayVar(1))
        CaseEq(2)
            Set(LVarA, ArrayVar(2))
        CaseEq(4)
            Set(LVarA, ArrayVar(4))
        CaseEq(5)
            Set(LVarA, ArrayVar(5))
    EndSwitch
    IfEq(LVarA, 1)
        Call(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -300, 0, -10)
        Call(SetTexPanOffset, LVar1, 0, 0, 0)
    Else
        Call(SetTexPanOffset, LVar1, 0, 0, -0x8000)
    EndIf
    Set(LVar9, 1)
    Sub(LVar9, LVarA)
    Switch(LVar1)
        CaseEq(0)
            Set(ArrayVar(0), LVar9)
        CaseEq(1)
            Set(ArrayVar(1), LVar9)
        CaseEq(2)
            Set(ArrayVar(2), LVar9)
        CaseEq(4)
            Set(ArrayVar(4), LVar9)
        CaseEq(5)
            Set(ArrayVar(5), LVar9)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_AnimateMushroomSet) = {
    Call(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -300, 0, -10)
    Exec(N(EVS_FlickerTexPanner))
    Wait(30)
    Loop(4)
        Exec(N(EVS_FlickerTexPanner))
        Wait(3)
        Exec(N(EVS_FlickerTexPanner))
        Wait(3)
    EndLoop
    Exec(N(EVS_FlickerTexPanner))
    Return
    End
};

EvtScript N(EVS_InspectMushrooms_West) = {
    Set(LVar1, TEX_PANNER_2)
    Exec(N(EVS_AnimateMushroomSet))
    Wait(10)
    Set(LVar1, TEX_PANNER_4)
    Exec(N(EVS_AnimateMushroomSet))
    Wait(10)
    Set(LVar1, TEX_PANNER_5)
    Exec(N(EVS_AnimateMushroomSet))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_InspectMushrooms_South) = {
    Call(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, -20, 0, 300)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(20)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    Return
    End
};

EvtScript N(EVS_InspectMushrooms_North) = {
    Call(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, 20, 0, -300)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(20)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, 0)
    Return
    End
};

EvtScript N(EVS_InspectMushrooms_East) = {
    Call(PlaySoundAt, SOUND_MIM_MUSHROOM_GLOW, SOUND_SPACE_DEFAULT, 300, 0, 10)
    Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(50)
    Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Call(SetTexPanner, MODEL_o402, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o510, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o511, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o403, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o500, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o501, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o404, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o498, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o499, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o505, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o509, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o507, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o508, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o405, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o502, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o503, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o504, TEX_PANNER_5)
    MallocArray(6, LVar0)
    UseArray(LVar0)
    Set(ArrayVar(0), 0)
    Set(ArrayVar(1), 0)
    Set(ArrayVar(2), 0)
    Set(ArrayVar(4), 0)
    Set(ArrayVar(5), 0)
    BindTrigger(Ref(N(EVS_InspectMushrooms_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o402, 1, 0)
    BindTrigger(Ref(N(EVS_InspectMushrooms_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o403, 1, 0)
    BindTrigger(Ref(N(EVS_InspectMushrooms_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_o405, 1, 0)
    BindTrigger(Ref(N(EVS_InspectMushrooms_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_o404, 1, 0)
    Return
    End
};
