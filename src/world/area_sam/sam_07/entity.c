#include "sam_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_SAM07_FloorRaised, false)
        Call(MakeEntity, Ref(Entity_GreenStompSwitch), -945, -179, -75, 0, MAKE_ENTITY_END)
        Set(MV_SwitchEntityID, LVar0)
        Call(AssignScript, Ref(N(EVS_UseGreenSwitch)))
    Else
        Call(MakeEntity, Ref(Entity_GreenStompSwitch), -945, 1, -75, 0, MAKE_ENTITY_END)
        Set(MV_SwitchEntityID, LVar0)
        Call(AssignScript, Ref(N(EVS_UseGreenSwitch)))
    EndIf
    Call(MakeEntity, Ref(Entity_BrickBlock), 810, 330, -120, 90, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 810, 360, -120, 90, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SAM07_HiddenItem_UltraShroom)
    Call(MakeEntity, Ref(Entity_SavePoint), -1350, -60, -120, 0, MAKE_ENTITY_END)
    Return
    End
};
