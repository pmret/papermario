#include "omo_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 400, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO05_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), 550, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO05_ItemBlock_CoinB)
    IfEq(GF_OMO05_Item_Cookbook, false)
        IfGt(GB_StoryProgress, STORY_CH4_GOT_TAYCE_TS_CAKE)
            Call(MakeItemEntity, ITEM_COOKBOOK, -250, 0, 120, ITEM_SPAWN_MODE_KEY, GF_OMO05_Item_Cookbook)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 475, 70, -150, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO05_HiddenItem_DizzyDial)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -540, 70, -150, 0, ITEM_SUPER_SODA, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO05_HiddenItem_SuperSoda)
    Return
    End
};
