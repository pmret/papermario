#include "flo_10.h"

EvtScript N(EVS_MakeEntities) = {
    IfGe(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Call(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, ITEM_SPAWN_MODE_DECORATION, 0)
    EndIf
    Return
    End
};
