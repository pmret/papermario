#include "jan_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -150, -60, 60, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN10_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
