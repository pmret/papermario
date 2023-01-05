#include "dgb_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -220, 75, -210, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB07_Item_StarPiece)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -370, 0, -200, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -410, 0, -200, 0, -1, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
