#include "kpa_119.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, -100, 20, 100, ITEM_SPAWN_MODE_KEY, GF_KPA119_Item_CastleKey2)
    Return
    End
};
