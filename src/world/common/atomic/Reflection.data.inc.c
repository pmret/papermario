#include "common.h"

EvtScript N(EVS_Reflection_UnkA) = {
    EVT_CALL(GetEntryID, LVarA)
    EVT_IF_EQ(LVarA, LVar1)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar2)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar3)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar4)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar5)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, LVar6)
        EVT_SET(LVar0, 2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Reflection_UnkB) = {
    EVT_MALLOC_ARRAY(16, LVarA)
    EVT_IF_EQ(LVar1, 0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(N(EnableWallReflection))
            EVT_CASE_EQ(1)
            EVT_CASE_EQ(2)
                EVT_CALL(N(EnableWallReflection))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(N(EnableFloorReflection), LVar0)
    EVT_CALL(N(EnablePartnerReflection), LVar0)
    EVT_RETURN
    EVT_END
};
