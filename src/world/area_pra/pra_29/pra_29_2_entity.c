#include "pra_29.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 330, 0, -77, 0, 2, MAKE_ENTITY_END)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 330, 0, 77, 0, 1, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_PRA09_HitSwitch))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
