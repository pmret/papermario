#include "jan_00.h"
#include "entity.h"

EvtScript N(D_80245860_B25DA0) = {
    EVT_CALL(MakeItemEntity, ITEM_COIN, 15, 100, 415, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 15, 125, 415, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_CoinB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_STOP_WATCH, 370, 0, -210, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN00_Item_StopWatch)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, jan_00_ENTRY_0)
        EVT_EXEC(N(D_80245860_B25DA0))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SpinningFlower), 15, 0, 415, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
