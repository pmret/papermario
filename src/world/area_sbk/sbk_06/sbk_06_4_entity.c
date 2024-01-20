#include "sbk_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 135, 60, -205, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK06_MultiCoinBrick)
    Call(MakeEntity, Ref(Entity_BrickBlock), -20, 60, -250, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 220, 60, 65, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 90, 60, 220, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -70, 60, 100, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -370, 60, 150, 0, MAKE_ENTITY_END)
    Return
    End
};
