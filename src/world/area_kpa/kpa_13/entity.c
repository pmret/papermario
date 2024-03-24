#include "kpa_13.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Set(AF_KPA13_HitSwitchA, FALSE)
    Set(AF_KPA13_HitSwitchB, FALSE)
    IfEq(GF_KPA13_BlueSwitchA, FALSE)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 285, 10, -55, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA13_HitSwitchA))
    EndIf
    IfEq(GF_KPA13_BlueSwitchB, FALSE)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 935, 10, -55, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA13_HitSwitchB))
    EndIf
    Return
    End
};
