#include "jan_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedBlock), 0, 60, 0, 0, ITEM_POWER_QUAKE, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_JAN05_BadgeBlock_PowerQuake)
    Call(MakeEntity, Ref(Entity_CymbalPlant), 205, 0, 220, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_TrumpetPlant), -386, 0, -214, 160, MAKE_ENTITY_END)
    Return
    End
};
