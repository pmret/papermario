#include "pra_15.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STAR_PIECE, 395, -60, 120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_PRA15_Item_StarPiece)
    Return
    End
};
