#include "kzn_08.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_DizzyStomp) = EVT_OPEN_CHEST_BADGE(ITEM_DIZZY_STOMP, GF_KZN08_Chest_DizzyStomp);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 120, 100, -55, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KZN08_Chest_DizzyStomp)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_DizzyStomp)))
    EVT_RETURN
    EVT_END
};
