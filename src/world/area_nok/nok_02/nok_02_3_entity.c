#include "nok_02.h"
#include "entity.h"

#include "common/ItemEntityJumpToPos.inc.c"

EvtScript N(EVS_BreakBlock_DropStarPiece) = {
    EVT_CALL(N(ItemEntityJumpToPos), MV_StarPieceItem, EVT_FLOAT(227.0), EVT_FLOAT(0.0), EVT_FLOAT(247.0), 20, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tik_01_3) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_01"), tik_01_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 151, 81, 251, 0, MAKE_ENTITY_END)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_IF_EQ(GF_NOK02_RecoveredShellB, FALSE)
                EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_DropShell)))
            EVT_END_IF
        EVT_CASE_GE(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_IF_EQ(GF_NOK02_Item_StarPiece, FALSE)
                EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_DropStarPiece)))
                EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 150, 106, 250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK02_Item_StarPiece)
                EVT_SET(MV_StarPieceItem, LVar0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(CreatePushBlockGrid, 0, 5, 5, 88, -4, 188, 0)
    EVT_CALL(SetPushBlock, 0, 0, 0, PUSH_GRID_BLOCK)
    EVT_IF_EQ(GF_NOK02_WarpPipe, FALSE)
        EVT_IF_EQ(GF_TIK01_WarpPipes, TRUE)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, nok_02_ENTRY_2)
                EVT_SET(GF_NOK02_WarpPipe, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), 365, 0, 90, 30, nok_02_ENTRY_2, EVT_PTR(N(EVS_GotoMap_tik_01_3)), EVT_INDEX_OF_GAME_FLAG(GF_NOK02_WarpPipe), MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
