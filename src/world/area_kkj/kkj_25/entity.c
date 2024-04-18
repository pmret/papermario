#include "kkj_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KKJ25_Defeated_Kammy, FALSE)
        Call(MakeEntity, Ref(Entity_GreenStompSwitch), 300, 0, 0, 0, MAKE_ENTITY_END)
        Set(MV_SwitchEntityIdx, LVar0)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KKJ_1A))
        BindTrigger(Ref(N(EVS_Scene_ActivateMachine)), TRIGGER_AREA_FLAG_SET, AF_KKJ_1A, 1, 0)
    EndIf
    Return
    End
};
