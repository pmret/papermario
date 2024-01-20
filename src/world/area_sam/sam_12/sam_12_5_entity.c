
#include "sam_12.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_GOT_STAR_STONE)
            Call(MakeItemEntity, ITEM_STAR_STONE, 230, 0, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM12_Item_StarStone)
            Set(MV_StarStoneItemID, LVar0)
        CaseGe(STORY_CH7_GOT_STAR_STONE)
            Call(MakeItemEntity, ITEM_STAR_STONE, 230, 31, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM12_Item_StarStone)
    EndSwitch
    Return
    End
};
