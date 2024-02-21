#include "trd_09.h"
#include "entity.h"

EvtScript N(EVS_BombRock) = {
    Set(GF_TRD09_BombedRock, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TRD09_BombedRock, FALSE)
        Call(MakeEntity, Ref(Entity_BombableRock2), -470, -75, 139, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BombRock)))
    EndIf
    Call(MakeEntity, Ref(Entity_HeartBlock), 1400, -15, 135, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), 1490, -15, 135, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), -540, -15, 135, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TRD09_ItemBlock_MapleSyrup)
    Return
    End
};
