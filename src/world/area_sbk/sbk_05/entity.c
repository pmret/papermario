#include "sbk_05.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_FIRE_FLOWER, -100, 0, -445, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SBK05_Item_FireFlower)
    Return
    End
};
