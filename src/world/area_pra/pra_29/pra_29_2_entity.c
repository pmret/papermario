#include "pra_29.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfGe(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
    Else
        Call(MakeEntity, Ref(Entity_BlueSwitch), 330, 0, -77, 0, 2, MAKE_ENTITY_END)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 330, 0, 77, 0, 1, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_PRA09_HitSwitch))
    EndIf
    Return
    End
};
