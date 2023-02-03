#include "sam_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_SAM07_FloorRaised, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_GreenStompSwitch), -945, -179, -75, 0, MAKE_ENTITY_END)
        EVT_SET(MV_SwitchEntityID, LVar0)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseGreenSwitch)))
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_GreenStompSwitch), -945, 1, -75, 0, MAKE_ENTITY_END)
        EVT_SET(MV_SwitchEntityID, LVar0)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseGreenSwitch)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 810, 330, -120, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 810, 360, -120, 90, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SAM07_HiddenItem_UltraShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -1350, -60, -120, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
