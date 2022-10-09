#include "iwa_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 64, 0, 95, 0, 120, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 307, 67, 99, 0, 120, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 700, 238, 15, 0, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 35, 167, 120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA02_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
