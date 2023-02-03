
#include "sam_12.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_GOT_STAR_STONE)
            EVT_CALL(MakeItemEntity, ITEM_STAR_STONE, 230, 0, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM12_Item_StarStone)
            EVT_SET(MV_StarStoneItemID, LVar0)
        EVT_CASE_GE(STORY_CH7_GOT_STAR_STONE)
            EVT_CALL(MakeItemEntity, ITEM_STAR_STONE, 230, 31, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM12_Item_StarStone)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
