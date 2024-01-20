#include "sbk_40.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK40_MultiCoinBrick)
    Call(MakeEntity, Ref(Entity_BrickBlock), 165, 60, -300, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 110, 60, 130, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -110, 60, 200, 0, MAKE_ENTITY_END)
    Return
    End
};
