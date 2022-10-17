#include "arn_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 450, 285, 120, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_ItemBlock_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 720, 333, 75, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 600, 290, 200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN04_MultiCoinBrick)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 540, 230, 13, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ARN04_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
