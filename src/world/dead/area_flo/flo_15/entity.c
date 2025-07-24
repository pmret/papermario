#include "flo_15.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_Rock) = {
    Set(GF_FLO15_BombedRock, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_FLO15_BombedRock, false)
        Call(MakeEntity, Ref(Entity_BombableRock), -180, 0, -18, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBlast_Rock)))
    EndIf
    Return
    End
};
