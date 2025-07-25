#include "dgb_10.h"
#include "entity.h"

EvtScript N(EVS_BreakFloor1) = {
    Set(GF_DGB10_BoardedFloor1, true)
    Return
    End
};

EvtScript N(EVS_BreakFloor2) = {
    Set(GF_DGB10_BoardedFloor2, true)
    Return
    End
};

EvtScript N(EVS_BreakFloor3) = {
    Set(GF_DGB10_BoardedFloor3, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_DGB10_BoardedFloor1, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 500, 0, -100, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakFloor1)))
    EndIf
    IfEq(GF_DGB10_BoardedFloor2, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 500, 0, -250, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakFloor2)))
    EndIf
    IfEq(GF_DGB10_BoardedFloor3, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 375, 0, -250, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakFloor3)))
    EndIf
    Return
    End
};
