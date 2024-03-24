#include "tik_07.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_TIK07_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STAR_PIECE, 306, 90, -104, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_TIK07_Item_StarPiece)
    EVT_MAKE_SUPER_BLOCK(820, 70, -5, 0)
    Return
    End
};
