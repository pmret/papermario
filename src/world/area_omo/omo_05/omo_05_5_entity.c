#include "omo_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 400, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO05_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 550, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO05_ItemBlock_CoinB)
    EVT_IF_EQ(GF_OMO05_Item_Cookbook, FALSE)
        EVT_IF_GT(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_CALL(MakeItemEntity, ITEM_COOKBOOK, -250, 0, 120, ITEM_SPAWN_MODE_KEY, GF_OMO05_Item_Cookbook)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 475, 70, -150, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO05_HiddenItem_DizzyDial)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -540, 70, -150, 0, ITEM_SUPER_SODA, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO05_HiddenItem_SuperSoda)
    EVT_RETURN
    EVT_END
};
