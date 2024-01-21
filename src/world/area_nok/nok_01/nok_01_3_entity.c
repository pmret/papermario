#include "nok_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_BrickBlock), 20, 60, 370, 0, MAKE_ENTITY_END)
    IfEq(GF_NOK01_RecoveredBlockShell, FALSE)
        Call(AssignScript, Ref(N(EVS_BreakBlock_DropShell)))
    EndIf
    Call(MakeEntity, Ref(Entity_SavePoint), 425, 60, 125, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 150, 0, 350, 0, MODEL_o4, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_NOK01_HiddenPanel)
    Return
    End
};
