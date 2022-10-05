#include "sbk_55.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK55_MultiCoinBrick)
    EVT_CALL(MakeItemEntity, ITEM_TASTY_TONIC, 420, 0, 168, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SBK55_Item_TastyTonic)
    EVT_RETURN
    EVT_END
};
