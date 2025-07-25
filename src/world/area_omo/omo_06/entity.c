#include "omo_06.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_Mailbag) = {
    Set(LVarA, ITEM_MAILBAG)
    Set(LVarB, ITEM_TYPE_KEY)
    Set(GF_OMO06_Chest_Mailbag, true)
    ExecWait(N(EVS_Chest_GetItem))
    Set(GF_MAC01_MailbagStolen, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -200, 60, 300, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -280, 60, -290, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO06_HiddenItem_ThunderRage)
    Call(MakeEntity, Ref(Entity_Chest), 400, 0, 60, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO06_Chest_Mailbag)
    Call(AssignScript, Ref(N(EVS_OpenChest_Mailbag)))
    Call(MakeEntity, Ref(Entity_HiddenPanel), 100, 0, 400, 0, MODEL_o817, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OMO06_HiddenPanel)
    Return
    End
};
