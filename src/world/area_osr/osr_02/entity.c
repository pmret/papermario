#include "osr_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KKJ25_Defeated_Bowser, true)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 180, 60, -15, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OSR02_HiddenItem_UltraShroom)
    Call(MakeEntity, Ref(Entity_SavePoint), -100, 60, -50, 0, MAKE_ENTITY_END)
    Return
    End
};
