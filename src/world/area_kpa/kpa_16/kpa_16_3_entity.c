#include "kpa_16.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 470, 230, -145, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA16_HitSwitch))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
