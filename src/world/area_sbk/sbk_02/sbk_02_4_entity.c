#include "sbk_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -240, 60, -200, 0, 6, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
