#include "mim_11.h"
#include "entity.h"

EvtScript N(EVS_UseBluePipe) = {
    Call(GotoMap, Ref("tik_09"), tik_09_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_MIM11_WarpPipe, FALSE)
        IfEq(GF_TIK09_WarpPipe, TRUE)
            Call(GetEntryID, LVar0)
            IfNe(LVar0, mim_11_ENTRY_3)
                Set(GF_KMR02_WarpPipe, TRUE)
            EndIf
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_BlueWarpPipe), -275, 0, -225, 270, mim_11_ENTRY_3, Ref(N(EVS_UseBluePipe)), EVT_INDEX_OF_GAME_FLAG(GF_MIM11_WarpPipe), MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 0, 60, -300, 45, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), 220, 60, -80, 45, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), -282, 60, 522, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MIM11_ItemBlock_VoltShroom)
    Return
    End
};
