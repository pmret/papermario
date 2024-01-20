#include "tst_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 90, 70, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 130, 80, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 170, 90, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 210, 100, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 250, 110, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_GiantChest), 193, 0, -38, -20, ITEM_NONE, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Chest), 130, 0, -38, -20, 0, MAKE_ENTITY_END)
    Return
    End
};
