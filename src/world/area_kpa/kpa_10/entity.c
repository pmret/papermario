#include "kpa_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 1400, 90, -875, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), 1400, 90, -375, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA10_ItemBlock_LifeShroom)
    Return
    End
};
