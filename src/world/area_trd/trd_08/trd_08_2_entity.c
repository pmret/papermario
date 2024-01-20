#include "trd_08.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, -500, 16, 0, ITEM_SPAWN_MODE_KEY, GF_TRD08_Item_FortressKey)
    Return
    End
};
