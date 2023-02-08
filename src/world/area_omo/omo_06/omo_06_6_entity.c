#include "omo_06.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_Mailbag) = {
    EVT_SET(LVarA, ITEM_MAILBAG)
    EVT_SET(LVarB, ITEM_TYPE_KEY)
    EVT_SET(GF_OMO06_Chest_Mailbag, TRUE)
    EVT_EXEC_WAIT(N(EVS_Chest_GetItem))
    EVT_SET(GF_MAC01_MailbagStolen, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -200, 60, 300, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -280, 60, -290, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO06_HiddenItem_ThunderRage)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 400, 0, 60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO06_Chest_Mailbag)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_Mailbag)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 100, 0, 400, 0, MODEL_o817, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OMO06_HiddenPanel)
    EVT_RETURN
    EVT_END
};
