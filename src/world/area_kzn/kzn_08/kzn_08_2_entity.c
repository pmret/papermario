#include "kzn_08.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_DizzyStomp) = EVT_OPEN_CHEST_BADGE(ITEM_DIZZY_STOMP, GF_KZN08_Chest_DizzyStomp);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 120, 100, -55, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_KZN08_Chest_DizzyStomp)
    Call(AssignScript, Ref(N(EVS_OpenChest_DizzyStomp)))
    Return
    End
};
