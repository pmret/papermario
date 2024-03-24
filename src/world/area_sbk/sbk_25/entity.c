#include "sbk_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK25_MultiCoinBrickA)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 120, 60, 185, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK25_MultiCoinBrickB)
    Call(MakeEntity, Ref(Entity_BrickBlock), -300, 60, -80, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -240, 60, 230, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -75, 60, 295, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -75, 60, -360, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 270, 60, -150, 0, MAKE_ENTITY_END)
    Return
    End
};
