#include "nok_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 20, 60, 370, 0, MAKE_ENTITY_END)
    EVT_IF_EQ(GF_NOK01_RecoveredBlockShell, FALSE)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_DropShell)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 425, 60, 125, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 150, 0, 350, 0, MODEL_o4, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_NOK01_HiddenPanel)
    EVT_RETURN
    EVT_END
};
