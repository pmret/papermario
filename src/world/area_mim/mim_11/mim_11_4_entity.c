#include "mim_11.h"
#include "entity.h"

EvtScript N(EVS_UseBluePipe) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_09"), tik_09_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_MIM11_WarpPipe, FALSE)
        EVT_IF_EQ(GF_TIK09_WarpPipe, TRUE)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, mim_11_ENTRY_3)
                EVT_SET(GF_KMR02_WarpPipe, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), -275, 0, -225, 270, mim_11_ENTRY_3, EVT_PTR(N(EVS_UseBluePipe)), EVT_INDEX_OF_GAME_FLAG(GF_MIM11_WarpPipe), MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 0, 60, -300, 45, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 220, 60, -80, 45, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -282, 60, 522, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_MIM11_ItemBlock_VoltShroom)
    EVT_RETURN
    EVT_END
};
