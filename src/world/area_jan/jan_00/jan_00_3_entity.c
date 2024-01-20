#include "jan_00.h"
#include "entity.h"

EvtScript N(D_80245860_B25DA0) = {
    Call(MakeItemEntity, ITEM_COIN, 15, 100, 415, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, 15, 125, 415, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_CoinB)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STOP_WATCH, 370, 0, -210, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_StopWatch)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, jan_00_ENTRY_0)
        Exec(N(D_80245860_B25DA0))
    EndIf
    Call(MakeEntity, Ref(Entity_SpinningFlower), 15, 0, 415, 0, MAKE_ENTITY_END)
    Return
    End
};
