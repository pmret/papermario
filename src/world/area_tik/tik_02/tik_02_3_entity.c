#include "tik_02.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest) = EVT_OPEN_CHEST_BADGE(ITEM_SHRINK_STOMP, GF_TIK02_Chest_ShrinkStomp);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 280, -10, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_TIK02_Chest_ShrinkStomp)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest)))
    EVT_RETURN
    EVT_END
};
