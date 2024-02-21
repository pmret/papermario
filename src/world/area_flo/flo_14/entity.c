#include "flo_14.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STAR_PIECE, 675, 60, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO14_Item_StarPiece)
    Return
    End
};
