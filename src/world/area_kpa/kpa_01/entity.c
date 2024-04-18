#include "kpa_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 220, 208, -125, 0, ITEM_POW_BLOCK, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA01_ItemBlock_POWBlock)
    Return
    End
};
