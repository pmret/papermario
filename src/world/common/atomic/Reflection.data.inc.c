#include "common.h"

EvtScript N(EVS_Reflection_Unk) = {
    EVT_CALL(GetEntryID, LVarA)
    EVT_IF_EQ(LVarA, LVar1)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar2)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar3)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar4)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar5)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar6)
        EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// LVar0 mode
// LVar1 disable wall flag (reflections wont show if false)
EvtScript N(EVS_SetupReflections) = {
    EVT_MALLOC_ARRAY(16, LVarA)
    EVT_IF_EQ(LVar1, FALSE)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(REFLECTION_FLOOR_WALL)
                EVT_CALL(N(EnableWallReflection))
            EVT_CASE_EQ(REFLECTION_FLOOR_ONLY)
                // do nothing
            EVT_CASE_EQ(REFLECTION_WALL_ONLY)
                EVT_CALL(N(EnableWallReflection))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(N(EnableFloorReflection), LVar0)
    EVT_CALL(N(EnablePartnerReflection), LVar0)
    EVT_RETURN
    EVT_END
};
