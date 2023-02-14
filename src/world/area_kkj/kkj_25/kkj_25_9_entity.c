#include "kkj_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KKJ25_Defeated_Kammy, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_GreenStompSwitch), 300, 0, 0, 0, MAKE_ENTITY_END)
        EVT_SET(MV_SwitchEntityIdx, LVar0)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KKJ_1A))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_ActivateMachine)), TRIGGER_AREA_FLAG_SET, AF_KKJ_1A, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
