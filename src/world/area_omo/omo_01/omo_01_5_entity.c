#include "omo_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_OMO09_Defeated_CalculatorThief, TRUE)
        EVT_IF_EQ(GF_OMO01_Item_Calculator, FALSE)
            EVT_CALL(MakeItemEntity, ITEM_CALCULATOR, -93, 0, 35, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO01_Item_Calculator)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -80, 60, -235, 0, ITEM_MYSTERY, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO01_HiddenItem_Mystery)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -30, 60, -235, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO01_HiddenItem_FrightJar)
    EVT_RETURN
    EVT_END
};
