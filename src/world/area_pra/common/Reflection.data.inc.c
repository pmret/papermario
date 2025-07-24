#include "common.h"

EvtScript N(EVS_Reflection_Unk) = {
    Call(GetEntryID, LVarA)
    IfEq(LVarA, LVar1)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    IfEq(LVarA, LVar2)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    IfEq(LVarA, LVar3)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    IfEq(LVarA, LVar4)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    IfEq(LVarA, LVar5)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    IfEq(LVarA, LVar6)
        Set(LVar0, REFLECTION_WALL_ONLY)
    EndIf
    Return
    End
};

// LVar0 mode
// LVar1 disable wall flag (reflections wont show if false)
EvtScript N(EVS_SetupReflections) = {
    MallocArray(16, LVarA)
    IfEq(LVar1, false)
        Switch(LVar0)
            CaseEq(REFLECTION_FLOOR_WALL)
                Call(N(EnableWallReflection))
            CaseEq(REFLECTION_FLOOR_ONLY)
                // do nothing
            CaseEq(REFLECTION_WALL_ONLY)
                Call(N(EnableWallReflection))
        EndSwitch
    EndIf
    Call(N(EnableFloorReflection), LVar0)
    Call(N(EnablePartnerReflection), LVar0)
    Return
    End
};
