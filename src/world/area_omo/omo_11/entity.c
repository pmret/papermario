#include "omo_11.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_OMO11_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(-115, 270, -120, 0)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 315, 270, -100, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_MultiCoinBrick)
    Call(UseDynamicShadow, true)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 685, 60, -100, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_HiddenItem_VoltShroom)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -600, 60, -50, 0, ITEM_SNOWMAN_DOLL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_HiddenItem_SnowmanDoll)
    Call(MakeEntity, Ref(Entity_YellowBlock), -100, 60, -45, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_HiddenRedBlock), -150, 60, -45, 0, ITEM_DEEP_FOCUS_B, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_HiddenBadge_DeepFocus2)
    Call(MakeEntity, Ref(Entity_YellowBlock), -200, 60, -45, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO11_ItemBlock_CoinA)
    Return
    End
};
