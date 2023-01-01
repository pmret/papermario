#include "kpa_100.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, -100, 0, 100, ITEM_SPAWN_MODE_KEY, GF_KPA100_Item_CastleKey2)
    EVT_RETURN
    EVT_END
};
