#include "arn_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_WENT_DOWN_THE_WELL)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 0, 30, 0, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
