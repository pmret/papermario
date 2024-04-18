#include "nok_02.h"
#include "entity.h"

#include "common/ItemEntityJumpToPos.inc.c"

EvtScript N(EVS_BreakBlock_DropStarPiece) = {
    Call(N(ItemEntityJumpToPos), MV_StarPieceItem, Float(227.0), Float(0.0), Float(247.0), 20, Float(1.0))
    Return
    End
};

EvtScript N(EVS_GotoMap_tik_01_3) = {
    Call(GotoMap, Ref("tik_01"), tik_01_ENTRY_3)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_BrickBlock), 151, 81, 251, 0, MAKE_ENTITY_END)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            IfEq(GF_NOK02_RecoveredShellB, FALSE)
                Call(AssignScript, Ref(N(EVS_BreakBlock_DropShell)))
            EndIf
        CaseGe(STORY_CH1_KOOPER_JOINED_PARTY)
            IfEq(GF_NOK02_Item_StarPiece, FALSE)
                Call(AssignScript, Ref(N(EVS_BreakBlock_DropStarPiece)))
                Call(MakeItemEntity, ITEM_STAR_PIECE, 150, 106, 250, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK02_Item_StarPiece)
                Set(MV_StarPieceItem, LVar0)
            EndIf
    EndSwitch
    Call(CreatePushBlockGrid, 0, 5, 5, 88, -4, 188, 0)
    Call(SetPushBlock, 0, 0, 0, PUSH_GRID_BLOCK)
    IfEq(GF_NOK02_WarpPipe, FALSE)
        IfEq(GF_TIK01_WarpPipes, TRUE)
            Call(GetEntryID, LVar0)
            IfNe(LVar0, nok_02_ENTRY_2)
                Set(GF_NOK02_WarpPipe, TRUE)
            EndIf
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), 365, 0, 90, 30, nok_02_ENTRY_2, Ref(N(EVS_GotoMap_tik_01_3)), EVT_INDEX_OF_GAME_FLAG(GF_NOK02_WarpPipe), MAKE_ENTITY_END)
    Return
    End
};
