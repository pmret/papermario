
#include "dgb_16.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_TUBBA_CASTLE_KEY, -235, 25, -165, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB16_Item_CastleKey1)
    Return
    End
};
