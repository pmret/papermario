#include "tik_10.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_TIK10_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(-140, 160, -40, 0)
    EVT_CALL(CreatePushBlockGrid, 0, 7, 6, -64, -15, -94, 0)
    EVT_CALL(SetPushBlock, 0, 1, 4, PUSH_GRID_BLOCK)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -52, 70, -32, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK10_HiddenItem_CoinA)
    EVT_CALL(UseDynamicShadow, TRUE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 23, 70, -32, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK10_HiddenItem_CoinB)
    EVT_CALL(UseDynamicShadow, TRUE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 98, 70, -32, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK10_HiddenItem_CoinC)
    EVT_CALL(UseDynamicShadow, TRUE)
    EVT_RETURN
    EVT_END
};
