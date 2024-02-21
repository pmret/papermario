#include "flo_11.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), -220, 60, -75, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_FLO11_MultiCoinBrick)
    Return
    End
};
