#include "kmr_05.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 133, 140, -155, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR05_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
