#include "flo_10.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
