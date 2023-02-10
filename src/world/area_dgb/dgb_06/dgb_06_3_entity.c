#include "dgb_06.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_TubbaKey) = EVT_OPEN_CHEST_KEY(ITEM_TUBBA_CASTLE_KEY, GF_DGB06_Chest_CastleKey1);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -300, 50, -200, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_DGB06_Chest_CastleKey1)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_TubbaKey)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -125, 60, 175, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
