#include "osr_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KKJ25_Defeated_Bowser, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 180, 60, -15, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OSR02_HiddenItem_UltraShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -100, 60, -50, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
