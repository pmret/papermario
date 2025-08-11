#include "iwa_00.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    Set(GF_IWA01_Hammer1Block, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_IWA01_Hammer1Block, false)
        Call(MakeEntity, Ref(Entity_Hammer1BlockWideZ), 900, -30, 220, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock)))
    EndIf
    Call(MakeItemEntity, ITEM_COIN, 405, 25, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, 465, 53, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinB)
    Call(MakeItemEntity, ITEM_COIN, 515, 92, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinC)
    Call(MakeEntity, Ref(Entity_YellowBlock), 1260, 30, 140, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_IWA00_ItemBlock_SleepySheep)
    Call(MakeEntity, Ref(Entity_ArrowSign), 58, -5, -73, -30, 90, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), 926, 70, -45, 22, 90, MAKE_ENTITY_END)
    Return
    End
};
