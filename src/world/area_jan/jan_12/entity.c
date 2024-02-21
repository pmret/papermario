#include "jan_12.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_PinkFlower), 130, 0, -110, 170, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BellbellPlant), -350, 30, -55, 25, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -310, 90, -25, 0, ITEM_STONE_CAP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_JAN12_HiddenItem_StoneCap)
    Return
    End
};
