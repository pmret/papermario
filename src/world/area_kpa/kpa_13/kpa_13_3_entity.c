#include "kpa_13.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(AF_KPA13_HitSwitchA, FALSE)
    EVT_SET(AF_KPA13_HitSwitchB, FALSE)
    EVT_IF_EQ(GF_KPA13_BlueSwitchA, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 285, 10, -55, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA13_HitSwitchA))
    EVT_END_IF
    EVT_IF_EQ(GF_KPA13_BlueSwitchB, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 935, 10, -55, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA13_HitSwitchB))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
