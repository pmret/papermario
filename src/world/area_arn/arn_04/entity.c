#include "arn_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 450, 285, 120, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_ARN04_ItemBlock_SuperShroom)
    Call(MakeEntity, Ref(Entity_YellowBlock), 720, 333, 75, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_ARN04_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 600, 290, 200, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_ARN04_MultiCoinBrick)
    Call(MakeItemEntity, ITEM_STAR_PIECE, 540, 230, 13, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ARN04_Item_StarPiece)
    Return
    End
};
