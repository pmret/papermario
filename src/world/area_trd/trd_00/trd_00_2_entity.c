#include "trd_00.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_Refund) = EVT_OPEN_CHEST_BADGE(ITEM_REFUND, GF_TRD00_Chest_Refund);
EvtScript N(EVS_OpenChest_FPPlus) = EVT_OPEN_CHEST_BADGE(ITEM_FP_PLUS_B, GF_TRD00_Chest_FPPlusB);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 810, 0, -50, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_TRD00_Chest_Refund)
    Call(AssignScript, Ref(N(EVS_OpenChest_Refund)))
    Call(MakeEntity, Ref(Entity_Chest), -750, 200, -125, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_TRD00_Chest_FPPlusB)
    Call(AssignScript, Ref(N(EVS_OpenChest_FPPlus)))
    Call(MakeEntity, Ref(Entity_SavePoint), -920, 60, 80, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), 325, 60, 220, 0, MAKE_ENTITY_END)
    Return
    End
};
