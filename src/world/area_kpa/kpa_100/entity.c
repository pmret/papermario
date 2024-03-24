#include "kpa_100.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, -100, 0, 100, ITEM_SPAWN_MODE_KEY, GF_KPA100_Item_CastleKey2)
    Return
    End
};
