#include "arn_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_DIZZY_DIAL, -248, 193, 45, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ARN02_Item_DizzyDial)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_FICE_T, 536, 260, 227, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ARN02_Item_LetterFiceT)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -350, 172, 170, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN02_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 225, 265, 30, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN02_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 275, 265, 150, 0, ITEM_REPEL_GEL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN02_ItemBlock_RepelGel)
    EVT_RETURN
    EVT_END
};
