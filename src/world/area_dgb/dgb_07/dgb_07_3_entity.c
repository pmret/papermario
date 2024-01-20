#include "dgb_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STAR_PIECE, -220, 75, -210, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB07_Item_StarPiece)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -370, 0, -200, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -410, 0, -200, 0, -1, MAKE_ENTITY_END)
    Return
    End
};
