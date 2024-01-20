#include "omo_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_OMO09_Defeated_CalculatorThief, TRUE)
        IfEq(GF_OMO01_Item_Calculator, FALSE)
            Call(MakeItemEntity, ITEM_CALCULATOR, -93, 0, 35, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO01_Item_Calculator)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -80, 60, -235, 0, ITEM_MYSTERY, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO01_HiddenItem_Mystery)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -30, 60, -235, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO01_HiddenItem_FrightJar)
    Return
    End
};
